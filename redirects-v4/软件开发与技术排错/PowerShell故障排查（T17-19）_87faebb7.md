---
title: "PowerShell故障排查（T17-19）"
source_platform: "DeepSeek"
source_file: "PowerShell配置文件创建与编辑指南.md"
turn_start: 17
turn_end: 19
primary_category: "软件开发与技术排错"
tags:
  - "PowerShell"
  - "软件开发"
project_id: "78599ff0b6-software-01"
stage: "阶段6/10"
previous_slice: "又出现问题了！运行完psadmin.bat后只有一个cmd窗口，在代码后加入paus_67412652.md"
next_slice: "PowerShell安装配置_29564572.md"
has_attachment: false
attachment_context_confidence: not_applicable
classification_confidence: 0.97
---

# PowerShell故障排查（T17-19）

## 问题摘要

本切片围绕“PowerShell故障排查（T17-19）”展开。起始诉求是：使用步骤一Start-Process : 由于出现以下错误，无法运行此命令: 系统找不到指定的文件。。 所在位置 行:1 字符: 1 + Start-Process pwsh -Verb RunAs -WindowStyle Hidden + ~~~~~~~~~~~~~~~~~~… 后续进展或反馈是：重新创建 PowerShell 脚本这个方法会弹出UAC窗口，且powershell窗口会闪退内容覆盖原始对话 T17-T19。

## 原始对话

，我会帮您进一步调整。

# 用户：

使用步骤一Start-Process : 由于出现以下错误，无法运行此命令: 系统找不到指定的文件。。
所在位置 行:1 字符: 1
+ Start-Process pwsh -Verb RunAs -WindowStyle Hidden
+ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    + CategoryInfo          : InvalidOperation: (:) [Start-Process]，InvalidOperationException
    + FullyQualifiedErrorId : InvalidOperationException,Microsoft.PowerShell.Commands.StartProcessCommand


[已退出进程，代码为 1 (0x00000001)]
现在可以使用Ctrl+D关闭此终端，或按 Enter 重新启动。

# DeepSeek：

**原始回答**

这个错误再次确认了您的系统上没有安装 PowerShell Core（`pwsh`），而是使用的是传统的 Windows PowerShell（`powershell`）。让我们修正命令，使用正确的可执行文件名称。

### 修正后的解决方案

#### 步骤 1：修改批处理文件使用正确的 PowerShell 可执行文件

将您的 `psadmin.bat` 文件内容修改为：

```batch
@echo off
wt -p "Windows PowerShell" powershell -Command "Start-Process powershell -Verb RunAs -WindowStyle Hidden"
```

或者更明确地指定完整路径：

```batch
@echo off
wt -p "Windows PowerShell" powershell -Command "Start-Process '%SystemRoot%\System32\WindowsPowerShell\v1.0\powershell.e

，我会继续帮助您解决。

# 用户：

方法二所在位置 C:\Users\Aaron Kwo'k\Scripts\Launch-Elevated.ps1:22 字符: 12
+ Write-Host "鎵€鏈夋柟娉曢兘澶辫触浜嗭紝璇锋鏌ョ郴缁熼厤缃€?
+            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
字符串缺少终止符: "。
    + CategoryInfo          : ParserError: (:) [], ParentContainsErrorRecordException
    + FullyQualifiedErrorId : TerminatorExpectedAtEndOfString


[已退出进程，代码为 1 (0x00000001)]
现在可以使用Ctrl+D关闭此终端，或按 Enter 重新启动。

# DeepSeek：

**原始回答**

这个错误很明显是由于字符编码问题导致的。PowerShell 脚本中的中文字符在保存时可能被错误地编码，导致了乱码和语法错误。让我们修复这个问题。

### 修复字符编码问题

#### 步骤 1：重新创建 PowerShell 脚本

1. 打开记事本
2. 复制以下内容（确保使用英文标点）：
```powershell
# 尝试多种方式启动提升权限的 PowerShell
try {
    # 方法1: 使用 Start-Process
    $process = Start-Process powershell -Verb RunAs -PassThru -WindowStyle Hidden
    Start-Sleep -Milliseconds 500
    if ($process.Id) { exit }
}
catch {
    Write-Host "Method 1 failed: $($_.Exception.Message)"
}

try {
    # 方法2: 使用 WMI
    $proces

可以避免文件编码问题。

# 用户：

重新创建 PowerShell 脚本这个方法会弹出UAC窗口，且powershell窗口会闪退

# DeepSeek：

**原始回答**

您遇到的问题很常见。让我提供一个更可靠、更简单的解决方案，避免脚本复杂性和编码问题。

### 简化的一步解决方案

让我们回到最基本的批处理文件方法，但使用更可靠的语法：

#### 方案 1：直接使用批处理文件

创建一个简单的 `psadmin.bat` 文件，内容如下：

```batch
@echo off
:: 直接启动 Windows Terminal 并以管理员权限运行 PowerShell
powershell -Command "Start-Process wt -ArgumentList '-p', 'Windows PowerShell' -Verb RunAs"
```

这个命令会：
1. 显示 UAC 提示（这是无法完全避免的）
2. 在获得批准后，启动带有管理员权限的 Windows Terminal

#### 方案 2：使用 VBScript 隐藏初始窗口

如果您想隐藏最初的 PowerShell 窗口，可以使用这个方案：

1. 创建 `psadmin.vbs` 文件：
```vbscript
Se

## 关键结论

原对话最后阶段给出的主要判断或处理方向：原始回答** 您遇到的问题很常见。让我提供一个更可靠、更简单的解决方案，避免脚本复杂性和编码问题。

## 上下文关系

- 所属项目：78599ff0b6-software-01
- 当前阶段：阶段6/10
- 前置切片：又出现问题了！运行完psadmin.bat后只有一个cmd窗口，在代码后加入paus_67412652.md
- 后续切片：PowerShell安装配置_29564572.md
- 附件说明：无
