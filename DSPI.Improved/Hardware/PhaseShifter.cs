using Microsoft.Win32;
using Microsoft.Win32.SafeHandles;
using System.Runtime.InteropServices;
using System.Text;

namespace DSPI.Improved.Hardware;

internal sealed class PhaseShifter : IDisposable
{
    private const int BaudRate = 115200;
    // Recovered from the supplied PztControl executable: 0..100% maps to the
    // controller's 13-bit DAC range (round(percent * 81.91), maximum 8191).
    private const double DacCountsPerPercent = 81.91;
    private SafeFileHandle? _handle;
    public string PortName { get; private set; } = "";

    public static IReadOnlyList<string> ListPorts()
        => RegistryPorts().Where(IsActivePort).ToArray();

    public static IReadOnlyList<string> ListDisconnectedPorts()
        => RegistryPorts().Where(port => !IsActivePort(port)).ToArray();

    private static IReadOnlyList<string> RegistryPorts()
    {
        using var key = Registry.LocalMachine.OpenSubKey(@"HARDWARE\DEVICEMAP\SERIALCOMM");
        if (key is null) return [];
        return key.GetValueNames()
            .Select(name => key.GetValue(name) as string)
            .Where(port => !string.IsNullOrWhiteSpace(port))
            .Cast<string>()
            .Distinct(StringComparer.OrdinalIgnoreCase)
            .OrderBy(PortNumber)
            .ThenBy(port => port, StringComparer.OrdinalIgnoreCase)
            .ToArray();
    }

    public void Open(string? portName = null)
    {
        Dispose();
        if (!string.IsNullOrWhiteSpace(portName) && !IsActivePort(portName))
            throw new InvalidOperationException($"串口 {portName} 当前未连接。请给 PZT 控制器上电并重新插拔 USB 数据线，然后点击“刷新”。");
        var ports = string.IsNullOrWhiteSpace(portName) ? ListPorts() : [portName];
        if (ports.Count == 0)
        {
            var disconnected = ListDisconnectedPorts();
            var history = disconnected.Count == 0 ? "" : $" 历史端口 {string.Join("、", disconnected)} 当前均未连接。";
            throw new InvalidOperationException("没有检测到可用串口。请给 PZT 控制器上电并重新连接 USB 数据线。" + history);
        }

        var errors = new List<string>();
        foreach (var port in ports)
        {
            try
            {
                OpenPort(port);
                VerifyController();
                PortName = port;
                return;
            }
            catch (Exception ex)
            {
                errors.Add($"{port}: {ex.Message}");
                Dispose();
            }
        }
        throw new InvalidOperationException("未找到兼容的 PZT 控制器（115200、8N1、二进制握手）。\n" + string.Join("\n", errors));
    }

    public async Task StepAsync(int step, int voltageStepPercent, CancellationToken cancellationToken)
    {
        if ((uint)step >= 4) throw new ArgumentOutOfRangeException(nameof(step));
        if (voltageStepPercent is < 1 or > 33) throw new ArgumentOutOfRangeException(nameof(voltageStepPercent));
        WriteVoltage(step * voltageStepPercent, requireEcho: false);
        await Task.Delay(80, cancellationToken);
    }

    private void OpenPort(string portName)
    {
        var handle = Native.CreateFile("\\\\.\\" + portName, 0xC0000000, 0, IntPtr.Zero, 3, 0, IntPtr.Zero);
        if (handle.IsInvalid)
        {
            var error = Marshal.GetLastWin32Error();
            handle.Dispose();
            throw new InvalidOperationException($"无法打开串口，Win32={error}");
        }
        _handle = handle;

        var dcb = new Dcb { Length = (uint)Marshal.SizeOf<Dcb>() };
        if (!Native.BuildCommDCB($"baud={BaudRate} parity=N data=8 stop=1", ref dcb) || !Native.SetCommState(handle, ref dcb))
            throw new InvalidOperationException("串口参数配置失败");
        var timeouts = new CommTimeouts
        {
            ReadIntervalTimeout = 20,
            ReadTotalTimeoutConstant = 250,
            WriteTotalTimeoutConstant = 250
        };
        if (!Native.SetCommTimeouts(handle, ref timeouts)) throw new InvalidOperationException("串口超时配置失败");
        Native.PurgeComm(handle, 0x0004 | 0x0008);
    }

    private void VerifyController() => WriteVoltage(0, requireEcho: true);

    private void WriteVoltage(int percent, bool requireEcho)
    {
        if (_handle is null || _handle.IsInvalid) throw new InvalidOperationException("PZT 控制器串口未打开。");
        percent = Math.Clamp(percent, 0, 100);
        var raw = (ushort)Math.Round(percent * DacCountsPerPercent);
        byte[] command = [0x10, 0x01, (byte)raw, (byte)(raw >> 8)];
        Native.PurgeComm(_handle, 0x0004 | 0x0008);
        if (!Native.WriteFile(_handle, command, command.Length, out var written, IntPtr.Zero) || written != command.Length)
            throw new InvalidOperationException("写入 PZT 电压指令失败");
        Native.FlushFileBuffers(_handle);

        if (!requireEcho) return;
        var response = new byte[4];
        if (!Native.ReadFile(_handle, response, response.Length, out var read, IntPtr.Zero) ||
            read != command.Length || !response.AsSpan(0, read).SequenceEqual(command))
            throw new InvalidOperationException("握手无响应或响应不匹配");
    }

    public void Dispose()
    {
        _handle?.Dispose();
        _handle = null;
        PortName = "";
    }

    private static int PortNumber(string port)
    {
        var digits = new string(port.SkipWhile(c => !char.IsDigit(c)).ToArray());
        return int.TryParse(digits, out var value) ? value : int.MaxValue;
    }

    private static bool IsActivePort(string port)
    {
        var target = new StringBuilder(512);
        return Native.QueryDosDevice(port, target, target.Capacity) != 0;
    }

    [StructLayout(LayoutKind.Sequential)]
    private struct Dcb
    {
        public uint Length, BaudRate, Flags;
        public ushort Reserved, XonLim, XoffLim;
        public byte ByteSize, Parity, StopBits;
        public sbyte XonChar, XoffChar, ErrorChar, EofChar, EvtChar;
        public ushort Reserved1;
    }

    [StructLayout(LayoutKind.Sequential)]
    private struct CommTimeouts
    {
        public uint ReadIntervalTimeout, ReadTotalTimeoutMultiplier, ReadTotalTimeoutConstant,
                    WriteTotalTimeoutMultiplier, WriteTotalTimeoutConstant;
    }

    private static class Native
    {
        [DllImport("kernel32", CharSet = CharSet.Unicode, SetLastError = true)]
        internal static extern SafeFileHandle CreateFile(string name, uint access, uint share, IntPtr security,
            uint creation, uint flags, IntPtr template);
        [DllImport("kernel32", CharSet = CharSet.Unicode)] internal static extern bool BuildCommDCB(string definition, ref Dcb dcb);
        [DllImport("kernel32", SetLastError = true)] internal static extern bool SetCommState(SafeFileHandle handle, ref Dcb dcb);
        [DllImport("kernel32", SetLastError = true)] internal static extern bool SetCommTimeouts(SafeFileHandle handle, ref CommTimeouts timeouts);
        [DllImport("kernel32", SetLastError = true)] internal static extern bool PurgeComm(SafeFileHandle handle, uint flags);
        [DllImport("kernel32", SetLastError = true)] internal static extern bool FlushFileBuffers(SafeFileHandle handle);
        [DllImport("kernel32", SetLastError = true)] internal static extern bool WriteFile(SafeFileHandle handle, byte[] buffer, int count, out int written, IntPtr overlapped);
        [DllImport("kernel32", SetLastError = true)] internal static extern bool ReadFile(SafeFileHandle handle, byte[] buffer, int count, out int read, IntPtr overlapped);
        [DllImport("kernel32", CharSet = CharSet.Unicode, SetLastError = true)]
        internal static extern uint QueryDosDevice(string deviceName, StringBuilder targetPath, int maximumLength);
    }
}
