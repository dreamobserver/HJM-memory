#   ⚡Aaron Kwo'k ❯❯ scoop install fastfetch

**分类**：编程与技术排错
**来源**：DeepSeek Chat 导出
**来源平台**：DeepSeek
**原始文件**：PowerShell配置文件创建与编辑指南.md
**包含轮次**：23 - 23

---

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
3.  安装完成后，输入 `fastfetch` 测试。如果成功显示系统信息，就大功告成了。

### 🔧 安装和配置 Scoop

如果你仍想使用 Scoop，请按照以下步骤检查和安装：

#### 1. 确认 Scoop 是否已安装

在终端中输入 `scoop --version` 并回车。如果显示版本号（如 `Current Scoop version: v0.5.2`），说明 Scoop 已安装，问题可能出在环境变量上。如果提示“无法识别”，则需要安装 Scoop。

#### 2. 正确安装 Scoop

Scoop 的安装需要注意以下几点：
*   **不要使用管理员权限**：Scoop 设计为在普通用户模式下运行。
*   **设置执行策略**：如果之前从未运行过 PowerShell 脚本，需要先设置执行策略。

**安装步骤：**
1.  在开始菜单中搜索 **PowerShell**，**不要选择“以管理员身份运行”**，直接打开。
2.  在 PowerShell 中，首先执行以下命令以允许脚本运行：
    ```powershell
    Set-ExecutionPolicy RemoteSigned -Scope CurrentUser
    ```
    输入 `Y` 确认。
3.  然后运行 Scoop 安装命令：
    ```powershell
    iwr -useb get.scoop.sh | iex
    ```

#### 3. 检查并修复环境变量

如果执行了上述安装步骤后，`scoop` 命令仍然无法识别，很可能是环境变量未正确配置。

1.  在 PowerShell 中输入 `$env:USERPROFILE` 查看你的用户配置文件路径。
2.  打开 **系统属性** > **高级** > **环境变量**。
3.  在"用户变量"列表中，找到并选中 **`Path`** 变量，然后点击"编辑"。
4.  点击"新建"，添加以下两条路径（请将 `<你的用户名>` 替换为实际的用户名）：
    *   `%USERPROFILE%\scoop\shims`
    *   `C:\Users\<你的用户名>\scoop\shims`
5.  点击"确定"保存所有更改。
6.  **完全关闭所有终端窗口再重新打开**，然后再次尝试 `scoop --version`。

#### 4. 使用 Scoop 安装 Fastfetch

当 `scoop` 命令可以正常识别后，就可以安装 Fastfetch 了：
```powershell
scoop install fastfetch
```

### ⚠️ 注意网络问题

无论是在安装 Scoop 还是通过 Scoop 安装软件时，如果遇到网络连接超时或下载失败（例如提示 `URL ... is not valid`），可以尝试以下方法：
*   **启用 Aria2 加速下载**（Scoop 支持多线程下载工具）：
    ```powershell
    scoop config aria2-enabled true
    ```
*   如果网络问题依然存在，可以考虑**使用国内镜像源**来安装 Scoop：
    ```powershell
    $env:SCOOP_REPO='https://gitee.com/Luozhijun/scoop-installer'
    iwr -useb 'https://gitee.com/Luozhijun/scoop-installer/raw/master/bin/install.ps1' | iex
    ```

### 📌 总结

1.  **首推尝试**：直接使用 **`winget install Fastfetch-cli.Fastfetch`**，这是最快捷的方式。
2.  若仍需 **Scoop**：
    *   确保在**普通用户模式**的 PowerShell 中安装。
    *   安装前设置正确的**执行策略**：`Set-ExecutionPolicy RemoteSigned -Scope CurrentUser`。
    *   检查**环境变量 `Path`** 是否包含 Scoop 的路径（`%USERPROFILE%\scoop\shims`）。
3.  遇到**网络问题**可尝试配置 Aria2 或使用国内镜像源。

希望这些步骤能帮你顺利装上 Fastfetch！如果还有其他问题，请随时告诉我。

