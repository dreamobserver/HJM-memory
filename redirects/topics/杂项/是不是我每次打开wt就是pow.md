# 是不是我每次打开wt就是pow

**分类**：杂项
**来源**：DeepSeek Chat 导出
**来源平台**：DeepSeek
**原始文件**：DeepSeek API PowerShell 中文乱码解决方案.md
**包含轮次**：10 - 10

---

# 用户：
是不是我每次打开wt就是powershell7，还是只有输入pwsh才可以使用powershell7

# DeepSeek：

**原始回答**
问得非常好！这是一个关键的使用区别。根据您刚才的测试结果，我来为您详细解释：

## 🔍 当前状态分析

从您刚才的截图来看：
```bash
└─[#]> pwsh  # 您手动输入了 pwsh 命令
PowerShell 7.5.3  # 然后才进入 PowerShell 7
```

这表明：**您的 Windows Terminal (WT) 当前默认的 Shell 还不是 PowerShell 7**，您需要手动输入 `pwsh` 来调用它。

---

## 🎯 两种使用方式的区别

| 场景 | 现在的情况 | 理想的情况（推荐） |
| :--- | :--- | :--- |
| **打开 WT 标签页** | 打开的是其他Shell（可能是CMD或PS5.1） | **直接打开的就是 PowerShell 7** |
| **需要 PowerShell 7** | 必须手动输入 `pwsh` | **无需额外操作，直接可用** |
| **体验** | 需要多一步操作 | 无缝衔接，开箱即用 |

---

## 🚀 如何设置 WT 默认使用 PowerShell 7

**强烈推荐进行这个设置**，让您每次打开 WT 都直接进入 PowerShell 7：

### 方法一：通过设置界面（图形化，推荐）

1.  **打开 Windows Terminal**
2.  􀆒 **按下 `Ctrl + ,`** 打开设置界面
3.  在左侧选择 **"启动"**
4.  找到 **"默认配置文件"** 选项
5.  点击下拉菜单，选择 **"PowerShell 7"**（通常会显示版本号）
6.  关闭设置窗口，**重启 Windows Terminal**

### 方法二：通过修改 settings.json（高级）

1.  在 WT 中按下 `Ctrl + ,` 打开设置
2.  点击左下角的 **"打开 JSON 文件"**
3.  找到 `"defaultProfile"` 字段
4.  将其值设置为 PowerShell 7 的 GUID（可以在 `profiles.list` 段中找到）
5.  保存文件并重启 WT

---

## 📋 如何确认当前使用的 PowerShell 版本

无论哪种方式，您都可以随时通过以下命令检查当前版本：

```powershell
$PSVersionTable.PSVersion
```

或者看提示符：
- **`PS C:\>`** 可能是 PowerShell 5.1 或 7
- **明确显示 `PowerShell 7.x.x`** 的就是版本7

---

## 💡 建议的设置

**推荐您将 Windows Terminal 的默认配置文件设置为 PowerShell 7**，这样：
- 每次打开新标签页都是 PowerShell 7
- 无需手动输入 `pwsh`
- 获得最佳的中文支持和现代功能
- 仍然可以随时通过下拉菜单切换到其他Shell（如CMD、PowerShell 5.1等）

需要我指导您具体如何操作吗？

