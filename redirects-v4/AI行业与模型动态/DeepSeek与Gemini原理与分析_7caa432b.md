---
title: "DeepSeek与Gemini原理与分析"
source_platform: "DeepSeek"
source_file: "DeepSeek开源协议与多模态战略.md"
turn_start: 1
turn_end: 3
primary_category: "AI行业与模型动态"
tags:
  - "DeepSeek"
  - "Gemini"
project_id: "4cc8f0dc88-ai-industry-01"
stage: "独立主题"
previous_slice: null
next_slice: null
has_attachment: false
attachment_context_confidence: not_applicable
classification_confidence: 0.97
---

# DeepSeek与Gemini原理与分析

## 问题摘要

本切片围绕“DeepSeek与Gemini原理与分析”展开。起始诉求是：为什么deepseek使用的的是MIT这种比较宽松的开源协议而不是那种“开源传染性强”的协议？还有现在deepseek开始灰度识图模式，是不是代表deepseek V4 是个原生多模态模型以后可以实现类似Gemini 3 image（谷歌banana）那样的生图？ 后续进展或反馈是：我现在在vsstudio中使用claudiaIDE现在我想要把终端与断点窗口变得透明以看到我的背景内容覆盖原始对话 T1-T3。

## 原始对话

# 用户：

为什么deepseek使用的的是MIT这种比较宽松的开源协议而不是那种“开源传染性强”的协议？还有现在deepseek开始灰度识图模式，是不是代表deepseek V4 是个原生多模态模型以后可以实现类似Gemini 3 image（谷歌banana）那样的生图？

# DeepSeek：

**原始回答**

DeepSeek选择MIT协议是一个深刻的战略选择，旨在最大限度地消除技术应用壁垒，推动AI技术的普及和构建生态护城河。这与其“AI普惠”的理念和商业化路径高度统一。

### 📜 技术的“自由经”：为什么选择MIT协议？

选择MIT协议，本质上是在通用的人工智能领域采取了一种 **“放水养鱼”** 的策略。它就像一份对开发者最友好的“自由宣言”，明确允许**商业用途、修改后再发布（甚至闭源）**，核心约束仅是**保留版权声明**[reference:0][reference:1]。

1.  **消除商业化顾虑**：MIT协议扫清了所有法律障碍，让企业可以无后顾之忧地将DeepSeek模型集成到闭源的商业产品（如SaaS服务）中，极大地促进了技术的快速落地[reference:2]。
2.  **降低合规门槛**：无论是个人开发者还是大型企业，都只需简单标注版权即可，这最大限度地降低了使用门槛[reference:3]。
3.  **构建技术生态**：通过完全开放，DeepSeek能吸引全球开发者为模型贡献改进、开发应用，迅速围绕其模

仅供参考，请仔细甄别。

# 用户：

说到人工智能你觉得米哈游的人工智能在市场上属于什么梯队？（这里的米哈游包括蔡浩宇在新加坡的那个公司anuttacon包括LPM1.0和AnuNeko ）

# DeepSeek：

**原始回答**

相比于其他互联网巨头，米哈游的AI叙事非常独特，它并没有选择通用大模型的正面战场，而是走出了一条将AI深度嵌入游戏，并探索“AI原生”娱乐体验的路线。

要把这件事说清楚，我们得把它在不同阶段的布局拆开来看。

### 🗺️ 一张图看懂米哈游的AI版图

这张表可以让你快速了解米哈游AI事业的两大核心：

| 实体 | 定位与角色 | 核心技术/产品 | 关键动态 |
| :--- | :--- | :--- | :--- |
| **米哈游 (本体)** | **AI技术应用与投资孵化器**，在成熟商业游戏中用AI，同时依托雄厚财力进行广泛投资[reference:0] | • 内部AI团队“逆熵”、自研大模型**Glossa**[reference:1]<br>• 投资**MiniMax**（大模型）[reference:2]、**Suplay**（潮玩平台）[reference:3]<br>• 成立“**无定谷科技**”（注册资本5亿，探索“AI原生世界”)[reference:4] | • **2018年**起布局AI[refer

值得关注的参与者之一。

# 用户：

我现在在vsstudio中使用claudiaIDE现在我想要把终端与断点窗口变得透明以看到我的背景

# DeepSeek：

**原始回答**

看到你也在用 Claude 的 IDE 插件，我猜你应该是想在 **VS Code** 里实现终端与断点窗口的透明效果。

然而，"ClaudiaIDE" 是一款专为 **Visual Studio (VS)** 设计的插件，在 VS Code 的插件市场中是搜不到的[reference:0][reference:1]。由于工具用错（VS Code vs. Visual Studio），会让实现思路完全不同。

下面我分别为这两种开发环境提供解决方案，你可以按需参考：

### 思路一：如果你用的是 Visual Studio (VS) + ClaudiaIDE

你用的 ClaudiaIDE 确实能让编辑器背景变透明[reference:2]，但它的作用范围有限，**无法让“终端”和“断点”窗口也变透明**[reference:3]。

要达到“整个IDE窗口都透明”的效果，你需要一个叫 **DarkTransparencyTheme** 的插件来配合[reference:4][reference:5]。

**具体步骤是：**

1.

## 关键结论

原对话最后阶段给出的主要判断或处理方向：下面我分别为这两种开发环境提供解决方案，你可以按需参考： 思路一：如果你用的是 Visual Studio (VS) + ClaudiaIDE 你用的 ClaudiaIDE 确实能让编辑器背景变透明[reference:2]，但它的作用范围有限，**无法让“终端”和“断点”窗口也变透明**[reference:3]。要达到“整个IDE窗口都透明”的效果，你需要一个叫 **DarkTransparencyTheme** 的插件来配合[reference:4][reference:5]。

## 上下文关系

- 所属项目：4cc8f0dc88-ai-industry-01
- 当前阶段：独立主题
- 前置切片：无
- 后续切片：无
- 附件说明：无
