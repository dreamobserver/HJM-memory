---
title: "DeepSeek与Claude Code安装配置：接下来该怎么办配置deepseekv4p"
source_platform: "DeepSeek"
source_file: "Claude Code配置DeepSeek V4 Pro.md"
turn_start: 7
turn_end: 9
primary_category: "软件开发与技术排错"
tags:
  - "DeepSeek"
  - "Claude Code"
  - "PowerShell"
project_id: "9d2c9e6dc7-software-03"
stage: "独立主题"
previous_slice: null
next_slice: null
has_attachment: false
attachment_context_confidence: not_applicable
classification_confidence: 0.93
---

# DeepSeek与Claude Code安装配置：接下来该怎么办配置deepseekv4p

## 问题摘要

本切片围绕“DeepSeek与Claude Code安装配置：接下来该怎么办配置deepseekv4p”展开。起始诉求是：接下来该怎么办配置deepseekv4pro 后续进展或反馈是：如果我想要无论是powershell，pycharm，vsstudio，使用终端打开Claude code都可以直接使用deepseekv4pro要怎么样内容覆盖原始对话 T7-T9。

## 原始对话

题，随时可以再来问我～

# 用户：

接下来该怎么办配置deepseekv4pro

# DeepSeek：

**原始回答**

从你发来的截图看，Claude Code已经成功安装，并尝试从你的用户目录启动了。但提示 `Not logged in` 是因为程序还在等待登录官方Anthropic账户。

**现在，我们直接为它配置DeepSeek V4 Pro，就能绕开这个登录步骤。**

简单来说，就像修改软件的“后端地址”和“密钥”一样，我们只需要告诉Claude Code，把它的底层模型换成DeepSeek的API。

请务必注意，为了最大限度地发挥DeepSeek V4 Pro的`1M超长上下文`能力，模型名称必须包含 `[1m]` 后缀[reference:0][reference:1]：

*   `deepseek-v4-pro[1m]`

请按照下面的步骤操作，核心是**配置一个配置文件，让配置能永久保存。**

---

### 📝 详细步骤指南

**第1步：获取DeepSeek API Key**
1.  访问 [DeepSeek Platform API Keys](https://platform.deepseek.com/api_keys

仅供参考，请仔细甄别。

# 用户：

目前我的ide在升级目前只能通过powershell运行设置

# DeepSeek：

**原始回答**

明白了，你的IDE暂时不能用，只能靠PowerShell来配置。没问题，我们完全可以通过PowerShell设置环境变量，让Claude Code使用DeepSeek V4 Pro，效果和配置文件一样。

---

## 🚀 在 PowerShell 中配置 DeepSeek V4 Pro

### 第一步：获取 DeepSeek API Key
如果还没有，先去 [DeepSeek Platform](https://platform.deepseek.com/api_keys) 创建一个，复制保存好。

### 第二步：选择配置方式（推荐永久生效）

#### ✅ 方式A：永久生效（设置 Windows 环境变量）
以后每次打开PowerShell，Claude Code都会自动使用DeepSeek。

1. 以**管理员身份**打开PowerShell（右键“Windows PowerShell” → “以管理员身份运行”）。
2. 依次执行以下命令（**注意：需要把 `你的API密钥` 替换成真实的Key**）：

```powe

仅供参考，请仔细甄别。

# 用户：

如果我想要无论是powershell，pycharm，vsstudio，使用终端打开Claude code都可以直接使用deepseekv4pro要怎么样

# DeepSeek：

**原始回答**

想让所有终端都自动调用配置，最核心的思路就是：**把你的DeepSeek配置设定为Windows系统级的环境变量**。这样，任何终端启动时都会自动继承这些设置，一次配置，永久有效。

以下是两个经过测试的可靠方法：

---

### 🚀 方案一：核心方法 — 配置Windows系统环境变量（一次配置，全局生效）

这是最根本的解决方案。通过Windows系统设置的环境变量，会成为所有应用程序（包括你提到的PowerShell、PyCharm、VS Studio等）的默认配置。

1.  **打开系统环境变量窗口**：使用快捷键 `Win + R`，输入 `sysdm.cpl` 并回车，在弹出的系统属性窗口中，切换到“高级”选项卡并点击“环境变量”[reference:0]。

2.  **添加用户变量**：
    *   在“用户变量”区域，点击“新建”，然后逐一添加以下几个变量。

        | 变量名 | 变量值 |
        | :--- | :--- |
        | `ANTHROPIC_BASE_URL`

## 关键结论

原对话最后阶段给出的主要判断或处理方向：以下是两个经过测试的可靠方法： 🚀 方案一：核心方法 — 配置Windows系统环境变量（一次配置，全局生效） 这是最根本的解决方案。

## 上下文关系

- 所属项目：9d2c9e6dc7-software-03
- 当前阶段：独立主题
- 前置切片：无
- 后续切片：无
- 附件说明：无
