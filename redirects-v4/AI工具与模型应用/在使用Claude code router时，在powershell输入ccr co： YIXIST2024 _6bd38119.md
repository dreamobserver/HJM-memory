---
title: "在使用Claude code router时，在powershell输入ccr co： YIXIST2024 "
source_platform: "DeepSeek"
source_file: "Claude Code Router报错解决方案.md"
turn_start: 17
turn_end: 20
primary_category: "AI工具与模型应用"
tags:
  - "Claude Code"
  - "PowerShell"
project_id: "90e4542910-ai-tools-02"
stage: "阶段1/2"
previous_slice: null
next_slice: "在使用Claude code router时，在powershell输入ccr co（T21-25）_3a20f116.md"
has_attachment: false
attachment_context_confidence: not_applicable
classification_confidence: 0.97
---

# 在使用Claude code router时，在powershell输入ccr co： YIXIST2024 

## 问题摘要

本切片围绕“在使用Claude code router时，在powershell输入ccr co： YIXIST2024 ”展开。起始诉求是： YIXIST2024       0ms   9:20 AM     ⚡Aaron Kwo'k ❯❯  YIXIST2024       0ms   9:20 AM     ⚡Aaron Kwo'k ❯❯ Add-Cont… 后续进展或反馈是：ok，我决定删除有特殊字符文件夹下的ccr，并且在D:\ccr文件夹中，是否可以正常使用内容覆盖原始对话 T17-T20。

## 原始对话

彻底和永久的解决方案。

# 用户：

 YIXIST2024       0ms   9:20 AM   
  ⚡Aaron Kwo'k ❯❯
 YIXIST2024       0ms   9:20 AM   
  ⚡Aaron Kwo'k ❯❯ Add-Content -Path $profile -Value $profileContent
 YIXIST2024       2ms   9:20 AM   
  ⚡Aaron Kwo'k ❯❯
 YIXIST2024       0ms   9:20 AM   
  ⚡Aaron Kwo'k ❯❯ # 7. 测试
 YIXIST2024       1ms   9:20 AM   
  ⚡Aaron Kwo'k ❯❯ ccr code
& : 无法将“C:\npm-global\ccr.cmd”项识别为 cmdlet、函数、脚本文件或可运行程序的名称。请检查名称的拼写，如果包括路径，
请确保路径正确，然后再试一次。
所在位置 行:2 字符: 7
+     & "$newGlobalPath\ccr.cmd" @args
+       ~~~~~~~~~~~~~~~~~~~~~~~~
    + CategoryInfo          : ObjectNotFound: (C:\npm-global\ccr.cmd:String) [], CommandNotFoundException
    + FullyQualifiedErrorId : CommandNotFoundException

 YIXIST2024       44ms   9:20 AM   
  ⚡Aaron Kwo'k ❯❯
 YIXIST2024       0ms   9:20 AM   
  ⚡Aaron Kwo'k ❯❯
 YIXIST2024       0ms   9:20 AM   
  ⚡Aaron Kwo'k ❯❯ ccr c
& : 无法将“C:\npm-global\ccr.cmd”项识别为 cmdlet、函数、脚本文件或可运行程序的名称。请检查名称的拼写，如果包括路径，
请确保路径正确，然后再试一次。
所在位置 行:2 字符: 7
+     & "$newGlobalPath\ccr.cmd" @args
+       ~~~~~~~~~~~~~~~~~~~~~~~~
    + CategoryInfo          : ObjectNotFound: (C:\npm-global\ccr.cmd:String) [], CommandNotFoundException
    + FullyQualifiedErrorId : CommandNotFoundException

# DeepSeek：

**原始回答**

看起来新路径 `C:\npm-global` 下还没有 `ccr.cmd` 文件。这是因为我们更改了 npm 的全局安装路径，但还没有重新安装 Claude Code Router 到新位置。让我们完成这个设置：

```powershell
# 1. 首先确保新路径已正确设置
npm config get prefix

# 2. 重新安装 Claude Code Router 到新位置
npm install -g @musistudio/claude-code-router

# 3. 验证新位置是否有 ccr.cmd
Test-Path "C:\npm-global\ccr.cmd"

# 4. 如果上面返回 False，可能需要手动创建链接或重新配置
# 检查 npm 的全局安装目录
npm root -g

# 5. 如果 npm root -g 显示的不是 C:\npm-global，需要重新设置
npm config set prefix "C:\npm-global"
npm install -g @musistudio

ode.js 的方法。

# 用户：

 YIXIST2024       1ms   9:20 AM   
  ⚡Aaron Kwo'k ❯❯ ccr code
& : 无法将“C:\npm-global\ccr.cmd”项识别为 cmdlet、函数、脚本文件或可运行程序的名称。请检查名称的拼写，如果包括路径，
请确保路径正确，然后再试一次。
所在位置 行:2 字符: 7
+     & "$newGlobalPath\ccr.cmd" @args
+       ~~~~~~~~~~~~~~~~~~~~~~~~
    + CategoryInfo          : ObjectNotFound: (C:\npm-global\ccr.cmd:String) [], CommandNotFoundException
    + FullyQualifiedErrorId : CommandNotFoundException

 YIXIST2024       44ms   9:20 AM   
  ⚡Aaron Kwo'k ❯❯
 YIXIST2024       0ms   9:20 AM   
  ⚡Aaron Kwo'k ❯❯
 YIXIST2024       0ms   9:20 AM   
  ⚡Aaron Kwo'k ❯❯ ccr c
& : 无法将“C:\npm-global\ccr.cmd”项识别为 cmdlet、函数、脚本文件或可运行程序的名称。请检查名称的拼写，如果包括路径，
请确保路径正确，然后再试一次。
所在位置 行:2 字符: 7
+     & "$newGlobalPath\ccr.cmd" @args
+       ~~~~~~~~~~~~~~~~~~~~~~~~
    + CategoryInfo          : ObjectNotFound: (C:\npm-global\ccr.cmd:String) [], CommandNotFoundException
    + FullyQualifiedErrorId : CommandNotFoundException

 YIXIST2024       7ms   9:20 AM   
  ⚡Aaron Kwo'k ❯❯ # 1. 首先确保新路径已正确设置
 YIXIST2024       0ms   9:21 AM   
  ⚡Aaron Kwo'k ❯❯ npm config get prefix
C:\Program Files\nodejs\\node.exe: --experimental-globals is not allowed in NODE_OPTIONS
C:\Program Files\nodejs\\node.exe: --experimental-globals is not allowed in NODE_OPTIONS
 YIXIST2024       128ms   9:21 AM   
  ⚡Aaron Kwo'k ❯❯
 YIXIST2024       0ms   9:21 AM   
  ⚡Aaron Kwo'k ❯❯ # 2. 重新安装 Claude Code Router 到新位置
 YIXIST2024       0ms   9:21 AM   
  ⚡Aaron Kwo'k ❯❯ npm install -g @musistudio/claude-code-router
C:\Program Files\nodejs\\node.exe: --experimental-globals is not allowed in NODE_OPTIONS
C:\Program Files\nodejs\\node.exe: --experimental-globals is not allowed in NODE_OPTIONS
 YIXIST2024       154ms   9:21 AM   
  ⚡Aaron Kwo'k ❯❯
 YIXIST2024       0ms   9:21 AM   
  ⚡Aaron Kwo'k ❯❯ # 3. 验证新位置是否有 ccr.cmd
 YIXIST2024       0ms   9:21 AM   
  ⚡Aaron Kwo'k ❯❯ Test-Path "C:\npm-global\ccr.cmd"
False
 YIXIST2024       0ms   9:21 AM   
  ⚡Aaron Kwo'k ❯❯
 YIXIST2024       0ms   9:21 AM   
  ⚡Aaron Kwo'k ❯❯ # 4. 如果上面返回 False，可能需要手动创建链接或重新配置
 YIXIST2024       0ms   9:21 AM   
  ⚡Aaron Kwo'k ❯❯ # 检查 npm 的全局安装目录
 YIXIST2024       0ms   9:21 AM   
  ⚡Aaron Kwo'k ❯❯ npm root -g
C:\Program Files\nodejs\\node.exe: --experimental-globals is not allowed in NODE_OPTIONS
C:\Program Files\nodejs\\node.exe: --experimental-globals is not allowed in NODE_OPTIONS
 YIXIST2024       83ms   9:21 AM   
  ⚡Aaron Kwo'k ❯❯
 YIXIST2024       0ms   9:21 AM   
  ⚡Aaron Kwo'k ❯❯ # 5. 如果 npm root -g 显示的不是 C:\npm-global，需要重新设置
 YIXIST2024       0ms   9:21 AM   
  ⚡Aaron Kwo'k ❯❯ npm config set prefix "C:\npm-global"
C:\Program Files\nodejs\\node.exe: --experimental-globals is not allowed in NODE_OPTIONS
C:\Program Files\nodejs\\node.exe: --experimental-globals is not allowed in NODE_OPTIONS
 YIXIST2024       85ms   9:21 AM   
  ⚡Aaron Kwo'k ❯❯ npm install -g @musistudio/claude-code-router
C:\Program Files\nodejs\\node.exe: --experimental-globals is not allowed in NODE_OPTIONS
C:\Program Files\nodejs\\node.exe: --experimental-globals is not allowed in NODE_OPTIONS
 YIXIST2024       108ms   9:21 AM   
  ⚡Aaron Kwo'k ❯❯
 YIXIST2024       0ms   9:21 AM   
  ⚡Aaron Kwo'k ❯❯ # 6. 再次验证
 YIXIST2024       0ms   9:21 AM   
  ⚡Aaron Kwo'k ❯❯ Test-Path "C:\npm-global\ccr.cmd"
False
 YIXIST2024       0ms   9:21 AM   
  ⚡Aaron Kwo'k ❯❯
 YIXIST2024       0ms   9:21 AM   
  ⚡Aaron Kwo'k ❯❯ # 7. 如果仍然没有，尝试使用 npx
 YIXIST2024       0ms   9:21 AM   
  ⚡Aaron Kwo'k ❯❯ npx @musistudio/claude-code-router code
C:\Program Files\nodejs\\node.exe: --experimental-globals is not allowed in NODE_OPTIONS
C:\Program Files\nodejs\\node.exe: --experimental-globals is not allowed in NODE_OPTIONS
 YIXIST2024       94ms   9:21 AM   
  ⚡Aaron Kwo'k ❯❯
 YIXIST2024       0ms   9:21 AM   
  ⚡Aaron Kwo'k ❯❯ # 8. 或者直接使用节点运行
 YIXIST2024       0ms   9:21 AM   
  ⚡Aaron Kwo'k ❯❯ node "C:\npm-global\node_modules\@musistudio\claude-code-router\dist\cli.js" code
C:\Program Files\nodejs\node.exe: --experimental-globals is not allowed in NODE_OPTIONS
 YIXIST2024       39ms   9:21 AM   
  ⚡Aaron Kwo'k ❯❯

# DeepSeek：

**原始回答**

看起来 `NODE_OPTIONS` 环境变量中设置了 `--experimental-globals`，这导致所有 Node.js 命令都失败。让我们先解决这个问题，然后再继续：

## 第一步：清除有问题的 NODE_OPTIONS 环境变量

```powershell
# 1. 清除当前的 NODE_OPTIONS 环境变量
$env:NODE_OPTIONS = $null

# 2. 从用户环境中永久移除
[Environment]::SetEnvironmentVariable("NODE_OPTIONS", $null, "User")

# 3. 从机器环境中检查并移除（如果需要）
[Environment]::SetEnvironmentVariable("NODE_OPTIONS", $null, "Machine")

# 4. 验证 NODE_OPTIONS 已被清除
echo "NODE_OPTIONS: $env:NODE_OPTIONS"
```

## 第二步：使用直接调用 Node.js 的方法

既然

这应该能解决您的问题。

# 用户：

全部运行完后新的报错出现了：  ⚡Aaron Kwo'k ❯❯ ccr code
Service not running, starting service...
C:\ccr-wrapper.js:14
require('C:\\Users\\AARONK~1\\AppData\\Roaming\\npm\\node_modules\\@musistudio\\claude-code-router\\dist\\cli.js').main();
                                                                                                                   ^

TypeError: require(...).main is not a function
    at Object.<anonymous> (C:\ccr-wrapper.js:14:116)
    at Module._compile (node:internal/modules/cjs/loader:1356:14)
    at Module._extensions..js (node:internal/modules/cjs/loader:1414:10)
    at Module.load (node:internal/modules/cjs/loader:1197:32)
    at Module._load (node:internal/modules/cjs/loader:1013:12)
    at Function.executeUserEntryPoint [as runMain] (node:internal/modules/run_main:128:12)
    at node:internal/main/run_main_module:28:49

Node.js v18.19.0

# DeepSeek：

**原始回答**

这个错误表明 `require(...).main` 不是一个函数。这意味着 Claude Code Router 的 CLI 模块可能没有直接导出 `main` 函数，或者导出方式不同。让我们修复包装脚本：

## 修复包装脚本

```powershell
# 1. 创建修正后的包装脚本
$fixedWrapperScript = @"
// 设置全局 File 对象
if (typeof global.File === 'undefined') {
    global.File = class File {
        constructor(blobParts, name, options) {
            this.name = name || '';
            this.size = 0;
            this.type = options?.type || '';
            this.lastModified = options?.lastModified || Da

法应该能解决您的问题。

# 用户：

ok，我决定删除有特殊字符文件夹下的ccr，并且在D:\ccr文件夹中，是否可以正常使用

# DeepSeek：

**原始回答**

非常好！将 Claude Code Router 安装到 `D:\ccr` 文件夹是一个很明智的决定，这样可以完全避免路径中的特殊字符问题。以下是完整的设置步骤：

## 第一步：完全清除旧安装

```powershell
# 1. 卸载全局安装的 Claude Code Router
npm uninstall -g @musistudio/claude-code-router

# 2. 清除 npm 缓存
npm cache clean --force

# 3. 删除可能存在的旧配置文件
Remove-Item -Path "C:\Users\AARONK~1\AppData\Roaming\npm\ccr.cmd" -ErrorAction SilentlyContinue
Remove-Item -Path "C:\Users\AARONK~1\AppData\Roaming\npm\ccr" -ErrorAction SilentlyContinue
```

## 第二步：设置新的全局安装路径

```powershel

## 关键结论

原对话最后阶段给出的主要判断或处理方向：将 Claude Code Router 安装到 `D:\ccr` 文件夹是一个很明智的决定，这样可以完全避免路径中的特殊字符问题。

## 上下文关系

- 所属项目：90e4542910-ai-tools-02
- 当前阶段：阶段1/2
- 前置切片：无
- 后续切片：在使用Claude code router时，在powershell输入ccr co（T21-25）_3a20f116.md
- 附件说明：无
