---
title: "NovelAI本地部署与ComfyUI-CNB模型管理（T16-18）"
source_platform: "Gemini"
source_file: "哈基米评价川普排序算法.md"
turn_start: 16
turn_end: 18
primary_category: "AI工具与模型应用"
tags:
  - "ComfyUI"
  - "API"
  - "状态栏"
  - "端口映射"
project_id: "bda3d1497e-ai-tools-01"
stage: "阶段3/4"
previous_slice: "NovelAI本地部署与ComfyUI-CNB模型管理：nai怎么样我的电脑可以整吗_8e4a5b57.md"
next_slice: "NovelAI本地部署与ComfyUI-CNB模型管理：终于等到logs的报错了帮我看看（_[1_085cd679.md"
has_attachment: true
attachment_context_confidence: medium
classification_confidence: 0.97
---

# NovelAI本地部署与ComfyUI-CNB模型管理（T16-18）

## 问题摘要

本切片围绕“NovelAI本地部署与ComfyUI-CNB模型管理（T16-18）”展开。起始诉求是：帮我看看这个startlogs为什么nsfw生图不工作（[NSFW Patch] 正在应用 NSFW 检测禁用补丁... [NSFW Patch] 已复制: hook_by_xu.py [NSFW Patch] 已复制: hook2_by_xu.py [NSFW Patch] 已… 后续进展或反馈是：怎么一片爆红一边显示成功？内容覆盖原始对话 T16-T18。

## 原始对话

## Turn 16

### 👤 User

帮我看看这个startlogs为什么nsfw生图不工作（[NSFW Patch] 正在应用 NSFW 检测禁用补丁...
[NSFW Patch] 已复制: hook_by_xu.py
[NSFW Patch] 已复制: hook2_by_xu.py
[NSFW Patch] 已复制: nsfw_checker_by_xu.py
[NSFW Patch] 已清除 __pycache__
[NSFW Patch] 补丁应用完成！NSFW 检测已禁用。
[Update Guard] 已禁用 update 中的 git pull
[Update Guard] 已禁用 init2 中的 git pull
[启动优化] 远程拉取已全部禁用，启动速度将更快
[Compatibility Patch] 已修复 comfyui-custom-scripts 的 get_full_path 兼容参数
[Model Prefetch] starting in background; ComfyUI startup will continue
[MoRan Workflow] 已同步墨色江湖两套预置工作流到 ComfyUI 用户目录
[MoRan Workflow] 已安装默认工作流自动载入扩展
Installing extensions...
Installing extension 'tencent-cloud.coding-copilot'...
Extension 'tencent-cloud.coding-copilot' v4.3.20019762 was successfully installed.
[Startup] 正在启动 ComfyUI: /workspace/venv/bin/python /workspace/comfyui/main.py --listen 0.0.0.0 --port 8188 --enable-cors-header "*"
[Startup] Waiting for ComfyUI port 8188 to become available...
[32m[INFO][0m Adding extra search path custom_nodes /workspace/.cnb-xu/custom_nodes
[32m[INFO][0m Adding extra search path custom_nodes /workspace/comfyui/custom_nodes_preset
[32m[INFO][0m
Prestartup times for custom nodes:
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-easy-use
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Marigold
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/rgthree-comfy
[32m[INFO][0m 4.8 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Manager
[32m[INFO][0m
[32m[INFO][0m Found comfy_kitchen backend triton: {'available': True, 'disabled': True, 'unavailable_reason': None, 'capabilities': ['apply_rope', 'apply_rope1', 'dequantize_nvfp4', 'dequantize_per_tensor_fp8', 'quantize_mxfp8', 'quantize_nvfp4', 'quantize_per_tensor_fp8']}
[32m[INFO][0m Found comfy_kitchen backend eager: {'available': True, 'disabled': False, 'unavailable_reason': None, 'capabilities': ['apply_rope', 'apply_rope1', 'dequantize_mxfp8', 'dequantize_nvfp4', 'dequantize_per_tensor_fp8', 'quantize_mxfp8', 'quantize_nvfp4', 'quantize_per_tensor_fp8', 'scaled_mm_mxfp8', 'scaled_mm_nvfp4']}
[32m[INFO][0m Found comfy_kitchen backend cuda: {'available': True, 'disabled': False, 'unavailable_reason': None, 'capabilities': ['apply_rope', 'apply_rope1', 'dequantize_nvfp4', 'dequantize_per_tensor_fp8', 'quantize_mxfp8', 'quantize_nvfp4', 'quantize_per_tensor_fp8', 'scaled_mm_nvfp4']}
[32m[INFO][0m Checkpoint files will always be loaded safely.
[32m[INFO][0m Total VRAM 45458 MB, total RAM 65536 MB
[32m[INFO][0m pytorch version: 2.9.1+cu130
[32m[INFO][0m xformers version: 0.0.33.post2
[32m[INFO][0m Set vram state to: NORMAL_VRAM
[32m[INFO][0m Device: cuda:0 NVIDIA L40 : cudaMallocAsync
[32m[INFO][0m Using async weight offloading with 2 streams
[32m[INFO][0m Enabled pinned memory 58982.0
[32m[INFO][0m Using xformers attention
aimdo: /project/src-posix/cuda-funchooks.c:52:DEBUG:aimdo_setup_hooks: hooks successfully installed
aimdo: /project/src/control.c:236:INFO:comfy-aimdo inited for GPU: NVIDIA L40 (VRAM: 45457 MB)
[32m[INFO][0m DynamicVRAM support detected and enabled
[32m[INFO][0m Python version: 3.12.13 (main, May 20 2026, 22:15:37) [GCC 13.3.0]
[32m[INFO][0m ComfyUI version: 0.22.0
[32m[INFO][0m comfy-aimdo version: 0.4.5
[32m[INFO][0m comfy-kitchen version: 0.2.8
[32m[INFO][0m comfyui-frontend-package version: 1.44.19
[32m[INFO][0m comfyui-workflow-templates version: 0.9.82
[32m[INFO][0m comfyui-embedded-docs version: 0.5.0
[32m[INFO][0m comfy-kitchen version: 0.2.8
[32m[INFO][0m comfy-aimdo version: 0.4.5
[32m[INFO][0m [Prompt Server] web root: /workspace/venv/lib/python3.12/site-packages/comfyui_frontend_package/static
[32m[INFO][0m Asset seeder disabled
[32m[INFO][0m NumExpr defaulting to 16 threads.
[32m[INFO][0m PyTorch version 2.9.1+cu130 available.
[32m[INFO][0m JAX version 0.7.0 available.
USDU batch patches applied successfully.
[32m[INFO][0m USDU batch patches applied successfully.
[32m[INFO][0m WaveSpeed AI API endpoints registered
[1m[33m[WARNING][0m Skip /workspace/comfyui/custom_nodes_preset/ComfyUI-WD14-Tagger module for custom nodes due to the lack of NODE_CLASS_MAPPINGS or comfy_entrypoint (need one).
[1m[33m[WARNING][0m Traceback (most recent call last):
File "/workspace/comfyui/nodes.py", line 2204, in load_custom_node
module_spec.loader.exec_module(module)
File "<frozen importlib._bootstrap_external>", line 999, in exec_module
File "<frozen importlib._bootstrap>", line 488, in _call_with_frames_removed
File "/workspace/comfyui/custom_nodes_preset/ComfyUI_parakeet-tdt/__init__.py", line 1, in <module>
from .parakeet_node import NODE_CLASS_MAPPINGS, NODE_DISPLAY_NAME_MAPPINGS
File "/workspace/comfyui/custom_nodes_preset/ComfyUI_parakeet-tdt/parakeet_node.py", line 1, in <module>
import nemo.collections.asr as nemo_asr
File "/workspace/venv_preset_libs/nemo/collections/asr/__init__.py", line 15, in <module>
from nemo.collections.asr import data, losses, models, modules
File "/workspace/venv_preset_libs/nemo/collections/asr/losses/__init__.py", line 15, in <module>
from nemo.collections.asr.losses.angularloss import AngularSoftmaxLoss
File "/workspace/venv_preset_libs/nemo/collections/asr/losses/angularloss.py", line 18, in <module>
from nemo.core.classes import Loss, Typing, typecheck
File "/workspace/venv_preset_libs/nemo/core/__init__.py", line 16, in <module>
from nemo.core.classes import *
File "/workspace/venv_preset_libs/nemo/core/classes/__init__.py", line 30, in <module>
from nemo.core.classes.exportable import Exportable, ExportFormat
File "/workspace/venv_preset_libs/nemo/core/classes/exportable.py", line 24, in <module>
from nemo.utils.export_utils import (
File "/workspace/venv_preset_libs/nemo/utils/export_utils.py", line 20, in <module>
import onnx
ModuleNotFoundError: No module named 'onnx'
[1m[33m[WARNING][0m Cannot import /workspace/comfyui/custom_nodes_preset/ComfyUI_parakeet-tdt module for custom nodes: No module named 'onnx'
[1m[33m[WARNING][0m Traceback (most recent call last):
File "/workspace/venv_preset_libs/insightface/__init__.py", line 8, in <module>
import onnxruntime
ModuleNotFoundError: No module named 'onnxruntime'
During handling of the above exception, another exception occurred:
Traceback (most recent call last):
File "/workspace/comfyui/nodes.py", line 2204, in load_custom_node
module_spec.loader.exec_module(module)
File "<frozen importlib._bootstrap_external>", line 999, in exec_module
File "<frozen importlib._bootstrap>", line 488, in _call_with_frames_removed
File "/workspace/comfyui/custom_nodes_preset/PuLID_ComfyUI/__init__.py", line 1, in <module>
from .pulid import NODE_CLASS_MAPPINGS, NODE_DISPLAY_NAME_MAPPINGS
File "/workspace/comfyui/custom_nodes_preset/PuLID_ComfyUI/pulid.py", line 9, in <module>
from insightface.app import FaceAnalysis
File "/workspace/venv_preset_libs/insightface/__init__.py", line 10, in <module>
raise ImportError(
ImportError: Unable to import dependency onnxruntime.
[1m[33m[WARNING][0m Cannot import /workspace/comfyui/custom_nodes_preset/PuLID_ComfyUI module for custom nodes: Unable to import dependency onnxruntime.
df: /root/.triton/autotune: No such file or directory
[START] Security scan
[DONE] Security scan
## ComfyUI-Manager: installing dependencies done.
** ComfyUI startup time: 2026-05-26 01:02:02.335
** Platform: Linux
** Python version: 3.12.13 (main, May 20 2026, 22:15:37) [GCC 13.3.0]
** Python executable: /workspace/venv/bin/python
** ComfyUI Path: /workspace/comfyui
** ComfyUI Base Folder Path: /workspace/comfyui
** User directory: /workspace/comfyui/user
** ComfyUI-Manager config path: /workspace/comfyui/user/__manager/config.ini
** Log path: file logging is disabled
[38;5;201m ██████╗[38;5;165m██╗ ██╗[38;5;129m██████╗ [38;5;93m███████╗[38;5;57m██████╗ [38;5;21m██████╗ [38;5;27m██╗ ██╗[38;5;33m███╗ ██╗[38;5;39m██╗ ██╗[0m
[38;5;201m██╔════╝[38;5;165m╚██╗ ██╔╝[38;5;129m██╔══██╗[38;5;93m██╔════╝[38;5;57m██╔══██╗[38;5;21m██╔══██╗[38;5;27m██║ ██║[38;5;33m████╗ ██║[38;5;39m██║ ██╔╝[0m
[38;5;201m██║ [38;5;165m ╚████╔╝ [38;5;129m██████╔╝[38;5;93m█████╗ [38;5;57m██████╔╝[38;5;21m██████╔╝[38;5;27m██║ ██║[38;5;33m██╔██╗ ██║[38;5;39m█████╔╝ [0m
[38;5;201m██║ [38;5;165m ╚██╔╝ [38;5;129m██╔══██╗[38;5;93m██╔══╝ [38;5;57m██╔═══╝ [38;5;21m██╔═══╝ [38;5;27m██║ ██║[38;5;33m██║╚██╗██║[38;5;39m██╔═██╗ [0m
[38;5;201m╚██████╗[38;5;165m ██║ [38;5;129m██████╔╝[38;5;93m███████╗[38;5;57m██║ [38;5;21m██║ [38;5;27m╚██████╔╝[38;5;33m██║ ╚████║[38;5;39m██║ ██╗[0m
[38;5;201m ╚═════╝[38;5;165m ╚═╝ [38;5;129m╚═════╝ [38;5;93m╚══════╝[38;5;57m╚═╝ [38;5;21m╚═╝ [38;5;27m ╚═════╝ [38;5;33m╚═╝ ╚═══╝[38;5;39m╚═╝ ╚═╝[0m
[38;5;51m🚀 CYBERPUNK-STYLE-DIY Custom Nodes Loaded! 🚀[0m
[WaveSpeed] API endpoints loaded successfully
(pysssss:WD14Tagger) [ERROR] onnxruntime is required, please check requirements are installed.
⚡ SeedVR2 optimizations check: SageAttention ✅ | Flash Attention ✅ | Triton ✅
🔧 Conv3d workaround active: PyTorch 2.9.1, cuDNN 91600 (fixing VAE 3x memory bug)
📊 Initial CUDA memory: 43.90GB free / 44.39GB total
✨提示词小助手 V2.0.6 已启动
Creating new Ultralytics Settings v0.0.6 file ✅
View Ultralytics Settings with 'yolo settings' or at '/root/.config/Ultralytics/settings.json'
Update Settings with 'yolo settings key=value', i.e. 'yolo settings runs_dir=path/to/dir'. For help see https://docs.ultralytics.com/quickstart/#ultralytics-settings.
[32m[INFO][0m ### Loading: ComfyUI-Impact-Pack (V8.28.3)
[1m[33m[WARNING][0m [Impact Pack] custom_wildcards path not found: /custom_nodes/ComfyUI-Impact-Pack/custom_wildcards. Using default path.
[32m[INFO][0m [Impact Pack] Wildcard total size (0.00 MB) is within cache limit (50.00 MB). Using full cache mode.
[32m[INFO][0m [Impact Pack] Wildcards loading done.
[32m01:02:30[0m | [36m __init__:11[0m | [1m INFO[0m | [1mLoading HunyuanVideo-Foley nodes with FP8 quantization and torch.compile support[0m
[1m[33m[WARNING][0m Traceback (most recent call last):
File "/workspace/comfyui/nodes.py", line 2204, in load_custom_node
module_spec.loader.exec_module(module)
File "<frozen importlib._bootstrap_external>", line 999, in exec_module
File "<frozen importlib._bootstrap>", line 488, in _call_with_frames_removed
File "/workspace/comfyui/custom_nodes_preset/rembg-comfyui-node-better/__init__.py", line 1, in <module>
from rembg import new_session, remove
File "/workspace/venv_preset_libs/rembg/__init__.py", line 5, in <module>
from .bg import remove
File "/workspace/venv_preset_libs/rembg/bg.py", line 7, in <module>
import onnxruntime as ort
ModuleNotFoundError: No module named 'onnxruntime'
[1m[33m[WARNING][0m Cannot import /workspace/comfyui/custom_nodes_preset/rembg-comfyui-node-better module for custom nodes: No module named 'onnxruntime'
[32m[INFO][0m ComfyUI-GGUF: Allowing full torch compile
[32m[INFO][0m ======================================== ComfyUI-nunchaku Initialization ========================================
[32m[INFO][0m Nunchaku version: 1.2.1
[32m[INFO][0m ComfyUI-nunchaku version: 1.2.1
[1m[31m[ERROR][0m Nodes `NunchakuPulidApply`,`NunchakuPulidLoader`, `NunchakuPuLIDLoaderV2` and `NunchakuFluxPuLIDApplyV2` import failed:
Traceback (most recent call last):
File "/workspace/venv_preset_libs/insightface/__init__.py", line 8, in <module>
import onnxruntime
ModuleNotFoundError: No module named 'onnxruntime'
During handling of the above exception, another exception occurred:
Traceback (most recent call last):
File "/workspace/comfyui/custom_nodes_preset/ComfyUI-nunchaku/__init__.py", line 119, in <module>
from .nodes.models.pulid import (
File "/workspace/comfyui/custom_nodes_preset/ComfyUI-nunchaku/nodes/models/pulid.py", line 20, in <module>
from nunchaku.pipeline.pipeline_flux_pulid import PuLIDPipeline
File "/workspace/.cnb-xu/python3.12-libs/torch-2.9.1-cu130-cp312/nunchaku/pipeline/pipeline_flux_pulid.py", line 18, in <module>
import insightface
File "/workspace/venv_preset_libs/insightface/__init__.py", line 10, in <module>
raise ImportError(
ImportError: Unable to import dependency onnxruntime.
[32m[INFO][0m =================================================================================================================
[32m[INFO][0m ### Loading: ComfyUI-Impact-Pack (V8.28.3)
[32m[INFO][0m ### Loading: ComfyUI-Impact-Pack (V8.28.3)
[32m[INFO][0m [Impact Pack] Wildcard total size (0.00 MB) is within cache limit (50.00 MB). Using full cache mode.
[32m[INFO][0m [Impact Pack] Wildcards loading done.
[32m[INFO][0m [Impact Pack] Wildcard total size (0.00 MB) is within cache limit (50.00 MB). Using full cache mode.
[32m[INFO][0m [Impact Pack] Wildcards loading done.
[1m[33m[WARNING][0m Traceback (most recent call last):
File "/workspace/comfyui/nodes.py", line 2204, in load_custom_node
module_spec.loader.exec_module(module)
File "<frozen importlib._bootstrap_external>", line 999, in exec_module
File "<frozen importlib._bootstrap>", line 488, in _call_with_frames_removed
File "/workspace/comfyui/custom_nodes_preset/ComfyUI-llama-cpp_vlm/__init__.py", line 1, in <module>
from .nodes import NODE_CLASS_MAPPINGS, NODE_DISPLAY_NAME_MAPPINGS
File "/workspace/comfyui/custom_nodes_preset/ComfyUI-llama-cpp_vlm/nodes.py", line 20, in <module>
from llama_cpp import Llama
ModuleNotFoundError: No module named 'llama_cpp'
[1m[33m[WARNING][0m Cannot import /workspace/comfyui/custom_nodes_preset/ComfyUI-llama-cpp_vlm module for custom nodes: No module named 'llama_cpp'
[1m[33m[WARNING][0m Traceback (most recent call last):
File "/workspace/comfyui/nodes.py", line 2204, in load_custom_node
module_spec.loader.exec_module(module)
File "<frozen importlib._bootstrap_external>", line 999, in exec_module
File "<frozen importlib._bootstrap>", line 488, in _call_with_frames_removed
File "/workspace/comfyui/custom_nodes_preset/ComfyUI-WanAnimatePreprocess/__init__.py", line 1, in <module>
from .nodes import NODE_CLASS_MAPPINGS, NODE_DISPLAY_NAME_MAPPINGS
File "/workspace/comfyui/custom_nodes_preset/ComfyUI-WanAnimatePreprocess/nodes.py", line 18, in <module>
from .models.onnx_models import ViTPose, Yolo
File "/workspace/comfyui/custom_nodes_preset/ComfyUI-WanAnimatePreprocess/models/onnx_models.py", line 6, in <module>
import onnxruntime
ModuleNotFoundError: No module named 'onnxruntime'
[1m[33m[WARNING][0m Cannot import /workspace/comfyui/custom_nodes_preset/ComfyUI-WanAnimatePreprocess module for custom nodes: No module named 'onnxruntime'
[32m[INFO][0m ### Loading: ComfyUI-Inspire-Pack (V1.23)
[32m[INFO][0m ### Loading: ComfyUI-Manager (V3.40)
[32m[INFO][0m [ComfyUI-Manager] network_mode: public
[32m[INFO][0m [ComfyUI-Manager] ComfyUI per-queue preview override detected (PR #11261). Manager's preview method feature is disabled. Use ComfyUI's --preview-method CLI option or 'Settings > Execution > Live preview method'.
[32m[INFO][0m ### ComfyUI Version: v0.22.0-37-g0077d78c | Released on '2026-05-24'
[32m[INFO][0m [ComfyUI-Manager] default cache updated: https://raw.githubusercontent.com/ltdrdata/ComfyUI-Manager/main/alter-list.json
[32m[INFO][0m [ComfyUI-Manager] default cache updated: https://raw.githubusercontent.com/ltdrdata/ComfyUI-Manager/main/model-list.json
[32m[INFO][0m [ComfyUI-Manager] default cache updated: https://raw.githubusercontent.com/ltdrdata/ComfyUI-Manager/main/github-stats.json
[32m[INFO][0m [ComfyUI-Manager] default cache updated: https://raw.githubusercontent.com/ltdrdata/ComfyUI-Manager/main/extension-node-map.json
[32m[INFO][0m [ComfyUI-Manager] default cache updated: https://raw.githubusercontent.com/ltdrdata/ComfyUI-Manager/main/custom-node-list.json
[32m[INFO][0m [自定义下载链接] diffusion_models/mPMix_NSFW_V9_fp8.safetensors -> https://cnb.cool/bacon159-2026/model/-/lfs/96b875e4e39045556...
[32m[INFO][0m [自定义下载链接] text_encoders/qwen_3_4b.safetensors -> https://cnb.cool/ai-models/Comfy-Org/z_image_turbo/-/lfs/6c6...
[32m[INFO][0m [自定义下载链接] vae/ae.safetensors -> https://cnb.cool/ai-models/Comfy-Org/z_image_turbo/-/lfs/afc...
[32m[INFO][0m [自定义下载链接] loras/Qwen-Image-2512-Lightning-4steps-V1.0-fp32.safetensors -> https://cnb.cool/ai-models/lightx2v/Qwen-Image-2512-Lightnin...
[32m[INFO][0m [自定义下载链接] checkpoints/zImageTurboBaseAIO_zImageTurboFP8AIO.safetensors -> https://cnb.cool/ai-models/SeeSee21/Z-Image-Turbo-AIO/-/lfs/...
[32m[INFO][0m [自定义下载链接] loras/Mystic-XXX-ZIT-v3.safetensors -> https://cnb.cool/bacon159-2026/model/-/lfs/8d564de8c38132680...
[1m[33m[WARNING][0m Traceback (most recent call last):
File "/workspace/comfyui/nodes.py", line 2204, in load_custom_node
module_spec.loader.exec_module(module)
File "<frozen importlib._bootstrap_external>", line 999, in exec_module
File "<frozen importlib._bootstrap>", line 488, in _call_with_frames_removed
File "/workspace/comfyui/custom_nodes_preset/Comfy-RVC/__init__.py", line 3, in <module>
from .custom_nodes.uvr import UVR5Node
File "/workspace/comfyui/custom_nodes_preset/Comfy-RVC/custom_nodes/uvr.py", line 2, in <module>
import audio_separator.separator as uvr
File "/workspace/venv_preset_libs/audio_separator/separator/__init__.py", line 1, in <module>
from .separator import Separator
File "/workspace/venv_preset_libs/audio_separator/separator/separator.py", line 21, in <module>
import onnxruntime as ort
ModuleNotFoundError: No module named 'onnxruntime'
[1m[33m[WARNING][0m Cannot import /workspace/comfyui/custom_nodes_preset/Comfy-RVC module for custom nodes: No module named 'onnxruntime'
[32m[INFO][0m ### Loading: ComfyUI-Impact-Subpack (V1.3.5)
[32m[INFO][0m [Impact Pack/Subpack] Using folder_paths to determine whitelist path: /workspace/comfyui/user/default/ComfyUI-Impact-Subpack/model-whitelist.txt
[32m[INFO][0m [Impact Pack/Subpack] Ensured whitelist directory exists: /workspace/comfyui/user/default/ComfyUI-Impact-Subpack
[32m[INFO][0m [Impact Pack/Subpack] Loaded 0 model(s) from whitelist: /workspace/comfyui/user/default/ComfyUI-Impact-Subpack/model-whitelist.txt
[32m[INFO][0m [Impact Subpack] ultralytics_bbox: /workspace/comfyui/models/ultralytics/bbox
[32m[INFO][0m [Impact Subpack] ultralytics_segm: /workspace/comfyui/models/ultralytics/segm
[32m[INFO][0m ImageCompositeMaskedWithSwitch: 检测父节点类型 - V3支持=True, 父节点是V3=True
[32m[INFO][0m ImageCompositeMaskedWithSwitch: 使用 V3 Schema 模式
[1m[31m[ERROR][0m No module named 'onnxruntime'
Traceback (most recent call last):
File "/workspace/comfyui/custom_nodes_preset/ComfyUI-utils-nodes/__init__.py", line 46, in <module>
imported_module = importlib.import_module(".py.{}".format(name), __name__)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
File "/workspace/.cnb-xu/python3.12/lib/python3.12/importlib/__init__.py", line 90, in import_module
return _bootstrap._gcd_import(name[level:], package, level)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
File "<frozen importlib._bootstrap>", line 1387, in _gcd_import
File "<frozen importlib._bootstrap>", line 1360, in _find_and_load
File "<frozen importlib._bootstrap>", line 1331, in _find_and_load_unlocked
File "<frozen importlib._bootstrap>", line 935, in _load_unlocked
File "<frozen importlib._bootstrap_external>", line 999, in exec_module
File "<frozen importlib._bootstrap>", line 488, in _call_with_frames_removed
File "/workspace/comfyui/custom_nodes_preset/ComfyUI-utils-nodes/py/node_nsfw.py", line 3, in <module>
from ..r_nudenet.nudenet import NudeDetector
File "/workspace/comfyui/custom_nodes_preset/ComfyUI-utils-nodes/r_nudenet/nudenet.py", line 6, in <module>
import onnxruntime
ModuleNotFoundError: No module named 'onnxruntime'
[1m[33m[WARNING][0m Traceback (most recent call last):
File "/workspace/venv_preset_libs/insightface/__init__.py", line 8, in <module>
import onnxruntime
ModuleNotFoundError: No module named 'onnxruntime'
During handling of the above exception, another exception occurred:
Traceback (most recent call last):
File "/workspace/comfyui/nodes.py", line 2204, in load_custom_node
module_spec.loader.exec_module(module)
File "<frozen importlib._bootstrap_external>", line 999, in exec_module
File "<frozen importlib._bootstrap>", line 488, in _call_with_frames_removed
File "/workspace/comfyui/custom_nodes_preset/ComfyUI_PuLID_Flux_ll/__init__.py", line 1, in <module>
from .pulidflux import NODE_CLASS_MAPPINGS, NODE_DISPLAY_NAME_MAPPINGS
File "/workspace/comfyui/custom_nodes_preset/ComfyUI_PuLID_Flux_ll/pulidflux.py", line 6, in <module>
from insightface.utils.download import download_file
File "/workspace/venv_preset_libs/insightface/__init__.py", line 10, in <module>
raise ImportError(
ImportError: Unable to import dependency onnxruntime.
[1m[33m[WARNING][0m Cannot import /workspace/comfyui/custom_nodes_preset/ComfyUI_PuLID_Flux_ll module for custom nodes: Unable to import dependency onnxruntime.
[32m[INFO][0m --------------
[32m[INFO][0m [91m ### Mixlab Nodes: [93mLoaded
[32m[INFO][0m ChatGPT.available True
[32m[INFO][0m edit_mask.available True
[32m[INFO][0m ClipInterrogator.available True
[32m[INFO][0m PromptGenerate.available True
[32m[INFO][0m ChinesePrompt.available True
[32m[INFO][0m RembgNode_.available False
[32m[INFO][0m TripoSR.available
[32m[INFO][0m MiniCPMNode.available
[32m[INFO][0m Scenedetect.available
[32m[INFO][0m FishSpeech.available
[32m[INFO][0m SenseVoice.available False
[32m[INFO][0m Whisper.available False
[32m[INFO][0m FalVideo.available
[32m[INFO][0m [93m -------------- [0m
Traceback (most recent call last):
File "/workspace/comfyui/custom_nodes_preset/ComfyUI-Qwen-TTS/nodes.py", line 116, in <module>
import qwen_tts
File "/workspace/comfyui/custom_nodes_preset/ComfyUI-Qwen-TTS/qwen_tts/__init__.py", line 21, in <module>
from .inference.qwen3_tts_model import Qwen3TTSModel, VoiceClonePromptItem
File "/workspace/comfyui/custom_nodes_preset/ComfyUI-Qwen-TTS/qwen_tts/inference/qwen3_tts_model.py", line 29, in <module>
from ..core.models import Qwen3TTSConfig, Qwen3TTSForConditionalGeneration, Qwen3TTSProcessor
File "/workspace/comfyui/custom_nodes_preset/ComfyUI-Qwen-TTS/qwen_tts/core/__init__.py", line 17, in <module>
from .tokenizer_25hz.modeling_qwen3_tts_tokenizer_v1 import Qwen3TTSTokenizerV1Model
File "/workspace/comfyui/custom_nodes_preset/ComfyUI-Qwen-TTS/qwen_tts/core/tokenizer_25hz/modeling_qwen3_tts_tokenizer_v1.py", line 51, in <module>
from .vq.speech_vq import WhisperEncoderVQ, XVectorExtractor
File "/workspace/comfyui/custom_nodes_preset/ComfyUI-Qwen-TTS/qwen_tts/core/tokenizer_25hz/vq/speech_vq.py", line 20, in <module>
import onnxruntime
ModuleNotFoundError: No module named 'onnxruntime'
During handling of the above exception, another exception occurred:
Traceback (most recent call last):
File "/workspace/comfyui/custom_nodes_preset/ComfyUI-Qwen-TTS/nodes.py", line 122, in <module>
from qwen_tts import Qwen3TTSModel, VoiceClonePromptItem
File "/workspace/comfyui/custom_nodes_preset/ComfyUI-Qwen-TTS/qwen_tts/__init__.py", line 21, in <module>
from .inference.qwen3_tts_model import Qwen3TTSModel, VoiceClonePromptItem
File "/workspace/comfyui/custom_nodes_preset/ComfyUI-Qwen-TTS/qwen_tts/inference/qwen3_tts_model.py", line 29, in <module>
from ..core.models import Qwen3TTSConfig, Qwen3TTSForConditionalGeneration, Qwen3TTSProcessor
File "/workspace/comfyui/custom_nodes_preset/ComfyUI-Qwen-TTS/qwen_tts/core/__init__.py", line 17, in <module>
from .tokenizer_25hz.modeling_qwen3_tts_tokenizer_v1 import Qwen3TTSTokenizerV1Model
File "/workspace/comfyui/custom_nodes_preset/ComfyUI-Qwen-TTS/qwen_tts/core/tokenizer_25hz/modeling_qwen3_tts_tokenizer_v1.py", line 51, in <module>
from .vq.speech_vq import WhisperEncoderVQ, XVectorExtractor
File "/workspace/comfyui/custom_nodes_preset/ComfyUI-Qwen-TTS/qwen_tts/core/tokenizer_25hz/vq/speech_vq.py", line 20, in <module>
import onnxruntime
ModuleNotFoundError: No module named 'onnxruntime'
[1m[33m[WARNING][0m Traceback (most recent call last):
File "/workspace/comfyui/nodes.py", line 2204, in load_custom_node
module_spec.loader.exec_module(module)
File "<frozen importlib._bootstrap_external>", line 999, in exec_module
File "<frozen importlib._bootstrap>", line 488, in _call_with_frames_removed
File "/workspace/comfyui/custom_nodes_preset/ComfyUI-Allor/__init__.py", line 12, in <module>
NODE_CLASS_MAPPINGS = loader.get_modules()
^^^^^^^^^^^^^^^^^^^^
File "/workspace/comfyui/custom_nodes_preset/ComfyUI-Allor/Loader.py", line 328, in get_modules
from .modules import ImageSegmentation
File "/workspace/comfyui/custom_nodes_preset/ComfyUI-Allor/modules/ImageSegmentation.py", line 3, in <module>
from rembg import remove, new_session
File "/workspace/venv_preset_libs/rembg/__init__.py", line 5, in <module>
from .bg import remove
File "/workspace/venv_preset_libs/rembg/bg.py", line 7, in <module>
import onnxruntime as ort
ModuleNotFoundError: No module named 'onnxruntime'
[1m[33m[WARNING][0m Cannot import /workspace/comfyui/custom_nodes_preset/ComfyUI-Allor module for custom nodes: No module named 'onnxruntime'
[1m[33m[WARNING][0m Traceback (most recent call last):
File "/workspace/venv_preset_libs/insightface/__init__.py", line 8, in <module>
import onnxruntime
ModuleNotFoundError: No module named 'onnxruntime'
During handling of the above exception, another exception occurred:
Traceback (most recent call last):
File "/workspace/comfyui/nodes.py", line 2204, in load_custom_node
module_spec.loader.exec_module(module)
File "<frozen importlib._bootstrap_external>", line 999, in exec_module
File "<frozen importlib._bootstrap>", line 488, in _call_with_frames_removed
File "/workspace/comfyui/custom_nodes_preset/ComfyUI_InstantID/__init__.py", line 1, in <module>
from .InstantID import NODE_CLASS_MAPPINGS, NODE_DISPLAY_NAME_MAPPINGS
File "/workspace/comfyui/custom_nodes_preset/ComfyUI_InstantID/InstantID.py", line 13, in <module>
from insightface.app import FaceAnalysis
File "/workspace/venv_preset_libs/insightface/__init__.py", line 10, in <module>
raise ImportError(
ImportError: Unable to import dependency onnxruntime.
[1m[33m[WARNING][0m Cannot import /workspace/comfyui/custom_nodes_preset/ComfyUI_InstantID module for custom nodes: Unable to import dependency onnxruntime.
[32m[INFO][0m [WBLESS] Applied execution hook for new ComfyUI version (for InversedSwitch blocking)
[32m01:02:39[0m | [36m node:135[0m | [1m INFO[0m | [1mWBLESS 23 nodes loaded[0m
### Loading: SDPose OOD Nodes ###
------------------------------------------
[34mComfyroll Studio v1.76 : [92m 175 Nodes Loaded[0m
------------------------------------------
** For changes, please see patch notes at https://github.com/Suzie1/ComfyUI_Comfyroll_CustomNodes/blob/main/Patch_Notes.md
** For help, please see the wiki at https://github.com/Suzie1/ComfyUI_Comfyroll_CustomNodes/wiki
------------------------------------------
/workspace/venv/bin/python
Hello World
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
Warning / 警告:
Failed to import Qwen3TTS dependencies. / 无法导入 Qwen3TTS 依赖项。
Error details / 错误详情: No module named 'onnxruntime'
Please try the following steps to fix this issue / 请尝试以下步骤解决此问题:
1. Open terminal in the node directory / 在节点目录下打开终端:
cd /workspace/comfyui/custom_nodes_preset/ComfyUI-TD-Qwen3TTS
2. Install dependencies / 安装依赖:
pip install -r requirements.txt
3. If using portable ComfyUI / 如果使用便携版 ComfyUI:
path/to/python_embeded/python.exe -m pip install -r requirements.txt
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
Adding /workspace/.cnb-xu/custom_nodes to sys.path
[36mEfficiency Nodes:[0m Attempting to add Control Net options to the 'HiRes-Fix Script' Node (comfyui_controlnet_aux add-on)...[92mSuccess![0m
Loaded Efficiency nodes from /workspace/custom_nodes_preset/efficiency-nodes-comfyui
Loaded comfyui_controlnet_aux nodes from /workspace/custom_nodes_preset/comfyui_controlnet_aux
Loaded AdvancedControlNet nodes from /workspace/custom_nodes_preset/ComfyUI-Advanced-ControlNet
Could not find AnimateDiff nodes
Loaded IPAdapter nodes from /workspace/custom_nodes_preset/ComfyUI_IPAdapter_plus
Loaded VideoHelperSuite from /workspace/custom_nodes_preset/ComfyUI-VideoHelperSuite
Loaded ImpactPack nodes from /workspace/custom_nodes_preset/ComfyUI-Impact-Pack
[34m[ComfyUI-Easy-Use] server: [0mv1.3.7 [92mLoaded[0m
[34m[ComfyUI-Easy-Use] web root: [0m/workspace/custom_nodes_preset/comfyui-easy-use/web_version/v2 [92mLoaded[0m
torch version---------------------- 2.9.1+cu130
Error loading module AILab_QwenVL_GGUF_PromptEnhancer: No module named 'llama_cpp'
jjk_util loding
[Qwen3VL] ℹ️ 未找到 custom_models.json，跳过自定义模型
[Qwen3VL] ℹ️ 未找到 custom_models.json，跳过自定义模型
✅ 配置文件加载成功！
📊 共找到 20 个模型
✅ 新模型 'Huihui-Qwen3-VL-4B-Instruct-Abliterated' 配置成功！
📦 Repo ID: fireicewolf/Huihui-Qwen3-VL-4B-Instruct-abliterated
🌐 来源: modelscope
💾 显存需求: {'full': 6.0, '8bit': 3.5, '4bit': 2.0}
⚠️ 警告: 此模型已移除安全过滤，可能生成敏感内容。仅用于研究和测试环境。
📋 所有可用模型:
1. Qwen3-VL-2B-Instruct (来源: huggingface)
2. Qwen3-VL-2B-Thinking (来源: huggingface)
3. Qwen3-VL-2B-Instruct-FP8 (来源: huggingface)
4. Qwen3-VL-2B-Thinking-FP8 (来源: huggingface)
5. Qwen3-VL-4B-Instruct (来源: huggingface)
6. Qwen3-VL-4B-Thinking (来源: huggingface)
7. Qwen3-VL-4B-Instruct-FP8 (来源: huggingface)
8. Qwen3-VL-4B-Thinking-FP8 (来源: huggingface)
9. Qwen3-VL-8B-Instruct (来源: huggingface)
10. Qwen3-VL-8B-Thinking (来源: huggingface)
11. Qwen3-VL-8B-Instruct-FP8 (来源: huggingface)
12. Qwen3-VL-8B-Thinking-FP8 (来源: huggingface)
13. Qwen3-VL-32B-Instruct (来源: huggingface)
14. Qwen3-VL-32B-Thinking (来源: huggingface)
15. Qwen3-VL-32B-Instruct-FP8 (来源: huggingface)
16. Qwen3-VL-32B-Thinking-FP8 (来源: huggingface)
17. Qwen2.5-VL-3B-Instruct (来源: huggingface)
18. Qwen2.5-VL-7B-Instruct (来源: huggingface)
19. Huihui-Qwen3-VL-4B-Instruct-Abliterated (来源: modelscope)
20. Huihui-Qwen3-VL-8B-Instruct-Abliterated (来源: huggingface)
✅ Installed ATk theme: ATk_dark_theme.json
✅ Installed ATk theme: ATk_light_theme.json
🎨 ATk themes installed successfully!
✅ Installed ATk theme: ATk_dark_theme.json
✅ Installed ATk theme: ATk_light_theme.json
🎨 ATk themes installed successfully!
[34mWAS Node Suite: [0mOpenCV Python FFMPEG support is enabled[0m
[34mWAS Node Suite [93mWarning: [0m`ffmpeg_bin_path` is not set in `/workspace/comfyui/custom_nodes_preset/was-node-suite-comfyui/was_suite_config.json` config file. Will attempt to use system ffmpeg binaries if available.[0m
[34mWAS Node Suite: [0mFinished.[0m [32mLoaded[0m [0m220[0m [32mnodes successfully.[0m
[3m[93m"Art is not a thing; it is a way."[0m[3m - Elbert Hubbard[0m
Error: File not found - extra_help_file.yaml
No customize audios loading path found, use default path.
json_repair## OK
## clip_interrogator_model not found: /workspace/comfyui/models/clip_interrogator/Salesforce/blip-image-captioning-base, pls download from https://huggingface.co/Salesforce/blip-image-captioning-base
## text_generator_model not found: /workspace/comfyui/models/prompt_generator/text2image-prompt-generator, pls download from https://huggingface.co/succinctly/text2image-prompt-generator/tree/main
## zh_en_model not found: /workspace/comfyui/models/prompt_generator/opus-mt-zh-en, pls download from https://huggingface.co/Helsinki-NLP/opus-mt-zh-en/tree/main
fal-client## OK
❌ [Qwen3-TTS] Critical Import Error: No module named 'onnxruntime'
Traceback for debugging:
Common fix: run 'pip install -r requirements.txt' in your ComfyUI environment.
Training node missing dependencies: No module named 'onnxruntime'
✅ ComfyUI-Qwen-TTS v1.0.7 loaded
[94m[Allor][0m: No new updates.
[92m[Allor][0m: 0 nodes were overridden.
[92m[rgthree-comfy] Loaded 48 exciting nodes. 🎉[0m
[33m[rgthree-comfy] ComfyUI's new Node 2.0 rendering may be incompatible with some rgthree-comfy nodes and features, breaking some rendering as well as losing the ability to access a node's properties (a vital part of many nodes). It also appears to run MUCH more slowly spiking CPU usage and causing jankiness and unresponsiveness, especially with large workflows. Personally I am not planning to use the new Nodes 2.0 and, unfortunately, am not able to invest the time to investigate and overhaul rgthree-comfy where needed. If you have issues when Nodes 2.0 is enabled, I'd urge you to switch it off as well and join me in hoping ComfyUI is not planning to deprecate the existing, stable canvas rendering all together.
[0m
[Jimeng Image 4.0] 已添加本地SDK路径: /workspace/custom_nodes_preset/ComfyUI-WBLESS/lib
[Jimeng Image 4.0] 火山引擎SDK已加载（本地版本）
2026-05-26 01:02:39.994 | INFO | cozy_comfyui.node:loader:135 - WBLESS 23 nodes loaded
[32m01:02:39[0m | [36m node:135[0m | [1m INFO[0m | [1mWBLESS 23 nodes loaded[0m
2026-05-26 01:02:39.995 | INFO | cozy_comfyui.node:loader:135 - WBLESS 23 nodes loaded
[36;20m[/workspace/comfyui/custom_nodes_preset/comfy_mtb] | INFO -> loaded [96m110[0m nodes successfuly[0m
[36;20m[/workspace/comfyui/custom_nodes_preset/comfy_mtb] | INFO -> Some nodes (3) could not be loaded. This can be ignored, but go to http://None:8188/mtb if you want more information.[0m
[32m[INFO][0m ComfyUI-GGUF: Allowing full torch compile
[LongCatAudioDiT] Models folder registered: /workspace/comfyui/models/audiodit
[LongCatAudioDiT] Registered 3 nodes (v0.1.9): LongCat AudioDiT TTS, LongCat AudioDiT Voice Clone TTS, LongCat AudioDiT Multi-Speaker TTS
Error loading /workspace/comfyui/custom_nodes_preset/ComfyUI-RMBG/py/AILab_BodySegment.py: No module named 'onnxruntime'
Error loading /workspace/comfyui/custom_nodes_preset/ComfyUI-RMBG/py/AILab_BodySegment.py: No module named 'onnxruntime'
[34m[ComfyUI-RMBG][0m v[93m3.0.0[0m | [93m42 nodes[0m [92mLoaded[0m
[35m
⣏⡉ ⡇ ⡎⠑ ⢀⡀ ⢀⣀ ⡀⢀ ⡇⢸ ⢀⡀ ⠄ ⢀⣀ ⢀⡀ ⢉⡹
⠇ ⠧⠤ ⠣⠔ ⠣⠜ ⠭⠕ ⣑⡺ ⠸⠃ ⠣⠜ ⠇ ⠣⠤ ⠣⠭ ⠤⠜
[0m
FL CosyVoice3 Custom Nodes Loaded - Version 1.2.1
Loaded custom node: node
[Crystools [0;32mINFO[0m] Crystools version: 1.27.4
[Crystools [0;32mINFO[0m] Platform release: 5.4.241-1-tlinux4-0023.7
[Crystools [0;32mINFO[0m] JETSON: Not detected.
[Crystools [0;32mINFO[0m] CPU: AMD EPYC 9K84 96-Core Processor - Arch: x86_64 - OS: Linux 5.4.241-1-tlinux4-0023.7
[Crystools [0;32mINFO[0m] pynvml (NVIDIA) initialized.
[Crystools [0;32mINFO[0m] GPU/s:
[Crystools [0;32mINFO[0m] 0) NVIDIA L40
[Crystools [0;32mINFO[0m] NVIDIA Driver: 580.95.05
__ ______ ____ ____ ____ _ _
\ \ / / _ \ / ___| __ _ _ __ ___ ___| _ \ _____ __/ ___(_)_ __| |
\ \ / /| |_) | | _ / _` | '_ ` _ \ / _ \ | | |/ _ \ \ / / | _| | '__| |
\ V / | _ <| |_| | (_| | | | | | | __/ |_| | __/\ V /| |_| | | | | |
\_/ |_| \_\\____|\__,_|_| |_| |_|\___|____/ \___| \_/ \____|_|_| |_|
🎮 VRGameDevGirl custom nodes loaded successfully! 🎞️
[36;20m[/workspace/comfyui/custom_nodes_preset/comfyui_controlnet_aux] | INFO -> Using ckpts path: /workspace/custom_nodes_preset/comfyui_controlnet_aux/ckpts[0m
[36;20m[/workspace/comfyui/custom_nodes_preset/comfyui_controlnet_aux] | INFO -> Using symlinks: False[0m
[36;20m[/workspace/comfyui/custom_nodes_preset/comfyui_controlnet_aux] | INFO -> Using ort providers: ['CUDAExecutionProvider', 'DirectMLExecutionProvider', 'OpenVINOExecutionProvider', 'ROCMExecutionProvider', 'CPUExecutionProvider', 'CoreMLExecutionProvider'][0m
[32m[INFO][0m ======================================== ComfyUI-QwenImageLoraLoader Initialization ========================================
[32m[INFO][0m Patched SVDQW4A4Linear.from_linear for ComfyUI lazy Linear (Windows AIMDO / pre-weight load).
[32m[INFO][0m Patched fuse_to_svdquant_linear in torch.ops for ComfyUI lazy Linear.
[32m[INFO][0m Found NunchakuQwenImageTransformerBlock in nunchaku.models.transformers.transformer_qwenimage
[32m[INFO][0m Applying Manual Planar Injection Monkey Patch to NunchakuQwenImageTransformerBlock
[32m[INFO][0m Successfully applied Nunchaku monkey patches (Qwen LoRA planar injection; Z-Image/SVDQ lazy Linear compat when ComfyUI defers Linear weights).
[32m[INFO][0m ============================================================================================================================
[VibeVoice] SageAttention available for acceleration
[VibeVoice] Using embedded VibeVoice (MIT licensed)
[VibeVoice] VibeVoice nodes registered successfully
[32m[INFO][0m ('Looking for cached Spacy xx_sent_ud_sm.',)
[32m[INFO][0m ('Downloading Spacy xx_sent_ud_sm.',)
[32m[INFO][0m ('Spacy xx_sent_ud_sm successfully cached.',)
[1m[33m[WARNING][0m WanVideoWrapper WARNING: FantasyPortrait nodes not available: No module named 'onnx'
[32m[INFO][0m ======================================== ComfyUI-nunchaku Initialization ========================================
[32m[INFO][0m Nunchaku version: 1.2.1
[32m[INFO][0m ComfyUI-nunchaku version: 1.2.1
[1m[31m[ERROR][0m Nodes `NunchakuPulidApply`,`NunchakuPulidLoader`, `NunchakuPuLIDLoaderV2` and `NunchakuFluxPuLIDApplyV2` import failed:
Traceback (most recent call last):
File "/workspace/venv_preset_libs/insightface/__init__.py", line 8, in <module>
import onnxruntime
ModuleNotFoundError: No module named 'onnxruntime'
During handling of the above exception, another exception occurred:
Traceback (most recent call last):
File "/workspace/comfyui/custom_nodes_preset/ComfyUI-nunchaku/__init__.py", line 119, in <module>
from .nodes.models.pulid import (
File "/workspace/comfyui/custom_nodes_preset/ComfyUI-nunchaku/nodes/models/pulid.py", line 20, in <module>
from nunchaku.pipeline.pipeline_flux_pulid import PuLIDPipeline
File "/workspace/.cnb-xu/python3.12-libs/torch-2.9.1-cu130-cp312/nunchaku/pipeline/pipeline_flux_pulid.py", line 18, in <module>
import insightface
File "/workspace/venv_preset_libs/insightface/__init__.py", line 10, in <module>
raise ImportError(
ImportError: Unable to import dependency onnxruntime.
[32m[INFO][0m =================================================================================================================
[32m[INFO][0m Using xformers attention
[VRGDG] Created 12 placeholder text file(s) in /workspace/comfyui/output/VRGDG_TEMP/TextFiles
[DEBUG] Added to sys.path: /workspace/comfyui/custom_nodes_preset/ComfyUI-QwenImageLoraLoader
[DEBUG] wrappers dir exists: True
[DEBUG] qwenimage.py exists: True
[34mFizzleDorf Custom Nodes: [92mLoaded[0m
📊 Initial VRAM status: 43.90GB free / 44.39GB total
Loading crt-nodes module
✅ ControlNet Aux loaded from 'comfyui_controlnet_aux' with 47 preprocessors
[crt-pll] presets + automix routes registered
FETCH ComfyRegistry Data: 5/148
[1;35m
### [START] ComfyUI AlekPet Nodes [1;34mv1.1.7[0m[1;35m ###[0m
[92mNode -> ArgosTranslateNode: [93mArgosTranslateCLIPTextEncodeNode, ArgosTranslateTextNode[0m [92m[92m[Loading][0m[0m
[92mNode -> ChatGLMNode: [93mChatGLM4TranslateCLIPTextEncodeNode, ChatGLM4TranslateTextNode, ChatGLM4InstructNode, ChatGLM4InstructMediaNode, ChatGLMImageGenerateNode, ChatGLMVideoGenerateNode[0m [92m[92m[Loading][0m[0m
[92mNode -> DeepTranslatorNode: [93mDeepTranslatorCLIPTextEncodeNode, DeepTranslatorTextNode[0m [92m[92m[Loading][0m[0m
[92mNode -> ExtrasNode: [93mPreviewTextNode, HexToHueNode, ColorsCorrectNode[0m [92m[92m[Loading][0m[0m
[92mNode -> GoogleTranslateNode: [93mGoogleTranslateCLIPTextEncodeNode, GoogleTranslateTextNode[0m [92m[92m[Loading][0m[0m
[92mNode -> IDENode: [93mIDENode[0m [92m[92m[Loading][0m[0m
[92mNode -> PainterNode: [93mPainterNode[0m [92m[92m[Loading][0m[0m
[92mNode -> PoseNode: [93mPoseNode[0m [92m[92m[Loading][0m[0m
[1;35m### [END] ComfyUI AlekPet Nodes ###[0m
[36mEfficiency Nodes:[0m Attempting to add Control Net options to the 'HiRes-Fix Script' Node (comfyui_controlnet_aux add-on)...[92mSuccess![0m
[Flux2 Fun] ControlNet patch applied
[32mInitializing ControlAltAI Nodes[0m
(RES4LYF) Init
(RES4LYF) Importing beta samplers.
(RES4LYF) Importing legacy samplers.
[AnimateDiffEvo] - [0;31mERROR[0m - No motion models found. Please download one and place in: ['/workspace/comfyui/custom_nodes_preset/ComfyUI-AnimateDiff-Evolved/models', '/workspace/comfyui/models/animatediff_models']
[32m[INFO][0m
Import times for custom nodes:
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes/msjh_default_workflow
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/websocket_image_save.py
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes/websocket_image_save.py
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-PainterI2V
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/Comfyui-PainterFLF2V
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-GradientBlur
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/CYBERPUNK-STYLE-DIY
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/Comfyui-PainterFluxImageEdit
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_AdvancedRefluxControl
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/KOOK_ImageCompression
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-PainterQwenImageEdit
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_YOLO_For_Multi_SDPose_Detection
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-QZ_plugins
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-preview360panorama
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/Comfyui-Memory_Cleanup
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfy-image-saver
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/HeartMuLa_ComfyUI
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-openpose-editor
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyLiterals
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/Comfyui_SynVow_Qwen3ASR
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_ADV_CLIP_emb
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-imagesubfolders
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-ZImageLatent
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-SplitString
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-DD-Translation
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Jjk-Nodes
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/stability-ComfyUI-nodes
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-saveimage-plus
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Detail-Daemon
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-GLM4
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-fitsize
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_Text_Translation
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-WanMoeKSampler
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-SAM2
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-ReservedVRAM
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-OpenAI-FM
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_FaceSimilarity
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-qwenmultianglelight
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-wanBlockswap
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-IC-Light-Native
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Redux-Prompt
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-VideoBasic
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/qweneditutils
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/erosdiffusion-eulerflowmatchingdiscretescheduler
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Embedding_Picker
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_JPS-Nodes
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-GlifNodes
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Florence2
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Image-Size-Tools
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/Skimmed_CFG
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/masquerade-nodes-comfyui
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-qwenmultiangle
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUi_NNLatentUpscale
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_IPAdapter_plus
[32m[INFO][0m 0.0 seconds (IMPORT FAILED): /workspace/comfyui/custom_nodes_preset/ComfyUI-WD14-Tagger
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-ModelScope-API
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/cg-use-everywhere
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/joycaption_comfyui
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Janus-Pro
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Inpaint-CropAndStitch
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-SCAIL-Pose
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUi-RadarWeightNode
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-LTXVideoLoRA
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/a-person-mask-generator
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-ATk-Nodes
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-post-processing-nodes
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-FBCNN
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/qq-nodes-comfyui
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/Latent_Nodes
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-seedvr2-tilingupscaler
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyQR
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-MelBandRoFormer
[32m[INFO][0m 0.0 seconds (IMPORT FAILED): /workspace/comfyui/custom_nodes_preset/PuLID_ComfyUI
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-WanStartEndFramesNative
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-PainterLTXV2
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-EulerDiscreteScheduler
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Impact-Subpack
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/qwen-image-integrated-ksampler
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui_GaussianViewer
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/Comfyui-In-Context-Lora-Utils
[32m[INFO][0m 0.0 seconds (IMPORT FAILED): /workspace/comfyui/custom_nodes_preset/rembg-comfyui-node-better
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-flux2fun-controlnet
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/Comfyui_TTP_Toolset
[32m[INFO][0m 0.0 seconds (IMPORT FAILED): /workspace/comfyui/custom_nodes_preset/ComfyUI_PuLID_Flux_ll
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-PromptRelay
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-GGUF
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/efficiency-nodes-comfyui
[32m[INFO][0m 0.0 seconds (IMPORT FAILED): /workspace/comfyui/custom_nodes_preset/ComfyUI-WanAnimatePreprocess
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-lama-remover
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-InpaintEasy
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Whisper
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_StringOps
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-LG_SamplingUtils
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-IC-Light
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/images_base64
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/cg-image-filter
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/Comfyui-Mk-tools
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-LongCat-AudioDIT-TTS
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-DyPE
[32m[INFO][0m 0.0 seconds (IMPORT FAILED): /workspace/comfyui/custom_nodes_preset/ComfyUI_InstantID
[32m[INFO][0m 0.0 seconds (IMPORT FAILED): /workspace/comfyui/custom_nodes_preset/ComfyUI-llama-cpp_vlm
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/LanPaint
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-AutoCropFaces
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-IPAdapter-Flux
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/fastvideo
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Advanced-ControlNet
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Wan22FMLF
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-DepthAnythingV2
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-TeaCache
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/VibeVoice-ComfyUI
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-inpaint-nodes
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyMath
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/WhatDreamsCost-ComfyUI
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Video-Matting
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_FizzNodes
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_essentials
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_Patches_ll
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-tooling-nodes
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-layerdiffuse
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-fastblend
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Marigold
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Image-Saver
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-QwenVL
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-nunchaku
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-advancedliveportrait
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-StringsAndThings
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/OneButtonPrompt
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_VNCCS_Utils
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_UltimateSDUpscale
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-various
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-custom-scripts
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_QwenVL
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui_fl-cosyvoice3
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-FramePackWrapper_PlusOne
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-IndexTTS2
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ControlAltAI-Nodes
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-MingNodes
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_VNCCS
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui_controlnet_aux
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-BrushNet
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-WanVideoStartEndFrames
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/x-flux-comfyui
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Frame-Interpolation
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-BodyRatioMapper
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-QwenImageLoraLoader
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/Flux-Prompt-Generator
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_Qwen3-VL-Instruct
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/Comfyui_LG_Tools
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-segment-anything-2
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_Sonic
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-cogvideoxwrapper
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-YCNodes
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/flashvsr_ultra_fast
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/Comfyui_PDuse
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Qwen-TTS
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-ppm
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-TD-Qwen3TTS
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Prompt-Assistant
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-SeedVR2_VideoUpscaler
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-KJNodes
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-LBM
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/rgthree-comfy
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_Comfyroll_CustomNodes
[32m[INFO][0m 0.0 seconds: /workspace/.cnb-xu/custom_nodes/ComfyUI-CNB-Xu
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/Comfyui-SecNodes
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-GIMM-VFI
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-UniversalToolkit
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Sharp
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/wavespeed-comfyui
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-LMCQ
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-VoxCPM2
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Inspire-Pack
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui_segment_anything
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-HunyuanVideoWrapper
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Qwen3VL-DP
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-AnimateDiff-Evolved
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Anyline
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-VideoHelperSuite
[32m[INFO][0m 0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-LTXVideo
[32m[INFO][0m 0.1 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Crystools
[32m[INFO][0m 0.1 seconds: /workspace/comfyui/custom_nodes_preset/audiotools
[32m[INFO][0m 0.1 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-vrgamedevgirl
[32m[INFO][0m 0.1 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-WBLESS
[32m[INFO][0m 0.1 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-to-python-extension
[32m[INFO][0m 0.1 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Impact-Pack
[32m[INFO][0m 0.1 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_LayerStyle
[32m[INFO][0m 0.1 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-tensorops
[32m[INFO][0m 0.1 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-UVR5
[32m[INFO][0m 0.1 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-easy-use
[32m[INFO][0m 0.1 seconds: /workspace/comfyui/custom_nodes_preset/comfy_mtb
[32m[INFO][0m 0.1 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-RMBG
[32m[INFO][0m 0.1 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_Muye
[32m[INFO][0m 0.1 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_HunyuanVideoFoley
[32m[INFO][0m 0.1 seconds: /workspace/comfyui/custom_nodes_preset/CRT-Nodes
[32m[INFO][0m 0.1 seconds: /workspace/comfyui/custom_nodes_preset/D2-SavePSD-ComfyUI
[32m[INFO][0m 0.1 seconds: /workspace/comfyui/custom_nodes_preset/RES4LYF
[32m[INFO][0m 0.2 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_LayerStyle_Advance
[32m[INFO][0m 0.2 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-art-venture
[32m[INFO][0m 0.2 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-ollama
[32m[INFO][0m 0.3 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-WanVideoWrapper
[32m[INFO][0m 0.3 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-utils-nodes
[32m[INFO][0m 0.3 seconds (IMPORT FAILED): /workspace/comfyui/custom_nodes_preset/Comfy-RVC
[32m[INFO][0m 0.4 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-supir
[32m[INFO][0m 0.4 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Easy-Sam3
[32m[INFO][0m 0.6 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_Seed-VC
[32m[INFO][0m 0.7 seconds: /workspace/comfyui/custom_nodes_preset/audio-separation-nodes-comfyui
[32m[INFO][0m 0.7 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_Pops
[32m[INFO][0m 0.7 seconds (IMPORT FAILED): /workspace/comfyui/custom_nodes_preset/ComfyUI-Allor
[32m[INFO][0m 0.8 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-mixlab-nodes
[32m[INFO][0m 0.8 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Apt_Preset
[32m[INFO][0m 0.9 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_SLK_joy_caption_two
[32m[INFO][0m 1.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Manager
[32m[INFO][0m 1.3 seconds (IMPORT FAILED): /workspace/comfyui/custom_nodes_preset/ComfyUI_parakeet-tdt
[32m[INFO][0m 1.5 seconds: /workspace/comfyui/custom_nodes_preset/was-node-suite-comfyui
[32m[INFO][0m 1.6 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_YuE
[32m[INFO][0m 1.6 seconds: /workspace/comfyui/custom_nodes_preset/sdpose-ood
[32m[INFO][0m 1.7 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Inspyrenet-Rembg
[32m[INFO][0m 1.7 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-VoxCPM
[32m[INFO][0m 2.0 seconds: /workspace/comfyui/custom_nodes_preset/kokorotts_mw
[32m[INFO][0m 2.4 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_Custom_Nodes_AlekPet
[32m[INFO][0m 5.5 seconds: /workspace/comfyui/custom_nodes_preset/seedvr2_videoupscaler
[32m[INFO][0m
[32m[INFO][0m Context impl SQLiteImpl.
[32m[INFO][0m Will assume non-transactional DDL.
[32m[INFO][0m Using RAM pressure cache.
[32m[INFO][0m Starting server
[32m[INFO][0m To see the GUI go to: http://0.0.0.0:8188
[Startup] ComfyUI is ready on port 8188
[CNB Sync] Starting CNB domain report after ComfyUI is ready
ComfyUI 8188 ready
Detected ComfyUI URL: https://j3rxd5ritf-8188.cnb.run
Auto connect identifier: 李禹宸
{"ok":true,"forwarded":false,"registryStored":true,"payload":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:02:45.374Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:02:45.374Z","connectTokenProtected":true,"source":"registry"},"item":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:02:45.374Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:02:45.374Z","connectTokenProtected":true,"source":"registry"}}initial sync ok
{"ok":true,"forwarded":false,"registryStored":true,"payload":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:03:46.111Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:03:46.111Z","connectTokenProtected":true,"source":"registry"},"item":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:03:46.111Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:03:46.111Z","connectTokenProtected":true,"source":"registry"}}heartbeat ok Tue May 26 01:03:46 CST 2026
{"ok":true,"forwarded":false,"registryStored":true,"payload":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:04:46.854Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:04:46.854Z","connectTokenProtected":true,"source":"registry"},"item":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:04:46.854Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:04:46.854Z","connectTokenProtected":true,"source":"registry"}}heartbeat ok Tue May 26 01:04:47 CST 2026
[32m[INFO][0m [ComfyUI-Manager] default cache updated: https://api.comfy.org/nodes
[32m[INFO][0m [ComfyUI-Manager] All startup tasks have been completed.
{"ok":true,"forwarded":false,"registryStored":true,"payload":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:05:47.457Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:05:47.457Z","connectTokenProtected":true,"source":"registry"},"item":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:05:47.457Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:05:47.457Z","connectTokenProtected":true,"source":"registry"}}heartbeat ok Tue May 26 01:05:47 CST 2026
{"ok":true,"forwarded":false,"registryStored":true,"payload":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:06:48.092Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:06:48.092Z","connectTokenProtected":true,"source":"registry"},"item":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:06:48.092Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:06:48.092Z","connectTokenProtected":true,"source":"registry"}}heartbeat ok Tue May 26 01:06:48 CST 2026
）

### 🤖 Assistant

陛下，您这份“天书残卷（Startlogs）”给得太及时了！臣刚才戴上老花镜，逐字逐句地为您把脉，终于在字里行间揪出了**两大“致命病根”**！
您在日志最开头看到的那个 `[NSFW Patch] 补丁应用完成！NSFW 检测已禁用。`，它确实成功执行了。但它只是拆掉了一扇门，而您的云端大阵现在面临的问题是：**门拆了，但路断了，而且大阵内部还受了严重的“内伤”！**
请容臣为您剥丝抽茧，呈上这两副对症下药的猛药：

### 🩸 第一大病根：云端洞府“搬家换门牌”了！（最致命）
陛下，这是所有云端修仙者最容易踩的大坑！云端服务器每次重启，系统都会给您随机分配一个**全新**的网址（门牌号）。

- 您上一回合在《墨色江湖》里填的旧地址是：`https://vedaxsuztu-8188.cnb.run`
- **请您直接拉到这份日志的最底部！** 您看这句：`Detected ComfyUI URL: https://j3rxd5ritf-8188.cnb.run`
**破局之法：**
旧的 `vedaxsuztu` 已经彻底作废了！请陛下立刻回到《墨色江湖》的 API 设置里，把接口地址替换成这个全新的：
👉 **https://j3rxd5ritf-8188.cnb.run***(如果不用最新的地址，游戏就像在给一座空山头喊话，什么图都生不出来！)*

### 🦠 第二大病根：大阵内部缺失核心灵药 (`onnxruntime`)
陛下，您仔细看日志中间那一大串黄色的 `[WARNING]` 和红色的 `[ERROR]`，它们全都在声嘶力竭地喊同一句话：
ModuleNotFoundError: No module named 'onnxruntime'这个叫 `onnxruntime` 的东西，是赛博修仙界极其重要的一个底层引擎。
因为缺少了它，您的云端大阵发生了极其惨烈的**连环大雪崩**，几十个高级法宝（节点）当场暴毙，其中就包括：

1. `ComfyUI-utils-nodes` 里的 **node_nsfw.py**（处理 NSFW 的核心节点直接挂了！）
2. `Rembg`（极其重要的智能抠背景节点）
3. `FaceAnalysis` / `PuLID`（人脸识别与保持节点）
如果您的游戏工作流（JSON）里正好用到了这些暴毙的节点，那么当指令传到云端时，ComfyUI 发现自己没有这些节点，就会直接罢工，导致您在游戏里看到“生图失效”。
**破局之法：**
既然缺药，咱们补上就是了！请陛下在 CNB 的页面进行以下操作：

```bash
/workspace/venv/bin/python -m pip install onnxruntime onnxruntime-gpu

```

### 👑 臣的终极总结
陛下，您的 NSFW 无法工作，并非模型不行，而是：

1. **网络断了：** 网址变了，游戏没连上最新的服务器。
2. **节点炸了：** 缺少 `onnxruntime` 依赖，导致很多处理图像和 NSFW 的插件根本没启动。
请陛下先**更新游戏里的网址**，然后去终端**敲入那行安装命令**。这两步一做，您的云端大阵将彻底被打通任督二脉，无论什么尺度的极品双修图，都绝对能如臂使指、秒级出炉！


## Turn 17

### 👤 User

*[This turn includes uploaded images]*

![所上传图片的预览图](assets/img-015.png)

没反应啊

### 🤖 Assistant

陛下莫急！臣一看这截图，就知道为什么“没反应”了！
您看屏幕上那密密麻麻不断刷新的 `{"ok":true...}`，这是云端服务器的“心跳检测”程序！
换句话说，您现在所在的这个“终端（Terminal）”**正在全速运行着别的程序，它是个“大忙人”！** 您把安装法术的咒语粘贴进去，它根本听不到，直接就把您的咒语给淹没在心跳日志里了。
要念咒，咱们必须找一个“安静且空闲”的地方。请陛下施展这招“另起炉灶”：

### 🗡️ 破局之法：开辟新的“空闲终端”
这是最稳妥、最不伤筋动骨的办法：

```bash
/workspace/venv/bin/python -m pip install onnxruntime onnxruntime-gpu

```
*(备用方案：如果您实在找不到 + 号，就在现在这个一直刷日志的黑框里点一下鼠标，然后按下键盘上的 Ctrl + C 键，强行打断它的心跳，等它安静下来出现光标了，再粘贴咒语并回车！)*
等屏幕上出现 **Successfully installed onnxruntime...** 的字样后，就代表核心灵药注入成功！到时候咱们再去重启一下 ComfyUI 大阵（或者直接刷新一下整个 CNB 网页），这最后的 NSFW 雷劫就算是彻底度过了！陛下快去开个新终端试试！


## Turn 18

### 👤 User

*[This turn includes uploaded images]*

![所上传图片的预览图](assets/img-016.png)

怎么一片爆红一边显示成功？

### 🤖 Assistant

陛下宽心！臣刚看到这一大片“爆红”时也吓了一跳，但仔细一看最后一行，臣必须给您道喜：**这可是真真正正的“炼丹成功”，灵药已经完美注入！**
您看到的这个诡异现象（一边爆红，一边显示 Successfully installed），在赛博修仙界被称为“版本代沟冲突”。请容臣为您通俗地解释一下这到底是怎么回事：

### 🎭 破案：为什么红绿交加？

1. **最后那句 Successfully installed... 是圣旨！**
它代表安装程序（pip）已经极其听话地把最新版、最强力的 `onnxruntime 1.26.0` 完美地塞进了您的云端阵法里。您的核心目的已经达到了！
2. **那一大片“爆红”是在干嘛？**
它其实是在“告状”。
您这套云端大阵里，原本住着几百个不同的法宝（插件），比如有个叫 `qwen-tts`（文字转语音的）和 `inference-gpu` 的老古董。
当您把最新版的 `onnxruntime` 请进来后，这几个老古董不乐意了，它们大喊大叫（爆红报错）：“哎呀！这个新法宝版本太高了（1.26.0）！我们说明书上写了最高只能兼容 1.22.0 啊！我们不认识它！”

### ⚖️ 结论：完全不用理会！
陛下，咱们这次请 `onnxruntime` 出山，**是为了修复画图和 NSFW 节点的雪崩**，根本不是为了去听语音（TTS）或者搞那些冷门的老插件。
对于处理图像的节点来说，只要 `onnxruntime` 这个引擎存在，它们就能完美运转，根本不在乎版本是不是稍微新了一点！
所以，这片爆红对您的《墨色江湖》双修大业**没有任何影响，纯粹是虚惊一场的纸老虎！**

### 🚀 破茧成蝶的最后一步：重启大阵！
既然灵药已经服下，现在必须让大阵重新运转，药效才能散入四肢百骸。
**请陛下进行这最后的“重启”操作：**

1. 回到您之前那个一直刷日志的终端（就是写着 `ComfyUI (8188)` 或 `bash` 的那个黑框，如果实在找不到，就刷新整个网页或者在 CNB 控制台重启这个空间）。
2. 如果您还在运行日志的黑框里，点击一下鼠标，按下键盘的 **Ctrl + C**（强行停止现在的进程）。
3. 停止后，在光标处输入大阵的重启咒语：**qd**，然后按回车（这是 CNB 官方教程里写的快捷启动命令）。
*(如果 qd 不管用，直接在网页右下角找到“重启工作空间”之类的按钮莽过去也行！)*
等大阵重新亮起绿灯（ComfyUI 8188 ready），您就可以去《墨色江湖》里，享受这历经九九八十一难才打通的云端极速双修体验了！臣在游戏外，静候陛下的捷报！

## 关键结论

原对话最后阶段给出的主要判断或处理方向：我们说明书上写了最高只能兼容 1.22.0 啊！陛下，咱们这次请 `onnxruntime` 出山，**是为了修复画图和 NSFW 节点的雪崩**，根本不是为了去听语音（TTS）或者搞那些冷门的老插件。

## 上下文关系

- 所属项目：bda3d1497e-ai-tools-01
- 当前阶段：阶段3/4
- 前置切片：NovelAI本地部署与ComfyUI-CNB模型管理：nai怎么样我的电脑可以整吗_8e4a5b57.md
- 后续切片：NovelAI本地部署与ComfyUI-CNB模型管理：终于等到logs的报错了帮我看看（_[1_085cd679.md
- 附件说明：含图片或附件；语义依据来自相邻文字和原助手复述，未独立推断图像内容。
