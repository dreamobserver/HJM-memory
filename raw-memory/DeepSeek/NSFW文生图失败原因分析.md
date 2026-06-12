# 用户：

这是cnb的logs帮我看看为什么我的nsfw文生图没有成功（[NSFW Patch] 正在应用 NSFW 检测禁用补丁...
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
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-easy-use
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Marigold
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/rgthree-comfy
[32m[INFO][0m    4.8 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Manager
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

[38;5;201m ██████╗[38;5;165m██╗   ██╗[38;5;129m██████╗ [38;5;93m███████╗[38;5;57m██████╗ [38;5;21m██████╗ [38;5;27m██╗   ██╗[38;5;33m███╗   ██╗[38;5;39m██╗  ██╗[0m
[38;5;201m██╔════╝[38;5;165m╚██╗ ██╔╝[38;5;129m██╔══██╗[38;5;93m██╔════╝[38;5;57m██╔══██╗[38;5;21m██╔══██╗[38;5;27m██║   ██║[38;5;33m████╗  ██║[38;5;39m██║ ██╔╝[0m
[38;5;201m██║     [38;5;165m ╚████╔╝ [38;5;129m██████╔╝[38;5;93m█████╗  [38;5;57m██████╔╝[38;5;21m██████╔╝[38;5;27m██║   ██║[38;5;33m██╔██╗ ██║[38;5;39m█████╔╝ [0m
[38;5;201m██║     [38;5;165m  ╚██╔╝  [38;5;129m██╔══██╗[38;5;93m██╔══╝  [38;5;57m██╔═══╝ [38;5;21m██╔═══╝ [38;5;27m██║   ██║[38;5;33m██║╚██╗██║[38;5;39m██╔═██╗ [0m
[38;5;201m╚██████╗[38;5;165m   ██║   [38;5;129m██████╔╝[38;5;93m███████╗[38;5;57m██║     [38;5;21m██║     [38;5;27m╚██████╔╝[38;5;33m██║ ╚████║[38;5;39m██║  ██╗[0m
[38;5;201m ╚═════╝[38;5;165m   ╚═╝   [38;5;129m╚═════╝ [38;5;93m╚══════╝[38;5;57m╚═╝     [38;5;21m╚═╝     [38;5;27m ╚═════╝ [38;5;33m╚═╝  ╚═══╝[38;5;39m╚═╝  ╚═╝[0m

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
[32m01:02:30[0m | [36m        __init__:11[0m | [1m    INFO[0m | [1mLoading HunyuanVideo-Foley nodes with FP8 quantization and torch.compile support[0m
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
[32m01:02:39[0m | [36m            node:135[0m | [1m    INFO[0m | [1mWBLESS 23 nodes loaded[0m
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
   ⚠️  警告: 此模型已移除安全过滤，可能生成敏感内容。仅用于研究和测试环境。

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
2026-05-26 01:02:39.994 | INFO     | cozy_comfyui.node:loader:135 - WBLESS 23 nodes loaded
[32m01:02:39[0m | [36m            node:135[0m | [1m    INFO[0m | [1mWBLESS 23 nodes loaded[0m
2026-05-26 01:02:39.995 | INFO     | cozy_comfyui.node:loader:135 - WBLESS 23 nodes loaded
[36;20m[/workspace/comfyui/custom_nodes_preset/comfy_mtb] | INFO -> loaded [96m110[0m nodes successfuly[0m
[36;20m[/workspace/comfyui/custom_nodes_preset/comfy_mtb] | INFO -> Some nodes (3) could not be loaded. This can be ignored, but go to http://None:8188/mtb if you want more information.[0m
[32m[INFO][0m ComfyUI-GGUF: Allowing full torch compile
[LongCatAudioDiT] Models folder registered: /workspace/comfyui/models/audiodit
[LongCatAudioDiT] Registered 3 nodes (v0.1.9): LongCat AudioDiT TTS, LongCat AudioDiT Voice Clone TTS, LongCat AudioDiT Multi-Speaker TTS
Error loading /workspace/comfyui/custom_nodes_preset/ComfyUI-RMBG/py/AILab_BodySegment.py: No module named 'onnxruntime'
Error loading /workspace/comfyui/custom_nodes_preset/ComfyUI-RMBG/py/AILab_BodySegment.py: No module named 'onnxruntime'
[34m[ComfyUI-RMBG][0m v[93m3.0.0[0m | [93m42 nodes[0m [92mLoaded[0m
[35m
⣏⡉ ⡇    ⡎⠑ ⢀⡀ ⢀⣀ ⡀⢀ ⡇⢸ ⢀⡀ ⠄ ⢀⣀ ⢀⡀ ⢉⡹
⠇  ⠧⠤   ⠣⠔ ⠣⠜ ⠭⠕ ⣑⡺ ⠸⠃ ⠣⠜ ⠇ ⠣⠤ ⠣⠭ ⠤⠜
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

__     ______   ____                      ____              ____ _      _ 
\ \   / /  _ \ / ___| __ _ _ __ ___   ___|  _ \  _____   __/ ___(_)_ __| |
 \ \ / /| |_) | |  _ / _` | '_ ` _ \ / _ \ | | |/ _ \ \ / / |  _| | '__| |
  \ V / |  _ <| |_| | (_| | | | | | |  __/ |_| |  __/\ V /| |_| | | |  | |
   \_/  |_| \_\\____|\__,_|_| |_| |_|\___|____/ \___| \_/  \____|_|_|  |_|
                                                                          
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
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes/msjh_default_workflow
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/websocket_image_save.py
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes/websocket_image_save.py
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-PainterI2V
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/Comfyui-PainterFLF2V
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-GradientBlur
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/CYBERPUNK-STYLE-DIY
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/Comfyui-PainterFluxImageEdit
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_AdvancedRefluxControl
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/KOOK_ImageCompression
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-PainterQwenImageEdit
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_YOLO_For_Multi_SDPose_Detection
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-QZ_plugins
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-preview360panorama
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/Comfyui-Memory_Cleanup
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfy-image-saver
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/HeartMuLa_ComfyUI
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-openpose-editor
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyLiterals
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/Comfyui_SynVow_Qwen3ASR
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_ADV_CLIP_emb
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-imagesubfolders
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-ZImageLatent
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-SplitString
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-DD-Translation
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Jjk-Nodes
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/stability-ComfyUI-nodes
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-saveimage-plus
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Detail-Daemon
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-GLM4
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-fitsize
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_Text_Translation
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-WanMoeKSampler
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-SAM2
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-ReservedVRAM
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-OpenAI-FM
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_FaceSimilarity
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-qwenmultianglelight
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-wanBlockswap
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-IC-Light-Native
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Redux-Prompt
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-VideoBasic
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/qweneditutils
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/erosdiffusion-eulerflowmatchingdiscretescheduler
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Embedding_Picker
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_JPS-Nodes
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-GlifNodes
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Florence2
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Image-Size-Tools
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/Skimmed_CFG
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/masquerade-nodes-comfyui
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-qwenmultiangle
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUi_NNLatentUpscale
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_IPAdapter_plus
[32m[INFO][0m    0.0 seconds (IMPORT FAILED): /workspace/comfyui/custom_nodes_preset/ComfyUI-WD14-Tagger
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-ModelScope-API
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/cg-use-everywhere
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/joycaption_comfyui
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Janus-Pro
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Inpaint-CropAndStitch
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-SCAIL-Pose
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUi-RadarWeightNode
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-LTXVideoLoRA
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/a-person-mask-generator
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-ATk-Nodes
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-post-processing-nodes
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-FBCNN
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/qq-nodes-comfyui
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/Latent_Nodes
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-seedvr2-tilingupscaler
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyQR
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-MelBandRoFormer
[32m[INFO][0m    0.0 seconds (IMPORT FAILED): /workspace/comfyui/custom_nodes_preset/PuLID_ComfyUI
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-WanStartEndFramesNative
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-PainterLTXV2
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-EulerDiscreteScheduler
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Impact-Subpack
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/qwen-image-integrated-ksampler
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui_GaussianViewer
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/Comfyui-In-Context-Lora-Utils
[32m[INFO][0m    0.0 seconds (IMPORT FAILED): /workspace/comfyui/custom_nodes_preset/rembg-comfyui-node-better
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-flux2fun-controlnet
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/Comfyui_TTP_Toolset
[32m[INFO][0m    0.0 seconds (IMPORT FAILED): /workspace/comfyui/custom_nodes_preset/ComfyUI_PuLID_Flux_ll
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-PromptRelay
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-GGUF
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/efficiency-nodes-comfyui
[32m[INFO][0m    0.0 seconds (IMPORT FAILED): /workspace/comfyui/custom_nodes_preset/ComfyUI-WanAnimatePreprocess
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-lama-remover
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-InpaintEasy
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Whisper
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_StringOps
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-LG_SamplingUtils
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-IC-Light
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/images_base64
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/cg-image-filter
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/Comfyui-Mk-tools
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-LongCat-AudioDIT-TTS
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-DyPE
[32m[INFO][0m    0.0 seconds (IMPORT FAILED): /workspace/comfyui/custom_nodes_preset/ComfyUI_InstantID
[32m[INFO][0m    0.0 seconds (IMPORT FAILED): /workspace/comfyui/custom_nodes_preset/ComfyUI-llama-cpp_vlm
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/LanPaint
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-AutoCropFaces
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-IPAdapter-Flux
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/fastvideo
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Advanced-ControlNet
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Wan22FMLF
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-DepthAnythingV2
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-TeaCache
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/VibeVoice-ComfyUI
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-inpaint-nodes
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyMath
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/WhatDreamsCost-ComfyUI
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Video-Matting
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_FizzNodes
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_essentials
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_Patches_ll
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-tooling-nodes
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-layerdiffuse
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-fastblend
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Marigold
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Image-Saver
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-QwenVL
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-nunchaku
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-advancedliveportrait
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-StringsAndThings
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/OneButtonPrompt
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_VNCCS_Utils
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_UltimateSDUpscale
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-various
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-custom-scripts
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_QwenVL
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui_fl-cosyvoice3
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-FramePackWrapper_PlusOne
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-IndexTTS2
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ControlAltAI-Nodes
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-MingNodes
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_VNCCS
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui_controlnet_aux
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-BrushNet
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-WanVideoStartEndFrames
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/x-flux-comfyui
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Frame-Interpolation
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-BodyRatioMapper
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-QwenImageLoraLoader
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/Flux-Prompt-Generator
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_Qwen3-VL-Instruct
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/Comfyui_LG_Tools
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-segment-anything-2
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_Sonic
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-cogvideoxwrapper
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-YCNodes
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/flashvsr_ultra_fast
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/Comfyui_PDuse
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Qwen-TTS
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-ppm
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-TD-Qwen3TTS
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Prompt-Assistant
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-SeedVR2_VideoUpscaler
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-KJNodes
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-LBM
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/rgthree-comfy
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_Comfyroll_CustomNodes
[32m[INFO][0m    0.0 seconds: /workspace/.cnb-xu/custom_nodes/ComfyUI-CNB-Xu
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/Comfyui-SecNodes
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-GIMM-VFI
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-UniversalToolkit
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Sharp
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/wavespeed-comfyui
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-LMCQ
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-VoxCPM2
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Inspire-Pack
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/comfyui_segment_anything
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-HunyuanVideoWrapper
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Qwen3VL-DP
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-AnimateDiff-Evolved
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Anyline
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-VideoHelperSuite
[32m[INFO][0m    0.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-LTXVideo
[32m[INFO][0m    0.1 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Crystools
[32m[INFO][0m    0.1 seconds: /workspace/comfyui/custom_nodes_preset/audiotools
[32m[INFO][0m    0.1 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-vrgamedevgirl
[32m[INFO][0m    0.1 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-WBLESS
[32m[INFO][0m    0.1 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-to-python-extension
[32m[INFO][0m    0.1 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Impact-Pack
[32m[INFO][0m    0.1 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_LayerStyle
[32m[INFO][0m    0.1 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-tensorops
[32m[INFO][0m    0.1 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-UVR5
[32m[INFO][0m    0.1 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-easy-use
[32m[INFO][0m    0.1 seconds: /workspace/comfyui/custom_nodes_preset/comfy_mtb
[32m[INFO][0m    0.1 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-RMBG
[32m[INFO][0m    0.1 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_Muye
[32m[INFO][0m    0.1 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_HunyuanVideoFoley
[32m[INFO][0m    0.1 seconds: /workspace/comfyui/custom_nodes_preset/CRT-Nodes
[32m[INFO][0m    0.1 seconds: /workspace/comfyui/custom_nodes_preset/D2-SavePSD-ComfyUI
[32m[INFO][0m    0.1 seconds: /workspace/comfyui/custom_nodes_preset/RES4LYF
[32m[INFO][0m    0.2 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_LayerStyle_Advance
[32m[INFO][0m    0.2 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-art-venture
[32m[INFO][0m    0.2 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-ollama
[32m[INFO][0m    0.3 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-WanVideoWrapper
[32m[INFO][0m    0.3 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-utils-nodes
[32m[INFO][0m    0.3 seconds (IMPORT FAILED): /workspace/comfyui/custom_nodes_preset/Comfy-RVC
[32m[INFO][0m    0.4 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-supir
[32m[INFO][0m    0.4 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Easy-Sam3
[32m[INFO][0m    0.6 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_Seed-VC
[32m[INFO][0m    0.7 seconds: /workspace/comfyui/custom_nodes_preset/audio-separation-nodes-comfyui
[32m[INFO][0m    0.7 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_Pops
[32m[INFO][0m    0.7 seconds (IMPORT FAILED): /workspace/comfyui/custom_nodes_preset/ComfyUI-Allor
[32m[INFO][0m    0.8 seconds: /workspace/comfyui/custom_nodes_preset/comfyui-mixlab-nodes
[32m[INFO][0m    0.8 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Apt_Preset
[32m[INFO][0m    0.9 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_SLK_joy_caption_two
[32m[INFO][0m    1.0 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Manager
[32m[INFO][0m    1.3 seconds (IMPORT FAILED): /workspace/comfyui/custom_nodes_preset/ComfyUI_parakeet-tdt
[32m[INFO][0m    1.5 seconds: /workspace/comfyui/custom_nodes_preset/was-node-suite-comfyui
[32m[INFO][0m    1.6 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_YuE
[32m[INFO][0m    1.6 seconds: /workspace/comfyui/custom_nodes_preset/sdpose-ood
[32m[INFO][0m    1.7 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-Inspyrenet-Rembg
[32m[INFO][0m    1.7 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI-VoxCPM
[32m[INFO][0m    2.0 seconds: /workspace/comfyui/custom_nodes_preset/kokorotts_mw
[32m[INFO][0m    2.4 seconds: /workspace/comfyui/custom_nodes_preset/ComfyUI_Custom_Nodes_AlekPet
[32m[INFO][0m    5.5 seconds: /workspace/comfyui/custom_nodes_preset/seedvr2_videoupscaler
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
{"ok":true,"forwarded":false,"registryStored":true,"payload":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:07:48.723Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:07:48.723Z","connectTokenProtected":true,"source":"registry"},"item":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:07:48.723Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:07:48.723Z","connectTokenProtected":true,"source":"registry"}}heartbeat ok Tue May 26 01:07:49 CST 2026
{"ok":true,"forwarded":false,"registryStored":true,"payload":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:08:49.325Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:08:49.325Z","connectTokenProtected":true,"source":"registry"},"item":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:08:49.325Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:08:49.325Z","connectTokenProtected":true,"source":"registry"}}heartbeat ok Tue May 26 01:08:49 CST 2026
{"ok":true,"forwarded":false,"registryStored":true,"payload":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:09:49.951Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:09:49.951Z","connectTokenProtected":true,"source":"registry"},"item":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:09:49.951Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:09:49.951Z","connectTokenProtected":true,"source":"registry"}}heartbeat ok Tue May 26 01:09:50 CST 2026
{"ok":true,"forwarded":false,"registryStored":true,"payload":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:10:50.501Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:10:50.501Z","connectTokenProtected":true,"source":"registry"},"item":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:10:50.501Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:10:50.501Z","connectTokenProtected":true,"source":"registry"}}heartbeat ok Tue May 26 01:10:50 CST 2026
{"ok":true,"forwarded":false,"registryStored":true,"payload":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:11:51.164Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:11:51.164Z","connectTokenProtected":true,"source":"registry"},"item":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:11:51.164Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:11:51.164Z","connectTokenProtected":true,"source":"registry"}}heartbeat ok Tue May 26 01:11:51 CST 2026
{"ok":true,"forwarded":false,"registryStored":true,"payload":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:12:51.810Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:12:51.810Z","connectTokenProtected":true,"source":"registry"},"item":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:12:51.810Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:12:51.810Z","connectTokenProtected":true,"source":"registry"}}heartbeat ok Tue May 26 01:12:52 CST 2026
{"ok":true,"forwarded":false,"registryStored":true,"payload":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:13:52.369Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:13:52.369Z","connectTokenProtected":true,"source":"registry"},"item":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:13:52.369Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:13:52.369Z","connectTokenProtected":true,"source":"registry"}}heartbeat ok Tue May 26 01:13:52 CST 2026
{"ok":true,"forwarded":false,"registryStored":true,"payload":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:14:52.994Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:14:52.994Z","connectTokenProtected":true,"source":"registry"},"item":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:14:52.994Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:14:52.994Z","connectTokenProtected":true,"source":"registry"}}heartbeat ok Tue May 26 01:14:53 CST 2026
{"ok":true,"forwarded":false,"registryStored":true,"payload":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:15:53.583Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:15:53.583Z","connectTokenProtected":true,"source":"registry"},"item":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:15:53.583Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:15:53.583Z","connectTokenProtected":true,"source":"registry"}}heartbeat ok Tue May 26 01:15:54 CST 2026
{"ok":true,"forwarded":false,"registryStored":true,"payload":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:16:54.197Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:16:54.197Z","connectTokenProtected":true,"source":"registry"},"item":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:16:54.197Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:16:54.197Z","connectTokenProtected":true,"source":"registry"}}heartbeat ok Tue May 26 01:16:54 CST 2026
{"ok":true,"forwarded":false,"registryStored":true,"payload":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:17:54.777Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:17:54.777Z","connectTokenProtected":true,"source":"registry"},"item":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:17:54.777Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:17:54.777Z","connectTokenProtected":true,"source":"registry"}}heartbeat ok Tue May 26 01:17:55 CST 2026
{"ok":true,"forwarded":false,"registryStored":true,"payload":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:18:55.346Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:18:55.346Z","connectTokenProtected":true,"source":"registry"},"item":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:18:55.346Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:18:55.346Z","connectTokenProtected":true,"source":"registry"}}heartbeat ok Tue May 26 01:18:55 CST 2026
{"ok":true,"forwarded":false,"registryStored":true,"payload":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:19:56.037Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:19:56.037Z","connectTokenProtected":true,"source":"registry"},"item":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:19:56.037Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:19:56.037Z","connectTokenProtected":true,"source":"registry"}}heartbeat ok Tue May 26 01:19:56 CST 2026
[1m[33m[WARNING][0m [DEPRECATION WARNING] Detected import of deprecated legacy API: /scripts/ui.js. This is likely caused by a custom node extension using outdated APIs. Please update your extensions or contact the extension author for an updated version.
[1m[33m[WARNING][0m [DEPRECATION WARNING] Detected import of deprecated legacy API: /extensions/core/widgetInputs.js. This is likely caused by a custom node extension using outdated APIs. Please update your extensions or contact the extension author for an updated version.
[1m[33m[WARNING][0m [DEPRECATION WARNING] Detected import of deprecated legacy API: /extensions/core/clipspace.js. This is likely caused by a custom node extension using outdated APIs. Please update your extensions or contact the extension author for an updated version.
[1m[33m[WARNING][0m [DEPRECATION WARNING] Detected import of deprecated legacy API: /scripts/ui/components/buttonGroup.js. This is likely caused by a custom node extension using outdated APIs. Please update your extensions or contact the extension author for an updated version.
[1m[33m[WARNING][0m [DEPRECATION WARNING] Detected import of deprecated legacy API: /extensions/core/groupNode.js. This is likely caused by a custom node extension using outdated APIs. Please update your extensions or contact the extension author for an updated version.
[VibeVoice] Created vibevoice models directory: /workspace/comfyui/models/vibevoice
[VibeVoice] No LoRA adapters found in ComfyUI/models/vibevoice/loras
[1m[33m[WARNING][0m Resolved SeedVR2 models via node registry: 6 models.
[1m[33m[WARNING][0m Resolved SeedVR2 default via node registry: seedvr2_ema_3b_fp8_e4m3fn.safetensors
[1m[33m[WARNING][0m Resolved SeedVR2 models via node registry: 6 models.
[1m[33m[WARNING][0m Resolved SeedVR2 default via node registry: seedvr2_ema_3b_fp8_e4m3fn.safetensors
[32m[INFO][0m [WaveSpeed Config] API key deleted via settings
[1m[33m[WARNING][0m [DEPRECATION WARNING] Detected import of deprecated legacy API: /scripts/ui/components/button.js. This is likely caused by a custom node extension using outdated APIs. Please update your extensions or contact the extension author for an updated version.
{"ok":true,"forwarded":false,"registryStored":true,"payload":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:20:56.644Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:20:56.644Z","connectTokenProtected":true,"source":"registry"},"item":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:20:56.644Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:20:56.644Z","connectTokenProtected":true,"source":"registry"}}heartbeat ok Tue May 26 01:20:57 CST 2026
{"ok":true,"forwarded":false,"registryStored":true,"payload":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:21:57.233Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:21:57.233Z","connectTokenProtected":true,"source":"registry"},"item":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:21:57.233Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:21:57.233Z","connectTokenProtected":true,"source":"registry"}}heartbeat ok Tue May 26 01:21:57 CST 2026
{"ok":true,"forwarded":false,"registryStored":true,"payload":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:22:57.875Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:22:57.875Z","connectTokenProtected":true,"source":"registry"},"item":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:22:57.875Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:22:57.875Z","connectTokenProtected":true,"source":"registry"}}heartbeat ok Tue May 26 01:22:58 CST 2026
{"ok":true,"forwarded":false,"registryStored":true,"payload":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:23:58.475Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:23:58.475Z","connectTokenProtected":true,"source":"registry"},"item":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:23:58.475Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:23:58.475Z","connectTokenProtected":true,"source":"registry"}}heartbeat ok Tue May 26 01:23:58 CST 2026
{"ok":true,"forwarded":false,"registryStored":true,"payload":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:24:59.081Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:24:59.081Z","connectTokenProtected":true,"source":"registry"},"item":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:24:59.081Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:24:59.081Z","connectTokenProtected":true,"source":"registry"}}heartbeat ok Tue May 26 01:24:59 CST 2026
{"ok":true,"forwarded":false,"registryStored":true,"payload":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:25:59.647Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:25:59.647Z","connectTokenProtected":true,"source":"registry"},"item":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:25:59.647Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:25:59.647Z","connectTokenProtected":true,"source":"registry"}}heartbeat ok Tue May 26 01:26:00 CST 2026
{"ok":true,"forwarded":false,"registryStored":true,"payload":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:27:00.321Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:27:00.321Z","connectTokenProtected":true,"source":"registry"},"item":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:27:00.321Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:27:00.321Z","connectTokenProtected":true,"source":"registry"}}heartbeat ok Tue May 26 01:27:00 CST 2026
{"ok":true,"forwarded":false,"registryStored":true,"payload":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:28:01.125Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:28:01.125Z","connectTokenProtected":true,"source":"registry"},"item":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:28:01.125Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:28:01.125Z","connectTokenProtected":true,"source":"registry"}}heartbeat ok Tue May 26 01:28:01 CST 2026
[VibeVoice] No valid models found in vibevoice directory
[VibeVoice] Please download models to: /workspace/comfyui/models/vibevoice
[1m[33m[WARNING][0m Resolved SeedVR2 models via node registry: 6 models.
[1m[33m[WARNING][0m Resolved SeedVR2 default via node registry: seedvr2_ema_3b_fp8_e4m3fn.safetensors
[1m[33m[WARNING][0m Resolved SeedVR2 models via node registry: 6 models.
[1m[33m[WARNING][0m Resolved SeedVR2 default via node registry: seedvr2_ema_3b_fp8_e4m3fn.safetensors
{"ok":true,"forwarded":false,"registryStored":true,"payload":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:29:01.729Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:29:01.729Z","connectTokenProtected":true,"source":"registry"},"item":{"customerId":"dreamobserve/comfyui-ql","backendType":"comfyui","port":8188,"url":"https://j3rxd5ritf-8188.cnb.run","healthUrl":"https://j3rxd5ritf-8188.cnb.run/system_stats","detectedFrom":"CNB_VSCODE_PROXY_URI","detectedAt":"2026-05-25T17:29:01.729Z","workspace":"dreamobserve/comfyui-ql","id":"backend:comfyui:dreamobserve/comfyui-ql:dreamobserve/comfyui-ql","label":"dreamobserve/comfyui-ql","lastHeartbeatAt":"2026-05-25T17:29:01.729Z","connectTokenProtected":true,"source":"registry"}}heartbeat ok Tue May 26 01:29:02 CST 2026
）

# DeepSeek：

**原始回答**

看了你的日志，NSFW 文生图失败，**核心原因不是 NSFW 补丁没生效，而是 ComfyUI 环境里缺少了关键的 `onnxruntime` 依赖库**。

这个库的缺失，导致了一连串与 NSFW 检测或图像处理相关的自定义节点加载失败。

### 关键错误分析
日志中最关键的错误信息是重复出现的：
`ModuleNotFoundError: No module named 'onnxruntime'`

`onnxruntime` 是运行 ONNX 模型所必需的。你日志里包含 NSFW 过滤功能的几个重要节点都因此崩溃了：

*   **直接相关的 NSFW 节点**：`ComfyUI-utils-nodes` 里的 `node_nsfw.py` 直接依赖它。这是最可能直接导致你 NSFW 检测功能失效的节点。
*   **可能辅助 NSFW 检测的节点**：
    *   `ComfyUI-WD14-Tagger` (日志提示需要 `onnxruntime`)
    *   `PuLID_ComfyUI` 和 `ComfyUI_PuLID_Flux_ll` (虽然用于换脸，但有面部检测功能)
*   **其他失败的关联节点**：`rembg` (移除背景), `ComfyUI-Allor`, `Comfy-RVC` 等，虽然不直接处理 NSFW，但它们的失败表明 `onnxruntime` 缺失是整个环境的系统性问题。

### 解决步骤
问题的根源找到了，解决方法很直接，就是在你的 ComfyUI 环境里把这个库装上。

1.  **通过命令行安装缺失的库**
    在 CNB 的终端里执行下面这行命令。确保你是在 ComfyUI 使用的 Python 环境下运行。
    ```bash
    /workspace/venv/bin/pip install onnxruntime
    ```

2.  **重启 ComfyUI**
    安装完成后，需要重启 ComfyUI 服务，让所有之前加载失败的节点重新加载一次。重启后你应该能看到这些节点的成功加载信息，不再有 `[WARNING]` 或 `IMPORT FAILED` 的提示。

3.  **（可选的）修复其他缺失库**
    日志里还提到了另一个缺失的库 `llama_cpp`，虽然它和 NSFW 关系不大，但如果你后续要用到 `ComfyUI-llama-cpp_vlm` 这个节点，也可以顺手装上：
    ```bash
    /workspace/venv/bin/pip install llama-cpp-python
    ```

重新生成前，你也可以留意一下日志，确认所有相关节点都加载成功了。执行了上面的步骤后，能解决你遇到的问题吗？如果还有新的报错，可以再发给我看看。

# 用户：

直接重启网页后我怎么知道有没有安装成功？

# DeepSeek：

**原始回答**

判断 `onnxruntime` 是否安装成功，不能只刷新浏览器网页，**必须先重启 ComfyUI 服务**，再检查启动日志。

### 1. 正确重启 ComfyUI 服务
只刷新网页不会让 Python 后端重新加载，必须让 ComfyUI 进程重启。在 CNB 终端中执行：
```bash
# 先停止当前 ComfyUI（通常按 Ctrl+C），再重新启动。
# 如果你是通过某个启动脚本运行的，重新运行该脚本即可。
```
重启后，终端会再次打印一串启动日志。

### 2. 查看启动日志中的关键信息
在重新滚动的日志里，重点查找以下**之前报错**的节点，现在应该**不再出现** `ModuleNotFoundError: No module named 'onnxruntime'`。

- **ComfyUI-utils-nodes**：这是直接包含 NSFW 检测节点的模块。
  之前日志中有：
  > `File ".../ComfyUI-utils-nodes/py/node_nsfw.py", line 3, in <module> ... import onnxruntime`
  成功安装后，应该能看到类似：
  > `[INFO] Loaded node: NudeDetector` 或不再有该文件的报错。

- **ComfyUI-WD14-Tagger**：之前日志提示 `[ERROR] onnxruntime is required...`，成功后会正常加载。

- **rembg-comfyui-node-better** 与 **ComfyUI-Allor** 等：它们的加载错误也会消失。

你也可以在终端搜索关键字 `onnxruntime`，如果**只有成功提示而没有错误**，就是安装好了：
```bash
grep -i "onnxruntime" /path/to/comfyui.log   # 如果有日志文件的话
```

### 3. 在 ComfyUI 界面上简单验证
重启后进入 ComfyUI 网页界面，可以尝试以下操作：
- 在节点搜索框输入 `NudeDetector` 或 `NudeFilter`（来自 ComfyUI-utils-nodes），如果能看到节点并能拖放到画布上，说明该模块已正常加载。
- 运行一个简单的 NSFW 检测工作流（比如用一张普通图片测试），如果没有报错 `ModuleNotFoundError: onnxruntime`，就证明依赖库已生效。

### 4. 终极确认：在终端直接验证库是否安装
在终端运行以下命令，如果出现安装路径而不是报错，说明库已存在：
```bash
/workspace/venv/bin/pip show onnxruntime
```
会输出类似：
```
Name: onnxruntime
Version: 1.xx.x
...
```

如果之前还安装了 `llama-cpp-python`，也可以用同样方式确认。

完成这些检查后，你的 NSFW 检测依赖就齐全了。如果重启后日志中仍有奇怪报错，可以把新的日志片段发给我，我再帮你看。

# 用户：

排查后发现问题在前端这是GitHub上其名称为__tests__/nsfwImageGeneration.test.ts的代码分析一下是否有问题import { afterEach, describe, expect, it, vi } from 'vitest';
import {
    获取NSFW文生图接口配置,
    生图接口支持NSFW,
    获取文生图接口配置,
    获取场景文生图接口配置,
    用已发现ComfyUI后端替换地址,
    刷新已发现ComfyUI后端缓存,
    清空已发现ComfyUI后端缓存,
    接口配置是否可用,
    规范化接口设置,
    创建空接口设置,
    默认功能模型占位
} from '../utils/apiConfig';
import type { 接口设置结构 } from '../models/system';
import {
    构建运行时额外提示词,
    构建文生图运行时额外提示词,
    默认NSFW模式提示词,
    默认文生图NSFW模式提示词
} from '../prompts/runtime/nsfw';

const 构建测试接口设置 = (overrides?: Partial<{
    文生图功能启用: boolean;
    文生图后端类型: string;
    文生图模型使用模型: string;
    文生图模型API地址: string;
    文生图模型API密钥: string;
    NSFW生图独立接口启用: boolean;
    NSFW生图后端类型: string;
    NSFW生图模型使用模型: string;
    NSFW生图模型API地址: string;
    NSFW生图模型API密钥: string;
    NSFWComfyUI工作流JSON: string;
    场景生图独立接口启用: boolean;
    场景生图后端类型: string;
    主接口baseUrl: string;
    主接口apiKey: string;
    主接口model: string;
}>): 接口设置结构 => {
    return {
        activeConfigId: 'default',
        configs: [{
            id: 'default',
            名称: '默认配置',
            供应商: 'openai_compatible',
            协议覆盖: 'auto',
            baseUrl: overrides?.主接口baseUrl || 'https://api.example.com',
            apiKey: overrides?.主接口apiKey || 'test-key',
            model: overrides?.主接口model || 'gpt-4',
            maxTokens: 4096,
            temperature: 0.7,
            createdAt: Date.now(),
            updatedAt: Date.now()
        }],
        功能模型占位: {
            ...默认功能模型占位,
            文生图功能启用: overrides?.文生图功能启用 ?? true,
            文生图后端类型: (overrides?.文生图后端类型 as any) || 'sd_webui',
            文生图模型使用模型: overrides?.文生图模型使用模型 || 'sd-v1',
            文生图模型API地址: overrides?.文生图模型API地址 || 'http://localhost:7860',
            文生图模型API密钥: overrides?.文生图模型API密钥 || '',
            NSFW生图独立接口启用: overrides?.NSFW生图独立接口启用 ?? false,
            NSFW生图后端类型: (overrides?.NSFW生图后端类型 as any) || 'sd_webui',
            NSFW生图模型使用模型: overrides?.NSFW生图模型使用模型 || '',
            NSFW生图模型API地址: overrides?.NSFW生图模型API地址 || '',
            NSFW生图模型API密钥: overrides?.NSFW生图模型API密钥 || '',
            NSFWComfyUI工作流JSON: overrides?.NSFWComfyUI工作流JSON || '',
            场景生图独立接口启用: overrides?.场景生图独立接口启用 ?? false,
            场景生图后端类型: (overrides?.场景生图后端类型 as any) || 'sd_webui'
        }
    };
};

afterEach(() => {
    清空已发现ComfyUI后端缓存();
    vi.restoreAllMocks();
});

const 模拟已发现ComfyUI后端 = async (items: Array<{ id: string; url: string; lastHeartbeatAt: string }>) => {
    vi.spyOn(globalThis, 'fetch').mockResolvedValue({
        ok: true,
        json: async () => ({
            ok: true,
            items: items.map((item) => ({
                id: item.id,
                customerId: 'test',
                label: item.id,
                backendType: 'comfyui',
                port: 8188,
                url: item.url,
                detectedAt: item.lastHeartbeatAt,
                lastHeartbeatAt: item.lastHeartbeatAt,
                source: 'registry'
            }))
        }),
        text: async () => ''
    } as Response);
    await 刷新已发现ComfyUI后端缓存('https://registry.example', 'token');
};

describe('生图接口支持NSFW', () => {
    it('returns false for null config', () => {
        expect(生图接口支持NSFW(null)).toBe(false);
    });

    it('returns false for OpenAI backend', () => {
        expect(生图接口支持NSFW({
            id: 'test',
            名称: 'test',
            供应商: 'openai',
            协议覆盖: 'auto',
            baseUrl: 'https://api.openai.com',
            apiKey: 'key',
            model: 'dall-e-3',
            maxTokens: 0,
            temperature: 0,
            图片后端类型: 'openai',
            图片接口路径模式: 'preset',
            图片预设接口路径: 'openai_images',
            图片接口路径: '/v1/images/generations',
            图片响应格式: 'url',
            图片走OpenAI自定义格式: false,
            NPC生图使用词组转化器: false
        })).toBe(false);
    });

    it('returns true for SD WebUI backend', () => {
        expect(生图接口支持NSFW({
            id: 'test',
            名称: 'test',
            供应商: 'openai_compatible',
            协议覆盖: 'auto',
            baseUrl: 'http://localhost:7860',
            apiKey: '',
            model: '',
            maxTokens: 0,
            temperature: 0,
            图片后端类型: 'sd_webui',
            图片接口路径模式: 'preset',
            图片预设接口路径: 'sd_txt2img',
            图片接口路径: '/sdapi/v1/txt2img',
            图片响应格式: 'url',
            图片走OpenAI自定义格式: false,
            NPC生图使用词组转化器: true
        })).toBe(true);
    });

    it('returns true for ComfyUI backend', () => {
        expect(生图接口支持NSFW({
            id: 'test',
            名称: 'test',
            供应商: 'openai_compatible',
            协议覆盖: 'auto',
            baseUrl: 'http://localhost:8188',
            apiKey: '',
            model: '',
            maxTokens: 0,
            temperature: 0,
            图片后端类型: 'comfyui',
            图片接口路径模式: 'preset',
            图片预设接口路径: 'comfyui_prompt',
            图片接口路径: '/prompt',
            图片响应格式: 'url',
            图片走OpenAI自定义格式: false,
            NPC生图使用词组转化器: true
        })).toBe(true);
    });

    it('returns true for NovelAI backend', () => {
        expect(生图接口支持NSFW({
            id: 'test',
            名称: 'test',
            供应商: 'novelai',
            协议覆盖: 'auto',
            baseUrl: 'https://image.novelai.net',
            apiKey: 'token',
            model: 'nai-diffusion-4',
            maxTokens: 0,
            temperature: 0,
            图片后端类型: 'novelai',
            图片接口路径模式: 'preset',
            图片预设接口路径: 'novelai_generate',
            图片接口路径: '/ai/generate-image',
            图片响应格式: 'url',
            图片走OpenAI自定义格式: false,
            NPC生图使用词组转化器: true
        })).toBe(true);
    });

    it('returns false for OpenAI-compatible backend with gpt in model name', () => {
        expect(生图接口支持NSFW({
            id: 'test',
            名称: 'test',
            供应商: 'openai_compatible',
            协议覆盖: 'auto',
            baseUrl: 'https://api.example.com',
            apiKey: 'key',
            model: 'gpt-image-1',
            maxTokens: 0,
            temperature: 0,
            图片后端类型: 'openai',
            图片接口路径模式: 'preset',
            图片预设接口路径: 'openai_images',
            图片接口路径: '/v1/images/generations',
            图片响应格式: 'url',
            图片走OpenAI自定义格式: false,
            NPC生图使用词组转化器: false
        })).toBe(false);
    });
});

describe('接口配置是否可用', () => {
    it('returns false for null', () => {
        expect(接口配置是否可用(null)).toBe(false);
    });

    it('returns true for valid SD WebUI config', () => {
        expect(接口配置是否可用({
            id: 'test',
            名称: 'test',
            供应商: 'openai_compatible',
            协议覆盖: 'auto',
            baseUrl: 'http://localhost:7860',
            apiKey: '',
            model: '',
            maxTokens: 0,
            temperature: 0,
            图片后端类型: 'sd_webui',
            图片接口路径模式: 'preset',
            图片预设接口路径: 'sd_txt2img',
            图片接口路径: '/sdapi/v1/txt2img',
            图片响应格式: 'url',
            图片走OpenAI自定义格式: false,
            NPC生图使用词组转化器: true
        })).toBe(true);
    });
});

describe('获取NSFW文生图接口配置', () => {
    it('returns null when image generation is disabled', () => {
        const settings = 构建测试接口设置({ 文生图功能启用: false });
        expect(获取NSFW文生图接口配置(settings)).toBeNull();
    });

    it('returns null when main config is null', () => {
        const settings = 创建空接口设置();
        expect(获取NSFW文生图接口配置(settings)).toBeNull();
    });

    it('keeps independent ComfyUI NSFW config usable when only the image backend is configured', () => {
        const settings = 构建测试接口设置({
            文生图后端类型: 'comfyui',
            文生图模型API地址: 'https://main-8188.cnb.run',
            NSFW生图独立接口启用: true,
            NSFW生图后端类型: 'comfyui',
            NSFW生图模型API地址: 'https://nsfw-8188.cnb.run'
        });
        settings.configs = [];
        settings.activeConfigId = '';

        const result = 获取NSFW文生图接口配置(settings);

        expect(result?.baseUrl).toBe('https://nsfw-8188.cnb.run');
        expect(result?.图片后端类型).toBe('comfyui');
        expect(接口配置是否可用(result)).toBe(true);
    });

    it('returns shared config when main backend supports NSFW and independent is off', () => {
        const settings = 构建测试接口设置({
            文生图后端类型: 'sd_webui',
            文生图模型API地址: 'http://localhost:7860',
            NSFW生图独立接口启用: false
        });
        const result = 获取NSFW文生图接口配置(settings);
        expect(result).not.toBeNull();
        expect(result?.图片后端类型).toBe('sd_webui');
    });

    it('uses independent NSFW config when enabled', () => {
        const settings = 构建测试接口设置({
            文生图后端类型: 'sd_webui',
            文生图模型API地址: 'http://localhost:7860',
            NSFW生图独立接口启用: true,
            NSFW生图后端类型: 'comfyui',
            NSFW生图模型API地址: 'http://localhost:8188'
        });
        const result = 获取NSFW文生图接口配置(settings);
        expect(result).not.toBeNull();
        expect(result?.图片后端类型).toBe('comfyui');
        expect(result?.baseUrl).toBe('http://localhost:8188');
    });

    it('falls back to main config when independent NSFW has no model for openai backend', () => {
        const settings = 构建测试接口设置({
            文生图后端类型: 'sd_webui',
            文生图模型API地址: 'http://localhost:7860',
            NSFW生图独立接口启用: true,
            NSFW生图后端类型: 'novelai',
            NSFW生图模型使用模型: ''
        });
        const result = 获取NSFW文生图接口配置(settings);
        // When independent NSFW needs a model but none is provided, it falls back
        expect(result).not.toBeNull();
    });

    it('tries fallback when main backend does not support NSFW', () => {
        const settings = 构建测试接口设置({
            文生图后端类型: 'openai',
            文生图模型使用模型: 'dall-e-3',
            文生图模型API地址: 'https://api.openai.com',
            NSFW生图独立接口启用: false
        });
        const result = 获取NSFW文生图接口配置(settings);
        // OpenAI doesn't support NSFW, so it tries fallbacks
        // Without scene config or discovered backends, this returns null
        expect(result).toBeNull();
    });

    it('tries discovered ComfyUI backends as last resort', () => {
        const settings = 构建测试接口设置({
            文生图后端类型: 'openai',
            文生图模型使用模型: 'dall-e-3',
            文生图模型API地址: 'https://api.openai.com',
            NSFW生图独立接口启用: false
        });
        const discovered = [{ url: 'http://localhost:8188' }];
        const result = 获取NSFW文生图接口配置(settings, discovered);
        expect(result).not.toBeNull();
        expect(result?.图片后端类型).toBe('comfyui');
        expect(result?.baseUrl).toBe('http://localhost:8188');
    });

    it('builds customer-facing ComfyUI auto switch config from reported backend', () => {
        const settings = 构建测试接口设置({
            文生图后端类型: 'comfyui',
            文生图模型API地址: 'http://offline-comfyui:8188',
            ComfyUI工作流JSON: '{"1":{"class_type":"KSampler"}}'
        });
        const current = 获取文生图接口配置(settings);
        expect(current).not.toBeNull();
        const result = 用已发现ComfyUI后端替换地址(current!, { url: 'http://online-comfyui:8188/' });
        expect(result?.图片后端类型).toBe('comfyui');
        expect(result?.baseUrl).toBe('http://online-comfyui:8188');
        expect(result?.图片接口路径).toBe('/prompt');
        expect(result?.ComfyUI工作流JSON).toBe(current?.ComfyUI工作流JSON);
        expect(result?.自动切换提示).toContain('已自动切换到在线 ComfyUI 后端');
    });

    it('prefers selected discovered ComfyUI URL over stale saved main URL', async () => {
        await 模拟已发现ComfyUI后端([
            { id: 'backend-old', url: 'https://old-8188.cnb.run', lastHeartbeatAt: '2026-05-13T16:00:00.000Z' },
            { id: 'backend-new', url: 'https://new-8188.cnb.run/', lastHeartbeatAt: '2026-05-13T17:00:00.000Z' }
        ]);
        const settings = 构建测试接口设置({
            文生图后端类型: 'comfyui',
            文生图模型API地址: 'https://old-8188.cnb.run'
        });
        settings.功能模型占位.当前图片后端发现ID = 'backend-new';

        const result = 获取文生图接口配置(settings);

        expect(result?.baseUrl).toBe('https://new-8188.cnb.run');
    });

    it('prefers selected discovered ComfyUI URL for independent scene image config', async () => {
        await 模拟已发现ComfyUI后端([
            { id: 'scene-new', url: 'https://scene-new-8188.cnb.run/', lastHeartbeatAt: '2026-05-13T17:00:00.000Z' }
        ]);
        const settings = 构建测试接口设置({
            文生图后端类型: 'comfyui',
            文生图模型API地址: 'https://main-old-8188.cnb.run',
            场景生图独立接口启用: true,
            场景生图后端类型: 'comfyui'
        });
        settings.功能模型占位.当前场景图片后端发现ID = 'scene-new';
        settings.功能模型占位.场景生图模型API地址 = 'https://scene-old-8188.cnb.run';

        const result = 获取场景文生图接口配置(settings);

        expect(result?.baseUrl).toBe('https://scene-new-8188.cnb.run');
    });

    it('prefers selected discovered ComfyUI URL for independent NSFW image config', async () => {
        await 模拟已发现ComfyUI后端([
            { id: 'nsfw-new', url: 'https://nsfw-new-8188.cnb.run/', lastHeartbeatAt: '2026-05-13T17:00:00.000Z' }
        ]);
        const settings = 构建测试接口设置({
            文生图后端类型: 'sd_webui',
            文生图模型API地址: 'http://localhost:7860',
            NSFW生图独立接口启用: true,
            NSFW生图后端类型: 'comfyui',
            NSFW生图模型API地址: 'https://nsfw-old-8188.cnb.run'
        });
        settings.功能模型占位.当前NSFW图片后端发现ID = 'nsfw-new';

        const result = 获取NSFW文生图接口配置(settings);

        expect(result?.baseUrl).toBe('https://nsfw-new-8188.cnb.run');
    });

    it('uses scene config as fallback for NSFW when scene backend supports it', () => {
        const settings = 构建测试接口设置({
            文生图后端类型: 'openai',
            文生图模型使用模型: 'dall-e-3',
            文生图模型API地址: 'https://api.openai.com',
            NSFW生图独立接口启用: false,
            场景生图独立接口启用: true,
            场景生图后端类型: 'comfyui'
        });
        const result = 获取NSFW文生图接口配置(settings);
        expect(result).not.toBeNull();
    });

    it('builds correct endpoint for ComfyUI NSFW config (different backend from shared)', () => {
        const settings = 构建测试接口设置({
            文生图后端类型: 'sd_webui',
            文生图模型API地址: 'http://localhost:7860',
            NSFW生图独立接口启用: true,
            NSFW生图后端类型: 'comfyui',
            NSFW生图模型API地址: 'http://nsfw-comfyui:8188'
        });
        const result = 获取NSFW文生图接口配置(settings);
        expect(result).not.toBeNull();
        expect(result?.图片后端类型).toBe('comfyui');
        expect(result?.图片接口路径).toBe('/prompt');
    });

    it('builds correct endpoint for SD WebUI NSFW config (different backend from shared)', () => {
        const settings = 构建测试接口设置({
            文生图后端类型: 'comfyui',
            文生图模型API地址: 'http://localhost:8188',
            NSFW生图独立接口启用: true,
            NSFW生图后端类型: 'sd_webui',
            NSFW生图模型API地址: 'http://nsfw-sd:7860'
        });
        const result = 获取NSFW文生图接口配置(settings);
        expect(result).not.toBeNull();
        expect(result?.图片后端类型).toBe('sd_webui');
        expect(result?.图片接口路径).toBe('/sdapi/v1/txt2img');
    });

    it('builds correct endpoint for NovelAI NSFW config (different backend from shared)', () => {
        const settings = 构建测试接口设置({
            文生图后端类型: 'sd_webui',
            文生图模型API地址: 'http://localhost:7860',
            NSFW生图独立接口启用: true,
            NSFW生图后端类型: 'novelai',
            NSFW生图模型使用模型: 'nai-diffusion-4',
            NSFW生图模型API地址: 'https://image.novelai.net'
        });
        const result = 获取NSFW文生图接口配置(settings);
        expect(result).not.toBeNull();
        expect(result?.图片后端类型).toBe('novelai');
        expect(result?.图片接口路径).toBe('/ai/generate-image');
    });
});

describe('NSFW prompt generation', () => {
    it('构建运行时额外提示词 returns NSFW prompt when enabled', () => {
        const result = 构建运行时额外提示词('', { 启用NSFW模式: true });
        expect(result).toContain('NSFW');
        expect(result).toContain('肉棒');
        expect(result).toContain('小穴');
    });

    it('构建运行时额外提示词 returns empty when NSFW disabled', () => {
        const result = 构建运行时额外提示词('', { 启用NSFW模式: false });
        expect(result).toBe('');
    });

    it('构建运行时额外提示词 combines custom prompt with NSFW', () => {
        const result = 构建运行时额外提示词('custom instruction', { 启用NSFW模式: true });
        expect(result).toContain('custom instruction');
        expect(result).toContain('NSFW');
    });

    it('构建运行时额外提示词 returns only custom prompt when NSFW disabled', () => {
        const result = 构建运行时额外提示词('custom instruction', { 启用NSFW模式: false });
        expect(result).toBe('custom instruction');
        expect(result).not.toContain('NSFW');
    });

    it('构建文生图运行时额外提示词 returns image NSFW prompt when enabled', () => {
        const result = 构建文生图运行时额外提示词('', { 启用NSFW模式: true });
        expect(result).toContain('NSFW');
        expect(result).toContain('adult');
        expect(result).toContain('sensual body language');
    });

    it('构建文生图运行时额外提示词 returns empty when NSFW disabled', () => {
        const result = 构建文生图运行时额外提示词('', { 启用NSFW模式: false });
        expect(result).toBe('');
    });

    it('构建文生图运行时额外提示词 combines custom prompt with image NSFW', () => {
        const result = 构建文生图运行时额外提示词('style: dark fantasy', { 启用NSFW模式: true });
        expect(result).toContain('style: dark fantasy');
        expect(result).toContain('NSFW');
        expect(result).toContain('adult');
    });

    it('构建运行时额外提示词 handles undefined options gracefully', () => {
        const result = 构建运行时额外提示词('test', undefined);
        expect(result).toBe('test');
    });

    it('构建文生图运行时额外提示词 handles undefined options gracefully', () => {
        const result = 构建文生图运行时额外提示词('test', undefined);
        expect(result).toBe('test');
    });

    it('构建运行时额外提示词 trims whitespace', () => {
        const result = 构建运行时额外提示词('  custom  ', { 启用NSFW模式: true });
        expect(result.startsWith('custom')).toBe(true);
        expect(result).toContain('NSFW');
    });

    it('构建运行时额外提示词 handles empty custom prompt', () => {
        const result = 构建运行时额外提示词('', { 启用NSFW模式: true });
        expect(result).toBe(默认NSFW模式提示词);
    });

    it('构建文生图运行时额外提示词 handles empty custom prompt', () => {
        const result = 构建文生图运行时额外提示词('', { 启用NSFW模式: true });
        expect(result).toBe(默认文生图NSFW模式提示词);
    });
});

describe('NSFW end-to-end flow simulation', () => {
    it('full flow: SD WebUI independent NSFW with ComfyUI fallback', () => {
        // Step 1: User enables independent NSFW with ComfyUI backend
        const settings = 构建测试接口设置({
            文生图后端类型: 'sd_webui',
            文生图模型API地址: 'http://localhost:7860',
            NSFW生图独立接口启用: true,
            NSFW生图后端类型: 'comfyui',
            NSFW生图模型API地址: 'http://nsfw-comfyui:8188',
            NSFWComfyUI工作流JSON: '{"1":{"class_type":"KSampler"}}'
        });

        // Step 2: Get NSFW config
        const nsfwConfig = 获取NSFW文生图接口配置(settings);
        expect(nsfwConfig).not.toBeNull();

        // Step 3: Verify config is usable
        expect(接口配置是否可用(nsfwConfig)).toBe(true);

        // Step 4: Verify it supports NSFW
        expect(生图接口支持NSFW(nsfwConfig)).toBe(true);

        // Step 5: Verify backend type
        expect(nsfwConfig?.图片后端类型).toBe('comfyui');
        expect(nsfwConfig?.图片接口路径).toBe('/prompt');
    });

    it('full flow: OpenAI main with discovered ComfyUI fallback', () => {
        // Step 1: Main backend is OpenAI (doesn't support NSFW)
        const settings = 构建测试接口设置({
            文生图后端类型: 'openai',
            文生图模型使用模型: 'dall-e-3',
            文生图模型API地址: 'https://api.openai.com',
            NSFW生图独立接口启用: false
        });

        // Step 2: No NSFW config without discovered backends
        const nsfwConfigNoFallback = 获取NSFW文生图接口配置(settings);
        expect(nsfwConfigNoFallback).toBeNull();

        // Step 3: With discovered ComfyUI backend, NSFW becomes available
        const nsfwConfig = 获取NSFW文生图接口配置(settings, [
            { url: 'http://comfyui.local:8188' }
        ]);
        expect(nsfwConfig).not.toBeNull();
        expect(nsfwConfig?.图片后端类型).toBe('comfyui');
        expect(生图接口支持NSFW(nsfwConfig)).toBe(true);
    });

    it('full flow: NSFW prompt injection into image generation', () => {
        // Step 1: User enables NSFW mode
        const gameConfig = { 启用NSFW模式: true };

        // Step 2: Build NSFW image prompt
        const imagePrompt = 构建文生图运行时额外提示词('', gameConfig);
        expect(imagePrompt).toContain('NSFW');
        expect(imagePrompt).toContain('adult');

        // Step 3: Build runtime prompt for story
        const storyPrompt = 构建运行时额外提示词('', gameConfig);
        expect(storyPrompt).toContain('NSFW');
        expect(storyPrompt).toContain('肉棒');

        // Step 4: Custom prompt gets merged
        const customExtra = 'additional style requirement';
        const mergedImagePrompt = 构建文生图运行时额外提示词(customExtra, gameConfig);
        expect(mergedImagePrompt).toContain(customExtra);
        expect(mergedImagePrompt).toContain('NSFW');
    });

    it('full flow: NSFW disabled returns empty prompts', () => {
        const gameConfig = { 启用NSFW模式: false };

        const imagePrompt = 构建文生图运行时额外提示词('', gameConfig);
        expect(imagePrompt).toBe('');

        const storyPrompt = 构建运行时额外提示词('', gameConfig);
        expect(storyPrompt).toBe('');
    });

    it('full flow: NovelAI independent NSFW config', () => {
        const settings = 构建测试接口设置({
            文生图后端类型: 'sd_webui',
            文生图模型API地址: 'http://localhost:7860',
            NSFW生图独立接口启用: true,
            NSFW生图后端类型: 'novelai',
            NSFW生图模型使用模型: 'nai-diffusion-4',
            NSFW生图模型API地址: 'https://image.novelai.net',
            NSFW生图模型API密钥: 'test-token'
        });

        const nsfwConfig = 获取NSFW文生图接口配置(settings);
        expect(nsfwConfig).not.toBeNull();
        expect(nsfwConfig?.图片后端类型).toBe('novelai');
        expect(nsfwConfig?.图片接口路径).toBe('/ai/generate-image');
        expect(nsfwConfig?.apiKey).toBe('test-token');
        expect(生图接口支持NSFW(nsfwConfig)).toBe(true);
    });

    it('full flow: SD WebUI independent NSFW reuses shared connection', () => {
        const settings = 构建测试接口设置({
            文生图后端类型: 'sd_webui',
            文生图模型API地址: 'http://localhost:7860',
            NSFW生图独立接口启用: true,
            NSFW生图后端类型: 'sd_webui',
            NSFW生图模型API地址: '',
            NSFW生图模型API密钥: ''
        });

        const nsfwConfig = 获取NSFW文生图接口配置(settings);
        expect(nsfwConfig).not.toBeNull();
        expect(nsfwConfig?.图片后端类型).toBe('sd_webui');
        // When NSFW URL is empty and backend matches shared, it reuses shared URL
        expect(nsfwConfig?.baseUrl).toBe('http://localhost:7860');
    });
});

# DeepSeek：

**原始回答**

这个测试文件逻辑上很严谨，但它更多是**对理想逻辑的“正向验证”**。如果前端出问题，问题大概率不在测试本身，而在被测试的实际函数（`获取NSFW文生图接口配置` 等）的实现，或者它们运行时读到的**真实配置数据**。

结合你之前的排查，NSFW 失败的根本原因可能是下面几种情况：

### 1. 测试能过，但代码在真实环境下的关键问题
- **从测试里可以看到，`获取NSFW文生图接口配置` 依赖 `设置.功能模型占位.当前NSFW图片后端发现ID` 来匹配已发现的后端。**
  如果你的前端没有正确持久化这个 `发现ID`，或者 CNB 注册中心返回的后端 `id` 和你保存的不一致，就会匹配失败，导致 NSFW 配置为空，从而使用不支持 NSFW 的主接口（比如 OpenAI）去生图，自然会失败。
- **测试中的 `NSFWComfyUI工作流JSON` 是手动传入的**。
  如果你的前端在保存设置时，没有把这个工作流 JSON 真正存进 `功能模型占位`，NSFW 请求体里就没有工作流，ComfyUI 无法执行。

### 2. ComfyUI 后端本身有变数
- 测试依赖 `生图接口支持NSFW` 判断后端是 `comfyui` 就返回 `true`。但如果 ComfyUI 后端因为缺 `onnxruntime`（就像你之前遇到的）实际跑不了 NSFW 模型，返回的图片可能空白或报错。**前端判断“支持”是真，但后端“能不能跑”是另一回事。**

### 3. 前端调用链可能没走到正确分支
- 测试中 `获取NSFW文生图接口配置` 有很多 fallback 逻辑（独立接口 -> 场景接口 -> 已发现后端）。
  如果调用方（比如发送生图请求的模块）没有实际调用这个函数，或者用了另一个获取配置的函数，NSFW 特性就根本没启用。

### 建议的排查方向
1. **检查真实保存的 NSFW 独立接口配置**：在浏览器控制台打印出当前的 `接口设置结构`，重点看 `NSFW生图独立接口启用`、`NSFWComfyUI工作流JSON` 是否和你 UI 上设置的一致。
2. **检查已发现后端匹配**：打印 `已发现ComfyUI后端缓存` 和 `功能模型占位.当前NSFW图片后端发现ID`，确认它们能对应。
3. **打日志确认函数调用**：在 `获取NSFW文生图接口配置` 的返回处加 `console.log`，看实际返回的配置是不是 `null`，以及当时的主接口和独立接口设置是什么。

如果需要，我可以帮你写一段在控制台运行的诊断脚本，直接把这些关键配置打印出来。