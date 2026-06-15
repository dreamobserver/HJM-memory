---
title: "Python反编译EXE软件方法指南原理与分析"
source_platform: "DeepSeek"
source_file: "Python反编译EXE软件方法指南.md"
turn_start: 16
turn_end: 18
primary_category: "软件开发与技术排错"
tags:
  - "状态栏"
  - "编译错误"
project_id: "b0d6b99ced-software-01"
stage: "阶段5/13"
previous_slice: "分析完毕后弹了一个警告(These messages are also writte（T13-15）_434b3cd5.md"
next_slice: "脉冲测距与API技术处理_4db36d35.md"
has_attachment: false
attachment_context_confidence: not_applicable
classification_confidence: 0.97
---

# Python反编译EXE软件方法指南原理与分析

## 问题摘要

本切片围绕“Python反编译EXE软件方法指南原理与分析”展开。起始诉求是：继续仔细找到我如何深入分析 CDSPIDlg 后续进展或反馈是：* FUNCTION * CDSPIDlg * __thiscall CDSPIDlg(CDSPIDlg * this, CWnd * p assume GS_OFFSET = 0xff00000000 CDSPIDlg * RAX:8 CDSPIDlg * RCX:8 (aut…内容覆盖原始对话 T16-T18。

## 原始对话

SPIDlg` 类了。

# 用户：

继续仔细找到我如何深入分析 CDSPIDlg

# DeepSeek：

**原始回答**

好的，现在我们进入了最激动人心的阶段——深入分析程序的核心逻辑层 `CDSPIDlg`。以下是系统性的操作步骤，帮助您一步步揭开它的面纱。

### 第1步：跳转到 `CDSPIDlg` 的构造函数

这是最直接的起点，可以了解对话框初始化时做了什么。

1.  在 `InitInstance` 的反编译窗口中，找到调用 `CDSPIDlg::CDSPIDlg` 的那一行。
2.  **按住 `Ctrl` 键并用鼠标点击** `CDSPIDlg::CDSPIDlg`。
3.  Ghidra 会跳转到该构造函数的地址。按 `F5` 进行反编译。

**在构造函数中，关注以下内容：**
*   **对基类 `CDialog` 构造函数的调用**：这是标准的MFC初始化。
*   **成员变量的初始化**：查找那些被设置为 `NULL`、`0` 或有特定初始值的变量。这些变量很可能在后面用于存储图像数据、算法参数、设备句柄等。
*   **调用其他初始化函数**：例如 `LoadSettings()`，这可能会从注册表或配置文件中加载参数。



开所有宝藏的钥匙。**

# 用户：

**************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             void __thiscall ~CDSPIDlg(CDSPIDlg * this)
                               assume GS_OFFSET = 0xff00000000
             void              <VOID>         <RETURN>
             CDSPIDlg *        RCX:8 (auto)   this
                             ??1CDSPIDlg@@UEAA@XZ                            XREF[4]:     InitInstance:14000121e(c), 
                             CDSPIDlg::~CDSPIDlg                                          `scalar_deleting_destructor':140
                                                                                          dtor$1:14000afb3(c), 
                                                                                          140015054(*)  
       140001250 40 53           PUSH       RBX                                              CStringT<char,class_StrTraitMFC_
       140001252 48 83 ec 20     SUB        RSP,0x20
       140001256 48 8b d9        MOV        RBX,this
       140001259 48 81 c1        ADD        this,0x11d0
                 d0 11 00 00
       140001260 ff 15 2a        CALL       qword ptr [->MFC140.DLL::ATL::CStringT<>::~CSt   = 8000000000000408
                 ba 00 00
       140001266 48 8d 8b        LEA        this,[RBX + 0x10e8]
                 e8 10 00 00
       14000126d ff 15 b5        CALL       qword ptr [->MFC140.DLL::CSliderCtrl::~CSlider   = 8000000000000581
                 b9 00 00
       140001273 48 8d 8b        LEA        this,[RBX + 0x1000]
                 00 10 00 00
       14000127a ff 15 98        CALL       qword ptr [->MFC140.DLL::CStatic::~CStatic]      = 800000000000058d
                 b9 00 00
       140001280 48 8d 8b        LEA        this,[RBX + 0xf18]
                 18 0f 00 00
       140001287 ff 15 8b        CALL       qword ptr [->MFC140.DLL::CStatic::~CStatic]      = 800000000000058d
                 b9 00 00
       14000128d 48 8d 8b        LEA        this,[RBX + 0xe30]
                 30 0e 00 00
       140001294 ff 15 7e        CALL       qword ptr [->MFC140.DLL::CStatic::~CStatic]      = 800000000000058d
                 b9 00 00
       14000129a 48 8d 8b        LEA        this,[RBX + 0xd08]
                 08 0d 00 00
       1400012a1 ff 15 79        CALL       qword ptr [->MFC140.DLL::CToolTipCtrl::~CToolT   = 800000000000059c
                 b9 00 00
       1400012a7 48 8d 8b        LEA        this,[RBX + 0xd00]
                 00 0d 00 00
       1400012ae ff 15 dc        CALL       qword ptr [->MFC140.DLL::ATL::CStringT<>::~CSt   = 8000000000000408
                 b9 00 00
       1400012b4 48 8d 8b        LEA        this,[RBX + 0xc18]
                 18 0c 00 00
       1400012bb ff 15 67        CALL       qword ptr [->MFC140.DLL::CSliderCtrl::~CSlider   = 8000000000000581
                 b9 00 00
       1400012c1 48 8d 8b        LEA        this,[RBX + 0xc10]
                 10 0c 00 00
       1400012c8 ff 15 c2        CALL       qword ptr [->MFC140.DLL::ATL::CStringT<>::~CSt   = 8000000000000408
                 b9 00 00
       1400012ce 48 8d 8b        LEA        this,[RBX + 0xb28]
                 28 0b 00 00
       1400012d5 ff 15 4d        CALL       qword ptr [->MFC140.DLL::CSliderCtrl::~CSlider   = 8000000000000581
                 b9 00 00
       1400012db 48 8d 8b        LEA        this,[RBX + 0xa40]
                 40 0a 00 00
       1400012e2 ff 15 48        CALL       qword ptr [->MFC140.DLL::CComboBox::~CComboBox]  = 800000000000041f
                 b9 00 00
       1400012e8 48 8d 8b        LEA        this,[RBX + 0x158]
                 58 01 00 00
       1400012ef ff 15 eb        CALL       qword ptr [->MFC140.DLL::CDialogImpl::~CDialog   = 8000000000000441
                 b8 00 00
       1400012f5 48 8d 8b        LEA        this,[RBX + 0x140]
                 40 01 00 00
       1400012fc 48 8d 05        LEA        RAX,[CBrush::vftable]
                 3d bc 00 00
       140001303 48 89 01        MOV        qword ptr [this->_padding_],RAX=>CBrush::vftable
       140001306 e8 85 01        CALL       CGdiObject::~CGdiObject                          void ~CGdiObject(CGdiObject * th
                 00 00
       14000130b 48 8b cb        MOV        this,RBX
       14000130e 48 83 c4 20     ADD        RSP,0x20
       140001312 5b              POP        RBX
       140001313 48 ff 25        JMP        qword ptr [->MFC140.DLL::CDialog::~CDialog]
                 f6 b8 00 00
       14000131a cc cc cc        align      align(6)
                 cc cc cc
这算是定位 CDSPIDlg::CDSPIDlg成功吗？

# DeepSeek：

**原始回答**

不，这不算定位 `CDSPIApp::CDSPIDlg` 成功。您找到的是 **`CDSPIDlg` 的析构函数（Destructor）**，而不是构造函数（Constructor）。

从函数名可以明确看出：
*   **`~CDSPIDlg`**： 波浪号 `~` 是 C++ 中析构函数的标志。这个函数在对话框对象被销毁时调用，用于清理资源。
*   **`??1CDSPIDlg@@UEAA@XZ`**： 这是析构函数在编译后的名称修饰（Name Mangling）。`??1` 是析构函数的常见前缀。

### 析构函数告诉了我们什么？

虽然这不是构造函数，但析构函数同样**极具价值**！它就像一个“拆卸指南”，反向揭示了对象的构成。从这段代码中，我们可以获得关于 `CDSPIDlg` 类的**大量关键信息**：

1.  **成员变量（最重要的发现！）**：
    析构函数必须逐一销毁所有成员对象。因此，它清晰地列出了 `CDSPIDlg` 类中几乎所有的重要成员变量及其**内存偏移量**和**类型**。例如：
    *   

 和消息处理函数。**

# 用户：

**************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             CDSPIDlg * __thiscall CDSPIDlg(CDSPIDlg * this, CWnd * p
                               assume GS_OFFSET = 0xff00000000
             CDSPIDlg *        RAX:8          <RETURN>
             CDSPIDlg *        RCX:8 (auto)   this
             CWnd *            RDX:8          param_1
             undefined8        Stack[0x20]:8  local_res20                             XREF[2]:     14000313b(W), 
                                                                                                   140003344(R)  
             undefined8        Stack[0x18]:8  local_res18                             XREF[2]:     140003136(W), 
                                                                                                   14000333f(R)  
             undefined8        Stack[0x10]:8  local_res10                             XREF[7]:     140003179(W), 
                                                                                                   140003198(W), 
                                                                                                   1400031cc(W), 
                                                                                                   140003207(W), 
                                                                                                   140003226(W), 
                                                                                                   14000323e(W), 
                                                                                                   140003256(W)  
             undefined8        Stack[0x8]:8   local_res8                              XREF[1]:     140003120(W)  
             undefined8        Stack[-0x28]:8 local_28                                XREF[1]:     14000312d(W)  
                             ??0CDSPIDlg@@QEAA@PEAVCWnd@@@Z                  XREF[2]:     InitInstance:1400011eb(c), 
                             CDSPIDlg::CDSPIDlg                                           14001533c(*)  
                             dspidlg.cpp:86 (35)
       140003120 48 89 4c        MOV        qword ptr [RSP + local_res8],this
                 24 08
       140003125 56              PUSH       RSI                                              CWnd * param_2 for CDialogEx
       140003126 57              PUSH       RDI                                              uint param_1 for CDialogEx
       140003127 41 56           PUSH       R14                                              CDialogEx * this for CDialogEx
       140003129 48 83 ec 30     SUB        RSP,0x30
       14000312d 48 c7 44        MOV        qword ptr [RSP + local_28],-0x2
                 24 20 fe 
                 ff ff ff
       140003136 48 89 5c        MOV        qword ptr [RSP + local_res18],RBX
                 24 60
       14000313b 48 89 6c        MOV        qword ptr [RSP + local_res20],RBP
                 24 68
       140003140 48 8b f1        MOV        RSI,this
                             dspidlg.cpp:83 (14)
       140003143 45 33 c0        XOR        R8D,R8D
       140003146 41 8d 50 66     LEA        param_1,[R8 + 0x66]
                             LAB_14000314a                                   XREF[1]:     1400107a0(*)  
       14000314a ff 15 f8        CALL       qword ptr [->MFC140.DLL::CDialogEx::CDialogEx]   = 80000000000001c2
                 97 00 00
       140003150 90              NOP
                             dspidlg.cpp:86 (95)
       140003151 48 8d 05        LEA        RAX,[CDSPIDlg::vftable]
                 48 b5 00 00
       140003158 48 89 06        MOV        qword ptr [RSI],RAX=>CDSPIDlg::vftable
       14000315b 33 db           XOR        EBX,EBX
       14000315d 48 89 9e        MOV        qword ptr [RSI + 0x198],RBX
                 98 01 00 00
       140003164 48 89 9e        MOV        qword ptr [RSI + 0x1a0],RBX
                 a0 01 00 00
       14000316b 48 89 9e        MOV        qword ptr [RSI + 0x228],RBX
                 28 02 00 00
       140003172 48 8d be        LEA        RDI,[RSI + 0xa40]
                 40 0a 00 00
       140003179 48 89 7c        MOV        qword ptr [RSP + local_res10],RDI
                 24 58
       14000317e 48 8b cf        MOV        this,RDI
                             LAB_140003181                                   XREF[1]:     1400107a8(*)  
       140003181 ff 15 51        CALL       qword ptr [->MFC140.DLL::CWnd::CWnd]             = 80000000000003dc
                 95 00 00
       140003187 48 8d 05        LEA        RAX,[CComboBox::vftable]
                 0a b2 00 00
       14000318e 48 89 07        MOV        qword ptr [RDI],RAX=>CComboBox::vftable
       140003191 48 8d be        LEA        RDI,[RSI + 0xb28]
                 28 0b 00 00
       140003198 48 89 7c        MOV        qword ptr [RSP + local_res10],RDI
                 24 58
       14000319d 48 8b cf        MOV        this,RDI
                             LAB_1400031a0                                   XREF[1]:     1400107b0(*)  
       1400031a0 ff 15 32        CALL       qword ptr [->MFC140.DLL::CWnd::CWnd]             = 80000000000003dc
                 95 00 00
       1400031a6 4c 8d 35        LEA        R14,[CSliderCtrl::vftable]
                 fb ae 00 00
       1400031ad 4c 89 37        MOV        qword ptr [RDI],R14=>CSliderCtrl::vftable
                             dspidlg.cpp:84 (21)
       1400031b0 48 8d 8e        LEA        this,[RSI + 0xc10]
                 10 0c 00 00
       1400031b7 48 8d 15        LEA        param_1,[s_]                                     = ""
                 6a bb 00 00
                             LAB_1400031be                                   XREF[1]:     1400107b8(*)  
       1400031be ff 15 ac        CALL       qword ptr [->MFC140.DLL::ATL::CStringT<>::CStr   = 8000000000000136
                 97 00 00
       1400031c4 90              NOP
                             dspidlg.cpp:86 (24)
       1400031c5 48 8d be        LEA        RDI,[RSI + 0xc18]
                 18 0c 00 00
       1400031cc 48 89 7c        MOV        qword ptr [RSP + local_res10],RDI
                 24 58
       1400031d1 48 8b cf        MOV        this,RDI
                             LAB_1400031d4                                   XREF[1]:     1400107c0(*)  
       1400031d4 ff 15 fe        CALL       qword ptr [->MFC140.DLL::CWnd::CWnd]             = 80000000000003dc
                 94 00 00
       1400031da 4c 89 37        MOV        qword ptr [RDI],R14=>CSliderCtrl::vftable
                             dspidlg.cpp:85 (21)
       1400031dd 48 8d 8e        LEA        this,[RSI + 0xd00]
                 00 0d 00 00
       1400031e4 48 8d 15        LEA        param_1,[s_10]                                   = "10"
                 81 a4 00 00
                             LAB_1400031eb                                   XREF[1]:     1400107c8(*)  
       1400031eb ff 15 7f        CALL       qword ptr [->MFC140.DLL::ATL::CStringT<>::CStr   = 8000000000000136
                 97 00 00
       1400031f1 90              NOP
                             dspidlg.cpp:86 (131)
       1400031f2 48 8d 8e        LEA        this,[RSI + 0xd08]
                 08 0d 00 00
                             LAB_1400031f9                                   XREF[1]:     1400107d0(*)  
       1400031f9 ff 15 b1        CALL       qword ptr [->MFC140.DLL::CToolTipCtrl::CToolTi   = 80000000000003cb
                 94 00 00
       1400031ff 90              NOP
       140003200 48 8d be        LEA        RDI,[RSI + 0xe30]
                 30 0e 00 00
       140003207 48 89 7c        MOV        qword ptr [RSP + local_res10],RDI
                 24 58
       14000320c 48 8b cf        MOV        this,RDI
                             LAB_14000320f                                   XREF[1]:     1400107d8(*)  
       14000320f ff 15 c3        CALL       qword ptr [->MFC140.DLL::CWnd::CWnd]             = 80000000000003dc
                 94 00 00
       140003215 48 8d 2d        LEA        RBP,[CStatic::vftable]
                 9c ab 00 00
       14000321c 48 89 2f        MOV        qword ptr [RDI],RBP=>CStatic::vftable
       14000321f 48 8d be        LEA        RDI,[RSI + 0xf18]
                 18 0f 00 00
       140003226 48 89 7c        MOV        qword ptr [RSP + local_res10],RDI
                 24 58
       14000322b 48 8b cf        MOV        this,RDI
                             LAB_14000322e                                   XREF[1]:     1400107e0(*)  
       14000322e ff 15 a4        CALL       qword ptr [->MFC140.DLL::CWnd::CWnd]             = 80000000000003dc
                 94 00 00
       140003234 48 89 2f        MOV        qword ptr [RDI],RBP=>CStatic::vftable
       140003237 48 8d be        LEA        RDI,[RSI + 0x1000]
                 00 10 00 00
       14000323e 48 89 7c        MOV        qword ptr [RSP + local_res10],RDI
                 24 58
       140003243 48 8b cf        MOV        this,RDI
                             LAB_140003246                                   XREF[1]:     1400107e8(*)  
       140003246 ff 15 8c        CALL       qword ptr [->MFC140.DLL::CWnd::CWnd]             = 80000000000003dc
                 94 00 00
       14000324c 48 89 2f        MOV        qword ptr [RDI],RBP=>CStatic::vftable
       14000324f 48 8d be        LEA        RDI,[RSI + 0x10e8]
                 e8 10 00 00
       140003256 48 89 7c        MOV        qword ptr [RSP + local_res10],RDI
                 24 58
       14000325b 48 8b cf        MOV        this,RDI
                             LAB_14000325e                                   XREF[1]:     1400107f0(*)  
       14000325e ff 15 74        CALL       qword ptr [->MFC140.DLL::CWnd::CWnd]             = 80000000000003dc
                 94 00 00
       140003264 4c 89 37        MOV        qword ptr [RDI],R14=>CSliderCtrl::vftable
       140003267 48 8d 8e        LEA        this,[RSI + 0x11d0]
                 d0 11 00 00
       14000326e ff 15 24        CALL       qword ptr [->MFC140.DLL::ATL::CStringT<>::CStr   = 800000000000013c
                 9a 00 00
       140003274 90              NOP
                             LAB_140003275                                   XREF[1]:     1400107f8(*)  
                             dspidlg.cpp:88 (39)
       140003275 ff 15 05        CALL       qword ptr [->MFC140.DLL::AfxGetModuleState]      = 800000000000089f
                 94 00 00
       14000327b 8d 53 0e        LEA        param_1,[RBX + 0xe]
       14000327e 8d 4a 73        LEA        this,[RDX + param_1+0x73]
       140003281 ff 15 01        CALL       qword ptr [->MFC140.DLL::AfxFindResourceHandle]  = 8000000000000886
                 94 00 00
       140003287 48 8b c8        MOV        this,RAX
       14000328a ba 81 00        MOV        param_1,DAT_00000081
                 00 00
       14000328f ff 15 43        CALL       qword ptr [->USER32.DLL::LoadIconW]              = 000125b6
                 90 00 00
       140003295 48 89 86        MOV        qword ptr [RSI + 0x170],RAX
                 70 01 00 00
                             dspidlg.cpp:89 (6)
       14000329c 89 9e 90        MOV        dword ptr [RSI + 0x190],EBX
                 01 00 00
                             dspidlg.cpp:91 (7)
       1400032a2 48 89 9e        MOV        qword ptr [RSI + 0xa34],RBX
                 34 0a 00 00
                             dspidlg.cpp:93 (10)
       1400032a9 c7 86 3c        MOV        dword ptr [RSI + 0xa3c],0xa
                 0a 00 00 
                 0a 00 00 00
                             dspidlg.cpp:94 (20)
       1400032b3 48 8d 15        LEA        param_1,[s_10]                                   = "10"
                 b2 a3 00 00
       1400032ba 48 8d 8e        LEA        this,[RSI + 0x11d0]
                 d0 11 00 00
       1400032c1 ff 15 a1        CALL       qword ptr [->MFC140.DLL::ATL::CStringT<>::oper   = 80000000000005e3
                 96 00 00
                             dspidlg.cpp:96 (7)
       1400032c7 48 89 9e        MOV        qword ptr [RSI + 0x1c0],RBX
                 c0 01 00 00
                             dspidlg.cpp:97 (7)
       1400032ce 48 89 9e        MOV        qword ptr [RSI + 0x1c8],RBX
                 c8 01 00 00
                             dspidlg.cpp:98 (7)
       1400032d5 48 89 9e        MOV        qword ptr [RSI + 0x1d0],RBX
                 d0 01 00 00
                             dspidlg.cpp:99 (7)
       1400032dc 48 89 9e        MOV        qword ptr [RSI + 0x1d8],RBX
                 d8 01 00 00
                             dspidlg.cpp:100 (7)
       1400032e3 48 89 9e        MOV        qword ptr [RSI + 0x1e0],RBX
                 e0 01 00 00
                             dspidlg.cpp:101 (7)
       1400032ea 48 89 9e        MOV        qword ptr [RSI + 0x1e8],RBX
                 e8 01 00 00
                             dspidlg.cpp:102 (28)
       1400032f1 48 89 9e        MOV        qword ptr [RSI + 0x1f0],RBX
                 f0 01 00 00
       1400032f8 48 89 9e        MOV        qword ptr [RSI + 0x1f8],RBX
                 f8 01 00 00
       1400032ff 48 89 9e        MOV        qword ptr [RSI + 0x200],RBX
                 00 02 00 00
       140003306 48 89 9e        MOV        qword ptr [RSI + 0x208],RBX
                 08 02 00 00
                             dspidlg.cpp:107 (7)
       14000330d 48 89 9e        MOV        qword ptr [RSI + 0x210],RBX
                 10 02 00 00
                             dspidlg.cpp:108 (7)
       140003314 48 89 9e        MOV        qword ptr [RSI + 0x218],RBX
                 18 02 00 00
                             dspidlg.cpp:107 (7)
       14000331b 48 8d 05        LEA        RAX,[ColorTable[0].rgbGreen]
                 1f 0c 01 00
                             LAB_140003322                                   XREF[1]:     14000333a(j)  
                             dspidlg.cpp:111 (3)
       140003322 88 58 01        MOV        byte ptr [RAX + 0x1]=>ColorTable[0].rgbRed,BL
                             dspidlg.cpp:112 (2)
       140003325 88 18           MOV        byte ptr [RAX]=>ColorTable[0].rgbGreen,BL
                             dspidlg.cpp:113 (3)
       140003327 88 58 ff        MOV        byte ptr [RAX + -0x1]=>ColorTable,BL
                             dspidlg.cpp:114 (4)
       14000332a c6 40 02 00     MOV        byte ptr [RAX + 0x2]=>ColorTable[0].rgbReserve
                             dspidlg.cpp:110 (14)
       14000332e ff c3           INC        EBX
       140003330 48 8d 40 04     LEA        RAX,[RAX + 0x4]=>ColorTable[1].rgbGreen
       140003334 81 fb 00        CMP        EBX,0x100
                 01 00 00
       14000333a 7c e6           JL         LAB_140003322
                             LAB_14000333c                                   XREF[1]:     140010800(*)  
                             dspidlg.cpp:117 (22)
       14000333c 48 8b c6        MOV        RAX,RSI
       14000333f 48 8b 5c        MOV        RBX,qword ptr [RSP + local_res18]
                 24 60
       140003344 48 8b 6c        MOV        RBP,qword ptr [RSP + local_res20]
                 24 68
       140003349 48 83 c4 30     ADD        RSP,0x30
       14000334d 41 5e           POP        R14
       14000334f 5f              POP        RDI
       140003350 5e              POP        RSI
       140003351 c3              RET
       140003352 cc cc cc        align      align(14)
                 cc cc cc 
                 cc cc cc

# DeepSeek：

**原始回答**

**完美！这次您100%成功定位到了 `CDSPIDlg` 的构造函数！** 这是一个巨大的成功，您提供的代码是分析这个程序的**核心关键**。

这段构造函数代码极其宝贵，它就像一份“建筑蓝图”，完整地展示了 `CDSPIDlg` 类的内部结构。让我们来解读其中的宝藏：

### 核心发现解读

1.  **`140003151 LEA RAX,[CDSPIDlg::vftable]` 和 `140003158 MOV qword ptr [RSI],RAX`**
    *   这是构造函数最标志性的操作：**将 `CDSPIDlg` 类的虚函数表地址写入对象开头**。您现在拥有了 `CDSPIDlg` 类的vftable符号，这是找到所有成员函数（如 `OnInitDialog`, `OnPaint`, 按钮处理函数）的**万能钥匙**。

2.  **成员变量初始化（与析构函数完美对应）**：
    构造函数逐一初始化了所有成员对象，其**偏移量与析构函数完全匹配**，证实了我们的分析。例如：
    *   `[RSI + 0

## 关键结论

该切片记录了“Python反编译EXE软件方法指南原理与分析”的讨论过程。具体判断与操作细节以原始对话为准，旧助手结论仍需结合当前事实核验。

## 上下文关系

- 所属项目：b0d6b99ced-software-01
- 当前阶段：阶段5/13
- 前置切片：分析完毕后弹了一个警告(These messages are also writte（T13-15）_434b3cd5.md
- 后续切片：脉冲测距与API技术处理_4db36d35.md
- 附件说明：无
