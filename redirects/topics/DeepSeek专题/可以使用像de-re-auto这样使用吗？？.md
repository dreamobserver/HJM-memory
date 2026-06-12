# 可以使用像de-re-auto这样使用吗？？

**分类**：DeepSeek专题
**来源**：DeepSeek Chat 导出
**来源平台**：DeepSeek
**原始文件**：DeepSeek API PowerShell 中文乱码解决方案.md
**包含轮次**：22 - 22

---

# 用户：
可以使用像de-re-auto这样使用吗？？

# DeepSeek：

**原始回答**
当然可以！我们可以创建一个统一的 `ds-re-auto` 命令来结合 reasoner 模型和自动压缩功能。

## 🚀 创建组合命令

在配置文件中添加以下函数：

```powershell
# 统一的智能推理命令：reasoner + 自动压缩
function ds-re-auto {
    [CmdletBinding()]
    param(
        [Parameter(Position=0, ValueFromRemainingArguments=$true)]
        [string[]]$QueryParts,
        
        [int]$AutoCompactThreshold = 8,  # reasoner 通常需要更频繁的压缩
        [switch]$NoCompact,
        
        [Parameter(Mandatory=$false)]
        [int]$MaxTokens = 4000,
        
        [Parameter(Mandatory=$false)]
        [double]$Temperature = 0.7
    )
    
    $Question = $QueryParts -join " "
    
    # 检查是否为空查询
    if ([string]::IsNullOrWhiteSpace($Question)) {
        Write-Host "请输入查询内容，例如: ds-re-auto 你的推理问题" -ForegroundColor Red
        return
    }
    
    # 检查是否需要自动压缩（reasoner 对上下文长度更敏感）
    if (-not $NoCompact -and $script:DeepSeekHistory -and $script:DeepSeekHistory.Count -ge $AutoCompactThreshold) {
        Write-Host "🤖 推理模式：检测到较长历史记录($($script:DeepSeekHistory.Count)条)，自动压缩中..." -ForegroundColor Cyan
        ds-compact -Force
    }
    
    # 使用 reasoner 模型执行查询
    Invoke-DeepSeek -Question $Question -Model "deepseek-reasoner" -MaxTokens $MaxTokens -Temperature $Temperature -NoHistory:$false
}

# 还可以创建其他组合命令
function ds-auto {
    [CmdletBinding()]
    param(
        [Parameter(Position=0, ValueFromRemainingArguments=$true)]
        [string[]]$QueryParts,
        
        [int]$AutoCompactThreshold = 12,
        [switch]$NoCompact,
        
        [Parameter(Mandatory=$false)]
        [int]$MaxTokens = 4000,
        
        [Parameter(Mandatory=$false)]
        [double]$Temperature = 0.7
    )
    
    $Question = $QueryParts -join " "
    
    if ([string]::IsNullOrWhiteSpace($Question)) {
        Write-Host "请输入查询内容" -ForegroundColor Red
        return
    }
    
    # 检查是否需要自动压缩
    if (-not $NoCompact -and $script:DeepSeekHistory -and $script:DeepSeekHistory.Count -ge $AutoCompactThreshold) {
        Write-Host "检测到较长历史记录($($script:DeepSeekHistory.Count)条)，自动压缩中..." -ForegroundColor Yellow
        ds-compact -Force
    }
    
    # 使用默认 chat 模型
    Invoke-DeepSeek -Question $Question -Model "deepseek-chat" -MaxTokens $MaxTokens -Temperature $Temperature -NoHistory:$false
}
```

## 📋 现在可以这样使用：

```powershell
# 1. 基本推理 + 自动压缩
ds-re-auto 请分析这个逻辑问题并给出推理过程

# 2. 带参数的高级使用
ds-re-auto 复杂的数学问题需要逐步推理 -MaxTokens 3000 -Temperature 0.3

# 3. 禁用自动压缩
ds-re-auto 这个问题不需要压缩上下文 -NoCompact

# 4. 调整压缩阈值
ds-re-auto 推理问题 -AutoCompactThreshold 6

# 5. 普通聊天 + 自动压缩
ds-auto 普通的聊天对话也会自动管理上下文
```

## 💡 添加更多组合命令

如果您需要，还可以创建其他变体：

```powershell
# 文件分析 + 自动压缩
function ds-file-auto {
    param(
        [Parameter(Mandatory=$true)]
        [string]$FilePath,
        
        [string]$AdditionalPrompt = "请分析这个文件的内容",
        [int]$AutoCompactThreshold = 8,
        [switch]$NoCompact
    )
    
    if (-not (Test-Path $FilePath)) {
        Write-Error "文件不存在: $FilePath"
        return
    }
    
    # 检查是否需要压缩
    if (-not $NoCompact -and $script:DeepSeekHistory -and $script:DeepSeekHistory.Count -ge $AutoCompactThreshold) {
        Write-Host "📁 文件分析模式：压缩上下文中..." -ForegroundColor Cyan
        ds-compact -Force
    }
    
    $fileContent = Get-Content $FilePath -Raw -Encoding UTF8
    $fullQuery = "文件内容：`n$fileContent`n`n$AdditionalPrompt"
    
    Invoke-DeepSeek -Question $fullQuery -Model "deepseek-reasoner" -NoHistory:$false
}
```

## 🎯 使用示例

```powershell
# 推理类问题（自动使用 reasoner + 压缩）
ds-re-auto 请推理这个数学定理的证明过程

# 代码分析
ds-re-auto 请分析这段代码的逻辑错误并给出修复建议

# 复杂决策
ds-re-auto 基于以下信息，请给出最优决策方案：

# 文件分析（自动压缩）
ds-file-auto "D:/project/analysis.txt" -AdditionalPrompt "请总结关键发现"
```

## 🔧 更新帮助信息

```powershell
function Get-DsHelp {
    Write-Host "DeepSeek API 命令帮助:" -ForegroundColor Cyan
    Write-Host "  ds <查询>                    # 普通聊天" -ForegroundColor Green
    Write-Host "  ds-re <查询>                 # 推理模型" -ForegroundColor Green
    Write-Host "  ds-re-auto <查询>            # 推理+自动压缩" -ForegroundColor Magenta
    Write-Host "  ds-auto <查询>               # 聊天+自动压缩" -ForegroundColor Magenta
    Write-Host "  ds-file <文件路径>           # 文件分析" -ForegroundColor Green
    Write-Host "  ds-compact                   # 手动压缩上下文" -ForegroundColor Yellow
    Write-Host "  ds-reset                     # 重置对话历史" -ForegroundColor Red
    Write-Host "  ds-history                   # 查看历史记录" -ForegroundColor Gray
}
```

**现在您就可以使用 `ds-re-auto` 这样的组合命令了！** 它会自动使用 reasoner 模型并在需要时压缩上下文，非常适合复杂的推理任务。

