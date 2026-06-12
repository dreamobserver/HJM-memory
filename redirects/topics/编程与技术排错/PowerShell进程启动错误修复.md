# PowerShell进程启动错误修复

**分类**：编程与技术排错
**来源**：DeepSeek Chat 导出
**来源平台**：DeepSeek
**原始文件**：PowerShell配置文件创建与编辑指南.md
**包含轮次**：7 - 7

---

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
    *   用记事本打开 `C:\Users\Aaron Kwo'k\Scripts\psadmin.bat`
    *   将内容修改为：
        ```batch
        @echo off
        powershell -Command "Start-Process powershell -Verb RunAs"
        pause
        ```
    *   **关键修改**：将 `pwsh` 替换为 `powershell`。

2.  **保存文件并测试**
    *   再次通过 `Win + R` 运行 `psadmin`。
    *   现在应该会成功弹出 **用户账户控制 (UAC)** 窗口，询问您是否允许允许更改。点击“是”后，将会打开一个全新的、具有管理员权限的 **Windows PowerShell** 窗口。
    *   之前加的 `pause` 命令会让最初的 CMD 窗口保持打开，直到您按任意键。确认脚本工作正常后，您可以移除 `pause` 这一行。

#### 方案二：安装 PowerShell Core（如果您确实想使用 `pwsh`）

如果您希望使用更新的 PowerShell 7（Core），您需要先安装它。

1.  **安装 PowerShell Core**
    *   前往 PowerShell 的 GitHub 发布页面：https://github.com/PowerShell/PowerShell/releases
    *   下载最新的稳定版（通常是文件名类似 `PowerShell-7.4.x-win-x64.msi` 的 MSI 安装包）。
    *   运行安装程序，按照提示完成安装。安装程序会自动将 `pwsh` 添加到您的系统 PATH 环境变量中。

2.  **使用您原来的脚本**
    *   安装完成后，您原来的脚本（使用 `pwsh` 的版本）就应该可以正常工作了。
    ```batch
    @echo off
    powershell -Command "Start-Process pwsh -Verb RunAs"
    ```

### 如何区分两者？

您可以在任何一个现有的 PowerShell 窗口中运行以下命令来检查：

*   **查看版本**：
    ```powershell
    $PSVersionTable.PSVersion
    ```
    *   如果主版本是 **5.x**，您使用的是 **Windows PowerShell**，应使用命令 `powershell`。
    *   如果主版本是 **7.x**，您使用的是 **PowerShell Core**，应使用命令 `pwsh`。

*   **自动判断的脚本**：
    如果您希望一个脚本能适应两种环境，可以把它做得更智能一些：
    ```batch
    @echo off
    powershell -Command "
        if (Get-Command pwsh -ErrorAction SilentlyContinue) {
            Start-Process pwsh -Verb RunAs
        } else {
            Start-Process powershell -Verb RunAs -ArgumentList '-NoExit', '-Command', 'echo \"Running Windows PowerShell\"'
        }
    "
    ```

### 总结

**请直接采用方案一**：将您批处理文件中的 `pwsh` 改为 `powershell`。这几乎可以立即解决您的问题，因为所有 Windows 系统都自带 `powershell.exe`。

修改后，您的命令流程将变为：
`Win + R` → 输入 `psadmin` → 回车 → **UAC弹窗** → 点击“是” → **成功打开管理员权限的 Windows PowerShell**。

这次问题与执行策略或文件路径无关，纯粹是命令名称不匹配。请尝试修改并告诉我结果！

