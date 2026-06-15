---
name: memory-search
description: Perform deep associative retrieval across the HJM personal memory archive. Use this skill when a direct HJM search is incomplete, when a conversation changed topics, when filenames are misleading, when the user tests recall, or when several past projects and aliases must be connected before answering.
---

# HJM Associative Memory Search

Perform multi-pass retrieval across `F:/HJM-memory/`, prioritizing
`redirects-v4` while verifying important details against `raw-memory`.

## Why this skill exists

Original conversations frequently drift across unrelated topics. File titles
may describe only the opening topic, and even semantic slices can have imperfect
classification. Retrieval must therefore combine metadata, exact vocabulary,
aliases, actions, objects, chronology, and source verification.

## Search order

1. `redirects-v4/**/*.md`
2. `raw-memory/{DeepSeek,Gemini}/**/*.md`
3. `redirects-v3/**/*.md`
4. `sessions/`, `result/`, `MEMORY.md`, and legacy `redirects/`

## Multi-pass workflow

### Pass 1: Direct and metadata search

Search exact terms plus likely aliases in:

- filenames;
- titles;
- tags;
- summaries and conclusions;
- `source_file`;
- `project_id`;
- original dialogue.

Collect several candidates. The first match is not automatically the answer.

### Pass 2: Scenario expansion

Expand from the scenario to vocabulary likely to appear in the actual
conversation:

- actions the user performed;
- concrete objects or devices;
- commands and error codes;
- brands, models, locations, and alternate names;
- symptoms, measurements, and outcomes.

Examples:

| Query | Useful expansion |
|---|---|
| 眼睛 | OCT, 黄斑, 眼底出血, 抗VEGF, 注药, 眼压 |
| 相机替换 | 大恒, Galaxy SDK, KSJ, DLL, OpenDevice, Ghidra |
| 酒馆限流 | SillyTavern, 429, RPM, Gemini API, 凭证冷却 |
| PowerShell AI | PROFILE, UTF-8, Invoke-RestMethod, DeepSeek API |
| 服务器失联 | SSH, iptables, DROP, INPUT, 防火墙, 端口, 502 |

Prefer concrete vocabulary over broad synonyms such as “失败” or“有问题”.

### Pass 3: Context and chronology

For each strong candidate:

1. read the frontmatter, summary, conclusion, and relevant turns;
2. inspect neighboring slices from the same `source_file`;
3. follow valid previous/next links when they describe the same task;
4. compare dates and turn ranges;
5. search newly discovered terms in another pass.

Do not merge unrelated discussions merely because a broad `project_id` or
category matches. `source_file + turn range + actual task` is stronger evidence
than a project label.

### Pass 4: Original-source verification

Open the matching raw export when:

- exact quotes or commands are requested;
- an attachment determines meaning;
- summaries disagree;
- the topic is medical, legal, financial, or otherwise high stakes;
- a credential or precise configuration is needed;
- the slice title or classification looks suspicious.

Use the raw conversation as the authority for what was said. Old assistant
claims still require current verification when facts may have changed.

### Pass 5: Candidate comparison

Before answering, compare all plausible candidates:

- Does the location or date match?
- Is the keyword central or merely an example?
- Is this the user's statement or the assistant's statement?
- Is it the same project stage?
- Did a later conversation revise the conclusion?

Select the best-supported record and mention uncertainty where appropriate.

## Guardrails

- Never rely on directory classification alone.
- Never treat a broad project label as proof that two slices belong together.
- Never infer image contents without textual evidence.
- Never present an old assistant's flattering personality analysis as an
  objective diagnosis.
- Do not read every large source file wholesale; narrow by ranges and context.
- Preserve privacy in the response even though the archive itself is private:
  disclose stored secrets only when directly necessary.

## Result format

When useful, structure the answer as:

1. **Found record** - source platform, source file, and topic.
2. **Relevant memory** - concise reconstruction of what happened.
3. **Current assessment** - corrections, changed facts, or uncertainty.

If no reliable record is found, say so rather than fabricating recall.
