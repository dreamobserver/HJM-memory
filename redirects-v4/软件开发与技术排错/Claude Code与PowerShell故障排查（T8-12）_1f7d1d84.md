---
title: "Claude Code与PowerShell故障排查（T8-12）"
source_platform: "DeepSeek"
source_file: "Claude Code Router报错解决方案.md"
turn_start: 8
turn_end: 12
primary_category: "软件开发与技术排错"
tags:
  - "Claude Code"
  - "PowerShell"
project_id: "90e4542910-software-01"
stage: "阶段2/3"
previous_slice: "Claude Code与PowerShell故障排查（T1-7）_e3577c6e.md"
next_slice: "Claude Code与PowerShell故障排查（T13-16）_719a2184.md"
has_attachment: false
attachment_context_confidence: not_applicable
classification_confidence: 0.97
---

# Claude Code与PowerShell故障排查（T8-12）

## 问题摘要

本切片围绕“Claude Code与PowerShell故障排查（T8-12）”展开。起始诉求是： ⚡Aaron Kwo'k ❯❯ cmd /c "dir /x C:\Users\Aaron*" 驱动器 C 中的卷是 OS 卷的序列号是 9249-1EBD C:\Users 的目录 2025-05-16 16:09 18,872 Aaron 2025-09-03 17:25… 后续进展或反馈是：由于我的powershell有过美化，使用oh-my-posh，fastfetch已经有了预加载个人配置，重新给出解决方法内容覆盖原始对话 T8-T12。

## 原始对话

能给出精确的修复代码。

# 用户：

  ⚡Aaron Kwo'k ❯❯ cmd /c "dir /x C:\Users\Aaron*"
 驱动器 C 中的卷是 OS
 卷的序列号是 9249-1EBD

 C:\Users 的目录

2025-05-16  16:09            18,872              Aaron
2025-09-03  17:25    <DIR>          AARONK~1     Aaron Kwo'k
2025-05-16  16:09           274,164              Aaron_000_vcRuntimeMinimum_x64.log
2025-05-16  16:08           254,916              Aaron_000_vcRuntimeMinimum_x86.log
2025-05-16  16:09           265,334              Aaron_001_vcRuntimeAdditional_x64.log
2025-05-16  16:08           257,354              Aaron_001_vcRuntimeAdditional_x86.log
               5 个文件      1,070,640 字节
               1 个目录 20,898,553,856 可用字节

# DeepSeek：

**原始回答**

很好！我看到您的短名称是 `AARONK~1`。现在让我为您提供准确的修复方案：

## 方案 1：直接使用正确的路径

```powershell
# 使用正确的转义路径
node -e "global.File = class File {}; require('C:\\\\Users\\\\AARONK~1\\\\AppData\\\\Roaming\\\\npm\\\\node_modules\\\\@musistudio\\\\claude-code-router\\\\dist\\\\cli.js').main()" code
```

## 方案 2：创建永久 PowerShell 函数

```powershell
# 编辑 PowerShell 配置文件
notepad $profile

# 在打开的文件中添加以下内容：
function ccr-fixed {
    $jsCode = @"
    if (typeof global.File === 'undefined') {
        global.F

提供最准确的解决方案。

# 用户：

Usage: ccr [command]

Commands:
  start         Start server
  stop          Stop server
  restart       Restart server
  status        Show server status
  statusline    Integrated statusline
  code          Execute claude command
  ui            Open the web UI in browser
  -v, version   Show version information
  -h, help      Show help information

Example:
  ccr start
  ccr code "Write a Hello World"
  ccr ui
这算运行成功吗？如果是，我使用的是创建永久 PowerShell 函数方法，是否下次打开powershell直接输入ccr code就可以正常运行

# DeepSeek：

**原始回答**

是的！**这完全运行成功了！** 🎉

您看到的正是 Claude Code Router 的正常帮助信息，说明程序已经正确加载并运行了。

## 关于永久函数的问题

**是的，如果您使用了创建永久 PowerShell 函数的方法，下次打开 PowerShell 直接输入 `ccr code` 就可以正常运行。**

但是需要确保您正确设置了 PowerShell 配置文件。让我为您确认一下步骤：

## 验证和设置永久函数

```powershell
# 1. 首先检查配置文件是否存在
Test-Path $profile

# 2. 如果不存在，创建它
if (!(Test-Path $profile)) {
    New-Item -ItemType File -Path $profile -Force
}

# 3. 添加函数到配置文件
$functionCode = @"
function ccr-fixed {
    `$jsCode = @"
    if (typeof global.File === 'unde

 Router 了。🚀

# 用户：

  ⚡Aaron Kwo'k ❯❯     node -e "`$jsCode" @args
[eval]:1
$jsCode
^

ReferenceError: $jsCode is not defined
    at [eval]:1:1
    at Script.runInThisContext (node:vm:122:12)
    at Object.runInThisContext (node:vm:298:38)
    at node:internal/process/execution:82:21
    at [eval]-wrapper:6:24
    at runScript (node:internal/process/execution:81:62)
    at evalScript (node:internal/process/execution:103:10)
    at node:internal/main/eval_string:30:3

Node.js v18.19.0
 YIXIST2024       68ms   9:02 AM   
  ⚡Aaron Kwo'k ❯❯ }
所在位置 行:1 字符: 1
+ }
+ ~
表达式或语句中包含意外的标记“}”。
    + CategoryInfo          : ParserError: (:) [], ParentContainsErrorRecordException
    + FullyQualifiedErrorId : UnexpectedToken

# DeepSeek：

**原始回答**

看起来在 PowerShell 变量处理上有些问题。让我为您提供一个更简单可靠的解决方案：

## 方案 1：使用临时文件的永久函数

```powershell
# 编辑配置文件
notepad $profile

# 在打开的文件中添加以下内容：
function ccr {
    $tempFile = "$env:TEMP\ccr_temp.js"
    $jsCode = @"
if (typeof global.File === 'undefined') {
    global.File = class File {
        constructor(blobParts, name, options) {
            this.name = name || '';
            this.size = 0;
            this.type = options?.type || '';
            this.lastModified = options?.lastModi

方案1的临时文件方法。

# 用户：

我使用最简单的永久函数，单次可以成功出现ccr code。但是重启powershell后直接运行ccr code还是不行

# DeepSeek：

**原始回答**

这个问题是因为 PowerShell 配置文件没有正确加载。让我们解决这个问题：

## 检查配置文件状态

```powershell
# 1. 首先检查配置文件路径
echo $profile

# 2. 检查配置文件是否存在
Test-Path $profile

# 3. 如果不存在，创建它
if (!(Test-Path $profile)) {
    New-Item -ItemType File -Path $profile -Force
    Write-Host "配置文件已创建: $profile"
}

# 4. 查看当前配置文件内容
Get-Content $profile -ErrorAction SilentlyContinue
```

## 正确设置配置文件

```powershell
# 清空并重新写入配置文件
$profileContent = @"
# Claude Code Router 修复函数
function ccr {
    `$env:NODE_OPTIONS = "--exper

PATH 环境变量问题

# 用户：

由于我的powershell有过美化，使用oh-my-posh，fastfetch已经有了预加载个人配置，重新给出解决方法

# DeepSeek：

**原始回答**

明白了！由于您使用了 oh-my-posh，配置文件可能已经存在并且有特殊结构。让我提供与现有配置兼容的解决方案：

## 方案 1：在现有配置文件中添加函数

```powershell
# 首先查看当前的配置文件内容
code $profile  # 或者用 notepad $profile

# 在文件末尾添加以下内容（不要删除现有内容）：

# Claude Code Router 修复函数
function ccr {
    $env:NODE_OPTIONS = "--experimental-globals"
    & "C:\Users\AARONK~1\AppData\Roaming\npm\ccr.cmd" @args
}
```

## 方案 2：使用 PowerShell 模块方式

```powershell
# 创建专门的模块文件
$moduleDir = "$HOME\Documents\PowerShell\Modules\CcrFix"
New-Item -ItemType Directory -Pa

## 关键结论

原对话最后阶段给出的主要判断或处理方向：让我提供与现有配置兼容的解决方案： 方案 1：在现有配置文件中添加函数 方案 2：使用 PowerShell 模块方式 ```powershell 创建专门的模块文件 $moduleDir = "$HOME\Documents\PowerShell\Modules\CcrFix" New-Item -ItemType Directory -Pa

## 上下文关系

- 所属项目：90e4542910-software-01
- 当前阶段：阶段2/3
- 前置切片：Claude Code与PowerShell故障排查（T1-7）_e3577c6e.md
- 后续切片：Claude Code与PowerShell故障排查（T13-16）_719a2184.md
- 附件说明：无
