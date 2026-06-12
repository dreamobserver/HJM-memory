# 这是一个部署在pc上的ai酒馆，如果我想使用与pc在同一个WiFi下的手机使用酒馆（使用手机输入pc的ipv4加上酒馆端口使用）要如何修改yaml

**分类**: AI工具与酒馆
**来源**: DeepSeek Chat 导出
**来源平台**: DeepSeek

---

# 用户：

这是一个部署在pc上的ai酒馆，如果我想使用与pc在同一个WiFi下的手机使用酒馆（使用手机输入pc的ipv4加上酒馆端口使用）要如何修改yaml

# DeepSeek：

**原始回答**

要让同一WiFi下的手机访问PC上的AI酒馆，你需要修改配置文件如下：

```yaml
# -- DATA CONFIGURATION --
# Root directory for user data storage
dataRoot: ./data
# -- SERVER CONFIGURATION --
# Listen for incoming connections
listen: true  # 改为true，启用网络监听
# Listen on a specific address, supports IPv4 and IPv6
listenAddress:
  ipv4: 0.0.0.0  # 保持0.0.0.0表示监听所有网络接口
  ipv6: '[::]'
# Enables IPv6 and/or IPv4 protocols. Need to have at least one enabled!
protocol:
    ipv4: true   # 确保IPv4启用
    ipv6: false  # IPv6可以保持禁用
# Prefers IPv6 for DNS. Enable this on ISPs that don't have issues with IPv6
dnsPreferIPv6: false
```

**还需要添加端口配置**（如果配置文件中没有的话）：

```yaml
# 添加端口配置
port: 8000  # 或其他你想要的端口号，比如5000、8080等
```

**完整步骤：**

1. **修改配置文件**：将 `listen: false` 改为 `listen: true`

2. **获取PC的IP地址**：
   - Windows: 在命令提示符输入 `ipconfig`，找到"无线局域网适配器 WLAN"下的IPv4地址
   - Mac/Linux: 在终端输入 `ifconfig` 或 `ip addr`

3. **在手机浏览器访问**：
   ```
   http://[PC的IP地址]:[端口号]
   ```
   例如：`http://192.168.1.100:8000`

4. **防火墙设置**：
   - 确保Windows防火墙允许该端口的传入连接
   - 或者在防火墙中为你的AI酒馆应用添加例外

**注意事项**：
- 确保手机和PC连接到同一个WiFi网络
- 如果连接不上，检查PC的防火墙设置
- 建议使用8000、8080等常用开发端口，避免使用80、443等系统端口
