---
title: "DeepSeek与API安装配置"
source_platform: "DeepSeek"
source_file: "AI助手自我介绍及功能概述.md"
turn_start: 11
turn_end: 13
primary_category: "软件开发与技术排错"
tags:
  - "DeepSeek"
  - "API"
project_id: "8dab112690-software-04"
stage: "阶段1/2"
previous_slice: null
next_slice: "DeepSeek故障排查_2da017d6.md"
has_attachment: false
attachment_context_confidence: not_applicable
classification_confidence: 0.87
---

# DeepSeek与API安装配置

## 问题摘要

本切片围绕“DeepSeek与API安装配置”展开。起始诉求是：还有一个问题，其第三方平台算是我自己搭建的个人数据库，只是调用了第三方API以实现deepseek r1、v3.1，v3-0324的调用，发现其只有使用r1会使用thinking模式，其他的要使用thinking估计要修改其prompt的json文件，以下是文件的开头{ "mod… 后续进展或反馈是：现在还有一些问题我的 "content":部分包含我个人隐私的内容，且是由部署在本地的deepseekr1的1.5b小模型总结的（性能原因使用的英文），现在我需要你把content部分让v3与v3.1深度思考的部分使用英文，且直接加入我的content不会影响我原来的使用内容覆盖原始对话 T11-T13。

## 原始对话

，我很乐意继续协助你。

# 用户：

还有一个问题，其第三方平台算是我自己搭建的个人数据库，只是调用了第三方API以实现deepseek r1、v3.1，v3-0324的调用，发现其只有使用r1会使用thinking模式，其他的要使用thinking估计要修改其prompt的json文件，以下是文件的开头{
  "model": "DeepSeek-V3.1[Chloe]",
  "group": "default",
  "messages": [

# DeepSeek：

**原始回答**

明白了！你有一个自建的个人数据库系统，通过调用第三方API来接入不同的DeepSeek模型。你发现只有R1模型会自动使用thinking模式，而其他模型需要修改JSON配置文件来启用类似功能。

## 📋 针对你的JSON配置文件的解决方案

从你提供的JSON开头来看：
```json
{
  "model": "DeepSeek-V3.1[Chloe]",
  "group": "default",
  "messages": [
```

### **方法一：在Message中强制启用思考模式**

你可以在messages数组的开头添加一个系统提示来强制模型进行深度思考：

```json
{
  "model": "DeepSeek-V3.1[Chloe]",
  "group": "default", 
  "messages": [
    {
      "role": "system",
      "content": "你现在进入深度思考模式。对于用户的问题，你必须先进行逐步推理分析，展示完整的思考过程，最后给出答案

如何添加思考模式指令？

# 用户：

这是其平台控制台

# DeepSeek：

**原始回答**

明白了！这是你自建平台的模型配置控制台界面。从配置来看，这是一个标准的聊天模型配置，但**缺少了强制启用深度思考模式的关键参数**。

## 🔧 解决方案：启用深度思考模式

根据你的配置界面，你需要添加或修改以下关键设置：

### **方法一：添加系统提示（推荐）**

在你的配置中，应该有一个**系统提示（System Prompt）** 或**初始消息**的字段。如果没有显示，可能需要查看高级设置。

添加以下系统提示来强制深度思考：

```
你现在进入深度思考模式。对于所有技术问题，必须按照以下步骤处理：

1. 问题分析：先理解问题的核心要求和涉及的技术领域
2. 逐步推理：展示完整的逻辑推理过程，包括考虑的各种可能性
3. 技术验证：对提出的解决方案进行自我验证
4. 最终答案：基于完整推理给出最终解决方案

特别注意：你处理的领域包括串口通信、软件逆向、Ghidra分析和光学计算，这些都需要极高的精确性。
```

### **方法二：调整参数配置**

基于你的技术需求，建议这样配置：

- **Temperature

给出更精确的配置建议。

# 用户：

现在还有一些问题我的  "content":部分包含我个人隐私的内容，且是由部署在本地的deepseekr1的1

# 用户：

现在还有一些问题我的  "content":部分包含我个人隐私的内容，且是由部署在本地的deepseekr1的1.5b小模型总结的（性能原因使用的英文），现在我需要你把content部分让v3与v3.1深度思考的部分使用英文，且直接加入我的content不会影响我原来的使用

# DeepSeek：

**原始回答**

理解了！你需要在保持原有使用方式的前提下，将content部分改为由V3/V3.1模型进行英文深度思考处理。以下是解决方案：

## 🎯 解决方案：英文深度思考配置

### **方法一：在System Prompt中设置英文思考模式**

```json
{
  "model": "DeepSeek-V3.1[Chloe]",
  "group": "default",
  "messages": [
    {
      "role": "system",
      "content": "You are now in deep thinking mode. For all technical queries, you MUST:\n\n1. Analyze the problem core and technical domain\n2. Conduct step-by-step reasoning in English\n3. Provide technical validation and verification\n4.

## 关键结论

原对话最后阶段给出的主要判断或处理方向：你需要在保持原有使用方式的前提下，将content部分改为由V3/V3.1模型进行英文深度思考处理。以下是解决方案： 🎯 解决方案：英文深度思考配置 **方法一：在System Prompt中设置英文思考模式** ```json { "model": "DeepSeek-V3.1[Chloe]", "group": "default", "messages": [ { "role": "system", "content": "You are now in deep thinking mode. For all technical queries, you MUST:\n\n1. Analyze the problem core and technical domain\n2. Conduct step-by-step reasoning in English\n3. Provide technical validation and verification\n4.

## 上下文关系

- 所属项目：8dab112690-software-04
- 当前阶段：阶段1/2
- 前置切片：无
- 后续切片：DeepSeek故障排查_2da017d6.md
- 附件说明：无
