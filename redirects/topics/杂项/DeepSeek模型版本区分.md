# DeepSeek模型版本区分

**分类**：杂项
**来源**：DeepSeek Chat 导出
**来源平台**：DeepSeek
**原始文件**：DeepSeek API PowerShell 中文乱码解决方案.md
**包含轮次**：17 - 17

---

# 用户：
你这个好像只有deepseek-chat，没有deepseek-reasoner吧

# DeepSeek：

**原始回答**
您说得对！我注意到了问题。在您的配置文件中，`Invoke-DeepSeek` 函数确实有 `deepseek-reasoner` 参数，但是 `ds` 函数的定义中没有正确传递这个参数。

## 🚀 正确的修复方案

在配置文件末尾添加**完整的 `ds` 函数**：

```powershell
# 创建完整的 ds 函数别名
function ds {
    param(
        [Parameter(Mandatory=$true)]
        [string]$Query,
        
        [ValidateSet("deepseek-chat", "deepseek-reasoner")]
        [string]$Model = "deepseek-chat",
        
        [int]$MaxTokens = 4000,
        [double]$Temperature = 0.7,
        [switch]$Reset,
        [switch]$NoHistory
    )
    
    Invoke-DeepSeek -Question $Query -Model $Model -MaxTokens $MaxTokens -Temperature $Temperature -Reset:$Reset -NoHistory:$NoHistory
}

# 同时为测试函数也创建别名
function testds {
    param([string]$Question = "Hello")
    Test-DeepSeekSimple -Question $Question
}
```

## 🎯 现在您可以这样使用：

```powershell
# 使用默认模型 (deepseek-chat)
ds "请用中文介绍你自己" -NoHistory

# 使用 reasoner 模型
ds "请用中文介绍你自己" -Model "deepseek-reasoner" -NoHistory

# 使用测试命令
testds "Hello"
testds "你好"
```

## 💡 或者使用真正的别名（更简洁）

如果您更喜欢纯粹的别名方式：

```powershell
# 创建真正的别名（但需要注意参数传递）
Set-Alias -Name ds -Value Invoke-DeepSeek
Set-Alias -Name testds -Value Test-DeepSeekSimple

# 但是这样使用时需要指定参数名
ds -Question "请用中文介绍你自己" -Model "deepseek-reasoner" -NoHistory
```

## 🔧 推荐使用函数包装器

我推荐使用**函数包装器**（第一个方案），因为：
- ✅ 支持所有参数自动传递
- ✅ 保持与 `Invoke-DeepSeek` 相同的使用方式
- ✅ 支持位置参数（`ds "你好"` 而不需要 `-Question "你好"`）

**请将完整的函数定义添加到配置文件末尾，然后重新加载即可！**

