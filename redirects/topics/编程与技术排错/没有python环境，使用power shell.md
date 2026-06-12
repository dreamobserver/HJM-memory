# 没有python环境，使用power shell

**分类**: 编程与技术排错
**来源**: DeepSeek Chat 导出
**来源平台**: DeepSeek

---

# 用户：

没有python环境，使用power shell

# DeepSeek：

**原始回答**

好的，我来为您提供一个使用PowerShell测试API连接情况的脚本。这个脚本不需要Python环境，直接在PowerShell中运行即可。

## PowerShell测试脚本

```powershell
# Gemini API连接测试脚本
# 保存为 Test-GeminiAPI.ps1 文件，然后在PowerShell中运行

# API配置
$API_BASE_URL = "https://gemini.beijixingxing.com/v1"
$API_KEY = "sk-fiZDM9HFa33kKRNuLnzfTJrbcdtXwFqVHR8YTivSJuHxsdtk"

# 请求头
$headers = @{
    "Content-Type" = "application/json"
    "Authorization" = "Bearer $API_KEY"
}

# 常见的Gemini模型列表
$commonModels = @(
    "gemini-pro",
    "gemini-1.5-pro", 
    "gemini-1.5-flash",
    "gemini-2.0-flash",
    "gpt-3.5-turbo",  # 有些中转服务可能也支持OpenAI模型
    "gpt-4"
)

# 函数：测试单个模型连接
function Test-ModelConnection {
    param(
        [string]$ModelName
    )
    
    $url = "$API_BASE_URL/chat/completions"
    $body = @{
        model = $ModelName
        messages = @(
            @{
                role = "user"
                content = "请简单回复'你好'。这是一个连接测试。"
            }
        )
        max_tokens = 10
    } | ConvertTo-Json
    
    Write-Host "测试模型: $ModelName" -ForegroundColor Yellow
    
    try {
        $response = Invoke-RestMethod -Uri $url -Method Post -Headers $headers -Body $body -TimeoutSec 30
        
        if ($response.choices -and $response.choices[0].message.content) {
            $reply = $response.choices[0].message.content.Trim()
            Write-Host "✅ 连接成功 - 回复: $reply" -ForegroundColor Green
            return $true
        } else {
            Write-Host "❌ 响应格式异常" -ForegroundColor Red
            return $false
        }
    }
    catch {
        Write-Host "❌ 连接失败 - 错误: $($_.Exception.Message)" -ForegroundColor Red
        return $false
    }
}

# 函数：尝试获取模型列表
function Get-ModelList {
    try {
        Write-Host "尝试获取支持的模型列表..." -ForegroundColor Cyan
        $modelsUrl = "$API_BASE_URL/models"
        $response = Invoke-RestMethod -Uri $modelsUrl -Method Get -Headers $headers -TimeoutSec 30
        
        if ($response.data -and $response.data.Count -gt 0) {
            $modelList = $response.data | ForEach-Object { $_.id }
            Write-Host "✅ 从API获取到 $($modelList.Count) 个模型" -ForegroundColor Green
            return $modelList
        }
    }
    catch {
        Write-Host "⚠️ 无法从API获取模型列表，使用常见模型列表" -ForegroundColor Yellow
    }
    
    return $commonModels
}

# 主测试流程
Write-Host "🚀 开始测试Gemini API连接情况" -ForegroundColor Magenta
Write-Host "API端点: $API_BASE_URL" -ForegroundColor Cyan
Write-Host "=" * 60

# 获取要测试的模型列表
$modelsToTest = Get-ModelList

Write-Host "`n📋 待测试模型列表:" -ForegroundColor Cyan
$modelsToTest | ForEach-Object { Write-Host "   - $_" }

Write-Host "`n" + "=" * 60
Write-Host "开始逐个测试模型连接..." -ForegroundColor Cyan
Write-Host ""

# 存储测试结果
$results = @{}

# 测试每个模型
foreach ($model in $modelsToTest) {
    $success = Test-ModelConnection -ModelName $model
    $results[$model] = $success
    Write-Host "-" * 50
    Start-Sleep -Milliseconds 500  # 短暂延迟，避免请求过于频繁
}

# 显示测试总结
Write-Host "`n" + "=" * 20 + " 测试总结 " + "=" * 20 -ForegroundColor Magenta

$successfulModels = $results.GetEnumerator() | Where-Object { $_.Value } | ForEach-Object { $_.Key }
$failedModels = $results.GetEnumerator() | Where-Object { -not $_.Value } | ForEach-Object { $_.Key }

Write-Host "✅ 连接成功的模型 ($($successfulModels.Count) 个):" -ForegroundColor Green
foreach ($model in $successfulModels) {
    Write-Host "   - $model"
}

Write-Host "`n❌ 连接失败的模型 ($($failedModels.Count) 个):" -ForegroundColor Red
foreach ($model in $failedModels) {
    Write-Host "   - $model"
}

Write-Host "`n🎯 测试完成!" -ForegroundColor Magenta
```

## 使用方法

1. **保存脚本**：将上面的代码保存为 `Test-GeminiAPI.ps1` 文件

2. **运行脚本**：在PowerShell中执行以下命令：
```powershell
# 如果遇到执行策略限制，先运行这个命令：
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser

# 然后运行测试脚本
.\Test-GeminiAPI.ps1
```

## 如果遇到SSL/TLS问题

如果出现SSL证书错误，可以在脚本开头添加以下代码：

```powershell
# 添加在脚本开头，处理SSL/TLS问题
[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12
Add-Type @"
    using System.Net;
    using System.Security.Cryptography.X509Certificates;
    public class TrustAllCertsPolicy : ICertificatePolicy {
        public bool CheckValidationResult(
            ServicePoint srvPoint, X509Certificate certificate,
            WebRequest request, int certificateProblem) {
            return true;
        }
    }
"@
[System.Net.ServicePointManager]::CertificatePolicy = New-Object TrustAllCertsPolicy
```

## 脚本特点

- ✅ **无需Python环境**：纯PowerShell实现
- ✅ **自动模型发现**：尝试从API获取支持的模型列表
- ✅ **详细错误报告**：显示具体的错误信息
- ✅ **彩色输出**：更容易区分成功和失败
- ✅ **超时控制**：避免长时间等待
- ✅ **测试总结**：清晰的测试结果汇总

## 预期输出示例

```
🚀 开始测试Gemini API连接情况
API端点: https://gemini.beijixingxing.com/v1
============================================================

📋 待测试模型列表:
   - gemini-pro
   - gemini-1.5-pro
   - gemini-1.5-flash

============================================================
开始逐个测试模型连接...

测试模型: gemini-pro
✅ 连接成功 - 回复: 你好！这是一个连接测试。
--------------------------------------------------
测试模型: gemini-1.5-pro  
✅ 连接成功 - 回复: 你好！连接测试收到。
--------------------------------------------------
测试模型: gemini-1.5-flash
❌ 连接失败 - 错误: 模型不存在
--------------------------------------------------

==================== 测试总结 ====================
✅ 连接成功的模型 (2 个):
   - gemini-pro
   - gemini-1.5-pro

❌ 连接失败的模型 (1 个):
   - gemini-1.5-flash

🎯 测试完成!
```

这个PowerShell脚本应该能满足您的需求。如果运行中遇到任何问题，请告诉我具体的错误信息，我可以帮您进一步调整。本回答由 AI 生成，内容仅供参考，请仔细甄别。
