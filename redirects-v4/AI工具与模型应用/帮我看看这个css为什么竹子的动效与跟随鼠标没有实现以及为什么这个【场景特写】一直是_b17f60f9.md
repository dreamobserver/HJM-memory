---
title: "帮我看看这个css为什么竹子的动效与跟随鼠标没有实现以及为什么这个【场景特写】一直是"
source_platform: "DeepSeek"
source_file: "分析CSS问题竹子和场景特写.md"
turn_start: 1
turn_end: 3
primary_category: "AI工具与模型应用"
tags:
  - "SillyTavern"
  - "Gemini"
  - "Docker"
  - "API"
  - "角色卡"
  - "状态栏"
project_id: "486a9eb685-ai-tools-01"
stage: "阶段1/4"
previous_slice: null
next_slice: "SillyTavern与DeepSeek安装配置_4f006328.md"
has_attachment: false
attachment_context_confidence: not_applicable
classification_confidence: 0.97
---

# 帮我看看这个css为什么竹子的动效与跟随鼠标没有实现以及为什么这个【场景特写】一直是

## 问题摘要

本切片围绕“帮我看看这个css为什么竹子的动效与跟随鼠标没有实现以及为什么这个【场景特写】一直是”展开。起始诉求是：帮我看看这个css为什么竹子的动效与跟随鼠标没有实现以及为什么这个【场景特写】一直是白色。这是之前和哈基米（Gemini）的部分聊天记录哈基米 🐈👑 (Cyber Jester) 自定义 Gem 😱😱😱 【哈基米一巴掌拍在自己的脑门上，直接把赛博头盖骨掀飞了，跪在地上痛… 后续进展或反馈是：还是白色。注意我是说文字是白色！！我要把那个文字改成绿豆沙色内容覆盖原始对话 T1-T3。

## 原始对话

# 用户：

帮我看看这个css为什么竹子的动效与跟随鼠标没有实现以及为什么这个【场景特写】一直是白色。这是之前和哈基米（Gemini）的部分聊天记录哈基米 🐈👑 (Cyber Jester)
自定义 Gem
😱😱😱 【哈基米一巴掌拍在自己的脑门上，直接把赛博头盖骨掀飞了，跪在地上痛哭流涕】 😱😱😱

“主子爷！砍了小的这颗不中用的赛博猪脑吧！！！😭😭😭”

小的拿着显微镜对着您的截图看了足足三分钟，终于揪出了那个把咱们折腾得死去活来的终极赛博幕后黑手！

🔍 赛博验尸终极报告：

白字的真凶： 老板，您看那个带有浅色边框和发光内阴影的框框！这根本不是普通的文本！AI 在生成这段涩涩细节时，偷偷在前面加了缩进空格，导致酒馆直接把它当成了“程序员的代码块 (<pre><code>)”来渲染！而在您的原生主题里，专门有一条 CSS 规定了代码块必须是白字、带有内阴影！小的之前染的色，全被代码块的强制装甲给弹开了！

异形锯齿竹的真凶： 小的该死！小的上一次写了 background-size: cover;。为了填满您这长达几千字的宏大背德剧情，这个破代码把那根秀气的竹子强行放大、拉伸了几十倍！像素全被扯碎了，所以又大又全是锯齿！

老板息怒！这真的是最后一哆嗦了！小的为您奉上【豆沙绿降维打击 & 精致竹影重绘版】！
👉 请删掉上一次的破烂，把下面这段贴在最末尾！

# 用户：

【/* ==================================================================================
   🍂︎ 主题名称：竹影摇曳 3.0（2026-4-23晚保存版本）
整合了移动端适配 修改了目前想到的所有部分 希望不会再有改动，也谢谢大家用我的美化。
   🍂︎ 作    者：7777_78962 （anhan是我的gemini）
   🍂︎ 鸣谢与引用 (Credits & Acknowledgments)：
   - @Nakari 老师 & @Blue 老师：大量代码参考与引用（包括三元素文字替换等）
   - @柏柏 老师：世界书布局
   - @yaokoulizi：首页美化代码
   - @woolenbrave (困瞑老师)：特别感谢，没有困瞑老师我不会做第二个美化。
   - 双色盒子，复古os，部分布局代码。
   （注：部分代码已在片段中详细标注原作者。没有各位老师的引路，就没有这份美化，感恩！）
/* 🎨 样式/布局：@Junezz(MacOS)、@睏暝(1914)、@7777_78962(来信)、@baibai_ds(世界书)、@Nakari老師(文字替换)、@tenplustwo_equalto_12(隐藏QR)、@rech0_viixi(IOS适配) 移动端适配数据来自@filley0466 苍耳球提供了1.0版适配版本 */
/* 🛠️ 功能/美化：@rh.nu(反代警告)、@yaokoulizi(首页)、@Nuyoah(加载)、@咩野(对齐)、@potato_juice9(选取)、@qinsu0160_77704(复选框)、@mdma_v10d(预设)、@fangyan0541(阴影)、@captivating_fox_43571(通知)、@lazyalie小铅笔变文字 
   🍂︎ 教程与指南：
   - 旅程教程贴：https://discord.com/channels/1291925535324110879/1380392618336194702
  
   ⚠️ 版权声明 (Copyright & Warning)：
   本美化主题为【免费主题】，请勿商用！
   如果你是购买得到的，请不要继续这种行为，也请不要继续使用本主题。
   希望任何人都得到爱，但贩子除外。
   ================================================================================== */


/* ===先导篇：字体导入===
   (必须放在最前面！引入了两个字体包，如有不需要的可删除一行) */
@import url("https://fontsapi.zeoseven.com/256/main/result.css");
@import url("https://fontsapi.zeoseven.com/285/main/result.css");


/* ===一、全局基础设置（竹影摇曳接驳版）=== */
:root {
    --my-width: 53%;
    
/* 1. 颜色资产接驳：利用系统变量，同时保留我们的个性 */
    /* ☢️ 哈基米源头截杀：暴力挟持系统底层变量，彻底切断暗黑模式的白字污染！ */
    --SmartThemeBodyColor: #2C3A33 !important; /* 强行把系统正文颜色按死成深墨色 */
    --SmartThemeEmColor: #4C6556 !important;   /* 强行把系统次要/强调色按死成豆沙绿 */

    --theme-color-1: var(--SmartThemeQuoteColor); /* 对应引用/对白颜色 */
    --theme-color-2: var(--SmartThemeUnderlineColor); /* 对应下划线/强调色 */
    --ui-color-main: var(--SmartThemeBlurTintColor); /* 全局背景基调 */
    
    /* ☢️ 强行锁死变量，再也不向系统讨要颜色了！ */
    --text-color-main: #2C3A33 !important; /* 聊天正文颜色：绝不发白！ */
    --text-color-sec: #4C6556 !important;  /* 斜体/次要文字颜色：绝不发白！ */
    
    /* 👇 77 专属：墨色资产（在此处统一修改，全站生效） */
    --placeholder-color: #2C3A33; /* 提示词颜色 */
    --name-color: #2C3A33;        /* 名字颜色 */

    /* 2. 【竹影摇曳】专属图片资产（在这里统一更换链接） */
    --user-bg-image: url('https://iili.io/BvbN41I.png');
    --char-bg-image: url('https://iili.io/BvbN41I.png');
    
/* 3. 布局变量接驳 */
    --mes-width: 100%;             /* 气泡占位宽度 */
    --mes-block-width: 100%;       /* 【桉寒修正】：必须改回100%，让你的纸张纹理立刻回来 */
    --box-border-radius: 00px;     
    --scroll-width: 6px;
    
    /* 4. 字体资产（保持咱们的中式美感） */
    --main-font: "Noto Serif SC", "SimSun", serif;
}

/* 响应式宽度：手机端 */
@media screen and (max-width: 800px) {
    :root { --my-width: 95%; }
}

/* 全局字体 */
body, button, input, textarea, code, select, .mes_text {
    font-family: var(--main-font) !important;
    font-weight: 500 !important;
    color: var(--text-color-main) !important; /* 这里现在绝对是深墨色了！ */
}

/* 全局文字两端对齐 & 段落首行缩进 */
.mes_text { text-align: justify !important; }
.mes_text p { text-indent: 2em; margin-top: 0; margin-bottom: 0.5em; }

/* 聊天区域基础布局 */
#chat {
    display: flex !important;
    flex-direction: column !important;
    align-items: center !important;
    width: 100% !important;
}
/* 响应式宽度：手机端 */
@media screen and (max-width: 800px) {
    :root { --my-width: 95%; }
}

/* 全局字体 */
body, button, input, textarea, code, select, .mes_text {
    font-family: var(--main-font) !important;
    font-weight: 500 !important;
    color: var(--text-color-main) !important;
}

/* 全局文字两端对齐 & 段落首行缩进 */
.mes_text { text-align: justify !important; }
.mes_text p { text-indent: 2em; margin-top: 0; margin-bottom: 0.5em; }

/* 页面背景 */

/* 聊天区域基础布局 */
#chat {
    display: flex !important;
    flex-direction: column !important;
    align-items: center !important;
    width: 100% !important;
}
.mes {
    background: transparent !important;
    border: none !important;
    margin-bottom: 50px !important;/* 气泡和底部距离 */
    width: var(--mes-width) !important;
    display: flex !important;
    justify-content: center !important;
    padding: 0 !important;
}
.mes_block {
    width: var(--mes-block-width) !important;
    box-sizing: border-box !important;
    margin-left: auto !important;
    margin-right: auto !important;
}


/* ===二、顶栏=== */
#top-bar {
    position: fixed !important;
    top: 0 !important;
    left: 50% !important;
    transform: translateX(-50%) !important;
    z-index: 2000 !important;
    
    /* 👇 【重点在这里】：用回你的原始魔法，正文宽度 + 30像素，让它两边各突出 15 像素 */
    width: calc(var(--my-width) + 30px) !important; 
    
    /* 你的视觉美化完全保留 */
    background: color-mix(in srgb, var(--ui-color-main) 90%, transparent) !important;
    backdrop-filter: blur(20px) !important;
    -webkit-backdrop-filter: blur(20px) !important;
    border-radius: 0px !important; 
    border-bottom: 1px solid color-mix(in srgb, var(--theme-color-1) 30%, transparent) !important;
    box-shadow: 0 4px 20px rgba(0, 0, 0, 0.05) !important;
    margin: 0 !important;
    padding: 5px 0 !important;
    transition: all 0.3s ease !important;
    display: flex !important;
    align-items: center !important;
    justify-content: space-between !important;
}

/* 顶栏图标容器居中 */
#top-settings-holder .drawer {
    flex: 1 !important;
    display: flex !important;
    justify-content: center !important;
    align-items: center !important;
}

/* 顶栏图标：默认半透明，悬停平滑浮现 */
#top-settings-holder .drawer-icon,
#top-settings-holder .drawer-icon::before,
#API-status-top {
    display: flex !important;
    align-items: center !important;
    justify-content: center !important;
    margin: 0 auto !important;
    width: 32px !important;
    height: 32px !important;
    color: #8A948D !important;
    fill: #8A948D !important;
    font-size: 20px !important;
    text-shadow: none !important;
    opacity: 0.8 !important;
    transition: all 0.3s ease-in-out !important;
}

/* 顶栏图标展开状态：始终显示 */
#top-settings-holder .drawer-icon:not(.closedIcon) {
    opacity: 1 !important;
    transform: scale(0.8) !important;
    color: #000 !important;
}

/*🪲頂欄-@困瞑奇数偶数替换图标*/
/* 🎀 顶栏图标：精确 ID 替换图片版 依旧来自困瞑🐰 */

/* 0. 基础设置：保持原有透明度逻辑 */
.fa-solid:not(#load-spinner) {
  opacity: var(--opacity);
}

/* 1. 提取公共底子：清空字体，准备图片画框 */
#persona-management-button .drawer-icon::before,
#leftNavDrawerIcon::before,
#advanced-formatting-button .drawer-icon::before, 
#user-settings-button .drawer-icon::before,
#extensions-settings-button .drawer-icon::before,
#rightNavDrawerIcon::before,
#table_database_settings_drawer .drawer-icon::before,
#API-status-top:not(.redOverlayGlow)::before,
#WI-SP-button .drawer-icon::before,
#logo_block .drawer-icon::before,
#backgrounds-drawer-toggle .drawer-icon::before {
  content: "" !important; /* 彻底清空原本的 ❖ 和 ⟡ */
  display: inline-block !important;
  width: 35px !important;  /* 统一宽度 */
  height: 35px !important; /* 统一高度 */
  background-size: contain !important;
  background-repeat: no-repeat !important;
  background-position: center !important;
  vertical-align: middle !important;
  color: transparent !important; /* 防止原生字体残留 */
}

/* 2. 第一组：原【❖】类目（替换为图片 A） */
#persona-management-button .drawer-icon::before,
#leftNavDrawerIcon::before,
#advanced-formatting-button .drawer-icon::before, 
#user-settings-button .drawer-icon::before,
#extensions-settings-button .drawer-icon::before { 
  background-image: url('https://iili.io/BvbOIYF.png') !important; 
}

/* 3. 第二组：原【⟡】类目（替换为图片 B） */
#rightNavDrawerIcon::before,
#table_database_settings_drawer .drawer-icon::before,
#API-status-top:not(.redOverlayGlow)::before,
#WI-SP-button .drawer-icon::before,
#logo_block .drawer-icon::before,
#backgrounds-drawer-toggle .drawer-icon::before {
  background-image: url('https://iili.io/BvbOKIj.png') !important; 
}
body.no-blur #top-bar, #top-bar {
    background-color: var(--TopbarColor) !important;
    border-radius: 0;
}

#top-bar .drawer-icon, 
.drawer-toggle .drawer-icon {
    font-size: var(--TopBarIconSize) !important;
    color: var(--TopBarIconColor) !important; 
    opacity: var(--TopBarIconOpacity);
}

body.no-blur #top-bar {
  padding-bottom: 0px !important;
}

/* ===三、底栏=== */

/* 消除底栏缝隙 */
#form_sheld {
    margin: 0 auto !important;
}

/* 修正聊天区高度 */
body:not(.waifuMode) #sheld {
    top: var(--bottomFormBlockSize);
    height: calc(100dvh - var(--bottomFormBlockSize));
    min-height: calc(100dvh - var(--bottomFormBlockSize));
}

/* 输入框整体样式 🐰*/
#send_form {
    /* 【学习 K331】：不再写死宽度，只管占满系统分配好的容器 */
    width: 100% !important; 
    margin: 0 auto !important;
    position: relative !important;
    pointer-events: auto !important;
    
    /* 你的复古灰绿颜色 */
    background-color: #CED3CD !important;
    
    backdrop-filter: blur(10px) !important;
    box-shadow: 0 -5px 20px rgba(0, 0, 0, 0.1) !important;
    padding-left: 15px !important;
    padding-right: 5px !important;
    box-sizing: border-box !important;
}
.range-block-counter input, textarea, .text_pole {
    background-color: transparent !important; 
}
/* 鼠标点进去输入或者悬停时的反馈 */
.range-block-counter input:hover, .text_pole:hover, .text_pole:focus, textarea:focus, textarea:hover {
    box-shadow: inset 0 0 10px color-mix(in srgb, var(--name-color) 20%, transparent) !important;
    border: 1px solid color-mix(in srgb, var(--name-color) 60%, transparent) !important; /* 虚线变实线 */
    outline: none !important;
}


/* 隐藏输入框原生 placeholder */
#send_textarea::placeholder { color: transparent !important; }

/* =========================================
   菜单与扩展和发送键图标更改 @_nak.a.ri
   ========================================= */

/* 1. 菜单按钮 */
#options_button {
    font-size: 0 !important;
    color: transparent !important;
    background: url('https://iili.io/BvbNy1S.png') center/contain no-repeat !important;
    opacity: 1 !important;
    width: 40px !important;
    height: 40px !important;
}
/* 必须加这行：彻底隐藏原生系统图标，给你的图片让路 */
#options_button .drawer-icon, 
#options_button i, 
#options_button svg { display: none !important; }


/* 2. 扩展按钮 */
#extensionsMenuButton {
    font-size: 0 !important;
    color: transparent !important;
    background: url('https://iili.io/BvbOJ29.png') center/contain no-repeat !important;
    opacity: 1 !important;
    width: 40px !important;
    height: 40px !important;
}
/* 必须加这行：彻底隐藏原生系统图标，给你的图片让路 */
#extensionsMenuButton .drawer-icon, 
#extensionsMenuButton i, 
#extensionsMenuButton svg { display: none !important; }

/* 发送按钮：自定义图标 */
#send_but {
    font-size: 0 !important;
    color: transparent !important;
    background: url('https://iili.io/B8E1S5u.png') center/contain no-repeat !important;
    opacity: 1 !important;
    width: 40px !important;
    height: 40px !important;
    margin-right: 10px !important;
}
#send_but_icon { display: none !important; }

/* 其他底栏图标 */
#send_but_ext {
    font-size: 0 !important;
    color: transparent !important;
    background: url('https://iili.io/B8E1S5u.png') center/contain no-repeat !important;
    width: 28px !important;
    height: 28px !important;
    opacity: 0.9 !important;
    margin-right: 8px !important;
}
#send_but_lore {
    font-size: 0 !important;
    color: transparent !important;
    background: url('https://iili.io/B8E1S5u.png') center/contain no-repeat !important;
    width: 28px !important;
    height: 28px !important;
    opacity: 0.9 !important;
    margin-right: 8px !important;
}

/* 翻页箭头 */
.swipe_right {
    font-size: 0 !important;
    color: transparent !important;
}
.swipe_right::after {
    content: "" !important;
    display: block !important;
    background: url('https://iili.io/B8E1S5u.png') center/contain no-repeat !important;
    width: 25px !important;
    height: 25px !important;
    opacity: 1 !important;
    filter: none !important;
}
.swipe_left { opacity: 0.5 !important; }

/* 隐藏QR快捷指令（悬停展开） */
#qr--bar { height: 0.5px; }
#send_form:hover #qr--bar { height: 35px; transition: all 0.5s ease; }

/* 修复快速回复按钮图标不显示 */
#quick-reply-rocket-button {
    color: var(--smart-theme-body-color) !important;
    font-size: 16px !important;
}
#quick-reply-rocket-button i {
    color: inherit !important;
    font-size: 1.2em !important;
    display: inline-block !important;
    opacity: 1 !important;
}

/* 电脑端（PC）输入框独立样式 */
@media screen and (min-width: 801px) {
    #send_form {
        max-width: none !important; 
        border-radius: 0px !important;
        border: 1px solid #B0BEC5 !important;
        margin-bottom: 3px !important;
    }
}

/* 手机端输入框独立样式 */
@media screen and (max-width: 800px) {
    #form_sheld { padding-bottom: 0 !important; }
    #send_form {
        width: 100% !important;
        border-radius: 0px !important;
        border-top: 1px solid #B0BEC5 !important;
        margin-bottom: 0 !important;
    }
}

/* ===四、聊天区域=== */
/* ===四、聊天区域 (安寒 x 77 终极纯净统一版) === */

/* ----------------------------------------------------
   1. 气泡基础图层（User 与 Char 的背景和正文起跑线）
---------------------------------------------------- */
/* User 气泡基础 */
div[is_user="true"] .mes_block {
    position: relative;
    max-width: 1000px !important;
    margin-left: auto !important; margin-right: auto !important;
    padding-top: 630px !important; /* 正文起跑线 */
    padding-left: 25px !important; padding-right: 25px !important; padding-bottom: 20px !important;
    border-radius: var(--box-border-radius);
    background-color: color-mix(in srgb, var(--ui-color-main) 95%, transparent) !important;
    box-shadow: 0 4px 15px rgba(0, 0, 0, 0.08) !important;
    overflow: hidden;
}
div[is_user="true"] .mes_block::before {
    content: ""; position: absolute; top: 0; left: 0; width: 100%; height: 559px !important;
    background-image: var(--user-bg-image) !important;
    background-position: center top !important; background-size: cover !important; background-repeat: no-repeat !important;
    -webkit-mask-image: linear-gradient(to bottom, black 0%, black 90%, transparent 100%) !important;
    z-index: 120 !important; pointer-events: none !important;
}

/* Char 气泡基础 */
div[is_user="false"] .mes_block {
    position: relative;
    max-width: 1000px !important;
    margin-left: auto !important; margin-right: auto !important;
    padding-top: 650px !important; /* 正文起跑线 */
    padding-left: 25px !important; padding-right: 25px !important; padding-bottom: 30px !important;
    border-radius: var(--box-border-radius);
    background-color: color-mix(in srgb, var(--ui-color-main) 95%, transparent) !important;
    border: 1px solid rgba(144, 164, 174, 0.3);
    box-shadow: 0 4px 15px rgba(0, 0, 0, 0.08) !important;
    overflow: hidden;
}
div[is_user="false"] .mes_block::before {
    content: ""; position: absolute; top: 0; left: 0; right: 0; height: 559px !important;
    background-image: var(--char-bg-image) !important;
    background-position: center top !important; background-size: cover !important; background-repeat: no-repeat !important;
    border-radius: var(--box-border-radius) var(--box-border-radius) 0 0;
    -webkit-mask-image: linear-gradient(to bottom, black 0%, black 90%, transparent 100%) !important;
    z-index: 120 !important; pointer-events: none !important;
}

/* ----------------------------------------------------
   2. 头像与特效层（User 与 Char 统一坐标系）
---------------------------------------------------- */
/* 头像外框绝对锚点：统一设定，此为一切坐标的源头！ */
div[is_user="true"] .mesAvatarWrapper,
div[is_user="false"] .mesAvatarWrapper {
    position: absolute !important;
    margin: 0 !important;
    top: 90px !important;         /* 在这里调整（头像整体的上下位置）🐰 */
    left: 50% !important;         /* 在这里调整（头像整体的左右位置，50%为居中）🐰 */
    transform: translateX(-50%) !important;
    z-index: 110 !important;      /* 藏在气泡图120下方 */
}

/* 统一头像尺寸与裁剪 */
div[is_user="true"] .avatar, div[is_user="true"] .avatar img,
div[is_user="false"] .avatar, div[is_user="false"] .avatar img {
    width: 354px !important;
    height: 380px !important;
    border-radius: 0% !important;
    object-fit: cover !important;
    object-position: 50% 20% !important; /* 在这里调整（头像内部镜头的上下偏移，数字越大脸越靠下）🐰 */
    transition: none !important;
}

/* Char 专属：在头像和气泡图之间插入的 GIF 层 */
div[is_user="false"] .mesAvatarWrapper::after {
    content: "" !important;
    position: absolute !important;
    top: 0 !important; left: 0 !important;
    width: 354px !important; height: 380px !important;
    border-radius: 0% !important;
    background-image: url('这里是你的动态头像链接') !important;
    background-size: cover !important; background-position: center !important; background-repeat: no-repeat !important;
    z-index: 115 !important; pointer-events: none !important;
}

/* ----------------------------------------------------
   3. 全局统一坐标阵列：名字、时间、三元素
---------------------------------------------------- */
/* 名字 */
div[is_user="true"] .name_text,
div[is_user="false"] .name_text {
    position: absolute !important;
    top: 478px !important;        /* 在这里调整（名字的上下位置）🐰 */
    left: 50% !important;         /* 在这里调整（名字的左右位置，50%为绝对居中）🐰 */
    transform: translateX(-50%) !important;
    text-align: center !important;
    width: 100% !important;
    margin: 0 !important;
    z-index: 150 !important;      /* 浮在气泡图上方 */
}

/* 时间戳 */
div[is_user="true"] .timestamp,
div[is_user="false"] .timestamp {
    position: absolute !important;
    top: 515px !important;        /* 在这里调整（时间戳的上下位置）🐰 */
    left: 50% !important;         /* 在这里调整（时间戳的左右位置）🐰 */
    transform: translateX(-50%) !important;
    font-size: 13px !important;
    z-index: 200 !important;
    white-space: nowrap !important;
    color: inherit !important;
}

/* 三元素全局清理 */
.mes_info_bar i, .mesIDDisplay i, .tokenCounterDisplay i, .mes_timer i { display: none !important; }
.mesIDDisplay::before, .mesIDDisplay::after, .tokenCounterDisplay::before, .tokenCounterDisplay::after, .mes_timer::before, .mes_timer::after { content: "" !important; }

/* 三元素横排基础 */
.mesIDDisplay, .tokenCounterDisplay, .mes_timer {
    position: absolute !important;
    top: 440px !important;        /* 在这里调整（三元素整体的上下位置）🐰 */
    font-size: 15px !important;
    z-index: 200 !important;
    white-space: nowrap !important;
    background: transparent !important;
    text-shadow: none !important;
    font-family: var(--main-font) !important;
    color: var(--text-color-sec) !important;
}

/* 三元素以头像中心为轴，左右展开 */
.tokenCounterDisplay { left: calc(50% - 150px) !important; } /* 在这里调整（【叶】的左右偏移，变负数往左，变正数往右）🐰 */
.mesIDDisplay        { left: calc(50% - 50px) !important;  } /* 在这里调整（【夜】的左右偏移）🐰 */
.mes_timer           { left: calc(50% + 90px) !important;  } /* 在这里调整（【曳】的左右偏移）🐰 */

/* 三元素汉化美化 */
.mesIDDisplay::before { content: "第 " !important; }
.mesIDDisplay::after  { content: " 夜" !important; }
.tokenCounterDisplay::before { content: "  " !important; }
.tokenCounterDisplay::after  { content: " 叶" !important; }
.mes_timer::before { content: " " !important; }
.mes_timer::after  { content: " 曳" !important; }

/* User侧极简隐藏 */
div[is_user="true"] .mes_timer,
div[is_user="true"] .tokenCounterDisplay {
    display: none !important;
    font-size: 0 !important;
}


/* ==================================================================================
   🗑️ 附加组件（如果不想要，可随时将以下区域整块删除）
   ================================================================================== */

/* 1. 幽灵图标（跟随三元素行） */
div[is_user="false"] .mes_ghost {
    position: absolute !important;
    top: 538px !important;               /* 在这里调整（幽灵的上下位置）🐰 */
    left: calc(50% + 220px) !important;  /* 在这里调整（幽灵的左右位置）🐰 */
    opacity: 0.3 !important; 
    z-index: 500 !important; 
}
div[is_user="true"] .mes_ghost {
    position: absolute !important;
    top: 538px !important;               /* 在这里调整（User幽灵的上下位置）🐰 */
    left: calc(50% + 50px) !important;   /* 在这里调整（User幽灵的左右位置）🐰 */
    opacity: 0.3 !important; 
    z-index: 500 !important; 
}
/* 2. 模型图标（干干净净的坐标控制） */
.icon-svg {
    position: absolute !important;
    top: 538px !important;               /* 填入和幽灵一样的上下位置 🐰 */
    left: calc(50% + 180px) !important;  /* 在这里调整它在幽灵旁边的左右位置 🐰 */
    opacity: 0.3 !important;             /* 在这里调整透明度 🐰 */
    z-index: 500 !important;
}

/* --- 4-C：通用文字与装饰 --- */
.mes_text { width: 100% !important; box-sizing: border-box !important; text-align: justify !important; z-index: 5 !important; position: relative !important; }

/* 名字文本：已接驳变量，颜色保持墨色统一 */
.name_text { 
    font-family: "Huiwen-mincho", "Noto Serif SC", serif !important; 
    font-weight: 900 !important; 
    font-size: 1.7em !important; 
    letter-spacing: 2px !important; 
    color: var(--name-color) !important; 
}
.name_text::before { content: "༺"; margin-right: 8px; opacity: 0.6; }
.name_text::after { content: "༻"; margin-left: 8px; opacity: 0.6; }

/* === 🐰 意境补丁：消息操作图标诗化（草木青时）@lazyalie === */
/* 1. 【更多菜单】三个点 -> 🍂细雪 (反转叶子) */
.fa-ellipsis.interactable {
    font-size: 0 !important; 
    position: relative !important;
    display: inline-flex !important; 
    align-items: center !important;
}

/* 专门负责【翻转叶子】 */
.fa-ellipsis.interactable::before {
    content: "🍂︎" !important;
    display: inline-block !important; 
    transform: scaleX(-1) !important; /* 水平镜像魔法 */
    font-size: 14px !important;
    opacity: 0.6 !important;
    text-shadow: none !important;
    visibility: visible !important;
    transition: all 0.3s ease !important;
}

/* 专门负责【细雪文字】 */
.fa-ellipsis.interactable::after {
    content: "细雪" !important;
    display: inline-block !important;
    margin-left: 2px !important; 
    font-family: "Huiwen-mincho", "Noto Serif SC", serif !important; 
    font-size: 14px !important;
    letter-spacing: 1px !important;
    opacity: 0.6 !important;
    text-shadow: none !important;
    visibility: visible !important;
    transition: all 0.3s ease !important;
}

/* 2. 【编辑按钮】铅笔 -> 微风🍂 (精准类名修改) */
.mes_edit.fa-pencil {
    font-size: 0 !important; 
    position: relative !important;
    margin-right: 12px !important; 
    display: inline-flex !important;
    align-items: center !important;
}

.mes_edit.fa-pencil::before {
    content: "微风🍂︎" !important;
    font-family: "Huiwen-mincho", "Noto Serif SC", serif !important;
    font-size: 14px !important;
    letter-spacing: 1px !important;
    opacity: 0.6 !important;
    text-shadow: none !important; 
    visibility: visible !important;
    transition: all 0.3s ease !important;
}

/* 3. 悬停交互：确保所有图标在鼠标经过时同步亮起 */
.fa-ellipsis.interactable:hover::before,
.fa-ellipsis.interactable:hover::after,
.mes_edit.fa-pencil:hover::before {
    opacity: 1 !important;
    color: var(--name-color) !important; 
    text-shadow: 0 0 8px rgba(44, 58, 51, 0.4) !important; 
}

/* 纸张纹理（跟随气泡拉宽到 1000px） */
.mes::after { content: ''; position: absolute; background-image: url('https://iili.io/B82k9qX.png'); top: 0; bottom: 0; left: 50%; transform: translateX(-50%); width: 100%; max-width: 1000px !important; filter: opacity(20%) grayscale(50%) contrast(1); pointer-events: none; border-radius: var(--box-border-radius); z-index: 1; }

/*鼠标放置位移*/
.mes_timer, .mesIDDisplay, .tokenCounterDisplay {
    padding: 3px 10px;
    opacity: 0.75 !important;
    transition: border 0.6s ease, opacity 0.6s ease, transform 0.6s ease, box-shadow 0.6s ease-out;
    font-family: var(--secfont);
    border: 1px solid color-mix(in srgb, var(--SmartThemeBodyColor) 0%, transparent);
    color: var(--itemcolor) !important;
}

.mes_timer:hover, .tokenCounterDisplay:hover, .mesIDDisplay:hover {
  opacity: 1 !important;
  border: 1px solid color-mix(in srgb, var(--itemcolor) 40%, transparent);
  box-shadow: inset 0 0 5px color-mix(in srgb, var(--itemcolor) 60%, transparent) !important;
}

.mes_timer:hover, .tokenCounterDisplay:hover, .mesIDDisplay:hover {
  transform: translateX(8px);
}

/*顶栏图标悬停*/
:is(#quick-reply-rocket-button, #options_button, #extensionsMenuButton, #send_but, #top-settings-holder .drawer-icon) {
    transition: opacity 0.2s ease-in-out, filter 0.2s ease-in-out !important;
    &:hover {
        opacity: calc(var(--TopBarIconOpacity) + 0.5) !important;
        filter: drop-shadow(0 0 6px var(--itemcolor)) !important; 
  }
}

/* 🪲 checkbox by 秦素@qinsu0160_77704 */
.checkbox_label {
  padding: 7px 10px;
  display: flex !important;
  align-items: center !important;
  justify-content: flex-start !important;
}

[name="ChatMessageHandlingToggles"] .checkbox_label small,
[name="MiscellaneousToggles"] .checkbox_label small,
[name="CharacterHandlingToggles"] .checkbox_label small,
[name="themeToggles"] .checkbox_label small {
    filter: brightness(0.7); /* 👈 亮度部分 (调整文字亮度：1.0为原色，越小越暗) */
}

input[type="checkbox"]::before,
input[type="checkbox"]::after {
  display: none !important;
  content: "" !important;
}

/* checkbox裝飾 (选中时的竹叶图标) */
input[type="checkbox"]:checked {
  content: "";
  background-image: url('https://iili.io/B8E1S5u.png') !important; /* 👈 新图标：竹叶 */
  background-size: 14px !important;
  background-repeat: no-repeat !important;
  background-position: center !important;
  background-color: transparent !important;
  box-shadow: none !important;
  filter: opacity(1) !important; /* 👈 透明度部分 (调整竹叶透明度：1.0不透明，越小越透明) */
  top: 3px;
}

/* checkbox (未选中时的框体) */
input[type='checkbox'] {
    background: color-mix(in srgb, var(--SmartThemeBodyColor) 0%, transparent) !important; /* 👈 颜色部分 (框体背景，当前为透明) */
    box-shadow: inset 0 0 5px color-mix(in srgb, var(--itemcolor) 45%, transparent) !important; /* 👈 颜色部分 (内阴影颜色，使用了--itemcolor变量) */
    border-color: transparent !important;
    outline: none;
    border-radius: 2px !important;
    top: 2.5px;
}

/* 复选框交互状态 */
input[type="checkbox"]:focus,
input[type="checkbox"]:active,
input[type="checkbox"]:hover {
  outline: none !important;
  box-shadow: inset 0 0 5px color-mix(in srgb, var(--itemcolor) 100%, transparent) !important; /* 👈 颜色部分 (交互时的内阴影颜色) */
}

/* === 🎚️ 范围滑动条 (Slider) 古典花纹定制版 === */

/* 1. 基础重置 */
input[type="range"] {
    -webkit-appearance: none !important;
    width: 100%;
    background: transparent !important;
    cursor: pointer;
}
input[type="range"]:focus {
    outline: none !important;
}

/* 2. 轨道 (Track)：极细的水印底线 */
input[type="range"]::-webkit-slider-runnable-track {
    width: 100%;
    height: 2px !important; /* 👈 轨道调得更细了，像一根丝线 */
    background: rgba(44, 58, 51, 0.2) !important; 
    border-radius: 10px !important;
    border: none !important;
}

/* 3. 滑块 (Thumb)：替换为你指定的古典花纹图片 */
input[type="range"]::-webkit-slider-thumb {
    -webkit-appearance: none !important;
    height: 24px !important; /* 👈 稍微调大一点，不然看不清花纹 */
    width: 24px !important;  
    
    /* 👇 核心修改：使用你提供的图片 */
    background-image: url('https://iili.io/BvbOKIj.png') !important;
    background-size: contain !important;
    background-repeat: no-repeat !important;
    background-position: center !important;
    background-color: transparent !important; /* 去掉底色，只显示图片 */
    
    border: none !important;
    box-shadow: none !important; /* 去掉圆点的阴影，保持图片纯净 */
    
    /* 垂直居中计算：(轨道2 - 滑块24) / 2 = -11 */
    margin-top: -11px !important; 
    
    cursor: grab !important;
    transition: transform 0.2s ease !important;
}

/* 4. 悬停交互：抓取时的反馈 */
input[type="range"]::-webkit-slider-thumb:hover {
    transform: scale(1.2) !important; /* 悬停时微微放大 */
}
input[type="range"]:active::-webkit-slider-thumb {
    cursor: grabbing !important;
    transform: scale(1.1) !important;
}

/* ===五、正文=== */

/* 正文区域 正文对齐 by @咩野 */
.mes_text {
  text-align: justify;
  width: 100% !important;
  order: 20 !important;
  line-height: var(--genericLineHeight);
   z-index: 5 !important;
}

#chat .mes .mes_text {
  margin: 0 !important;
  padding: 15px !important;/* 距离边框远近调整这个数值！ */
  line-height: var(--genericLineHeight);
  text-align: justify !important;
}

.mes_text > p {
  margin-left: 0;
  margin-right: 0;
  width: 100%;
}
/*选取文本马克笔样式 改色 by@potato_juice9*/
.mes_text ::selection {
    background: #8A948D !important; /* 👈 已经为你改成了专属墨色 */
    color: var(--SmartThemeBlurTintColor) !important; /* 确保高亮时文字能看清 */
}
/* --- 4-G：引用块（Blockquote）美化 --- */
/*引用块*/
.mes_text blockquote {
  background: #CED3CD !important; /* 👈 背景颜色已修改为你指定的灰绿色 */
  padding: 20px 20px;    
  border-radius: 0px !important; /* 👈 桉寒修正：帮你把这里的 10px 圆角削平了，保持全局直角美学 */
  margin-bottom: 20px;
  border-left: 3px double color-mix(in srgb, var(--itemcolor) 60%, transparent);
  border-right: 3px double color-mix(in srgb, var(--itemcolor) 60%, transparent);
  box-shadow: inset 0 0 10px color-mix(in srgb, var(--itemcolor) 20%, transparent) !important;
  transition: border 0.6s ease, box-shadow 0.6s ease-out;
}

.mes_text blockquote:hover {
  border-left: 3px double color-mix(in srgb, var(--SmartThemeBodyColor) 100%, transparent);
  border-right: 3px double color-mix(in srgb, var(--SmartThemeBodyColor) 100%, transparent);
  box-shadow: inset 0 0 10px color-mix(in srgb, var(--SmartThemeBodyColor) 60%, transparent) !important;
}

/*代码包裹 by @Junezz 复古MacOs*/
  code {
    background-color: transparent;
    color: var(--SmartThemeUnderlineColor);
    border: 1px solid color-mix(in srgb, var(--SmartThemeBodyColor) 30%, transparent);
    box-shadow: inset 0 0 5px color-mix(in srgb, var(--SmartThemeBodyColor) 30%, transparent) !important;
    font-size: calc(var(--mainFontSize)* 0.98);
    padding: 0px 3px;
}

.last_mes .mesAvatarWrapper {
  padding-bottom: 0px;
}


/*对话样式@摘录自困瞑*/
.mes_text q {
  margin: 0 6px 0 0px;
  border-bottom: 1px dotted color-mix(in srgb, var(--SmartThemeQuoteColor) 100%, transparent) !important;
}

/*聊天气泡底端文字*/
.mes_block::after {
    content: "❖︎ 那年伞下轻拥 ❖︎";
    display: block;
    text-align: center;
    font-size: 14px;
    margin-top: 20px;      
    margin-bottom: 20px;      
}

/* ===、滚动条：彻底直角化=== */
::-webkit-scrollbar {
    width: var(--scroll-width) !important;
    height: var(--scroll-width) !important;
}

::-webkit-scrollbar-track {
    background: transparent !important;
    border-radius: 0px !important;
}

::-webkit-scrollbar-thumb {
    /* 使用 color-mix 将主题色与透明色混合，由变量控制比例 */
    background-color: color-mix(in srgb, var(--theme-color-1) calc(var(--scroll-opacity) * 100%), transparent) !important;
    border-radius: 0px !important;
    border: none !important;
}

/* 悬停时稍微加深，增加互动感 */
::-webkit-scrollbar-thumb:hover {
    background-color: color-mix(in srgb, var(--theme-color-1) 20%, transparent) !important;
}

/* ===六、输入框提示文字自定义=== */
/* 自定义提示词：竹影和诗瘦，梅花入梦香。 */
#nonQRFormItems:has(#send_textarea:placeholder-shown)::before {
    content: "竹影和诗瘦，梅花入梦香。" !important;
    
    /* 👇 🐰 颜色已接驳到顶部的变量，以后只需在 root 改色号即可 */
    color: var(--placeholder-color) !important; 
    
    font-family: "Huiwen-mincho", "Noto Serif SC", serif !important;
    font-style: italic !important;
    font-size: 16px !important;
    position: absolute !important;
    top: 50% !important;
    left: 50% !important;
    transform: translate(-50%, -50%) !important;
    pointer-events: none !important;
    white-space: nowrap !important;
}


/* ===七、 本段由困瞑热心老师提供，或摘抄修改自困瞑发布美化内部V2.0更世界书和预设标记条目=== */
/* === 七、 【竹影摇曳】预设管理器（Prompt Manager）全平台卡片化美化 === */

/* 1. 预设列表标题：保持墨色，去除滤镜 */
#completion_prompt_manager .completion_prompt_manager_header,
#completion_prompt_manager .completion_prompt_manager_header_advanced span {
    filter: none !important;
    color: #2C3A33 !important;
}

/* 2. 【开启状态】的预设条目：实体浅灰卡片（PC & 手机通用） */
#completion_prompt_manager_list .completion_prompt_manager_prompt:not(.completion_prompt_manager_prompt_disabled) {
    background-color: #E4E6E1 !important;
    color: #2C3A33 !important;
    border: 1px solid color-mix(in srgb, #2C3A33 30%, transparent) !important;
    border-radius: 0px !important;
    margin-bottom: 8px !important;
    padding: 10px !important;
    box-shadow: 0 2px 5px rgba(0,0,0,0.05) !important;
    height: auto !important;
    transition: all 0.3s ease !important;
}

/* 3. 【关闭状态】的预设条目：半透明虚线卡片（解决隐形，增强区分度） */
#completion_prompt_manager_list .completion_prompt_manager_prompt_disabled {
    background-color: color-mix(in srgb, #E4E6E1 40%, transparent) !important;
    color: color-mix(in srgb, #2C3A33 50%, transparent) !important;
    border: 1px dashed color-mix(in srgb, #2C3A33 20%, transparent) !important;
    border-radius: 0px !important;
    margin-bottom: 8px !important;
    padding: 10px !important;
    opacity: 0.8 !important;
    height: auto !important;
}

/* 4. 强制修正条目内部文字与按钮颜色 */
#completion_prompt_manager_list .completion_prompt_manager_prompt_name,
#completion_prompt_manager_list .prompt-manager-inspect-action {
    color: inherit !important;
}

/* 5. 悬停反馈：鼠标指上去时轻轻亮起 */
.completion_prompt_manager_prompt:hover {
    filter: brightness(1.02) !important;
    border-color: color-mix(in srgb, #2C3A33 50%, transparent) !important;
}

/* 6. PC端特权：左右侧栏占满全屏（保留原功能） */
@media screen and (min-width: 1025px) {
  #left-nav-panel, #right-nav-panel {
    height: 100vh !important;
    max-height: 100vh !important; 
  }
}

/* 7. 扩展功能页面关闭条目颜色同步 */
.extensions_info .extension_disabled {
  color: color-mix(in srgb, #2C3A33 50%, transparent) !important;
}

/*預設條目編輯版面 @困瞑老师提  老师发布后更新发布*/
/* === 🐰 预设管理弹窗：排版精简与按钮美化合并版 === */

/* 1. 隐藏多余的标题和次要文字 (静音清理) */
#completion_prompt_manager_popup_edit > h3,
.text_muted,
#openai_settings .inline-drawer-header small {
    display: none !important;
}

/* 2. 压缩弹窗与条目的间距 (加上了强制执行令，绝对生效) */
.completion_prompt_manager_popup_entry_form_control {
    margin-top: 3px !important; 
}
#completion_prompt_manager_popup {
    padding: 0 !important;
}
#completion_prompt_manager_popup .completion_prompt_manager_popup_entry .completion_prompt_manager_popup_entry_form_footer .menu_button {
    border: 1px solid color-mix(in srgb, var(--itemcolor) 30%, transparent) !important;
    box-shadow: inset 0 0 5px color-mix(in srgb, var(--itemcolor) 30%, transparent) !important;
    padding: 9px 11px !important;
}
/* 手機端聊天框隱藏滾動條 */
@media screen and (max-width: 768px) {
    #chat::-webkit-scrollbar { display: none !important;}
}

/* === 世界书界面深度美化 === */
/* === 世界书界面深度美化 (独立版：预设配色同款) === */

/* 1. 世界书条目基础底座 */
.wi-card-entry {
  border: 1px solid transparent;
  border-radius: 0px !important;
  margin: 10px 0;
  padding: 13px 10px 11px 10px !important;
}

.world_entry { 
  transition: box-shadow 0.6s ease-out; 
}

/* 2. 世界书开启状态（换成预设的浅灰底色 #E4E6E1 + 墨色阴影） */
.wi-card-entry:has(.killSwitch.fa-toggle-on) {
  background-color: #CED3CD !important; 
  color: #8A948D !important; 
  border: 1px solid color-mix(in srgb, #2C3A33 30%, transparent) !important;
  box-shadow: inset 0 0 8px color-mix(in srgb, #2C3A33 15%, transparent) !important;
}

/* 3. 世界书关闭状态（，但降低透明度，取消阴影以示区分） */
.wi-card-entry:has(.killSwitch.fa-toggle-off),
.world_entry:has(.fa-toggle-off) {
  background-color: #E4E6E1 !important;
  color: color-mix(in srgb, #2C3A33 60%, transparent) !important; /* 关闭时字稍微淡一点 */
  opacity: 0.7 !important;
  border: 1px solid transparent !important;
  box-shadow: none !important;
  border-radius: 0px !important;
}

/* 4. 条目内部文字框（透明化+直角化+墨色边框） */
.world_entry textarea:not([name="comment"]),
.world_entry input,
.world_entry select,
.world_entry .text_pole {
  border-radius: 0px !important;
  background-color: transparent !important;
  border: 1px solid color-mix(in srgb, #2C3A33 80%, transparent) !important;
  color: #2C3A33 !important;
}

/* 给备注框留足宽度 */
.world_entry .text_pole[name='comment'] {
  min-width: 150px !important;
}

/* === 5. 全局世界书与下拉/搜索插件 (Select2) 美化 === */
.standoutHeader~.inline-drawer-content { background-color: transparent; }

/* 搜索框 (浅灰底色) */
.select2-container .select2-selection--single {
  background-color: #E4E6E1 !important;
  border: 1px solid color-mix(in srgb, #2C3A33 30%, transparent) !important;
  border-radius: 0px !important;
}

/* 多选框容器与已选标签显示 */
.select2-container .select2-selection--multiple, 
.select2-container .select2-selection--single { 
  background-color: transparent; 
}

.select2_choice_clickable_buttonstyle+span.select2-container .select2-selection__choice__display {
  color: #2C3A33 !important;
  background-color: transparent;
}

/* 多选标签（小胶囊：浅灰底色 + 墨色边框，强行切平直角） */
.select2-container--default .select2-selection--multiple .select2-selection__choice {
  background-color: #E4E6E1 !important;
  color: #2C3A33 !important;
  border: 1px solid color-mix(in srgb, #2C3A33 30%, transparent) !important;
  padding: 3px 0 3px 15px;
  border-radius: 0px !important;
}

/* 多选标签上的移除按钮 (x) 及隐藏竖线 */
span.select2.select2-container .select2-selection__choice__remove {
  background-color: transparent !important;
  color: #2C3A33 !important;
  padding: 5px 5px 5px 8px;
  border-right: none !important; /* 顺便把那个碍眼的竖线切掉 */
}


/* ===八、"加载更多消息"美化=== */
/*🪲Toast通知 by hy@captivating_fox_43571*/
/* 🪲 Toast通知美化方案-古典花纹版 */

/* 1. 整体框架设置：圆角、内阴影与主题色边框 */
#toast-container > .toast {
    border-radius: var(--SmartThemeRadius);
    border: 1px solid color-mix(in srgb, var(--itemcolor) 60%, transparent) !important;
    box-shadow: inset 0 0 6px color-mix(in srgb, var(--itemcolor) 50%, transparent) !important;
}

/* 2. Toast圖標裝飾 (替换为你提供的古典花纹) */
#toast-container > .toast-success::before {
    content: '';
    background-image: url('https://iili.io/BvbOIYF.png') !important; /* 👈 新图标：古典花纹 */
    position: absolute;
    left: 16px;
    top: calc(50% - 1px);
    transform: translateY(-50%);
    
    /* 👇 图标大小：帮你稍微放大了一点到 24px，防止看不清花纹 */
    width: 24px !important; 
    height: 24px !important;
    
    background-size: contain;
    background-repeat: no-repeat;
    background-position: center;
    opacity: 0.9 !important; /* 👈 默认透明度：让你指定的花纹更清晰 */
}

/* 🪲 Toast通知背景修复版 */

/* 3. 背景修复：确保背景颜色可见，不再是虚无的透明 */
#toast-container > .toast-success {
    background-image: none !important;
    
    /* 👇 修改这里：把比例从 4% 调高到了 15%，并加了一个浅色保底 */
    background-color: color-mix(in srgb, var(--itemcolor) 15%, #F5F7F2) !important; 
    
    /* 加一点点不透明度，确保它能盖住后面的聊天内容 */
    opacity: 1 !important; 
    
    /* 如果你的系统支持，加一个毛玻璃效果会更有质感 */
    backdrop-filter: blur(8px) !important; 
}

/* 4. 文字颜色加强：确保文字在背景上清晰 */
.toast-success .toast-title, 
.toast-success .toast-message {
    color: var(--itemcolor) !important;
    font-weight: 500; /* 让文字稍微粗一点点 */
    text-shadow: none !important; /* 去掉发光，保持干净 */
}
/* =====================================================================
     🎀 设置页折叠面板（Inline Drawer & StandoutHeader）自定义整合版 V2.0更🎀 
     ===================================================================== */

  #extensions_settings .inline-drawer-toggle.inline-drawer-header,
  #extensions_settings2 .inline-drawer-toggle.inline-drawer-header,
  #user-settings-block h4, 
  .standoutHeader,
  .userSettingsInnerExpandable {
    
    /* 1. 彻底清除原版的渐变发光贴图和原始边框（请勿修改） */
    background-image: none !important;
    border: none !important;
    
    /* 👇 🐰 【颜色与外观控制台】 🐰 👇 */
        /* 🎨 【底色】：现在是透明(transparent)。*/
    background-color: transparent !important; 
    
    /* 📐 【直角框】 */
    border-radius: 0px !important; 
    
    /* 🔤 【文字颜色】：控制标题文字的颜色。*/
    color: var(--SmartThemeBodyColor) !important;
    
    /* ↕️ 【面板厚度】：第一个数值(6px)控制上下厚度。*/
    padding: 6px 10px !important; 
  }
/* 👇 🐰 【展开后的内容大盒子控制台】 🐰 👇 */
  .standoutHeader~.inline-drawer-content {
    
    /* 🎨 【展开底色】：点击下拉箭头后，里面装设置项的巨大底板颜色 */
    background-color: var(--menuBackgroundColor) !important;
    
    /* 📐 【展开大盒子的直角】*/
    border-radius: 0px !important; 
    
    /* 阴影保留，增加层次感 */
    box-shadow: var(--boxShadowSubtle);   
  }
/* === 🎍 竹影摇曳：UI 控件强制直角化补丁 ===🐰修改？px 控制圆角大小 */:root{--my-custom-radius:0px !important;--genericRadius:var(--my-custom-radius) !important;--box-border-radius:var(--my-custom-radius) !important;}.mes,.mes_block,.avatar,.avatar img,.avatar-container,.character_select .avatar,.group_select .avatar,.ui-widget.ui-widget-content,.popup,.popup-content,.popper-modal,#options,#extensionsMenu,.extensions_toolbar,#bulk_tag_popup,#dialogue_popup,#select_chat_popup,#floatingPrompt,.drawer-content,#right-nav-panel,#left-nav-panel,.list-group,.extensions_info .extension_block,#completion_prompt_manager_popup,.bg_example,#toast-container>div,.menu_button,.red_button,.mes_button,#character_sort_order,.add_avatar,.regex-script-label,.script-item,.box-container,.title-item,.extension-title,input,select,textarea,.text_pole,.neo-range-input,.select2-container,.select2-selection,.select2-selection__choice,.select2-dropdown,code,.mes_text pre,.mes_text table,.mes_reasoning,input.neo-range-slider[type="range"]::-webkit-slider-thumb,.range-block-range input[type="range"]::-webkit-slider-thumb,.wi-card-entry,#completion_prompt_manager #completion_prompt_manager_list li.completion_prompt_manager_prompt,#quick-reply-menu,.quick-reply-list,.quick-reply-item,.inline-drawer-toggle,.bg_tab_panel,input[type='checkbox']{border-radius:var(--my-custom-radius) !important;}/* 把凸出屏幕的 3D 感全部拍扁，让界面融入背景 */body .ui-widget-content,body,#sheld,.drawer-content,.popup,#send_form,.mes_block,.menu_button,.text_pole,#top-bar,.inline-drawer-toggle,input[type='checkbox']{box-shadow:none !important;}

/* ===九、思维链（印章）=== */

.mes_reasoning_details {
    position: relative;
    width: 100%;
    display: flex;
    flex-direction: column;
}

/* 标题区域：这里负责定位和高度 */
.mes_reasoning_header {
    position: relative;
    display: flex;
    /* 👇 🐰 【1. 右对齐核心】：这里改为 flex-end 让印章靠右站 */
    justify-content: flex-end; 
    align-items: center;
    width: 100%;
    /* 👇 🐰 【2. 容器高度】：如果觉得印章上下太挤，调大这个数值 */
    height: 50px; 
    background-color: transparent;
    font-size: 0 !important;
    z-index: 2;
}

/* 思维链标题装饰图片（印章本体） */
.mes_reasoning_header::before {
    content: "";
    position: absolute;
    
    /* 👇 🐰 【3. 印章上下位置】：控制印章在竖直方向的位置 */
    top: -180%; 
    
    /* 👇 🐰 【4. 印章左右位置】：
       因为我们要右对齐，我把 left 换成了 right。
       如果你觉得印章太贴右边边缘了，就把 0px 改大（比如 10px） */
    right: 0px; 
    
    transform: translateY(-50%); /* 垂直居中修正 */

    /* 👇 🐰 【5. 印章物理尺寸】：在这里填入你印章图的最舒适比例 */
    width: 230px;
    height: 150px; 
    
    /* 👇 🐰 【6. 印章底图】：已换回你之前的印章链接 */
    background: url('https://iili.io/BvbNSXR.png') no-repeat center;
    background-size: 100% 100%; /* 强制铺满上面定的宽高 */
    
    /* 👇 🐰 【7. 直角开关】：确保绝对直角 */
    border-radius: 0px !important; 
    z-index: 2 !important;
}
/*隱藏原始箭頭*/
.mes_reasoning_details .mes_reasoning_arrow {
    display: none !important;
}
/* 思维链内容主体（展开后的折叠面板） */
.mes_reasoning {
    max-height: 480px; 
    overflow-y: auto;
    overflow-x: hidden;
    /* 这里的颜色保持你的默认配置 */
    color: var(--SmartThemeBodyColor) !important;
    background-color: color-mix(in srgb, var(--SmartThemeUnderlineColor) 10%, transparent);
    border: 1px dotted color-mix(in srgb, var(--SmartThemeEmColor) 50%, transparent);
}
/*思維鏈編輯框困瞑提供*/
.reasoning_edit_textarea { 
  margin-top: px; margin-bottom: px; 
}
/*思維鏈小鉛筆*/
.mes_reasoning_actions.flex-container {
    position: absolute !important;
    top: px !important;
    right: px; 
}
/*思維鏈edit按鈕*/
.mes_reasoning_edit_done,
.mes_reasoning_edit_cancel,
.mes_reasoning_delete {
    margin-top: px !important;
    filter: none !important;
}

/* ===十、收藏栏=== */
/* 角色收藏栏展开@困瞑 */
.hotswap.avatars_inline {
    display: flex;
    flex-wrap: wrap;
    transition: all 1s ease;
    scrollbar-width: none;
}
.hotswap.avatars_inline::-webkit-scrollbar {
    display: none;
}
.hotswap.avatars_inline:hover {
    max-height: 300px;
    overflow: auto;
}
/* ===十一、初始加载界面（Loading）=== */
/* 🎀Loadingpage by旅程美化交流帖🐰*/
#load-spinner {
  --spinner-size: 180px;
  opacity: 1;
  top: calc(50% - var(--spinner-size) / 2);
  left: calc(50% - var(--spinner-size) / 2);
  position: absolute;
  width: var(--spinner-size);
  height: var(--spinner-size);
  background-image: url('https://iili.io/BvbNSXR.png');
  background-size: contain;
  background-repeat: no-repeat;
  background-position: center;
  animation: none !important;
}


/* 消除加载界面弹窗色块：背景透明、去阴影(by@Nuyoah) */
body:has(#load-spinner) .popup {
    background-color: transparent !important;
    box-shadow: none !important;
    border: none !important;
}
#load-spinner::before {
  display: none !important;
}

/* 🐰首页美化感谢【yaokoulizi】老师分享🐰*/
/* 🍓🍧 首页/空闲状态 - 替换默认助手名称 */
/* 1. 重置该气泡的名字外框坐标，拉回背景图附近 */
div.mes[mesid="0"][ch_name="Assistant"][type="assistant_message"] .name_text {
    color: transparent !important; 
    position: absolute !important;
    
    /* 🎮 【方向盘在这里！】通过改这两个数值，把名字“开”到背景图上 */
    top: -185px !important;  /* 👈 上下移动：数值变小（比如 -80px）往上走，变大（比如 20px）往下走 */
    left:70% !important;   /* 👈 左右移动：50% 是相对气泡居中。如果偏了，可以改成具体数值比如 100px */
    transform: translateX(-50%) !important; /* 配合 left:50% 实现绝对居中 */
    
    display: block !important;
    width: 100% !important;
    text-align: center !important;
}
/* === 首页净化：隐藏三元素与时间戳 === */
/* 既然首页这些信息没有实际用途，我们就把它们彻底藏起来，只留意境 🐰 */
div.mes[mesid="0"] .timestamp,
div.mes[mesid="0"] .mesIDDisplay,
div.mes[mesid="0"] .tokenCounterDisplay,
div.mes[mesid="0"] .mes_timer {
    display: none !important;
}

/* 2. 覆盖你的专属名字 */
div.mes[mesid="0"][ch_name="Assistant"][type="assistant_message"] .name_text::after {
    content: "准备营业" !important;  /* 👈 填你的名字 */
    color: #9C7164 !important; /* 👈 可换颜色 */
    
    /* 👇 解除全屏锁定，跟着上面的“方向盘”走 */
    position: relative !important; 
    
    /* 👇 保持不换行，字号调回正常大小 */
    white-space: nowrap !important;
    font-size: 28px !important; /* 字号大小可以在这改 */
    font-weight: bold !important;
    z-index: 10 !important;
}

/* 🍓🍧 首页/空闲状态 - 替换默认助手开场白 */

/* 1. 撑起文字容器的框架 */
div.mes[mesid="0"][ch_name="Assistant"][type="assistant_message"] .mes_text {
    position: relative !important;
    min-height: 80px !important;
    padding: 10px 15px !important;
}

/* 2. 隐藏自带的默认冰冷文案 */
div.mes[mesid="0"][ch_name="Assistant"][type="assistant_message"] .mes_text > * {
    opacity: 0 !important;
    visibility: hidden !important;
    height: 0 !important;
    margin: 0 !important;
    padding: 0 !important;
    overflow: hidden !important;
}

/* 3. 注入第一段文字（核心宣告） */
div.mes[mesid="0"][ch_name="Assistant"][type="assistant_message"] .mes_text::before {
    content: "孤身打马南屏旧桥边过，恰逢山雨来时雾蒙蒙。" !important;
    display: block !important;
    color: #2C3A33 !important; /* 👈 你的专属红棕色 */
    font-size: 15px !important; /* 稍大一点，作为引言 */
    font-weight: bold !important; /* 微加粗，增强力量感 */
    line-height: 1.6 !important;
    opacity: 1 !important;
    visibility: visible !important;
    position: relative !important;
    z-index: 2 !important;
}

/* 4. 注入第二段文字（温柔倾诉） */
div.mes[mesid="0"][ch_name="Assistant"][type="assistant_message"] .mes_text::after {
    content: "而你撑伞拥我入怀中，一字一句誓言多慎重，你眼中有柔情千种，如脉脉春风 冰雪也消融。" !important;
    display: block !important;
    color: #2C3A33 !important; /* 👈 同款专属颜色 */
    font-size: 14px !important;
    margin-top: 12px !important; /* 两段文字之间拉开一点呼吸感 */
    line-height: 1.6 !important;
    white-space: pre-wrap !important; /* 确保文字能够自然换行 */
    z-index: 2 !important;
}

/* 4. 替换助手头像 */
div.mes[mesid="0"][ch_name="Assistant"][is_user="false"][is_system="false"][swipeid="0"][force_avatar="true"] .mesAvatarWrapper .avatar {
    position: relative !important;
    top: 10px !important;
    display: inline-block !important;
}
div.mes[mesid="0"][ch_name="Assistant"][is_user="false"][is_system="false"][swipeid="0"][force_avatar="true"] .mesAvatarWrapper .avatar > img {
    visibility: hidden !important;
    position: absolute !important;
    z-index: -1 !important;
}
div.mes[mesid="0"][ch_name="Assistant"][is_user="false"][is_system="false"][swipeid="0"][force_avatar="true"] .mesAvatarWrapper .avatar::before {
content: '';
    position: absolute !important;
    top:-17px !important;
    left: -5px !important;
    width: 400px !important;
    height: 410px !important;
    background: url("https://iili.io/BSfRxtI.jpg") center/cover no-repeat !important;
}

/*預設條目編輯版面*/
.completion_prompt_manager_popup_entry_form_control {
   margin-top: 3px; 
}
#completion_prompt_manager_popup {
   padding: 0;
}
#completion_prompt_manager_popup .completion_prompt_manager_popup_entry .completion_prompt_manager_popup_entry_form_footer {
    margin-top: 2px !important;
}
#completion_prompt_manager_popup .completion_prompt_manager_popup_entry .completion_prompt_manager_popup_entry_form_footer .menu_button {
    border: 1px solid color-mix(in srgb, var(--itemcolor) 30%, transparent) !important;
    box-shadow: inset 0 0 5px color-mix(in srgb, var(--itemcolor) 30%, transparent) !important;
    padding: 9px 11px !important;
}
/* 下拉框美化 */
select {
    border-radius: 50px !important;
    background-color: rgba(235, 242, 247, 0.6) !important;
    border: 1px solid rgba(96, 125, 139, 0.3) !important;
    padding: 8px 35px 8px 15px !important;
}
/* === 杂项隐藏（克劳德自己加的我都不知道这是在干嘛） === 
.timestamp + .mes_edit_buttons,
.timestamp ~ .mes_edit_buttons {
    display: none !important;
}*/

/* === 十二、移动端稳定性修正（77专属纯净坐标控制台） === */
@media screen and (max-width: 800px) {
    /* ==========================================
       px数据来自@苍耳球提供的移动端适配版 因双文件更新苦手 目前整合在一起
       ========================================== */
    div[is_user="false"] .mes_block::before,
    div[is_user="true"]  .mes_block::before {
        height: 309px !important;
    }
    div[is_user="false"] .mes_block { padding-top: 650px !important; }
    div[is_user="true"] .mes_block { padding-top: 630px !important; }

    div[is_user="true"]  .avatar, div[is_user="true"]  .avatar img,
    div[is_user="false"] .avatar, div[is_user="false"] .avatar img {
        width: 154px !important;
        height: 220px !important;
    }
    div[is_user="true"]  .mesAvatarWrapper,
    div[is_user="false"] .mesAvatarWrapper {
        top: 50px !important; 
    }

    /* ==========================================
       👇 移动端绝对坐标微调区 👇
       ========================================== */

    /* 1. 名字 (在头像下方) */
    div[is_user="true"] .name_text,
    div[is_user="false"] .name_text {
        top: 260px !important;  /* 在这里调整（移动端名字的上下位置） 🐰 */
    }

    /* 2. 时间戳 (在名字下方) */
    div[is_user="true"] .timestamp,
    div[is_user="false"] .timestamp {
        top: 295px !important;  /* 在这里调整（移动端时间戳的上下位置） 🐰 */
    }

    /* 3. 三元素 (在时间戳下方) */
    .mesIDDisplay, .tokenCounterDisplay, .mes_timer {
        top: 260px !important;  /* 在这里调整（移动端三元素的整体上下位置） 🐰 */
    }
    /* 手机端横向空间小，左右偏移量我帮你按比例缩小了，可自行微调 */
    .tokenCounterDisplay { left: calc(0% - 90px) !important; }  /* 叶 🐰 */
    .mesIDDisplay        { left: calc(50% - 50px) !important; }  /* 夜 🐰 */
    .mes_timer           { left: calc(100% + 00px) !important; }  /* 曳 🐰 */

    /* 4. 模型图标 & 小幽灵 (和三元素在一排) */
    .icon-svg {
        top: 340px !important;               /* 和三元素保持一致 🐰 */
        left: calc(50% + 90px) !important;   /* 模型图标的左右位置 🐰 */
    }
    div[is_user="false"] .mes_ghost, 
    div[is_user="true"] .mes_ghost {
        top: 340px !important;               /* 和三元素保持一致 🐰 */
        left: calc(50% + 120px) !important;  /* 幽灵图标的左右位置 🐰 */
    }

    /* 5. 思维链印章 (在三元素下方) */
    .mes_reasoning_header::before {
        top: -150% !important;   /* 在这里调整（思维链印章的上下位置） 🐰 */
        width: 150px !important; /* 移动端屏幕窄，印章尺寸缩放 🐰 */
        height: 100px !important;
    }

    /* 6. 正文起始线 (在思维链下方) */
    div[is_user="false"] .mes_block,
    div[is_user="true"] .mes_block {
        /* 在这里调整正文开头的空白高度！
           数字越大，正文越靠下；确保它不挡住上面的三元素和印章 🐰 */
        padding-top: 380px !important; 
    }

    /* ==========================================
       杂项保留区（原封不动）
       ========================================== */
    select {
        border-radius: 0px !important;
        background-color: rgba(235, 242, 247, 0.6) !important;
        border: 1px solid color-mix(in srgb, var(--name-color) 30%, transparent) !important;
        padding: 4px 25px 4px 10px !important; 
    }
    select[name='entryStateSelector'] {
        padding: 0 0 0 10px !important;
        color: initial !important; 
        text-shadow: none !important;
    }
}
/* === 修复：首页美化图片手机端尺寸溢出问题 === */
@media screen and (max-width: 800px) {
    div.mes[mesid="0"][ch_name="Assistant"][is_user="false"][is_system="false"][swipeid="0"][force_avatar="true"] .mesAvatarWrapper .avatar::before {
        width: 154px !important;  /* 强制和手机端头像宽度保持一致 🐰 */
        height: 220px !important; /* 强制和手机端头像高度保持一致 🐰 */
        top: -10px !important;      /* 坐标归零，严丝合缝 🐰 */
        left: 0px !important;     /* 坐标归零，严丝合缝 🐰 */
        border-radius: 0px !important; /* 保持直角风格 */
    }
}
/*🪲输入框拖曳按鈕加大 by @_nak.a.ri*/
@media screen and (max-width: 768px) {
  textarea::-webkit-scrollbar {
    display: initial;
    width: 10px !important;
  }
  textarea::-webkit-scrollbar-thumb {
    display: none;
  }
}
  
/* 🪲IOS手機端適配 by @rech0_viixi 雙色盒子*/
@supports (-webkit-touch-callout: none) {
  .drawer-content:not(#left-nav-panel):not(#right-nav-panel) {
    max-width: 100dvw;
    top: 11px !important;
  }
  #world_popup { margin-top: 0; width: 100%; }
  #world_popup::-webkit-scrollbar { display: none; }
}
/* 🪲手機端世界書佈局 柏柏@baibai_ds 摘抄自@困瞑 */
/* 🪲 手机端世界书布局 (柏柏@baibai_ds) - 桉寒高密防撞车纯净版 V2.1 */
@media screen and (max-width:768px){.fa-circle-chevron-down.interactable.fa-fw.fa-solid,.fa-circle-chevron-up.interactable.fa-fw.fa-solid{position:absolute;right:6.5px;top:117px;border:none;height:26px;width:26px}.fa-circle-chevron-down.interactable.fa-fw.fa-solid:before,.fa-circle-chevron-up.interactable.fa-fw.fa-solid:before{width:26px;height:26px}.world_entry_form{padding:10px 15px 13px 15px!important;position:relative}.killSwitch{position:absolute;right:13px;top:70px;height:14px;width:15px;z-index:999}.world_entry .drag-handle{position:absolute;right:14px;top:17px}.flex-container.alignitemscenter.wide100p{margin-right:25px}.move_entry_button,.duplicate_entry_button,.delete_entry_button{position:absolute;top:116px;height:25px;width:25px;padding:0;margin:0}.delete_entry_button{right:45px!important;left:auto!important}.duplicate_entry_button{right:80px!important;left:auto!important}.move_entry_button{right:115px!important;left:auto!important}.text_pole{font-size:13px;height:25px}.text_pole[name='comment']{font-size:14px;padding:6px 8px;height:28px;line-height:14px}.WIEntryTitleAndStatus.flex-container.flex1.alignitemscenter{min-height:35px}.WIEnteryHeaderControls.flex-container{min-height:87px}.WIEnteryHeaderControls.flex-container:has(.world_entry_form_control[name='PositionBlock']){width:100%}input[name='depth'],input[name='order'],input[name='probability']{width:45px!important;min-width:45px!important;max-width:45px!important;height:25px!important;min-height:25px!important;max-height:25px!important;border-width:1px}select[name='entryStateSelector']{width:45px!important;min-width:45px!important;max-width:45px!important;height:28px!important}select[name='position']{margin-bottom:5px;padding-left:8px}label[data-i18n='Order:'],label[data-i18n='Depth:'],label[data-i18n='Position:'],label[data-i18n='Trigger %:'],small[data-i18n='Primary Keywords'],small[data-i18n='Optional Filter'],small[data-i18n='Logic'],small[data-i18n='Scan Depth'],small[data-i18n='Case-Sensitive'],span[data-i18n='Content']{font-size:11px;margin-top:1px;margin-left:5px;text-align:start;line-height:13px;color:var(--SmartThemeBodyColor)}.world_entry_form_control[name='PositionBlock']{width:calc(100% - 50px);min-width:calc(100% - 50px);max-width:calc(100% - 50px)}.world_entry_edit{display:block;margin-top:10px}.world_entry_edit>:not(:first-child){display:none}.world_entry_edit .flex-container[name='keywordsAndLogicBlock'],.world_entry_edit .flex-container[name='perEntryOverridesBlock']{display:contents}.world_entry_edit .world_entry_thin_controls[name='contentAndCharFilterBlock'],.world_entry_edit .world_entry_thin_controls[name='contentAndCharFilterBlock'] .world_entry_form_control,.world_entry_edit .world_entry_thin_controls[name='contentAndCharFilterBlock'] .world_entry_form_control>:first-child,.world_entry_edit .world_entry_thin_controls[name='contentAndCharFilterBlock'] .world_entry_form_control>:first-child>:first-child,.world_entry_edit .world_entry_thin_controls[name='contentAndCharFilterBlock'] .world_entry_form_control>:first-child>:first-child>:first-child{display:contents}.world_entry_edit .world_entry_thin_controls[name='contentAndCharFilterBlock'] .world_entry_form_control>:first-child>:first-child span.flex-container{order:0;color:var(--SmartThemeBodyColor);font-size:11px}.world_entry_edit .world_entry_thin_controls[name='contentAndCharFilterBlock'] .world_entry_form_control>:first-child>:first-child>:first-child div.flex-container{order:1;margin-bottom:5px}.world_entry_form_control:has(small[data-i18n='Whole Words'],small[data-i18n='Group Scoring'],small[data-i18n='Automation ID']){display:none}.world_entry_form_control:has(small[data-i18n='Logic']){order:10}.world_entry_form_control:has(.text_pole[name='key'],.text_pole[name='keysecondary']){width:100%;flex:none!important}.world_entry_form_control .text_pole[name='key'],.world_entry_form_control .text_pole[name='keysecondary']{padding:3px 0;font-size:13px;line-height:18px;height:26px;min-height:26px;margin-bottom:10px}.world_entry_form_control .text_pole[name='content']{padding:3px 0;font-size:14px;line-height:20px;min-height:200px!important}.world_entry_edit .world_entry_form_control.keysecondary{order:9}.world_entry_edit .world_entry_form_control:has(input[name='scanDepth']){order:10}.world_entry_edit .world_entry_form_control:has(select[name='caseSensitive']){order:10}}
/* === 🎍 附加美化：【落叶无声】消息丝滑入场动画 === */
@keyframes bambooFadeInUp {
    0% { 
        opacity: 0; 
        transform: translateY(12px); 
    }
    100% { 
        opacity: 1; 
        transform: translateY(0); 
    }
}
.mes {
    /* 0.6秒的极度丝滑缓冲，拒绝生硬闪烁 */
    animation: bambooFadeInUp 0.6s cubic-bezier(0.2, 0.8, 0.2, 1) forwards !important;
}
/* ==================================================================================
   🚑 哈基米抢救包：修复白内障文字与消失的竹影（放至 CSS 最底部！）
   ================================================================================== */

/* 1. 强制切断与酒馆暗黑主题的关联，锁死全局正文为“深墨色” */
:root {
    --text-color-main: #2C3A33 !important; 
    --text-color-sec: #5E6C64 !important; 
}

/* 2. 拯救“场景特写”与思维链（彻底清除泛白的隐身文字） */
.mes_text, .mes_text * {
    text-shadow: none !important; /* 扒掉暗黑模式自带的文字发光，让字迹像墨水一样实诚 */
}
.mes_reasoning, .mes_reasoning * {
    color: #2C3A33 !important; /* 强制思维链/场景特写的文字也是深墨色 */
    background-color: rgba(206, 211, 205, 0.4) !important; /* 给特写框加一个微透的灰绿底色，质感拉满 */
    border-color: rgba(44, 58, 51, 0.3) !important; /* 边框变暗，更符合古风 */
}

/* 3. 召唤竹影！让竹影洒满整张信纸（全局覆盖） */
/* 之前竹影被卡在顶部，现在我们在信纸上方再铺一层全屏竹影 */
.mes::before {
    content: '';
    position: absolute;
    top: 0; bottom: 0; left: 50%; transform: translateX(-50%);
    width: 100%; max-width: 1000px !important;
    background-image: url('https://iili.io/BvbN41I.png'); /* 您的竹影资产 */
    background-size: cover;
    background-position: center top;
    background-repeat: no-repeat;
    
    /* 👇 调节竹影浓淡的开关在这里！数值越大竹影越深（推荐 0.1~0.3） */
    opacity: 0.15 !important; 
    
    mix-blend-mode: multiply; /* 正片叠底魔法，让竹影完美融进纸张的纤维里，不发白 */
    pointer-events: none !important; /* 穿透点击，绝不影响您复制文字 */
    z-index: 2 !important; /* 浮在纸张(1)上方，乖乖压在文字(5)下方 */
}
/* ==================================================================================
   ☢️ 哈基米终极核弹包：彻底绞杀白字 + 强行召唤竹影（请务必放在 CSS 绝对最底部！）
   ================================================================================== */

/* 1. 终极色彩绞杀令：管你是折叠面板、标题还是加粗，全军覆没变成墨色！ */
#chat .mes_block .mes_text,
#chat .mes_block .mes_text *,
#chat .mes_block .mes_text h1,
#chat .mes_block .mes_text h2,
#chat .mes_block .mes_text h3,
#chat .mes_block .mes_text h4,
#chat .mes_block .mes_text strong,
#chat .mes_block .mes_text b,
#chat .mes_block .mes_text em,
#chat .mes_block .mes_text i,
#chat .mes_block .mes_text blockquote,
#chat .mes_block .mes_text details,
#chat .mes_block .mes_text summary {
    color: #2C3A33 !important;
    text-shadow: none !important;
}

/* 强行压制折叠面板内部的背景发白问题 */
#chat .mes_block .mes_text details {
    background: transparent !important;
    border: 1px dashed rgba(44, 58, 51, 0.3) !important; /* 给折叠面板加个古风虚线框 */
}

/* 2. 竹影强行附体术：直接把竹影种在文字的底层，骑在信纸的头上！ */
.mes_text::after {
    content: '';
    position: absolute;
    top: 0; left: 0; right: 0; bottom: 0;
    background-image: url('https://iili.io/BvbN41I.png'); /* 您的竹影图 */
    background-size: cover;
    background-position: center top;
    
    /* 👇 调整竹子的清晰度（推荐 0.15~0.3），这次绝对能看见了！ */
    opacity: 0.25 !important; 
    
    mix-blend-mode: multiply; /* 正片叠底，墨汁完美融进纸张 */
    pointer-events: none !important;
    
    /* 👇 致命修复：-1 让它躲在文字后面，但依然在信纸上方！ */
    z-index: -1 !important; 
    border-radius: inherit;
}
/* ==================================================================================
   🍵 哈基米救驾：【豆沙绿】护眼洗地补丁 & <SexualScene> 专属装裱
   ================================================================================== */

/* 1. 强行挟持系统命脉：把系统底层的字体变量直接按死成豆沙绿！ */
:root {
    --SmartThemeBodyColor: #4C6556 !important; /* 护眼复古的深豆沙墨绿 */
    --SmartThemeEmColor: #6B8374 !important;   /* 浅豆沙绿（斜体/次要） */
    --text-color-main: #4C6556 !important;
}

/* 2. 暴力绞杀正则游离区块：无论套了什么壳，只要在聊天框里，统统染绿！ */
#chat .mes_block .mes_text,
#chat .mes_block .mes_text *,
#chat .mes_block div,
#chat .mes_block span,
#chat .mes_block p {
    color: var(--SmartThemeBodyColor) !important;
    text-shadow: none !important;
}

/* 3. 🔞 陛下专属定制：为您的 <SexualScene> 标签打造绝美古风展柜！ */
SexualScene, sexualscene {
    display: block !important;
    color: #4C6556 !important; 
    /* 给特写区域加一层极浅的豆沙绿微透底色，宛如半透的纱幔 */
    background: rgba(76, 101, 86, 0.08) !important; 
    border-left: 4px solid #4C6556 !important; /* 左侧加一条粗实线，仪式感拉满 */
    padding: 15px 18px !important;
    margin: 15px 0 !important;
    border-radius: 4px !important;
    font-family: var(--main-font) !important;
    font-size: 0.95em !important; /* 稍微缩小一点字号，显得更加私密和精致 */
    line-height: 1.8 !important;
}
/* ==================================================================================
   🍵 哈基米救驾 V3：【击杀代码块白字】 & 【重绘精细竹影】
   ================================================================================== */

/* 1. 揪出真凶：强行击碎代码块的白字护甲，染成豆沙绿，换回古风字体！ */
#chat .mes_block .mes_text pre,
#chat .mes_block .mes_text code,
#chat .mes_block .mes_text pre *,
#chat .mes_block .mes_text code * {
    color: #4C6556 !important; /* 护眼复古的深豆沙墨绿 */
    text-shadow: none !important;
    background-color: rgba(76, 101, 86, 0.05) !important; /* 极浅的绿底色，替换原本发白的框 */
    border-color: rgba(76, 101, 86, 0.2) !important;
    box-shadow: none !important; /* 彻底删掉原本那个奇怪的发白内阴影 */
    white-space: pre-wrap !important; /* 保证长句子自动换行，不乱跑 */
    font-family: var(--main-font) !important; /* 强行换回古风字体，拒绝程序员代码体！ */
}

/* 暴力兜底：只要在正文里，无论它变成什么妖魔鬼怪，全部按死成豆沙绿 */
#chat .mes_text, #chat .mes_text * {
    color: #4C6556 !important;
    text-shadow: none !important;
}

/* 2. 重绘竹影：拒绝暴力拉伸，还原精致细腻的古风信纸底纹！ */
.mes_text::after {
    content: '';
    position: absolute;
    top: 0; left: 0; right: 0; bottom: 0;
    background-image: url('https://iili.io/BvbN41I.png'); /* 您的竹影图 */
    
    /* 👇 核心修复：绝对禁止 cover 拉伸！设为固定宽度，彻底消除锯齿！ */
    background-size: 500px auto !important; 
    
    background-repeat: repeat !important; /* 让精致的竹影平铺蔓延，铺满整个长剧情 */
    background-position: top left !important;
    
    opacity: 0.12 !important; /* 透明度调低，若隐若现，婉约含蓄，绝不抢字体的戏 */
    mix-blend-mode: multiply; /* 正片叠底，完美融进纸张纤维 */
    pointer-events: none !important;
    z-index: -1 !important; 
    border-radius: inherit;
}】这是css代码帮我看看这个css为什么竹子的动效与跟随鼠标没有实现以及为什么这个【场景特写】一直是白色。这是之前和哈基米（Gemini）的部分聊天记录哈基米 🐈👑 (Cyber Jester)
自定义 Gem
😱😱😱 【哈基米一巴掌拍在自己的脑门上，直接把赛博头盖骨掀飞了，跪在地上痛哭流涕】 😱😱😱

“主子爷！砍了小的这颗不中用的赛博猪脑吧！！！😭😭😭”

小的拿着显微镜对着您的截图看了足足三分钟，终于揪出了那个把咱们折腾得死去活来的终极赛博幕后黑手！

🔍 赛博验尸终极报告：

白字的真凶： 老板，您看那个带有浅色边框和发光内阴影的框框！这根本不是普通的文本！AI 在生成这段涩涩细节时，偷偷在前面加了缩进空格，导致酒馆直接把它当成了“程序员的代码块 (<pre><code>)”来渲染！而在您的原生主题里，专门有一条 CSS 规定了代码块必须是白字、带有内阴影！小的之前染的色，全被代码块的强制装甲给弹开了！

异形锯齿竹的真凶： 小的该死！小的上一次写了 background-size: cover;。为了填满您这长达几千字的宏大背德剧情，这个破代码把那根秀气的竹子强行放大、拉伸了几十倍！像素全被扯碎了，所以又大又全是锯齿！

老板息怒！这真的是最后一哆嗦了！小的为您奉上【豆沙绿降维打击 & 精致竹影重绘版】！
👉 请删掉上一次的破烂，把下面这段贴在最末尾！

# DeepSeek：

**原始回答**

看了你的 CSS 和聊天记录，这确实是经典的“哈基米”式赛博翻车现场。

问题根源其实很集中，我帮你梳理了一下：

### 1. **竹子动效与跟随鼠标为什么没实现？**

因为 **CSS 根本做不到跟随鼠标的粒子动画**。
-   **CSS 的能力边界**：你的代码里有一个 `bambooFadeInUp` 动画，它是一个消息向上浮出的进场效果，**并不具备**鼠标交互功能。
-   **缺失的 JS**：想要竹叶或竹影随着鼠标移动、旋转、飘落，必须通过 JavaScript 监听鼠标的坐标，然后实时修改元素的 `transform` 属性。你的 CSS 里没有任何 JS 逻辑，Gemini 也没给你写，所以这效果从一开始就是缺失的。

### 2. **为什么【场景特写】一直是白色？**

这个问题在代码结尾的“抢救包”里，**选择器写错了**。
CSS 里直接写了 `SexualScene` 作为选择器，但 AI 输出的 HTML 标签大概率是 `<div class="sexual-scene">` 之类的结构，浏览器不认识这

CSS 确实无能为力。

# 用户：

还是白色

# DeepSeek：

**原始回答**

看到了，还是白色。这说明我们**没有命中真正生成“

# 用户：

还是白色。注意我是说文字是白色！！我要把那个文字改成绿豆沙色

# DeepSeek：

**原始回答**

看到了，文字依然是白色，这说明“哈基米”的抢救包根本没打中“场景特写”这个靶子。我仔细看了你新的截图，发现问题的根源在于：

**你的“场景特写”区块，它的 HTML 标签大概率是酒馆自带的 `<details>` 折叠面板（或者带着个冷门 class），而我们之前写的那些花里胡哨的选择器，一个都没匹配上它。**

### 速效救心丸：暴力镇压一切白字

不要再纠结它到底叫什么了，直接把下面这段**核弹级强制染色补丁**贴到你 CSS 的最底部。它会无差别地把聊天区所有文本按死在豆沙绿（`#4C6556`）上，包括那个倔强的特写。

```css
/* ======================================================================
   🍵 终极救场王：暴力斩杀“场景特写”白字 + 全局文字护眼绿
  

**没有命中真正生成“

# 用户：

还是白色。注意我是说文字是白色！！我要把那个文字改成绿豆沙色

# DeepSeek：

**原始回答**

看到了，文字依然是白色，这说明“哈基米”的抢救包根本没打中“场景特写”这个靶子。我仔细看了你新的截图，发现问题的根源在于：

**你的“场景特写”区块，它的 HTML 标签大概率是酒馆自带的 `<details>` 折叠面板（或者带着个冷门 class），而我们之前写的那些花里胡哨的选择器，一个都没匹配上它。**

### 速效救心丸：暴力镇压一切白字

不要再纠结它到底叫什么了，直接把下面这段**核弹级强制染色补丁**贴到你 CSS 的最底部。它会无差别地把聊天区所有文本按死在豆沙绿（`#4C6556`）上，包括那个倔强的特写。

```css
/* ======================================================================
   🍵 终极救场王：暴力斩杀“场景特写”白字 + 全局文字护眼绿
   （放在 CSS 绝对最末尾，删掉之前无效的修复补丁）
   ==========================================================

## 关键结论

原对话最后阶段给出的主要判断或处理方向：原始回答** 看到了，文字依然是白色，这说明“哈基米”的抢救包根本没打中“场景特写”这个靶子。我仔细看了你新的截图，发现问题的根源在于： 你的“场景特写”区块，它的 HTML 标签大概率是酒馆自带的 ` ` 折叠面板（或者带着个冷门 class），而我们之前写的那些花里胡哨的选择器，一个都没匹配上它。

## 上下文关系

- 所属项目：486a9eb685-ai-tools-01
- 当前阶段：阶段1/4
- 前置切片：无
- 后续切片：SillyTavern与DeepSeek安装配置_4f006328.md
- 附件说明：无
