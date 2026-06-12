# 方法二在呼出powershell时是输入psadmin.vbs吗？如果是就不考虑，因为可能输入中文的句号导致呼出失败

**分类**：编程与技术排错
**来源**：DeepSeek Chat 导出
**来源平台**：DeepSeek
**原始文件**：PowerShell配置文件创建与编辑指南.md
**包含轮次**：11 - 11

---

# 用户：
方法二在呼出powershell时是输入psadmin.vbs吗？如果是就不考虑，因为可能输入中文的句号导致呼出失败

# DeepSeek：

**原始回答**
您提出了一个非常实际的顾虑。确实，在 `Win + R` 运行对话框中输入 `psadmin.vbs`（包含点号）很容易因输入错误（如误输入中文句号）而导致失败。您完全正确，这不是一个用户友好的解决方案。

让我们回到更简单、更可靠的方法，避免需要输入文件扩展名的问题。

### 最佳解决方案：使用批处理文件 + 永久别名

这个方法不需要输入文件扩展名，只需要输入一个简单的命令。

#### 步骤 1：创建可靠的批处理文件

1.  创建一个新的批处理文件 `adminwt.bat`（名称可以自定义，但不要包含特殊字符）：
    ```batch
    @echo off
    powershell -Command "Start-Process wt -ArgumentList '-p \"Windows PowerShell\"' -Verb RunAs"
    ```

2.  将此文件保存到一个固定位置，例如 `C:\Users\<YourUsername>\Scripts\adminwt.bat`

#### 步骤 2：创建永久 DOSKEY 宏（别名）

这种方法允许您为长命令创建一个简短的别名，类似于 Linux 中的 alias。

1.  打开注册表编辑器（`regedit`）
2.  导航到：`HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Command Processor`
3.  右键点击右侧空白处，选择「新建」→「字符串值」
4.  命名为 `AutoRun`
5.  双击新建的 `AutoRun`，将其值设置为：
    ```
    DOSKEY wtadmin=powershell -Command "Start-Process wt -ArgumentList '-p \"Windows PowerShell\"' -Verb RunAs"
    ```
6.  点击「确定」保存

#### 步骤 3：使用简单命令

完成上述设置后：

1.  按下 `Win + R`
2.  输入 `wtadmin`（这是您设置的别名，不需要扩展名）
3.  按回车

系统会弹出 UAC 对话框请求权限提升，确认后会以管理员身份启动 Windows Terminal 中的 PowerShell。

### 替代方案：使用 PowerShell 配置文件添加函数

如果您更喜欢使用 PowerShell 的方式：

1.  打开您的 PowerShell 配置文件：
    ```powershell
    notepad $PROFILE
    ```

2.  在文件末尾添加以下函数：
    ```powershell
    function Start-AdminWT {
        Start-Process wt -ArgumentList '-p "Windows PowerShell"' -Verb RunAs
    }
    
    Set-Alias wtadmin Start-AdminWT
    ```

3.  保存并关闭文件

4.  然后您可以通过以下方式使用：
    - 在 PowerShell 中直接输入 `wtadmin`
    - 或者通过 `Win + R` 运行 `powershell -Command "wtadmin"`

### 验证管理员权限

无论使用哪种方法，打开新窗口后，请使用以下命令验证权限：

```powershell
$currentPrincipal = New-Object Security.Principal.WindowsPrincipal([Security.Principal.WindowsIdentity]::GetCurrent())
$isAdmin = $currentPrincipal.IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)
Write-Host "管理员权限: $isAdmin" -ForegroundColor $(if($isAdmin){"Green"}else{"Red"})
```

### 总结

我推荐使用「批处理文件 + 永久 DOSKEY 宏」的方法，因为：

1.  它只需要输入简单的 `wtadmin` 命令，不需要输入文件扩展名
2.  它直接可靠地请求管理员权限（通过 `-Verb RunAs`）
3.  它保留了 Windows Terminal 的所有美化效果
4.  它在所有命令提示符窗口中都可用，而不仅仅是 PowerShell

这样您就可以通过 `Win + R` 输入简单的 `wtadmin` 来启动带有所有美化效果的管理员权限 PowerShell 了。

