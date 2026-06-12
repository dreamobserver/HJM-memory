# 给我造个小脚本。使得我在Win11上可以使用win+r输入“psadmin”打开powershell的管理员模式

**分类**: 编程与技术排错
**来源**: DeepSeek Chat 导出
**来源平台**: DeepSeek

---

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
     ```

2. **保存并命名**  
   将文件保存为 `psadmin.bat`（注意扩展名必须是 `.bat`，而不是 `.txt`）。保存时在「另存为」对话框中选择「所有文件」，然后输入文件名 `psadmin.bat`。

3. **放置到 PATH 目录**  
   将 `psadmin.bat` 放到任何一个系统环境变量 `PATH` 包含的文件夹中，例如：
   - `C:\Windows\System32`（最简单，但需要管理员权限才能复制进去）
   - 或者自己新建一个文件夹（如 `C:\Scripts`），并将其添加到系统 PATH 中（具体步骤见下文）。

4. **添加到 PATH（如果使用自定义文件夹）**  
   - 右键「此电脑」→「属性」→「高级系统设置」→「环境变量」。
   - 在「系统变量」或「用户变量」中找到 `Path` 变量，双击编辑，点击「新建」，输入你的文件夹路径（如 `C:\Scripts`），然后确定。

5. **测试**  
   按 `Win + R`，输入 `psadmin`，回车。此时会弹出 UAC 确认窗口，确认后即可看到管理员模式的 PowerShell 窗口。

---

### 方法二：使用 PowerShell 脚本（需要调整执行策略）
1. **创建脚本文件**  
   新建文本文件，内容如下：
   ```powershell
   Start-Process powershell -Verb RunAs
   ```
   保存为 `psadmin.ps1`。

2. **放置到 PATH 目录**（同方法一中的步骤 3 和 4）。

3. **调整 PowerShell 执行策略**  
   默认情况下，Windows 禁止运行 `.ps1` 脚本。你需要以管理员身份打开 PowerShell 并执行：
   ```powershell
   Set-ExecutionPolicy RemoteSigned -Scope CurrentUser
   ```
   这样只影响当前用户，且允许运行本地脚本。

4. **测试**  
   Win+R 输入 `psadmin`，回车。如果执行策略正确，也会启动管理员 PowerShell。

---

### 方法三：使用快捷方式（简单直接）
1. **创建快捷方式**  
   - 右键桌面或任意文件夹 →「新建」→「快捷方式」。
   - 在「请键入对象的位置」中输入：  
     `powershell.exe`
   - 点击「下一步」，命名为 `psadmin`，完成。

2. **设置以管理员身份运行**  
   - 右键刚创建的快捷方式 →「属性」→「快捷方式」选项卡。
   - 点击「高级」，勾选「用管理员身份运行」，确定。

3. **放置到 PATH 目录**  
   将快捷方式文件 `psadmin.lnk` 复制到 PATH 中的某个文件夹（如 `C:\Windows\System32`）。

4. **测试**  
   Win+R 输入 `psadmin`，回车。UAC 提示后即可打开管理员 PowerShell。

---

### 注意事项
- 无论哪种方法，都会触发 UAC（用户账户控制）提示，需要你确认或输入管理员密码。
- 如果选择将脚本放入 `C:\Windows\System32`，可能需要管理员权限才能复制进去。
- 如果使用自定义 PATH 文件夹，确保文件夹路径正确且没有空格或中文（避免潜在问题）。

选择你最喜欢的方法，完成后就能通过 Win+R 快速打开管理员 PowerShell 了。


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
- Win+R 输入 `psadmin` 回车，即可触发 UAC 确认，打开管理员 PowerShell。

---

### 方案二：在 Windows Terminal 中以管理员身份打开 PowerShell 标签页（推荐，体验更现代）
如果你已安装 Windows Terminal（Win11 通常自带或可通过商店安装），并希望 `psadmin` 直接打开一个**管理员权限的 Windows Terminal**，并在其中默认显示 PowerShell 标签页，可以使用这个脚本：

**脚本内容（`psadmin.bat`）：**
```batch
@echo off
powershell -Command "Start-Process wt -Verb RunAs -ArgumentList '-p \"Windows PowerShell\"'"
```
- 如果你安装的是 PowerShell 7（`pwsh.exe`），可以将 `"Windows PowerShell"` 改为 `"PowerShell"`（取决于你的 Windows Terminal 配置文件名称）。

**原理：**
- `Start-Process wt -Verb RunAs` 以管理员身份启动 Windows Terminal。
- `-ArgumentList '-p \"Windows PowerShell\"'` 告诉 Windows Terminal 启动后直接打开名为“Windows PowerShell”的配置文件标签页。

**使用方法同上**：保存为 `.bat` 文件，放到 PATH 目录，然后 Win+R 输入 `psadmin` 运行。

---

### 补充说明
1. **UAC 提示不可避免**：无论哪种方式，启动管理员权限的程序都会触发 UAC 确认（除非你完全关闭 UAC，但不建议）。
2. **Windows Terminal 配置文件名**：你的 Windows Terminal 中 PowerShell 配置文件的名称可能不是默认的“Windows PowerShell”。你可以在 Windows Terminal 的下拉菜单中查看，或者打开设置 → 配置文件，找到对应的名称（例如可能是“PowerShell”或“命令提示符”等）。根据实际名称调整脚本中的 `-p` 参数。
3. **备用方案**：如果你没有 Windows Terminal，或者想保留一个简单的管理员 PowerShell 入口，直接使用方法一即可。

这样，你就能像运行 `wt` 一样，通过 `psadmin` 快速打开管理员权限的 PowerShell 环境了。如果遇到任何问题，欢迎随时追问！
