---
title: "NovelAI本地部署与ComfyUI-CNB模型管理：终于等到logs的报错了帮我看看（\u001b[1"
source_platform: "Gemini"
source_file: "哈基米评价川普排序算法.md"
turn_start: 19
turn_end: 20
primary_category: "AI工具与模型应用"
tags:
  - "ComfyUI"
  - "API"
  - "端口映射"
project_id: "bda3d1497e-ai-tools-01"
stage: "阶段4/4"
previous_slice: "NovelAI本地部署与ComfyUI-CNB模型管理（T16-18）_9e378658.md"
next_slice: null
has_attachment: true
attachment_context_confidence: medium
classification_confidence: 0.97
---

# NovelAI本地部署与ComfyUI-CNB模型管理：终于等到logs的报错了帮我看看（[1

## 问题摘要

本切片围绕“NovelAI本地部署与ComfyUI-CNB模型管理：终于等到logs的报错了帮我看看（[1”展开。起始诉求是：终于等到logs的报错了帮我看看（[1m[33m[WARNING][0m [DEPRECATION WARNING] Detected import of deprecated legacy API: /scripts/ui.js. This is likely cause… 后续进展或反馈是：哈基米这个普通文生图可以运行是不是我要整两个后端？内容覆盖原始对话 T19-T20。

## 原始对话

## Turn 19

### 👤 User

终于等到logs的报错了帮我看看（[1m[33m[WARNING][0m [DEPRECATION WARNING] Detected import of deprecated legacy API: /scripts/ui.js. This is likely caused by a custom node extension using outdated APIs. Please update your extensions or contact the extension author for an updated version.
[1m[33m[WARNING][0m [DEPRECATION WARNING] Detected import of deprecated legacy API: /extensions/core/widgetInputs.js. This is likely caused by a custom node extension using outdated APIs. Please update your extensions or contact the extension author for an updated version.
[1m[33m[WARNING][0m [DEPRECATION WARNING] Detected import of deprecated legacy API: /extensions/core/clipspace.js. This is likely caused by a custom node extension using outdated APIs. Please update your extensions or contact the extension author for an updated version.
[1m[33m[WARNING][0m [DEPRECATION WARNING] Detected import of deprecated legacy API: /scripts/ui/components/buttonGroup.js. This is likely caused by a custom node extension using outdated APIs. Please update your extensions or contact the extension author for an updated version.
[1m[33m[WARNING][0m [DEPRECATION WARNING] Detected import of deprecated legacy API: /extensions/core/groupNode.js. This is likely caused by a custom node extension using outdated APIs. Please update your extensions or contact the extension author for an updated version.
[VibeVoice] Created vibevoice models directory: /workspace/comfyui/models/vibevoice
[VibeVoice] No LoRA adapters found in ComfyUI/models/vibevoice/loras
[1m[33m[WARNING][0m Resolved SeedVR2 models via node registry: 6 models.
[1m[33m[WARNING][0m Resolved SeedVR2 default via node registry: seedvr2_ema_3b_fp8_e4m3fn.safetensors
[1m[33m[WARNING][0m Resolved SeedVR2 models via node registry: 6 models.
[1m[33m[WARNING][0m Resolved SeedVR2 default via node registry: seedvr2_ema_3b_fp8_e4m3fn.safetensors
[32m[INFO][0m [WaveSpeed Config] API key deleted via settings）

### 🤖 Assistant

陛下，臣仔细看了您发来的这份“报错”日志，必须要先给您吃一颗定心丸：**这份日志里根本没有致命的报错（ERROR）！这是一份极其“健康”的启动日志！**
您苦等来的这些黄字，其实都是纸老虎。请容臣为您逐条拆解，看看它们到底在说什么：

### 🟡 第一部分：满屏的 `[DEPRECATION WARNING]`（弃用警告）
Detected import of deprecated legacy API...
- **这是什么：** ComfyUI 最近对它的网页前端代码（UI）进行了一次大升级。而您安装的一些自定义节点（插件）还在使用老版本的代码接口（比如 `ui.js`, `clipspace.js`）。
- **有什么影响：****完全没有影响！** 这就像是系统在唠叨：“哎呀，这几个插件用的零件太老了，以后可能会不兼容哦。” 但在当下，它们依然能正常干活，绝对不会导致您的 NSFW 生图失效。
- **怎么处理：** 直接**无视**。如果您有强迫症，可以去 ComfyUI 的管理器（Manager）里点一下 `Update All`（更新全部插件），等插件作者更新了代码，这些黄字自然就消失了。

### 🟢 第二部分：`[VibeVoice]` 与 `SeedVR2` 的加载汇报
Created vibevoice models directory... No LoRA adapters found... Resolved SeedVR2 models via node registry...
- **这是什么：** 这是两个音视频相关的节点在向您“打卡汇报”。VibeVoice 告诉您它建好了一个文件夹，但里面目前没有附加模型（LoRA）；SeedVR2 告诉您它成功找到了 6 个模型并设置了默认值。
- **有什么影响：** 这是再正常不过的启动流水账，说明这两个节点**加载非常成功**。

### 🟢 第三部分：`[WaveSpeed Config]` 提示
API key deleted via settings
- **这是什么：** WaveSpeed 节点提示它的 API 密钥被清空或未设置。
- **有什么影响：** 只要您当前没有在使用 WaveSpeed 相关的特定付费云端功能，这条提示就没有任何意义，直接略过即可。

### 👑 臣的诊断总结
陛下，这段日志非但没有报错，反而证明了您的云端大阵此刻**运转极其平稳，各路法宝都已安然就位**。
如果您在《墨色江湖》中依然遇到“生图失效”或者出图卡住的问题，**病根绝对不在您截取的这段日志里**。导致生图失败的真正元凶，大概率是以下两种情况之一，您可以在运行时留意：

1. **出图瞬间的报错：** 只有当您在游戏里发出“生图”指令的那一瞬间，终端里突然跳出来的带 `[ERROR]` 或者 `Traceback` 的红字，才是真正的死因（通常是显存爆了或者节点连错了）。
2. **网络通道又被封印：** 就像上一回合那样，如果 ComfyUI 后台根本没收到指令（终端里静悄悄的连个水花都没有），那就是浏览器的 CORS 跨域插件没生效，或者 CNB 的地址又变了。


## Turn 20

### 👤 User

*[This turn includes uploaded images]*

![所上传图片的预览图](assets/img-017.png)

哈基米这个普通文生图可以运行是不是我要整两个后端？

### 🤖 Assistant

陛下，臣可以无比肯定地回答您：**绝对不需要整两个后端！** 您在云端搭建的这套 Z-Image-Turbo 绝世大阵，法力无边，既能画清风明月（普通图），也能画翻云覆雨（NSFW），它一个就能把所有的活儿全包了！
您现在碰到的，完全是《墨色江湖》这个前端系统设下的“逻辑结界”。请容臣为您拆解这个报错框里的玄机：

### 👁️ 破阵关键：看懂系统的“双重标准”
游戏报错里写得很清楚：“*请确认主文生图后端不是 OpenAI/Gemini... 或者开启 NSFW 独立接口*”。
这说明游戏系统是个“死脑筋”，它有两套逻辑：

1. **主通道（普通文生图）：** 陛下说普通生图可以运行，请问您在页面**最上方**的“主文生图后端”选的是什么？如果是选了类似 OpenAI、Gemini、智谱这类“正规军”API，系统就会默认“哦，主通道是太监，画不了涩图”。
2. **暗道（NSFW 独立接口）：** 如果主通道画不了，系统就要求您必须**显式地打开一个开关**，告诉它：“我要走暗道画 NSFW！”

### 🗡️ 臣的破阵两策（任选其一即可解决）
陛下，既然咱们的 CNB 云端大阵什么都能画，咱们直接用最霸道的办法接管它：

#### 🥇 上策：一统江湖（最推荐，最省事）
既然您的 CNB 接口又快又好，为什么不让它把普通图也包揽了呢？

1. 请您在这个设置页面**往上滑**，找到最上面的【主文生图后端】配置区。
2. 把主后端也选为 **ComfyUI**。
3. 把您的 CNB 地址 `https://j3rxd5ritf-8188.cnb.run` 填到主接口地址里。
4. **神奇的事情发生了：** 一旦主接口变成了 ComfyUI，系统就知道您有能力画 NSFW 了。您甚至可以把下面这个专门的 NSFW 独立设置给**关掉或留空**，游戏会自动用主接口把所有尺度的图全画出来！

#### 🥈 下策：明修栈道，暗度陈仓（保留双后端）
如果您就是想用别的 AI 画普通风景，非要用 CNB 专攻 NSFW：

1. 请仔细看您截图的右上角（就在“测试 NSFW 连接”按钮的右上方、那段文字说明的旁边）。
2. 那里隐约有一个“独立接口”的拨动开关（Toggle），它现在极有可能是关闭状态（暗色）！
3. **把那个开关点亮（开启）！**
4. 只有打开了那个总闸，系统才会承认您下面填写的这串 CNB 网址，报错就会瞬间消失。
陛下，这已经是纯粹的 UI 界面设置问题了。云端大阵早已饥渴难耐，快去把游戏里的“主接口”换成它，或者把“暗道开关”打开，直接享受出图的快感吧！

---

*Exported from [Voyager](https://github.com/Nagi-ovo/gemini-voyager)*  
*Generated on June 10, 2026 at 09:29 AM*

## 关键结论

原对话最后阶段给出的主要判断或处理方向：陛下，臣可以无比肯定地回答您：**绝对不需要整两个后端！这说明游戏系统是个“死脑筋”，它有两套逻辑： 1. **主通道（普通文生图）：** 陛下说普通生图可以运行，请问您在页面**最上方**的“主文生图后端”选的是什么？

## 上下文关系

- 所属项目：bda3d1497e-ai-tools-01
- 当前阶段：阶段4/4
- 前置切片：NovelAI本地部署与ComfyUI-CNB模型管理（T16-18）_9e378658.md
- 后续切片：无
- 附件说明：含图片或附件；语义依据来自相邻文字和原助手复述，未独立推断图像内容。
