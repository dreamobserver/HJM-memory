# FUNCTION                          *

**分类**：光学与物理实验
**来源**：DeepSeek Chat 导出
**来源平台**：DeepSeek
**原始文件**：Python反编译EXE软件方法指南.md
**包含轮次**：15 - 15

---

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
    *   这行代码调用了 **`DoModal`** 方法。这意味着程序的主界面是一个**模态对话框**。当这个对话框运行时，它会接管主要的消息循环，直到对话框关闭，程序才会退出。

3.  **`1400011e0 CALL qword ptr [->MFC140.DLL::CWinApp::SetRegistryKey`**
    *   程序设置了注册表键，说明它很可能使用Windows注册表来存储配置信息。

### 这对您意味着什么？

您的分析策略需要做出重大调整：

*   **忘记 `CMainFrame`**：因为这是一个对话框程序，没有传统的主框架窗口。
*   **新的核心目标**：您现在需要关注的核心类是 **`CDSPIDlg`**（数字散斑干涉相位测量对话框）。
*   **主逻辑所在地**：所有主要的用户交互、按钮点击事件、图像处理算法**极有可能都位于 `CDSPIDlg` 类的成员函数中**。

### 接下来的行动路线

1.  **跳转到 `CDSPIDlg` 的构造函数**：
    *   在反编译窗口中，**按住 `Ctrl` 键并点击** `CDSPIDlg::CDSPIDlg`。
    *   这会带您到对话框的构造函数，您可以看看它初始化了哪些成员变量。

2.  **找到 `CDSPIDlg` 的消息映射**：
    *   和之前查找 `CDSPIApp` 的方法一样，您需要找到 `CDSPIDlg` 的虚函数表或消息映射。
    *   在 `CDSPIDlg` 的构造函数或附近代码中，寻找对其虚函数表的引用。
    *   或者，在 **`Symbol Tree`** -> **`Data`** 中搜索 `CDSPIDlg::vftable`。

3.  **分析 `CDSPIDlg` 的消息处理函数**：
    *   一旦找到 `CDSPIDlg` 的虚函数表，寻找其中的消息处理函数，特别是处理 `WM_COMMAND` 消息的函数（如 `OnBnClickedButton1` 这样的按钮点击处理函数）。
    *   **这里才是您最终会找到相位计算、图像处理、相机控制等核心算法的地方。**

4.  **查看字符串参考**：
    *   使用 **`Search`** -> **`Program Text...`** 搜索界面上的按钮文字（如“开始计算”、“采集图像”等），然后通过交叉引用找到处理这些命令的函数。

### 总结

您已经完全成功地定位了 `InitInstance`，并且有了一个极其关键的发现：**这是一个基于对话框的MFC应用程序，主对话框类是 `CDSPIDlg`**。

**您的逆向工程焦点现在应该立刻从 `CDSPIApp` 转移到 `CDSPIDlg` 类上。** 这个类才是实现所有相位测量 DSPI 功能的核心。

恭喜您，您已经穿透了MFC框架的层层包装，即将触达程序最核心的业务逻辑层！下一步就是深入分析 `CDSPIDlg` 类了。

