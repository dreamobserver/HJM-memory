---
title: "在使用Claude code router时，在powershell输入ccr co（T21-25）"
source_platform: "DeepSeek"
source_file: "Claude Code Router报错解决方案.md"
turn_start: 21
turn_end: 25
primary_category: "AI工具与模型应用"
tags:
  - "Claude Code"
  - "PowerShell"
  - "API"
  - "端口映射"
project_id: "90e4542910-ai-tools-02"
stage: "阶段2/2"
previous_slice: "在使用Claude code router时，在powershell输入ccr co： YIXIST2024 _6bd38119.md"
next_slice: null
has_attachment: false
attachment_context_confidence: not_applicable
classification_confidence: 0.97
---

# 在使用Claude code router时，在powershell输入ccr co（T21-25）

## 问题摘要

本切片围绕“在使用Claude code router时，在powershell输入ccr co（T21-25）”展开。起始诉求是：等一下我的ccr在C:\Users\Aaron Kwo'k\.cluade-code-router中有个自定义的config.json。重新安装后这个设置文件在特殊字符文件夹中是否可以正常运转 后续进展或反馈是：PS C:\Users\Aaron Kwo'k> ccr code "写一个简单的Python程序" Service not running, starting service... Service startup timeout, please manually run `cc…内容覆盖原始对话 T21-T25。

## 原始对话

仅供参考，请仔细甄别。

# 用户：

等一下我的ccr在C:\Users\Aaron Kwo'k\.cluade-code-router中有个自定义的config.json。重新安装后这个设置文件在特殊字符文件夹中是否可以正常运转

# DeepSeek：

**原始回答**

您提出了一个非常好的问题！是的，Claude Code Router 的配置文件通常存储在用户目录下的 `.claude-code-router` 文件夹中（在您的情况下是 `C:\Users\Aaron Kwo'k\.claude-code-router\config.json`），这个配置文件与安装位置是分开的。

## 配置文件的位置和使用

当您重新安装 CCR 到 `D:\ccr` 后：

1. **二进制文件和核心代码**会安装在 `D:\ccr` 中
2. **配置文件**仍然会保留在 `C:\Users\Aaron Kwo'k\.claude-code-router\` 中
3. **CCR 应该能够正常读取和使用**这个配置文件，因为它会通过系统API获取用户目录路径

## 验证配置是否正常工作

安装完成后，您可以验证配置是否正常加载：

```powershell
# 1. 首先检查配置文件是否存在
Test-Path "C:\Users\Aaron Kwo'k\.claude-code-router\config

息采取相应的解决方案。

# 用户：

  ⚡Aaron Kwo'k ❯❯ ccr code "写一个简单的Python程序"
node:internal/modules/cjs/loader:1137
  throw err;
  ^

Error: Cannot find module 'C:\Users\AARONK~1\AppData\Roaming\npm\node_modules\@musistudio\claude-code-router\dist\cli.js'
Require stack:
- C:\ccr-wrapper.js
    at Module._resolveFilename (node:internal/modules/cjs/loader:1134:15)
    at Module._load (node:internal/modules/cjs/loader:975:27)
    at Module.require (node:internal/modules/cjs/loader:1225:19)
    at require (node:internal/modules/helpers:177:18)
    at Object.<anonymous> (C:\ccr-wrapper.js:17:19)
    at Module._compile (node:internal/modules/cjs/loader:1356:14)
    at Module._extensions..js (node:internal/modules/cjs/loader:1414:10)
    at Module.load (node:internal/modules/cjs/loader:1197:32)
    at Module._load (node:internal/modules/cjs/loader:1013:12)
    at Function.executeUserEntryPoint [as runMain] (node:internal/modules/run_main:128:12) {
  code: 'MODULE_NOT_FOUND',
  requireStack: [ 'C:\\ccr-wrapper.js' ]
}

Node.js v18.19.0

# DeepSeek：

**原始回答**

看起来包装脚本仍然在尝试从旧的路径加载模块。让我们完全清除旧的包装脚本并重新设置。由于您已经决定将 CCR 安装到 `D:\ccr`，我们应该完全重新开始。

## 第一步：完全清除旧的设置

```powershell
# 1. 删除旧的包装脚本
Remove-Item "C:\ccr-wrapper.js" -ErrorAction SilentlyContinue

# 2. 从 PowerShell 配置文件中移除旧的 ccr 函数定义
# 首先备份当前配置文件
Copy-Item $profile "$profile.backup"

# 然后清空或编辑配置文件，移除所有旧的 ccr 函数定义
# 如果您想保留其他配置，可以手动编辑文件
notepad $profile
```

在打开的配置文件中，删除或注释掉所有与 `ccr` 相关的函数定义。

## 第二步：设置新的安装路径

```powershell
# 1. 设置 npm 使用 D:\ccr 作为全局安装路径
npm config set prefix "D:\cc

提供更精确的解决方案。

# 用户：

  ⚡Aaron Kwo'k ❯❯ New-Item -ItemType Directory -Path "D:\ccr" -Force


    目录: D:\


Mode                 LastWriteTime         Length Name
----                 -------------         ------ ----
d-----          2025-9-4      9:51                ccr


 YIXIST2024       2ms   9:51 AM   
  ⚡Aaron Kwo'k ❯❯
 YIXIST2024       0ms   9:51 AM   
  ⚡Aaron Kwo'k ❯❯ # 5. 重新设置 npm 前缀
 YIXIST2024       0ms   9:51 AM   
  ⚡Aaron Kwo'k ❯❯ npm config set prefix "D:\ccr"
 YIXIST2024       1.054s   9:51 AM   
  ⚡Aaron Kwo'k ❯❯
 YIXIST2024       0ms   9:51 AM   
  ⚡Aaron Kwo'k ❯❯ # 6. 重新安装
 YIXIST2024       0ms   9:51 AM   
  ⚡Aaron Kwo'k ❯❯ npm install -g @musistudio/claude-code-router
npm WARN EBADENGINE Unsupported engine {
npm WARN EBADENGINE   package: 'glob@11.0.3',
npm WARN EBADENGINE   required: { node: '20 || >=22' },
npm WARN EBADENGINE   current: { node: 'v18.19.0', npm: '10.2.3' }
npm WARN EBADENGINE }
npm WARN EBADENGINE Unsupported engine {
npm WARN EBADENGINE   package: '@google/genai@1.17.0',
npm WARN EBADENGINE   required: { node: '>=20.0.0' },
npm WARN EBADENGINE   current: { node: 'v18.19.0', npm: '10.2.3' }
npm WARN EBADENGINE }
npm WARN EBADENGINE Unsupported engine {
npm WARN EBADENGINE   package: 'undici@7.15.0',
npm WARN EBADENGINE   required: { node: '>=20.18.1' },
npm WARN EBADENGINE   current: { node: 'v18.19.0', npm: '10.2.3' }
npm WARN EBADENGINE }
npm WARN EBADENGINE Unsupported engine {
npm WARN EBADENGINE   package: 'find-my-way@9.3.0',
npm WARN EBADENGINE   required: { node: '>=20' },
npm WARN EBADENGINE   current: { node: 'v18.19.0', npm: '10.2.3' }
npm WARN EBADENGINE }
npm WARN EBADENGINE Unsupported engine {
npm WARN EBADENGINE   package: 'jackspeak@4.1.1',
npm WARN EBADENGINE   required: { node: '20 || >=22' },
npm WARN EBADENGINE   current: { node: 'v18.19.0', npm: '10.2.3' }
npm WARN EBADENGINE }
npm WARN EBADENGINE Unsupported engine {
npm WARN EBADENGINE   package: 'minimatch@10.0.3',
npm WARN EBADENGINE   required: { node: '20 || >=22' },
npm WARN EBADENGINE   current: { node: 'v18.19.0', npm: '10.2.3' }
npm WARN EBADENGINE }
npm WARN EBADENGINE Unsupported engine {
npm WARN EBADENGINE   package: 'path-scurry@2.0.0',
npm WARN EBADENGINE   required: { node: '20 || >=22' },
npm WARN EBADENGINE   current: { node: 'v18.19.0', npm: '10.2.3' }
npm WARN EBADENGINE }
npm WARN EBADENGINE Unsupported engine {
npm WARN EBADENGINE   package: '@isaacs/brace-expansion@5.0.0',
npm WARN EBADENGINE   required: { node: '20 || >=22' },
npm WARN EBADENGINE   current: { node: 'v18.19.0', npm: '10.2.3' }
npm WARN EBADENGINE }
npm WARN EBADENGINE Unsupported engine {
npm WARN EBADENGINE   package: '@isaacs/balanced-match@4.0.1',
npm WARN EBADENGINE   required: { node: '20 || >=22' },
npm WARN EBADENGINE   current: { node: 'v18.19.0', npm: '10.2.3' }
npm WARN EBADENGINE }
npm WARN EBADENGINE Unsupported engine {
npm WARN EBADENGINE   package: 'lru-cache@11.2.1',
npm WARN EBADENGINE   required: { node: '20 || >=22' },
npm WARN EBADENGINE   current: { node: 'v18.19.0', npm: '10.2.3' }
npm WARN EBADENGINE }
npm WARN deprecated node-domexception@1.0.0: Use your platform's native DOMException instead

added 152 packages in 43s

41 packages are looking for funding
  run `npm fund` for details
 YIXIST2024       44.176s   9:51 AM   
  ⚡Aaron Kwo'k ❯❯
 YIXIST2024       0ms   9:51 AM   
  ⚡Aaron Kwo'k ❯❯ # 7. 创建简单的函数
 YIXIST2024       0ms   9:51 AM   
  ⚡Aaron Kwo'k ❯❯ function ccr {
>     & "D:\ccr\ccr.cmd" @args
> }
 YIXIST2024       0ms   9:51 AM   
  ⚡Aaron Kwo'k ❯❯
 YIXIST2024       0ms   9:51 AM   
  ⚡Aaron Kwo'k ❯❯ # 8. 添加到配置文件
 YIXIST2024       0ms   9:51 AM   
  ⚡Aaron Kwo'k ❯❯ Add-Content -Path $profile -Value "function ccr { & 'D:\ccr\ccr.cmd' @args }"
 YIXIST2024       0ms   9:51 AM   
  ⚡Aaron Kwo'k ❯❯
 YIXIST2024       0ms   9:51 AM   
  ⚡Aaron Kwo'k ❯❯ # 9. 重新加载并测试
 YIXIST2024       1ms   9:51 AM   
  ⚡Aaron Kwo'k ❯❯ . $profile
 YIXIST2024       4ms   9:51 AM   
  ⚡Aaron Kwo'k ❯❯ ccr code "写一个简单的Python程序"
D:\ccr\node_modules\@musistudio\claude-code-router\dist\cli.js:39377
    webidl.is.File = webidl.util.MakeTypeAssertion(File);
                                                   ^

ReferenceError: File is not defined
    at node_modules/.pnpm/undici@7.15.0/node_modules/undici/lib/web/webidl/index.js (D:\ccr\node_modules\@musistudio\claude-code-router\dist\cli.js:39377:52)
    at __require (D:\ccr\node_modules\@musistudio\claude-code-router\dist\cli.js:13:50)
    at node_modules/.pnpm/undici@7.15.0/node_modules/undici/lib/web/fetch/util.js (D:\ccr\node_modules\@musistudio\claude-code-router\dist\cli.js:39538:22)
    at __require (D:\ccr\node_modules\@musistudio\claude-code-router\dist\cli.js:13:50)
    at node_modules/.pnpm/undici@7.15.0/node_modules/undici/lib/web/fetch/headers.js (D:\ccr\node_modules\@musistudio\claude-code-router\dist\cli.js:50340:9)
    at __require (D:\ccr\node_modules\@musistudio\claude-code-router\dist\cli.js:13:50)
    at node_modules/.pnpm/undici@7.15.0/node_modules/undici/lib/web/fetch/response.js (D:\ccr\node_modules\@musistudio\claude-code-router\dist\cli.js:50795:102)
    at __require (D:\ccr\node_modules\@musistudio\claude-code-router\dist\cli.js:13:50)
    at node_modules/.pnpm/undici@7.15.0/node_modules/undici/lib/web/fetch/index.js (D:\ccr\node_modules\@musistudio\claude-code-router\dist\cli.js:52112:9)
    at __require (D:\ccr\node_modules\@musistudio\claude-code-router\dist\cli.js:13:50)

Node.js v18.19.0

# DeepSeek：

**原始回答**

看起来问题依然存在，这是因为您的 Node.js 版本（v18.19.0）与 Claude Code Router 所需的依赖不兼容。从警告信息可以看出，多个依赖包需要 Node.js 20 或更高版本。

## 解决方案：升级 Node.js

这是根本的解决方案。您需要将 Node.js 升级到 20 或更高版本：

### 方法 1：使用 Node.js 官方安装包

1. **访问 Node.js 官网**：https://nodejs.org/
2. **下载 LTS 版本**（推荐 v20.x.x）
3. **运行安装程序**，它会自动替换旧版本

### 方法 2：使用 nvm-windows（推荐）

```powershell
# 1. 下载并安装 nvm-windows
# 访问：https://github.com/coreybutler/nvm-windows/releases
# 下载 nvm-setup.exe 并运行

# 2. 安装完成后，打开新的 PowerShell 窗口
nvm list availa

，我会帮您进一步解决。

# 用户：

我删除了所有的ccr。cmd设置后，我的打开powershell自动打开fastfetch怎么不运行了

# DeepSeek：

**原始回答**

看起来在修改 PowerShell 配置文件时，可能意外删除了或影响了 fastfetch 的启动设置。让我们来修复这个问题。

## 恢复 fastfetch 自动启动

### 方法 1：检查并修复 PowerShell 配置文件

```powershell
# 1. 首先检查当前的配置文件内容
notepad $profile

# 2. 查看是否有 fastfetch 相关的命令被删除
# 通常 fastfetch 的启动命令类似这样：
# fastfetch
# 或者
# Invoke-Expression (fastfetch --gen-config)

# 3. 如果缺少 fastfetch 命令，在文件末尾添加：
Add-Content -Path $profile -Value "`nfastfetch"
```

### 方法 2：检查 fastfetch 是否仍然安装

```powershell
# 检查 fastfetch 是否仍然可用
Get-Command fastfetch -ErrorAction S

提供更具体的解决方案。

# 用户：

PS C:\Users\Aaron Kwo'k> ccr code "写一个简单的Python程序"
Service not running, starting service...
Service startup timeout, please manually run `ccr start` to start the service
PS C:\Users\Aaron Kwo'k> ccr start
Enter Provider Name: modelscope
Enter Provider API KEY: ms-c4bdf950-baa9-482a-a4bc-9c60c1e2505a
Enter Provider URL:
Enter MODEL Name:
Loaded JSON config from: C:\Users\Aaron Kwo'k\.claude-code-router\config.json卡住了

# DeepSeek：

**原始回答**

看起来您已经成功安装了 Claude Code Router，但在启动服务时遇到了配置问题。服务启动时卡在了配置步骤，可能是因为某些配置项需要输入或者配置文件中缺少必要的信息。

## 解决配置卡住的问题

### 方法 1：手动编辑配置文件

首先，让我们手动编辑配置文件，避免交互式配置：

```powershell
# 1. 打开配置文件
notepad "C:\Users\Aaron Kwo'k\.claude-code-router\config.json"

# 2. 确保配置文件包含必要的信息，类似这样：
{
  "providers": [
    {
      "name": "modelscope",
      "apiKey": "ms-c4bdf950-baa9-482a-a4bc-9c60c1e2505a",
      "url": "https://api.modelscope.cn",
      "models": ["your-model-name"]
    }
  ],
  "defaultPr

## 关键结论

原对话最后阶段给出的主要判断或处理方向：原始回答** 看起来您已经成功安装了 Claude Code Router，但在启动服务时遇到了配置问题。服务启动时卡在了配置步骤，可能是因为某些配置项需要输入或者配置文件中缺少必要的信息。

## 上下文关系

- 所属项目：90e4542910-ai-tools-02
- 当前阶段：阶段2/2
- 前置切片：在使用Claude code router时，在powershell输入ccr co： YIXIST2024 _6bd38119.md
- 后续切片：无
- 附件说明：无
