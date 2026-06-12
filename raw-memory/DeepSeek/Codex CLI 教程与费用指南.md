# 用户：

最近Gemini拉了限额卡的更加死准备搞个gpt玩玩，顺便试试codex给点教程

# DeepSeek：

**原始回答**

玩 GPT 当然要试试 Codex，这玩意儿用好了确实很香，尤其是对开发者来说。

针对 Gemini 限额卡死的问题，Codex 有个好处：它用起来更像雇了个懂你代码库的副脑，而不是只回答问题的聊天机器人。定价模式也和 ChatGPT 套餐强关联，你可以根据预算和用量灵活选择[reference:0]。

### 💸 模式与费用：选哪个划算？

**1. 订阅制（最省心）**
直接使用你的 ChatGPT 付费套餐就行，开了就能用，额度会定时重置。
*   **Plus ($20/月)**：个人轻度使用，主力模型是 `GPT-5.5`[reference:1]，本地任务在 5 小时内大约能用 45-225 次，完全够日常使用[reference:2]。
*   **Pro ($200/月)**：个人重度使用，用量是 Plus 的 6 倍以上[reference:3]，还能用上最新的 `GPT-5.3-Codex` 预览版[reference:4]。
*   **Business ($25/人/月)**：团队协作首选，有 SAML SSO 等高级管理功能，你的数据默认不会拿来训练模型[reference:5]。

**2. 按量付费/API Key（最灵活）**
如果你用量不稳定，或者习惯用各种 API 中转服务，这也是个好选择。按实际用掉的 Token 付费，大约 $0.50 - $2.00 一次会话[reference:6]，适合低频但需要高灵活性的用户。

### ⚙️ 国内使用与配置

你知道的，在国内直接用 `api.openai.com` 不太行。好在 Codex CLI 支持通过配置文件 `~/.codex/config.toml` 来指定 API 端点，指向国内兼容的 API 中转服务就行[reference:7]。

**安装 Codex CLI（你得先有 Node.js 环境）**
```bash
# 推荐用 npm 全局安装
npm install -g @openai/codex

# 国内如果下载慢，可以试试 npmmirror 镜像
npm install -g @openai/codex --registry=https://registry.npmmirror.com
```
> 注意：Node.js 版本要求 >= 22[reference:8]。Windows 用户建议在 WSL 2 里用，在 PowerShell 原生环境里可能会碰到权限问题[reference:9][reference:10]。

安装完，就该配置 API 端点和 Key 了。

**第一步：创建配置文件 `~/.codex/config.toml`**
```toml
# 指向你信任的国内 API 端点
openai_base_url = "https://api.qnaigc.com/v1"
# 指定模型
model = "deepseek-v4-pro"
# 沙盒模式，允许修改项目目录里的文件
sandbox_mode = "workspace-write"
# 审批策略：遇到不确定的操作会暂停等你确认
approval_policy = "on-request"
```
> 这个配置文件里，`openai_base_url` 是关键，把 `/v1` 后面的路径填对就行[reference:11]。

**第二步：设置 API Key**
把 API Key 写到 shell 配置文件（比如 `~/.zshrc` 或 `~/.bashrc`）里，省得每次都手动输：
```bash
# 以 zsh 为例
echo 'export OPENAI_API_KEY="你的API Key"' >> ~/.zshrc
source ~/.zshrc
```
> 顺手把 `OPENAI_API_KEY` 这个变量写到 shell 配置里，用起来会方便很多[reference:12]。

**第三步：验证配置**
最后用 `codex doctor` 命令检查下，如果都绿了，就说明配置没问题[reference:13]。

### 🚀 从入门到进阶的技巧

开始用之前，建议在你的项目根目录放一个 `AGENTS.md` 文件，告诉 Codex 你的项目结构、代码风格等等，这样它能更快理解你的代码，干活也更靠谱[reference:14]。

**基础用法（入门）**
*   **直接提问**：`codex "我这个项目里 redis 是怎么连的？"`[reference:15]
*   **交互模式**：输入 `codex` 回车，进入和它慢慢聊的模式[reference:16]
*   **小修改**：`codex "给 utils/helper.js 加上错误处理逻辑"`[reference:17]

**进阶技巧（提效）**
*   **用斜杠命令切换模型**：在交互模式里输入 `/model`，可以从便宜的模型切到能跑复杂逻辑的模型[reference:18]。
*   **巧用上下文**：`codex "帮我查下昨天那个数据库连接池溢出的 bug，日志在 app.log 里"` —— 它能自己读日志、看代码、定位问题[reference:19]。
*   **直接执行任务**：`codex exec "把首页的接口响应时间优化到 500ms 以内"` —— 它会自己分析代码、改代码、甚至跑测试，一条龙服务[reference:20]。
*   **让它做 Code Review**：`codex "帮我审查下最近的提交"` —— 读 diff、找问题，比很多自动化工具都仔细[reference:21]。

### 💎 总结

总的来说，从 Gemini 转到 Codex，核心就是把这 3 点玩熟：
1.  **把 Codex 当副脑，不是答题机**：用它去理解你的整个项目，而不仅仅是回答问题。
2.  **养成看 Diff 的习惯**：它做的任何修改，你都得仔仔细细过一遍再合并，安全第一。
3.  **用好 `AGENTS.md` 和斜杠命令**：这是用好 Codex 的核心，文档写好，命令用熟，效率会高很多。

# 用户：

我现在连OpenAI账号都没有从这里开始教程

# DeepSeek：

**原始回答**

好的，我们完全从零开始。整个过程主要就三步：**① 搞定账号 → ② 搞定订阅 → ③ 搞定Codex**。我们一步步来。

### 🪜 第一步：搞定一个 ChatGPT 账号

首先要有个ChatGPT账号才能进行后续操作。

#### 1. 准备工作：搞定“两样东西”

1.  **一个合适的邮箱**：**一定不要用** QQ、163等国内邮箱，可能会收不到验证邮件。
    *   **强烈推荐用 Gmail** (谷歌邮箱) 或 **Outlook** (微软邮箱)，它们对OpenAI最友好[reference:1]。Outlook注册非常简单，甚至可能不需要手机验证，对新手特别友好[reference:2]。
2.  **一个稳定的网络环境（关键）**
    *   你需要确保全程的网络IP地址在日本、新加坡、美国等OpenAI支持的地区[reference:4]。
    *   **推荐用浏览器的无痕模式**，并全程保持网络稳定[reference:5][reference:6]。

#### 2. 开始注册：避开手机号验证这个“坑”

这是整个注册过程最核心、也最容易卡住的环节。

1.  **访问官网**：在准备好上述环境后，打开ChatGPT官网 [https://chat.openai.com](https://chat.openai.com)，点击右上角的 **“Sign up”**[reference:7]。
2.  **选择方式，完成邮箱验证**：输入邮箱和密码创建账号，然后去邮箱里点击激活链接[reference:9]。如果网络稳定，这里也会很顺利。
3.  **跨过手机号验证**：官网注册时，强烈建议点击 **“通过 Google 登录”**或 **“通过 Apple 登录”**，通常可以直接跳过短信验证码环节，是成功率最高且免费的方法[reference:10][reference:11]。
4.  **最后的备选方案**：如果运气不好，所有方法都触发了手机号验证。那么，你需要通过接码平台（如SMS-Activate）付费获取一个国外手机号来接收短信[reference:12]。
    *   **费用**：通常只需几块钱人民币[reference:13][reference:14]。
    *   **操作流程**：
        1.  注册一个接码平台账号，用支付宝充值几美元（平台有最低充值额）[reference:15]。
        2.  在平台搜索“OpenAI”服务，选择一个国家（如印尼、英国）[reference:16]。
        3.  获取一个临时手机号。
        4.  将此号码填入ChatGPT的验证页面，**注意在ChatGPT这边要选对号码对应的国家代码**。
        5.  在接码平台等待并查收验证码[reference:17]。

### 💰 第二步：搞定订阅，为 Codex 解锁额度

有了账号后，要稳定使用Codex，建议订阅会员。不同的套餐也决定了你的Codex使用额度。

#### 1. ChatGPT 套餐与 Codex 额度解析

这是目前（2026年5月）ChatGPT主要套餐的一个简单对比：

| 套餐名称 | 月费 | 功能特点 | 推荐人群 |
| :--- | :--- | :--- | :--- |
| **Free** | **$0** | 基础模型，有消息限制（如5小时10条）[reference:18][reference:19] | 偶尔体验 |
| **Go** | **$8** | 基础模型，比免费版配额高[reference:20] | 日常轻度使用 |
| **Plus** | **$20** | GPT-5.5等高级模型，**包含Codex**，无广告[reference:21] | **个人开发者首选** |
| **Pro ($100)** | **$100** | 同样包含高级模型，**Codex额度是Plus的5倍**[reference:22] | 重度编程用户 |
| **Pro ($200)** | **$200** | **Codex额度是Plus的20倍**，适合高强度使用[reference:23] | 专业/企业用户 |

> 对于个人开发者，**$20/月的 Plus 套餐**是性价比最高的起点，已完全包含Codex功能[reference:24]。Pro套餐则提供更大额度。

#### 2. 国内如何完成支付？

国内银行卡通常会被OpenAI的风控系统拦截[reference:26]。你可以通过这几种方式订阅：

*   **官方代充平台（首选推荐）**：这是目前非常流行且相对安全稳定的方式。你只需在支持微信/支付宝的代充网站购买一个ChatGPT Plus的“**充值卡密**”，然后在指定的激活网站上，自己完成兑换。**注意**：请挑选信誉好、运营时间长的平台。
*   **Google Play订阅 (安卓用户)**：在你手机上的Google Play商店下载ChatGPT应用，并通过应用内购买订阅。可以将你的Google账号地区改为**新加坡**，并绑定一张国内银行的**Visa/Mastercard**信用卡进行支付[reference:29][reference:30]。
*   **App Store内购 (苹果用户)**：如果你有**美区Apple ID**，可以通过App Store完成内购订阅。需要先为美区ID充值礼品卡[reference:31]。
*   **共享账号 (不推荐)**：多人共用一个账号，隐私无保障，有被封号风险[reference:33]。

### ⚙️ 第三步：配置 Codex CLI，火力全开

有了订阅，就可以在国内顺畅地使用Codex CLI了。

#### 1. 准备工作

*   **安装Node.js**：确保你的电脑已安装 **Node.js 18 或更高版本**[reference:34]。你可以在[Node.js官网](https://nodejs.org/)下载。
*   **获取API Key**：Codex CLI的安装和使用需要你的OpenAI **API Key**。你可以在[OpenAI API Keys页面](https://platform.openai.com/api-keys)创建并获取。
*   **准备API代理地址**：由于网络限制，你需要一个支持OpenAI协议的国内API代理地址。可以选择提供此类服务的国内云平台，或通过其他方式获得。

#### 2. 安装 Codex CLI

1.  **配置npm镜像源**：在国内，先设置npm镜像源，安装会快很多。打开终端，运行：
    ```bash
    npm config set registry https://registry.npmmirror.com
    ```

2.  **全局安装Codex**：继续在终端运行：
    ```bash
    npm install -g @openai/codex
    ```
    **安装完成后，输入 `codex --version` 并回车，如果显示版本号，就说明安装成功了**[reference:35]。

#### 3. 核心配置：让 Codex 在国内跑起来

这是最关键的一步，通过修改配置文件，让Codex连接到你准备好的国内API。

1.  **创建配置文件**：在终端执行：
    ```bash
    mkdir -p ~/.codex
    ```

2.  **编辑配置文件**：用文本编辑器（如VS Code、Sublime Text）创建并打开 `~/.codex/config.toml` 文件，复制以下内容并修改：
    ```toml
    #:schema https://developers.openai.com/codex/config-schema.json

    # ① 替换为你的国内API代理地址
    openai_base_url = "https://api.qnaigc.com/v1"

    # ② 选择模型（根据你的API代理可用模型填写）
    model = "deepseek-v4-pro"

    # ③ 沙盒模式：允许Codex修改你当前项目目录下的文件
    sandbox_mode = "workspace-write"

    # ④ 审批策略：遇到不确定的操作会暂停，等待你确认
    approval_policy = "on-request"
    ```

3.  **设置API Key环境变量**：在终端执行，将 `YOUR_OPENAI_API_KEY` 替换为你自己的API Key：
    ```bash
    # 如果你是 zsh 用户（macOS默认）
    echo 'export OPENAI_API_KEY="YOUR_OPENAI_API_KEY"' >> ~/.zshrc
    source ~/.zshrc

    # 如果你是 bash 用户（Linux默认）
    echo 'export OPENAI_API_KEY="YOUR_OPENAI_API_KEY"' >> ~/.bashrc
    source ~/.bashrc
    ```

4.  **验证配置**：最后，运行以下命令检查配置是否正确：
    ```bash
    codex doctor
    ```
    如果各项检查都显示绿色通过，就代表大功告成了！[reference:36]

#### 4. 开启你的第一个 Codex 任务

1.  在终端，导航到你的项目文件夹下。
2.  试着输入一个简单的指令，比如：
    ```bash
    codex "帮我解释一下这个项目的文件结构"
    ```
    Codex会阅读你的项目文件，并在终端给出回应。

> **小提示**：你可以在项目根目录放一个 `AGENTS.md` 文件，在里面用简单的文字说明项目是做什么的、有什么规范，Codex会自动读取，能让它更好地理解你的意图[reference:37]。

### 💎 总结

总的来说，就是这三步：用谷歌邮箱（比如 Gmail）通过免手机号验证的方式注册账号，然后通过官方代充平台订阅一个 Plus 会员来解锁额度，最后在本地配置好 Codex CLI 让它走你准备好的中转线路就可以畅快使用了。

建议先从 **Plus 套餐**开始体验，它的 Codex 额度对于个人日常使用是足够充裕的。等用一段时间后，如果觉得额度不够了，再考虑升级到 Pro 套餐也不迟。本回答由 AI 生成，内容仅供参考，请仔细甄别。