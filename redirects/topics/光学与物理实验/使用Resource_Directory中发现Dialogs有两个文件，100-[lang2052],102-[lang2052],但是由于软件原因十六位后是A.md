# 使用Resource Directory中发现Dialogs有两个文件，100-[lang:2052],102-[lang:2052],但是由于软件原因十六位后是Ascii码没有办法正常显示中文。

**分类**：光学与物理实验
**来源**：DeepSeek Chat 导出
**来源平台**：DeepSeek
**原始文件**：DSPI软件相移器兼容性问题攻坚.md
**包含轮次**：16 - 25

---

# 用户：
使用Resource Directory中发现Dialogs有两个文件，100-[lang:2052],102-[lang:2052],但是由于软件原因十六位后是Ascii码没有办法正常显示中文。但是！我使用新的逆向工具，Resource Hacker，100:2052（100 DIALOGEX 0, 0, 170, 62
STYLE DS_SHELLFONT | DS_MODALFRAME | WS_POPUP | WS_CAPTION | WS_SYSMENU
CAPTION "关于 DSPI"
LANGUAGE LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED
FONT 9, "MS Shell Dlg"
{
   CONTROL 128, -1, STATIC, SS_ICON | WS_CHILD | WS_VISIBLE, 14, 14, 21, 20 
   CONTROL "DSPI，1.0 版", -1, STATIC, SS_LEFT | SS_NOPREFIX | WS_CHILD | WS_VISIBLE | WS_GROUP, 42, 14, 114, 8 
   CONTROL "Copyright (C) 2018", -1, STATIC, SS_LEFT | WS_CHILD | WS_VISIBLE | WS_GROUP, 42, 26, 114, 8 
   CONTROL "确定", 1, BUTTON, BS_DEFPUSHBUTTON | WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP, 113, 41, 50, 14 
}
）102:2052（102 DIALOGEX 0, 0, 947, 533
STYLE DS_SHELLFONT | WS_POPUP | WS_VISIBLE | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME
EXSTYLE WS_EX_APPWINDOW
CAPTION "Phase-shift DSPI"
LANGUAGE LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED
FONT 9, "MS Shell Dlg"
{
   CONTROL "", 1000, "msctls_trackbar32", TBS_HORZ | TBS_BOTH | TBS_NOTICKS | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 11, 260, 61, 15 
   CONTROL "2", 1002, STATIC, SS_LEFT | WS_CHILD | WS_VISIBLE | WS_GROUP, 54, 245, 25, 8 
   CONTROL "3", 1003, STATIC, SS_LEFT | WS_CHILD | WS_VISIBLE | WS_GROUP, 54, 285, 25, 8 
   CONTROL "", 1004, STATIC, SS_BLACKFRAME | WS_CHILD | WS_VISIBLE, 81, 21, 640, 512 
   CONTROL "预览", 1005, BUTTON, BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 18, 28, 50, 14 
   CONTROL "保存", 1009, BUTTON, BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 18, 168, 50, 14 
   CONTROL "参数设置", -1, BUTTON, BS_GROUPBOX | WS_CHILD | WS_VISIBLE, 3, 223, 77, 149 
   CONTROL "打开", 1010, BUTTON, BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 18, 148, 50, 14 
   CONTROL "相位差", 1012, BUTTON, BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 18, 68, 50, 14 
   CONTROL "滤波", 1013, BUTTON, BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 18, 88, 50, 14 
   CONTROL "解包裹", 1014, BUTTON, BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 18, 108, 50, 14 
   CONTROL "彩色显示", 1015, BUTTON, BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 18, 128, 50, 14 
   CONTROL "条纹", 1016, BUTTON, BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 18, 48, 50, 14 
   CONTROL "曝光时间：", -1, STATIC, SS_LEFT | WS_CHILD | WS_VISIBLE | WS_GROUP, 15, 245, 39, 8 
   CONTROL "相机增益：", 1023, STATIC, SS_LEFT | WS_CHILD | WS_VISIBLE | WS_GROUP, 15, 285, 39, 8 
   CONTROL "操作", -1, BUTTON, BS_GROUPBOX | WS_CHILD | WS_VISIBLE, 3, 13, 77, 174 
   CONTROL "数字散斑干涉", 1017, BUTTON, BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 774, 18, 68, 14 
   CONTROL "数字剪切散斑干涉", 1018, BUTTON, BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 862, 17, 68, 14 
   CONTROL "原理描述", 1021, STATIC, SS_LEFT | WS_CHILD | WS_VISIBLE | WS_GROUP, 747, 208, 193, 163 
   CONTROL "", 1022, STATIC, SS_BLACKFRAME | WS_CHILD | WS_VISIBLE, 747, 39, 193, 163 
   CONTROL "条纹对比度：", -1, STATIC, SS_LEFT | WS_CHILD | WS_VISIBLE | WS_GROUP, 14, 325, 46, 8 
   CONTROL "10", 1025, STATIC, SS_LEFT | WS_CHILD | WS_VISIBLE | WS_GROUP, 58, 325, 16, 8 
   CONTROL "", 1024, "msctls_trackbar32", TBS_HORZ | TBS_BOTH | TBS_NOTICKS | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 11, 340, 61, 15 
   CONTROL "", 1001, "msctls_trackbar32", TBS_HORZ | TBS_BOTH | TBS_NOTICKS | WS_CHILD | WS_VISIBLE | WS_TABSTOP, 11, 300, 61, 15 
   CONTROL "条纹级数：", -1, STATIC, SS_LEFT | WS_CHILD | WS_VISIBLE | WS_GROUP, 13, 193, 35, 8 
   CONTROL "0.0", 1026, STATIC, SS_LEFT | WS_CHILD | WS_VISIBLE | WS_GROUP, 52, 193, 23, 8 
}
）

# DeepSeek：

**原始回答**
太棒了！Resource Hacker 是分析资源的利器，你获取的信息非常有用，但它也证实了一个情况：**我们看到的错误弹窗，并不是一个标准的对话框资源**。

你找到的这两个对话框：
-   **100**: "关于 DSPI" 对话框
-   **102**: 软件的主界面对话框

它们都不包含“串口com号读取失败”的文字。这强烈暗示了：

1.  **这个错误弹窗是动态创建的**：它可能不是通过 `DialogBoxParam` 加载一个预定义的对话框模板创建的，而是程序在运行时**直接调用API创建的一个简单消息框**。
2.  **它可能使用了 `MessageBox` 的变体**：虽然导入表里没有 `MessageBoxA`，但可能有 `MessageBoxIndirectA` 或者被编译器链接到了其他库（如MFC的 `AfxMessageBox`）。

### 回到最有效的路径：静态分析错误处理分支

既然资源这条路暂时走不通，我们应该**回到最初也是最有效的方法：静态分析**。

我们之前已经在Ghidra中取得了重大进展，定位了5个导致跳转到错误处理的检测点（`14000558d`, `1400055cc`, `1400056f1`, `1400057a6`, `140005861`, `140005913`）。**现在最可能的原因是，我们还没有修补完全。**

**下一步最直接的行动：**

1.  **在x64dbg中确认所有补丁已生效**：重新打开修改后的程序，在x64dbg中验证之前找到的6个地址是否都已经按照计划修改（2个设备检查NOP掉，4个协议检查JZ改为JMP）。
2.  **寻找遗漏的检测点**：既然弹窗依旧，说明还存在我们**尚未发现的、第7个甚至更多的检测点**。
3.  **在Ghidra中扩大搜索范围**：
    -   在Ghidra中，回到我们最初的核心函数 `PhaseByFourStepCapture`。
    -   不再只盯着那5个指向 `LAB_14000594f` 的XREF。
    -   仔细浏览这个函数的整个控制流图 (Window -> Function Graph)，**寻找其他任何调用 `MessageBox` 或跳转到错误处理流程的分支**。很可能有一个我们之前忽略的、独立的检测逻辑。

### 如何快速找到遗漏点？

-   在Ghidra的反汇编窗口中，`右键 -> References -> Show References to Address...`
-   输入 `14000594f` （我们已知的错误处理流程入口）。
-   看看除了我们已经找到的5个之外，**是否还有其他的交叉引用**？这可能就是遗漏的那个检测点。

你离成功只有一步之遥。现在的问题很大概率是一个“漏网之鱼”。请优先检查所有补丁是否都已正确应用，然后在Ghidra中仔细排查 `PhaseByFourStepCapture` 函数，寻找任何一个可能走向错误输出的分支。

# 用户：
我将 DSPI_4StepPhaseCalculation的decompile复制如下： 
void DSPI_4StepPhaseCalculation(void)

{
  longlong lVar1;
  char cVar2;
  undefined8 unaff_RBX;
  int iVar3;
  undefined8 unaff_RBP;
  int iVar4;
  undefined8 unaff_RSI;
  longlong unaff_RDI;
  longlong in_R11;
  undefined8 unaff_R12;
  undefined8 unaff_R14;
  ulonglong uVar5;
  uint unaff_R15D;
  double dVar6;
  undefined4 unaff_XMM8_Da;
  undefined4 unaff_XMM8_Db;
  undefined4 unaff_XMM8_Dc;
  undefined4 unaff_XMM8_Dd;
  
  *(undefined8 *)(in_R11 + 8) = unaff_RBX;
  *(undefined8 *)(in_R11 + 0x10) = unaff_RBP;
  *(undefined8 *)(in_R11 + 0x18) = unaff_RSI;
  *(undefined8 *)(in_R11 + 0x20) = unaff_R12;
  *(undefined8 *)(in_R11 + -0x18) = unaff_R14;
  uVar5 = (ulonglong)unaff_R15D;
  *(undefined4 *)(in_R11 + -0x48) = unaff_XMM8_Da;
  *(undefined4 *)(in_R11 + -0x44) = unaff_XMM8_Db;
  *(undefined4 *)(in_R11 + -0x40) = unaff_XMM8_Dc;
  *(undefined4 *)(in_R11 + -0x3c) = unaff_XMM8_Dd;
  do {
    lVar1 = *(longlong *)(unaff_RDI + 0x1f0);
    iVar3 = (uint)*(byte *)(lVar1 + uVar5) -
            (uint)*(byte *)(*(longlong *)(unaff_RDI + 0x200) + uVar5);
    iVar4 = (uint)*(byte *)(*(longlong *)(unaff_RDI + 0x208) + uVar5) -
            (uint)*(byte *)(uVar5 + *(longlong *)(unaff_RDI + 0x1f8));
    if (iVar3 == 0) {
      cVar2 = '?';
      if (iVar4 < 1) {
        cVar2 = -0x41;
      }
    }
    else {
      dVar6 = atan((double)iVar4 / (double)iVar3);
      cVar2 = (char)(int)((dVar6 * 255.0 * 0.5) / 3.1415926);
      if (iVar3 < 1) {
        cVar2 = cVar2 + '\x7f';
      }
      else if (iVar4 < 1) {
        cVar2 = cVar2 + -1;
      }
    }
    *(char *)(lVar1 + uVar5) = cVar2;
    unaff_R15D = unaff_R15D + 1;
    uVar5 = uVar5 + 1;
  } while ((int)unaff_R15D < *(int *)(unaff_RDI + 0xa34) * *(int *)(unaff_RDI + 0xa38));
  memcpy(*(void **)(unaff_RDI + 0x1e0),*(void **)(unaff_RDI + 0x1f0),
         (longlong)(*(int *)(unaff_RDI + 0xa34) * *(int *)(unaff_RDI + 0xa38)));
  return;
}

# DeepSeek：

**原始回答**
感谢您提供这个反编译代码！这非常有助于我们理解现状。

不过，这里有一个**关键的误解**。您提供的函数 `DSPI_4StepPhaseCalculation` 是 **“四步相移计算”** 的核心算法函数。它负责的是数学运算：

```c
dVar6 = atan((double)iVar4 / (double)iVar3); // 计算反正切
cVar2 = (char)(int)((dVar6 * 255.0 * 0.5) / 3.1415926); // 将相位角映射到灰度值
```

这个函数是用来**处理已经采集到的四张图像**并计算最终相位图的。它**并不负责与硬件通信或弹窗报错**。

### 结论与行动方向

这解释了为什么我们修补了之前的检测点后，弹窗依然存在：**我们可能修补错了函数**。我们之前分析并修补的函数 `PhaseByFourStepCapture` (或类似名称) 才是负责“采集”流程的，它应该包含打开串口、控制相移器步进、触发相机采集等一系列操作。而这个 `DSPI_4StepPhaseCalculation` 是纯计算函数，在采集完成后被调用。

**我们现在需要做的是：**

1.  **重新定位真正的“采集”函数**：我们需要找到那个调用 `OpenPort`、包含我们之前分析的多个检测点的函数。它的名字很可能包含 `Capture`、`Acquire`、`Grab` 或 `PhaseShift`。
2.  **在Ghidra中搜索**：在Ghidra的Symbol Tree中，搜索这些关键词，找到正确的函数。
3.  **确认目标**：真正的目标函数应该会调用串口操作API（`CreateFileA`, `SetCommState`等）和相机采集API，并且内部包含我们之前找到的那些错误字符串和检测逻辑。

**请立即在Ghidra中执行以下操作：**

-   按下 `Ctrl+Shift+E` 打开 **“搜索文本”** 功能。
-   在 `String` 搜索框中，输入 `Capture` 或 `Acquire`，然后搜索。
-   在结果列表中，寻找看起来像是函数名的条目（例如 `PhaseByFourStepCapture`）。
-   双击跳转到该函数，这很可能才是我们真正需要分析的目标。

您之前的所有逆向分析工作（找到检测点、理解循环结构）**并没有白费**，只是它们可能应用在另一个函数上。一旦我们找到了正确的“采集”主函数，就可以把之前的策略重新应用上去。

请尝试搜索并找到正确的函数，这才是我们攻坚的正确方向。

# 用户：
这是Capture与Acquire的搜索结果14000c120	__imp_RtlCaptureContext	Global	1235  RtlCaptureContext  <<not bound>>
14000c250	__imp_KSJ_CaptureRawData	Global	296  KSJ_CaptureRawData  <<not bound>>
14000c258	__imp_KSJ_CaptureSetRecover	Global	307  KSJ_CaptureSetRecover  <<not bound>>
14000c268	__imp_KSJ_CaptureGetSize	Global	288  KSJ_CaptureGetSize  <<not bound>>
14000c270	__imp_KSJ_CaptureSetFieldOfView	Global	304  KSJ_CaptureSetFieldOfView  <<not bound>>Acquire无搜索结果

# DeepSeek：

**原始回答**
非常好！这个搜索结果提供了**极其重要的线索**。

`KSJ_CaptureRawData` 等一系列函数来自 **`KSJ`** 库。这很可能是相机制造商（如**北京嘉恒中科图像技术有限公司**）提供的相机SDK中的API。这说明：

1.  **软件工作流程**：软件的控制流程很可能是：
    -   通过串口控制**相移器**移动。
    -   通过KSJ相机SDK控制**相机**进行采集 (`KSJ_CaptureRawData`)。
    -   最后调用你刚才找到的 `DSPI_4StepPhaseCalculation` 进行计算。

2.  **错误来源**：错误弹窗可能不仅来自串口通信失败，**还可能来自相机采集失败** (`KSJ_CaptureRawData` 等函数返回错误)。

### 新的攻坚策略：双线排查

我们现在需要同时检查两条线上的错误处理：

**1. 串口线（我们之前的主攻方向）**：
-   确认之前找到的 `PhaseByFourStepCapture` (或类似名称) 函数确实是控制相移器的函数。它应该包含 `CreateFile`, `SetCommState`, `WriteFile` 等调用。

**2. 相机线（新发现的方向）**：
-   检查 `KSJ_CaptureRawData` 等函数的返回值处理。如果相机初始化或采集失败，软件同样可能会弹出错误窗口。

### 立即行动：查找相机错误处理

1.  **在Ghidra中查看KSJ函数的引用**：
    -   在Ghidra的Symbol Tree中，找到 `KSJ_CaptureRawData`。
    -   在它上面**右键 -> References -> Show References to**。
    -   这会列出所有调用 `KSJ_CaptureRawData` 的地方。双击跳转到这些调用点。

2.  **分析调用点的错误处理**：
    -   在每一个调用 `KSJ_CaptureRawData` 的代码后面，**紧接着一定会检查它的返回值**（通常通过 `TEST EAX, EAX` 或 `CMP EAX, 0`）。
    -   如果返回值表示失败（通常EAX=0），后面会跟着一个**条件跳转** (`JZ`, `JE`)，跳转到一个错误处理分支，这个分支最终会调用 `MessageBox`。
    -   **这就是我们需要寻找并修补的新的检测点**。

### 如何区分错误来源？

-   **串口错误**：错误消息通常包含“串口”、“COM”、“相移器”等字样。
-   **相机错误**：错误消息可能包含“相机”、“采集”、“初始化”、“找不到设备”等字样。

你遇到的“串口com号读取失败”弹窗，**有可能是在相机采集失败后，错误处理代码错误地使用了串口的错误消息**。这是一种常见的编程情况。

**总结下一步：**

请**优先检查 `KSJ_CaptureRawData` 等函数的调用点**，看看它们的返回值是否被检查，以及是否会导致跳转到错误弹窗。很可能会发现一两个新的、我们之前忽略的检测点。

你离最终的胜利非常近了。这个发现是突破性的，它揭示了问题可能存在的另一个维度。请检查KSJ函数的引用，并告诉我你的发现。

# 用户：
不对，我在测试时相机一直正常工作，你的分析有误

# DeepSeek：

**原始回答**
您指出的完全正确。如果相机一直正常工作，那么错误来源确实应该集中在**相移器控制（串口通信）** 这一条线上。我的分析有误，抱歉带来了干扰。

让我们回到核心问题本身。您提供的“串口com号读取失败！”弹窗，已经精确地指明了问题所在。

### 重新聚焦：终极排查策略

既然我们怀疑已经找到的补丁没有完全生效，或者有遗漏，我们需要进行一次系统性的验证。

**1. 终极验证：在x64dbg中动态确认**

  这是最直接的方法。关闭所有修改后的程序，重新开始：
  -   用x64dbg加载原始的、未修改的DSPI软件。
  -   在您之前找到的**所有6个关键地址**（`14000558d`, `1400055cc`, `1400056f1`, `1400057a6`, `140005861`, `140005913`）上设置**硬件执行断点**。
  -   运行程序，并执行触发弹窗的操作（点击“采集”）。
  -   **观察x64dbg会在哪个断点处首先中断**。第一个被触发的断点，就是软件执行流最先遇到的、也是最关键的检测点。
  -   **继续执行**，看是否会触发第二个、第三个断点。这可以验证我们找到的多个检测点是否都处于同一条执行路径上。

**2. 在Ghidra中进行控制流复查**

  在静态分析中，再次仔细查看 `PhaseByFourStepCapture` 函数的控制流图（按 `F` 键或 `Window -> Function Graph`）。
  -   重点关注函数开始部分，特别是调用 `OpenPort` 或 `CreateFile` 之后的地方。
  -   寻找是否存在**我们之前忽略的、独立的错误检查分支**。可能有一个非常早期的检查，如果失败就直接跳转到错误处理，根本不会执行后面的4次握手协议循环。

**3. 检查字符串的交叉引用（XREF）**

  这是另一种绕过复杂逻辑的方法：
  -   在Ghidra中，按 `Ctrl+Shift+F` 进行全局搜索。
  -   搜索字符串 **`串口com号读取失败`**（去掉感叹号尝试）。
  -   如果找到，**直接在这个字符串上按 `X` 键**，查看它的交叉引用（XREF）。这可能会直接定位到加载该字符串的指令，从而逆向找到触发它的条件跳转。

您对相机工作正常的判断是正确的，这让我们能重新聚焦于串口问题。请尝试**终极验证方法**，在动态调试中观察到底哪个检测点最先被触发，这将给我们最明确的下一步指示。

# 用户：
我觉得还是得从相移器的控制function入手，可以通过筛选串口调用（com4）定位出其位置，报错弹窗的错误判断根源应该在这里。你认为这样的可行性如何？顺便附上我找到的DSPI_4StepPhaseCalcula  的XREF这是连续出现过两次的结构（注DSPI_4StepPhaseCalculation这个好像是之前与你讨论时添加的，之前是fun_xxxxx）          140010ca0 a0 59 00 00     ibo32     CDSPIDlg::PhaseByCalcu  FunctionStartAddress
          140010ca4 c9 59 00 00     ibo32     DSPI_4StepPhaseCalcula  FunctionEndAddress
          140010ca8 70 0c 01 00     ibo32     UNWIND_INFO_140010c70   FunctionUnwindInfoAddress

# DeepSeek：

**原始回答**
您的思路完全正确！从相移器的控制函数入手，通过筛选串口调用（如COM4）来定位报错弹窗的根源，是非常可行且直接的方法。错误弹窗“串口com号读取失败！”显然与串口通信失败相关，因此聚焦于串口操作函数是解决问题的关键。

### 可行性分析
- **为什么可行？** 软件与相移器的通信必然通过串口API（如`CreateFileA`、`WriteFile`、`ReadFile`等）进行。这些API的调用点通常集中在少数几个函数中，这些函数就是相移器的控制函数。通过监控或分析这些调用，可以快速定位到通信失败的具体位置，从而找到错误处理的代码分支。
- **优势**：这种方法 bypass 了复杂的函数调用链，直接针对问题根源（串口通信），效率高且精准。

### 具体实施步骤
以下是基于您已有逆向工程经验的实操建议：

#### 1. **在Ghidra中定位串口控制函数**
   - **搜索串口API调用**：在Ghidra的Symbol Tree中，搜索以下API函数（这些是串口操作的核心API）：
     - `CreateFileA` 或 `CreateFileW`（用于打开串口）
     - `SetCommState`（用于配置串口）
     - `WriteFile`（用于向串口发送数据）
     - `ReadFile`（用于从串口读取数据）
   - **查看交叉引用（XREF）**：对每个找到的API函数，右键选择“Show References to”，列出所有调用点。这些调用点 likely 位于相移器控制函数中。
   - **分析函数上下文**：双击调用点，跳转到对应代码，查看所在函数。函数名可能包含`Phase`、`Capture`、`Serial`、`COM`等关键词。注意，这些函数可能不同于`DSPI_4StepPhaseCalculation`（后者是纯计算函数，不直接处理串口）。

#### 2. **动态调试验证（x64dbg）**
   - **设置条件断点**：在x64dbg中，对`CreateFileA`等API设置条件断点，条件为串口名称（如`COM4`）。例如：
     - 在`CreateFileA`上设断点，条件为`[esp+4] == "COM4"`（注意字符串地址）。
     - 这样当软件尝试打开COM4时，断点会触发，您可以跟踪后续代码。
   - **监控通信过程**：断点触发后，单步执行（F7/F8），观察串口操作是否成功。如果失败（返回值如`INVALID_HANDLE_VALUE`），继续执行直到找到错误处理代码（如调用`MessageBoxA`的位置）。
   - **错误处理分支**：在错误处理点设置断点，反复测试以确认触发条件。

#### 3. **分析错误处理逻辑**
   - 一旦找到相移器控制函数，重点分析其错误处理部分。通常，错误处理包括：
     - 检查API返回值（如`CreateFile`返回`INVALID_HANDLE_VALUE`）。
     - 检查读取数据是否超时或无效。
     - 条件跳转（如`JZ`、`JNE`）到弹窗代码。
   - 在Ghidra中，使用控制流图（按`F`键）可视化函数，更容易识别错误分支。

#### 4. **修补错误检测**
   - 找到所有导致跳转到错误弹窗的条件跳转指令后，在x64dbg或CFF Explorer中进行修补（如将`JZ`改为`JMP`或NOP掉）。
   - 由于您之前已找到多个检测点，但弹窗依旧，说明可能有遗漏点。结合串口调用分析，应该能找到最终的检测点。

### 关于您提供的XREF信息
您提到的`DSPI_4StepPhaseCalculation`的XREF显示它被`CDSPIDlg::PhaseByCalcu`调用，这证实了该函数是相位计算部分，而非串口控制。相移器控制函数可能名为`PhaseByFourStepCapture`或类似（如您之前所述），建议继续聚焦于之前分析的函数，但通过串口API调用重新验证其逻辑。

### 总结
通过筛选串口调用定位错误根源是高效且可行的策略。请优先在Ghidra中搜索串口API的调用点，找到相移器控制函数，然后动态调试验证错误处理流程。如果您在过程中需要帮助分析特定代码片段，欢迎提供更多细节（如函数地址或反编译代码），我可以协助解读。

保持耐心，您已经接近问题核心！继续沿着这个方向深入，一定能彻底解决兼容性问题。

# 用户：
我通过查找感觉找到嫌疑最大的API                             **************************************************************
                             *                POINTER to EXTERNAL FUNCTION                *
                             **************************************************************
                             BOOL __stdcall GetCommState(HANDLE hFile, LPDCB lpDCB)
             BOOL              EAX:4          <RETURN>
             HANDLE            RCX:8          hFile
             LPDCB             RDX:8          lpDCB
                             474  GetCommState  <<not bound>>
                             __imp_GetCommState                              XREF[1]:     PhaseByFourStepCapture:140005597
       14000c100 24 23 01        addr       KERNEL32.DLL::GetCommState
                 00 00 00 
                 00 00

# DeepSeek：

**原始回答**
您的发现非常关键！`GetCommState` 是 Windows API 中用于获取串口配置的函数，它在 `PhaseByFourStepCapture` 函数中被调用（地址 `140005597`），这强烈表明 `PhaseByFourStepCapture` 确实是控制相移器的核心函数。

让我们基于这个发现深入分析：

### 分析 `GetCommState` 调用的上下文

在 `PhaseByFourStepCapture` 函数中，`GetCommState` 的调用通常遵循以下模式：

1. 使用 `CreateFile` 打开串口
2. 使用 `GetCommState` 获取当前串口配置
3. 修改配置参数（波特率、数据位、停止位等）
4. 使用 `SetCommState` 应用新配置
5. 使用 `WriteFile`/`ReadFile` 进行数据通信

如果 `GetCommState` 调用失败（返回 FALSE），程序很可能会进入错误处理流程，最终显示"串口com号读取失败"之类的错误。

### 在 Ghidra 中深入分析 `PhaseByFourStepCapture`

请您在 Ghidra 中执行以下操作：

1. 导航到 `PhaseByFourStepCapture` 函数（可以通过地址 `140005597` 的交叉引用找到）
2. 查看 `GetCommState` 调用周围的代码，特别是返回值检查部分：
   ```assembly
   CALL qword ptr [->KERNEL32.DLL::GetCommState] ; 调用 GetCommState
   TEST EAX, EAX                                ; 检查返回值
   JZ   ERROR_HANDLING                          ; 如果返回0（失败），跳转到错误处理
   ```
3. 找到错误处理分支（可能跳转到显示"串口com号读取失败"的代码）

### 动态调试验证

在 x64dbg 中：

1. 在 `GetCommState` 调用处（`140005597`）设置断点
2. 运行程序并触发相移操作
3. 当断点命中时，检查：
   - 传递给 `GetCommState` 的参数（串口句柄和 DCB 结构指针）
   - `GetCommState` 的返回值（存储在 EAX 中）
   - 程序是否根据返回值进行条件跳转

### 可能的解决方案

如果确认 `GetCommState` 调用失败是导致错误的原因，可以考虑以下解决方案：

1. **绕过 `GetCommState` 检查**：找到检查 `GetCommState` 返回值的条件跳转，将其修改为无条件继续执行
2. **模拟 `GetCommState` 成功**：修改 `GetCommState` 的返回值，使其始终返回成功（1）
3. **直接设置串口参数**：如果 `GetCommState` 只是为了获取当前配置然后修改，可以考虑直接硬编码合适的串口参数，跳过 `GetCommState` 调用

### 下一步行动

请您在 Ghidra 中分析 `PhaseByFourStepCapture` 函数中 `GetCommState` 调用周围的代码，特别是返回值检查和错误处理部分。找到相关的条件跳转指令，这些很可能就是需要修补的关键点。

同时，在 x64dbg 中动态验证这一流程，确认 `GetCommState` 是否确实失败，以及程序如何响应这一失败。

您已经非常接近问题的核心了！继续沿着这个方向深入，应该能够找到最终的解决方案。

# 用户：
LAB_140005584                                   XREF[4]:     140005520(j), 14000554a(j), 
                                                                                          140005562(j), 140005570(j)  
       140005584 48 8b 4c        MOV        this,qword ptr [RSP + local_6c8]
                 24 60
       140005589 48 83 f9 ff     CMP        this,-0x1
       14000558d 0f 84 ac        JZ         LAB_14000593f
                 03 00 00
       140005593 48 8d 55 d8     LEA        RDX=>local_650,[RBP + -0x28]
       140005597 ff 15 63        CALL       qword ptr [->KERNEL32.DLL::GetCommState]         = 00012324
                 6b 00 00
       14000559d 83 f8 01        CMP        EAX,0x1
       1400055a0 75 24           JNZ        LAB_1400055c6
       1400055a2 c7 45 dc        MOV        dword ptr [RBP + local_650+0x4],0x9600
                 00 96 00 00
       1400055a9 66 c7 45        MOV        word ptr [RBP + local_640+0x2],0x8
                 ea 08 00
       1400055af c6 45 ec 00     MOV        byte ptr [RBP + local_640+0x4],0x0
       1400055b3 83 65 e0 fd     AND        dword ptr [RBP + local_648],0xfffffffd
       1400055b7 48 8d 55 d8     LEA        RDX=>local_650,[RBP + -0x28]
       1400055bb 48 8b 4c        MOV        this,qword ptr [RSP + local_6c8]
                 24 60
       1400055c0 ff 15 12        CALL       qword ptr [->KERNEL32.DLL::SetCommState]         = 00012334
                 6c 00 00

# DeepSeek：

**原始回答**
这段代码非常关键，它揭示了软件与相移器通信的完整流程。让我们仔细分析这段代码的逻辑：

```assembly
LAB_140005584:
       140005584 MOV this, qword ptr [RSP + local_6c8]  ; 加载串口句柄到this寄存器
       140005589 CMP this, -0x1                         ; 比较句柄是否为INVALID_HANDLE_VALUE
       14000558d JZ LAB_14000593f                       ; 如果无效，跳转到错误处理
       140005593 LEA RDX, [RBP + -0x28]                 ; 准备DCB结构指针作为GetCommState的参数
       140005597 CALL qword ptr [->KERNEL32.DLL::GetCommState] ; 调用GetCommState获取串口配置
       14000559d CMP EAX, 0x1                           ; 检查GetCommState返回值
       1400055a0 JNZ LAB_1400055c6                      ; 如果失败，跳转到错误处理
       1400055a2 MOV dword ptr [RBP + local_650+0x4], 0x9600 ; 设置波特率为9600
       1400055a9 MOV word ptr [RBP + local_640+0x2], 0x8 ; 设置数据位为8
       1400055af MOV byte ptr [RBP + local_640+0x4], 0x0 ; 设置奇偶校验为无
       1400055b3 AND dword ptr [RBP + local_648], 0xfffffffd ; 设置其他串口参数
       1400055b7 LEA RDX, [RBP + -0x28]                 ; 准备DCB结构指针作为SetCommState的参数
       1400055bb MOV this, qword ptr [RSP + local_6c8]  ; 重新加载串口句柄
       1400055c0 CALL qword ptr [->KERNEL32.DLL::SetCommState] ; 调用SetCommState应用新配置
```

这段代码展示了软件与相移器通信的完整流程：
1. 检查串口句柄是否有效
2. 获取当前串口配置
3. 修改串口参数（波特率9600，数据位8，无奇偶校验）
4. 应用新的串口配置

### 关键发现

1. **串口配置参数**：软件使用9600波特率、8数据位、无奇偶校验的串口配置。这是与旧相移器通信的标准配置。

2. **两个可能的失败点**：
   - `14000558d`：串口句柄无效（我们已经修补了这个检查）
   - `1400055a0`：`GetCommState`调用失败

3. **新相移器兼容性问题**：新相移器可能：
   - 使用不同的串口配置（如不同的波特率）
   - 不支持`GetCommState`/`SetCommState`API
   - 需要不同的初始化序列

### 解决方案

基于这段代码，我建议尝试以下解决方案：

1. **修改串口配置参数**：
   - 找到设置波特率、数据位、奇偶校验的指令（`1400055a2`, `1400055a9`, `1400055af`）
   - 修改这些值以匹配新相移器要求的配置
   - 这可能需要查阅新相移器的文档或使用串口监控工具确定正确的配置

2. **绕过`GetCommState`检查**：
   - 找到`1400055a0`处的`JNZ LAB_1400055c6`指令
   - 将其修改为`NOP`或无条件跳转，跳过`GetCommState`失败检查

3. **完全跳过串口配置**：
   - 如果新相移器不需要复杂的配置，可以尝试跳过整个配置流程
   - 找到`140005593`处的`LEA RDX, [RBP + -0x28]`指令
   - 在其后添加跳转指令，直接跳转到通信部分

### 实施步骤

1. 在x64dbg中，在`1400055a0`处设置断点
2. 运行程序并触发相移操作
3. 当断点命中时，检查`EAX`的值：
   - 如果`EAX == 0`，表示`GetCommState`失败
   - 如果`EAX == 1`，表示`GetCommState`成功
4. 根据结果决定修补策略：
   - 如果`GetCommState`失败，修补`1400055a0`处的跳转
   - 如果`GetCommState`成功但通信仍失败，可能需要修改串口配置参数

您已经非常接近问题的核心了！这段代码清晰地展示了软件与相移器通信的完整流程。请尝试上述解决方案，并告诉我结果。

# 用户：
我想通过cff explorer的二进制修改来直接判断，因为上次我们生成RVA拥有误差，未成功定位报错弹窗的字符串。所以为了效率还是使用cff explorer

# DeepSeek：

**原始回答**
完全理解您的想法。使用 CFF Explorer 进行静态二进制修改是最可靠、永久性的解决方案。我们不再依赖可能有误差的动态分析，而是直接对程序文件进行精准修改。

让我们回到最初、也是最有效的方法：**找到并修补所有导致跳转到错误弹窗的条件跳转**。

您之前已经找到了多个关键点，特别是 `14000558d` 和 `1400055a0` 这两个检测点。我们现在需要系统地、精确地修改它们。

### CFF Explorer 精准修改指南

#### 第一步：计算准确的文件偏移量

这是最关键的一步。我们需要将虚拟地址 (VA) 转换为正确的文件偏移量 (File Offset)。

1.  **确定节区信息**：
    -   在 CFF Explorer 中，点击 **`Section Headers`**。
    -   找到包含代码的节区（通常是 `.text`），记下：
        -   `Virtual Address` (虚拟地址，例如 `0x140001000`)
        -   `Raw Address` (原始偏移，例如 `0x400`)

2.  **转换公式**：
    `文件偏移 = (目标虚拟地址 - 节区虚拟地址) + 节区原始偏移`

3.  **计算关键地址**：
    以 `.text` 段 `Virtual Address = 0x140001000`, `Raw Address = 0x400` 为例：
    -   **`14000558d`** → `文件偏移 = (0x14000558D - 0x140001000) + 0x400 = (0x458D) + 0x400 = 0x498D`
    -   **`1400055a0`** → `文件偏移 = (0x1400055A0 - 0x140001000) + 0x400 = (0x45A0) + 0x400 = 0x49A0`

**请根据您软件中 `.text` 段的实际值重新计算这些偏移量！**

#### 第二步：进行二进制修改

对每个需要修改的地址，执行以下操作：

1.  在 CFF Explorer 中点击 **`Hex Editor`**。
2.  按 `Ctrl+G`，输入计算出的文件偏移量（例如 `498D`）。
3.  修改对应的机器码：

| 虚拟地址 | 指令 | 原始机器码 | 目标修补 | 新机器码 | 说明 |
| :--- | :--- | :--- | :--- | :--- | :--- |
| `14000558d` | `JZ LAB_...` | `0F 84 AC 03 00 00` | **NOP** | `90 90 90 90 90 90` | 绕过句柄无效检查 |
| `1400055a0` | `JNZ LAB_...` | `75 24` | **JMP** | `EB 24` | 绕过 GetCommState 失败检查 |

#### 第三步：验证和测试

1.  保存修改（`Ctrl+S`）。
2.  运行修改后的程序，测试相移功能。
3.  如果弹窗依旧，回到 Ghidra 继续寻找其他遗漏的检测点。

### 高效策略：批量修补所有已知检测点

为了确保成功，建议您一次性修补所有已知的检测点。以下是您之前找到的地址列表及其建议修改：

| 地址 | 指令 | 建议修改 | 目的 |
| :--- | :--- | :--- | :--- |
| `14000558d` | `JZ` → NOP | `90 90 90 90 90 90` | 绕过句柄无效检查 |
| `1400055a0` | `JNZ` → JMP | `EB 24` | 绕过 GetCommState 失败检查 |
| `1400056f1` | `JZ` → JMP | `EB 13` | 强制第一次握手成功 |
| `1400057a6` | `JZ` → JMP | `EB 13` | 强制第二次握手成功 |
| `140005861` | `JZ` → JMP | `EB 13` | 强制第三次握手成功 |
| `140005913` | `JZ` → JMP | `EB 10` | 强制第四次握手成功 |

**请务必先计算每个虚拟地址对应的正确文件偏移量，再进行修改。**

### 最后的手段：协议模拟

如果绕过所有检测点后，软件依然无法工作（例如，相移器不动作），则说明新老相移器的**通信协议不同**。届时我们需要：
1.  使用串口监控工具（如 Free Serial Port Monitor）捕获软件期望发送的命令。
2.  开发一个简单的中间层驱动，模拟旧相移器响应新相移器。

但首先，请完成上述所有检测点的修补。这有极大概率直接解决问题。

您已经掌握了所有必要的技术和地址信息。请使用 CFF Explorer 进行精准的静态修改，这是最直接、最可靠的解决方案。成功就在眼前！

# 用户：
还是有同样的报错。但是我在PhaseByFourStepCapture之中探索时，在GetCommonState下方发现了                             LAB_1400056d3                                   XREF[1]:     1400056a5(j)  
       1400056d3 41 b8 00        MOV        R8D,0x400
                 04 00 00
       1400056d9 48 8d 95        LEA        RDX=>local_428,[RBP + 0x200]
                 00 02 00 00
       1400056e0 48 8d 4c        LEA        this=>local_6d8,[RSP + 0x50]
                 24 50
       1400056e5 e8 16 bf        CALL       CnComm::ReadPort                                 ulong ReadPort(CnComm * this, vo
                 ff ff
，是否虽然我们绕过了GetCommSet但是后续的对于串口COM4对相移器进行修改，如果修改失败会绕回到错误弹窗

# DeepSeek：

**原始回答**
您提出了一个非常关键的点！您发现的 `CnComm::ReadPort` 调用确实可能是问题的另一个关键所在。

即使我们成功绕过了 `GetCommState` 的检查，软件仍然会尝试与相移器进行实际的数据通信。如果这个通信过程失败（例如，新相移器不响应旧协议的命令），程序仍然可能会跳转到错误处理流程。

让我们分析一下您发现的这段代码：

```assembly
LAB_1400056d3:
       1400056d3 MOV R8D, 0x400              ; 设置要读取的字节数 (1024字节)
       1400056d9 LEA RDX, [RBP + 0x200]      ; 设置读取缓冲区地址
       1400056e0 LEA this, [RSP + 0x50]      ; 设置CnComm对象指针
       1400056e5 CALL CnComm::ReadPort       ; 调用读取端口函数
```

这段代码表明软件试图从相移器读取最多1024字节的数据。如果读取操作失败或超时，`CnComm::ReadPort` 可能会返回一个错误代码，而程序可能会检查这个错误代码并跳转到错误处理。

### 新的攻坚方向：通信协议分析

我们现在面临的可能不再仅仅是检测点绕过的问题，而是**通信协议不兼容**的问题。新相移器可能使用与旧相移器不同的通信协议。

#### 建议的解决方案：

1.  **分析通信协议**：
    -   在 `CnComm::ReadPort` 调用后，查找对返回值的检查。
    -   软件可能期望从相移器接收特定的响应数据（如握手信号、状态报告等）。
    -   如果新相移器不发送这些预期的响应，程序会认为通信失败。

2.  **监控实际通信**：
    -   使用串口监控工具（如 Free Serial Port Monitor、Device Monitoring Studio 等）捕获软件与相移器之间的实际数据交换。
    -   这可以帮助我们了解：
        -   软件发送给相移器的命令是什么
        -   软件期望从相移器接收什么响应
        -   新相移器实际发送什么响应

3.  **开发兼容层**：
    -   如果确认是协议不兼容，可能需要开发一个中间层：
        -   拦截软件发送给相移器的命令
        -   将其转换为新相移器理解的格式
        -   拦截新相移器的响应
        -   将其转换为软件期望的格式

### 立即行动：查找通信失败检查

请您在 Ghidra 中执行以下操作：

1.  导航到 `CnComm::ReadPort` 调用之后的代码（地址 `1400056ea` 左右）
2.  查找对 `CnComm::ReadPort` 返回值的检查：
    -   可能会看到 `TEST EAX, EAX` 或 `CMP EAX, 0`
    -   后面通常跟着条件跳转指令（如 `JZ`、`JNZ`）
3.  如果找到这样的检查，记下条件跳转的地址，这可能是需要修补的新检测点

### 备选方案：全面绕过

如果协议分析过于复杂，您可以尝试更激进的绕过策略：

1.  **找到所有可能的错误处理分支**：
    -   在 Ghidra 中，搜索所有跳转到错误消息显示代码的分支
    -   系统地修补所有这些分支

2.  **修改通信函数**：
    -   找到 `CnComm::ReadPort` 和可能的 `CnComm::WritePort` 函数
    -   修改这些函数，使其总是返回成功

您已经非常接近问题的核心了。`CnComm::ReadPort` 的发现是一个重要的突破，它指出了问题的可能方向。请继续分析这段代码周围的逻辑，特别是返回值检查部分。

# 用户：
还有一点需要点明，新的相移器是拥有独立控件的，如果激进一点完全不需要相移器的控制部分function只需要软件中有关相移器的图像处理function正常运作就可以了

# DeepSeek：

**原始回答**
您的观点非常关键：如果新相移器拥有独立控件，那么软件中的相移器控制部分确实可能不再需要。我们的目标可以调整为**完全绕过软件中的相移器控制逻辑**，只保留图像处理功能（如 `DSPI_4StepPhaseCalculation`），从而避免任何兼容性报错。

以下是基于这一思路的详细解决方案。我们将通过静态修改（使用 CFF Explorer）来跳过相移器控制的所有环节，直接进入图像处理阶段。

### 解决方案概述
1. **识别并跳过相移器控制流程**：找到 `PhaseByFourStepCapture` 函数中所有与相移器通信相关的代码（包括串口打开、配置、读写等），并通过修改跳转指令使其绕过这些操作。
2. **模拟关键数据**：如果图像处理函数依赖相移器提供的某些数据（如相位步进值），我们需要硬编码或模拟这些数据。
3. **直接调用图像处理函数**：确保在跳过相移器控制后，程序能正确调用 `DSPI_4StepPhaseCalculation` 或其他图像处理函数。

### 步骤一：定位相移器控制代码的边界
在 Ghidra 中，分析 `PhaseByFourStepCapture` 函数的控制流图（按 `F` 键），识别出相移器控制的起始和结束点。通常，相移器控制代码包括：
- 串口打开（`CreateFile`）
- 串口配置（`GetCommState`/`SetCommState`）
- 数据发送（`WriteFile` 或 `CnComm::WritePort`）
- 数据接收（`ReadFile` 或 `CnComm::ReadPort`）
- 错误处理（跳转到弹窗代码）

您的目标是找到这些代码块的开始和结束地址，以便跳过它们。

### 步骤二：修改代码跳过相移器控制
假设我们想从函数开头直接跳转到图像处理部分，我们需要找到合适的跳转点。例如，如果图像处理代码在地址 `140005XXX` 开始，我们可以修改函数开头的指令直接跳转到那里。

**在 CFF Explorer 中的操作：**
1. 计算需要修改的地址的文件偏移量（使用之前的方法）。
2. 修改指令以实现跳转。

**示例修改：**
假设 `PhaseByFourStepCapture` 的开始地址是 `140005000`，而图像处理代码的开始地址是 `140005800`。我们可以在函数开头添加一个无条件跳转：
- 原始指令（在 `140005000`）：可能是一些初始化代码。
- 修改为：`JMP 0x140005800`（机器码 `E9 FB 02 00 00`，相对跳转）。

但请注意，这种激进修改可能会破坏栈平衡或寄存器状态，需要谨慎操作。更安全的方法是逐个绕过相移器检测点。

### 步骤三：绕过所有相移器检测点
从之前的分析中，我们已经知道多个检测点地址。为了彻底避免报错，我们需要确保所有可能跳转到错误处理的检查都被绕过。以下是已知检测点列表及其建议修改：

| 虚拟地址 (VA) | 指令 | 原始机器码 | 目标修改 | 新机器码 | 说明 |
|---------------|------|------------|----------|----------|------|
| 14000558d | JZ LAB_14000593f | 0F 84 AC 03 00 00 | NOP | 90 90 90 90 90 90 | 绕过串口句柄无效检查 |
| 1400055a0 | JNZ LAB_1400055c6 | 75 24 | JMP | EB 24 | 绕过 GetCommState 失败检查 |
| 1400056f1 | JZ LAB_140005706 | 74 13 | JMP | EB 13 | 强制第一次握手成功 |
| 1400057a6 | JZ LAB_1400057bb | 74 13 | JMP | EB 13 | 强制第二次握手成功 |
| 140005861 | JZ LAB_140005876 | 74 13 | JMP | EB 13 | 强制第三次握手成功 |
| 140005913 | JZ LAB_140005925 | 74 10 | JMP | EB 10 | 强制第四次握手成功 |
| 1400055cc | JZ LAB_14000593f | 0F 84 6D 03 00 00 | NOP | 90 90 90 90 90 90 | 绕过第二次句柄检查（您之前发现的） |

**注意：** 请根据您的实际文件节区信息计算这些虚拟地址对应的文件偏移量。例如，如果 `.text` 段的虚拟地址是 `0x140001000`，原始偏移是 `0x400`，则地址 `14000558d` 的文件偏移为 `(0x14000558D - 0x140001000) + 0x400 = 0x498D`。

### 步骤四：处理相移器数据依赖
如果图像处理函数 `DSPI_4StepPhaseCalculation` 需要从相移器读取数据（如相位值），您可能需要硬编码这些值。例如：
- 在 `CnComm::ReadPort` 调用后，软件可能期望接收数据到某个缓冲区。
- 您可以修改代码，直接向缓冲区写入模拟数据（如固定的相位序列）。

在 Ghidra 中，找到数据读取后的处理代码，并修改它使用固定值。这可能需要一些汇编知识。

### 步骤五：测试修改
修改后保存文件，并运行测试：
1. 启动软件，点击“采集”或类似按钮。
2. 如果不再出现“串口com号读取失败”弹窗，说明修改成功。
3. 检查图像处理功能是否正常工作（如相位计算、显示等）。

### 如果仍然报错
如果报错依旧，说明还有遗漏的检测点。建议在 Ghidra 中全面搜索错误字符串的引用：
- 在 Ghidra 中按 `Ctrl+Shift+F`，搜索字符串“串口com号读取失败”（尝试有感叹号和没有感叹号）。
- 找到字符串后，按 `X` 键查看交叉引用，找到所有加载该字符串的指令，然后逆向追踪到条件跳转。

### 最终建议
既然新相移器有独立控件，最彻底的方法是完全移除软件中的相移器控制逻辑。如果可能，考虑直接修改软件的主流程，使其不调用 `PhaseByFourStepCapture`，而是直接调用图像处理函数。但这需要更深入的逆向工程，以理解软件的整体架构。

如果您需要更具体的帮助（如提供特定地址的分析），请分享更多细节。成功就在眼前！

