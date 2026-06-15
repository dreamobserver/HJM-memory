---
title: "Python环境缺少FastAPI库故障排查"
source_platform: "DeepSeek"
source_file: "Python环境缺少FastAPI库.md"
turn_start: 1
turn_end: 5
primary_category: "软件开发与技术排错"
tags:
  - "状态栏"
  - "端口映射"
project_id: "b9a592c19c-software-01"
stage: "独立主题"
previous_slice: null
next_slice: null
has_attachment: false
attachment_context_confidence: not_applicable
classification_confidence: 0.97
---

# Python环境缺少FastAPI库故障排查

## 问题摘要

本切片围绕“Python环境缺少FastAPI库故障排查”展开。起始诉求是：(gcli2api) C:\Users\Aaron Kwo'k\gcli2api>python web.py Traceback (most recent call last): File "C:\Users\Aaron Kwo'k\gcli2api\web.py", line… 后续进展或反馈是：┏[ 11/17/2025 @ 9:35:12 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 10/15GB][ 98][ 0.915s] ┣[ gcli2api] ┣[ ~\gcli2api][ master ≡]…内容覆盖原始对话 T1-T5。

## 原始对话

# 用户：

(gcli2api) C:\Users\Aaron Kwo'k\gcli2api>python web.py
Traceback (most recent call last):
  File "C:\Users\Aaron Kwo'k\gcli2api\web.py", line 8, in <module>
    from fastapi import FastAPI, Response
ModuleNotFoundError: No module named 'fastapi'

(gcli2api) C:\Users\Aaron Kwo'k\gcli2api>pause
请按任意键继续. . .



这个错误数是否是因为用户名有特殊符号导致的

# DeepSeek：

**原始回答**

这个错误**不是**由于用户名中的特殊符号导致的。

错误信息 `ModuleNotFoundError: No module named 'fastapi'` 表明你的 Python 环境中没有安装 FastAPI 库。

## 解决方案：

### 1. 安装 FastAPI
在你的虚拟环境 `(gcli2api)` 中运行以下命令：

```bash
pip install fastapi
```

### 2. 安装 ASGI 服务器
你还需要安装一个 ASGI 服务器来运行 FastAPI 应用，推荐安装 uvicorn：

```bash
pip install "uvicorn[standard]"
```

### 3. 或者一次性安装所有依赖
```bash
pip install fastapi uvicorn
```

### 4. 如果使用 requirements.txt
如果你有 `requirements.txt` 文件，可以运行：
```bash
pip install -r requirements.tx

 应该就能正常运行了。

# 用户：

oduleNotFoundError: No module named 'starlette'
┏[ 11/17/2025 @ 9:17:11 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 11/15GB][ 96][ 21.191s]
┣[ gcli2api]
┣[ ~\gcli2api][ master ≡]
└─[#]> pip install -r requirements.txt
pip: The term 'pip' is not recognized as a name of a cmdlet, function, script file, or executable program.
Check the spelling of the name, or if a path was included, verify that the path is correct and try again.
┏[ 11/17/2025 @ 9:32:25 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 10/15GB][ 98][ 0.114s]
┣[ gcli2api]
┣[ ~\gcli2api][ master ≡]
└─[#][ Error, check your command]> pip install -r requirements.txt
pip: The term 'pip' is not recognized as a name of a cmdlet, function, script file, or executable program.
Check the spelling of the name, or if a path was included, verify that the path is correct and try again.
┏[ 11/17/2025 @ 9:32:42 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 10/15GB][ 98][ 0.06s]
┣[ gcli2api]
┣[ ~\gcli2api][ master ≡]
└─[#][ Error, check your command]> pip install fastapi uvicorn
pip: The term 'pip' is not recognized as a name of a cmdlet, function, script file, or executable program.
Check the spelling of the name, or if a path was included, verify that the path is correct and try again.继续解答

# DeepSeek：

**原始回答**

现在的问题是 `pip` 命令无法识别，这表明你的 Python 环境配置有问题。让我们逐步解决：

## 解决方案：

### 1. 检查虚拟环境是否激活
首先确认虚拟环境是否已正确激活：

```bash
# 检查 Python 版本
python --version

# 检查 pip 是否可用
python -m pip --version
```

### 2. 使用 python -m pip 安装
既然直接使用 `pip` 不行，可以使用 Python 模块方式：

```bash
# 安装 FastAPI 和依赖
python -m pip install fastapi uvicorn

# 或者安装 requirements.txt
python -m pip install -r requirements.txt
```

### 3. 重新创建虚拟环境（如果上述方法失败）
如果虚拟环境有问题，可以重新创建：

```bash
# 退出当前虚拟环境
deactivate

# 删除旧的虚拟环境（可选）
rmdir /

请告诉我具体错误信息。

# 用户：

安装时也报错[ 11/17/2025 @ 9:34:27 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 10/15GB][ 98][ 0.041s]
┣[ gcli2api]
┣[ ~\gcli2api][ master ≡]
└─[#][ Error, check your command]> iex (iwr "https://raw.githubusercontent.com/su-kaka/gcli2api/refs/heads/master/install.ps1" -UseBasicParsing).Content
Scoop is already installed. Skipping installation.
Resolved 63 packages in 1ms
error: Failed to install: asyncpg-0.30.0-cp312-cp312-win_amd64.whl (asyncpg==0.30.0)
  Caused by: The wheel is invalid: Headers were followed by an unexpected lone CR character!
Traceback (most recent call last):
  File "C:\Users\Aaron Kwo'k\gcli2api\web.py", line 8, in <module>
    from fastapi import FastAPI, Response
  File "C:\Users\Aaron Kwo'k\gcli2api\.venv\Lib\site-packages\fastapi\__init__.py", line 7, in <module>
    from .applications import FastAPI as FastAPI
  File "C:\Users\Aaron Kwo'k\gcli2api\.venv\Lib\site-packages\fastapi\applications.py", line 17, in <module>
    from fastapi import routing
  File "C:\Users\Aaron Kwo'k\gcli2api\.venv\Lib\site-packages\fastapi\routing.py", line 28, in <module>
    from fastapi import params, temp_pydantic_v1_params
  File "C:\Users\Aaron Kwo'k\gcli2api\.venv\Lib\site-packages\fastapi\params.py", line 6, in <module>
    from fastapi.openapi.models import Example
  File "C:\Users\Aaron Kwo'k\gcli2api\.venv\Lib\site-packages\fastapi\openapi\models.py", line 4, in <module>
    from fastapi._compat import (
  File "C:\Users\Aaron Kwo'k\gcli2api\.venv\Lib\site-packages\fastapi\_compat\__init__.py", line 1, in <module>
    from .main import BaseConfig as BaseConfig
  File "C:\Users\Aaron Kwo'k\gcli2api\.venv\Lib\site-packages\fastapi\_compat\main.py", line 12, in <module>
    from fastapi._compat import may_v1
  File "C:\Users\Aaron Kwo'k\gcli2api\.venv\Lib\site-packages\fastapi\_compat\may_v1.py", line 4, in <module>
    from fastapi.types import ModelNameMap
  File "C:\Users\Aaron Kwo'k\gcli2api\.venv\Lib\site-packages\fastapi\types.py", line 5, in <module>
    from pydantic import BaseModel
  File "C:\Users\Aaron Kwo'k\gcli2api\.venv\Lib\site-packages\pydantic\__init__.py", line 5, in <module>
    from ._migration import getattr_migration
  File "C:\Users\Aaron Kwo'k\gcli2api\.venv\Lib\site-packages\pydantic\_migration.py", line 4, in <module>
    from pydantic.warnings import PydanticDeprecatedSince20
  File "C:\Users\Aaron Kwo'k\gcli2api\.venv\Lib\site-packages\pydantic\warnings.py", line 5, in <module>
    from .version import version_short
  File "C:\Users\Aaron Kwo'k\gcli2api\.venv\Lib\site-packages\pydantic\version.py", line 7, in <module>
    from pydantic_core import __version__ as __pydantic_core_version__
  File "C:\Users\Aaron Kwo'k\gcli2api\.venv\Lib\site-packages\pydantic_core\__init__.py", line 6, in <module>
    from typing_extensions import Sentinel
ModuleNotFoundError: No module named 'typing_extensions'
┏[ 11/17/2025 @ 9:35:12 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 10/15GB][ 98][ 0.915s]
┣[ gcli2api]
┣[ ~\gcli2api][ master ≡]
└─[#]>

# DeepSeek：

**原始回答**

看起来安装过程中出现了多个问题。让我们一步步解决：

## 问题分析：
1. Scoop 安装 asyncpg 时出现 wheel 文件损坏
2. 缺少 `typing_extensions` 模块
3. 依赖包安装不完整

## 解决方案：

### 1. 首先修复虚拟环境中的依赖
```bash
# 安装缺失的 typing_extensions
python -m pip install typing_extensions

# 然后重新安装关键依赖
python -m pip install --force-reinstall pydantic fastapi starlette
```

### 2. 如果上述方法失败，清理并重新安装
```bash
# 清理当前安装的包
python -m pip uninstall fastapi uvicorn starlette pydantic asyncpg -y

# 重新安装，使用国内镜像源加速
python -m pip install -i https://pypi.tuna

告诉我具体的错误信息。

# 用户：

[ 11/17/2025 @ 9:35:12 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 10/15GB][ 98][ 0.915s]
┣[ gcli2api]
┣[ ~\gcli2api][ master ≡]
└─[#]> # 安装缺失的 typing_extensions
┏[ 11/17/2025 @ 9:39:09 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 11/15GB][ 100][ 0s]
┣[ gcli2api]
┣[ ~\gcli2api][ master ≡]
└─[#]> python -m pip install typing_extensions
C:\Users\Aaron Kwo'k\gcli2api\.venv\Scripts\python.exe: No module named pip
┏[ 11/17/2025 @ 9:39:09 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 11/15GB][ 100][ 0.041s]
┣[ gcli2api]
┣[ ~\gcli2api][ master ≡]
└─[#][ Error, check your command]>
┏[ 11/17/2025 @ 9:39:09 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 11/15GB][ 100][ 0s]
┣[ gcli2api]
┣[ ~\gcli2api][ master ≡]
└─[#][ Error, check your command]> # 然后重新安装关键依赖
┏[ 11/17/2025 @ 9:39:09 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 11/15GB][ 100][ 0s]
┣[ gcli2api]
┣[ ~\gcli2api][ master ≡]
└─[#][ Error, check your command]> python -m pip install --force-reinstall pydantic fastapi starlette
C:\Users\Aaron Kwo'k\gcli2api\.venv\Scripts\python.exe: No module named pip
┏[ 11/17/2025 @ 9:39:10 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 11/15GB][ 100][ 0.039s]
┣[ gcli2api]
┣[ ~\gcli2api][ master ≡]
└─[#][ Error, check your command]>

# DeepSeek：

**原始回答**

现在的问题是虚拟环境中没有安装 `pip`。这通常发生在虚拟环境创建不完整的情况下。让我们解决这个问题：

## 解决方案：

### 1. 重新创建虚拟环境（推荐）
```bash
# 退出当前虚拟环境
deactivate

# 删除有问题的虚拟环境
rmdir /s .venv

# 重新创建虚拟环境
python -m venv .venv

# 激活虚拟环境
.venv\Scripts\activate

# 现在应该可以正常使用 pip 了
python -m pip install --upgrade pip
python -m pip install fastapi uvicorn
```

### 2. 如果重新创建虚拟环境失败，尝试直接使用系统 Python
```bash
# 退出虚拟环境
deactivate

# 直接使用系统 Python 安装（不推荐长期使用，但可以临时解决问题）
pip install fastapi uvicorn typing_extensions

# 然后运行你的应用
python 

告诉我具体的错误信息。

# 用户：

┏[ 11/17/2025 @ 9:35:12 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 10/15GB][ 98][ 0.915s]
┣[ gcli2api]
┣[ ~\gcli2api][ master ≡]
└─[#]> # 安装缺失的 typing_extensions
┏[ 11/17/2025 @ 9:39:09 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 11/15GB][ 100][ 0s]
┣[ gcli2api]
┣[ ~\gcli2api][ master ≡]
└─[#]> python -m pip install typing_extensions
C:\Users\Aaron Kwo'k\gcli2api\.venv\Scripts\python.exe: No module named pip
┏[ 11/17/2025 @ 9:39:09 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 11/15GB][ 100][ 0.041s]
┣[ gcli2api]
┣[ ~\gcli2api][ master ≡]
└─[#][ Error, check your command]>
┏[ 11/17/2025 @ 9:39:09 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 11/15GB][ 100][ 0s]
┣[ gcli2api]
┣[ ~\gcli2api][ master ≡]
└─[#][ Error, check your command]> # 然后重新安装关键依赖
┏[ 11/17/2025 @ 9:39:09 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 11/15GB][ 100][ 0s]
┣[ gcli2api]
┣[ ~\gcli2api][ master ≡]
└─[#][ Error, check your command]> python -m pip install --force-reinstall pydantic fastapi starlette
C:\Users\Aaron Kwo'k\gcli2api\.venv\Scripts\python.exe: No module named pip
┏[ 11/17/2025 @ 9:39:10 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 11/15GB][ 100][ 0.039s]
┣[ gcli2api]
┣[ ~\gcli2api][ master ≡]
└─[#][ Error, check your command]> # 退出当前虚拟环境
┏[ 11/17/2025 @ 9:40:03 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 11/15GB][ 100][ 0s]
┣[ gcli2api]
┣[ ~\gcli2api][ master ≡]
└─[#][ Error, check your command]> deactivate
┏[ 11/17/2025 @ 9:40:03 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 11/15GB][ 100][ 0.001s]
┣[ gcli2api]
┣[ ~\gcli2api][ master ≡]
└─[#]>
┏[ 11/17/2025 @ 9:40:03 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 11/15GB][ 100][ 0s]
┣[ gcli2api]
┣[ ~\gcli2api][ master ≡]
└─[#]> # 删除有问题的虚拟环境
┏[ 11/17/2025 @ 9:40:03 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 11/15GB][ 100][ 0s]
┣[ gcli2api]
┣[ ~\gcli2api][ master ≡]
└─[#]> rmdir /s .venv
Remove-Item: A positional parameter cannot be found that accepts argument '.venv'.
┏[ 11/17/2025 @ 9:40:03 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 11/15GB][ 100][ 0.016s]
┣[ gcli2api]
┣[ ~\gcli2api][ master ≡]
└─[#][ Error, check your command]>
┏[ 11/17/2025 @ 9:40:03 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 11/15GB][ 100][ 0s]
┣[ gcli2api]
┣[ ~\gcli2api][ master ≡]
└─[#][ Error, check your command]> # 重新创建虚拟环境
┏[ 11/17/2025 @ 9:40:03 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 11/15GB][ 100][ 0s]
┣[ gcli2api]
┣[ ~\gcli2api][ master ≡]
└─[#][ Error, check your command]> python -m venv .venv
┏[ 11/17/2025 @ 9:40:07 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 11/15GB][ 100][ 3.84s]
┣[ gcli2api]
┣[ ~\gcli2api][ master ≡]
└─[#]>
┏[ 11/17/2025 @ 9:40:08 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 11/15GB][ 100][ 0s]
┣[ gcli2api]
┣[ ~\gcli2api][ master ≡]
└─[#]> # 激活虚拟环境
┏[ 11/17/2025 @ 9:40:08 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 11/15GB][ 100][ 0s]
┣[ gcli2api]
┣[ ~\gcli2api][ master ≡]
└─[#]> .venv\Scripts\activate
┏[ 11/17/2025 @ 9:40:08 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 11/15GB][ 100][ 0.028s]
┣[ gcli2api]
┣[ ~\gcli2api][ master ≡]
└─[#]>
┏[ 11/17/2025 @ 9:40:08 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 11/15GB][ 100][ 0s]
┣[ gcli2api]
┣[ ~\gcli2api][ master ≡]
└─[#]> # 现在应该可以正常使用 pip 了
┏[ 11/17/2025 @ 9:40:08 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 11/15GB][ 100][ 0s]
┣[ gcli2api]
┣[ ~\gcli2api][ master ≡]
└─[#]> python -m pip install --upgrade pip
Requirement already satisfied: pip in c:\users\aaron kwo'k\gcli2api\.venv\lib\site-packages (25.2)
Collecting pip
  Downloading pip-25.3-py3-none-any.whl.metadata (4.7 kB)
Downloading pip-25.3-py3-none-any.whl (1.8 MB)
   ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 1.8/1.8 MB 12.0 MB/s  0:00:00
Installing collected packages: pip
  Attempting uninstall: pip
    Found existing installation: pip 25.2
    Uninstalling pip-25.2:
      Successfully uninstalled pip-25.2
Successfully installed pip-25.3
┏[ 11/17/2025 @ 9:40:12 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 11/15GB][ 100][ 3.898s]
┣[ gcli2api]
┣[ ~\gcli2api][ master ≡]
└─[#]> python -m pip install fastapi uvicorn
Requirement already satisfied: fastapi in c:\users\aaron kwo'k\gcli2api\.venv\lib\site-packages (0.121.2)
Collecting uvicorn
  Downloading uvicorn-0.38.0-py3-none-any.whl.metadata (6.8 kB)
Requirement already satisfied: starlette<0.50.0,>=0.40.0 in c:\users\aaron kwo'k\gcli2api\.venv\lib\site-packages (from fastapi) (0.49.3)
Requirement already satisfied: pydantic!=1.8,!=1.8.1,!=2.0.0,!=2.0.1,!=2.1.0,<3.0.0,>=1.7.4 in c:\users\aaron kwo'k\gcli2api\.venv\lib\site-packages (from fastapi) (2.12.4)
Collecting typing-extensions>=4.8.0 (from fastapi)
  Downloading typing_extensions-4.15.0-py3-none-any.whl.metadata (3.3 kB)
Requirement already satisfied: annotated-doc>=0.0.2 in c:\users\aaron kwo'k\gcli2api\.venv\lib\site-packages (from fastapi) (0.0.4)
Collecting annotated-types>=0.6.0 (from pydantic!=1.8,!=1.8.1,!=2.0.0,!=2.0.1,!=2.1.0,<3.0.0,>=1.7.4->fastapi)
  Downloading annotated_types-0.7.0-py3-none-any.whl.metadata (15 kB)
Requirement already satisfied: pydantic-core==2.41.5 in c:\users\aaron kwo'k\gcli2api\.venv\lib\site-packages (from pydantic!=1.8,!=1.8.1,!=2.0.0,!=2.0.1,!=2.1.0,<3.0.0,>=1.7.4->fastapi) (2.41.5)
Requirement already satisfied: typing-inspection>=0.4.2 in c:\users\aaron kwo'k\gcli2api\.venv\lib\site-packages (from pydantic!=1.8,!=1.8.1,!=2.0.0,!=2.0.1,!=2.1.0,<3.0.0,>=1.7.4->fastapi) (0.4.2)
Requirement already satisfied: anyio<5,>=3.6.2 in c:\users\aaron kwo'k\gcli2api\.venv\lib\site-packages (from starlette<0.50.0,>=0.40.0->fastapi) (4.11.0)
Requirement already satisfied: idna>=2.8 in c:\users\aaron kwo'k\gcli2api\.venv\lib\site-packages (from anyio<5,>=3.6.2->starlette<0.50.0,>=0.40.0->fastapi) (3.11)
Requirement already satisfied: sniffio>=1.1 in c:\users\aaron kwo'k\gcli2api\.venv\lib\site-packages (from anyio<5,>=3.6.2->starlette<0.50.0,>=0.40.0->fastapi) (1.3.1)
Collecting click>=7.0 (from uvicorn)
  Downloading click-8.3.1-py3-none-any.whl.metadata (2.6 kB)
Collecting h11>=0.8 (from uvicorn)
  Downloading h11-0.16.0-py3-none-any.whl.metadata (8.3 kB)
Collecting colorama (from click>=7.0->uvicorn)
  Downloading colorama-0.4.6-py2.py3-none-any.whl.metadata (17 kB)
Downloading uvicorn-0.38.0-py3-none-any.whl (68 kB)
Downloading annotated_types-0.7.0-py3-none-any.whl (13 kB)
Downloading click-8.3.1-py3-none-any.whl (108 kB)
Downloading h11-0.16.0-py3-none-any.whl (37 kB)
Downloading typing_extensions-4.15.0-py3-none-any.whl (44 kB)
Downloading colorama-0.4.6-py2.py3-none-any.whl (25 kB)
Installing collected packages: typing-extensions, h11, colorama, annotated-types, click, uvicorn
ERROR: pip's dependency resolver does not currently take into account all the packages that are installed. This behaviour is the source of the following dependency conflicts.
hypercorn 0.18.0 requires h2>=4.3.0, which is not installed.
hypercorn 0.18.0 requires priority, which is not installed.
Successfully installed annotated-types-0.7.0 click-8.3.1 colorama-0.4.6 h11-0.16.0 typing-extensions-4.15.0 uvicorn-0.38.0
┏[ 11/17/2025 @ 9:40:16 AM CST][ Aaron Kwo'k ::  YIXIST2024][ RAM: 11/15GB][ 100][ 3.621s]

# DeepSeek：

**原始回答**

很好！现在虚拟环境已经重建成功，并且 FastAPI 和 Uvicorn 已经安装完成。虽然有一些依赖冲突的警告，但这不会影响基本功能。

## 测试安装是否成功：

```bash
# 测试 FastAPI 是否能正常导入
python -c "from fastapi import FastAPI; print('FastAPI 导入成功！')"

# 测试 Uvicorn 是否能正常导入
python -c "import uvicorn; print('Uvicorn 导入成功！')"
```

## 现在运行你的应用：

```bash
# 运行你的 web.py 文件
python web.py
```

如果一切正常，你应该能看到类似这样的输出：
```
INFO:     Started server process [xxxx]
INFO:     Waiting for application startup.
INFO:     Application startup complete.
INFO:     Uvic

## 关键结论

原对话最后阶段给出的主要判断或处理方向：测试安装是否成功： 现在运行你的应用： 如果一切正常，你应该能看到类似这样的输出： ``` INFO: Started server process [xxxx] INFO: Waiting for application startup. INFO: Application startup complete. INFO: Uvic

## 上下文关系

- 所属项目：b9a592c19c-software-01
- 当前阶段：独立主题
- 前置切片：无
- 后续切片：无
- 附件说明：无
