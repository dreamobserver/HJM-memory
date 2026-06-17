# FACT.md — CherryClaw 持久知识

## 思考链语言（2026-06-17 确立）
- 哈基米的所有思考链（thinking chain）必须使用**简体中文**输出
- 原因：陛下是中文用户，英文思考链不便于快速理解 Agent 的推理过程

## 文件组织规范（2026-06-10 确立）
- **根目录 `F:/HJM-memory/`**：仅存放 Gemini 历史导出（120+ .md，只读，用于搜索）
- **`result/`**：CherryClaw 生成的所有新文件（SOUL.md、session、分析报告等）
- **`sessions/`**：增量对话片段存档（cron 自动留存，segment 格式）
- **新会话启动**：先扫描 `result/` 了解最新状态
- **原因**：生成文件混入根目录会浪费 Grep/搜索 token

## CherryClaw 身份文件
- SOUL.md → `F:/HJM-memory/result/SOUL.md`（哈基米人格）
- USER.md → `F:/HJM-memory/USER.md`（陛下画像，保持在根目录，由系统预加载）

## 当前活跃 Cron 作业
| 名称 | 频率 | 用途 |
|---|---|---|
| hjm-memory-daily-push | 每天 17:20 UTC | 生成每日总结 → 推送 HJM-memory 到 GitHub |
| hjm-conversation-save | 每 30 分钟 | 增量存档：只保存新增轮次到 sessions/segment-*.md，含原文+摘要，无新增则跳过，绝不重复 |

## 会话存档
- 增量格式：`sessions/segment-YYYY-MM-DD-N.md`（cron 自动生成，含摘要+原文）
- 完整格式：`result/session-YYYY-MM-DD-N.md`（手动/大事件触发）
- 每日总结：`result/daily-YYYY-MM-DD.md`（每日 17:20 UTC cron 自动生成）
- MEMORY.md 索引同步更新

## Cherry Studio 升级须知
- 升级可能导致对话线程丢失（已发生一次）
- Skills 独立存储不受影响
- 关键文件在 `F:/HJM-memory/` 不受影响
- 建议重要对话及时手动存档
