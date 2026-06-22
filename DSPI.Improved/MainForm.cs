using DSPI.Improved.Hardware;
using DSPI.Improved.Processing;
using System.Drawing.Imaging;
using System.Runtime.InteropServices;

namespace DSPI.Improved;

internal sealed class MainForm : Form
{
    private enum DisplayMode { None, Preview, Fringe, PhaseDifference, Filtered, Unwrapped }

    private readonly KsjCamera _camera = new();
    private readonly PhaseShifter _shifter = new();
    private readonly System.Windows.Forms.Timer _timer = new() { Interval = 100 };
    private readonly PictureBox _viewer = new() { Dock = DockStyle.Fill, BackColor = Color.FromArgb(24, 27, 34), SizeMode = PictureBoxSizeMode.Zoom };
    private readonly Label _status = new() { Dock = DockStyle.Bottom, Height = 28, TextAlign = ContentAlignment.MiddleLeft, Padding = new Padding(8, 0, 0, 0) };
    private readonly Label _modeInfo = new()
    {
        Dock = DockStyle.Top, Height = 150, Padding = new Padding(12), BackColor = Color.White,
        Text = "当前模式：就绪\n连接相机后点击“预览”。", AutoEllipsis = false
    };
    private readonly Label _fringeOrder = new() { AutoSize = true, Text = "条纹级数：—", ForeColor = Color.Navy };
    private readonly TrackBar _exposure = new() { TickStyle = TickStyle.None, Minimum = 0, Maximum = 100, Width = 230 };
    private readonly TrackBar _gain = new() { TickStyle = TickStyle.None, Minimum = 0, Maximum = 100, Width = 230 };
    private readonly NumericUpDown _contrast = new()
    {
        Minimum = 0.1m, Maximum = 100m, Value = 1m, Increment = 0.5m,
        DecimalPlaces = 1, Width = 120, TextAlign = HorizontalAlignment.Right
    };
    private readonly ComboBox _port = new() { DropDownStyle = ComboBoxStyle.DropDownList, Width = 164 };
    private readonly NumericUpDown _phaseStep = new()
    {
        Minimum = 1, Maximum = 33, Value = 25, Increment = 1,
        DecimalPlaces = 0, Width = 120, TextAlign = HorizontalAlignment.Right
    };
    private readonly Label _exposureValue = new() { AutoSize = true, Text = "0" };
    private readonly Label _gainValue = new() { AutoSize = true, Text = "0" };

    private bool _cameraReady;
    private bool _shifterReady;
    private bool _busy;
    private bool _color;
    private DisplayMode _mode;
    private byte[]? _latestRaw;
    private byte[]? _fringeReference;
    private PhaseFrame? _phaseReference;
    private PhaseFrame? _currentPhase;
    private UnwrapResult? _unwrap;
    private byte[]? _currentGray;
    private int _imageWidth;
    private int _imageHeight;
    private Rectangle _roi;
    private Point _dragStart;
    private bool _dragging;

    public MainForm()
    {
        Text = "Phase-shift DSPI Improved";
        WindowState = FormWindowState.Maximized;
        MinimumSize = new Size(1100, 700);
        Font = new Font("Microsoft YaHei UI", 10f);
        AutoScaleMode = AutoScaleMode.Dpi;

        var left = BuildControlPanel();
        var content = new TableLayoutPanel { Dock = DockStyle.Fill, ColumnCount = 3, RowCount = 1, BackColor = Color.FromArgb(229, 232, 238) };
        content.ColumnStyles.Add(new ColumnStyle(SizeType.Absolute, 280));
        content.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 100));
        content.ColumnStyles.Add(new ColumnStyle(SizeType.Absolute, 340));
        content.RowStyles.Add(new RowStyle(SizeType.Percent, 100));
        _viewer.Margin = new Padding(8);
        content.Controls.Add(left, 0, 0);
        content.Controls.Add(_viewer, 1, 0);
        content.Controls.Add(BuildInfoPanel(), 2, 0);

        var root = new TableLayoutPanel { Dock = DockStyle.Fill, RowCount = 2, ColumnCount = 1 };
        root.RowStyles.Add(new RowStyle(SizeType.Percent, 100));
        root.RowStyles.Add(new RowStyle(SizeType.Absolute, 30));
        root.Controls.Add(content, 0, 0);
        root.Controls.Add(_status, 0, 1);
        Controls.Add(root);

        _timer.Tick += async (_, _) => await OnAcquisitionTickAsync();
        _viewer.MouseDown += ViewerMouseDown;
        _viewer.MouseMove += ViewerMouseMove;
        _viewer.MouseUp += ViewerMouseUp;
        _viewer.Paint += ViewerPaint;
        _exposure.Scroll += (_, _) => SetExposure();
        _gain.Scroll += (_, _) => SetGain();
        _contrast.ValueChanged += (_, _) => SetStatus($"条纹对比度已设为 {_contrast.Value:F1}×。");
        FormClosing += (_, _) => { _timer.Stop(); _shifter.Dispose(); _camera.Dispose(); _viewer.Image?.Dispose(); };
        SetStatus("就绪。连接相机后点击“预览”；PZT 控制器串口可在左侧选择。");
        RefreshPorts();
    }

    private Control BuildInfoPanel()
    {
        var panel = new Panel { Dock = DockStyle.Fill, BackColor = Color.FromArgb(247, 248, 250), Padding = new Padding(10) };
        var title = new Label
        {
            Dock = DockStyle.Top, Height = 42, Text = "处理状态与原理", TextAlign = ContentAlignment.MiddleLeft,
            Font = new Font("Microsoft YaHei UI", 11f, FontStyle.Bold)
        };
        var help = new RichTextBox
        {
            Dock = DockStyle.Fill, ReadOnly = true, BorderStyle = BorderStyle.None,
            BackColor = Color.White, ScrollBars = RichTextBoxScrollBars.Vertical, WordWrap = true,
            DetectUrls = false,
            Text = "改进后的处理链\n\n" +
                   "条纹\n饱和强度差，避免 8 位回绕。\n\n" +
                   "相位差\n四步相移 atan2，内部保存浮点弧度。\n\n" +
                   "滤波\n质量加权圆周均值；支持 ×1、×5、×10。\n\n" +
                   "解包裹\n右键框选 ROI，按相位质量优先传播。\n\n" +
                   "PZT 控制器\n自动使用 115200、8N1 和二进制握手；默认四步电压为 0%、25%、50%、75%。\n\n" +
                   "提示：真实硬件首次测试请保持物体静止。"
        };
        panel.Controls.Add(help);
        panel.Controls.Add(_modeInfo);
        panel.Controls.Add(title);
        return panel;
    }

    private Control BuildControlPanel()
    {
        var panel = new FlowLayoutPanel
        {
            Dock = DockStyle.Fill, FlowDirection = FlowDirection.TopDown,
            WrapContents = false, AutoScroll = true, Padding = new Padding(10), BackColor = Color.FromArgb(245, 246, 249)
        };
        panel.Controls.Add(Section("操作"));
        panel.Controls.Add(Button("预览", async (_, _) => await StartPreviewAsync()));
        panel.Controls.Add(Button("条纹", async (_, _) => await StartFringeAsync()));
        panel.Controls.Add(Button("相位差", async (_, _) => await StartPhaseDifferenceAsync()));
        panel.Controls.Add(Button("滤波 ×1", (_, _) => ApplyFilter(1)));
        panel.Controls.Add(Button("一键滤波 ×5", (_, _) => ApplyFilter(5), Color.FromArgb(224, 240, 255)));
        panel.Controls.Add(Button("一键滤波 ×10", (_, _) => ApplyFilter(10), Color.FromArgb(210, 232, 255)));
        panel.Controls.Add(Button("解包裹", (_, _) => Unwrap()));
        panel.Controls.Add(Button("彩色显示", (_, _) => ToggleColor()));
        panel.Controls.Add(Button("打开", (_, _) => OpenImage()));
        panel.Controls.Add(Button("保存", (_, _) => SaveImage()));
        panel.Controls.Add(new Label { Height = 3, Width = 240, Margin = Padding.Empty });
        panel.Controls.Add(_fringeOrder);
        panel.Controls.Add(new Label { Height = 5, Width = 240, Margin = Padding.Empty });
        panel.Controls.Add(Section("参数设置"));
        panel.Controls.Add(ParameterRow("曝光时间", _exposureValue));
        panel.Controls.Add(_exposure);
        panel.Controls.Add(ParameterRow("相机增益", _gainValue));
        panel.Controls.Add(_gain);
        panel.Controls.Add(LabeledControl("条纹对比度", _contrast, "倍（0.1–100.0）"));
        panel.Controls.Add(Section("相移控制器"));
        var portRow = new TableLayoutPanel { Width = 240, Height = 34, ColumnCount = 2, Margin = new Padding(2, 1, 2, 2) };
        portRow.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 100));
        portRow.ColumnStyles.Add(new ColumnStyle(SizeType.Absolute, 68));
        _port.Dock = DockStyle.Fill;
        var refresh = new Button { Text = "刷新", Dock = DockStyle.Fill, Margin = new Padding(4, 0, 0, 0), FlatStyle = FlatStyle.Flat };
        refresh.Click += (_, _) => RefreshPorts();
        portRow.Controls.Add(_port, 0, 0);
        portRow.Controls.Add(refresh, 1, 0);
        panel.Controls.Add(portRow);
        panel.Controls.Add(LabeledControl("单步电压", _phaseStep, "%（1–33）"));
        panel.Controls.Add(new Label { Text = "115200 / 8N1 / PZT 二进制协议", Width = 240, Height = 26, ForeColor = Color.DimGray });
        return panel;
    }

    private static Label Section(string text) => new()
    {
        Text = text, Font = new Font("Microsoft YaHei UI", 10f, FontStyle.Bold),
        Width = 240, Height = 27, Margin = new Padding(2, 2, 2, 1), TextAlign = ContentAlignment.MiddleLeft
    };

    private static Button Button(string text, EventHandler click, Color? color = null)
    {
        var button = new Button { Text = text, Width = 240, Height = 36, Margin = new Padding(2, 1, 2, 1), BackColor = color ?? Color.White, FlatStyle = FlatStyle.Flat };
        button.FlatAppearance.BorderColor = Color.FromArgb(190, 195, 205);
        button.Click += click;
        return button;
    }

    private static Control ParameterRow(string name, Label value)
    {
        var panel = new TableLayoutPanel { Width = 240, Height = 28, ColumnCount = 2, Margin = new Padding(2, 1, 2, 1) };
        panel.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 100));
        panel.ColumnStyles.Add(new ColumnStyle(SizeType.Absolute, 70));
        panel.Controls.Add(new Label { Text = name + "：", Dock = DockStyle.Fill, TextAlign = ContentAlignment.MiddleLeft }, 0, 0);
        value.Dock = DockStyle.Fill;
        value.TextAlign = ContentAlignment.MiddleRight;
        panel.Controls.Add(value, 1, 0);
        return panel;
    }

    private static Control LabeledControl(string name, Control control, string suffix)
    {
        var panel = new TableLayoutPanel { Width = 240, Height = 36, ColumnCount = 3, Margin = new Padding(2, 1, 2, 3) };
        panel.ColumnStyles.Add(new ColumnStyle(SizeType.Absolute, 90));
        panel.ColumnStyles.Add(new ColumnStyle(SizeType.Absolute, 90));
        panel.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 100));
        panel.Controls.Add(new Label { Text = name + "：", Dock = DockStyle.Fill, TextAlign = ContentAlignment.MiddleLeft }, 0, 0);
        control.Dock = DockStyle.Fill;
        panel.Controls.Add(control, 1, 0);
        panel.Controls.Add(new Label { Text = suffix, Dock = DockStyle.Fill, TextAlign = ContentAlignment.MiddleLeft, ForeColor = Color.DimGray }, 2, 0);
        return panel;
    }

    private void RefreshPorts()
    {
        var selected = _port.SelectedItem?.ToString();
        var ports = PhaseShifter.ListPorts();
        _port.BeginUpdate();
        _port.Items.Clear();
        foreach (var port in ports) _port.Items.Add(port);
        _port.EndUpdate();
        if (ports.Count > 0)
        {
            var index = selected is null ? -1 : _port.FindStringExact(selected);
            _port.SelectedIndex = index >= 0 ? index : 0;
            SetStatus($"检测到串口：{string.Join("、", ports)}。相位差会先执行 PZT 握手验证。");
        }
        else
        {
            var disconnected = PhaseShifter.ListDisconnectedPorts();
            var history = disconnected.Count == 0 ? "" : $" 历史端口 {string.Join("、", disconnected)} 当前处于离线状态。";
            SetStatus("未检测到可用串口。请确认 PZT 控制器已上电并重新插拔 USB 数据线。" + history, true);
        }
    }

    private async Task EnsureCameraAsync()
    {
        if (_cameraReady) return;
        SetStatus("正在初始化 KSJ 相机……");
        await Task.Run(_camera.Initialize);
        _cameraReady = true;
        _imageWidth = _camera.Width;
        _imageHeight = _camera.Height;
        ConfigureCameraSlider(_exposure, _exposureValue, KsjCamera.CameraParameter.Exposure);
        ConfigureCameraSlider(_gain, _gainValue, KsjCamera.CameraParameter.Red);
        _roi = new Rectangle(0, 0, _imageWidth, _imageHeight);
        SetStatus($"相机已连接：通道 {_camera.Channel}，{_imageWidth}×{_imageHeight}");
    }

    private void ConfigureCameraSlider(TrackBar slider, Label label, KsjCamera.CameraParameter parameter)
    {
        var range = _camera.GetRange(parameter);
        slider.Minimum = range.Minimum;
        slider.Maximum = Math.Max(range.Minimum + 1, range.Maximum);
        slider.Value = Math.Clamp(range.Current, slider.Minimum, slider.Maximum);
        label.Text = slider.Value.ToString();
    }

    private async Task StartPreviewAsync()
    {
        await RunUiAction(async () =>
        {
            await EnsureCameraAsync();
            _mode = DisplayMode.Preview;
            _timer.Interval = 100;
            _timer.Start();
            SetStatus("实时预览中。");
        });
    }

    private async Task StartFringeAsync()
    {
        await RunUiAction(async () =>
        {
            await EnsureCameraAsync();
            _timer.Stop();
            _fringeReference = await Task.Run(_camera.Capture);
            _mode = DisplayMode.Fringe;
            _timer.Interval = 100;
            _timer.Start();
            SetStatus("已保存强度参考图，正在显示饱和保护后的实时差分条纹。");
        });
    }

    private async Task StartPhaseDifferenceAsync()
    {
        await RunUiAction(async () =>
        {
            await EnsureCameraAsync();
            _timer.Stop();
            if (!_shifterReady)
            {
                _shifter.Open(_port.SelectedItem?.ToString());
                _shifterReady = true;
            }
            SetStatus($"正在通过 {_shifter.PortName} 采集四步参考相位……");
            _phaseReference = await CapturePhaseAsync();
            _currentPhase = new PhaseFrame(new float[_phaseReference.Wrapped.Length],
                                           (float[])_phaseReference.Quality.Clone(), _imageWidth, _imageHeight);
            _mode = DisplayMode.PhaseDifference;
            _timer.Interval = 200;
            _timer.Start();
            SetStatus("相位参考已保存，正在显示实时包裹相位差。");
        });
    }

    private async Task<PhaseFrame> CapturePhaseAsync()
    {
        var frames = new byte[4][];
        for (var step = 0; step < 4; step++)
        {
            await _shifter.StepAsync(step, (int)_phaseStep.Value, CancellationToken.None);
            frames[step] = await Task.Run(_camera.Capture);
        }
        return PhaseAlgorithms.FourStep(frames[0], frames[1], frames[2], frames[3], _imageWidth, _imageHeight);
    }

    private async Task OnAcquisitionTickAsync()
    {
        if (_busy || !_cameraReady) return;
        _busy = true;
        try
        {
            switch (_mode)
            {
                case DisplayMode.Preview:
                    _latestRaw = await Task.Run(_camera.Capture);
                    ShowGray(_latestRaw, _imageWidth, _imageHeight);
                    break;
                case DisplayMode.Fringe when _fringeReference is not null:
                    _latestRaw = await Task.Run(_camera.Capture);
                    ShowGray(PhaseAlgorithms.SaturatingFringeDifference(_latestRaw, _fringeReference,
                             (float)_contrast.Value), _imageWidth, _imageHeight);
                    break;
                case DisplayMode.PhaseDifference when _phaseReference is not null:
                    _currentPhase = PhaseAlgorithms.CircularDifference(await CapturePhaseAsync(), _phaseReference);
                    ShowPhase(_currentPhase);
                    break;
            }
        }
        catch (Exception ex)
        {
            _timer.Stop();
            SetStatus("采集停止：" + ex.Message, true);
        }
        finally { _busy = false; }
    }

    private void ApplyFilter(int passes)
    {
        RunUiAction(() =>
        {
            if (_currentPhase is null) throw new InvalidOperationException("请先获取“相位差”或打开一张包裹相位图。");
            _timer.Stop();
            _currentPhase = PhaseAlgorithms.CircularMean(_currentPhase, passes);
            _mode = DisplayMode.Filtered;
            ShowPhase(_currentPhase);
            SetStatus($"已完成圆周均值滤波 ×{passes}。内部仍保留浮点相位，未反复量化。");
        });
    }

    private void Unwrap()
    {
        RunUiAction(() =>
        {
            if (_currentPhase is null) throw new InvalidOperationException("请先获取相位差并进行滤波。");
            _timer.Stop();
            var roi = _roi.Width >= 2 && _roi.Height >= 2 ? _roi : new Rectangle(0, 0, _currentPhase.Width, _currentPhase.Height);
            _unwrap = PhaseAlgorithms.QualityGuidedUnwrap(_currentPhase, roi);
            _mode = DisplayMode.Unwrapped;
            _fringeOrder.Text = $"条纹级数：{_unwrap.FringeOrder:F3}";
            ShowGray(_unwrap.Display, _unwrap.Width, _unwrap.Height);
            SetStatus($"质量引导解包裹完成：ROI {roi.Width}×{roi.Height}，峰谷相位差 {_unwrap.FringeOrder:F3}×2π。");
        });
    }

    private void ToggleColor()
    {
        _color = !_color;
        if (_currentGray is not null) ShowGray(_currentGray, _imageWidth, _imageHeight);
        SetStatus(_color ? "已切换为 Jet 伪彩显示。" : "已切换为灰度显示。");
    }

    private void OpenImage()
    {
        using var dialog = new OpenFileDialog { Filter = "图像文件|*.bmp;*.png;*.jpg;*.jpeg;*.tif;*.tiff|所有文件|*.*" };
        if (dialog.ShowDialog(this) != DialogResult.OK) return;
        using var bitmap = new Bitmap(dialog.FileName);
        _imageWidth = bitmap.Width; _imageHeight = bitmap.Height;
        var gray = BitmapToGray(bitmap);
        var phase = gray.Select(v => v * PhaseAlgorithms.TwoPi / 255f).ToArray();
        _currentPhase = new PhaseFrame(phase, Enumerable.Repeat(1f, phase.Length).ToArray(), _imageWidth, _imageHeight);
        _roi = new Rectangle(0, 0, _imageWidth, _imageHeight);
        _mode = DisplayMode.Filtered;
        ShowGray(gray, _imageWidth, _imageHeight);
        SetStatus("已按 0..255 → 0..2π 载入离线包裹相位图。");
    }

    private void SaveImage()
    {
        if (_viewer.Image is null) return;
        using var dialog = new SaveFileDialog { Filter = "PNG 图像|*.png|BMP 图像|*.bmp", DefaultExt = "png" };
        if (dialog.ShowDialog(this) == DialogResult.OK) _viewer.Image.Save(dialog.FileName);
    }

    private void ShowPhase(PhaseFrame frame) => ShowGray(PhaseAlgorithms.PhaseToGray(frame.Wrapped), frame.Width, frame.Height);

    private void ShowGray(byte[] gray, int width, int height)
    {
        _currentGray = (byte[])gray.Clone();
        _imageWidth = width; _imageHeight = height;
        var bitmap = CreateBitmap(gray, width, height, _color);
        var old = _viewer.Image;
        _viewer.Image = bitmap;
        old?.Dispose();
        _viewer.Invalidate();
    }

    private static unsafe Bitmap CreateBitmap(ReadOnlySpan<byte> gray, int width, int height, bool color)
    {
        var bitmap = new Bitmap(width, height, PixelFormat.Format24bppRgb);
        var data = bitmap.LockBits(new Rectangle(0, 0, width, height), ImageLockMode.WriteOnly, PixelFormat.Format24bppRgb);
        try
        {
            var jet = color ? PhaseAlgorithms.Jet(gray) : null;
            for (var y = 0; y < height; y++)
            {
                var row = (byte*)data.Scan0 + y * data.Stride;
                for (var x = 0; x < width; x++)
                {
                    var index = y * width + x;
                    if (jet is null) row[3 * x] = row[3 * x + 1] = row[3 * x + 2] = gray[index];
                    else
                    {
                        row[3 * x] = jet[3 * index + 2];
                        row[3 * x + 1] = jet[3 * index + 1];
                        row[3 * x + 2] = jet[3 * index];
                    }
                }
            }
        }
        finally { bitmap.UnlockBits(data); }
        return bitmap;
    }

    private static byte[] BitmapToGray(Bitmap bitmap)
    {
        var output = new byte[bitmap.Width * bitmap.Height];
        for (var y = 0; y < bitmap.Height; y++)
        for (var x = 0; x < bitmap.Width; x++)
        {
            var c = bitmap.GetPixel(x, y);
            output[y * bitmap.Width + x] = (byte)Math.Clamp((int)Math.Round(0.299 * c.R + 0.587 * c.G + 0.114 * c.B), 0, 255);
        }
        return output;
    }

    private void ViewerMouseDown(object? sender, MouseEventArgs e)
    {
        if (e.Button != MouseButtons.Right || _viewer.Image is null) return;
        _dragStart = ImagePoint(e.Location);
        _dragging = true;
    }

    private void ViewerMouseMove(object? sender, MouseEventArgs e)
    {
        if (!_dragging) return;
        var end = ImagePoint(e.Location);
        _roi = NormalizeRectangle(_dragStart, end);
        _viewer.Invalidate();
    }

    private void ViewerMouseUp(object? sender, MouseEventArgs e)
    {
        if (e.Button != MouseButtons.Right) return;
        _dragging = false;
        if (_roi.Width >= 2 && _roi.Height >= 2) SetStatus($"已选择 ROI：X={_roi.X}, Y={_roi.Y}, {_roi.Width}×{_roi.Height}");
    }

    private void ViewerPaint(object? sender, PaintEventArgs e)
    {
        if (_viewer.Image is null || _mode == DisplayMode.Unwrapped || _roi.Width < 2 || _roi.Height < 2) return;
        var display = ImageRectangle();
        var sx = display.Width / (float)_imageWidth; var sy = display.Height / (float)_imageHeight;
        var rect = new RectangleF(display.X + _roi.X * sx, display.Y + _roi.Y * sy, _roi.Width * sx, _roi.Height * sy);
        using var pen = new Pen(Color.Lime, 2f) { DashStyle = System.Drawing.Drawing2D.DashStyle.Dash };
        e.Graphics.DrawRectangle(pen, rect.X, rect.Y, rect.Width, rect.Height);
    }

    private Point ImagePoint(Point point)
    {
        var rect = ImageRectangle();
        var x = Math.Clamp((int)((point.X - rect.X) * _imageWidth / rect.Width), 0, _imageWidth - 1);
        var y = Math.Clamp((int)((point.Y - rect.Y) * _imageHeight / rect.Height), 0, _imageHeight - 1);
        return new Point(x, y);
    }

    private RectangleF ImageRectangle()
    {
        var scale = Math.Min(_viewer.ClientSize.Width / (float)_imageWidth, _viewer.ClientSize.Height / (float)_imageHeight);
        var width = _imageWidth * scale; var height = _imageHeight * scale;
        return new RectangleF((_viewer.ClientSize.Width - width) / 2f, (_viewer.ClientSize.Height - height) / 2f, width, height);
    }

    private static Rectangle NormalizeRectangle(Point a, Point b)
    {
        var left = Math.Min(a.X, b.X); var top = Math.Min(a.Y, b.Y);
        return Rectangle.FromLTRB(left, top, Math.Max(a.X, b.X) + 1, Math.Max(a.Y, b.Y) + 1);
    }

    private void SetExposure()
    {
        _exposureValue.Text = _exposure.Value.ToString();
        if (_cameraReady) RunUiAction(() => _camera.SetExposure(_exposure.Value));
    }

    private void SetGain()
    {
        _gainValue.Text = _gain.Value.ToString();
        if (_cameraReady) RunUiAction(() => _camera.SetGain(_gain.Value));
    }

    private void SetStatus(string text, bool error = false)
    {
        _status.Text = text;
        _status.BackColor = error ? Color.MistyRose : Color.FromArgb(235, 240, 247);
        _status.ForeColor = error ? Color.DarkRed : Color.FromArgb(35, 45, 60);
        _modeInfo.Text = $"当前模式：{ModeName()}\n{text}";
        _modeInfo.ForeColor = error ? Color.DarkRed : Color.FromArgb(35, 45, 60);
    }

    private string ModeName() => _mode switch
    {
        DisplayMode.Preview => "预览",
        DisplayMode.Fringe => "条纹差分",
        DisplayMode.PhaseDifference => "相位差",
        DisplayMode.Filtered => "圆周滤波",
        DisplayMode.Unwrapped => "质量引导解包裹",
        _ => "就绪"
    };

    private async Task RunUiAction(Func<Task> action)
    {
        try { await action(); }
        catch (Exception ex) { SetStatus(ex.Message, true); MessageBox.Show(this, ex.Message, "DSPI", MessageBoxButtons.OK, MessageBoxIcon.Error); }
    }

    private void RunUiAction(Action action)
    {
        try { action(); }
        catch (Exception ex) { SetStatus(ex.Message, true); MessageBox.Show(this, ex.Message, "DSPI", MessageBoxButtons.OK, MessageBoxIcon.Error); }
    }
}
