---
title: "PowerShell安装配置"
source_platform: "DeepSeek"
source_file: "PowerShell配置文件创建与编辑指南.md"
turn_start: 20
turn_end: 22
primary_category: "软件开发与技术排错"
tags:
  - "PowerShell"
  - "软件开发"
project_id: "78599ff0b6-software-01"
stage: "阶段7/10"
previous_slice: "PowerShell故障排查（T17-19）_87faebb7.md"
next_slice: "PowerShell故障排查（T23-27）_0eb51314.md"
has_attachment: false
attachment_context_confidence: not_applicable
classification_confidence: 0.97
---

# PowerShell安装配置

## 问题摘要

本切片围绕“PowerShell安装配置”展开。起始诉求是：还有一个问题，users账户名为Aaron Kwo'k有特殊符号该如何修改 后续进展或反馈是：win11该如何安装fastfech内容覆盖原始对话 T20-T22。

## 原始对话

在您的环境中可靠工作。

# 用户：

还有一个问题，users账户名为Aaron Kwo'k有特殊符号该如何修改

# DeepSeek：

**原始回答**

非常好，您指出了这个关键问题！用户名中包含单引号 `'` 确实会在命令行和脚本中造成很多问题，因为单引号在大多数 shell 中都是特殊字符（在 PowerShell 中用于定义字符串，在 CMD 中也会引起解析问题）。

以下是几种解决这个问题的方案：

### 方案一：使用环境变量避免直接使用用户名

这是最推荐的方法，因为环境变量会自动处理特殊字符。

#### 在批处理文件中：

```batch
@echo off
:: 使用环境变量代替硬编码路径
powershell -Command "Start-Process wt -ArgumentList '-p', 'Windows PowerShell' -Verb RunAs -WorkingDirectory '%USERPROFILE%'"
```

#### 在 PowerShell 脚本中：

```powershell
# 使用 $env:USERPROFILE 环境变量
$profilePath = "$env:USERPROFILE\Scripts\Launch-

代码的简洁和可移植性。

# 用户：

我准备修改用户名

# DeepSeek：

**原始回答**

**重要提醒：修改 Windows 用户名是一个高风险操作，特别是在公司环境中。请务必先备份重要数据，并尽可能在 IT 部门的协助下进行。**

修改用户名涉及两个部分：**用户文件夹名称**和**用户账户名称**。以下是正确的方法：

### 方案一：创建新本地账户（推荐，最安全）

这是最安全的方法，不会影响现有文件和设置：

1. **创建新管理员账户**：
   - 按 `Win + I` 打开设置 → 账户 → 家庭和其他用户
   - 点击"添加其他用户" → "我没有这个人的登录信息" → "添加一个没有 Microsoft 账户的用户"
   - 创建一个新用户名，如 `AaronKwok`（不要使用特殊符号）
   - 创建完成后，将其设置为管理员：点击新账户 → 更改账户类型 → 管理员

2. **迁移文件和设置**：
   - 登录到新账户
   - 从旧账户 `C:\Users\Aaron Kwo'k` 手动复制需要的文件到新账户
   - 重新安装必要的应用程序

3. **删除旧账户**（可选）：
   - 

仅供参考，请仔细甄别。

# 用户：

win11该如何安装fastfech

# DeepSeek：

**原始回答**

在 Win11 上安装 Fastfetch 👾，让你在终端里快速显示美观的系统信息，可以通过几种方法实现。我先用一个表格为你概括这几种主要方式，方便你对比选择：

| 安装方式                     | 特点                                                                 | 适用人群                                   |
| :--------------------------- | :------------------------------------------------------------------- | :----------------------------------------- |
| **使用 Winget (微软官方包管理器)** | **官方推荐**，通常最直接                                     | 希望使用系统自带工具，追求稳定和简单的用户

## 关键结论

原对话最后阶段给出的主要判断或处理方向：原始回答** 在 Win11 上安装 Fastfetch 👾，让你在终端里快速显示美观的系统信息，可以通过几种方法实现。

## 上下文关系

- 所属项目：78599ff0b6-software-01
- 当前阶段：阶段7/10
- 前置切片：PowerShell故障排查（T17-19）_87faebb7.md
- 后续切片：PowerShell故障排查（T23-27）_0eb51314.md
- 附件说明：无
