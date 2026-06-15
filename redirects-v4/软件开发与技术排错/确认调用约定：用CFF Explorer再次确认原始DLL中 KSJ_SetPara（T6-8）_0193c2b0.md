---
title: "确认调用约定：用CFF Explorer再次确认原始DLL中 KSJ_SetPara（T6-8）"
source_platform: "DeepSeek"
source_file: "Ghidra逆向适配相机API教程.md"
turn_start: 6
turn_end: 8
primary_category: "软件开发与技术排错"
tags:
  - "Ghidra"
  - "脉冲测距"
  - "API"
project_id: "8cb1548b62-software-01"
stage: "阶段2/5"
previous_slice: "大恒相机SDK替换与兼容性改造_3a032717.md"
next_slice: "确认调用约定：用CFF Explorer再次确认原始DLL中 KSJ_SetPara（T9-11）_8dd97170.md"
has_attachment: false
attachment_context_confidence: not_applicable
classification_confidence: 0.97
---

# 确认调用约定：用CFF Explorer再次确认原始DLL中 KSJ_SetPara（T6-8）

## 问题摘要

本切片围绕“确认调用约定：用CFF Explorer再次确认原始DLL中 KSJ_SetPara（T6-8）”展开。起始诉求是：确认调用约定：用CFF Explorer再次确认原始DLL中 KSJ_SetParam 的导出名，以最终确定使用 __cdecl 还是 __stdcall。是将ghidra中有使用KSJ_SetParam的位置，根据cffexplorer中address converter转化定… 后续进展或反馈是：我从集成程序的文件夹中发现了名为KSJAPI.ini对逆向工程有帮助吗？内容覆盖原始对话 T6-T8。

## 原始对话

替换相机又近了一大步！

# 用户：

确认调用约定：用CFF Explorer再次确认原始DLL中 KSJ_SetParam 的导出名，以最终确定使用 __cdecl 还是 __stdcall。是将ghidra中有使用KSJ_SetParam的位置，根据cffexplorer中address converter转化定位吗？

# DeepSeek：

**原始回答**

非常好的问题！您对过程的思考非常接近，但这里有一个更直接和准确的方法，不需要通过地址转换来关联Ghidra和CFF Explorer。

**不需要使用CFF Explorer的“Address Converter”。** 这两个工具在此刻是独立工作的，它们的分析对象不同：

*   **Ghidra** 分析的是**主程序(.exe)**，告诉我们它**如何调用**`KSJ_SetParam`。
*   **CFF Explorer** 分析的是**原始的`KSJAPI64.dll`**，告诉我们这个函数**是如何被定义和导出的**。

调用约定是函数定义的一部分，所以最权威的信息来源是函数被定义的地方，即原始的DLL文件。因此，正确的方法是：

### 操作步骤：在CFF Explorer中直接查看导出函数名

1.  **用CFF Explorer打开原始的 `KSJAPI64.dll`**。
2.  在左侧导航树中，确保展开目录，找到并点击 **`Export Directory`** （导出目录）。
3.  在右侧的主窗口中找到

tParam，并且对其进行XREFs搜索结果如下

# DeepSeek：

**原始回答**

非常好！您在Ghidra中找到的交叉引用（XREFs）信息是**无价之宝**。它不仅仅告诉我们`KSJ_SetParam`被调用了，更重要的是告诉了我们它**在什么情况下、为了什么目的**被调用。

这极大地降低了你推断函数参数含义的难度。

### 分析XREFs结果

您的搜索结果 `OnBnClickedBtnCapContinue`, `OnHNCustomdrawSliderExposuretime`, `OnHNCustomdrawSliderGain` 是三个非常重要的函数名称，它们揭示了程序的逻辑：

1.  **`OnBnClickedBtnCapContinue`**:
    *   这是一个典型的**MFC按钮点击事件处理函数**的命名。`OnBnClicked`表示“按钮被点击”，`BtnCapContinue`很可能表示“开始连续采集”按钮。
    *   **意义**：在开始连续采集图像之前或之时，程序会调用`KSJ_SetParam`来设置某些相机参数以确保采集正确。

2.  **`OnHNCustom

的分析工作。祝您好运！

# 用户：

我从集成程序的文件夹中发现了名为KSJAPI.ini对逆向工程有帮助吗？

# DeepSeek：

**原始回答**

**非常有帮助！这是一个极其重要的发现！** `KSJAPI.ini` 文件很可能成为您破解整个相机参数映射关系的 **“罗塞塔石碑”**。

INI文件是标准的配置文件，对于逆向工程来说，它们通常是纯文本、未加密的，包含了软件运行的大量关键参数和设置。分析这个文件可以为您节省数小时甚至数天的猜测和逆向分析工作。

### 为什么 KSJAPI.ini 如此重要？

这个文件很可能是凯士佳相机的**参数配置和初始化文件**。软件启动时，DLL 会读取这个文件来配置相机的各种参数。

### 您应该立即做什么？

1.  **用文本编辑器打开它**：使用记事本（Notepad）、Notepad++ 或 VSCode 等工具打开 `KSJAPI.ini` 文件。
2.  **仔细查看其内容**：寻找与您之前在反编译代码中看到的**魔术数字（Magic Number）** 相关的信息。

### 您可能会发现什么？（预期内容）

这个文件很可能具有类似下面的结构，这将是您的宝藏：

```ini
[Device]
Model=KSJ-Camer

## 关键结论

原对话最后阶段给出的主要判断或处理方向：分析这个文件可以为您节省数小时甚至数天的猜测和逆向分析工作。

## 上下文关系

- 所属项目：8cb1548b62-software-01
- 当前阶段：阶段2/5
- 前置切片：大恒相机SDK替换与兼容性改造_3a032717.md
- 后续切片：确认调用约定：用CFF Explorer再次确认原始DLL中 KSJ_SetPara（T9-11）_8dd97170.md
- 附件说明：无
