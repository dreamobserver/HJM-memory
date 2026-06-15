---
name: memory-search
description: Multi-round associative memory search across F:/HJM-memory/. Unlike simple Grep, this skill performs expanding keyword searches, cross-file context linking, and file-title-aware discovery. Use when the user asks about past conversations, tests memory recall, or when a simple keyword search fails to find expected results.
---

# Memory Search with Associative Expansion

Search the HJM memory archive (`F:/HJM-memory/`) using multi-round expanding searches.
The goal is to find information even when the search keyword doesn't appear in the file title or obvious locations.

## Core Principle

**Simple Grep is not enough.** Files are often named after their starting topic (e.g., "拼多多龙井真假鉴别") but contain discussions of completely different topics later (e.g., alcohol selection, ComfyUI setup). A keyword search on "酒" won't find the 龙井 file even though it contains detailed alcohol discussions.

## Workflow

### Round 1: Direct Hit
Search for the user's exact query keywords across all md files:
```
Grep pattern="<keyword1>|<keyword2>" glob="*.md" path="F:/HJM-memory"
```
Also search in file titles (ls or Glob the root directory for filenames containing related terms).

### Round 2: Expand Keywords (THIS IS THE KEY STEP)
Based on the user's query, generate 3-5 **semantically related** search terms. Examples:

| User asks about | Expand to |
|---|---|
| 酒 | 酒精 微醺 气泡 甜白 红酒 啤酒 梅酒 果酒 买.*瓶 小甜水 制冰机.*酒 |
| a÷ | Anthropic Claude 封号 封IP 不退款 歧视.*中国 反作弊 |
| 眼睛 | OCT 黄斑 眼底 出血 视力 眼科 打针 注药 VEGF 眼压 青光 |
| 电锅 | 锅.*材质 不锈钢 煎锅 煮锅 分离 水垢 |
| 服务器设置失败 | iptables DROP 防火墙 INPUT 白名单 物理登录 机房 失联 自杀.*规则 绝对安全.*防御 |
| AI犯错误 | 人工智障 幻觉 编造 不靠谱 坑 翻车 服了 傻.*AI |
| 安徽出差 | 合肥 芜湖 蚌埠 淮南 马鞍山 淮北 铜陵 安庆 黄山 滁州 阜阳 宿州 六安 亳州 池州 宣城 |

**CRITICAL: Expand from scenario → specific vocabulary.** 
Don't search for "服务器部署失败" — search for the specific commands/terms that WOULD appear in such a story.
Example: "AI told me to secure my server and it locked me out" → search for `iptables|DROP|INPUT|白名单|防火墙.*关|物理登录|机房|自杀|面板.*登不上|SSH.*不上` — the actual technical vocabulary of the failure, NOT synonyms of "failure".

**CRITICAL: When searching by location, exhaust ALL sub-locations.**
If the user mentions "安徽", search every city in 安徽. Never stop at the first city found (e.g., 蚌埠) and assume the answer is there. The correct answer might be in 合肥, 芜湖, or another city entirely.

### Round 3: Cross-File Context Linking
When a file is found in Rounds 1-2, **read a portion of it** (first 30 lines + grep for the keyword context). Use what you learn about the file's actual topic to generate more search terms for another round.

Example: If Round 1 finds "a÷" in `罗技公关翻车与新品发布.md`, reading it reveals the file discusses 罗技, gaming, EA, anti-cheat, 封号. These terms become new search anchors.

### Round 4: Blind File Title Scan
If Rounds 1-3 fail, systematically scan all file titles (ls or Glob or MEMORY.md). A file titled "拼多多龙井" might have nothing to do with alcohol in its title but contain alcohol discussions. Read candidate files to verify.

## Search Pattern Library

When searching HJM memory, always combine these pattern categories:

**Direct match**: The user's exact word
**Synonym/alias**: Alternative names (a÷ = Anthropic, 小克 = Claude, 酒馆 = SillyTavern)
**Action context**: What the user was DOING (买酒, 选酒, 推荐, 下单, 到了, 喝完)
**Object context**: Related objects (制冰机, 冰箱, 杯子, 冰块 ← all related to 酒)
**Negation context**: Don't search for just "酒" — also search for specific types and brands

## Important Rules

1. **Never stop after one Grep.** Run at least 2 rounds with expanded keywords.
2. **When a hit seems wrong**, read the file to understand its actual topic before dismissing it.
3. **File titles are NOT reliable indicators of content.** A file about 龙井茶 may contain the alcohol discussion you're looking for.
4. **Context from one file feeds the next search.** If you discover a file is about topic X, add X-related terms to your next search round.
5. **Always search both root and other-memory/ directories.**
6. **Exhaust sub-locations.** "安徽" means searching 合肥+芜湖+蚌埠+...+宣城 (all 16 cities). Never stop at the first city hit.
7. **Verify quotes before citing.** If a quote contains a location keyword as an EXAMPLE in a general statement (e.g., "二三线城市比如蚌埠"), it does NOT mean the recommendation was for that city. Read the full context.
8. **No first-hit conclusion.** The first match is a candidate, not the answer. Exhaust all candidates, then compare and select the correct one.
