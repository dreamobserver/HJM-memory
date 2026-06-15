---
title: "PowerShell修改与升级"
source_platform: "DeepSeek"
source_file: "创建psadmin脚本打开管理员PowerShell.md"
turn_start: 1
turn_end: 3
primary_category: "软件开发与技术排错"
tags:
  - "PowerShell"
  - "软件开发"
project_id: "1966a9d787-software-01"
stage: "独立主题"
previous_slice: null
next_slice: null
has_attachment: false
attachment_context_confidence: not_applicable
classification_confidence: 0.97
---

# PowerShell修改与升级

## 问题摘要

本切片围绕“PowerShell修改与升级”展开。起始诉求是：给我造个小脚本。使得我在Win11上可以使用win+r输入“psadmin”打开powershell的管理员模式 后续进展或反馈是：不是我是要输入psadmin打开wt的管理员模式内容覆盖原始对话 T1-T3。

## 原始对话

# 用户：

给我造个小脚本。使得我在Win11上可以使用win+r输入“psadmin”打开powershell的管理员模式

# DeepSeek：

**原始回答**

你可以创建一个简单的批处理脚本或快捷方式，让 Windows 11 的「运行」对话框（Win+R）能通过输入 `psadmin` 直接打开管理员权限的 PowerShell。以下是几种实现方法，任选一种即可。

---

### 方法一：使用批处理脚本（推荐）
1. **创建脚本文件**  
   新建一个文本文件，将以下内容复制进去：
   ```batch
   @echo off
   powershell -Command "Start-Process powershell -Verb RunAs"
   ```
   - 这行命令会以管理员权限启动一个新的 PowerShell 窗口（会触发 UAC 提示）。
   - 如果你希望使用 Windows Terminal 打开 PowerShell（需已安装），可以将第二行替换为：
     ```batch
     powershell -Command "Start-Process wt -Verb RunAs -ArgumentList 'powershell.exe'"


werShell 了。

# 用户：

修改一下我要的是类似输入wt的管理员模式

# DeepSeek：

**原始回答**

明白了，你想要在 Win+R 运行框中输入 `psadmin` 后，像执行 `wt` 命令一样方便地打开**管理员权限的 PowerShell**（或者管理员权限的 Windows Terminal 中的 PowerShell 标签页）。这里有两种实现方式，你可以根据自己的喜好选择。

---

### 方案一：直接打开管理员 PowerShell 窗口（类似普通 PowerShell 但提权）
如果你只想打开一个独立的管理员 PowerShell 窗口（不是 Windows Terminal 内），可以使用以下脚本：

**脚本内容（`psadmin.bat`）：**
```batch
@echo off
powershell -Command "Start-Process powershell -Verb RunAs"
```

**使用方法：**
- 将上述内容保存为 `psadmin.bat`。
- 把文件放到系统 PATH 环境变量包含的目录（如 `C:\Windows\System32` 或自定义文件夹）。
- Win+R 输

何问题，欢迎随时追问！

# 用户：

不是我是要输入psadmin打开wt的管理员模式

# DeepSeek：

**原始回答**

好的，你想要的是：在「运行」对话框（Win+R）中输入 `psadmin` 后，直接打开**管理员权限的 Windows Terminal**（即 Windows Terminal 以管理员身份运行）。以下是最简单直接的实现方法。

---

### 方法：创建一个批处理脚本

1. **新建一个文本文件**，将以下内容复制进去：
   ```batch
   @echo off
   powershell -Command "Start-Process wt -Verb RunAs"
   ```
   - 这行命令会以管理员权限启动 Windows Terminal（触发 UAC 提示）。
   - 如果你希望启动后默认进入 **PowerShell** 标签页，可以指定配置文件：
     ```batch
     @echo off
     powershell -Command "Start-Process wt -Verb RunAs -ArgumentList '-p \"Windows PowerShell\"'"

## 关键结论

原对话最后阶段给出的主要判断或处理方向：方法：创建一个批处理脚本 1. **新建一个文本文件**，将以下内容复制进去： 这行命令会以管理员权限启动 Windows Terminal（触发 UAC 提示）。如果你希望启动后默认进入 **PowerShell** 标签页，可以指定配置文件： ```batch @echo off powershell -Command "Start-Process wt -Verb RunAs -ArgumentList '-p \"Windows PowerShell\"'"

## 上下文关系

- 所属项目：1966a9d787-software-01
- 当前阶段：独立主题
- 前置切片：无
- 后续切片：无
- 附件说明：无
