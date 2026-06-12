# 026/06/02 20:02:38 ERROR - X-UI: Failed to upgrade WebSocket connection:websocke

**分类**: 编程与技术排错
**来源**: DeepSeek Chat 导出
**来源平台**: DeepSeek

---

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
1. 进入 3X-UI 管理后台 → **入站列表**。
2. 找到标签为 `inbound-40481` 的节点，点击**编辑**。
3. 检查 **“加密方式”** 一栏。如果为空，必须选择一个（如 `aes-256-gcm`、`aes-128-gcm` 或 `chacha20-ietf-poly1305`）；若已选择但仍旧报错，可尝试更换为 `aes-256-gcm`。
4. 保存后**重启 Xray**。

#### 通过命令行直接修复（面板也进不去时）
3X-UI 的配置存在 SQLite 数据库中，可以直接更新：
```bash
# 停止 x-ui
systemctl stop x-ui

# 编辑数据库（默认 /etc/x-ui/x-ui.db）
sqlite3 /etc/x-ui/x-ui.db

# 查看有问题的入站（确认标签）
SELECT id, remark, protocol, settings FROM inbounds WHERE tag='inbound-40481';

# 把加密方式修改为 aes-256-gcm（假设记录 id 为 1，请用上一步查到的实际 id）
UPDATE inbounds SET settings = json_set(settings, '$.method', 'aes-256-gcm') WHERE id=1;

# 退出 sqlite
.quit

# 重启 x-ui
systemctl start x-ui
```

#### 彻底删除重建（最简单）
如果确认该节点可以丢弃，直接删除它：
```bash
sqlite3 /etc/x-ui/x-ui.db "DELETE FROM inbounds WHERE tag='inbound-40481';"
systemctl restart x-ui
```
删除后 Xray 即可正常启动。

---

### 2. 次要错误：WebSocket 升级被拒绝 (CheckOrigin)
日志中大量出现：
```
Failed to upgrade WebSocket connection: request origin not allowed by Upgrader.CheckOrigin
```
这是指 **3X-UI 面板自身的 WebSocket 连接**被拦截，不是你代理节点的 WebSocket。通常因为：
- 你使用了**域名 + CDN / Nginx 反向代理**访问面板，但请求中的 `Origin` 头与面板允许的不符。
- 面板默认开启了 `CheckOrigin` 安全策略。

这会导致管理页面**无法实时连接**（页面打开空白或持续转圈），但**不影响代理**。而你现在因为核心都没起来，面板连接错误会更频繁。

**解决方法**：
- 在面板**设置 → 面板设置**中，找到 **“WebSocket 安全检查 (CheckOrigin)”** 或类似选项，将其**关闭**（或改为 `false`）。
- 如果已经进不去面板，可以直接修改配置文件 `/etc/x-ui/x-ui.db` 或 `/usr/local/x-ui/bin/config.json`（取决于版本），添加：
  ```json
  "webServer": {
    "checkOrigin": false
  }
  ```
  若使用的是新版 3X-UI，可以直接执行：
  ```bash
  sqlite3 /etc/x-ui/x-ui.db "UPDATE settings SET value='{\"checkOrigin\": false}' WHERE key='webServer';"
  systemctl restart x-ui
  ```
  或者通过环境变量启动：`XUI_CHECK_ORIGIN=false`。

---

### 当前最紧急的步骤
1. **先修复 Xray 配置**（删除或修正那个 Shadowsocks 入站的加密方法）。
2. 看到 `xray is not running` 错误消失，状态变为运行中。
3. 如果面板仍然因为 WebSocket Origin 被拦无法使用，再按上面方法关闭 CheckOrigin。

注意：日志中还有 `VLESS (with no Flow)` 和 `Shadowsocks` 的弃用警告，这些暂时只是提醒，不影响当前运行，可后续按建议升级配置（VLESS 加上 `xtls-rprx-vision` 等 Flow）。


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
nginx    1234 root    6u  IPv4  12345      0t0  TCP *:80 (LISTEN)
```
记下 **进程名** 和 **PID**。

### 2. 根据情况处理

#### 情况 A：是你安装的其他 Web 服务（Nginx、Apache、Caddy 等）

如果你这台机器**只用来跑 Xray**，可以停掉并禁用那个 Web 服务：
```bash
sudo systemctl stop nginx   # 替换成实际的服务名
sudo systemctl disable nginx
```
然后重启 Xray（或 x-ui）：
```bash
sudo systemctl restart x-ui   # 或 xray
```

#### 情况 B：你想保留那个 Web 服务，让 Xray 换端口

那就需要把 **Xray 配置里占用 80 端口的入站节点** 的端口改成别的（比如 8080 或 443）。  
登录 3X-UI 面板 → 入站列表 → 找到监听 `80` 端口的节点 → 编辑 → 修改端口 → 保存 → 重启 Xray。

#### 情况 C：是另一个残留的 Xray 进程占着端口

可能有僵尸 Xray 进程，先杀掉再启动：
```bash
sudo kill -9 <PID>   # 填你查到的进程号
```
然后正常重启。

---

## 还是进不去面板？顺手解决上次的 CheckOrigin 问题

因为 `CheckOrigin` 报错还没修复，如果你连面板都打不开，可以用命令行直接**关闭安全策略**，重启后就能正常访问：

```bash
sqlite3 /etc/x-ui/x-ui.db "UPDATE settings SET value='{\"checkOrigin\": false}' WHERE key='webServer';"
systemctl restart x-ui
```
（如果数据库路径不是 `/etc/x-ui/x-ui.db`，用 `find / -name x-ui.db` 找一下）

---

## 小结
1. **端口冲突是主因** → 查占用 → 停服务或改端口。
2. **WebSocket 错误是次因** → 关掉 CheckOrigin 让面板恢复。
3. 修复后看到 `Xray started successfully` 就代表活了。

如果查端口时发现是别的未知程序，把输出贴出来，我帮你看该不该停。
