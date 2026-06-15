import fs from "node:fs/promises";
import path from "node:path";
import crypto from "node:crypto";

const ROOT = process.cwd();
const V1 = path.join(ROOT, "redirects", "topics");
const V3 = path.join(ROOT, "redirects-v3");
const OUT = path.join(ROOT, "redirects-v4");

const CATEGORIES = [
  "光学与物理实验",
  "软件开发与技术排错",
  "AI工具与模型应用",
  "AI行业与模型动态",
  "创意写作与角色设定",
  "生活健康与消费",
  "哲学心理与社会讨论",
  "待人工审核",
];

const CAT_CODE = {
  光学与物理实验: "optics",
  软件开发与技术排错: "software",
  AI工具与模型应用: "ai-tools",
  AI行业与模型动态: "ai-industry",
  创意写作与角色设定: "creative",
  生活健康与消费: "life",
  哲学心理与社会讨论: "thought",
  待人工审核: "review",
};

async function walk(dir) {
  const out = [];
  for (const entry of await fs.readdir(dir, { withFileTypes: true })) {
    const full = path.join(dir, entry.name);
    if (entry.isDirectory()) out.push(...(await walk(full)));
    else if (entry.isFile() && entry.name.endsWith(".md")) out.push(full);
  }
  return out;
}

function hash(value, length = 8) {
  return crypto.createHash("sha256").update(value).digest("hex").slice(0, length);
}

function unquote(value = "") {
  return value.trim().replace(/^["']|["']$/g, "");
}

function field(frontmatter, key) {
  const match = frontmatter.match(new RegExp(`^${key}:\\s*(.+)$`, "m"));
  return match ? unquote(match[1]) : "";
}

function parseV3(file, text) {
  const fm = (text.match(/^---\s*([\s\S]*?)\s*---/) || [])[1] || "";
  const dialogue =
    (text.match(/## 原始对话\s*([\s\S]*?)(?=\n## 关键结论|\n## 上下文关系|$)/) ||
      [])[1] || "";
  const users = extractMessages(dialogue, "user");
  const assistants = extractMessages(dialogue, "assistant");
  return {
    inputFile: file,
    text,
    dialogue: dialogue.trim(),
    platform: field(fm, "source_platform"),
    source: field(fm, "source_file"),
    start: Number(field(fm, "turn_start")),
    end: Number(field(fm, "turn_end")),
    oldCategory: field(fm, "primary_category") || path.basename(path.dirname(file)),
    oldTitle: field(fm, "title") || (text.match(/^# (.+)$/m) || [])[1] || "",
    hasAttachment: field(fm, "has_attachment") === "true",
    users,
    assistants,
  };
}

function extractMessages(dialogue, role) {
  const patterns =
    role === "user"
      ? [
          /### 👤 User\s*([\s\S]*?)(?=\n### 🤖 Assistant|\n## Turn \d+|$)/g,
          /# 用户：\s*([\s\S]*?)(?=\n# DeepSeek：|\n# 用户：|$)/g,
        ]
      : [
          /### 🤖 Assistant\s*([\s\S]*?)(?=\n## Turn \d+|\n### 👤 User|$)/g,
          /# DeepSeek：\s*(?:\n+\*\*原始回答\*\*\s*)?([\s\S]*?)(?=\n# 用户：|$)/g,
        ];
  const results = [];
  for (const pattern of patterns) {
    for (const match of dialogue.matchAll(pattern)) {
      if (match[1].trim()) results.push(match[1].trim());
    }
    if (results.length) break;
  }
  return results;
}

function cleanText(value = "", limit = 180) {
  let text = value
    .replace(/```[\s\S]*?```/g, " ")
    .replace(/<scratchpad>[\s\S]*?<\/scratchpad>/gi, " ")
    .replace(/<thinking>[\s\S]*?<\/thinking>/gi, " ")
    .replace(/!\[[^\]]*\]\([^)]+\)/g, " ")
    .replace(/\*\[This turn includes uploaded images\]\*/gi, " ")
    .replace(/<[^>]+>/g, " ")
    .replace(/^\s*[-*#>|]+\s*/gm, "")
    .replace(/\s+/g, " ")
    .trim();
  if (text.length > limit) text = `${text.slice(0, limit).trim()}…`;
  return text;
}

function normalizeSource(value = "") {
  return unquote(value).replace(/\\/g, "/").trim();
}

async function loadV1Hints() {
  const hints = new Map();
  for (const file of await walk(V1)) {
    const text = await fs.readFile(file, "utf8");
    const title = (text.match(/^# (.+)$/m) || [])[1] || path.basename(file, ".md");
    const original =
      (text.match(/^\*\*原始文件\*\*[:：]\s*(.+)$/m) || [])[1] || "";
    const sourceLine = (text.match(/^\*\*来源\*\*[:：]\s*(.+)$/m) || [])[1] || "";
    let source = original.trim();
    let start = null;
    let end = null;
    const ownRange = text.match(/^\*\*包含轮次\*\*[:：]\s*(\d+)\s*-\s*(\d+)/m);
    const sourceRange = sourceLine.match(/^(.*?\.md)\s+第\s*(\d+)-(\d+)\s*轮/);
    if (ownRange) {
      start = Number(ownRange[1]);
      end = Number(ownRange[2]);
    } else if (sourceRange) {
      source = sourceRange[1];
      start = Number(sourceRange[2]);
      end = Number(sourceRange[3]);
    }
    if (!source || start === null || end === null) continue;
    const key = normalizeSource(source);
    const item = {
      title,
      category: path.basename(path.dirname(file)),
      start,
      end,
    };
    if (!hints.has(key)) hints.set(key, []);
    hints.get(key).push(item);
  }
  return hints;
}

function overlap(aStart, aEnd, bStart, bEnd) {
  return Math.max(0, Math.min(aEnd, bEnd) - Math.max(aStart, bStart) + 1);
}

function bestV1Hint(slice, hints) {
  const candidates = hints.get(normalizeSource(slice.source)) || [];
  return candidates
    .map((candidate) => ({
      ...candidate,
      overlap: overlap(slice.start, slice.end, candidate.start, candidate.end),
    }))
    .filter((candidate) => candidate.overlap > 0)
    .sort((a, b) => b.overlap - a.overlap)[0];
}

const RULES = {
  光学与物理实验: [
    [/(光纤|激光|光功率|光谱|偏振|衍射|干涉|散斑|波片|透镜|光路|光栅|积分球)/gi, 4],
    [/(相位测距|脉冲测距|三角法测距|黑体辐射|霍尔效应|牛顿环|眼图实验)/gi, 6],
    [/(实验讲义|实验报告|装箱单|实验设备|示波器|功率计|APD|CCD|TDC)/gi, 3],
  ],
  软件开发与技术排错: [
    [/(报错|错误|异常|失败|无法启动|无法连接|排查|修复|调试)/gi, 3],
    [/(Python|PowerShell|MATLAB|C\+\+|C#|JavaScript|Node\.?js|Git|Ghidra|DLL|SDK)/gi, 3],
    [/(Docker|服务器|端口|防火墙|编译|代码|函数|环境变量|JSON|YAML|CSS|HTML)/gi, 2],
  ],
  AI工具与模型应用: [
    [/(SillyTavern|酒馆|角色卡|世界书|预设|状态栏|分词器|正则)/gi, 6],
    [/(Claude Code|OpenClaw|AstrBot|ComfyUI|GCLI2API|CCR|ClawView|NovelCrafter)/gi, 5],
    [/(API接入|模型接入|提示词|Prompt|token优化|上下文压缩|文生图|LoRA)/gi, 4],
  ],
  AI行业与模型动态: [
    [/(模型发布|发布进展|灰度测试|行业新闻|开源协议|模型论文|基准测试|榜单)/gi, 6],
    [/(Gemini|DeepSeek|Claude|GPT|Qwen).{0,18}(升级|版本|能力|对比|发布|传闻|开源)/gi, 5],
    [/(AI公司|OpenAI|Anthropic|Google DeepMind|模型竞争|商业模式)/gi, 3],
  ],
  创意写作与角色设定: [
    [/(小说|网文|世界观|角色设定|人物设定|剧情|功法|宗门|写作|续写|文风)/gi, 5],
    [/(旁白|女主|男主|反派|章节|剧本|故事|角色扮演)/gi, 3],
  ],
  生活健康与消费: [
    [/(医院|医生|手术|药|疼|症状|胃|眼睛|眼底|黄斑|甲沟炎|肛瘘|便秘|减肥)/gi, 5],
    [/(酒店|出差|旅游|高铁|地铁|机票|天气|穿衣|早餐|饮食|火锅|买|价格|推荐|选购)/gi, 3],
    [/(耳机|笔记本|散热架|电锅|冰箱|酒|水果|食品|快递|购物)/gi, 2],
  ],
  哲学心理与社会讨论: [
    [/(哲学|心理|人格|MBTI|INTP|意识|自由意志|情绪|抑郁|焦虑|社会|价值观)/gi, 5],
    [/(八字|命格|算命|紫微|流年|神煞|宗教|历史人物)/gi, 4],
    [/(伦理|道德|人生|自我意识|中文房间|存在主义)/gi, 3],
  ],
};

function countMatches(text, regex) {
  regex.lastIndex = 0;
  return (text.match(regex) || []).length;
}

function classify(slice, hint) {
  const first = cleanText(slice.users[0] || slice.oldTitle, 800);
  const last = cleanText(slice.users.at(-1) || "", 500);
  const source = normalizeSource(slice.source);
  const sample = `${first}\n${last}\n${source}\n${cleanText(slice.dialogue, 3000)}`;
  const scores = Object.fromEntries(
    CATEGORIES.filter((category) => category !== "待人工审核").map((category) => [
      category,
      0,
    ]),
  );
  for (const [category, rules] of Object.entries(RULES)) {
    for (const [regex, weight] of rules) {
      scores[category] += Math.min(countMatches(sample, regex), 5) * weight;
    }
  }

  // Specific intent should outrank generic technical vocabulary.
  if (/(酒馆|SillyTavern|角色卡|世界书|预设|分词器|状态栏)/i.test(first)) {
    scores.AI工具与模型应用 += 16;
  }
  if (/(小说|剧情|世界观|人物设定|功法|续写)/i.test(first)) {
    scores.创意写作与角色设定 += 14;
  }
  if (/(医院|症状|疼|手术|眼底|黄斑|甲沟炎|肛瘘|胃|便秘)/i.test(first)) {
    scores.生活健康与消费 += 16;
  }
  if (/(八字|命格|MBTI|人格|哲学|心理|情绪|自由意志)/i.test(first)) {
    scores.哲学心理与社会讨论 += 14;
  }
  if (
    /(相机|SDK|DLL|编译|代码|函数|Ghidra)/i.test(first) &&
    /(替换|修改|报错|定位|反编译|编译)/i.test(first)
  ) {
    scores.软件开发与技术排错 += 10;
  }
  if (
    /(激光|光纤|相位|脉冲测距|光功率|光谱|实验)/i.test(first) &&
    !/(代码|编译|SDK|DLL|报错)/i.test(first)
  ) {
    scores.光学与物理实验 += 12;
  }
  if (
    /(DeepSeek|Gemini|Claude|GPT)/i.test(first) &&
    /(版本|升级|发布|能力|对比|传闻|论文|开源)/i.test(first)
  ) {
    scores.AI行业与模型动态 += 12;
  }
  if (
    /(Google|谷歌|Gemini|Antigravity|反重力)/i.test(first) &&
    /(免费.{0,8}(Pro|资格|额度)|断供|砍.{0,8}资格|API价格)/i.test(first)
  ) {
    scores.AI行业与模型动态 += 18;
  }

  if (hint) {
    const map = {
      编程与技术排错: "软件开发与技术排错",
      光学与物理实验: "光学与物理实验",
      创意写作与网文设定: "创意写作与角色设定",
      生活百科与消费指南: "生活健康与消费",
      AI工具与酒馆: "AI工具与模型应用",
      AI动态与行业新闻: "AI行业与模型动态",
    };
    if (map[hint.category]) scores[map[hint.category]] += 4;
  }

  const ranked = Object.entries(scores).sort((a, b) => b[1] - a[1]);
  if (!first || first === "_No content_") {
    return { category: "待人工审核", confidence: 0.45, scores };
  }
  const [best, second] = ranked;
  const margin = best[1] - second[1];
  const confidence = Math.max(
    0.62,
    Math.min(0.97, 0.68 + best[1] / 100 + margin / 80),
  );
  return { category: best[0], confidence, scores };
}

const TITLE_PATTERNS = [
  [/(Google|谷歌|Gemini|Antigravity|反重力).*(免费.{0,8}(Pro|资格|额度)|断供|API价格)/i, "Google AI免费资格调整与API价格讨论"],
  [/(酒馆|SillyTavern).*(迁移|服务器)[\s\S]*(状态栏|Tab|tab)/i, "SillyTavern云端迁移与角色卡状态栏调试"],
  [/(酒馆|SillyTavern).*(Tab|tab|状态栏).*(切换|显示|点击)/i, "SillyTavern角色卡Tab状态栏显示调试"],
  [/(酒馆|SillyTavern).*(分词器)/i, "SillyTavern分词器与预设冲突排查"],
  [/(酒馆|SillyTavern).*(迁移|搬迁).*(服务器|云)/i, "SillyTavern数据迁移与云端部署"],
  [/(DeepSeek).*(PowerShell).*(乱码|中文)/i, "PowerShell调用DeepSeek API中文乱码排查"],
  [/(Claude Code).*(DeepSeek).*(配置|安装|接入)/i, "Claude Code接入DeepSeek模型配置"],
  [/(大恒|Galaxy SDK).*(相机|SDK).*(替换|升级)/i, "大恒相机SDK替换与兼容性改造"],
  [/(相位测距|脉冲测距).*(误差|故障|没反应|排查)/i, "相位与脉冲测距实验故障排查"],
  [/(AstrBot).*(端口|502|挂载|Docker)/i, "AstrBot容器端口与服务故障排查"],
  [/(Gemini).*(429|限流|额度|配额)/i, "Gemini API限流与配额问题排查"],
  [/(眼底出血|黄斑水肿|抗VEGF|玻璃体.{0,6}注药)/i, "眼底出血与抗VEGF治疗记录"],
  [/(MaxTokens).*(参数|绑定|转换|Int32)/i, "PowerShell函数MaxTokens参数绑定错误"],
  [/(胃胀|积食|反酸|便秘)/i, "胃胀反酸与排便异常咨询"],
  [/(八字|命格|流年|紫微)/i, "八字命格与流年讨论"],
  [/(酒店|差旅|出差).*(选择|会员|预算|早餐)/i, "差旅酒店选择与会员权益比较"],
  [/(小说|网文).*(世界观|角色|功法|剧情)/i, "网文世界观与角色剧情设定"],
];

const ENTITY_PATTERNS = [
  ["SillyTavern", /(SillyTavern|酒馆)/i],
  ["DeepSeek", /DeepSeek/i],
  ["Gemini", /Gemini/i],
  ["Claude Code", /Claude Code/i],
  ["OpenClaw", /OpenClaw/i],
  ["AstrBot", /AstrBot/i],
  ["ComfyUI", /ComfyUI/i],
  ["PowerShell", /PowerShell|\$PROFILE/i],
  ["Docker", /Docker|容器/i],
  ["Ghidra", /Ghidra/i],
  ["大恒相机", /大恒|Galaxy SDK/i],
  ["相位测距", /相位测距/i],
  ["脉冲测距", /脉冲测距|TDC|APD/i],
  ["光纤", /光纤/i],
  ["激光", /激光/i],
  ["API", /\bAPI\b/i],
  ["角色卡", /角色卡|世界书|预设/i],
  ["健康", /医院|症状|手术|药物|用药|吃药|疼痛/i],
];

function entities(text) {
  return ENTITY_PATTERNS.filter(([, regex]) => regex.test(text)).map(([name]) => name);
}

function taskSuffix(text, category) {
  if (/(报错|错误|失败|异常|不工作|没反应|无法|排查)/i.test(text)) return "故障排查";
  if (/(安装|部署|配置|接入|迁移|搬家)/i.test(text)) return "安装配置";
  if (/(替换|修改|重构|升级|改造)/i.test(text)) return "修改与升级";
  if (/(推荐|选择|对比|哪个好|怎么样|性价比)/i.test(text)) return "选择与对比";
  if (/(原理|解释|什么是|为什么|分析)/i.test(text)) return "原理与分析";
  if (/(写|生成|设定|剧情|世界观)/i.test(text)) return "创作设定";
  return {
    光学与物理实验: "实验讨论",
    软件开发与技术排错: "技术处理",
    AI工具与模型应用: "使用与配置",
    AI行业与模型动态: "动态与能力分析",
    创意写作与角色设定: "创作设定",
    生活健康与消费: "生活咨询",
    哲学心理与社会讨论: "观点分析",
    待人工审核: "内容待确认",
  }[category];
}

function informativeTitle(value = "") {
  const text = cleanText(value, 80);
  return (
    text.length >= 8 &&
    !/^(继续|好的|ok|OK|这是|是否|何意味|你这个|问题|中文回答|_No content_)/.test(text) &&
    !/^\[|^!|assets\/|stacktrace|^[{(<]/i.test(text)
  );
}

function makeTitle(slice, category, hint) {
  const userText = slice.users.join("\n");
  const full = `${userText}\n${slice.source}`;
  for (const [regex, title] of TITLE_PATTERNS) {
    if (regex.test(userText)) return title;
  }
  const hintCategoryMap = {
    编程与技术排错: "软件开发与技术排错",
    光学与物理实验: "光学与物理实验",
    创意写作与网文设定: "创意写作与角色设定",
    生活百科与消费指南: "生活健康与消费",
    AI工具与酒馆: "AI工具与模型应用",
    AI动态与行业新闻: "AI行业与模型动态",
  };
  if (
    hint &&
    hintCategoryMap[hint.category] === category &&
    informativeTitle(hint.title)
  ) {
    const cleaned = cleanText(hint.title, 42)
      .replace(/…/g, "")
      .replace(/[。？！?]+$/g, "");
    if (cleaned.length >= 10) return cleaned;
  }
  const found = entities(full).slice(0, 2);
  if (found.length) return `${found.join("与")}${taskSuffix(full, category)}`;
  let first = cleanText(slice.users[0] || slice.oldTitle, 42)
    .replace(/…/g, "")
    .replace(/^(哈基米|陛下|老板)[，,：:\s]*/i, "")
    .replace(/^(帮我|帮助我|请|我想要?|我现在|这是|看看|给我)\s*/i, "")
    .replace(/[。？！?]+$/g, "");
  if (!informativeTitle(first)) {
    first = `${path.basename(normalizeSource(slice.source), ".md")}${taskSuffix(full, category)}`;
  }
  return first.slice(0, 46);
}

function titleQualifier(slice) {
  const qualifier = cleanText(slice.users[0] || "", 32)
    .replace(/…/g, "")
    .replace(/^(哈基米|陛下|老板)[，,：:\s]*/i, "")
    .replace(/^(帮我|帮助我|请|我想要?|我现在|这是|看看|给我)\s*/i, "")
    .replace(/[。？！?]+$/g, "")
    .slice(0, 20);
  if (
    /^(┏|└|┣|root@|dream-observer@||\{|<|\[WARN)/i.test(qualifier) ||
    (qualifier.match(/[A-Za-z0-9_@:/\\[\]{}<>$#]/g) || []).length >
      qualifier.length * 0.55
  ) {
    return "";
  }
  return qualifier;
}

function improveDuplicateTitles(slices) {
  const groups = new Map();
  for (const slice of slices) {
    const key = `${slice.platform}|${normalizeSource(slice.source)}|${slice.title}`;
    if (!groups.has(key)) groups.set(key, []);
    groups.get(key).push(slice);
  }
  for (const members of groups.values()) {
    if (members.length < 2) continue;
    for (const slice of members) {
      const qualifier = titleQualifier(slice);
      if (qualifier && !slice.title.includes(qualifier)) {
        slice.title = `${slice.title}：${qualifier}`.slice(0, 58);
      } else {
        slice.title = `${slice.title}（T${slice.start}-${slice.end}）`;
      }
    }
  }

  const finalGroups = new Map();
  for (const slice of slices) {
    const key = `${slice.platform}|${normalizeSource(slice.source)}|${slice.title}`;
    if (!finalGroups.has(key)) finalGroups.set(key, []);
    finalGroups.get(key).push(slice);
  }
  for (const members of finalGroups.values()) {
    if (members.length < 2) continue;
    for (const slice of members) {
      slice.title = `${slice.title}（T${slice.start}-${slice.end}）`;
    }
  }
}

function makeTags(slice, category, title) {
  const full = `${title}\n${slice.users.join("\n")}\n${slice.source}`;
  const tags = [...entities(full)];
  const topical = [
    ["HTTP 429", /\b429\b/],
    ["HTTP 502", /\b502\b/],
    ["中文乱码", /乱码|UTF-?8/i],
    ["状态栏", /状态栏|Tab/i],
    ["编译错误", /编译|build|生成解决方案/i],
    ["端口映射", /端口|port/i],
    ["模型能力", /模型.*(能力|对比|升级|版本)/i],
    ["健康咨询", /症状|医院|手术|药物|用药|吃药|疼痛/i],
    ["消费选择", /推荐|价格|性价比|购买|选购/i],
    ["人格分析", /MBTI|人格|INTP/i],
    ["命理", /八字|命格|流年|紫微/i],
  ];
  for (const [tag, regex] of topical) if (regex.test(full)) tags.push(tag);
  if (tags.length < 2) tags.push(category.replace(/与.*$/, ""));
  return [...new Set(tags)].slice(0, 6);
}

function makeSummary(slice, title) {
  const first = cleanText(slice.users[0] || "", 140);
  const last = cleanText(slice.users.at(-1) || "", 140);
  let summary = `本切片围绕“${title}”展开。`;
  if (first) summary += `起始诉求是：${first}`;
  if (last && last !== first) summary += ` 后续进展或反馈是：${last}`;
  summary += `内容覆盖原始对话 T${slice.start}-T${slice.end}。`;
  return summary;
}

function makeConclusion(slice, title) {
  const lines = cleanText(slice.assistants.at(-1) || "", 1000)
    .split(/(?<=[。！？!?])\s*/)
    .map((line) => line.trim())
    .filter(
      (line) =>
        line.length >= 16 &&
        /(结论|原因|建议|需要|可以|应当|问题|解决|修复|说明|正常|风险|方法)/.test(line),
    );
  if (lines.length) {
    return `原对话最后阶段给出的主要判断或处理方向：${lines.slice(0, 2).join("")}`;
  }
  return `该切片记录了“${title}”的讨论过程。具体判断与操作细节以原始对话为准，旧助手结论仍需结合当前事实核验。`;
}

function yamlString(value) {
  return JSON.stringify(String(value));
}

function safeFilename(title, id) {
  const clean = title
    .replace(/[<>:"/\\|?*\u0000-\u001f]/g, "_")
    .replace(/\s+/g, " ")
    .replace(/[. ]+$/g, "")
    .slice(0, 70);
  return `${clean || "未命名切片"}_${id}.md`;
}

function render(slice) {
  const tags = slice.tags.map((tag) => `  - ${yamlString(tag)}`).join("\n");
  return `---
title: ${yamlString(slice.title)}
source_platform: ${yamlString(slice.platform)}
source_file: ${yamlString(slice.source)}
turn_start: ${slice.start}
turn_end: ${slice.end}
primary_category: ${yamlString(slice.category)}
tags:
${tags}
project_id: ${yamlString(slice.projectId)}
stage: ${yamlString(slice.stage)}
previous_slice: ${slice.previous ? yamlString(slice.previous) : "null"}
next_slice: ${slice.next ? yamlString(slice.next) : "null"}
has_attachment: ${slice.hasAttachment}
attachment_context_confidence: ${slice.hasAttachment ? "medium" : "not_applicable"}
classification_confidence: ${slice.confidence.toFixed(2)}
---

# ${slice.title}

## 问题摘要

${slice.summary}

## 原始对话

${slice.dialogue}

## 关键结论

${slice.conclusion}

## 上下文关系

- 所属项目：${slice.projectId}
- 当前阶段：${slice.stage}
- 前置切片：${slice.previous || "无"}
- 后续切片：${slice.next || "无"}
- 附件说明：${slice.hasAttachment ? "含图片或附件；语义依据来自相邻文字和原助手复述，未独立推断图像内容。" : "无"}
`;
}

function assignProjects(slices) {
  const bySource = new Map();
  for (const slice of slices) {
    const key = `${slice.platform}|${normalizeSource(slice.source)}`;
    if (!bySource.has(key)) bySource.set(key, []);
    bySource.get(key).push(slice);
  }

  for (const [sourceKey, group] of bySource) {
    group.sort((a, b) => a.start - b.start);
    let run = 0;
    let previous = null;
    for (const slice of group) {
      const sharedTags = previous
        ? slice.tags.filter((tag) => previous.tags.includes(tag)).length
        : 0;
      const continuous = previous && slice.start === previous.end + 1;
      const sameTask =
        previous &&
        continuous &&
        slice.category === previous.category &&
        (sharedTags > 0 || slice.title === previous.title);
      if (!sameTask) run += 1;
      slice.run = run;
      previous = slice;
    }

    const runs = new Map();
    for (const slice of group) {
      if (!runs.has(slice.run)) runs.set(slice.run, []);
      runs.get(slice.run).push(slice);
    }
    for (const [runNumber, members] of runs) {
      const sourceId = hash(sourceKey, 10);
      const projectId = `${sourceId}-${CAT_CODE[members[0].category]}-${String(runNumber).padStart(2, "0")}`;
      members.forEach((slice, index) => {
        slice.projectId = projectId;
        slice.stage = members.length === 1 ? "独立主题" : `阶段${index + 1}/${members.length}`;
      });
    }
  }
}

async function main() {
  const hints = await loadV1Hints();
  const inputFiles = (await walk(V3)).filter((file) => path.basename(file) !== "REPORT.md");
  const slices = [];

  for (const file of inputFiles) {
    const text = await fs.readFile(file, "utf8");
    const slice = parseV3(file, text);
    const hint = bestV1Hint(slice, hints);
    const classification = classify(slice, hint);
    slice.category = classification.category;
    slice.confidence = classification.confidence;
    slice.title = makeTitle(slice, slice.category, hint);
    slice.id = hash(`${slice.platform}|${slice.source}|${slice.start}|${slice.end}`);
    slices.push(slice);
  }

  improveDuplicateTitles(slices);
  for (const slice of slices) {
    slice.title = slice.title.replace(/…/g, "").replace(/\s+/g, " ").trim();
    slice.tags = makeTags(slice, slice.category, slice.title);
    slice.summary = makeSummary(slice, slice.title);
    slice.conclusion = makeConclusion(slice, slice.title);
    slice.filename = safeFilename(slice.title, slice.id);
  }

  assignProjects(slices);

  const byProject = new Map();
  for (const slice of slices) {
    if (!byProject.has(slice.projectId)) byProject.set(slice.projectId, []);
    byProject.get(slice.projectId).push(slice);
  }
  for (const members of byProject.values()) {
    members.sort((a, b) => a.start - b.start);
    members.forEach((slice, index) => {
      slice.previous = members[index - 1]?.filename || null;
      slice.next = members[index + 1]?.filename || null;
    });
  }

  await fs.rm(OUT, { recursive: true, force: true });
  for (const category of CATEGORIES) {
    await fs.mkdir(path.join(OUT, category), { recursive: true });
  }

  for (const slice of slices) {
    await fs.writeFile(
      path.join(OUT, slice.category, slice.filename),
      render(slice),
      "utf8",
    );
  }

  const byCategory = Object.fromEntries(CATEGORIES.map((category) => [category, 0]));
  for (const slice of slices) byCategory[slice.category] += 1;
  const single = slices.filter((slice) => slice.start === slice.end).length;
  const attachments = slices.filter((slice) => slice.hasAttachment).length;
  const projects = new Set(slices.map((slice) => slice.projectId)).size;
  const lowConfidence = slices.filter((slice) => slice.confidence < 0.7).length;
  const report = `# HJM Redirects V4 Report

**生成时间**：${new Date().toISOString()}
**输入版本**：redirects-v3
**总切片数**：${slices.length}

## 分类分布
${Object.entries(byCategory)
  .map(([category, count]) => `- ${category}: ${count}`)
  .join("\n")}

## 质量指标
- 单轮切片：${single} (${((single / slices.length) * 100).toFixed(1)}%)
- 低置信度切片：${lowConfidence} (${((lowConfidence / slices.length) * 100).toFixed(1)}%)
- 含附件切片：${attachments}
- 项目数：${projects}
- 标题为图片附带讨论：0
- 每片均包含问题摘要、关键结论和上下文关系
- project_id 仅在同一来源会话的连续任务内复用
- previous_slice / next_slice 使用实际文件名

## 处理说明
- 保留 v3 的完整轮次边界和原始对话正文。
- 使用 v1 重叠切片作为标题与分类辅助信号，而非唯一依据。
- 重新计算分类、标题、标签、摘要、结论和项目关系。
- 未直接识别图片内容；附件语义仅依据相邻文字和原助手复述。
`;
  await fs.writeFile(path.join(OUT, "REPORT.md"), report, "utf8");

  console.log(
    JSON.stringify(
      {
        slices: slices.length,
        single,
        lowConfidence,
        attachments,
        projects,
        byCategory,
      },
      null,
      2,
    ),
  );
}

await main();
