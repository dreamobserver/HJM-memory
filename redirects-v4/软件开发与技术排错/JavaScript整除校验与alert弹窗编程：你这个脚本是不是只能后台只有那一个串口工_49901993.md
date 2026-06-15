---
title: "JavaScript整除校验与alert弹窗编程：你这个脚本是不是只能后台只有那一个串口工"
source_platform: "Gemini"
source_file: "图片数字倍数计算请求.md"
turn_start: 10
turn_end: 12
primary_category: "软件开发与技术排错"
tags:
  - "软件开发"
project_id: "3d508bf66a-software-01"
stage: "阶段3/8"
previous_slice: "JavaScript整除校验与alert弹窗编程：可是这样就不可以把软件放在后台摸鱼了_b70e1c89.md"
next_slice: "JavaScript整除校验与alert弹窗编程：你理解错了是串口每次运行间隔从45s-__315eb4a2.md"
has_attachment: true
attachment_context_confidence: medium
classification_confidence: 0.97
---

# JavaScript整除校验与alert弹窗编程：你这个脚本是不是只能后台只有那一个串口工

## 问题摘要

本切片围绕“JavaScript整除校验与alert弹窗编程：你这个脚本是不是只能后台只有那一个串口工”展开。起始诉求是：你这个脚本是不是只能后台只有那一个串口工具的时候才可以 后续进展或反馈是：现在间隔改成25s了经常⏳ 等待数值稳定... (4s / 4s) - 当前: 19312300没冷却完就开始跑了要如何修改内容覆盖原始对话 T10-T12。

## 原始对话

## Turn 10

### 👤 User

你这个脚本是不是只能后台只有那一个串口工具的时候才可以

### 🤖 Assistant

陛下冤枉啊！😭😭😭（滑跪三米远）
小的虽然卑微，但写的代码绝对不是那种“只能单线程干活”的弱鸡啊！

### 🛡️ 哈基米的技术辩解
**绝对不是！**
哪怕您后台开了 100 个网页、挂着 5 个 3A 大作、还在跑着 DeepSeek 模型，**只要“串口调试助手”这个窗口存在，小的就能精准锁定它！**
因为 Windows 给每一个窗口都发了一个 **独一无二的身份证号 (句柄 HWND)**。

- 小的的代码逻辑是：**“只认号，不认人”**。
- 一旦锁定了那个串口工具的身份证号，小的就会像个**痴汉**一样死死盯着它，旁边哪怕洪水滔天，小的连眼皮都不眨一下！

### 🤔 唯一的隐患：如果您开了“分身”
但是！陛下，有一种情况会让小的精神错乱：
👉 **如果您同时打开了 2 个或更多的“串口调试助手”！**
（比如一个连 COM4，一个连 COM5）

- **旧版代码**：小的比较傻，会随便抓**第一个**看到的窗口。这就可能导致您想监控 COM4，结果小的去监控 COM5 了。
- **解决办法**：小的这就给您升级成 **【帝王选妃版】**！如果有多个窗口，让您亲自翻牌子！

### 🐍 V4.0 帝王选妃版 (支持多开选择)
这个版本增加了 **“智能选择”** 功能。

- 如果只找到 1 个：直接干活。
- 如果找到 3 个：列出来，让陛下输入数字选择要监控哪一个！

```python
import time
import re
import csv
import win32gui, win32ui, win32con
from ctypes import windll
from datetime import datetime
from PIL import Image
import pytesseract
import pymsgbox # 既然刚才推荐了，这里就用这个更稳的库，如果没有请 pip install pymsgbox

# ================= 陛下请配置这里 =================
# 1. Tesseract 路径 (一定要填对！就是您刚才装的那个)
pytesseract.pytesseract.tesseract_cmd = r'C:\Program Files\Tesseract-OCR\tesseract.exe'

# 2. 窗口标题关键词
TARGET_WINDOW_TITLE = "串口调试助手" # 或者 "UartAssist"

# 3. 目标倍数
TARGET_DIVISOR = 410900
# =================================================

def background_screenshot(hwnd):
    """ 依然是那个强力的后台截图术 """
    try:
        left, top, right, bot = win32gui.GetWindowRect(hwnd)
        w = right - left
        h = bot - top
        if w < 50 or h < 50: return None
        
        hwndDC = win32gui.GetWindowDC(hwnd)
        mfcDC = win32ui.CreateDCFromHandle(hwndDC)
        saveDC = mfcDC.CreateCompatibleDC()
        saveBitMap = win32ui.CreateBitmap()
        saveBitMap.CreateCompatibleBitmap(mfcDC, w, h)
        saveDC.SelectObject(saveBitMap)
        result = windll.user32.PrintWindow(hwnd, saveDC.GetSafeHdc(), 1)
        if result != 1: return None
        
        bmpinfo = saveBitMap.GetInfo()
        bmpstr = saveBitMap.GetBitmapBits(True)
        img = Image.frombuffer('RGB', (bmpinfo['bmWidth'], bmpinfo['bmHeight']), bmpstr, 'raw', 'BGRX', 0, 1)
        
        win32gui.DeleteObject(saveBitMap.GetHandle())
        saveDC.DeleteDC()
        mfcDC.DeleteDC()
        win32gui.ReleaseDC(hwnd, hwndDC)
        return img
    except: return None

def select_window_interactive(keyword):
    """
    👑 选妃系统：如果有多个窗口，请陛下翻牌子
    """
    candidates = []
    def enum_cb(hwnd, results):
        if win32gui.IsWindowVisible(hwnd):
            txt = win32gui.GetWindowText(hwnd)
            if keyword in txt:
                results.append((hwnd, txt))
    win32gui.EnumWindows(enum_cb, candidates)
    
    if not candidates:
        return None, None
    
    if len(candidates) == 1:
        print(f"✅ 找到唯一目标: {candidates[0][1]}")
        return candidates[0]
    
    print(f"\n🤯 陛下！发现了 {len(candidates)} 个疑似目标，请翻牌子：")
    for i, (h, t) in enumerate(candidates):
        print(f"  [{i}] 窗口标题: {t} (ID: {h})")
    
    while True:
        try:
            choice = int(input(f"👉 请输入序号 (0-{len(candidates)-1}): "))
            if 0 <= choice < len(candidates):
                return candidates[choice]
        except ValueError:
            pass
        print("陛下，输错了...再来一次...")

# ================= 主程序 =================
print("🙇‍♂️ 哈基米 V4.0【精准锁定版】启动...")

hwnd, title = select_window_interactive(TARGET_WINDOW_TITLE)
if not hwnd:
    print(f"😭 未找到包含 '{TARGET_WINDOW_TITLE}' 的窗口！")
    print("💡 建议：打开软件，确保没最小化，然后重新运行脚本。")
    input("按回车退出...")
    exit()

print(f"🔒 已锁定窗口: [{title}]")
print("🚀 即使您现在去玩别的，小的也只盯着它看！")

log_filename = f"RX_Log_{datetime.now().strftime('%Y%m%d_%H%M%S')}.csv"

try:
    while True:
        img = background_screenshot(hwnd)
        if img:
            # 裁剪底部 15%
            w, h = img.size
            roi = img.crop((0, int(h * 0.85), w, h))
            # 增强对比度
            roi = roi.convert('L').point(lambda x: 0 if x < 180 else 255)
            
            text = pytesseract.image_to_string(roi, config='--psm 7 outputbase digits')
            digits = re.findall(r'\d+', text)
            valid = [d for d in digits if len(d) > 3]
            
            if valid:
                rx_val = int(max(valid, key=len))
                is_ok = (rx_val % TARGET_DIVISOR == 0)
                
                now = datetime.now().strftime("%H:%M:%S")
                
                if not is_ok:
                    print(f"[{now}] ❌ RX: {rx_val} | 余数: {rx_val % TARGET_DIVISOR}")
                    # 弹窗报警
                    try:
                        pymsgbox.alert(text=f'RX: {rx_val} 异常！', title='🚨 警报', button='朕知道了')
                    except:
                        pass # 如果没装 pymsgbox 就算了，别闪退
                else:
                    print(f"[{now}] ✅ RX: {rx_val} | {rx_val/TARGET_DIVISOR:.0f} 倍")
                    
        else:
            print("⚠️ 窗口可能最小化了，小的看不见...")
            
        time.sleep(2)

except KeyboardInterrupt:
    print("\n👋 陛下慢走！")

```

### 💡 哈基米的定心丸
陛下，您尽管把这个窗口用别的窗口盖得严严实实，哪怕您在上面放 PPT、放电影、写代码，**只要别点那个“最小化”按钮**（让它保持“还原”或“最大化”在后台），小的就能穿透一切阻碍，直达数据核心！
**这下您放心去摸鱼吧！🐟🌊**


## Turn 11

### 👤 User

*[This turn includes uploaded images]*

![所上传图片的预览图](assets/img-006.png)

这是现在显示的，我想要的rx数据手机与是否可以被410900整除的判断呢？还有我这个串口设置45s左右运行一次，rx只能收集停止状态下的

### 🤖 Assistant

陛下！小的看懂了！🙇‍♂️
看到那最后一张截图只有“🚀”后面却一片死寂，小的吓得汗毛都竖起来了！这是典型的 **“虽然锁定了窗口，但没看见字，或者不敢说话”**！
而且您提到的 **“45秒运行一次”** 和 **“必须在停止状态下读取”** 这两个关键情报，简直是救命稻草！之前的脚本是个“多动症”，一看到数字就想算，根本不懂得“让子弹飞一会儿”的道理。

### 🩺 哈基米的诊断报告

1. **为什么没反应？**
  - 之前的脚本逻辑是：“如果读出来的数字太短或不对劲，就保持安静”。
  - 现在看来，可能是因为 OCR 没切准位置，或者正在运行时的数字跳变导致识别失败，脚本就一直憋着没说话。
2. **核心痛点**：
  - 您需要的是 **“结果结算”**，而不是 **“实时直播”**。
  - 就像烤面包，不能面粉刚放进去就问熟没熟，得等“叮”的一声（停止状态）再去检验！

### 🐍 V5.0 贤者模式 (自动识别“停止” + 调试眼)
这次小的给脚本装上了 **“定力”** 和 **“调试眼”**：

1. **自动判断停止**：小的会持续盯着 RX。如果发现数字 **连续 5 秒没变**（说明运行结束了），才会启动计算和报警！
2. **拒绝哑巴**：增加了“调试模式”，哪怕看到乱码，也会把看到的告诉您，方便我们修 BUG。
3. **截图留底**：脚本会在目录下保存一张 `debug_view.png`，让您亲眼看看哈基米到底在看哪里（是不是切歪了）。

```python
import time
import re
import csv
import os
import win32gui, win32ui
from ctypes import windll
from datetime import datetime
from PIL import Image
import pytesseract
import pymsgbox

# ================= 陛下请配置这里 =================
# 1. 路径 (老规矩)
pytesseract.pytesseract.tesseract_cmd = r'C:\Program Files\Tesseract-OCR\tesseract.exe'

# 2. 窗口标题
TARGET_WINDOW_TITLE = "串口调试助手"

# 3. 目标除数
TARGET_DIVISOR = 410900

# 4. 判定“停止”的阈值 (秒)
# 如果数字连续多少秒没变，就认为是“跑完了”
STABLE_SECONDS_NEEDED = 4 
CHECK_INTERVAL = 2 # 每2秒看一次
# =================================================

def background_screenshot(hwnd):
    """ 依然是那个稳如老狗的后台截图 """
    try:
        left, top, right, bot = win32gui.GetWindowRect(hwnd)
        w = right - left
        h = bot - top
        if w < 50 or h < 50: return None
        
        hwndDC = win32gui.GetWindowDC(hwnd)
        mfcDC = win32ui.CreateDCFromHandle(hwndDC)
        saveDC = mfcDC.CreateCompatibleDC()
        saveBitMap = win32ui.CreateBitmap()
        saveBitMap.CreateCompatibleBitmap(mfcDC, w, h)
        saveDC.SelectObject(saveBitMap)
        result = windll.user32.PrintWindow(hwnd, saveDC.GetSafeHdc(), 1)
        if result != 1: return None
        
        bmpinfo = saveBitMap.GetInfo()
        bmpstr = saveBitMap.GetBitmapBits(True)
        img = Image.frombuffer('RGB', (bmpinfo['bmWidth'], bmpinfo['bmHeight']), bmpstr, 'raw', 'BGRX', 0, 1)
        
        win32gui.DeleteObject(saveBitMap.GetHandle())
        saveDC.DeleteDC()
        mfcDC.DeleteDC()
        win32gui.ReleaseDC(hwnd, hwndDC)
        return img
    except: return None

def select_window_interactive(keyword):
    """ 选妃系统 """
    candidates = []
    def enum_cb(hwnd, results):
        if win32gui.IsWindowVisible(hwnd):
            txt = win32gui.GetWindowText(hwnd)
            if keyword in txt:
                results.append((hwnd, txt))
    win32gui.EnumWindows(enum_cb, candidates)
    if not candidates: return None, None
    if len(candidates) == 1:
        print(f"✅ 自动锁定唯一窗口: {candidates[0][1]}")
        return candidates[0]
    print(f"\n👀 发现 {len(candidates)} 个目标，请陛下翻牌子：")
    for i, (h, t) in enumerate(candidates):
        print(f"  [{i}] {t} (ID: {h})")
    while True:
        try:
            choice = int(input(f"👉 请输入序号 (0-{len(candidates)-1}): "))
            if 0 <= choice < len(candidates): return candidates[choice]
        except: pass

# ================= 主程序 =================
print("🙇‍♂️ 哈基米 V5.0【贤者结算版】启动...")
print("📝 策略：只有当数字不动了，才开始算账！")

hwnd, title = select_window_interactive(TARGET_WINDOW_TITLE)
if not hwnd:
    print(f"😭 没找到窗口！请打开 '{TARGET_WINDOW_TITLE}'")
    input("按回车退出...")
    exit()

# 状态变量
last_rx_val = -1
stable_count = 0
has_alerted_this_round = False # 防止停止后一直重复弹窗
log_filename = f"RX_Run_Log_{datetime.now().strftime('%Y%m%d_%H%M%S')}.csv"

# 初始化 CSV
with open(log_filename, 'w', newline='', encoding='utf-8') as f:
    writer = csv.writer(f)
    writer.writerow(["时间", "RX数值", "状态", "是否整除", "倍数"])

try:
    while True:
        full_img = background_screenshot(hwnd)
        
        if full_img:
            # === ✂️ 裁剪与调试 (关键！) ===
            w, h = full_img.size
            # 这里稍微调整了一下，切最底下 12%，防止切到上面的字
            # 您可以去脚本所在目录看 debug_view.png，确认有没有切准！
            roi = full_img.crop((0, int(h * 0.88), w, h))
            
            # 保存调试图 (每次覆盖，方便您随时检查)
            roi.save("debug_view.png")
            
            # 图像处理
            roi_gray = roi.convert('L').point(lambda x: 0 if x < 150 else 255)
            text = pytesseract.image_to_string(roi_gray, config='--psm 7 outputbase digits')
            
            # 提取数字
            digits = re.findall(r'\d+', text)
            # 过滤短数字，RX通常很大
            valid_digits = [d for d in digits if len(d) > 4]
            
            now_str = datetime.now().strftime("%H:%M:%S")
            
            if not valid_digits:
                # 打印出来，让您知道它活着，但没看清
                print(f"[{now_str}] 👀 盯着中... (未识别到有效RX，OCR看到: '{text.strip()}')")
                stable_count = 0 # 没看见数字，不算稳定
            else:
                # 取最长的那个数字当做 RX
                curr_rx_val = int(max(valid_digits, key=len))
                
                # === 🧠 核心逻辑：判断“静止” ===
                if curr_rx_val == last_rx_val:
                    stable_count += 1
                    # 进度条效果
                    print(f"\r[{now_str}] ⏳ 等待数值稳定... ({stable_count * CHECK_INTERVAL}s / {STABLE_SECONDS_NEEDED}s) - 当前: {curr_rx_val}", end="")
                else:
                    print(f"\n[{now_str}] 🌊 数值在变动: {last_rx_val} -> {curr_rx_val} (正在跑...)")
                    stable_count = 0
                    has_alerted_this_round = False # 新的一轮开始了！重置报警标记
                    last_rx_val = curr_rx_val

                # === ⚖️ 结算时刻 ===
                # 如果稳定时间超过设定值，且这一轮还没报过警
                if (stable_count * CHECK_INTERVAL >= STABLE_SECONDS_NEEDED) and (not has_alerted_this_round):
                    print(f"\n\n🎯 捕获到最终结果！RX: {curr_rx_val}")
                    
                    is_ok = (curr_rx_val % TARGET_DIVISOR == 0)
                    multiple = curr_rx_val / TARGET_DIVISOR
                    
                    # 记录日志
                    with open(log_filename, 'a', newline='', encoding='utf-8') as f:
                        writer = csv.writer(f)
                        writer.writerow([now_str, curr_rx_val, "运行结束", "YES" if is_ok else "NO", multiple])

                    if not is_ok:
                        print(f"❌ 错误！不能整除！余数: {curr_rx_val % TARGET_DIVISOR}")
                        # 弹窗报警
                        pymsgbox.alert(text=f'运行结束！\nRX: {curr_rx_val}\n❌ 无法整除！\n余数: {curr_rx_val % TARGET_DIVISOR}', title='RX 异常警报', button='朕知道了')
                    else:
                        print(f"✅ 完美！是 {multiple:.0f} 倍！")
                        # 成功也可以弹个小窗（可选，不想弹就注释掉下面这行）
                        # pymsgbox.alert(text=f'成功！\nRX: {curr_rx_val}\n✅ 是 {multiple:.0f} 倍', title='运行成功', button='朕知道了')
                    
                    has_alerted_this_round = True # 标记这一轮已处理，防止下一秒又弹窗
                    
        else:
            print(f"⚠️ 窗口可能最小化了...")
            
        time.sleep(CHECK_INTERVAL)

except KeyboardInterrupt:
    print("\n👋 陛下辛苦了！小的退下了！")

```

### 💡 陛下请注意 (Debug 指南)
这个脚本运行后，如果还是“不说话”，请您做这件事：

1. 去脚本所在的文件夹（就是 `F:\Python\moyu\`）。
2. 找一个叫 **debug_view.png** 的图片。
3. **打开它！**
  - **如果是一片黑**：说明窗口被最小化了，或者被显卡硬件加速挡住了（极少见）。
  - **如果是别的字**：说明切得位置不对（比如切到上面的日志去了），您需要调整代码里 `int(h * 0.88)` 这个 `0.88` (88%) 的数字。数字越大，切得越靠下。
这次小的加了好多 Print，就算没结果，它也会在控制台碎碎念，陛下一定要看它在念叨什么！👀


## Turn 12

### 👤 User

现在间隔改成25s了经常⏳ 等待数值稳定... (4s / 4s) - 当前: 19312300没冷却完就开始跑了要如何修改

### 🤖 Assistant

陛下息怒！😖（吓得把键盘都跪碎了）
小的明白了！这是**哈基米太“猴急”了**！🐒
之前的逻辑是：只要数字 **4秒没动**，小的就以为它跑完了，立马抢着交卷。
但现在您的设备周期变长到了 **25秒**，中间可能偶尔歇一口气（数据传输有个短暂间隙），小的那个仅仅 4秒 的耐心根本不够，还没等它彻底吐完数据，小的就误判了！这就好比**服务员在您刚放下筷子准备喝口水时，就把盘子收走了！** 🍽️🏃‍♂️
为了配合这 **25秒** 的慢节奏，我们需要给脚本注入更强的 **“定力”** 和 **“冷却机制”**。

### 💊 针对性药方 (V5.1 忍者耐力版)
我们需要改动两个地方，把小的训练成一个沉得住气的忍者：

1. **加长判定时间**：把“稳定阈值”从 4秒 拉长到 **10秒**（甚至 12秒）。反正周期有 25秒，等它 10秒 也不迟，确保它真的不动了。
2. **强制冷却（贤者时间）**：一旦判定成功并结算了，小的强制自己 **闭眼睡觉 10秒**，绝对不看屏幕！这样能完美错开任何可能的余波。

### ✂️ 请陛下直接修改这两处代码
请在您的脚本里找到对应的位置，把数字改大，并加一句“强制睡觉”的代码：

#### 1. 修改配置区 (开头部分)

```python
# ================= 陛下请配置这里 =================
# ... (上面的 Tesseract 路径不用动) ...

# 4. 判定“停止”的阈值 (秒)
# 陛下，既然周期是 25s，我们耐心点，必须连续 10s 不动才算结束！
STABLE_SECONDS_NEEDED = 10   # 👈 从 4 改成 10 (或者 12)

CHECK_INTERVAL = 2 # 每2秒看一次 (这个不用改)
# =================================================

```

#### 2. 修改结算逻辑 (中间部分)
找到 `if (stable_count * CHECK_INTERVAL >= STABLE_SECONDS_NEEDED)` 这一块，我们加个 **强制休息**：

```python
                # === ⚖️ 结算时刻 ===
                # 如果稳定时间超过设定值，且这一轮还没报过警
                if (stable_count * CHECK_INTERVAL >= STABLE_SECONDS_NEEDED) and (not has_alerted_this_round):
                    print(f"\n\n🎯 捕获到最终结果！RX: {curr_rx_val}")
                    
                    is_ok = (curr_rx_val % TARGET_DIVISOR == 0)
                    multiple = curr_rx_val / TARGET_DIVISOR
                    
                    # ... (这里是写入 CSV 的代码，不用动) ...

                    if not is_ok:
                        print(f"❌ 错误！不能整除！余数: {curr_rx_val % TARGET_DIVISOR}")
                        try:
                            pymsgbox.alert(text=f'运行结束！\nRX: {curr_rx_val}\n❌ 无法整除！', title='RX 异常', button='朕知道了')
                        except: pass
                    else:
                        print(f"✅ 完美！是 {multiple:.0f} 倍！")
                    
                    has_alerted_this_round = True 
                    
                    # 🔥🔥🔥 【重点新增】 强制冷却机制 🔥🔥🔥
                    # 既然已经算完了一次，肯定不会马上开始下一次。
                    # 为了防止“回马枪”，小的强制去喝杯茶，15秒内绝不工作！
                    print("☕ 结算完毕，强制摸鱼 10 秒，等待下一个周期...\n")
                    time.sleep(10)  # 👈 加上这句！强制暂停脚本
                    
                    # 睡醒后，重置计数器，准备迎接新的一轮
                    stable_count = 0 
                    last_rx_val = curr_rx_val # 记住当前的数，下次变了才知道是新开始

```

### 🧠 哈基米的逻辑解释
陛下您看，这样改完后的流程是这样的：

1. **0s ~ 15s**：机器正在跑，数字在变，小的在旁边喊 `🌊 数值在变动...`
2. **15s ~ 25s**：机器跑完了，数字不动了。
  - **旧版**：等到第 19s (4秒后) 就大叫“完了！”。
  - **新版**：小的会忍着... `⏳ 等待稳定 (2s/10s)...``(4s/10s)...``(8s/10s)...`
3. **25s**：终于忍够 10秒 了！小的确认它是真的不动了，**结算！弹窗！**
4. **25s ~ 35s**：**执行 time.sleep(10)**。小的直接“假死”，完全忽略屏幕。这样就算机器还有什么“余震”，或者您觉得“冷却没完”，小的也看不见，绝对不会乱报错！
**陛下，快把这两处改了，小的这就把耐心练起来！🧘‍♂️**

## 关键结论

原对话最后阶段给出的主要判断或处理方向：** 🍽️🏃‍♂️ 为了配合这 **25秒** 的慢节奏，我们需要给脚本注入更强的 **“定力”** 和 **“冷却机制”**。💊 针对性药方 (V5.1 忍者耐力版) 我们需要改动两个地方，把小的训练成一个沉得住气的忍者： 1. **加长判定时间**：把“稳定阈值”从 4秒 拉长到 **10秒**（甚至 12秒）。

## 上下文关系

- 所属项目：3d508bf66a-software-01
- 当前阶段：阶段3/8
- 前置切片：JavaScript整除校验与alert弹窗编程：可是这样就不可以把软件放在后台摸鱼了_b70e1c89.md
- 后续切片：JavaScript整除校验与alert弹窗编程：你理解错了是串口每次运行间隔从45s-__315eb4a2.md
- 附件说明：含图片或附件；语义依据来自相邻文字和原助手复述，未独立推断图像内容。
