---
title: "Ghidra 中搜索中文没有任何结果"
source_platform: "DeepSeek"
source_file: "查看我之前与deepseek的对话总结，继续解决问题.md"
turn_start: 11
turn_end: 13
primary_category: "软件开发与技术排错"
tags:
  - "DeepSeek"
  - "Ghidra"
project_id: "d2bcbefbd9-software-01"
stage: "阶段4/4"
previous_slice: "DeepSeek故障排查_f66ca9b1.md"
next_slice: null
has_attachment: false
attachment_context_confidence: not_applicable
classification_confidence: 0.97
---

# Ghidra 中搜索中文没有任何结果

## 问题摘要

本切片围绕“Ghidra 中搜索中文没有任何结果”展开。起始诉求是：Ghidra 中搜索中文没有任何结果 后续进展或反馈是：使用cff explorer的十六进制编辑的“查找”功能有“字符串”区域与“区分大小写”，“unicode”选项以及“hex”区域，要如何完成上文查找内容覆盖原始对话 T11-T13。

## 原始对话

能定位到真正的检查点。

# 用户：

Ghidra 中搜索中文没有任何结果

# DeepSeek：

**原始回答**

这是一个非常常见且棘手的问题。Ghidra 默认的字符串扫描器（`ASCII Strings` 和 `Unicode Strings`）可能无法正确识别或解码程序中的中文字符串，尤其是如果字符串存储方式有些特殊（例如加密、或非标准编码）。

我们需要换用更强大的方法。请按照以下步骤操作：

### 方法一：使用高级字符串搜索（在 Ghidra 内）

1.  **确保字符串已定义**：
    -   在 Ghidra 的 "Listing" 窗口（主代码视图）中，**右键 -> Setup Strings...**。
    -   确保 `ASCII` 和 `Unicode` 选项都被勾选，并尝试调整 "Minimum Length"（最小长度），比如降低到 `3`，然后点击 "Refresh"。
    -   看看中文字符串是否会出现在新的 "Defined Strings" 列表中。

2.  **使用字节模式搜索（最有效的方法）**：
    -   我们需要将中文字符串转换为其原始的**字节序列**进行搜索。
    -  

是我们解决问题的关键。

# 用户：

1.没有找到Setup Strings...。的选项2.Ctrl+Alt+S快捷键没有用使用的是search->memory，寻找的3.两个报错为：“串口com号读取失败1！”与“串口没被打开”

# DeepSeek：

**原始回答**

感谢您提供更精确的信息！这两个具体的错误消息非常关键。您遇到的问题（找不到字符串）在Ghidra中很常见，我们需要换用更直接的方法。

### 最佳解决方案：使用十六进制编辑器直接搜索字节

这是目前最可靠、最快速的方法。我们不再依赖Ghidra的字符串识别功能，而是直接搜索程序文件中存储这些字符串的原始字节。

#### 步骤一：将中文错误消息转换为字节序列

这两个错误消息很可能是以 **GBK编码**（中文Windows程序的默认编码）存储的。

1.  **“串口com号读取失败1！”**
    -   字符串：`串口com号读取失败1！`
    -   **GBK编码十六进制序列**：
        `B4 AE BF DA 63 6F 6D BA C5 B6 C1 C8 A1 CA B5 B0 DC 31 A3 A1`
        *（`B4AE BFDA` = "串口", `63 6F 6D` = "com", `BAC5` = "号", `B6C1 C8A1` = "读取", `CAB5 B0DC` = "失败"

即将取得决定性的进展。

# 用户：

使用cff explorer的十六进制编辑的“查找”功能有“字符串”区域与“区分大小写”，“unicode”选项以及“hex”区域，要如何完成上文查找

# DeepSeek：

**原始回答**

非常好！CFF Explorer 内置的十六进制编辑器功能非常强大，完全可以完成这个任务。它的查找选项比HxD更丰富，让我们来正确配置它。

### 使用 CFF Explorer 查找中文错误消息

您的目标是找到这两个字符串的原始字节：
1.  `串口com号读取失败1！`
2.  `串口没被打开`

由于这些是中文字符串，我们需要在 **“Hex”** 区域进行搜索，而不是“字符串”区域。

#### 详细步骤：

1.  **打开CFF Explorer并启动十六进制编辑器**：
    -   用CFF Explorer打开您的`.exe`文件。
    -   点击顶部菜单栏的 **“Tools”** -> **“Hex Editor”**。

2.  **打开查找对话框**：
    -   在十六进制编辑器窗口中，按 **`Ctrl+F`** 快捷键，打开“查找”对话框。

3.  **关键配置：搜索第一个字符串 `串口com号读取失败1！`**
    -   在“查找”对话框中，您会看到两个主要的输入区域：“**字符串

## 关键结论

原对话最后阶段给出的主要判断或处理方向：CFF Explorer 内置的十六进制编辑器功能非常强大，完全可以完成这个任务。` 2. `串口没被打开` 由于这些是中文字符串，我们需要在 **“Hex”** 区域进行搜索，而不是“字符串”区域。

## 上下文关系

- 所属项目：d2bcbefbd9-software-01
- 当前阶段：阶段4/4
- 前置切片：DeepSeek故障排查_f66ca9b1.md
- 后续切片：无
- 附件说明：无
