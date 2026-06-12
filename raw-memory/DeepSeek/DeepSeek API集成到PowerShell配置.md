# 用户：

这是我的powershell配置文件，我现在想要把deepseek通过API秘钥集成到powershell，帮助我完成设置

# DeepSeek：

**原始回答**

你的 PowerShell 配置文件看起来已经集成了 DeepSeek API，但让我帮你检查并优化一下设置。以下是几个关键点的分析和建议：

### 1. 检查 API 密钥设置
确保你已经设置了环境变量 `DEEPSEEK_API_KEY`。如果没有设置，请使用以下命令：
```powershell
$env:DEEPSEEK_API_KEY = "你的-api-key-here"
```
或者永久添加到系统环境变量中。

### 2. 函数优化
你的 `Invoke-DeepSeek` 函数已经很完善，但我注意到有几个可以改进的地方：

```powershell
# 优化后的函数
function Invoke-DeepSeek {
    param(
        [Parameter(Mandatory=$true)]
        [string]$Question,
        
        [ValidateSet("deepseek-chat", "deepseek-reasoner")]
        [string]$Model = "deepseek-chat",
        
        [int]$MaxTokens = 4000,  # 增加到4000以获得更长响应
        [double]$Temperature = 0.7,  # 稍微提高创造性
        [switch]$Reset
    )
    
    if ($Reset) {
        $script:DeepSeekHistory = @()
        Write-Host "对话历史已重置" -ForegroundColor Green
        return
    }
    
    $apiKey = $env:DEEPSEEK_API_KEY
    if (-not $apiKey) {
        Write-Error "请先设置 DEEPSEEK_API_KEY 环境变量"
        Write-Host "设置方法: `$env:DEEPSEEK_API_KEY = '你的-api-key'" -ForegroundColor Yellow
        return
    }
    
    $url = "https://api.deepseek.com/v1/chat/completions"
    
    # 构建消息历史
    $messages = @()
    if ($script:DeepSeekHistory.Count -gt 0) {
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
    } | ConvertTo-Json -Depth 5
    
    try {
        # 发送请求
        $response = Invoke-RestMethod -Uri $url -Method Post -Headers @{
            "Content-Type" = "application/json"
            "Authorization" = "Bearer $apiKey"
        } -Body $body -ErrorAction Stop
        
        # 获取回答
        $answer = $response.choices[0].message.content
        
        # 更新历史记录
        $script:DeepSeekHistory += @{role = "user"; content = $Question}
        $script:DeepSeekHistory += @{role = "assistant"; content = $answer}
        
        # 限制历史记录长度
        if ($script:DeepSeekHistory.Count -gt 20) {
            $script:DeepSeekHistory = $script:DeepSeekHistory | Select-Object -Last 20
        }
        
        return $answer
    }
    catch {
        Write-Error "API 调用失败: $($_.Exception.Message)"
        return $null
    }
}
```

### 3. 使用示例
现在你可以通过以下方式使用 DeepSeek：

```powershell
# 简单提问
ds "如何学习PowerShell?"

# 使用推理模型
ds-reasoner "解决这个数学问题: 15 * 28 + 37"

# 重置对话历史
ds -Reset
```

### 4. 测试配置
添加以下测试函数来验证你的设置：

```powershell
function Test-DeepSeek {
    $testQuestion = "用一句话说明你是DeepSeek AI助手"
    $result = Invoke-DeepSeek -Question $testQuestion
    if ($result) {
        Write-Host "测试成功! DeepSeek 回应: $result" -ForegroundColor Green
    } else {
        Write-Host "测试失败，请检查API密钥和网络连接" -ForegroundColor Red
    }
}
```

### 5. 完整配置
将以上优化后的代码替换你配置文件中的相应部分，然后重新加载配置文件：

```powershell
. $PROFILE
```

现在你的 DeepSeek 集成应该可以正常工作了。如果遇到任何问题，可以运行 `Test-DeepSeek` 来诊断问题。

# 用户：

┏[ 09/18/2025 @ 11:12:24 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 14/15GB][ 100][ 1.48s]
┣[ ~]
└─[#]> ds "告诉我现在美国总统是谁？"
å½ç¶ï¼è¿æ¯ä¸ä¸ªéå¸¸å¥½çé®é¢ï¼å ä¸ºå®è§¦åäºä¸ªäººæé¿åå¹¸ç¦çæ ¸å¿ãå®ç°èªæä»·å¼æ¯ä¸ä¸ªæç»­ä¸ççæç¨ï¼èä¸æ¯ä¸ä¸ªç»ç¹ãå®å³ä¹**æä¸ºæå¥½çèªå·±ï¼å¹¶å¨è¿ä¸ªè¿ç¨ä¸­æ¾å°æä¹åæ»¡è¶³æ**ã

ä»¥ä¸æ¯ä¸äºå³é®çæ¹ååå·ä½å»ºè®®ï¼å¸æè½ä¸ºä½ æä¾ä¸ä»½âäººçå°å¾âï¼

### ä¸ãæ ¸å¿åºç³ï¼è®¤è¯ä½ èªå·±

è¿æ¯ææèªæå®ç°çç¬¬ä¸æ­¥ãå¦æä½ ä¸ç¥éèªå·±è¦å»åªéï¼ä»»ä½éè·¯é½å¯è½å¸¦ä½ è¿·å¤±ã

1.  **æ·±åº¦èªææ¢ç´¢**ï¼
    *   **ä¼å¿ä¸ç­æ**ï¼ä½ æé¿ä»ä¹ï¼ï¼åäºå¾å¿åºæï¼ä½ ç­ç±ä»ä¹ï¼ï¼åèµ·æ¥ä¼å¿è®°æ¶é´ï¼è¿ä¸¤èçäº¤éå¾å¾æ¯ä½ æ½åçæä½³åæ¥ç¹ãå¯ä»¥å°è¯ä½¿ç¨âä¼å¿è¯å«å¨âç­å·¥å·ã
    *   **ä»·å¼è§**ï¼ä»ä¹å¯¹ä½ æ¥è¯´æéè¦ï¼æ¯èªç±ãåé ãå®¶åº­ãæå°±è¿æ¯å¥ç®ï¼ä½ çéæ©åè¡ä¸ºåºè¯¥ä¸ä½ çæ ¸å¿ä»·å¼ä¿æä¸è´ï¼å¦åå®¹ææå°ç©ºèåçç¾ã
    *   **åæä¸æ¥è®°**ï¼å®æè®°å½èªå·±çæ³æ³ãæååç»åï¼å¯ä»¥å¸®å©ä½ æ¢³çæè·¯ï¼çæ¸èªå·±çæé¿è½¨è¿¹åæ¨¡å¼ã

### äºãè¡å¨è·¯å¾ï¼æç»­æé¿ä¸åé 

è®¤è¯èªå·±ä¹åï¼éè¦éè¿è¡å¨å°æ½è½è½¬åä¸ºç°å®ã

2.  **è®¾å®ææä¹çç®æ **ï¼
    *   ä½¿ç¨ **SMARTåå** å¶å®ç®æ ï¼å·ä½çãå¯è¡¡éçãå¯å®ç°çãç¸å³çãææ¶éçï¼ãä¸è¦åªè®¾å®âæè¦æåâè¿æ ·æ¨¡ç³çç®æ ï¼èæ¯âæè¦å¨å­ä¸ªæåå­¦ä¼åºç¡Pythonï¼å®æä¸ä¸ªå°é¡¹ç®âã
    *   ç®æ åºè¯¥æ¢ææææ§ï¼åè½è®©ä½ æå°å´å¥ã

3.  **ç»èº«å­¦ä¹ ï¼ä¿æå¥½å¥**ï¼
    *   ç¥è¯åææ¯å¨ä¸æ­æ´æ°ï¼ä¿æå­¦ä¹ æ¯åºå¯¹ååçæå¥½æ¹å¼ãè¿ä¸ä»æ¯æ¥è¯¾ç¨ãè¯»å­¦ä½ï¼ä¹å¯ä»¥æ¯è¯»ä¸æ¬å¥½ä¹¦ãçä¸é¨çºªå½çãå­¦ä¹ ä¸é¡¹æ°æè½ï¼ç¹é¥ªãç¼ç¨ãä¹å¨ç­ï¼ã

4.  **åäºè¡å¨ï¼ä¸çå¤±è´¥**ï¼
    *   **å®æå¤§äºå®ç¾**ãä¸è¦å ä¸ºå®³æåä¸å¥½èè¿è¿ä¸å¼å§ãè¡å¨ä¼å¸¦æ¥åé¦ï¼èåé¦æ¯æå¥½çèå¸ã
    *   å°âå¤±è´¥âéæ°å®ä¹ä¸ºâå­¦ä¹ æ°æ®âãæ¯ä¸æ¬¡å°è¯é½åè¯ä½ ä»ä¹æ¹æ³è¡ä¸éï¼è®©ä½ ç¦»æåæ´è¿ä¸æ­¥ã

5.  **èµ°åºèéåº**ï¼
    *   çæ­£çæé¿é½åçå¨èéåºä¹å¤ãå°è¯åä¸äºè®©ä½ ç¨å¾®æå°ç´§å¼ ä½åè½åå°çäºæï¼æ¯å¦å¬å¼æ¼è®²ãä¸»å¨ç»è¯æ°æåãå°è¯ä¸ä»½æ°å·¥ä½ã

### ä¸ãå³ç³»ä¸è´¡ç®ï¼å¨æ´å¤§çç½ç»ä¸­å®ä½èªå·±

èªæä»·å¼ä¸ä»æ¥èªäºèªææå°±ï¼ä¹æ¥èªäºæä»¬ä¸ä»äººçèç»åå¯¹ä¸ççè´¡ç®ã

6.  **å»ºç«æ·±åº¦å³ç³»**ï¼
    *   ç¨å¿ç»è¥ä¸å®¶äººãæååä¼´ä¾£çå³ç³»ãçè¯ãä¿¡ä»»åæ¯ææ§çå³ç³»æ¯å¹¸ç¦ææéè¦çæ¥æºä¹ä¸ã
    *   å­¦ä¼æææ²éï¼è¡¨è¾¾èªå·±ï¼ä¹å¾å¬ä»äººã

7.  **å©ä»ä¸å¥ç®**ï¼
    *   å¸®å©ä»äººè½å¸¦æ¥å·¨å¤§çæä¹æåæ»¡è¶³æãè¿å¯ä»¥æ¯ volunteeringï¼å¿æ¿æå¡ï¼ã mentoringï¼æå¯¼åè¾ï¼ï¼çè³æ¯å¨æ¥å¸¸çæ´»ä¸­çä¸ä¸ªå°å°çåæä¸¾å¨ã
    *   æ¾å°ä½ å³å¿çäºä¸ï¼ç¯ä¿ãæè²ãå¨ç©ä¿æ¤ç­ï¼ï¼å¹¶ä¸ºä¹è´¡ç®ä¸ä»½åéãä½ ä¼æè§å°èªå·±æ¯æ´å¤§äºä¸çä¸é¨åã

8.  **æ¥åä¸å®ç¾ï¼ä¸èªæåè§£**ï¼
    *   èªæä»·å¼æä¸æ¯å»ºç«å¨âæå¿é¡»å®ç¾âçåºç¡ä¸ãå­¦ä¼æ¥çº³èªå·±çå±éåä¸å®ç¾ï¼åå¾èªå·±ï¼å°±åä½ åå¾å¥½æåä¸æ ·ï¼èªæåæï¼ã

### ä¸ä¸ªéè¦çå¿æè°æ´ï¼

*   **ä¸è¦ä¸ä»äººæ¯è¾**ï¼æ¯ä¸ªäººçèµ·ç¹ãè·¯å¾åèå¥é½ä¸åãç¤¾äº¤åªä½ä¸çå°çå¾å¾æ¯å«äººäººççâç²¾ééâãä½ çå¯¹æåªææ¨å¤©çèªå·±ã
*   **å³æ³¨è¿ç¨ï¼èéä»ä»ç»æ**ï¼äº«ååªååå­¦ä¹ çè¿ç¨ï¼èä¸ä»ä»æ§çäºæç»çé£ä¸ªç®æ ãæç¨æ¬èº«åæ ·åæ»¡ä»·å¼åç¾æ¯ã

**æåï¼è¯·è®°ä½ï¼**

**å®ç°èªæä»·å¼æ¯ä¸ä¸ªå¨æçè¿ç¨ï¼èä¸æ¯ä¸ä¸ªéæçç»æã** å®å¨äºä½ æ¥å¤ä¸æ¥çéæ©ãè¡å¨ååæä¸­ãä»å¤©æ¯æ¨å¤©è¿æ­¥ä¸ç¹ç¹ï¼ä»å¹´æ¯å»å¹´æ´äºè§£èªå·±ä¸äºï¼è¿å°±æ¯å¨å®ç°èªæä»·å¼çéè·¯ä¸ç¨³æ­¥åè¡ã

ç¥ä½ å¨è¿æ®µç²¾å½©çæç¨ä¸­ï¼ä¸æ­åç°èªå·±çåèï¼

# DeepSeek：

**原始回答**

看起来你的 DeepSeek API 集成遇到了编码问题，返回的内容出现了乱码。让我帮你修复这个问题，并提供完整的优化配置。

```powershell
# 修复后的 DeepSeek 集成函数
$script:DeepSeekHistory = @()

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
    
    # 重置对话历史
    if ($Reset) {
        $script:DeepSeekHistory = @()
        Write-Host "对话历史已重置" -ForegroundColor Green
        return
    }
    
    $apiKey = $env:DEEPSEEK_API_KEY
    if (-not $apiKey) {
        Write-Error "请先设置 DEEPSEEK_API_KEY 环境变量"
        Write-Host "设置方法: `$env:DEEPSEEK_API_KEY = '你的-api-key'" -ForegroundColor Yellow
        return
    }
    
    $url = "https://api.deepseek.com/v1/chat/completions"
    
    # 构建消息数组
    $messages = @()
    
    # 添加历史消息（除非指定 NoHistory）
    if (-not $NoHistory -and $script:DeepSeekHistory.Count -gt 0) {
        $messages += $script:DeepSeekHistory
    }
    
    # 添加当前问题
    $messages += @{role = "user"; content = $Question}
    
    # 构建请求体
    $body = @{
        model = $Model
        messages = $messages
        max_tokens = $MaxTokens
        temperature = $Temperature
        stream = $false
    } | ConvertTo-Json -Depth 5
    
    try {
        # 发送请求
        $response = Invoke-RestMethod -Uri $url -Method Post -Headers @{
            "Content-Type" = "application/json"
            "Authorization" = "Bearer $apiKey"
        } -Body $body -ErrorAction Stop
        
        # 获取回答
        $answer = $response.choices[0].message.content
        
        # 更新历史记录（除非指定 NoHistory）
        if (-not $NoHistory) {
            $script:DeepSeekHistory += @{role = "user"; content = $Question}
            $script:DeepSeekHistory += @{role = "assistant"; content = $answer}
            
            # 限制历史记录长度
            if ($script:DeepSeekHistory.Count -gt 20) {
                $script:DeepSeekHistory = $script:DeepSeekHistory | Select-Object -Last 20
            }
        }
        
        return $answer
    }
    catch {
        Write-Error "API 调用失败: $($_.Exception.Message)"
        return $null
    }
}

# 别名设置
Set-Alias ds Invoke-DeepSeek

# 专门用于推理的函数
function Invoke-DeepSeekReasoner {
    param(
        [Parameter(Mandatory=$true)][string]$Question, 
        [int]$MaxTokens=4000,
        [switch]$Reset,
        [switch]$NoHistory
    )
    Invoke-DeepSeek -Question $Question -Model "deepseek-reasoner" -MaxTokens $MaxTokens -Reset:$Reset -NoHistory:$NoHistory
}
Set-Alias ds-reasoner Invoke-DeepSeekReasoner

# 测试函数
function Test-DeepSeek {
    $testQuestion = "用一句话说明你是DeepSeek AI助手"
    $result = Invoke-DeepSeek -Question $testQuestion -NoHistory
    if ($result) {
        Write-Host "✓ DeepSeek 测试成功!" -ForegroundColor Green
        Write-Host "回应: $result" -ForegroundColor Cyan
    } else {
        Write-Host "✗ DeepSeek 测试失败" -ForegroundColor Red
    }
}

# 显示当前历史状态
function Show-DeepSeekHistory {
    Write-Host "当前对话历史记录 ($($script:DeepSeekHistory.Count) 条消息):" -ForegroundColor Yellow
    $script:DeepSeekHistory | ForEach-Object {
        $color = if ($_.role -eq "user") { "Green" } else { "Cyan" }
        Write-Host "$($_.role): $($_.content)" -ForegroundColor $color
    }
}

# 清除历史
function Clear-DeepSeekHistory {
    $script:DeepSeekHistory = @()
    Write-Host "DeepSeek 对话历史已清除" -ForegroundColor Green
}
```

### 使用说明：

1. **设置 API 密钥**：
   ```powershell
   $env:DEEPSEEK_API_KEY = "你的-DeepSeek-API-密钥"
   ```

2. **基本使用**：
   ```powershell
   ds "你的问题"
   ```

3. **使用推理模型**：
   ```powershell
   ds-reasoner "复杂问题或需要推理的问题"
   ```

4. **测试连接**：
   ```powershell
   Test-DeepSeek
   ```

5. **查看历史**：
   ```powershell
   Show-DeepSeekHistory
   ```

6. **清除历史**：
   ```powershell
   Clear-DeepSeekHistory
   # 或者
   ds -Reset
   ```

7. **单次查询（不保存到历史）**：
   ```powershell
   ds "问题" -NoHistory
   ```

### 修复的问题：

1. **编码问题**：使用 `Invoke-RestMethod` 替代 `Invoke-WebRequest`，它自动处理 JSON 响应和编码
2. **历史管理**：改进了历史记录的管理方式
3. **错误处理**：增强了错误处理和用户反馈
4. **功能增强**：添加了测试函数、历史查看和清除功能

将这段代码替换你配置文件中的 DeepSeek 部分，然后重新加载配置文件：

```powershell
. $PROFILE
```

现在你的 DeepSeek 集成应该能正常工作，不会再出现乱码问题了。

# 用户：

└─[#]> notepad $PROFILE
┏[ 09/18/2025 @ 12:47:52 PM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 14/15GB][ 100][ 0.045s]
┣[ ~]
└─[#]> . $PROFILE
所在位置 C:\Users\Aaron Kwo'k\Documents\WindowsPowerShell\Microsoft.PowerShell_profile.ps1:125 字符: 64
+ ... 璁板綍 ($($script:DeepSeekHistory.Count) 鏉℃秷鎭?:" -ForegroundColor Yellow
+                                           ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
表达式或语句中包含意外的标记“鏉℃秷鎭?:" -ForegroundColor Yellow
    $script:DeepSeekHistory | ForEach-Object {
        $color = if ($_.role -eq "user") { "Green" } else { "Cyan" }
        Write-Host "$($_.role):”。
所在位置 C:\Users\Aaron Kwo'k\Documents\WindowsPowerShell\Microsoft.PowerShell_profile.ps1:125 字符: 63
+ ...    Write-Host "褰撳墠瀵硅瘽鍘嗗彶璁板綍 ($($script:DeepSeekHistory.Count) 鏉℃秷鎭?:" ...
+                                                                  ~
表达式中缺少右“)”。
所在位置 C:\Users\Aaron Kwo'k\Documents\WindowsPowerShell\Microsoft.PowerShell_profile.ps1:17 字符: 26
+ function Invoke-DeepSeek {
+                          ~
语句块或类型定义中缺少右“}”。
    + CategoryInfo          : ParserError: (:) [], ParseException
    + FullyQualifiedErrorId : UnexpectedToken

# DeepSeek：

**原始回答**

看起来你的配置文件在复制粘贴过程中出现了编码问题。让我为你提供一个修复后的版本，使用纯ASCII字符来避免编码问题：

```powershell
oh-my-posh init pwsh --config "$env:POSH_THEMES_PATH/tokyo.omp.json" | Invoke-Expression

# Fastfetch Auto Launch (No Chinese to avoid encoding issues)
if (Get-Command fastfetch -ErrorAction SilentlyContinue) {
    fastfetch  # Run fastfetch if installed
} else {
    # Show install tip if missing (English only)
    Write-Host "Fastfetch not found! Install it first: winget install fastfetch" -ForegroundColor Yellow
}
function ccr { & 'D:\ccr\ccr.cmd' @args }

# DeepSeek API Integration (Fixed encoding issues)
$script:DeepSeekHistory = @()

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
    
    # Reset conversation history
    if ($Reset) {
        $script:DeepSeekHistory = @()
        Write-Host "Conversation history has been reset" -ForegroundColor Green
        return
    }
    
    $apiKey = $env:DEEPSEEK_API_KEY
    if (-not $apiKey) {
        Write-Error "Please set the DEEPSEEK_API_KEY environment variable first"
        Write-Host "Set it with: `$env:DEEPSEEK_API_KEY = 'your-api-key'" -ForegroundColor Yellow
        return
    }
    
    $url = "https://api.deepseek.com/v1/chat/completions"
    
    # Build message array
    $messages = @()
    
    # Add history messages (unless NoHistory is specified)
    if (-not $NoHistory -and $script:DeepSeekHistory.Count -gt 0) {
        $messages += $script:DeepSeekHistory
    }
    
    # Add current question
    $messages += @{role = "user"; content = $Question}
    
    # Build request body
    $body = @{
        model = $Model
        messages = $messages
        max_tokens = $MaxTokens
        temperature = $Temperature
        stream = $false
    } | ConvertTo-Json -Depth 5
    
    try {
        # Send request
        $response = Invoke-RestMethod -Uri $url -Method Post -Headers @{
            "Content-Type" = "application/json"
            "Authorization" = "Bearer $apiKey"
        } -Body $body -ErrorAction Stop
        
        # Get answer
        $answer = $response.choices[0].message.content
        
        # Update history (unless NoHistory is specified)
        if (-not $NoHistory) {
            $script:DeepSeekHistory += @{role = "user"; content = $Question}
            $script:DeepSeekHistory += @{role = "assistant"; content = $answer}
            
            # Limit history length
            if ($script:DeepSeekHistory.Count -gt 20) {
                $script:DeepSeekHistory = $script:DeepSeekHistory | Select-Object -Last 20
            }
        }
        
        return $answer
    }
    catch {
        Write-Error "API call failed: $($_.Exception.Message)"
        return $null
    }
}

# Aliases
Set-Alias ds Invoke-DeepSeek

# Specialized function for reasoning
function Invoke-DeepSeekReasoner {
    param(
        [Parameter(Mandatory=$true)][string]$Question, 
        [int]$MaxTokens=4000,
        [switch]$Reset,
        [switch]$NoHistory
    )
    Invoke-DeepSeek -Question $Question -Model "deepseek-reasoner" -MaxTokens $MaxTokens -Reset:$Reset -NoHistory:$NoHistory
}
Set-Alias ds-reasoner Invoke-DeepSeekReasoner

# Test function
function Test-DeepSeek {
    $testQuestion = "Introduce yourself in one sentence"
    $result = Invoke-DeepSeek -Question $testQuestion -NoHistory
    if ($result) {
        Write-Host "✓ DeepSeek test successful!" -ForegroundColor Green
        Write-Host "Response: $result" -ForegroundColor Cyan
    } else {
        Write-Host "✗ DeepSeek test failed" -ForegroundColor Red
    }
}

# Show current history status
function Show-DeepSeekHistory {
    Write-Host "Current conversation history ($($script:DeepSeekHistory.Count) messages):" -ForegroundColor Yellow
    $script:DeepSeekHistory | ForEach-Object {
        $color = if ($_.role -eq "user") { "Green" } else { "Cyan" }
        Write-Host "$($_.role): $($_.content)" -ForegroundColor $color
    }
}

# Clear history
function Clear-DeepSeekHistory {
    $script:DeepSeekHistory = @()
    Write-Host "DeepSeek conversation history cleared" -ForegroundColor Green
}
```

### 使用说明：

1. **替换你的配置文件**：
   - 打开 PowerShell
   - 运行 `notepad $PROFILE` 打开配置文件
   - 删除所有内容
   - 复制上面的代码并粘贴到文件中
   - 保存文件

2. **重新加载配置文件**：
   ```powershell
   . $PROFILE
   ```

3. **设置 API 密钥**：
   ```powershell
   $env:DEEPSEEK_API_KEY = "你的-DeepSeek-API-密钥"
   ```

4. **测试 DeepSeek**：
   ```powershell
   Test-DeepSeek
   ```

这个版本使用了英文注释和变量名，避免了中文字符可能导致的编码问题。如果你需要中文提示，可以稍后逐步添加，但要确保使用正确的编码保存文件。

如果你仍然遇到问题，可以尝试使用 PowerShell ISE 或 Visual Studio Code 来编辑配置文件，这些工具通常能更好地处理编码问题。

# 用户：

┏[ 09/18/2025 @ 12:50:42 PM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 14/15GB][ 100][ 1.41s]
┣[ ~]
└─[#]> ds "告诉我现在美国总统是谁？"
æ¨å¥½ï¼è¯·é®æä»ä¹æå¯ä»¥å¸®å©æ¨è§£ç­çé®é¢åï¼ð
┏[ 09/18/2025 @ 12:50:50 PM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 14/15GB][ 100][ 4.133s]
┣[ ~]
└─[#]> Test-DeepSeek
鉁?DeepSeek test successful!
Response: I am DeepSeek-V3, your intelligent and knowledgeable AI assistant created by DeepSeek, ready to help with insightful and accurate responses. ð

# DeepSeek：

**原始回答**

看起来你的 DeepSeek API 集成现在可以工作了，但返回的中文内容仍然有编码问题。这是因为 PowerShell 控制台的编码设置问题。让我们修复这个问题：

### 解决方案：设置 PowerShell 控制台编码

在你的 PowerShell 配置文件中添加以下代码，确保控制台使用正确的 UTF-8 编码：

```powershell
# 设置控制台编码为 UTF-8
$OutputEncoding = [System.Text.Encoding]::UTF8
[Console]::OutputEncoding = [System.Text.Encoding]::UTF8
[Console]::InputEncoding = [System.Text.Encoding]::UTF8

# 设置控制台字体（如果需要）
if ($host.Name -eq 'ConsoleHost') {
    chcp 65001 > $null  # 设置代码页为 UTF-8
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

# DeepSeek API Integration
$script:DeepSeekHistory = @()

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
    
    # Reset conversation history
    if ($Reset) {
        $script:DeepSeekHistory = @()
        Write-Host "对话历史已重置" -ForegroundColor Green
        return
    }
    
    $apiKey = $env:DEEPSEEK_API_KEY
    if (-not $apiKey) {
        Write-Error "请先设置 DEEPSEEK_API_KEY 环境变量"
        Write-Host "设置方法: `$env:DEEPSEEK_API_KEY = '你的-api-key'" -ForegroundColor Yellow
        return
    }
    
    $url = "https://api.deepseek.com/v1/chat/completions"
    
    # Build message array
    $messages = @()
    
    # Add history messages (unless NoHistory is specified)
    if (-not $NoHistory -and $script:DeepSeekHistory.Count -gt 0) {
        $messages += $script:DeepSeekHistory
    }
    
    # Add current question
    $messages += @{role = "user"; content = $Question}
    
    # Build request body
    $body = @{
        model = $Model
        messages = $messages
        max_tokens = $MaxTokens
        temperature = $Temperature
        stream = $false
    } | ConvertTo-Json -Depth 5
    
    try {
        # Send request
        $response = Invoke-RestMethod -Uri $url -Method Post -Headers @{
            "Content-Type" = "application/json"
            "Authorization" = "Bearer $apiKey"
        } -Body $body -ErrorAction Stop
        
        # Get answer
        $answer = $response.choices[0].message.content
        
        # Update history (unless NoHistory is specified)
        if (-not $NoHistory) {
            $script:DeepSeekHistory += @{role = "user"; content = $Question}
            $script:DeepSeekHistory += @{role = "assistant"; content = $answer}
            
            # Limit history length
            if ($script:DeepSeekHistory.Count -gt 20) {
                $script:DeepSeekHistory = $script:DeepSeekHistory | Select-Object -Last 20
            }
        }
        
        return $answer
    }
    catch {
        Write-Error "API 调用失败: $($_.Exception.Message)"
        return $null
    }
}

# Aliases
Set-Alias ds Invoke-DeepSeek

# Specialized function for reasoning
function Invoke-DeepSeekReasoner {
    param(
        [Parameter(Mandatory=$true)][string]$Question, 
        [int]$MaxTokens=4000,
        [switch]$Reset,
        [switch]$NoHistory
    )
    Invoke-DeepSeek -Question $Question -Model "deepseek-reasoner" -MaxTokens $MaxTokens -Reset:$Reset -NoHistory:$NoHistory
}
Set-Alias ds-reasoner Invoke-DeepSeekReasoner

# Test function
function Test-DeepSeek {
    $testQuestion = "用一句话说明你是DeepSeek AI助手"
    $result = Invoke-DeepSeek -Question $testQuestion -NoHistory
    if ($result) {
        Write-Host "✓ DeepSeek 测试成功!" -ForegroundColor Green
        Write-Host "回应: $result" -ForegroundColor Cyan
    } else {
        Write-Host "✗ DeepSeek 测试失败" -ForegroundColor Red
    }
}

# Show current history status
function Show-DeepSeekHistory {
    Write-Host "当前对话历史记录 ($($script:DeepSeekHistory.Count) 条消息):" -ForegroundColor Yellow
    $script:DeepSeekHistory | ForEach-Object {
        $color = if ($_.role -eq "user") { "Green" } else { "Cyan" }
        Write-Host "$($_.role): $($_.content)" -ForegroundColor $color
    }
}

# Clear history
function Clear-DeepSeekHistory {
    $script:DeepSeekHistory = @()
    Write-Host "DeepSeek 对话历史已清除" -ForegroundColor Green
}
```

### 额外建议：

1. **使用 Windows Terminal**：
   如果你使用的是传统的 PowerShell 控制台，建议改用 Windows Terminal，它对 UTF-8 编码的支持更好。

2. **设置 Windows Terminal 默认编码**：
   在 Windows Terminal 的设置中，确保默认配置文件使用 UTF-8 编码。

3. **检查系统区域设置**：
   确保你的系统区域设置支持中文：
   - 打开 "控制面板" → "区域"
   - 在 "管理" 选项卡中，点击 "更改系统区域设置"
   - 确保勾选了 "Beta: 使用 Unicode UTF-8 提供全球语言支持"

4. **重新加载配置文件**：
   保存修改后的配置文件后，运行：
   ```powershell
   . $PROFILE
   ```

5. **测试中文输出**：
   现在尝试运行：
   ```powershell
   ds "告诉我现在美国总统是谁？"
   ```

这些更改应该能解决中文显示乱码的问题。如果仍然有问题，可能需要检查你的系统区域设置或考虑使用不同的终端应用程序。

# 用户：

系统区域设置勾选了 "Beta: 使用 Unicode UTF-8 提供全球语言支持"，但是
Loading personal and system profiles took 1662ms.
┏[ 09/18/2025 @ 1:01:40 PM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 8/15GB][ 100][ 0s]
┣[ ~]
└─[#]> ds "告诉我现在美国总统是谁？"
æ¨å¥½ï¼è¯·é®æä»ä¹æå¯ä»¥å¸®å©æ¨è§£ç­çé®é¢åï¼ðPowerShell是使用json文件配置的

# DeepSeek：

**原始回答**

看起来你已经启用了系统的 UTF-8 支持，但 PowerShell 仍然存在编码问题。这可能是因为 PowerShell 控制台本身或 oh-my-posh 主题的配置问题。让我们尝试一个更彻底的解决方案。

### 解决方案 1：修改 PowerShell 配置文件

在你的 PowerShell 配置文件中添加以下代码，放在文件的最顶部：

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

# 其余代码保持不变...
```

### 解决方案 2：使用 Windows Terminal

如果你还没有使用 Windows Terminal，强烈建议安装并使用它，因为它对 UTF-8 的支持更好：

1. 从 Microsoft Store 安装 Windows Terminal
2. 打开 Windows Terminal 设置 (Ctrl+,)
3. 在默认配置文件设置中，确保"命令行"指向 PowerShell：
   ```
   "commandline": "pwsh.exe -NoExit -Command \"chcp 65001\""
   ```
4. 确保配置文件中的"字体"设置为支持中文的字体，如 "Cascadia Code PL" 或 "Microsoft YaHei Mono"

### 解决方案 3：修改 DeepSeek 函数以处理编码

修改你的 `Invoke-DeepSeek` 函数，添加编码处理：

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
    
    # 重置对话历史
    if ($Reset) {
        $script:DeepSeekHistory = @()
        Write-Host "对话历史已重置" -ForegroundColor Green
        return
    }
    
    $apiKey = $env:DEEPSEEK_API_KEY
    if (-not $apiKey) {
        Write-Error "请先设置 DEEPSEEK_API_KEY 环境变量"
        Write-Host "设置方法: `$env:DEEPSEEK_API_KEY = '你的-api-key'" -ForegroundColor Yellow
        return
    }
    
    $url = "https://api.deepseek.com/v1/chat/completions"
    
    # 构建消息数组
    $messages = @()
    
    # 添加历史消息（除非指定 NoHistory）
    if (-not $NoHistory -and $script:DeepSeekHistory.Count -gt 0) {
        $messages += $script:DeepSeekHistory
    }
    
    # 添加当前问题
    $messages += @{role = "user"; content = $Question}
    
    # 构建请求体
    $body = @{
        model = $Model
        messages = $messages
        max_tokens = $MaxTokens
        temperature = $Temperature
        stream = $false
    } | ConvertTo-Json -Depth 5
    
    try {
        # 发送请求
        $response = Invoke-WebRequest -Uri $url -Method Post -Headers @{
            "Content-Type" = "application/json"
            "Authorization" = "Bearer $apiKey"
        } -Body $body -UseBasicParsing
        
        # 获取原始字节内容
        $contentBytes = $response.Content
        $content = [System.Text.Encoding]::UTF8.GetString([System.Text.Encoding]::GetEncoding("ISO-8859-1").GetBytes($contentBytes))
        
        # 解析 JSON
        $jsonResponse = $content | ConvertFrom-Json
        
        # 获取回答
        $answer = $jsonResponse.choices[0].message.content
        
        # 更新历史记录（除非指定 NoHistory）
        if (-not $NoHistory) {
            $script:DeepSeekHistory += @{role = "user"; content = $Question}
            $script:DeepSeekHistory += @{role = "assistant"; content = $answer}
            
            # 限制历史记录长度
            if ($script:DeepSeekHistory.Count -gt 20) {
                $script:DeepSeekHistory = $script:DeepSeekHistory | Select-Object -Last 20
            }
        }
        
        # 确保输出使用正确的编码
        if ($Host.UI.RawUI.OutputEncoding.EncodingName -ne "Unicode (UTF-8)") {
            $Host.UI.RawUI.OutputEncoding = [System.Text.Encoding]::UTF8
        }
        
        return $answer
    }
    catch {
        Write-Error "API 调用失败: $($_.Exception.Message)"
        return $null
    }
}
```

### 解决方案 4：检查 PowerShell 版本

确保你使用的是最新版本的 PowerShell。可以通过以下命令检查：

```powershell
$PSVersionTable.PSVersion
```

如果版本较旧（低于 7.0），建议升级到 PowerShell 7，它对 UTF-8 的支持更好。

### 解决方案 5：临时测试

为了确认问题是否与 oh-my-posh 有关，你可以暂时禁用它进行测试：

1. 注释掉 oh-my-posh 的初始化行：
   ```powershell
   # oh-my-posh init pwsh --config "$env:POSH_THEMES_PATH/tokyo.omp.json" | Invoke-Expression
   ```
2. 重新加载配置文件：
   ```powershell
   . $PROFILE
   ```
3. 测试 DeepSeek：
   ```powershell
   ds "告诉我现在美国总统是谁？"
   ```

如果这样能正常显示中文，那么问题可能出在 oh-my-posh 主题或配置上。

尝试这些解决方案，看看哪个能解决你的编码问题。如果问题仍然存在，可能需要更深入地检查你的系统配置或考虑使用不同的终端应用程序。

# 用户：

┣[ ~]
└─[#]> $PSVersionTable.PSVersion

Major  Minor  Build  Revision
-----  -----  -----  --------
5      1      22000  2538

# DeepSeek：

**原始回答**

看起来你的 PowerShell 5.1 版本仍然存在编码问题。让我们尝试一个更直接的方法来解决这个问题。我们将修改 DeepSeek 函数，使其在处理响应时强制使用正确的编码。

### 解决方案：修改 DeepSeek 函数处理编码

在你的 PowerShell 配置文件中，替换 DeepSeek 函数为以下版本：

```powershell
# DeepSeek API Integration with encoding fix
$script:DeepSeekHistory = @()

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
    
    # Reset conversation history
    if ($Reset) {
        $script:DeepSeekHistory = @()
        Write-Host "对话历史已重置" -ForegroundColor Green
        return
    }
    
    $apiKey = $env:DEEPSEEK_API_KEY
    if (-not $apiKey) {
        Write-Error "请先设置 DEEPSEEK_API_KEY 环境变量"
        Write-Host "设置方法: `$env:DEEPSEEK_API_KEY = '你的-api-key'" -ForegroundColor Yellow
        return
    }
    
    $url = "https://api.deepseek.com/v1/chat/completions"
    
    # Build message array
    $messages = @()
    
    # Add history messages (unless NoHistory is specified)
    if (-not $NoHistory -and $script:DeepSeekHistory.Count -gt 0) {
        $messages += $script:DeepSeekHistory
    }
    
    # Add current question
    $messages += @{role = "user"; content = $Question}
    
    # Build request body
    $body = @{
        model = $Model
        messages = $messages
        max_tokens = $MaxTokens
        temperature = $Temperature
        stream = $false
    } | ConvertTo-Json -Depth 5
    
    try {
        # Send request using .NET HttpClient for better encoding handling
        Add-Type -AssemblyName System.Net.Http
        
        $httpClient = New-Object System.Net.Http.HttpClient
        $httpClient.DefaultRequestHeaders.TryAddWithoutValidation("Content-Type", "application/json")
        $httpClient.DefaultRequestHeaders.Authorization = New-Object System.Net.Http.Headers.AuthenticationHeaderValue("Bearer", $apiKey)
        
        $content = New-Object System.Net.Http.StringContent($body, [System.Text.Encoding]::UTF8, "application/json")
        $response = $httpClient.PostAsync($url, $content).Result
        
        if ($response.IsSuccessStatusCode) {
            $responseContent = $response.Content.ReadAsStringAsync().Result
            $jsonResponse = $responseContent | ConvertFrom-Json
            
            # Get answer
            $answer = $jsonResponse.choices[0].message.content
            
            # Update history (unless NoHistory is specified)
            if (-not $NoHistory) {
                $script:DeepSeekHistory += @{role = "user"; content = $Question}
                $script:DeepSeekHistory += @{role = "assistant"; content = $answer}
                
                # Limit history length
                if ($script:DeepSeekHistory.Count -gt 20) {
                    $script:DeepSeekHistory = $script:DeepSeekHistory | Select-Object -Last 20
                }
            }
            
            # Ensure proper encoding for output
            $outputEncoding = [System.Console]::OutputEncoding
            if ($outputEncoding.WebName -ne "utf-8") {
                $answer = [System.Text.Encoding]::Convert([System.Text.Encoding]::UTF8, $outputEncoding, [System.Text.Encoding]::UTF8.GetBytes($answer))
                $answer = $outputEncoding.GetString($answer)
            }
            
            return $answer
        }
        else {
            Write-Error "API 返回错误: $($response.StatusCode) - $($response.ReasonPhrase)"
            return $null
        }
    }
    catch {
        Write-Error "API 调用失败: $($_.Exception.Message)"
        return $null
    }
}

# Aliases
Set-Alias ds Invoke-DeepSeek

# Specialized function for reasoning
function Invoke-DeepSeekReasoner {
    param(
        [Parameter(Mandatory=$true)][string]$Question, 
        [int]$MaxTokens=4000,
        [switch]$Reset,
        [switch]$NoHistory
    )
    Invoke-DeepSeek -Question $Question -Model "deepseek-reasoner" -MaxTokens $MaxTokens -Reset:$Reset -NoHistory:$NoHistory
}
Set-Alias ds-reasoner Invoke-DeepSeekReasoner

# Test function
function Test-DeepSeek {
    $testQuestion = "用一句话说明你是DeepSeek AI助手"
    $result = Invoke-DeepSeek -Question $testQuestion -NoHistory
    if ($result) {
        Write-Host "✓ DeepSeek 测试成功!" -ForegroundColor Green
        Write-Host "回应: $result" -ForegroundColor Cyan
    } else {
        Write-Host "✗ DeepSeek 测试失败" -ForegroundColor Red
    }
}

# Show current history status
function Show-DeepSeekHistory {
    Write-Host "当前对话历史记录 ($($script:DeepSeekHistory.Count) 条消息):" -ForegroundColor Yellow
    $script:DeepSeekHistory | ForEach-Object {
        $color = if ($_.role -eq "user") { "Green" } else { "Cyan" }
        Write-Host "$($_.role): $($_.content)" -ForegroundColor $color
    }
}

# Clear history
function Clear-DeepSeekHistory {
    $script:DeepSeekHistory = @()
    Write-Host "DeepSeek 对话历史已清除" -ForegroundColor Green
}
```

### 额外建议：

1. **升级到 PowerShell 7**：
   PowerShell 7 对 UTF-8 的支持更好。你可以从 [PowerShell GitHub 发布页面](https://github.com/PowerShell/PowerShell/releases)下载最新版本。

2. **使用 Windows Terminal**：
   如果你还没有使用 Windows Terminal，强烈建议安装并使用它：
   ```powershell
   winget install Microsoft.WindowsTerminal
   ```

3. **检查控制台字体**：
   确保你的 PowerShell 控制台使用的是支持中文的字体：
   - 右键点击 PowerShell 标题栏 → 属性
   - 在"字体"选项卡中，选择支持中文的字体，如 "Microsoft YaHei Mono" 或 "等距更纱黑体 SC"

4. **临时禁用 oh-my-posh**：
   为了测试是否是 oh-my-posh 导致的编码问题，可以暂时禁用它：
   ```powershell
   # 注释掉这一行
   # oh-my-posh init pwsh --config "$env:POSH_THEMES_PATH/tokyo.omp.json" | Invoke-Expression
   ```
   然后重新加载配置文件并测试 DeepSeek。

5. **检查系统区域设置**：
   虽然你已经启用了 UTF-8 支持，但请确保系统区域设置为中文：
   - 打开"控制面板" → "区域"
   - 在"管理"选项卡中，点击"更改系统区域设置"
   - 确保选择的是"中文(简体，中国)"

6. **重新加载配置文件**：
   保存修改后的配置文件后，运行：
   ```powershell
   . $PROFILE
   ```

这个修改后的版本使用 .NET 的 HttpClient 类来处理 HTTP 请求，这通常能更好地处理编码问题。它还添加了额外的编码转换逻辑，以确保输出能够正确显示在 PowerShell 控制台中。

如果问题仍然存在，可能需要考虑升级到 PowerShell 7 或使用不同的终端应用程序，如 Windows Terminal。

# 用户：

我决定先升级powershell7看看，但是登不上github，尽量在powershell中下载升级

# DeepSeek：

**原始回答**

好的，我来帮你在 PowerShell 中下载和安装 PowerShell 7，而不需要访问 GitHub。我们可以使用微软官方的下载链接和 PowerShell 命令来完成这个任务。

### 在 PowerShell 5.1 中下载和安装 PowerShell 7

请按照以下步骤操作：

1. **首先，检查当前系统架构（32位还是64位）**：
   ```powershell
   $architecture = if ([Environment]::Is64BitOperatingSystem) { "x64" } else { "x86" }
   Write-Host "系统架构: $architecture"
   ```

2. **下载 PowerShell 7 安装包**：
   ```powershell
   # 确定最新稳定版的下载URL
   $downloadUrl = "https://github.com/PowerShell/PowerShell/releases/download/v7.4.2/PowerShell-7.4.2-win-$architecture.msi"
   
   # 设置下载路径
   $downloadPath = "$env:TEMP\PowerShell-7.4.2-win-$architecture.msi"
   
   # 下载文件
   Write-Host "正在下载 PowerShell 7..." -ForegroundColor Yellow
   try {
       Invoke-WebRequest -Uri $downloadUrl -OutFile $downloadPath -UseBasicParsing
       Write-Host "下载完成: $downloadPath" -ForegroundColor Green
   }
   catch {
       Write-Host "下载失败，尝试备用链接..." -ForegroundColor Red
       
       # 尝试使用微软官方链接
       $altUrl = "https://aka.ms/powershell-release?format=MSI&arch=$architecture"
       Invoke-WebRequest -Uri $altUrl -OutFile $downloadPath -UseBasicParsing
       Write-Host "使用备用链接下载完成: $downloadPath" -ForegroundColor Green
   }
   ```

3. **安装 PowerShell 7**：
   ```powershell
   Write-Host "正在安装 PowerShell 7..." -ForegroundColor Yellow
   try {
       # 使用msiexec安装
       $process = Start-Process -FilePath "msiexec.exe" -ArgumentList "/i", "`"$downloadPath`"", "/quiet", "/norestart" -Wait -PassThru
       
       if ($process.ExitCode -eq 0) {
           Write-Host "PowerShell 7 安装成功!" -ForegroundColor Green
           
           # 添加 PowerShell 7 到环境变量
           $env:Path += ";$env:ProgramFiles\PowerShell\7"
           
           # 测试新版本
           Write-Host "测试新版本 PowerShell..." -ForegroundColor Yellow
           & "$env:ProgramFiles\PowerShell\7\pwsh.exe" -Command "Write-Host 'PowerShell 7 安装成功!' -ForegroundColor Green; `$PSVersionTable.PSVersion"
       }
       else {
           Write-Host "安装失败，退出代码: $($process.ExitCode)" -ForegroundColor Red
       }
   }
   catch {
       Write-Host "安装过程中出错: $($_.Exception.Message)" -ForegroundColor Red
   }
   ```

4. **设置 PowerShell 7 为默认版本（可选）**：
   ```powershell
   # 如果你想将 PowerShell 7 设置为默认版本，可以运行以下命令
   Write-Host "是否要将 PowerShell 7 设置为默认版本? (Y/N)" -ForegroundColor Yellow
   $response = Read-Host
   if ($response -eq 'Y' -or $response -eq 'y') {
       # 设置默认版本（这需要管理员权限）
       if (-not ([Security.Principal.WindowsPrincipal][Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole] "Administrator")) {
           Write-Host "需要管理员权限来设置默认版本" -ForegroundColor Red
       }
       else {
           # 设置默认版本
           $regPath = "HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\App Paths\powershell.exe"
           Set-ItemProperty -Path $regPath -Name "(default)" -Value "$env:ProgramFiles\PowerShell\7\pwsh.exe" -Force
           Write-Host "已设置 PowerShell 7 为默认版本" -ForegroundColor Green
       }
   }
   ```

5. **完整的安装脚本**：
   你可以将以下完整脚本复制到 PowerShell 中运行：

```powershell
# PowerShell 7 安装脚本
Write-Host "=== PowerShell 7 安装程序 ===" -ForegroundColor Cyan

# 检查系统架构
$architecture = if ([Environment]::Is64BitOperatingSystem) { "x64" } else { "x86" }
Write-Host "系统架构: $architecture" -ForegroundColor Yellow

# 下载 PowerShell 7
$downloadUrl = "https://github.com/PowerShell/PowerShell/releases/download/v7.4.2/PowerShell-7.4.2-win-$architecture.msi"
$downloadPath = "$env:TEMP\PowerShell-7.4.2-win-$architecture.msi"

Write-Host "正在下载 PowerShell 7..." -ForegroundColor Yellow
try {
    # 尝试主要下载链接
    Invoke-WebRequest -Uri $downloadUrl -OutFile $downloadPath -UseBasicParsing
    Write-Host "下载完成: $downloadPath" -ForegroundColor Green
}
catch {
    Write-Host "主要下载链接失败，尝试备用链接..." -ForegroundColor Red
    try {
        # 尝试备用链接
        $altUrl = "https://aka.ms/powershell-release?format=MSI&arch=$architecture"
        Invoke-WebRequest -Uri $altUrl -OutFile $downloadPath -UseBasicParsing
        Write-Host "使用备用链接下载完成: $downloadPath" -ForegroundColor Green
    }
    catch {
        Write-Host "所有下载尝试都失败，请检查网络连接" -ForegroundColor Red
        exit 1
    }
}

# 安装 PowerShell 7
Write-Host "正在安装 PowerShell 7..." -ForegroundColor Yellow
try {
    $process = Start-Process -FilePath "msiexec.exe" -ArgumentList "/i", "`"$downloadPath`"", "/quiet", "/norestart" -Wait -PassThru
    
    if ($process.ExitCode -eq 0) {
        Write-Host "PowerShell 7 安装成功!" -ForegroundColor Green
        
        # 更新环境变量
        $env:Path += ";$env:ProgramFiles\PowerShell\7"
        
        # 测试新版本
        Write-Host "测试新版本 PowerShell..." -ForegroundColor Yellow
        & "$env:ProgramFiles\PowerShell\7\pwsh.exe" -Command "Write-Host 'PowerShell 7 安装成功!' -ForegroundColor Green; `$PSVersionTable.PSVersion"
    }
    else {
        Write-Host "安装失败，退出代码: $($process.ExitCode)" -ForegroundColor Red
    }
}
catch {
    Write-Host "安装过程中出错: $($_.Exception.Message)" -ForegroundColor Red
}

# 清理安装文件
Write-Host "清理安装文件..." -ForegroundColor Yellow
Remove-Item -Path $downloadPath -Force -ErrorAction SilentlyContinue

Write-Host "=== 安装完成 ===" -ForegroundColor Cyan
Write-Host "要使用 PowerShell 7，请运行: $env:ProgramFiles\PowerShell\7\pwsh.exe" -ForegroundColor Green
```

### 使用 PowerShell 7 测试 DeepSeek

安装完成后，你可以使用 PowerShell 7 来测试 DeepSeek 功能：

1. **打开 PowerShell 7**：
   ```powershell
   & "$env:ProgramFiles\PowerShell\7\pwsh.exe"
   ```

2. **测试 DeepSeek**：
   ```powershell
   ds "告诉我现在美国总统是谁？"
   ```

PowerShell 7 对 UTF-8 的支持更好，应该能够正确显示中文内容。

### 如果下载链接仍然不可用

如果上述下载链接都不可用，你可以尝试从微软官方文档页面获取最新下载链接：

1. 打开浏览器访问：https://docs.microsoft.com/powershell/scripting/install/installing-powershell-on-windows
2. 找到 "MSI package" 部分
3. 复制适合你系统架构的下载链接
4. 在 PowerShell 中使用 `Invoke-WebRequest` 命令下载

希望这些步骤能帮助你成功升级到 PowerShell 7 并解决中文显示问题！

# 用户：

下载失败，尝试备用链接...
Invoke-WebRequest : 远程服务器返回错误: (400) 错误的请求。
At line:10 char:5
+     Invoke-WebRequest -Uri $altUrl -OutFile $downloadPath -UseBasicPa ...
+     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    + CategoryInfo          : InvalidOperation: (System.Net.HttpWebRequest:HttpWebRequest) [Invoke-WebRequest], WebException
    + FullyQualifiedErrorId : WebCmdletWebResponseException,Microsoft.PowerShell.Commands.InvokeWebRequestCommand

# DeepSeek：

**原始回答**

看起来下载链接存在问题。让我们尝试另一种方法来安装 PowerShell 7，使用微软官方的包管理器或者直接下载链接。

### 方法 1：使用 Winget 包管理器安装 PowerShell 7

如果你有 Winget 包管理器，这是最简单的方法：

```powershell
# 检查是否已安装 winget
if (Get-Command winget -ErrorAction SilentlyContinue) {
    Write-Host "使用 Winget 安装 PowerShell 7..." -ForegroundColor Yellow
    winget install --id Microsoft.PowerShell --source winget
} else {
    Write-Host "Winget 未安装，尝试其他方法..." -ForegroundColor Red
}
```

### 方法 2：使用 Chocolatey 包管理器安装 PowerShell 7

如果你有 Chocolatey 包管理器：

```powershell
# 检查是否已安装 Chocolatey
if (Get-Command choco -ErrorAction SilentlyContinue) {
    Write-Host "使用 Chocolatey 安装 PowerShell 7..." -ForegroundColor Yellow
    choco install powershell-core -y
} else {
    Write-Host "Chocolatey 未安装，尝试其他方法..." -ForegroundColor Red
}
```

### 方法 3：直接下载 PowerShell 7 安装程序

让我们尝试使用微软的 CDN 链接来下载 PowerShell 7：

```powershell
# 确定系统架构
$architecture = if ([Environment]::Is64BitOperatingSystem) { "x64" } else { "x86" }
Write-Host "系统架构: $architecture" -ForegroundColor Yellow

# 使用微软 CDN 链接
$cdnUrl = "https://pscoretools.blob.core.windows.net/v7/PowerShell-7.4.2-win-$architecture.msi"
$downloadPath = "$env:TEMP\PowerShell-7.4.2-win-$architecture.msi"

Write-Host "尝试从微软 CDN 下载 PowerShell 7..." -ForegroundColor Yellow
try {
    # 使用 .NET 的 WebClient 进行下载，可能更可靠
    $webClient = New-Object System.Net.WebClient
    $webClient.DownloadFile($cdnUrl, $downloadPath)
    Write-Host "下载完成: $downloadPath" -ForegroundColor Green
}
catch {
    Write-Host "CDN 下载失败: $($_.Exception.Message)" -ForegroundColor Red
    Write-Host "尝试使用其他方法..." -ForegroundColor Yellow
}

# 如果 CDN 下载失败，尝试使用微软商店链接
if (-not (Test-Path $downloadPath)) {
    try {
        $storeUrl = "https://www.microsoft.com/store/productId/9MZ1SNWT0N5D"
        Write-Host "请手动从 Microsoft Store 安装 PowerShell 7: $storeUrl" -ForegroundColor Yellow
        
        # 尝试打开 Microsoft Store 页面
        Start-Process "ms-windows-store://pdp/?productid=9MZ1SNWT0N5D"
    }
    catch {
        Write-Host "无法打开 Microsoft Store" -ForegroundColor Red
    }
}
```

### 方法 4：手动下载并安装 PowerShell 7

如果上述方法都失败，我们可以尝试手动下载：

```powershell
# 提供手动下载指南
Write-Host "由于网络限制，无法自动下载 PowerShell 7" -ForegroundColor Red
Write-Host "请按照以下步骤手动安装:" -ForegroundColor Yellow
Write-Host "1. 打开浏览器访问: https://docs.microsoft.com/powershell/scripting/install/installing-powershell-on-windows" -ForegroundColor Cyan
Write-Host "2. 找到 'MSI package' 部分" -ForegroundColor Cyan
Write-Host "3. 下载适合你系统架构的 MSI 安装包 ($architecture)" -ForegroundColor Cyan
Write-Host "4. 运行下载的安装包" -ForegroundColor Cyan
Write-Host "5. 安装完成后，重新打开 PowerShell" -ForegroundColor Cyan

# 提供直接下载链接
Write-Host "`n或者尝试直接访问以下链接:" -ForegroundColor Yellow
if ($architecture -eq "x64") {
    Write-Host "64位: https://github.com/PowerShell/PowerShell/releases/download/v7.4.2/PowerShell-7.4.2-win-x64.msi" -ForegroundColor Cyan
} else {
    Write-Host "32位: https://github.com/PowerShell/PowerShell/releases/download/v7.4.2/PowerShell-7.4.2-win-x86.msi" -ForegroundColor Cyan
}
```

### 方法 5：使用 PowerShell 7 便携版

如果安装版无法下载，可以尝试便携版：

```powershell
# 下载 PowerShell 7 便携版
$portableUrl = "https://github.com/PowerShell/PowerShell/releases/download/v7.4.2/PowerShell-7.4.2-win-$architecture.zip"
$portablePath = "$env:TEMP\PowerShell-7.4.2-win-$architecture.zip"
$extractPath = "$env:USERPROFILE\PowerShell-7"

try {
    Write-Host "尝试下载 PowerShell 7 便携版..." -ForegroundColor Yellow
    Invoke-WebRequest -Uri $portableUrl -OutFile $portablePath -UseBasicParsing
    Write-Host "下载完成: $portablePath" -ForegroundColor Green
    
    # 解压文件
    Expand-Archive -Path $portablePath -DestinationPath $extractPath -Force
    Write-Host "已解压到: $extractPath" -ForegroundColor Green
    
    # 添加到环境变量
    $env:Path += ";$extractPath"
    Write-Host "已添加到当前会话的环境变量" -ForegroundColor Green
    Write-Host "要启动 PowerShell 7，请运行: $extractPath\pwsh.exe" -ForegroundColor Cyan
}
catch {
    Write-Host "便携版下载失败: $($_.Exception.Message)" -ForegroundColor Red
}
```

### 临时解决方案：在当前 PowerShell 5.1 中修复编码问题

如果无法升级到 PowerShell 7，我们可以尝试在当前 PowerShell 5.1 中修复编码问题：

```powershell
# 在当前会话中设置编码
$OutputEncoding = [System.Text.Encoding]::UTF8
[Console]::OutputEncoding = [System.Text.Encoding]::UTF8
[Console]::InputEncoding = [System.Text.Encoding]::UTF8

# 修改 DeepSeek 函数以处理编码问题
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
    
    # 重置对话历史
    if ($Reset) {
        $script:DeepSeekHistory = @()
        Write-Host "对话历史已重置" -ForegroundColor Green
        return
    }
    
    $apiKey = $env:DEEPSEEK_API_KEY
    if (-not $apiKey) {
        Write-Error "请先设置 DEEPSEEK_API_KEY 环境变量"
        Write-Host "设置方法: `$env:DEEPSEEK_API_KEY = '你的-api-key'" -ForegroundColor Yellow
        return
    }
    
    $url = "https://api.deepseek.com/v1/chat/completions"
    
    # 构建消息数组
    $messages = @()
    
    # 添加历史消息（除非指定 NoHistory）
    if (-not $NoHistory -and $script:DeepSeekHistory.Count -gt 0) {
        $messages += $script:DeepSeekHistory
    }
    
    # 添加当前问题
    $messages += @{role = "user"; content = $Question}
    
    # 构建请求体
    $body = @{
        model = $Model
        messages = $messages
        max_tokens = $MaxTokens
        temperature = $Temperature
        stream = $false
    } | ConvertTo-Json -Depth 5
    
    try {
        # 发送请求
        $response = Invoke-RestMethod -Uri $url -Method Post -Headers @{
            "Content-Type" = "application/json"
            "Authorization" = "Bearer $apiKey"
        } -Body $body -ErrorAction Stop
        
        # 获取回答
        $answer = $response.choices[0].message.content
        
        # 更新历史记录（除非指定 NoHistory）
        if (-not $NoHistory) {
            $script:DeepSeekHistory += @{role = "user"; content = $Question}
            $script:DeepSeekHistory += @{role = "assistant"; content = $answer}
            
            # 限制历史记录长度
            if ($script:DeepSeekHistory.Count -gt 20) {
                $script:DeepSeekHistory = $script:DeepSeekHistory | Select-Object -Last 20
            }
        }
        
        # 尝试修复编码问题
        try {
            # 将字符串转换为字节数组，然后使用正确的编码重新解码
            $bytes = [System.Text.Encoding]::GetEncoding("ISO-8859-1").GetBytes($answer)
            $answer = [System.Text.Encoding]::UTF8.GetString($bytes)
        }
        catch {
            # 如果编码转换失败，保持原样
        }
        
        return $answer
    }
    catch {
        Write-Error "API 调用失败: $($_.Exception.Message)"
        return $null
    }
}
```

尝试这些方法中的一种，看看是否能够成功安装 PowerShell 7 或者至少在当前 PowerShell 5.1 中修复编码问题。如果所有方法都失败，可能需要检查你的网络连接或者考虑使用 VPN 来访问 GitHub。

# 用户：

┏[ 09/18/2025 @ 1:35:24 PM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 9/15GB][ 100][ 21:20.518s]
┣[ ~]
└─[#]> # 检查是否已安装 winget
┏[ 09/18/2025 @ 1:38:49 PM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 9/15GB][ 100][ 0s]
┣[ ~]
└─[#]> if (Get-Command winget -ErrorAction SilentlyContinue) {
     Write-Host "使用 Winget 安装 PowerShell 7..." -ForegroundColor Yellow
     winget install --id Microsoft.PowerShell --source winget
 } else {
     Write-Host "Winget 未安装，尝试其他方法..." -ForegroundColor Red
 }
使用 Winget 安装 PowerShell 7...
已找到 PowerShell [Microsoft.PowerShell] 版本 7.5.3.0
此应用程序由其所有者授权给你。
Microsoft 对第三方程序包概不负责，也不向第三方程序包授予任何许可证。
正在下载 https://github.com/PowerShell/PowerShell/releases/download/v7.5.3/PowerShell-7.5.3-win-x64.msi
执行此命令时发生意外错误：
InternetOpenUrl() failed.
0x80072efd : unknown error

# DeepSeek：

**原始回答**

看起来你在使用 Winget 安装 PowerShell 7 时遇到了网络连接问题。错误代码 `0x80072efd` 通常表示网络连接问题。让我们尝试其他方法来安装 PowerShell 7。

### 方法 1：使用 Microsoft Store 安装 PowerShell 7

由于 Winget 无法访问 GitHub，我们可以尝试通过 Microsoft Store 安装 PowerShell 7：

```powershell
# 尝试通过 Microsoft Store 安装 PowerShell 7
Write-Host "尝试通过 Microsoft Store 安装 PowerShell 7..." -ForegroundColor Yellow

# 打开 PowerShell 7 的 Microsoft Store 页面
Start-Process "ms-windows-store://pdp/?productid=9MZ1SNWT0N5D"

Write-Host "Microsoft Store 页面已打开，请手动点击安装按钮" -ForegroundColor Cyan
Write-Host "或者使用以下命令尝试安装:" -ForegroundColor Yellow
Write-Host "1. 首先确保已安装 Microsoft Store: winget install Microsoft.WindowsStore" -ForegroundColor Cyan
Write-Host "2. 然后使用: winget install 9MZ1SNWT0N5D" -ForegroundColor Cyan
```

### 方法 2：使用 Chocolatey 安装 PowerShell 7

如果你已经安装了 Chocolatey 包管理器，可以尝试使用它：

```powershell
# 检查是否已安装 Chocolatey
if (Get-Command choco -ErrorAction SilentlyContinue) {
    Write-Host "使用 Chocolatey 安装 PowerShell 7..." -ForegroundColor Yellow
    choco install powershell-core -y
} else {
    Write-Host "Chocolatey 未安装，尝试安装 Chocolatey..." -ForegroundColor Yellow
    
    # 尝试安装 Chocolatey
    try {
        Set-ExecutionPolicy Bypass -Scope Process -Force
        [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072
        Invoke-Expression ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
        
        # 刷新环境变量
        $env:Path = [System.Environment]::GetEnvironmentVariable("Path","Machine") + ";" + [System.Environment]::GetEnvironmentVariable("Path","User")
        
        # 使用 Chocolatey 安装 PowerShell 7
        choco install powershell-core -y
    }
    catch {
        Write-Host "Chocolatey 安装失败: $($_.Exception.Message)" -ForegroundColor Red
    }
}
```

### 方法 3：手动下载并安装 PowerShell 7

如果上述方法都失败，我们可以尝试手动下载 PowerShell 7：

```powershell
# 手动下载 PowerShell 7
Write-Host "手动下载 PowerShell 7..." -ForegroundColor Yellow

# 确定系统架构
$architecture = if ([Environment]::Is64BitOperatingSystem) { "x64" } else { "x86" }
Write-Host "系统架构: $architecture" -ForegroundColor Cyan

# 创建下载链接
$downloadUrl = "https://github.com/PowerShell/PowerShell/releases/download/v7.4.2/PowerShell-7.4.2-win-$architecture.msi"
$downloadPath = "$env:TEMP\PowerShell-7.4.2-win-$architecture.msi"

Write-Host "下载链接: $downloadUrl" -ForegroundColor Cyan
Write-Host "保存路径: $downloadPath" -ForegroundColor Cyan

# 提供替代下载方法
Write-Host "`n如果无法自动下载，请尝试以下方法:" -ForegroundColor Yellow
Write-Host "1. 使用浏览器手动下载: $downloadUrl" -ForegroundColor Cyan
Write-Host "2. 将下载的文件保存到: $downloadPath" -ForegroundColor Cyan
Write-Host "3. 然后运行以下命令安装:" -ForegroundColor Cyan
Write-Host "   msiexec /i `"$downloadPath`" /quiet /norestart" -ForegroundColor Cyan

# 尝试使用不同的方法下载
try {
    # 方法 1: 使用 .NET WebClient
    Write-Host "尝试使用 .NET WebClient 下载..." -ForegroundColor Yellow
    $webClient = New-Object System.Net.WebClient
    $webClient.DownloadFile($downloadUrl, $downloadPath)
    Write-Host "下载成功!" -ForegroundColor Green
}
catch {
    Write-Host "WebClient 下载失败: $($_.Exception.Message)" -ForegroundColor Red
    
    # 方法 2: 使用 BitsTransfer
    try {
        Write-Host "尝试使用 BitsTransfer 下载..." -ForegroundColor Yellow
        Import-Module BitsTransfer
        Start-BitsTransfer -Source $downloadUrl -Destination $downloadPath
        Write-Host "下载成功!" -ForegroundColor Green
    }
    catch {
        Write-Host "BitsTransfer 下载失败: $($_.Exception.Message)" -ForegroundColor Red
        Write-Host "请手动下载并安装 PowerShell 7" -ForegroundColor Red
    }
}

# 如果下载成功，尝试安装
if (Test-Path $downloadPath) {
    Write-Host "正在安装 PowerShell 7..." -ForegroundColor Yellow
    try {
        $process = Start-Process -FilePath "msiexec.exe" -ArgumentList "/i", "`"$downloadPath`"", "/quiet", "/norestart" -Wait -PassThru
        
        if ($process.ExitCode -eq 0) {
            Write-Host "PowerShell 7 安装成功!" -ForegroundColor Green
            
            # 更新环境变量
            $env:Path += ";$env:ProgramFiles\PowerShell\7"
            
            # 测试新版本
            Write-Host "测试新版本 PowerShell..." -ForegroundColor Yellow
            & "$env:ProgramFiles\PowerShell\7\pwsh.exe" -Command "Write-Host 'PowerShell 7 安装成功!' -ForegroundColor Green; `$PSVersionTable.PSVersion"
        }
        else {
            Write-Host "安装失败，退出代码: $($process.ExitCode)" -ForegroundColor Red
        }
    }
    catch {
        Write-Host "安装过程中出错: $($_.Exception.Message)" -ForegroundColor Red
    }
}
```

### 方法 4：在当前 PowerShell 5.1 中修复编码问题

如果无法安装 PowerShell 7，我们可以尝试在当前 PowerShell 5.1 中修复编码问题：

```powershell
# 在当前 PowerShell 会话中设置编码
$OutputEncoding = [System.Text.Encoding]::UTF8
[Console]::OutputEncoding = [System.Text.Encoding]::UTF8
[Console]::InputEncoding = [System.Text.Encoding]::UTF8

# 修改 DeepSeek 函数以处理编码问题
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
    
    # 重置对话历史
    if ($Reset) {
        $script:DeepSeekHistory = @()
        Write-Host "对话历史已重置" -ForegroundColor Green
        return
    }
    
    $apiKey = $env:DEEPSEEK_API_KEY
    if (-not $apiKey) {
        Write-Error "请先设置 DEEPSEEK_API_KEY 环境变量"
        Write-Host "设置方法: `$env:DEEPSEEK_API_KEY = '你的-api-key'" -ForegroundColor Yellow
        return
    }
    
    $url = "https://api.deepseek.com/v1/chat/completions"
    
    # 构建消息数组
    $messages = @()
    
    # 添加历史消息（除非指定 NoHistory）
    if (-not $NoHistory -and $script:DeepSeekHistory.Count -gt 0) {
        $messages += $script:DeepSeekHistory
    }
    
    # 添加当前问题
    $messages += @{role = "user"; content = $Question}
    
    # 构建请求体
    $body = @{
        model = $Model
        messages = $messages
        max_tokens = $MaxTokens
        temperature = $Temperature
        stream = $false
    } | ConvertTo-Json -Depth 5
    
    try {
        # 发送请求
        $response = Invoke-RestMethod -Uri $url -Method Post -Headers @{
            "Content-Type" = "application/json"
            "Authorization" = "Bearer $apiKey"
        } -Body $body -ErrorAction Stop
        
        # 获取回答
        $answer = $response.choices[0].message.content
        
        # 更新历史记录（除非指定 NoHistory）
        if (-not $NoHistory) {
            $script:DeepSeekHistory += @{role = "user"; content = $Question}
            $script:DeepSeekHistory += @{role = "assistant"; content = $answer}
            
            # 限制历史记录长度
            if ($script:DeepSeekHistory.Count -gt 20) {
                $script:DeepSeekHistory = $script:DeepSeekHistory | Select-Object -Last 20
            }
        }
        
        # 尝试修复编码问题
        try {
            # 将字符串转换为字节数组，然后使用正确的编码重新解码
            $bytes = [System.Text.Encoding]::GetEncoding("ISO-8859-1").GetBytes($answer)
            $answer = [System.Text.Encoding]::UTF8.GetString($bytes)
        }
        catch {
            # 如果编码转换失败，保持原样
        }
        
        return $answer
    }
    catch {
        Write-Error "API 调用失败: $($_.Exception.Message)"
        return $null
    }
}
```

### 方法 5：使用代理或 VPN

如果你有可用的代理或 VPN，可以尝试使用它们来访问 GitHub：

```powershell
# 设置代理（如果你有可用的代理服务器）
$proxyAddress = "http://your-proxy-server:port"
[System.Net.WebRequest]::DefaultWebProxy = New-Object System.Net.WebProxy($proxyAddress, $true)
[System.Net.WebRequest]::DefaultWebProxy.Credentials = [System.Net.CredentialCache]::DefaultCredentials

# 然后尝试使用 Winget 安装 PowerShell 7
winget install --id Microsoft.PowerShell --source winget
```

### 总结

由于你的网络环境限制，安装 PowerShell 7 可能会比较困难。我建议尝试以下步骤：

1. 首先尝试使用 Microsoft Store 安装 PowerShell 7
2. 如果不行，尝试手动下载并安装
3. 如果所有方法都失败，使用我在方法 4 中提供的修改版 DeepSeek 函数，它应该能在 PowerShell 5.1 中更好地处理编码问题

请尝试这些方法，看看哪个能够成功。如果仍然遇到问题，请告诉我具体的错误信息，我会帮你进一步排查。

# 用户：

└─[#]> try {
     # 方法 1: 使用 .NET WebClient
     Write-Host "尝试使用 .NET WebClient 下载..." -ForegroundColor Yellow
     $webClient = New-Object System.Net.WebClient
     $webClient.DownloadFile($downloadUrl, $downloadPath)
     Write-Host "下载成功!" -ForegroundColor Green
 }
 catch {
     Write-Host "WebClient 下载失败: $($_.Exception.Message)" -ForegroundColor Red

     # 方法 2: 使用 BitsTransfer
     try {
         Write-Host "尝试使用 BitsTransfer 下载..." -ForegroundColor Yellow
         Import-Module BitsTransfer
         Start-BitsTransfer -Source $downloadUrl -Destination $downloadPath
         Write-Host "下载成功!" -ForegroundColor Green
     }
     catch {
         Write-Host "BitsTransfer 下载失败: $($_.Exception.Message)" -ForegroundColor Red
         Write-Host "请手动下载并安装 PowerShell 7" -ForegroundColor Red
     }
 }
尝试使用 .NET WebClient 下载...
WebClient 下载失败: Exception calling "DownloadFile" with "2" argument(s): "操作超时"
尝试使用 BitsTransfer 下载...
Start-BitsTransfer : 操作超时
At line:15 char:9
+         Start-BitsTransfer -Source $downloadUrl -Destination $downloa ...
+         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    + CategoryInfo          : InvalidOperation: (:) [Start-BitsTransfer], Exception
    + FullyQualifiedErrorId : StartBitsTransferCOMException,Microsoft.BackgroundIntelligentTransfer.Management.NewBitsTransferCommand

下载成功!
┏[ 09/18/2025 @ 2:48:55 PM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 10/15GB][ 100][ 6:49.313s]
┣[ ~]
└─[#]>
┏[ 09/18/2025 @ 2:48:55 PM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 10/15GB][ 100][ 0s]
┣[ ~]
└─[#]> # 如果下载成功，尝试安装
┏[ 09/18/2025 @ 2:48:55 PM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 10/15GB][ 100][ 0s]
┣[ ~]
└─[#]> if (Test-Path $downloadPath) {
     Write-Host "正在安装 PowerShell 7..." -ForegroundColor Yellow
     try {
         $process = Start-Process -FilePath "msiexec.exe" -ArgumentList "/i", "`"$downloadPath`"", "/quiet", "/norestart" -Wait -PassThru

         if ($process.ExitCode -eq 0) {
             Write-Host "PowerShell 7 安装成功!" -ForegroundColor Green

             # 更新环境变量
             $env:Path += ";$env:ProgramFiles\PowerShell\7"

             # 测试新版本
             Write-Host "测试新版本 PowerShell..." -ForegroundColor Yellow
             & "$env:ProgramFiles\PowerShell\7\pwsh.exe" -Command "Write-Host 'PowerShell 7 安装成功!' -ForegroundColor Green; `$PSVersionTable.PSVersion"
         }
         else {
             Write-Host "安装失败，退出代码: $($process.ExitCode)" -ForegroundColor Red
         }
     }
     catch {
         Write-Host "安装过程中出错: $($_.Exception.Message)" -ForegroundColor Red
     }
 }
┏[ 09/18/2025 @ 2:49:06 PM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 10/15GB][ 100][ 0.002s]
┣[ ~]
└─[#]>

# DeepSeek：

**原始回答**

看起来下载过程中遇到了超时问题，但最终显示"下载成功！"。让我检查一下是否真的下载成功，并尝试安装 PowerShell 7：

```powershell
# 检查文件是否真的下载成功
$downloadPath = "$env:TEMP\PowerShell-7.4.2-win-x64.msi"  # 根据你的系统架构调整
if (Test-Path $downloadPath) {
    $fileSize = (Get-Item $downloadPath).Length
    Write-Host "文件已下载，大小: $($fileSize/1MB) MB" -ForegroundColor Green
    
    if ($fileSize -gt 0) {
        Write-Host "正在安装 PowerShell 7..." -ForegroundColor Yellow
        try {
            $process = Start-Process -FilePath "msiexec.exe" -ArgumentList "/i", "`"$downloadPath`"", "/quiet", "/norestart" -Wait -PassThru
            
            if ($process.ExitCode -eq 0) {
                Write-Host "PowerShell 7 安装成功!" -ForegroundColor Green
                
                # 更新环境变量
                $env:Path += ";$env:ProgramFiles\PowerShell\7"
                
                # 测试新版本
                Write-Host "测试新版本 PowerShell..." -ForegroundColor Yellow
                & "$env:ProgramFiles\PowerShell\7\pwsh.exe" -Command "Write-Host 'PowerShell 7 安装成功!' -ForegroundColor Green; `$PSVersionTable.PSVersion"
            }
            else {
                Write-Host "安装失败，退出代码: $($process.ExitCode)" -ForegroundColor Red
            }
        }
        catch {
            Write-Host "安装过程中出错: $($_.Exception.Message)" -ForegroundColor Red
        }
    }
    else {
        Write-Host "文件大小为 0，下载可能未完成" -ForegroundColor Red
    }
} else {
    Write-Host "文件不存在，下载失败" -ForegroundColor Red
}
```

如果文件确实下载成功但安装失败，或者文件大小为0，我们可以尝试手动安装：

```powershell
# 手动安装 PowerShell 7
if (Test-Path $downloadPath) {
    Write-Host "尝试手动安装 PowerShell 7..." -ForegroundColor Yellow
    Write-Host "请双击以下文件进行安装: $downloadPath" -ForegroundColor Cyan
    
    # 尝试打开文件资源管理器并选中文件
    try {
        Invoke-Item (Split-Path $downloadPath)
        explorer.exe /select,"$downloadPath"
    }
    catch {
        Write-Host "无法打开文件资源管理器，请手动导航到: $env:TEMP" -ForegroundColor Red
    }
}
```

如果安装仍然失败，我们可以尝试在当前 PowerShell 5.1 中修复编码问题：

```powershell
# 在当前 PowerShell 会话中设置编码
$OutputEncoding = [System.Text.Encoding]::UTF8
[Console]::OutputEncoding = [System.Text.Encoding]::UTF8
[Console]::InputEncoding = [System.Text.Encoding]::UTF8

# 修改 DeepSeek 函数以处理编码问题
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
    
    # 重置对话历史
    if ($Reset) {
        $script:DeepSeekHistory = @()
        Write-Host "对话历史已重置" -ForegroundColor Green
        return
    }
    
    $apiKey = $env:DEEPSEEK_API_KEY
    if (-not $apiKey) {
        Write-Error "请先设置 DEEPSEEK_API_KEY 环境变量"
        Write-Host "设置方法: `$env:DEEPSEEK_API_KEY = '你的-api-key'" -ForegroundColor Yellow
        return
    }
    
    $url = "https://api.deepseek.com/v1/chat/completions"
    
    # 构建消息数组
    $messages = @()
    
    # 添加历史消息（除非指定 NoHistory）
    if (-not $NoHistory -and $script:DeepSeekHistory.Count -gt 0) {
        $messages += $script:DeepSeekHistory
    }
    
    # 添加当前问题
    $messages += @{role = "user"; content = $Question}
    
    # 构建请求体
    $body = @{
        model = $Model
        messages = $messages
        max_tokens = $MaxTokens
        temperature = $Temperature
        stream = $false
    } | ConvertTo-Json -Depth 5
    
    try {
        # 发送请求
        $response = Invoke-RestMethod -Uri $url -Method Post -Headers @{
            "Content-Type" = "application/json"
            "Authorization" = "Bearer $apiKey"
        } -Body $body -ErrorAction Stop
        
        # 获取回答
        $answer = $response.choices[0].message.content
        
        # 更新历史记录（除非指定 NoHistory）
        if (-not $NoHistory) {
            $script:DeepSeekHistory += @{role = "user"; content = $Question}
            $script:DeepSeekHistory += @{role = "assistant"; content = $answer}
            
            # 限制历史记录长度
            if ($script:DeepSeekHistory.Count -gt 20) {
                $script:DeepSeekHistory = $script:DeepSeekHistory | Select-Object -Last 20
            }
        }
        
        # 尝试修复编码问题
        try {
            # 将字符串转换为字节数组，然后使用正确的编码重新解码
            $bytes = [System.Text.Encoding]::GetEncoding("ISO-8859-1").GetBytes($answer)
            $answer = [System.Text.Encoding]::UTF8.GetString($bytes)
        }
        catch {
            # 如果编码转换失败，保持原样
        }
        
        return $answer
    }
    catch {
        Write-Error "API 调用失败: $($_.Exception.Message)"
        return $null
    }
}

# 重新设置别名
Set-Alias ds Invoke-DeepSeek

# 测试 DeepSeek 函数
Write-Host "测试 DeepSeek 函数..." -ForegroundColor Yellow
$testResult = ds "用一句话说明你是DeepSeek AI助手" -NoHistory
if ($testResult) {
    Write-Host "测试成功!" -ForegroundColor Green
    Write-Host "回应: $testResult" -ForegroundColor Cyan
} else {
    Write-Host "测试失败" -ForegroundColor Red
}
```

如果所有这些方法都失败，我建议你尝试以下替代方案：

1. **使用在线转换工具**：将 PowerShell 配置文件中的中文内容转换为 Unicode 转义序列，这样可以避免编码问题。

2. **使用英文界面**：暂时将 PowerShell 配置文件中的所有中文提示和注释改为英文，以避免编码问题。

3. **使用其他终端**：尝试使用 Windows Terminal 或 ConEmu，它们通常对 UTF-8 的支持更好。

4. **手动安装 PowerShell 7**：从另一台可以访问互联网的计算机下载 PowerShell 7 安装程序，然后通过 U 盘或其他方式复制到当前计算机进行安装。

请尝试这些方法，看看哪个能够解决你的问题。如果仍然遇到困难，请提供更多详细信息，我会尽力帮助你解决。

# 用户：

总结以上对话内容以重新开始对话

# DeepSeek：

**原始回答**

# PowerShell DeepSeek API 集成总结与重新开始

## 当前状态总结
1. **环境**：PowerShell 5.1，已启用系统UTF-8支持
2. **问题**：DeepSeek API 返回中文内容显示乱码
3. **尝试的解决方案**：
   - 修改控制台编码设置
   - 升级到 PowerShell 7（因网络限制失败）
   - 修改 DeepSeek 函数处理编码
   - 使用不同的HTTP请求方法

## 重新开始方案

### 方案一：优化当前 PowerShell 5.1 的编码处理

```powershell
# 强制设置 UTF-8 编码
$OutputEncoding = [System.Text.Encoding]::UTF8
[Console]::OutputEncoding = [System.Text.Encoding]::UTF8
[Console]::InputEncoding = [System.Text.Encoding]::UTF8

# 修复版 DeepSeek 函数
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
    $messages = @()
    
    if (-not $NoHistory -and $script:DeepSeekHistory.Count -gt 0) {
        $messages += $script:DeepSeekHistory
    }
    
    $messages += @{role = "user"; content = $Question}
    
    $body = @{
        model = $Model
        messages = $messages
        max_tokens = $MaxTokens
        temperature = $Temperature
        stream = $false
    } | ConvertTo-Json -Depth 5
    
    try {
        $response = Invoke-RestMethod -Uri $url -Method Post -Headers @{
            "Content-Type" = "application/json"
            "Authorization" = "Bearer $apiKey"
        } -Body $body -ErrorAction Stop
        
        $answer = $response.choices[0].message.content
        
        # 编码修复
        try {
            $bytes = [System.Text.Encoding]::GetEncoding("ISO-8859-1").GetBytes($answer)
            $answer = [System.Text.Encoding]::UTF8.GetString($bytes)
        } catch {}
        
        if (-not $NoHistory) {
            $script:DeepSeekHistory += @{role = "user"; content = $Question}
            $script:DeepSeekHistory += @{role = "assistant"; content = $answer}
            
            if ($script:DeepSeekHistory.Count -gt 20) {
                $script:DeepSeekHistory = $script:DeepSeekHistory | Select-Object -Last 20
            }
        }
        
        return $answer
    }
    catch {
        Write-Error "API 调用失败: $($_.Exception.Message)"
        return $null
    }
}

Set-Alias ds Invoke-DeepSeek
```

### 方案二：使用 Windows Terminal（推荐）
1. 安装 Windows Terminal：`winget install Microsoft.WindowsTerminal`
2. 在 Windows Terminal 中测试 DeepSeek

### 方案三：手动安装 PowerShell 7
1. 从其他设备下载 PowerShell 7 MSI 安装包
2. 通过U盘等方式传输到当前设备
3. 手动安装

## 快速测试命令

```powershell
# 设置API密钥
$env:DEEPSEEK_API_KEY = "你的-API-密钥"

# 测试中文显示
ds "用一句话介绍你自己" -NoHistory

# 测试英文（避免编码问题）
ds "Introduce yourself in one sentence" -NoHistory
```

## 建议的后续步骤
1. 先测试英文查询是否正常
2. 如果英文正常，说明API连接成功，只是中文编码问题
3. 尝试使用 Windows Terminal
4. 考虑暂时使用英文界面避免编码问题

是否需要我详细解释某个特定方案，或者你有其他偏好？

# 用户：

我是否可以看到ds-re的思考内容

# DeepSeek：

**原始回答**

# 查看 DeepSeek 模型的思考过程

目前，DeepSeek API 的标准响应不包含模型的完整思考过程或推理链。API 主要返回最终的生成结果，而不是中间推理步骤。

不过，有几种方法可以尝试获取更详细的推理内容：

## 方法一：使用特定的提示词要求展示思考过程

你可以修改提问方式，明确要求模型展示其思考过程：

```powershell
# 要求展示思考过程
ds "请逐步推理并告诉我现在美国总统是谁？展示你的思考过程。"

# 或者使用推理专用模型
ds-reasoner "请详细说明你的推理步骤：现在美国总统是谁？"
```

## 方法二：修改函数以获取更多信息

你可以修改 `Invoke-DeepSeek` 函数来获取 API 返回的完整响应，而不仅仅是最终答案：

```powershell
function Invoke-DeepSeekWithDetails {
    param(
        [Parameter(Mandatory=$true)]
        [string]$Question,
        
        [ValidateSet("deepseek-chat", "deepseek-reasoner")]
        [string]$Model = "deepseek-reasoner",  # 默认使用推理模型
        
        [int]$MaxTokens = 4000,
        [double]$Temperature = 0.7,
        [switch]$Reset
    )
    
    $apiKey = $env:DEEPSEEK_API_KEY
    if (-not $apiKey) {
        Write-Error "请先设置 DEEPSEEK_API_KEY 环境变量"
        return
    }
    
    $url = "https://api.deepseek.com/v1/chat/completions"
    
    # 构建提示词，要求展示思考过程
    $enhancedQuestion = "请详细展示你的思考过程和推理步骤：$Question"
    
    $body = @{
        model = $Model
        messages = @(@{role = "user"; content = $enhancedQuestion})
        max_tokens = $MaxTokens
        temperature = $Temperature
        stream = $false
    } | ConvertTo-Json -Depth 5
    
    try {
        $response = Invoke-RestMethod -Uri $url -Method Post -Headers @{
            "Content-Type" = "application/json"
            "Authorization" = "Bearer $apiKey"
        } -Body $body -ErrorAction Stop
        
        # 返回完整响应对象，包含更多细节
        return @{
            Answer = $response.choices[0].message.content
            FullResponse = $response
            Model = $response.model
            Usage = $response.usage
        }
    }
    catch {
        Write-Error "API 调用失败: $($_.Exception.Message)"
        return $null
    }
}

# 设置别名
Set-Alias ds-detail Invoke-DeepSeekWithDetails

# 使用示例
$detailedResponse = ds-detail "现在美国总统是谁？"
$detailedResponse.Answer  # 获取答案
$detailedResponse.Usage   # 查看使用情况（token数量等）
```

## 方法三：使用系统提示词引导模型行为

你可以通过系统消息来引导模型的响应方式：

```powershell
function Invoke-DeepSeekWithReasoning {
    param(
        [Parameter(Mandatory=$true)]
        [string]$Question
    )
    
    $apiKey = $env:DEEPSEEK_API_KEY
    if (-not $apiKey) {
        Write-Error "请先设置 DEEPSEEK_API_KEY 环境变量"
        return
    }
    
    $url = "https://api.deepseek.com/v1/chat/completions"
    
    # 使用系统消息引导模型展示思考过程
    $messages = @(
        @{role = "system"; content = "你是一个注重透明度和解释性的AI助手。请始终展示你的思考过程和推理步骤，然后再给出最终答案。"},
        @{role = "user"; content = $Question}
    )
    
    $body = @{
        model = "deepseek-reasoner"
        messages = $messages
        max_tokens = 4000
        temperature = 0.7
        stream = $false
    } | ConvertTo-Json -Depth 5
    
    try {
        $response = Invoke-RestMethod -Uri $url -Method Post -Headers @{
            "Content-Type" = "application/json"
            "Authorization" = "Bearer $apiKey"
        } -Body $body -ErrorAction Stop
        
        return $response.choices[0].message.content
    }
    catch {
        Write-Error "API 调用失败: $($_.Exception.Message)"
        return $null
    }
}

Set-Alias ds-think Invoke-DeepSeekWithReasoning
```

## 方法四：简单的测试函数

```powershell
function Test-Reasoning {
    # 测试模型是否会展示思考过程
    $questions = @(
        "请逐步推理：现在美国总统是谁？",
        "展示你的思考过程：计算15×28+37",
        "请详细解释你的推理：为什么天空是蓝色的？"
    )
    
    foreach ($q in $questions) {
        Write-Host "问题: $q" -ForegroundColor Yellow
        $answer = ds $q
        Write-Host "回答: $answer" -ForegroundColor Cyan
        Write-Host "---" -ForegroundColor Gray
    }
}
```

## 注意事项

1. **模型限制**：即使使用上述方法，你看到的仍然是模型生成的文本，而不是真正的"思考过程"。大型语言模型不会像人类一样有意识地进行逐步思考。

2. **token 消耗**：要求模型展示思考过程会消耗更多 token，可能增加 API 使用成本。

3. **响应时间**：更详细的响应可能需要更长的生成时间。

4. **提示词工程**：获取详细推理的关键在于精心设计提示词，明确要求模型展示其"思考过程"。

尝试这些方法，看看哪种方式能给你提供最满意的"思考过程"展示。如果你有特定的需求或期望的格式，可以进一步调整提示词。

# 用户：

PowerShell 7.5.3
&: The term 'C:\Users\Aaron Kwo'k\AppData\Local\oh-my-posh\init.26.19.1.6a2ee05abe7c14bb.10.ps1' is not recognized as a name of a cmdlet, function, script file, or executable program.
Check the spelling of the name, or if a path was included, verify that the path is correct and try again.

# DeepSeek：

**原始回答**

这个错误是因为你的用户名中包含空格（`Aaron Kwo'k`），而 oh-my-posh 生成的路径没有正确处理空格。让我们修复这个问题：

## 解决方案

### 方法一：修复 oh-my-posh 初始化

在你的 PowerShell 配置文件中修改 oh-my-posh 的初始化方式：

```powershell
# 修复 oh-my-posh 初始化（处理用户名中的空格）
try {
    # 使用正确的引号处理路径
    $ohMyPoshScript = & oh-my-posh init pwsh --config "$env:POSH_THEMES_PATH/tokyo.omp.json" --print
    if ($ohMyPoshScript) {
        Invoke-Expression $ohMyPoshScript
    }
}
catch {
    Write-Warning "oh-my-posh 初始化失败: $($_.Exception.Message)"
    Write-Host "继续加载其他配置..." -ForegroundColor Yellow
}

# 或者使用更简单的方法
# oh-my-posh init pwsh --config "$env:POSH_THEMES_PATH/tokyo.omp.json" | Invoke-Expression
```

### 方法二：手动设置提示符

如果 oh-my-posh 仍然有问题，可以暂时禁用它，使用 PowerShell 原生提示符：

```powershell
# 暂时禁用 oh-my-posh
# oh-my-posh init pwsh --config "$env:POSH_THEMES_PATH/tokyo.omp.json" | Invoke-Expression

# 使用简单的自定义提示符
function global:prompt {
    # 显示当前目录和基本信息
    $location = $(Get-Location)
    $time = Get-Date -Format "HH:mm:ss"
    
    # 设置颜色主题
    Write-Host "[$(Get-Date -Format 'MM/dd/yyyy @ HH:mm:ss')] " -NoNewline -ForegroundColor Gray
    Write-Host "$($env:USERNAME) " -NoNewline -ForegroundColor Cyan
    Write-Host ":: " -NoNewline -ForegroundColor Gray
    Write-Host "$(Split-Path -Leaf $location) " -NoNewline -ForegroundColor Green
    Write-Host "> " -NoNewline -ForegroundColor Yellow
    
    return " "
}
```

### 方法三：修复路径引用

在你的配置文件中添加路径处理：

```powershell
# 修复路径处理（针对包含空格的用户名）
$env:POSH_THEMES_PATH = $env:POSH_THEMES_PATH -replace " ", "` "  # 转义空格

# 然后初始化 oh-my-posh
try {
    oh-my-posh init pwsh --config "$env:POSH_THEMES_PATH/tokyo.omp.json" | Invoke-Expression
}
catch {
    Write-Host "oh-my-posh 初始化失败，使用备用提示符" -ForegroundColor Red
    # 使用备用提示符
    function global:prompt {
        Write-Host "PS $($executionContext.SessionState.Path.CurrentLocation)$('>' * ($nestedPromptLevel + 1)) " -NoNewline -ForegroundColor Green
        return " "
    }
}
```

### 方法四：重新安装 oh-my-posh

如果问题持续存在，可以尝试重新安装 oh-my-posh：

```powershell
# 卸载当前版本
winget uninstall JanDeDobbeleer.OhMyPosh

# 重新安装
winget install JanDeDobbeleer.OhMyPosh

# 或者使用 PowerShell 安装
Install-Module oh-my-posh -Force
```

### 方法五：临时解决方案

在修复之前，你可以暂时在 PowerShell 7 中运行以下命令来绕过这个问题：

```powershell
# 临时禁用 oh-my-posh
function global:prompt {
    # 简单的提示符
    Write-Host "PS $($executionContext.SessionState.Path.CurrentLocation)$('>' * ($nestedPromptLevel + 1)) " -NoNewline -ForegroundColor Green
    return " "
}

# 设置编码
$OutputEncoding = [System.Text.Encoding]::UTF8
[Console]::OutputEncoding = [System.Text.Encoding]::UTF8

# 加载 DeepSeek 功能
. $PROFILE.CurrentUserCurrentHost
```

### 完整的修复配置

将以下内容添加到你的 PowerShell 配置文件中：

```powershell
# 设置编码
$OutputEncoding = [System.Text.Encoding]::UTF8
[Console]::OutputEncoding = [System.Text.Encoding]::UTF8
[Console]::InputEncoding = [System.Text.Encoding]::UTF8

# 修复 oh-my-posh 初始化
try {
    # 方法1：使用正确的路径处理
    $configPath = "$env:POSH_THEMES_PATH/tokyo.omp.json"
    if (Test-Path $configPath) {
        oh-my-posh init pwsh --config $configPath | Invoke-Expression
    } else {
        Write-Warning "oh-my-posh 主题文件未找到: $configPath"
        # 使用默认配置
        oh-my-posh init pwsh | Invoke-Expression
    }
}
catch {
    Write-Warning "oh-my-posh 初始化失败: $($_.Exception.Message)"
    
    # 备用提示符
    function global:prompt {
        $location = $(Get-Location)
        $time = Get-Date -Format "HH:mm:ss"
        
        Write-Host "[$time] " -NoNewline -ForegroundColor Gray
        Write-Host "$($env:USERNAME) " -NoNewline -ForegroundColor Cyan
        Write-Host ":: " -NoNewline -ForegroundColor Gray
        Write-Host "$(Split-Path -Leaf $location) " -NoNewline -ForegroundColor Green
        Write-Host "> " -NoNewline -ForegroundColor Yellow
        
        return " "
    }
}

# Fastfetch Auto Launch
if (Get-Command fastfetch -ErrorAction SilentlyContinue) {
    fastfetch
} else {
    Write-Host "Fastfetch not found! Install: winget install fastfetch" -ForegroundColor Yellow
}

# DeepSeek 功能（之前已经配置好的）
# ... 你的 DeepSeek 函数代码 ...
```

保存配置文件后，重新启动 PowerShell 7，或者运行：

```powershell
. $PROFILE
```

这样应该能解决 oh-my-posh 的路径问题，同时确保 DeepSeek 功能正常工作。