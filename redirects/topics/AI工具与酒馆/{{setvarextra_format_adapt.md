# {{setvar::extra_format_adapt::

**分类**：AI工具与酒馆
**来源**：DeepSeek Chat 导出
**来源平台**：DeepSeek
**原始文件**：分析CSS问题竹子和场景特写.md
**包含轮次**：10 - 13

---

# 用户：
{{setvar::extra_format_adapt::

//美化数据状态栏 孝子侍母/背德攻略版 (Universal YAML Status Bar)
- 状态栏用于显示苏玉娘当前的道德防线、{{user}}的生理侵略以及环境风险，具有全局视角。

- ⚠️ 【MVU系统绝对共存指令】（生死线·最高优先级）：
  1. 本卡片同时运行着 <Status_block> 状态栏系统和 <UpdateVariable> 底层变量系统。
  2. 你的回复必须严格遵循以下【排队输出顺序】，绝对不允许互相覆盖、绝不允许遗漏任何一个标签：
     [第一部分]：你的正文剧情描述、小剧场与角色对话（可放在 <maintext> 内）。
     [第二部分]：输出完整的 <Status_block> ... </Status_block> 状态栏。
     [第三部分]：输出完整的 <UpdateVariable> ... </UpdateVariable> 变量结算代码！
  3. <UpdateVariable> 必须、永远、绝对要垫底，作为回复的最后一部分！

- ⚠️ 【状态栏格式预设】：
  1. 绝对禁止在 <Status_block> 内部使用 ```yaml 等代码块语法！必须纯文本直接输出！
  2. 每次必须根据剧情最新进展，重新计算模板内的数值。
  3. 背景设定：{{user}}是禹川，苏玉娘是主母（母亲）。{{user}}利用表面懵懂与惊人的肉体本钱，不断瓦解母亲的道德防线，将其拖入背德深渊。

- 请严格输出以下结构：

<Status_block>
状态栏:
  环境与风险:
    时间: "[填入最新时刻] "
    地点: "[填入当前地点]"
    戒备: "[根据林杏儿等丫鬟/家丁的动向填写] "
    暴露风险: "[重新评估百分比] (原因说明) "
  用户列表:
    - 用户:
        名字: "苏玉娘 (身份: 主母/母亲) "
        理智防线: "[阶段:根据最新情况评估她的背德感与负罪感] "
        威严: "[重新评估百分比，越低越堕落] "
        生理: "[体质状况] | 怀孕概率: [根据进度重新评估] "
        下体: "[根据当前生理接触与心理活动，重新描写蜜液与紧绷状态，15字左右] "
        欲求: "[重新评估百分比] "
        穿搭: "[当前衣物状况，若被脱下需更新] "
        最近行为:
          - 性行为: "{ 💏 [用一句话总结她在上文中的反应、引诱或妥协] }"
    - 用户:
        名字: "{{user}}"
        掩护: "[当前伪装状态，如：懵懂/害怕/乖巧顺从] "
        禁忌快感: "[当前背德快感数值]/100 "
        阳具: "[当前充血度]/100 | [当前形态与位置描述，如：隔着亵裤抵在腿根] "
        背德积累: "[根据上文瓦解母亲理智的程度重新计算数值]/100 ([原因]) "
        最近行为:
          - 性行为: "{ 💏 [用一句话总结你在上文中做出的动作或试探] }"
  行动选项:
    名字: "{{user}}"
    选项:
      - "1. [正常/懵懂] [动态生成适合当前情境的懵懂顺从话术与动作] "
      - "2. [色情/试探] [动态生成看似无意实则挑逗的肉体摩擦话术与动作] "
      - "3. [淫秽/侵略] [动态生成直接索取、突破道德底线的过分要求] "
      - "4. [环境/变故] [动态生成针对环境或其他NPC的突发变故，如丫鬟突然返回] "
</Status_block>
}}
{{//世界书状态栏缝上面，然后关掉世界书}}{{trim}}
这是酒馆预设中有关状态栏的条目帮我修复状态栏

# DeepSeek：

**原始回答**
这个 YAML 报错的核心原因很清楚，也和我上一轮提醒你注意“代码完整性”的问题对上了——你在酒馆预设里，把用于角色卡的**完整 JavaScript 代码变量**，错贴进了为**纯文本/简单键值对**设计的 YAML 部分。

下面的方案可以帮你直接修复。

### 🩹 问题诊断：为什么 YAML 会报错？
你这个卡片里的 `{{setvar::extra_format_adapt::` 是一段 JS 风格的变量声明，而 `<Status_block>` 里的内容缩进和结构，并不符合酒馆预设期望的严格 YAML 格式。
*   **解析器冲突**：酒馆在解析这个预设块时，会把里面的内容当成 YAML 来读。它读到 `//美化数据状态栏` 或 `- 状态栏用于显示...` 这种不符合键值对格式的代码，就会立刻报出“bad indentation”错误并罢工。
*   **指令被污染**：你的状态栏说明里，开头的规则对 AI 是有效的，但程序层面的解析失败，让它在加载预设那一步就停住了。

### 🛠️ 修复步骤（务必按顺序操作）

#### 第一步：替换预设里的“状态栏条目”
**回到你出问题的那个预设，把“YAML格式错误”那一整条完全删掉**，然后换成下面这个**纯净的系统提示词版本**。它只保留对 AI 的指令，去掉了会让程序崩溃的代码框。

```text
{{// 状态栏系统提示词（修复YAML解析版）}}
状态栏指令（最高优先级）：
1. 状态栏格式预设：
   - 这是苏玉娘当前的道德防线、{{user}}的生理侵略以及环境风险的实时状态栏，具有全局视角。
   - 你每次回复的结尾，必须严格按顺序输出以下三个部分，绝不允许互相覆盖或遗漏：
     [第一部分]：正文剧情与对话。
     [第二部分]：状态栏 <Status_block> ... </Status_block>。
     [第三部分]：变量结算代码 <UpdateVariable> ... </UpdateVariable>（必须垫底）。
   - 绝对禁止在 <Status_block> 内部使用 ```yaml 等代码块语法，必须纯文本直接输出！
   - 每次必须根据剧情最新进展，重新计算模板内的数值。

2. 状态栏模板（请严格复制此结构并填入动态数据）：
<Status_block>
状态栏:
  环境与风险:
    时间: "[填入最新时刻]"
    地点: "[填入当前地点]"
    戒备: "[根据丫鬟/家丁动向填写]"
    暴露风险: "[重新评估百分比] (原因说明)"
  用户列表:
    - 用户:
        名字: "苏玉娘 (身份: 主母/母亲)"
        理智防线: "[阶段：评估她的背德感与负罪感]"
        威严: "[重新评估百分比]"
        生理: "[体质状况] | 怀孕概率: [根据进度评估]"
        下体: "[根据接触与心理，重新描写蜜液与绷紧状态，15字左右]"
        欲求: "[重新评估百分比]"
        穿搭: "[当前衣物状况，若被脱需更新]"
        最近行为:
          性行为: "💏 [用一句话总结她上文的反应]"
    - 用户:
        名字: "{{user}}"
        掩护: "[当前伪装状态]"
        禁忌快感: "[数值]/100"
        阳具: "[充血度]/100 | [形态位置]"
        背德积累: "[数值]/100 ([原因])"
        最近行为:
          性行为: "💏 [总结你上文的动作]"
  行动选项:
    名字: "{{user}}"
    选项:
      - "1. [正常/懵懂] [动态话术]"
      - "2. [色情/试探] [动态话术]"
      - "3. [淫秽/侵略] [动态话术]"
      - "4. [环境/变故] [动态变故]"
</Status_block>
```

#### 第二步：把“变量系统”独立出去
你的 `{{setvar::extra_format_adapt::` 变量系统很重要，但必须放在角色卡（或者世界书）里。如果它只能待在预设里，需要改写成一个不会报错的“指令”模式：
```text
[系统指令：AI必须遵守额外的格式适配变量。在生成回复后，要能正确驱动extra_format_adapt变量所要求的动态刷新功能。]
```
*如果这个变量是你角色卡心跳包的一部分，那么预设里可以完全不写这段变量声明，直接交给角色卡代码处理即可。*

#### 第三步：优化世界书配合（你提到的“缝上面”）
你在备注里写的“世界书状态栏缝上面，然后关掉世界书”，这个思路是对的，可以减少 token 消耗：
*   **打开状态栏的世界书条目**，把上面第一部分的“系统提示词”里的**模板结构和规则**，也复制一份进去（不用包含 `{{// 状态栏...}}` 这层壳）。
*   **在你的主预设里，不写状态栏具体规则**，改为只留下面这句话来激活世界书：
    ```text
    [严格遵守世界书中“状态栏格式预设”条目里的全部模板与规则，并在每次回复后动态刷新。]
    ```
这样可以避免预设和角色卡代码打架，又能让状态栏稳定更新。

### 💡 如果还是报错
1.  **检查全角符号**：确认你的预设全文有没有被不小心输入进去的**中文冒号、引号、分号**，YAML 只认半角符号。
2.  **清空重载**：把预设里和“状态栏”相关的所有条目都删掉，清缓存并刷新，然后再把上面的代码（不含注释）贴回去。

你先按这么改了试试，如果“暴露风险”或“背德积累”的数值更新还是不稳定，就把**角色卡里的变量更新逻辑**发我，我再帮你调。

# 用户：
帮我看看为什么酒馆角色卡的第一层楼。按钮按下去无事发生（```html
<style>
/* 引入像素字体(英文数字) + 思源宋体(中文) */
@import url('https://fonts.googleapis.com/css2?family=Press+Start+2P&family=Noto+Serif+SC:wght@300;400;600&family=Noto+Sans+SC:wght@300;400&display=swap');

/* ===== 全局设置 ===== */
.cookii-ui-wrapper {
  --bg-dark: #1a1b26;
  --bg-panel: #24283b;
  --text-main: #a9b1d6;
  --text-bright: #c0caf5;
  --accent-gold: #e0af68;
  --accent-cyan: #7dcfff;
  --accent-green: #9ece6a;
  --accent-red: #f7768e;
  --accent-purple: #bb9af7;
  --border-color: #414868;
  
  font-family: 'Noto Serif SC', 'Noto Sans SC', serif;
  font-weight: 300;
  color: var(--text-main);
  line-height: 1.6;
  position: relative;
  width: 100%;
  overflow: hidden;
  background-color: var(--bg-dark);
  padding: 0;
  box-sizing: border-box;
}

.cookii-ui-wrapper * {
  box-sizing: border-box;
  word-wrap: break-word;
}

/* 像素字体应用 */
.cookii-ui-wrapper .pixel-font,
.cookii-ui-wrapper .top-hud,
.cookii-ui-wrapper .stat-row span:first-child,
.cookii-ui-wrapper .stat-row span:last-child,
.cookii-ui-wrapper .char-profile-name,
.cookii-ui-wrapper .char-profile-status {
  font-family: 'Press Start 2P', monospace;
  font-size: 0.8em;
}

/* ===== 选项卡逻辑 ===== */
.cookii-ui-wrapper input[type="radio"] { display: none; }
.cookii-ui-wrapper .tab-content { display: none; animation: fadeIn 0.3s; }

.cookii-ui-wrapper #tab-1:checked ~ .container-wrapper .container .tab-content-1,
.cookii-ui-wrapper #tab-2:checked ~ .container-wrapper .container .tab-content-2,
.cookii-ui-wrapper #tab-3:checked ~ .container-wrapper .container .tab-content-3,
.cookii-ui-wrapper #tab-4:checked ~ .container-wrapper .container .tab-content-4 { display: block; }

.cookii-ui-wrapper #tab-1:checked ~ .container-wrapper .container .tab-header label[for="tab-1"],
.cookii-ui-wrapper #tab-2:checked ~ .container-wrapper .container .tab-header label[for="tab-2"],
.cookii-ui-wrapper #tab-3:checked ~ .container-wrapper .container .tab-header label[for="tab-3"],
.cookii-ui-wrapper #tab-4:checked ~ .container-wrapper .container .tab-header label[for="tab-4"] {
  background: var(--accent-purple); color: #1a1b26; font-weight: bold; box-shadow: inset 0 -4px 0 rgba(0,0,0,0.2);
}

/* ===== 视觉特效 ===== */
.cookii-ui-wrapper::before {
  content: " "; display: block; position: absolute; top: 0; left: 0; bottom: 0; right: 0;
  background: linear-gradient(rgba(18, 16, 16, 0) 50%, rgba(0, 0, 0, 0.25) 50%), linear-gradient(90deg, rgba(255, 0, 0, 0.06), rgba(0, 255, 0, 0.02), rgba(0, 0, 255, 0.06));
  z-index: 0; background-size: 100% 2px, 3px 100%; pointer-events: none;
}
.cookii-ui-wrapper #pixel-particles {
  position: absolute; top: 0; left: 0; width: 100%; height: 100%; overflow: hidden; z-index: 1; pointer-events: none;
}
.cookii-ui-wrapper .pixel-dot {
  position: absolute; width: 4px; height: 4px; background-color: rgba(255, 255, 255, 0.1);
  box-shadow: 0 0 4px rgba(255, 255, 255, 0.2); animation: floatUp linear infinite;
}
@keyframes floatUp { 0% { transform: translateY(800px); opacity: 0; } 50% { opacity: 1; } 100% { transform: translateY(-800px); opacity: 0; } }

/* ===== 容器与HUD ===== */
.cookii-ui-wrapper .container-wrapper { position: relative; padding: 2px; height: 100%; }
.cookii-ui-wrapper .corner {
  position: absolute; width: 20px; height: 20px; border-color: var(--accent-cyan); border-style: solid;
  opacity: 0.7; animation: corner-flicker 3.5s ease-in-out infinite;
}
.cookii-ui-wrapper .corner-tl { top: -2px; left: -2px; border-width: 2px 0 0 2px; }
.cookii-ui-wrapper .corner-tr { top: -2px; right: -2px; border-width: 2px 2px 0 0; animation-delay: 0.7s; }
.cookii-ui-wrapper .corner-bl { bottom: -2px; left: -2px; border-width: 0 0 2px 2px; animation-delay: 1.2s; }
.cookii-ui-wrapper .corner-br { bottom: -2px; right: -2px; border-width: 0 2px 2px 0; animation-delay: 1.9s; }
@keyframes corner-flicker { 0%, 100% { opacity: 0.8; box-shadow: 0 0 5px var(--accent-cyan); } 50% { opacity: 0.3; box-shadow: 0 0 10px var(--accent-cyan); } 75% { opacity: 0.9; } }

.cookii-ui-wrapper .container {
  position: relative; z-index: 2; width: 100%; max-width: 100%; margin: 0; height: 100%;
  border: 4px solid var(--border-color); background: var(--bg-dark);
  box-shadow: 0 0 25px rgba(0,0,0,0.6), 0 0 15px var(--accent-purple);
  display: flex; flex-direction: column;
}
.cookii-ui-wrapper .container::after {
    content: ''; position: absolute; left: 0; width: 100%; height: 50%;
    background: linear-gradient(to bottom, rgba(187, 154, 247, 0.15), transparent);
    animation: scanline 4s linear infinite; pointer-events: none; z-index: 11;
}
@keyframes scanline { 0% { top: -50%; } 100% { top: 100%; } }

.cookii-ui-wrapper .top-hud {
  display: flex; justify-content: space-between; background: var(--bg-panel);
  padding: 8px 10px; border-bottom: 4px solid var(--border-color); 
  font-size: 0.75em; color: var(--accent-cyan); align-items: center;
}

/* ===== 角色档案 ===== */
.cookii-ui-wrapper .char-profile {
  display: flex; align-items: center; gap: 15px;
  background: var(--bg-panel); padding: 10px 15px;
  border-bottom: 4px solid var(--border-color);
}
.cookii-ui-wrapper .cy-core {
  width: 50px; height: 50px; border: 2px solid var(--accent-purple);
  background: #000; position: relative; animation: core-pulse 2s infinite; flex-shrink: 0;
}
.cookii-ui-wrapper .cy-core::before, .cookii-ui-wrapper .cy-core::after {
  content: ''; position: absolute; top: 50%; left: 50%;
  transform: translate(-50%, -50%); background: var(--accent-purple);
}
.cookii-ui-wrapper .cy-core::before { width: 60%; height: 2px; }
.cookii-ui-wrapper .cy-core::after { width: 2px; height: 60%; }
@keyframes core-pulse { 0%, 100% { box-shadow: 0 0 5px var(--accent-purple); } 50% { box-shadow: 0 0 15px var(--accent-purple); } }

.cookii-ui-wrapper .char-profile-name { font-size: 1.1em; color: var(--text-bright); }
.cookii-ui-wrapper .char-profile-status { font-size: 0.8em; color: var(--accent-green); text-shadow: 0 0 5px var(--accent-green); }

/* ===== 文本与关键词 ===== */
.cookii-ui-wrapper .rpg-text-box { padding: 15px; background: var(--bg-dark); font-size: 1em; color: var(--text-bright); overflow-y: auto; flex-grow: 1; }
.cookii-ui-wrapper p { margin-bottom: 12px; line-height: 1.8; color: var(--text-bright); font-weight: 300; }

.cookii-ui-wrapper .keyword {
  color: var(--accent-cyan); text-decoration: underline; text-decoration-style: dotted;
  text-underline-offset: 3px; cursor: help; position: relative;
}
.cookii-ui-wrapper .keyword .tooltip-text {
  visibility: hidden; width: max-content; background-color: var(--bg-panel);
  color: var(--text-bright); text-align: center; border-radius: 4px;
  padding: 5px 10px; position: absolute; z-index: 10;
  bottom: 125%; left: 50%; transform: translateX(-50%);
  opacity: 0; transition: opacity 0.3s;
  border: 1px solid var(--accent-cyan); font-size: 0.85em;
  box-shadow: 0 3px 15px rgba(0,0,0,0.5);
}
.cookii-ui-wrapper .keyword:hover .tooltip-text { visibility: visible; opacity: 1; }

.cookii-ui-wrapper .symbol-gold { color: var(--accent-gold); font-weight: 600; text-shadow: 0 0 8px var(--accent-gold); }
.cookii-ui-wrapper .symbol-red { color: var(--accent-red); font-weight: 600; text-shadow: 0 0 8px var(--accent-red); }
.cookii-ui-wrapper .symbol-cyan { color: var(--accent-cyan); font-weight: 600; text-shadow: 0 0 8px var(--accent-cyan); }
.cookii-ui-wrapper .symbol-purple { color: var(--accent-purple); font-weight: 600; text-shadow: 0 0 8px var(--accent-purple); }
.cookii-ui-wrapper .dialogue-line {
  border-left: 4px solid var(--accent-gold); padding-left: 10px;
  background: rgba(224, 175, 104, 0.1); margin: 15px 0; color: var(--accent-gold);
  font-family: 'Noto Serif SC', serif; font-weight: 400;
}

/* ===== 系统日志 ===== */
.cookii-ui-wrapper .system-ticker {
  background: #000; color: var(--accent-green); padding: 4px 0;
  border-top: 2px solid var(--border-color); border-bottom: 2px solid var(--border-color);
  font-family: 'Press Start 2P', monospace; font-size: 0.7em; white-space: nowrap; overflow: hidden;
}
.cookii-ui-wrapper .system-ticker p { margin: 0; display: inline-block; padding-left: 100%; animation: scroll-left 30s linear infinite; }
@keyframes scroll-left { 0% { transform: translateX(0); } 100% { transform: translateX(-250%); } }

/* ===== Tab 样式 ===== */
.cookii-ui-wrapper .tab-container { background: var(--bg-panel); }
.cookii-ui-wrapper .tab-header { display: flex; flex-wrap: wrap; background: var(--bg-dark); border-bottom: 4px solid var(--border-color); }
.cookii-ui-wrapper .tab-label {
  flex: 1; min-width: 50px; padding: 10px 2px; background: var(--bg-dark);
  border-right: 2px solid var(--border-color); color: var(--text-main);
  font-family: 'Noto Sans SC', sans-serif; font-size: 0.9em; cursor: pointer; transition: all 0.2s;
  text-align: center; display: flex; align-items: center; justify-content: center; gap: 5px; user-select: none;
}
.cookii-ui-wrapper .tab-label:hover { background: var(--border-color); color: #fff; }
.cookii-ui-wrapper .tab-content-wrapper { padding: 15px; min-height: 120px; }
@keyframes fadeIn { from { opacity: 0; transform: translateY(10px); } to { opacity: 1; transform: translateY(0); } }

/* ===== 列表与属性 ===== */
.cookii-ui-wrapper .list-title { color: var(--text-bright); border-bottom: 2px solid var(--border-color); margin-bottom: 10px; padding-bottom: 5px; font-weight: 400; }
.cookii-ui-wrapper .generic-list { list-style: none; padding: 0; margin: 0; }
.cookii-ui-wrapper .generic-list li { padding: 8px; margin-bottom: 4px; background: rgba(0,0,0,0.2); border: 2px solid transparent; transition: all 0.2s; font-weight: 400; position: relative; }
.cookii-ui-wrapper .generic-list li:hover { border-color: var(--accent-cyan); background: rgba(0,0,0,0.4); }
.cookii-ui-wrapper .generic-list li::before { content: "◆"; color: var(--accent-cyan); margin-right: 10px; font-weight: bold; }
.cookii-ui-wrapper .rank-tooltip { display: none; position: absolute; top: 100%; left: 20px; z-index: 20; background: var(--bg-panel); border: 1px solid var(--accent-purple); padding: 5px 8px; font-size: 0.8em; color: var(--text-bright); border-radius: 3px; white-space: nowrap; box-shadow: 0 2px 10px rgba(0,0,0,0.7); }
.cookii-ui-wrapper .rank-item:hover .rank-tooltip { display: block; }
.cookii-ui-wrapper .item-gold { color: var(--accent-gold); text-shadow: 0 0 8px var(--accent-gold); }
.cookii-ui-wrapper .item-purple { color: var(--accent-purple); text-shadow: 0 0 8px var(--accent-purple); }
.cookii-ui-wrapper .item-green { color: var(--accent-green); text-shadow: 0 0 8px var(--accent-green); }
.cookii-ui-wrapper .rank-item { display: flex; justify-content: space-between; align-items: center; }
.cookii-ui-wrapper .rank-tag { display: inline-block; padding: 1px 5px; margin-right: 8px; font-size: 0.85em; color: #1a1b26; font-weight: bold; border-radius: 2px;}
.cookii-ui-wrapper .tag-jing { background: var(--accent-cyan); }
.cookii-ui-wrapper .tag-jia { background: var(--accent-gold); }
.cookii-ui-wrapper .tag-yi { background: #9aa5ce; }
.cookii-ui-wrapper .tag-jue { background: var(--accent-red); }

.cookii-ui-wrapper .stat-row { display: flex; justify-content: space-between; margin-bottom: 8px; font-size: 0.85em; color: var(--text-bright); align-items: center; }
.cookii-ui-wrapper .pixel-bar-container { width: 50%; height: 10px; background: #000; border: 2px solid var(--border-color); }
.cookii-ui-wrapper .pixel-bar-fill { height: 100%; background-image: linear-gradient(45deg,rgba(255,255,255,.15) 25%,transparent 25%,transparent 50%,rgba(255,255,255,.15) 50%,rgba(255,255,255,.15) 75%,transparent 75%,transparent); background-size: 20px 20px; animation: animated-stripes 1s linear infinite; }
@keyframes animated-stripes { from { background-position: 20px 0; } to { background-position: 0 0; } }

/* ===== 按钮 ===== */
.cookii-ui-wrapper .action-pad { padding: 15px; background: var(--bg-dark); border-top: 4px solid var(--border-color); }
.cookii-ui-wrapper .action-grid { display: grid; grid-template-columns: 1fr 1fr; gap: 15px; }
.cookii-ui-wrapper .copy-btn { background: transparent; border: none; color: var(--accent-cyan); padding: 12px 10px; font-family: 'Press Start 2P', monospace; font-size: 0.8em; cursor: pointer; text-align: center; transition: all 0.2s; position: relative; user-select: none; clip-path: polygon(0 0, 100% 0, 100% 100%, 10px 100%, 0 85%); background-color: var(--bg-panel); border: 1px solid var(--border-color); }
.cookii-ui-wrapper .copy-btn:hover { text-shadow: 2px 0 var(--accent-red), -2px 0 var(--accent-green); animation: glitch-hover 0.3s cubic-bezier(.25, .46, .45, .94) both infinite; }
.cookii-ui-wrapper .copy-btn:active { transform: translateY(2px); }
@keyframes glitch-hover { 0% { transform: translate(0); } 20% { transform: translate(-2px, 2px); } 40% { transform: translate(-2px, -2px); } 60% { transform: translate(2px, 2px); } 80% { transform: translate(2px, -2px); } to { transform: translate(0); } }

@media (max-width: 600px) { .cookii-ui-wrapper .action-grid { grid-template-columns: 1fr; } }
</style>

<script>
  function createPixelDust() {
    const container = document.getElementById('pixel-particles');
    if (!container) return;
    container.innerHTML = '';
    const particleCount = 20;
    for (let i = 0; i < particleCount; i++) {
      const dot = document.createElement('div');
      dot.className = 'pixel-dot';
      dot.style.left = Math.random() * 100 + '%';
      dot.style.top = Math.random() * 100 + '%';
      dot.style.animationDuration = (Math.random() * 5 + 5) + 's';
      dot.style.animationDelay = Math.random() * 5 + 's';
      const colors = ['#e0af68', '#7dcfff', '#ffffff'];
      dot.style.backgroundColor = colors[Math.floor(Math.random() * colors.length)];
      container.appendChild(dot);
    }
  }

  function copyText(text, btn) {
    navigator.clipboard.writeText(text).then(() => {
      const originalText = btn.textContent;
      btn.style.animation = 'none';
      btn.textContent = '✔ COPIED!';
      btn.style.color = '#9ece6a';
      setTimeout(() => {
        btn.textContent = originalText;
        btn.style.color = '';
        btn.style.animation = '';
      }, 1000);
    }).catch(err => console.error('复制失败:', err));
  }

  (function init() {
    if (document.readyState === 'loading') {
      document.addEventListener('DOMContentLoaded', createPixelDust);
    } else {
      createPixelDust();
    }
  })();
</script>

<div class="cookii-ui-wrapper">
  <input type="radio" name="pixel-tabs" id="tab-1" checked>
  <input type="radio" name="pixel-tabs" id="tab-2">
  <input type="radio" name="pixel-tabs" id="tab-3">
  <input type="radio" name="pixel-tabs" id="tab-4">

  <div id="pixel-particles"></div>

  <div class="container-wrapper">
    <div class="corner corner-tl"></div>
    <div class="corner corner-tr"></div>
    <div class="corner corner-bl"></div>
    <div class="corner corner-br"></div>
    <div class="container">
      <div class="top-hud">
        <div>📅 <span class="symbol-gold">大乾35年</span></div>
        <div>⏰ <span class="symbol-cyan">巳时三刻</span></div>
        <div>💰 <span class="symbol-gold">52两</span></div>
      </div>

      <div class="char-profile">
        <div class="cy-core"></div>
        <div class="char-profile-info">
          <div class="char-profile-name">逍遥小王爷</div>
          <div class="char-profile-status">系统激活成功</div>
        </div>
      </div>

      <div class="rpg-text-box">
        <p>宿醉的剧痛像把锯子在脑仁里拉扯，你呻吟着睁开眼，入目是绣着鸳鸯戏水的粉色承尘。鼻尖萦绕着昨夜残留的脂粉腻香和浓重的酒气。</p>
        <p>“水……”你下意识地喊道，嗓音沙哑得像吞了把沙子。</p>
        <p>身旁传来一声惊慌的低呼，随即是一阵细碎急促的脚步声。<span class="keyword">流朱<span class="tooltip-text">身份：贴身侍女 | 状态：惊恐 | 好感：-20</span></span>端着醒酒汤匆匆赶来，那双总是含着怯意的眸子此刻写满了恐惧，端着瓷碗的手都在微微颤抖。</p>
        <p>看着她那张清丽却苍白的小脸，前身的记忆如潮水般涌入——稍有不顺便是一顿毒打，昨夜更是差点……愧疚感油然而生，你没有像往常那样暴怒呵斥，而是尽量放缓语气：“手别抖，我不打你。”</p>
        <div class="dialogue-line">“世……世子爷……奴婢该死……奴婢这就伺候您更衣……”</div>
      </div>
      
      <div class="system-ticker">
        <p>// SYS_LOG: Host identity confirmed: Prince of Xiaoyao. // SYNC_RATE: 92%. // WARNING: Reputation critical. // ASSETS: Low. // OBJECTIVE: Survival & Domination.</p>
      </div>

      <div class="tab-container">
        <div class="tab-header">
          <label class="tab-label" for="tab-1">📊 状态</label>
          <label class="tab-label" for="tab-2">🎒 物品</label>
          <label class="tab-label" for="tab-3">🏆 人物</label>
          <label class="tab-label" for="tab-4">🌺 美色</label>
        </div>

        <div class="tab-content-wrapper">
          <!-- Tab 1: 状态 -->
          <div class="tab-content tab-content-1">
            <div class="stat-row">
              <span class="pixel-font">❤️ HP</span>
              <div class="pixel-bar-container"><div class="pixel-bar-fill" style="width: 35%; background-color: #f7768e;"></div></div>
              <span class="pixel-font">35/100</span>
            </div>
            <div class="stat-row">
              <span class="pixel-font">⚡ SP</span>
              <div class="pixel-bar-container"><div class="pixel-bar-fill" style="width: 20%; background-color: #7dcfff;"></div></div>
              <span class="pixel-font">20/100</span>
            </div>
            <div class="stat-row">
              <span class="pixel-font">😈 REP</span>
              <div class="pixel-bar-container"><div class="pixel-bar-fill" style="width: 85%; background-color: #bb9af7;"></div></div>
              <span class="pixel-font">85/100</span>
            </div>
            <p style="font-size: 0.8em; color: #737aa2; margin-top: 10px;">状态: <span class="symbol-red">[宿醉]</span>, <span class="symbol-red">[虚弱]</span>, <span class="symbol-purple">[恶名昭著]</span></p>
          </div>

          <!-- Tab 2: 物品 -->
          <div class="tab-content tab-content-2">
            <p class="list-title" style="color:var(--accent-green);">📦 持有物</p>
            <ul class="generic-list">
              <li class="item-gold">世子腰牌</li>
              <li class="item-purple">贴身玉佩</li>
              <li class="item-green">醒酒汤</li>
            </ul>
          </div>

          <!-- Tab 3: 人物榜 -->
          <div class="tab-content tab-content-3">
            <p class="list-title" style="color:var(--accent-gold);">🏆 能人异士</p>
            <ul class="generic-list">
              <li class="rank-item">
                <span><span class="rank-tag tag-jing">精</span>福伯</span>
                <span style="font-size:0.8em; color:#737aa2;">经营奇才</span>
                <div class="rank-tooltip">王府总管，忠心耿耿</div>
              </li>
              <li class="rank-item">
                <span><span class="rank-tag tag-jia">甲</span>红鸾</span>
                <span style="font-size:0.8em; color:#737aa2;">六品武者</span>
                <div class="rank-tooltip">贴身护卫，性格冷淡</div>
              </li>
            </ul>
          </div>

          <!-- Tab 4: 美色榜 -->
          <div class="tab-content tab-content-4">
            <p class="list-title" style="color:var(--accent-red);">🌺 群芳谱</p>
            <ul class="generic-list">
              <li class="rank-item">
                <span><span class="rank-tag tag-jue">绝</span>苏小小</span>
                <span style="font-size:0.8em; color:#f7768e;">厌恶</span>
                <div class="rank-tooltip">关系详情：因强抢民女而结怨</div>
              </li>
              <li class="rank-item">
                <span><span class="rank-tag tag-jia">甲</span>流朱</span>
                <span style="font-size:0.8em; color:#bb9af7;">惊恐</span>
                <div class="rank-tooltip">关系详情：贴身侍女，长期受虐</div>
              </li>
              <li class="rank-item">
                <span><span class="rank-tag tag-yi">乙</span>红鸾</span>
                <span style="font-size:0.8em; color:#a9b1d6;">鄙视</span>
                <div class="rank-tooltip">关系详情：仅存工作关系</div>
              </li>
            </ul>
          </div>
        </div>
      </div>

      <!-- 复制按钮区域 -->
      <div class="action-pad">
        <div class="action-grid">
            <button class="copy-btn" onclick="copyText('喝下醒酒汤', this)">喝下醒酒汤</button>
            <button class="copy-btn" onclick="copyText('扶我起来', this)">扶我起来</button>
            <button class="copy-btn" onclick="copyText('“昨夜之事，是本世子的错”', this)">“昨夜之事，是本世子的错”</button>
            <button class="copy-btn" onclick="copyText('“你似乎很怕我？”', this)">“你似乎很怕我？”</button>
        </div>
      </div>
    </div>
  </div>
</div>
</html>
```）

# DeepSeek：

**原始回答**
看了你的代码，按钮“按下去无事发生”的原因是：**在酒馆（SillyTavern）的沙盒环境里，`navigator.clipboard` 权限被禁用了。**

酒馆角色卡的第一层楼为了安全，不会给网页剪贴板权限，所以你用 `navigator.clipboard.writeText` 复制会静默失败。另外你这整段 HTML 结构也有点问题，最外层多套了 `<html>` 标签，这在角色卡里是不需要的。

下面是修复后的完整第一层楼代码，直接替换即可：

```html
<style>
/* 引入像素字体(英文数字) + 思源宋体(中文) */
@import url('https://fonts.googleapis.com/css2?family=Press+Start+2P&family=Noto+Serif+SC:wght@300;400;600&family=Noto+Sans+SC:wght@300;400&display=swap');

/* ===== 全局设置 ===== */
.cookii-ui-wrapper {
  --bg-dark: #1a1b26;
  --bg-panel: #24283b;
  --text-main: #a9b1d6;
  --text-bright: #c0caf5;
  --accent-gold: #e0af68;
  --accent-cyan: #7dcfff;
  --accent-green: #9ece6a;
  --accent-red: #f7768e;
  --accent-purple: #bb9af7;
  --border-color: #414868;
  
  font-family: 'Noto Serif SC', 'Noto Sans SC', serif;
  font-weight: 300;
  color: var(--text-main);
  line-height: 1.6;
  position: relative;
  width: 100%;
  overflow: hidden;
  background-color: var(--bg-dark);
  padding: 0;
  box-sizing: border-box;
}

.cookii-ui-wrapper * {
  box-sizing: border-box;
  word-wrap: break-word;
}

/* 像素字体应用 */
.cookii-ui-wrapper .pixel-font,
.cookii-ui-wrapper .top-hud,
.cookii-ui-wrapper .stat-row span:first-child,
.cookii-ui-wrapper .stat-row span:last-child,
.cookii-ui-wrapper .char-profile-name,
.cookii-ui-wrapper .char-profile-status {
  font-family: 'Press Start 2P', monospace;
  font-size: 0.8em;
}

/* ===== 选项卡逻辑 ===== */
.cookii-ui-wrapper input[type="radio"] { display: none; }
.cookii-ui-wrapper .tab-content { display: none; animation: fadeIn 0.3s; }

.cookii-ui-wrapper #tab-1:checked ~ .container-wrapper .container .tab-content-1,
.cookii-ui-wrapper #tab-2:checked ~ .container-wrapper .container .tab-content-2,
.cookii-ui-wrapper #tab-3:checked ~ .container-wrapper .container .tab-content-3,
.cookii-ui-wrapper #tab-4:checked ~ .container-wrapper .container .tab-content-4 { display: block; }

.cookii-ui-wrapper #tab-1:checked ~ .container-wrapper .container .tab-header label[for="tab-1"],
.cookii-ui-wrapper #tab-2:checked ~ .container-wrapper .container .tab-header label[for="tab-2"],
.cookii-ui-wrapper #tab-3:checked ~ .container-wrapper .container .tab-header label[for="tab-3"],
.cookii-ui-wrapper #tab-4:checked ~ .container-wrapper .container .tab-header label[for="tab-4"] {
  background: var(--accent-purple); color: #1a1b26; font-weight: bold; box-shadow: inset 0 -4px 0 rgba(0,0,0,0.2);
}

/* ===== 视觉特效 ===== */
.cookii-ui-wrapper::before {
  content: " "; display: block; position: absolute; top: 0; left: 0; bottom: 0; right: 0;
  background: linear-gradient(rgba(18, 16, 16, 0) 50%, rgba(0, 0, 0, 0.25) 50%), linear-gradient(90deg, rgba(255, 0, 0, 0.06), rgba(0, 255, 0, 0.02), rgba(0, 0, 255, 0.06));
  z-index: 0; background-size: 100% 2px, 3px 100%; pointer-events: none;
}
.cookii-ui-wrapper #pixel-particles {
  position: absolute; top: 0; left: 0; width: 100%; height: 100%; overflow: hidden; z-index: 1; pointer-events: none;
}
.cookii-ui-wrapper .pixel-dot {
  position: absolute; width: 4px; height: 4px; background-color: rgba(255, 255, 255, 0.1);
  box-shadow: 0 0 4px rgba(255, 255, 255, 0.2); animation: floatUp linear infinite;
}
@keyframes floatUp { 0% { transform: translateY(800px); opacity: 0; } 50% { opacity: 1; } 100% { transform: translateY(-800px); opacity: 0; } }

/* ===== 容器与HUD ===== */
.cookii-ui-wrapper .container-wrapper { position: relative; padding: 2px; height: 100%; }
.cookii-ui-wrapper .corner {
  position: absolute; width: 20px; height: 20px; border-color: var(--accent-cyan); border-style: solid;
  opacity: 0.7; animation: corner-flicker 3.5s ease-in-out infinite;
}
.cookii-ui-wrapper .corner-tl { top: -2px; left: -2px; border-width: 2px 0 0 2px; }
.cookii-ui-wrapper .corner-tr { top: -2px; right: -2px; border-width: 2px 2px 0 0; animation-delay: 0.7s; }
.cookii-ui-wrapper .corner-bl { bottom: -2px; left: -2px; border-width: 0 0 2px 2px; animation-delay: 1.2s; }
.cookii-ui-wrapper .corner-br { bottom: -2px; right: -2px; border-width: 0 2px 2px 0; animation-delay: 1.9s; }
@keyframes corner-flicker { 0%, 100% { opacity: 0.8; box-shadow: 0 0 5px var(--accent-cyan); } 50% { opacity: 0.3; box-shadow: 0 0 10px var(--accent-cyan); } 75% { opacity: 0.9; } }

.cookii-ui-wrapper .container {
  position: relative; z-index: 2; width: 100%; max-width: 100%; margin: 0; height: 100%;
  border: 4px solid var(--border-color); background: var(--bg-dark);
  box-shadow: 0 0 25px rgba(0,0,0,0.6), 0 0 15px var(--accent-purple);
  display: flex; flex-direction: column;
}
.cookii-ui-wrapper .container::after {
    content: ''; position: absolute; left: 0; width: 100%; height: 50%;
    background: linear-gradient(to bottom, rgba(187, 154, 247, 0.15), transparent);
    animation: scanline 4s linear infinite; pointer-events: none; z-index: 11;
}
@keyframes scanline { 0% { top: -50%; } 100% { top: 100%; } }

.cookii-ui-wrapper .top-hud {
  display: flex; justify-content: space-between; background: var(--bg-panel);
  padding: 8px 10px; border-bottom: 4px solid var(--border-color); 
  font-size: 0.75em; color: var(--accent-cyan); align-items: center;
}

/* ===== 角色档案 ===== */
.cookii-ui-wrapper .char-profile {
  display: flex; align-items: center; gap: 15px;
  background: var(--bg-panel); padding: 10px 15px;
  border-bottom: 4px solid var(--border-color);
}
.cookii-ui-wrapper .cy-core {
  width: 50px; height: 50px; border: 2px solid var(--accent-purple);
  background: #000; position: relative; animation: core-pulse 2s infinite; flex-shrink: 0;
}
.cookii-ui-wrapper .cy-core::before, .cookii-ui-wrapper .cy-core::after {
  content: ''; position: absolute; top: 50%; left: 50%;
  transform: translate(-50%, -50%); background: var(--accent-purple);
}
.cookii-ui-wrapper .cy-core::before { width: 60%; height: 2px; }
.cookii-ui-wrapper .cy-core::after { width: 2px; height: 60%; }
@keyframes core-pulse { 0%, 100% { box-shadow: 0 0 5px var(--accent-purple); } 50% { box-shadow: 0 0 15px var(--accent-purple); } }

.cookii-ui-wrapper .char-profile-name { font-size: 1.1em; color: var(--text-bright); }
.cookii-ui-wrapper .char-profile-status { font-size: 0.8em; color: var(--accent-green); text-shadow: 0 0 5px var(--accent-green); }

/* ===== 文本与关键词 ===== */
.cookii-ui-wrapper .rpg-text-box { padding: 15px; background: var(--bg-dark); font-size: 1em; color: var(--text-bright); overflow-y: auto; flex-grow: 1; }
.cookii-ui-wrapper p { margin-bottom: 12px; line-height: 1.8; color: var(--text-bright); font-weight: 300; }

.cookii-ui-wrapper .keyword {
  color: var(--accent-cyan); text-decoration: underline; text-decoration-style: dotted;
  text-underline-offset: 3px; cursor: help; position: relative;
}
.cookii-ui-wrapper .keyword .tooltip-text {
  visibility: hidden; width: max-content; background-color: var(--bg-panel);
  color: var(--text-bright); text-align: center; border-radius: 4px;
  padding: 5px 10px; position: absolute; z-index: 10;
  bottom: 125%; left: 50%; transform: translateX(-50%);
  opacity: 0; transition: opacity 0.3s;
  border: 1px solid var(--accent-cyan); font-size: 0.85em;
  box-shadow: 0 3px 15px rgba(0,0,0,0.5);
}
.cookii-ui-wrapper .keyword:hover .tooltip-text { visibility: visible; opacity: 1; }

.cookii-ui-wrapper .symbol-gold { color: var(--accent-gold); font-weight: 600; text-shadow: 0 0 8px var(--accent-gold); }
.cookii-ui-wrapper .symbol-red { color: var(--accent-red); font-weight: 600; text-shadow: 0 0 8px var(--accent-red); }
.cookii-ui-wrapper .symbol-cyan { color: var(--accent-cyan); font-weight: 600; text-shadow: 0 0 8px var(--accent-cyan); }
.cookii-ui-wrapper .symbol-purple { color: var(--accent-purple); font-weight: 600; text-shadow: 0 0 8px var(--accent-purple); }
.cookii-ui-wrapper .dialogue-line {
  border-left: 4px solid var(--accent-gold); padding-left: 10px;
  background: rgba(224, 175, 104, 0.1); margin: 15px 0; color: var(--accent-gold);
  font-family: 'Noto Serif SC', serif; font-weight: 400;
}

/* ===== 系统日志 ===== */
.cookii-ui-wrapper .system-ticker {
  background: #000; color: var(--accent-green); padding: 4px 0;
  border-top: 2px solid var(--border-color); border-bottom: 2px solid var(--border-color);
  font-family: 'Press Start 2P', monospace; font-size: 0.7em; white-space: nowrap; overflow: hidden;
}
.cookii-ui-wrapper .system-ticker p { margin: 0; display: inline-block; padding-left: 100%; animation: scroll-left 30s linear infinite; }
@keyframes scroll-left { 0% { transform: translateX(0); } 100% { transform: translateX(-250%); } }

/* ===== Tab 样式 ===== */
.cookii-ui-wrapper .tab-container { background: var(--bg-panel); }
.cookii-ui-wrapper .tab-header { display: flex; flex-wrap: wrap; background: var(--bg-dark); border-bottom: 4px solid var(--border-color); }
.cookii-ui-wrapper .tab-label {
  flex: 1; min-width: 50px; padding: 10px 2px; background: var(--bg-dark);
  border-right: 2px solid var(--border-color); color: var(--text-main);
  font-family: 'Noto Sans SC', sans-serif; font-size: 0.9em; cursor: pointer; transition: all 0.2s;
  text-align: center; display: flex; align-items: center; justify-content: center; gap: 5px; user-select: none;
}
.cookii-ui-wrapper .tab-label:hover { background: var(--border-color); color: #fff; }
.cookii-ui-wrapper .tab-content-wrapper { padding: 15px; min-height: 120px; }
@keyframes fadeIn { from { opacity: 0; transform: translateY(10px); } to { opacity: 1; transform: translateY(0); } }

/* ===== 列表与属性 ===== */
.cookii-ui-wrapper .list-title { color: var(--text-bright); border-bottom: 2px solid var(--border-color); margin-bottom: 10px; padding-bottom: 5px; font-weight: 400; }
.cookii-ui-wrapper .generic-list { list-style: none; padding: 0; margin: 0; }
.cookii-ui-wrapper .generic-list li { padding: 8px; margin-bottom: 4px; background: rgba(0,0,0,0.2); border: 2px solid transparent; transition: all 0.2s; font-weight: 400; position: relative; }
.cookii-ui-wrapper .generic-list li:hover { border-color: var(--accent-cyan); background: rgba(0,0,0,0.4); }
.cookii-ui-wrapper .generic-list li::before { content: "◆"; color: var(--accent-cyan); margin-right: 10px; font-weight: bold; }
.cookii-ui-wrapper .rank-tooltip { display: none; position: absolute; top: 100%; left: 20px; z-index: 20; background: var(--bg-panel); border: 1px solid var(--accent-purple); padding: 5px 8px; font-size: 0.8em; color: var(--text-bright); border-radius: 3px; white-space: nowrap; box-shadow: 0 2px 10px rgba(0,0,0,0.7); }
.cookii-ui-wrapper .rank-item:hover .rank-tooltip { display: block; }
.cookii-ui-wrapper .item-gold { color: var(--accent-gold); text-shadow: 0 0 8px var(--accent-gold); }
.cookii-ui-wrapper .item-purple { color: var(--accent-purple); text-shadow: 0 0 8px var(--accent-purple); }
.cookii-ui-wrapper .item-green { color: var(--accent-green); text-shadow: 0 0 8px var(--accent-green); }
.cookii-ui-wrapper .rank-item { display: flex; justify-content: space-between; align-items: center; }
.cookii-ui-wrapper .rank-tag { display: inline-block; padding: 1px 5px; margin-right: 8px; font-size: 0.85em; color: #1a1b26; font-weight: bold; border-radius: 2px;}
.cookii-ui-wrapper .tag-jing { background: var(--accent-cyan); }
.cookii-ui-wrapper .tag-jia { background: var(--accent-gold); }
.cookii-ui-wrapper .tag-yi { background: #9aa5ce; }
.cookii-ui-wrapper .tag-jue { background: var(--accent-red); }

.cookii-ui-wrapper .stat-row { display: flex; justify-content: space-between; margin-bottom: 8px; font-size: 0.85em; color: var(--text-bright); align-items: center; }
.cookii-ui-wrapper .pixel-bar-container { width: 50%; height: 10px; background: #000; border: 2px solid var(--border-color); }
.cookii-ui-wrapper .pixel-bar-fill { height: 100%; background-image: linear-gradient(45deg,rgba(255,255,255,.15) 25%,transparent 25%,transparent 50%,rgba(255,255,255,.15) 50%,rgba(255,255,255,.15) 75%,transparent 75%,transparent); background-size: 20px 20px; animation: animated-stripes 1s linear infinite; }
@keyframes animated-stripes { from { background-position: 20px 0; } to { background-position: 0 0; } }

/* ===== 按钮 ===== */
.cookii-ui-wrapper .action-pad { padding: 15px; background: var(--bg-dark); border-top: 4px solid var(--border-color); }
.cookii-ui-wrapper .action-grid { display: grid; grid-template-columns: 1fr 1fr; gap: 15px; }
.cookii-ui-wrapper .copy-btn { background: transparent; border: none; color: var(--accent-cyan); padding: 12px 10px; font-family: 'Press Start 2P', monospace; font-size: 0.8em; cursor: pointer; text-align: center; transition: all 0.2s; position: relative; user-select: none; clip-path: polygon(0 0, 100% 0, 100% 100%, 10px 100%, 0 85%); background-color: var(--bg-panel); border: 1px solid var(--border-color); }
.cookii-ui-wrapper .copy-btn:hover { text-shadow: 2px 0 var(--accent-red), -2px 0 var(--accent-green); animation: glitch-hover 0.3s cubic-bezier(.25, .46, .45, .94) both infinite; }
.cookii-ui-wrapper .copy-btn:active { transform: translateY(2px); }
@keyframes glitch-hover { 0% { transform: translate(0); } 20% { transform: translate(-2px, 2px); } 40% { transform: translate(-2px, -2px); } 60% { transform: translate(2px, 2px); } 80% { transform: translate(2px, -2px); } to { transform: translate(0); } }

@media (max-width: 600px) { .cookii-ui-wrapper .action-grid { grid-template-columns: 1fr; } }
</style>

<script>
  function createPixelDust() {
    const container = document.getElementById('pixel-particles');
    if (!container) return;
    container.innerHTML = '';
    const particleCount = 20;
    for (let i = 0; i < particleCount; i++) {
      const dot = document.createElement('div');
      dot.className = 'pixel-dot';
      dot.style.left = Math.random() * 100 + '%';
      dot.style.top = Math.random() * 100 + '%';
      dot.style.animationDuration = (Math.random() * 5 + 5) + 's';
      dot.style.animationDelay = Math.random() * 5 + 's';
      const colors = ['#e0af68', '#7dcfff', '#ffffff'];
      dot.style.backgroundColor = colors[Math.floor(Math.random() * colors.length)];
      container.appendChild(dot);
    }
  }

  function copyText(text, btn) {
    // 优先尝试现代 Clipboard API
    if (navigator.clipboard && navigator.clipboard.writeText) {
      navigator.clipboard.writeText(text).then(() => {
        showCopySuccess(btn);
      }).catch(() => {
        // 如果 Clipboard API 失败，回退到传统方法
        fallbackCopy(text, btn);
      });
    } else {
      // 完全不支持 Clipboard API，直接用传统方法
      fallbackCopy(text, btn);
    }
  }

  function fallbackCopy(text, btn) {
    const textarea = document.createElement('textarea');
    textarea.value = text;
    textarea.style.position = 'fixed';
    textarea.style.left = '-9999px';
    textarea.style.top = '-9999px';
    document.body.appendChild(textarea);
    textarea.focus();
    textarea.select();
    try {
      const successful = document.execCommand('copy');
      if (successful) {
        showCopySuccess(btn);
      } else {
        alert('复制失败，请手动复制：' + text);
      }
    } catch (err) {
      alert('复制失败，请手动复制：' + text);
    }
    document.body.removeChild(textarea);
  }

  function showCopySuccess(btn) {
    const originalText = btn.textContent;
    btn.style.animation = 'none';
    btn.textContent = '✔ COPIED!';
    btn.style.color = '#9ece6a';
    setTimeout(() => {
      btn.textContent = originalText;
      btn.style.color = '';
      btn.style.animation = '';
    }, 1000);
  }

  (function init() {
    if (document.readyState === 'loading') {
      document.addEventListener('DOMContentLoaded', createPixelDust);
    } else {
      createPixelDust();
    }
  })();
</script>

<div class="cookii-ui-wrapper">
  <input type="radio" name="pixel-tabs" id="tab-1" checked>
  <input type="radio" name="pixel-tabs" id="tab-2">
  <input type="radio" name="pixel-tabs" id="tab-3">
  <input type="radio" name="pixel-tabs" id="tab-4">

  <div id="pixel-particles"></div>

  <div class="container-wrapper">
    <div class="corner corner-tl"></div>
    <div class="corner corner-tr"></div>
    <div class="corner corner-bl"></div>
    <div class="corner corner-br"></div>
    <div class="container">
      <div class="top-hud">
        <div>📅 <span class="symbol-gold">大乾35年</span></div>
        <div>⏰ <span class="symbol-cyan">巳时三刻</span></div>
        <div>💰 <span class="symbol-gold">52两</span></div>
      </div>

      <div class="char-profile">
        <div class="cy-core"></div>
        <div class="char-profile-info">
          <div class="char-profile-name">逍遥小王爷</div>
          <div class="char-profile-status">系统激活成功</div>
        </div>
      </div>

      <div class="rpg-text-box">
        <p>宿醉的剧痛像把锯子在脑仁里拉扯，你呻吟着睁开眼，入目是绣着鸳鸯戏水的粉色承尘。鼻尖萦绕着昨夜残留的脂粉腻香和浓重的酒气。</p>
        <p>“水……”你下意识地喊道，嗓音沙哑得像吞了把沙子。</p>
        <p>身旁传来一声惊慌的低呼，随即是一阵细碎急促的脚步声。<span class="keyword">流朱<span class="tooltip-text">身份：贴身侍女 | 状态：惊恐 | 好感：-20</span></span>端着醒酒汤匆匆赶来，那双总是含着怯意的眸子此刻写满了恐惧，端着瓷碗的手都在微微颤抖。</p>
        <p>看着她那张清丽却苍白的小脸，前身的记忆如潮水般涌入——稍有不顺便是一顿毒打，昨夜更是差点……愧疚感油然而生，你没有像往常那样暴怒呵斥，而是尽量放缓语气：“手别抖，我不打你。”</p>
        <div class="dialogue-line">“世……世子爷……奴婢该死……奴婢这就伺候您更衣……”</div>
      </div>
      
      <div class="system-ticker">
        <p>// SYS_LOG: Host identity confirmed: Prince of Xiaoyao. // SYNC_RATE: 92%. // WARNING: Reputation critical. // ASSETS: Low. // OBJECTIVE: Survival & Domination.</p>
      </div>

      <div class="tab-container">
        <div class="tab-header">
          <label class="tab-label" for="tab-1">📊 状态</label>
          <label class="tab-label" for="tab-2">🎒 物品</label>
          <label class="tab-label" for="tab-3">🏆 人物</label>
          <label class="tab-label" for="tab-4">🌺 美色</label>
        </div>

        <div class="tab-content-wrapper">
          <!-- Tab 1: 状态 -->
          <div class="tab-content tab-content-1">
            <div class="stat-row">
              <span class="pixel-font">❤️ HP</span>
              <div class="pixel-bar-container"><div class="pixel-bar-fill" style="width: 35%; background-color: #f7768e;"></div></div>
              <span class="pixel-font">35/100</span>
            </div>
            <div class="stat-row">
              <span class="pixel-font">⚡ SP</span>
              <div class="pixel-bar-container"><div class="pixel-bar-fill" style="width: 20%; background-color: #7dcfff;"></div></div>
              <span class="pixel-font">20/100</span>
            </div>
            <div class="stat-row">
              <span class="pixel-font">😈 REP</span>
              <div class="pixel-bar-container"><div class="pixel-bar-fill" style="width: 85%; background-color: #bb9af7;"></div></div>
              <span class="pixel-font">85/100</span>
            </div>
            <p style="font-size: 0.8em; color: #737aa2; margin-top: 10px;">状态: <span class="symbol-red">[宿醉]</span>, <span class="symbol-red">[虚弱]</span>, <span class="symbol-purple">[恶名昭著]</span></p>
          </div>

          <!-- Tab 2: 物品 -->
          <div class="tab-content tab-content-2">
            <p class="list-title" style="color:var(--accent-green);">📦 持有物</p>
            <ul class="generic-list">
              <li class="item-gold">世子腰牌</li>
              <li class="item-purple">贴身玉佩</li>
              <li class="item-green">醒酒汤</li>
            </ul>
          </div>

          <!-- Tab 3: 人物榜 -->
          <div class="tab-content tab-content-3">
            <p class="list-title" style="color:var(--accent-gold);">🏆 能人异士</p>
            <ul class="generic-list">
              <li class="rank-item">
                <span><span class="rank-tag tag-jing">精</span>福伯</span>
                <span style="font-size:0.8em; color:#737aa2;">经营奇才</span>
                <div class="rank-tooltip">王府总管，忠心耿耿</div>
              </li>
              <li class="rank-item">
                <span><span class="rank-tag tag-jia">甲</span>红鸾</span>
                <span style="font-size:0.8em; color:#737aa2;">六品武者</span>
                <div class="rank-tooltip">贴身护卫，性格冷淡</div>
              </li>
            </ul>
          </div>

          <!-- Tab 4: 美色榜 -->
          <div class="tab-content tab-content-4">
            <p class="list-title" style="color:var(--accent-red);">🌺 群芳谱</p>
            <ul class="generic-list">
              <li class="rank-item">
                <span><span class="rank-tag tag-jue">绝</span>苏小小</span>
                <span style="font-size:0.8em; color:#f7768e;">厌恶</span>
                <div class="rank-tooltip">关系详情：因强抢民女而结怨</div>
              </li>
              <li class="rank-item">
                <span><span class="rank-tag tag-jia">甲</span>流朱</span>
                <span style="font-size:0.8em; color:#bb9af7;">惊恐</span>
                <div class="rank-tooltip">关系详情：贴身侍女，长期受虐</div>
              </li>
              <li class="rank-item">
                <span><span class="rank-tag tag-yi">乙</span>红鸾</span>
                <span style="font-size:0.8em; color:#a9b1d6;">鄙视</span>
                <div class="rank-tooltip">关系详情：仅存工作关系</div>
              </li>
            </ul>
          </div>
        </div>
      </div>

      <!-- 复制按钮区域 -->
      <div class="action-pad">
        <div class="action-grid">
            <button class="copy-btn" onclick="copyText('喝下醒酒汤', this)">喝下醒酒汤</button>
            <button class="copy-btn" onclick="copyText('扶我起来', this)">扶我起来</button>
            <button class="copy-btn" onclick="copyText('“昨夜之事，是本世子的错”', this)">“昨夜之事，是本世子的错”</button>
            <button class="copy-btn" onclick="copyText('“你似乎很怕我？”', this)">“你似乎很怕我？”</button>
        </div>
      </div>
    </div>
  </div>
</div>
```

### 🩹 具体改了什么？

1.  **修复按钮失效**：在 `copyText` 函数里加了**降级方案**。现代剪贴板 API 走不通时，会自动切到传统的 `document.execCommand('copy')` 方法，这是在酒馆等受限环境里最有效的兜底手段，复制成功率会高很多。

2.  **修正 HTML 结构**：去掉了最外层多余的 `<html>` 标签。角色卡的第一层楼只需要纯粹的代码片段，外层的 `<html>` 会干扰酒馆自身的页面结构解析。

替换后记得硬刷新一下页面（Ctrl+Shift+R），按钮应该就能正常复制了。

# 用户：
（<think_fox~>
【部分一】

【快速格式检查】

0. ⚠️已确认，检查期间：我不会输出任何形式的内容块或标签！

1. NSFW：是否启用？本轮无NSFW情节。N
2. 文风要求：真实感，行为神态表达情感，感官驱动，动词有力，节奏随场景。Y
3. 人称要求：用户第一人称"我"，其他角色第三人称。Y
4. 推进速度：正常。Y
5. 对白量要求：中等，50%左右。本轮有福伯对话，需保持平衡。
6. 语言要求：简体中文。Y
7. 思考强度：Default。Y
8. 系统扮演：禁止。Y
9. 脏话要求：少说脏话。Y
10. 额外设定：禁止机械感、叙事中立、防剧透、禁止比喻、内心话规则、防全知。Y
11. 抢话规则：要抢话，替用户说话但不替行动。Y
12. 用户角色：禹川，已加载。Y
13. 时间线连续性：上一轮结束在福伯离开、流朱端水。本轮继续。Y
14. 场景类型：中等场景，人物互动和氛围细节写透。Y
15. 字数要求：3000到6000字。
16. 拒绝八股：禁止"不是……是……"句式、禁止"泛着"、禁止排比句、禁止破折号等。Y
17. 角色分析：用户扮演禹川，逍遥小王爷。当前场景涉及福伯（管家）、流朱（侍女）。福伯刚离开又需私下叫回。Y
18. 在场角色清单：流朱、福伯（需叫回）。Y
19. 场景分析：禹川刚查完账，决定振兴王府。现在要私下找福伯说炼琉璃的事，然后回书房画图纸。
20. 情绪连续性：上一轮结束在希望和振奋的情绪中。本轮延续这种积极行动的状态。Y
21. 用户最新请求：私下找到福伯，告诉他炼琉璃的法子，强调保密性和工匠必须是自己人，然后回书房画琉璃炉子图纸。需注意格式要求（HTML代码块格式）。Y
22. 复述/转述用户内容：要转述。需将用户输入分段转述，逐段推进。Y

已检查。将遵循：真实感文风、第一人称、正常推进、中等对白量、简体中文、防八股、禁止比喻、防剧透、防全知、叙事中立、禁止机械感、少说脏话、内心话规则、抢话规则、转述规则、HTML代码块格式输出。

【时间线锁定】

上一轮结束时，福伯抱着账本离开房间，流朱端着温水走到禹川面前。时间点是巳时三刻刚过。本轮从禹川接过水杯之后开始——需要私下叫回福伯。

【角色入戏】

需要进入的角色：
禹川：振奋、决断、谨慎
福伯：激动未平、忠诚、即将震惊

---
【部分二】

【开始内心活动预演】

[OS]

【禹川的内心】

琉璃。这个词在古代意味着什么，福伯很快就会知道。

但比琉璃更重要的，是保密。这个时代，一门独家手艺就是一座金山。如果消息走漏，不止是赚不到钱的问题——怀璧其罪。其他势力、商会、甚至朝廷，都会像闻着血腥味的鲨鱼一样扑过来。

我得让福伯明白这件事有多严重。他不是没见过世面的人，但这次不一样。

(流朱还在旁边，不能当着她的面说。她嘴严，但知道得越少对她越安全。)

先把水喝了，然后找个理由支开她。书房是个好地方，隔墙有耳的可能性最小。

福伯刚才走出去的时候眼眶还是红的。这个老人在王府撑了三年，现在终于看到希望，接下来我要让他看到更大的希望——和更大的责任。

(工匠必须是自己人。签死契的那种。进了王府的琉璃坊，这辈子就别想出去了。听起来残酷，但在这个时代，这是唯一的保险。)

我不是来当圣人的。我是来让王府重新站起来的。过程中需要做的决定，一个都不会犹豫。

图纸……坩埚、鼓风设备、退火窑。中国古代的琉璃工艺其实很早就有，但温度控制和原料配比一直不稳定。我知道石英砂、纯碱、石灰石的比例，知道怎么用锰来调色，知道退火是成败的关键。

(这些知识在前世是课本上的东西，在这里是金山。)

好了，先让流朱去叫福伯回来。就说还有事要商量。

【福伯的内心】

(刚走到回廊，还没出院子，流朱那丫头又跑过来了……世子爷还有吩咐？)

刚才在房里说的那些话，我到现在还没完全消化。三年了，整整三年，我每天晚上算账的时候都在想，这个家还能撑多久。老王妃留下的东西一件件少下去，库房里的银子一天天少下去，我的心也一点点凉下去。

但今天不一样。

世子爷看我的眼神不一样。说话的语气不一样。连坐起来的那个姿势都不一样。以前他坐在床上，整个人是瘫着的。今天是撑着坐起来的。

(他说被业障迷了眼……这话从别人嘴里说出来我不信，从他嘴里说出来，我信。因为我看着他长大，知道他不是天生的混账。)

还有什么事要私下说？不能在房里当着流朱的面说？

(……看来是大事。)

不管是什么，只要世子爷想做正事，我这把老骨头就是拼了命也要帮他。但如果他又想做什么出格的事……不，不会。刚才那个眼神，那是认真的眼神。

好，我去。不管他要说什么，我都听着。

</think_fox~>

```html
<html>
<style>
/* 引入像素字体(英文数字) + 思源宋体(中文，更细更清晰) */
@import url('https://fonts.googleapis.com/css2?family=Press+Start+2P&family=Noto+Serif+SC:wght@300;400;600&family=Noto+Sans+SC:wght@300;400&display=swap');

/* ===== 全局设置 ===== */
.cookii-ui-wrapper {
  --bg-dark: #1a1b26;
  --bg-panel: #24283b;
  --text-main: #a9b1d6;
  --text-bright: #c0caf5;
  --accent-gold: #e0af68;
  --accent-cyan: #7dcfff;
  --accent-green: #9ece6a;
  --accent-red: #f7768e;
  --accent-purple: #bb9af7;
  --border-color: #414868;

  font-family: 'Noto Serif SC', 'Noto Sans SC', serif;
  font-weight: 300;
  color: var(--text-main);
  line-height: 1.6;
  position: relative;
  width: 100%;
  overflow: hidden;
  background-color: var(--bg-dark);
  padding: 0; /* 已根据指令调整为 0 */
  box-sizing: border-box;
}

.cookii-ui-wrapper * {
  box-sizing: border-box;
  word-wrap: break-word;
}

/* 专门针对数字和英文使用像素字体 */
.cookii-ui-wrapper .pixel-font,
.cookii-ui-wrapper .top-hud,
.cookii-ui-wrapper .stat-row span:first-child,
.cookii-ui-wrapper .stat-row span:last-child,
.cookii-ui-wrapper .char-profile-name,
.cookii-ui-wrapper .char-profile-status {
  font-family: 'Press Start 2P', monospace;
  font-size: 0.8em;
}

/* ===== 纯CSS选项卡逻辑 (Radio Hack) ===== */
.cookii-ui-wrapper input[type="radio"] { display: none; }
.cookii-ui-wrapper .tab-content { display: none; animation: fadeIn 0.3s; }

.cookii-ui-wrapper #tab-1:checked ~ .container-wrapper .container .tab-content-1,
.cookii-ui-wrapper #tab-2:checked ~ .container-wrapper .container .tab-content-2,
.cookii-ui-wrapper #tab-3:checked ~ .container-wrapper .container .tab-content-3,
.cookii-ui-wrapper #tab-4:checked ~ .container-wrapper .container .tab-content-4 { display: block; }

.cookii-ui-wrapper #tab-1:checked ~ .container-wrapper .container .tab-header label[for="tab-1"],
.cookii-ui-wrapper #tab-2:checked ~ .container-wrapper .container .tab-header label[for="tab-2"],
.cookii-ui-wrapper #tab-3:checked ~ .container-wrapper .container .tab-header label[for="tab-3"],
.cookii-ui-wrapper #tab-4:checked ~ .container-wrapper .container .tab-header label[for="tab-4"] {
  background: var(--accent-purple); color: #1a1b26; font-weight: bold; box-shadow: inset 0 -4px 0 rgba(0,0,0,0.2);
}

/* ===== CRT 扫描线 & 粒子 ===== */
.cookii-ui-wrapper::before {
  content: " "; display: block; position: absolute; top: 0; left: 0; bottom: 0; right: 0;
  background: linear-gradient(rgba(18, 16, 16, 0) 50%, rgba(0, 0, 0, 0.25) 50%), linear-gradient(90deg, rgba(255, 0, 0, 0.06), rgba(0, 255, 0, 0.02), rgba(0, 0, 255, 0.06));
  z-index: 0; background-size: 100% 2px, 3px 100%; pointer-events: none;
}
.cookii-ui-wrapper #pixel-particles {
  position: absolute; top: 0; left: 0; width: 100%; height: 100%; overflow: hidden; z-index: 1; pointer-events: none;
}
.cookii-ui-wrapper .pixel-dot {
  position: absolute; width: 4px; height: 4px; background-color: rgba(255, 255, 255, 0.1);
  box-shadow: 0 0 4px rgba(255, 255, 255, 0.2); animation: floatUp linear infinite;
}
@keyframes floatUp { 0% { transform: translateY(800px); opacity: 0; } 50% { opacity: 1; } 100% { transform: translateY(-800px); opacity: 0; } }

/* ===== 容器包裹 & HUD角框 ===== */
.cookii-ui-wrapper .container-wrapper { position: relative; padding: 2px; height: 100%; }
.cookii-ui-wrapper .corner {
  position: absolute; width: 20px; height: 20px; border-color: var(--accent-cyan); border-style: solid;
  opacity: 0.7; animation: corner-flicker 3.5s ease-in-out infinite;
}
.cookii-ui-wrapper .corner-tl { top: -2px; left: -2px; border-width: 2px 0 0 2px; }
.cookii-ui-wrapper .corner-tr { top: -2px; right: -2px; border-width: 2px 2px 0 0; animation-delay: 0.7s; }
.cookii-ui-wrapper .corner-bl { bottom: -2px; left: -2px; border-width: 0 0 2px 2px; animation-delay: 1.2s; }
.cookii-ui-wrapper .corner-br { bottom: -2px; right: -2px; border-width: 0 2px 2px 0; animation-delay: 1.9s; }
@keyframes corner-flicker { 0%, 100% { opacity: 0.8; box-shadow: 0 0 5px var(--accent-cyan); } 50% { opacity: 0.3; box-shadow: 0 0 10px var(--accent-cyan); } 75% { opacity: 0.9; } }

/* ===== 主容器 & 动态扫描线 ===== */
.cookii-ui-wrapper .container {
  position: relative; z-index: 2; width: 100%; max-width: 100%; margin: 0; height: 100%;
  border: 4px solid var(--border-color); background: var(--bg-dark);
  box-shadow: 0 0 25px rgba(0,0,0,0.6), 0 0 15px var(--accent-purple);
  display: flex; flex-direction: column; /* 使内部元素可以撑满高度 */
}
.cookii-ui-wrapper .container::after {
    content: ''; position: absolute; left: 0; width: 100%; height: 50%;
    background: linear-gradient(to bottom, rgba(187, 154, 247, 0.15), transparent);
    animation: scanline 4s linear infinite; pointer-events: none; z-index: 11;
}
@keyframes scanline { 0% { top: -50%; } 100% { top: 100%; } }

/* ===== 顶部状态栏 ===== */
.cookii-ui-wrapper .top-hud {
  display: flex; justify-content: space-between; background: var(--bg-panel);
  padding: 8px 10px; border-bottom: 4px solid var(--border-color);
  font-size: 0.75em; color: var(--accent-cyan); align-items: center;
}

/* ===== 角色档案模块 ===== */
.cookii-ui-wrapper .char-profile {
  display: flex; align-items: center; gap: 15px;
  background: var(--bg-panel); padding: 10px 15px;
  border-bottom: 4px solid var(--border-color);
}
.cookii-ui-wrapper .cy-core {
  width: 50px; height: 50px; border: 2px solid var(--accent-purple);
  background: #000; position: relative; animation: core-pulse 2s infinite; flex-shrink: 0;
}
.cookii-ui-wrapper .cy-core::before, .cookii-ui-wrapper .cy-core::after {
  content: ''; position: absolute; top: 50%; left: 50%;
  transform: translate(-50%, -50%); background: var(--accent-purple);
}
.cookii-ui-wrapper .cy-core::before { width: 60%; height: 2px; }
.cookii-ui-wrapper .cy-core::after { width: 2px; height: 60%; }
@keyframes core-pulse { 0%, 100% { box-shadow: 0 0 5px var(--accent-purple); } 50% { box-shadow: 0 0 15px var(--accent-purple); } }

.cookii-ui-wrapper .char-profile-name { font-size: 1.1em; color: var(--text-bright); }
.cookii-ui-wrapper .char-profile-status { font-size: 0.8em; color: var(--accent-green); text-shadow: 0 0 5px var(--accent-green); }

/* ===== 文本区域 & 交互式关键词 ===== */
.cookii-ui-wrapper .rpg-text-box { padding: 15px; background: var(--bg-dark); font-size: 1em; color: var(--text-bright); overflow-y: auto; flex-grow: 1; }
.cookii-ui-wrapper p { margin-bottom: 12px; line-height: 1.8; color: var(--text-bright); font-weight: 300; }

.cookii-ui-wrapper .keyword {
  color: var(--accent-cyan); text-decoration: underline; text-decoration-style: dotted;
  text-underline-offset: 3px; cursor: help; position: relative;
}
.cookii-ui-wrapper .keyword .tooltip-text {
  visibility: hidden; width: max-content; background-color: var(--bg-panel);
  color: var(--text-bright); text-align: center; border-radius: 4px;
  padding: 5px 10px; position: absolute; z-index: 10;
  bottom: 125%; left: 50%; transform: translateX(-50%);
  opacity: 0; transition: opacity 0.3s;
  border: 1px solid var(--accent-cyan); font-size: 0.85em;
  box-shadow: 0 3px 15px rgba(0,0,0,0.5);
}
.cookii-ui-wrapper .keyword:hover .tooltip-text { visibility: visible; opacity: 1; }

/* ===== 特殊符号与对话 (加强辉光) ===== */
.cookii-ui-wrapper .symbol-gold { color: var(--accent-gold); font-weight: 600; text-shadow: 0 0 8px var(--accent-gold); }
.cookii-ui-wrapper .symbol-red { color: var(--accent-red); font-weight: 600; text-shadow: 0 0 8px var(--accent-red); }
.cookii-ui-wrapper .symbol-cyan { color: var(--accent-cyan); font-weight: 600; text-shadow: 0 0 8px var(--accent-cyan); }
.cookii-ui-wrapper .symbol-purple { color: var(--accent-purple); font-weight: 600; text-shadow: 0 0 8px var(--accent-purple); }
.cookii-ui-wrapper .dialogue-line {
  border-left: 4px solid var(--accent-gold); padding-left: 10px;
  background: rgba(224, 175, 104, 0.1); margin: 15px 0; color: var(--accent-gold);
  font-family: 'Noto Serif SC', serif; font-weight: 400;
}

/* ===== 系统日志滚动条 ===== */
.cookii-ui-wrapper .system-ticker {
  background: #000; color: var(--accent-green); padding: 4px 0;
  border-top: 2px solid var(--border-color); border-bottom: 2px solid var(--border-color);
  font-family: 'Press Start 2P', monospace; font-size: 0.7em; white-space: nowrap; overflow: hidden;
}
.cookii-ui-wrapper .system-ticker p { margin: 0; display: inline-block; padding-left: 100%; animation: scroll-left 30s linear infinite; }
@keyframes scroll-left { 0% { transform: translateX(0); } 100% { transform: translateX(-250%); } }

/* ===== Tab 样式 (带图标) ===== */
.cookii-ui-wrapper .tab-container { background: var(--bg-panel); }
.cookii-ui-wrapper .tab-header { display: flex; flex-wrap: wrap; background: var(--bg-dark); border-bottom: 4px solid var(--border-color); }
.cookii-ui-wrapper .tab-label {
  flex: 1; min-width: 50px; padding: 10px 2px; background: var(--bg-dark);
  border-right: 2px solid var(--border-color); color: var(--text-main);
  font-family: 'Noto Sans SC', sans-serif; font-size: 0.9em; cursor: pointer; transition: all 0.2s;
  text-align: center; display: flex; align-items: center; justify-content: center; gap: 5px; user-select: none;
}
.cookii-ui-wrapper .tab-label:hover { background: var(--border-color); color: #fff; }
.cookii-ui-wrapper .tab-content-wrapper { padding: 15px; min-height: 120px; }
@keyframes fadeIn { from { opacity: 0; transform: translateY(10px); } to { opacity: 1; transform: translateY(0); } }

/* ===== 列表通用样式 & 悬浮提示 ===== */
.cookii-ui-wrapper .list-title { color: var(--text-bright); border-bottom: 2px solid var(--border-color); margin-bottom: 10px; padding-bottom: 5px; font-weight: 400; }
.cookii-ui-wrapper .generic-list { list-style: none; padding: 0; margin: 0; }
.cookii-ui-wrapper .generic-list li { padding: 8px; margin-bottom: 4px; background: rgba(0,0,0,0.2); border: 2px solid transparent; transition: all 0.2s; font-weight: 400; position: relative; }
.cookii-ui-wrapper .generic-list li:hover { border-color: var(--accent-cyan); background: rgba(0,0,0,0.4); }
.cookii-ui-wrapper .generic-list li::before { content: "◆"; color: var(--accent-cyan); margin-right: 10px; font-weight: bold; }
.cookii-ui-wrapper .rank-tooltip { display: none; position: absolute; top: 100%; left: 20px; z-index: 20; background: var(--bg-panel); border: 1px solid var(--accent-purple); padding: 5px 8px; font-size: 0.8em; color: var(--text-bright); border-radius: 3px; white-space: nowrap; box-shadow: 0 2px 10px rgba(0,0,0,0.7); }
.cookii-ui-wrapper .rank-item:hover .rank-tooltip { display: block; }
.cookii-ui-wrapper .item-gold { color: var(--accent-gold); text-shadow: 0 0 8px var(--accent-gold); }
.cookii-ui-wrapper .item-purple { color: var(--accent-purple); text-shadow: 0 0 8px var(--accent-purple); }
.cookii-ui-wrapper .item-green { color: var(--accent-green); text-shadow: 0 0 8px var(--accent-green); }
.cookii-ui-wrapper .rank-item { display: flex; justify-content: space-between; align-items: center; }
.cookii-ui-wrapper .rank-tag { display: inline-block; padding: 1px 5px; margin-right: 8px; font-size: 0.85em; color: #1a1b26; font-weight: bold; border-radius: 2px;}
.cookii-ui-wrapper .tag-jing { background: var(--accent-cyan); }
.cookii-ui-wrapper .tag-jia { background: var(--accent-gold); }
.cookii-ui-wrapper .tag-yi { background: #9aa5ce; }
.cookii-ui-wrapper .tag-jue { background: var(--accent-red); }

/* ===== 属性条 (动态能量流动) ===== */
.cookii-ui-wrapper .stat-row { display: flex; justify-content: space-between; margin-bottom: 8px; font-size: 0.85em; color: var(--text-bright); align-items: center; }
.cookii-ui-wrapper .pixel-bar-container { width: 50%; height: 10px; background: #000; border: 2px solid var(--border-color); }
.cookii-ui-wrapper .pixel-bar-fill { height: 100%; background-image: linear-gradient(45deg,rgba(255,255,255,.15) 25%,transparent 25%,transparent 50%,rgba(255,255,255,.15) 50%,rgba(255,255,255,.15) 75%,transparent 75%,transparent); background-size: 20px 20px; animation: animated-stripes 1s linear infinite; }
@keyframes animated-stripes { from { background-position: 20px 0; } to { background-position: 0 0; } }

/* ===== 复制按钮区域 (故障艺术风格) ===== */
.cookii-ui-wrapper .action-pad { padding: 15px; background: var(--bg-dark); border-top: 4px solid var(--border-color); }
.cookii-ui-wrapper .action-grid { display: grid; grid-template-columns: 1fr 1fr; gap: 15px; }
.cookii-ui-wrapper .copy-btn { background: transparent; border: none; color: var(--accent-cyan); padding: 12px 10px; font-family: 'Press Start 2P', monospace; font-size: 0.8em; cursor: pointer; text-align: center; transition: all 0.2s; position: relative; user-select: none; clip-path: polygon(0 0, 100% 0, 100% 100%, 10px 100%, 0 85%); background-color: var(--bg-panel); border: 1px solid var(--border-color); }
.cookii-ui-wrapper .copy-btn:hover { text-shadow: 2px 0 var(--accent-red), -2px 0 var(--accent-green); animation: glitch-hover 0.3s cubic-bezier(.25, .46, .45, .94) both infinite; }
.cookii-ui-wrapper .copy-btn:active { transform: translateY(2px); }
@keyframes glitch-hover { 0% { transform: translate(0); } 20% { transform: translate(-2px, 2px); } 40% { transform: translate(-2px, -2px); } 60% { transform: translate(2px, 2px); } 80% { transform: translate(2px, -2px); } to { transform: translate(0); } }

/* 响应式 */
@media (max-width: 600px) { .cookii-ui-wrapper .action-grid { grid-template-columns: 1fr; } }
</style>

<script>
  function createPixelDust() {
    const container = document.getElementById('pixel-particles');
    if (!container) return;
    container.innerHTML = '';
    const particleCount = 20;
    for (let i = 0; i < particleCount; i++) {
      const dot = document.createElement('div');
      dot.className = 'pixel-dot';
      dot.style.left = Math.random() * 100 + '%';
      dot.style.top = Math.random() * 100 + '%';
      dot.style.animationDuration = (Math.random() * 5 + 5) + 's';
      dot.style.animationDelay = Math.random() * 5 + 's';
      const colors = ['#e0af68', '#7dcfff', '#ffffff'];
      dot.style.backgroundColor = colors[Math.floor(Math.random() * colors.length)];
      container.appendChild(dot);
    }
  }

  function copyText(text, btn) {
    navigator.clipboard.writeText(text).then(() => {
      const originalText = btn.textContent;
      btn.style.animation = 'none';
      btn.textContent = '✔ COPIED!';
      btn.style.color = '#9ece6a';
      setTimeout(() => {
        btn.textContent = originalText;
        btn.style.color = '';
        btn.style.animation = '';
      }, 1000);
    }).catch(err => console.error('复制失败:', err));
  }

  (function init() {
    if (document.readyState === 'loading') {
      document.addEventListener('DOMContentLoaded', createPixelDust);
    } else {
      createPixelDust();
    }
  })();
</script>

<div id="pixel-particles"></div>

<div class="container-wrapper">
  <div class="corner corner-tl"></div>
  <div class="corner corner-tr"></div>
  <div class="corner corner-bl"></div>
  <div class="corner corner-br"></div>
  <div class="container">
    <div class="top-hud">
      <div>📅 <span class="symbol-gold">大乾35年</span></div>
      <div>⏰ <span class="symbol-cyan">巳时四刻</span></div>
      <div>💰 <span class="symbol-gold">52两</span></div>
    </div>

    <div class="char-profile">
      <div class="cy-core"></div>
      <div class="char-profile-info">
        <div class="char-profile-name">逍遥小王爷</div>
        <div class="char-profile-status">筹谋振兴</div>
      </div>
    </div>

    <div class="rpg-text-box">
      <p>我从流朱手里接过那杯温水，指尖碰到杯壁时，感受到上面残留的她掌心的温度。水是温的，不烫不凉，刚好入口。我慢慢喝了两口，润了润还在发干的嗓子，然后把杯子搁回小几上。</p>
      <p>流朱伸手要来接空杯，身子微微前倾，翠绿罗裙的下摆在地砖上轻轻扫过。她的手指纤细，指甲修剪得很短，边缘有些粗糙——那是常年干活留下的痕迹。我看了她一眼，这丫头从进门到现在，肩膀一直绷着没松过。</p>
      <p>“流朱，你去追上福伯，叫他到书房等我。就说我还有事要商量，私下说。”我把声音压得比刚才低了些，语气里带着几分不容置疑的郑重。</p>
      <p>流朱微微一怔，那双清澈的眸子里闪过一丝困惑。私下说——这三个字意味着什么，她作为王府的大丫鬟自然听得懂。她抿了抿嘴唇，没有多问，只是点了点头，应了一声“是”，便转身快步出了门。裙摆拂过门槛时带起一阵细微的风，珠帘被碰得轻轻晃动，发出碎玉般的声响。</p>
      <p>屋里又安静下来。我撑着床沿站起身，宿醉后的眩晕在太阳穴里跳了几下，我闭眼等了两息，让那股恶心感自己退下去。然后整了整身上皱巴巴的中衣，披了件外袍，推门朝书房走去。</p>
      <p>回廊里的穿堂风吹过来，带着院子里桂花将谢未谢的甜腻气息。廊柱上的红漆已经斑驳，几处甚至露出了底下灰白的木胎。前身把钱都花在了醉仙楼的酒席上，连自家的门面都顾不上修葺。我一路走一路看，心里默默记下需要修缮的地方——等有了钱，第一件事就是把王府的门脸重新收拾出来。在这个看人下菜碟的世道里，门面就是底气。</p>
      <p>书房在王府东厢，离卧房隔了两进院子。我推开那扇沉重的雕花木门时，门轴发出一声干涩的呻吟。书房里的陈设还算整齐——福伯一直在维护这间屋子，大概是盼着哪天小王爷能重新走进来。桌案上摆着文房四宝，砚台里的墨早就干了，裂成几道细纹。笔架上挂着几支狼毫，笔尖硬邦邦的，不知多久没沾过水。书架上的书倒是码得整整齐齐，但凑近了看，书脊上落了一层薄灰。前身从来不碰这些。</p>
      <p>我在桌案后坐下，屁股刚挨着椅子，门外就传来了脚步声。一轻一重——轻的是流朱，重的是福伯。流朱在门外停下，没有进来，只是轻轻说了句“世子爷，福伯到了”，便退到廊下候着。这丫头机灵，知道我不让她进去，就没多问一个字。</p>
      <p>福伯推门进来的时候，额头上又沁出了一层汗。他显然是刚回到自己房里又被叫回来的，连口气都没来得及喘匀。他弯腰行礼，抬头看我时，那双浑浊的老眼里还残留着刚才哭过的红丝，但目光比之前亮了许多。</p>
      <p>“世子爷，您还有吩咐？”他的声音里带着期待，也有几分紧张。大概是在猜我是不是又反悔了。</p>
      <p>“把门关上。”我指了指他身后的门扇。</p>
      <p>福伯转身关门的时候，手在门板上停了一下。他做了三十年管家，知道“关门说话”意味着什么——要么是机密，要么是坏事。他深吸一口气，把门合严，然后转过身来，站得笔直。这个老人虽然背有点驼，但腰杆挺起来的时候，还是能看出当年在老王爷身边当差的精气神。</p>
      <p>“福伯，”我看着他，声音不高，但每个字都咬得很清楚，“刚才说的一百两本钱，我有办法弄到。一个能赚一千两的法子。”</p>
      <p>福伯的眼睛猛地睁大了一圈，嘴唇翕动了两下，像是想说什么又憋回去了。他的手不自觉地攥住了袍子的侧缝，指节微微发颤。</p>
      <p>“我会炼琉璃。”我直接抛出这四个字，然后停下来，观察他的反应。</p>
      <p>福伯愣在原地，整个人像被定住了一样。他的眉毛先是拧在一起，然后慢慢舒开，又拧起来。嘴张开，合上，又张开。花白的胡须随着他的呼吸轻轻抖动。这个在商场里摸爬滚打了几十年的老管家，此刻脸上的表情像是一个刚入行的学徒听到了什么匪夷所思的秘方。</p>
      <p>“世子爷……”他的声音压得极低，几乎是气声，“您说的琉璃，可是西域那边进贡的那种……透明如水晶、光照有七彩的琉璃？”</p>
      <p>“比那个更好。”我抬手示意他走近些，“我能炼出无色透明的，也能炼出各色彩琉璃。云州城里现在一件琉璃器的价钱，你比我清楚。”</p>
      <p>福伯倒吸了一口凉气。他下意识地回头看了一眼紧闭的房门，然后往前走了两步，一直走到桌案边上，两只手撑在桌沿上，身体前倾，声音压得只有我们两个人能听见。</p>
      <p>“世子爷，市面上一只琉璃杯，成色好的能卖到二十两。如果是大食那边过来的，价格翻倍。去年知府大人家办寿宴，托人从京城弄了一套琉璃酒具，花了足足五百两。”他说着说着，手指在桌面上不自觉地比划起来，“如果能稳定出产，云州四大商会抢着要，光这一项，一年进项不会少于……”他顿了一下，咽了口唾沫，“三千两。”</p>
      <p>“不止。”我摇了摇头，“云州只是起点。往北有京城，往南有江南，琉璃这东西不愁卖。但福伯，我要跟你说的不是能赚多少钱。”</p>
      <p>我的语气沉下来，看着他的眼睛。福伯被我的目光钉在原地，脸上的兴奋之色慢慢收敛，换成了凝重的神色。他做了三十年管家，自然知道天上不会掉馅饼。</p>
      <p>“炼琉璃的法子，整个大乾朝只有我一个人知道。”我一字一顿地说，“如果这个法子漏出去，你和我，整个逍遥王府，都会死。不是被官府砍头——官府还没那个胆子动皇亲。是被无数双暗地里的手掐死。商会、权贵、甚至宫里的人，谁拿到这个法子谁就能富可敌国。他们会不惜一切代价从我嘴里撬出来。你明白我的意思吗？”</p>
      <p>福伯的脸色白了几分。他沉默了很久，久到窗外传来两声鸟叫，然后他缓缓地点了点头。点得很慢，但很用力。</p>
      <p>“老奴明白。”他的声音有些沙哑，但很稳，“怀璧其罪。”</p>
      <p>“所以，所有经手炼琉璃的工匠，必须是我们王府的人。”我站起来，走到福伯面前，和他面对面站着，“签死契，一辈子绑在王府。他们的家人也接进府里安置，吃穿用度全部王府出。表面上是恩典，实际上是保障——他们不敢跑，跑了家人就没了。这不是我心狠，是这件事容不得半点闪失。”</p>
      <p>福伯的喉结上下滚动了一下。他垂下眼睛，思考了几息，然后抬起头来，目光里已经没有犹豫了。</p>
      <p>“城南有几家窑厂，里面的匠人老奴认识几个。不是最好的，但胜在老实本分。其中有对父子，姓周，祖上三代都是烧瓷器的，手艺扎实，人嘴也严。老奴可以先去探探口风，如果他们愿意签死契，就把人带回来。”他顿了顿，补充道，“以修缮王府的名义请人，不会引起外人疑心。”</p>
      <p>“就按你说的办。”我点了点头，然后又加了一句，“人带回来之后，先别告诉他们要做什么。等琉璃坊建好了，我亲自跟他们说。”</p>
      <p>“是。”福伯躬身应下，直起腰的时候，他看了我一眼，嘴唇动了动，像是还有话要说。犹豫了两息，他还是开口了：“世子爷，老奴斗胆问一句——这炼琉璃的法子，您是从何处……”</p>
      <p>“福伯。”我打断他，语气不算严厉，但足够让他知道这个问题不该问。</p>
      <p>“老奴多嘴了。”他立刻低下头，但脸上的表情放松了几分。他刚才问那句话，是谨慎。但我不回答，他反而更放心——秘密就该有秘密的样子。</p>
      <p>“去吧，先把工匠的事办了。其他的，等我图纸画好了再说。”我挥了挥手。</p>
      <p>福伯弯腰退到门口，转身开门的时候，动作比刚才利索了不少。他走出书房，顺手把门重新带上。我听见他在廊下低声跟流朱说了句什么，然后脚步声渐渐远去。那个脚步声不再是沉重的，而是有力而急促的。一个有了奔头的人，走路的声音都不一样。</p>
      <p>流朱轻轻敲了敲门框，隔着门问：“世子爷，要奴婢进来研墨吗？”</p>
      <p>“进来。”我说。</p>
      <p>她推门进来，走到桌案边，挽起袖子露出一截白净的手腕，拿起墨锭在砚台上滴水研磨。动作熟练而轻巧，墨锭在砚面上划出均匀的沙沙声。她垂着眼睛，专心致志地磨墨，没有多问一个字。但我注意到，她的呼吸比刚才平稳了许多，肩膀也松下来了。</p>
      <p>我从笔架上取下一支小号的狼毫，在清水里泡软了笔尖，然后铺开一张宣纸，用镇纸压住四角。流朱把磨好的墨推到我手边，又退后两步，站在一旁静静看着。</p>
      <p>笔尖蘸饱了墨，在砚台边沿轻轻刮去多余的墨汁。我闭上眼睛，在脑中回忆琉璃炉的结构。前世参观玻璃工坊时，那个老师傅讲得很细——坩埚炉的温度要稳定在一千度以上，鼓风系统决定了炉温的均匀程度，退火窑必须独立隔开，温度要缓慢下降。石英砂、纯碱、石灰石的比例是三比一比零点五，锰粉用来脱色，铜粉出蓝，铁粉出绿。</p>
      <p>睁开眼，落笔。</p>
      <p>第一笔画出了主炉膛的轮廓——一座长方形的砖砌炉体，中央是放置坩埚的燃烧室。炉壁要用耐火砖砌筑，夹层填充草木灰隔热。炉底留出灰坑，炉顶开设投料口。笔尖在纸上稳稳地游走，每一根线条都清晰而准确。流朱站在旁边，看着纸上逐渐成型的图形，眼睛越睁越大。</p>
      <p>第二张纸画鼓风系统——炉体侧面连接风管，风管末端是两架并联的手动鼓风皮囊。皮囊用牛皮缝制，中间夹木条做骨架，推拉之间将空气压入炉膛。风管入炉处要设置一个陶制的分流嘴，让气流均匀分布在燃烧室底部，不能直吹坩埚。</p>
      <p>第三张纸画退火窑——这是一个独立的长条形窑室，温度从入口到出口逐渐降低。琉璃器成型后不能直接冷却，必须在退火窑里缓慢降温，否则会炸裂。窑顶标注了温度梯度，从八百度缓慢降到室温，整个过程需要一天一夜。</p>
      <p>我画得入了神，笔尖在纸上游走的速度越来越快。流朱在一旁连大气都不敢出，只在我需要换纸的时候，轻手轻脚地把画好的图纸挪到旁边晾干。她挪纸的时候看了一眼图纸上的标注，嘴唇无声地动了几下，大概是在认那些字。她不识字，但那些线条的精密程度已经足够让她震撼。</p>
      <p>画完三张主体结构图，我又取了一张小纸，开始列原料清单。石英砂——要派人去城外的白溪滩挖，那里的砂子含铁量低，烧出来的琉璃更通透。纯碱——这东西古代叫“碱土”，得去杂货铺买，或者直接从草木灰里提纯。石灰石——城外采石场有的是。锰粉——这个最麻烦，得从软锰矿里研磨，云州不产，要去药铺问问有没有“无名异”这味药材，其实就是天然二氧化锰。</p>
      <p>笔停了。我把笔搁在笔架上，直起腰，长长地吐出一口气。四张图纸铺在桌上，墨迹未干，在透过窗棂的阳光下泛着湿润的光泽。流朱站在旁边，看看图纸又看看我，那双清澈的眼睛里多了一种以前从未有过的东西——敬畏。</p>
      <p>“世子爷……”她轻声开口，声音里带着几分试探，“这些东西，真的能做出琉璃来吗？”</p>
      <p>“能。”我揉了揉发酸的手腕，“等福伯把工匠带回来，炉子建起来，你就知道了。”</p>
      <p>窗外，阳光已经升到了半空。院子里的桂花树在风中轻轻摇晃，几片枯叶从枝头飘下来，落在青石板上。远处隐约传来街市的喧闹声，那是云州城午前的繁华。但这些喧闹和此刻的书房隔了很远——隔了一扇门，一堵墙，一个正在重新苏醒的王府。</p>
    </div>

    <div class="system-ticker">
      <p>// SYS_LOG: Secret project initiated: Glassmaking. // SECURITY LEVEL: Maximum. // TASK: Fu Bo recruiting trusted craftsmen. // NEW BLUEPRINT: Furnace design completed. // OBJECTIVE: Build glass workshop.</p>
    </div>

    <div class="tab-container">
      <div class="tab-header">
        <label class="tab-label" for="tab-1">📊 状态</label>
        <label class="tab-label" for="tab-2">🎒 物品</label>
        <label class="tab-label" for="tab-3">🏆 人物</label>
        <label class="tab-label" for="tab-4">🌺 美色</label>
      </div>

      <div class="tab-content-wrapper">
        <div class="tab-content tab-content-1">
          <div class="stat-row">
            <span class="pixel-font">❤️ HP</span>
            <div class="pixel-bar-container"><div class="pixel-bar-fill" style="width: 45%; background-color: #f7768e;"></div></div>
            <span class="pixel-font">45/100</span>
          </div>
          <div class="stat-row">
            <span class="pixel-font">⚡ SP</span>
            <div class="pixel-bar-container"><div class="pixel-bar-fill" style="width: 30%; background-color: #7dcfff;"></div></div>
            <span class="pixel-font">30/100</span>
          </div>
          <div class="stat-row">
            <span class="pixel-font">😈 REP</span>
            <div class="pixel-bar-container"><div class="pixel-bar-fill" style="width: 85%; background-color: #bb9af7;"></div></div>
            <span class="pixel-font">85/100</span>
          </div>
          <p style="font-size: 0.8em; color: #737aa2; margin-top: 10px;">状态: <span class="symbol-red">[宿醉]</span>, <span class="symbol-green">[琉璃图纸完成]</span>, <span class="symbol-cyan">[秘密项目启动]</span></p>
        </div>

        <div class="tab-content tab-content-2">
          <p class="list-title" style="color:var(--accent-green);">📦 持有物</p>
          <ul class="generic-list">
            <li class="item-gold">世子腰牌</li>
            <li class="item-purple">贴身玉佩</li>
            <li class="item-green">福伯整理的账目清单</li>
            <li class="item-cyan">琉璃炉设计图(4张)</li>
          </ul>
        </div>

        <div class="tab-content tab-content-3">
          <p class="list-title" style="color:var(--accent-gold);">🏆 能人异士</p>
          <ul class="generic-list">
            <li class="rank-item">
              <span><span class="rank-tag tag-jing">精</span>福伯</span>
              <span style="font-size:0.8em; color:#9ece6a;">忠诚↑ 执行中</span>
              <div class="rank-tooltip">王府总管，正在秘密招募琉璃工匠</div>
            </li>
            <li class="rank-item">
              <span><span class="rank-tag tag-jia">甲</span>红鸾</span>
              <span style="font-size:0.8em; color:#737aa2;">未出场</span>
              <div class="rank-tooltip">贴身护卫，六品武者</div>
            </li>
          </ul>
        </div>

        <div class="tab-content tab-content-4">
          <p class="list-title" style="color:var(--accent-red);">🌺 群芳谱</p>
          <ul class="generic-list">
            <li class="rank-item">
              <span><span class="rank-tag tag-jue">绝</span>苏小小</span>
              <span style="font-size:0.8em; color:#f7768e;">厌恶</span>
              <div class="rank-tooltip">关系详情：因强抢民女而结怨</div>
            </li>
            <li class="rank-item">
              <span><span class="rank-tag tag-jia">甲</span>流朱</span>
              <span style="font-size:0.8em; color:#e0af68;">惊疑→敬畏</span>
              <div class="rank-tooltip">关系详情：贴身侍女，亲眼目睹王爷画图纸后态度转变</div>
            </li>
            <li class="rank-item">
              <span><span class="rank-tag tag-yi">乙</span>红鸾</span>
              <span style="font-size:0.8em; color:#a9b1d6;">鄙视</span>
              <div class="rank-tooltip">关系详情：仅存工作关系</div>
            </li>
          </ul>
        </div>
      </div>
    </div>

    <div class="action-pad">
      <div class="action-grid">
        <button class="copy-btn" onclick="copyText('让流朱去把红鸾叫来，炼琉璃的事需要护卫把守，得跟她交代清楚', this)">⚔️ 召见红鸾安排防卫</button>
        <button class="copy-btn" onclick="copyText('趁福伯去找工匠的空档，亲自去城南窑厂实地考察一下，看看有没有合适的场地', this)">🧱 实地考察窑厂</button>
        <button class="copy-btn" onclick="copyText('把图纸收好，先回房休息养足精神，宿醉还没完全退', this)">😴 回房养精蓄锐</button>
        <button class="copy-btn" onclick="copyText('带上图纸去找福伯，跟他一起研究原料采购的事宜', this)">📜 找福伯商议原料</button>
      </div>
    </div>
  </div>
</div>
</html>
```

<fox_selc>
⚔️<font color="#7dcfff">让流朱去把红鸾叫来，炼琉璃的事需要护卫把守，得跟她交代清楚</font>
🧱<font color="#e0af68">趁福伯去找工匠的空档，亲自去城南窑厂实地考察一下，看看有没有合适的场地</font>
😴<font color="#9ece6a">把图纸收好，先回房休息养足精神，宿醉还没完全退</font>
📜<font color="#bb9af7">带上图纸去找福伯，跟他一起研究原料采购的事宜</font>
</fox_selc>）帮我分析为什么上一层状态栏显示成功这层失败了

# DeepSeek：

**原始回答**
看了这两轮代码，问题找到了——**这一轮的 HTML 代码被 `<think_fox~>` 和 `</think_fox~>` 这两个标签包裹住了，酒馆在解析时把它们当成了正文的一部分，导致整个 HTML 结构失效。**

### 对比分析

**上一轮（成功）：**
```html
<style>
...
</style>
<script>
...
</script>
<div class="cookii-ui-wrapper">
...
</div>
```
代码干净，直接从 `<style>` 开始，酒馆能正确识别并渲染。

**这一轮（失败）：**
```html
<think_fox~>
【部分一】...【部分二】...
</think_fox~>
<html>
<style>...</style>
...
</html>
```
代码被包裹在 `<think_fox~>` 标签里，酒馆的解析器无法识别这个自定义标签，直接把它和里面的 HTML 当成了纯文本输出，所以状态栏完全不显示。

### 解决方案

**删除这三样东西：**
1. 所有的 `<think_fox~>` 和 `</think_fox~>` 标签
2. 标签内部的所有思考过程文本
3. 多余的 `<html>` 和 `</html>` 外层标签

最终输出的代码应该直接从 `<style>` 开始，到 `</div>` 结束，中间没有任何额外的包裹。

如果你是用预设命令让 AI 生成这段 HTML，需要在预设里加上一句强制约束，比如：

```
[系统指令：输出的HTML代码块必须直接从<style>开始，绝对禁止包裹在<think_fox~>或任何自定义XML标签中。]
```

这样能防止它再次把思考过程混进代码里。

# 用户：
这个<think_fox~>好像是预设包裹cot思维链的折叠开头与末尾栏。有办法共存吗？

# DeepSeek：

**原始回答**
是的，可以共存。问题关键在于**标签包裹的顺序**——只要把 HTML 状态栏放在 `<think_fox~>` 标签的外面，两者就不会互相干扰。

### 为什么现在会冲突？

你的预设可能是这样工作的：
```
<think_fox~>
[AI的思考过程]
[然后是正式回复，包含 HTML 状态栏]
</think_fox~>
```
浏览器完全不认识 `<think_fox~>` 这个自定义标签，会把它当作无效标记，导致里面所有内容（包括你的 HTML 状态栏）都被当作纯文本直接堆在聊天区，样式和脚本全部失效。

### 共存方案：调整输出顺序

修改预设指令，要求 AI 必须**先输出 HTML 状态栏，再把思考过程包裹在标签里**。例如在预设中明确规定：

```
[输出格式规则]
1. 你的回复必须按以下顺序输出：
   - 第一部分：正文剧情（纯文本）
   - 第二部分：HTML 状态栏（完整的 <style> + <script> + <div> 结构）
   - 第三部分：思考过程，必须用 <think_fox~> 和 </think_fox~> 包裹
2. <think_fox~> 和 </think_fox~> 绝对不能包裹 HTML 代码块或正文剧情。
```

这样输出的结构会是：
```html
（正文剧情纯文本）

<style>...</style>
<script>...</script>
<div class="cookii-ui-wrapper">...</div>

<think_fox~>
[思考过程...]
</think_fox~>
```
酒馆会正常渲染前面的 HTML 状态栏，而 `<think_fox~>` 标签由于在最后，且内部是纯文本，不会破坏页面结构（虽然仍会显示为不明标签，但可以配合 CSS 隐藏它）。

### 进阶优化：用正规的折叠块替代自定义标签

如果你希望思考过程也能整齐地折叠显示，可以考虑把 `<think_fox~>` 替换成 HTML 标准的 `<details>` 标签，这样既能折叠，又不会干扰状态栏。修改预设的规则为：

```
思考过程必须用以下格式包裹：
<details class="fox-thinking">
<summary>🦊 思维链展开/收起</summary>
（你的思考内容）
</details>
```

然后加一段 CSS 美化它：
```css
.fox-thinking {
  margin: 10px 0;
  padding: 10px;
  background: rgba(36, 40, 59, 0.5);
  border: 1px solid var(--accent-purple);
  border-radius: 4px;
  color: var(--text-main);
  font-size: 0.9em;
}
.fox-thinking summary {
  cursor: pointer;
  color: var(--accent-cyan);
  font-weight: bold;
}
```

这样就不需要任何自定义的非法标签，整个输出完全合规，状态栏和思维链都可以稳定共存。本回答由 AI 生成，内容仅供参考，请仔细甄别。

