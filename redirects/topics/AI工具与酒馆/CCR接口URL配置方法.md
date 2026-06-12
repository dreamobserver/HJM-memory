# CCR接口URL配置方法

**分类**: AI工具与酒馆
**来源**: DeepSeek Chat 导出
**来源平台**: DeepSeek

---

# 用户：

ccr要我填下Enter Provider URL:该怎么写

# DeepSeek：

**原始回答**

当 CCR 提示 `Enter Provider URL:` 时，这是要求您输入 **API 的基础 URL**。

对于 **ModelScope（莫凡）**，您可以直接按 **Enter 键留空**，或者输入以下标准 URL：

```
https://dashscope.aliyun.com
```

### 具体操作步骤：

1. **当看到提示 `Enter Provider URL:` 时**：
   - 直接按 **Enter 键**（使用默认值或留空）
   - 或者输入：`https://dashscope.aliyun.com`

2. **接下来可能会询问其他配置**：
   - `Enter API Key/Token:` → 输入您的 ModelScope API 令牌（`ms-c4bdf950-baa9-482a-a4bc-9c60c1e2505a`）
   - `Enter Model Name:` → 输入模型名称（如 `qwen-max`）

### 更简单的解决方案：

为了避免交互式配置的麻烦，我建议使用**命令行参数一次性完成配置**，这是最可靠的方法：

```powershell
ccr start --api-type modelscope --api-token "ms-c4bdf950-baa9-482a-a4bc-9c60c1e2505a" --model "qwen-max" --api-base-url "https://dashscope.aliyun.com"
```

或者更简单，因为 ModelScope 通常可以自动识别基础 URL：

```powershell
ccr start --api-type modelscope --api-token "ms-c4bdf950-baa9-482a-a4bc-9c60c1e2505a" --model "qwen-max"
```

这样就能跳过所有交互式提问，直接启动服务。
