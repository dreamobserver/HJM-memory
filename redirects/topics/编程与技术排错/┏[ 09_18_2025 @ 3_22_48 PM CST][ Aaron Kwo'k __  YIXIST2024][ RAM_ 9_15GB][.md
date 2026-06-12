# ┏[ 09/18/2025 @ 3:22:48 PM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 9/15GB][

**分类**: 编程与技术排错
**来源**: DeepSeek Chat 导出
**来源平台**: DeepSeek

---

# 用户：

┏[ 09/18/2025 @ 3:22:48 PM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 9/15GB][ 100][ 1.127s]
┣[ ~]
└─[#]>
┏[ 09/18/2025 @ 3:22:48 PM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 9/15GB][ 100][ 0s]
┣[ ~]
└─[#]> # 先测试简单函数
┏[ 09/18/2025 @ 3:22:48 PM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 9/15GB][ 100][ 0s]
┣[ ~]
└─[#]> testds "Hello"
测试请求...
Hello! How can I assist you today? ð
┏[ 09/18/2025 @ 3:22:52 PM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 9/15GB][ 100][ 3.612s]
┣[ ~]
└─[#]> testds "你好"
测试请求...
ä½ å¥½ï¼ð è¯·é®æä»ä¹å¯ä»¥å¸®å©ä½ çåï¼
┏[ 09/18/2025 @ 3:22:56 PM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 9/15GB][ 100][ 3.712s]
┣[ ~]
└─[#]>
┏[ 09/18/2025 @ 3:22:56 PM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 9/15GB][ 100][ 0s]
┣[ ~]
└─[#]> # 如果上面工作，测试完整函数
┏[ 09/18/2025 @ 3:22:56 PM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 9/15GB][ 100][ 0s]
┣[ ~]
└─[#]> ds "请用中文简单介绍你自己" -NoHistory

# DeepSeek：

**原始回答**

很好！测试结果显示：

1. **英文查询正常**：`testds "Hello"` 工作正常
2. **中文查询有响应但乱码**：`testds "你好"` 返回了响应但显示乱码
3. **完整函数可能还在运行**：`ds "请用中文简单介绍你自己" -NoHistory` 正在执行

这说明 API 连接是正常的，问题纯粹是**中文显示编码问题**。让我们修复这个问题：

## 修复中文显示乱码

在你的 profile 文件中修改 `Invoke-DeepSeek` 函数，添加编码修复：

```powershell
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
```

## 同时修复测试函数

```powershell
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
```

## 重新测试

```powershell
# 重新加载 profile
. $PROFILE

# 测试中文显示
testds "你好"

# 如果显示正常，测试完整函数
ds "请用中文简单介绍你自己" -NoHistory
```

如果仍然显示乱码，请告诉我具体的输出内容，这样我可以进一步调整编码转换逻辑。
