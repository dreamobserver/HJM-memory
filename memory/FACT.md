# FACT.md — CherryClaw 持久知识

## 信息检索纪律（2026-06-23 陛下训诫）
- **严禁 grep + 直接结论**：当用户要求从记忆库中提取观点/评分/立场时，必须通读相关切片/原文全文，不能只靠 grep 搜关键词就下判断
- **长上下文是优势不是摆设**：v4 切片已包含完整原文，应充分利用长上下文能力逐段阅读，而非偷懒用模式匹配替代
- **用户评分不一定是数字**：很多观点以推理段落形式存在，grep 搜 `[0-9]分` 搜不到不代表没有
- **修正流程**：grep 定位候选区域 → Read 展开上下文 → 确认无遗漏后再回答
- 教训来源：2026-06-23 声望幻觉与信息验证切片查询中，grep 搜数字评分未果即断言"无评分"，实则用户自评以推理段落形式存在于原文中，通读即可发现

## 主机名纠正（2026-06-22 陛下亲自指正）
- **LIGHT-AND-DUST** = 公司电脑（非私人电脑）
- **DOR-ASUS** = 私人笔记本（华硕天选 5 Pro）
- USER.md 中"私人主机名：LIGHT-AND-DUST"有误，已修正为"公司主机名"
- F:/HJM-memory/ 当前位于公司电脑 LIGHT-AND-DUST 上

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
