---
title: "PowerShell故障排查（T28-30）"
source_platform: "DeepSeek"
source_file: "PowerShell配置文件创建与编辑指南.md"
turn_start: 28
turn_end: 30
primary_category: "软件开发与技术排错"
tags:
  - "PowerShell"
  - "软件开发"
project_id: "78599ff0b6-software-01"
stage: "阶段9/10"
previous_slice: "PowerShell故障排查（T23-27）_0eb51314.md"
next_slice: "Swap交换空间超限解释_d94d7941.md"
has_attachment: false
attachment_context_confidence: not_applicable
classification_confidence: 0.97
---

# PowerShell故障排查（T28-30）

## 问题摘要

本切片围绕“PowerShell故障排查（T28-30）”展开。起始诉求是：Set-PSReadLineKeyHandler : Unrecognized key 'Space'. Please use a character literal or a well-known key name from the S ystem.ConsoleKey enu… 后续进展或反馈是：Test-Administrator : 无法将“Test-Administrator”项识别为 cmdlet、函数、脚本文件或可运行程序的名称。请检查名称的拼写， 如果包括路径，请确保路径正确，然后再试一次。 所在位置 C:\Users\Aaron Kwo'k\Document…内容覆盖原始对话 T28-T30。

## 原始对话

的强大自动补全功能了！

# 用户：

Set-PSReadLineKeyHandler : Unrecognized key 'Space'. Please use a character literal or a well-known key name from the S
ystem.ConsoleKey enumeration.
所在位置 C:\Users\Aaron Kwo'k\Documents\WindowsPowerShell\Microsoft.PowerShell_profile.ps1:14 字符: 1
+ Set-PSReadLineKeyHandler -Key Ctrl+Space -Function Complete
+ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    + CategoryInfo          : NotSpecified: (:) [Set-PSReadLineKeyHandler], ArgumentException
    + FullyQualifiedErrorId : System.ArgumentException,Microsoft.PowerShell.SetPSReadLineKeyHandlerCommand

# DeepSeek：

**原始回答**

这个错误是因为 `Ctrl+Space` 的语法不正确。在 PSReadLine 中，组合键的指定方式有特定的格式。让我为您提供正确的配置方法。

### 修正后的 PSReadLine 配置

请修改您的配置文件中的相关行：

```powershell
# 错误的写法：
# Set-PSReadLineKeyHandler -Key Ctrl+Space -Function Complete

# 正确的写法：
Set-PSReadLineKeyHandler -Chord 'Ctrl+Space' -Function Complete
```

### 完整的修正版配置文件

这是您应该使用的完整正确配置：

```powershell
# 导入 PSReadLine 模块
Import-Module PSReadLine

# 设置编辑模式和预测源
Set-PSReadLineOption -EditMode Windows
Set-PSReadLineOption -PredictionSource History
Set-PS

息，我会继续帮您解决！

# 用户：

Set-PSReadLineKeyHandler : Unrecognized key 'Space'. Please use a character literal or a well-known key name from the S
ystem.ConsoleKey enumeration.
所在位置 C:\Users\Aaron Kwo'k\Documents\WindowsPowerShell\Microsoft.PowerShell_profile.ps1:17 字符: 1
+ Set-PSReadLineKeyHandler -Chord 'Ctrl+Space' -Function Complete
+ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    + CategoryInfo          : NotSpecified: (:) [Set-PSReadLineKeyHandler], ArgumentException
    + FullyQualifiedErrorId : System.ArgumentException,Microsoft.PowerShell.SetPSReadLineKeyHandlerCommand

Set-PSReadLineOption : 找不到与参数名称“ShowToolTips#”匹配的参数。
所在位置 C:\Users\Aaron Kwo'k\Documents\WindowsPowerShell\Microsoft.PowerShell_profile.ps1:34 字符: 22
+ Set-PSReadLineOption -ShowToolTips# 妫€鏌ユ槸鍚︿负绠＄悊鍛樻潈闄?
+                      ~~~~~~~~~~~~~~
    + CategoryInfo          : InvalidArgument: (:) [Set-PSReadLineOption]，ParameterBindingException
    + FullyQualifiedErrorId : NamedParameterNotFound,Microsoft.PowerShell.SetPSReadLineOption

# DeepSeek：

**原始回答**

看到这两个错误了！一个是 `Ctrl+Space` 的问题，另一个是字符编码问题导致的乱码。让我们一步步解决。

## 问题一：Ctrl+Space 不被识别

在某些版本的 PSReadLine 或 PowerShell 中，`Space` 键确实不能被直接绑定。我们需要使用替代方案。

### 修正后的配置

请将您的配置文件修改为以下内容：

```powershell
# 导入 PSReadLine 模块
Import-Module PSReadLine

# 基本设置
Set-PSReadLineOption -EditMode Windows
Set-PSReadLineOption -PredictionSource History
Set-PSReadLineOption -PredictionViewStyle ListView

# 使用 Tab 键进行菜单式补全（这是最常用的）
Set-PSReadLineKeyHandler -Key Tab -Function MenuComplete

# 替代方案：使用其他组

强大的自动补全功能了！

# 用户：

Test-Administrator : 无法将“Test-Administrator”项识别为 cmdlet、函数、脚本文件或可运行程序的名称。请检查名称的拼写，
如果包括路径，请确保路径正确，然后再试一次。
所在位置 C:\Users\Aaron Kwo'k\Documents\WindowsPowerShell\Microsoft.PowerShell_profile.ps1:43 字符: 5
+ if (Test-Administrator) {
+     ~~~~~~~~~~~~~~~~~~
    + CategoryInfo          : ObjectNotFound: (Test-Administrator:String) [], CommandNotFoundException
    + FullyQualifiedErrorId : CommandNotFoundException

# DeepSeek：

**原始回答**

这个错误是因为在您的配置文件中调用了 `Test-Administrator` 函数，但这个函数还没有被定义。您需要先定义这个函数，然后再调用它。

### 解决方案：在配置文件中添加缺失的函数

请在您的 `$PROFILE` 文件的开头部分添加这个函数定义：

```powershell
# 检查是否为管理员权限的函数
function Test-Administrator {
    $currentUser = [Security.Principal.WindowsIdentity]::GetCurrent()
    $principal = New-Object Security.Principal.WindowsPrincipal($currentUser)
    return $principal.IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)
}

# 然后在后面使用这个函数
if (Test-Administrator) {
    #

## 关键结论

原对话最后阶段给出的主要判断或处理方向：您需要先定义这个函数，然后再调用它。解决方案：在配置文件中添加缺失的函数 请在您的 `$PROFILE` 文件的开头部分添加这个函数定义： ```powershell 检查是否为管理员权限的函数 function Test-Administrator { $currentUser = [Security.Principal.WindowsIdentity]::GetCurrent() $principal = New-Object Security.Principal.WindowsPrincipal($currentUser) return $principal.IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator) } 然后在后面使用这个函数 if (Test-Administrator) {

## 上下文关系

- 所属项目：78599ff0b6-software-01
- 当前阶段：阶段9/10
- 前置切片：PowerShell故障排查（T23-27）_0eb51314.md
- 后续切片：Swap交换空间超限解释_d94d7941.md
- 附件说明：无
