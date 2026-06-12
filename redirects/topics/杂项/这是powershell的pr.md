# 这是powershell的pr

**分类**: 杂项
**来源**: DeepSeek Chat 导出
**来源平台**: DeepSeek

---

# 用户：

这是powershell的profile文件修改一下

# DeepSeek：

**原始回答**

我看到你的 profile 文件了。问题在于 JSON 编码和 Unicode 字符处理。让我帮你修复 `Invoke-DeepSeek` 函数：

```powershell
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
    
    # 构建请求体 - 修复编码问题
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
        
        # 更新历史记录
        if (-not $NoHistory) {
            $script:DeepSeekHistory += @{role = "user"; content = $Question}
            $script:DeepSeekHistory += @{role = "assistant"; content = $answer}
            
            # 限制历史记录长度
            if ($script:DeepSeekHistory.Count -gt 10) {
                $script:DeepSeekHistory = $script:DeepSeekHistory | Select-Object -Last 10
            }
        }
        
        return $answer
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

Set-Alias ds Invoke-DeepSeek

# 添加一个简单的测试函数
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
        
        return $response.choices[0].message.content
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

Set-Alias testds Test-DeepSeekSimple
```

## 主要修改：

1. **修复了 JSON 编码**：使用 `-Body ([System.Text.Encoding]::UTF8.GetBytes($jsonBody))` 确保正确编码
2. **移除了重复的编码设置**：删除了重复的 `$OutputEncoding` 和 `chcp` 设置
3. **添加了测试函数**：`Test-DeepSeekSimple` 使用硬编码 JSON 来避免编码问题

## 测试步骤：

```powershell
# 重新加载 profile
. $PROFILE

# 先测试简单函数
testds "Hello"
testds "你好"

# 如果上面工作，测试完整函数
ds "请用中文简单介绍你自己" -NoHistory
```

如果仍有问题，请运行测试并告诉我具体的错误信息。
