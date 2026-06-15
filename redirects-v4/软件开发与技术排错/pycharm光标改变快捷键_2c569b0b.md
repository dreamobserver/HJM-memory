---
title: "pycharm光标改变快捷键"
source_platform: "DeepSeek"
source_file: "PyCharm光标模式切换快捷键.md"
turn_start: 1
turn_end: 3
primary_category: "软件开发与技术排错"
tags:
  - "端口映射"
  - "软件开发"
project_id: "d91ccda415-software-01"
stage: "阶段1/3"
previous_slice: null
next_slice: "为什么数组会多出一个元素_3eb16f24.md"
has_attachment: false
attachment_context_confidence: not_applicable
classification_confidence: 0.97
---

# pycharm光标改变快捷键

## 问题摘要

本切片围绕“pycharm光标改变快捷键”展开。起始诉求是：pycharm光标改变快捷键 后续进展或反馈是：为什么会索引越界内容覆盖原始对话 T1-T3。

## 原始对话

# 用户：

pycharm光标改变快捷键

# DeepSeek：

**原始回答**

在 PyCharm 中，与**光标模式切换**（插入模式 ↔ 覆盖模式）相关的默认快捷键如下：

### 1. 切换插入/覆盖模式 (Insert/Overwrite)
- **默认快捷键**：  
  - **Windows/Linux**：`Insert` 键  
  - **macOS**：`fn` + `Enter`（或外接键盘的 `Insert` 键）  

  按下后，光标会从竖线 `|`（插入模式）变为方块 `█`（覆盖模式），输入时会替换已有文本。

---

### 2. 自定义快捷键（如需修改）
若需修改此快捷键：
1. **打开设置**：  
   - **Windows/Linux**：`File` → `Settings`  
   - **macOS**：`PyCharm` → `Preferences`  
2. **导航到快捷键设置**：  
   `Keymap` → 搜索 `Toggle Overwrite Mode`  
3. **绑定新快捷键**：  
   右键点击操作 → `Add Keyboa

插入模式（竖线光标）。

# 用户：

为什么代码没有办法正确计算斐波那契数列import array
def get_num():
    try:
        num_getted=int(input("请输入，n个斐波那契数列的n=：").strip())
        if num_getted :
            return num_getted
        print("输入无效！n必须大于等于0!")
    except ValueError:
        print("输入无效！请输入有效数字！")
def fib(n):
    fib_list = [1]
    try:
        if n == 2:
            fib_list.append(1)
            return fib_list
        elif n > 2:
            fib_list.append(1)
            for i in range(1,n):
                fib_list_value=fib_list[i-3]+fib_list[i-2]
                fib_list.append(fib_list_value)
            return fib_list
        elif n == 1:
            return fib_list
    except ValueError:
        print("计算失败！")
user_num = get_num()
user_fib_array = fib(user_num)
print(f"计算完成！前{user_num}个斐波那契数列为{user_fib_array}")

# DeepSeek：

**原始回答**

您的代码中存在几个问题，导致斐波那契数列计算不正确。以下是主要问题和修复方案：

### 主要问题分析：
1. **索引错误**：
   - 在循环中使用了 `fib_list[i-3] + fib_list[i-2]`，这会导致索引越界
   - 正确的计算应该是当前最后两个元素相加：`fib_list[-1] + fib_list[-2]`

2. **初始值处理**：
   - 斐波那契数列通常定义为：F(0)=0, F(1)=1 或 F(1)=1, F(2)=1
   - 您的代码从[1]开始，但未包含0，且对n=1的处理不符合常规

3. **输入验证**：
   - 当输入0时，`get_num()` 函数会拒绝（因为 `if num_getted` 将0视为False）
   - 未处理负数输入

### 修复后的代码：
```python
def get_num():
    while True:
        try:
            num = int(input("请输入要生成的斐波那契数列项数 n = 

# 第2项
> ```

# 用户：

为什么会索引越界

# DeepSeek：

**原始回答**

索引越界错误在您的原始代码中发生在斐波那契计算部分，具体原因如下：

### 问题根源分析

1. **错误的索引计算**：
   ```python
   fib_list_value = fib_list[i-3] + fib_list[i-2]
   ```
   当 `i=1` 时：
   - `i-3 = 1-3 = -2`
   - `i-2 = 1-2 = -1`
   这会尝试访问列表末尾的元素（负索引在Python中是有效的）

   但当 `i=2` 时：
   - `i-3 = 2-3 = -1`
   - `i-2 = 2-2 = 0`
   这会访问索引0和最后一个元素

   当 `i=3` 时：
   - `i-3 = 0`
   - `i-2 = 1`
   这会访问索引0和1

2. **真正的问题在于循环范围和初始条件**：
   - 您初始化了 `fib_list = [1]`
   - 当 `n>2` 时，您又添加了一个元素：`fib_list.append(1)` → 现在列表有2个元素
   -

## 关键结论

原对话最后阶段给出的主要判断或处理方向：原始回答** 索引越界错误在您的原始代码中发生在斐波那契计算部分，具体原因如下： 问题根源分析 1. **错误的索引计算**： 当 `i=1` 时： `i-3 = 1-3 = -2` `i-2 = 1-2 = -1` 这会尝试访问列表末尾的元素（负索引在Python中是有效的） 但当 `i=2` 时： `i-3 = 2-3 = -1` `i-2 = 2-2 = 0` 这会访问索引0和最后一个元素 当 `i=3` 时： `i-3 = 0` `i-2 = 1` 这会访问索引0和1 2. **真正的问题在于循环范围和初始条件**： 您初始化了 `fib_list = [1]` 当 `n>2` 时，您又添加了一个元素：`fib_list.append(1)` → 现在列表有2个元素

## 上下文关系

- 所属项目：d91ccda415-software-01
- 当前阶段：阶段1/3
- 前置切片：无
- 后续切片：为什么数组会多出一个元素_3eb16f24.md
- 附件说明：无
