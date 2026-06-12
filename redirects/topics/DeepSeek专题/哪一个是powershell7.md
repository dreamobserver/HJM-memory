# 哪一个是powershell7

**分类**：DeepSeek专题
**来源**：DeepSeek Chat 导出
**来源平台**：DeepSeek
**原始文件**：DeepSeek API PowerShell 中文乱码解决方案.md
**包含轮次**：11 - 11

---

# 用户：
哪一个是powershell7

# DeepSeek：

**原始回答**
从您的截图来看，**最后一个选项 `PowerShell` 就是 PowerShell 7**。

## 🔍 如何确认

在 Windows Terminal 的下拉列表中：

- **`Windows PowerShell`** → 这是旧的 **PowerShell 5.1**
- **`PowerShell`** (没有"Windows"前缀) → 这就是 **PowerShell 7**

## 🚀 设置默认值

**推荐您这样设置：**

1.  打开 Windows Terminal
2.  按下 `Ctrl + ,` 打开设置
3.  在左侧选择「启动」
4.  在「默认配置文件」中，选择 **`PowerShell`**（就是您截图中的最后一个选项）
5.  关闭设置并重启 Terminal

这样设置后，**每次打开 Windows Terminal 都会自动进入 PowerShell 7**，您就不再需要手动输入 `pwsh` 了。

## ✅ 验证方法

设置完成后，打开新的 Terminal 窗口，直接输入：
```powershell
$PSVersionTable.PSVersion
```
如果显示的主版本号是 **7**（如 7.5.3），就说明设置成功了！

现在您的 DeepSeek API 集成应该能够完美显示中文了！🎉

