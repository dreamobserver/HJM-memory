---
title: "API技术处理"
source_platform: "DeepSeek"
source_file: "Python反编译EXE软件方法指南.md"
turn_start: 31
turn_end: 34
primary_category: "软件开发与技术排错"
tags:
  - "API"
  - "编译错误"
project_id: "b0d6b99ced-software-01"
stage: "阶段10/13"
previous_slice: "脉冲测距与API原理与分析_58dc1a1f.md"
next_slice: "现在我要使用一个新的相移器代替其旧的作用，但是新的相移器没有sdk，只有一个控制软件_396d28ff.md"
has_attachment: false
attachment_context_confidence: not_applicable
classification_confidence: 0.97
---

# API技术处理

## 问题摘要

本切片围绕“API技术处理”展开。起始诉求是：只有atan函数，定位如下 ************************************************************** THUNK FUNCTION * thunk double __cdecl atan(double _X) Thunked-F… 后续进展或反馈是：140008C2D的定位如下： ************************************************************** FUNCTION * undefined __fastcall FUN_140008c2d(void) assume GS…内容覆盖原始对话 T31-T34。

## 原始对话

开始您的下一步分析。

# 用户：

只有atan函数，定位如下                             **************************************************************
                             *                       THUNK FUNCTION                       *
                             **************************************************************
                             thunk double __cdecl atan(double _X)
                               Thunked-Function: API-MS-WIN-CRT-MATH-L1-
                               assume GS_OFFSET = 0xff00000000
             double            XMM0_Qa:8      <RETURN>
             double            XMM0_Qa:8      _X
                             atan                                            XREF[3]:     FUN_1400059c9:140005a69(c), 
                                                                                          FUN_140008c2d:140008cbd(c), 
                                                                                          FUN_140008c2d:140008cf9(c)  
       14000b23d ff 25 b5        JMP        qword ptr [->API-MS-WIN-CRT-MATH-L1-1-0.DLL::a
                 11 00 00

# DeepSeek：

**原始回答**

非常好！您成功定位到了 `atan` 函数，并且 Ghidra 显示了它的交叉引用（XRefs）。这是**最关键的一步**，因为这些交叉引用直接将您引向程序中执行数学计算的核心函数！

### 分析交叉引用

从信息中可以看到，`atan` 函数被以下三个函数调用：

1.  **`FUN_1400059c9:140005a69(c)`**
2.  **`FUN_140008c2d:140008cbd(c)`**
3.  **`FUN_140008c2d:140008cf9(c)`**

这告诉我们：
*   有两个不同的函数（`FUN_1400059c9` 和 `FUN_140008c2d`）包含了相位计算。
*   函数 `FUN_140008c2d` 内部有两个不同的地方调用了 `atan`。

**这些 `FUN_1400059c9` 和 `FUN_140008c2d` 极大概率就是您要找的相位计算核心算法函数！**

### 下一步操作：深入分析核心函数

您现在应该立即跳转到这两个函数进行分析：

1.  **在 Ghidra

算部分。祝您分析顺利！

# 用户：

这是1400059c9的定位与伪代码：定位：                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined __fastcall FUN_1400059c9(void)
                               assume GS_OFFSET = 0xff00000000
             undefined         <UNASSIGNED>   <RETURN>
             undefined1[16]    Stack[0x20]:16 local_res20                             XREF[1]:     140005ab1(R)  
                             FUN_1400059c9                                   XREF[3]:     140010ca4(*), 140010cb4(*), 
                                                                                          1400154b0(*)  
       1400059c9 49 89 5b 08     MOV        qword ptr [R11 + 0x8],RBX
 伪代码： *(undefined8 *)(in_R11 + 8) = unaff_RBX;

# DeepSeek：

**原始回答**

这个反编译结果看起来不完整，Ghidra 似乎没有正确识别出函数的边界和参数。`MOV qword ptr [R11 + 0x8],RBX` 看起来更像是函数**内部**的指令，而不是函数的开头。

我们需要手动帮助 Ghidra 正确识别这个函数。请按照以下步骤操作：

### 第1步：删除并重新创建函数

1.  在 Ghidra 的汇编窗口（Listing View）中，导航到地址 `1400059c9`。
2.  在该地址上**右键单击**。
3.  选择 **`Functions`** -> **`Delete Function`**。
4.  现在，同一地址应该显示为未定义的代码（可能是 `??` 或原始字节）。
5.  再次在地址 `1400059c9` 上**右键单击**。
6.  选择 **`Functions`** -> **`Create Function`**。
7.  在弹出的对话框中，Ghidra 可能会自动建议一个函数名，您可以保留 `FUN_1400059c9` 或为其命名（如 `CalculatePhas

a69` 周围的代码。

# 用户：

重新定位如下，                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined __fastcall FUN_1400059c9(void)
                               assume GS_OFFSET = 0xff00000000
             undefined         <UNASSIGNED>   <RETURN>
             undefined1[16]    Stack[0x20]:16 local_res20                             XREF[1]:     140005ab1(R)  
                             FUN_1400059c9                                   XREF[3]:     140010ca4(*), 140010cb4(*), 
                                                                                          1400154b0(*)  
       1400059c9 49 89 5b 08     MOV        qword ptr [R11 + 0x8],RBX
       1400059cd 49 89 6b 10     MOV        qword ptr [R11 + 0x10],RBP
       1400059d1 49 89 73 18     MOV        qword ptr [R11 + 0x18],RSI
       1400059d5 4d 89 63 20     MOV        qword ptr [R11 + 0x20],R12
       1400059d9 41 bc bf        MOV        R12D,0xbf
                 00 00 00
       1400059df 4d 89 73 e8     MOV        qword ptr [R11 + -0x18],R14
       1400059e3 45 8b f7        MOV        R14D,R15D
       1400059e6 0f 29 74        MOVAPS     xmmword ptr [RSP + Stack[0x40]],XMM6
                 24 40
       1400059eb f2 0f 10        MOVSD      XMM6,qword ptr [__real@406fe00000000000]         = 406FE00000000000h
                 35 b5 94 
                 00 00
       1400059f3 0f 29 7c        MOVAPS     xmmword ptr [RSP + Stack[0x30]],XMM7
                 24 30
       1400059f8 f2 0f 10        MOVSD      XMM7,qword ptr [__real@3fe0000000000000]         = 3FE0000000000000h
                 3d 80 94 
                 00 00
       140005a00 45 0f 29        MOVAPS     xmmword ptr [R11 + -0x48],XMM8
                 43 b8
       140005a05 f2 44 0f        MOVSD      XMM8,qword ptr [__real@400921fb4d12d84a]         = 400921FB4D12D84Ah
                 10 05 82 
                 94 00 00
       140005a0e 66 90           NOP
                             LAB_140005a10                                   XREF[1]:     140005aab(j)  
                             dspidlg.cpp:1240 (19)
       140005a10 48 8b 87        MOV        RAX,qword ptr [RDI + 0x200]
                 00 02 00 00
       140005a17 48 8b 9f        MOV        RBX,qword ptr [RDI + 0x1f0]
                 f0 01 00 00
       140005a1e 42 0f b6        MOVZX      ECX,byte ptr [RAX + R14*0x1]
                 0c 30
                             dspidlg.cpp:1241 (33)
       140005a23 48 8b 87        MOV        RAX,qword ptr [RDI + 0x208]
                 08 02 00 00
       140005a2a 42 0f b6        MOVZX      EBP,byte ptr [RBX + R14*0x1]
                 2c 33
       140005a2f 2b e9           SUB        EBP,ECX
       140005a31 42 0f b6        MOVZX      ESI,byte ptr [RAX + R14*0x1]
                 34 30
       140005a36 48 8b 87        MOV        RAX,qword ptr [RDI + 0x1f8]
                 f8 01 00 00
       140005a3d 41 0f b6        MOVZX      ECX,byte ptr [R14 + RAX*0x1]
                 0c 06
       140005a42 2b f1           SUB        ESI,ECX
                             dspidlg.cpp:1242 (4)
       140005a44 85 ed           TEST       EBP,EBP
       140005a46 75 0d           JNZ        LAB_140005a55
                             dspidlg.cpp:1251 (17)
       140005a48 85 f6           TEST       ESI,ESI
       140005a4a b8 3f 00        MOV        EAX,0x3f
                 00 00
       140005a4f 41 0f 4e c4     CMOVLE     EAX,R12D
       140005a53 eb 38           JMP        LAB_140005a8d
                             LAB_140005a55                                   XREF[1]:     140005a46(j)  
       140005a55 66 0f 6e cd     MOVD       XMM1,EBP
                             dspidlg.cpp:1253 (42)
       140005a59 f3 0f e6 c9     CVTDQ2PD   XMM1,XMM1
       140005a5d 66 0f 6e c6     MOVD       XMM0,ESI
       140005a61 f3 0f e6 c0     CVTDQ2PD   XMM0,XMM0
       140005a65 f2 0f 5e c1     DIVSD      XMM0,XMM1
       140005a69 e8 cf 57        CALL       atan                                             double atan(double _X)
                 00 00
       140005a6e f2 0f 59 c6     MULSD      XMM0,XMM6
       140005a72 f2 0f 59 c7     MULSD      XMM0,XMM7
       140005a76 f2 41 0f        DIVSD      XMM0,XMM8
                 5e c0
       140005a7b f2 0f 2c c0     CVTTSD2SI  EAX,XMM0
       140005a7f 85 ed           TEST       EBP,EBP
       140005a81 7e 08           JLE        LAB_140005a8b
                             dspidlg.cpp:1254 (4)
       140005a83 85 f6           TEST       ESI,ESI
       140005a85 7f 06           JG         LAB_140005a8d
                             dspidlg.cpp:1258 (2)
       140005a87 fe c8           DEC        AL
                             dspidlg.cpp:1261 (2)
       140005a89 eb 02           JMP        LAB_140005a8d
                             LAB_140005a8b                                   XREF[1]:     140005a81(j)  
                             dspidlg.cpp:1262 (2)
       140005a8b 04 7f           ADD        AL,0x7f
                             LAB_140005a8d                                   XREF[3]:     140005a53(j), 140005a85(j), 
                                                                                          140005a89(j)  
                             dspidlg.cpp:1239 (83)
       140005a8d 42 88 04 33     MOV        byte ptr [RBX + R14*0x1],AL
       140005a91 41 ff c7        INC        R15D
       140005a94 8b 97 34        MOV        EDX,dword ptr [RDI + 0xa34]
                 0a 00 00
       140005a9a 49 ff c6        INC        R14
       140005a9d 8b 8f 38        MOV        ECX,dword ptr [RDI + 0xa38]
                 0a 00 00
       140005aa3 8b c2           MOV        EAX,EDX
       140005aa5 0f af c1        IMUL       EAX,ECX
       140005aa8 44 3b f8        CMP        R15D,EAX
       140005aab 0f 8c 5f        JL         LAB_140005a10
                 ff ff ff
       140005ab1 44 0f 28        MOVAPS     XMM8,xmmword ptr [RSP + local_res20[0]]
                 44 24 20
       140005ab7 0f 28 7c        MOVAPS     XMM7,xmmword ptr [RSP + Stack[0x30]]
                 24 30
       140005abc 0f 28 74        MOVAPS     XMM6,xmmword ptr [RSP + Stack[0x40]]
                 24 40
       140005ac1 4c 8b 74        MOV        R14,qword ptr [RSP + Stack[0x50]]
                 24 50
       140005ac6 4c 8b a4        MOV        R12,qword ptr [RSP + Stack[0x88]]
                 24 88 00 
                 00 00
       140005ace 48 8b b4        MOV        RSI,qword ptr [RSP + Stack[0x80]]
                 24 80 00 
                 00 00
       140005ad6 48 8b 6c        MOV        RBP,qword ptr [RSP + Stack[0x78]]
                 24 78
       140005adb 48 8b 5c        MOV        RBX,qword ptr [RSP + Stack[0x70]]
                 24 70

# DeepSeek：

**原始回答**

**太棒了！您已经成功定位到了核心的相位计算函数！** 这段反编译代码非常宝贵，它清晰地展示了数字散斑干涉测量（DSPI）中**相位计算的核心算法**。

### 核心算法分析

让我们来逐行解读这个函数的关键部分，它实现了一个标准的**四步相移法相位提取算法**：

1.  **图像数据加载** (`140005a10` - `140005a42`):
    ```assembly
    MOV RAX,qword ptr [RDI + 0x200] ; 加载第4幅图像指针 (I4)
    MOV RBX,qword ptr [RDI + 0x1f0] ; 加载结果图像指针 (Phase Map)
    MOVZX ECX,byte ptr [RAX + R14*0x1] ; 读取 I4[x,y]
    
    MOV RAX,qword ptr [RDI + 0x208] ; 加载第2幅图像指针 (I2)
    MOVZX EBP,byte ptr [RBX + R14*0x1] ; (这行可能有问题，似乎是复用RBX)

心的算法部分！恭喜您！

# 用户：

140008C2D的定位如下：                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined __fastcall FUN_140008c2d(void)
                               assume GS_OFFSET = 0xff00000000
             undefined         <UNASSIGNED>   <RETURN>
                             FUN_140008c2d                                   XREF[3]:     14001103c(*), 14001104c(*), 
                                                                                          140015720(*)  
                             fundib.cpp:756 (83)
       140008c2d 0f 29 bc        MOVAPS     xmmword ptr [RSP + Stack[0x90]],XMM7
                 24 90 00 
                 00 00
       140008c35 45 33 f6        XOR        R14D,R14D
       140008c38 44 0f 29        MOVAPS     xmmword ptr [RSP + Stack[0x60]],XMM10
                 54 24 60
       140008c3e 0f 57 ff        XORPS      XMM7,XMM7
       140008c41 f2 44 0f        MOVSD      XMM10,qword ptr [__real@401921fb4d12d84a]        = 401921FB4D12D84Ah
                 10 15 56 
                 62 00 00
       140008c4a 44 0f 29        MOVAPS     xmmword ptr [RSP + Stack[0x50]],XMM11
                 5c 24 50
       140008c50 f2 44 0f        MOVSD      XMM11,qword ptr [__real@3fe0000000000000]        = 3FE0000000000000h
                 10 1d 27 
                 62 00 00
       140008c59 44 0f 29        MOVAPS     xmmword ptr [RSP + Stack[0x40]],XMM12
                 64 24 40
       140008c5f f2 44 0f        MOVSD      XMM12,qword ptr [__real@3ff921fb4d12d84a]        = 3FF921FB4D12D84Ah
                 10 25 20 
                 62 00 00
       140008c68 44 0f 29        MOVAPS     xmmword ptr [RSP + Stack[0x30]],XMM13
                 6c 24 30
       140008c6e f2 44 0f        MOVSD      XMM13,qword ptr [__real@4012d97c79ce2238]        = 4012D97C79CE2238h
                 10 2d 21 
                 62 00 00
       140008c77 66 0f 1f        NOP        word ptr [RAX + RAX*0x1]
                 84 00 00 
                 00 00 00
                             LAB_140008c80                                   XREF[1]:     140008d3b(j)  
                             fundib.cpp:762 (13)
       140008c80 8b 43 3c        MOV        EAX,dword ptr [RBX + 0x3c]
       140008c83 33 f6           XOR        ESI,ESI
       140008c85 85 c0           TEST       EAX,EAX
       140008c87 0f 8e a6        JLE        LAB_140008d33
                 00 00 00
                             fundib.cpp:773 (3)
       140008c8d 49 63 fe        MOVSXD     RDI,R14D
                             LAB_140008c90                                   XREF[1]:     140008d2d(j)  
                             fundib.cpp:764 (33)
       140008c90 0f af c5        IMUL       EAX,EBP
       140008c93 03 c6           ADD        EAX,ESI
       140008c95 48 63 c8        MOVSXD     RCX,EAX
       140008c98 48 8b 83        MOV        RAX,qword ptr [RBX + 0xa8]
                 a8 00 00 00
       140008c9f f2 0f 10        MOVSD      XMM1,qword ptr [RAX + RCX*0x8]
                 0c c8
       140008ca4 66 0f 2f f9     COMISD     XMM7,XMM1
       140008ca8 48 8b 83        MOV        RAX,qword ptr [RBX + 0xa0]
                 a0 00 00 00
       140008caf 76 25           JBE        LAB_140008cd6
                             fundib.cpp:766 (23)
       140008cb1 f2 0f 10        MOVSD      XMM6,qword ptr [RAX + RCX*0x8]
                 34 c8
       140008cb6 0f 28 c6        MOVAPS     XMM0,XMM6
       140008cb9 f2 0f 5e c1     DIVSD      XMM0,XMM1
       140008cbd e8 7b 25        CALL       atan                                             double atan(double _X)
                 00 00
       140008cc2 66 0f 2f f7     COMISD     XMM6,XMM7
       140008cc6 76 07           JBE        LAB_140008ccf
                             fundib.cpp:768 (5)
       140008cc8 f2 41 0f        ADDSD      XMM0,XMM8
                 58 c0
                             fundib.cpp:775 (2)
       140008ccd eb 2f           JMP        LAB_140008cfe
                             LAB_140008ccf                                   XREF[1]:     140008cc6(j)  
                             fundib.cpp:777 (5)
       140008ccf f2 41 0f        SUBSD      XMM0,XMM8
                 5c c0
                             fundib.cpp:783 (2)
       140008cd4 eb 28           JMP        LAB_140008cfe
                             LAB_140008cd6                                   XREF[1]:     140008caf(j)  
                             fundib.cpp:785 (13)
       140008cd6 66 0f 2e cf     UCOMISD    XMM1,XMM7
       140008cda f2 0f 10        MOVSD      XMM0,qword ptr [RAX + RCX*0x8]
                 04 c8
       140008cdf 7a 14           JP         LAB_140008cf5
       140008ce1 75 12           JNZ        LAB_140008cf5
                             fundib.cpp:787 (6)
       140008ce3 66 0f 2f c7     COMISD     XMM0,XMM7
       140008ce7 76 06           JBE        LAB_140008cef
                             fundib.cpp:789 (4)
       140008ce9 41 0f 28 c4     MOVAPS     XMM0,XMM12
                             fundib.cpp:791 (2)
       140008ced eb 1a           JMP        LAB_140008d09
                             LAB_140008cef                                   XREF[1]:     140008ce7(j)  
                             fundib.cpp:797 (4)
       140008cef 41 0f 28 c5     MOVAPS     XMM0,XMM13
                             fundib.cpp:801 (2)
       140008cf3 eb 14           JMP        LAB_140008d09
                             LAB_140008cf5                                   XREF[2]:     140008cdf(j), 140008ce1(j)  
                             fundib.cpp:803 (9)
       140008cf5 f2 0f 5e c1     DIVSD      XMM0,XMM1
       140008cf9 e8 3f 25        CALL       atan                                             double atan(double _X)
                 00 00
                             LAB_140008cfe                                   XREF[2]:     140008ccd(j), 140008cd4(j)  
                             fundib.cpp:762 (53)
       140008cfe 66 0f 2f f8     COMISD     XMM7,XMM0
       140008d02 76 05           JBE        LAB_140008d09
       140008d04 f2 41 0f        ADDSD      XMM0,XMM10
                 58 c2
                             LAB_140008d09                                   XREF[3]:     140008ced(j), 140008cf3(j), 
                                                                                          140008d02(j)  
       140008d09 48 8b 43 50     MOV        RAX,qword ptr [RBX + 0x50]
       140008d0d ff c6           INC        ESI
       140008d0f f2 41 0f        MULSD      XMM0,XMM9
                 59 c1
       140008d14 f2 41 0f        MULSD      XMM0,XMM11
                 59 c3
       140008d19 f2 41 0f        DIVSD      XMM0,XMM8
                 5e c0
       140008d1e f2 0f 2c c8     CVTTSD2SI  ECX,XMM0
       140008d22 88 0c 07        MOV        byte ptr [RDI + RAX*0x1],CL
       140008d25 48 ff c7        INC        RDI
       140008d28 8b 43 3c        MOV        EAX,dword ptr [RBX + 0x3c]
       140008d2b 3b f0           CMP        ESI,EAX
       140008d2d 0f 8c 5d        JL         LAB_140008c90
                 ff ff ff
                             LAB_140008d33                                   XREF[1]:     140008c87(j)  
                             fundib.cpp:760 (46)
       140008d33 ff c5           INC        EBP
       140008d35 45 03 f4        ADD        R14D,R12D
       140008d38 3b 6b 40        CMP        EBP,dword ptr [RBX + 0x40]
       140008d3b 0f 8c 3f        JL         LAB_140008c80
                 ff ff ff
       140008d41 44 0f 28        MOVAPS     XMM13,xmmword ptr [RSP + Stack[0x30]]
                 6c 24 30
       140008d47 44 0f 28        MOVAPS     XMM12,xmmword ptr [RSP + Stack[0x40]]
                 64 24 40
       140008d4d 44 0f 28        MOVAPS     XMM11,xmmword ptr [RSP + Stack[0x50]]
                 5c 24 50
       140008d53 44 0f 28        MOVAPS     XMM10,xmmword ptr [RSP + Stack[0x60]]
                 54 24 60
       140008d59 0f 28 bc        MOVAPS     XMM7,xmmword ptr [RSP + Stack[0x90]]
                 24 90 00 
                 00 00

# DeepSeek：

**原始回答**

**完美！您已经成功定位到了第二个核心函数。这个函数 `FUN_140008c2d` 同样极其重要，它实现了另一种形式的相位计算，很可能用于处理复数或矢量数据，或者就是另一种相移算法。**

### 核心算法分析

这个函数同样包含一个嵌套循环结构，对数据进行逐像素处理，并两次调用 `atan` 函数。让我们分析其关键部分：

1.  **常数加载** (`140008c41` - `140008c6e`):
    *   `XMM10 = 6.283185307179586` (2π) (`401921fb4d12d84Ah`)
    *   `XMM11 = 0.5` (`3fe0000000000000h`)
    *   `XMM12 = 1.5707963267948966` (π/2) (`3ff921fb4d12d84Ah`)
    *   `XMM13 = 4.71238898038469` (3π/2) (`4012d97c79ce2238h`)
    *   这些常数的加载表明它正在进行**角度和弧度的转换*

## 关键结论

该切片记录了“API技术处理”的讨论过程。具体判断与操作细节以原始对话为准，旧助手结论仍需结合当前事实核验。

## 上下文关系

- 所属项目：b0d6b99ced-software-01
- 当前阶段：阶段10/13
- 前置切片：脉冲测距与API原理与分析_58dc1a1f.md
- 后续切片：现在我要使用一个新的相移器代替其旧的作用，但是新的相移器没有sdk，只有一个控制软件_396d28ff.md
- 附件说明：无
