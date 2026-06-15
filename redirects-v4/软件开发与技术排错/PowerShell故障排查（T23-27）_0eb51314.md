---
title: "PowerShell故障排查（T23-27）"
source_platform: "DeepSeek"
source_file: "PowerShell配置文件创建与编辑指南.md"
turn_start: 23
turn_end: 27
primary_category: "软件开发与技术排错"
tags:
  - "PowerShell"
  - "软件开发"
project_id: "78599ff0b6-software-01"
stage: "阶段8/10"
previous_slice: "PowerShell安装配置_29564572.md"
next_slice: "PowerShell故障排查（T28-30）_3834ab59.md"
has_attachment: false
attachment_context_confidence: not_applicable
classification_confidence: 0.97
---

# PowerShell故障排查（T23-27）

## 问题摘要

本切片围绕“PowerShell故障排查（T23-27）”展开。起始诉求是： ⚡Aaron Kwo'k ❯❯ scoop install fastfetch scoop : 无法将“scoop”项识别为 cmdlet、函数、脚本文件或可运行程序的名称。请检查名称的拼写，如果包括路径，请确保路径正 确，然后再试一次。 所在位置 行:1 字符: 1 + s… 后续进展或反馈是：帮助我在powershell中添加类似于自动补全的功能内容覆盖原始对话 T23-T27。

## 原始对话

玩法，随时可以再问我。

# 用户：

  ⚡Aaron Kwo'k ❯❯ scoop install fastfetch
scoop : 无法将“scoop”项识别为 cmdlet、函数、脚本文件或可运行程序的名称。请检查名称的拼写，如果包括路径，请确保路径正
确，然后再试一次。
所在位置 行:1 字符: 1
+ scoop install fastfetch
+ ~~~~~
    + CategoryInfo          : ObjectNotFound: (scoop:String) [], CommandNotFoundException
    + FullyQualifiedErrorId : CommandNotFoundException

 YIXIST2024       108ms   4:04 PM   
  ⚡Aaron Kwo'k ❯❯

# DeepSeek：

**原始回答**

看起来你想使用 `scoop` 来安装 `fastfetch`，但系统无法识别 `scoop` 命令。这通常是因为 **Scoop 没有正确安装**，或者它的路径没有添加到系统环境变量中。别担心，我们来一步步解决。

首先，我推荐使用 **Winget** 来安装 Fastfetch，因为它是微软官方的包管理器，通常更直接可靠。Fastfetch 已经支持通过 Winget 安装。当然，如果你想继续使用 Scoop，我也会告诉你如何正确安装和配置它。

### 💡 优先推荐：使用 Winget 安装 Fastfetch

Winget 是 Windows 自带的包管理器，无需额外安装，而且 Fastfetch 也已加入其软件源。

1.  **以管理员身份**打开 **Windows Terminal** 或 **PowerShell**。
2.  输入以下命令并按回车：
    ```powershell
    winget install Fastfetch-cli.Fastfetch
    ```
3.  安装完成后，输入 `f

他问题，请随时告诉我。

# 用户：

 YIXIST2024       108ms   4:04 PM   
  ⚡Aaron Kwo'k ❯❯ winget install Fastfetch-cli.Fastfetch
已找到 fastfetch [Fastfetch-cli.Fastfetch] 版本 2.50.2
此应用程序由其所有者授权给你。
Microsoft 对第三方程序包概不负责，也不向第三方程序包授予任何许可证。
正在下载 https://github.com/fastfetch-cli/fastfetch/releases/download/2.50.2/fastfetch-windows-amd64.zip
执行此命令时发生意外错误：
InternetOpenUrl() failed.
0x80072efd : unknown error

# DeepSeek：

**原始回答**

这个错误 `0x80072efd : unknown error` 通常表示**网络连接问题**，Winget 无法从 GitHub 下载 Fastfetch 的安装包。这在公司网络环境下很常见，可能是因为防火墙、代理设置或网络策略限制。

别担心，我们有几种方法可以解决这个问题：

### 解决方案 1：手动下载并安装（最可靠）

既然 Winget 无法自动下载，我们可以手动下载然后让 Winget 安装本地文件。

1.  **手动下载 Fastfetch**：
    - 打开浏览器，访问 [Fastfetch 的 GitHub Releases 页面](https://github.com/fastfetch-cli/fastfetch/releases/)
    - 找到最新的版本（如 2.50.2），下载 `fastfetch-windows-amd64.zip` 文件
    - 将文件保存到一个容易找到的位置，比如 `C:\Users\Aaron Kwo'k\Downloads\`

2.  **使用 Winget 安

全不依赖网络自动下载。

# 用户：

github又连不上了，帮助我从零开始配置scoop以使用scoop安装fastfetch

# DeepSeek：

**原始回答**

好的！我们来从零开始配置 Scoop，并使用它来安装 Fastfetch。我会为您提供详细的步骤。

### 第一步：安装 Scoop

Scoop 的设计初衷是**不需要管理员权限**，所有软件都会安装到您的用户目录下。

1.  **以普通用户身份打开 PowerShell**（**不要**使用管理员身份）：
    - 在开始菜单搜索 "PowerShell"
    - 直接点击打开，**不要**选择"以管理员身份运行"

2.  **设置 PowerShell 执行策略**（允许运行脚本）：
    ```powershell
    Set-ExecutionPolicy RemoteSigned -Scope CurrentUser
    ```
    - 如果出现提示，输入 `Y` 并按回车确认。

3.  **安装 Scoop**（使用国内镜像源，解决网络问题）：
    ```powershell
    # 设置环境变量指向国内镜像源
    $env:SCOOP_REPO='https://gitee.com/

，我会帮您进一步解决！

# 用户：

OK我成功的安装了fastfetch，是否可以在我使用psadmin命令打开powershell管理员权限时，自动显示

# DeepSeek：

**原始回答**

当然可以！这是一个很棒的想法。我们可以通过修改 PowerShell 的配置文件来实现这个功能。

### 方法一：修改 PowerShell 配置文件（推荐）

这个方法会让**所有**管理员权限的 PowerShell 窗口在启动时自动显示 fastfetch。

1.  **首先打开您的 PowerShell 配置文件**：
    ```powershell
    notepad $PROFILE
    ```

2.  **在文件末尾添加以下代码**：
    ```powershell
    # 检查是否为管理员权限
    function Test-Administrator {
        $currentUser = [Security.Principal.WindowsIdentity]::GetCurrent()
        $principal = New-Object Security.Principal.WindowsPrincipal($currentUser)
        return 

显示漂亮的系统信息了！

# 用户：

帮助我在powershell中添加类似于自动补全的功能

# DeepSeek：

**原始回答**

太好了！为 PowerShell 添加自动补全功能可以极大提高工作效率。我会为您介绍几种强大的自动补全方案。

## 方案一：安装 PSReadLine（官方推荐，最强大）

PSReadLine 是微软官方开发的模块，提供极其强大的补全功能。

### 安装和配置 PSReadLine

1. **安装 PSReadLine**（通常 Win11 已预装，但需要更新）：
   ```powershell
   Install-Module PSReadLine -Force -SkipPublisherCheck
   ```

2. **编辑 PowerShell 配置文件**：
   ```powershell
   notepad $PROFILE
   ```

3. **添加以下配置到配置文件中**：
   ```powershell
   # 导入 PSReadLine 模块
   Import-Module PSReadLine
   
   # 设置补全模式：MenuComplete（菜单式）或 Complete（默认）

## 关键结论

原对话最后阶段给出的主要判断或处理方向：为 PowerShell 添加自动补全功能可以极大提高工作效率。安装和配置 PSReadLine 1. **安装 PSReadLine**（通常 Win11 已预装，但需要更新）： 2. **编辑 PowerShell 配置文件**： 3. **添加以下配置到配置文件中**： ```powershell 导入 PSReadLine 模块 Import-Module PSReadLine 设置补全模式：MenuComplete（菜单式）或 Complete（默认）

## 上下文关系

- 所属项目：78599ff0b6-software-01
- 当前阶段：阶段8/10
- 前置切片：PowerShell安装配置_29564572.md
- 后续切片：PowerShell故障排查（T28-30）_3834ab59.md
- 附件说明：无
