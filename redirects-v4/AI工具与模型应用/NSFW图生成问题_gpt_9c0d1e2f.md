---
title: "NSFW图生成问题：ComfyUI云端安全过滤排查"
source_platform: "ChatGPT Web"
source_file: "raw-memory/Chat GPT/NSFW 图生成问题.md"
turn_start: 1
turn_end: 1
primary_category: "AI工具与模型应用"
tags:
  - "ComfyUI"
  - "NSFW"
  - "SafetyChecker"
  - "MoRanJiangHu"
  - "CNB"
  - "文生图"
project_id: "gpt-0624-ai-03"
stage: "故障排查"
previous_slice: null
next_slice: null
has_attachment: false
attachment_context_confidence: not_applicable
classification_confidence: 0.93
---
# NSFW 图生成问题

**Assistant:**

你这个问题，本质上不是“网页酒馆/MoRanJiangHu坏了”，而是：

> 你接入的 CNB 云端 ComfyUI 大概率开启了 NSFW 安全过滤（Safety Checker / Guardrails），所以普通图能出，涉及 NSFW 的就被拦截了。

从你截图里的日志也能看出来，目前真正报错的是：

> “未配置可用的文生图接口，无法生成团队档案”

这个其实是网页酒馆自己在调用“角色档案/记忆图”时失败，不一定是你画图主流程的问题。

而你说：

- 普通图 → 能生成
- NSFW → 完全不行

这就非常符合：

- 云端平台加了审核
- 或模型被替换成阉割版
- 或 workflow 里有 NSFWChecker 节点

很多 ComfyUI 云平台都会这样。citeturn0search3turn0search7turn0reddit12

你现在应该按下面顺序排查。

---

# 一、先确认：到底是谁在拦

有 4 种常见情况。

---

## 情况 1：CNB 云平台自身拦截（最常见）

特征：

- 普通图正常
- 一涉及裸露关键词直接失败
- ComfyUI 根本没开始采样
- 或输出纯黑图
- 或日志出现：
  - safety
  - nsfw
  - blocked
  - guardrails

很多云平台都会这样。Reddit 里就有人遇到：

> “Generation blocked by guardrails”  
> 后来发现是平台默认打开了 Safety Filter。citeturn0reddit12

---

## 解决方法

去 CNB 云 ComfyUI：

### 检查：

- Settings
- Advanced
- Safety Filter
- NSFW Filter
- Guardrails
- Safe Mode

有没有：

- Enable Safety Filter
- NSFW Check
- Safety Checker

关闭它。

---

# 二、检查 workflow 里有没有 NSFW 节点

很多 workflow 自带：

- NSFWChecker
- SafetyChecker
- NudeNet
- NSFWScore

这些节点会：

- 检测到 NSFW
- 自动黑图
- 自动中断

ComfyUI 里非常常见。citeturn0search3turn0search7turn0search8

---

## 你该怎么查

打开 workflow。

搜索：

- nsfw
- safety
- checker
- nude

如果看到：

- Safety Checker
- NSFW Detection
- NSFWScore

直接删掉节点。

---

# 三、模型本身可能是“净化版”

这是第二大概率。

很多云平台：

- 不给你真正 SDXL
- 而是：
  - Pony Safe
  - Juggernaut Safe
  - 官方 SDXL-safe
  - DeepSeek-safe

这些模型：

- 会自动回避裸体
- 甚至故意生成衣服

---

## 怎么验证

测试 prompt：

```text
1girl, nude
```

如果结果：

- 穿衣服
- 模糊
- 崩坏
- 黑图

说明模型被净化了。

---

## 解决方法

换真正支持 NSFW 的模型：

例如：

- Pony Diffusion
- AutismMix
- RealVisXL
- CyberRealistic
- Anything
- MeinaMix
- Hassaku
- Animagine（部分）

---

# 四、CLIP / Negative Prompt 被系统注入

很多网页酒馆、整合包、云端 API 会偷偷加：

```text
nsfw, nude, explicit
```

到 negative prompt。

于是你越想色色，越出不来。

---

## 怎么查

在 ComfyUI：

看：

- CLIP Text Encode (Negative)

有没有：

```text
nsfw
nude
explicit
裸体
乳房
```

---

## 如果有：

删掉。

---

# 五、你这个 MoRanJiangHu 还有一个特殊点

它本质是：

- RPG 网页酒馆
- 自动调用文生图 API

所以：

## 它可能根本没把 NSFW prompt 传给 ComfyUI

很多前端会：

- 自动净化 prompt
- 删除敏感词
- 替换成 safe

---

# 你现在应该重点检查：

## 设置 → 接口连接

看：

- Prompt增强
- 安全模式
- 内容审核
- 自动优化Prompt

关闭。

---

# 六、最重要的一步：直接在 ComfyUI 测试

不要通过网页酒馆。

直接去：

CNB 的 ComfyUI 页面。

用最简单 workflow：

```text
CheckpointLoader
CLIPTextEncode
KSampler
VAE Decode
SaveImage
```

prompt：

```text
1girl, nude
```

---

## 结果判断：

### 如果这里都不行：

说明：

# 是 CNB 云平台限制

不是网页酒馆问题。

---

### 如果这里能出：

说明：

# 是 MoRanJiangHu 前端拦截

---

# 七、还有一种可能：云端根本不允许 NSFW 模型

一些平台：

- 禁止上传 NSFW LoRA
- 禁止下载 CivitAI 模型
- 自动删除模型

---

# 你可以看日志：

如果有：

- model blocked
- unauthorized model
- safety policy

那就是平台策略。

---

# 八、你截图里的报错其实还有另一个问题

这里：

```text
未配置可用的文生图接口
```

说明：

MoRanJiangHu 的：

- “团队档案”
- “文生图接口”

没正确绑定。

---

# 你应该检查：

设置 → 接口连接

确认：

## 文生图 API：

填的是：

```text
http://127.0.0.1:8188
```

或者：

```text
你的CNB地址/prompt
```

---

并且：

## API 模式：

选：

- ComfyUI
- 不是 OpenAI Image

---

# 九、最终结论（你现在最可能的问题）

按概率排序：

| 概率 | 原因 |
|---|---|
| 40% | CNB 云端开了 NSFW Filter |
| 25% | workflow 里有 Safety Checker |
| 20% | 模型是 Safe 版 |
| 10% | MoRanJiangHu 自动净化 prompt |
| 5% | API 没正确连接 |

---

# 你下一步应该这样做（最有效）

## 第一步

直接在 ComfyUI 页面测试：

```text
1girl, nude
```

不用网页酒馆。

---

## 第二步

如果失败：

找：

- Safety Filter
- Guardrails
- NSFW Checker

关闭。

---

## 第三步

如果还是失败：

换模型：

- Pony
- AutismMix
- MeinaMix

---

## 第四步

如果 ComfyUI 能出，但网页酒馆不能：

说明是：

# MoRanJiangHu 前端审查

需要关闭：

- Prompt净化
- 内容审核
- 安全模式

---

如果你愿意，下一步你可以把：

1. 你的 ComfyUI workflow 截图  
2. MoRanJiangHu 的“接口连接”页面  
3. CNB 云 ComfyUI 的设置页面  

发给我。

我可以直接帮你定位：

- 哪个节点在拦
- 哪个配置有问题
- 哪个模型不对
- 哪个 prompt 被净化了

---
