---
name: hjm-memory
description: Search and load the user's HJM personal memory archive. Use this skill whenever the user refers to an earlier DeepSeek/Gemini conversation, asks whether you remember something, wants continuity with a past project, or needs facts, decisions, commands, preferences, or context stored under F:/HJM-memory/.
---

# HJM Memory

Retrieve relevant context from `F:/HJM-memory/` without treating old model
answers as authoritative facts.

## Source priority

Use the highest available layer:

1. `F:/HJM-memory/redirects-v4/` - curated semantic slices and metadata.
2. `F:/HJM-memory/raw-memory/` - authoritative original exports for verification.
3. `F:/HJM-memory/redirects-v3/` - fallback while v4 is unavailable.
4. `F:/HJM-memory/MEMORY.md` and legacy `redirects/` - discovery fallback only.
5. `F:/HJM-memory/sessions/` and `result/` - recent CherryClaw sessions.

`redirects-v4` is an index over the originals, not a replacement for them.
When exact wording, chronology, attachments, credentials, or technical details
matter, verify against `raw-memory`.

## Fast workflow

### 1. Search metadata and text

Search `redirects-v4/**/*.md` for:

- exact terms and aliases;
- `source_file`, `project_id`, `tags`, and `primary_category`;
- commands, error codes, product names, device models, places, and people.

Do not assume the directory is correct merely because a file is stored there.
Use its title, summary, tags, source file, and original dialogue together.

### 2. Read the smallest useful slice

Read the matched slice's:

- frontmatter;
- `问题摘要`;
- `关键结论`;
- relevant portion of `原始对话`;
- `上下文关系`.

Follow `previous_slice` or `next_slice` only when the current question depends
on an earlier or later stage. Resolve links relative to the v4 root and verify
the target exists.

### 3. Verify when needed

Open the corresponding file in:

- `raw-memory/DeepSeek/`, or
- `raw-memory/Gemini/`

when the slice is ambiguous, contains an attachment, summarizes a high-stakes
topic, or appears inconsistent.

### 4. Answer with calibrated trust

Separate:

- what the user previously said or decided;
- what an old assistant claimed;
- what is currently verified;
- what remains uncertain or may be outdated.

Never convert an old assistant's speculation into a user fact.

## Retrieval rules

- Prefer task intent over literal keyword overlap.
- Search aliases: 酒馆/SillyTavern, 哈基米/Gemini, 小克/Claude,
  大恒/Galaxy SDK, 反重力/Antigravity.
- For a continuing project, search both the project name and its concrete
  objects, errors, commands, and equipment.
- Treat attachment-only turns as context-dependent. Use neighboring dialogue
  and the old assistant's textual description; do not invent unseen details.
- Avoid loading entire large files when a relevant slice or turn range is
  sufficient.
- Quote sparingly and preserve the distinction between User and Assistant.
- The archive is private personal memory. Do not censor stored credentials
  merely because they exist, but do not expose them unless the user's current
  request genuinely requires them.

## Fallback

If `redirects-v4` is missing or has no useful match:

1. search `redirects-v3`;
2. search `raw-memory` directly;
3. use `MEMORY.md` and legacy paths for discovery;
4. state when the archive contains no reliable answer.
