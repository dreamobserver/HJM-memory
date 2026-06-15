---
title: "026/06/02 20:02:38 ERROR - X-UI: Failed to"
source_platform: "DeepSeek"
source_file: "3xui故障诊断解决.md"
turn_start: 1
turn_end: 2
primary_category: "软件开发与技术排错"
tags:
  - "编译错误"
  - "端口映射"
project_id: "00ab82c45c-software-01"
stage: "独立主题"
previous_slice: null
next_slice: null
has_attachment: false
attachment_context_confidence: not_applicable
classification_confidence: 0.97
---

# 026/06/02 20:02:38 ERROR - X-UI: Failed to

## 问题摘要

本切片围绕“026/06/02 20:02:38 ERROR - X-UI: Failed to”展开。起始诉求是：026/06/02 20:02:38 ERROR - X-UI: Failed to upgrade WebSocket connection:websocket: request origin not allowed by Upgrader.CheckOrigin 2026/0… 后续进展或反馈是：帮我看看又炸了2026/06/03 04:16:35 ERROR - X-UI: Failure in running xray-core:exit status 255 2026/06/03 04:16:35 ERROR - XRAY: Failed to start: app…内容覆盖原始对话 T1-T2。

## 原始对话

# 用户：

026/06/02 20:02:38 ERROR - X-UI: Failed to upgrade WebSocket connection:websocket: request origin not allowed by Upgrader.CheckOrigin
2026/06/02 20:02:36 ERROR - X-UI: Failed to upgrade WebSocket connection:websocket: request origin not allowed by Upgrader.CheckOrigin
2026/06/02 20:02:30 ERROR - X-UI: Failed to upgrade WebSocket connection:websocket: request origin not allowed by Upgrader.CheckOrigin
2026/06/02 20:02:25 ERROR - X-UI: Failed to upgrade WebSocket connection:websocket: request origin not allowed by Upgrader.CheckOrigin
2026/06/02 20:02:21 ERROR - X-UI: Failed to upgrade WebSocket connection:websocket: request origin not allowed by Upgrader.CheckOrigin
2026/06/02 20:02:16 ERROR - X-UI: Failed to upgrade WebSocket connection:websocket: request origin not allowed by Upgrader.CheckOrigin
2026/06/02 20:02:11 ERROR - X-UI: Failed to upgrade WebSocket connection:websocket: request origin not allowed by Upgrader.CheckOrigin
2026/06/02 20:02:10 WARNING - X-UI: 停止Xray时发生错误。 失败: xray is not running
2026/06/02 20:02:10 ERROR - X-UI: stop xray failed:xray is not running
2026/06/02 20:02:09 ERROR - X-UI: Failed to upgrade WebSocket connection:websocket: request origin not allowed by Upgrader.CheckOrigin
2026/06/02 20:02:09 ERROR - X-UI: Failure in running xray-core:exit status 23
2026/06/02 20:02:09 ERROR - XRAY: Failed to start: main: failed to load config files: [bin/config.json] > infra/conf: failed to build inbound config with tag inbound-40481 > infra/conf: failed to build inbound handler for protocol shadowsocks > infra/conf: unsupported cipher method:
2026/06/02 20:02:09 WARNING - XRAY: common/errors: The feature Shadowsocks (with no Forward Secrecy, etc.) is deprecated, not recommended for using and might be removed. Please migrate to VLESS Encryption as soon as possible.
2026/06/02 20:02:09 WARNING - XRAY: common/errors: The feature VLESS (with no Flow, etc.) is deprecated, not recommended for using and might be removed. Please migrate to VLESS with Flow & Seed as soon as possible.
2026/06/02 20:02:09 WARNING - XRAY: common/errors: The feature VLESS (with no Flow, etc.) is deprecated, not recommended for using and might be removed. Please migrate to VLESS with Flow & Seed as soon as possible.
2026/06/02 20:02:09 INFO - XRAY: infra/conf/serial: Reading config: &{Name:bin/config.json Format:json}
2026/06/02 20:02:08 ERROR - X-UI: Failed to upgrade WebSocket connection:websocket: request origin not allowed by Upgrader.CheckOrigin
2026/06/02 20:02:07 ERROR - X-UI: Failure in running xray-core:exit status 23
2026/06/02 20:02:07 ERROR - XRAY: Failed to start: main: failed to load config files: [bin/config.json] > infra/conf: failed to build inbound config with tag inbound-40481 > infra/conf: failed to build inbound handler for protocol shadowsocks > infra/conf: unsupported cipher method:
2026/06/02 20:02:07 WARNING - XRAY: common/errors: The feature Shadowsocks (with no Forward Secrecy, etc.) is deprecated, not recommended for using and might be removed. Please migrate to VLESS Encryption as soon as possible.
2026/06/02 20:02:07 WARNING - XRAY: common/errors: The feature VLESS (with no Flow, etc.) is deprecated, not recommended for using and might be removed. Please migrate to VLESS with Flow & Seed as soon as possible.帮我看看我的3xui怎么了

# DeepSeek：

**原始回答**

专家模式暂不支持搜索，请使用快速模式从日志来看，你的 3X-UI 面板目前有**两个主要问题**，导致整个代理服务不可用。

---

### 1. 致命错误：Xray 核心启动失败  
**原因**：Shadowsocks 入站节点的**加密方式 (cipher) 不受支持**。  
日志关键行：  
```
Failed to build inbound handler for protocol shadowsocks > infra/conf: unsupported cipher method:
```
`unsupported cipher method:` 后面为空，说明配置里加密字段**为空**，或者填写了新版 Xray 已移除的过时算法。

- 该入站的标签是 `inbound-40481`。  
- 由于 Xray 无法加载此配置，状态直接 `exit status 23`，并且会反复重启失败。

**解决方法**（任选其一）：

#### 通过面板修改（如果能登录）
1. 进入 3X-UI 管理后台 → **入站列表*

n` 等 Flow）。

# 用户：

帮我看看又炸了2026/06/03 04:16:35 ERROR - X-UI: Failure in running xray-core:exit status 255
2026/06/03 04:16:35 ERROR - XRAY: Failed to start: app/proxyman/inbound: failed to listen TCP on 80 > transport/internet: failed to listen on address: 0.0.0.0:80 > transport/internet/tcp: failed to listen TCP on 0.0.0.0:80 > listen tcp 0.0.0.0:80: bind: address already in use
2026/06/03 04:16:35 WARNING - XRAY: common/errors: The feature Shadowsocks (with no Forward Secrecy, etc.) is deprecated, not recommended for using and might be removed. Please migrate to VLESS Encryption as soon as possible.
2026/06/03 04:16:35 WARNING - XRAY: common/errors: The feature VLESS (with no Flow, etc.) is deprecated, not recommended for using and might be removed. Please migrate to VLESS with Flow & Seed as soon as possible.
2026/06/03 04:16:35 WARNING - XRAY: common/errors: The feature VLESS (with no Flow, etc.) is deprecated, not recommended for using and might be removed. Please migrate to VLESS with Flow & Seed as soon as possible.
2026/06/03 04:16:35 ERROR - X-UI: Failed to upgrade WebSocket connection:websocket: request origin not allowed by Upgrader.CheckOrigin
2026/06/03 04:16:35 INFO - XRAY: infra/conf/serial: Reading config: &{Name:bin/config.json Format:json}
2026/06/03 04:16:33 ERROR - X-UI: Failed to upgrade WebSocket connection:websocket: request origin not allowed by Upgrader.CheckOrigin
2026/06/03 04:16:33 ERROR - X-UI: Failure in running xray-core:exit status 255
2026/06/03 04:16:33 ERROR - XRAY: Failed to start: app/proxyman/inbound: failed to listen TCP on 80 > transport/internet: failed to listen on address: 0.0.0.0:80 > transport/internet/tcp: failed to listen TCP on 0.0.0.0:80 > listen tcp 0.0.0.0:80: bind: address already in use
2026/06/03 04:16:33 WARNING - XRAY: common/errors: The feature Shadowsocks (with no Forward Secrecy, etc.) is deprecated, not recommended for using and might be removed. Please migrate to VLESS Encryption as soon as possible.
2026/06/03 04:16:33 WARNING - XRAY: common/errors: The feature VLESS (with no Flow, etc.) is deprecated, not recommended for using and might be removed. Please migrate to VLESS with Flow & Seed as soon as possible.
2026/06/03 04:16:33 WARNING - XRAY: common/errors: The feature VLESS (with no Flow, etc.) is deprecated, not recommended for using and might be removed. Please migrate to VLESS with Flow & Seed as soon as possible.
2026/06/03 04:16:33 INFO - XRAY: infra/conf/serial: Reading config: &{Name:bin/config.json Format:json}
2026/06/03 04:16:31 ERROR - X-UI: Failure in running xray-core:exit status 255
2026/06/03 04:16:31 ERROR - XRAY: Failed to start: app/proxyman/inbound: failed to listen TCP on 80 > transport/internet: failed to listen on address: 0.0.0.0:80 > transport/internet/tcp: failed to listen TCP on 0.0.0.0:80 > listen tcp 0.0.0.0:80: bind: address already in use
2026/06/03 04:16:31 WARNING - XRAY: common/errors: The feature Shadowsocks (with no Forward Secrecy, etc.) is deprecated, not recommended for using and might be removed. Please migrate to VLESS Encryption as soon as possible.
2026/06/03 04:16:31 WARNING - XRAY: common/errors: The feature VLESS (with no Flow, etc.) is deprecated, not recommended for using and might be removed. Please migrate to VLESS with Flow & Seed as soon as possible.
2026/06/03 04:16:31 WARNING - XRAY: common/errors: The feature VLESS (with no Flow, etc.) is deprecated, not recommended for using and might be removed. Please migrate to VLESS with Flow & Seed as soon as possible.
2026/06/03 04:16:31 INFO - XRAY: infra/conf/serial: Reading config: &{Name:bin/config.json Format:json}
2026/06/03 04:16:30 INFO - X-UI: admin logged in successfully

# DeepSeek：

**原始回答**

这次崩的原因很明确，和上次不同，但同样致命：**端口冲突**。

---

## 核心问题：80 端口被占用

日志里反复出现：
```
listen tcp 0.0.0.0:80: bind: address already in use
```
你的 **Xray 配置里有一个入站节点监听了 80 端口**，但是 80 端口已经被机器上别的程序占用了，导致 Xray 无法启动，状态码 `exit status 255`。

> 之前日志里还有 `CheckOrigin` 和弃用警告，那些都不是这次崩溃的原因，可以稍后再处理。

---

## 解决步骤

### 1. 查出是谁占用了 80 端口

SSH 连上服务器，运行：
```bash
sudo lsof -i :80
```
或者
```bash
sudo ss -tlnp | grep :80
```
你会看到类似这样的输出：
```
COMMAND   PID USER   FD   TYPE DEVICE SIZE/OFF NODE NAME
nginx    1234

## 关键结论

原对话最后阶段给出的主要判断或处理方向：原始回答** 这次崩的原因很明确，和上次不同，但同样致命：**端口冲突**。核心问题：80 端口被占用 日志里反复出现： 你的 **Xray 配置里有一个入站节点监听了 80 端口**，但是 80 端口已经被机器上别的程序占用了，导致 Xray 无法启动，状态码 `exit status 255`。

## 上下文关系

- 所属项目：00ab82c45c-software-01
- 当前阶段：独立主题
- 前置切片：无
- 后续切片：无
- 附件说明：无
