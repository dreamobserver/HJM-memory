using System.Runtime.InteropServices;

namespace DSPI.Improved.Hardware;

internal sealed class KsjCamera : IDisposable
{
    private const int Success = 1;
    private const int NotSupported = -3;
    private readonly object _sync = new();
    private bool _initialized;
    public int Channel { get; private set; }
    public int Width { get; private set; }
    public int Height { get; private set; }

    public void Initialize()
    {
        Check(Native.KSJ_Init(), "初始化 KSJ SDK");
        _initialized = true;
        var count = Native.KSJ_DeviceGetCount();
        if (count <= 0) throw new InvalidOperationException("未检测到 KSJ 相机。");
        Channel = count - 1; // 与原程序保持一致：使用枚举中的最后一台相机。

        var colStart = 0; var rowStart = 0; var colSize = 0; var rowSize = 0;
        var colMode = AddressMode.SkipNone; var rowMode = AddressMode.SkipNone;
        Check(Native.KSJ_PreviewGetDefaultFieldOfView(Channel, ref colStart, ref rowStart,
              ref colSize, ref rowSize, ref colMode, ref rowMode), "读取相机视场");
        Check(Native.KSJ_PreviewSetFieldOfView(Channel, 0, 0, colSize, rowSize,
              AddressMode.SkipNone, AddressMode.SkipNone), "设置预览视场");
        Check(Native.KSJ_CaptureSetFieldOfView(Channel, 0, 0, colSize, rowSize,
              AddressMode.SkipNone, AddressMode.SkipNone), "设置采集视场");
        var width = 0; var height = 0;
        Check(Native.KSJ_CaptureGetSize(Channel, ref width, ref height), "读取图像尺寸");
        Width = width;
        Height = height;
        // Some KSJ camera models only support synchronous KSJ_CaptureRawData and return
        // RET_NOTSUPPORT (-3) for the optional stream/recovery APIs. The original DSPI
        // program ignored both return values, so retain that cross-model compatibility.
        CheckOptional(Native.KSJ_StreamStart(Channel), "启动相机数据流");
        CheckOptional(Native.KSJ_CaptureSetRecover(Channel, false), "设置采集恢复模式");
    }

    public byte[] Capture()
    {
        lock (_sync)
        {
            if (!_initialized) throw new InvalidOperationException("相机尚未初始化。");
            var data = new byte[checked(Width * Height)];
            Check(Native.KSJ_CaptureRawData(Channel, data), "采集图像");
            return data;
        }
    }

    public void SetExposure(int value)
    {
        lock (_sync) Check(Native.KSJ_SetParam(Channel, CameraParameter.Exposure, value), "设置曝光");
    }

    public void SetGain(int value)
    {
        lock (_sync)
        {
            // CatchBEST's official C# sample uses the RGB gain parameters. On CCD/mono
            // cameras KSJ_RED is explicitly mapped by the SDK to the hardware VGA gain.
            // KSJ_VGAGAIN is a legacy CCD-only alias and returns RET_NOTSUPPORT on this camera.
            Check(Native.KSJ_SetParam(Channel, CameraParameter.Red, value), "设置相机增益");
            CheckOptional(Native.KSJ_SetParam(Channel, CameraParameter.Green, value), "设置绿色增益");
            CheckOptional(Native.KSJ_SetParam(Channel, CameraParameter.Blue, value), "设置蓝色增益");
        }
    }

    public (int Minimum, int Maximum, int Current) GetRange(CameraParameter parameter)
    {
        lock (_sync)
        {
            var min = 0; var max = 0; var current = 0;
            Check(Native.KSJ_GetParamRange(Channel, parameter, ref min, ref max), "读取参数范围");
            Check(Native.KSJ_GetParam(Channel, parameter, ref current), "读取参数值");
            return (min, max, current);
        }
    }

    public void Dispose()
    {
        lock (_sync)
        {
            if (_initialized) Native.KSJ_UnInit();
            _initialized = false;
        }
    }

    private static void Check(int code, string action)
    {
        if (code != Success) throw new InvalidOperationException($"{action}失败，KSJ 错误码：{code}");
    }

    private static void CheckOptional(int code, string action)
    {
        if (code != Success && code != NotSupported)
            throw new InvalidOperationException($"{action}失败，KSJ 错误码：{code}");
    }

    internal enum CameraParameter
    {
        Exposure = 0, Red, Green, Blue, Gamma, PreviewColumnStart, PreviewRowStart,
        CaptureColumnStart, CaptureRowStart, HorizontalBlank, VerticalBlank, Flip, Bin,
        Mirror, Contrast, Brightness, VgaGain
    }

    private enum AddressMode { SkipNone = 0, Skip2, Skip3, Skip4, Skip8 }

    private static class Native
    {
        private const string Dll = "KSJApi64.dll";
        [DllImport(Dll)] internal static extern int KSJ_Init();
        [DllImport(Dll)] internal static extern int KSJ_UnInit();
        [DllImport(Dll)] internal static extern int KSJ_DeviceGetCount();
        [DllImport(Dll)] internal static extern int KSJ_GetParamRange(int channel, CameraParameter parameter, ref int min, ref int max);
        [DllImport(Dll)] internal static extern int KSJ_SetParam(int channel, CameraParameter parameter, int value);
        [DllImport(Dll)] internal static extern int KSJ_GetParam(int channel, CameraParameter parameter, ref int value);
        [DllImport(Dll)] internal static extern int KSJ_PreviewGetDefaultFieldOfView(int channel, ref int colStart,
            ref int rowStart, ref int colSize, ref int rowSize, ref AddressMode colMode, ref AddressMode rowMode);
        [DllImport(Dll)] internal static extern int KSJ_PreviewSetFieldOfView(int channel, int colStart,
            int rowStart, int colSize, int rowSize, AddressMode colMode, AddressMode rowMode);
        [DllImport(Dll)] internal static extern int KSJ_CaptureSetFieldOfView(int channel, int colStart,
            int rowStart, int colSize, int rowSize, AddressMode colMode, AddressMode rowMode);
        [DllImport(Dll)] internal static extern int KSJ_CaptureGetSize(int channel, ref int width, ref int height);
        [DllImport(Dll)] internal static extern int KSJ_CaptureRawData(int channel, byte[] data);
        [DllImport(Dll)] internal static extern int KSJ_StreamStart(int channel);
        // Match the vendor's official C# declaration (Win32 BOOL marshaling).
        [DllImport(Dll)] internal static extern int KSJ_CaptureSetRecover(int channel, bool recover);
    }
}
