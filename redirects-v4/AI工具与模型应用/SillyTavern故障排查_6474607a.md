---
title: "SillyTavern故障排查"
source_platform: "Gemini"
source_file: "AI酒馆-502-错误排查.md"
turn_start: 4
turn_end: 4
primary_category: "AI工具与模型应用"
tags:
  - "SillyTavern"
  - "HTTP 502"
project_id: "9814a4eaf9-ai-tools-01"
stage: "阶段2/2"
previous_slice: "SillyTavern与API故障排查_59b9e80c.md"
next_slice: null
has_attachment: false
attachment_context_confidence: not_applicable
classification_confidence: 0.91
---

# SillyTavern故障排查

## 问题摘要

本切片围绕“SillyTavern故障排查”展开。起始诉求是：404又是怎么了内容覆盖原始对话 T4-T4。

## 原始对话

## Turn 4

### 👤 User

404又是怎么了

### 🤖 Assistant

**404 错误代表“Not Found”（找不到资源）。**
这和刚才的 502（网络不通）完全不同。502 是路没修好，404 是路通了，但是你**敲错了门，或者找了一个不存在的人。**
在 AI 酒馆（SillyTavern）的语境下，出现 404 通常只有以下两种原因：

### 1. 模型名字填错了（最常见）
你可能在“Model ID”或者模型名称那里，手动填了一个服务器不认识的名字。

- **情况**：比如你填了 `gemini-3-pro`（假设现在还不能用这个名字），或者填了一个已经过期的测试版模型名（比如某些带 `exp` 后缀的旧模型）。
- **或者**：你用的中转/反代服务，不支持你当前选择的这个模型。
- **解决**：
  - 检查你的 **Model ID** 设置。
  - 尝试换回一个最标准的模型名试试，比如 `gemini-1.5-pro-latest` 或 `gemini-1.5-flash`。
  - 如果你是用 OpenAI 格式连接 Gemini，确保你的模型名字不需要加 `models/` 前缀（或者反过来，试试加上）。

### 2. API 地址（Endpoint）填错了
你可能不小心改动了 API 的连接地址。

- **情况**：
  - 比如本来应该是 `.../v1/chat/completions`，结果不小心删掉了一部分变成了 `.../v1/chat`。
  - 或者你从“Chat Completion”模式切到了“Text Completion”模式，导致地址对不上。
- **解决**：
  - 如果你用的是反代/中转，确认地址后缀是否完整。
  - 如果你刚刚没动过地址，那就大概率是上面的**原因 1（模型名字问题）**。
**总结：**
既然你刚才 200 (成功) 过，说明网络和地址大概率是没问题的。
**请立刻检查：你是不是刚刚手滑改了“Model”那一栏的选项？或者选了一个很冷门/新的模型？切回标准模型通常就好了。**

---

*Exported from [Voyager](https://github.com/Nagi-ovo/gemini-voyager)*  
*Generated on June 10, 2026 at 10:49 AM*

## 关键结论

原对话最后阶段给出的主要判断或处理方向：** 在 AI 酒馆（SillyTavern）的语境下，出现 404 通常只有以下两种原因： 1. 模型名字填错了（最常见） 你可能在“Model ID”或者模型名称那里，手动填了一个服务器不认识的名字。**解决**： 检查你的 **Model ID** 设置。

## 上下文关系

- 所属项目：9814a4eaf9-ai-tools-01
- 当前阶段：阶段2/2
- 前置切片：SillyTavern与API故障排查_59b9e80c.md
- 后续切片：无
- 附件说明：无
