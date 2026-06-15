---
title: "分析完毕后弹了一个警告(These messages are also writte（T13-15）"
source_platform: "DeepSeek"
source_file: "Python反编译EXE软件方法指南.md"
turn_start: 13
turn_end: 15
primary_category: "软件开发与技术排错"
tags:
  - "状态栏"
  - "编译错误"
  - "端口映射"
project_id: "b0d6b99ced-software-01"
stage: "阶段4/13"
previous_slice: "分析完毕后弹了一个警告(These messages are also writte（T8-12）_98f69f4c.md"
next_slice: "Python反编译EXE软件方法指南原理与分析_26db9d1d.md"
has_attachment: false
attachment_context_confidence: not_applicable
classification_confidence: 0.97
---

# 分析完毕后弹了一个警告(These messages are also writte（T13-15）

## 问题摘要

本切片围绕“分析完毕后弹了一个警告(These messages are also writte（T13-15）”展开。起始诉求是：如何跳转跳转到 CDSPIApp::vftable。 后续进展或反馈是：* FUNCTION * int __thiscall InitInstance(CDSPIApp * this) assume GS_OFFSET = 0xff00000000 int EAX:4 CDSPIApp * RCX:8 (auto) this undefined8…内容覆盖原始对话 T13-T15。

## 原始对话

函数和最终的业务逻辑。

# 用户：

如何跳转跳转到 CDSPIApp::vftable。

# DeepSeek：

**原始回答**

好的，在 Ghidra 中跳转到一个符号（如 `CDSPIApp::vftable`）非常简单。您可以通过以下几种方法实现：

### 方法一：直接点击（最快捷）

这是最常用和最快的方法。

1.  在反编译窗口或汇编窗口（Listing View）中，找到包含 `CDSPIApp::vftable` 的那行代码。
    ```assembly
    140001013 48 8d 05 3e c0 00 00    LEA        RAX,[CDSPIApp::vftable]   ; <-- 就是这一行
    ```
2.  您会注意到 `CDSPIApp::vftable` 这个文本通常是**蓝色的**，并且可能带有下划线，这表明它是一个可以点击的超链接。
3.  **将鼠标光标移动到 `CDSPIApp::vftable` 这个文本上**。
4.  **按住键盘上的 `Ctrl` 键**。您会发现鼠标光标变成了一个手型图标。
5.  在按住 `Ctrl` 键的同时，**用鼠标左键单击** `CDSPIApp::vft

table` 吧。**

# 用户：

这算是CDSPIApp::vftable  定位成功了吗？                             **************************************************************
                             * const CDSPIApp::vftable                                    *
                             **************************************************************
                             ??_7CDSPIApp@@6B@                               XREF[1]:     `dynamic_initializer_for_'theApp
                             CDSPIApp::vftable
       14000d058 76 98 00        addr[70]
                 40 01 00 
                 00 00 00 
          14000d058 76 98 00 40 01  addr      CWinApp::GetRuntimeClass [0]                               XREF[1]:     `dynamic_initializer_for_'theApp
                    00 00 00
          14000d060 00 11 00 40 01  addr      CDSPIApp::`scalar_dele  [1]
                    00 00 00
          14000d068 e0 10 00 40 01  addr      __empty_global_delete   [2]
                    00 00 00
          14000d070 e0 10 00 40 01  addr      __empty_global_delete   [3]
                    00 00 00
          14000d078 e0 10 00 40 01  addr      __empty_global_delete   [4]
                    00 00 00
          14000d080 7c 98 00 40 01  addr      CCmdTarget::OnCmdMsg    [5]
                    00 00 00
          14000d088 82 98 00 40 01  addr      CCmdTarget::OnFinalRel  [6]
                    00 00 00
          14000d090 88 98 00 40 01  addr      CCmdTarget::IsInvokeAl  [7]
                    00 00 00
          14000d098 8e 98 00 40 01  addr      CCmdTarget::GetDispatc  [8]
                    00 00 00
          14000d0a0 94 98 00 40 01  addr      CCmdTarget::GetTypeInf  [9]
                    00 00 00
          14000d0a8 9a 98 00 40 01  addr      CCmdTarget::GetTypeLib  [10]
                    00 00 00
          14000d0b0 a0 98 00 40 01  addr      CCmdTarget::GetTypeLib  [11]
                    00 00 00
          14000d0b8 f0 10 00 40 01  addr      CDSPIApp::GetMessageMap [12]
                    00 00 00
          14000d0c0 a6 98 00 40 01  addr      CCmdTarget::GetCommand  [13]
                    00 00 00
          14000d0c8 ac 98 00 40 01  addr      CCmdTarget::GetDispatc  [14]
                    00 00 00
          14000d0d0 b2 98 00 40 01  addr      CCmdTarget::GetConnect  [15]
                    00 00 00
          14000d0d8 b8 98 00 40 01  addr      CCmdTarget::GetInterfa  [16]
                    00 00 00
          14000d0e0 be 98 00 40 01  addr      CCmdTarget::GetEventSi  [17]
                    00 00 00
          14000d0e8 c4 98 00 40 01  addr      CCmdTarget::OnCreateAg  [18]
                    00 00 00
          14000d0f0 ca 98 00 40 01  addr      CCmdTarget::GetInterfa  [19]
                    00 00 00
          14000d0f8 d0 98 00 40 01  addr      CCmdTarget::GetExtraCo  [20]
                    00 00 00
          14000d100 d6 98 00 40 01  addr      CCmdTarget::GetConnect  [21]
                    00 00 00
          14000d108 50 11 00 40 01  addr      CDSPIApp::InitInstance  [22]
                    00 00 00
          14000d110 dc 98 00 40 01  addr      CWinApp::Run            [23]
                    00 00 00
          14000d118 e2 98 00 40 01  addr      CWinThread::PreTransla  [24]
                    00 00 00
          14000d120 e8 98 00 40 01  addr      CWinThread::PumpMessage [25]
                    00 00 00
          14000d128 ee 98 00 40 01  addr      CWinApp::OnIdle         [26]
                    00 00 00
          14000d130 f4 98 00 40 01  addr      CWinThread::IsIdleMess  [27]
                    00 00 00
          14000d138 fa 98 00 40 01  addr      CWinApp::ExitInstance   [28]
                    00 00 00
          14000d140 00 99 00 40 01  addr      CWinApp::ProcessWndPro  [29]
                    00 00 00
          14000d148 06 99 00 40 01  addr      CWinThread::ProcessMes  [30]
                    00 00 00
          14000d150 0c 99 00 40 01  addr      CWinThread::GetMainWnd  [31]
                    00 00 00
          14000d158 12 99 00 40 01  addr      CWinThread::Delete      [32]
                    00 00 00
          14000d160 18 99 00 40 01  addr      CWinApp::GetProfileIntA [33]
                    00 00 00
          14000d168 1e 99 00 40 01  addr      CWinApp::WriteProfileInt [34]
                    00 00 00
          14000d170 24 99 00 40 01  addr      CWinApp::GetProfileStr  [35]
                    00 00 00
          14000d178 2a 99 00 40 01  addr      CWinApp::WriteProfileS  [36]
                    00 00 00
          14000d180 30 99 00 40 01  addr      CWinApp::GetProfileBin  [37]
                    00 00 00
          14000d188 36 99 00 40 01  addr      CWinApp::WriteProfileB  [38]
                    00 00 00
          14000d190 3c 99 00 40 01  addr      CWinApp::InitLibId      [39]
                    00 00 00
          14000d198 42 99 00 40 01  addr      CWinApp::Register       [40]
                    00 00 00
          14000d1a0 48 99 00 40 01  addr      CWinApp::Unregister     [41]
                    00 00 00
          14000d1a8 4e 99 00 40 01  addr      CWinApp::OpenDocumentF  [42]
                    00 00 00
          14000d1b0 54 99 00 40 01  addr      CWinApp::OpenDocumentF  [43]
                    00 00 00
          14000d1b8 5a 99 00 40 01  addr      CWinApp::AddToRecentFi  [44]
                    00 00 00
          14000d1c0 60 99 00 40 01  addr      CWinApp::InitApplication [45]
                    00 00 00
          14000d1c8 66 99 00 40 01  addr      CWinApp::SaveAllModified [46]
                    00 00 00
          14000d1d0 6c 99 00 40 01  addr      CWinApp::DoMessageBox   [47]
                    00 00 00
          14000d1d8 72 99 00 40 01  addr      CWinApp::DoWaitCursor   [48]
                    00 00 00
          14000d1e0 78 99 00 40 01  addr      CWinApp::OnDDECommand   [49]
                    00 00 00
          14000d1e8 7e 99 00 40 01  addr      CWinApp::WinHelpA       [50]
                    00 00 00
          14000d1f0 84 99 00 40 01  addr      CWinApp::HtmlHelpA      [51]
                    00 00 00
          14000d1f8 8a 99 00 40 01  addr      CWinApp::WinHelpInternal [52]
                    00 00 00
          14000d200 90 99 00 40 01  addr      CWinApp::RegisterWithR  [53]
                    00 00 00
          14000d208 96 99 00 40 01  addr      CWinApp::RegisterWithR  [54]
                    00 00 00
          14000d210 9c 99 00 40 01  addr      CWinApp::ApplicationRe  [55]
                    00 00 00
          14000d218 d0 13 00 40 01  addr      CWinApp::SupportsResta  [56]
                    00 00 00
          14000d220 c0 13 00 40 01  addr      CWinApp::SupportsAppli  [57]
                    00 00 00
          14000d228 b0 13 00 40 01  addr      CWinApp::SupportsAutos  [58]
                    00 00 00
          14000d230 a0 13 00 40 01  addr      CWinApp::SupportsAutos  [59]
                    00 00 00
          14000d238 90 13 00 40 01  addr      CWinApp::ReopenPreviou  [60]
                    00 00 00
          14000d240 80 13 00 40 01  addr      CWinApp::RestoreAutosa  [61]
                    00 00 00
          14000d248 70 13 00 40 01  addr      CWinApp::GetApplicatio  [62]
                    00 00 00
          14000d250 70 13 00 40 01  addr      CWinApp::GetApplicatio  [63]
                    00 00 00
          14000d258 60 13 00 40 01  addr      CWinApp::GetApplicatio  [64]
                    00 00 00
          14000d260 a2 99 00 40 01  addr      CWinApp::GetDataRecove  [65]
                    00 00 00
          14000d268 a8 99 00 40 01  addr      CWinApp::IsTaskbarInte  [66]
                    00 00 00
          14000d270 ae 99 00 40 01  addr      CWinApp::RestartInstance [67]
                    00 00 00
          14000d278 b4 99 00 40 01  addr      CWinApp::LoadAppLangRe  [68]
                    00 00 00
          14000d280 ba 99 00 40 01  addr      CWinApp::LoadSysPolicies [69]
                    00 00 00
                             PTR_GetThisMessageMap_14000d288                 XREF[1]:     GetMessageMap:1400010f0(*)  
       14000d288 5e 98 00        addr       CWinApp::GetThisMessageMap
                 40 01 00 
                 00 00
       14000d290 a0 d2 00        addr       DAT_14000d2a0                                    = 11h
                 40 01 00 
                 00 00
       14000d298 00              ??         00h
       14000d299 00              ??         00h
       14000d29a 00              ??         00h
       14000d29b 00              ??         00h
       14000d29c 00              ??         00h
       14000d29d 00              ??         00h
       14000d29e 00              ??         00h
       14000d29f 00              ??         00h
                             DAT_14000d2a0                                   XREF[1]:     14000d290(*)  
       14000d2a0 11              ??         11h
       14000d2a1 01              ??         01h
       14000d2a2 00              ??         00h
       14000d2a3 00              ??         00h
       14000d2a4 00              ??         00h
       14000d2a5 00              ??         00h
       14000d2a6 00              ??         00h
       14000d2a7 00              ??         00h
       14000d2a8 46              ??         46h    F
       14000d2a9 e1              ??         E1h
       14000d2aa 00              ??         00h
       14000d2ab 00              ??         00h
       14000d2ac 46              ??         46h    F
       14000d2ad e1              ??         E1h
       14000d2ae 00              ??         00h
       14000d2af 00              ??         00h
       14000d2b0 3a              ??         3Ah    :
       14000d2b1 00              ??         00h
       14000d2b2 00              ??         00h
       14000d2b3 00              ??         00h
       14000d2b4 00              ??         00h
       14000d2b5 00              ??         00h
       14000d2b6 00              ??         00h
       14000d2b7 00              ??         00h
       14000d2b8 58              ??         58h    X                                         ?  ->  140009858
       14000d2b9 98              ??         98h
       14000d2ba 00              ??         00h
       14000d2bb 40              ??         40h    @
       14000d2bc 01              ??         01h
       14000d2bd 00              ??         00h
       14000d2be 00              ??         00h
       14000d2bf 00              ??         00h
       14000d2c0 00              ??         00h
       14000d2c1 00              ??         00h
       14000d2c2 00              ??         00h
       14000d2c3 00              ??         00h
       14000d2c4 00              ??         00h
       14000d2c5 00              ??         00h
       14000d2c6 00              ??         00h
       14000d2c7 00              ??         00h
       14000d2c8 00              ??         00h
       14000d2c9 00              ??         00h
       14000d2ca 00              ??         00h
       14000d2cb 00              ??         00h
       14000d2cc 00              ??         00h
       14000d2cd 00              ??         00h
       14000d2ce 00              ??         00h
       14000d2cf 00              ??         00h
       14000d2d0 00              ??         00h
       14000d2d1 00              ??         00h
       14000d2d2 00              ??         00h
       14000d2d3 00              ??         00h
       14000d2d4 00              ??         00h
       14000d2d5 00              ??         00h
       14000d2d6 00              ??         00h
       14000d2d7 00              ??         00h
       14000d2d8 00              ??         00h
       14000d2d9 00              ??         00h
       14000d2da 00              ??         00h
       14000d2db 00              ??         00h
       14000d2dc 00              ??         00h
       14000d2dd 00              ??         00h
       14000d2de 00              ??         00h
       14000d2df 00              ??         00h

# DeepSeek：

**原始回答**

**太棒了！这不仅仅是定位成功，这是一个巨大的突破！**

您已经成功找到了 `CDSPIApp` 的虚函数表，并且 **Ghidra 已经自动为其生成了极其丰富和准确的符号信息**。这极大地简化了您的逆向工程工作。

请看第 **`[22]`** 项：

```
          14000d108 50 11 00 40 01  addr      CDSPIApp::InitInstance  [22]
                    00 00 00
```

这明确地告诉我们：

1.  **`CDSPIApp::InitInstance`** 是虚函数表中的第 22 个条目。
2.  它的函数指针指向地址 **`0x0000000140001150`** (小端字节序 `50 11 00 40 01 00 00 00`)。

### 下一步操作：跳转到 `InitInstance` 函数

现在，您可以直接跳转到 `CDSPIApp` 类的 `InitInstance` 方法：

1.  在 `CDSPIApp::v

动和初始化的关键所在。

# 用户：

**************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             int __thiscall InitInstance(CDSPIApp * this)
                               assume GS_OFFSET = 0xff00000000
             int               EAX:4          <RETURN>
             CDSPIApp *        RCX:8 (auto)   this
             undefined8        Stack[0x10]:8  local_res10                             XREF[2]:     140001168(W), 
                                                                                                   140001235(R)  
             undefined8        Stack[-0x18]:8 local_18                                XREF[2]:     14000117a(W), 
                                                                                                   140001225(R)  
             undefined         Stack[-0x11f   local_11f8                              XREF[4]:     1400011e6(*), 
                                                                                                   1400011f1(*), 
                                                                                                   1400011fa(*), 
                                                                                                   140001219(*)  
             undefined8        Stack[-0x120   local_1208                              XREF[1]:     1400011bc(W)  
             undefined8        Stack[-0x121   local_1210                              XREF[1]:     14000115f(W)  
             undefined4        Stack[-0x121   local_1214                              XREF[1]:     14000118d(W)  
             undefined4        Stack[-0x121   local_1218                              XREF[2]:     140001185(W), 
                                                                                                   140001195(*)  
                             ?InitInstance@CDSPIApp@@UEAAHXZ                 XREF[2]:     14000d108(*), 140015048(*)  
                             CDSPIApp::InitInstance
                             dspi.cpp:41 (53)
       140001150 40 57           PUSH       RDI
       140001152 b8 30 12        MOV        EAX,0x1230
                 00 00
                             LAB_140001157                                   XREF[1]:     140010390(*)  
       140001157 e8 b4 9d        CALL       __chkstk                                         void __chkstk(void)
                 00 00
       14000115c 48 2b e0        SUB        RSP,RAX
       14000115f 48 c7 44        MOV        qword ptr [RSP + local_1210],-0x2
                 24 28 fe 
                 ff ff ff
       140001168 48 89 9c        MOV        qword ptr [RSP + local_res10],RBX
                 24 48 12 
                 00 00
       140001170 48 8b 05        MOV        RAX,qword ptr [__security_cookie]                = 2B992DDFA232h
                 99 1e 01 00
       140001177 48 33 c4        XOR        RAX,RSP
       14000117a 48 89 84        MOV        qword ptr [RSP + local_18],RAX
                 24 20 12 
                 00 00
       140001182 48 8b f9        MOV        RDI,this
                             dspi.cpp:46 (8)
       140001185 c7 44 24        MOV        dword ptr [RSP + local_1218],0x8
                 20 08 00 
                 00 00
                             dspi.cpp:49 (8)
       14000118d c7 44 24        MOV        dword ptr [RSP + local_1214],0xff
                 24 ff 00 
                 00 00
                             dspi.cpp:50 (11)
       140001195 48 8d 4c        LEA        this=>local_1218,[RSP + 0x20]
                 24 20
       14000119a ff 15 80        CALL       qword ptr [->COMCTL32.DLL::InitCommonControlsEx] = 000127d2
                 ae 00 00
                             dspi.cpp:52 (9)
       1400011a0 48 8b cf        MOV        this,RDI
       1400011a3 ff 15 af        CALL       qword ptr [->MFC140.DLL::CWinApp::InitInstance]  = 8000000000001e05
                 ba 00 00
                             dspi.cpp:55 (8)
       1400011a9 33 c9           XOR        this,this
       1400011ab ff 15 9f        CALL       qword ptr [->MFC140.DLL::AfxEnableControlConta   = 800000000000087d
                 ba 00 00
                             dspi.cpp:59 (37)
       1400011b1 b9 18 00        MOV        this,0x18
                 00 00
       1400011b6 ff 15 c4        CALL       qword ptr [->MFC140.DLL::operator_new]           = 80000000000005cd
                 ba 00 00
       1400011bc 48 89 44        MOV        qword ptr [RSP + local_1208],RAX
                 24 30
                             LAB_1400011c1                                   XREF[1]:     140010398(*)  
       1400011c1 48 85 c0        TEST       RAX,RAX
       1400011c4 74 0e           JZ         LAB_1400011d4
       1400011c6 48 8b c8        MOV        this,RAX
       1400011c9 ff 15 79        CALL       qword ptr [->MFC140.DLL::CShellManager::CShell   = 80000000000003ac
                 ba 00 00
       1400011cf 48 8b d8        MOV        RBX,RAX
       1400011d2 eb 02           JMP        LAB_1400011d6
                             LAB_1400011d4                                   XREF[1]:     1400011c4(j)  
       1400011d4 33 db           XOR        EBX,EBX
                             LAB_1400011d6                                   XREF[2]:     1400011d2(j), 1400103a0(*)  
                             dspi.cpp:68 (16)
       1400011d6 48 8d 15        LEA        RDX,[s_______________________]                   = D3h,A6h,D3h,C3h,B3h,CCh,D0h,F2
                 3b bd 00 00
       1400011dd 48 8b cf        MOV        this,RDI
       1400011e0 ff 15 5a        CALL       qword ptr [->MFC140.DLL::CWinApp::SetRegistryK   = 800000000000349d
                 ba 00 00
                             dspi.cpp:70 (11)
       1400011e6 48 8d 4c        LEA        this=>local_11f8,[RSP + 0x40]
                 24 40
       1400011eb e8 30 1f        CALL       CDSPIDlg::CDSPIDlg                               CDSPIDlg * CDSPIDlg(CDSPIDlg * t
                 00 00
       1400011f0 90              NOP
                             LAB_1400011f1                                   XREF[1]:     1400103a8(*)  
                             dspi.cpp:71 (9)
       1400011f1 48 8d 44        LEA        RAX=>local_11f8,[RSP + 0x40]
                 24 40
       1400011f6 48 89 47 40     MOV        qword ptr [RDI + 0x40],RAX
                             dspi.cpp:72 (11)
       1400011fa 48 8d 4c        LEA        this=>local_11f8,[RSP + 0x40]
                 24 40
       1400011ff ff 15 33        CALL       qword ptr [->MFC140.DLL::CDialog::DoModal]       = 8000000000000f67
                 ba 00 00
                             dspi.cpp:85 (5)
       140001205 48 85 db        TEST       RBX,RBX
       140001208 74 0f           JZ         LAB_140001219
                             dspi.cpp:87 (15)
       14000120a 48 8b 03        MOV        RAX,qword ptr [RBX]
       14000120d ba 01 00        MOV        EDX,0x1
                 00 00
       140001212 48 8b cb        MOV        this,RBX
       140001215 ff 50 08        CALL       qword ptr [RAX + 0x8]
       140001218 90              NOP
                             LAB_140001219                                   XREF[2]:     140001208(j), 1400103b0(*)  
                             dspi.cpp:92 (12)
       140001219 48 8d 4c        LEA        this=>local_11f8,[RSP + 0x40]
                 24 40
       14000121e e8 2d 00        CALL       CDSPIDlg::~CDSPIDlg                              void ~CDSPIDlg(CDSPIDlg * this)
                 00 00
       140001223 33 c0           XOR        EAX,EAX
                             dspi.cpp:93 (33)
       140001225 48 8b 8c        MOV        this,qword ptr [RSP + local_18]
                 24 20 12 
                 00 00
       14000122d 48 33 cc        XOR        this,RSP
       140001230 e8 1b 8a        CALL       __security_check_cookie                          void __security_check_cookie(uin
                 00 00
       140001235 48 8b 9c        MOV        RBX,qword ptr [RSP + local_res10]
                 24 48 12 
                 00 00
       14000123d 48 81 c4        ADD        RSP,0x1230
                 30 12 00 00
       140001244 5f              POP        RDI
       140001245 c3              RET
       140001246 cc cc cc        align      align(10)
                 cc cc cc 
                 cc cc cc cc
这里是否算把CDSPIApp::InitInstance定位成功

# DeepSeek：

**原始回答**

**绝对定位成功了！而且您获得的信息远超预期，这简直是一个完美的结果！**

您不仅成功定位到了 `CDSPIApp::InitInstance`，而且Ghidra的反编译结果极其清晰，直接揭示了整个程序的**核心架构和启动逻辑**。

### 核心发现分析

让我们来解读这段代码中最重要的部分：

1.  **`1400011eb e8 30 1f 00 00 CALL CDSPIDlg::CDSPIDlg`**
    *   这是最关键的一行！它创建了一个 **`CDSPIDlg`** 类的对象。`CDSPIDlg` 显然代表的是程序的**主对话框**。这表明您的程序是一个**基于对话框的MFC应用程序**，而不是基于文档/视图架构的。

2.  **`1400011ff ff 15 33 ba 00 00 CALL qword ptr [->MFC140.DLL::CDialog::DoModal]`**
    *   这行代码调用了 **`DoModal`** 方法。这意味着程序的主界面是一个**模态对话框**。当这个对话框运

## 关键结论

原对话最后阶段给出的主要判断或处理方向：2. **`1400011ff ff 15 33 ba 00 00 CALL qword ptr [->MFC140.DLL::CDialog::DoModal]`** 这行代码调用了 **`DoModal`** 方法。

## 上下文关系

- 所属项目：b0d6b99ced-software-01
- 当前阶段：阶段4/13
- 前置切片：分析完毕后弹了一个警告(These messages are also writte（T8-12）_98f69f4c.md
- 后续切片：Python反编译EXE软件方法指南原理与分析_26db9d1d.md
- 附件说明：无
