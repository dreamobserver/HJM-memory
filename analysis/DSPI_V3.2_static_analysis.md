# Phase-shifting DSPI V3.2 静态分析

## 范围与样本

- 仅做静态分析，未执行目标程序或配套 DLL。
- 样本：`Phase-shifting DSPI V3.2.exe`
- 大小：153,088 字节
- SHA-256：`E8DF537B931D688A600B378C48613986E16BD0CA0BDF402AB9E5008F9D4125D4`
- MD5（Ghidra 载入日志）：`CF0F9E643BB5B858C9FA11C4EDCA3A15`
- 架构：Windows PE x86-64，MSVC/MFC，映像基址 `0x140000000`
- Authenticode：未签名
- 资源版本：`1.0.0.1`；内部名/原文件名仍为 `DSPI.exe`，与文件名中的 V3.2 不一致。
- Manifest：`asInvoker`，不主动请求管理员权限。

使用本机 Ghidra 11.4.1 分析，并成功加载安装目录中的 `DSPI.pdb`。PDB 恢复了主要类、成员和函数名；由于编译优化和部分类型重建警告，个别反编译表达式仍需按汇编语义理解。

## 软件用途与工作流

这是一个基于四步相移的数字散斑干涉（DSPI）采集与处理程序，主类为 `CDSPIDlg`。主要流程是：

1. 初始化 MFC 界面、加密狗授权、KSJ 相机。
2. 通过 `KSJApi64.dll` 获取设备、设置视场、曝光、增益并启动相机流。
3. 从 `HKLM\\HARDWARE\\DEVICEMAP\\SERIALCOMM` 查找 `\\Device\\VCP0`，打开对应 `COM` 口。
4. 向相移控制器依次发送四条命令，每次等待约 50 ms 后采集一帧：
   - `:000oo\r\n`
   - `:0c0oo\r\n`
   - `:180oo\r\n`
   - `:240oo\r\n`
5. 使用四帧灰度图计算包裹相位。
6. 可进行参考相位差、原始图像差、滤波、ROI 相位展开、Jet 伪彩色和 3D 显示。
7. 支持打开图像、保存图像/BMP 和显示数字散斑/剪切散斑说明图。

## 关键函数（PDB 原名）

| 地址 | 函数 | 作用 |
|---|---|---|
| `0x1400034F0` | `OnInitDialog` | 授权、UI、相机初始化 |
| `0x140003E30` / `0x140003F60` | `DrawImage` / `DrawImage2` | 灰度/彩色显示 |
| `0x1400041C0` | `OnTimer` | 连续采集及差分/相位状态机 |
| `0x140004600` | `OnNMCustomdrawSliderExposuretime` | 曝光调节 |
| `0x1400046B0` | `OnNMCustomdrawSliderGain` | 增益调节 |
| `0x1400047F0` / `0x140004C90` | `OnBnClickedBtnOpen` / `OnBnClickedBtnSave` | 文件打开/保存 |
| `0x1400052B0` | `PhaseByFourStepCapture` | 串口控制四步相移并采四帧 |
| `0x1400059A0` | `PhaseByCalculate` | 四步相移相位计算 |
| `0x140005B00` | `OnBnClickedBtnPhasedif` | 保存参考相位并进入相位差模式 |
| `0x140005BB0` | `OnBnClickedBtnImgdif` | 保存参考强度图并进入图像差模式 |
| `0x140005C20` | `OnBnClickedBtnFilter` | 多次相位平滑滤波 |
| `0x140005E90` | `OnBnClickedBtnUnwrap` | 裁剪 ROI 并相位展开 |
| `0x140006150` | `grayToJet` | 灰度到 Jet 伪彩色 |
| `0x140006650` | `OnBnClickedBtn3d` | 3D 显示模式 |
| `0x140006A40`–`0x140006C40` | 鼠标右键事件 | 框选 ROI |
| `0x1400084E0` / `0x1400089F0` | `SpecialFilter` / `SpecialFilterEx` | 灰度/相位滤波 |
| `0x140008DB0` | `PhaseUnwrap` | 相位展开 |

## 相位算法

四帧像素记为 `I1, I2, I3, I4`。反编译代码计算：

```text
x = I1 - I3
y = I4 - I2
phi = atan2(y, x)
```

程序源码层面以 `atan(y/x)` 加手工象限修正实现，再把相位量化到 8 位图（约 `0..255`）。这就是标准四步相移算法的一种实现。相位差模式先保存一组参考包裹相位，再持续采集新相位并作差；图像差模式则对原始灰度帧作参考差分。

滤波按钮调用 `SpecialFilterEx`，每轮连续执行三次，并通过“Phase Smoothing”确认框决定是否继续。展开按钮先复制鼠标框选区域，再调用 `PhaseUnwrap`；结果还会计算一个浮点量并格式化为 `Unwrap_%.3f`。程序包含 `UnwrapJet_%.3f` 和 Jet 映射代码，表明展开结果可用伪彩显示。

## 外设与运行依赖

- `KSJApi64.dll`：相机 SDK，调用 `KSJ_Init`、`KSJ_DeviceGetCount`、`KSJ_CaptureRawData`、`KSJ_SetParam` 等。
- `dog_windows_x64_3151774.dll`：软件狗/授权组件。`OnInitDialog` 调用其序号 13，参数包含操作码 `0x0C` 和一段约 1 KiB 的编码授权数据。
- `MFC140.dll`、`VCRUNTIME140.dll`：Visual C++ 运行库。
- 虚拟串口 `VCP0`：用于控制相移器；程序将其映射成 `\\.\\COMn`。
- `res\\Holography.png`、`res\\Shearography.png`：界面说明图片。

安装目录保留了 `DSPI.pdb`、`DSPI.iobj`、`DSPI.ipdb`，说明这是接近开发/发布构建的归档，而非经过剥离的最终发行包。

## 安全性判断

静态结果中没有发现网络栈、下载器、命令执行、进程创建、服务安装或自启动持久化相关导入。可见的系统访问主要是：相机、串口、图像文件、MFC 注册表配置和授权 DLL。程序未加壳，PDB 与二进制匹配，整体行为与实验仪器软件一致。

但它是未签名程序，而且会加载同目录下两个第三方 DLL；因此“主 EXE 未见明显恶意行为”不等于整个软件包绝对安全。若要实际运行，建议先分别检查 `KSJApi64.dll` 和 `dog_windows_x64_3151774.dll`，并在隔离环境中记录文件、注册表、串口和进程行为。

## Ghidra 产物

- `analysis/report_pdb/summary.txt`：带 PDB 的函数、导入和地址摘要
- `analysis/report_pdb/decompiled.c`：带符号反编译结果
- `analysis/report/strings.txt`：字符串及交叉引用
- `analysis/ghidra_project_pdb/DSPI_PDB.gpr`：可在 Ghidra GUI 中继续查看的项目

