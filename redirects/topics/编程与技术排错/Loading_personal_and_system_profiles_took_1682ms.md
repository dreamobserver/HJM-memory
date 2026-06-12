# Loading personal and system profiles took 1682ms.

**分类**：编程与技术排错
**来源**：DeepSeek Chat 导出
**来源平台**：DeepSeek
**原始文件**：DeepSeek API PowerShell 中文乱码解决方案.md
**包含轮次**：12 - 12

---

# 用户：
Loading personal and system profiles took 1682ms.
┏[ 09/18/2025 @ 4:31:16 PM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 12/15GB][ 100][ 0s]
┣[ ~]
└─[#]> $PSVersionTable.PSVersion

Major  Minor  Build  Revision
-----  -----  -----  --------
5      1      22000  2538

还是不行，估计是由于我的wtsetting是有部分设置靠着settings.json实施的，可能要修改json文件json文件如下：{
    "$help": "https://aka.ms/terminal-documentation",
    "$schema": "https://aka.ms/terminal-profiles-schema",
    "actions": [],
    "centerOnLaunch": true,
    "copyFormatting": "none",
    "copyOnSelect": false,
    "defaultProfile": "{574e775e-4f2a-5b96-ac1e-a2962a402336}",
    "initialCols": 145,
    "initialRows": 45,
    "keybindings": 
    [
        {
            "id": "Terminal.CopyToClipboard",
            "keys": "ctrl+c"
        },
        {
            "id": "Terminal.PasteFromClipboard",
            "keys": "ctrl+v"
        },
        {
            "id": "Terminal.FindText",
            "keys": "ctrl+shift+f"
        },
        {
            "id": "Terminal.DuplicatePaneAuto",
            "keys": "alt+shift+d"
        }
    ],
    "launchMode": "focus",
    "newTabMenu": 
    [
        {
            "type": "remainingProfiles"
        }
    ],
    "profiles": 
    {
        "defaults": 
        {
            "backgroundImage": "D:/background/fufu.jpg",
            "backgroundImageOpacity": 0.37,
            "cursorShape": "filledBox",
            "font": 
            {
                "face": "JetBrainsMono Nerd Font"
            },
            "opacity": 90,
            "useAcrylic": true
        },
        "list": 
        [
            {
                "backgroundImageOpacity": 0.43,
                "commandline": "%SystemRoot%\\System32\\WindowsPowerShell\\v1.0\\powershell.exe",
                "cursorShape": "filledBox",
                "font": 
                {
                    "face": "JetBrainsMono Nerd Font"
                },
                "guid": "{61c54bbd-c2c6-5271-96e7-009a87ff44bf}",
                "hidden": false,
                "name": "Windows PowerShell"
            },
            {
                "commandline": "%SystemRoot%\\System32\\cmd.exe",
                "guid": "{0caa0dad-35be-5f56-a8ff-afceeeaa6101}",
                "hidden": false,
                "name": "\u547d\u4ee4\u63d0\u793a\u7b26"
            },
            {
                "guid": "{b453ae62-4e3d-5e58-b989-0a998ec441b8}",
                "hidden": false,
                "name": "Azure Cloud Shell",
                "source": "Windows.Terminal.Azure"
            },
            {
                "guid": "{fc4b1ad9-8f8f-54a7-98cd-79034141f273}",
                "hidden": false,
                "name": "Developer Command Prompt for VS 2022",
                "source": "Windows.Terminal.VisualStudio"
            },
            {
                "guid": "{7c7ed75c-5598-59a2-b4f6-4be4a9f5efbf}",
                "hidden": false,
                "name": "Developer PowerShell for VS 2022",
                "source": "Windows.Terminal.VisualStudio"
            },
            {
                "guid": "{574e775e-4f2a-5b96-ac1e-a2962a402336}",
                "hidden": false,
                "name": "PowerShell",
                "source": "Windows.Terminal.PowershellCore"
            }
        ]
    },
    "schemes": [],
    "themes": []
}

# DeepSeek：

**原始回答**
您分析得非常准确！问题就出在您的 `settings.json` 文件中。让我帮您修复这个问题。

## 🔍 问题诊断

您的 `defaultProfile` 设置为 `{574e775e-4f2a-5b96-ac1e-a2962a402336}`，这个 GUID 对应的确实是 PowerShell 7，但是：

**问题在于**：Windows Terminal 有时会错误地使用旧的 PowerShell 5.1，即使 GUID 指向的是 PowerShell 7。

## 🚀 解决方案

请按照以下步骤修改您的 `settings.json` 文件：

### 步骤 1：找到 PowerShell 7 的正确命令行路径

首先，我们需要找到您安装的 PowerShell 7 的实际路径。在终端中运行：

```powershell
where pwsh
```

或者
```powershell
Get-Command pwsh | Format-List Source
```

这会返回类似这样的路径：`C:\Program Files\PowerShell\7\pwsh.exe`

### 步骤 2：修改 settings.json

找到 PowerShell 7 的配置段（GUID 为 `{574e775e-4f2a-5b96-ac1e-a2962a402336}`），**添加明确的 `commandline` 路径**：

```json
{
    "guid": "{574e775e-4f2a-5b96-ac1e-a2962a402336}",
    "hidden": false,
    "name": "PowerShell",
    "source": "Windows.Terminal.PowershellCore",
    "commandline": "C:\\Program Files\\PowerShell\\7\\pwsh.exe"  // 添加这一行！
}
```

**请将路径替换为刚才 `where pwsh` 命令返回的实际路径**。

### 步骤 3：确保默认配置文件设置正确

确认您的 `defaultProfile` 设置是正确的：

```json
"defaultProfile": "{574e775e-4f2a-5b96-ac1e-a2962a402336}",
```

### 步骤 4：保存并测试

1. 保存 `settings.json` 文件
2. 完全关闭并重新打开 Windows Terminal
3. 现在应该直接进入 PowerShell 7 了
4. 验证版本：`$PSVersionTable.PSVersion`

## 💡 替代方案：直接修改默认配置

如果上述方法仍不工作，您可以尝试直接修改默认的 PowerShell 配置：

```json
{
    "commandline": "%SystemRoot%\\System32\\WindowsPowerShell\\v1.0\\powershell.exe",
    "guid": "{61c54bbd-c2c6-5271-96e7-009a87ff44bf}",
    "hidden": false,
    "name": "Windows PowerShell"
}
```

改为指向 PowerShell 7：

```json
{
    "commandline": "C:\\Program Files\\PowerShell\\7\\pwsh.exe",
    "guid": "{61c54bbd-c2c6-5271-96e7-009a87ff44bf}",
    "hidden": false,
    "name": "Windows PowerShell"  // 您可以改成 "PowerShell 7"
}
```

## ✅ 验证修复

修改后，打开新的 Terminal 标签页，运行：
```powershell
$PSVersionTable.PSVersion
```

现在应该显示：
```
Major  Minor  Build  Revision
-----  -----  -----  --------
7      5      3      0
```

**请先运行 `where pwsh` 找到确切的路径，然后修改 settings.json**。如果还有问题，请告诉我路径是什么，我可以帮您完善配置！

