---
title: "还是不满意！！，的确打开了powershell的管理员版本但是我的美化全都没了"
source_platform: "DeepSeek"
source_file: "PowerShell配置文件创建与编辑指南.md"
turn_start: 7
turn_end: 9
primary_category: "软件开发与技术排错"
tags:
  - "PowerShell"
  - "软件开发"
project_id: "78599ff0b6-software-01"
stage: "阶段3/10"
previous_slice: "在使用wt终端输入notepad $profile显示找不到指定路径：ok但是如何在使用win+r打开wt时，_05341708.md"
next_slice: "NET命令返回False排查_adccce89.md"
has_attachment: false
attachment_context_confidence: not_applicable
classification_confidence: 0.97
---

# 还是不满意！！，的确打开了powershell的管理员版本但是我的美化全都没了

## 问题摘要

本切片围绕“还是不满意！！，的确打开了powershell的管理员版本但是我的美化全都没了”展开。起始诉求是：Start-Process : 由于出现以下错误，无法运行此命令: 系统找不到指定的文件。。 所在位置 行:1 字符: 1 + Start-Process pwsh -Verb RunAs + ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ + CategoryIn… 后续进展或反馈是：如何验证方法一是否是管理员权限内容覆盖原始对话 T7-T9。

## 原始对话

您原始需求的解决方案。

# 用户：

Start-Process : 由于出现以下错误，无法运行此命令: 系统找不到指定的文件。。
所在位置 行:1 字符: 1
+ Start-Process pwsh -Verb RunAs
+ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    + CategoryInfo          : InvalidOperation: (:) [Start-Process]，InvalidOperationException
    + FullyQualifiedErrorId : InvalidOperationException,Microsoft.PowerShell.Commands.StartProcessCommand

请按任意键继续. . .

# DeepSeek：

**原始回答**

非常感谢您提供了详细的错误信息！这个错误非常明确地指出了问题所在：

**系统无法找到名为 `pwsh` 的命令。**

### 问题原因

`pwsh` 是 **PowerShell Core** (版本 7 及以上) 的可执行文件名称。而您系统上安装的可能是传统的 **Windows PowerShell** (版本 5.1)，它的可执行文件名称是 `powershell`。

当您使用 `Start-Process pwsh` 命令时，系统试图启动一个不存在的程序，因此报错“找不到指定的文件”。

---

### 解决方案

根据您想要启动的 PowerShell 版本，选择以下两种方案之一：

#### 方案一：改为启动 Windows PowerShell（最可能成功）

这是最简单直接的解决方案，因为 Windows PowerShell 是 Windows 系统自带的。

1.  **修改您的 `psadmin.bat` 批处理文件**
    *   用记事本打开 `C:\Users\Aaron Kwo'k\Script

尝试修改并告诉我结果！

# 用户：

还是不满意！！，的确打开了powershell的管理员版本但是我的美化全都没了！！！

# DeepSeek：

**原始回答**

您完全正确，我理解您的 frustration！直接启动 `powershell.exe` 会绕过 Windows Terminal，因此您所有的美化（包括字体、颜色方案、Oh My Posh 提示符等）都会丢失，因为它运行在传统的控制台主机 (conhost.exe) 中，而不是 Windows Terminal 中。

让我们解决这个根本问题：我们需要确保通过 Windows Terminal 以管理员权限启动 PowerShell。

### 完美解决方案：通过 Windows Terminal 以管理员身份启动

这是正确的方法，可以保留所有您的美化设置：

#### 方法一：使用 Windows Terminal 的命令行参数（推荐）

Windows Terminal (`wt.exe`) 支持命令行参数来指定以管理员身份启动特定配置文件。

1. **修改您的批处理文件**：
   用记事本打开您的 `psadmin.bat` 文件，将其内容替换为：

   ```batch
   @echo off
   wt new-t

，我会帮您进一步调试。

# 用户：

如何验证方法一是否是管理员权限

# DeepSeek：

**原始回答**

非常好的问题！验证是否真正获得了管理员权限是非常重要的。这里有几种可靠的方法可以验证。

### 方法一：使用 PowerShell 命令（最可靠）

在您通过方法一打开的 PowerShell 窗口中，运行以下命令之一：

#### 命令 1：使用 .NET 类（推荐）
```powershell
$currentPrincipal = New-Object Security.Principal.WindowsPrincipal([Security.Principal.WindowsIdentity]::GetCurrent())
$isAdmin = $currentPrincipal.IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)
Write-Host "当前是否为管理员权限: $isAdmin"
```
- 如果返回 `True`，则表示您拥有管理员权限。
- 如果返回 `False`，则表示是普通用户权限。

#### 命令 2：使用 whoami

## 关键结论

原对话最后阶段给出的主要判断或处理方向：方法一：使用 PowerShell 命令（最可靠） 在您通过方法一打开的 PowerShell 窗口中，运行以下命令之一： 命令 1：使用 .NET 类（推荐） 如果返回 `True`，则表示您拥有管理员权限。

## 上下文关系

- 所属项目：78599ff0b6-software-01
- 当前阶段：阶段3/10
- 前置切片：在使用wt终端输入notepad $profile显示找不到指定路径：ok但是如何在使用win+r打开wt时，_05341708.md
- 后续切片：NET命令返回False排查_adccce89.md
- 附件说明：无
