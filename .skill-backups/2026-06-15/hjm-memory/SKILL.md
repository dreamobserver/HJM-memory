---
name: hjm-memory
description: Search and load HJM memory files — past Gemini chat exports covering AI news, physics experiments, creative writing, tech troubleshooting, and life tips. Use when the user references past conversations, asks "do you remember", or needs context from previous discussions stored in F:/HJM-memory/.
---

# HJM Memory Search

Search through the user's exported Gemini chat history stored at `F:/HJM-memory/`.

## Memory Structure

- **`F:/HJM-memory/MEMORY.md`** — Topic-based index of all 115+ memory files. Always read this first to find relevant files.
- **`F:/HJM-memory/*.md`** (33 files) — Named topic files, each is a Gemini chat export with Turn 1, Turn 2... format.
- **`F:/HJM-memory/other-memory/chat(N).md`** (81 files) — Numbered chat exports with descriptive H1 titles.
- **`F:/HJM-memory/other-memory/assets/`** — Referenced images.
- **`F:/HJM-memory/sessions/`** — Auto-saved CherryClaw conversations (30-message threshold).

## Workflow

### Step 1: Identify relevant files

Use Grep to search for keywords across the memory files:

```
Grep pattern="<keyword>" path="F:/HJM-memory" glob="*.md" output_mode="files_with_matches"
```

Or read `F:/HJM-memory/MEMORY.md` to browse by topic category:
- AI 动态与行业新闻
- AI 工具与酒馆
- DeepSeek 专题
- 光学/物理实验
- 编程/技术排错
- 创意写作/网文设定
- 生活百科/消费指南
- 杂项

### Step 2: Load relevant files

Read the matched files with Read tool. Focus on the Turn sections that relate to the user's query. Files can be large (some 400K+), so use offset/limit to read specific sections.

### Step 3: Synthesize context

Answer based on what you find. If a past conversation is directly relevant, quote the key exchange. If the memory contradicts current facts, note the discrepancy and trust current information.

## Important Rules

- Always check MEMORY.md first for topic categorization before doing blind keyword search
- Memory files are Gemini exports — the "🤖 Assistant" is the old Gemini-based 哈基米, not you
- All dates are in the file headers; note when information may be outdated
- Files in `other-memory/` have both a number AND a title H1 — use the title for relevance judgment
- Do NOT read entire large files (>100K) into context; use offset/limit strategically
