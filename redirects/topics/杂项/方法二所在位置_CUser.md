# 方法二所在位置 C:\User

**分类**：杂项
**来源**：DeepSeek Chat 导出
**来源平台**：DeepSeek
**原始文件**：PowerShell配置文件创建与编辑指南.md
**包含轮次**：18 - 18

---

# 用户：
方法二所在位置 C:\Users\Aaron Kwo'k\Scripts\Launch-Elevated.ps1:22 字符: 12
+ Write-Host "鎵€鏈夋柟娉曢兘澶辫触浜嗭紝璇锋鏌ョ郴缁熼厤缃€?
+            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
字符串缺少终止符: "。
    + CategoryInfo          : ParserError: (:) [], ParentContainsErrorRecordException
    + FullyQualifiedErrorId : TerminatorExpectedAtEndOfString


[已退出进程，代码为 1 (0x00000001)]
现在可以使用Ctrl+D关闭此终端，或按 Enter 重新启动。

# DeepSeek：

**原始回答**
这个错误很明显是由于字符编码问题导致的。PowerShell 脚本中的中文字符在保存时可能被错误地编码，导致了乱码和语法错误。让我们修复这个问题。

### 修复字符编码问题

#### 步骤 1：重新创建 PowerShell 脚本

1. 打开记事本
2. 复制以下内容（确保使用英文标点）：
```powershell
# 尝试多种方式启动提升权限的 PowerShell
try {
    # 方法1: 使用 Start-Process
    $process = Start-Process powershell -Verb RunAs -PassThru -WindowStyle Hidden
    Start-Sleep -Milliseconds 500
    if ($process.Id) { exit }
}
catch {
    Write-Host "Method 1 failed: $($_.Exception.Message)"
}

try {
    # 方法2: 使用 WMI
    $process = ([WMI]"root\cimv2:Win32_Process").Create("powershell -NoExit -Command `"Write-Host 'Elevated permissions acquired'`"")
    Start-Sleep -Milliseconds 500
    if ($process.ProcessId) { exit }
}
catch {
    Write-Host "Method 2 failed: $($_.Exception.Message)"
}

Write-Host "All methods failed, please check system configuration."
pause
```

3. 将文件另存为 `Launch-Elevated.ps1`，在保存时选择"编码"为"UTF-8 with BOM"

#### 步骤 2：简化方法 - 不使用外部脚本

如果您不想处理编码问题，我们可以直接在批处理文件中完成所有操作：

```batch
@echo off
wt -p "Windows PowerShell" powershell -Command "
try {
    $process = Start-Process powershell -Verb RunAs -PassThru -WindowStyle Hidden
    Start-Sleep -Milliseconds 500
    if ($process.Id) { exit }
}
catch {
    Write-Host 'Start-Process failed: ' + $_.Exception.Message
    try {
        $process = ([WMI]'root\cimv2:Win32_Process').Create('powershell -NoExit -Command \"Write-Host \"Elevated permissions acquired\"\"')
        Start-Sleep -Milliseconds 500
        if ($process.ProcessId) { exit }
    }
    catch {
        Write-Host 'WMI method also failed: ' + $_.Exception.Message
    }
}
Write-Host 'All elevation methods failed.'
pause
"
```

### 更简单的解决方案

考虑到公司环境的限制，我们可以尝试一个更直接的方法：

#### 方案 1：使用 runas 命令

```batch
@echo off
echo Please enter your password when prompted
runas /user:Administrator "wt -p \"Windows PowerShell\""
```

#### 方案 2：使用计划任务（如果已有）

```batch
@echo off
schtasks /run /tn "AdminWindowsTerminal" >nul 2>&1
if %errorlevel% neq 0 (
    echo Admin task not found, creating it...
    schtasks /create /tn "AdminWindowsTerminal" /tr "wt -p \"Windows PowerShell\"" /sc onlogon /ru %USERNAME% /rl HIGHEST >nul 2>&1
    if %errorlevel% equ 0 (
        schtasks /run /tn "AdminWindowsTerminal" >nul 2>&1
    ) else (
        echo Failed to create task. You may need admin rights.
    )
)
```

#### 方案 3：直接启动并接受 UAC（最简单）

如果您无法完全跳过 UAC，这是最可靠的方案：

```batch
@echo off
powershell -Command "Start-Process wt -ArgumentList '-p', 'Windows PowerShell' -Verb RunAs"
```

### 针对公司环境的建议

在公司环境中，安全策略通常限制较严格，我建议：

1. **与 IT 部门沟通**：询问是否有批准的方法可以提升权限而不需要每次输入密码
2. **使用批准的提升方法**：公司可能有自己的工具或流程来处理权限提升
3. **考虑使用普通权限**：评估是否真的需要管理员权限进行日常工作

如果您确实需要管理员权限，最简单的解决方案可能是接受 UAC 提示，或者使用方案 3 的直接方法。

请尝试这些解决方案，特别是直接在批处理文件中嵌入 PowerShell 代码的方法，这样可以避免文件编码问题。

