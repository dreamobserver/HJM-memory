# CCR主题文件夹配置

**分类**：AI工具与酒馆
**来源**：DeepSeek Chat 导出
**来源平台**：DeepSeek
**原始文件**：Fixing PowerShell Path Issue with Apostrophes.md
**包含轮次**：11 - 12

---

# 用户：
ccr，与themes都是文件夹，这是内容

# DeepSeek：

**原始回答**
完美！现在文件结构完全正确。根据您提供的信息，我来更新配置脚本以正确处理这些文件：

## 🔄 更新后的配置脚本

### 1. 更新 `OneClick-Setup.ps1` 中的自定义工具部分

```powershell
# 在 OneClick-Setup.ps1 中更新第5步：配置自定义工具
Write-Host "`n5. 配置自定义工具..." -ForegroundColor Yellow

# 定义要复制的自定义工具
$customTools = @(
    @{ Name = "ccr"; Dest = "D:\ccr" },
    @{ Name = "claude"; Dest = "D:\claude" },
    @{ Name = "npm"; Dest = "D:\npm" },
    @{ Name = "npx"; Dest = "D:\npx" }
)

foreach ($tool in $customTools) {
    $toolSource = Join-Path $UDrivePath $tool.Name
    if (Test-Path $toolSource) {
        try {
            if (-not (Test-Path $tool.Dest)) {
                New-Item -ItemType Directory -Path $tool.Dest -Force
            }
            Copy-Item -Path "$toolSource\*" -Destination $tool.Dest -Recurse -Force
            Write-Host "✅ $($tool.Name) 工具已复制到: $($tool.Dest)" -ForegroundColor Green
        }
        catch {
            Write-Host "❌ $($tool.Name) 工具复制失败: $($_.Exception.Message)" -ForegroundColor Red
        }
    } else {
        Write-Host "⚠️  未找到工具: $($tool.Name)" -ForegroundColor Yellow
    }
}

# 如果有 node_modules，也复制（如果是工具依赖）
$nodeModulesPath = Join-Path $UDrivePath "node_modules"
if (Test-Path $nodeModulesPath) {
    Write-Host "📦 复制 Node.js 模块..." -ForegroundColor Yellow
    try {
        $nodeDest = "D:\node_modules"
        Copy-Item -Path $nodeModulesPath -Destination $nodeDest -Recurse -Force
        Write-Host "✅ Node.js 模块已复制" -ForegroundColor Green
    }
    catch {
        Write-Host "❌ Node.js 模块复制失败: $($_.Exception.Message)" -ForegroundColor Red
    }
}
```

### 2. 更新 `Install-Profile.ps1` 中的路径适配

```powershell
# 在 Install-Profile.ps1 的路径适配部分添加工具路径更新
$profileContent = $profileContent.Replace(
    "function ccr { & 'D:\\ccr\\ccr.cmd' @args }",
    "function ccr { & 'D:\ccr\ccr.cmd' @args }"
)

# 添加其他工具的函数（如果配置文件中没有）
$additionalTools = @"
`n# 自定义工具函数
function claude { & 'D:\claude\claude.cmd' @args }
function my-npm { & 'D:\npm\npm.cmd' @args }
function my-npx { & 'D:\npx\npx.cmd' @args }
"@

# 检查是否已包含这些函数，如果没有则添加
if ($profileContent -notmatch "function claude") {
    $profileContent += $additionalTools
}
```

### 3. 创建工具验证脚本 `Test-Tools.ps1`

```powershell
# Test-Tools.ps1 - 验证所有工具是否正常工作
param([string]$UDrivePath = "G:\powershell-dive\")

Write-Host "🧪 测试自定义工具..." -ForegroundColor Cyan

$tools = @(
    @{ Name = "ccr"; Path = "D:\ccr\ccr.cmd" },
    @{ Name = "claude"; Path = "D:\claude\claude.cmd" },
    @{ Name = "npm"; Path = "D:\npm\npm.cmd" },
    @{ Name = "npx"; Path = "D:\npx\npx.cmd" }
)

foreach ($tool in $tools) {
    if (Test-Path $tool.Path) {
        try {
            # 测试工具是否能正常执行（不实际运行，只检查存在性和权限）
            $result = Get-Command $tool.Path -ErrorAction Stop
            Write-Host "✅ $($tool.Name) - 可用" -ForegroundColor Green
        }
        catch {
            Write-Host "⚠️  $($tool.Name) - 存在但可能无法执行" -ForegroundColor Yellow
        }
    } else {
        Write-Host "❌ $($tool.Name) - 未找到" -ForegroundColor Red
    }
}

# 测试 PowerShell 函数
Write-Host "`n🔧 测试 PowerShell 函数..." -ForegroundColor Cyan

$functions = @("ccr", "claude", "my-npm", "my-npx", "ds", "ds-re")
foreach ($func in $functions) {
    if (Get-Command $func -ErrorAction SilentlyContinue) {
        Write-Host "✅ $func 函数 - 已加载" -ForegroundColor Green
    } else {
        Write-Host "❌ $func 函数 - 未找到" -ForegroundColor Red
    }
}

Write-Host "`n🎉 工具测试完成!" -ForegroundColor Cyan
```

### 4. 更新主配置脚本的最终步骤

在 `OneClick-Setup.ps1` 的最后添加工具测试：

```powershell
# 在 OneClick-Setup.ps1 末尾添加

# 6. 测试所有工具
Write-Host "`n6. 测试安装的工具..." -ForegroundColor Yellow
$testScript = Join-Path $UDrivePath "Test-Tools.ps1"
if (Test-Path $testScript) {
    & $testScript
} else {
    Write-Host "⚠️  未找到工具测试脚本" -ForegroundColor Yellow
}

Write-Host "`n" + "=" * 50
Write-Host "🎉 一键配置完成!" -ForegroundColor Cyan

# 最终建议
Write-Host "`n📋 下一步操作:" -ForegroundColor Yellow
Write-Host "   1. 重新启动 PowerShell" -ForegroundColor White
Write-Host "   2. 或在当前会话运行: . `$PROFILE" -ForegroundColor White
Write-Host "   3. 测试命令: ds '你好，DeepSeek'" -ForegroundColor White
Write-Host "   4. 测试命令: ccr --help" -ForegroundColor White

# 立即重新加载 Profile
$reloadNow = Read-Host "`n是否立即重新加载 Profile? (y/n)"
if ($reloadNow -eq 'y' -or $reloadNow -eq 'Y') {
    try {
        . $PROFILE
        Write-Host "✅ Profile 已重新加载" -ForegroundColor Green
        
        # 重新测试函数
        Write-Host "`n🔄 重新测试函数..." -ForegroundColor Cyan
        & $testScript
    }
    catch {
        Write-Host "❌ Profile 重新加载失败: $($_.Exception.Message)" -ForegroundColor Red
    }
}
```

## 📁 最终 U盘文件结构确认

您的 U盘结构现在应该是：

```
G:\powershell-dive\
├── 📄 主脚本文件
│   ├── OneClick-Setup.ps1
│   ├── Install-Profile.ps1
│   ├── Setup-Terminal.ps1
│   ├── Install-Fonts.ps1
│   └── Test-Tools.ps1 (新增)
├── 📄 配置文件
│   ├── Microsoft.PowerShell_profile.ps1
│   └── settings.json
├── 📁 自定义工具文件夹
│   ├── ccr\ (包含 ccr.cmd, ccr.ps1)
│   ├── claude\ (包含 claude.cmd, claude.ps1)
│   ├── npm\ (包含 npm.cmd, npm.ps1)
│   ├── npx\ (包含 npx.cmd, npx.ps1)
│   └── node_modules\ (Node.js 模块)
└── 📁 themes\ (包含所有 .omp.json 主题文件)
    ├── tokyo.omp.json
    ├── jandedobbeleer.omp.json
    └── 其他70+个主题文件...
```

## 🚀 使用方法

现在您可以运行完整的一键配置：

```powershell
# 插入 U盘后，打开 PowerShell 7
cd G:\powershell-dive

# 完整配置（推荐）
.\OneClick-Setup.ps1 -All -SetupDeepSeek

# 或者分步骤配置
.\Install-Profile.ps1 -BackupExisting -SetupDeepSeek
.\Setup-Terminal.ps1 -BackupExisting
.\Test-Tools.ps1
```

## ✅ 配置完成后的验证清单

配置完成后请检查：

- [ ] PowerShell 启动无错误
- [ ] `ds` 和 `ds-re` 命令可用
- [ ] `ccr` 命令可用
- [ ] `claude` 命令可用（如果适用）
- [ ] Oh-My-Posh 主题正常显示
- [ ] Windows Terminal 设置正确应用
- [ ] 所有自定义工具路径正确

## 💡 注意事项

1. **路径兼容性**：脚本会自动处理用户名差异，但工具的目标路径固定为 `D:\` 驱动器
2. **权限问题**：如果遇到权限错误，请以管理员身份运行 PowerShell
3. **依赖关系**：某些工具可能需要额外的运行时（如 Node.js）
4. **主题文件**：您有丰富的主题选择，可以在配置文件中切换使用

您的 U盘配置现在已经非常完善，包含了完整的 PowerShell 环境、Windows Terminal 设置、多个自定义工具和丰富的主题库！🎉本回答由 AI 生成，内容仅供参考，请仔细甄别。

# 用户：
字体文件夹还没有配置

# DeepSeek：

**原始回答**
您说得对，字体文件夹确实还没有配置。我来为您创建完整的字体安装方案：

## 1. 创建字体文件夹和安装脚本

### 创建字体文件夹结构
在 U盘 `G:\powershell-dive\` 中创建 `fonts\` 文件夹，并放入常用的 Nerd Fonts：

```
G:\powershell-dive\
└── fonts\
    ├── MesloLGM NF.ttf
    ├── CascadiaCode NF.ttf
    ├── FiraCode NF.ttf
    ├── JetBrainsMono NF.ttf
    ├── UbuntuMono NF.ttf
    └── 其他需要的字体文件.ttf
```

### 更新 `Install-Fonts.ps1` 字体安装脚本

```powershell
# Install-Fonts.ps1 - 完整的字体自动安装脚本
param(
    [string]$FontsPath = "G:\powershell-dive\fonts\",
    [switch]$Force,
    [switch]$ListOnly,
    [string[]]$InstallSpecific
)

Write-Host "🔤 PowerShell 终端字体安装工具" -ForegroundColor Cyan
Write-Host "=" * 50

# 检查字体目录
if (-not (Test-Path $FontsPath)) {
    Write-Host "❌ 字体目录不存在: $FontsPath" -ForegroundColor Red
    Write-Host "请创建 fonts 文件夹并放入字体文件" -ForegroundColor Yellow
    return
}

# 获取系统字体目录
$fontInstallPath = "$env:WINDIR\Fonts"
$registryPath = "HKLM:\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts"

Write-Host "系统字体目录: $fontInstallPath" -ForegroundColor Gray

# 支持的字体文件扩展名
$fontExtensions = @("*.ttf", "*.otf", "*.ttc")

# 获取所有字体文件
$fontFiles = Get-ChildItem -Path $FontsPath -Include $fontExtensions -Recurse

if ($fontFiles.Count -eq 0) {
    Write-Host "❌ 未找到字体文件 (支持: .ttf, .otf, .ttc)" -ForegroundColor Red
    return
}

# 仅列出字体
if ($ListOnly) {
    Write-Host "`n📋 可用的字体文件:" -ForegroundColor Yellow
    $fontFiles | ForEach-Object { 
        Write-Host "   • $($_.Name)" -ForegroundColor White 
    }
    return
}

# 显示找到的字体
Write-Host "`n🎯 找到 $($fontFiles.Count) 个字体文件:" -ForegroundColor Green
$fontFiles | ForEach-Object { Write-Host "   • $($_.Name)" -ForegroundColor Gray }

# 检查管理员权限（字体安装需要管理员权限）
$isAdmin = ([Security.Principal.WindowsPrincipal] [Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole] "Administrator")

if (-not $isAdmin) {
    Write-Host "`n⚠️  字体安装需要管理员权限!" -ForegroundColor Yellow
    Write-Host "请以管理员身份运行 PowerShell，然后执行此脚本" -ForegroundColor White
    
    $elevate = Read-Host "是否尝试以管理员身份重新运行? (y/n)"
    if ($elevate -eq 'y' -or $elevate -eq 'Y') {
        try {
            $scriptPath = $MyInvocation.MyCommand.Path
            Start-Process pwsh.exe -ArgumentList "-NoProfile -ExecutionPolicy Bypass -File `"$scriptPath`" -Force" -Verb RunAs
            return
        }
        catch {
            Write-Host "❌ 提升权限失败: $($_.Exception.Message)" -ForegroundColor Red
            Write-Host "请手动以管理员身份运行此脚本" -ForegroundColor Yellow
        }
    }
    return
}

# 安装字体函数
function Install-Font {
    param([System.IO.FileInfo]$FontFile)
    
    $fontName = $FontFile.BaseName
    $destination = Join-Path $fontInstallPath $FontFile.Name
    
    try {
        # 检查是否已安装
        $installed = Test-Path $destination
        if ($installed -and -not $Force) {
            Write-Host "⏭️  字体已存在: $fontName" -ForegroundColor Yellow
            return $false
        }
        
        # 复制字体文件
        Copy-Item -Path $FontFile.FullName -Destination $destination -Force
        Write-Host "✅ 已安装字体: $fontName" -ForegroundColor Green
        
        # 注册字体（可选，系统通常会自动注册）
        # 这里我们让系统自动处理字体注册
        
        return $true
    }
    catch {
        Write-Host "❌ 安装失败: $fontName - $($_.Exception.Message)" -ForegroundColor Red
        return $false
    }
}

# 安装字体
Write-Host "`n🚀 开始安装字体..." -ForegroundColor Cyan

$installedCount = 0
$skippedCount = 0

foreach ($fontFile in $fontFiles) {
    # 如果指定了特定字体，检查是否在列表中
    if ($InstallSpecific.Count -gt 0 -and $fontFile.BaseName -notin $InstallSpecific) {
        continue
    }
    
    if (Install-Font -FontFile $fontFile) {
        $installedCount++
    } else {
        $skippedCount++
    }
}

# 字体安装完成后的建议
Write-Host "`n" + "=" * 50
Write-Host "🎉 字体安装完成!" -ForegroundColor Cyan
Write-Host "   • 成功安装: $installedCount 个字体" -ForegroundColor Green
Write-Host "   • 跳过安装: $skippedCount 个字体" -ForegroundColor Yellow

if ($installedCount -gt 0) {
    Write-Host "`n📋 下一步操作:" -ForegroundColor Yellow
    Write-Host "   1. 重启 Windows Terminal" -ForegroundColor White
    Write-Host "   2. 在设置中选择已安装的 Nerd Font" -ForegroundColor White
    Write-Host "   3. 推荐字体: MesloLGM NF 或 CascadiaCode NF" -ForegroundColor White
    
    # 显示已安装的 Nerd Fonts 列表
    Write-Host "`n🔤 推荐的 Nerd Fonts:" -ForegroundColor Cyan
    $nerdFonts = $fontFiles | Where-Object { $_.Name -match "NF" } | ForEach-Object { $_.BaseName }
    $nerdFonts | ForEach-Object { Write-Host "   • $_" -ForegroundColor White }
}

# 检查当前终端字体设置
Write-Host "`n🔍 当前终端字体检查:" -ForegroundColor Cyan
try {
    $wtSettingsPath = "$env:LOCALAPPDATA\Microsoft\Windows Terminal\settings.json"
    if (Test-Path $wtSettingsPath) {
        $settings = Get-Content $wtSettingsPath -Raw | ConvertFrom-Json
        if ($settings.profiles.defaults.font) {
            Write-Host "   当前默认字体: $($settings.profiles.defaults.font.face)" -ForegroundColor Gray
        }
    }
}
catch {
    Write-Host "   无法读取当前字体设置" -ForegroundColor Gray
}
```

## 2. 创建字体下载脚本（可选）

如果还没有字体文件，可以创建 `Download-Fonts.ps1`：

```powershell
# Download-Fonts.ps1 - 字体下载脚本（可选）
param(
    [string]$DownloadPath = "G:\powershell-dive\fonts\",
    [switch]$DownloadAll,
    [string[]]$SpecificFonts
)

Write-Host "📥 Nerd Fonts 下载工具" -ForegroundColor Cyan

# 创建下载目录
New-Item -ItemType Directory -Path $DownloadPath -Force | Out-Null

# 常用 Nerd Fonts 下载链接（请替换为实际可用的链接）
$fontUrls = @{
    "MesloLGM NF" = "https://github.com/ryanoasis/nerd-fonts/releases/download/v3.0.2/Meslo.zip"
    "CascadiaCode NF" = "https://github.com/ryanoasis/nerd-fonts/releases/download/v3.0.2/CascadiaCode.zip"
    "FiraCode NF" = "https://github.com/ryanoasis/nerd-fonts/releases/download/v3.0.2/FiraCode.zip"
    "JetBrainsMono NF" = "https://github.com/ryanoasis/nerd-fonts/releases/download/v3.0.2/JetBrainsMono.zip"
    "UbuntuMono NF" = "https://github.com/ryanoasis/nerd-fonts/releases/download/v3.0.2/UbuntuMono.zip"
}

# 选择要下载的字体
if ($SpecificFonts.Count -gt 0) {
    $selectedFonts = $SpecificFonts
} elseif ($DownloadAll) {
    $selectedFonts = $fontUrls.Keys
} else {
    Write-Host "`n请选择要下载的字体:" -ForegroundColor Yellow
    $i = 1
    $fontUrls.Keys | ForEach-Object { 
        Write-Host "   $i. $_" -ForegroundColor White
        $i++
    }
    
    $choices = Read-Host "`n输入数字（多个用逗号分隔，或输入 all）"
    if ($choices -eq "all") {
        $selectedFonts = $fontUrls.Keys
    } else {
        $selectedIndexes = $choices -split ',' | ForEach-Object { [int]$_ - 1 }
        $selectedFonts = $fontUrls.Keys | Select-Object -Index $selectedIndexes
    }
}

# 下载字体
foreach ($fontName in $selectedFonts) {
    if ($fontUrls.ContainsKey($fontName)) {
        $url = $fontUrls[$fontName]
        $zipPath = Join-Path $DownloadPath "$fontName.zip"
        $extractPath = Join-Path $DownloadPath $fontName
        
        Write-Host "`n📥 下载 $fontName..." -ForegroundColor Yellow
        
        try {
            # 下载ZIP文件
            Invoke-WebRequest -Uri $url -OutFile $zipPath
            
            # 解压
            Expand-Archive -Path $zipPath -DestinationPath $extractPath -Force
            
            # 查找.ttf文件并移动到fonts根目录
            $ttfFiles = Get-ChildItem -Path $extractPath -Filter "*.ttf" -Recurse
            foreach ($ttfFile in $ttfFiles) {
                $destPath = Join-Path $DownloadPath $ttfFile.Name
                Move-Item -Path $ttfFile.FullName -Destination $destPath -Force
            }
            
            # 清理
            Remove-Item -Path $zipPath -Force
            Remove-Item -Path $extractPath -Recurse -Force
            
            Write-Host "✅ $fontName 下载完成" -ForegroundColor Green
        }
        catch {
            Write-Host "❌ $fontName 下载失败: $($_.Exception.Message)" -ForegroundColor Red
        }
    }
}

Write-Host "`n🎉 字体下载完成!" -ForegroundColor Cyan
Write-Host "运行 .\Install-Fonts.ps1 来安装字体" -ForegroundColor White
```

## 3. 更新主配置脚本

在 `OneClick-Setup.ps1` 中更新字体安装部分：

```powershell
# 在 OneClick-Setup.ps1 中更新字体安装部分

# 3. 安装字体
if ($InstallFonts -or $All) {
    Write-Host "`n3. 安装终端字体..." -ForegroundColor Yellow
    $fontScript = Join-Path $UDrivePath "Install-Fonts.ps1"
    if (Test-Path $fontScript) {
        # 检查是否已有字体文件
        $fontsDir = Join-Path $UDrivePath "fonts"
        if (Test-Path $fontsDir) {
            $fontFiles = Get-ChildItem -Path $fontsDir -Filter "*.ttf" -Recurse
            if ($fontFiles.Count -gt 0) {
                Write-Host "找到 $($fontFiles.Count) 个字体文件" -ForegroundColor Green
                & $fontScript -Force
            } else {
                Write-Host "⚠️  字体目录为空" -ForegroundColor Yellow
                
                $downloadFonts = Read-Host "是否下载推荐的 Nerd Fonts? (y/n)"
                if ($downloadFonts -eq 'y' -or $downloadFonts -eq 'Y') {
                    $downloadScript = Join-Path $UDrivePath "Download-Fonts.ps1"
                    if (Test-Path $downloadScript) {
                        & $downloadScript -DownloadAll
                        # 安装下载的字体
                        & $fontScript -Force
                    } else {
                        Write-Host "❌ 找不到字体下载脚本" -ForegroundColor Red
                        Write-Host "请手动下载 Nerd Fonts 到 fonts 文件夹" -ForegroundColor Yellow
                    }
                }
            }
        } else {
            Write-Host "❌ 找不到字体目录" -ForegroundColor Red
        }
    } else {
        Write-Host "❌ 找不到字体安装脚本" -ForegroundColor Red
    }
}
```

## 4. 创建字体配置验证脚本

```powershell
# Test-Fonts.ps1 - 字体配置验证脚本
param([string]$UDrivePath = "G:\powershell-dive\")

Write-Host "🔤 字体配置验证" -ForegroundColor Cyan
Write-Host "=" * 50

# 检查已安装的 Nerd Fonts
Write-Host "`n📋 系统已安装的 Nerd Fonts:" -ForegroundColor Yellow
$installedFonts = Get-ChildItem "$env:WINDIR\Fonts\*NF*.ttf" -ErrorAction SilentlyContinue
if ($installedFonts.Count -gt 0) {
    $installedFonts | ForEach-Object { 
        Write-Host "   ✅ $($_.BaseName)" -ForegroundColor Green 
    }
} else {
    Write-Host "   ❌ 未找到 Nerd Fonts" -ForegroundColor Red
}

# 检查 U 盘中的字体文件
Write-Host "`n📂 U 盘中的字体文件:" -ForegroundColor Yellow
$uDiskFonts = Get-ChildItem "$UDrivePath\fonts\*.ttf" -ErrorAction SilentlyContinue
if ($uDiskFonts.Count -gt 0) {
    $uDiskFonts | ForEach-Object { 
        Write-Host "   📄 $($_.Name)" -ForegroundColor Gray 
    }
} else {
    Write-Host "   ❌ U 盘中无字体文件" -ForegroundColor Red
}

# 检查 Windows Terminal 字体设置
Write-Host "`n⚙️  Windows Terminal 字体设置:" -ForegroundColor Yellow
try {
    $wtSettingsPath = "$env:LOCALAPPDATA\Microsoft\Windows Terminal\settings.json"
    if (Test-Path $wtSettingsPath) {
        $settings = Get-Content $wtSettingsPath -Raw | ConvertFrom-Json
        $fontFace = $settings.profiles.defaults.font.face
        if ($fontFace) {
            Write-Host "   当前字体: $fontFace" -ForegroundColor White
            
            # 检查是否是 Nerd Font
            if ($fontFace -match "NF") {
                Write-Host "   ✅ 已配置 Nerd Font" -ForegroundColor Green
            } else {
                Write-Host "   ⚠️  未使用 Nerd Font" -ForegroundColor Yellow
            }
        } else {
            Write-Host "   ⚠️  未设置默认字体" -ForegroundColor Yellow
        }
    } else {
        Write-Host "   ❌ 未找到 Windows Terminal 设置" -ForegroundColor Red
    }
}
catch {
    Write-Host "   ❌ 无法读取字体设置" -ForegroundColor Red
}

Write-Host "`n💡 建议:" -ForegroundColor Cyan
Write-Host "   1. 运行 .\Install-Fonts.ps1 安装字体" -ForegroundColor White
Write-Host "   2. 在 Windows Terminal 设置中选择 Nerd Font" -ForegroundColor White
Write-Host "   3. 推荐使用 MesloLGM NF 或 CascadiaCode NF" -ForegroundColor White
```

## 5. 最终 U盘文件结构

现在您的 U盘应该是这样的完整结构：

```
G:\powershell-dive\
├── 📄 主脚本文件
│   ├── OneClick-Setup.ps1
│   ├── Install-Profile.ps1
│   ├── Setup-Terminal.ps1
│   ├── Install-Fonts.ps1
│   ├── Download-Fonts.ps1 (可选)
│   ├── Test-Tools.ps1
│   └── Test-Fonts.ps1 (新增)
├── 📄 配置文件
│   ├── Microsoft.PowerShell_profile.ps1
│   └── settings.json
├── 📁 fonts\ (新增)
│   ├── MesloLGM NF.ttf
│   ├── CascadiaCode NF.ttf
│   ├── FiraCode NF.ttf
│   └── 其他字体文件...
├── 📁 自定义工具文件夹
│   ├── ccr\
│   ├── claude\
│   ├── npm\
│   ├── npx\
│   └── node_modules\
└── 📁 themes\
    ├── tokyo.omp.json
    ├── jandedobbeleer.omp.json
    └── 其他70+个主题文件...
```

## 🚀 使用方法

现在您可以使用完整的字体配置：

```powershell
# 列出可用字体
.\Install-Fonts.ps1 -ListOnly

# 安装所有字体（需要管理员权限）
.\Install-Fonts.ps1 -Force

# 验证字体配置
.\Test-Fonts.ps1

# 完整的一键配置（包括字体）
.\OneClick-Setup.ps1 -All
```

## 💡 字体获取建议

1. **从 GitHub 下载**：访问 [nerd-fonts GitHub](https://github.com/ryanoasis/nerd-fonts) 下载
2. **使用脚本下载**：运行 `.\Download-Fonts.ps1`（需要网络连接）
3. **手动下载**：下载后放入 `fonts\` 文件夹

现在您的 U盘配置就真正完整了，包含了字体、主题、工具和所有配置脚本！🎉

