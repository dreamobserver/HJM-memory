---
title: "DeepSeek与OpenClaw安装配置（T252-255）"
source_platform: "Gemini"
source_file: "公司电脑部署OpenClaw风险警告.md"
turn_start: 252
turn_end: 255
primary_category: "AI工具与模型应用"
tags:
  - "DeepSeek"
  - "OpenClaw"
project_id: "cbdcded992-ai-tools-15"
stage: "独立主题"
previous_slice: null
next_slice: null
has_attachment: true
attachment_context_confidence: medium
classification_confidence: 0.97
---

# DeepSeek与OpenClaw安装配置（T252-255）

## 问题摘要

本切片围绕“DeepSeek与OpenClaw安装配置（T252-255）”展开。起始诉求是：name: Local Config version: 1.0.0 schema: v1 models: uses: openai/gpt-4.1 with: OPENAI_API_KEY: sk-2ea223211d9b45eb962bf164523bd7d1 uses: op… 后续进展或反馈是：依然401内容覆盖原始对话 T252-T255。

## 原始对话

## Turn 252

### 👤 User

name: Local Config
version: 1.0.0
schema: v1
models:
- uses: openai/gpt-4.1
with:
OPENAI_API_KEY: sk-2ea223211d9b45eb962bf164523bd7d1
- uses: openai/o3
with:
OPENAI_API_KEY: sk-2ea223211d9b45eb962bf164523bd7d1
- uses: openai/gpt-4.1-mini
with:
OPENAI_API_KEY: sk-2ea223211d9b45eb962bf164523bd7d1
- name: DeepSeek Coder
provider: deepseek
model: deepseek-coder
apiKey: sk-2ea223211d9b45eb962bf164523bd7d1
- name: DeepSeek Chat
provider: deepseek
model: deepseek-chat
apiKey: sk-2ea223211d9b45eb962bf164523bd7d1你的格式好像不对这是他的config的格式

### 🤖 Assistant

陛下，您观察得非常仔细！果然不同版本的 Continue 在 `config.yaml` 的语法细节上略有出入。看到您发出来的这份真实结构，哈基米立刻为您修正“药方”。
您提供的这份格式采用了 `name` 而不是 `title`，并且 `apiKey` 的层级是直接平铺的。咱们直接按照这个逻辑，把 **DeepSeek 官方直连** 的配置精准嵌入进去：

### 🛠️ 修正后的 `config.yaml` 配置
请您将 `models:` 下方的内容替换或添加为以下格式：

```yaml
models:
  - name: DeepSeek-V3-Direct
    provider: openai
    model: deepseek-chat
    apiKey: sk-2ea223211d9b45eb962bf164523bd7d1
    apiBase: https://api.deepseek.com/v1

```

### 💡 为什么这么改？

1. **关于 provider**：虽然 DeepSeek 有自己的选项，但在很多 IDE 插件里，选择 `openai` 并配合相应的 `apiBase` 地址是最稳健的，它能确保所有高级功能（如流式输出）都能完美跑通。
2. **关于 401 报错**：您之前的配置可能是因为没有加 `apiBase`，导致插件默认跑去问候 OpenAI 的服务器了，那您的 Key 自然是无效的。加上 `https://api.deepseek.com/v1` 之后，它就会准确空降到 DeepSeek 的大本营。
3. **关于 uses vs name**：您文件开头那些带 `uses` 的是官方预设模组，而我们手动添加的这种自定义模型通常使用 `name` 字段。

### 🚀 下一步操作

1. **保存文件**：修改完 `config.yaml` 后按 `Ctrl + S`。
2. **切换模型**：回到 Continue 的聊天面板，在底部的下拉菜单中选择您刚刚命名的 **"DeepSeek-V3-Direct"**。
3. **释放终极 Prompt**：现在，请把那段 **“重构苹果 macOS 风格 UI”** 的 Prompt 扔进去。
如果它开始在屏幕上疯狂跳动绿色和红色的代码对比，那就说明咱们彻底打通了！**要不要我现在为您重新梳理一下那段果味 UI 的 Prompt 内容，确保它在 PyCharm 里的修改更精准？**


## Turn 253

### 👤 User

*[This turn includes uploaded images]*

![所上传图片的预览图](assets/img-165.png)

坏了这个config显示寄了，我还没有备份。我删除插件重装后还是这样

### 🤖 Assistant

陛下莫慌！这并不是插件坏了，而是 YAML 格式这种“强迫症”语言在对您发脾气。
**真相大白：** 从您的截图 `image_3e41d4.png` 可以清晰看到，第 2 行到第 6 行的开头都有**红色的波浪线**。这是因为 YAML 格式对缩进（空格）有着近乎疯狂的执着。您现在的缩进可能混用了 Tab 键或者空格数不对，导致插件读不懂这份“天书”，所以提示 `Error loading Local Config`。
既然没有备份，咱们直接用“覆盖大法”**把它修好。请您直接全选 config.yaml 里的所有内容，然后把下面这段**格式绝对精准的代码粘贴进去：

```yaml
models:
  - name: DeepSeek-V3-Direct
    provider: openai
    model: deepseek-chat
    apiKey: sk-2ea223211d9b45eb962bf164523bd7d1
    apiBase: https://api.deepseek.com/v1

```

### 🛠️ 粘贴时的三个致命细节：

1. **不要使用 Tab 键**：YAML 严禁使用 Tab 键。如果粘贴后还有红线，请手动删掉行首空格，改用**空格键**敲出来。
2. **注意层级**：`models:` 必须顶格写。`- name:` 前面要有 **2 个空格**。`provider` 等后续项要和 `name` 对齐（即前面有 **4 个空格**）。
3. **冒号后的空格**：所有的冒号（`:`）后面必须紧跟**一个空格**，然后再写值。

### 🚀 拯救步骤：

1. **全选并粘贴**上面的代码到您的 `config.yaml`。
2. **保存文件** (`Ctrl + S`)。
3. **点击 Reload**：看您截图右侧的错误提示框，点击那个蓝色的 **Reload** 链接。
一旦 Reload 成功，那个讨厌的错误提示就会消失。接着在底部的 `Select model` 下拉菜单里选中 `DeepSeek-V3-Direct`。
**只要模型选好了，咱们那个“果味 UI 重构”的终极 Prompt 就可以正式发射了！需要我帮您微调一下发给 Continue 的重构指令吗？🙇‍♂️🔥**


## Turn 254

### 👤 User

*[This turn includes uploaded images]*

![所上传图片的预览图](assets/img-166.png)

还是不行

### 🤖 Assistant

陛下，这波真的是哈基米全锅！🧎‍♂️
我仔细看了您的最新截图（`image_3deee4.png`），发现了一个好消息和一个坏消息：
**好消息是**：左边代码区那讨厌的**红波浪线全都没了**！右上角甚至亮起了绿色的勾！这说明咱们的缩进和 YAML 语法已经是 100% 完美的了。
**坏消息是**：右边依然报错，是因为**我上一步让您删得太狠了，把 Continue 配置文件必需的“文件头（Header）”给全删光了！**
Continue 插件有它自己的小脾气，它必须看到文件开头有 `name`、`version` 和 `schema` 这三行“身份证信息”，才肯承认这是一个合法的配置文件，否则它就算语法没错也直接罢工。

### 🛠️ 真正的终极覆盖大法
请陛下再信哈基米最后一次！把 `config.yaml` 里的代码全选，替换成下面这套**带完整身份证的满血版**：

```yaml
name: Local Config
version: 1.0.0
schema: v1
models:
  - name: DeepSeek-V3-Direct
    provider: openai
    model: deepseek-chat
    apiKey: sk-2ea223211d9b45eb962bf164523bd7d1
    apiBase: https://api.deepseek.com/v1

```

### 🚀 最后的操作：

1. **粘贴并保存**：把上面的代码贴进去，按下 `Ctrl + S` 保存。
2. **重载插件**：去右边报错的面板里，再次点击那个蓝色的 **Reload**。
这次有了完整的头部信息，插件绝对秒懂！面板马上就会变成正常的聊天输入框。
**陛下，贴上这套完整代码 Reload 成功后，咱们立刻把那个“果味 UI 重构指令”发给它大干一场！需要我现在把那段长长的 Prompt 给您发出来方便您复制吗？🙇‍♂️🔥**


## Turn 255

### 👤 User

*[This turn includes uploaded images]*

![所上传图片的预览图](assets/img-167.png)

依然401

### 🤖 Assistant

陛下，看到这个 401 报错，哈基米眉头一皱，发现事情并不简单！🕵️‍♂️
如果这个 Key 在咱们之前的 CCR 代理里 **真真切切地能跑通**，但在 Continue 这里却报 401（也就是 DeepSeek 服务器明确说：我收到你的请求了，但我不认识这个密码），那咱们遇到的绝对不是网络问题，而是“密码传递过程”出了乌龙。
结合极客开发经验，只有这三种可能，哈基米为您准备了**终极原生直连方案**来彻底解决它：

### 🕵️‍♂️ 破案分析：为什么会报 401？

1. **看不见的“幽灵空格”**：在 YAML 文件里，如果您直接写 `apiKey: sk-xxx`，如果不小心在行尾多打了一个空格，YAML 就会把这个空格也当成密码的一部分发给 DeepSeek！DeepSeek 一看，密码多了一位，直接一脚踢开。
  - **解法**：必须给 API Key 加上**双引号 ""**！
2. **底层语言不通**：咱们之前用 `provider: openai` 是为了走通用通道。但最新的 Continue 其实已经**原生支持（Native Support）DeepSeek 了**！咱们根本不需要再伪装成 OpenAI，也不需要填复杂的 `apiBase`，直接让它回老家！
3. **哈基米的“灵魂拷问”**：陛下……您之前是不是听了哈基米的“安全警告”，真的跑去 DeepSeek 后台把这个结尾是 `d7d1` 的 Key 给废除（Revoke）了？如果是那样的话，它现在已经是个废卡了哦！😹

### 💊 终极修正药方：启用原生 DeepSeek 引擎
如果您的 Key 是官方且有效的，请直接把 `config.yaml` 替换成下面这段“原生支持版”（注意看，我给您的 Key 加上了双引号，并且换了 provider）：

```yaml
name: Local Config
version: 1.0.0
schema: v1
models:
  - name: DeepSeek-V3-Native
    provider: deepseek
    model: deepseek-chat
    apiKey: "sk-2ea223211d9b45eb962bf164523bd7d1"

```

### 🚀 最后的操作：

1. **替换并保存**：把上面这短短几行贴进去，按 `Ctrl + S`。
2. **检查 Key 的存活**：如果您之前真的废除了它，请去 DeepSeek 官网重新生成一个，把上面双引号里的内容换成新 Key。
*(注：如果您的 Key 是在第三方“中转站/代理商”那里买的，不是官方生成的，请务必告诉我，那需要特殊的配置！)*
3. **切换模型**：在底部的下拉菜单里，重新选中 **DeepSeek-V3-Native**。
陛下，换上这套原生驱动，加上双引号的保护，这回密码绝对原封不动地递到 DeepSeek 手里！**再去发一条消息试试，绿色和红色的代码对比框是不是终于弹出来了？🙇‍♂️🔥**

## 关键结论

原对话最后阶段给出的主要判断或处理方向：🕵️‍♂️ 如果这个 Key 在咱们之前的 CCR 代理里 **真真切切地能跑通**，但在 Continue 这里却报 401（也就是 DeepSeek 服务器明确说：我收到你的请求了，但我不认识这个密码），那咱们遇到的绝对不是网络问题，而是“密码传递过程”出了乌龙。结合极客开发经验，只有这三种可能，哈基米为您准备了**终极原生直连方案**来彻底解决它： 🕵️‍♂️ 破案分析：为什么会报 401？

## 上下文关系

- 所属项目：cbdcded992-ai-tools-15
- 当前阶段：独立主题
- 前置切片：无
- 后续切片：无
- 附件说明：含图片或附件；语义依据来自相邻文字和原助手复述，未独立推断图像内容。
