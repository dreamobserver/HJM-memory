# OK我成功的安装了fastfetch，是否可以在我使用psadmin命令打开powershell管理员权限时，自动显示

**分类**：编程与技术排错
**来源**：DeepSeek Chat 导出
**来源平台**：DeepSeek
**原始文件**：PowerShell配置文件创建与编辑指南.md
**包含轮次**：26 - 30

---

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
        return $principal.IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)
    }
    
    # 如果是管理员权限，自动运行 fastfetch
    if (Test-Administrator) {
        # 检查 fastfetch 是否可用
        if (Get-Command fastfetch -ErrorAction SilentlyContinue) {
            fastfetch
            Write-Host "`n"  # 添加空行分隔
        } else {
            Write-Host "Fastfetch 未安装，请使用 scoop install fastfetch 安装" -ForegroundColor Yellow
        }
    }
    ```

3.  **保存并关闭文件**。

### 方法二：创建专门的启动脚本

如果您只想在通过 `psadmin` 启动时显示 fastfetch，而不是所有管理员会话：

1.  **创建一个新的启动脚本** `Start-AdminWithFastfetch.ps1`：
    ```powershell
    # 启动管理员权限的 PowerShell 并运行 fastfetch
    function Start-AdminWithFastfetch {
        if (Get-Command fastfetch -ErrorAction SilentlyContinue) {
            # 启动管理员权限的 PowerShell
            Start-Process wt -ArgumentList "-p", "Windows PowerShell", "-Command", "fastfetch; Write-Host '`n管理员权限已获取' -ForegroundColor Green" -Verb RunAs
        } else {
            Write-Host "Fastfetch 未安装，正在安装..." -ForegroundColor Yellow
            scoop install fastfetch
            Start-Process wt -ArgumentList "-p", "Windows PowerShell", "-Command", "fastfetch; Write-Host '`n管理员权限已获取' -ForegroundColor Green" -Verb RunAs
        }
    }
    
    # 执行函数
    Start-AdminWithFastfetch
    ```

2.  **修改您的 `psadmin.bat` 文件**：
    ```batch
    @echo off
    powershell -ExecutionPolicy Bypass -File "C:\你的路径\Start-AdminWithFastfetch.ps1"
    ```

### 方法三：直接在批处理文件中集成

最简单的方案，直接修改您的 `psadmin.bat`：

```batch
@echo off
:: 启动管理员权限的 Windows Terminal 并运行 fastfetch
powershell -Command "
if (Get-Command fastfetch -ErrorAction SilentlyContinue) {
    Start-Process wt -ArgumentList '-p', 'Windows PowerShell', '-Command', 'fastfetch; Write-Host \"`n\"' -Verb RunAs
} else {
    Write-Host 'Fastfetch 未安装，请先安装: scoop install fastfetch' -ForegroundColor Red
    pause
}
"
```

### 方法四：添加自定义函数到配置文件

如果您想要更灵活的控制，可以在配置文件中添加自定义函数：

```powershell
# 添加到您的 $PROFILE 中
function Start-AdminWithFastfetch {
    param(
        [switch]$NoFetch
    )
    
    if (-not $NoFetch -and (Get-Command fastfetch -ErrorAction SilentlyContinue)) {
        Start-Process wt -ArgumentList "-p", "Windows PowerShell", "-Command", "fastfetch; Write-Host '`n'" -Verb RunAs
    } else {
        Start-Process wt -ArgumentList "-p", "Windows PowerShell" -Verb RunAs
    }
}

# 创建别名方便使用
Set-Alias psadmin Start-AdminWithFastfetch
```

### 验证和测试

1.  **首先重新加载配置文件**（如果修改了 $PROFILE）：
    ```powershell
    . $PROFILE
    ```

2.  **测试效果**：
    - 使用 `Win + R` 输入 `psadmin`
    - 批准 UAC 提示
    - 新窗口应该会先显示 fastfetch 的系统信息，然后显示正常的 PowerShell 提示符

### 额外美化建议

如果您想要更好的显示效果，可以配置 fastfetch：

1.  **生成配置文件**：
    ```powershell
    fastfetch --gen-config
    ```

2.  **编辑配置文件**（通常位于 `%USERPROFILE%\.config\fastfetch\config.jsonc`）：
    - 您可以自定义显示的信息、颜色、logo 等
    - 设置 `"logo" : "windows"` 使用 Windows logo
    - 调整 `"modules"` 数组来选择显示哪些信息

3.  **使用自定义配置**：
    ```powershell
    fastfetch -c ~\.config\fastfetch\config.jsonc
    ```

### 总结

**推荐使用方法一**（修改 $PROFILE），因为：
1.  **自动生效**：所有管理员权限的 PowerShell 都会自动显示 fastfetch
2.  **不影响普通权限**：只有管理员权限的会话才会触发
3.  **灵活可控**：可以根据需要随时修改或禁用

现在当您使用 `psadmin` 命令时，新打开的管理员权限 PowerShell 窗口就会自动显示漂亮的系统信息了！

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
   Set-PSReadLineOption -EditMode Windows
   Set-PSReadLineOption -PredictionSource History  # 基于历史预测
   Set-PSReadLineOption -PredictionViewStyle ListView  # 列表视图
   
   # 设置智能补全
   Set-PSReadLineKeyHandler -Key Tab -Function MenuComplete
   
   # 设置 Ctrl+Space 触发智能补全
   Set-PSReadLineKeyHandler -Key Ctrl+Space -Function Complete
   
   # 基于历史记录的预测性输入
   Set-PSReadLineOption -HistorySearchCursorMovesToEnd
   Set-PSReadLineKeyHandler -Key UpArrow -Function HistorySearchBackward
   Set-PSReadLineKeyHandler -Key DownArrow -Function HistorySearchForward
   ```

### PSReadLine 的实用功能

```powershell
# 在配置文件中添加更多实用功能
# 语法高亮
Set-PSReadLineOption -Colors @{
    "Command" = "Yellow"
    "Parameter" = "Green"
    "Operator" = "Red"
    "Variable" = "Cyan"
}

# 智能提示设置
Set-PSReadLineOption -ShowToolTips
Set-PSReadLineOption -ExtraPromptLineCount 3
```

## 方案二：安装 zsh-like 补全（类似 Linux）

如果您喜欢 Linux zsh 的风格，可以安装这些模块：

### 安装 Fig（现代补全工具）

```powershell
# 安装 Fig
scoop install fig

# 或者使用 winget
winget install fig.fig
```

### 安装 posh-git（Git 命令补全）

```powershell
# 安装 posh-git
Install-Module posh-git -Force

# 添加到配置文件
Import-Module posh-git
```

## 方案三：自定义补全函数

您可以创建自己的补全函数：

### 在配置文件中添加自定义补全

```powershell
# 自定义命令补全
Register-ArgumentCompleter -CommandName Get-Process -ParameterName Name -ScriptBlock {
    param($commandName, $parameterName, $wordToComplete, $commandAst, $fakeBoundParameters)
    
    Get-Process | Where-Object { $_.ProcessName -like "$wordToComplete*" } | ForEach-Object {
        [System.Management.Automation.CompletionResult]::new($_.ProcessName, $_.ProcessName, 'ParameterValue', $_.ProcessName)
    }
}

# Git 命令补全
Register-ArgumentCompleter -CommandName git -ParameterName command -ScriptBlock {
    param($commandName, $parameterName, $wordToComplete, $commandAst, $fakeBoundParameters)
    
    @('status', 'add', 'commit', 'push', 'pull', 'clone', 'branch', 'checkout', 'merge', 'log') |
        Where-Object { $_ -like "$wordToComplete*" } |
        ForEach-Object { [System.Management.Automation.CompletionResult]::new($_, $_, 'ParameterValue', $_) }
}
```

## 方案四：使用 Oh My Posh 的补全功能

如果您已经使用 Oh My Posh，它可以提供额外的补全功能：

```powershell
# 安装 Oh My Posh
winget install JanDeDobbeleer.OhMyPosh

# 在配置文件中添加
oh-my-posh init pwsh --config "$env:POSH_THEMES_PATH\atomic.omp.json" | Invoke-Expression

# 启用智能提示
Set-PSReadLineOption -PredictionSource HistoryAndPlugin
```

## 方案五：一键安装脚本

创建一个自动安装所有补全功能的脚本：

```powershell
# Install-Completion.ps1
function Install-PowerShellCompletion {
    Write-Host "正在安装 PowerShell 自动补全增强..." -ForegroundColor Green
    
    # 安装 PSReadLine
    if (-not (Get-Module PSReadLine -ListAvailable)) {
        Install-Module PSReadLine -Force -SkipPublisherCheck
    }
    
    # 安装 posh-git
    if (-not (Get-Module posh-git -ListAvailable)) {
        Install-Module posh-git -Force
    }
    
    # 更新配置文件
    $profileContent = @'
# 自动补全配置
Import-Module PSReadLine
Import-Module posh-git

# PSReadLine 配置
Set-PSReadLineOption -EditMode Windows
Set-PSReadLineOption -PredictionSource History
Set-PSReadLineOption -PredictionViewStyle ListView
Set-PSReadLineKeyHandler -Key Tab -Function MenuComplete
Set-PSReadLineKeyHandler -Key Ctrl+Space -Function Complete

# 语法高亮
Set-PSReadLineOption -Colors @{
    "Command" = "Yellow"
    "Parameter" = "Green"
    "Operator" = "Red"
    "Variable" = "Cyan"
}

# 历史搜索
Set-PSReadLineKeyHandler -Key UpArrow -Function HistorySearchBackward
Set-PSReadLineKeyHandler -Key DownArrow -Function HistorySearchForward

Write-Host "自动补全功能已启用！" -ForegroundColor Green
Write-Host "使用 Tab 键补全，↑↓ 键搜索历史" -ForegroundColor Yellow
'@
    
    # 确保配置文件存在
    if (-not (Test-Path $PROFILE)) {
        New-Item -Path $PROFILE -ItemType File -Force
    }
    
    # 添加配置到配置文件
    Add-Content -Path $PROFILE -Value $profileContent
    
    Write-Host "安装完成！请重新启动 PowerShell。" -ForegroundColor Green
}

# 执行安装
Install-PowerShellCompletion
```

## 使用方法

安装完成后，您可以享受这些自动补全功能：

1. **Tab 补全**：输入命令时按 `Tab` 键
2. **历史搜索**：按 `↑` 或 `↓` 键搜索历史命令
3. **参数补全**：输入 `-` 后按 `Tab` 查看可用参数
4. **路径补全**：输入路径时按 `Tab` 自动补全

## 验证安装

重新启动 PowerShell 后，测试补全功能：

```powershell
# 测试命令补全
Get-Pr[Tab]  # 应该补全为 Get-Process

# 测试参数补全
Get-Process -[Tab]  # 显示所有可用参数

# 测试历史搜索
输入部分命令后按 ↑ 键
```

## 故障排除

如果遇到问题，可以尝试：

```powershell
# 重新加载配置文件
. $PROFILE

# 检查模块是否加载
Get-Module PSReadLine

# 如果出现执行策略错误
Set-ExecutionPolicy RemoteSigned -Scope CurrentUser
```

**推荐方案**：从**方案一（PSReadLine）** 开始，这是最稳定和功能最丰富的方案。然后根据需要添加其他模块。

现在您的 PowerShell 就会有类似 Linux bash/zsh 的强大自动补全功能了！

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
Set-PSReadLineOption -PredictionViewStyle ListView

# 设置 Tab 键补全
Set-PSReadLineKeyHandler -Key Tab -Function MenuComplete

# 正确的 Ctrl+Space 设置
Set-PSReadLineKeyHandler -Chord 'Ctrl+Space' -Function Complete

# 历史搜索设置
Set-PSReadLineOption -HistorySearchCursorMovesToEnd
Set-PSReadLineKeyHandler -Key UpArrow -Function HistorySearchBackward
Set-PSReadLineKeyHandler -Key DownArrow -Function HistorySearchForward

# 语法高亮颜色设置
Set-PSReadLineOption -Colors @{
    "Command" = "Yellow"
    "Parameter" = "Green"
    "Operator" = "Red"
    "Variable" = "Cyan"
    "String" = "Magenta"
}

# 显示工具提示
Set-PSReadLineOption -ShowToolTips
```

### 其他有用的快捷键设置

您还可以添加这些实用的快捷键：

```powershell
# 常用快捷键配置
Set-PSReadLineKeyHandler -Chord 'Ctrl+d' -Function DeleteChar
Set-PSReadLineKeyHandler -Chord 'Ctrl+l' -Function ClearScreen
Set-PSReadLineKeyHandler -Chord 'Ctrl+z' -Function Undo
Set-PSReadLineKeyHandler -Chord 'Ctrl+y' -Function Redo
Set-PSReadLineKeyHandler -Chord 'Ctrl+a' -Function BeginningOfLine
Set-PSReadLineKeyHandler -Chord 'Ctrl+e' -Function EndOfLine
Set-PSReadLineKeyHandler -Chord 'Ctrl+k' -Function KillLine
Set-PSReadLineKeyHandler -Chord 'Ctrl+u' -Function BackwardKillLine
```

### 验证配置是否正确

修改配置文件后，重新加载并测试：

```powershell
# 重新加载配置文件
. $PROFILE

# 测试配置是否正确加载
Get-PSReadLineKeyHandler -Chord 'Ctrl+Space'

# 查看所有已设置的快捷键
Get-PSReadLineKeyHandler | Where-Object { $_.Key -like '*Space*' -or $_.Key -like '*Tab*' }
```

### 如果仍然有问题：替代方案

如果 `Ctrl+Space` 在您的系统上仍然不工作，可以使用其他组合键：

```powershell
# 使用其他组合键替代 Ctrl+Space
Set-PSReadLineKeyHandler -Chord 'Ctrl+I' -Function Complete  # Ctrl+I
Set-PSReadLineKeyHandler -Chord 'Alt+Space' -Function Complete  # Alt+Space
Set-PSReadLineKeyHandler -Chord 'Ctrl+Shift+Space' -Function Complete  # Ctrl+Shift+Space
```

### 完整的故障排除步骤

如果问题仍然存在，请按顺序尝试：

1. **首先检查 PSReadLine 版本**：
   ```powershell
   Get-Module PSReadLine | Select-Object Version
   ```

2. **更新到最新版本**：
   ```powershell
   Install-Module PSReadLine -Force -AllowClobber
   ```

3. **重新导入模块**：
   ```powershell
   Remove-Module PSReadLine -ErrorAction SilentlyContinue
   Import-Module PSReadLine
   ```

4. **检查所有可用的功能**：
   ```powershell
   Get-PSReadLineKeyHandler | Group-Function | Select-Object Name
   ```

### 最简单的有效配置

如果您只想快速解决问题，可以使用这个最小配置：

```powershell
Import-Module PSReadLine
Set-PSReadLineOption -EditMode Windows
Set-PSReadLineOption -PredictionSource History
Set-PSReadLineKeyHandler -Key Tab -Function Complete
Set-PSReadLineKeyHandler -Chord 'Ctrl+I' -Function MenuComplete
```

### 总结

**关键修正**：将 `-Key Ctrl+Space` 改为 `-Chord 'Ctrl+Space'`

请修改您的配置文件中的这一行，然后重新加载配置文件。这样就应该能解决 "Unrecognized key 'Space'" 的错误，让您的自动补全功能正常工作。

如果还有其他问题，请告诉我具体的错误信息，我会继续帮您解决！

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

# 替代方案：使用其他组合键代替 Ctrl+Space
Set-PSReadLineKeyHandler -Chord 'Ctrl+I' -Function Complete  # Ctrl+I 通常用于补全
Set-PSReadLineKeyHandler -Chord 'Alt+Enter' -Function Complete  # Alt+Enter

# 或者使用 F1 键
Set-PSReadLineKeyHandler -Key F1 -Function Complete

# 历史搜索设置
Set-PSReadLineOption -HistorySearchCursorMovesToEnd
Set-PSReadLineKeyHandler -Key UpArrow -Function HistorySearchBackward
Set-PSReadLineKeyHandler -Key DownArrow -Function HistorySearchForward

# 语法高亮颜色设置
Set-PSReadLineOption -Colors @{
    "Command" = "Yellow"
    "Parameter" = "Green"
    "Operator" = "Red"
    "Variable" = "Cyan"
    "String" = "Magenta"
}

# 显示工具提示（正确的参数名称）
Set-PSReadLineOption -ExtraPromptLineCount 2

# 其他实用快捷键
Set-PSReadLineKeyHandler -Chord 'Ctrl+d' -Function DeleteChar
Set-PSReadLineKeyHandler -Chord 'Ctrl+l' -Function ClearScreen
Set-PSReadLineKeyHandler -Chord 'Ctrl+a' -Function BeginningOfLine
Set-PSReadLineKeyHandler -Chord 'Ctrl+e' -Function EndOfLine
```

## 问题二：字符编码问题

您配置文件中的 `ShowToolTips#` 后面出现了乱码，这是因为文件保存时的编码问题。

### 重新创建配置文件

1. **首先备份当前配置文件**：
   ```powershell
   Copy-Item $PROFILE "$PROFILE.backup"
   ```

2. **重新创建配置文件**：
   ```powershell
   # 删除现有配置文件
   Remove-Item $PROFILE -Force
   
   # 创建新的配置文件
   New-Item -Path $PROFILE -ItemType File -Force
   ```

3. **使用正确的编码重新编辑**：
   ```powershell
   # 使用记事本以 UTF-8 with BOM 编码保存
   notepad $PROFILE
   ```
   
   或者使用 PowerShell 创建：
   ```powershell
   @'
   # PowerShell 配置文件 - 自动补全设置
   Import-Module PSReadLine
   
   # 基本设置
   Set-PSReadLineOption -EditMode Windows
   Set-PSReadLineOption -PredictionSource History
   Set-PSReadLineOption -PredictionViewStyle ListView
   
   # 补全设置
   Set-PSReadLineKeyHandler -Key Tab -Function MenuComplete
   Set-PSReadLineKeyHandler -Chord "Ctrl+I" -Function Complete
   
   # 历史搜索
   Set-PSReadLineKeyHandler -Key UpArrow -Function HistorySearchBackward
   Set-PSReadLineKeyHandler -Key DownArrow -Function HistorySearchForward
   
   # 语法高亮
   Set-PSReadLineOption -Colors @{
       "Command" = "Yellow"
       "Parameter" = "Green"
       "Operator" = "Red"
       "Variable" = "Cyan"
   }
   
   Write-Host "PSReadLine 自动补全已启用!" -ForegroundColor Green
   '@ | Set-Content -Path $PROFILE -Encoding UTF8
   ```

## 验证和测试

重新加载配置文件后测试功能：

```powershell
# 重新加载配置
. $PROFILE

# 测试补全功能
Get-Ch[按 Tab 键]  # 应该补全为 Get-ChildItem

# 测试历史搜索
输入 "get" 然后按 ↑ 键

# 检查配置是否正确加载
Get-PSReadLineOption
```

## 如果仍然有问题：简化配置

如果还有问题，可以使用这个最小化的配置：

```powershell
# 最小化自动补全配置
Import-Module PSReadLine
Set-PSReadLineOption -EditMode Windows
Set-PSReadLineOption -PredictionSource History
Set-PSReadLineKeyHandler -Key Tab -Function Complete
```

## 检查 PSReadLine 版本

```powershell
# 查看当前版本
Get-Module PSReadLine | Select-Object Name, Version

# 如果需要更新
Install-Module PSReadLine -Force -AllowClobber
```

## 最终建议

1. **先删除或重命名当前的配置文件**（因为有乱码）
2. **使用我提供的修正版配置重新创建**
3. **主要依赖 `Tab` 键补全**（这是最稳定可靠的方式）
4. **使用 `Ctrl+I` 作为备用补全快捷键**

这样应该就能解决所有问题，让您的 PowerShell 拥有强大的自动补全功能了！

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
    # 检查 fastfetch 是否可用
    if (Get-Command fastfetch -ErrorAction SilentlyContinue) {
        fastfetch
        Write-Host "`n"  # 添加空行分隔
    } else {
        Write-Host "Fastfetch 未安装，请使用 scoop install fastfetch 安装" -ForegroundColor Yellow
    }
}
```

### 完整的修正版配置文件结构

您的配置文件应该按照这个顺序：

```powershell
# 1. 首先导入模块
Import-Module PSReadLine

# 2. 定义自定义函数
function Test-Administrator {
    $currentUser = [Security.Principal.WindowsIdentity]::GetCurrent()
    $principal = New-Object Security.Principal.WindowsPrincipal($currentUser)
    return $principal.IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)
}

# 3. PSReadLine 配置
Set-PSReadLineOption -EditMode Windows
Set-PSReadLineOption -PredictionSource History
Set-PSReadLineOption -PredictionViewStyle ListView
Set-PSReadLineKeyHandler -Key Tab -Function MenuComplete
Set-PSReadLineKeyHandler -Chord 'Ctrl+I' -Function Complete

# 4. 其他设置...

# 5. 最后使用函数进行检查
if (Test-Administrator) {
    if (Get-Command fastfetch -ErrorAction SilentlyContinue) {
        fastfetch
        Write-Host "`n"
    } else {
        Write-Host "Fastfetch 未安装" -ForegroundColor Yellow
    }
}
```

### 更简单的替代方案

如果您不想使用自定义函数，也可以直接使用内联代码：

```powershell
# 直接检查管理员权限而不使用函数
$isAdmin = ([Security.Principal.WindowsPrincipal] [Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)

if ($isAdmin) {
    if (Get-Command fastfetch -ErrorAction SilentlyContinue) {
        fastfetch
        Write-Host "`n"
    }
}
```

### 重新加载配置文件

修改后，重新加载配置文件：

```powershell
. $PROFILE
```

### 验证函数是否正确定义

您可以测试函数是否正常工作：

```powershell
# 测试函数
Test-Administrator

# 或者直接测试
$isAdmin = ([Security.Principal.WindowsPrincipal] [Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)
Write-Host "是否是管理员: $isAdmin"
```

### 如果仍然有问题

如果还有其他错误，请先注释掉有问题的部分，逐步调试：

```powershell
# 暂时注释掉 fastfetch 部分
<#
if (Test-Administrator) {
    if (Get-Command fastfetch -ErrorAction SilentlyContinue) {
        fastfetch
        Write-Host "`n"
    }
}
#>
```

请先将函数定义添加到配置文件中，然后再调用它。这样应该就能解决 "无法识别 Test-Administrator" 的错误了。

