---
title: "DeepSeek与Claude Code安装配置：我之前的配置环境原来的api要改吗"
source_platform: "DeepSeek"
source_file: "Claude Code配置DeepSeek V4 Pro.md"
turn_start: 10
turn_end: 12
primary_category: "AI工具与模型应用"
tags:
  - "DeepSeek"
  - "Claude Code"
  - "API"
project_id: "9d2c9e6dc7-ai-tools-04"
stage: "阶段1/3"
previous_slice: null
next_slice: "DeepSeek与Claude Code故障排查_ec033bff.md"
has_attachment: false
attachment_context_confidence: not_applicable
classification_confidence: 0.94
---

# DeepSeek与Claude Code安装配置：我之前的配置环境原来的api要改吗

## 问题摘要

本切片围绕“DeepSeek与Claude Code安装配置：我之前的配置环境原来的api要改吗”展开。起始诉求是：这是我之前的配置环境原来的api要改吗 后续进展或反馈是：帮我看看除了apikey这些对吗内容覆盖原始对话 T10-T12。

## 原始对话

仅供参考，请仔细甄别。

# 用户：

这是我之前的配置环境原来的api要改吗

# DeepSeek：

**原始回答**

看到你的环境变量截图了。关键点来了：

**你的 `DEEPSEEK_API_KEY` 不需要改**，可以保留它用于其他调用 DeepSeek API 的工具/脚本。  
但是为了让 **Claude Code 直接使用**，需要**新增**以 `ANTHROPIC_` 开头的环境变量，其中 `ANTHROPIC_AUTH_TOKEN` 的值**可以直接复制你现有的 `DEEPSEEK_API_KEY`**。

也就是说，你的 DeepSeek API Key 是一样的，只是变量名不同。

---

## ⚠️ 安全警告（非常重要！）

**你截图中完整暴露了 API Key**：`sk-2ea223211d9b45eb962bf164523bd7d1`  
**这非常危险**，因为任何看到这张截图的人都可以使用你的额度。

👉 **建议你立即做以下操作**  
1. 登录 [DeepSeek Platform API Keys](https://platform.deepseek.com/api_keys)  
2. 找到这个 Key，

什么），截个图再问我。

# 用户：

？？？你确定是https://api.deepseek.com/anthropic而不是https://api.deepseek.com/anthropic/v1吗

# DeepSeek：

**原始回答**

你是对的，我来确认一下。`ANTHROPIC_BASE_URL` 的正确值就是 `https://api.deepseek.com/anthropic`，不需要加 `/v1`。

这个设置可以直接引用DeepSeek官方的说明：

> “如果你已经安装了 Claude Code，只需修改以下环境变量…… `export ANTHROPIC_BASE_URL=https://api.deepseek.com/anthropic`”[reference:0]

### 🧐 为什么是 `/anthropic` 而不是 `/anthropic/v1`？

1.  **专门设计的兼容接口**：`/anthropic` 是DeepSeek为兼容Anthropic API专门设计的端点[reference:1]。Claude Code正是通过这个格式来通信的[reference:2]。

2.  **避免混淆其他API接口**：DeepSeek也有兼容OpenAI API的接口，对应的基础URL是 `https://api.deepseek.com/v

可以随时问我更多细节～

# 用户：

帮我看看除了apikey这些对吗

# DeepSeek：

**原始回答**

你配置的变量基本上都对了，但**缺了最关键的一个**，而且之前的 API Key 风险还在。

---

## ✅ 已配置正确的变量

| 变量 | 值 | 状态 |
|------|-----|------|
| `ANTHROPIC_BASE_URL` | `https://api.deepseek.com/anthropic` | ✅ 正确 |
| `ANTHROPIC_MODEL` | `deepseek-v4-pro[1m]` | ✅ 正确 |
| `ANTHROPIC_DEFAULT_OPUS_MODEL` | `deepseek-v4-pro[1m]` | ✅ 正确 |
| `ANTHROPIC_DEFAULT_SONNET_MODEL` | `deepseek-v4-pro[1m]` | ✅ 正确 |
| `ANTHROPIC_DEFAULT_HAIKU_MODEL` | `deepseek-v4-flash` | ✅ 正确 |
| `CLAUDE_CODE_SUBAGENT_MODEL` | `deepseek-v4-f

## 关键结论

原对话最后阶段给出的主要判断或处理方向：原始回答** 你配置的变量基本上都对了，但**缺了最关键的一个**，而且之前的 API Key 风险还在。

## 上下文关系

- 所属项目：9d2c9e6dc7-ai-tools-04
- 当前阶段：阶段1/3
- 前置切片：无
- 后续切片：DeepSeek与Claude Code故障排查_ec033bff.md
- 附件说明：无
