---
title: "PowerShell安装配置：字体文件夹还没有配置"
source_platform: "DeepSeek"
source_file: "Fixing PowerShell Path Issue with Apostrophes.md"
turn_start: 12
turn_end: 15
primary_category: "软件开发与技术排错"
tags:
  - "PowerShell"
  - "软件开发"
project_id: "17df9e4ae1-software-03"
stage: "独立主题"
previous_slice: null
next_slice: null
has_attachment: false
attachment_context_confidence: not_applicable
classification_confidence: 0.97
---

# PowerShell安装配置：字体文件夹还没有配置

## 问题摘要

本切片围绕“PowerShell安装配置：字体文件夹还没有配置”展开。起始诉求是：字体文件夹还没有配置 后续进展或反馈是：错了，由于新电脑就两个盘所以u盘的盘符是e内容覆盖原始对话 T12-T15。

## 原始对话

仅供参考，请仔细甄别。

# 用户：

字体文件夹还没有配置

# DeepSeek：

**原始回答**

您说得对，字体文件夹确实还没有配置。我来为您创建完整的字体安装方案：

## 1. 创建字体文件夹和安装脚本

### 创建字体文件夹结构
在 U盘 `G:\powershell-dive\` 中创建 `fonts\` 文件夹，并放入常用的 Nerd Fonts：

```
G:\powershell-dive\
└── fonts\
    ├── MesloLGM NF.ttf
    ├── CascadiaCode NF.ttf
    ├── FiraCode NF.ttf
    ├── JetBrainsMono NF.ttf
    ├── UbuntuMono NF.ttf
    └── 其他需要的字体文件.ttf
```

### 更新 `Install-Fonts.ps1` 字体安装脚本

```powershell
# Install-Fonts.ps1 - 完整的字体自动安装脚本
param(
    [string]$FontsPath = "G:\powershell-dive\fonts\",
    [

工具和所有配置脚本！🎉

# 用户：

OneClick-Setup.ps1 中完整输出

# DeepSeek：

**原始回答**

# OneClick-Setup.ps1 - 完整版本

```powershell
# OneClick-Setup.ps1 - PowerShell 环境一键配置工具
param(
    [string]$UDrivePath = "G:\powershell-dive\",
    [switch]$InstallFonts,
    [switch]$InstallModules, 
    [switch]$SetupDeepSeek,
    [switch]$All,
    [switch]$SkipProfile,
    [switch]$SkipTerminal,
    [switch]$SkipTools,
    [switch]$Force
)

Write-Host ""
Write-Host "🎯 PowerShell 环境一键配置工具" -ForegroundColor Cyan
Write-Host "═════════════════════════════════════════════════

仅供参考，请仔细甄别。

# 用户：

这里面怎么没有fastfetch等安装

# DeepSeek：

**原始回答**

您说得对，我遗漏了 `fastfetch` 的安装。让我在 `OneClick-Setup.ps1` 中添加完整的 `fastfetch` 安装步骤：

## 更新后的 OneClick-Setup.ps1（包含 fastfetch）

```powershell
# OneClick-Setup.ps1 - PowerShell 环境一键配置工具
param(
    [string]$UDrivePath = "G:\powershell-dive\",
    [switch]$InstallFonts,
    [switch]$InstallModules, 
    [switch]$SetupDeepSeek,
    [switch]$All,
    [switch]$SkipProfile,
    [switch]$SkipTerminal,
    [switch]$SkipTools,
    [switch]$Force
)

Write-Host ""
Write-Host "🎯 PowerShell 环境一

仅供参考，请仔细甄别。

# 用户：

错了，由于新电脑就两个盘所以u盘的盘符是e

# DeepSeek：

**原始回答**

您说得对，U盘的盘符变成了 `E:`。我来更新所有脚本中的路径配置：

## 更新 OneClick-Setup.ps1 中的路径

```powershell
# OneClick-Setup.ps1 - PowerShell 环境一键配置工具
param(
    [string]$UDrivePath = "E:\powershell-dive\",  # 改为 E:
    [switch]$InstallFonts,
    [switch]$InstallModules, 
    [switch]$SetupDeepSeek,
    [switch]$All,
    [switch]$SkipProfile,
    [switch]$SkipTerminal,
    [switch]$SkipTools,
    [switch]$Force
)

Write-Host ""
Write-Host "🎯 PowerShell 环境一键配置工具" -ForegroundColor Cyan
Write-Host "══

## 关键结论

该切片记录了“PowerShell安装配置：字体文件夹还没有配置”的讨论过程。具体判断与操作细节以原始对话为准，旧助手结论仍需结合当前事实核验。

## 上下文关系

- 所属项目：17df9e4ae1-software-03
- 当前阶段：独立主题
- 前置切片：无
- 后续切片：无
- 附件说明：无
