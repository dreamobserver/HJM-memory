# Windows终端管理员启动

**分类**: 编程与技术排错
**来源**: DeepSeek Chat 导出
**来源平台**: DeepSeek

---

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
     ```
     （将 `"Windows PowerShell"` 换成你的默认配置文件名称，如 `"PowerShell"` 或 `"Command Prompt"`）

2. **保存文件**，文件名为 `psadmin.bat`（注意扩展名必须是 `.bat`）。保存时在「另存为」对话框中选择「所有文件」。

3. **将文件放到系统 PATH 目录中**，例如：
   - `C:\Windows\System32`（最方便，但需要管理员权限复制进去）
   - 或者自定义文件夹（如 `C:\Scripts`），然后将该文件夹路径添加到系统环境变量 `Path` 中（步骤：右键「此电脑」→「属性」→「高级系统设置」→「环境变量」→ 编辑 `Path` → 新建 → 输入文件夹路径）。

4. **测试**：按 `Win + R`，输入 `psadmin`，回车。此时会弹出 UAC 确认窗口，确认后即可看到管理员权限的 Windows Terminal 窗口。

---

### 备选方案：使用快捷方式

如果你不想写脚本，也可以创建一个快捷方式：

1. 右键桌面 →「新建」→「快捷方式」。
2. 在「请键入对象的位置」中输入：`wt`。
3. 点击「下一步」，命名为 `psadmin`，完成。
4. 右键该快捷方式 →「属性」→「快捷方式」选项卡 →「高级」→ 勾选「用管理员身份运行」→ 确定。
5. 将 `psadmin.lnk` 文件复制到 `C:\Windows\System32` 或 PATH 目录中。

这样 Win+R 输入 `psadmin` 同样能打开管理员模式的 Windows Terminal。

---

### 注意事项
- 两种方法都会触发 UAC 提示（需要确认管理员权限），这是 Windows 的安全机制。
- 如果使用自定义 PATH 文件夹，确保文件夹路径正确且没有中文/空格，以免找不到命令。

现在，你可以像执行 `wt` 一样，通过 `psadmin` 快速启动管理员权限的 Windows Terminal 了。如果还有问题，欢迎追问！
