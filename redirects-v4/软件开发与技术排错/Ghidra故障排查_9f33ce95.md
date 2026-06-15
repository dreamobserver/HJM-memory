---
title: "Ghidra故障排查"
source_platform: "DeepSeek"
source_file: "绕过串口读取失败集成新相移器.md"
turn_start: 1
turn_end: 4
primary_category: "软件开发与技术排错"
tags:
  - "Ghidra"
  - "端口映射"
project_id: "c494ca4724-software-01"
stage: "阶段1/2"
previous_slice: null
next_slice: "步骤一成功实现，输出结果：可用COM端口_ 0_ COM4 - USB Serial_cfb056ae.md"
has_attachment: false
attachment_context_confidence: not_applicable
classification_confidence: 0.97
---

# Ghidra故障排查

## 问题摘要

本切片围绕“Ghidra故障排查”展开。起始诉求是：由于原来的相移器控件是集成到软件中的，如果更换了相移器会弹窗报错“串口com号读取失败”，该如何绕过这个弹窗。如果可以将新的相移器取代软件中的旧相移器，使得其可以不再另外使用新的相移器软件这是集成软件中imports截图 后续进展或反馈是：OK，我要先从集成软件开始，找出控件对旧相移器的指令，以达到新的相移器与旧相移器以同种工作模式运行内容覆盖原始对话 T1-T4。

## 原始对话

# 用户：

由于原来的相移器控件是集成到软件中的，如果更换了相移器会弹窗报错“串口com号读取失败”，该如何绕过这个弹窗。如果可以将新的相移器取代软件中的旧相移器，使得其可以不再另外使用新的相移器软件这是集成软件中imports截图

# DeepSeek：

**原始回答**

要绕过“串口com号读取失败”弹窗并集成新相移器，需分析软件现有依赖并替换/模拟旧相移器组件。以下是具体解决方案：

---

### 1. **分析现有依赖（基于你的Imports列表）**
关键DLL可能涉及相移器通信：
- `ADVAPT32.DLL`、`OMCTL32.DLL`、`DOG_TVIDOUS_X64_3151774.DLL`（可能含硬件驱动或加密狗验证）
- `EISNEU32.DLL`、`ISjAP164.DLL`（可能为相移器专用库）
- 串口相关：`APT-HS-TIN-CRT-SIDIO-L1-i-0.DLL`（疑似串口I/O操作）

---

### 2. **绕过弹窗的两种方法**
#### 方法一：拦截旧DLL调用并重定向到新相移器
- **使用DLL劫持**：将旧相移器DLL（如`EISNEU32.DLL`）替换为自定义代理DLL：
  1. 编写代理DLL，导出与原DLL相同的函数（用工具分析原导出函数，如Dependency Walker）。
  2. 在代理DLL中：
     - 拦截串口初始化

移器型号和新设备型号！

# 用户：

我的环境是Win11，装有ghidra，hxd，pycharm，结合以上再次给出解决方法

# DeepSeek：

**原始回答**

好的，结合你的技术环境（Win11 + Ghidra, HxD, PyCharm），我们可以采用更精准的逆向工程和自动化方法来解决这个问题。以下是详细的解决方案：

---

## 解决方案概览

我们将采用 **静态分析（Ghidra）定位关键代码** -> **动态验证（可选）** -> **二进制修改（HxD）或创建劫持DLL（PyCharm开发）** 的流程。

---

## 第一步：使用Ghidra进行静态分析，定位弹窗代码

1.  **导入目标文件**
    *   在Ghidra中创建一个新项目，并导入主程序EXE文件（以及相关的DLL，特别是 `EISNEU32.DLL`, `ADVAPT32.DLL`, `OMCTL32.DLL`，这些最可能包含相移器控制逻辑）。
    *   让Ghidra自动完成分析和反编译。

2.  **搜索错误字符串**
    *   这是最快的方法。在Ghidra的 **`Defined Strings`** 列表中，直接搜索错误消息字符串： **`串口com号读取失败`** 或其

统地解决这个集成问题。

# 用户：

还有一点要补充，新的相移器没有SDk库但是有个独立的控制软件

# DeepSeek：

**原始回答**

这一点非常关键！新的相移器有独立控制软件但没有SDK，这改变了我们的集成策略。我们现在有两个主要方向：

## 方案一：自动化独立控制软件（推荐首选）

既然有独立控制软件，我们可以通过自动化方式控制它，而不是直接集成。

### 使用PyCharm开发自动化脚本：

```python
# phase_shifter_controller.py
import subprocess
import time
import psutil
import win32gui
import win32con
import win32api

class PhaseShifterController:
    def __init__(self, exe_path="C:\\Program Files\\NewPhaseShifter\\control.exe"):
        self.exe_path = exe_path
        self.process = None
        
    def start_software(s

功能来调整自动化逻辑。

# 用户：

OK，我要先从集成软件开始，找出控件对旧相移器的指令，以达到新的相移器与旧相移器以同种工作模式运行

# DeepSeek：

**原始回答**

非常好的思路！直接从集成软件入手，捕获旧相移器的控制指令，然后让新相移器模拟相同的协议和工作模式。这是最彻底的解决方案。以下是详细的实施步骤：

## 第一步：准备监控环境

### 1. 使用串口监控工具
```python
# serial_monitor.py
import serial
import serial.tools.list_ports
from datetime import datetime
import json

class SerialMonitor:
    def __init__(self, com_port, baud_rate=9600):
        self.com_port = com_port
        self.baud_rate = baud_rate
        self.log_file = f"com_{com_port}_log_{datetime.now().strftime('%Y%m%d_%H%M%S')}.json"
        self.log_data

## 关键结论

该切片记录了“Ghidra故障排查”的讨论过程。具体判断与操作细节以原始对话为准，旧助手结论仍需结合当前事实核验。

## 上下文关系

- 所属项目：c494ca4724-software-01
- 当前阶段：阶段1/2
- 前置切片：无
- 后续切片：步骤一成功实现，输出结果：可用COM端口_ 0_ COM4 - USB Serial_cfb056ae.md
- 附件说明：无
