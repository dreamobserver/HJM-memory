# 重新创建 PowerShell 脚本这个方法会弹出UAC窗口，且powershell窗口会闪退

**分类**：编程与技术排错
**来源**：DeepSeek Chat 导出
**来源平台**：DeepSeek
**原始文件**：PowerShell配置文件创建与编辑指南.md
**包含轮次**：19 - 19

---

# 用户：
重新创建 PowerShell 脚本这个方法会弹出UAC窗口，且powershell窗口会闪退

# DeepSeek：

**原始回答**
您遇到的问题很常见。让我提供一个更可靠、更简单的解决方案，避免脚本复杂性和编码问题。

### 简化的一步解决方案

让我们回到最基本的批处理文件方法，但使用更可靠的语法：

#### 方案 1：直接使用批处理文件

创建一个简单的 `psadmin.bat` 文件，内容如下：

```batch
@echo off
:: 直接启动 Windows Terminal 并以管理员权限运行 PowerShell
powershell -Command "Start-Process wt -ArgumentList '-p', 'Windows PowerShell' -Verb RunAs"
```

这个命令会：
1. 显示 UAC 提示（这是无法完全避免的）
2. 在获得批准后，启动带有管理员权限的 Windows Terminal

#### 方案 2：使用 VBScript 隐藏初始窗口

如果您想隐藏最初的 PowerShell 窗口，可以使用这个方案：

1. 创建 `psadmin.vbs` 文件：
```vbscript
Set objShell = CreateObject("WScript.Shell")
objShell.Run "powershell -Command ""Start-Process wt -ArgumentList '-p', 'Windows PowerShell' -Verb RunAs""", 0, False
```

2. 创建 `psadmin.bat` 文件：
```batch
@echo off
start /b wscript "C:\你的路径\psadmin.vbs"
```

#### 方案 3：公司环境友好方案

对于公司环境，最可靠的方案可能是接受 UAC 提示，但通过优化使其更加顺畅：

```batch
@echo off
:: 检查是否已经是管理员权限
powershell -Command "
$isAdmin = ([Security.Principal.WindowsPrincipal] [Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)
if (-not $isAdmin) {
    Write-Host '需要管理员权限，请批准 UAC 提示...'
    Start-Process wt -ArgumentList '-p', 'Windows PowerShell' -Verb RunAs
} else {
    Write-Host '已经是管理员权限，直接启动...'
    wt -p 'Windows PowerShell'
}
"
```

### 为什么无法完全跳过 UAC

在公司环境中，完全跳过 UAC 通常是不可能的，原因如下：

1. **安全策略**：公司 IT 部门通常会强制执行 UAC 策略
2. **权限限制**：普通用户账户无法修改系统级别的安全设置
3. **审计要求**：公司可能需要记录所有权限提升操作

### 最佳实践建议

考虑到公司环境的限制，我建议：

1. **接受 UAC 提示**：这是最可靠、最安全的方法
2. **优化体验**：通过清晰的提示让用户知道为什么需要 UAC
3. **使用公司批准的工具**：如果有公司提供的权限提升工具，使用它们

### 最终简化方案

如果您只是想通过 `Win+R` 快速启动管理员权限的 PowerShell，最简单的方法是：

```batch
@echo off
:: 简单直接的方法
powershell -Command "Start-Process powershell -Verb RunAs"
```

这个命令会：
1. 显示 UAC 提示
2. 打开一个具有管理员权限的 PowerShell 窗口

虽然不是完全跳过 UAC，但这是最可靠、最兼容公司环境的方法。

**总结**：在公司环境中，完全跳过 UAC 通常不可行。最好的方法是接受 UAC 提示，但通过优化脚本使其更加用户友好。方案 1 或最终简化方案应该能在您的环境中可靠工作。

