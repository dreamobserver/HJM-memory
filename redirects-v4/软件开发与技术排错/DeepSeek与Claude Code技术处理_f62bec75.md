---
title: "DeepSeek与Claude Code技术处理"
source_platform: "DeepSeek"
source_file: "DeepSeek API PowerShell 中文乱码解决方案.md"
turn_start: 17
turn_end: 19
primary_category: "软件开发与技术排错"
tags:
  - "DeepSeek"
  - "Claude Code"
  - "PowerShell"
  - "API"
  - "中文乱码"
project_id: "baf411af77-software-01"
stage: "阶段4/5"
previous_slice: "DeepSeek与PowerShell技术处理_2dd108a4.md"
next_slice: "PowerShell函数MaxTokens参数绑定错误_218edc44.md"
has_attachment: false
attachment_context_confidence: not_applicable
classification_confidence: 0.90
---

# DeepSeek与Claude Code技术处理

## 问题摘要

本切片围绕“DeepSeek与Claude Code技术处理”展开。起始诉求是：你这个好像只有deepseek-chat，没有deepseek-reasoner吧 后续进展或反馈是：有没有像Claude code那样压缩总结上下文的/compact的指令内容覆盖原始对话 T17-T19。

## 原始对话

代码就能立即解决问题！

# 用户：

你这个好像只有deepseek-chat，没有deepseek-reasoner吧

# DeepSeek：

**原始回答**

您说得对！我注意到了问题。在您的配置文件中，`Invoke-DeepSeek` 函数确实有 `deepseek-reasoner` 参数，但是 `ds` 函数的定义中没有正确传递这个参数。

## 🚀 正确的修复方案

在配置文件末尾添加**完整的 `ds` 函数**：

```powershell
# 创建完整的 ds 函数别名
function ds {
    param(
        [Parameter(Mandatory=$true)]
        [string]$Query,
        
        [ValidateSet("deepseek-chat", "deepseek-reasoner")]
        [string]$Model = "deepseek-chat",
        
        [int]$MaxTokens = 4000,
        [double]$Temperature = 0.7,
        [switch]$Reset,
        [sw

然后重新加载即可！**

# 用户：

ok，可以正常输出中文了，但是还有如下要改进的问题：1.使用reasoner的功能要加-Model "deepseek-reasoner"后缀，建议使用ds代指chat，ds-re代指reasoner2.问题还要加英文双引号，太麻烦了，是否可以直接不加双引号3.如何上传图片或者文件？

# DeepSeek：

**原始回答**

太好了！中文问题解决了！现在来优化您提出的三个需求：

## 🚀 改进方案

### 1. 分开的命令别名（ds 和 ds-re）

在配置文件末尾添加：

```powershell
# ds: 默认使用 deepseek-chat
function ds {
    param(
        [Parameter(ValueFromRemainingArguments=$true)]
        [string[]]$QueryParts,
        
        [int]$MaxTokens = 4000,
        [double]$Temperature = 0.7,
        [switch]$Reset,
        [switch]$NoHistory
    )
    
    $Question = $QueryParts -join " "
    Invoke-DeepSeek -Question $Question -Model "deepseek-chat" -MaxTok

我帮您调整其他功能吗？

# 用户：

有没有像Claude code那样压缩总结上下文的/compact的指令

# DeepSeek：

**原始回答**

有的！我们可以为 DeepSeek 添加类似 Claude 的上下文压缩/总结功能。这是一个非常实用的功能，可以避免对话历史过长。

## 🚀 上下文压缩功能实现

在您的配置文件中添加以下函数：

```powershell
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

## 关键结论

原对话最后阶段给出的主要判断或处理方向：我们可以为 DeepSeek 添加类似 Claude 的上下文压缩/总结功能。这是一个非常实用的功能，可以避免对话历史过长。

## 上下文关系

- 所属项目：baf411af77-software-01
- 当前阶段：阶段4/5
- 前置切片：DeepSeek与PowerShell技术处理_2dd108a4.md
- 后续切片：PowerShell函数MaxTokens参数绑定错误_218edc44.md
- 附件说明：无
