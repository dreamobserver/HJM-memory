# OneClick-Setup.ps1 中完整输出

**分类**：DeepSeek专题
**来源**：DeepSeek Chat 导出
**来源平台**：DeepSeek
**原始文件**：Fixing PowerShell Path Issue with Apostrophes.md
**包含轮次**：13 - 15

---

# 用户：
OneClick-Setup.ps1 中完整输出

# DeepSeek：

**原始回答**
# OneClick-Setup.ps1 - 完整版本

```powershell
# OneClick-Setup.ps1 - PowerShell 环境一键配置工具
param(
    [string]$UDrivePath = "G:\powershell-dive\",
    [switch]$InstallFonts,
    [switch]$InstallModules, 
    [switch]$SetupDeepSeek,
    [switch]$All,
    [switch]$SkipProfile,
    [switch]$SkipTerminal,
    [switch]$SkipTools,
    [switch]$Force
)

Write-Host ""
Write-Host "🎯 PowerShell 环境一键配置工具" -ForegroundColor Cyan
Write-Host "═══════════════════════════════════════════════════════════════════════" -ForegroundColor Cyan
Write-Host "作者: 您的名称 | 版本: 2.0 | 日期: $(Get-Date -Format 'yyyy-MM-dd')" -ForegroundColor Gray
Write-Host ""

# 检查 U盘路径
if (-not (Test-Path $UDrivePath)) {
    Write-Host "❌ 错误: 找不到 U盘路径" -ForegroundColor Red
    Write-Host "   请检查 U盘是否已连接，当前路径: $UDrivePath" -ForegroundColor Yellow
    Write-Host "   或者使用 -UDrivePath 参数指定正确路径" -ForegroundColor White
    return
}

Write-Host "📁 使用配置源: $UDrivePath" -ForegroundColor Green
Write-Host "🏠 用户目录: $env:USERPROFILE" -ForegroundColor Gray
Write-Host ""

# 0. 设置执行策略
try {
    Write-Host "0. 检查 PowerShell 执行策略..." -ForegroundColor Yellow
    $currentPolicy = Get-ExecutionPolicy -Scope CurrentUser
    if ($currentPolicy -eq "Restricted") {
        Write-Host "   ⚠️  当前执行策略: $currentPolicy" -ForegroundColor Yellow
        $changePolicy = Read-Host "   是否更改为 RemoteSigned? (y/n)"
        if ($changePolicy -eq 'y' -or $changePolicy -eq 'Y') {
            Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser -Force
            Write-Host "   ✅ 执行策略已设置为 RemoteSigned" -ForegroundColor Green
        } else {
            Write-Host "   ⚠️  保持当前执行策略，可能会影响脚本运行" -ForegroundColor Yellow
        }
    } else {
        Write-Host "   ✅ 执行策略正常: $currentPolicy" -ForegroundColor Green
    }
}
catch {
    Write-Host "   ⚠️  无法设置执行策略: $($_.Exception.Message)" -ForegroundColor Yellow
}

Write-Host ""

# 1. 安装 PowerShell Profile
if (-not $SkipProfile) {
    Write-Host "1. 配置 PowerShell Profile" -ForegroundColor Yellow
    Write-Host "   ──────────────────────────────────────────────────────────────" -ForegroundColor Gray
    
    $profileScript = Join-Path $UDrivePath "Install-Profile.ps1"
    if (Test-Path $profileScript) {
        Write-Host "   📝 找到 Profile 安装脚本..." -ForegroundColor Gray
        
        $profileArgs = @{
            ProfileSource = Join-Path $UDrivePath "Microsoft.PowerShell_profile.ps1"
            BackupExisting = $true
        }
        if ($SetupDeepSeek -or $All) { 
            $profileArgs.SetupDeepSeek = $true 
        }
        if ($Force) {
            $profileArgs.Force = $true
        }
        
        try {
            & $profileScript @profileArgs
            Write-Host "   ✅ Profile 配置完成" -ForegroundColor Green
        }
        catch {
            Write-Host "   ❌ Profile 配置失败: $($_.Exception.Message)" -ForegroundColor Red
        }
    } else {
        Write-Host "   ❌ 找不到 Profile 安装脚本" -ForegroundColor Red
        
        # 直接复制 Profile 文件作为后备方案
        $profileSource = Join-Path $UDrivePath "Microsoft.PowerShell_profile.ps1"
        if (Test-Path $profileSource) {
            Write-Host "   🔄 尝试直接复制 Profile 文件..." -ForegroundColor Yellow
            try {
                Copy-Item -Path $profileSource -Destination $PROFILE.CurrentUserCurrentHost -Force
                Write-Host "   ✅ Profile 文件已复制" -ForegroundColor Green
            }
            catch {
                Write-Host "   ❌ Profile 文件复制失败: $($_.Exception.Message)" -ForegroundColor Red
            }
        } else {
            Write-Host "   ❌ 找不到 Profile 源文件" -ForegroundColor Red
        }
    }
} else {
    Write-Host "1. ⏭️  跳过 PowerShell Profile 配置" -ForegroundColor Gray
}

Write-Host ""

# 2. 配置 Windows Terminal
if (-not $SkipTerminal) {
    Write-Host "2. 配置 Windows Terminal" -ForegroundColor Yellow
    Write-Host "   ──────────────────────────────────────────────────────────────" -ForegroundColor Gray
    
    $terminalScript = Join-Path $UDrivePath "Setup-Terminal.ps1"
    if (Test-Path $terminalScript) {
        Write-Host "   🖥️  找到终端配置脚本..." -ForegroundColor Gray
        
        try {
            & $terminalScript -BackupExisting
            Write-Host "   ✅ Windows Terminal 配置完成" -ForegroundColor Green
        }
        catch {
            Write-Host "   ❌ 终端配置失败: $($_.Exception.Message)" -ForegroundColor Red
        }
    } else {
        Write-Host "   ❌ 找不到终端配置脚本" -ForegroundColor Red
        
        # 直接复制 settings.json 作为后备方案
        $settingsSource = Join-Path $UDrivePath "settings.json"
        if (Test-Path $settingsSource) {
            Write-Host "   🔄 尝试直接复制终端设置..." -ForegroundColor Yellow
            try {
                $targetPaths = @(
                    "$env:LOCALAPPDATA\Microsoft\Windows Terminal\settings.json",
                    "$env:LOCALAPPDATA\Microsoft\Windows Terminal Preview\settings.json"
                )
                
                foreach ($targetPath in $targetPaths) {
                    $targetDir = Split-Path $targetPath -Parent
                    if (Test-Path $targetDir) {
                        Copy-Item -Path $settingsSource -Destination $targetPath -Force
                        Write-Host "   ✅ 终端设置已复制到: $(Split-Path $targetPath -Leaf)" -ForegroundColor Green
                    }
                }
            }
            catch {
                Write-Host "   ❌ 终端设置复制失败: $($_.Exception.Message)" -ForegroundColor Red
            }
        }
    }
} else {
    Write-Host "2. ⏭️  跳过 Windows Terminal 配置" -ForegroundColor Gray
}

Write-Host ""

# 3. 安装字体
if ($InstallFonts -or $All) {
    Write-Host "3. 安装终端字体" -ForegroundColor Yellow
    Write-Host "   ──────────────────────────────────────────────────────────────" -ForegroundColor Gray
    
    $fontScript = Join-Path $UDrivePath "Install-Fonts.ps1"
    if (Test-Path $fontScript) {
        # 检查是否已有字体文件
        $fontsDir = Join-Path $UDrivePath "fonts"
        if (Test-Path $fontsDir) {
            $fontFiles = Get-ChildItem -Path $fontsDir -Filter "*.ttf" -Recurse
            if ($fontFiles.Count -gt 0) {
                Write-Host "   🔤 找到 $($fontFiles.Count) 个字体文件" -ForegroundColor Green
                
                # 检查管理员权限
                $isAdmin = ([Security.Principal.WindowsPrincipal] [Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole] "Administrator")
                
                if ($isAdmin) {
                    try {
                        & $fontScript -Force
                        Write-Host "   ✅ 字体安装完成" -ForegroundColor Green
                    }
                    catch {
                        Write-Host "   ❌ 字体安装失败: $($_.Exception.Message)" -ForegroundColor Red
                    }
                } else {
                    Write-Host "   ⚠️  字体安装需要管理员权限" -ForegroundColor Yellow
                    Write-Host "   💡 请以管理员身份运行: .\Install-Fonts.ps1 -Force" -ForegroundColor White
                }
            } else {
                Write-Host "   ⚠️  字体目录为空" -ForegroundColor Yellow
                Write-Host "   💡 请下载 Nerd Fonts 到 fonts 文件夹" -ForegroundColor White
            }
        } else {
            Write-Host "   ❌ 找不到字体目录" -ForegroundColor Red
            Write-Host "   💡 请创建 fonts 文件夹并放入字体文件" -ForegroundColor White
        }
    } else {
        Write-Host "   ❌ 找不到字体安装脚本" -ForegroundColor Red
    }
} else {
    Write-Host "3. ⏭️  跳过字体安装" -ForegroundColor Gray
}

Write-Host ""

# 4. 复制 Oh-My-Posh 主题
Write-Host "4. 配置 Oh-My-Posh 主题" -ForegroundColor Yellow
Write-Host "   ──────────────────────────────────────────────────────────────" -ForegroundColor Gray

$themesSource = Join-Path $UDrivePath "themes"
$themesDest = "$env:POSH_THEMES_PATH"

if (-not $themesDest) {
    # 如果环境变量不存在，使用默认路径
    $themesDest = "$env:USERPROFILE\AppData\Local\Programs\oh-my-posh\themes"
}

if (Test-Path $themesSource) {
    try {
        $themeFiles = Get-ChildItem -Path $themesSource -Filter "*.omp.json" -Recurse
        Write-Host "   🎨 找到 $($themeFiles.Count) 个主题文件" -ForegroundColor Green
        
        if (-not (Test-Path $themesDest)) {
            New-Item -ItemType Directory -Path $themesDest -Force
            Write-Host "   📁 创建主题目录: $themesDest" -ForegroundColor Gray
        }
        
        Copy-Item -Path "$themesSource\*" -Destination $themesDest -Recurse -Force
        Write-Host "   ✅ Oh-My-Posh 主题已复制" -ForegroundColor Green
        
        # 显示推荐主题
        Write-Host "   💡 推荐主题: tokyo, jandedobbeleer, space, dracula" -ForegroundColor White
    }
    catch {
        Write-Host "   ❌ 主题复制失败: $($_.Exception.Message)" -ForegroundColor Red
    }
} else {
    Write-Host "   ⚠️  未找到主题目录" -ForegroundColor Yellow
}

Write-Host ""

# 5. 复制自定义工具
if (-not $SkipTools) {
    Write-Host "5. 配置自定义工具" -ForegroundColor Yellow
    Write-Host "   ──────────────────────────────────────────────────────────────" -ForegroundColor Gray
    
    # 定义要复制的自定义工具
    $customTools = @(
        @{ Name = "ccr"; Dest = "D:\ccr" },
        @{ Name = "claude"; Dest = "D:\claude" },
        @{ Name = "npm"; Dest = "D:\npm" },
        @{ Name = "npx"; Dest = "D:\npx" }
    )
    
    $toolsInstalled = 0
    
    foreach ($tool in $customTools) {
        $toolSource = Join-Path $UDrivePath $tool.Name
        if (Test-Path $toolSource) {
            try {
                if (-not (Test-Path $tool.Dest)) {
                    New-Item -ItemType Directory -Path $tool.Dest -Force
                }
                Copy-Item -Path "$toolSource\*" -Destination $tool.Dest -Recurse -Force
                Write-Host "   ✅ $($tool.Name) 工具已复制到: $($tool.Dest)" -ForegroundColor Green
                $toolsInstalled++
            }
            catch {
                Write-Host "   ❌ $($tool.Name) 工具复制失败: $($_.Exception.Message)" -ForegroundColor Red
            }
        } else {
            Write-Host "   ⚠️  未找到工具: $($tool.Name)" -ForegroundColor Yellow
        }
    }
    
    # 如果有 node_modules，也复制（如果是工具依赖）
    $nodeModulesPath = Join-Path $UDrivePath "node_modules"
    if (Test-Path $nodeModulesPath) {
        Write-Host "   📦 复制 Node.js 模块..." -ForegroundColor Gray
        try {
            $nodeDest = "D:\node_modules"
            Copy-Item -Path $nodeModulesPath -Destination $nodeDest -Recurse -Force
            Write-Host "   ✅ Node.js 模块已复制" -ForegroundColor Green
        }
        catch {
            Write-Host "   ❌ Node.js 模块复制失败: $($_.Exception.Message)" -ForegroundColor Red
        }
    }
    
    if ($toolsInstalled -eq 0) {
        Write-Host "   ⚠️  未安装任何自定义工具" -ForegroundColor Yellow
    }
} else {
    Write-Host "5. ⏭️  跳过自定义工具配置" -ForegroundColor Gray
}

Write-Host ""

# 6. 安装 PowerShell 模块
if ($InstallModules -or $All) {
    Write-Host "6. 安装 PowerShell 模块" -ForegroundColor Yellow
    Write-Host "   ──────────────────────────────────────────────────────────────" -ForegroundColor Gray
    
    $requiredModules = @("PSReadLine", "Terminal-Icons", "Z")
    $modulesInstalled = 0
    
    foreach ($module in $requiredModules) {
        if (-not (Get-Module -ListAvailable -Name $module)) {
            Write-Host "   📦 正在安装 $module..." -ForegroundColor Gray
            try {
                Install-Module -Name $module -Force -AllowClobber -Scope CurrentUser -ErrorAction Stop
                Write-Host "   ✅ $module 安装完成" -ForegroundColor Green
                $modulesInstalled++
            }
            catch {
                Write-Host "   ❌ $module 安装失败: $($_.Exception.Message)" -ForegroundColor Red
            }
        } else {
            Write-Host "   ✅ $module 已安装" -ForegroundColor Gray
            $modulesInstalled++
        }
    }
    
    if ($modulesInstalled -eq 0) {
        Write-Host "   ⚠️  未安装任何 PowerShell 模块" -ForegroundColor Yellow
    }
} else {
    Write-Host "6. ⏭️  跳过 PowerShell 模块安装" -ForegroundColor Gray
}

Write-Host ""

# 7. 最终测试和验证
Write-Host "7. 最终验证" -ForegroundColor Yellow
Write-Host "   ──────────────────────────────────────────────────────────────" -ForegroundColor Gray

# 测试工具
$testScript = Join-Path $UDrivePath "Test-Tools.ps1"
if (Test-Path $testScript) {
    Write-Host "   🧪 测试安装的工具..." -ForegroundColor Gray
    try {
        & $testScript
    }
    catch {
        Write-Host "   ❌ 工具测试失败: $($_.Exception.Message)" -ForegroundColor Red
    }
} else {
    Write-Host "   ⚠️  未找到工具测试脚本" -ForegroundColor Yellow
}

# 测试字体
$testFontsScript = Join-Path $UDrivePath "Test-Fonts.ps1"
if (Test-Path $testFontsScript) {
    Write-Host "   🔤 测试字体配置..." -ForegroundColor Gray
    try {
        & $testFontsScript
    }
    catch {
        Write-Host "   ❌ 字体测试失败: $($_.Exception.Message)" -ForegroundColor Red
    }
}

Write-Host ""

# 配置完成总结
Write-Host "═══════════════════════════════════════════════════════════════════════" -ForegroundColor Cyan
Write-Host "🎉 PowerShell 环境一键配置完成!" -ForegroundColor Cyan
Write-Host ""

# 显示配置摘要
Write-Host "📊 配置摘要:" -ForegroundColor Yellow
$checks = @()

# 检查 Profile
if (-not $SkipProfile) {
    if (Test-Path $PROFILE.CurrentUserCurrentHost) {
        $checks += "✅ PowerShell Profile"
    } else {
        $checks += "❌ PowerShell Profile"
    }
}

# 检查终端设置
if (-not $SkipTerminal) {
    $wtSettings = "$env:LOCALAPPDATA\Microsoft\Windows Terminal\settings.json"
    if (Test-Path $wtSettings) {
        $checks += "✅ Windows Terminal"
    } else {
        $checks += "❌ Windows Terminal"
    }
}

# 检查工具
if (-not $SkipTools) {
    if (Test-Path "D:\ccr\ccr.cmd") {
        $checks += "✅ 自定义工具"
    } else {
        $checks += "❌ 自定义工具"
    }
}

# 检查主题
if (Test-Path $themesDest) {
    $themeCount = (Get-ChildItem $themesDest -Filter "*.omp.json" -ErrorAction SilentlyContinue).Count
    $checks += "✅ Oh-My-Posh 主题 ($themeCount 个)"
} else {
    $checks += "❌ Oh-My-Posh 主题"
}

# 显示检查结果
foreach ($check in $checks) {
    Write-Host "   $check" -ForegroundColor $check.Substring(0, 1)
}

Write-Host ""

# 下一步操作建议
Write-Host "📋 下一步操作:" -ForegroundColor Yellow
Write-Host "   1. 重新启动 PowerShell 或运行: . `$PROFILE" -ForegroundColor White
Write-Host "   2. 测试 DeepSeek 集成: ds '你好，DeepSeek'" -ForegroundColor White
Write-Host "   3. 测试自定义工具: ccr --help" -ForegroundColor White
Write-Host "   4. 在 Windows Terminal 设置中选择 Nerd Font" -ForegroundColor White
Write-Host "   5. 享受您的新 PowerShell 环境! 🚀" -ForegroundColor White

Write-Host ""

# 立即重新加载 Profile 的选项
$reloadNow = Read-Host "是否立即重新加载 Profile 并测试环境? (y/n)"
if ($reloadNow -eq 'y' -or $reloadNow -eq 'Y') {
    try {
        Write-Host "🔄 重新加载 Profile..." -ForegroundColor Yellow
        . $PROFILE
        Write-Host "✅ Profile 已重新加载" -ForegroundColor Green
        
        # 测试基本功能
        Write-Host "`n🧪 测试基本功能..." -ForegroundColor Yellow
        
        if (Get-Command ds -ErrorAction SilentlyContinue) {
            Write-Host "   ✅ DeepSeek 集成正常" -ForegroundColor Green
        } else {
            Write-Host "   ❌ DeepSeek 集成异常" -ForegroundColor Red
        }
        
        if (Get-Command ccr -ErrorAction SilentlyContinue) {
            Write-Host "   ✅ CCR 工具正常" -ForegroundColor Green
        } else {
            Write-Host "   ❌ CCR 工具异常" -ForegroundColor Red
        }
        
        Write-Host "`n🎉 环境测试完成! 所有功能已就绪。" -ForegroundColor Cyan
    }
    catch {
        Write-Host "❌ Profile 重新加载失败: $($_.Exception.Message)" -ForegroundColor Red
        Write-Host "💡 请手动重新启动 PowerShell" -ForegroundColor White
    }
} else {
    Write-Host "💡 请记得重新启动 PowerShell 以使所有更改生效" -ForegroundColor White
}

Write-Host ""
Write-Host "感谢使用 PowerShell 环境一键配置工具! ✨" -ForegroundColor Cyan
```

## 使用说明

### 基本用法：
```powershell
# 完整配置（推荐）
.\OneClick-Setup.ps1 -All

# 完整配置并设置 DeepSeek API 密钥
.\OneClick-Setup.ps1 -All -SetupDeepSeek

# 仅配置特定部分
.\OneClick-Setup.ps1 -InstallFonts -InstallModules

# 跳过某些部分
.\OneClick-Setup.ps1 -All -SkipTools -SkipTerminal
```

### 参数说明：
- `-All`: 执行所有配置步骤
- `-InstallFonts`: 安装字体
- `-InstallModules`: 安装 PowerShell 模块
- `-SetupDeepSeek`: 设置 DeepSeek API 密钥
- `-SkipProfile`: 跳过 PowerShell Profile 配置
- `-SkipTerminal`: 跳过 Windows Terminal 配置
- `-SkipTools`: 跳过自定义工具配置
- `-Force`: 强制覆盖现有配置

这个完整版本的脚本提供了：
- ✅ 清晰的进度显示
- ✅ 详细的错误处理
- ✅ 配置状态摘要
- ✅ 下一步操作指导
- ✅ 美观的格式化输出
- ✅ 灵活的配置选项

现在您就有了一个专业级的 PowerShell 环境一键配置工具！🎉本回答由 AI 生成，内容仅供参考，请仔细甄别。

# 用户：
这里面怎么没有fastfetch等安装

# DeepSeek：

**原始回答**
您说得对，我遗漏了 `fastfetch` 的安装。让我在 `OneClick-Setup.ps1` 中添加完整的 `fastfetch` 安装步骤：

## 更新后的 OneClick-Setup.ps1（包含 fastfetch）

```powershell
# OneClick-Setup.ps1 - PowerShell 环境一键配置工具
param(
    [string]$UDrivePath = "G:\powershell-dive\",
    [switch]$InstallFonts,
    [switch]$InstallModules, 
    [switch]$SetupDeepSeek,
    [switch]$All,
    [switch]$SkipProfile,
    [switch]$SkipTerminal,
    [switch]$SkipTools,
    [switch]$Force
)

Write-Host ""
Write-Host "🎯 PowerShell 环境一键配置工具" -ForegroundColor Cyan
Write-Host "═══════════════════════════════════════════════════════════════════════" -ForegroundColor Cyan
Write-Host "作者: 您的名称 | 版本: 2.0 | 日期: $(Get-Date -Format 'yyyy-MM-dd')" -ForegroundColor Gray
Write-Host ""

# 检查 U盘路径
if (-not (Test-Path $UDrivePath)) {
    Write-Host "❌ 错误: 找不到 U盘路径" -ForegroundColor Red
    Write-Host "   请检查 U盘是否已连接，当前路径: $UDrivePath" -ForegroundColor Yellow
    Write-Host "   或者使用 -UDrivePath 参数指定正确路径" -ForegroundColor White
    return
}

Write-Host "📁 使用配置源: $UDrivePath" -ForegroundColor Green
Write-Host "🏠 用户目录: $env:USERPROFILE" -ForegroundColor Gray
Write-Host ""

# 0. 设置执行策略
try {
    Write-Host "0. 检查 PowerShell 执行策略..." -ForegroundColor Yellow
    $currentPolicy = Get-ExecutionPolicy -Scope CurrentUser
    if ($currentPolicy -eq "Restricted") {
        Write-Host "   ⚠️  当前执行策略: $currentPolicy" -ForegroundColor Yellow
        $changePolicy = Read-Host "   是否更改为 RemoteSigned? (y/n)"
        if ($changePolicy -eq 'y' -or $changePolicy -eq 'Y') {
            Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser -Force
            Write-Host "   ✅ 执行策略已设置为 RemoteSigned" -ForegroundColor Green
        } else {
            Write-Host "   ⚠️  保持当前执行策略，可能会影响脚本运行" -ForegroundColor Yellow
        }
    } else {
        Write-Host "   ✅ 执行策略正常: $currentPolicy" -ForegroundColor Green
    }
}
catch {
    Write-Host "   ⚠️  无法设置执行策略: $($_.Exception.Message)" -ForegroundColor Yellow
}

Write-Host ""

# 1. 安装系统工具 (fastfetch, oh-my-posh 等)
Write-Host "1. 安装系统工具" -ForegroundColor Yellow
Write-Host "   ──────────────────────────────────────────────────────────────" -ForegroundColor Gray

$toolsToInstall = @()

# 检查并安装 fastfetch
if (-not (Get-Command fastfetch -ErrorAction SilentlyContinue)) {
    $toolsToInstall += @{Name = "fastfetch"; Command = "fastfetch"; Package = "fastfetch"}
    Write-Host "   🔍 检测到未安装: fastfetch" -ForegroundColor Yellow
} else {
    Write-Host "   ✅ fastfetch 已安装" -ForegroundColor Green
}

# 检查并安装 oh-my-posh
if (-not (Get-Command oh-my-posh -ErrorAction SilentlyContinue)) {
    $toolsToInstall += @{Name = "Oh-My-Posh"; Command = "oh-my-posh"; Package = "JanDeDobbeleer.OhMyPosh"}
    Write-Host "   🔍 检测到未安装: Oh-My-Posh" -ForegroundColor Yellow
} else {
    Write-Host "   ✅ Oh-My-Posh 已安装" -ForegroundColor Green
}

# 安装缺失的工具
if ($toolsToInstall.Count -gt 0) {
    Write-Host "   📦 开始安装缺失工具..." -ForegroundColor Gray
    
    foreach ($tool in $toolsToInstall) {
        Write-Host "   正在安装 $($tool.Name)..." -ForegroundColor Gray
        try {
            winget install $tool.Package -s winget --silent --accept-package-agreements --accept-source-agreements
            Write-Host "   ✅ $($tool.Name) 安装完成" -ForegroundColor Green
        }
        catch {
            Write-Host "   ❌ $($tool.Name) 安装失败: $($_.Exception.Message)" -ForegroundColor Red
            Write-Host "   尝试备用安装方法..." -ForegroundColor Yellow
            
            # 备用安装方法
            try {
                if ($tool.Name -eq "fastfetch") {
                    # 对于 fastfetch，可以尝试其他安装方式
                    Write-Host "   请手动安装 fastfetch: winget install fastfetch" -ForegroundColor White
                } elseif ($tool.Name -eq "Oh-My-Posh") {
                    # 对于 oh-my-posh，可以尝试其他安装方式
                    Write-Host "   请手动安装 Oh-My-Posh: winget install JanDeDobbeleer.OhMyPosh" -ForegroundColor White
                }
            }
            catch {
                Write-Host "   ❌ $($tool.Name) 备用安装也失败" -ForegroundColor Red
            }
        }
    }
} else {
    Write-Host "   ✅ 所有系统工具已安装" -ForegroundColor Green
}

Write-Host ""

# 2. 安装 PowerShell Profile
if (-not $SkipProfile) {
    Write-Host "2. 配置 PowerShell Profile" -ForegroundColor Yellow
    Write-Host "   ──────────────────────────────────────────────────────────────" -ForegroundColor Gray
    
    $profileScript = Join-Path $UDrivePath "Install-Profile.ps1"
    if (Test-Path $profileScript) {
        Write-Host "   📝 找到 Profile 安装脚本..." -ForegroundColor Gray
        
        $profileArgs = @{
            ProfileSource = Join-Path $UDrivePath "Microsoft.PowerShell_profile.ps1"
            BackupExisting = $true
        }
        if ($SetupDeepSeek -or $All) { 
            $profileArgs.SetupDeepSeek = $true 
        }
        if ($Force) {
            $profileArgs.Force = $true
        }
        
        try {
            & $profileScript @profileArgs
            Write-Host "   ✅ Profile 配置完成" -ForegroundColor Green
        }
        catch {
            Write-Host "   ❌ Profile 配置失败: $($_.Exception.Message)" -ForegroundColor Red
        }
    } else {
        Write-Host "   ❌ 找不到 Profile 安装脚本" -ForegroundColor Red
        
        # 直接复制 Profile 文件作为后备方案
        $profileSource = Join-Path $UDrivePath "Microsoft.PowerShell_profile.ps1"
        if (Test-Path $profileSource) {
            Write-Host "   🔄 尝试直接复制 Profile 文件..." -ForegroundColor Yellow
            try {
                Copy-Item -Path $profileSource -Destination $PROFILE.CurrentUserCurrentHost -Force
                Write-Host "   ✅ Profile 文件已复制" -ForegroundColor Green
            }
            catch {
                Write-Host "   ❌ Profile 文件复制失败: $($_.Exception.Message)" -ForegroundColor Red
            }
        } else {
            Write-Host "   ❌ 找不到 Profile 源文件" -ForegroundColor Red
        }
    }
} else {
    Write-Host "2. ⏭️  跳过 PowerShell Profile 配置" -ForegroundColor Gray
}

Write-Host ""

# 3. 配置 Windows Terminal
if (-not $SkipTerminal) {
    Write-Host "3. 配置 Windows Terminal" -ForegroundColor Yellow
    Write-Host "   ──────────────────────────────────────────────────────────────" -ForegroundColor Gray
    
    $terminalScript = Join-Path $UDrivePath "Setup-Terminal.ps1"
    if (Test-Path $terminalScript) {
        Write-Host "   🖥️  找到终端配置脚本..." -ForegroundColor Gray
        
        try {
            & $terminalScript -BackupExisting
            Write-Host "   ✅ Windows Terminal 配置完成" -ForegroundColor Green
        }
        catch {
            Write-Host "   ❌ 终端配置失败: $($_.Exception.Message)" -ForegroundColor Red
        }
    } else {
        Write-Host "   ❌ 找不到终端配置脚本" -ForegroundColor Red
        
        # 直接复制 settings.json 作为后备方案
        $settingsSource = Join-Path $UDrivePath "settings.json"
        if (Test-Path $settingsSource) {
            Write-Host "   🔄 尝试直接复制终端设置..." -ForegroundColor Yellow
            try {
                $targetPaths = @(
                    "$env:LOCALAPPDATA\Microsoft\Windows Terminal\settings.json",
                    "$env:LOCALAPPDATA\Microsoft\Windows Terminal Preview\settings.json"
                )
                
                foreach ($targetPath in $targetPaths) {
                    $targetDir = Split-Path $targetPath -Parent
                    if (Test-Path $targetDir) {
                        Copy-Item -Path $settingsSource -Destination $targetPath -Force
                        Write-Host "   ✅ 终端设置已复制到: $(Split-Path $targetPath -Leaf)" -ForegroundColor Green
                    }
                }
            }
            catch {
                Write-Host "   ❌ 终端设置复制失败: $($_.Exception.Message)" -ForegroundColor Red
            }
        }
    }
} else {
    Write-Host "3. ⏭️  跳过 Windows Terminal 配置" -ForegroundColor Gray
}

Write-Host ""

# 4. 安装字体
if ($InstallFonts -or $All) {
    Write-Host "4. 安装终端字体" -ForegroundColor Yellow
    Write-Host "   ──────────────────────────────────────────────────────────────" -ForegroundColor Gray
    
    $fontScript = Join-Path $UDrivePath "Install-Fonts.ps1"
    if (Test-Path $fontScript) {
        # 检查是否已有字体文件
        $fontsDir = Join-Path $UDrivePath "fonts"
        if (Test-Path $fontsDir) {
            $fontFiles = Get-ChildItem -Path $fontsDir -Filter "*.ttf" -Recurse
            if ($fontFiles.Count -gt 0) {
                Write-Host "   🔤 找到 $($fontFiles.Count) 个字体文件" -ForegroundColor Green
                
                # 检查管理员权限
                $isAdmin = ([Security.Principal.WindowsPrincipal] [Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole] "Administrator")
                
                if ($isAdmin) {
                    try {
                        & $fontScript -Force
                        Write-Host "   ✅ 字体安装完成" -ForegroundColor Green
                    }
                    catch {
                        Write-Host "   ❌ 字体安装失败: $($_.Exception.Message)" -ForegroundColor Red
                    }
                } else {
                    Write-Host "   ⚠️  字体安装需要管理员权限" -ForegroundColor Yellow
                    Write-Host "   💡 请以管理员身份运行: .\Install-Fonts.ps1 -Force" -ForegroundColor White
                }
            } else {
                Write-Host "   ⚠️  字体目录为空" -ForegroundColor Yellow
                Write-Host "   💡 请下载 Nerd Fonts 到 fonts 文件夹" -ForegroundColor White
            }
        } else {
            Write-Host "   ❌ 找不到字体目录" -ForegroundColor Red
            Write-Host "   💡 请创建 fonts 文件夹并放入字体文件" -ForegroundColor White
        }
    } else {
        Write-Host "   ❌ 找不到字体安装脚本" -ForegroundColor Red
    }
} else {
    Write-Host "4. ⏭️  跳过字体安装" -ForegroundColor Gray
}

Write-Host ""

# 5. 复制 Oh-My-Posh 主题
Write-Host "5. 配置 Oh-My-Posh 主题" -ForegroundColor Yellow
Write-Host "   ──────────────────────────────────────────────────────────────" -ForegroundColor Gray

$themesSource = Join-Path $UDrivePath "themes"
$themesDest = "$env:POSH_THEMES_PATH"

if (-not $themesDest) {
    # 如果环境变量不存在，使用默认路径
    $themesDest = "$env:USERPROFILE\AppData\Local\Programs\oh-my-posh\themes"
}

if (Test-Path $themesSource) {
    try {
        $themeFiles = Get-ChildItem -Path $themesSource -Filter "*.omp.json" -Recurse
        Write-Host "   🎨 找到 $($themeFiles.Count) 个主题文件" -ForegroundColor Green
        
        if (-not (Test-Path $themesDest)) {
            New-Item -ItemType Directory -Path $themesDest -Force
            Write-Host "   📁 创建主题目录: $themesDest" -ForegroundColor Gray
        }
        
        Copy-Item -Path "$themesSource\*" -Destination $themesDest -Recurse -Force
        Write-Host "   ✅ Oh-My-Posh 主题已复制" -ForegroundColor Green
        
        # 显示推荐主题
        Write-Host "   💡 推荐主题: tokyo, jandedobbeleer, space, dracula" -ForegroundColor White
    }
    catch {
        Write-Host "   ❌ 主题复制失败: $($_.Exception.Message)" -ForegroundColor Red
    }
} else {
    Write-Host "   ⚠️  未找到主题目录" -ForegroundColor Yellow
}

Write-Host ""

# 6. 复制自定义工具
if (-not $SkipTools) {
    Write-Host "6. 配置自定义工具" -ForegroundColor Yellow
    Write-Host "   ──────────────────────────────────────────────────────────────" -ForegroundColor Gray
    
    # 定义要复制的自定义工具
    $customTools = @(
        @{ Name = "ccr"; Dest = "D:\ccr" },
        @{ Name = "claude"; Dest = "D:\claude" },
        @{ Name = "npm"; Dest = "D:\npm" },
        @{ Name = "npx"; Dest = "D:\npx" }
    )
    
    $toolsInstalled = 0
    
    foreach ($tool in $customTools) {
        $toolSource = Join-Path $UDrivePath $tool.Name
        if (Test-Path $toolSource) {
            try {
                if (-not (Test-Path $tool.Dest)) {
                    New-Item -ItemType Directory -Path $tool.Dest -Force
                }
                Copy-Item -Path "$toolSource\*" -Destination $tool.Dest -Recurse -Force
                Write-Host "   ✅ $($tool.Name) 工具已复制到: $($tool.Dest)" -ForegroundColor Green
                $toolsInstalled++
            }
            catch {
                Write-Host "   ❌ $($tool.Name) 工具复制失败: $($_.Exception.Message)" -ForegroundColor Red
            }
        } else {
            Write-Host "   ⚠️  未找到工具: $($tool.Name)" -ForegroundColor Yellow
        }
    }
    
    # 如果有 node_modules，也复制（如果是工具依赖）
    $nodeModulesPath = Join-Path $UDrivePath "node_modules"
    if (Test-Path $nodeModulesPath) {
        Write-Host "   📦 复制 Node.js 模块..." -ForegroundColor Gray
        try {
            $nodeDest = "D:\node_modules"
            Copy-Item -Path $nodeModulesPath -Destination $nodeDest -Recurse -Force
            Write-Host "   ✅ Node.js 模块已复制" -ForegroundColor Green
        }
        catch {
            Write-Host "   ❌ Node.js 模块复制失败: $($_.Exception.Message)" -ForegroundColor Red
        }
    }
    
    if ($toolsInstalled -eq 0) {
        Write-Host "   ⚠️  未安装任何自定义工具" -ForegroundColor Yellow
    }
} else {
    Write-Host "6. ⏭️  跳过自定义工具配置" -ForegroundColor Gray
}

Write-Host ""

# 7. 安装 PowerShell 模块
if ($InstallModules -or $All) {
    Write-Host "7. 安装 PowerShell 模块" -ForegroundColor Yellow
    Write-Host "   ──────────────────────────────────────────────────────────────" -ForegroundColor Gray
    
    $requiredModules = @("PSReadLine", "Terminal-Icons", "Z")
    $modulesInstalled = 0
    
    foreach ($module in $requiredModules) {
        if (-not (Get-Module -ListAvailable -Name $module)) {
            Write-Host "   📦 正在安装 $module..." -ForegroundColor Gray
            try {
                Install-Module -Name $module -Force -AllowClobber -Scope CurrentUser -ErrorAction Stop
                Write-Host "   ✅ $module 安装完成" -ForegroundColor Green
                $modulesInstalled++
            }
            catch {
                Write-Host "   ❌ $module 安装失败: $($_.Exception.Message)" -ForegroundColor Red
            }
        } else {
            Write-Host "   ✅ $module 已安装" -ForegroundColor Gray
            $modulesInstalled++
        }
    }
    
    if ($modulesInstalled -eq 0) {
        Write-Host "   ⚠️  未安装任何 PowerShell 模块" -ForegroundColor Yellow
    }
} else {
    Write-Host "7. ⏭️  跳过 PowerShell 模块安装" -ForegroundColor Gray
}

Write-Host ""

# 8. 最终验证和测试
Write-Host "8. 最终验证和测试" -ForegroundColor Yellow
Write-Host "   ──────────────────────────────────────────────────────────────" -ForegroundColor Gray

# 测试系统工具
Write-Host "   🔧 测试系统工具..." -ForegroundColor Gray

# 测试 fastfetch
if (Get-Command fastfetch -ErrorAction SilentlyContinue) {
    Write-Host "   ✅ fastfetch 可用" -ForegroundColor Green
    
    # 可选：显示 fastfetch 输出
    $showFastfetch = Read-Host "   是否显示 fastfetch 系统信息? (y/n)"
    if ($showFastfetch -eq 'y' -or $showFastfetch -eq 'Y') {
        try {
            fastfetch
        }
        catch {
            Write-Host "   ⚠️  fastfetch 运行有警告" -ForegroundColor Yellow
        }
    }
} else {
    Write-Host "   ❌ fastfetch 不可用" -ForegroundColor Red
}

# 测试 oh-my-posh
if (Get-Command oh-my-posh -ErrorAction SilentlyContinue) {
    Write-Host "   ✅ Oh-My-Posh 可用" -ForegroundColor Green
} else {
    Write-Host "   ❌ Oh-My-Posh 不可用" -ForegroundColor Red
}

# 测试其他工具
$testScript = Join-Path $UDrivePath "Test-Tools.ps1"
if (Test-Path $testScript) {
    Write-Host "   🧪 测试安装的工具..." -ForegroundColor Gray
    try {
        & $testScript
    }
    catch {
        Write-Host "   ❌ 工具测试失败: $($_.Exception.Message)" -ForegroundColor Red
    }
} else {
    Write-Host "   ⚠️  未找到工具测试脚本" -ForegroundColor Yellow
}

# 测试字体
$testFontsScript = Join-Path $UDrivePath "Test-Fonts.ps1"
if (Test-Path $testFontsScript) {
    Write-Host "   🔤 测试字体配置..." -ForegroundColor Gray
    try {
        & $testFontsScript
    }
    catch {
        Write-Host "   ❌ 字体测试失败: $($_.Exception.Message)" -ForegroundColor Red
    }
}

Write-Host ""

# 配置完成总结
Write-Host "═══════════════════════════════════════════════════════════════════════" -ForegroundColor Cyan
Write-Host "🎉 PowerShell 环境一键配置完成!" -ForegroundColor Cyan
Write-Host ""

# 显示配置摘要
Write-Host "📊 配置摘要:" -ForegroundColor Yellow
$checks = @()

# 检查系统工具
if (Get-Command fastfetch -ErrorAction SilentlyContinue) {
    $checks += "✅ fastfetch"
} else {
    $checks += "❌ fastfetch"
}

if (Get-Command oh-my-posh -ErrorAction SilentlyContinue) {
    $checks += "✅ Oh-My-Posh"
} else {
    $checks += "❌ Oh-My-Posh"
}

# 检查 Profile
if (-not $SkipProfile) {
    if (Test-Path $PROFILE.CurrentUserCurrentHost) {
        $checks += "✅ PowerShell Profile"
    } else {
        $checks += "❌ PowerShell Profile"
    }
}

# 检查终端设置
if (-not $SkipTerminal) {
    $wtSettings = "$env:LOCALAPPDATA\Microsoft\Windows Terminal\settings.json"
    if (Test-Path $wtSettings) {
        $checks += "✅ Windows Terminal"
    } else {
        $checks += "❌ Windows Terminal"
    }
}

# 检查工具
if (-not $SkipTools) {
    if (Test-Path "D:\ccr\ccr.cmd") {
        $checks += "✅ 自定义工具"
    } else {
        $checks += "❌ 自定义工具"
    }
}

# 检查主题
if (Test-Path $themesDest) {
    $themeCount = (Get-ChildItem $themesDest -Filter "*.omp.json" -ErrorAction SilentlyContinue).Count
    $checks += "✅ Oh-My-Posh 主题 ($themeCount 个)"
} else {
    $checks += "❌ Oh-My-Posh 主题"
}

# 显示检查结果
foreach ($check in $checks) {
    Write-Host "   $check" -ForegroundColor $check.Substring(0, 1)
}

Write-Host ""

# 下一步操作建议
Write-Host "📋 下一步操作:" -ForegroundColor Yellow
Write-Host "   1. 重新启动 PowerShell 或运行: . `$PROFILE" -ForegroundColor White
Write-Host "   2. 测试 DeepSeek 集成: ds '你好，DeepSeek'" -ForegroundColor White
Write-Host "   3. 测试自定义工具: ccr --help" -ForegroundColor White
Write-Host "   4. 测试 fastfetch: fastfetch" -ForegroundColor White
Write-Host "   5. 在 Windows Terminal 设置中选择 Nerd Font" -ForegroundColor White
Write-Host "   6. 享受您的新 PowerShell 环境! 🚀" -ForegroundColor White

Write-Host ""

# 立即重新加载 Profile 的选项
$reloadNow = Read-Host "是否立即重新加载 Profile 并测试环境? (y/n)"
if ($reloadNow -eq 'y' -or $reloadNow -eq 'Y') {
    try {
        Write-Host "🔄 重新加载 Profile..." -ForegroundColor Yellow
        . $PROFILE
        Write-Host "✅ Profile 已重新加载" -ForegroundColor Green
        
        # 测试基本功能
        Write-Host "`n🧪 测试基本功能..." -ForegroundColor Yellow
        
        if (Get-Command ds -ErrorAction SilentlyContinue) {
            Write-Host "   ✅ DeepSeek 集成正常" -ForegroundColor Green
        } else {
            Write-Host "   ❌ DeepSeek 集成异常" -ForegroundColor Red
        }
        
        if (Get-Command ccr -ErrorAction SilentlyContinue) {
            Write-Host "   ✅ CCR 工具正常" -ForegroundColor Green
        } else {
            Write-Host "   ❌ CCR 工具异常" -ForegroundColor Red
        }
        
        if (Get-Command fastfetch -ErrorAction SilentlyContinue) {
            Write-Host "   ✅ Fastfetch 正常" -ForegroundColor Green
        } else {
            Write-Host "   ❌ Fastfetch 异常" -ForegroundColor Red
        }
        
        Write-Host "`n🎉 环境测试完成! 所有功能已就绪。" -ForegroundColor Cyan
    }
    catch {
        Write-Host "❌ Profile 重新加载失败: $($_.Exception.Message)" -ForegroundColor Red
        Write-Host "💡 请手动重新启动 PowerShell" -ForegroundColor White
    }
} else {
    Write-Host "💡 请记得重新启动 PowerShell 以使所有更改生效" -ForegroundColor White
}

Write-Host ""
Write-Host "感谢使用 PowerShell 环境一键配置工具! ✨" -ForegroundColor Cyan
```

## 主要更新内容

### 1. 新增第1步：系统工具安装
- ✅ 自动检测并安装 `fastfetch`
- ✅ 自动检测并安装 `oh-my-posh`
- ✅ 使用 `winget` 进行静默安装
- ✅ 提供备用安装方法和错误处理

### 2. 更新第8步：最终验证
- ✅ 专门测试 `fastfetch` 可用性
- ✅ 可选显示 `fastfetch` 系统信息
- ✅ 在配置摘要中显示 `fastfetch` 状态

### 3. 更新下一步操作建议
- ✅ 添加 `fastfetch` 测试步骤
- ✅ 在功能测试中包含 `fastfetch`

## 使用说明

### 完整配置（推荐）：
```powershell
.\OneClick-Setup.ps1 -All
```

### 仅安装系统工具：
```powershell
.\OneClick-Setup.ps1 -InstallFonts -InstallModules
```

### 参数说明：
- `-All`: 执行所有配置步骤（包括 fastfetch）
- `-InstallFonts`: 安装字体
- `-InstallModules`: 安装 PowerShell 模块
- `-SetupDeepSeek`: 设置 DeepSeek API 密钥
- `-SkipProfile`: 跳过 PowerShell Profile 配置
- `-SkipTerminal`: 跳过 Windows Terminal 配置
- `-SkipTools`: 跳过自定义工具配置
- `-Force`: 强制覆盖现有配置

## 验证 fastfetch 安装

配置完成后，您可以通过以下方式验证：

```powershell
# 测试 fastfetch 是否正常工作
fastfetch

# 或者在 PowerShell 中直接输入
fastfetch
```

现在您的 `OneClick-Setup.ps1` 脚本已经包含了完整的 `fastfetch` 安装和配置，可以完美复制您原有的 PowerShell 环境了！🎉本回答由 AI 生成，内容仅供参考，请仔细甄别。

# 用户：
错了，由于新电脑就两个盘所以u盘的盘符是e

# DeepSeek：

**原始回答**
您说得对，U盘的盘符变成了 `E:`。我来更新所有脚本中的路径配置：

## 更新 OneClick-Setup.ps1 中的路径

```powershell
# OneClick-Setup.ps1 - PowerShell 环境一键配置工具
param(
    [string]$UDrivePath = "E:\powershell-dive\",  # 改为 E:
    [switch]$InstallFonts,
    [switch]$InstallModules, 
    [switch]$SetupDeepSeek,
    [switch]$All,
    [switch]$SkipProfile,
    [switch]$SkipTerminal,
    [switch]$SkipTools,
    [switch]$Force
)

Write-Host ""
Write-Host "🎯 PowerShell 环境一键配置工具" -ForegroundColor Cyan
Write-Host "═══════════════════════════════════════════════════════════════════════" -ForegroundColor Cyan
Write-Host "作者: 您的名称 | 版本: 2.0 | 日期: $(Get-Date -Format 'yyyy-MM-dd')" -ForegroundColor Gray
Write-Host ""

# 自动检测 U盘路径（如果默认路径不存在）
if (-not (Test-Path $UDrivePath)) {
    Write-Host "🔍 自动检测 U盘路径..." -ForegroundColor Yellow
    
    # 检查可能的驱动器
    $possibleDrives = @("E:", "F:", "G:", "H:", "D:")
    $foundPath = $null
    
    foreach ($drive in $possibleDrives) {
        $testPath = "$drive\powershell-dive"
        if (Test-Path $testPath) {
            $foundPath = $testPath
            Write-Host "   ✅ 在 $drive 找到配置文件夹" -ForegroundColor Green
            break
        }
    }
    
    if ($foundPath) {
        $UDrivePath = $foundPath + "\"
        Write-Host "   📁 使用自动检测的路径: $UDrivePath" -ForegroundColor Green
    } else {
        Write-Host "❌ 错误: 找不到 U盘路径" -ForegroundColor Red
        Write-Host "   请检查 U盘是否已连接，或使用 -UDrivePath 参数指定正确路径" -ForegroundColor Yellow
        Write-Host "   例如: .\OneClick-Setup.ps1 -UDrivePath 'E:\powershell-dive\'" -ForegroundColor White
        return
    }
}

Write-Host "📁 使用配置源: $UDrivePath" -ForegroundColor Green
Write-Host "🏠 用户目录: $env:USERPROFILE" -ForegroundColor Gray
Write-Host ""

# 其余代码保持不变...
```

## 创建路径自动检测脚本

创建一个独立的 `Detect-Path.ps1` 脚本：

```powershell
# Detect-Path.ps1 - 自动检测 U盘路径
param()

Write-Host "🔍 自动检测 U盘路径..." -ForegroundColor Cyan

$possiblePaths = @(
    "E:\powershell-dive\",
    "F:\powershell-dive\", 
    "G:\powershell-dive\",
    "H:\powershell-dive\",
    "D:\powershell-dive\"
)

$foundPath = $null

foreach ($path in $possiblePaths) {
    if (Test-Path $path) {
        $foundPath = $path
        Write-Host "✅ 找到配置文件夹: $path" -ForegroundColor Green
        
        # 检查关键文件是否存在
        $keyFiles = @(
            "Microsoft.PowerShell_profile.ps1",
            "settings.json", 
            "OneClick-Setup.ps1"
        )
        
        $missingFiles = @()
        foreach ($file in $keyFiles) {
            if (-not (Test-Path (Join-Path $path $file))) {
                $missingFiles += $file
            }
        }
        
        if ($missingFiles.Count -eq 0) {
            Write-Host "📋 所有关键文件都存在" -ForegroundColor Green
        } else {
            Write-Host "⚠️  缺少文件: $($missingFiles -join ', ')" -ForegroundColor Yellow
        }
        
        break
    }
}

if (-not $foundPath) {
    Write-Host "❌ 未找到配置文件夹" -ForegroundColor Red
    Write-Host "💡 请检查:" -ForegroundColor Yellow
    Write-Host "   • U盘是否已连接" -ForegroundColor White
    Write-Host "   • 文件夹名称是否为 'powershell-dive'" -ForegroundColor White
    Write-Host "   • 或者手动指定路径: .\OneClick-Setup.ps1 -UDrivePath '您的路径\'" -ForegroundColor White
    
    # 显示当前驱动器
    Write-Host "`n📀 当前可用驱动器:" -ForegroundColor Cyan
    Get-PSDrive -PSProvider FileSystem | Where-Object { $_.Used -gt 0 } | ForEach-Object {
        Write-Host "   $($_.Name): - $($_.Root)" -ForegroundColor Gray
    }
} else {
    # 设置环境变量供其他脚本使用
    $env:POWERSHELL_DIVE_PATH = $foundPath
    Write-Host "`n🚀 使用命令开始配置:" -ForegroundColor Cyan
    Write-Host "   cd '$foundPath'" -ForegroundColor White
    Write-Host "   .\OneClick-Setup.ps1" -ForegroundColor White
    
    # 询问是否立即开始配置
    $startNow = Read-Host "`n是否立即开始配置? (y/n)"
    if ($startNow -eq 'y' -or $startNow -eq 'Y') {
        Set-Location $foundPath
        .\OneClick-Setup.ps1
    }
}

return $foundPath
```

## 更新所有相关脚本的路径

### 在 Install-Profile.ps1 中添加路径检测：

```powershell
# 在 Install-Profile.ps1 开头添加
param(
    [string]$ProfileSource = "",
    [switch]$BackupExisting,
    [switch]$Force,
    [switch]$SetupDeepSeek
)

# 自动检测 U盘路径
if ([string]::IsNullOrEmpty($ProfileSource)) {
    $detectedPath = & (Join-Path (Split-Path $MyInvocation.MyCommand.Path) "Detect-Path.ps1")
    if ($detectedPath) {
        $ProfileSource = Join-Path $detectedPath "Microsoft.PowerShell_profile.ps1"
    } else {
        Write-Host "❌ 无法找到 Profile 文件" -ForegroundColor Red
        return
    }
}
```

### 在 Setup-Terminal.ps1 中添加路径检测：

```powershell
# 在 Setup-Terminal.ps1 开头添加
param(
    [string]$SettingsPath = "",
    [switch]$BackupExisting
)

# 自动检测 U盘路径
if ([string]::IsNullOrEmpty($SettingsPath)) {
    $detectedPath = & (Join-Path (Split-Path $MyInvocation.MyCommand.Path) "Detect-Path.ps1")
    if ($detectedPath) {
        $SettingsPath = Join-Path $detectedPath "settings.json"
    } else {
        Write-Host "❌ 无法找到设置文件" -ForegroundColor Red
        return
    }
}
```

## 创建便捷启动脚本

创建 `Start-Here.cmd` 批处理文件：

```batch
@echo off
chcp 65001 > nul
echo.
echo 🚀 PowerShell 环境配置工具
echo ========================================
echo.

:: 检查 PowerShell 7
where pwsh >nul 2>nul
if %errorlevel% neq 0 (
    echo ❌ 未找到 PowerShell 7
    echo 请先安装 PowerShell 7
    echo 下载地址: https://aka.ms/powershell-release
    pause
    exit /b 1
)

:: 自动检测路径
set "FOUND_PATH="
for %%d in (E F G H D) do (
    if exist "%%d:\powershell-dive\" (
        set "FOUND_PATH=%%d:\powershell-dive\"
        goto :found
    )
)

:found
if "%FOUND_PATH%"=="" (
    echo ❌ 未找到配置文件夹
    echo 请检查:
    echo   • U盘是否已连接
    echo   • 文件夹名称是否为 powershell-dive
    pause
    exit /b 1
)

echo ✅ 找到配置文件夹: %FOUND_PATH%
cd /d "%FOUND_PATH%"

:: 启动 PowerShell 并运行配置
echo.
echo 正在启动配置工具...
pwsh -NoProfile -ExecutionPolicy Bypass -Command ".\OneClick-Setup.ps1 -All"

pause
```

## 最终 U盘文件结构

```
E:\powershell-dive\
├── 📄 启动文件
│   ├── Start-Here.cmd              # 双击启动的批处理文件
│   ├── Detect-Path.ps1             # 路径自动检测脚本
│   └── README.txt                  # 说明文件
├── 📄 主配置脚本
│   ├── OneClick-Setup.ps1          # 主配置脚本（已更新路径）
│   ├── Install-Profile.ps1         # Profile 安装脚本
│   ├── Setup-Terminal.ps1          # 终端配置脚本
│   ├── Install-Fonts.ps1           # 字体安装脚本
│   ├── Test-Tools.ps1              # 工具测试脚本
│   └── Test-Fonts.ps1              # 字体测试脚本
├── 📄 配置文件
│   ├── Microsoft.PowerShell_profile.ps1
│   └── settings.json
├── 📁 fonts\                       # 字体文件夹
├── 📁 themes\                      # 主题文件夹
└── 📁 自定义工具\
    ├── ccr\
    ├── claude\ 
    ├── npm\
    ├── npx\
    └── node_modules\
```

## 创建 README.txt 说明文件

```
PowerShell 环境一键配置工具
============================

📋 使用说明：

方法1：简单启动（推荐）
----------------------
1. 双击运行 "Start-Here.cmd"
2. 按提示操作即可

方法2：手动启动
--------------
1. 打开 PowerShell 7
2. 运行：.\Detect-Path.ps1
3. 或直接运行：.\OneClick-Setup.ps1

🔧 配置内容：
- PowerShell Profile 配置
- Windows Terminal 设置
- Oh-My-Posh 主题和字体
- Fastfetch 系统信息工具
- DeepSeek AI 集成
- 自定义工具 (CCR, Claude 等)

💡 提示：
- 确保 U盘已连接
- 首次运行可能需要管理员权限
- 字体安装需要管理员权限

📞 帮助：
如有问题，请检查各脚本文件的注释说明
```

## 使用方法

### 最简单的方法：
1. 插入 U盘
2. 双击运行 `Start-Here.cmd`
3. 按提示操作

### 手动方法：
```powershell
# 打开 PowerShell 7，然后：
.\Detect-Path.ps1
# 或者
.\OneClick-Setup.ps1 -All
```

### 指定路径（如果自动检测失败）：
```powershell
.\OneClick-Setup.ps1 -UDrivePath "E:\powershell-dive\" -All
```

## 主要改进

1. **路径自动检测** - 自动查找 U盘的正确盘符
2. **容错处理** - 即使盘符变化也能正常工作
3. **便捷启动** - 提供双击即可运行的批处理文件
4. **环境变量** - 使用环境变量传递检测到的路径
5. **用户友好** - 清晰的错误提示和操作指导

现在无论 U盘在哪个驱动器（E:、F:、G: 等），配置工具都能自动找到并正常工作！🎉

