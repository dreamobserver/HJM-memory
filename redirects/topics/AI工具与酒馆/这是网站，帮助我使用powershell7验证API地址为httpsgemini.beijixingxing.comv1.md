# 这是网站，帮助我使用powershell7验证API地址为https://gemini.beijixingxing.com/v1

**分类**：AI工具与酒馆
**来源**：DeepSeek Chat 导出
**来源平台**：DeepSeek
**原始文件**：SSE Error__{_  _error__ _{__erro.md
**包含轮次**：9 - 9

---

# 用户：
这是网站，帮助我使用powershell7验证API地址为https://gemini.beijixingxing.com/v1
API秘钥sk-7qN7wdHJVPce7dVnltwqPRDDjMwNX6qLYhn1UacMzJ9wtNKx

# DeepSeek：

**原始回答**
我来帮您使用PowerShell 7验证这个Gemini API地址。以下是完整的验证脚本：

## 基础验证脚本

```powershell
# Gemini API验证脚本
$apiKey = "sk-7qN7wdHJVPce7dVnltwqPRDDjMwNX6qLYhn1UacMzJ9wtNKx"
$apiUrl = "https://gemini.beijixingxing.com/v1"
$headers = @{
    "Authorization" = "Bearer $apiKey"
    "Content-Type" = "application/json"
}

# 1. 测试基础连接
Write-Host "🔍 测试API基础连接..." -ForegroundColor Yellow
try {
    $response = Invoke-RestMethod -Uri "$apiUrl/models" -Method Get -Headers $headers
    Write-Host "✅ 基础连接成功！" -ForegroundColor Green
    Write-Host "可用模型: " -NoNewline
    $response.data | ForEach-Object { Write-Host "$($_.id) " -NoNewline -ForegroundColor Cyan }
    Write-Host ""
} catch {
    Write-Host "❌ 基础连接失败: $($_.Exception.Message)" -ForegroundColor Red
}
```

## 完整功能测试脚本

```powershell
# 完整的Gemini API验证脚本
function Test-GeminiAPI {
    param(
        [string]$ApiKey = "sk-7qN7wdHJVPce7dVnltwqPRDDjMwNX6qLYhn1UacMzJ9wtNKx",
        [string]$BaseUrl = "https://gemini.beijixingxing.com/v1"
    )
    
    # 设置请求头
    $headers = @{
        "Authorization" = "Bearer $ApiKey"
        "Content-Type" = "application/json"
    }
    
    Write-Host "🚀 开始验证Gemini API..." -ForegroundColor Magenta
    Write-Host "API地址: $BaseUrl" -ForegroundColor Gray
    Write-Host "=" * 60 -ForegroundColor Gray
    
    # 1. 测试模型列表端点
    Write-Host "1. 测试模型列表端点..." -ForegroundColor Yellow
    try {
        $modelsResponse = Invoke-RestMethod -Uri "$BaseUrl/models" -Method Get -Headers $headers
        Write-Host "   ✅ 模型列表获取成功" -ForegroundColor Green
        Write-Host "   📊 可用模型数量: $($modelsResponse.data.Count)" -ForegroundColor Cyan
        
        # 显示前5个模型
        $modelsResponse.data[0..4] | ForEach-Object {
            Write-Host "      • $($_.id)" -ForegroundColor White
        }
    } catch {
        Write-Host "   ❌ 模型列表获取失败: $($_.Exception.Message)" -ForegroundColor Red
        return $false
    }
    
    # 2. 测试聊天完成端点
    Write-Host "`n2. 测试聊天完成端点..." -ForegroundColor Yellow
    try {
        $chatBody = @{
            model = "gpt-3.5-turbo"
            messages = @(
                @{
                    role = "user"
                    content = "请回复'API测试成功'"
                }
            )
            max_tokens = 50
        } | ConvertTo-Json
        
        $chatResponse = Invoke-RestMethod -Uri "$BaseUrl/chat/completions" -Method Post -Headers $headers -Body $chatBody
        Write-Host "   ✅ 聊天API测试成功" -ForegroundColor Green
        Write-Host "   🤖 回复: $($chatResponse.choices[0].message.content)" -ForegroundColor Cyan
    } catch {
        Write-Host "   ❌ 聊天API测试失败: $($_.Exception.Message)" -ForegroundColor Red
    }
    
    # 3. 测试流式响应
    Write-Host "`n3. 测试流式响应..." -ForegroundColor Yellow
    try {
        $streamBody = @{
            model = "gpt-3.5-turbo"
            messages = @(
                @{
                    role = "user"
                    content = "简单介绍一下你自己"
                }
            )
            stream = $true
            max_tokens = 100
        } | ConvertTo-Json
        
        # 使用WebRequest获取流式响应
        $request = [System.Net.HttpWebRequest]::Create("$BaseUrl/chat/completions")
        $request.Headers.Add("Authorization", "Bearer $ApiKey")
        $request.ContentType = "application/json"
        $request.Method = "POST"
        
        $stream = $request.GetRequestStream()
        $writer = New-Object System.IO.StreamWriter($stream)
        $writer.Write($streamBody)
        $writer.Flush()
        $writer.Close()
        
        $response = $request.GetResponse()
        $reader = New-Object System.IO.StreamReader($response.GetResponseStream())
        
        Write-Host "   ✅ 流式连接建立成功" -ForegroundColor Green
        Write-Host "   📡 开始接收流数据..." -ForegroundColor Cyan
        
        # 读取前几行流数据
        for ($i = 0; $i -lt 5; $i++) {
            $line = $reader.ReadLine()
            if ($line -and $line -match "data: ") {
                $data = $line.Substring(6) | ConvertFrom-Json -ErrorAction SilentlyContinue
                if ($data -and $data.choices[0].delta.content) {
                    Write-Host "      $($data.choices[0].delta.content)" -ForegroundColor White -NoNewline
                }
            }
        }
        Write-Host ""
        $reader.Close()
        
    } catch {
        Write-Host "   ❌ 流式响应测试失败: $($_.Exception.Message)" -ForegroundColor Red
    }
    
    # 4. 测试 completions 端点
    Write-Host "`n4. 测试Completions端点..." -ForegroundColor Yellow
    try {
        $completionBody = @{
            model = "text-davinci-003"
            prompt = "Say 'Hello, PowerShell!'"
            max_tokens = 20
        } | ConvertTo-Json
        
        $completionResponse = Invoke-RestMethod -Uri "$BaseUrl/completions" -Method Post -Headers $headers -Body $completionBody
        Write-Host "   ✅ Completions API测试成功" -ForegroundColor Green
        Write-Host "   📝 回复: $($completionResponse.choices[0].text)" -ForegroundColor Cyan
    } catch {
        Write-Host "   ⚠️ Completions API测试失败 (可能是端点不支持): $($_.Exception.Message)" -ForegroundColor Yellow
    }
    
    Write-Host "`n" + "=" * 60 -ForegroundColor Gray
    Write-Host "🎉 Gemini API验证完成！" -ForegroundColor Magenta
    return $true
}

# 执行验证
Test-GeminiAPI
```

## 高级监控脚本

```powershell
# API健康监控脚本
function Start-APIMonitor {
    param(
        [string]$ApiKey = "sk-7qN7wdHJVPce7dVnltwqPRDDjMwNX6qLYhn1UacMzJ9wtNKx",
        [string]$BaseUrl = "https://gemini.beijixingxing.com/v1",
        [int]$IntervalSeconds = 30
    )
    
    $headers = @{
        "Authorization" = "Bearer $ApiKey"
        "Content-Type" = "application/json"
    }
    
    Write-Host "🔬 启动API健康监控..." -ForegroundColor Magenta
    Write-Host "监控间隔: $IntervalSeconds 秒" -ForegroundColor Gray
    Write-Host "按 Ctrl+C 停止监控`n" -ForegroundColor Gray
    
    $successCount = 0
    $failCount = 0
    
    while ($true) {
        $timestamp = Get-Date -Format "yyyy-MM-dd HH:mm:ss"
        
        try {
            # 简单的健康检查
            $response = Invoke-RestMethod -Uri "$BaseUrl/models" -Method Get -Headers $headers -TimeoutSec 10
            $successCount++
            Write-Host "[$timestamp] ✅ 健康检查通过 (成功: $successCount, 失败: $failCount)" -ForegroundColor Green
            
        } catch {
            $failCount++
            Write-Host "[$timestamp] ❌ 健康检查失败: $($_.Exception.Message) (成功: $successCount, 失败: $failCount)" -ForegroundColor Red
        }
        
        Start-Sleep -Seconds $IntervalSeconds
    }
}

# 使用示例：
# Start-APIMonitor -IntervalSeconds 60
```

## 快速测试命令

```powershell
# 单行快速测试
$apiKey = "sk-7qN7wdHJVPce7dVnltwqPRDDjMwNX6qLYhn1UacMzJ9wtNKx"; $headers = @{"Authorization"="Bearer $apiKey";"Content-Type"="application/json"}; try { Invoke-RestMethod -Uri "https://gemini.beijixingxing.com/v1/models" -Headers $headers; Write-Host "✅ API验证成功" -ForegroundColor Green } catch { Write-Host "❌ API验证失败: $($_.Exception.Message)" -ForegroundColor Red }
```

## 使用说明

1. **保存脚本**：将上述代码保存为 `.ps1` 文件
2. **执行权限**：可能需要先运行 `Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser`
3. **运行脚本**：在PowerShell 7中执行脚本

## 预期输出示例
```
🚀 开始验证Gemini API...
API地址: https://gemini.beijixingxing.com/v1
============================================================
1. 测试模型列表端点...
   ✅ 模型列表获取成功
   📊 可用模型数量: 15
      • gpt-3.5-turbo
      • gpt-4
      • text-davinci-003
...
```

运行这些脚本将全面测试您的Gemini API连接状态、功能可用性和性能表现。

