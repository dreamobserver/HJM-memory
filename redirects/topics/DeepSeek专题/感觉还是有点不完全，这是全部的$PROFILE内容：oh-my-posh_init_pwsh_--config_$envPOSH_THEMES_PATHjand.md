# 感觉还是有点不完全，这是全部的$PROFILE内容：oh-my-posh init pwsh --config "$env:POSH_THEMES_PATH\jandedobbeleer.omp.

**分类**：DeepSeek专题
**来源**：DeepSeek Chat 导出
**来源平台**：DeepSeek
**原始文件**：Fixing PowerShell Path Issue with Apostrophes.md
**包含轮次**：4 - 4

---

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

