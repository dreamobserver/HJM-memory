# UAC认证绕过与安全权衡

**分类**：编程与技术排错
**来源**：DeepSeek Chat 导出
**来源平台**：DeepSeek
**原始文件**：PowerShell配置文件创建与编辑指南.md
**包含轮次**：12 - 13

---

# 用户：
ok使用修改bat文件成功拿到了管理员权限，现在我需要提出要求，跳过cmd的UAC认证，因为这会拖慢工作进度

# DeepSeek：

**原始回答**
我理解您希望跳过UAC提示来提升工作效率的需求，但这是一个非常重要的安全边界，我需要先解释一下其中的权衡。

### 重要安全说明

**UAC（用户账户控制）是Windows最重要的安全功能之一**。它的目的就是在进行可能影响系统安全的操作前，明确要求用户确认。完全跳过UAC会显著降低系统的安全性。

不过，我们可以通过一些方法在**安全性和便利性之间取得平衡**。

---

### 可行的解决方案（按推荐顺序）

#### 方案一：调整UAC级别（推荐平衡方案）

这是最合理的折中方案，它不会完全禁用UAC，但会减少提示频率。

1.  在开始菜单搜索「更改用户账户控制设置」并打开
2.  将滑块从默认的「始终通知」调整到「仅当应用尝试更改计算机时通知我(不降低桌面亮度)」
3.  点击「确定」

**效果**：系统级别的更改仍然会提示，但很多操作不会再触发UAC，同时不会完全关闭安全保护。

#### 方案二：使用计划任务（技术方案）

创建一个自动提升权限的计划任务：

1.  **创建批处理文件** `adminwt_nouac.bat`：
    ```batch
    @echo off
    schtasks /run /tn "AdminWindowsTerminal"
    ```

2.  **创建计划任务**（以管理员身份运行PowerShell）：
    ```powershell
    $action = New-ScheduledTaskAction -Execute "wt.exe" -Argument '-p "Windows PowerShell"'
    $principal = New-ScheduledTaskPrincipal -UserId $env:USERNAME -RunLevel Highest
    $settings = New-ScheduledTaskSettingsSet -AllowStartIfOnBatteries -DontStopIfGoingOnBatteries -StartWhenAvailable
    Register-ScheduledTask -TaskName "AdminWindowsTerminal" -Action $action -Principal $principal -Settings $settings -Description "启动带管理员权限的WT"
    ```

#### 方案三：使用自动批准工具（需要下载）

使用像 `Elevate` 或 `sudo for Windows` 这样的第三方工具：

```batch
# 使用Elevate工具（需要先下载）
elevate.exe wt -p "Windows PowerShell"
```

#### 方案四：完全禁用UAC（极度不推荐）

**警告：这会严重降低系统安全性**

1.  按 `Win + R`，输入 `secpol.msc`
2.  导航到：安全设置 → 本地策略 → 安全选项
3.  找到「用户账户控制: 管理员批准模式中管理员的提升提示行为」
4.  改为「不提示，直接提升」
5.  **重启计算机**

---

### 我的专业建议

我强烈推荐**方案一（调整UAC级别）**，因为：

1.  **保持安全性**：仍然对真正的系统更改进行提示
2.  **减少干扰**：日常操作不再频繁弹出UAC
3.  **符合最佳实践**：是微软官方推荐的安全设置

如果您确实需要完全跳过UAC，请至少了解其中的风险：恶意软件可以在不被察觉的情况下获得管理员权限。

### 验证是否成功

调整后，测试您的批处理文件：
```batch
# 您的原始文件应该不再频繁弹出UAC
wt new-tab --elevate -p "Windows PowerShell"
```

或者使用改进后的命令：
```batch
# 更可靠的版本
powershell -Command "Start-Process wt -ArgumentList '-p \"Windows PowerShell\"' -Verb RunAs"
```

**请优先考虑方案一**，它在安全性和便利性之间提供了最好的平衡。完全跳过UAC虽然方便，但会让您的系统面临更大的安全风险。

# 用户：
我只是在使用psadmin时，跳过UAC，其他不变

# DeepSeek：

**原始回答**
明白了！您希望**仅针对 `psadmin` 这个特定的命令跳过 UAC 提示**，而保持系统其他所有的 UAC 安全设置不变。这是一个非常精准的需求。

这完全可以通过创建一个**已经内置管理员权限的 Windows Terminal 任务**来实现。以下是完美的解决方案：

### 最佳方案：创建自动提升的计划任务

这个方法的原理是：预先创建一个以最高权限运行的计划任务，然后您的 `psadmin` 命令只是触发这个任务，而不是发起新的权限提升请求。

#### 步骤 1：创建计划任务（只需设置一次）

1.  **以管理员身份打开 PowerShell**（这是唯一一次需要UAC）
2.  运行以下命令来创建计划任务：

    ```powershell
    $action = New-ScheduledTaskAction -Execute "wt.exe" -Argument '-p "Windows PowerShell"'
    $principal = New-ScheduledTaskPrincipal -UserId $env:USERNAME -LogonType Interactive -RunLevel Highest
    $settings = New-ScheduledTaskSettingsSet -AllowStartIfOnBatteries -DontStopIfGoingOnBatteries -StartWhenAvailable -DontStopOnIdleEnd
    Register-ScheduledTask -TaskName "AdminWindowsTerminal" -Action $action -Principal $principal -Settings $settings -Description "启动带管理员权限的Windows Terminal"
    ```

#### 步骤 2：修改您的批处理文件

将您的 `psadmin.bat` 文件内容改为：

```batch
@echo off
schtasks /run /tn "AdminWindowsTerminal" > nul 2>&1
```

- `schtasks /run /tn "AdminWindowsTerminal"`：立即运行名为 "AdminWindowsTerminal" 的计划任务
- `> nul 2>&1`：静默运行，不显示任何命令行输出

#### 步骤 3：使用方式

现在，当您：
1.  按下 `Win + R`
2.  输入 `psadmin`
3.  按回车

**系统会立即启动一个具有管理员权限的 Windows Terminal，完全跳过 UAC 提示**，同时您所有的美化效果都会保留。

---

### 备选方案：如果计划任务方法遇到问题

如果上述方法在您的系统上不工作，这里还有一个同样有效的备选方案：

#### 使用 VBScript 静默提升（无弹窗）

1.  **创建 `psadmin.vbs` 文件**（但我们通过批处理文件来调用它，避免直接输入扩展名）：

    ```vbscript
    Set WshShell = CreateObject("WScript.Shell")
    WshShell.Run "wt -p ""Windows PowerShell""", 0, False
    Set WshShell = Nothing
    ```

2.  **修改 `psadmin.bat` 文件**：

    ```batch
    @echo off
    start /b wscript "C:\你的路径\psadmin.vbs"
    ```

---

### 为什么这个方案是完美的？

1.  **精准目标**：只对 `psadmin` 命令跳过 UAC，系统其他所有安全设置保持不变
2.  **无需禁用安全功能**：UAC 仍然正常工作，保护您的系统免受其他潜在威胁
3.  **保持美化**：仍然通过 Windows Terminal 启动，所有主题、字体、Oh My Posh 配置都完整保留
4.  **极致速度**：几乎瞬间启动，没有任何延迟

### 验证成功

使用新方法后，再次验证：
```powershell
$currentPrincipal = New-Object Security.Principal.WindowsPrincipal([Security.Principal.WindowsIdentity]::GetCurrent())
$currentPrincipal.IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)
```
应该返回 `True`，但这次**完全没有看到 UAC 提示**。

**请优先尝试「计划任务」方案**，这是最简洁、最可靠的实现方式。

