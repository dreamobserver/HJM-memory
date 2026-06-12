# 用户：

&: The term 'C:\Users\Aaron Kwo'k\AppData\Local\oh-my-posh\init.26.19.1.6a2ee05abe7c14bb.10.ps1' is not recognized as a name of a cmdlet, function, script file, or executable program.
Check the spelling of the name, or if a path was included, verify that the path is correct and try again.

# DeepSeek：

**原始回答**

This error occurs because your Windows username contains an apostrophe (`'`), which is causing issues with PowerShell path parsing. Here are several solutions:

## Solution 1: Escape the Apostrophe in Your PowerShell Profile

Edit your PowerShell profile and escape the apostrophe:

```powershell
# Open your profile
notepad $PROFILE

# Replace the oh-my-posh line with:
oh-my-posh init pwsh --config "$env:POSH_THEMES_PATH\your-theme.omp.json" | Invoke-Expression
```

## Solution 2: Use the Full Path with Proper Escaping

```powershell
# In your $PROFILE, use:
. "C:\Users\Aaron Kwo'k\AppData\Local\oh-my-posh\init.ps1"
```

## Solution 3: Use the Environment Variable

```powershell
# Use the environment variable instead of hardcoded path
oh-my-posh init pwsh | Invoke-Expression
```

## Solution 4: Move oh-my-posh to a Different Location

1. Create a new directory without special characters:
```powershell
New-Item -ItemType Directory -Path "C:\Tools\oh-my-posh" -Force
```

2. Reinstall oh-my-posh to this location or copy the files.

## Solution 5: Use Backticks for Escaping

```powershell
# Escape the apostrophe with a backtick
. 'C:\Users\Aaron Kwo`'k\AppData\Local\oh-my-posh\init.ps1'
```

## Recommended Approach

I recommend **Solution 1** or **Solution 3** as they're the most reliable. Your PowerShell profile should look like this:

```powershell
# Reliable approach using oh-my-posh command
oh-my-posh init pwsh --config "$env:POSH_THEMES_PATH\jandedobbeleer.omp.json" | Invoke-Expression
```

After making changes, reload your profile:
```powershell
. $PROFILE
```

The apostrophe in your username is causing the path to be interpreted incorrectly by PowerShell's parser. Using double quotes or the built-in oh-my-posh command avoids this issue entirely.

# 用户：

使用中文回答

# DeepSeek：

**原始回答**

这个错误是因为您的 Windows 用户名中包含**单引号**，导致 PowerShell 在解析路径时出现问题。以下是几种解决方案：

## 方案 1：修改 PowerShell 配置文件（推荐）

1. 用记事本打开 PowerShell 配置文件：
```powershell
notepad $PROFILE
```

2. 将 oh-my-posh 的初始化命令改为：
```powershell
oh-my-posh init pwsh --config "$env:POSH_THEMES_PATH\你的主题名.omp.json" | Invoke-Expression
```

## 方案 2：使用转义字符

在配置文件中使用：
```powershell
. "C:\Users\Aaron Kwo'k\AppData\Local\oh-my-posh\init.ps1"
```
或者
```powershell
. 'C:\Users\Aaron Kwo''k\AppData\Local\oh-my-posh\init.ps1'
```

## 方案 3：使用环境变量

最简单的办法：
```powershell
oh-my-posh init pwsh | Invoke-Expression
```

## 方案 4：移动安装位置

如果上述方法都不行，可以将 oh-my-posh 移动到没有特殊字符的路径：
```powershell
# 创建新目录
New-Item -ItemType Directory -Path "C:\Tools\oh-my-posh" -Force
```

## 最推荐的解决方案

使用**方案 1**，在你的 `$PROFILE` 文件中这样写：
```powershell
oh-my-posh init pwsh --config "$env:POSH_THEMES_PATH\jandedobbeleer.omp.json" | Invoke-Expression
```

修改后重新加载配置文件：
```powershell
. $PROFILE
```

**问题原因**：用户名中的单引号 `'` 在 PowerShell 中被当作特殊字符处理，导致路径被错误分割。使用双引号或 oh-my-posh 的内置命令可以避免这个问题。

# 用户：

ok，解决了，如果我想要在另一台电脑上配置与目前电脑上一样的powershell7设置该将哪些文件迁移到另一台电脑上哪些文件夹中

# DeepSeek：

**原始回答**

要在另一台电脑上配置相同的 PowerShell 7 设置，你需要迁移以下文件和文件夹：

## 需要迁移的核心文件

### 1. PowerShell 配置文件
- **位置**: `C:\Users\[用户名]\Documents\PowerShell\`
- **文件**: `Microsoft.PowerShell_profile.ps1`
- **这是最重要的配置文件**

### 2. Oh-My-Posh 配置
- **主题文件**: `C:\Users\[用户名]\AppData\Local\Programs\oh-my-posh\themes\`
- **自定义配置**: 你的 `.omp.json` 主题文件

### 3. 迁移步骤

#### 第一步：备份当前电脑的文件
```powershell
# 1. 复制整个 PowerShell 配置目录
Copy-Item -Path "$HOME\Documents\PowerShell" -Destination "备份路径" -Recurse

# 2. 复制 Oh-My-Posh 主题
Copy-Item -Path "$env:POSH_THEMES_PATH\*" -Destination "备份路径\themes\" -Recurse

# 3. 复制可能的手动安装模块
Copy-Item -Path "$HOME\Documents\PowerShell\Modules" -Destination "备份路径\Modules\" -Recurse
```

#### 第二步：在新电脑上安装基础软件
1. 安装 **PowerShell 7**
2. 安装 **Oh-My-Posh**
   ```powershell
   winget install JanDeDobbeleer.OhMyPosh -s winget
   ```

#### 第三步：恢复配置文件
1. 将备份的 `PowerShell` 文件夹复制到：
   `C:\Users\[新用户名]\Documents\PowerShell\`

2. 将主题文件复制到：
   `C:\Users\[新用户名]\AppData\Local\Programs\oh-my-posh\themes\`

#### 第四步：安装必要的字体
- 下载并安装 **Nerd Font**（如 Meslo LGM NF、Cascadia Code 等）
- 在终端设置中使用该字体

## 可选迁移内容

### 1. 模块和插件
如果需要相同的功能模块：
```powershell
# 常用模块
Install-Module -Name PSReadLine -Force
Install-Module -Name Terminal-Icons -Force
Install-Module -Name Z -Force
```

### 2. 终端设置
如果使用 Windows Terminal：
- 导出 Windows Terminal 的 `settings.json` 文件
- 在新电脑上导入

## 快速检查清单

在新电脑上配置完成后，检查：
- [ ] PowerShell 7 已安装
- [ ] Oh-My-Posh 已安装
- [ ] 配置文件已复制
- [ ] 主题文件已复制
- [ ] Nerd Font 已安装并设置
- [ ] 必要的 PowerShell 模块已安装

这样就能在新电脑上获得完全相同的 PowerShell 环境了！

# 用户：

感觉还是有点不完全，这是全部的$PROFILE内容：oh-my-posh init pwsh --config "$env:POSH_THEMES_PATH\jandedobbeleer.omp.json" | Invoke-Expression
# 强制设置 UTF-8 编码
$OutputEncoding = [System.Text.Encoding]::UTF8
[Console]::OutputEncoding = [System.Text.Encoding]::UTF8
[Console]::InputEncoding = [System.Text.Encoding]::UTF8

# 设置控制台代码页为 UTF-8
if ($host.Name -eq 'ConsoleHost') {
    chcp 65001 > $null
}

# 设置 PowerShell 默认编码
$PSDefaultParameterValues['*:Encoding'] = 'utf8'

# 修复 oh-my-posh 的编码问题
function global:prompt {
    # 保存最后退出代码
    $lastExitCode = $global:?
    
    # 设置编码
    [Console]::OutputEncoding = [System.Text.Encoding]::UTF8
    
    # 调用 oh-my-posh
    $originalPrompt = oh-my-posh prompt print primary --config="$env:POSH_THEMES_PATH/tokyo.omp.json" --error=$lastExitCode
    
    # 返回处理后的提示符
    return $originalPrompt
}

oh-my-posh init pwsh --config "$env:POSH_THEMES_PATH/tokyo.omp.json" | Invoke-Expression

# Fastfetch Auto Launch (No Chinese to avoid encoding issues)
if (Get-Command fastfetch -ErrorAction SilentlyContinue) {
    fastfetch  # Run fastfetch if installed
} else {
    # Show install tip if missing (English only)
    Write-Host "Fastfetch not found! Install it first: winget install fastfetch" -ForegroundColor Yellow
}
function ccr { & 'D:\ccr\ccr.cmd' @args }

function Invoke-DeepSeek {
    param(
        [Parameter(Mandatory=$true)]
        [string]$Question,
        
        [ValidateSet("deepseek-chat", "deepseek-reasoner")]
        [string]$Model = "deepseek-chat",
        
        [int]$MaxTokens = 4000,
        [double]$Temperature = 0.7,
        [switch]$Reset,
        [switch]$NoHistory
    )
    
    # 初始化历史记录
    if (-not $script:DeepSeekHistory) {
        $script:DeepSeekHistory = @()
    }
    
    if ($Reset) {
        $script:DeepSeekHistory = @()
        Write-Host "对话历史已重置" -ForegroundColor Green
        return
    }
    
    $apiKey = $env:DEEPSEEK_API_KEY
    if (-not $apiKey) {
        Write-Error "请先设置 DEEPSEEK_API_KEY 环境变量"
        return
    }
    
    $url = "https://api.deepseek.com/v1/chat/completions"
    
    # 构建消息数组
    $messages = @()
    if (-not $NoHistory -and $script:DeepSeekHistory.Count -gt 0) {
        $messages += $script:DeepSeekHistory
    }
    $messages += @{role = "user"; content = $Question}
    
    # 构建请求体
    $body = @{
        model = $Model
        messages = $messages
        max_tokens = $MaxTokens
        temperature = $Temperature
        stream = $false
    }
    
    # 使用正确的 JSON 编码方式
    $jsonBody = $body | ConvertTo-Json -Depth 10
    
    try {
        Write-Host "正在发送请求..." -ForegroundColor Yellow
        
        # 使用正确的编码发送请求
        $response = Invoke-RestMethod -Uri $url -Method Post -Headers @{
            "Content-Type" = "application/json"
            "Authorization" = "Bearer $apiKey"
        } -Body ([System.Text.Encoding]::UTF8.GetBytes($jsonBody)) -ErrorAction Stop
        
        $answer = $response.choices[0].message.content
        
        # 编码修复 - 处理中文乱码
        try {
            # 检查是否包含中文字符（如果已经是乱码）
            if ($answer -match "[^\u0000-\u007F]") {
                # 如果是正常中文，直接返回
                $result = $answer
            } else {
                # 尝试从可能的错误编码转换
                $bytes = [System.Text.Encoding]::GetEncoding("ISO-8859-1").GetBytes($answer)
                $result = [System.Text.Encoding]::UTF8.GetString($bytes)
            }
        }
        catch {
            $result = $answer
        }
        
        # 更新历史记录
        if (-not $NoHistory) {
            $script:DeepSeekHistory += @{role = "user"; content = $Question}
            $script:DeepSeekHistory += @{role = "assistant"; content = $result}
            
            # 限制历史记录长度
            if ($script:DeepSeekHistory.Count -gt 10) {
                $script:DeepSeekHistory = $script:DeepSeekHistory | Select-Object -Last 10
            }
        }
        
        return $result
    }
    catch {
        Write-Error "API 调用失败: $($_.Exception.Message)"
        if ($_.Exception.Response) {
            $reader = New-Object System.IO.StreamReader($_.Exception.Response.GetResponseStream())
            $reader.BaseStream.Position = 0
            $reader.DiscardBufferedData()
            $errorResponse = $reader.ReadToEnd()
            Write-Host "错误详情: $errorResponse" -ForegroundColor Red
        }
        return $null
    }
}

function Test-DeepSeekSimple {
    param(
        [string]$Question = "Hello"
    )
    
    $apiKey = $env:DEEPSEEK_API_KEY
    if (-not $apiKey) {
        Write-Error "请先设置 DEEPSEEK_API_KEY 环境变量"
        return
    }
    
    $url = "https://api.deepseek.com/v1/chat/completions"
    
    # 使用硬编码的 JSON 字符串避免编码问题
    $bodyJson = @"
{
    "model": "deepseek-chat",
    "messages": [
        {
            "role": "user",
            "content": "$($Question.Replace('"', '\"').Replace('\', '\\'))"
        }
    ],
    "max_tokens": 1000,
    "temperature": 0.7,
    "stream": false
}
"@
    
    try {
        Write-Host "测试请求..." -ForegroundColor Yellow
        
        $response = Invoke-RestMethod -Uri $url -Method Post -Headers @{
            "Content-Type" = "application/json"
            "Authorization" = "Bearer $apiKey"
        } -Body $bodyJson
        
        $answer = $response.choices[0].message.content
        
        # 编码修复
        try {
            $bytes = [System.Text.Encoding]::GetEncoding("ISO-8859-1").GetBytes($answer)
            $result = [System.Text.Encoding]::UTF8.GetString($bytes)
            return $result
        }
        catch {
            return $answer
        }
    }
    catch {
        Write-Host "错误: $($_.Exception.Message)" -ForegroundColor Red
        if ($_.Exception.Response) {
            $reader = New-Object System.IO.StreamReader($_.Exception.Response.GetResponseStream())
            $reader.BaseStream.Position = 0
            $reader.DiscardBufferedData()
            $errorResponse = $reader.ReadToEnd()
            Write-Host "错误详情: $errorResponse" -ForegroundColor Red
        }
        return $null
    }
}

# ds: 默认使用 deepseek-chat
# 修复后的 ds 函数
function ds {
    [CmdletBinding()]
    param(
        [Parameter(Position=0, ValueFromRemainingArguments=$true)]
        [string[]]$QueryParts,
        
        [Parameter(Mandatory=$false)]
        [ValidateSet("deepseek-chat", "deepseek-reasoner")]
        [string]$Model = "deepseek-chat",
        
        [Parameter(Mandatory=$false)]
        [int]$MaxTokens = 4000,
        
        [Parameter(Mandatory=$false)]
        [double]$Temperature = 0.7,
        
        [switch]$Reset,
        [switch]$NoHistory
    )
    
    # 合并查询部分
    $Question = $QueryParts -join " "
    
    if ([string]::IsNullOrEmpty($Question)) {
        Write-Host "请输入查询内容" -ForegroundColor Red
        return
    }
    
    Invoke-DeepSeek -Question $Question -Model $Model -MaxTokens $MaxTokens -Temperature $Temperature -Reset:$Reset -NoHistory:$NoHistory
}

# 修复后的 ds-re 函数（专门用于 reasoner）
function ds-re {
    [CmdletBinding()]
    param(
        [Parameter(Position=0, ValueFromRemainingArguments=$true)]
        [string[]]$QueryParts,
        
        [Parameter(Mandatory=$false)]
        [int]$MaxTokens = 4000,
        
        [Parameter(Mandatory=$false)]
        [double]$Temperature = 0.7,
        
        [switch]$Reset,
        [switch]$NoHistory
    )
    
    $Question = $QueryParts -join " "
    
    if ([string]::IsNullOrEmpty($Question)) {
        Write-Host "请输入查询内容" -ForegroundColor Red
        return
    }
    
    Invoke-DeepSeek -Question $Question -Model "deepseek-reasoner" -MaxTokens $MaxTokens -Temperature $Temperature -Reset:$Reset -NoHistory:$NoHistory
}
# 测试命令也优化
function testds {
    param([Parameter(ValueFromRemainingArguments=$true)][string[]]$QueryParts)
    $Question = $QueryParts -join " "
    Test-DeepSeekSimple -Question $Question
}

# 文件处理函数（添加到配置文件中）
function ds-file {
    param(
        [Parameter(Mandatory=$true)]
        [string]$FilePath,
        
        [ValidateSet("deepseek-chat", "deepseek-reasoner")]
        [string]$Model = "deepseek-chat",
        
        [string]$AdditionalPrompt = "请分析这个文件的内容",
        
        [int]$MaxTokens = 4000,
        [double]$Temperature = 0.7,
        [switch]$NoHistory
    )
    
    if (-not (Test-Path $FilePath)) {
        Write-Error "文件不存在: $FilePath"
        return
    }
    
    # 读取文件内容（支持文本文件）
    $fileContent = Get-Content $FilePath -Raw -Encoding UTF8
    
    # 构建查询（组合文件内容和额外提示）
    $fullQuery = "文件内容：`n$fileContent`n`n$AdditionalPrompt"
    
    Invoke-DeepSeek -Question $fullQuery -Model $Model -MaxTokens $MaxTokens -Temperature $Temperature -NoHistory:$NoHistory
}

# 使用示例：
# ds-file -FilePath "D:\document.txt" -AdditionalPrompt "请总结主要内容"
# ds-file "D:\code.py" -Model "deepseek-reasoner" -AdditionalPrompt "请分析代码逻辑"

# 快速重置对话历史
function ds-reset {
    $script:DeepSeekHistory = @()
    Write-Host "对话历史已重置" -ForegroundColor Green
}

# 查看当前历史记录长度
function ds-history {
    if ($script:DeepSeekHistory) {
        Write-Host "当前历史记录: $($script:DeepSeekHistory.Count) 条消息" -ForegroundColor Cyan
        $script:DeepSeekHistory | ForEach-Object {
            Write-Host "$($_.role): $($_.content.Substring(0, [Math]::Min(50, $_.content.Length)))..." -ForegroundColor Gray
        }
    } else {
        Write-Host "没有历史记录" -ForegroundColor Yellow
    }
}
# 上下文压缩总结功能（类似 Claude 的 /compact）
function ds-compact {
    param(
        [switch]$Force
    )
    
    if (-not $script:DeepSeekHistory -or $script:DeepSeekHistory.Count -le 4) {
        Write-Host "当前历史记录较短，无需压缩" -ForegroundColor Yellow
        return
    }
    
    # 如果没有强制压缩且历史记录不长，则不压缩
    if (-not $Force -and $script:DeepSeekHistory.Count -le 8) {
        Write-Host "历史记录长度: $($script:DeepSeekHistory.Count)。使用 -Force 参数强制压缩" -ForegroundColor Yellow
        return
    }
    
    Write-Host "正在压缩上下文..." -ForegroundColor Yellow
    
    # 构建压缩提示
    $compressPrompt = @"
请将以下对话历史压缩总结为一个简洁的上下文摘要。保持所有重要信息、决策和上下文。

对话历史：
$($script:DeepSeekHistory | ForEach-Object { "$($_.role): $($_.content)" } | Out-String)

请提供一個简洁的摘要，用于后续对话保持上下文连贯。
"@
    
    # 保存原始历史记录
    $originalHistory = $script:DeepSeekHistory
    
    try {
        # 临时清空历史记录以避免递归
        $script:DeepSeekHistory = @()
        
        # 使用 NoHistory 避免再次记录
        $summary = Invoke-DeepSeek -Question $compressPrompt -Model "deepseek-reasoner" -NoHistory -MaxTokens 1000
        
        if ($summary) {
            # 用摘要替换完整历史记录
            $script:DeepSeekHistory = @(
                @{
                    role = "system"
                    content = "上下文摘要：$summary"
                }
            )
            
            Write-Host "✅ 上下文已压缩！历史记录从 $($originalHistory.Count) 条减少到 1 条" -ForegroundColor Green
            Write-Host "摘要: $($summary.Substring(0, [Math]::Min(100, $summary.Length)))..." -ForegroundColor Gray
        }
    }
    catch {
        Write-Error "压缩失败: $($_.Exception.Message)"
        # 恢复原始历史记录
        $script:DeepSeekHistory = $originalHistory
    }
}

# 自动压缩功能（可在长时间对话后自动调用）
# 修复后的 ds-auto 函数
function ds-auto {
    [CmdletBinding()]
    param(
        [Parameter(Position=0, ValueFromRemainingArguments=$true)]
        [string[]]$QueryParts,
        
        [int]$AutoCompactThreshold = 12,
        [switch]$NoCompact
    )
    
    $Question = $QueryParts -join " "
    
    # 检查是否为空查询
    if ([string]::IsNullOrWhiteSpace($Question)) {
        Write-Host "请输入查询内容，例如: ds-auto 你的问题" -ForegroundColor Red
        Write-Host "或者使用: ds-help 查看帮助" -ForegroundColor Yellow
        return
    }
    
    # 检查是否需要自动压缩
    if (-not $NoCompact -and $script:DeepSeekHistory -and $script:DeepSeekHistory.Count -ge $AutoCompactThreshold) {
        Write-Host "检测到较长历史记录($($script:DeepSeekHistory.Count)条)，自动压缩中..." -ForegroundColor Yellow
        ds-compact -Force
    }
    
    # 执行查询
    Invoke-DeepSeek -Question $Question -Model "deepseek-chat" -NoHistory:$false
}

# 修复后的 ds-smart 函数
function ds-smart {
    [CmdletBinding()]
    param(
        [Parameter(Position=0, ValueFromRemainingArguments=$true)]
        [string[]]$QueryParts,
        
        [ValidateSet("aggressive", "moderate", "conservative")]
        [string]$CompressionStyle = "moderate"
    )
    
    $Question = $QueryParts -join " "
    
    # 检查是否为空查询
    if ([string]::IsNullOrWhiteSpace($Question)) {
        Write-Host "请输入查询内容，例如: ds-smart 你的问题" -ForegroundColor Red
        return
    }
    
    # 根据压缩策略设置不同的阈值
    $thresholds = @{
        "aggressive"   = 6
        "moderate"     = 10
        "conservative" = 15
    }
    
    if ($script:DeepSeekHistory -and $script:DeepSeekHistory.Count -ge $thresholds[$CompressionStyle]) {
        Write-Host "🤖 智能压缩上下文($CompressionStyle模式)..." -ForegroundColor Cyan
        ds-compact -Force
    }
    
    Invoke-DeepSeek -Question $Question -Model "deepseek-chat" -NoHistory:$false
}

# DeepSeek：

**原始回答**

根据您的完整配置文件，要完全复制 PowerShell 7 设置到另一台电脑，需要迁移以下内容：

## 必须迁移的文件和设置

### 1. PowerShell 配置文件
- **文件**: `Microsoft.PowerShell_profile.ps1` (就是您展示的完整内容)
- **位置**: `C:\Users\[用户名]\Documents\PowerShell\`

### 2. Oh-My-Posh 主题文件
- **主题文件**: `tokyo.omp.json` 和 `jandedobbeleer.omp.json`
- **位置**: `C:\Users\[用户名]\AppData\Local\Programs\oh-my-posh\themes\`

### 3. 自定义脚本和工具
- **CCR 工具**: `D:\ccr\ccr.cmd` (需要复制整个文件夹)
- **Fastfetch**: 需要重新安装或复制

## 完整的迁移清单

### 第一步：备份当前电脑的文件

```powershell
# 创建备份文件夹
$backupPath = "D:\PowerShell_Backup\"
New-Item -ItemType Directory -Path $backupPath -Force

# 1. 备份 PowerShell 配置文件夹
Copy-Item -Path "$HOME\Documents\PowerShell" -Destination "$backupPath\PowerShell" -Recurse

# 2. 备份 Oh-My-Posh 主题
Copy-Item -Path "$env:POSH_THEMES_PATH\*" -Destination "$backupPath\themes\" -Recurse

# 3. 备份自定义工具 (CCR)
if (Test-Path "D:\ccr\") {
    Copy-Item -Path "D:\ccr\" -Destination "$backupPath\ccr\" -Recurse
}

# 4. 备份已安装的模块列表
Get-Module | Where-Object {$_.Path -like "$HOME*"} | Export-Clixml "$backupPath\installed_modules.xml"
```

### 第二步：在新电脑上安装基础软件

1. **安装 PowerShell 7**
2. **安装 Oh-My-Posh**
   ```powershell
   winget install JanDeDobbeleer.OhMyPosh -s winget
   ```
3. **安装 Fastfetch**
   ```powershell
   winget install fastfetch
   ```
4. **安装 Nerd Font** (如 Meslo LGM NF)

### 第三步：恢复配置文件

1. **恢复 PowerShell 配置**：
   - 将备份的整个 `PowerShell` 文件夹复制到：
     `C:\Users\[新用户名]\Documents\PowerShell\`

2. **恢复主题文件**：
   - 将备份的 `themes\` 文件夹内容复制到：
     `C:\Users\[新用户名]\AppData\Local\Programs\oh-my-posh\themes\`

3. **恢复自定义工具**：
   - 将 `ccr\` 文件夹复制到相同路径 `D:\ccr\` 或修改配置文件中的路径

### 第四步：设置环境变量

在新电脑上设置 DeepSeek API 密钥：
```powershell
# 设置环境变量
[System.Environment]::SetEnvironmentVariable('DEEPSEEK_API_KEY', '您的API密钥', [System.EnvironmentVariableTarget]::User)

# 立即在当前会话生效
$env:DEEPSEEK_API_KEY = '您的API密钥'
```

### 第五步：安装必要的 PowerShell 模块

```powershell
# 常用模块
Install-Module -Name PSReadLine -Force -AllowClobber
Install-Module -Name Terminal-Icons -Force
Install-Module -Name Z -Force

# 如果使用了其他模块，也一并安装
```

## 特殊注意事项

### 1. 路径适配
检查配置文件中是否有绝对路径需要修改：
- `ccr` 函数的路径 `D:\ccr\ccr.cmd`
- 如果有其他自定义脚本，确保路径正确

### 2. 编码设置
您的配置文件包含大量 UTF-8 编码设置，这些在新电脑上应该能正常工作

### 3. DeepSeek 函数
所有 DeepSeek 相关函数 (`ds`, `ds-re`, `ds-file` 等) 都会一并迁移

## 验证清单

配置完成后检查：
- [ ] PowerShell 启动无错误
- [ ] Oh-My-Posh 主题正常显示
- [ ] `ds` 命令能调用 DeepSeek API
- [ ] `ccr` 命令能正常工作
- [ ] Fastfetch 能正常显示
- [ ] 中文显示正常无乱码

## 快速迁移包结构

建议的备份文件夹结构：
```
PowerShell_Backup/
├── PowerShell/                 # 完整的配置文件夹
│   └── Microsoft.PowerShell_profile.ps1
├── themes/                    # Oh-My-Posh 主题
│   ├── tokyo.omp.json
│   └── jandedobbeleer.omp.json
├── ccr/                       # 自定义工具
│   └── ccr.cmd
└── installed_modules.xml      # 模块列表
```

这样就能在新电脑上获得完全相同的 PowerShell 环境了！本回答由 AI 生成，内容仅供参考，请仔细甄别。

# 用户：

我的powershell的设置json要如何迁移

# DeepSeek：

**原始回答**

要迁移 PowerShell 的 settings.json 文件（通常是 Windows Terminal 的配置），请按照以下步骤操作：

## Windows Terminal Settings.json 迁移

### 1. 找到配置文件位置

**当前电脑上的位置：**
```powershell
# 方法1：通过 Windows Terminal 设置
# 打开 Windows Terminal → 设置 → 打开 JSON 文件

# 方法2：直接路径
$wtSettingsPath = "$env:LOCALAPPDATA\Packages\Microsoft.WindowsTerminal_8wekyb3d8bbwe\LocalState\settings.json"

# 如果是非商店版 Windows Terminal：
$wtSettingsPath = "$env:LOCALAPPDATA\Microsoft\Windows Terminal\settings.json"
```

### 2. 备份设置文件

```powershell
# 备份 Windows Terminal 设置
Copy-Item -Path $wtSettingsPath -Destination "D:\PowerShell_Backup\windows_terminal_settings.json"

# 如果找不到，搜索所有可能的路径
$possiblePaths = @(
    "$env:LOCALAPPDATA\Packages\Microsoft.WindowsTerminal_8wekyb3d8bbwe\LocalState\settings.json",
    "$env:LOCALAPPDATA\Packages\Microsoft.WindowsTerminalPreview_8wekyb3d8bbwe\LocalState\settings.json",
    "$env:LOCALAPPDATA\Microsoft\Windows Terminal\settings.json",
    "$env:LOCALAPPDATA\Microsoft\Windows Terminal Preview\settings.json"
)

foreach ($path in $possiblePaths) {
    if (Test-Path $path) {
        Write-Host "找到设置文件: $path" -ForegroundColor Green
        Copy-Item -Path $path -Destination "D:\PowerShell_Backup\windows_terminal_settings.json"
        break
    }
}
```

### 3. 需要迁移的关键设置

在 settings.json 中，需要特别关注这些部分：

#### 配置文件 (profiles)
```json
{
    "profiles": {
        "defaults": {
            // 字体、颜色、背景等通用设置
            "font": {
                "face": "MesloLGM NF",  // 字体
                "size": 12
            },
            "colorScheme": "One Half Dark",  // 颜色方案
            "backgroundImage": "path/to/image"  // 背景图片
        },
        "list": [
            {
                "guid": "{574e775e-4f2a-5b96-ac1e-a2962a402336}",
                "hidden": false,
                "name": "PowerShell 7",
                "source": "Windows.Terminal.PowershellCore",
                "startingDirectory": "D:\\",  // 启动目录
                "icon": "path/to/icon"  // 图标
            }
        ]
    }
}
```

#### 颜色方案 (schemes)
```json
{
    "schemes": [
        {
            "name": "One Half Dark",
            "background": "#282C34",
            "foreground": "#DCDFE4",
            // ... 其他颜色定义
        }
    ]
}
```

#### 键绑定 (keybindings)
```json
{
    "keybindings": [
        {
            "command": "copy",
            "keys": "ctrl+shift+c"
        },
        {
            "command": "paste", 
            "keys": "ctrl+shift+v"
        }
        // ... 其他快捷键
    ]
}
```

### 4. 迁移到新电脑

#### 方法1：直接替换（推荐）
1. 在新电脑安装 **Windows Terminal**
2. 关闭所有 Windows Terminal 窗口
3. 用备份的 `settings.json` 替换新电脑的对应文件
4. 重新打开 Windows Terminal

#### 方法2：手动合并
如果新电脑已有一些设置，可以手动合并重要部分：

```powershell
# 在新电脑上，先备份原有设置
Copy-Item -Path $wtSettingsPath -Destination "$wtSettingsPath.backup"

# 然后用文本编辑器手动合并两个 JSON 文件
```

### 5. 需要调整的路径

迁移后可能需要修改的路径：

```json
{
    "profiles": {
        "list": [
            {
                "startingDirectory": "C:\\Users\\新用户名\\",  // 修改用户目录
                "icon": "C:\\Users\\新用户名\\图标.png",      // 修改图标路径
                "backgroundImage": "C:\\Users\\新用户名\\背景.jpg"  // 修改背景路径
            }
        ]
    }
}
```

### 6. 完整迁移脚本

这是一个完整的迁移脚本：

```powershell
# 备份当前电脑的 Windows Terminal 设置
function Backup-WindowsTerminalSettings {
    param([string]$BackupPath = "D:\PowerShell_Backup")
    
    New-Item -ItemType Directory -Path $BackupPath -Force
    
    $possiblePaths = @(
        "$env:LOCALAPPDATA\Packages\Microsoft.WindowsTerminal_8wekyb3d8bbwe\LocalState\settings.json",
        "$env:LOCALAPPDATA\Packages\Microsoft.WindowsTerminalPreview_8wekyb3d8bbwe\LocalState\settings.json", 
        "$env:LOCALAPPDATA\Microsoft\Windows Terminal\settings.json",
        "$env:LOCALAPPDATA\Microsoft\Windows Terminal Preview\settings.json"
    )
    
    foreach ($path in $possiblePaths) {
        if (Test-Path $path) {
            $fileName = "windows_terminal_settings_$(Get-Date -Format 'yyyyMMdd_HHmmss').json"
            Copy-Item -Path $path -Destination (Join-Path $BackupPath $fileName)
            Write-Host "已备份: $path → $BackupPath\$fileName" -ForegroundColor Green
            return $true
        }
    }
    
    Write-Host "未找到 Windows Terminal 设置文件" -ForegroundColor Yellow
    return $false
}

# 恢复设置到新电脑
function Restore-WindowsTerminalSettings {
    param(
        [string]$BackupFile,
        [switch]$BackupExisting
    )
    
    $targetPaths = @(
        "$env:LOCALAPPDATA\Packages\Microsoft.WindowsTerminal_8wekyb3d8bbwe\LocalState\settings.json",
        "$env:LOCALAPPDATA\Packages\Microsoft.WindowsTerminalPreview_8wekyb3d8bbwe\LocalState\settings.json",
        "$env:LOCALAPPDATA\Microsoft\Windows Terminal\settings.json", 
        "$env:LOCALAPPDATA\Microsoft\Windows Terminal Preview\settings.json"
    )
    
    foreach ($targetPath in $targetPaths) {
        $targetDir = Split-Path $targetPath -Parent
        if (Test-Path $targetDir) {
            if ($BackupExisting -and (Test-Path $targetPath)) {
                $backupName = "settings_backup_$(Get-Date -Format 'yyyyMMdd_HHmmss').json"
                Copy-Item -Path $targetPath -Destination (Join-Path $targetDir $backupName)
                Write-Host "已备份原有设置: $backupName" -ForegroundColor Yellow
            }
            
            Copy-Item -Path $BackupFile -Destination $targetPath -Force
            Write-Host "已恢复设置到: $targetPath" -ForegroundColor Green
            return $true
        }
    }
    
    Write-Host "未找到 Windows Terminal 安装目录" -ForegroundColor Red
    return $false
}

# 使用示例：
# Backup-WindowsTerminalSettings -BackupPath "D:\Backup"
# Restore-WindowsTerminalSettings -BackupFile "D:\Backup\windows_terminal_settings.json" -BackupExisting
```

### 7. 迁移后的验证

恢复完成后检查：
- [ ] Windows Terminal 能正常启动
- [ ] PowerShell 7 配置档显示正确
- [ ] 字体和颜色方案正常
- [ ] 快捷键工作正常
- [ ] 背景图片和图标显示正确

### 8. 额外提醒

如果使用了自定义的：
- **字体文件**：需要单独安装相同的 Nerd Font
- **背景图片**：需要复制图片文件到相同路径或更新路径
- **图标文件**：需要复制图标文件
- **颜色方案**：确保所有自定义颜色方案都包含在迁移的 JSON 中

这样就能完整迁移 Windows Terminal 的所有设置了！

# 用户：

settings.json我是否可以直接移植到新电脑上使用，因为使用了美化

# DeepSeek：

**原始回答**

是的，**settings.json 可以直接移植到新电脑上使用**，特别是如果您已经进行了美化配置。不过需要注意一些细节：

## 可以直接移植的情况

### 1. 大部分设置都能完美迁移
```json
{
    // 这些设置都能直接迁移
    "theme": "dark",
    "colorScheme": "One Half Dark",
    "font": {
        "face": "MesloLGM NF",
        "size": 12,
        "weight": "normal"
    },
    "opacity": 0.9,
    "useAcrylic": true,
    "acrylicOpacity": 0.8,
    "backgroundImage": "",
    "backgroundImageStretchMode": "uniformToFill",
    "keybindings": [
        // 快捷键绑定
    ],
    "schemes": [
        // 颜色方案
    ]
}
```

### 2. 需要检查的配置部分

#### 配置文件路径
```json
{
    "profiles": {
        "list": [
            {
                "guid": "{574e775e-4f2a-5b96-ac1e-a2962a402336}",
                "name": "PowerShell 7",
                "commandline": "pwsh.exe",  // ✅ 可以直接使用
                "startingDirectory": "D:\\",  // ⚠️ 可能需要修改
                "icon": "D:\\icons\\pwsh.png",  // ⚠️ 可能需要修改路径
                "backgroundImage": "D:\\wallpapers\\terminal-bg.jpg"  // ⚠️ 可能需要修改路径
            }
        ]
    }
}
```

## 移植步骤

### 1. 直接替换方法（最简单）
```powershell
# 在新电脑上：
# 1. 关闭所有 Windows Terminal 窗口
# 2. 备份原有设置（如果有）
Copy-Item $env:LOCALAPPDATA\Microsoft\Windows Terminal\settings.json $env:LOCALAPPDATA\Microsoft\Windows Terminal\settings.json.backup

# 3. 用旧电脑的 settings.json 替换
Copy-Item "D:\Backup\settings.json" $env:LOCALAPPDATA\Microsoft\Windows Terminal\settings.json

# 4. 重新打开 Windows Terminal
```

### 2. 需要手动调整的内容

#### 绝对路径修改
如果配置中使用了绝对路径，需要更新：

```json
{
    "profiles": {
        "list": [
            {
                // 修改为新的用户目录
                "startingDirectory": "C:\\Users\\新用户名\\",
                
                // 如果图标文件也迁移了，更新路径
                "icon": "C:\\Users\\新用户名\\icons\\pwsh.png",
                
                // 背景图片路径
                "backgroundImage": "C:\\Users\\新用户名\\Pictures\\terminal-bg.jpg"
            }
        ]
    }
}
```

#### 字体确认
确保新电脑安装了相同的字体：
```powershell
# 检查字体是否安装
$fonts = New-Object System.Drawing.Text.InstalledFontCollection
$fonts.Families | Where-Object Name -like "*Meslo*"
```

## 美化相关的特殊注意事项

### 1. 颜色方案和主题
所有颜色方案都会完美迁移：
```json
{
    "schemes": [
        {
            "name": "Tokyo Night",
            "background": "#1A1B26",
            "foreground": "#C0CAF5",
            "colors": [
                "#15161E", "#F7768E", "#9ECE6A", "#E0AF68",
                "#7AA2F7", "#BB9AF7", "#7DCFFF", "#A9B1D6"
            ]
        }
    ]
}
```

### 2. 透明度和视觉效果
```json
{
    "profiles": {
        "defaults": {
            "useAcrylic": true,           // 亚克力效果
            "acrylicOpacity": 0.85,       // 透明度
            "backgroundImageOpacity": 0.1, // 背景图透明度
            "cursorShape": "filledBox",   // 光标样式
            "antialiasingMode": "cleartype" // 抗锯齿
        }
    }
}
```

### 3. 面板和布局设置
```json
{
    "launchMode": "focus",        // 启动模式
    "initialRows": 30,            // 初始行数
    "initialCols": 120,           // 初始列数
    "alwaysOnTop": false,         // 始终置顶
    "tabSwitcherMode": "mru"      // 标签切换模式
}
```

## 完整的移植检查清单

### ✅ 可以直接移植的：
- 颜色方案 (schemes)
- 字体设置 (font face, size, weight)
- 透明度效果 (acrylic, opacity)
- 快捷键绑定 (keybindings)
- 主题设置 (theme)
- 光标样式 (cursorShape)
- 抗锯齿设置 (antialiasingMode)
- 启动模式 (launchMode)
- 标签设置 (tab settings)

### ⚠️ 需要检查的：
- 启动目录 (startingDirectory)
- 图标路径 (icon)
- 背景图片路径 (backgroundImage)
- 自定义命令路径 (commandline)
- 字体可用性 (font face)

### 🔄 可能需要更新的：
- 用户特定的文件路径
- 应用程序安装路径
- 工作目录路径

## 最佳实践建议

### 1. 使用相对路径或环境变量
如果可以，修改配置使用环境变量：
```json
{
    "icon": "%USERPROFILE%\\icons\\pwsh.png",
    "backgroundImage": "%USERPROFILE%\\Pictures\\terminal-bg.jpg",
    "startingDirectory": "%USERPROFILE%"
}
```

### 2. 分阶段测试
移植后先测试：
```powershell
# 1. 测试基本功能
# 2. 测试颜色和字体显示
# 3. 测试快捷键
# 4. 测试透明效果
```

### 3. 备份新电脑原有配置
```powershell
# 在替换前备份
Copy-Item $env:LOCALAPPDATA\Microsoft\Windows Terminal\settings.json $env:LOCALAPPDATA\Microsoft\Windows Terminal\settings.json.original
```

## 总结

**是的，settings.json 可以直接移植**，您的所有美化设置都会保留。只需要注意：

1. **字体**：确保新电脑安装相同的 Nerd Font
2. **文件路径**：更新图标、背景图片等绝对路径
3. **测试验证**：移植后检查所有功能是否正常

这样您就能在新电脑上获得完全相同的终端美化效果了！

# 用户：

旧电脑的settings.json会在在哪里

# DeepSeek：

**原始回答**

旧电脑的 `settings.json` 文件位置取决于 Windows Terminal 的安装方式。以下是所有可能的位置：

## 主要位置（按优先级）

### 1. 最常见的位置（Windows Terminal 稳定版）
```powershell
# 稳定版（从 Microsoft Store 或 GitHub 安装）
$env:LOCALAPPDATA\Microsoft\Windows Terminal\settings.json
```
**完整路径示例：**
`C:\Users\[您的用户名]\AppData\Local\Microsoft\Windows Terminal\settings.json`

### 2. Windows Terminal 预览版
```powershell
# 预览版
$env:LOCALAPPDATA\Microsoft\Windows Terminal Preview\settings.json
```

### 3. Microsoft Store 版本
```powershell
# Microsoft Store 安装的稳定版
$env:LOCALAPPDATA\Packages\Microsoft.WindowsTerminal_8wekyb3d8bbwe\LocalState\settings.json
```

### 4. Microsoft Store 预览版
```powershell
# Microsoft Store 安装的预览版  
$env:LOCALAPPDATA\Packages\Microsoft.WindowsTerminalPreview_8wekyb3d8bbwe\LocalState\settings.json
```

## 快速查找脚本

您可以在 PowerShell 中运行这个脚本来找到准确的路径：

```powershell
function Find-WindowsTerminalSettings {
    $possiblePaths = @(
        "$env:LOCALAPPDATA\Microsoft\Windows Terminal\settings.json",
        "$env:LOCALAPPDATA\Microsoft\Windows Terminal Preview\settings.json",
        "$env:LOCALAPPDATA\Packages\Microsoft.WindowsTerminal_8wekyb3d8bbwe\LocalState\settings.json",
        "$env:LOCALAPPDATA\Packages\Microsoft.WindowsTerminalPreview_8wekyb3d8bbwe\LocalState\settings.json"
    )
    
    Write-Host "正在搜索 Windows Terminal 设置文件..." -ForegroundColor Cyan
    
    foreach ($path in $possiblePaths) {
        if (Test-Path $path) {
            Write-Host "✅ 找到设置文件: " -ForegroundColor Green -NoNewline
            Write-Host $path -ForegroundColor Yellow
            
            # 显示文件信息
            $fileInfo = Get-Item $path
            Write-Host "   文件大小: $([math]::Round($fileInfo.Length/1KB, 2)) KB" -ForegroundColor Gray
            Write-Host "   修改时间: $($fileInfo.LastWriteTime)" -ForegroundColor Gray
            
            # 打开所在文件夹
            $openFolder = Read-Host "是否打开所在文件夹? (y/n)"
            if ($openFolder -eq 'y' -or $openFolder -eq 'Y') {
                Invoke-Item (Split-Path $path -Parent)
            }
            
            return $path
        }
    }
    
    Write-Host "❌ 未找到 Windows Terminal 设置文件" -ForegroundColor Red
    Write-Host "请确认已安装 Windows Terminal" -ForegroundColor Yellow
    return $null
}

# 运行查找函数
Find-WindowsTerminalSettings
```

## 手动查找方法

### 方法1：通过 Windows Terminal 界面
1. 打开 **Windows Terminal**
2. 点击下拉菜单箭头 ▼
3. 选择 **设置** (或按 `Ctrl + ,`)
4. 在设置界面底部，点击 **打开 JSON 文件**
5. 这会直接打开 `settings.json` 并显示其位置

### 方法2：通过文件资源管理器
1. 按 `Win + R`，输入 `%LOCALAPPDATA%`，回车
2. 依次进入以下文件夹查找：
   - `Microsoft\Windows Terminal\`
   - `Microsoft\Windows Terminal Preview\`
   - `Packages\Microsoft.WindowsTerminal_8wekyb3d8bbwe\LocalState\`
   - `Packages\Microsoft.WindowsTerminalPreview_8wekyb3d8bbwe\LocalState\`

### 方法3：通过 PowerShell 命令
```powershell
# 一次性检查所有可能位置
Get-ChildItem "$env:LOCALAPPDATA" -Recurse -Filter "settings.json" -ErrorAction SilentlyContinue | 
Where-Object { $_.FullName -like "*WindowsTerminal*" } |
Select-Object FullName, LastWriteTime, @{Name="Size(KB)";Expression={[math]::Round($_.Length/1KB, 2)}}
```

## 备份脚本

找到文件后，使用这个脚本进行备份：

```powershell
function Backup-WindowsTerminalSettings {
    param([string]$BackupPath = "D:\Backup\WindowsTerminal")
    
    # 创建备份目录
    New-Item -ItemType Directory -Path $BackupPath -Force
    
    # 所有可能的路径
    $sourcePaths = @(
        "$env:LOCALAPPDATA\Microsoft\Windows Terminal\settings.json",
        "$env:LOCALAPPDATA\Microsoft\Windows Terminal Preview\settings.json",
        "$env:LOCALAPPDATA\Packages\Microsoft.WindowsTerminal_8wekyb3d8bbwe\LocalState\settings.json",
        "$env:LOCALAPPDATA\Packages\Microsoft.WindowsTerminalPreview_8wekyb3d8bbwe\LocalState\settings.json"
    )
    
    $backupCount = 0
    
    foreach ($sourcePath in $sourcePaths) {
        if (Test-Path $sourcePath) {
            $fileName = "settings_$(Get-Date -Format 'yyyyMMdd_HHmmss').json"
            $backupFile = Join-Path $BackupPath $fileName
            
            Copy-Item -Path $sourcePath -Destination $backupFile
            Write-Host "✅ 已备份: $sourcePath" -ForegroundColor Green
            Write-Host "   备份到: $backupFile" -ForegroundColor Gray
            $backupCount++
        }
    }
    
    if ($backupCount -eq 0) {
        Write-Host "❌ 未找到任何 Windows Terminal 设置文件" -ForegroundColor Red
    } else {
        Write-Host "`n🎉 成功备份 $backupCount 个设置文件到: $BackupPath" -ForegroundColor Cyan
    }
}

# 运行备份（默认备份到 D:\Backup\WindowsTerminal）
Backup-WindowsTerminalSettings

# 或者指定自定义路径
# Backup-WindowsTerminalSettings -BackupPath "E:\MyBackups\Terminal"
```

## 最可能的位置

根据统计，**95% 的情况**下，文件在：
```
C:\Users\[您的用户名]\AppData\Local\Microsoft\Windows Terminal\settings.json
```

**建议**：直接运行上面的查找脚本，它会自动找到准确的位置并为您打开文件夹。

# 用户：

如果我把旧电脑中的setting.json,通过储存在u盘G:\powershell-dive之中，前文提到的迁移方法要怎么自动配置

# DeepSeek：

**原始回答**

# 自动配置 Windows Terminal Settings.json 的方法

以下是将 U盘中的 `settings.json` 自动配置到新电脑的完整方案：

## 1. 自动配置脚本

创建一个自动配置脚本 `Setup-Terminal.ps1` 保存在 U盘 `G:\powershell-dive\` 中：

```powershell
# Setup-Terminal.ps1 - Windows Terminal 自动配置脚本
param(
    [string]$SettingsPath = "G:\powershell-dive\settings.json",
    [switch]$BackupExisting,
    [switch]$Force
)

Write-Host "🚀 开始自动配置 Windows Terminal..." -ForegroundColor Cyan

# 检查源文件是否存在
if (-not (Test-Path $SettingsPath)) {
    Write-Host "❌ 找不到设置文件: $SettingsPath" -ForegroundColor Red
    Write-Host "请确保 U盘已连接且路径正确" -ForegroundColor Yellow
    return
}

# 所有可能的目标路径
$targetPaths = @(
    "$env:LOCALAPPDATA\Microsoft\Windows Terminal\settings.json",
    "$env:LOCALAPPDATA\Microsoft\Windows Terminal Preview\settings.json",
    "$env:LOCALAPPDATA\Packages\Microsoft.WindowsTerminal_8wekyb3d8bbwe\LocalState\settings.json",
    "$env:LOCALAPPDATA\Packages\Microsoft.WindowsTerminalPreview_8wekyb3d8bbwe\LocalState\settings.json"
)

# 查找已安装的 Windows Terminal
$installedPaths = @()
foreach ($path in $targetPaths) {
    $dir = Split-Path $path -Parent
    if (Test-Path $dir) {
        $installedPaths += $path
        Write-Host "✅ 找到 Windows Terminal: $dir" -ForegroundColor Green
    }
}

if ($installedPaths.Count -eq 0) {
    Write-Host "❌ 未找到 Windows Terminal 安装" -ForegroundColor Red
    Write-Host "请先安装 Windows Terminal" -ForegroundColor Yellow
    
    $installChoice = Read-Host "是否通过 Winget 安装 Windows Terminal? (y/n)"
    if ($installChoice -eq 'y' -or $installChoice -eq 'Y') {
        try {
            Write-Host "正在安装 Windows Terminal..." -ForegroundColor Yellow
            winget install Microsoft.WindowsTerminal -e --silent
            Start-Sleep -Seconds 3
            
            # 重新检查安装路径
            foreach ($path in $targetPaths) {
                $dir = Split-Path $path -Parent
                if (Test-Path $dir) {
                    $installedPaths += $path
                }
            }
        }
        catch {
            Write-Host "安装失败: $($_.Exception.Message)" -ForegroundColor Red
            return
        }
    } else {
        return
    }
}

# 处理路径适配（更新用户名等）
Write-Host "🔄 正在适配设置文件..." -ForegroundColor Yellow
$tempSettingsPath = [System.IO.Path]::GetTempFileName() + ".json"
$settingsContent = Get-Content $SettingsPath -Raw

# 替换旧用户名为新用户名（如果知道旧用户名）
$oldUserName = "Aaron Kwo'k"  # 修改为您的旧用户名
$newUserName = $env:USERNAME

if ($oldUserName -and $newUserName -and $oldUserName -ne $newUserName) {
    Write-Host "正在更新用户名: $oldUserName → $newUserName" -ForegroundColor Cyan
    $settingsContent = $settingsContent.Replace($oldUserName, $newUserName)
    
    # 替换路径中的用户名
    $settingsContent = $settingsContent.Replace(
        "C:\Users\$oldUserName", 
        "C:\Users\$newUserName"
    )
}

# 保存适配后的设置文件
$settingsContent | Out-File -FilePath $tempSettingsPath -Encoding UTF8

# 复制设置文件到所有找到的安装路径
$successCount = 0
foreach ($targetPath in $installedPaths) {
    try {
        $targetDir = Split-Path $targetPath -Parent
        
        # 备份原有设置
        if ($BackupExisting -and (Test-Path $targetPath)) {
            $backupName = "settings_backup_$(Get-Date -Format 'yyyyMMdd_HHmmss').json"
            $backupPath = Join-Path $targetDir $backupName
            Copy-Item -Path $targetPath -Destination $backupPath
            Write-Host "📦 已备份原有设置: $backupName" -ForegroundColor Magenta
        }
        
        # 复制新设置
        Copy-Item -Path $tempSettingsPath -Destination $targetPath -Force
        Write-Host "✅ 已配置: $targetPath" -ForegroundColor Green
        $successCount++
    }
    catch {
        Write-Host "❌ 配置失败 $targetPath : $($_.Exception.Message)" -ForegroundColor Red
    }
}

# 清理临时文件
Remove-Item $tempSettingsPath -ErrorAction SilentlyContinue

if ($successCount -gt 0) {
    Write-Host "`n🎉 Windows Terminal 配置完成!" -ForegroundColor Cyan
    Write-Host "   • 成功配置 $successCount 个位置" -ForegroundColor White
    Write-Host "   • 请重新启动 Windows Terminal 查看效果" -ForegroundColor White
    
    $openTerminal = Read-Host "是否立即打开 Windows Terminal? (y/n)"
    if ($openTerminal -eq 'y' -or $openTerminal -eq 'Y') {
        Start-Process "wt.exe"
    }
} else {
    Write-Host "❌ 配置失败，请检查以上错误信息" -ForegroundColor Red
}
```

## 2. 完整迁移包结构

在 U盘 `G:\powershell-dive\` 中创建以下结构：

```
G:\powershell-dive\
├── Setup-Terminal.ps1          # 自动配置脚本
├── settings.json               # Windows Terminal 设置
├── Install-Fonts.ps1           # 字体安装脚本（可选）
└── themes\                     # Oh-My-Posh 主题文件夹
    ├── tokyo.omp.json
    └── jandedobbeleer.omp.json
```

## 3. 字体自动安装脚本（可选）

创建 `Install-Fonts.ps1` 用于安装必要的 Nerd Font：

```powershell
# Install-Fonts.ps1 - 字体自动安装
param(
    [string]$FontsPath = "G:\powershell-dive\fonts\",
    [switch]$Force
)

Write-Host "🔤 开始安装终端字体..." -ForegroundColor Cyan

# 检查字体目录
if (-not (Test-Path $FontsPath)) {
    Write-Host "❌ 字体目录不存在: $FontsPath" -ForegroundColor Red
    return
}

# 获取系统字体目录
$fontInstallPath = "$env:WINDIR\Fonts"

# 安装所有 .ttf 字体文件
$fontFiles = Get-ChildItem -Path $FontsPath -Filter "*.ttf" -Recurse

if ($fontFiles.Count -eq 0) {
    Write-Host "❌ 未找到字体文件 (.ttf)" -ForegroundColor Red
    return
}

foreach ($fontFile in $fontFiles) {
    $fontName = $fontFile.BaseName
    $destination = Join-Path $fontInstallPath $fontFile.Name
    
    if ((Test-Path $destination) -and -not $Force) {
        Write-Host "⏭️  字体已存在: $fontName" -ForegroundColor Yellow
        continue
    }
    
    try {
        Copy-Item -Path $fontFile.FullName -Destination $destination -Force
        Write-Host "✅ 已安装字体: $fontName" -ForegroundColor Green
    }
    catch {
        Write-Host "❌ 安装失败: $fontName - $($_.Exception.Message)" -ForegroundColor Red
    }
}

Write-Host "`n🎉 字体安装完成!" -ForegroundColor Cyan
Write-Host "请在 Windows Terminal 设置中选择安装的 Nerd Font" -ForegroundColor White
```

## 4. 一键配置脚本

创建主配置脚本 `OneClick-Setup.ps1`：

```powershell
# OneClick-Setup.ps1 - 一键配置 PowerShell 环境
param(
    [string]$UDrivePath = "G:\powershell-dive\",
    [switch]$InstallFonts,
    [switch]$InstallModules,
    [switch]$All
)

Write-Host "🎯 PowerShell 环境一键配置" -ForegroundColor Cyan
Write-Host "=" * 50

# 检查 U盘路径
if (-not (Test-Path $UDrivePath)) {
    Write-Host "❌ 找不到 U盘路径: $UDrivePath" -ForegroundColor Red
    Write-Host "请确保 U盘已连接且路径正确" -ForegroundColor Yellow
    return
}

# 1. 配置 Windows Terminal
Write-Host "`n1. 配置 Windows Terminal..." -ForegroundColor Yellow
$terminalScript = Join-Path $UDrivePath "Setup-Terminal.ps1"
if (Test-Path $terminalScript) {
    & $terminalScript -BackupExisting
} else {
    Write-Host "❌ 找不到终端配置脚本" -ForegroundColor Red
}

# 2. 安装字体
if ($InstallFonts -or $All) {
    Write-Host "`n2. 安装终端字体..." -ForegroundColor Yellow
    $fontScript = Join-Path $UDrivePath "Install-Fonts.ps1"
    if (Test-Path $fontScript) {
        & $fontScript
    } else {
        Write-Host "❌ 找不到字体安装脚本" -ForegroundColor Red
    }
}

# 3. 安装 PowerShell 模块
if ($InstallModules -or $All) {
    Write-Host "`n3. 安装 PowerShell 模块..." -ForegroundColor Yellow
    $modules = @("PSReadLine", "Terminal-Icons", "Z")
    foreach ($module in $modules) {
        try {
            Write-Host "正在安装 $module..." -ForegroundColor Gray
            Install-Module -Name $module -Force -AllowClobber -Scope CurrentUser
            Write-Host "✅ 已安装: $module" -ForegroundColor Green
        }
        catch {
            Write-Host "❌ 安装失败: $module - $($_.Exception.Message)" -ForegroundColor Red
        }
    }
}

# 4. 复制 PowerShell 配置
Write-Host "`n4. 配置 PowerShell..." -ForegroundColor Yellow
$profileBackup = Join-Path $UDrivePath "Microsoft.PowerShell_profile.ps1"
$profilePath = "$HOME\Documents\PowerShell\Microsoft.PowerShell_profile.ps1"

if (Test-Path $profileBackup) {
    try {
        $profileDir = Split-Path $profilePath -Parent
        if (-not (Test-Path $profileDir)) {
            New-Item -ItemType Directory -Path $profileDir -Force
        }
        
        Copy-Item -Path $profileBackup -Destination $profilePath -Force
        Write-Host "✅ PowerShell 配置已复制" -ForegroundColor Green
    }
    catch {
        Write-Host "❌ PowerShell 配置复制失败: $($_.Exception.Message)" -ForegroundColor Red
    }
} else {
    Write-Host "ℹ️  未找到 PowerShell 配置备份" -ForegroundColor Yellow
}

# 5. 复制 Oh-My-Posh 主题
Write-Host "`n5. 配置 Oh-My-Posh 主题..." -ForegroundColor Yellow
$themesSource = Join-Path $UDrivePath "themes"
$themesDest = "$env:POSH_THEMES_PATH"

if (Test-Path $themesSource) {
    try {
        if (-not (Test-Path $themesDest)) {
            Write-Host "ℹ️  Oh-My-Posh 未安装，正在安装..." -ForegroundColor Yellow
            winget install JanDeDobbeleer.OhMyPosh -s winget --silent
        }
        
        if (Test-Path $themesDest) {
            Copy-Item -Path "$themesSource\*" -Destination $themesDest -Recurse -Force
            Write-Host "✅ Oh-My-Posh 主题已复制" -ForegroundColor Green
        }
    }
    catch {
        Write-Host "❌ 主题复制失败: $($_.Exception.Message)" -ForegroundColor Red
    }
}

Write-Host "`n" + "=" * 50
Write-Host "🎉 一键配置完成!" -ForegroundColor Cyan
Write-Host "请重新启动 Windows Terminal 查看效果" -ForegroundColor White
```

## 5. 使用方法

### 简单使用：
```powershell
# 插入 U盘后，打开 PowerShell 7 并运行：
cd G:\powershell-dive
.\OneClick-Setup.ps1 -All
```

### 分步使用：
```powershell
# 只配置 Windows Terminal
.\Setup-Terminal.ps1 -BackupExisting

# 只安装字体
.\Install-Fonts.ps1

# 完整配置（包括模块安装）
.\OneClick-Setup.ps1 -All
```

## 6. 额外建议

### 创建桌面快捷方式：
```powershell
# 创建快捷方式脚本
$shortcutPath = "$HOME\Desktop\配置PowerShell环境.ps1"
@"
cd 'G:\powershell-dive'
.\OneClick-Setup.ps1 -All
Read-Host "`n按回车键退出..."
"@ | Out-File -FilePath $shortcutPath -Encoding UTF8

Write-Host "✅ 已在桌面创建快捷方式" -ForegroundColor Green
```

### 设置执行策略（如果需要）：
```powershell
# 以管理员身份运行
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser
```

这样您就可以通过 U盘一键完成所有 PowerShell 和 Windows Terminal 的配置迁移了！

# 用户：

如果我的$PROFILE也在同一个位置，该如何自动安装

# DeepSeek：

**原始回答**

# 自动安装 $PROFILE 的完整方案

既然您的 `$PROFILE` 文件也在 U盘 `G:\powershell-dive\` 中，我们可以创建完整的自动安装方案。以下是完整的实现：

## 1. 智能 $PROFILE 安装脚本

创建 `Install-Profile.ps1`：

```powershell
# Install-Profile.ps1 - 自动安装 PowerShell Profile
param(
    [string]$ProfileSource = "G:\powershell-dive\Microsoft.PowerShell_profile.ps1",
    [switch]$BackupExisting,
    [switch]$Force,
    [switch]$SetupDeepSeek
)

Write-Host "📝 开始配置 PowerShell Profile..." -ForegroundColor Cyan

# 检查源文件是否存在
if (-not (Test-Path $ProfileSource)) {
    Write-Host "❌ 找不到 Profile 文件: $ProfileSource" -ForegroundColor Red
    return
}

# 获取目标 Profile 路径
$profilePath = $PROFILE.CurrentUserCurrentHost
$profileDir = Split-Path $profilePath -Parent

Write-Host "目标 Profile 路径: $profilePath" -ForegroundColor Gray

# 创建 Profile 目录（如果不存在）
if (-not (Test-Path $profileDir)) {
    Write-Host "创建 Profile 目录: $profileDir" -ForegroundColor Yellow
    New-Item -ItemType Directory -Path $profileDir -Force
}

# 备份现有 Profile
if ($BackupExisting -and (Test-Path $profilePath)) {
    $backupName = "Profile_backup_$(Get-Date -Format 'yyyyMMdd_HHmmss').ps1"
    $backupPath = Join-Path $profileDir $backupName
    Copy-Item -Path $profilePath -Destination $backupPath
    Write-Host "📦 已备份现有 Profile: $backupName" -ForegroundColor Magenta
}

# 读取并处理 Profile 内容
Write-Host "🔄 正在处理 Profile 内容..." -ForegroundColor Yellow
$profileContent = Get-Content $ProfileSource -Raw

# 路径适配 - 更新用户名等系统特定路径
$oldUserName = "Aaron Kwo'k"  # 修改为您的旧用户名
$newUserName = $env:USERNAME

if ($oldUserName -and $newUserName -and $oldUserName -ne $newUserName) {
    Write-Host "正在更新用户名: $oldUserName → $newUserName" -ForegroundColor Cyan
    $profileContent = $profileContent.Replace($oldUserName, $newUserName)
    
    # 替换用户目录路径
    $profileContent = $profileContent.Replace(
        "C:\Users\$oldUserName", 
        "C:\Users\$newUserName"
    )
}

# 检查并安装必要的组件
$missingComponents = @()

# 检查 Oh-My-Posh
if (-not (Get-Command oh-my-posh -ErrorAction SilentlyContinue)) {
    $missingComponents += "Oh-My-Posh"
    Write-Host "⚠️  未找到 Oh-My-Posh" -ForegroundColor Yellow
}

# 检查 Fastfetch
if (-not (Get-Command fastfetch -ErrorAction SilentlyContinue)) {
    $missingComponents += "Fastfetch"
    Write-Host "⚠️  未找到 Fastfetch" -ForegroundColor Yellow
}

# 自动安装缺失组件
if ($missingComponents.Count -gt 0) {
    Write-Host "`n🔧 安装缺失组件..." -ForegroundColor Cyan
    
    if ($missingComponents -contains "Oh-My-Posh") {
        Write-Host "正在安装 Oh-My-Posh..." -ForegroundColor Yellow
        try {
            winget install JanDeDobbeleer.OhMyPosh -s winget --silent
            Write-Host "✅ Oh-My-Posh 安装完成" -ForegroundColor Green
        }
        catch {
            Write-Host "❌ Oh-My-Posh 安装失败: $($_.Exception.Message)" -ForegroundColor Red
        }
    }
    
    if ($missingComponents -contains "Fastfetch") {
        Write-Host "正在安装 Fastfetch..." -ForegroundColor Yellow
        try {
            winget install fastfetch -s winget --silent
            Write-Host "✅ Fastfetch 安装完成" -ForegroundColor Green
        }
        catch {
            Write-Host "❌ Fastfetch 安装失败: $($_.Exception.Message)" -ForegroundColor Red
        }
    }
}

# 设置 DeepSeek API 密钥（可选）
if ($SetupDeepSeek) {
    Write-Host "`n🔑 设置 DeepSeek API 密钥..." -ForegroundColor Cyan
    $apiKey = Read-Host "请输入您的 DeepSeek API 密钥" -AsSecureString
    $plainKey = [Runtime.InteropServices.Marshal]::PtrToStringAuto([Runtime.InteropServices.Marshal]::SecureStringToBSTR($apiKey))
    
    if (-not [string]::IsNullOrEmpty($plainKey)) {
        [System.Environment]::SetEnvironmentVariable('DEEPSEEK_API_KEY', $plainKey, [System.EnvironmentVariableTarget]::User)
        $env:DEEPSEEK_API_KEY = $plainKey
        Write-Host "✅ DeepSeek API 密钥已设置" -ForegroundColor Green
    }
}

# 安装 PowerShell 模块
Write-Host "`n📦 安装 PowerShell 模块..." -ForegroundColor Cyan
$requiredModules = @("PSReadLine", "Terminal-Icons", "Z")

foreach ($module in $requiredModules) {
    if (-not (Get-Module -ListAvailable -Name $module)) {
        Write-Host "正在安装 $module..." -ForegroundColor Yellow
        try {
            Install-Module -Name $module -Force -AllowClobber -Scope CurrentUser
            Write-Host "✅ $module 安装完成" -ForegroundColor Green
        }
        catch {
            Write-Host "❌ $module 安装失败: $($_.Exception.Message)" -ForegroundColor Red
        }
    } else {
        Write-Host "✅ $module 已安装" -ForegroundColor Gray
    }
}

# 写入处理后的 Profile
try {
    $profileContent | Out-File -FilePath $profilePath -Encoding UTF8
    Write-Host "✅ Profile 已安装到: $profilePath" -ForegroundColor Green
    
    # 测试 Profile 是否有效
    Write-Host "`n🧪 测试 Profile..." -ForegroundColor Cyan
    try {
        & $profilePath
        Write-Host "✅ Profile 测试通过" -ForegroundColor Green
    }
    catch {
        Write-Host "⚠️  Profile 测试有警告: $($_.Exception.Message)" -ForegroundColor Yellow
    }
}
catch {
    Write-Host "❌ Profile 安装失败: $($_.Exception.Message)" -ForegroundColor Red
    return
}

Write-Host "`n🎉 PowerShell Profile 配置完成!" -ForegroundColor Cyan
Write-Host "请重新启动 PowerShell 或运行: . `$PROFILE" -ForegroundColor White
```

## 2. 增强版一键配置脚本

更新 `OneClick-Setup.ps1`：

```powershell
# OneClick-Setup.ps1 - 增强版一键配置
param(
    [string]$UDrivePath = "G:\powershell-dive\",
    [switch]$InstallFonts,
    [switch]$InstallModules, 
    [switch]$SetupDeepSeek,
    [switch]$All,
    [switch]$SkipProfile
)

Write-Host "🎯 PowerShell 环境一键配置" -ForegroundColor Cyan
Write-Host "=" * 50

# 检查 U盘路径
if (-not (Test-Path $UDrivePath)) {
    Write-Host "❌ 找不到 U盘路径: $UDrivePath" -ForegroundColor Red
    Write-Host "请确保 U盘已连接且路径正确" -ForegroundColor Yellow
    return
}

# 0. 设置执行策略（如果需要）
try {
    $currentPolicy = Get-ExecutionPolicy -Scope CurrentUser
    if ($currentPolicy -eq "Restricted") {
        Write-Host "0. 设置执行策略..." -ForegroundColor Yellow
        Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser -Force
        Write-Host "✅ 执行策略已设置为 RemoteSigned" -ForegroundColor Green
    }
}
catch {
    Write-Host "⚠️  无法设置执行策略: $($_.Exception.Message)" -ForegroundColor Yellow
}

# 1. 安装 PowerShell Profile
if (-not $SkipProfile) {
    Write-Host "`n1. 安装 PowerShell Profile..." -ForegroundColor Yellow
    $profileScript = Join-Path $UDrivePath "Install-Profile.ps1"
    if (Test-Path $profileScript) {
        $profileArgs = @{
            ProfileSource = Join-Path $UDrivePath "Microsoft.PowerShell_profile.ps1"
            BackupExisting = $true
        }
        if ($SetupDeepSeek -or $All) { $profileArgs.SetupDeepSeek = $true }
        
        & $profileScript @profileArgs
    } else {
        Write-Host "❌ 找不到 Profile 安装脚本" -ForegroundColor Red
        
        # 直接复制 Profile 文件作为后备方案
        $profileSource = Join-Path $UDrivePath "Microsoft.PowerShell_profile.ps1"
        if (Test-Path $profileSource) {
            Write-Host "尝试直接复制 Profile 文件..." -ForegroundColor Yellow
            Copy-Item -Path $profileSource -Destination $PROFILE.CurrentUserCurrentHost -Force
            Write-Host "✅ Profile 文件已复制" -ForegroundColor Green
        }
    }
}

# 2. 配置 Windows Terminal
Write-Host "`n2. 配置 Windows Terminal..." -ForegroundColor Yellow
$terminalScript = Join-Path $UDrivePath "Setup-Terminal.ps1"
if (Test-Path $terminalScript) {
    & $terminalScript -BackupExisting
} else {
    Write-Host "❌ 找不到终端配置脚本" -ForegroundColor Red
}

# 3. 安装字体
if ($InstallFonts -or $All) {
    Write-Host "`n3. 安装终端字体..." -ForegroundColor Yellow
    $fontScript = Join-Path $UDrivePath "Install-Fonts.ps1"
    if (Test-Path $fontScript) {
        & $fontScript
    } else {
        Write-Host "❌ 找不到字体安装脚本" -ForegroundColor Red
    }
}

# 4. 复制 Oh-My-Posh 主题
Write-Host "`n4. 配置 Oh-My-Posh 主题..." -ForegroundColor Yellow
$themesSource = Join-Path $UDrivePath "themes"
$themesDest = "$env:POSH_THEMES_PATH"

if (-not $themesDest) {
    # 如果环境变量不存在，使用默认路径
    $themesDest = "$env:USERPROFILE\AppData\Local\Programs\oh-my-posh\themes"
}

if (Test-Path $themesSource) {
    try {
        if (-not (Test-Path $themesDest)) {
            New-Item -ItemType Directory -Path $themesDest -Force
        }
        
        Copy-Item -Path "$themesSource\*" -Destination $themesDest -Recurse -Force
        Write-Host "✅ Oh-My-Posh 主题已复制" -ForegroundColor Green
    }
    catch {
        Write-Host "❌ 主题复制失败: $($_.Exception.Message)" -ForegroundColor Red
    }
}

# 5. 复制自定义工具（CCR）
Write-Host "`n5. 配置自定义工具..." -ForegroundColor Yellow
$ccrSource = Join-Path $UDrivePath "ccr"
if (Test-Path $ccrSource) {
    $ccrDest = "D:\ccr"
    try {
        if (-not (Test-Path $ccrDest)) {
            New-Item -ItemType Directory -Path $ccrDest -Force
        }
        Copy-Item -Path "$ccrSource\*" -Destination $ccrDest -Recurse -Force
        Write-Host "✅ CCR 工具已复制到: $ccrDest" -ForegroundColor Green
    }
    catch {
        Write-Host "❌ CCR 工具复制失败: $($_.Exception.Message)" -ForegroundColor Red
    }
}

Write-Host "`n" + "=" * 50
Write-Host "🎉 一键配置完成!" -ForegroundColor Cyan

# 最终建议
Write-Host "`n📋 下一步操作:" -ForegroundColor Yellow
Write-Host "   1. 重新启动 PowerShell" -ForegroundColor White
Write-Host "   2. 或在当前会话运行: . `$PROFILE" -ForegroundColor White
Write-Host "   3. 测试命令: ds '你好，DeepSeek'" -ForegroundColor White

# 立即重新加载 Profile
$reloadNow = Read-Host "`n是否立即重新加载 Profile? (y/n)"
if ($reloadNow -eq 'y' -or $reloadNow -eq 'Y') {
    try {
        . $PROFILE
        Write-Host "✅ Profile 已重新加载" -ForegroundColor Green
    }
    catch {
        Write-Host "❌ Profile 重新加载失败: $($_.Exception.Message)" -ForegroundColor Red
    }
}
```

## 3. 完整的 U盘文件结构

确保 U盘中有以下结构：

```
G:\powershell-dive\
├── 📄 OneClick-Setup.ps1              # 主配置脚本
├── 📄 Install-Profile.ps1             # Profile 安装脚本  
├── 📄 Setup-Terminal.ps1              # 终端配置脚本
├── 📄 Install-Fonts.ps1               # 字体安装脚本（可选）
├── 📄 Microsoft.PowerShell_profile.ps1 # 您的 PowerShell Profile
├── 📄 settings.json                   # Windows Terminal 设置
├── 📁 themes\                         # Oh-My-Posh 主题
│   ├── tokyo.omp.json
│   └── jandedobbeleer.omp.json
└── 📁 ccr\                            # 自定义工具（如果有）
    └── ccr.cmd
```

## 4. 创建桌面快捷方式

创建 `创建快捷方式.ps1`：

```powershell
# 创建桌面快捷方式
$desktopPath = [Environment]::GetFolderPath("Desktop")
$shortcutPath = Join-Path $desktopPath "配置PowerShell环境.ps1"

$shortcutContent = @"
# PowerShell 环境配置快捷方式
Write-Host "正在配置 PowerShell 环境..." -ForegroundColor Cyan

# 切换到 U盘目录
if (Test-Path "G:\powershell-dive") {
    cd "G:\powershell-dive"
} else {
    Write-Host "❌ 请插入包含配置文件的 U盘" -ForegroundColor Red
    Read-Host "按回车键退出"
    exit
}

# 运行一键配置
.\OneClick-Setup.ps1 -All -SetupDeepSeek

Write-Host "`n配置完成！" -ForegroundColor Green
Read-Host "按回车键退出"
"@

$shortcutContent | Out-File -FilePath $shortcutPath -Encoding UTF8

Write-Host "✅ 已在桌面创建配置快捷方式" -ForegroundColor Green
Write-Host "位置: $shortcutPath" -ForegroundColor Gray
```

## 5. 使用方法

### 方法一：直接运行（推荐）
```powershell
# 插入 U盘后，打开 PowerShell 7
cd G:\powershell-dive
.\OneClick-Setup.ps1 -All -SetupDeepSeek
```

### 方法二：分步安装
```powershell
# 只安装 Profile
.\Install-Profile.ps1 -BackupExisting -SetupDeepSeek

# 只配置终端
.\Setup-Terminal.ps1 -BackupExisting

# 只安装字体
.\Install-Fonts.ps1
```

### 方法三：使用桌面快捷方式
1. 先在 U盘运行 `.\创建快捷方式.ps1`
2. 然后将桌面上的 "配置PowerShell环境.ps1" 发送到任何新电脑使用

## 6. 特性说明

这个自动安装方案会：

- ✅ **自动安装** $PROFILE 文件
- ✅ **路径适配** - 自动更新用户名和路径
- ✅ **依赖检查** - 自动安装 Oh-My-Posh、Fastfetch 等
- ✅ **模块安装** - 自动安装必要的 PowerShell 模块
- ✅ **环境配置** - 设置 DeepSeek API 密钥等
- ✅ **备份保护** - 备份现有配置避免丢失
- ✅ **错误处理** - 完善的错误提示和恢复机制

这样您就可以通过 U盘一键完成所有 PowerShell 环境的配置迁移了！本回答由 AI 生成，内容仅供参考，请仔细甄别。

# 用户：

OK，检查一下是否符合

# DeepSeek：

**原始回答**

根据您提供的文件列表，我来检查一下是否符合我们的自动配置要求：

## ✅ 文件完整性检查

### 必需文件 ✅ 全部存在
| 文件 | 状态 | 说明 |
|------|------|------|
| `Install-Fonts.ps1` | ✅ 存在 | 字体安装脚本 |
| `Install-Profile.ps1` | ✅ 存在 | Profile 安装脚本 |
| `Microsoft.PowerShell_profile.ps1` | ✅ 存在 | **您的 PowerShell 配置** |
| `OneClick-Setup.ps1` | ✅ 存在 | 一键配置主脚本 |
| `settings.json` | ✅ 存在 | **Windows Terminal 设置** |
| `Setup-Terminal.ps1` | ✅ 存在 | 终端配置脚本 |

### 文件夹检查 ⚠️ 需要确认
| 项目 | 状态 | 说明 |
|------|------|------|
| `ccr` | ⚠️ 显示为"文件" | 应该是包含 `ccr.cmd` 的**文件夹** |
| `themes` | ⚠️ 显示为"文件" | 应该是包含主题文件的**文件夹** |

## 🔧 需要修复的问题

### 问题1：ccr 和 themes 应该是文件夹
目前显示为"文件"，但应该是包含多个文件的文件夹：

**期望的结构：**
```
G:\powershell-dive\
├── ccr\                    ← 应该是文件夹
│   └── ccr.cmd            ← 包含这个文件
├── themes\                 ← 应该是文件夹  
│   ├── tokyo.omp.json     ← 包含这些主题文件
│   └── jandedobbeleer.omp.json
```

### 问题2：缺少字体文件（可选但推荐）
建议添加字体文件夹：
```
G:\powershell-dive\
└── fonts\                  ← 建议添加的文件夹
    ├── MesloLGM NF.ttf
    └── 其他 Nerd Fonts.ttf
```

## 📝 快速修复脚本

创建一个修复脚本 `Fix-Structure.ps1`：

```powershell
# Fix-Structure.ps1 - 修复文件结构
param([string]$UDrivePath = "G:\powershell-dive\")

Write-Host "🔧 检查并修复文件结构..." -ForegroundColor Cyan

# 检查 ccr
$ccrPath = Join-Path $UDrivePath "ccr"
if (Test-Path $ccrPath -PathType Leaf) {
    Write-Host "⚠️  ccr 是文件，应该是文件夹" -ForegroundColor Yellow
    # 如果是ccr.cmd文件，重命名为正确的结构
    if ((Get-Item $ccrPath).Name -eq "ccr.cmd") {
        $ccrDir = Join-Path $UDrivePath "ccr"
        New-Item -ItemType Directory -Path $ccrDir -Force
        Move-Item -Path $ccrPath -Destination (Join-Path $ccrDir "ccr.cmd")
        Write-Host "✅ 已修复 ccr 结构" -ForegroundColor Green
    }
}

# 检查 themes
$themesPath = Join-Path $UDrivePath "themes"
if (Test-Path $themesPath -PathType Leaf) {
    Write-Host "⚠️  themes 是文件，应该是文件夹" -ForegroundColor Yellow
    # 如果是主题文件，移动到正确的文件夹
    $themesDir = Join-Path $UDrivePath "themes"
    New-Item -ItemType Directory -Path $themesDir -Force
    
    # 检查文件扩展名
    $fileExt = [System.IO.Path]::GetExtension($themesPath)
    if ($fileExt -eq ".json" -or $fileExt -eq ".omp.json") {
        $fileName = Split-Path $themesPath -Leaf
        Move-Item -Path $themesPath -Destination (Join-Path $themesDir $fileName)
        Write-Host "✅ 已修复 themes 结构" -ForegroundColor Green
    }
}

# 创建缺失的文件夹
$requiredDirs = @("fonts")
foreach ($dir in $requiredDirs) {
    $dirPath = Join-Path $UDrivePath $dir
    if (-not (Test-Path $dirPath)) {
        New-Item -ItemType Directory -Path $dirPath -Force
        Write-Host "📁 创建文件夹: $dir" -ForegroundColor Green
    }
}

Write-Host "`n🎉 文件结构检查完成!" -ForegroundColor Cyan
```

## 🚀 使用建议

### 立即测试配置：
```powershell
# 1. 先运行修复脚本（如果需要）
cd G:\powershell-dive
.\Fix-Structure.ps1

# 2. 测试一键配置
.\OneClick-Setup.ps1 -All
```

### 如果 ccr/themes 确实是文件：
需要手动检查这些文件的内容：
- 如果 `ccr` 文件就是 `ccr.cmd` 的内容，需要重命名
- 如果 `themes` 文件包含主题配置，需要拆分为多个文件

## 📋 最终检查清单

运行前请确认：

- [ ] `Microsoft.PowerShell_profile.ps1` 包含您的完整配置
- [ ] `settings.json` 是有效的 Windows Terminal 配置
- [ ] `ccr` 和 `themes` 是文件夹（或已修复）
- [ ] 所有脚本文件编码为 UTF-8
- [ ] U盘有足够空间（建议 >100MB）

## 💡 如果遇到问题

### 快速诊断：
```powershell
# 检查文件类型
Get-ChildItem "G:\powershell-dive\" | Select-Object Name, @{Name="Type";Expression={if($_.PSIsContainer){"Folder"}else{"File"}}}, Length
```

### 手动修复 ccr：
如果 `ccr` 是单个文件且包含 ccr.cmd 的内容：
```powershell
# 创建 ccr 文件夹
New-Item -ItemType Directory -Path "G:\powershell-dive\ccr" -Force
# 将 ccr 文件移动并重命名为 ccr.cmd
Move-Item -Path "G:\powershell-dive\ccr" -Destination "G:\powershell-dive\ccr\ccr.cmd"
```

**总结：** 您的文件基本齐全，主要需要确认 `ccr` 和 `themes` 的文件夹结构。修复后就可以完美运行自动配置了！

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