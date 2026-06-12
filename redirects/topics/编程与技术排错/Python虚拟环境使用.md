# Python虚拟环境使用

编程与技术排错
**来源**: DeepSeek Chat 导出
**来源平台**: DeepSeek

---

# 用户：

如何使用虚拟环境运行，我不想在一次次装库了

# DeepSeek：

**原始回答**

# 使用虚拟环境管理Python项目

虚拟环境可以让你为每个项目创建独立的Python环境，避免库版本冲突，也便于管理依赖。以下是详细的使用方法：

## 方法1：使用venv（Python内置，推荐）

### 1. 创建虚拟环境

打开命令提示符，导航到你的项目目录：

```bash
cd D:\PycharmProjects\fun
python -m venv venv
```

这会在项目目录下创建一个名为`venv`的虚拟环境文件夹。

### 2. 激活虚拟环境

**Windows (命令提示符):**
```bash
venv\Scripts\activate
```

**Windows (PowerShell):**
```bash
venv\Scripts\Activate.ps1
```

激活后，命令提示符前面会显示`(venv)`，表示你正在虚拟环境中。

### 3. 在虚拟环境中安装所有需要的库

```bash
pip install requests rich psutil feedparser keyboard
```

### 4. 使用虚拟环境运行脚本

```bash
python observe.py
```

### 5. 退出虚拟环境

```bash
deactivate
```

## 方法2：使用PyCharm内置的虚拟环境

### 1. 创建虚拟环境

1. 打开PyCharm
2. 进入 `File` → `Settings` → `Project: fun` → `Python Interpreter`
3. 点击右上角的齿轮图标，选择 `Add...`
4. 在左侧选择 `Virtualenv Environment`
5. 选择位置（通常默认在项目目录下）
6. 点击 `OK`

### 2. 安装库

在PyCharm的Python解释器设置中，点击`+`号，然后一次性安装所有需要的库：
- requests
- rich
- psutil
- feedparser
- keyboard

### 3. 运行脚本

直接在PyCharm中运行你的脚本，它会自动使用虚拟环境。

## 方法3：使用requirements.txt管理依赖

### 1. 创建requirements.txt文件

在项目根目录创建`requirements.txt`文件，内容如下：
```
requests
rich
psutil
feedparser
keyboard
```

### 2. 使用requirements.txt安装所有依赖

激活虚拟环境后，运行：
```bash
pip install -r requirements.txt
```

### 3. 导出当前环境的依赖

如果你已经在虚拟环境中安装好了所有库，可以导出依赖列表：
```bash
pip freeze > requirements.txt
```

## 方法4：使用conda虚拟环境（如果你使用Anaconda/Miniconda）

### 1. 创建conda环境
```bash
conda create -n myenv python=3.8
```

### 2. 激活环境
```bash
conda activate myenv
```

### 3. 安装包
```bash
conda install requests rich psutil feedparser keyboard
```
或使用pip：
```bash
pip install requests rich psutil feedparser keyboard
```

## 虚拟环境常用命令

```bash
# 创建虚拟环境
python -m venv 环境名称

# 激活虚拟环境 (Windows)
环境名称\Scripts\activate

# 激活虚拟环境 (Mac/Linux)
source 环境名称/bin/activate

# 退出虚拟环境
deactivate

# 查看已安装的包
pip list

# 安装包
pip install 包名

# 从requirements.txt安装
pip install -r requirements.txt

# 导出当前环境依赖
pip freeze > requirements.txt

# 删除虚拟环境（直接删除文件夹即可）
rm -rf 环境名称  # Linux/Mac
# 或直接删除文件夹 (Windows)
```

## 在PyCharm中设置虚拟环境

1. 打开 `File` → `Settings` → `Project: fun` → `Python Interpreter`
2. 点击右上角齿轮图标，选择 `Add...`
3. 选择 `Existing environment`
4. 浏览到你的虚拟环境中的Python解释器：
   `D:\PycharmProjects\fun\venv\Scripts\python.exe`

## 建议的工作流程

1. 为每个项目创建独立的虚拟环境
2. 使用`requirements.txt`记录项目依赖
3. 将`venv/`文件夹添加到`.gitignore`中（不要将虚拟环境提交到版本控制）
4. 将`requirements.txt`提交到版本控制

这样，其他人在克隆你的项目后，只需要创建虚拟环境并运行`pip install -r requirements.txt`就可以获得所有依赖。

现在你可以创建一个虚拟环境，一次性安装所有需要的库，然后在这个环境中开发和运行你的项目，不再需要反复安装库了！
