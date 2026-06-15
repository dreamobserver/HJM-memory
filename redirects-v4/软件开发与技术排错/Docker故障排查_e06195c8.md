---
title: "Docker故障排查"
source_platform: "DeepSeek"
source_file: "MATLAB许可证错误解决方法.md"
turn_start: 4
turn_end: 8
primary_category: "软件开发与技术排错"
tags:
  - "Docker"
  - "软件开发"
project_id: "498af69237-software-01"
stage: "阶段2/2"
previous_slice: "解决安装matlab时的报错格 License checkout failed_b249971f.md"
next_slice: null
has_attachment: false
attachment_context_confidence: not_applicable
classification_confidence: 0.97
---

# Docker故障排查

## 问题摘要

本切片围绕“Docker故障排查”展开。起始诉求是：报错显示license.lic是在roaming文件夹，这是否是个共享文件夹，删了会不会对其他电脑产生影响 后续进展或反馈是：忘掉上一个报错，这才是distributedCOM的报错计算机-默认 权限设置并未向在应用程序容器 Microsoft Windows.Shel IExperienceHost10.0.19041.5072 neutral neutral cw5n1h2bxyewy SID (S…内容覆盖原始对话 T4-T8。

## 原始对话

23` 和操作记录）。

# 用户：

报错显示license.lic是在roaming文件夹，这是否是个共享文件夹，删了会不会对其他电脑产生影响

# DeepSeek：

**原始回答**

您观察得很仔细！`Roaming` 文件夹**不是共享文件夹**，删除其中的 MATLAB 许可证文件 **不会影响其他电脑**。以下是关键解析和操作建议：

---

### **1. `Roaming` 文件夹的性质**
- **定位**：  
  `C:\Users\你的用户名\AppData\Roaming\` 是当前用户的**私有配置文件目录**（非共享）。
- **作用**：  
  存储当前用户的软件配置、临时文件等（如 MATLAB 许可证、浏览器书签）。
- **同步机制**：  
  仅当电脑加入 **企业域（Domain）** 且启用漫游配置文件时，此文件夹会同步到域服务器（普通个人电脑**不存在此行为**）。

> ✅ **结论**：  
> 您路径中的 `C:\Users\ustc\AppData\Roaming\...` 是用户 `ustc` 的**本地专属文件夹**，删除其内容仅影响当前电脑的当前用户。

---

### **2. 删除 `license.lic` 的安全性**
| **操作**      

脑或用户造成任何影响。

# 用户：

但是目标文件夹中没有license.lic只有matlabPkey.p12

# DeepSeek：

**原始回答**

您发现了一个关键问题！目标文件夹中只有 `matlabPkey.p12` 而没有 `license.lic` 文件，这表明您的 MATLAB 安装使用了**证书式激活**而非传统的许可证文件激活。这是完全不同的激活机制，需要特殊处理。

---

### **为什么会出现这种情况？**
1. **证书式激活**：
   - 某些组织机构（如大学、企业）使用 `.p12` 证书文件进行批量激活
   - 证书包含加密的许可证信息，比传统 `.lic` 文件更安全
   - 常见于教育机构或企业环境

2. **证书文件作用**：
   - `matlabPkey.p12`：包含私钥和证书链的PKCS#12格式文件
   - 需要配套的 `ca.pem` 和 `cert.pem` 文件才能工作

---

### **解决方案：修复证书式激活**

#### 步骤1：确认完整证书文件
检查以下文件**必须同时存在**：
```plaintext
C:\Users\ustc\AppData\Roaming\MathWorks\MATLAB\R2

仅供参考，请仔细甄别。

# 用户：

我这边拥有一个USB控制的的压电陶瓷驱动器使用USB进行控制，在一台Win11笔记本电脑上可以使用。但是在一台Win10台式机上会显示“串口com号读失败1”，且在设备管理器中改设备为FT232R USB UART是显示改设备的驱动程序未被安装（代码28），然而在win11笔记本中没有需要安装驱动也可以正常使用

# DeepSeek：

**原始回答**

您遇到的问题是 **FT232R USB UART 驱动在 Win10 上未正确安装**，导致压电陶瓷驱动器无法通过串口通信（COM 端口读失败），而在 Win11 上能自动识别。以下是系统化的解决方案：

---

### **1. 确认驱动问题**
- **现象对比**：
  - **Win11**：系统自带驱动，自动识别为 COM 端口（无需手动安装）
  - **Win10**：设备管理器显示 **FT232R USB UART** 带黄色感叹号，错误代码 **28**（驱动未安装）

---

### **2. 解决方案**
#### **方法 1：手动安装官方 FTDI 驱动**
1. **下载官方驱动**：
   - 访问 FTDI 官网：[FT232R 驱动下载页](https://www.ftdichip.com/Drivers/VCP.htm)
   - 选择 **Windows 10 兼容版本**（如 `FTDI CDM v2.12.36.4 WHQL Certified`）

2. **安装步骤**：
   - 解

in10 的专用驱动。

# 用户：

这是其一段事件中的报错由于下列错误， Diagnostic Service Host服务启动失败:
服务帐户配置中不存在服务正常运行所需的特权。你可以使用 Services Microsoft
Management Console(MMC管理单元(services.msc)和 Local Security Settings MMC 管理
单元(secpol.msc)来查看服务配置和帐户配置。

# DeepSeek：

**原始回答**

您遇到的 **Diagnostic Service Host 服务启动失败** 问题是由于服务账户权限配置错误导致的。以下是系统化的解决方案：

---

### **1. 问题根源分析**
错误信息表明：
- **服务账户**（通常是 `NT AUTHORITY\LocalService`）缺少必要的特权
- 可能原因：
  - 安全策略中被误删了服务账户权限
  - 服务配置被第三方软件修改
  - 系统文件损坏

---

### **2. 解决方案**

#### **方法 1：重置服务账户权限（推荐）**
**步骤：**
1. 按 `Win+R` 输入 `services.msc` 打开服务管理器
2. 找到 **Diagnostic Service Host** 服务 → 右键 **属性**
3. 切换到 **登录** 选项卡：
   - 选择 **此账户** → 输入 `NT AUTHORITY\LocalService`
   - 密码留空
   - 勾选 **允许服务与桌面交互**
4. 点击 **应用** → **确定

损坏，需考虑系统重置。

# 用户：

忘掉上一个报错，这才是distributedCOM的报错计算机-默认 权限设置并未向在应用程序容器 Microsoft Windows.Shel IExperienceHost10.0.19041.5072 neutral neutral cw5n1h2bxyewy SID (S-1-15-2-155514346-
10016
无
2573954481-755741238-1654018636-12333318293075935687--2861478708)中运行的地址 LocalHost(使用 LRPC中的用户DESKTOP- IO03OVRIVustc SID (S-1-5-
无
10016
21-2942219632893739544-1904321087-1001)授予针对CLSID 为
7040
无
无
7000
(C2F03A33-21F5-47FA-B4BB-156362A2F239]
7000
无
APPID 为
无
7000
(316CDED5-E4AE-4B15--9113-7055D84DCC97

# DeepSeek：

**原始回答**

您遇到的 **Distributed COM (DCOM) 权限错误** 是由于 Windows Shell Experience Host（`ShellExperienceHost.exe`）在运行时缺少必要的 DCOM 访问权限。以下是系统化的解决方案：

---

### **1. 错误分析**
- **核心问题**：  
  `S-1-15-2-...`（应用程序容器 SID）未被授权访问 `CLSID {C2F03A33-...}` 和 `APPID {316CDED5-...}` 的 DCOM 组件。
- **影响范围**：  
  可能导致开始菜单、任务栏或系统界面功能异常（如无法打开设置、搜索框无响应）。

---

### **2. 解决方案**

#### **方法 1：通过注册表修复 DCOM 权限**
1. **打开注册表编辑器**（`regedit`）  
   → 导航至以下路径：
   ```
   HKEY_CLASSES_ROOT\AppID\{316CDED5-E4AE-4B15-9113-7055D8

## 关键结论

原对话最后阶段给出的主要判断或处理方向：以下是系统化的解决方案： **1. 错误分析** **核心问题**： `S-1-15-2-...`（应用程序容器 SID）未被授权访问 `CLSID {C2F03A33-...}` 和 `APPID {316CDED5-...}` 的 DCOM 组件。**2. 解决方案** **方法 1：通过注册表修复 DCOM 权限** 1. **打开注册表编辑器**（`regedit`） → 导航至以下路径： ``` HKEY_CLASSES_ROOT\AppID\{316CDED5-E4AE-4B15-9113-7055D8

## 上下文关系

- 所属项目：498af69237-software-01
- 当前阶段：阶段2/2
- 前置切片：解决安装matlab时的报错格 License checkout failed_b249971f.md
- 后续切片：无
- 附件说明：无
