
/* 140001000 FUN_140001000 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140001000(void)

{
  CWinApp::CWinApp((CWinApp *)&DAT_140014340,(char *)0x0);
  _DAT_14001448c = 1;
  _DAT_140014340 = CDSPIApp::vftable;
  atexit((_func_5014 *)&LAB_14000b6c0);
  return;
}



/* 140001040 FUN_140001040 */

void FUN_140001040(void)

{
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             &DAT_1400144b8,&DAT_14000d300);
  atexit((_func_5014 *)&LAB_14000b6d0);
  return;
}



/* 140001070 FUN_140001070 */

void FUN_140001070(void)

{
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             &DAT_1400144c0,&DAT_14000d4b0);
  atexit((_func_5014 *)&LAB_14000b6e0);
  return;
}



/* 140001098 FUN_140001098 */

void FUN_140001098(void)

{
  ATL::CAtlBaseModule::CAtlBaseModule((CAtlBaseModule *)&DAT_140013eb0);
  atexit((_func_5014 *)&LAB_14000b770);
  return;
}



/* 1400010b8 FUN_1400010b8 */

void FUN_1400010b8(void)

{
  undefined8 uVar1;
  
  uVar1 = FUN_14000b108(0,0xe00);
  DAT_140013f14 = (char)uVar1;
  return;
}



/* 1400010e0 _guard_check_icall */

void _guard_check_icall(void)

{
  return;
}



/* 1400010f0 FUN_1400010f0 */

undefined8 FUN_1400010f0(void)

{
  return 0x14000d298;
}



/* 140001100 FUN_140001100 */

CWinApp * FUN_140001100(CWinApp *param_1,uint param_2)

{
  CWinApp::~CWinApp(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    _guard_check_icall();
  }
  return param_1;
}



/* 140001150 FUN_140001150 */

/* WARNING: Function: _alloca_probe replaced with injection: alloca_probe */

void FUN_140001150(CWinApp *param_1)

{
  longlong *plVar1;
  undefined1 auStack_1248 [32];
  INITCOMMONCONTROLSEX local_1228;
  undefined8 local_1220;
  CShellManager *local_1218;
  CDialogEx local_1208 [4592];
  ulonglong local_18;
  undefined8 uStack_10;
  
  uStack_10 = 0x14000115c;
  local_1220 = 0xfffffffffffffffe;
  local_18 = DAT_140013010 ^ (ulonglong)auStack_1248;
  local_1228.dwSize = 8;
  local_1228.dwICC = 0xff;
  InitCommonControlsEx(&local_1228);
  CWinApp::InitInstance(param_1);
  AfxEnableControlContainer((COccManager *)0x0);
  local_1218 = (CShellManager *)operator_new(0x18);
  if (local_1218 == (CShellManager *)0x0) {
    plVar1 = (longlong *)0x0;
  }
  else {
    plVar1 = (longlong *)CShellManager::CShellManager(local_1218);
  }
  CWinApp::SetRegistryKey(param_1,&DAT_14000cf28);
  FUN_140003130(local_1208);
  *(CDialogEx **)(param_1 + 0x40) = local_1208;
  CDialog::DoModal((CDialog *)local_1208);
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 8))(plVar1,1);
  }
  FUN_140001250((CDialog *)local_1208);
  __security_check_cookie(local_18 ^ (ulonglong)auStack_1248);
  return;
}



/* 140001250 FUN_140001250 */

void FUN_140001250(CDialog *param_1)

{
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_1 + 0x11e0));
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_1 + 0x11d8));
  CSliderCtrl::~CSliderCtrl((CSliderCtrl *)(param_1 + 0x10f0));
  CStatic::~CStatic((CStatic *)(param_1 + 0x1008));
  CStatic::~CStatic((CStatic *)(param_1 + 0xf20));
  CStatic::~CStatic((CStatic *)(param_1 + 0xe38));
  CToolTipCtrl::~CToolTipCtrl((CToolTipCtrl *)(param_1 + 0xd10));
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_1 + 0xd08));
  CSliderCtrl::~CSliderCtrl((CSliderCtrl *)(param_1 + 0xc20));
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_1 + 0xc18));
  CSliderCtrl::~CSliderCtrl((CSliderCtrl *)(param_1 + 0xb30));
  CComboBox::~CComboBox((CComboBox *)(param_1 + 0xa48));
  CDialogImpl::~CDialogImpl((CDialogImpl *)(param_1 + 0x158));
  *(undefined ***)(param_1 + 0x140) = CBrush::vftable;
  FUN_1400014a0((CGdiObject *)(param_1 + 0x140));
                    /* WARNING: Could not recover jumptable at 0x000140001320. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CDialog::~CDialog(param_1);
  return;
}



/* 140001330 FUN_140001330 */

void FUN_140001330(CDialog *param_1)

{
  CDialogImpl::~CDialogImpl((CDialogImpl *)(param_1 + 0x158));
  *(undefined ***)(param_1 + 0x140) = CBrush::vftable;
  FUN_1400014a0((CGdiObject *)(param_1 + 0x140));
                    /* WARNING: Could not recover jumptable at 0x000140001364. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CDialog::~CDialog(param_1);
  return;
}



/* 140001370 FUN_140001370 */

undefined8 FUN_140001370(void)

{
  return 5000;
}



/* 140001380 FUN_140001380 */

undefined8 FUN_140001380(void)

{
  return 0;
}



/* 140001390 FUN_140001390 */

uint FUN_140001390(longlong param_1)

{
  return *(uint *)(param_1 + 0x14c) & 0x20;
}



/* 1400013a0 FUN_1400013a0 */

uint FUN_1400013a0(longlong param_1)

{
  return *(uint *)(param_1 + 0x14c) & 0x10;
}



/* 1400013b0 FUN_1400013b0 */

uint FUN_1400013b0(longlong param_1)

{
  return *(uint *)(param_1 + 0x14c) & 8;
}



/* 1400013c0 FUN_1400013c0 */

uint FUN_1400013c0(longlong param_1)

{
  return *(uint *)(param_1 + 0x14c) & 4;
}



/* 1400013d0 FUN_1400013d0 */

uint FUN_1400013d0(longlong param_1)

{
  return *(uint *)(param_1 + 0x14c) & 2;
}



/* 1400013e0 FUN_1400013e0 */

uint FUN_1400013e0(longlong param_1)

{
  return *(uint *)(param_1 + 0x14c) & 1;
}



/* 1400013f0 FUN_1400013f0 */

CGdiObject * FUN_1400013f0(CGdiObject *param_1,uint param_2)

{
  *(undefined ***)param_1 = CBrush::vftable;
  FUN_1400014a0(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    _guard_check_icall();
  }
  return param_1;
}



/* 140001450 FUN_140001450 */

CGdiObject * FUN_140001450(CGdiObject *param_1,uint param_2)

{
  FUN_1400014a0(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    _guard_check_icall();
  }
  return param_1;
}



/* 1400014a0 FUN_1400014a0 */

void FUN_1400014a0(CGdiObject *param_1)

{
  undefined1 auStack_268 [56];
  undefined8 local_230;
  ulonglong local_18;
  
  local_230 = 0xfffffffffffffffe;
  local_18 = DAT_140013010 ^ (ulonglong)auStack_268;
  *(undefined ***)param_1 = CGdiObject::vftable;
  CGdiObject::DeleteObject(param_1);
  __security_check_cookie(local_18 ^ (ulonglong)auStack_268);
  return;
}



/* 140001500 FUN_140001500 */

void FUN_140001500(undefined8 *param_1)

{
  *param_1 = CnComm::vftable;
  if (param_1[2] != -1) {
    FUN_140001b00((longlong)param_1,500);
    if ((*(uint *)(param_1 + 1) & 0x300) != 0) {
      FlushFileBuffers((HANDLE)param_1[2]);
    }
    PurgeComm((HANDLE)param_1[2],0xf);
    CloseHandle((HANDLE)param_1[2]);
    param_1[2] = 0xffffffffffffffff;
  }
  if ((HANDLE)param_1[0x3a] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[0x3a]);
  }
  if ((HANDLE)param_1[0x3e] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[0x3e]);
  }
  if ((HANDLE)param_1[0x42] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[0x42]);
  }
  if ((HANDLE)param_1[0x2e] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[0x2e]);
  }
  if ((HANDLE)param_1[0x31] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[0x31]);
  }
  if ((HANDLE)param_1[0x34] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[0x34]);
  }
  if ((void *)param_1[0x17] != (void *)0x0) {
    operator_delete__((void *)param_1[0x17]);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  FUN_140001d60(param_1 + 0x21);
  FUN_140001d60(param_1 + 0x18);
  return;
}



/* 140001600 FUN_140001600 */

void FUN_140001600(longlong param_1,LPVOID param_2,DWORD param_3)

{
  BOOL BVar1;
  DWORD DVar2;
  undefined1 auStackY_68 [32];
  DWORD local_38;
  DWORD local_34;
  _COMSTAT local_30;
  ulonglong local_20;
  
  local_20 = DAT_140013010 ^ (ulonglong)auStackY_68;
  local_38 = 0;
  if ((*(HANDLE *)(param_1 + 0x10) != (HANDLE)0xffffffffffffffff) && (param_3 != 0)) {
    BVar1 = ClearCommError(*(HANDLE *)(param_1 + 0x10),&local_34,&local_30);
    if ((BVar1 != 0) && (local_34 != 0)) {
      PurgeComm(*(HANDLE *)(param_1 + 0x10),2);
    }
    if ((*(uint *)(param_1 + 8) >> 1 & 1) == 0) {
      ReadFile(*(HANDLE *)(param_1 + 0x10),param_2,param_3,&local_38,(LPOVERLAPPED)0x0);
      *(int *)(param_1 + 0x150) = *(int *)(param_1 + 0x150) + local_38;
    }
    else {
      BVar1 = ReadFile(*(HANDLE *)(param_1 + 0x10),param_2,param_3,&local_38,
                       (LPOVERLAPPED)(param_1 + 0x1b8));
      if ((BVar1 == 0) && (DVar2 = GetLastError(), DVar2 == 0x3e5)) {
        do {
          BVar1 = GetOverlappedResult(*(HANDLE *)(param_1 + 0x10),(LPOVERLAPPED)(param_1 + 0x1b8),
                                      &local_38,1);
        } while (BVar1 == 0);
      }
      *(int *)(param_1 + 0x150) = *(int *)(param_1 + 0x150) + local_38;
    }
  }
  __security_check_cookie(local_20 ^ (ulonglong)auStackY_68);
  return;
}



/* 140001710 FUN_140001710 */

DWORD FUN_140001710(longlong param_1,LPCVOID param_2,DWORD param_3)

{
  BOOL BVar1;
  DWORD DVar2;
  DWORD aDStackX_8 [2];
  DWORD aDStackX_20 [2];
  
  if ((*(HANDLE *)(param_1 + 0x10) == (HANDLE)0xffffffffffffffff) || (param_3 == 0)) {
    return 0;
  }
  aDStackX_8[0] = 0;
  BVar1 = ClearCommError(*(HANDLE *)(param_1 + 0x10),aDStackX_20,(LPCOMSTAT)0x0);
  if ((BVar1 != 0) && (aDStackX_20[0] != 0)) {
    PurgeComm(*(HANDLE *)(param_1 + 0x10),1);
  }
  if ((*(uint *)(param_1 + 8) >> 1 & 1) == 0) {
    WriteFile(*(HANDLE *)(param_1 + 0x10),param_2,param_3,aDStackX_8,(LPOVERLAPPED)0x0);
    *(int *)(param_1 + 0x154) = *(int *)(param_1 + 0x154) + aDStackX_8[0];
    return aDStackX_8[0];
  }
  BVar1 = WriteFile(*(HANDLE *)(param_1 + 0x10),param_2,param_3,aDStackX_8,
                    (LPOVERLAPPED)(param_1 + 0x1d8));
  if ((BVar1 == 0) && (DVar2 = GetLastError(), DVar2 != 0x3e5)) {
    return 0;
  }
  *(int *)(param_1 + 0x154) = *(int *)(param_1 + 0x154) + param_3;
  return aDStackX_8[0];
}



/* 140001738 FUN_140001738 */

DWORD FUN_140001738(HANDLE param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  longlong unaff_RBX;
  LPCVOID unaff_RBP;
  DWORD unaff_ESI;
  DWORD DStack0000000000000050;
  DWORD in_stack_00000068;
  
  DStack0000000000000050 = 0;
  BVar1 = ClearCommError(param_1,&stack0x00000068,(LPCOMSTAT)0x0);
  if ((BVar1 != 0) && (in_stack_00000068 != 0)) {
    PurgeComm(*(HANDLE *)(unaff_RBX + 0x10),1);
  }
  if ((*(uint *)(unaff_RBX + 8) >> 1 & 1) == 0) {
    WriteFile(*(HANDLE *)(unaff_RBX + 0x10),unaff_RBP,unaff_ESI,&stack0x00000050,(LPOVERLAPPED)0x0);
    *(int *)(unaff_RBX + 0x154) = *(int *)(unaff_RBX + 0x154) + DStack0000000000000050;
    return DStack0000000000000050;
  }
  BVar1 = WriteFile(*(HANDLE *)(unaff_RBX + 0x10),unaff_RBP,unaff_ESI,&stack0x00000050,
                    (LPOVERLAPPED)(unaff_RBX + 0x1d8));
  if ((BVar1 == 0) && (DVar2 = GetLastError(), DVar2 != 0x3e5)) {
    return 0;
  }
  *(int *)(unaff_RBX + 0x154) = *(int *)(unaff_RBX + 0x154) + unaff_ESI;
  return DStack0000000000000050;
}



/* 1400017bc FUN_1400017bc */

int FUN_1400017bc(HANDLE param_1,LPCVOID param_2,DWORD param_3,LPDWORD param_4)

{
  longlong unaff_RBX;
  LPOVERLAPPED unaff_RDI;
  int in_stack_00000050;
  
  WriteFile(param_1,param_2,param_3,param_4,unaff_RDI);
  *(int *)(unaff_RBX + 0x154) = *(int *)(unaff_RBX + 0x154) + in_stack_00000050;
  return in_stack_00000050;
}



/* 1400017e0 FUN_1400017e0 */

undefined8 FUN_1400017e0(void)

{
  return 0;
}



/* 1400017f0 FUN_1400017f0 */

DWORD FUN_1400017f0(longlong param_1,LPCVOID param_2,uint param_3)

{
  int *piVar1;
  longlong lVar2;
  uint uVar3;
  DWORD DVar4;
  undefined8 *puVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  
  uVar8 = (ulonglong)param_3;
  if ((param_3 == 0) || ((*(byte *)(param_1 + 8) & 8) == 0)) {
    DVar4 = FUN_140001710(param_1,param_2,param_3);
  }
  else {
    if (param_1 != -0x108) {
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x128));
    }
    lVar2 = *(longlong *)(param_1 + 0x118);
    uVar6 = 0;
    if (lVar2 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(int *)(lVar2 + 8) - *(int *)(lVar2 + 4);
    }
    uVar7 = param_3;
    if (uVar3 != 0) {
      uVar6 = uVar3;
      if (param_3 < uVar3) {
        uVar6 = param_3;
      }
      memcpy((void *)(lVar2 + 0x18 + (ulonglong)*(uint *)(lVar2 + 4)),param_2,(ulonglong)uVar6);
      uVar7 = param_3 - uVar6;
      piVar1 = (int *)(*(longlong *)(param_1 + 0x118) + 4);
      *piVar1 = *piVar1 + uVar6;
    }
    if (uVar7 != 0) {
      if (param_3 < *(uint *)(param_1 + 0x124)) {
        uVar8 = (ulonglong)*(uint *)(param_1 + 0x124);
      }
      puVar5 = (undefined8 *)operator_new__(uVar8 + 0x1c);
      if (puVar5 != (undefined8 *)0x0) {
        *puVar5 = 0;
        puVar5[1] = 0;
        puVar5[2] = 0;
        puVar5[3] = 0;
        *(int *)(puVar5 + 1) = (int)uVar8;
        if (*(longlong *)(param_1 + 0x118) == 0) {
          *(undefined8 **)(param_1 + 0x110) = puVar5;
        }
        else {
          *(undefined8 **)(*(longlong *)(param_1 + 0x118) + 0x10) = puVar5;
        }
        *(undefined8 **)(param_1 + 0x118) = puVar5;
      }
      memcpy(puVar5 + 3,(void *)((ulonglong)uVar6 + (longlong)param_2),(ulonglong)uVar7);
      piVar1 = (int *)(*(longlong *)(param_1 + 0x118) + 4);
      *piVar1 = *piVar1 + uVar7;
    }
    *(int *)(param_1 + 0x120) = *(int *)(param_1 + 0x120) + param_3;
    if (((*(uint *)(param_1 + 8) & 0x20) == 0) && ((*(uint *)(param_1 + 8) >> 1 & 1) != 0)) {
      SetCommMask(*(HANDLE *)(param_1 + 0x10),*(DWORD *)(param_1 + 0x15c));
    }
    else {
      SetEvent(*(HANDLE *)(param_1 + 0x170));
    }
    if (param_1 != -0x108) {
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x128));
    }
    DVar4 = 0;
  }
  return DVar4;
}



/* 140001970 FUN_140001970 */

ulonglong FUN_140001970(void *param_1,uint param_2)

{
  BOOL BVar1;
  HANDLE in_RAX;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  undefined4 extraout_var_01;
  uint uVar2;
  uint _InitFlag;
  uint auStackX_8 [2];
  uint local_res10 [2];
  uint auStackX_18 [2];
  
  if (((*(longlong *)((longlong)param_1 + 0x160) != 0) ||
      (*(longlong *)((longlong)param_1 + 0x178) != 0)) ||
     (*(longlong *)((longlong)param_1 + 400) != 0)) goto LAB_140001ad5;
  *(undefined1 *)((longlong)param_1 + 0x158) = 1;
  uVar2 = *(uint *)((longlong)param_1 + 8);
  _InitFlag = uVar2 >> 4 & 4;
  local_res10[0] = param_2;
  if ((uVar2 & 1) != 0) {
    in_RAX = (HANDLE)_beginthreadex((void *)0x0,0,FUN_140002f70,param_1,_InitFlag,local_res10);
    uVar2 = *(uint *)((longlong)param_1 + 8);
    *(HANDLE *)((longlong)param_1 + 0x160) = in_RAX;
  }
  if ((uVar2 & 0x10) != 0) {
    in_RAX = (HANDLE)_beginthreadex((void *)0x0,0,FUN_140002fc0,param_1,_InitFlag,auStackX_8);
    uVar2 = *(uint *)((longlong)param_1 + 8);
    *(HANDLE *)((longlong)param_1 + 0x178) = in_RAX;
  }
  if ((uVar2 & 0x20) != 0) {
    in_RAX = (HANDLE)_beginthreadex((void *)0x0,0,FUN_140002ff0,param_1,_InitFlag,auStackX_18);
    uVar2 = *(uint *)((longlong)param_1 + 8);
    *(HANDLE *)((longlong)param_1 + 400) = in_RAX;
  }
  if ((uVar2 & 1) == 0) {
LAB_140001a87:
    if ((uVar2 & 0x10) != 0) {
      in_RAX = (HANDLE)(ulonglong)auStackX_8[0];
      *(uint *)((longlong)param_1 + 0x180) = auStackX_8[0];
      if (auStackX_8[0] == 0) goto LAB_140001ac8;
      if ((char)uVar2 < '\0') {
        BVar1 = SetThreadPriority(*(HANDLE *)((longlong)param_1 + 0x178),1);
        in_RAX = (HANDLE)CONCAT44(extraout_var_00,BVar1);
        uVar2 = *(uint *)((longlong)param_1 + 8);
      }
    }
    if ((uVar2 & 0x20) == 0) {
LAB_140001af3:
      return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
    }
    in_RAX = (HANDLE)(ulonglong)auStackX_18[0];
    *(uint *)((longlong)param_1 + 0x198) = auStackX_18[0];
    if (auStackX_18[0] != 0) {
      if ((char)uVar2 < '\0') {
        BVar1 = SetThreadPriority(*(HANDLE *)((longlong)param_1 + 400),1);
        in_RAX = (HANDLE)CONCAT44(extraout_var_01,BVar1);
      }
      goto LAB_140001af3;
    }
  }
  else {
    *(uint *)((longlong)param_1 + 0x168) = local_res10[0];
    in_RAX = *(HANDLE *)((longlong)param_1 + 0x160);
    if (in_RAX != (HANDLE)0x0) {
      if ((char)uVar2 < '\0') {
        BVar1 = SetThreadPriority(in_RAX,1);
        in_RAX = (HANDLE)CONCAT44(extraout_var,BVar1);
        uVar2 = *(uint *)((longlong)param_1 + 8);
      }
      goto LAB_140001a87;
    }
  }
LAB_140001ac8:
  in_RAX = (HANDLE)FUN_140001b00((longlong)param_1,500);
LAB_140001ad5:
  return (ulonglong)in_RAX & 0xffffffffffffff00;
}



/* 1400019a6 FUN_1400019a6 */

ulonglong FUN_1400019a6(longlong param_1)

{
  BOOL BVar1;
  HANDLE in_RAX;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  ulonglong uVar2;
  undefined4 extraout_var_01;
  uint uVar3;
  void *unaff_RBX;
  uint _InitFlag;
  uint in_stack_00000040;
  uint in_stack_00000048;
  uint in_stack_00000050;
  
  *(undefined1 *)(param_1 + 0x158) = 1;
  uVar3 = *(uint *)(param_1 + 8);
  _InitFlag = uVar3 >> 4 & 4;
  if ((uVar3 & 1) != 0) {
    in_RAX = (HANDLE)_beginthreadex((void *)0x0,0,FUN_140002f70,unaff_RBX,_InitFlag,&stack0x00000048
                                   );
    uVar3 = *(uint *)((longlong)unaff_RBX + 8);
    *(HANDLE *)((longlong)unaff_RBX + 0x160) = in_RAX;
  }
  if ((uVar3 & 0x10) != 0) {
    in_RAX = (HANDLE)_beginthreadex((void *)0x0,0,FUN_140002fc0,unaff_RBX,_InitFlag,&stack0x00000040
                                   );
    uVar3 = *(uint *)((longlong)unaff_RBX + 8);
    *(HANDLE *)((longlong)unaff_RBX + 0x178) = in_RAX;
  }
  if ((uVar3 & 0x20) != 0) {
    in_RAX = (HANDLE)_beginthreadex((void *)0x0,0,FUN_140002ff0,unaff_RBX,_InitFlag,&stack0x00000050
                                   );
    uVar3 = *(uint *)((longlong)unaff_RBX + 8);
    *(HANDLE *)((longlong)unaff_RBX + 400) = in_RAX;
  }
  if ((uVar3 & 1) != 0) {
    *(uint *)((longlong)unaff_RBX + 0x168) = in_stack_00000048;
    in_RAX = *(HANDLE *)((longlong)unaff_RBX + 0x160);
    if (in_RAX == (HANDLE)0x0) goto LAB_140001ac8;
    if ((char)uVar3 < '\0') {
      BVar1 = SetThreadPriority(in_RAX,1);
      in_RAX = (HANDLE)CONCAT44(extraout_var,BVar1);
      uVar3 = *(uint *)((longlong)unaff_RBX + 8);
    }
  }
  if ((uVar3 & 0x10) != 0) {
    in_RAX = (HANDLE)(ulonglong)in_stack_00000040;
    *(uint *)((longlong)unaff_RBX + 0x180) = in_stack_00000040;
    if (in_stack_00000040 == 0) goto LAB_140001ac8;
    if ((char)uVar3 < '\0') {
      BVar1 = SetThreadPriority(*(HANDLE *)((longlong)unaff_RBX + 0x178),1);
      in_RAX = (HANDLE)CONCAT44(extraout_var_00,BVar1);
      uVar3 = *(uint *)((longlong)unaff_RBX + 8);
    }
  }
  if ((uVar3 & 0x20) != 0) {
    in_RAX = (HANDLE)(ulonglong)in_stack_00000050;
    *(uint *)((longlong)unaff_RBX + 0x198) = in_stack_00000050;
    if (in_stack_00000050 == 0) {
LAB_140001ac8:
      uVar2 = FUN_140001b00((longlong)unaff_RBX,500);
      return uVar2 & 0xffffffffffffff00;
    }
    if ((char)uVar3 < '\0') {
      BVar1 = SetThreadPriority(*(HANDLE *)((longlong)unaff_RBX + 400),1);
      in_RAX = (HANDLE)CONCAT44(extraout_var_01,BVar1);
    }
  }
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
}



/* 140001a5c FUN_140001a5c */

ulonglong FUN_140001a5c(char param_1,uint param_2)

{
  BOOL BVar1;
  undefined4 extraout_var;
  HANDLE hThread;
  undefined4 extraout_var_00;
  ulonglong uVar2;
  undefined4 extraout_var_01;
  longlong unaff_RBX;
  uint in_stack_00000040;
  undefined4 in_stack_00000048;
  uint in_stack_00000050;
  
  *(undefined4 *)(unaff_RBX + 0x168) = in_stack_00000048;
  hThread = *(HANDLE *)(unaff_RBX + 0x160);
  if (hThread != (HANDLE)0x0) {
    if (param_1 < '\0') {
      BVar1 = SetThreadPriority(hThread,1);
      hThread = (HANDLE)CONCAT44(extraout_var,BVar1);
      param_2 = *(uint *)(unaff_RBX + 8);
    }
    if ((param_2 & 0x10) != 0) {
      hThread = (HANDLE)(ulonglong)in_stack_00000040;
      *(uint *)(unaff_RBX + 0x180) = in_stack_00000040;
      if (in_stack_00000040 == 0) goto LAB_140001ac8;
      if ((char)param_2 < '\0') {
        BVar1 = SetThreadPriority(*(HANDLE *)(unaff_RBX + 0x178),1);
        hThread = (HANDLE)CONCAT44(extraout_var_00,BVar1);
        param_2 = *(uint *)(unaff_RBX + 8);
      }
    }
    if ((param_2 & 0x20) != 0) {
      hThread = (HANDLE)(ulonglong)in_stack_00000050;
      *(uint *)(unaff_RBX + 0x198) = in_stack_00000050;
      if (in_stack_00000050 == 0) goto LAB_140001ac8;
      if ((char)param_2 < '\0') {
        BVar1 = SetThreadPriority(*(HANDLE *)(unaff_RBX + 400),1);
        hThread = (HANDLE)CONCAT44(extraout_var_01,BVar1);
      }
    }
    return CONCAT71((int7)((ulonglong)hThread >> 8),1);
  }
LAB_140001ac8:
  uVar2 = FUN_140001b00(unaff_RBX,500);
  return uVar2 & 0xffffffffffffff00;
}



/* 140001b00 FUN_140001b00 */

ulonglong FUN_140001b00(longlong param_1,DWORD param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  ulonglong in_RAX;
  ulonglong uVar3;
  ulonglong extraout_RAX;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  undefined4 extraout_var_01;
  undefined4 extraout_var_02;
  undefined4 extraout_var_03;
  undefined4 extraout_var_04;
  undefined4 extraout_var_05;
  uint uVar4;
  
  if (((*(longlong *)(param_1 + 0x160) == 0) && (*(longlong *)(param_1 + 0x178) == 0)) &&
     (*(longlong *)(param_1 + 400) == 0)) {
LAB_140001c6c:
    return in_RAX & 0xffffffffffffff00;
  }
  uVar4 = *(uint *)(param_1 + 8);
  uVar3 = (ulonglong)(uVar4 & 0x208);
  if (((uVar4 & 0x208) == 0x208) && (*(int *)(param_1 + 0x120) != 0)) {
    do {
      Sleep(0x32);
    } while (*(int *)(param_1 + 0x120) != 0);
    uVar4 = *(uint *)(param_1 + 8);
    uVar3 = extraout_RAX;
  }
  *(undefined1 *)(param_1 + 0x158) = 0;
  if ((uVar4 >> 1 & 1) != 0) {
    BVar1 = SetCommMask(*(HANDLE *)(param_1 + 0x10),0);
    uVar3 = CONCAT44(extraout_var,BVar1);
  }
  if (*(longlong *)(param_1 + 0x160) != 0) {
    SetEvent(*(HANDLE *)(param_1 + 0x170));
    DVar2 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x160),param_2);
    if (DVar2 != 0) {
      BVar1 = TerminateThread(*(HANDLE *)(param_1 + 0x160),0);
      in_RAX = CONCAT44(extraout_var_00,BVar1);
      if (BVar1 == 0) goto LAB_140001c6c;
    }
    BVar1 = CloseHandle(*(HANDLE *)(param_1 + 0x160));
    uVar3 = CONCAT44(extraout_var_01,BVar1);
    *(undefined8 *)(param_1 + 0x160) = 0;
  }
  if (*(longlong *)(param_1 + 0x178) != 0) {
    SetEvent(*(HANDLE *)(param_1 + 0x188));
    DVar2 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x178),param_2);
    if (DVar2 != 0) {
      BVar1 = TerminateThread(*(HANDLE *)(param_1 + 0x178),0);
      in_RAX = CONCAT44(extraout_var_02,BVar1);
      if (BVar1 == 0) goto LAB_140001c6c;
    }
    BVar1 = CloseHandle(*(HANDLE *)(param_1 + 0x178));
    uVar3 = CONCAT44(extraout_var_03,BVar1);
    *(undefined8 *)(param_1 + 0x178) = 0;
  }
  if (*(longlong *)(param_1 + 400) != 0) {
    SetEvent(*(HANDLE *)(param_1 + 0x1a0));
    DVar2 = WaitForSingleObject(*(HANDLE *)(param_1 + 400),param_2);
    if (DVar2 != 0) {
      BVar1 = TerminateThread(*(HANDLE *)(param_1 + 400),0);
      in_RAX = CONCAT44(extraout_var_04,BVar1);
      if (BVar1 == 0) goto LAB_140001c6c;
    }
    BVar1 = CloseHandle(*(HANDLE *)(param_1 + 400));
    uVar3 = CONCAT44(extraout_var_05,BVar1);
    *(undefined8 *)(param_1 + 400) = 0;
  }
  return CONCAT71((int7)(uVar3 >> 8),1);
}



/* 140001ca0 FUN_140001ca0 */

void FUN_140001ca0(longlong param_1,DWORD param_2)

{
  if (*(longlong *)(param_1 + 0x10) != -1) {
    FUN_140001b00(param_1,param_2);
    if ((*(uint *)(param_1 + 8) & 0x300) != 0) {
      FlushFileBuffers(*(HANDLE *)(param_1 + 0x10));
    }
    PurgeComm(*(HANDLE *)(param_1 + 0x10),0xf);
    CloseHandle(*(HANDLE *)(param_1 + 0x10));
    *(undefined8 *)(param_1 + 0x10) = 0xffffffffffffffff;
  }
  return;
}



/* 140001cf0 FUN_140001cf0 */

void FUN_140001cf0(longlong param_1)

{
  undefined1 auStack_48 [32];
  DWORD local_28 [2];
  _COMSTAT local_20;
  ulonglong local_10;
  
  local_10 = DAT_140013010 ^ (ulonglong)auStack_48;
  if (*(HANDLE *)(param_1 + 0x10) != (HANDLE)0xffffffffffffffff) {
    ClearCommError(*(HANDLE *)(param_1 + 0x10),local_28,&local_20);
  }
  __security_check_cookie(local_10 ^ (ulonglong)auStack_48);
  return;
}



/* 140001d40 FUN_140001d40 */

void FUN_140001d40(longlong *param_1)

{
  if (*param_1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x000140001d4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    LeaveCriticalSection((LPCRITICAL_SECTION)(*param_1 + 0x20));
    return;
  }
  return;
}



/* 140001d60 FUN_140001d60 */

void FUN_140001d60(undefined8 *param_1)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  
  puVar2 = (undefined8 *)param_1[1];
  *param_1 = CnComm::BlockBuffer::vftable;
  if (puVar2 != (undefined8 *)0x0) {
    if ((puVar2 == (undefined8 *)param_1[2]) &&
       (uVar1 = *(uint *)(puVar2 + 1), (uint)(*(int *)((longlong)param_1 + 0x1c) << 2) < uVar1)) {
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
      *(uint *)(param_1[1] + 8) = uVar1;
      goto LAB_140001de7;
    }
    while (puVar2 != (undefined8 *)0x0) {
      param_1[1] = puVar2;
      puVar3 = (undefined8 *)puVar2[2];
      operator_delete(puVar2);
      puVar2 = puVar3;
    }
  }
  param_1[2] = 0;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 3) = 0;
LAB_140001de7:
                    /* WARNING: Could not recover jumptable at 0x000140001df5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



/* 140001e00 FUN_140001e00 */

undefined4 FUN_140001e00(longlong param_1)

{
  undefined4 uVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  if (param_1 == 0) {
    lpCriticalSection = (LPCRITICAL_SECTION)0x20;
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x20);
    EnterCriticalSection(lpCriticalSection);
  }
  uVar1 = *(undefined4 *)(param_1 + 0x18);
  LeaveCriticalSection(lpCriticalSection);
  return uVar1;
}



/* 140001e40 FUN_140001e40 */

ulonglong FUN_140001e40(longlong param_1,longlong param_2,uint param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  ulonglong uVar7;
  
  puVar6 = *(uint **)(param_1 + 8);
  uVar7 = 0;
  if (param_3 == 0) {
    return 0;
  }
  do {
    if (puVar6 == (uint *)0x0) {
      return uVar7;
    }
    uVar4 = puVar6[1];
    uVar5 = *puVar6;
    uVar3 = param_3 - (int)uVar7;
    uVar2 = uVar4 - uVar5;
    if (uVar3 <= uVar4 - uVar5) {
      uVar2 = uVar3;
    }
    if (param_2 != 0) {
      memcpy((void *)(uVar7 + param_2),(void *)((ulonglong)uVar5 + 0x18 + (longlong)puVar6),
             (ulonglong)uVar2);
      uVar4 = puVar6[1];
      uVar5 = *puVar6;
    }
    puVar1 = *(uint **)(puVar6 + 4);
    uVar3 = (int)uVar7 + uVar2;
    uVar7 = (ulonglong)uVar3;
    if (uVar2 == uVar4 - uVar5) {
      if ((puVar1 == (uint *)0x0) && (puVar6[2] <= (uint)(*(int *)(param_1 + 0x1c) << 2))) {
        puVar6[0] = 0;
        puVar6[1] = 0;
      }
      else {
        operator_delete__(puVar6);
        *(uint **)(param_1 + 8) = puVar1;
        if (puVar1 == (uint *)0x0) {
          *(undefined8 *)(param_1 + 0x10) = 0;
        }
      }
    }
    else {
      *puVar6 = uVar2 + uVar5;
    }
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) - uVar2;
    puVar6 = puVar1;
  } while (uVar3 < param_3);
  return uVar7;
}



/* 140001e6e FUN_140001e6e */

uint FUN_140001e6e(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *unaff_RBX;
  longlong unaff_RSI;
  longlong unaff_R12;
  undefined8 unaff_R13;
  uint unaff_R14D;
  uint unaff_R15D;
  
  do {
    if (unaff_RBX == (uint *)0x0) {
      return unaff_R14D;
    }
    uVar3 = unaff_RBX[1];
    uVar4 = *unaff_RBX;
    uVar2 = uVar3 - uVar4;
    if (unaff_R15D - unaff_R14D <= uVar3 - uVar4) {
      uVar2 = unaff_R15D - unaff_R14D;
    }
    if (unaff_R12 != 0) {
      memcpy((void *)((ulonglong)unaff_R14D + unaff_R12),
             (void *)((ulonglong)uVar4 + 0x18 + (longlong)unaff_RBX),(ulonglong)uVar2);
      uVar3 = unaff_RBX[1];
      uVar4 = *unaff_RBX;
    }
    puVar1 = *(uint **)(unaff_RBX + 4);
    unaff_R14D = unaff_R14D + uVar2;
    if (uVar2 == uVar3 - uVar4) {
      if ((puVar1 == (uint *)0x0) && (unaff_RBX[2] <= (uint)(*(int *)(unaff_RSI + 0x1c) << 2))) {
        *(undefined8 *)unaff_RBX = unaff_R13;
      }
      else {
        operator_delete__(unaff_RBX);
        *(uint **)(unaff_RSI + 8) = puVar1;
        if (puVar1 == (uint *)0x0) {
          *(undefined8 *)(unaff_RSI + 0x10) = unaff_R13;
        }
      }
    }
    else {
      *unaff_RBX = uVar2 + uVar4;
    }
    *(int *)(unaff_RSI + 0x18) = *(int *)(unaff_RSI + 0x18) - uVar2;
    unaff_RBX = puVar1;
  } while (unaff_R14D < unaff_R15D);
  return unaff_R14D;
}



/* 140001f2a FUN_140001f2a */

undefined4 FUN_140001f2a(void)

{
  undefined4 unaff_R13D;
  
  return unaff_R13D;
}



/* 140001f40 FUN_140001f40 */

void FUN_140001f40(longlong param_1,uint param_2)

{
  undefined8 *puVar1;
  
  if (param_2 < *(uint *)(param_1 + 0x1c)) {
    param_2 = *(uint *)(param_1 + 0x1c);
  }
  puVar1 = (undefined8 *)operator_new__((ulonglong)param_2 + 0x1c);
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    *(uint *)(puVar1 + 1) = param_2;
    if (*(longlong *)(param_1 + 0x10) != 0) {
      *(undefined8 **)(*(longlong *)(param_1 + 0x10) + 0x10) = puVar1;
      *(undefined8 **)(param_1 + 0x10) = puVar1;
      return;
    }
    *(undefined8 **)(param_1 + 8) = puVar1;
    *(undefined8 **)(param_1 + 0x10) = puVar1;
  }
  return;
}



/* 140001fb0 FUN_140001fb0 */

void FUN_140001fb0(longlong param_1)

{
  HANDLE pvVar1;
  
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x60));
  *(undefined8 *)(param_1 + 0x1c) = 0;
  *(undefined8 *)(param_1 + 0x24) = 0;
  *(undefined8 *)(param_1 + 0x2c) = 0;
  *(undefined8 *)(param_1 + 0x34) = 0;
  *(undefined8 *)(param_1 + 0x3c) = 0;
  *(undefined8 *)(param_1 + 0x44) = 0;
  *(undefined8 *)(param_1 + 0x4c) = 0;
  *(undefined8 *)(param_1 + 0x54) = 0;
  *(undefined8 *)(param_1 + 0x8c) = 0;
  *(undefined8 *)(param_1 + 0x94) = 0;
  *(undefined8 *)(param_1 + 0x9c) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0x1c;
  *(undefined8 *)(param_1 + 0x10) = 0xffffffffffffffff;
  *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  *(undefined8 *)(param_1 + 0x150) = 0;
  *(undefined4 *)(param_1 + 0x15c) = 0x1fd;
  *(undefined8 *)(param_1 + 0x160) = 0;
  *(undefined8 *)(param_1 + 0x178) = 0;
  *(undefined8 *)(param_1 + 400) = 0;
  *(undefined4 *)(param_1 + 0x168) = 0;
  *(undefined4 *)(param_1 + 0x180) = 0;
  *(undefined4 *)(param_1 + 0x198) = 0;
  *(undefined8 *)(param_1 + 0x1a8) = 0;
  *(undefined8 *)(param_1 + 0x1b0) = 0;
  *(undefined8 *)(param_1 + 0xb8) = 0;
  memset((void *)(param_1 + 0x1b8),0,0x60);
  pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
  *(HANDLE *)(param_1 + 0x1d0) = pvVar1;
  pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
  *(HANDLE *)(param_1 + 0x1f0) = pvVar1;
  pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
  *(HANDLE *)(param_1 + 0x210) = pvVar1;
  pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
  *(HANDLE *)(param_1 + 0x170) = pvVar1;
  pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
  *(HANDLE *)(param_1 + 0x188) = pvVar1;
  pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
  *(HANDLE *)(param_1 + 0x1a0) = pvVar1;
  return;
}



/* 140002110 FUN_140002110 */

void FUN_140002110(longlong param_1)

{
  if (*(HANDLE *)(param_1 + 0x1d0) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_1 + 0x1d0));
  }
  if (*(HANDLE *)(param_1 + 0x1f0) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_1 + 0x1f0));
  }
  if (*(HANDLE *)(param_1 + 0x210) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_1 + 0x210));
  }
  if (*(HANDLE *)(param_1 + 0x170) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_1 + 0x170));
  }
  if (*(HANDLE *)(param_1 + 0x188) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_1 + 0x188));
  }
  if (*(HANDLE *)(param_1 + 0x1a0) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_1 + 0x1a0));
  }
  if (*(void **)(param_1 + 0xb8) != (void *)0x0) {
    operator_delete__(*(void **)(param_1 + 0xb8));
  }
                    /* WARNING: Could not recover jumptable at 0x0001400021a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x60));
  return;
}



/* 1400021b0 FUN_1400021b0 */

bool FUN_1400021b0(longlong *param_1)

{
  HANDLE pvVar1;
  
  if (param_1[2] != -1) {
    (**(code **)(*param_1 + 8))(param_1,500);
  }
  pvVar1 = CreateFileA((LPCSTR)((longlong)param_1 + 0x1c),0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,
                       (*(uint *)(param_1 + 1) >> 1 & 1) << 0x1e | 0x80,(HANDLE)0x0);
  param_1[2] = (longlong)pvVar1;
  return pvVar1 != (HANDLE)0xffffffffffffffff;
}



/* 140002220 FUN_140002220 */

ulonglong FUN_140002220(longlong param_1)

{
  BOOL BVar1;
  uint uVar2;
  undefined4 uVar3;
  ulonglong in_RAX;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  undefined4 extraout_var_01;
  undefined4 extraout_var_02;
  
  if (*(HANDLE *)(param_1 + 0x10) != (HANDLE)0xffffffffffffffff) {
    BVar1 = SetupComm(*(HANDLE *)(param_1 + 0x10),0x1000,0x1000);
    in_RAX = CONCAT44(extraout_var,BVar1);
    if (BVar1 != 0) {
      BVar1 = GetCommTimeouts(*(HANDLE *)(param_1 + 0x10),(LPCOMMTIMEOUTS)(param_1 + 0xa4));
      in_RAX = CONCAT44(extraout_var_00,BVar1);
      if (BVar1 != 0) {
        uVar2 = *(uint *)(param_1 + 8) >> 1;
        uVar3 = 0xfa;
        *(undefined8 *)(param_1 + 0xa4) = 100;
        if ((uVar2 & 1) != 0) {
          uVar3 = 500;
        }
        *(undefined4 *)(param_1 + 0xac) = uVar3;
        *(uint *)(param_1 + 0xb0) = uVar2 & 1;
        uVar3 = 0xfa;
        if ((uVar2 & 1) != 0) {
          uVar3 = 10000;
        }
        *(undefined4 *)(param_1 + 0xb4) = uVar3;
        BVar1 = SetCommTimeouts(*(HANDLE *)(param_1 + 0x10),(LPCOMMTIMEOUTS)(param_1 + 0xa4));
        in_RAX = CONCAT44(extraout_var_01,BVar1);
        if (BVar1 != 0) {
          BVar1 = PurgeComm(*(HANDLE *)(param_1 + 0x10),0xf);
          in_RAX = CONCAT44(extraout_var_02,BVar1);
          if (BVar1 != 0) {
            return CONCAT71((int7)(in_RAX >> 8),1);
          }
        }
      }
    }
  }
  return in_RAX & 0xffffffffffffff00;
}



/* 140002300 FUN_140002300 */

uint FUN_140002300(longlong param_1,uint param_2)

{
  int *piVar1;
  longlong lVar2;
  uint uVar3;
  LPVOID pvVar4;
  longlong lVar5;
  
  lVar2 = param_1 + 0xc0;
  if (lVar2 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xe0));
  }
  if (param_2 != 0) {
    lVar5 = *(longlong *)(param_1 + 0xd0);
    if ((lVar5 == 0) || (*(int *)(lVar5 + 8) - *(uint *)(lVar5 + 4) <= param_2)) {
      lVar5 = FUN_140001f40(lVar2,param_2);
      pvVar4 = (LPVOID)(lVar5 + 0x18);
    }
    else {
      pvVar4 = (LPVOID)(lVar5 + 0x18 + (ulonglong)*(uint *)(lVar5 + 4));
    }
    uVar3 = FUN_140001600(param_1,pvVar4,param_2);
    if (uVar3 <= *(uint *)(*(longlong *)(param_1 + 0xd0) + 8)) {
      piVar1 = (int *)(*(longlong *)(param_1 + 0xd0) + 4);
      *piVar1 = *piVar1 + uVar3;
      *(int *)(param_1 + 0xd8) = *(int *)(param_1 + 0xd8) + uVar3;
      goto LAB_140002393;
    }
  }
  uVar3 = 0;
LAB_140002393:
  if (lVar2 != 0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xe0));
  }
  return uVar3;
}



/* 1400023c0 FUN_1400023c0 */

void FUN_1400023c0(longlong param_1)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  DWORD DVar5;
  uint uVar6;
  LPCVOID pvVar7;
  int *piVar8;
  uint *puVar9;
  uint uVar10;
  LPCVOID pvVar12;
  ulonglong uVar13;
  undefined1 auStack_458 [32];
  undefined1 auStack_438 [1024];
  ulonglong local_38;
  ulonglong uVar11;
  
  local_38 = DAT_140013010 ^ (ulonglong)auStack_458;
  if ((*(uint *)(param_1 + 8) >> 1 & 1) == 0) {
    uVar13 = 0;
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x128));
    puVar9 = *(uint **)(param_1 + 0x110);
    uVar11 = uVar13;
    do {
      uVar10 = (uint)uVar11;
      if (puVar9 == (uint *)0x0) break;
      uVar3 = puVar9[1] - *puVar9;
      if (0x400 - uVar10 <= uVar3) {
        uVar3 = 0x400 - uVar10;
      }
      memcpy(auStack_438 + uVar11,(void *)((ulonglong)*puVar9 + 0x18 + (longlong)puVar9),
             (ulonglong)uVar3);
      uVar10 = uVar10 + uVar3;
      uVar11 = (ulonglong)uVar10;
      puVar2 = *(uint **)(puVar9 + 4);
      if (uVar3 == puVar9[1] - *puVar9) {
        if ((puVar2 == (uint *)0x0) && (puVar9[2] <= (uint)(*(int *)(param_1 + 0x124) << 2))) {
          puVar9[0] = 0;
          puVar9[1] = 0;
        }
        else {
          operator_delete__(puVar9);
          *(uint **)(param_1 + 0x110) = puVar2;
          if (puVar2 == (uint *)0x0) {
            *(undefined8 *)(param_1 + 0x118) = 0;
          }
        }
      }
      else {
        *puVar9 = uVar3 + *puVar9;
      }
      *(int *)(param_1 + 0x120) = *(int *)(param_1 + 0x120) - uVar3;
      puVar9 = puVar2;
    } while (uVar10 < 0x400);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x128));
    if (uVar10 != 0) {
      do {
        DVar5 = FUN_140001710(param_1,auStack_438 + uVar13,uVar10 - (int)uVar13);
        uVar3 = (int)uVar13 + DVar5;
        uVar13 = (ulonglong)uVar3;
      } while (uVar3 < uVar10);
    }
  }
  else {
    if (param_1 != -0x108) {
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x128));
    }
    pvVar12 = (LPCVOID)0x0;
    uVar10 = 0;
    if (*(int *)(param_1 + 0x120) != 0) {
      puVar9 = *(uint **)(param_1 + 0x110);
      pvVar7 = pvVar12;
      if (puVar9 != (uint *)0x0) {
        uVar3 = puVar9[1] - *puVar9;
        uVar10 = 0x400;
        if (uVar3 < 0x400) {
          uVar10 = uVar3;
        }
        pvVar7 = (LPCVOID)((longlong)puVar9 + (ulonglong)*puVar9 + 0x18);
      }
      FUN_140001710(param_1,pvVar7,uVar10);
      piVar8 = *(int **)(param_1 + 0x110);
      if (uVar10 != 0) {
        do {
          if (piVar8 == (int *)0x0) break;
          uVar4 = uVar10 - (int)pvVar12;
          piVar1 = *(int **)(piVar8 + 4);
          uVar6 = piVar8[1] - *piVar8;
          uVar3 = uVar6;
          if (uVar4 <= uVar6) {
            uVar3 = uVar4;
          }
          uVar4 = (int)pvVar12 + uVar3;
          pvVar12 = (LPCVOID)(ulonglong)uVar4;
          if (uVar3 == uVar6) {
            if ((piVar1 == (int *)0x0) &&
               ((uint)piVar8[2] <= (uint)(*(int *)(param_1 + 0x124) << 2))) {
              piVar8[0] = 0;
              piVar8[1] = 0;
            }
            else {
              operator_delete__(piVar8);
              *(int **)(param_1 + 0x110) = piVar1;
              if (piVar1 == (int *)0x0) {
                *(undefined8 *)(param_1 + 0x118) = 0;
              }
            }
          }
          else {
            *piVar8 = *piVar8 + uVar3;
          }
          *(int *)(param_1 + 0x120) = *(int *)(param_1 + 0x120) - uVar3;
          piVar8 = piVar1;
        } while (uVar4 < uVar10);
      }
    }
    if (param_1 != -0x108) {
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x128));
    }
  }
  __security_check_cookie(local_38 ^ (ulonglong)auStack_458);
  return;
}



/* 1400024f3 FUN_1400024f3 */

void FUN_1400024f3(longlong param_1)

{
  ulonglong *puVar1;
  DWORD DVar2;
  uint uVar3;
  ulonglong *puVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong unaff_RSI;
  ulonglong unaff_RDI;
  undefined1 local_res20 [8];
  ulonglong in_stack_00000420;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x128));
  uVar6 = unaff_RDI & 0xffffffff;
  puVar4 = *(ulonglong **)(unaff_RSI + 0x110);
  do {
    uVar5 = (uint)uVar6;
    if (puVar4 == (ulonglong *)0x0) break;
    uVar3 = *(uint *)((longlong)puVar4 + 4) - (uint)*puVar4;
    if (0x400 - uVar5 <= uVar3) {
      uVar3 = 0x400 - uVar5;
    }
    memcpy(local_res20 + uVar6,(void *)((ulonglong)(uint)*puVar4 + 0x18 + (longlong)puVar4),
           (ulonglong)uVar3);
    uVar5 = uVar5 + uVar3;
    uVar6 = (ulonglong)uVar5;
    puVar1 = (ulonglong *)puVar4[2];
    if (uVar3 == *(uint *)((longlong)puVar4 + 4) - (uint)*puVar4) {
      if ((puVar1 == (ulonglong *)0x0) &&
         ((uint)puVar4[1] <= (uint)(*(int *)(unaff_RSI + 0x124) << 2))) {
        *puVar4 = unaff_RDI;
      }
      else {
        operator_delete__(puVar4);
        *(ulonglong **)(unaff_RSI + 0x110) = puVar1;
        if (puVar1 == (ulonglong *)0x0) {
          *(ulonglong *)(unaff_RSI + 0x118) = unaff_RDI;
        }
      }
    }
    else {
      *(uint *)puVar4 = uVar3 + (uint)*puVar4;
    }
    *(int *)(unaff_RSI + 0x120) = *(int *)(unaff_RSI + 0x120) - uVar3;
    puVar4 = puVar1;
  } while (uVar5 < 0x400);
  LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_RSI + 0x128));
  if (uVar5 != 0) {
    do {
      DVar2 = FUN_140001710(unaff_RSI,local_res20 + (unaff_RDI & 0xffffffff),uVar5 - (int)unaff_RDI)
      ;
      uVar3 = (int)unaff_RDI + DVar2;
      unaff_RDI = (ulonglong)uVar3;
    } while (uVar3 < uVar5);
  }
  __security_check_cookie(in_stack_00000420 ^ (ulonglong)&stack0x00000000);
  return;
}



/* 1400025d0 FUN_1400025d0 */

void FUN_1400025d0(void)

{
  DWORD DVar1;
  uint unaff_EBP;
  longlong unaff_RSI;
  uint unaff_EDI;
  undefined1 local_res20 [8];
  ulonglong in_stack_00000420;
  
  do {
    DVar1 = FUN_140001710(unaff_RSI,local_res20 + unaff_EDI,unaff_EBP - unaff_EDI);
    unaff_EDI = unaff_EDI + DVar1;
  } while (unaff_EDI < unaff_EBP);
  __security_check_cookie(in_stack_00000420 ^ (ulonglong)&stack0x00000000);
  return;
}



/* 140002620 FUN_140002620 */

void FUN_140002620(longlong param_1,UINT param_2,LPARAM param_3,char param_4)

{
  BOOL BVar1;
  
  if (*(HWND *)(param_1 + 0x1a8) != (HWND)0x0) {
    BVar1 = IsWindow(*(HWND *)(param_1 + 0x1a8));
    if (BVar1 != 0) {
      if (param_4 == '\0') {
        SendMessageA(*(HWND *)(param_1 + 0x1a8),param_2,(ulonglong)*(uint *)(param_1 + 0x18),param_3
                    );
      }
      else {
        PostMessageA(*(HWND *)(param_1 + 0x1a8),param_2,(ulonglong)*(uint *)(param_1 + 0x18),param_3
                    );
      }
    }
  }
  if (*(DWORD *)(param_1 + 0x1b0) != 0) {
    PostThreadMessageA(*(DWORD *)(param_1 + 0x1b0),param_2,(ulonglong)*(uint *)(param_1 + 0x18),
                       param_3);
  }
  return;
}



/* 1400026b0 FUN_1400026b0 */

void FUN_1400026b0(longlong *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0001400026be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x30))(param_1,0x66a,0,1);
  return;
}



/* 1400026d0 FUN_1400026d0 */

void FUN_1400026d0(longlong *param_1)

{
  BOOL BVar1;
  uint uVar2;
  DWORD local_res8 [2];
  
  local_res8[0] = 0;
  uVar2 = 0;
  if ((HANDLE)param_1[2] != (HANDLE)0xffffffffffffffff) {
    BVar1 = GetCommModemStatus((HANDLE)param_1[2],local_res8);
    uVar2 = 0;
    if (BVar1 != 0) {
      uVar2 = local_res8[0];
    }
  }
  (**(code **)(*param_1 + 0x30))(param_1,0x66c,uVar2 >> 5 & 1,1);
  return;
}



/* 140002730 FUN_140002730 */

void FUN_140002730(longlong *param_1)

{
  BOOL BVar1;
  uint uVar2;
  DWORD local_res8 [2];
  
  local_res8[0] = 0;
  uVar2 = 0;
  if ((HANDLE)param_1[2] != (HANDLE)0xffffffffffffffff) {
    BVar1 = GetCommModemStatus((HANDLE)param_1[2],local_res8);
    uVar2 = 0;
    if (BVar1 != 0) {
      uVar2 = local_res8[0];
    }
  }
  (**(code **)(*param_1 + 0x30))(param_1,0x66b,uVar2 >> 4 & 1,1);
  return;
}



/* 140002790 FUN_140002790 */

void FUN_140002790(longlong *param_1)

{
  ClearCommBreak((HANDLE)param_1[2]);
                    /* WARNING: Could not recover jumptable at 0x0001400027b9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x30))(param_1,0x66f,0,1);
  return;
}



/* 1400027c0 FUN_1400027c0 */

void FUN_1400027c0(longlong *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0001400027ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x30))(param_1,0x670,0,1);
  return;
}



/* 1400027e0 FUN_1400027e0 */

void FUN_1400027e0(longlong *param_1)

{
  BOOL BVar1;
  DWORD local_res8 [8];
  
  if (((HANDLE)param_1[2] == (HANDLE)0xffffffffffffffff) ||
     (BVar1 = ClearCommError((HANDLE)param_1[2],local_res8,(LPCOMSTAT)0x0), BVar1 == 0)) {
    local_res8[0] = 0;
  }
  (**(code **)(*param_1 + 0x30))(param_1,0x671,local_res8[0],1);
  return;
}



/* 140002830 FUN_140002830 */

void FUN_140002830(longlong *param_1)

{
  BOOL BVar1;
  uint uVar2;
  DWORD local_res8 [2];
  
  local_res8[0] = 0;
  uVar2 = 0;
  if ((HANDLE)param_1[2] != (HANDLE)0xffffffffffffffff) {
    BVar1 = GetCommModemStatus((HANDLE)param_1[2],local_res8);
    uVar2 = 0;
    if (BVar1 != 0) {
      uVar2 = local_res8[0];
    }
  }
  (**(code **)(*param_1 + 0x30))(param_1,0x66d,uVar2 >> 6 & 1,1);
  return;
}



/* 140002890 FUN_140002890 */

void FUN_140002890(longlong *param_1)

{
  BOOL BVar1;
  uint uVar2;
  DWORD local_res8 [2];
  
  local_res8[0] = 0;
  uVar2 = 0;
  if ((HANDLE)param_1[2] != (HANDLE)0xffffffffffffffff) {
    BVar1 = GetCommModemStatus((HANDLE)param_1[2],local_res8);
    uVar2 = 0;
    if (BVar1 != 0) {
      uVar2 = local_res8[0];
    }
  }
  (**(code **)(*param_1 + 0x30))(param_1,0x80,uVar2 >> 7 & 1,1);
  return;
}



/* 1400028f0 FUN_1400028f0 */

void FUN_1400028f0(longlong *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0001400028fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x30))(param_1,0x672,0,1);
  return;
}



/* 140002910 FUN_140002910 */

void FUN_140002910(longlong *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00014000291e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x30))(param_1,0x673,0,1);
  return;
}



/* 140002930 FUN_140002930 */

void FUN_140002930(longlong *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00014000293e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x30))(param_1,0x676,0,1);
  return;
}



/* 140002950 FUN_140002950 */

void FUN_140002950(longlong *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00014000295e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x30))(param_1,0x674,0,1);
  return;
}



/* 140002970 FUN_140002970 */

void FUN_140002970(longlong *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00014000297e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x30))(param_1,0x675,0,1);
  return;
}



/* 140002990 FUN_140002990 */

void FUN_140002990(longlong *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00014000299e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x30))(param_1,0x677,0,1);
  return;
}



/* 1400029b0 FUN_1400029b0 */

void FUN_1400029b0(longlong *param_1,uint param_2)

{
  longlong lVar1;
  BOOL BVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  bool bVar3;
  undefined1 auStack_48 [32];
  DWORD aDStack_28 [2];
  _COMSTAT _Stack_20;
  ulonglong local_10;
  
  local_10 = DAT_140013010 ^ (ulonglong)auStack_48;
  if (((param_2 & 1) != 0) && ((*(byte *)(param_1 + 1) & 0x10) == 0)) {
    if (((HANDLE)param_1[2] == (HANDLE)0xffffffffffffffff) ||
       (BVar2 = ClearCommError((HANDLE)param_1[2],aDStack_28,&_Stack_20), BVar2 == 0)) {
      _Stack_20.cbInQue = 0xffffffff;
    }
    else if (_Stack_20.cbInQue == 0) goto LAB_140002a3b;
    if ((*(byte *)(param_1 + 1) & 4) == 0) {
      bVar3 = _Stack_20.cbInQue < *(uint *)((longlong)param_1 + 0x1b4);
    }
    else {
      FUN_140002300((longlong)param_1,_Stack_20.cbInQue * 2 + 0x40);
      bVar3 = *(uint *)(param_1 + 0x1b) < *(uint *)((longlong)param_1 + 0x1b4);
    }
    if (!bVar3) {
      (**(code **)(*param_1 + 0x38))(param_1);
    }
  }
LAB_140002a3b:
  if ((param_2 & 4) != 0) {
    if (((*(uint *)(param_1 + 1) & 8) != 0) && ((*(uint *)(param_1 + 1) & 0x20) == 0)) {
      if (param_1 == (longlong *)0xfffffffffffffef8) {
        lpCriticalSection = (LPCRITICAL_SECTION)0x20;
      }
      else {
        lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x25);
        EnterCriticalSection(lpCriticalSection);
      }
      lVar1 = param_1[0x24];
      LeaveCriticalSection(lpCriticalSection);
      if ((int)lVar1 != 0) {
        FUN_1400023c0((longlong)param_1);
      }
    }
    (**(code **)(*param_1 + 0x58))(param_1);
  }
  if ((param_2 & 2) != 0) {
    (**(code **)(*param_1 + 0x78))(param_1);
  }
  if ((param_2 & 8) != 0) {
    (**(code **)(*param_1 + 0x48))(param_1);
  }
  if ((param_2 & 0x10) != 0) {
    (**(code **)(*param_1 + 0x40))(param_1);
  }
  if ((param_2 >> 8 & 1) != 0) {
    (**(code **)(*param_1 + 0x68))(param_1);
  }
  if ((param_2 & 0x20) != 0) {
    (**(code **)(*param_1 + 0x70))(param_1);
  }
  if ((param_2 & 0x40) != 0) {
    (**(code **)(*param_1 + 0x50))(param_1);
  }
  if ((char)param_2 < '\0') {
    (**(code **)(*param_1 + 0x60))(param_1);
  }
  __security_check_cookie(local_10 ^ (ulonglong)auStack_48);
  return;
}



/* 1400029c5 FUN_1400029c5 */

void FUN_1400029c5(longlong *param_1,uint param_2,undefined8 param_3,undefined8 param_4,
                  undefined8 param_5,undefined8 param_6,ulonglong param_7)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  BOOL BVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  bool bVar5;
  DWORD local_res20 [2];
  
  if (((param_2 & 1) == 0) || ((*(byte *)(param_1 + 1) & 0x10) != 0)) goto LAB_140002a3b;
  uVar2 = param_5;
  if ((HANDLE)param_1[2] == (HANDLE)0xffffffffffffffff) {
LAB_140002a02:
    param_5._4_4_ = 0xffffffff;
  }
  else {
    BVar4 = ClearCommError((HANDLE)param_1[2],local_res20,(LPCOMSTAT)&param_5);
    uVar2 = param_5;
    if (BVar4 == 0) goto LAB_140002a02;
    if (param_5._4_4_ == 0) goto LAB_140002a3b;
  }
  param_5 = uVar2;
  if ((*(byte *)(param_1 + 1) & 4) == 0) {
    bVar5 = param_5._4_4_ < *(uint *)((longlong)param_1 + 0x1b4);
  }
  else {
    iVar1 = param_5._4_4_ * 2;
    FUN_140002300((longlong)param_1,iVar1 + 0x40);
    bVar5 = *(uint *)(param_1 + 0x1b) < *(uint *)((longlong)param_1 + 0x1b4);
  }
  if (!bVar5) {
    (**(code **)(*param_1 + 0x38))(param_1);
  }
LAB_140002a3b:
  if ((param_2 & 4) != 0) {
    if (((*(uint *)(param_1 + 1) & 8) != 0) && ((*(uint *)(param_1 + 1) & 0x20) == 0)) {
      if (param_1 == (longlong *)0xfffffffffffffef8) {
        lpCriticalSection = (LPCRITICAL_SECTION)0x20;
      }
      else {
        lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x25);
        EnterCriticalSection(lpCriticalSection);
      }
      lVar3 = param_1[0x24];
      LeaveCriticalSection(lpCriticalSection);
      if ((int)lVar3 != 0) {
        FUN_1400023c0((longlong)param_1);
      }
    }
    (**(code **)(*param_1 + 0x58))(param_1);
  }
  if ((param_2 & 2) != 0) {
    (**(code **)(*param_1 + 0x78))(param_1);
  }
  if ((param_2 & 8) != 0) {
    (**(code **)(*param_1 + 0x48))(param_1);
  }
  if ((param_2 & 0x10) != 0) {
    (**(code **)(*param_1 + 0x40))(param_1);
  }
  if ((param_2 >> 8 & 1) != 0) {
    (**(code **)(*param_1 + 0x68))(param_1);
  }
  if ((param_2 & 0x20) != 0) {
    (**(code **)(*param_1 + 0x70))(param_1);
  }
  if ((param_2 & 0x40) != 0) {
    (**(code **)(*param_1 + 0x50))(param_1);
  }
  if ((char)param_2 < '\0') {
    (**(code **)(*param_1 + 0x60))(param_1);
  }
  __security_check_cookie(param_7 ^ (ulonglong)&stack0x00000000);
  return;
}



/* 140002a4c FUN_140002a4c */

void FUN_140002a4c(void)

{
  longlong lVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  uint unaff_ESI;
  longlong *unaff_RDI;
  ulonglong in_stack_00000038;
  
  if (unaff_RDI == (longlong *)0xfffffffffffffef8) {
    lpCriticalSection = (LPCRITICAL_SECTION)0x20;
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)(unaff_RDI + 0x25);
    EnterCriticalSection(lpCriticalSection);
  }
  lVar1 = unaff_RDI[0x24];
  LeaveCriticalSection(lpCriticalSection);
  if ((int)lVar1 != 0) {
    FUN_1400023c0((longlong)unaff_RDI);
  }
  (**(code **)(*unaff_RDI + 0x58))();
  if ((unaff_ESI & 2) != 0) {
    (**(code **)(*unaff_RDI + 0x78))();
  }
  if ((unaff_ESI & 8) != 0) {
    (**(code **)(*unaff_RDI + 0x48))();
  }
  if ((unaff_ESI & 0x10) != 0) {
    (**(code **)(*unaff_RDI + 0x40))();
  }
  if ((unaff_ESI >> 8 & 1) != 0) {
    (**(code **)(*unaff_RDI + 0x68))();
  }
  if ((unaff_ESI & 0x20) != 0) {
    (**(code **)(*unaff_RDI + 0x70))();
  }
  if ((unaff_ESI & 0x40) != 0) {
    (**(code **)(*unaff_RDI + 0x50))();
  }
  if ((char)unaff_ESI < '\0') {
    (**(code **)(*unaff_RDI + 0x60))();
  }
  __security_check_cookie(in_stack_00000038 ^ (ulonglong)&stack0x00000000);
  return;
}



/* 140002a90 FUN_140002a90 */

void FUN_140002a90(void)

{
  uint unaff_ESI;
  longlong *unaff_RDI;
  ulonglong in_stack_00000038;
  
  FUN_1400023c0((longlong)unaff_RDI);
  (**(code **)(*unaff_RDI + 0x58))();
  if ((unaff_ESI & 2) != 0) {
    (**(code **)(*unaff_RDI + 0x78))();
  }
  if ((unaff_ESI & 8) != 0) {
    (**(code **)(*unaff_RDI + 0x48))();
  }
  if ((unaff_ESI & 0x10) != 0) {
    (**(code **)(*unaff_RDI + 0x40))();
  }
  if ((unaff_ESI >> 8 & 1) != 0) {
    (**(code **)(*unaff_RDI + 0x68))();
  }
  if ((unaff_ESI & 0x20) != 0) {
    (**(code **)(*unaff_RDI + 0x70))();
  }
  if ((unaff_ESI & 0x40) != 0) {
    (**(code **)(*unaff_RDI + 0x50))();
  }
  if ((char)unaff_ESI < '\0') {
    (**(code **)(*unaff_RDI + 0x60))();
  }
  __security_check_cookie(in_stack_00000038 ^ (ulonglong)&stack0x00000000);
  return;
}



/* 140002b05 FUN_140002b05 */

void FUN_140002b05(void)

{
  longlong *unaff_RDI;
  ulonglong in_stack_00000038;
  
  (**(code **)(*unaff_RDI + 0x60))();
  __security_check_cookie(in_stack_00000038 ^ (ulonglong)&stack0x00000000);
  return;
}



/* 140002b30 FUN_140002b30 */

void FUN_140002b30(longlong *param_1)

{
  char cVar1;
  BOOL BVar2;
  DWORD DVar3;
  int iVar4;
  undefined1 auStack_58 [32];
  DWORD DStack_38;
  DWORD DStack_34;
  DWORD aDStack_30 [2];
  _COMSTAT _Stack_28;
  ulonglong local_18;
  
  local_18 = DAT_140013010 ^ (ulonglong)auStack_58;
  if (((HANDLE)param_1[2] == (HANDLE)0xffffffffffffffff) ||
     (BVar2 = SetCommMask((HANDLE)param_1[2],*(DWORD *)((longlong)param_1 + 0x15c)), BVar2 == 0)) {
    __security_check_cookie(local_18 ^ (ulonglong)auStack_58);
    return;
  }
  cVar1 = (char)param_1[0x2b];
  while (cVar1 != '\0') {
    DStack_38 = 0;
    if ((HANDLE)param_1[2] == (HANDLE)0xffffffffffffffff) break;
    BVar2 = ClearCommError((HANDLE)param_1[2],&DStack_34,&_Stack_28);
    if ((BVar2 == 0) || (_Stack_28.cbInQue != 0)) {
      DStack_38 = 1;
      Sleep(10);
LAB_140002c1d:
      if (DStack_38 == 0) {
        if ((((byte)(int)param_1[1] & 0x28) == 8) &&
           (iVar4 = FUN_140001e00((longlong)(param_1 + 0x21)), iVar4 != 0)) {
          FUN_1400023c0((longlong)param_1);
        }
      }
      else {
        (**(code **)(*param_1 + 0xa8))(param_1);
      }
    }
    else {
      BVar2 = WaitCommEvent((HANDLE)param_1[2],&DStack_38,(LPOVERLAPPED)(param_1 + 0x3f));
      if (BVar2 != 0) goto LAB_140002c1d;
      DVar3 = GetLastError();
      if (DVar3 == 0x3e5) {
        GetOverlappedResult((HANDLE)param_1[2],(LPOVERLAPPED)(param_1 + 0x3f),aDStack_30,1);
        goto LAB_140002c1d;
      }
      Sleep(10);
    }
    cVar1 = (char)param_1[0x2b];
  }
  DStack_38 = 0;
  __security_check_cookie(local_18 ^ (ulonglong)auStack_58);
  return;
}



/* 140002b6a FUN_140002b6a */

void FUN_140002b6a(void)

{
  char cVar1;
  BOOL BVar2;
  DWORD DVar3;
  int iVar4;
  longlong *unaff_RBX;
  DWORD local_res20;
  DWORD DStackX_24;
  DWORD in_stack_00000034;
  ulonglong in_stack_00000040;
  
  cVar1 = (char)unaff_RBX[0x2b];
  while (cVar1 != '\0') {
    local_res20 = 0;
    if ((HANDLE)unaff_RBX[2] == (HANDLE)0xffffffffffffffff) break;
    BVar2 = ClearCommError((HANDLE)unaff_RBX[2],&DStackX_24,(LPCOMSTAT)&stack0x00000030);
    if ((BVar2 == 0) || (in_stack_00000034 != 0)) {
      local_res20 = 1;
      Sleep(10);
LAB_140002c1d:
      if (local_res20 == 0) {
        if ((((byte)(int)unaff_RBX[1] & 0x28) == 8) &&
           (iVar4 = FUN_140001e00((longlong)(unaff_RBX + 0x21)), iVar4 != 0)) {
          FUN_1400023c0((longlong)unaff_RBX);
        }
      }
      else {
        (**(code **)(*unaff_RBX + 0xa8))();
      }
    }
    else {
      BVar2 = WaitCommEvent((HANDLE)unaff_RBX[2],&local_res20,(LPOVERLAPPED)(unaff_RBX + 0x3f));
      if (BVar2 != 0) goto LAB_140002c1d;
      DVar3 = GetLastError();
      if (DVar3 == 0x3e5) {
        GetOverlappedResult((HANDLE)unaff_RBX[2],(LPOVERLAPPED)(unaff_RBX + 0x3f),
                            (LPDWORD)&stack0x00000028,1);
        goto LAB_140002c1d;
      }
      Sleep(10);
    }
    cVar1 = (char)unaff_RBX[0x2b];
  }
  local_res20 = 0;
  __security_check_cookie(in_stack_00000040 ^ (ulonglong)&stack0x00000000);
  return;
}



/* 140002b82 FUN_140002b82 */

void FUN_140002b82(void)

{
  BOOL BVar1;
  DWORD DVar2;
  int iVar3;
  longlong *unaff_RBX;
  DWORD unaff_ESI;
  DWORD local_res20;
  DWORD local_res24;
  DWORD in_stack_00000034;
  ulonglong in_stack_00000040;
  
  do {
    if ((HANDLE)unaff_RBX[2] == (HANDLE)0xffffffffffffffff) break;
    BVar1 = ClearCommError((HANDLE)unaff_RBX[2],&local_res24,(LPCOMSTAT)&stack0x00000030);
    if ((BVar1 == 0) || (in_stack_00000034 != unaff_ESI)) {
      local_res20 = 1;
      Sleep(10);
LAB_140002c1d:
      if (local_res20 == 0) {
        if (((byte)(int)unaff_RBX[1] & 0x28) == 8) {
          iVar3 = FUN_140001e00((longlong)(unaff_RBX + 0x21));
          if (iVar3 != 0) {
            FUN_1400023c0((longlong)unaff_RBX);
          }
        }
      }
      else {
        (**(code **)(*unaff_RBX + 0xa8))();
      }
    }
    else {
      BVar1 = WaitCommEvent((HANDLE)unaff_RBX[2],&local_res20,(LPOVERLAPPED)(unaff_RBX + 0x3f));
      if (BVar1 != 0) goto LAB_140002c1d;
      DVar2 = GetLastError();
      if (DVar2 == 0x3e5) {
        GetOverlappedResult((HANDLE)unaff_RBX[2],(LPOVERLAPPED)(unaff_RBX + 0x3f),
                            (LPDWORD)&stack0x00000028,1);
        goto LAB_140002c1d;
      }
      Sleep(10);
    }
    local_res20 = unaff_ESI;
  } while ((char)unaff_RBX[0x2b] != (char)unaff_ESI);
  __security_check_cookie(in_stack_00000040 ^ (ulonglong)&stack0x00000000);
  return;
}



/* 140002c6a FUN_140002c6a */

void FUN_140002c6a(void)

{
  ulonglong in_stack_00000040;
  
  __security_check_cookie(in_stack_00000040 ^ (ulonglong)&stack0x00000000);
  return;
}



/* 140002c84 FUN_140002c84 */

void FUN_140002c84(void)

{
  ulonglong in_stack_00000040;
  
  __security_check_cookie(in_stack_00000040 ^ (ulonglong)&stack0x00000000);
  return;
}



/* 140002ca0 FUN_140002ca0 */

undefined8 FUN_140002ca0(longlong *param_1)

{
  char cVar1;
  byte bVar2;
  longlong lVar3;
  DWORD DVar4;
  uint uVar5;
  int iVar6;
  LPCRITICAL_SECTION lpCriticalSection;
  bool bVar7;
  
  if (param_1[2] == -1) {
    return 1;
  }
  cVar1 = (char)param_1[0x2b];
  do {
    if (((cVar1 == '\0') || (param_1[2] == -1)) ||
       (DVar4 = WaitForSingleObject((HANDLE)param_1[0x2e],0x32), (char)param_1[0x2b] == '\0')) {
      return 0;
    }
    if (DVar4 == 0) {
      bVar2 = *(byte *)(param_1 + 1);
      while ((bVar2 & 8) != 0) {
        if (param_1 == (longlong *)0xfffffffffffffef8) {
          lpCriticalSection = (LPCRITICAL_SECTION)0x20;
        }
        else {
          lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x25);
          EnterCriticalSection(lpCriticalSection);
        }
        lVar3 = param_1[0x24];
        LeaveCriticalSection(lpCriticalSection);
        if ((int)lVar3 == 0) break;
        FUN_1400023c0((longlong)param_1);
        bVar2 = *(byte *)(param_1 + 1);
      }
      ResetEvent((HANDLE)param_1[0x2e]);
    }
    else if (DVar4 == 0x102) {
      uVar5 = FUN_140001cf0((longlong)param_1);
      if (uVar5 != 0) {
        if ((*(byte *)(param_1 + 1) & 4) == 0) {
          bVar7 = uVar5 < *(uint *)((longlong)param_1 + 0x1b4);
        }
        else {
          FUN_140002300((longlong)param_1,uVar5);
          bVar7 = *(uint *)(param_1 + 0x1b) < *(uint *)((longlong)param_1 + 0x1b4);
        }
        if (!bVar7) {
          (**(code **)(*param_1 + 0x38))(param_1);
        }
      }
      if (((*(byte *)(param_1 + 1) & 8) != 0) &&
         (iVar6 = FUN_140001e00((longlong)(param_1 + 0x21)), iVar6 != 0)) {
        FUN_1400023c0((longlong)param_1);
      }
    }
    cVar1 = (char)param_1[0x2b];
  } while( true );
}



/* 140002cc8 FUN_140002cc8 */

undefined8 FUN_140002cc8(void)

{
  byte bVar1;
  longlong lVar2;
  DWORD DVar3;
  uint uVar4;
  int iVar5;
  longlong *unaff_RBX;
  LPCRITICAL_SECTION lpCriticalSection;
  bool bVar6;
  
  do {
    if (unaff_RBX[2] == -1) {
      return 0;
    }
    DVar3 = WaitForSingleObject((HANDLE)unaff_RBX[0x2e],0x32);
    if ((char)unaff_RBX[0x2b] == '\0') {
      return 0;
    }
    if (DVar3 == 0) {
      bVar1 = *(byte *)(unaff_RBX + 1);
      while ((bVar1 & 8) != 0) {
        if (unaff_RBX == (longlong *)0xfffffffffffffef8) {
          lpCriticalSection = (LPCRITICAL_SECTION)0x20;
        }
        else {
          lpCriticalSection = (LPCRITICAL_SECTION)(unaff_RBX + 0x25);
          EnterCriticalSection(lpCriticalSection);
        }
        lVar2 = unaff_RBX[0x24];
        LeaveCriticalSection(lpCriticalSection);
        if ((int)lVar2 == 0) break;
        FUN_1400023c0((longlong)unaff_RBX);
        bVar1 = *(byte *)(unaff_RBX + 1);
      }
      ResetEvent((HANDLE)unaff_RBX[0x2e]);
    }
    else if (DVar3 == 0x102) {
      uVar4 = FUN_140001cf0((longlong)unaff_RBX);
      if (uVar4 != 0) {
        if ((*(byte *)(unaff_RBX + 1) & 4) == 0) {
          bVar6 = uVar4 < *(uint *)((longlong)unaff_RBX + 0x1b4);
        }
        else {
          FUN_140002300((longlong)unaff_RBX,uVar4);
          bVar6 = *(uint *)(unaff_RBX + 0x1b) < *(uint *)((longlong)unaff_RBX + 0x1b4);
        }
        if (!bVar6) {
          (**(code **)(*unaff_RBX + 0x38))();
        }
      }
      if (((*(byte *)(unaff_RBX + 1) & 8) != 0) &&
         (iVar5 = FUN_140001e00((longlong)(unaff_RBX + 0x21)), iVar5 != 0)) {
        FUN_1400023c0((longlong)unaff_RBX);
      }
    }
    if ((char)unaff_RBX[0x2b] == '\0') {
      return 0;
    }
  } while( true );
}



/* 140002de1 FUN_140002de1 */

undefined8 FUN_140002de1(void)

{
  return 0;
}



/* 140002df0 FUN_140002df0 */

void FUN_140002df0(longlong *param_1)

{
  char cVar1;
  BOOL BVar2;
  uint uVar3;
  bool bVar4;
  undefined1 auStack_48 [32];
  DWORD local_28 [2];
  _COMSTAT local_20;
  ulonglong local_10;
  
  local_10 = DAT_140013010 ^ (ulonglong)auStack_48;
  cVar1 = (char)param_1[0x2b];
  do {
    if (cVar1 == '\0') {
      __security_check_cookie(local_10 ^ (ulonglong)auStack_48);
      return;
    }
    Sleep(0x32);
    if (((HANDLE)param_1[2] == (HANDLE)0xffffffffffffffff) ||
       (BVar2 = ClearCommError((HANDLE)param_1[2],local_28,&local_20), BVar2 == 0)) {
      uVar3 = 0xffffffff;
LAB_140002e49:
      if ((*(byte *)(param_1 + 1) & 4) == 0) {
        bVar4 = uVar3 < *(uint *)((longlong)param_1 + 0x1b4);
      }
      else {
        FUN_140002300((longlong)param_1,uVar3);
        bVar4 = *(uint *)(param_1 + 0x1b) < *(uint *)((longlong)param_1 + 0x1b4);
      }
      if (!bVar4) {
        (**(code **)(*param_1 + 0x38))(param_1);
      }
    }
    else {
      uVar3 = local_20.cbInQue;
      if (local_20.cbInQue != 0) goto LAB_140002e49;
    }
    cVar1 = (char)param_1[0x2b];
  } while( true );
}



/* 140002ea0 FUN_140002ea0 */

undefined8 FUN_140002ea0(longlong param_1)

{
  char cVar1;
  int iVar2;
  DWORD DVar3;
  LPCRITICAL_SECTION lpCriticalSection;
  
  cVar1 = *(char *)(param_1 + 0x158);
  do {
    if (cVar1 == '\0') {
      return 0;
    }
    DVar3 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x1a0),200);
    cVar1 = *(char *)(param_1 + 0x158);
    while (cVar1 != '\0') {
      if (param_1 == -0x108) {
        lpCriticalSection = (LPCRITICAL_SECTION)0x20;
      }
      else {
        lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x128);
        EnterCriticalSection(lpCriticalSection);
      }
      iVar2 = *(int *)(param_1 + 0x120);
      LeaveCriticalSection(lpCriticalSection);
      if (iVar2 == 0) break;
      FUN_1400023c0(param_1);
      cVar1 = *(char *)(param_1 + 0x158);
    }
    if (DVar3 == 0) {
      ResetEvent(*(HANDLE *)(param_1 + 0x170));
    }
    cVar1 = *(char *)(param_1 + 0x158);
  } while( true );
}



/* 140002eb6 FUN_140002eb6 */

undefined8 FUN_140002eb6(void)

{
  char cVar1;
  int iVar2;
  DWORD DVar3;
  LPCRITICAL_SECTION lpCriticalSection;
  longlong unaff_RSI;
  
  do {
    DVar3 = WaitForSingleObject(*(HANDLE *)(unaff_RSI + 0x1a0),200);
    cVar1 = *(char *)(unaff_RSI + 0x158);
    while (cVar1 != '\0') {
      if (unaff_RSI == -0x108) {
        lpCriticalSection = (LPCRITICAL_SECTION)0x20;
      }
      else {
        lpCriticalSection = (LPCRITICAL_SECTION)(unaff_RSI + 0x128);
        EnterCriticalSection(lpCriticalSection);
      }
      iVar2 = *(int *)(unaff_RSI + 0x120);
      LeaveCriticalSection(lpCriticalSection);
      if (iVar2 == 0) break;
      FUN_1400023c0(unaff_RSI);
      cVar1 = *(char *)(unaff_RSI + 0x158);
    }
    if (DVar3 == 0) {
      ResetEvent(*(HANDLE *)(unaff_RSI + 0x170));
    }
    if (*(char *)(unaff_RSI + 0x158) == '\0') {
      return 0;
    }
  } while( true );
}



/* 140002f5e FUN_140002f5e */

undefined8 FUN_140002f5e(void)

{
  return 0;
}



/* 140002f70 FUN_140002f70 */

uint FUN_140002f70(longlong *param_1)

{
  uint uVar1;
  
  if ((*(uint *)(param_1 + 1) >> 1 & 1) != 0) {
    uVar1 = (**(code **)(*param_1 + 0xb0))();
    _endthreadex(uVar1);
    return uVar1;
  }
  uVar1 = (**(code **)(*param_1 + 0xb8))();
  _endthreadex(uVar1);
  return uVar1;
}



/* 140002fc0 FUN_140002fc0 */

uint FUN_140002fc0(longlong *param_1)

{
  uint _Retval;
  
  _Retval = (**(code **)(*param_1 + 0xc0))();
  _endthreadex(_Retval);
  return _Retval;
}



/* 140002ff0 FUN_140002ff0 */

uint FUN_140002ff0(longlong *param_1)

{
  uint _Retval;
  
  _Retval = (**(code **)(*param_1 + 200))();
  _endthreadex(_Retval);
  return _Retval;
}



/* 140003020 FUN_140003020 */

undefined8 * FUN_140003020(undefined8 *param_1,uint param_2)

{
  FUN_140001500(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 140003060 FUN_140003060 */

undefined8 * FUN_140003060(undefined8 *param_1,uint param_2)

{
  FUN_140001d60(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 1400030a0 FUN_1400030a0 */

CDialog * FUN_1400030a0(CDialog *param_1,uint param_2)

{
  CDialogImpl::~CDialogImpl((CDialogImpl *)(param_1 + 0x158));
  *(undefined ***)(param_1 + 0x140) = CBrush::vftable;
  FUN_1400014a0((CGdiObject *)(param_1 + 0x140));
  CDialog::~CDialog(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    _guard_check_icall();
  }
  return param_1;
}



/* 140003120 FUN_140003120 */

undefined8 FUN_140003120(void)

{
  return 0x14000e9f8;
}



/* 140003130 FUN_140003130 */

CDialogEx * FUN_140003130(CDialogEx *param_1)

{
  HINSTANCE__ *hInstance;
  HICON pHVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  int iVar4;
  
  CDialogEx::CDialogEx(param_1,0x66,(CWnd *)0x0);
  *(undefined ***)param_1 = CDSPIDlg::vftable;
  iVar4 = 0;
  *(undefined8 *)(param_1 + 0x198) = 0;
  *(undefined8 *)(param_1 + 0x1a0) = 0;
  *(undefined8 *)(param_1 + 0x228) = 0;
  CWnd::CWnd((CWnd *)(param_1 + 0xa48));
  *(undefined ***)(param_1 + 0xa48) = CComboBox::vftable;
  CWnd::CWnd((CWnd *)(param_1 + 0xb30));
  *(undefined ***)(param_1 + 0xb30) = CSliderCtrl::vftable;
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_1 + 0xc18),(char *)&PTR_14000ed58);
  CWnd::CWnd((CWnd *)(param_1 + 0xc20));
  *(undefined ***)(param_1 + 0xc20) = CSliderCtrl::vftable;
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_1 + 0xd08),"10");
  CToolTipCtrl::CToolTipCtrl((CToolTipCtrl *)(param_1 + 0xd10));
  CWnd::CWnd((CWnd *)(param_1 + 0xe38));
  *(undefined ***)(param_1 + 0xe38) = CStatic::vftable;
  CWnd::CWnd((CWnd *)(param_1 + 0xf20));
  *(undefined ***)(param_1 + 0xf20) = CStatic::vftable;
  CWnd::CWnd((CWnd *)(param_1 + 0x1008));
  *(undefined ***)(param_1 + 0x1008) = CStatic::vftable;
  CWnd::CWnd((CWnd *)(param_1 + 0x10f0));
  *(undefined ***)(param_1 + 0x10f0) = CSliderCtrl::vftable;
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_1 + 0x11d8));
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_1 + 0x11e0),(char *)&PTR_14000ed58);
  AfxGetModuleState();
  hInstance = AfxFindResourceHandle((char *)0x81,&DAT_0000000e);
  pHVar1 = LoadIconW(hInstance,(LPCWSTR)0x81);
  *(HICON *)(param_1 + 0x170) = pHVar1;
  *(undefined4 *)(param_1 + 400) = 0;
  *(undefined8 *)(param_1 + 0xa34) = 0;
  *(undefined4 *)(param_1 + 0xa3c) = 10;
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_1 + 0x11d8),"10");
  *(undefined4 *)(param_1 + 0xa40) = 0;
  *(undefined8 *)(param_1 + 0x1c0) = 0;
  *(undefined8 *)(param_1 + 0x1c8) = 0;
  *(undefined8 *)(param_1 + 0x1d0) = 0;
  *(undefined8 *)(param_1 + 0x1d8) = 0;
  *(undefined8 *)(param_1 + 0x1e0) = 0;
  *(undefined8 *)(param_1 + 0x1e8) = 0;
  *(undefined8 *)(param_1 + 0x1f0) = 0;
  *(undefined8 *)(param_1 + 0x1f8) = 0;
  *(undefined8 *)(param_1 + 0x200) = 0;
  *(undefined8 *)(param_1 + 0x208) = 0;
  *(undefined8 *)(param_1 + 0x210) = 0;
  *(undefined8 *)(param_1 + 0x218) = 0;
  puVar2 = &DAT_140013f41;
  do {
    uVar3 = (undefined1)iVar4;
    puVar2[1] = uVar3;
    *puVar2 = uVar3;
    puVar2[-1] = uVar3;
    puVar2[2] = 0;
    iVar4 = iVar4 + 1;
    puVar2 = puVar2 + 4;
  } while (iVar4 < 0x100);
  return param_1;
}



/* 140003390 FUN_140003390 */

CDialog * FUN_140003390(CDialog *param_1,uint param_2)

{
  FUN_140001250(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    _guard_check_icall();
  }
  return param_1;
}



/* 1400033e0 FUN_1400033e0 */

void FUN_1400033e0(longlong param_1,CDataExchange *param_2)

{
  DDX_Control(param_2,1000,(CWnd *)(param_1 + 0xb30));
  DDX_Text(param_2,0x3ea,
           (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
           (param_1 + 0xc18));
  DDX_Text(param_2,0x3eb,
           (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
           (param_1 + 0xd08));
  DDX_Control(param_2,0x3e9,(CWnd *)(param_1 + 0xc20));
  DDX_Control(param_2,0x3fd,(CWnd *)(param_1 + 0xf20));
  DDX_Control(param_2,0x3ec,(CWnd *)(param_1 + 0x1008));
  DDX_Control(param_2,0x400,(CWnd *)(param_1 + 0x10f0));
  DDX_Text(param_2,0x401,
           (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
           (param_1 + 0x11d8));
  DDV_MaxChars(param_2,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                       (param_1 + 0x11d8),100);
                    /* WARNING: Could not recover jumptable at 0x0001400034d1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DDX_Text(param_2,0x402,
           (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
           (param_1 + 0x11e0));
  return;
}



/* 1400034e0 FUN_1400034e0 */

undefined ** FUN_1400034e0(void)

{
  return &PTR_GetThisMessageMap_14000dad0;
}



/* 1400034f0 FUN_1400034f0 */

undefined8 FUN_1400034f0(CDialog *param_1)

{
  CDialog *pCVar1;
  int iVar2;
  HMENU pHVar3;
  CMenu *pCVar4;
  CWnd *pCVar5;
  HDC pHVar6;
  CDC *pCVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  longlong lParam;
  LPCSTR local_res10;
  ulonglong uVar10;
  ulonglong uVar11;
  
  CDialog::OnInitDialog(param_1);
  pHVar3 = GetSystemMenu(*(HWND *)(param_1 + 0x40),0);
  pCVar4 = CMenu::FromHandle(pHVar3);
  if (pCVar4 != (CMenu *)0x0) {
    ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               &local_res10);
    ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::LoadStringA
              ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               &local_res10,0x65);
    if (*(int *)(local_res10 + -0x10) != 0) {
      AppendMenuA(*(HMENU *)(pCVar4 + 8),0x800,0,(LPCSTR)0x0);
      AppendMenuA(*(HMENU *)(pCVar4 + 8),0,0x10,local_res10);
    }
    ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               &local_res10);
  }
  SendMessageA(*(HWND *)(param_1 + 0x40),0x80,1,*(LPARAM *)(param_1 + 0x170));
  SendMessageA(*(HWND *)(param_1 + 0x40),0x80,0,*(LPARAM *)(param_1 + 0x170));
  Ordinal_13(0xc,s_WyWA7do5FzTHuHfbsigE9FQX7CjZQ0_u_140013040);
  pCVar5 = CWnd::GetDlgItem((CWnd *)param_1,0x3ec);
  pHVar6 = GetDC(*(HWND *)(pCVar5 + 0x40));
  pCVar7 = CDC::FromHandle(pHVar6);
  *(CDC **)(param_1 + 0x188) = pCVar7;
  pCVar5 = CWnd::GetDlgItem((CWnd *)param_1,0x3f8);
  CWnd::EnableWindow(pCVar5,0);
  pCVar5 = CWnd::GetDlgItem((CWnd *)param_1,0x3f4);
  CWnd::EnableWindow(pCVar5,0);
  pCVar5 = CWnd::GetDlgItem((CWnd *)param_1,0x3f5);
  CWnd::EnableWindow(pCVar5,0);
  pCVar5 = CWnd::GetDlgItem((CWnd *)param_1,0x3f6);
  CWnd::EnableWindow(pCVar5,0);
  pCVar5 = CWnd::GetDlgItem((CWnd *)param_1,0x3f7);
  CWnd::EnableWindow(pCVar5,0);
  *(undefined8 *)(param_1 + 0x178) = 0;
  *(undefined4 *)(param_1 + 0x180) = 0;
  *(undefined4 *)(param_1 + 0x230) = 0;
  KSJ_UnInit();
  KSJ_Init();
  iVar2 = KSJ_DeviceGetCount();
  *(int *)(param_1 + 400) = iVar2;
  if (iVar2 == 0) {
    CWnd::MessageBoxA((CWnd *)param_1,&DAT_14000d6a0,(char *)0x0,0);
    pCVar5 = CWnd::GetDlgItem((CWnd *)param_1,0x3ed);
    CWnd::EnableWindow(pCVar5,0);
    return 0;
  }
  pCVar1 = param_1 + 0xa34;
  uVar11 = 0;
  uVar10 = 0;
  KSJ_PreviewGetDefaultFieldOfView(iVar2 + -1,0,0,param_1 + 0xa38,pCVar1,0,0);
  uVar11 = uVar11 & 0xffffffff00000000;
  uVar10 = uVar10 & 0xffffffff00000000;
  KSJ_PreviewSetFieldOfView
            (0,0,0,*(undefined4 *)(param_1 + 0xa38),*(undefined4 *)pCVar1,uVar10,uVar11);
  KSJ_CaptureSetFieldOfView
            (0,0,0,*(undefined4 *)(param_1 + 0xa38),*(undefined4 *)pCVar1,
             uVar10 & 0xffffffff00000000,uVar11 & 0xffffffff00000000);
  KSJ_CaptureGetSize(0,param_1 + 0xa38,pCVar1);
  KSJ_StreamStart(0);
  KSJ_CaptureSetRecover(0,0);
  *(undefined4 *)(param_1 + 0x178) = 1;
  FUN_140003c00((longlong)param_1);
  CSliderCtrl::SetRange((CSliderCtrl *)(param_1 + 0xc20),1,200,0);
  SendMessageA(*(HWND *)(param_1 + 0xc60),0x405,1,10);
  pCVar5 = CWnd::GetDlgItem((CWnd *)param_1,0x3e9);
  CWnd::EnableWindow(pCVar5,0);
  pCVar5 = CWnd::GetDlgItem((CWnd *)param_1,0x3eb);
  CWnd::EnableWindow(pCVar5,0);
  pCVar5 = CWnd::GetDlgItem((CWnd *)param_1,0x3ff);
  CWnd::EnableWindow(pCVar5,0);
  CSliderCtrl::SetRange((CSliderCtrl *)(param_1 + 0xb30),10,500,0);
  SendMessageA(*(HWND *)(param_1 + 0xb70),0x405,1,100);
  CSliderCtrl::SetRange((CSliderCtrl *)(param_1 + 0x10f0),1,100,0);
  lParam = (longlong)*(int *)(param_1 + 0xa3c);
  uVar8 = 0x405;
  uVar9 = 1;
  SendMessageA(*(HWND *)(param_1 + 0x1130),0x405,1,lParam);
  FUN_1400066a0((CWnd *)param_1,uVar8,uVar9,(int)lParam);
  (**(code **)(*(longlong *)(param_1 + 0xd10) + 0x2d8))(param_1 + 0xd10,param_1,0);
  pCVar5 = CWnd::GetDlgItem((CWnd *)param_1,0x3f6);
  CToolTipCtrl::AddTool((CToolTipCtrl *)(param_1 + 0xd10),pCVar5,&DAT_14000d6b0,(tagRECT *)0x0,0);
  pCVar5 = CWnd::GetDlgItem((CWnd *)param_1,0x3f7);
  CToolTipCtrl::AddTool((CToolTipCtrl *)(param_1 + 0xd10),pCVar5,&DAT_14000d6f0,(tagRECT *)0x0,0);
  pCVar5 = CWnd::GetDlgItem((CWnd *)param_1,0x3f5);
  CToolTipCtrl::AddTool((CToolTipCtrl *)(param_1 + 0xd10),pCVar5,&DAT_14000d718,(tagRECT *)0x0,0);
  SendMessageA(*(HWND *)(param_1 + 0xd50),0x403,0,200);
  SendMessageA(*(HWND *)(param_1 + 0xd50),0x414,0xff0000,0);
  SendMessageA(*(HWND *)(param_1 + 0xd50),0x413,0xffffff,0);
  SendMessageA(*(HWND *)(param_1 + 0xd50),0x401,1,0);
  return 1;
}



/* 1400039d0 FUN_1400039d0 */

void FUN_1400039d0(CWnd *param_1,uint param_2)

{
  undefined **local_178 [40];
  undefined **local_38 [3];
  CDialogImpl local_20 [32];
  
  if ((param_2 & 0xfff0) == 0x10) {
    CDialogEx::CDialogEx((CDialogEx *)local_178,100,(CWnd *)0x0);
    local_178[0] = CAboutDlg::vftable;
    CDialog::DoModal((CDialog *)local_178);
    CDialogImpl::~CDialogImpl(local_20);
    local_38[0] = CBrush::vftable;
    FUN_1400014a0((CGdiObject *)local_38);
    CDialog::~CDialog((CDialog *)local_178);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000140003a59. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CWnd::Default(param_1);
  return;
}



/* 140003a60 FUN_140003a60 */

void FUN_140003a60(CDialog *param_1)

{
  BOOL BVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_b8 [32];
  tagRECT tStack_98;
  CPaintDC aCStack_88 [8];
  HDC pHStack_80;
  ulonglong local_18;
  
  local_18 = DAT_140013010 ^ (ulonglong)auStack_b8;
  BVar1 = IsIconic(*(HWND *)(param_1 + 0x40));
  if (BVar1 == 0) {
    CDialog::OnPaint(param_1);
  }
  else {
    CPaintDC::CPaintDC(aCStack_88,(CWnd *)param_1);
    SendMessageA(*(HWND *)(param_1 + 0x40),0x27,(WPARAM)pHStack_80,0);
    iVar2 = GetSystemMetrics(0xb);
    iVar3 = GetSystemMetrics(0xc);
    tStack_98.left = 0;
    tStack_98.top = 0;
    tStack_98.right = 0;
    tStack_98.bottom = 0;
    GetClientRect(*(HWND *)(param_1 + 0x40),&tStack_98);
    DrawIcon(pHStack_80,(((tStack_98.right - tStack_98.left) - iVar2) + 1) / 2,
             (((tStack_98.bottom - tStack_98.top) - iVar3) + 1) / 2,*(HICON *)(param_1 + 0x170));
    CPaintDC::~CPaintDC(aCStack_88);
  }
  __security_check_cookie(local_18 ^ (ulonglong)auStack_b8);
  return;
}



/* 140003a90 FUN_140003a90 */

void FUN_140003a90(void)

{
  int iVar1;
  int iVar2;
  CWnd *unaff_RSI;
  undefined8 local_res20;
  LONG LStack0000000000000028;
  LONG LStack000000000000002c;
  HDC in_stack_00000038;
  ulonglong in_stack_000000a0;
  
  CPaintDC::CPaintDC((CPaintDC *)&stack0x00000030,unaff_RSI);
  SendMessageA(*(HWND *)(unaff_RSI + 0x40),0x27,(WPARAM)in_stack_00000038,0);
  iVar1 = GetSystemMetrics(0xb);
  iVar2 = GetSystemMetrics(0xc);
  local_res20._0_4_ = 0;
  local_res20._4_4_ = 0;
  LStack0000000000000028 = 0;
  LStack000000000000002c = 0;
  GetClientRect(*(HWND *)(unaff_RSI + 0x40),(LPRECT)&local_res20);
  DrawIcon(in_stack_00000038,(((LStack0000000000000028 - (LONG)local_res20) - iVar1) + 1) / 2,
           (((LStack000000000000002c - local_res20._4_4_) - iVar2) + 1) / 2,
           *(HICON *)(unaff_RSI + 0x170));
  CPaintDC::~CPaintDC((CPaintDC *)&stack0x00000030);
  __security_check_cookie(in_stack_000000a0 ^ (ulonglong)&stack0x00000000);
  return;
}



/* 140003b4c FUN_140003b4c */

void FUN_140003b4c(void)

{
  CDialog *unaff_RSI;
  ulonglong in_stack_000000a0;
  
  CDialog::OnPaint(unaff_RSI);
  __security_check_cookie(in_stack_000000a0 ^ (ulonglong)&stack0x00000000);
  return;
}



/* 140003b80 FUN_140003b80 */

void FUN_140003b80(undefined8 param_1,undefined1 *param_2,longlong param_3,uint param_4,uint param_5
                  )

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined1 *puVar6;
  
  if (0 < (int)param_4) {
    puVar6 = (undefined1 *)(param_3 + 2);
    uVar4 = (ulonglong)param_4;
    do {
      if (0 < (int)param_5) {
        puVar2 = puVar6;
        puVar3 = param_2;
        uVar5 = (ulonglong)param_5;
        do {
          puVar2[-2] = *puVar3;
          puVar2[-1] = *puVar3;
          uVar1 = *puVar3;
          puVar3 = puVar3 + (int)param_4;
          *puVar2 = uVar1;
          puVar2 = puVar2 + (int)(param_4 * 3);
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
      }
      param_2 = param_2 + 1;
      puVar6 = puVar6 + 3;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  return;
}



/* 140003b8d FUN_140003b8d */

void FUN_140003b8d(undefined8 param_1,undefined8 param_2,longlong param_3,undefined8 param_4,
                  undefined8 param_5,uint param_6)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  ulonglong unaff_RSI;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined1 *puVar6;
  undefined1 *in_R11;
  
  puVar6 = (undefined1 *)(param_3 + 2);
  uVar4 = unaff_RSI & 0xffffffff;
  do {
    if (0 < (int)param_6) {
      puVar2 = puVar6;
      puVar3 = in_R11;
      uVar5 = (ulonglong)param_6;
      do {
        puVar2[-2] = *puVar3;
        puVar2[-1] = *puVar3;
        uVar1 = *puVar3;
        puVar3 = puVar3 + unaff_RSI;
        *puVar2 = uVar1;
        puVar2 = puVar2 + (int)unaff_RSI * 3;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
    in_R11 = in_R11 + 1;
    puVar6 = puVar6 + 3;
    uVar4 = uVar4 - 1;
  } while (uVar4 != 0);
  return;
}



/* 140003bf9 FUN_140003bf9 */

void FUN_140003bf9(void)

{
  return;
}



/* 140003c00 FUN_140003c00 */

void FUN_140003c00(longlong param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined8 *puVar3;
  longlong lVar4;
  
  *(undefined4 *)(param_1 + 0x1b8) = *(undefined4 *)(param_1 + 0xa38);
  *(undefined8 *)(param_1 + 0x1b0) = 0;
  *(undefined4 *)(param_1 + 0x1bc) = *(undefined4 *)(param_1 + 0xa34);
  puVar1 = (undefined4 *)operator_new__(0x2c);
  *(undefined4 **)(param_1 + 0x1a8) = puVar1;
  *puVar1 = 0x28;
  *(undefined2 *)(*(longlong *)(param_1 + 0x1a8) + 0xc) = 1;
  *(undefined2 *)(*(longlong *)(param_1 + 0x1a8) + 0xe) = 0x18;
  *(undefined4 *)(*(longlong *)(param_1 + 0x1a8) + 0x10) = 0;
  *(int *)(*(longlong *)(param_1 + 0x1a8) + 0x14) =
       *(int *)(param_1 + 0xa34) * *(int *)(param_1 + 0xa38) * 3;
  *(undefined4 *)(*(longlong *)(param_1 + 0x1a8) + 0x18) = 0;
  *(undefined4 *)(*(longlong *)(param_1 + 0x1a8) + 0x1c) = 0;
  *(undefined4 *)(*(longlong *)(param_1 + 0x1a8) + 0x20) = 0;
  *(undefined4 *)(*(longlong *)(param_1 + 0x1a8) + 0x24) = 0;
  *(undefined4 *)(*(longlong *)(param_1 + 0x1a8) + 4) = *(undefined4 *)(param_1 + 0xa38);
  *(int *)(*(longlong *)(param_1 + 0x1a8) + 8) = -*(int *)(param_1 + 0xa34);
  pvVar2 = operator_new__((longlong)(*(int *)(param_1 + 0xa34) * *(int *)(param_1 + 0xa38)));
  *(void **)(param_1 + 0x1c0) = pvVar2;
  pvVar2 = operator_new__((longlong)(*(int *)(param_1 + 0xa34) * *(int *)(param_1 + 0xa38)));
  *(void **)(param_1 + 0x1c8) = pvVar2;
  *(undefined8 *)(param_1 + 0x1d0) = 0;
  pvVar2 = operator_new__((longlong)(*(int *)(param_1 + 0xa34) * *(int *)(param_1 + 0xa38)));
  *(void **)(param_1 + 0x1d0) = pvVar2;
  pvVar2 = operator_new__((longlong)(*(int *)(param_1 + 0xa34) * *(int *)(param_1 + 0xa38) * 3));
  *(void **)(param_1 + 0x1d8) = pvVar2;
  pvVar2 = operator_new__((longlong)(*(int *)(param_1 + 0xa34) * *(int *)(param_1 + 0xa38)));
  *(void **)(param_1 + 0x1e0) = pvVar2;
  pvVar2 = operator_new__((longlong)(*(int *)(param_1 + 0xa34) * *(int *)(param_1 + 0xa38)));
  *(void **)(param_1 + 0x1e8) = pvVar2;
  pvVar2 = operator_new__((longlong)(*(int *)(param_1 + 0xa34) * *(int *)(param_1 + 0xa38)));
  *(void **)(param_1 + 0x210) = pvVar2;
  pvVar2 = operator_new__((longlong)(*(int *)(param_1 + 0xa34) * *(int *)(param_1 + 0xa38)));
  *(void **)(param_1 + 0x218) = pvVar2;
  puVar3 = (undefined8 *)(param_1 + 0x1f0);
  lVar4 = 4;
  do {
    pvVar2 = operator_new__((longlong)(*(int *)(param_1 + 0xa34) * *(int *)(param_1 + 0xa38)));
    *puVar3 = pvVar2;
    puVar3 = puVar3 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  return;
}



/* 140003e30 FUN_140003e30 */

void FUN_140003e30(CWnd *param_1)

{
  CWnd *pCVar1;
  HDC pHVar2;
  CDC *pCVar3;
  undefined1 auStackY_a8 [32];
  tagRECT local_38;
  ulonglong local_28;
  
  local_28 = DAT_140013010 ^ (ulonglong)auStackY_a8;
  pCVar1 = CWnd::GetDlgItem(param_1,0x3ec);
  pHVar2 = GetDC(*(HWND *)(pCVar1 + 0x40));
  pCVar3 = CDC::FromHandle(pHVar2);
  GetClientRect(*(HWND *)(pCVar1 + 0x40),&local_38);
  if (pCVar3 == (CDC *)0x0) {
    pHVar2 = (HDC)0x0;
  }
  else {
    pHVar2 = *(HDC *)(pCVar3 + 8);
  }
  SetStretchBltMode(pHVar2,3);
  if (pCVar3 == (CDC *)0x0) {
    pHVar2 = (HDC)0x0;
  }
  else {
    pHVar2 = *(HDC *)(pCVar3 + 8);
  }
  StretchDIBits(pHVar2,0,0,local_38.right - local_38.left,local_38.bottom - local_38.top,0,0,
                *(int *)(param_1 + 0xa38),*(int *)(param_1 + 0xa34),*(void **)(param_1 + 0x1c0),
                *(BITMAPINFO **)(param_1 + 0x1a8),0,0xcc0020);
  ReleaseDC(*(HWND *)(pCVar1 + 0x40),*(HDC *)(pCVar3 + 8));
  __security_check_cookie(local_28 ^ (ulonglong)auStackY_a8);
  return;
}



/* 140003f60 FUN_140003f60 */

void FUN_140003f60(CWnd *param_1)

{
  CWnd *pCVar1;
  HDC hdc;
  HDC hdc_00;
  int SrcWidth;
  int iVar2;
  undefined1 auStackY_98 [32];
  void *lpBits;
  BITMAPINFO *lpbmi;
  tagRECT local_28;
  ulonglong local_18;
  
  local_18 = DAT_140013010 ^ (ulonglong)auStackY_98;
  pCVar1 = CWnd::GetDlgItem(param_1,0x3ec);
  GetClientRect(*(HWND *)(pCVar1 + 0x40),&local_28);
  hdc_00 = (HDC)0x0;
  hdc = hdc_00;
  if (*(longlong *)(param_1 + 0x188) != 0) {
    hdc = *(HDC *)(*(longlong *)(param_1 + 0x188) + 8);
  }
  SetStretchBltMode(hdc,3);
  iVar2 = *(int *)(param_1 + 0x180);
  *(undefined2 *)(*(longlong *)(param_1 + 0x1a8) + 0xe) = 0x18;
  if (iVar2 != 6) {
    if (iVar2 == 8) {
      *(undefined4 *)(*(longlong *)(param_1 + 0x1a8) + 4) = *(undefined4 *)(param_1 + 0x228);
      *(int *)(*(longlong *)(param_1 + 0x1a8) + 8) = -*(int *)(param_1 + 0x22c);
      if (*(longlong *)(param_1 + 0x188) != 0) {
        hdc_00 = *(HDC *)(*(longlong *)(param_1 + 0x188) + 8);
      }
      lpbmi = *(BITMAPINFO **)(param_1 + 0x1a8);
      lpBits = *(void **)(param_1 + 0x220);
      iVar2 = *(int *)(param_1 + 0x22c);
      SrcWidth = *(int *)(param_1 + 0x228);
      goto LAB_140004170;
    }
    if (iVar2 == 5) {
      *(int *)(*(longlong *)(param_1 + 0x1a8) + 4) =
           *(int *)(param_1 + 0x1b8) - *(int *)(param_1 + 0x1b0);
      *(int *)(*(longlong *)(param_1 + 0x1a8) + 8) =
           *(int *)(param_1 + 0x1b4) - *(int *)(param_1 + 0x1bc);
      if (*(longlong *)(param_1 + 0x188) != 0) {
        hdc_00 = *(HDC *)(*(longlong *)(param_1 + 0x188) + 8);
      }
      lpbmi = *(BITMAPINFO **)(param_1 + 0x1a8);
      iVar2 = *(int *)(param_1 + 0x1bc) - *(int *)(param_1 + 0x1b4);
      SrcWidth = *(int *)(param_1 + 0x1b8) - *(int *)(param_1 + 0x1b0);
      lpBits = *(void **)(param_1 + 0x220);
      goto LAB_140004170;
    }
  }
  *(undefined4 *)(*(longlong *)(param_1 + 0x1a8) + 4) = *(undefined4 *)(param_1 + 0xa38);
  *(int *)(*(longlong *)(param_1 + 0x1a8) + 8) = -*(int *)(param_1 + 0xa34);
  if (*(longlong *)(param_1 + 0x188) != 0) {
    hdc_00 = *(HDC *)(*(longlong *)(param_1 + 0x188) + 8);
  }
  lpbmi = *(BITMAPINFO **)(param_1 + 0x1a8);
  lpBits = *(void **)(param_1 + 0x1d8);
  iVar2 = *(int *)(param_1 + 0xa34);
  SrcWidth = *(int *)(param_1 + 0xa38);
LAB_140004170:
  StretchDIBits(hdc_00,0,0,local_28.right - local_28.left,local_28.bottom - local_28.top,0,0,
                SrcWidth,iVar2,lpBits,lpbmi,0,0xcc0020);
  __security_check_cookie(local_18 ^ (ulonglong)auStackY_98);
  return;
}



/* 1400041c0 FUN_1400041c0 */

void FUN_1400041c0(CWnd *param_1,longlong param_2)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  longlong lVar5;
  char cVar6;
  int iVar7;
  longlong lVar8;
  void *_Dst;
  void *pvVar9;
  longlong lVar10;
  uint uVar11;
  longlong lVar12;
  undefined1 *puVar13;
  byte *pbVar14;
  char *pcVar15;
  ulonglong uVar16;
  
  if (param_2 == 1) {
    iVar7 = *(int *)(param_1 + 0x180);
    if (iVar7 == 1) {
      KSJ_CaptureRawData(*(int *)(param_1 + 400) + -1,*(undefined8 *)(param_1 + 0x1c0));
      pvVar9 = *(void **)(param_1 + 0x1d0);
      memcpy(pvVar9,*(void **)(param_1 + 0x1c0),
             (longlong)(*(int *)(param_1 + 0xa34) * *(int *)(param_1 + 0xa38)));
      FUN_140003b80(pvVar9,*(undefined1 **)(param_1 + 0x1d0),*(longlong *)(param_1 + 0x1d8),
                    *(uint *)(param_1 + 0xa38),*(uint *)(param_1 + 0xa34));
      FUN_140003f60(param_1);
                    /* WARNING: Could not recover jumptable at 0x000140004249. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      CWnd::Default(param_1);
      return;
    }
    if (iVar7 == 2) {
      KSJ_CaptureRawData(*(int *)(param_1 + 400) + -1,*(undefined8 *)(param_1 + 0x1c0));
      uVar4 = *(uint *)(param_1 + 0xa34);
      uVar11 = *(uint *)(param_1 + 0xa38);
      lVar5 = *(longlong *)(param_1 + 0x1c8);
      lVar8 = *(longlong *)(param_1 + 0x1c0);
      puVar13 = *(undefined1 **)(param_1 + 0x1d0);
      if (0 < (int)(uVar4 * uVar11)) {
        lVar12 = 0;
        do {
          bVar2 = *(byte *)(lVar12 + lVar5);
          bVar3 = *(byte *)(lVar12 + lVar8);
          if (bVar2 < bVar3) {
            cVar6 = bVar3 - bVar2;
          }
          else {
            cVar6 = bVar2 - bVar3;
          }
          puVar13[lVar12] = (char)param_1[0xa3c] * cVar6;
          lVar12 = lVar12 + 1;
        } while (lVar12 < (int)(uVar4 * uVar11));
        uVar4 = *(uint *)(param_1 + 0xa34);
        uVar11 = *(uint *)(param_1 + 0xa38);
        puVar13 = *(undefined1 **)(param_1 + 0x1d0);
      }
      FUN_140003b80((ulonglong)uVar4,puVar13,*(longlong *)(param_1 + 0x1d8),uVar11,uVar4);
    }
    else {
      if (iVar7 == 3) {
        cVar6 = FUN_1400052b0((longlong)param_1);
        if (cVar6 == '\0') {
          *(undefined4 *)(param_1 + 0x180) = 1;
        }
        else {
          FUN_1400059a0((longlong)param_1);
          uVar11 = *(uint *)(param_1 + 0xa34);
          iVar7 = *(int *)(param_1 + 0xa38);
          lVar8 = (longlong)iVar7;
          lVar5 = *(longlong *)(param_1 + 0x1e8);
          pvVar9 = *(void **)(param_1 + 0x1e0);
          if (0 < (int)uVar11) {
            lVar12 = 0;
            uVar16 = (ulonglong)uVar11;
            do {
              if (0 < lVar8) {
                pbVar14 = (byte *)(lVar12 + lVar5);
                lVar10 = lVar8;
                pcVar15 = (char *)((longlong)pvVar9 + lVar12);
                do {
                  pbVar1 = pbVar14 + ((longlong)pvVar9 - lVar5);
                  cVar6 = *pbVar1 - *pbVar14;
                  bVar2 = *pbVar14;
                  pbVar14 = pbVar14 + 1;
                  if (*pbVar1 < bVar2) {
                    cVar6 = cVar6 + -1;
                  }
                  *pcVar15 = cVar6;
                  lVar10 = lVar10 + -1;
                  pcVar15 = pcVar15 + 1;
                } while (lVar10 != 0);
              }
              lVar12 = lVar12 + lVar8;
              uVar16 = uVar16 - 1;
            } while (uVar16 != 0);
            iVar7 = *(int *)(param_1 + 0xa38);
            uVar11 = *(uint *)(param_1 + 0xa34);
            pvVar9 = *(void **)(param_1 + 0x1e0);
          }
          _Dst = *(void **)(param_1 + 0x1d0);
          memcpy(_Dst,pvVar9,(longlong)(int)(uVar11 * iVar7));
          FUN_140003b80(_Dst,*(undefined1 **)(param_1 + 0x1d0),*(longlong *)(param_1 + 0x1d8),
                        *(uint *)(param_1 + 0xa38),*(uint *)(param_1 + 0xa34));
          FUN_140003f60(param_1);
        }
        goto FUN_1400044d8;
      }
      if (iVar7 == 4) {
        pvVar9 = *(void **)(param_1 + 0x1d0);
        memcpy(pvVar9,*(void **)(param_1 + 0x210),
               (longlong)(*(int *)(param_1 + 0xa34) * *(int *)(param_1 + 0xa38)));
        FUN_140003b80(pvVar9,*(undefined1 **)(param_1 + 0x1d0),*(longlong *)(param_1 + 0x1d8),
                      *(uint *)(param_1 + 0xa38),*(uint *)(param_1 + 0xa34));
      }
      else if (iVar7 == 5) {
        FUN_140003b80(param_1,*(undefined1 **)(param_1 + 0x218),*(longlong *)(param_1 + 0x220),
                      *(uint *)(param_1 + 0x228),*(uint *)(param_1 + 0x22c));
      }
      else if (2 < iVar7 - 6U) goto FUN_1400044d8;
    }
    FUN_140003f60(param_1);
  }
FUN_1400044d8:
                    /* WARNING: Could not recover jumptable at 0x0001400044e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CWnd::Default(param_1);
  return;
}



/* 140004250 FUN_140004250 */

void FUN_140004250(CWnd *param_1)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  longlong lVar5;
  int in_EAX;
  char cVar6;
  int iVar7;
  longlong lVar8;
  void *_Dst;
  void *pvVar9;
  CWnd *unaff_RBX;
  longlong lVar10;
  uint uVar11;
  longlong lVar12;
  undefined1 *puVar13;
  byte *pbVar14;
  char *pcVar15;
  ulonglong uVar16;
  
  if (in_EAX == 2) {
    KSJ_CaptureRawData(*(int *)(param_1 + 400) + -1,*(undefined8 *)(unaff_RBX + 0x1c0));
    uVar4 = *(uint *)(unaff_RBX + 0xa34);
    uVar11 = *(uint *)(unaff_RBX + 0xa38);
    lVar5 = *(longlong *)(unaff_RBX + 0x1c8);
    lVar8 = *(longlong *)(unaff_RBX + 0x1c0);
    puVar13 = *(undefined1 **)(unaff_RBX + 0x1d0);
    if (0 < (int)(uVar4 * uVar11)) {
      lVar12 = 0;
      do {
        bVar2 = *(byte *)(lVar12 + lVar5);
        bVar3 = *(byte *)(lVar12 + lVar8);
        if (bVar2 < bVar3) {
          cVar6 = bVar3 - bVar2;
        }
        else {
          cVar6 = bVar2 - bVar3;
        }
        puVar13[lVar12] = (char)unaff_RBX[0xa3c] * cVar6;
        lVar12 = lVar12 + 1;
      } while (lVar12 < (int)(uVar4 * uVar11));
      uVar4 = *(uint *)(unaff_RBX + 0xa34);
      uVar11 = *(uint *)(unaff_RBX + 0xa38);
      puVar13 = *(undefined1 **)(unaff_RBX + 0x1d0);
    }
    FUN_140003b80((ulonglong)uVar4,puVar13,*(longlong *)(unaff_RBX + 0x1d8),uVar11,uVar4);
    param_1 = unaff_RBX;
  }
  else {
    if (in_EAX == 3) {
      cVar6 = FUN_1400052b0((longlong)param_1);
      if (cVar6 == '\0') {
        *(undefined4 *)(unaff_RBX + 0x180) = 1;
      }
      else {
        FUN_1400059a0((longlong)unaff_RBX);
        uVar11 = *(uint *)(unaff_RBX + 0xa34);
        iVar7 = *(int *)(unaff_RBX + 0xa38);
        lVar8 = (longlong)iVar7;
        lVar5 = *(longlong *)(unaff_RBX + 0x1e8);
        pvVar9 = *(void **)(unaff_RBX + 0x1e0);
        if (0 < (int)uVar11) {
          lVar12 = 0;
          uVar16 = (ulonglong)uVar11;
          do {
            if (0 < lVar8) {
              pbVar14 = (byte *)(lVar12 + lVar5);
              lVar10 = lVar8;
              pcVar15 = (char *)((longlong)pvVar9 + lVar12);
              do {
                pbVar1 = pbVar14 + ((longlong)pvVar9 - lVar5);
                cVar6 = *pbVar1 - *pbVar14;
                bVar2 = *pbVar14;
                pbVar14 = pbVar14 + 1;
                if (*pbVar1 < bVar2) {
                  cVar6 = cVar6 + -1;
                }
                *pcVar15 = cVar6;
                lVar10 = lVar10 + -1;
                pcVar15 = pcVar15 + 1;
              } while (lVar10 != 0);
            }
            lVar12 = lVar12 + lVar8;
            uVar16 = uVar16 - 1;
          } while (uVar16 != 0);
          iVar7 = *(int *)(unaff_RBX + 0xa38);
          uVar11 = *(uint *)(unaff_RBX + 0xa34);
          pvVar9 = *(void **)(unaff_RBX + 0x1e0);
        }
        _Dst = *(void **)(unaff_RBX + 0x1d0);
        memcpy(_Dst,pvVar9,(longlong)(int)(uVar11 * iVar7));
        FUN_140003b80(_Dst,*(undefined1 **)(unaff_RBX + 0x1d0),*(longlong *)(unaff_RBX + 0x1d8),
                      *(uint *)(unaff_RBX + 0xa38),*(uint *)(unaff_RBX + 0xa34));
        FUN_140003f60(unaff_RBX);
      }
      goto LAB_1400044d3;
    }
    if (in_EAX == 4) {
      pvVar9 = *(void **)(param_1 + 0x1d0);
      memcpy(pvVar9,*(void **)(param_1 + 0x210),
             (longlong)(*(int *)(param_1 + 0xa34) * *(int *)(param_1 + 0xa38)));
      FUN_140003b80(pvVar9,*(undefined1 **)(unaff_RBX + 0x1d0),*(longlong *)(unaff_RBX + 0x1d8),
                    *(uint *)(unaff_RBX + 0xa38),*(uint *)(unaff_RBX + 0xa34));
      param_1 = unaff_RBX;
    }
    else if (in_EAX == 5) {
      FUN_140003b80(param_1,*(undefined1 **)(param_1 + 0x218),*(longlong *)(param_1 + 0x220),
                    *(uint *)(param_1 + 0x228),*(uint *)(param_1 + 0x22c));
      param_1 = unaff_RBX;
    }
    else if (2 < in_EAX - 6U) goto LAB_1400044d3;
  }
  FUN_140003f60(param_1);
LAB_1400044d3:
                    /* WARNING: Could not recover jumptable at 0x0001400044e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CWnd::Default(unaff_RBX);
  return;
}



/* 140004329 FUN_140004329 */

void FUN_140004329(void)

{
  byte *pbVar1;
  byte bVar2;
  longlong lVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  longlong lVar7;
  void *_Dst;
  CWnd *unaff_RBX;
  longlong lVar8;
  longlong lVar9;
  byte *pbVar10;
  char *pcVar11;
  ulonglong uVar12;
  void *_Src;
  
  FUN_1400059a0((longlong)unaff_RBX);
  uVar5 = *(uint *)(unaff_RBX + 0xa34);
  iVar6 = *(int *)(unaff_RBX + 0xa38);
  lVar7 = (longlong)iVar6;
  lVar3 = *(longlong *)(unaff_RBX + 0x1e8);
  _Src = *(void **)(unaff_RBX + 0x1e0);
  if (0 < (int)uVar5) {
    lVar9 = 0;
    uVar12 = (ulonglong)uVar5;
    do {
      if (0 < lVar7) {
        pbVar10 = (byte *)(lVar9 + lVar3);
        lVar8 = lVar7;
        pcVar11 = (char *)((longlong)_Src + lVar9);
        do {
          pbVar1 = pbVar10 + ((longlong)_Src - lVar3);
          cVar4 = *pbVar1 - *pbVar10;
          bVar2 = *pbVar10;
          pbVar10 = pbVar10 + 1;
          if (*pbVar1 < bVar2) {
            cVar4 = cVar4 + -1;
          }
          *pcVar11 = cVar4;
          lVar8 = lVar8 + -1;
          pcVar11 = pcVar11 + 1;
        } while (lVar8 != 0);
      }
      lVar9 = lVar9 + lVar7;
      uVar12 = uVar12 - 1;
    } while (uVar12 != 0);
    iVar6 = *(int *)(unaff_RBX + 0xa38);
    uVar5 = *(uint *)(unaff_RBX + 0xa34);
    _Src = *(void **)(unaff_RBX + 0x1e0);
  }
  _Dst = *(void **)(unaff_RBX + 0x1d0);
  memcpy(_Dst,_Src,(longlong)(int)(uVar5 * iVar6));
  FUN_140003b80(_Dst,*(undefined1 **)(unaff_RBX + 0x1d0),*(longlong *)(unaff_RBX + 0x1d8),
                *(uint *)(unaff_RBX + 0xa38),*(uint *)(unaff_RBX + 0xa34));
  FUN_140003f60(unaff_RBX);
                    /* WARNING: Could not recover jumptable at 0x0001400044e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CWnd::Default(unaff_RBX);
  return;
}



/* 14000435e FUN_14000435e */

void FUN_14000435e(longlong param_1)

{
  byte *pbVar1;
  byte bVar2;
  char cVar3;
  uint in_EAX;
  void *_Dst;
  CWnd *unaff_RBX;
  longlong lVar4;
  longlong lVar5;
  byte *pbVar6;
  char *pcVar7;
  longlong unaff_R12;
  ulonglong uVar8;
  longlong unaff_R15;
  
  lVar5 = 0;
  uVar8 = (ulonglong)in_EAX;
  do {
    if (0 < param_1) {
      pbVar6 = (byte *)(lVar5 + unaff_R12);
      lVar4 = param_1;
      pcVar7 = (char *)(unaff_R15 + lVar5);
      do {
        pbVar1 = pbVar6 + (unaff_R15 - unaff_R12);
        cVar3 = *pbVar1 - *pbVar6;
        bVar2 = *pbVar6;
        pbVar6 = pbVar6 + 1;
        if (*pbVar1 < bVar2) {
          cVar3 = cVar3 + -1;
        }
        *pcVar7 = cVar3;
        lVar4 = lVar4 + -1;
        pcVar7 = pcVar7 + 1;
      } while (lVar4 != 0);
    }
    lVar5 = lVar5 + param_1;
    uVar8 = uVar8 - 1;
  } while (uVar8 != 0);
  _Dst = *(void **)(unaff_RBX + 0x1d0);
  memcpy(_Dst,*(void **)(unaff_RBX + 0x1e0),
         (longlong)(*(int *)(unaff_RBX + 0xa34) * *(int *)(unaff_RBX + 0xa38)));
  FUN_140003b80(_Dst,*(undefined1 **)(unaff_RBX + 0x1d0),*(longlong *)(unaff_RBX + 0x1d8),
                *(uint *)(unaff_RBX + 0xa38),*(uint *)(unaff_RBX + 0xa34));
  FUN_140003f60(unaff_RBX);
                    /* WARNING: Could not recover jumptable at 0x0001400044e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CWnd::Default(unaff_RBX);
  return;
}



/* 1400043e8 FUN_1400043e8 */

void FUN_1400043e8(int param_1)

{
  int in_EAX;
  void *_Dst;
  CWnd *unaff_RBX;
  void *unaff_R15;
  
  _Dst = *(void **)(unaff_RBX + 0x1d0);
  memcpy(_Dst,unaff_R15,(longlong)(in_EAX * param_1));
  FUN_140003b80(_Dst,*(undefined1 **)(unaff_RBX + 0x1d0),*(longlong *)(unaff_RBX + 0x1d8),
                *(uint *)(unaff_RBX + 0xa38),*(uint *)(unaff_RBX + 0xa34));
  FUN_140003f60(unaff_RBX);
                    /* WARNING: Could not recover jumptable at 0x0001400044e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CWnd::Default(unaff_RBX);
  return;
}



/* 140004438 FUN_140004438 */

void FUN_140004438(void)

{
  CWnd *unaff_RBX;
  
  *(undefined4 *)(unaff_RBX + 0x180) = 1;
                    /* WARNING: Could not recover jumptable at 0x0001400044e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CWnd::Default(unaff_RBX);
  return;
}



/* 1400044d8 FUN_1400044d8 */

void FUN_1400044d8(void)

{
  CWnd *unaff_RBX;
  
                    /* WARNING: Could not recover jumptable at 0x0001400044e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CWnd::Default(unaff_RBX);
  return;
}



/* 1400044f0 FUN_1400044f0 */

void FUN_1400044f0(CWnd *param_1)

{
  CWnd *pCVar1;
  
  pCVar1 = CWnd::GetDlgItem(param_1,0x3f8);
  CWnd::EnableWindow(pCVar1,1);
  pCVar1 = CWnd::GetDlgItem(param_1,0x3f4);
  CWnd::EnableWindow(pCVar1,1);
  pCVar1 = CWnd::GetDlgItem(param_1,0x3f5);
  CWnd::EnableWindow(pCVar1,1);
  pCVar1 = CWnd::GetDlgItem(param_1,0x3f6);
  CWnd::EnableWindow(pCVar1,1);
  pCVar1 = CWnd::GetDlgItem(param_1,0x3f7);
  CWnd::EnableWindow(pCVar1,1);
  pCVar1 = CWnd::GetDlgItem(param_1,0x3f1);
  CWnd::EnableWindow(pCVar1,1);
  KSJ_SetParam(*(int *)(param_1 + 400) + -1,0xb);
  *(undefined4 *)(param_1 + 0x180) = 1;
                    /* WARNING: Could not recover jumptable at 0x0001400045d1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetTimer(*(HWND *)(param_1 + 0x40),1,100,(TIMERPROC)0x0);
  return;
}



/* 1400045e0 FUN_1400045e0 */

void FUN_1400045e0(longlong param_1)

{
  KSJ_UnInit();
  FUN_140008280(param_1);
                    /* WARNING: Subroutine does not return */
  exit(0);
}



/* 140004600 FUN_140004600 */

void FUN_140004600(CWnd *param_1,undefined8 param_2,undefined8 *param_3)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined1 auStack_48 [32];
  char local_28 [16];
  ulonglong local_18;
  
  local_18 = DAT_140013010 ^ (ulonglong)auStack_48;
  uVar2 = 0;
  uVar1 = SendMessageA(*(HWND *)(param_1 + 0xb70),0x400,0,0);
  KSJ_SetParam(*(int *)(param_1 + 400) + -1,0,uVar1 & 0xffffffff);
  FUN_140007140(local_28,&DAT_14000dac8,uVar1 & 0xffffffff,uVar2);
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_1 + 0xc18),local_28);
  CWnd::UpdateData(param_1,0);
  *param_3 = 0;
  __security_check_cookie(local_18 ^ (ulonglong)auStack_48);
  return;
}



/* 1400046b0 FUN_1400046b0 */

void FUN_1400046b0(CWnd *param_1,undefined8 param_2,undefined8 *param_3)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined1 auStack_48 [32];
  char local_28 [16];
  ulonglong local_18;
  
  local_18 = DAT_140013010 ^ (ulonglong)auStack_48;
  uVar2 = 0;
  uVar1 = SendMessageA(*(HWND *)(param_1 + 0xc60),0x400,0,0);
  KSJ_SetParam(*(int *)(param_1 + 400) + -1,0x10,uVar1 & 0xff);
  FUN_140007140(local_28,&DAT_14000dac8,uVar1 & 0xff,uVar2);
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_1 + 0xd08),local_28);
  CWnd::UpdateData(param_1,0);
  *param_3 = 0;
  __security_check_cookie(local_18 ^ (ulonglong)auStack_48);
  return;
}



/* 140004760 FUN_140004760 */

void FUN_140004760(CWnd *param_1,undefined8 param_2,undefined8 *param_3)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined1 auStack_48 [32];
  char local_28 [16];
  ulonglong local_18;
  
  local_18 = DAT_140013010 ^ (ulonglong)auStack_48;
  uVar2 = 0;
  uVar1 = SendMessageA(*(HWND *)(param_1 + 0x1130),0x400,0,0);
  *(int *)(param_1 + 0xa3c) = (int)(uVar1 & 0xff);
  FUN_140007140(local_28,&DAT_14000dac8,uVar1 & 0xff,uVar2);
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_1 + 0x11d8),local_28);
  CWnd::UpdateData(param_1,0);
  *param_3 = 0;
  __security_check_cookie(local_18 ^ (ulonglong)auStack_48);
  return;
}



/* 1400047f0 FUN_1400047f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400047f0(CWnd *param_1)

{
  __int64 _Var1;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar2;
  CWnd *pCVar3;
  ulonglong uVar4;
  longlong lVar5;
  int iVar6;
  undefined1 *puVar7;
  uint uVar8;
  uint uVar9;
  undefined1 *puVar10;
  int iVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  void *pvVar14;
  ulonglong uVar15;
  undefined1 auStackY_4b8 [32];
  char *local_468;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> local_460 [8];
  longlong local_458 [2];
  int local_448;
  void *local_438;
  undefined8 local_430;
  HGDIOBJ local_428;
  uint local_41c;
  uint local_418;
  undefined8 local_408;
  CFileDialog local_3f8 [912];
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined2 local_40;
  ulonglong local_38;
  
  local_408 = 0xfffffffffffffffe;
  local_38 = DAT_140013010 ^ (ulonglong)auStackY_4b8;
  KillTimer(*(HWND *)(param_1 + 0x40),1);
  local_68 = _DAT_14000d760;
  uStack_60 = _UNK_14000d768;
  local_58 = _DAT_14000d770;
  uStack_50 = _UNK_14000d778;
  local_48 = DAT_14000d780;
  local_40 = DAT_14000d788;
  uVar15 = 0;
  CFileDialog::CFileDialog(local_3f8,1,"bmp",(char *)0x0,0,(char *)&local_68,param_1,0,1);
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)&local_468
             ,"This is the string A,This is the string B.");
  _Var1 = CFileDialog::DoModal(local_3f8);
  if (_Var1 == 1) {
    pCVar2 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             CFileDialog::GetPathName(local_3f8);
    ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               &local_468,pCVar2);
    ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>(local_460);
  }
  local_438 = (void *)0x0;
  local_458[1] = 0;
  local_458[0] = 0;
  local_430 = 0;
  local_428 = (HGDIOBJ)0x0;
  FUN_140009660(local_458,local_468);
  pvVar14 = local_438;
  if (local_448 == 8) {
    uVar8 = 0;
    if (*(int *)(param_1 + 0x178) == 0) {
      uVar9 = local_41c;
      if (local_438 == (void *)0x0) {
        uVar9 = uVar8;
      }
      *(uint *)(param_1 + 0xa38) = uVar9;
      uVar9 = uVar8;
      if ((local_438 != (void *)0x0) && (uVar9 = local_418, (int)local_418 < 0)) {
        uVar9 = -local_418;
      }
      *(uint *)(param_1 + 0xa34) = uVar9;
      FUN_140003c00((longlong)param_1);
    }
    uVar13 = (ulonglong)local_41c;
    if (pvVar14 == (void *)0x0) {
      uVar13 = uVar15;
    }
    iVar6 = (int)uVar13;
    *(int *)(param_1 + 0xa38) = iVar6;
    if ((pvVar14 == (void *)0x0) || (uVar8 = local_418, -1 < (int)local_418)) {
      *(uint *)(param_1 + 0xa34) = uVar8;
      uVar4 = uVar15;
      if (0 < iVar6) {
        do {
          iVar11 = (int)uVar4;
          uVar4 = uVar15;
          if (0 < (int)uVar8) {
            do {
              iVar6 = (int)uVar4;
              *(undefined1 *)
               ((longlong)(*(int *)(param_1 + 0xa38) * iVar6 + iVar11) +
               *(longlong *)(param_1 + 0x1c0)) =
                   *(undefined1 *)
                    (((*(int *)(param_1 + 0xa34) - iVar6) * *(int *)(param_1 + 0xa38) + iVar11) +
                    local_458[0]);
              uVar4 = (ulonglong)(iVar6 + 1U);
              uVar8 = *(uint *)(param_1 + 0xa34);
            } while ((int)(iVar6 + 1U) < (int)uVar8);
            uVar13 = (ulonglong)*(uint *)(param_1 + 0xa38);
          }
          iVar6 = (int)uVar13;
          uVar4 = (ulonglong)(iVar11 + 1U);
        } while ((int)(iVar11 + 1U) < iVar6);
      }
    }
    else {
      uVar8 = -local_418;
      *(uint *)(param_1 + 0xa34) = uVar8;
      uVar4 = uVar15;
      if (0 < iVar6) {
        do {
          uVar12 = uVar15;
          if (0 < (int)uVar8) {
            do {
              lVar5 = (longlong)(*(int *)(param_1 + 0xa38) * (int)uVar12 + (int)uVar4);
              *(undefined1 *)(lVar5 + *(longlong *)(param_1 + 0x1c0)) =
                   *(undefined1 *)(lVar5 + local_458[0]);
              uVar9 = (int)uVar12 + 1;
              uVar8 = *(uint *)(param_1 + 0xa34);
              uVar12 = (ulonglong)uVar9;
            } while ((int)uVar9 < (int)uVar8);
            uVar13 = (ulonglong)*(uint *)(param_1 + 0xa38);
          }
          uVar9 = (int)uVar4 + 1;
          iVar6 = (int)uVar13;
          uVar4 = (ulonglong)uVar9;
        } while ((int)uVar9 < iVar6);
      }
    }
    memcpy(*(void **)(param_1 + 0x1e0),*(void **)(param_1 + 0x1c0),(longlong)(int)(uVar8 * iVar6));
    memcpy(*(void **)(param_1 + 0x210),*(void **)(param_1 + 0x1c0),
           (longlong)(*(int *)(param_1 + 0xa38) * *(int *)(param_1 + 0xa34)));
    memcpy(*(void **)(param_1 + 0x218),*(void **)(param_1 + 0x1c0),
           (longlong)(*(int *)(param_1 + 0xa38) * *(int *)(param_1 + 0xa34)));
    *(undefined8 *)(param_1 + 0x1b0) = 0;
    *(undefined4 *)(param_1 + 0x1b8) = *(undefined4 *)(param_1 + 0xa38);
    *(undefined4 *)(param_1 + 0x1bc) = *(undefined4 *)(param_1 + 0xa34);
    pCVar3 = CWnd::GetDlgItem(param_1,0x3f5);
    CWnd::EnableWindow(pCVar3,1);
    pCVar3 = CWnd::GetDlgItem(param_1,0x3f6);
    CWnd::EnableWindow(pCVar3,1);
    pCVar3 = CWnd::GetDlgItem(param_1,0x3f7);
    CWnd::EnableWindow(pCVar3,1);
    memcpy(*(void **)(param_1 + 0x1d0),*(void **)(param_1 + 0x1c0),
           (longlong)(*(int *)(param_1 + 0xa38) * *(int *)(param_1 + 0xa34)));
    uVar8 = *(uint *)(param_1 + 0xa34);
    uVar9 = *(uint *)(param_1 + 0xa38);
    lVar5 = *(longlong *)(param_1 + 0x1d8);
    puVar7 = *(undefined1 **)(param_1 + 0x1d0);
    if (0 < (int)uVar9) {
      uVar13 = (ulonglong)uVar9;
      do {
        if (0 < (int)uVar8) {
          uVar4 = uVar15;
          puVar10 = puVar7;
          uVar12 = (ulonglong)uVar8;
          do {
            *(undefined1 *)(uVar4 + lVar5) = *puVar10;
            *(undefined1 *)(lVar5 + 1 + uVar4) = *puVar10;
            *(undefined1 *)(uVar4 + 2 + lVar5) = *puVar10;
            uVar4 = uVar4 + (longlong)(int)(uVar9 * 3);
            puVar10 = puVar10 + (int)uVar9;
            uVar12 = uVar12 - 1;
          } while (uVar12 != 0);
        }
        uVar15 = uVar15 + 3;
        puVar7 = puVar7 + 1;
        uVar13 = uVar13 - 1;
        pvVar14 = local_438;
      } while (uVar13 != 0);
    }
    *(undefined4 *)(param_1 + 0x180) = 7;
    SetTimer(*(HWND *)(param_1 + 0x40),1,100,(TIMERPROC)0x0);
  }
  else {
    CWnd::MessageBoxA(param_1,&DAT_14000d7c0,(char *)0x0,0);
  }
  if (pvVar14 != (void *)0x0) {
    operator_delete__(pvVar14);
  }
  if (local_428 != (HGDIOBJ)0x0) {
    DeleteObject(local_428);
  }
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)&local_468
            );
  CFileDialog::~CFileDialog(local_3f8);
  __security_check_cookie(local_38 ^ (ulonglong)auStackY_4b8);
  return;
}



/* 140004c90 FUN_140004c90 */

void FUN_140004c90(CWnd *param_1)

{
  tagOFNA *ptVar1;
  __int64 _Var2;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar3;
  void *pvVar4;
  undefined1 auStackY_418 [32];
  int iVar5;
  int iVar6;
  char *local_3c8;
  char *local_3c0;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> local_3b8 [8];
  undefined8 local_3b0;
  CFileDialog local_3a8 [912];
  ulonglong local_18;
  
  local_3b0 = 0xfffffffffffffffe;
  local_18 = DAT_140013010 ^ (ulonglong)auStackY_418;
  KillTimer(*(HWND *)(param_1 + 0x40),1);
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)&local_3c0
             ,"This is the string A,This is the string B.");
  if (*(int *)(param_1 + 0x180) == 5) {
    ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               &local_3c8);
    ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::Format
              ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               &local_3c8,"Unwrap_%.3f",(double)*(float *)(param_1 + 0xa40));
    ATL::CSimpleStringT<char,1>::SetAt
              ((CSimpleStringT<char,1> *)&local_3c8,*(int *)(local_3c8 + -0x10) + -4,'_');
    CFileDialog::CFileDialog(local_3a8,0,"bmp",local_3c8,6,(char *)0x0,(CWnd *)0x0,0,1);
    ptVar1 = CFileDialog::GetOFN(local_3a8);
    *(undefined **)(ptVar1 + 0x18) = &DAT_14000d7f0;
    _Var2 = CFileDialog::DoModal(local_3a8);
    if (_Var2 == 1) {
      pCVar3 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               CFileDialog::GetPathName(local_3a8);
      ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 &local_3c0,pCVar3);
      ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>(local_3b8);
      FUN_1400050b0(param_1,local_3c0,*(void **)(param_1 + 0x218),
                    *(int *)(param_1 + 0x1b8) - *(int *)(param_1 + 0x1b0),
                    *(int *)(param_1 + 0x1bc) - *(int *)(param_1 + 0x1b4),8);
    }
    CFileDialog::~CFileDialog(local_3a8);
    ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               &local_3c8);
  }
  else if (*(int *)(param_1 + 0x180) == 8) {
    ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               &local_3c8);
    ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::Format
              ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               &local_3c8,"UnwrapJet_%.3f",(double)*(float *)(param_1 + 0xa40));
    ATL::CSimpleStringT<char,1>::SetAt
              ((CSimpleStringT<char,1> *)&local_3c8,*(int *)(local_3c8 + -0x10) + -4,'_');
    CFileDialog::CFileDialog(local_3a8,0,"bmp",local_3c8,6,(char *)0x0,(CWnd *)0x0,0,1);
    ptVar1 = CFileDialog::GetOFN(local_3a8);
    *(undefined **)(ptVar1 + 0x18) = &DAT_14000d7f0;
    _Var2 = CFileDialog::DoModal(local_3a8);
    if (_Var2 == 1) {
      pCVar3 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               CFileDialog::GetPathName(local_3a8);
      ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 &local_3c0,pCVar3);
      ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>(local_3b8);
      FUN_1400050b0(param_1,local_3c0,*(void **)(param_1 + 0x220),
                    *(int *)(param_1 + 0x1b8) - *(int *)(param_1 + 0x1b0),
                    *(int *)(param_1 + 0x1bc) - *(int *)(param_1 + 0x1b4),0x18);
    }
    CFileDialog::~CFileDialog(local_3a8);
    ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               &local_3c8);
  }
  else {
    CFileDialog::CFileDialog(local_3a8,0,"bmp",(char *)0x0,6,(char *)0x0,(CWnd *)0x0,0,1);
    ptVar1 = CFileDialog::GetOFN(local_3a8);
    *(undefined **)(ptVar1 + 0x18) = &DAT_14000d7f0;
    _Var2 = CFileDialog::DoModal(local_3a8);
    if (_Var2 == 1) {
      pCVar3 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               CFileDialog::GetPathName(local_3a8);
      ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 &local_3c0,pCVar3);
      ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>(local_3b8);
      if (((*(int *)(param_1 + 0x180) == 6) ||
          (*(int *)(param_1 + 0x1b8) - *(int *)(param_1 + 0x1b0) != *(int *)(param_1 + 0xa38))) ||
         (iVar5 = *(int *)(param_1 + 0xa34),
         *(int *)(param_1 + 0x1bc) - *(int *)(param_1 + 0x1b4) != iVar5)) {
        iVar6 = 0x18;
        iVar5 = *(int *)(param_1 + 0xa34);
        pvVar4 = *(void **)(param_1 + 0x1d8);
      }
      else {
        iVar6 = 8;
        pvVar4 = *(void **)(param_1 + 0x1d0);
      }
      FUN_1400050b0(param_1,local_3c0,pvVar4,*(int *)(param_1 + 0xa38),iVar5,iVar6);
    }
    CFileDialog::~CFileDialog(local_3a8);
  }
  SetTimer(*(HWND *)(param_1 + 0x40),1,100,(TIMERPROC)0x0);
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)&local_3c0
            );
  __security_check_cookie(local_18 ^ (ulonglong)auStackY_418);
  return;
}



/* 1400050b0 FUN_1400050b0 */

void FUN_1400050b0(CWnd *param_1,char *param_2,void *param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined1 auStack_c8 [32];
  CFile local_a8 [40];
  undefined8 local_80;
  undefined2 local_70;
  int local_6e;
  undefined4 local_6a;
  undefined4 local_66;
  undefined4 local_60;
  int local_5c;
  int local_58;
  undefined2 local_54;
  undefined2 local_52;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_80 = 0xfffffffffffffffe;
  local_38 = DAT_140013010 ^ (ulonglong)auStack_c8;
  if ((param_4 < 0) || (param_5 < 0)) {
    pcVar3 = &DAT_14000d830;
  }
  else if (param_3 == (void *)0x0) {
    pcVar3 = &DAT_14000d840;
  }
  else {
    if ((param_6 - 8U & 0xffffffef) == 0) {
      iVar1 = (int)(param_4 * param_6 + (param_4 * param_6 >> 0x1f & 7U)) >> 3;
      local_6e = iVar1 * param_5 + 0x436;
      local_70 = 0x4d42;
      local_6a = 0;
      local_66 = 0x436;
      local_60 = 0x28;
      local_58 = -param_5;
      local_54 = 1;
      local_52 = (undefined2)param_6;
      local_50 = 0;
      local_48 = 0;
      local_40 = 0;
      local_5c = param_4;
      CFile::CFile(local_a8);
      iVar2 = CFile::Open(local_a8,param_2,0x1012,(CFileException *)0x0);
      if (iVar2 == 0) {
        CWnd::MessageBoxA(param_1,&DAT_14000d880,(char *)0x0,0);
        CFile::~CFile(local_a8);
      }
      else {
        CFile::Write(local_a8,&local_70,0xe);
        CFile::Write(local_a8,&local_60,0x28);
        CFile::Write(local_a8,&DAT_140013f40,0x400);
        iVar1 = iVar1 + 3;
        CFile::Write(local_a8,param_3,((int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2) * param_5 * 4);
        CFile::~CFile(local_a8);
      }
      goto LAB_140005287;
    }
    pcVar3 = &DAT_14000d858;
  }
  CWnd::MessageBoxA(param_1,pcVar3,(char *)0x0,0);
LAB_140005287:
  __security_check_cookie(local_38 ^ (ulonglong)auStack_c8);
  return;
}



/* 1400052b0 FUN_1400052b0 */

void FUN_1400052b0(longlong param_1)

{
  longlong lVar1;
  char cVar2;
  undefined8 uVar3;
  uint uVar4;
  longlong lVar5;
  longlong lVar6;
  undefined1 auStackY_728 [32];
  DWORD local_6f8 [2];
  HKEY local_6f0;
  undefined8 local_6e8;
  undefined **local_6d8;
  uint local_6d0;
  HANDLE local_6c8;
  uint local_6c0;
  CHAR local_6bc [68];
  _RTL_CRITICAL_SECTION local_678;
  _DCB local_650;
  undefined8 local_620;
  undefined **local_618;
  undefined8 local_610;
  undefined8 local_608;
  undefined4 local_600;
  undefined4 local_5fc;
  _RTL_CRITICAL_SECTION local_5f8;
  undefined **local_5d0;
  undefined8 local_5c8;
  undefined8 local_5c0;
  undefined4 local_5b8;
  undefined4 local_5b4;
  _RTL_CRITICAL_SECTION local_5b0;
  undefined8 local_588;
  undefined4 local_57c;
  undefined8 local_578;
  undefined4 local_570;
  HANDLE local_568;
  undefined8 local_560;
  undefined4 local_558;
  HANDLE local_550;
  undefined8 local_548;
  undefined4 local_540;
  HANDLE local_538;
  undefined8 local_530;
  undefined8 local_528;
  undefined1 local_520 [24];
  HANDLE local_508;
  HANDLE local_4e8;
  HANDLE local_4c8;
  undefined8 local_4b8;
  undefined1 local_4b0;
  undefined1 local_4af;
  undefined8 local_4a8;
  undefined1 local_4a0;
  undefined1 local_49f;
  undefined8 local_498;
  undefined1 local_490;
  undefined1 local_48f;
  undefined8 local_488;
  undefined1 local_480;
  undefined1 local_47f;
  BYTE local_478 [6];
  char local_472;
  undefined1 local_428 [1024];
  ulonglong local_28;
  
  local_6e8 = 0xfffffffffffffffe;
  local_28 = DAT_140013010 ^ (ulonglong)auStackY_728;
  local_6d8 = CnComm::vftable;
  local_618 = CnComm::BlockBuffer::vftable;
  InitializeCriticalSection(&local_5f8);
  local_600 = 0;
  local_608 = 0;
  local_610 = 0;
  local_5fc = 0x400;
  local_5d0 = CnComm::BlockBuffer::vftable;
  InitializeCriticalSection(&local_5b0);
  local_5b8 = 0;
  local_5c0 = 0;
  local_5c8 = 0;
  local_5b4 = 0x400;
  InitializeCriticalSection(&local_678);
  local_6bc[0] = '\0';
  local_6bc[1] = '\0';
  local_6bc[2] = '\0';
  local_6bc[3] = '\0';
  local_6bc[4] = '\0';
  local_6bc[5] = '\0';
  local_6bc[6] = '\0';
  local_6bc[7] = '\0';
  local_6bc[8] = '\0';
  local_6bc[9] = '\0';
  local_6bc[10] = '\0';
  local_6bc[0xb] = '\0';
  local_6bc[0xc] = '\0';
  local_6bc[0xd] = '\0';
  local_6bc[0xe] = '\0';
  local_6bc[0xf] = '\0';
  local_6bc[0x10] = '\0';
  local_6bc[0x11] = '\0';
  local_6bc[0x12] = '\0';
  local_6bc[0x13] = '\0';
  local_6bc[0x14] = '\0';
  local_6bc[0x15] = '\0';
  local_6bc[0x16] = '\0';
  local_6bc[0x17] = '\0';
  local_6bc[0x18] = '\0';
  local_6bc[0x19] = '\0';
  local_6bc[0x1a] = '\0';
  local_6bc[0x1b] = '\0';
  local_6bc[0x1c] = '\0';
  local_6bc[0x1d] = '\0';
  local_6bc[0x1e] = '\0';
  local_6bc[0x1f] = '\0';
  local_6bc[0x20] = '\0';
  local_6bc[0x21] = '\0';
  local_6bc[0x22] = '\0';
  local_6bc[0x23] = '\0';
  local_6bc[0x24] = '\0';
  local_6bc[0x25] = '\0';
  local_6bc[0x26] = '\0';
  local_6bc[0x27] = '\0';
  local_6bc[0x28] = '\0';
  local_6bc[0x29] = '\0';
  local_6bc[0x2a] = '\0';
  local_6bc[0x2b] = '\0';
  local_6bc[0x2c] = '\0';
  local_6bc[0x2d] = '\0';
  local_6bc[0x2e] = '\0';
  local_6bc[0x2f] = '\0';
  local_6bc[0x30] = '\0';
  local_6bc[0x31] = '\0';
  local_6bc[0x32] = '\0';
  local_6bc[0x33] = '\0';
  local_6bc[0x34] = '\0';
  local_6bc[0x35] = '\0';
  local_6bc[0x36] = '\0';
  local_6bc[0x37] = '\0';
  local_6bc[0x38] = '\0';
  local_6bc[0x39] = '\0';
  local_6bc[0x3a] = '\0';
  local_6bc[0x3b] = '\0';
  local_6bc[0x3c] = '\0';
  local_6bc[0x3d] = '\0';
  local_6bc[0x3e] = '\0';
  local_6bc[0x3f] = '\0';
  local_650._8_4_ = 0;
  local_650.wReserved = 0;
  local_650.XonLim = 0;
  local_650.XoffLim = 0;
  local_650.ByteSize = '\0';
  local_650.Parity = '\0';
  local_650.StopBits = '\0';
  local_650.XonChar = '\0';
  local_650.XoffChar = '\0';
  local_650.ErrorChar = '\0';
  local_650.EofChar = '\0';
  local_650.EvtChar = '\0';
  local_650.wReserved1 = 0;
  local_650.DCBlength = 0x1c;
  local_650.BaudRate = 0;
  local_6c8 = (HANDLE)0xffffffffffffffff;
  local_6c0 = 0xffffffff;
  local_588 = 0;
  local_57c = 0x1fd;
  local_578 = 0;
  local_560 = 0;
  local_548 = 0;
  local_570 = 0;
  local_558 = 0;
  local_540 = 0;
  local_530 = 0;
  local_528 = 0;
  local_620 = 0;
  memset(local_520,0,0x60);
  local_508 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
  local_4e8 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
  local_4c8 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
  local_568 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
  local_550 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
  local_538 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
  local_6d0 = 3;
  local_6f8[0] = 0x50;
  local_6f8[1] = 1;
  RegOpenKeyExA((HKEY)0xffffffff80000002,"HARDWARE\\DEVICEMAP\\SERIALCOMM",0,1,&local_6f0);
  RegQueryValueExA(local_6f0,"\\Device\\VCP0",(LPDWORD)0x0,local_6f8 + 1,local_478,local_6f8);
  RegCloseKey(local_6f0);
  if ((byte)(local_472 - 0x30U) - 1 < 0x400) {
    local_6c0 = (uint)(byte)(local_472 - 0x30U);
    uVar4 = 0x4000d2f0;
    wsprintfA(local_6bc,"\\\\.\\COM%d");
    cVar2 = (*(code *)local_6d8[4])(&local_6d8);
    if (cVar2 != '\0') {
      cVar2 = (*(code *)local_6d8[5])(&local_6d8);
      if (cVar2 != '\0') {
        if ((local_6d0 & 0x31) == 0) goto LAB_140005584;
        uVar3 = FUN_140001970(&local_6d8,uVar4);
        if ((char)uVar3 != '\0') goto LAB_140005584;
      }
      (*(code *)local_6d8[1])(&local_6d8,500);
    }
  }
LAB_140005584:
  GetCommState(local_6c8,&local_650);
  local_4b8 = DAT_14000d8e0;
  local_4b0 = DAT_14000d8e8;
  local_4af = 0;
  local_4a8 = DAT_14000d8f0;
  local_4a0 = DAT_14000d8f8;
  local_49f = 0;
  local_498 = DAT_14000d900;
  local_490 = DAT_14000d908;
  local_48f = 0;
  local_488 = DAT_14000d910;
  local_480 = DAT_14000d918;
  local_47f = 0;
  lVar5 = -1;
  do {
    lVar6 = lVar5 + 1;
    lVar1 = lVar5 + 1;
    lVar5 = lVar6;
  } while (*(char *)((longlong)&local_4b8 + lVar1) != '\0');
  FUN_1400017f0((longlong)&local_6d8,&local_4b8,(uint)lVar6);
  Sleep(0x32);
  local_428[0] = 0x77;
  if ((local_6d0 & 4) == 0) {
    FUN_140001600((longlong)&local_6d8,local_428,0x400);
  }
  else {
    EnterCriticalSection(&local_5f8);
    FUN_140001e40((longlong)&local_618,(longlong)local_428,0x400);
    LeaveCriticalSection(&local_5f8);
  }
  KSJ_CaptureRawData(*(int *)(param_1 + 400) + -1,*(undefined8 *)(param_1 + 0x1f0));
  lVar5 = -1;
  do {
    lVar6 = lVar5 + 1;
    lVar1 = lVar5 + 1;
    lVar5 = lVar6;
  } while (*(char *)((longlong)&local_4a8 + lVar1) != '\0');
  FUN_1400017f0((longlong)&local_6d8,&local_4a8,(uint)lVar6);
  Sleep(0x32);
  local_428[0] = 0x77;
  if ((local_6d0 & 4) == 0) {
    FUN_140001600((longlong)&local_6d8,local_428,0x400);
  }
  else {
    EnterCriticalSection(&local_5f8);
    FUN_140001e40((longlong)&local_618,(longlong)local_428,0x400);
    LeaveCriticalSection(&local_5f8);
  }
  KSJ_CaptureRawData(*(int *)(param_1 + 400) + -1,*(undefined8 *)(param_1 + 0x1f8));
  lVar5 = -1;
  do {
    lVar6 = lVar5 + 1;
    lVar1 = lVar5 + 1;
    lVar5 = lVar6;
  } while (*(char *)((longlong)&local_498 + lVar1) != '\0');
  FUN_1400017f0((longlong)&local_6d8,&local_498,(uint)lVar6);
  Sleep(0x32);
  local_428[0] = 0x77;
  if ((local_6d0 & 4) == 0) {
    FUN_140001600((longlong)&local_6d8,local_428,0x400);
  }
  else {
    EnterCriticalSection(&local_5f8);
    FUN_140001e40((longlong)&local_618,(longlong)local_428,0x400);
    LeaveCriticalSection(&local_5f8);
  }
  KSJ_CaptureRawData(*(int *)(param_1 + 400) + -1,*(undefined8 *)(param_1 + 0x200));
  lVar5 = -1;
  do {
    lVar6 = lVar5 + 1;
    lVar1 = lVar5 + 1;
    lVar5 = lVar6;
  } while (*(char *)((longlong)&local_488 + lVar1) != '\0');
  FUN_1400017f0((longlong)&local_6d8,&local_488,(uint)lVar6);
  Sleep(0x32);
  local_428[0] = 0x77;
  if ((local_6d0 & 4) == 0) {
    FUN_140001600((longlong)&local_6d8,local_428,0x400);
  }
  else {
    EnterCriticalSection(&local_5f8);
    FUN_140001e40((longlong)&local_618,(longlong)local_428,0x400);
    LeaveCriticalSection(&local_5f8);
  }
  KSJ_CaptureRawData(*(int *)(param_1 + 400) + -1,*(undefined8 *)(param_1 + 0x208));
  FUN_140001500(&local_6d8);
  __security_check_cookie(local_28 ^ (ulonglong)auStackY_728);
  return;
}



/* 1400059a0 FUN_1400059a0 */

void FUN_1400059a0(longlong param_1)

{
  longlong lVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  ulonglong uVar8;
  uint uVar9;
  ulonglong uVar10;
  double dVar11;
  
  dVar4 = DAT_14000eea8;
  dVar3 = DAT_14000ee90;
  dVar2 = DAT_14000ee80;
  uVar8 = 0;
  iVar6 = *(int *)(param_1 + 0xa38);
  iVar7 = *(int *)(param_1 + 0xa34);
  uVar10 = uVar8;
  if (0 < iVar7 * iVar6) {
    do {
      lVar1 = *(longlong *)(param_1 + 0x1f0);
      iVar6 = (uint)*(byte *)(lVar1 + uVar8) -
              (uint)*(byte *)(*(longlong *)(param_1 + 0x200) + uVar8);
      iVar7 = (uint)*(byte *)(*(longlong *)(param_1 + 0x208) + uVar8) -
              (uint)*(byte *)(uVar8 + *(longlong *)(param_1 + 0x1f8));
      if (iVar6 == 0) {
        cVar5 = '?';
        if (iVar7 < 1) {
          cVar5 = -0x41;
        }
      }
      else {
        dVar11 = atan((double)iVar7 / (double)iVar6);
        cVar5 = (char)(int)((dVar11 * dVar4 * dVar2) / dVar3);
        if (iVar6 < 1) {
          cVar5 = cVar5 + '\x7f';
        }
        else if (iVar7 < 1) {
          cVar5 = cVar5 + -1;
        }
      }
      *(char *)(lVar1 + uVar8) = cVar5;
      uVar9 = (int)uVar10 + 1;
      iVar7 = *(int *)(param_1 + 0xa34);
      uVar8 = uVar8 + 1;
      iVar6 = *(int *)(param_1 + 0xa38);
      uVar10 = (ulonglong)uVar9;
    } while ((int)uVar9 < iVar7 * iVar6);
  }
  memcpy(*(void **)(param_1 + 0x1e0),*(void **)(param_1 + 0x1f0),(longlong)(iVar7 * iVar6));
  return;
}



/* 1400059c9 FUN_1400059c9 */

void FUN_1400059c9(void)

{
  longlong lVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  char cVar5;
  undefined8 unaff_RBX;
  int iVar6;
  undefined8 unaff_RBP;
  int iVar7;
  undefined8 unaff_RSI;
  longlong unaff_RDI;
  longlong in_R11;
  undefined8 unaff_R12;
  undefined8 unaff_R14;
  ulonglong uVar8;
  uint unaff_R15D;
  double dVar9;
  undefined4 unaff_XMM8_Da;
  undefined4 unaff_XMM8_Db;
  undefined4 unaff_XMM8_Dc;
  undefined4 unaff_XMM8_Dd;
  
  *(undefined8 *)(in_R11 + 8) = unaff_RBX;
  *(undefined8 *)(in_R11 + 0x10) = unaff_RBP;
  *(undefined8 *)(in_R11 + 0x18) = unaff_RSI;
  *(undefined8 *)(in_R11 + 0x20) = unaff_R12;
  *(undefined8 *)(in_R11 + -0x18) = unaff_R14;
  dVar4 = DAT_14000eea8;
  dVar2 = DAT_14000ee80;
  uVar8 = (ulonglong)unaff_R15D;
  *(undefined4 *)(in_R11 + -0x48) = unaff_XMM8_Da;
  *(undefined4 *)(in_R11 + -0x44) = unaff_XMM8_Db;
  *(undefined4 *)(in_R11 + -0x40) = unaff_XMM8_Dc;
  *(undefined4 *)(in_R11 + -0x3c) = unaff_XMM8_Dd;
  dVar3 = DAT_14000ee90;
  do {
    lVar1 = *(longlong *)(unaff_RDI + 0x1f0);
    iVar6 = (uint)*(byte *)(lVar1 + uVar8) -
            (uint)*(byte *)(*(longlong *)(unaff_RDI + 0x200) + uVar8);
    iVar7 = (uint)*(byte *)(*(longlong *)(unaff_RDI + 0x208) + uVar8) -
            (uint)*(byte *)(uVar8 + *(longlong *)(unaff_RDI + 0x1f8));
    if (iVar6 == 0) {
      cVar5 = '?';
      if (iVar7 < 1) {
        cVar5 = -0x41;
      }
    }
    else {
      dVar9 = atan((double)iVar7 / (double)iVar6);
      cVar5 = (char)(int)((dVar9 * dVar4 * dVar2) / dVar3);
      if (iVar6 < 1) {
        cVar5 = cVar5 + '\x7f';
      }
      else if (iVar7 < 1) {
        cVar5 = cVar5 + -1;
      }
    }
    *(char *)(lVar1 + uVar8) = cVar5;
    unaff_R15D = unaff_R15D + 1;
    uVar8 = uVar8 + 1;
  } while ((int)unaff_R15D < *(int *)(unaff_RDI + 0xa34) * *(int *)(unaff_RDI + 0xa38));
  memcpy(*(void **)(unaff_RDI + 0x1e0),*(void **)(unaff_RDI + 0x1f0),
         (longlong)(*(int *)(unaff_RDI + 0xa34) * *(int *)(unaff_RDI + 0xa38)));
  return;
}



/* 140005ae0 FUN_140005ae0 */

void FUN_140005ae0(int param_1,int param_2)

{
  longlong unaff_RDI;
  
  memcpy(*(void **)(unaff_RDI + 0x1e0),*(void **)(unaff_RDI + 0x1f0),(longlong)(param_2 * param_1));
  return;
}



/* 140005b00 FUN_140005b00 */

void FUN_140005b00(longlong param_1)

{
  char cVar1;
  
  KSJ_CaptureRawData(*(int *)(param_1 + 400) + -1,*(undefined8 *)(param_1 + 0x1c0));
  memcpy(*(void **)(param_1 + 0x1c8),*(void **)(param_1 + 0x1c0),
         (longlong)(*(int *)(param_1 + 0xa38) * *(int *)(param_1 + 0xa34)));
  cVar1 = FUN_1400052b0(param_1);
  if (cVar1 != '\0') {
    FUN_1400059a0(param_1);
    memcpy(*(void **)(param_1 + 0x1e8),*(void **)(param_1 + 0x1e0),
           (longlong)(*(int *)(param_1 + 0xa38) * *(int *)(param_1 + 0xa34)));
    *(undefined4 *)(param_1 + 0x180) = 3;
                    /* WARNING: Could not recover jumptable at 0x000140005b98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    SetTimer(*(HWND *)(param_1 + 0x40),1,200,(TIMERPROC)0x0);
    return;
  }
  return;
}



/* 140005bb0 FUN_140005bb0 */

void FUN_140005bb0(longlong param_1)

{
  KSJ_CaptureRawData(*(int *)(param_1 + 400) + -1,*(undefined8 *)(param_1 + 0x1c0));
  memcpy(*(void **)(param_1 + 0x1c8),*(void **)(param_1 + 0x1c0),
         (longlong)(*(int *)(param_1 + 0xa38) * *(int *)(param_1 + 0xa34)));
  *(undefined4 *)(param_1 + 0x180) = 2;
                    /* WARNING: Could not recover jumptable at 0x000140005c0f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetTimer(*(HWND *)(param_1 + 0x40),1,100,(TIMERPROC)0x0);
  return;
}



/* 140005c20 FUN_140005c20 */

void FUN_140005c20(CWnd *param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  int iVar5;
  void *_Dst;
  char *pcVar6;
  longlong lVar7;
  char *pcVar8;
  undefined1 auStackY_298 [32];
  longlong local_258 [4];
  undefined8 local_238;
  undefined8 local_230;
  undefined8 local_228;
  undefined4 local_210;
  void *local_208;
  undefined8 uStack_200;
  undefined8 local_1f8;
  undefined8 uStack_1f0;
  undefined8 local_1e8;
  undefined8 uStack_1e0;
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  undefined4 local_1c8;
  undefined8 local_1c0;
  undefined8 local_1b8;
  undefined8 uStack_1b0;
  undefined8 local_1a8;
  undefined8 local_1a0;
  char local_198 [336];
  ulonglong local_48;
  
  local_48 = DAT_140013010 ^ (ulonglong)auStackY_298;
  _Dst = operator_new__((longlong)(*(int *)(param_1 + 0xa34) * *(int *)(param_1 + 0xa38)));
  memcpy(_Dst,*(void **)(param_1 + 0x1e0),
         (longlong)(*(int *)(param_1 + 0xa34) * *(int *)(param_1 + 0xa38)));
  memcpy(*(void **)(param_1 + 0x210),*(void **)(param_1 + 0x1e0),
         (longlong)(*(int *)(param_1 + 0xa34) * *(int *)(param_1 + 0xa38)));
  *(undefined4 *)(param_1 + 0x180) = 4;
  pcVar8 = (char *)0x64;
  SetTimer(*(HWND *)(param_1 + 0x40),1,100,(TIMERPROC)0x0);
  uVar4 = DAT_14000eea0;
  lVar7 = 5;
  pcVar6 = local_198;
  do {
    pcVar6[0] = '\0';
    pcVar6[1] = '\0';
    pcVar6[2] = -0x80;
    pcVar6[3] = '?';
    pcVar6[4] = '\0';
    pcVar6[5] = '\0';
    pcVar6[6] = -0x80;
    pcVar6[7] = '?';
    pcVar6[8] = '\0';
    pcVar6[9] = '\0';
    pcVar6[10] = -0x80;
    pcVar6[0xb] = '?';
    pcVar6[0xc] = '\0';
    pcVar6[0xd] = '\0';
    pcVar6[0xe] = -0x80;
    pcVar6[0xf] = '?';
    pcVar6[0x10] = '\0';
    pcVar6[0x11] = '\0';
    pcVar6[0x12] = -0x80;
    pcVar6[0x13] = '?';
    pcVar6[0x14] = '\0';
    pcVar6[0x15] = '\0';
    pcVar6[0x16] = -0x80;
    pcVar6[0x17] = '?';
    pcVar1 = pcVar6 + 0x40;
    pcVar6[0x18] = '\0';
    pcVar6[0x19] = '\0';
    pcVar6[0x1a] = -0x80;
    pcVar6[0x1b] = '?';
    pcVar6[0x1c] = '\0';
    pcVar6[0x1d] = '\0';
    pcVar6[0x1e] = -0x80;
    pcVar6[0x1f] = '?';
    pcVar6[0x20] = '\0';
    pcVar6[0x21] = '\0';
    pcVar6[0x22] = -0x80;
    pcVar6[0x23] = '?';
    pcVar6[0x24] = '\0';
    pcVar6[0x25] = '\0';
    pcVar6[0x26] = -0x80;
    pcVar6[0x27] = '?';
    pcVar6[0x28] = '\0';
    pcVar6[0x29] = '\0';
    pcVar6[0x2a] = -0x80;
    pcVar6[0x2b] = '?';
    pcVar6[0x2c] = '\0';
    pcVar6[0x2d] = '\0';
    pcVar6[0x2e] = -0x80;
    pcVar6[0x2f] = '?';
    pcVar6[0x30] = '\0';
    pcVar6[0x31] = '\0';
    pcVar6[0x32] = -0x80;
    pcVar6[0x33] = '?';
    pcVar6[0x34] = '\0';
    pcVar6[0x35] = '\0';
    pcVar6[0x36] = -0x80;
    pcVar6[0x37] = '?';
    pcVar6[0x38] = '\0';
    pcVar6[0x39] = '\0';
    pcVar6[0x3a] = -0x80;
    pcVar6[0x3b] = '?';
    pcVar6[0x3c] = '\0';
    pcVar6[0x3d] = '\0';
    pcVar6[0x3e] = -0x80;
    pcVar6[0x3f] = '?';
    lVar7 = lVar7 + -1;
    pcVar6 = pcVar1;
  } while (lVar7 != 0);
  pcVar1[0] = '\0';
  pcVar1[1] = '\0';
  pcVar1[2] = -0x80;
  pcVar1[3] = '?';
  uVar2 = *(undefined4 *)(param_1 + 0xa38);
  uVar3 = *(undefined4 *)(param_1 + 0xa34);
  local_238 = 0;
  local_258[1] = 0;
  local_258[0] = 0;
  local_230 = 0;
  local_228 = 0;
  local_1f8 = 0;
  uStack_1f0 = 0;
  local_208 = (void *)0x0;
  uStack_200 = 0;
  local_1e8 = 0;
  uStack_1e0 = 0;
  local_1d8 = 0;
  uStack_1d0 = 0;
  local_1c0 = 0;
  local_1b8 = 0;
  uStack_1b0 = 0;
  local_1c8 = 0;
  local_210 = 0;
  local_1a0 = 0;
  local_1a8 = 0;
  do {
    lVar7 = 3;
    do {
      FUN_140009880(local_258,CONCAT44(uVar3,uVar2),pcVar8,
                    (void *)(*(longlong *)(param_1 + 0x1a8) + 0x28),_Dst,uVar4);
      pcVar8 = local_198;
      FUN_1400089f0(local_258);
      lVar7 = lVar7 + -1;
    } while (lVar7 != 0);
    memcpy(*(void **)(param_1 + 0x210),local_208,
           (longlong)(*(int *)(param_1 + 0xa34) * *(int *)(param_1 + 0xa38)));
    memcpy(_Dst,*(void **)(param_1 + 0x210),
           (longlong)(*(int *)(param_1 + 0xa34) * *(int *)(param_1 + 0xa38)));
    pcVar8 = "Phase Smoothing";
    iVar5 = CWnd::MessageBoxA(param_1,&DAT_14000d9b0,"Phase Smoothing",4);
  } while (iVar5 != 6);
  operator_delete__(_Dst);
  FUN_1400083d0((longlong)local_258);
  __security_check_cookie(local_48 ^ (ulonglong)auStackY_298);
  return;
}



/* 140005e90 FUN_140005e90 */

void FUN_140005e90(CWnd *param_1,undefined8 param_2,longlong param_3)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  undefined1 auStackY_128 [32];
  longlong local_e8 [4];
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined4 local_a0;
  void *local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  double local_38;
  undefined8 local_30;
  char local_28 [16];
  ulonglong local_18;
  
  local_18 = DAT_140013010 ^ (ulonglong)auStackY_128;
  iVar1 = *(int *)(param_1 + 0x1b8) - *(int *)(param_1 + 0x1b0);
  *(int *)(param_1 + 0x228) = iVar1;
  iVar3 = *(int *)(param_1 + 0x1bc) - *(int *)(param_1 + 0x1b4);
  *(int *)(param_1 + 0x22c) = iVar3;
  if ((*(int *)(param_1 + 0xa38) != iVar1) || (*(int *)(param_1 + 0xa34) != iVar3)) {
    operator_delete__(*(void **)(param_1 + 0x218));
    pvVar2 = operator_new__((longlong)(*(int *)(param_1 + 0x228) * *(int *)(param_1 + 0x22c)));
    *(void **)(param_1 + 0x218) = pvVar2;
    iVar1 = *(int *)(param_1 + 0x228);
    iVar3 = *(int *)(param_1 + 0x22c);
  }
  iVar4 = iVar3;
  iVar5 = 0;
  if (0 < iVar1) {
    do {
      iVar3 = iVar4;
      iVar4 = 0;
      if (iVar3 < 1) {
        iVar4 = *(int *)(param_1 + 0x22c);
      }
      else {
        do {
          param_3 = *(longlong *)(param_1 + 0x210);
          *(undefined1 *)
           ((longlong)(*(int *)(param_1 + 0x228) * iVar4 + iVar5) + *(longlong *)(param_1 + 0x218))
               = *(undefined1 *)
                  (((*(int *)(param_1 + 0x1b4) + iVar4) * *(int *)(param_1 + 0xa38) +
                    *(int *)(param_1 + 0x1b0) + iVar5) + param_3);
          iVar4 = iVar4 + 1;
          iVar3 = *(int *)(param_1 + 0x22c);
        } while (iVar4 < iVar3);
        iVar1 = *(int *)(param_1 + 0x228);
        iVar4 = iVar3;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar1);
  }
  *(undefined8 *)(param_1 + 0x220) = 0;
  pvVar2 = operator_new__((longlong)(*(int *)(param_1 + 0x228) * iVar3 * 3));
  *(void **)(param_1 + 0x220) = pvVar2;
  local_c8 = 0;
  local_e8[1] = 0;
  local_e8[0] = 0;
  local_c0 = 0;
  local_b8 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = (void *)0x0;
  uStack_90 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  local_a0 = 0;
  local_30 = 0;
  local_38 = 0.0;
  pvVar2 = (void *)(*(longlong *)(param_1 + 0x1a8) + 0x28);
  FUN_140009880(local_e8,*(undefined8 *)(param_1 + 0x228),param_3,pvVar2,*(void **)(param_1 + 0x218)
                ,DAT_14000eea0);
  FUN_140008db0(local_e8);
  memcpy(*(void **)(param_1 + 0x218),local_98,
         (longlong)(*(int *)(param_1 + 0x228) * *(int *)(param_1 + 0x22c)));
  fVar6 = (float)((local_38 * DAT_14000ee80) / DAT_14000ee90);
  *(float *)(param_1 + 0xa40) = fVar6;
  FUN_140007140(local_28,&DAT_14000d9bc,(double)fVar6,pvVar2);
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_1 + 0x11e0),local_28);
  CWnd::UpdateData(param_1,0);
  *(undefined4 *)(param_1 + 0x180) = 5;
  SetTimer(*(HWND *)(param_1 + 0x40),1,100,(TIMERPROC)0x0);
  FUN_1400083d0((longlong)local_e8);
  __security_check_cookie(local_18 ^ (ulonglong)auStackY_128);
  return;
}



/* 140006150 FUN_140006150 */

void FUN_140006150(longlong param_1,longlong param_2,int param_3,uint param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  double dVar7;
  float fVar8;
  float fVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  longlong lVar12;
  ulonglong uVar13;
  longlong lVar14;
  longlong lVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  
  fVar9 = DAT_14000eeb8;
  fVar8 = DAT_14000eeb0;
  dVar7 = DAT_14000eea8;
  fVar6 = DAT_14000ee78;
  fVar5 = DAT_14000ee74;
  fVar4 = DAT_14000ee70;
  fVar3 = DAT_14000ee6c;
  fVar2 = DAT_14000ee68;
  fVar1 = DAT_14000ee64;
  if (0 < (int)param_4) {
    lVar14 = param_1 + 2;
    puVar11 = (undefined1 *)(param_2 + 2);
    lVar15 = (longlong)param_3;
    uVar13 = (ulonglong)param_4;
    do {
      lVar12 = 0;
      if (3 < lVar15) {
        puVar10 = puVar11;
        do {
          fVar18 = (float)*(byte *)(lVar14 + -2 + lVar12) / fVar9;
          if (fVar1 < fVar18) {
            if (fVar2 < fVar18) {
              if (fVar4 < fVar18) {
                if (fVar5 < fVar18) {
                  fVar16 = fVar6 - (fVar18 - fVar5) * fVar8;
                  fVar18 = 0.0;
                  goto LAB_1400062a6;
                }
                fVar17 = fVar6 - (fVar18 - fVar4) * fVar8;
                fVar18 = 0.0;
                fVar16 = fVar6;
              }
              else {
                fVar16 = (fVar18 - fVar2) * fVar8;
                fVar18 = fVar6 - fVar16;
                fVar17 = fVar6;
              }
            }
            else {
              fVar16 = 0.0;
              fVar17 = (fVar18 - fVar1) * fVar8;
              fVar18 = fVar6;
            }
          }
          else {
            fVar16 = 0.0;
            fVar18 = fVar18 * fVar8 + fVar3;
LAB_1400062a6:
            fVar17 = 0.0;
          }
          puVar10[-2] = (char)(int)((double)fVar16 * dVar7);
          puVar10[-1] = (char)(int)((double)fVar17 * dVar7);
          *puVar10 = (char)(int)((double)fVar18 * dVar7);
          fVar18 = (float)*(byte *)(lVar14 + -1 + lVar12) / fVar9;
          if (fVar1 < fVar18) {
            if (fVar2 < fVar18) {
              if (fVar4 < fVar18) {
                if (fVar5 < fVar18) {
                  fVar16 = fVar6 - (fVar18 - fVar5) * fVar8;
                  fVar18 = 0.0;
                  goto LAB_140006361;
                }
                fVar17 = fVar6 - (fVar18 - fVar4) * fVar8;
                fVar18 = 0.0;
                fVar16 = fVar6;
              }
              else {
                fVar16 = (fVar18 - fVar2) * fVar8;
                fVar18 = fVar6 - fVar16;
                fVar17 = fVar6;
              }
            }
            else {
              fVar16 = 0.0;
              fVar17 = (fVar18 - fVar1) * fVar8;
              fVar18 = fVar6;
            }
          }
          else {
            fVar16 = 0.0;
            fVar18 = fVar18 * fVar8 + fVar3;
LAB_140006361:
            fVar17 = 0.0;
          }
          puVar10[1] = (char)(int)((double)fVar16 * dVar7);
          puVar10[2] = (char)(int)((double)fVar17 * dVar7);
          puVar10[3] = (char)(int)((double)fVar18 * dVar7);
          fVar18 = (float)*(byte *)(lVar14 + lVar12) / fVar9;
          if (fVar1 < fVar18) {
            if (fVar2 < fVar18) {
              if (fVar4 < fVar18) {
                if (fVar5 < fVar18) {
                  fVar16 = fVar6 - (fVar18 - fVar5) * fVar8;
                  fVar18 = 0.0;
                  goto LAB_14000641c;
                }
                fVar17 = fVar6 - (fVar18 - fVar4) * fVar8;
                fVar18 = 0.0;
                fVar16 = fVar6;
              }
              else {
                fVar16 = (fVar18 - fVar2) * fVar8;
                fVar18 = fVar6 - fVar16;
                fVar17 = fVar6;
              }
            }
            else {
              fVar16 = 0.0;
              fVar17 = (fVar18 - fVar1) * fVar8;
              fVar18 = fVar6;
            }
          }
          else {
            fVar16 = 0.0;
            fVar18 = fVar18 * fVar8 + fVar3;
LAB_14000641c:
            fVar17 = 0.0;
          }
          puVar10[4] = (char)(int)((double)fVar16 * dVar7);
          puVar10[5] = (char)(int)((double)fVar17 * dVar7);
          puVar10[6] = (char)(int)((double)fVar18 * dVar7);
          fVar18 = (float)*(byte *)(lVar14 + 1 + lVar12) / fVar9;
          if (fVar1 < fVar18) {
            if (fVar2 < fVar18) {
              if (fVar4 < fVar18) {
                if (fVar5 < fVar18) {
                  fVar16 = fVar6 - (fVar18 - fVar5) * fVar8;
                  fVar18 = 0.0;
                  goto LAB_1400064d8;
                }
                fVar17 = fVar6 - (fVar18 - fVar4) * fVar8;
                fVar18 = 0.0;
                fVar16 = fVar6;
              }
              else {
                fVar16 = (fVar18 - fVar2) * fVar8;
                fVar18 = fVar6 - fVar16;
                fVar17 = fVar6;
              }
            }
            else {
              fVar16 = 0.0;
              fVar17 = (fVar18 - fVar1) * fVar8;
              fVar18 = fVar6;
            }
          }
          else {
            fVar16 = 0.0;
            fVar18 = fVar18 * fVar8 + fVar3;
LAB_1400064d8:
            fVar17 = 0.0;
          }
          lVar12 = lVar12 + 4;
          puVar10[7] = (char)(int)((double)fVar16 * dVar7);
          puVar10[8] = (char)(int)((double)fVar17 * dVar7);
          puVar10[9] = (char)(int)((double)fVar18 * dVar7);
          puVar10 = puVar10 + 0xc;
        } while (lVar12 < lVar15 + -3);
      }
      if (lVar12 < lVar15) {
        puVar10 = (undefined1 *)(param_2 + 2 + ((-2 - param_1) + lVar14 + lVar12) * 3);
        do {
          fVar18 = (float)*(byte *)(lVar14 + -2 + lVar12) / fVar9;
          if (fVar1 < fVar18) {
            if (fVar2 < fVar18) {
              if (fVar4 < fVar18) {
                if (fVar5 < fVar18) {
                  fVar16 = fVar6 - (fVar18 - fVar5) * fVar8;
                  fVar18 = 0.0;
                  goto LAB_1400065c0;
                }
                fVar17 = fVar6 - (fVar18 - fVar4) * fVar8;
                fVar18 = 0.0;
                fVar16 = fVar6;
              }
              else {
                fVar16 = (fVar18 - fVar2) * fVar8;
                fVar18 = fVar6 - fVar16;
                fVar17 = fVar6;
              }
            }
            else {
              fVar16 = 0.0;
              fVar17 = (fVar18 - fVar1) * fVar8;
              fVar18 = fVar6;
            }
          }
          else {
            fVar16 = 0.0;
            fVar18 = fVar18 * fVar8 + fVar3;
LAB_1400065c0:
            fVar17 = 0.0;
          }
          lVar12 = lVar12 + 1;
          puVar10[-2] = (char)(int)((double)fVar16 * dVar7);
          puVar10[-1] = (char)(int)((double)fVar17 * dVar7);
          *puVar10 = (char)(int)((double)fVar18 * dVar7);
          puVar10 = puVar10 + 3;
        } while (lVar12 < lVar15);
      }
      puVar11 = puVar11 + lVar15 * 3;
      lVar14 = lVar14 + lVar15;
      uVar13 = uVar13 - 1;
    } while (uVar13 != 0);
  }
  return;
}



/* 140006180 FUN_140006180 */

void FUN_140006180(longlong param_1,longlong param_2,int param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  float fVar6;
  longlong in_RAX;
  undefined1 *puVar7;
  undefined8 unaff_RBX;
  undefined1 *puVar8;
  undefined8 unaff_RBP;
  longlong unaff_RSI;
  undefined8 unaff_RDI;
  longlong lVar9;
  uint in_R9D;
  ulonglong uVar10;
  longlong in_R10;
  longlong lVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float in_XMM4_Da;
  float in_XMM5_Da;
  undefined4 unaff_XMM6_Da;
  undefined4 unaff_XMM6_Db;
  undefined4 unaff_XMM6_Dc;
  undefined4 unaff_XMM6_Dd;
  undefined4 unaff_XMM7_Da;
  undefined4 unaff_XMM7_Db;
  undefined4 unaff_XMM7_Dc;
  undefined4 unaff_XMM7_Dd;
  undefined4 unaff_XMM8_Da;
  undefined4 unaff_XMM8_Db;
  undefined4 unaff_XMM8_Dc;
  undefined4 unaff_XMM8_Dd;
  undefined4 unaff_XMM9_Da;
  undefined4 unaff_XMM9_Db;
  undefined4 unaff_XMM9_Dc;
  undefined4 unaff_XMM9_Dd;
  undefined4 unaff_XMM10_Da;
  undefined4 unaff_XMM10_Db;
  undefined4 unaff_XMM10_Dc;
  undefined4 unaff_XMM10_Dd;
  
  *(undefined8 *)(in_RAX + 8) = unaff_RBX;
  puVar8 = (undefined1 *)(param_2 + 2);
  *(undefined8 *)(in_RAX + 0x10) = unaff_RBP;
  *(undefined8 *)(in_RAX + 0x18) = unaff_RDI;
  *(undefined4 *)(in_RAX + -0x18) = unaff_XMM6_Da;
  *(undefined4 *)(in_RAX + -0x14) = unaff_XMM6_Db;
  *(undefined4 *)(in_RAX + -0x10) = unaff_XMM6_Dc;
  *(undefined4 *)(in_RAX + -0xc) = unaff_XMM6_Dd;
  fVar4 = DAT_14000ee74;
  *(undefined4 *)(in_RAX + -0x28) = unaff_XMM7_Da;
  *(undefined4 *)(in_RAX + -0x24) = unaff_XMM7_Db;
  *(undefined4 *)(in_RAX + -0x20) = unaff_XMM7_Dc;
  *(undefined4 *)(in_RAX + -0x1c) = unaff_XMM7_Dd;
  fVar2 = DAT_14000ee68;
  *(undefined4 *)(in_RAX + -0x38) = unaff_XMM8_Da;
  *(undefined4 *)(in_RAX + -0x34) = unaff_XMM8_Db;
  *(undefined4 *)(in_RAX + -0x30) = unaff_XMM8_Dc;
  *(undefined4 *)(in_RAX + -0x2c) = unaff_XMM8_Dd;
  fVar1 = DAT_14000ee64;
  *(undefined4 *)(in_RAX + -0x48) = unaff_XMM9_Da;
  *(undefined4 *)(in_RAX + -0x44) = unaff_XMM9_Db;
  *(undefined4 *)(in_RAX + -0x40) = unaff_XMM9_Dc;
  *(undefined4 *)(in_RAX + -0x3c) = unaff_XMM9_Dd;
  dVar5 = DAT_14000eea8;
  *(undefined4 *)(in_RAX + -0x58) = unaff_XMM10_Da;
  *(undefined4 *)(in_RAX + -0x54) = unaff_XMM10_Db;
  *(undefined4 *)(in_RAX + -0x50) = unaff_XMM10_Dc;
  *(undefined4 *)(in_RAX + -0x4c) = unaff_XMM10_Dd;
  fVar6 = DAT_14000eeb8;
  fVar3 = DAT_14000ee6c;
  lVar11 = (longlong)param_3;
  uVar10 = (ulonglong)in_R9D;
  do {
    lVar9 = 0;
    if (3 < lVar11) {
      puVar7 = puVar8;
      do {
        fVar14 = (float)*(byte *)(in_R10 + -2 + lVar9) / fVar6;
        if (fVar1 < fVar14) {
          if (fVar2 < fVar14) {
            if (in_XMM5_Da < fVar14) {
              if (fVar4 < fVar14) {
                fVar12 = param_4 - (fVar14 - fVar4) * in_XMM4_Da;
                fVar14 = 0.0;
                goto LAB_1400062a6;
              }
              fVar13 = param_4 - (fVar14 - in_XMM5_Da) * in_XMM4_Da;
              fVar14 = 0.0;
              fVar12 = param_4;
            }
            else {
              fVar12 = (fVar14 - fVar2) * in_XMM4_Da;
              fVar14 = param_4 - fVar12;
              fVar13 = param_4;
            }
          }
          else {
            fVar12 = 0.0;
            fVar13 = (fVar14 - fVar1) * in_XMM4_Da;
            fVar14 = param_4;
          }
        }
        else {
          fVar12 = 0.0;
          fVar14 = fVar14 * in_XMM4_Da + fVar3;
LAB_1400062a6:
          fVar13 = 0.0;
        }
        puVar7[-2] = (char)(int)((double)fVar12 * dVar5);
        puVar7[-1] = (char)(int)((double)fVar13 * dVar5);
        *puVar7 = (char)(int)((double)fVar14 * dVar5);
        fVar14 = (float)*(byte *)(in_R10 + -1 + lVar9) / fVar6;
        if (fVar1 < fVar14) {
          if (fVar2 < fVar14) {
            if (in_XMM5_Da < fVar14) {
              if (fVar4 < fVar14) {
                fVar12 = param_4 - (fVar14 - fVar4) * in_XMM4_Da;
                fVar14 = 0.0;
                goto LAB_140006361;
              }
              fVar13 = param_4 - (fVar14 - in_XMM5_Da) * in_XMM4_Da;
              fVar14 = 0.0;
              fVar12 = param_4;
            }
            else {
              fVar12 = (fVar14 - fVar2) * in_XMM4_Da;
              fVar14 = param_4 - fVar12;
              fVar13 = param_4;
            }
          }
          else {
            fVar12 = 0.0;
            fVar13 = (fVar14 - fVar1) * in_XMM4_Da;
            fVar14 = param_4;
          }
        }
        else {
          fVar12 = 0.0;
          fVar14 = fVar14 * in_XMM4_Da + fVar3;
LAB_140006361:
          fVar13 = 0.0;
        }
        puVar7[1] = (char)(int)((double)fVar12 * dVar5);
        puVar7[2] = (char)(int)((double)fVar13 * dVar5);
        puVar7[3] = (char)(int)((double)fVar14 * dVar5);
        fVar14 = (float)*(byte *)(in_R10 + lVar9) / fVar6;
        if (fVar1 < fVar14) {
          if (fVar2 < fVar14) {
            if (in_XMM5_Da < fVar14) {
              if (fVar4 < fVar14) {
                fVar12 = param_4 - (fVar14 - fVar4) * in_XMM4_Da;
                fVar14 = 0.0;
                goto LAB_14000641c;
              }
              fVar13 = param_4 - (fVar14 - in_XMM5_Da) * in_XMM4_Da;
              fVar14 = 0.0;
              fVar12 = param_4;
            }
            else {
              fVar12 = (fVar14 - fVar2) * in_XMM4_Da;
              fVar14 = param_4 - fVar12;
              fVar13 = param_4;
            }
          }
          else {
            fVar12 = 0.0;
            fVar13 = (fVar14 - fVar1) * in_XMM4_Da;
            fVar14 = param_4;
          }
        }
        else {
          fVar12 = 0.0;
          fVar14 = fVar14 * in_XMM4_Da + fVar3;
LAB_14000641c:
          fVar13 = 0.0;
        }
        puVar7[4] = (char)(int)((double)fVar12 * dVar5);
        puVar7[5] = (char)(int)((double)fVar13 * dVar5);
        puVar7[6] = (char)(int)((double)fVar14 * dVar5);
        fVar14 = (float)*(byte *)(in_R10 + 1 + lVar9) / fVar6;
        if (fVar1 < fVar14) {
          if (fVar2 < fVar14) {
            if (in_XMM5_Da < fVar14) {
              if (fVar4 < fVar14) {
                fVar12 = param_4 - (fVar14 - fVar4) * in_XMM4_Da;
                fVar14 = 0.0;
                goto LAB_1400064d8;
              }
              fVar13 = param_4 - (fVar14 - in_XMM5_Da) * in_XMM4_Da;
              fVar14 = 0.0;
              fVar12 = param_4;
            }
            else {
              fVar12 = (fVar14 - fVar2) * in_XMM4_Da;
              fVar14 = param_4 - fVar12;
              fVar13 = param_4;
            }
          }
          else {
            fVar12 = 0.0;
            fVar13 = (fVar14 - fVar1) * in_XMM4_Da;
            fVar14 = param_4;
          }
        }
        else {
          fVar12 = 0.0;
          fVar14 = fVar14 * in_XMM4_Da + fVar3;
LAB_1400064d8:
          fVar13 = 0.0;
        }
        lVar9 = lVar9 + 4;
        puVar7[7] = (char)(int)((double)fVar12 * dVar5);
        puVar7[8] = (char)(int)((double)fVar13 * dVar5);
        puVar7[9] = (char)(int)((double)fVar14 * dVar5);
        puVar7 = puVar7 + 0xc;
      } while (lVar9 < lVar11 + -3);
    }
    if (lVar9 < lVar11) {
      puVar7 = (undefined1 *)(unaff_RSI + 2 + ((-2 - param_1) + in_R10 + lVar9) * 3);
      do {
        fVar14 = (float)*(byte *)(in_R10 + -2 + lVar9) / fVar6;
        if (fVar1 < fVar14) {
          if (fVar2 < fVar14) {
            if (in_XMM5_Da < fVar14) {
              if (fVar4 < fVar14) {
                fVar12 = param_4 - (fVar14 - fVar4) * in_XMM4_Da;
                fVar14 = 0.0;
                goto LAB_1400065c0;
              }
              fVar13 = param_4 - (fVar14 - in_XMM5_Da) * in_XMM4_Da;
              fVar14 = 0.0;
              fVar12 = param_4;
            }
            else {
              fVar12 = (fVar14 - fVar2) * in_XMM4_Da;
              fVar14 = param_4 - fVar12;
              fVar13 = param_4;
            }
          }
          else {
            fVar12 = 0.0;
            fVar13 = (fVar14 - fVar1) * in_XMM4_Da;
            fVar14 = param_4;
          }
        }
        else {
          fVar12 = 0.0;
          fVar14 = fVar14 * in_XMM4_Da + fVar3;
LAB_1400065c0:
          fVar13 = 0.0;
        }
        lVar9 = lVar9 + 1;
        puVar7[-2] = (char)(int)((double)fVar12 * dVar5);
        puVar7[-1] = (char)(int)((double)fVar13 * dVar5);
        *puVar7 = (char)(int)((double)fVar14 * dVar5);
        puVar7 = puVar7 + 3;
      } while (lVar9 < lVar11);
    }
    puVar8 = puVar8 + lVar11 * 3;
    in_R10 = in_R10 + lVar11;
    uVar10 = uVar10 - 1;
    if (uVar10 == 0) {
      return;
    }
  } while( true );
}



/* 14000664d FUN_14000664d */

void FUN_14000664d(void)

{
  return;
}



/* 140006650 FUN_140006650 */

void FUN_140006650(longlong param_1)

{
  FUN_140006150(*(longlong *)(param_1 + 0x218),*(longlong *)(param_1 + 0x220),
                *(int *)(param_1 + 0x228),*(uint *)(param_1 + 0x22c));
  *(undefined4 *)(param_1 + 0x180) = 8;
                    /* WARNING: Could not recover jumptable at 0x000140006698. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetTimer(*(HWND *)(param_1 + 0x40),1,100,(TIMERPROC)0x0);
  return;
}



/* 1400066a0 FUN_1400066a0 */

void FUN_1400066a0(CWnd *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  longlong *plVar1;
  HGDIOBJ ho;
  CWnd *pCVar2;
  HDC pHVar3;
  CDC *pCVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  undefined1 auStackY_e8 [32];
  undefined8 in_stack_ffffffffffffff48;
  undefined8 in_stack_ffffffffffffff50;
  undefined **local_98;
  HGDIOBJ local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined2 local_70;
  undefined8 local_6c;
  undefined8 local_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined8 local_48;
  tagRECT local_40;
  ulonglong local_30;
  
  local_48 = 0xfffffffffffffffe;
  local_30 = DAT_140013010 ^ (ulonglong)auStackY_e8;
  pCVar2 = CWnd::GetDlgItem(param_1,0x3fe);
  pHVar3 = GetDC(*(HWND *)(pCVar2 + 0x40));
  pCVar4 = CDC::FromHandle(pHVar3);
  pHVar3 = (HDC)0x0;
  if (pCVar4 != (CDC *)0x0) {
    pHVar3 = *(HDC *)(pCVar4 + 8);
  }
  local_40.left = 0;
  local_40.top = 0;
  local_40.right = 0;
  local_40.bottom = 0;
  GetClientRect(*(HWND *)(pCVar2 + 0x40),&local_40);
  local_98 = ATL::CImage::vftable;
  local_90 = (HGDIOBJ)0x0;
  local_88 = 0;
  local_80 = 0;
  local_78 = 0;
  local_70 = 0;
  local_6c = 0xffffffffffffffff;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  puVar5 = FUN_140008170();
  EnterCriticalSection((LPCRITICAL_SECTION)(puVar5 + 1));
  *(int *)(puVar5 + 6) = *(int *)(puVar5 + 6) + 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)(puVar5 + 1));
  FUN_140007f20(&local_98,"res\\Holography.png");
  FUN_1400071b0((longlong)&local_98,pHVar3,(RGBQUAD)(local_40.bottom - local_40.top),param_4,
                local_40.right - local_40.left,local_40.bottom - local_40.top,
                in_stack_ffffffffffffff48,in_stack_ffffffffffffff50,(int)local_80,local_80._4_4_);
  CWnd::SetWindowTextA(param_1 + 0xf20,DAT_1400144b8);
  ho = local_90;
  local_98 = ATL::CImage::vftable;
  if (local_90 != (HGDIOBJ)0x0) {
    local_90 = (HGDIOBJ)0x0;
    local_88 = 0;
    local_80 = 0;
    local_78 = 0;
    local_6c = 0xffffffffffffffff;
    local_70 = 0;
    DeleteObject(ho);
  }
  plVar6 = FUN_140008170();
  EnterCriticalSection((LPCRITICAL_SECTION)(plVar6 + 1));
  plVar1 = plVar6 + 6;
  *(int *)plVar1 = (int)*plVar1 + -1;
  if ((int)*plVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(plVar6 + 1));
    if (*plVar6 != 0) {
      GdiplusShutdown();
    }
    *plVar6 = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)(plVar6 + 1));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(plVar6 + 1));
  __security_check_cookie(local_30 ^ (ulonglong)auStackY_e8);
  return;
}



/* 140006870 FUN_140006870 */

void FUN_140006870(CWnd *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  longlong *plVar1;
  HGDIOBJ ho;
  CWnd *pCVar2;
  HDC pHVar3;
  CDC *pCVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  undefined1 auStackY_e8 [32];
  undefined8 in_stack_ffffffffffffff48;
  undefined8 in_stack_ffffffffffffff50;
  undefined **local_98;
  HGDIOBJ local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined2 local_70;
  undefined8 local_6c;
  undefined8 local_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined8 local_48;
  tagRECT local_40;
  ulonglong local_30;
  
  local_48 = 0xfffffffffffffffe;
  local_30 = DAT_140013010 ^ (ulonglong)auStackY_e8;
  pCVar2 = CWnd::GetDlgItem(param_1,0x3fe);
  pHVar3 = GetDC(*(HWND *)(pCVar2 + 0x40));
  pCVar4 = CDC::FromHandle(pHVar3);
  pHVar3 = (HDC)0x0;
  if (pCVar4 != (CDC *)0x0) {
    pHVar3 = *(HDC *)(pCVar4 + 8);
  }
  local_40.left = 0;
  local_40.top = 0;
  local_40.right = 0;
  local_40.bottom = 0;
  GetClientRect(*(HWND *)(pCVar2 + 0x40),&local_40);
  local_98 = ATL::CImage::vftable;
  local_90 = (HGDIOBJ)0x0;
  local_88 = 0;
  local_80 = 0;
  local_78 = 0;
  local_70 = 0;
  local_6c = 0xffffffffffffffff;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  puVar5 = FUN_140008170();
  EnterCriticalSection((LPCRITICAL_SECTION)(puVar5 + 1));
  *(int *)(puVar5 + 6) = *(int *)(puVar5 + 6) + 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)(puVar5 + 1));
  FUN_140007f20(&local_98,"res\\Shearography.png");
  FUN_1400071b0((longlong)&local_98,pHVar3,(RGBQUAD)(local_40.bottom - local_40.top),param_4,
                local_40.right - local_40.left,local_40.bottom - local_40.top,
                in_stack_ffffffffffffff48,in_stack_ffffffffffffff50,(int)local_80,local_80._4_4_);
  CWnd::SetWindowTextA(param_1 + 0xf20,DAT_1400144c0);
  ho = local_90;
  local_98 = ATL::CImage::vftable;
  if (local_90 != (HGDIOBJ)0x0) {
    local_90 = (HGDIOBJ)0x0;
    local_88 = 0;
    local_80 = 0;
    local_78 = 0;
    local_6c = 0xffffffffffffffff;
    local_70 = 0;
    DeleteObject(ho);
  }
  plVar6 = FUN_140008170();
  EnterCriticalSection((LPCRITICAL_SECTION)(plVar6 + 1));
  plVar1 = plVar6 + 6;
  *(int *)plVar1 = (int)*plVar1 + -1;
  if ((int)*plVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(plVar6 + 1));
    if (*plVar6 != 0) {
      GdiplusShutdown();
    }
    *plVar6 = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)(plVar6 + 1));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(plVar6 + 1));
  __security_check_cookie(local_30 ^ (ulonglong)auStackY_e8);
  return;
}



/* 140006a40 FUN_140006a40 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140006a40(CWnd *param_1)

{
  POINT pt;
  BOOL BVar1;
  CWnd *pCVar2;
  float fVar3;
  undefined1 auStack_48 [32];
  tagRECT local_28;
  ulonglong local_18;
  
  local_18 = DAT_140013010 ^ (ulonglong)auStack_48;
  local_28.left = 0;
  local_28.top = 0;
  local_28.right = 0;
  local_28.bottom = 0;
  GetCursorPos((LPPOINT)&DAT_140013f30);
  pCVar2 = CWnd::GetDlgItem(param_1,0x3ec);
  GetWindowRect(*(HWND *)(pCVar2 + 0x40),&local_28);
  pt.y = DAT_140013f34;
  pt.x = DAT_140013f30;
  BVar1 = PtInRect(&local_28,pt);
  if (BVar1 != 0) {
    ClipCursor(&local_28);
    _DAT_140013f24 = (float)*(int *)(param_1 + 0xa38) / (float)(local_28.right - local_28.left);
    fVar3 = (float)*(int *)(param_1 + 0xa34) / (float)(local_28.bottom - local_28.top);
    _DAT_140013f20 = fVar3;
    *(int *)(param_1 + 0x1b0) = (int)((float)(DAT_140013f30 - local_28.left) * _DAT_140013f24);
    *(int *)(param_1 + 0x1b4) = (int)((float)(DAT_140013f34 - local_28.top) * fVar3);
  }
  DAT_140013f28 = 1;
  CWnd::Default(param_1);
  __security_check_cookie(local_18 ^ (ulonglong)auStack_48);
  return;
}



/* 140006b60 FUN_140006b60 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140006b60(CWnd *param_1)

{
  POINT pt;
  BOOL BVar1;
  CWnd *pCVar2;
  undefined1 auStack_48 [32];
  tagRECT local_28;
  ulonglong local_18;
  
  local_18 = DAT_140013010 ^ (ulonglong)auStack_48;
  local_28.left = 0;
  local_28.top = 0;
  local_28.right = 0;
  local_28.bottom = 0;
  if (DAT_140013f28 != '\0') {
    GetCursorPos((LPPOINT)&DAT_140013f30);
    pCVar2 = CWnd::GetDlgItem(param_1,0x3ec);
    GetWindowRect(*(HWND *)(pCVar2 + 0x40),&local_28);
    pt.y = DAT_140013f34;
    pt.x = DAT_140013f30;
    BVar1 = PtInRect(&local_28,pt);
    if (BVar1 != 0) {
      *(int *)(param_1 + 0x1b8) = (int)((float)(DAT_140013f30 - local_28.left) * _DAT_140013f24);
      *(int *)(param_1 + 0x1bc) = (int)((float)(DAT_140013f34 - local_28.top) * _DAT_140013f20);
    }
    DAT_140013f28 = '\0';
  }
  DAT_140013f29 = 1;
  CWnd::Default(param_1);
  __security_check_cookie(local_18 ^ (ulonglong)auStack_48);
  return;
}



/* 140006c40 FUN_140006c40 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140006c40(CWnd *param_1)

{
  POINT pt;
  BOOL BVar1;
  int iVar2;
  CWnd *pCVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_48 [32];
  tagRECT local_28;
  ulonglong local_18;
  
  local_18 = DAT_140013010 ^ (ulonglong)auStack_48;
  local_28.left = 0;
  local_28.top = 0;
  local_28.right = 0;
  local_28.bottom = 0;
  if (DAT_140013f29 != '\0') {
    GetCursorPos((LPPOINT)&DAT_140013f30);
    pCVar3 = CWnd::GetDlgItem(param_1,0x3ec);
    GetWindowRect(*(HWND *)(pCVar3 + 0x40),&local_28);
    pt.y = DAT_140013f34;
    pt.x = DAT_140013f30;
    BVar1 = PtInRect(&local_28,pt);
    if (BVar1 != 0) {
      ClipCursor((RECT *)0x0);
      *(int *)(param_1 + 0x1b8) = (int)((float)(DAT_140013f30 - local_28.left) * _DAT_140013f24);
      *(int *)(param_1 + 0x1bc) = (int)((float)(DAT_140013f34 - local_28.top) * _DAT_140013f20);
    }
  }
  iVar6 = 0;
  iVar2 = *(int *)(param_1 + 0x1b8) - *(int *)(param_1 + 0x1b0);
  DAT_140013f29 = '\0';
  *(int *)(param_1 + 0x1b8) =
       *(int *)(param_1 + 0x1b0) + ((int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2) * 4;
  iVar2 = *(int *)(param_1 + 0x1bc) - *(int *)(param_1 + 0x1b4);
  *(int *)(param_1 + 0x1bc) =
       *(int *)(param_1 + 0x1b4) + ((int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2) * 4;
  if (0 < *(int *)(param_1 + 0xa38)) {
    do {
      iVar2 = 0;
      if (0 < *(int *)(param_1 + 0xa34)) {
        do {
          if ((((iVar6 == *(int *)(param_1 + 0x1b0)) || (iVar6 == *(int *)(param_1 + 0x1b8))) &&
              (*(int *)(param_1 + 0x1b4) <= iVar2)) && (iVar2 <= *(int *)(param_1 + 0x1bc))) {
            *(undefined1 *)
             ((longlong)((*(int *)(param_1 + 0xa38) * iVar2 + iVar6) * 3) +
             *(longlong *)(param_1 + 0x1d8)) = 0;
            *(undefined1 *)
             ((longlong)((*(int *)(param_1 + 0xa38) * iVar2 + iVar6) * 3) + 1 +
             *(longlong *)(param_1 + 0x1d8)) = 0;
            *(undefined1 *)
             ((longlong)((*(int *)(param_1 + 0xa38) * iVar2 + iVar6) * 3) + 2 +
             *(longlong *)(param_1 + 0x1d8)) = 0xff;
            *(undefined1 *)
             ((longlong)((*(int *)(param_1 + 0xa38) * iVar2 + iVar6) * 3) + -3 +
             *(longlong *)(param_1 + 0x1d8)) = 0;
            *(undefined1 *)
             ((longlong)((*(int *)(param_1 + 0xa38) * iVar2 + iVar6) * 3) + -2 +
             *(longlong *)(param_1 + 0x1d8)) = 0;
            *(undefined1 *)
             ((longlong)((*(int *)(param_1 + 0xa38) * iVar2 + iVar6) * 3) + -1 +
             *(longlong *)(param_1 + 0x1d8)) = 0xff;
            *(undefined1 *)
             ((longlong)((*(int *)(param_1 + 0xa38) * iVar2 + iVar6) * 3) + 3 +
             *(longlong *)(param_1 + 0x1d8)) = 0;
            *(undefined1 *)
             ((longlong)((*(int *)(param_1 + 0xa38) * iVar2 + iVar6) * 3) + 4 +
             *(longlong *)(param_1 + 0x1d8)) = 0;
            *(undefined1 *)
             ((longlong)((*(int *)(param_1 + 0xa38) * iVar2 + iVar6) * 3) + 5 +
             *(longlong *)(param_1 + 0x1d8)) = 0xff;
          }
          else if (((iVar6 < *(int *)(param_1 + 0x1b0)) || (*(int *)(param_1 + 0x1b8) < iVar6)) ||
                  ((iVar2 != *(int *)(param_1 + 0x1b4) && (iVar2 != *(int *)(param_1 + 0x1bc))))) {
            iVar4 = *(int *)(param_1 + 0xa38) * iVar2 + iVar6;
            *(undefined1 *)((longlong)(iVar4 * 3) + *(longlong *)(param_1 + 0x1d8)) =
                 *(undefined1 *)((longlong)iVar4 + *(longlong *)(param_1 + 0x1d0));
            iVar4 = *(int *)(param_1 + 0xa38) * iVar2 + iVar6;
            *(undefined1 *)((longlong)(iVar4 * 3) + 1 + *(longlong *)(param_1 + 0x1d8)) =
                 *(undefined1 *)((longlong)iVar4 + *(longlong *)(param_1 + 0x1d0));
            iVar4 = *(int *)(param_1 + 0xa38) * iVar2 + iVar6;
            *(undefined1 *)((longlong)(iVar4 * 3) + 2 + *(longlong *)(param_1 + 0x1d8)) =
                 *(undefined1 *)((longlong)iVar4 + *(longlong *)(param_1 + 0x1d0));
          }
          else {
            iVar4 = iVar2 + 1;
            iVar5 = iVar2 + -1;
            *(undefined1 *)
             ((longlong)((*(int *)(param_1 + 0xa38) * iVar2 + iVar6) * 3) +
             *(longlong *)(param_1 + 0x1d8)) = 0;
            *(undefined1 *)
             ((longlong)((*(int *)(param_1 + 0xa38) * iVar2 + iVar6) * 3) + 1 +
             *(longlong *)(param_1 + 0x1d8)) = 0;
            *(undefined1 *)
             ((longlong)((*(int *)(param_1 + 0xa38) * iVar2 + iVar6) * 3) + 2 +
             *(longlong *)(param_1 + 0x1d8)) = 0xff;
            *(undefined1 *)
             ((longlong)((iVar5 * *(int *)(param_1 + 0xa38) + iVar6) * 3) +
             *(longlong *)(param_1 + 0x1d8)) = 0;
            *(undefined1 *)
             ((longlong)((iVar5 * *(int *)(param_1 + 0xa38) + iVar6) * 3) + 1 +
             *(longlong *)(param_1 + 0x1d8)) = 0;
            *(undefined1 *)
             ((longlong)((iVar5 * *(int *)(param_1 + 0xa38) + iVar6) * 3) + 2 +
             *(longlong *)(param_1 + 0x1d8)) = 0xff;
            *(undefined1 *)
             ((longlong)((iVar4 * *(int *)(param_1 + 0xa38) + iVar6) * 3) +
             *(longlong *)(param_1 + 0x1d8)) = 0;
            *(undefined1 *)
             ((longlong)((iVar4 * *(int *)(param_1 + 0xa38) + iVar6) * 3) + 1 +
             *(longlong *)(param_1 + 0x1d8)) = 0;
            *(undefined1 *)
             ((longlong)((iVar4 * *(int *)(param_1 + 0xa38) + iVar6) * 3) + 2 +
             *(longlong *)(param_1 + 0x1d8)) = 0xff;
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < *(int *)(param_1 + 0xa34));
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(param_1 + 0xa38));
  }
  *(undefined4 *)(param_1 + 0x180) = 6;
  SetTimer(*(HWND *)(param_1 + 0x40),1,100,(TIMERPROC)0x0);
  CWnd::Default(param_1);
  __security_check_cookie(local_18 ^ (ulonglong)auStack_48);
  return;
}



/* 1400070f0 FUN_1400070f0 */

void FUN_1400070f0(CDialogEx *param_1,tagMSG *param_2)

{
  if (*(int *)(param_2 + 8) == 0x200) {
    SendMessageA(*(HWND *)(param_1 + 0xd50),0x407,0,(LPARAM)param_2);
  }
                    /* WARNING: Could not recover jumptable at 0x000140007131. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CDialogEx::PreTranslateMessage(param_1,param_2);
  return;
}



/* 140007140 FUN_140007140 */

int FUN_140007140(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  puVar2 = (undefined8 *)FUN_1400083c0();
  iVar1 = __stdio_common_vsprintf_s(*puVar2,param_1,10,param_2,0,&local_res18);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  return iVar1;
}



/* 1400071a0 FUN_1400071a0 */

void FUN_1400071a0(CDialog *param_1,ushort param_2,CWnd *param_3)

{
                    /* WARNING: Could not recover jumptable at 0x0001400071a3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CDialog::Create(param_1,(char *)(ulonglong)param_2,param_3);
  return;
}



/* 1400071b0 FUN_1400071b0 */

BOOL FUN_1400071b0(longlong param_1,HDC param_2,RGBQUAD param_3,undefined4 param_4,int param_5,
                  int param_6,undefined8 param_7,undefined8 param_8,int param_9,int param_10)

{
  int *piVar1;
  HDC hdc;
  BOOL BVar2;
  undefined8 *puVar3;
  HDC pHVar4;
  HGDIOBJ pvVar5;
  UINT crTransparent;
  int iVar6;
  int iVar7;
  RGBQUAD local_res18 [2];
  undefined4 local_res20;
  
  if (param_2 == (HDC)0x0) {
    return 0;
  }
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  iVar6 = 0;
  local_res18[0] = param_3;
  local_res20 = param_4;
  if (*(longlong *)(param_1 + 0x38) == 0) {
    puVar3 = FUN_140007940();
    iVar7 = iVar6;
    do {
      LOCK();
      pHVar4 = (HDC)puVar3[iVar7];
      puVar3[iVar7] = 0;
      UNLOCK();
      if (pHVar4 != (HDC)0x0) goto LAB_14000721e;
      iVar7 = iVar7 + 1;
    } while (iVar7 < 4);
    pHVar4 = CreateCompatibleDC((HDC)0x0);
LAB_14000721e:
    *(HDC *)(param_1 + 0x38) = pHVar4;
    pvVar5 = SelectObject(pHVar4,*(HGDIOBJ *)(param_1 + 8));
    *(HGDIOBJ *)(param_1 + 0x48) = pvVar5;
  }
  if (*(UINT *)(param_1 + 0x2c) == 0xffffffff) {
    crTransparent = *(UINT *)(param_1 + 0x30);
    if (crTransparent == 0xffffffff) {
      if (*(char *)(param_1 + 0x29) == '\0') {
        BVar2 = StretchBlt(param_2,0,0,param_5,param_6,*(HDC *)(param_1 + 0x38),0,0,param_9,param_10
                           ,0xcc0020);
      }
      else {
        local_res20 = 0x1ff0000;
        BVar2 = AlphaBlend(param_2,0,0,param_5,param_6,*(HDC *)(param_1 + 0x38),0,0,param_9,param_10
                           ,(BLENDFUNCTION)0x1ff0000);
      }
      goto LAB_14000737e;
    }
  }
  else {
    GetDIBColorTable(*(HDC *)(param_1 + 0x38),*(UINT *)(param_1 + 0x2c),1,local_res18);
    crTransparent =
         ((uint)local_res18[0] >> 8 & 0xff) << 8 | ((uint)local_res18[0] & 0xff) << 0x10 |
         (uint)local_res18[0] >> 0x10 & 0xff;
  }
  BVar2 = TransparentBlt(param_2,0,0,param_5,param_6,*(HDC *)(param_1 + 0x38),0,0,param_9,param_10,
                         crTransparent);
LAB_14000737e:
  piVar1 = (int *)(param_1 + 0x40);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    SelectObject(*(HDC *)(param_1 + 0x38),*(HGDIOBJ *)(param_1 + 0x48));
    pHVar4 = *(HDC *)(param_1 + 0x38);
    puVar3 = FUN_140007940();
    do {
      LOCK();
      hdc = (HDC)puVar3[iVar6];
      puVar3[iVar6] = pHVar4;
      UNLOCK();
      if (hdc == (HDC)0x0) goto LAB_1400073bc;
      iVar6 = iVar6 + 1;
      pHVar4 = hdc;
    } while (iVar6 < 4);
    DeleteDC(hdc);
LAB_1400073bc:
    *(undefined8 *)(param_1 + 0x38) = 0;
  }
  return BVar2;
}



/* 1400073e0 FUN_1400073e0 */

void FUN_1400073e0(undefined8 *param_1,int param_2,void *param_3)

{
  void *_Memory;
  code *pcVar1;
  
  if (((param_1 == (undefined8 *)0x0) || (param_2 < 0)) || (param_3 == (void *)0x0)) {
    FUN_1400083a0(-0x7ff8ffa9);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _Memory = (void *)*param_1;
  if (_Memory == param_3) {
    if (param_2 < 0x81) goto LAB_140007425;
    param_3 = calloc((longlong)param_2,2);
    *param_1 = param_3;
  }
  else {
    if (param_2 < 0x81) {
      free(_Memory);
    }
    else {
      param_3 = _recalloc(_Memory,(longlong)param_2,2);
      if (param_3 == (void *)0x0) goto LAB_140007460;
    }
LAB_140007425:
    *param_1 = param_3;
  }
  if (param_3 != (void *)0x0) {
    return;
  }
LAB_140007460:
  FUN_1400083a0(-0x7ff8fff2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* 140007480 FUN_140007480 */

void FUN_140007480(void)

{
  code *pcVar1;
  DWORD DVar2;
  
  DVar2 = GetLastError();
  if (0 < (int)DVar2) {
    DVar2 = DVar2 & 0xffff | 0x80070000;
  }
  FUN_1400083a0(DVar2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* 1400074a0 FUN_1400074a0 */

void FUN_1400074a0(undefined8 *param_1,LPCSTR param_2,UINT param_3)

{
  LPWSTR pWVar1;
  LPWSTR _Memory;
  code *pcVar2;
  int iVar3;
  DWORD DVar4;
  LPWSTR pWVar5;
  int iVar6;
  longlong lVar7;
  bool bVar8;
  
  if (param_2 == (LPCSTR)0x0) {
    *param_1 = 0;
    return;
  }
  lVar7 = -1;
  do {
    lVar7 = lVar7 + 1;
  } while (param_2[lVar7] != '\0');
  iVar6 = (int)lVar7 + 1;
  pWVar1 = (LPWSTR)(param_1 + 1);
  if (((param_1 == (undefined8 *)0x0) || (iVar6 < 0)) || (pWVar1 == (LPWSTR)0x0)) {
    FUN_1400083a0(-0x7ff8ffa9);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  _Memory = (LPWSTR)*param_1;
  pWVar5 = pWVar1;
  if (_Memory == pWVar1) {
    if (iVar6 < 0x81) {
      *param_1 = pWVar1;
    }
    else {
      pWVar5 = (LPWSTR)calloc((longlong)iVar6,2);
      *param_1 = pWVar5;
    }
  }
  else if (iVar6 < 0x81) {
    free(_Memory);
    *param_1 = pWVar1;
  }
  else {
    pWVar5 = (LPWSTR)_recalloc(_Memory,(longlong)iVar6,2);
    if (pWVar5 == (LPWSTR)0x0) goto FUN_14000760d;
    *param_1 = pWVar5;
  }
  if (pWVar5 != (LPWSTR)0x0) {
    iVar3 = MultiByteToWideChar(param_3,0,param_2,iVar6,pWVar5,iVar6);
    bVar8 = iVar3 == 0;
    if (iVar3 == 0) {
      DVar4 = GetLastError();
      if (DVar4 == 0x7a) {
        iVar3 = MultiByteToWideChar(param_3,0,param_2,iVar6,(LPWSTR)0x0,0);
        FUN_1400073e0(param_1,iVar3,pWVar1);
        iVar6 = MultiByteToWideChar(param_3,0,param_2,iVar6,(LPWSTR)*param_1,iVar3);
        bVar8 = iVar6 == 0;
      }
    }
    if (!bVar8) {
      return;
    }
    FUN_140007640((void *)*param_1,pWVar1);
    FUN_140007480();
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
FUN_14000760d:
  FUN_1400083a0(-0x7ff8fff2);
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}



/* 1400074c5 FUN_1400074c5 */

void FUN_1400074c5(undefined8 *param_1,longlong param_2)

{
  LPWSTR pWVar1;
  LPWSTR _Memory;
  code *pcVar2;
  int iVar3;
  DWORD DVar4;
  LPWSTR pWVar5;
  int iVar6;
  longlong lVar7;
  undefined8 *unaff_RSI;
  UINT unaff_R12D;
  LPCSTR unaff_R14;
  bool bVar8;
  
  lVar7 = -1;
  do {
    lVar7 = lVar7 + 1;
  } while (*(char *)(param_2 + lVar7) != '\0');
  iVar6 = (int)lVar7 + 1;
  pWVar1 = (LPWSTR)(param_1 + 1);
  if (((unaff_RSI == (undefined8 *)0x0) || (iVar6 < 0)) || (pWVar1 == (LPWSTR)0x0)) {
    FUN_1400083a0(-0x7ff8ffa9);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  _Memory = (LPWSTR)*param_1;
  pWVar5 = pWVar1;
  if (_Memory == pWVar1) {
    if (iVar6 < 0x81) {
      *unaff_RSI = pWVar1;
    }
    else {
      pWVar5 = (LPWSTR)calloc((longlong)iVar6,2);
      *unaff_RSI = pWVar5;
    }
  }
  else if (iVar6 < 0x81) {
    free(_Memory);
    *unaff_RSI = pWVar1;
  }
  else {
    pWVar5 = (LPWSTR)_recalloc(_Memory,(longlong)iVar6,2);
    if (pWVar5 == (LPWSTR)0x0) goto FUN_14000760d;
    *unaff_RSI = pWVar5;
  }
  if (pWVar5 != (LPWSTR)0x0) {
    iVar3 = MultiByteToWideChar(unaff_R12D,0,unaff_R14,iVar6,pWVar5,iVar6);
    bVar8 = iVar3 == 0;
    if (iVar3 == 0) {
      DVar4 = GetLastError();
      if (DVar4 == 0x7a) {
        iVar3 = MultiByteToWideChar(unaff_R12D,0,unaff_R14,iVar6,(LPWSTR)0x0,0);
        FUN_1400073e0(unaff_RSI,iVar3,pWVar1);
        iVar6 = MultiByteToWideChar(unaff_R12D,0,unaff_R14,iVar6,(LPWSTR)*unaff_RSI,iVar3);
        bVar8 = iVar6 == 0;
      }
    }
    if (!bVar8) {
      return;
    }
    FUN_140007640((void *)*unaff_RSI,pWVar1);
    FUN_140007480();
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
FUN_14000760d:
  FUN_1400083a0(-0x7ff8fff2);
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}



/* 140007575 FUN_140007575 */

void FUN_140007575(undefined8 param_1,DWORD param_2,LPCSTR param_3,int param_4,int param_5)

{
  code *pcVar1;
  int iVar2;
  DWORD DVar3;
  int unaff_EBX;
  void *unaff_RBP;
  undefined8 *unaff_RSI;
  UINT unaff_R12D;
  LPCSTR unaff_R14;
  bool bVar4;
  LPWSTR in_stack_00000020;
  
  iVar2 = MultiByteToWideChar(unaff_R12D,param_2,param_3,param_4,in_stack_00000020,param_5);
  bVar4 = iVar2 == 0;
  if (iVar2 == 0) {
    DVar3 = GetLastError();
    if (DVar3 == 0x7a) {
      iVar2 = MultiByteToWideChar(unaff_R12D,0,unaff_R14,unaff_EBX,(LPWSTR)0x0,0);
      FUN_1400073e0(unaff_RSI,iVar2,unaff_RBP);
      iVar2 = MultiByteToWideChar(unaff_R12D,0,unaff_R14,unaff_EBX,(LPWSTR)*unaff_RSI,iVar2);
      bVar4 = iVar2 == 0;
    }
  }
  if (!bVar4) {
    return;
  }
  FUN_140007640((void *)*unaff_RSI,unaff_RBP);
  FUN_140007480();
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* 1400075f9 FUN_1400075f9 */

void FUN_1400075f9(void)

{
  return;
}



/* 14000760d FUN_14000760d */

void FUN_14000760d(void)

{
  code *pcVar1;
  
  FUN_1400083a0(-0x7ff8fff2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* 140007640 FUN_140007640 */

void FUN_140007640(void *param_1,void *param_2)

{
  if (param_1 != param_2) {
                    /* WARNING: Could not recover jumptable at 0x000140007645. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    free(param_1);
    return;
  }
  return;
}



/* 140007650 FUN_140007650 */

void FUN_140007650(longlong param_1,undefined4 param_2,int param_3,int param_4,undefined8 param_5,
                  undefined8 param_6,byte param_7)

{
  int iVar1;
  undefined8 *_Memory;
  HBITMAP h;
  undefined8 *_Dst;
  int iVar2;
  undefined8 *puVar3;
  int iVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int *piVar9;
  undefined2 *puVar10;
  undefined8 *puVar11;
  undefined2 *puVar12;
  BITMAPINFO *lpbmi;
  undefined1 auStackY_e8 [32];
  undefined1 auStack_a8 [4];
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  ushort uStack_96;
  undefined8 uStack_90;
  undefined4 uStack_84;
  uint uStack_80;
  ushort uStack_7a;
  ulonglong local_38;
  
  local_38 = DAT_140013010 ^ (ulonglong)auStackY_e8;
  _Memory = (undefined8 *)malloc(0x438);
  if (_Memory == (undefined8 *)0x0) {
    lpbmi = (BITMAPINFO *)0x0;
    puVar3 = (undefined8 *)&DAT_00000014;
    _Dst = (undefined8 *)0x28;
    puVar6 = (undefined8 *)&DAT_0000001c;
    puVar7 = (undefined4 *)&DAT_00000024;
    puVar8 = (undefined4 *)&DAT_00000004;
    piVar9 = (int *)&DAT_00000008;
    puVar12 = (undefined2 *)&DAT_0000000c;
    puVar10 = (undefined2 *)&DAT_0000000e;
    puVar11 = (undefined8 *)&DAT_00000010;
    _Memory = (undefined8 *)0x0;
  }
  else {
    *_Memory = 0;
    lpbmi = (BITMAPINFO *)(_Memory + 2);
    puVar3 = (undefined8 *)((longlong)_Memory + 0x24);
    puVar6 = (undefined8 *)((longlong)_Memory + 0x2c);
    puVar7 = (undefined4 *)((longlong)_Memory + 0x34);
    puVar8 = (undefined4 *)((longlong)_Memory + 0x14);
    piVar9 = (int *)(_Memory + 3);
    puVar12 = (undefined2 *)((longlong)_Memory + 0x1c);
    puVar10 = (undefined2 *)((longlong)_Memory + 0x1e);
    puVar11 = _Memory + 4;
    _Dst = _Memory + 7;
  }
  if (lpbmi != (BITMAPINFO *)0x0) {
    *puVar3 = 0;
    *puVar6 = 0;
    *puVar7 = 0;
    *puVar10 = (short)param_4;
    *puVar8 = param_2;
    (lpbmi->bmiHeader).biSize = 0x28;
    *piVar9 = param_3;
    *puVar12 = 1;
    *(undefined4 *)puVar11 = 0;
    if (param_4 < 9) {
      memset(_Dst,0,0x400);
    }
    h = CreateDIBSection((HDC)0x0,lpbmi,0,(void **)(param_1 + 0x10),(HANDLE)0x0,0);
    if (h != (HBITMAP)0x0) {
      *(HBITMAP *)(param_1 + 8) = h;
      iVar4 = (param_3 >> 0x1f) + 2;
      iVar1 = GetObjectA(h,0x68,auStack_a8);
      if (iVar1 == 0x68) {
        *(undefined4 *)(param_1 + 0x18) = uStack_84;
        *(uint *)(param_1 + 0x24) = (uint)uStack_7a;
        *(undefined1 *)(param_1 + 0x28) = 1;
        iVar5 = (uStack_80 ^ (int)uStack_80 >> 0x1f) - ((int)uStack_80 >> 0x1f);
        *(int *)(param_1 + 0x1c) = iVar5;
        *(undefined8 *)(param_1 + 0x10) = uStack_90;
        iVar1 = *(int *)(param_1 + 0x18) * (uint)uStack_7a + 0x1f;
        iVar1 = (int)((iVar1 >> 0x1f & 0x1fU) + iVar1) >> 5;
        iVar2 = iVar1 * 4;
        *(int *)(param_1 + 0x20) = iVar2;
        if (iVar4 == 0) {
          iVar4 = (0 < (int)uStack_80) + 1;
        }
        if (iVar4 == 2) {
          *(longlong *)(param_1 + 0x10) =
               *(longlong *)(param_1 + 0x10) + (longlong)((iVar5 + -1) * iVar2);
          *(int *)(param_1 + 0x20) = iVar1 * -4;
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x18) = uStack_a4;
        *(undefined4 *)(param_1 + 0x1c) = uStack_a0;
        *(uint *)(param_1 + 0x24) = (uint)uStack_96;
        *(undefined1 *)(param_1 + 0x28) = 0;
        *(undefined4 *)(param_1 + 0x20) = 0;
        *(undefined8 *)(param_1 + 0x10) = 0;
      }
      *(undefined1 *)(param_1 + 0x29) = 0;
      *(bool *)(param_1 + 0x29) = (param_7 & 1) != 0;
      *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
    }
  }
  while (_Memory != (undefined8 *)0x0) {
    puVar3 = (undefined8 *)*_Memory;
    free(_Memory);
    _Memory = puVar3;
  }
  __security_check_cookie(local_38 ^ (ulonglong)auStackY_e8);
  return;
}



/* 14000766e FUN_14000766e */

void FUN_14000766e(longlong param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined8 *_Memory;
  HBITMAP h;
  undefined8 *_Dst;
  int iVar2;
  undefined8 *puVar3;
  int iVar4;
  undefined8 unaff_RSI;
  undefined8 unaff_RDI;
  int iVar5;
  undefined8 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  longlong in_R11;
  int *piVar9;
  undefined8 unaff_R12;
  undefined2 *puVar10;
  undefined8 unaff_R13;
  undefined8 *puVar11;
  undefined8 unaff_R14;
  undefined2 *puVar12;
  undefined8 unaff_R15;
  BITMAPINFO *lpbmi;
  int iStack0000000000000030;
  undefined4 in_stack_00000044;
  undefined4 in_stack_00000048;
  ushort in_stack_00000052;
  undefined8 in_stack_00000058;
  undefined4 in_stack_00000064;
  uint in_stack_00000068;
  ushort in_stack_0000006e;
  ulonglong in_stack_000000b0;
  byte in_stack_00000120;
  
  *(undefined8 *)(in_R11 + 0x10) = unaff_RSI;
  *(undefined8 *)(in_R11 + 0x18) = unaff_RDI;
  *(undefined8 *)(in_R11 + 0x20) = unaff_R12;
  *(undefined8 *)(in_R11 + -0x18) = unaff_R13;
  *(undefined8 *)(in_R11 + -0x20) = unaff_R14;
  *(undefined8 *)(in_R11 + -0x28) = unaff_R15;
  iStack0000000000000030 = param_4;
  _Memory = (undefined8 *)malloc(0x438);
  if (_Memory == (undefined8 *)0x0) {
    lpbmi = (BITMAPINFO *)0x0;
    puVar3 = (undefined8 *)&DAT_00000014;
    _Dst = (undefined8 *)0x28;
    puVar6 = (undefined8 *)&DAT_0000001c;
    puVar7 = (undefined4 *)&DAT_00000024;
    puVar8 = (undefined4 *)&DAT_00000004;
    piVar9 = (int *)&DAT_00000008;
    puVar12 = (undefined2 *)&DAT_0000000c;
    puVar10 = (undefined2 *)&DAT_0000000e;
    puVar11 = (undefined8 *)&DAT_00000010;
    _Memory = (undefined8 *)0x0;
  }
  else {
    *_Memory = 0;
    lpbmi = (BITMAPINFO *)(_Memory + 2);
    puVar3 = (undefined8 *)((longlong)_Memory + 0x24);
    puVar6 = (undefined8 *)((longlong)_Memory + 0x2c);
    puVar7 = (undefined4 *)((longlong)_Memory + 0x34);
    puVar8 = (undefined4 *)((longlong)_Memory + 0x14);
    piVar9 = (int *)(_Memory + 3);
    puVar12 = (undefined2 *)((longlong)_Memory + 0x1c);
    puVar10 = (undefined2 *)((longlong)_Memory + 0x1e);
    puVar11 = _Memory + 4;
    _Dst = _Memory + 7;
  }
  if (lpbmi != (BITMAPINFO *)0x0) {
    *puVar3 = 0;
    *puVar6 = 0;
    *puVar7 = 0;
    *puVar10 = (short)iStack0000000000000030;
    *puVar8 = param_2;
    (lpbmi->bmiHeader).biSize = 0x28;
    *piVar9 = param_3;
    *puVar12 = 1;
    *(undefined4 *)puVar11 = 0;
    if (iStack0000000000000030 < 9) {
      memset(_Dst,0,0x400);
    }
    h = CreateDIBSection((HDC)0x0,lpbmi,0,(void **)(param_1 + 0x10),(HANDLE)0x0,0);
    if (h != (HBITMAP)0x0) {
      *(HBITMAP *)(param_1 + 8) = h;
      iVar4 = (param_3 >> 0x1f) + 2;
      iVar1 = GetObjectA(h,0x68,&stack0x00000040);
      if (iVar1 == 0x68) {
        *(undefined4 *)(param_1 + 0x18) = in_stack_00000064;
        *(uint *)(param_1 + 0x24) = (uint)in_stack_0000006e;
        *(undefined1 *)(param_1 + 0x28) = 1;
        iVar5 = (in_stack_00000068 ^ (int)in_stack_00000068 >> 0x1f) -
                ((int)in_stack_00000068 >> 0x1f);
        *(int *)(param_1 + 0x1c) = iVar5;
        *(undefined8 *)(param_1 + 0x10) = in_stack_00000058;
        iVar1 = *(int *)(param_1 + 0x18) * (uint)in_stack_0000006e + 0x1f;
        iVar1 = (int)((iVar1 >> 0x1f & 0x1fU) + iVar1) >> 5;
        iVar2 = iVar1 * 4;
        *(int *)(param_1 + 0x20) = iVar2;
        if (iVar4 == 0) {
          iVar4 = (0 < (int)in_stack_00000068) + 1;
        }
        if (iVar4 == 2) {
          *(longlong *)(param_1 + 0x10) =
               *(longlong *)(param_1 + 0x10) + (longlong)((iVar5 + -1) * iVar2);
          *(int *)(param_1 + 0x20) = iVar1 * -4;
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x18) = in_stack_00000044;
        *(undefined4 *)(param_1 + 0x1c) = in_stack_00000048;
        *(uint *)(param_1 + 0x24) = (uint)in_stack_00000052;
        *(undefined1 *)(param_1 + 0x28) = 0;
        *(undefined4 *)(param_1 + 0x20) = 0;
        *(undefined8 *)(param_1 + 0x10) = 0;
      }
      *(undefined1 *)(param_1 + 0x29) = 0;
      *(bool *)(param_1 + 0x29) = (in_stack_00000120 & 1) != 0;
      *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
    }
  }
  while (_Memory != (undefined8 *)0x0) {
    puVar3 = (undefined8 *)*_Memory;
    free(_Memory);
    _Memory = puVar3;
  }
  __security_check_cookie(in_stack_000000b0 ^ (ulonglong)&stack0x00000000);
  return;
}



/* 140007880 FUN_140007880 */

void FUN_140007880(void)

{
  longlong *plVar1;
  longlong *unaff_RBX;
  ulonglong in_stack_000000b0;
  
  do {
    plVar1 = (longlong *)*unaff_RBX;
    free(unaff_RBX);
    unaff_RBX = plVar1;
  } while (plVar1 != (longlong *)0x0);
  __security_check_cookie(in_stack_000000b0 ^ (ulonglong)&stack0x00000000);
  return;
}



/* 1400078b0 FUN_1400078b0 */

/* WARNING: Function: _alloca_probe replaced with injection: alloca_probe */

void FUN_1400078b0(ulonglong param_1)

{
  ulonglong uVar1;
  undefined1 *puVar2;
  undefined1 auStack_38 [32];
  undefined1 local_18 [8];
  ulonglong local_10;
  
  puVar2 = auStack_38;
  local_10 = DAT_140013010 ^ (ulonglong)local_18;
  if (~param_1 < 0x4000) {
    local_18[0] = 0;
  }
  else {
    uVar1 = param_1 + 0x400f;
    if (uVar1 <= param_1 + 0x4000) {
      uVar1 = 0xffffffffffffff0;
    }
    puVar2 = auStack_38 + -(uVar1 & 0xfffffffffffffff0);
  }
  *(undefined8 *)(puVar2 + -8) = 0x14000792a;
  __security_check_cookie(DAT_140013010);
  return;
}



/* 140007940 FUN_140007940 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * FUN_140007940(void)

{
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_1400144c8) {
    _Init_thread_header(&DAT_1400144c8);
    if (DAT_1400144c8 == -1) {
      DAT_1400144d0 = 0;
      DAT_1400144d8 = 0;
      _DAT_1400144e0 = 0;
      uRam00000001400144e8 = 0;
      atexit(`private:_static_class_CImage::GetCDCCacheInstance::CDCCache*___ptr64___cdecl_ATL::CImage::GetCDCCacheInstance(void)'
             ::__l2::_dynamic_atexit_destructor_for__cache__);
      _Init_thread_footer(&DAT_1400144c8);
    }
  }
  return &DAT_1400144d0;
}



/* 1400079b0 FUN_1400079b0 */

void FUN_1400079b0(void *param_1,ulonglong param_2,void *param_3,ulonglong param_4)

{
  code *pcVar1;
  int *piVar2;
  
  if (param_4 == 0) {
    return;
  }
  if (param_1 == (void *)0x0) {
    piVar2 = _errno();
    *piVar2 = 0x16;
  }
  else {
    if ((param_3 != (void *)0x0) && (param_4 <= param_2)) {
      memcpy(param_1,param_3,param_4);
      return;
    }
    memset(param_1,0,param_2);
    if (param_3 == (void *)0x0) {
      piVar2 = _errno();
      *piVar2 = 0x16;
    }
    else {
      if (param_4 <= param_2) goto LAB_140007a39;
      piVar2 = _errno();
      *piVar2 = 0x22;
    }
  }
  _invalid_parameter_noinfo();
LAB_140007a39:
  AfxThrowInvalidArgException();
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* 140007a40 FUN_140007a40 */

undefined8 * FUN_140007a40(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = Gdiplus::Image::vftable;
  GdipDisposeImage(param_1[1]);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      GdipFree(param_1);
      return param_1;
    }
    _guard_check_icall();
  }
  return param_1;
}



/* 140007aa0 FUN_140007aa0 */

void FUN_140007aa0(longlong param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 local_res8 [4];
  
  local_res8[0] = 0;
  iVar2 = GdipCloneImage(*(undefined8 *)(param_1 + 8),local_res8);
  if (iVar2 != 0) {
    *(int *)(param_1 + 0x10) = iVar2;
  }
  puVar3 = (undefined8 *)GdipAlloc(0x18);
  if (puVar3 != (undefined8 *)0x0) {
    uVar1 = *(undefined4 *)(param_1 + 0x10);
    *puVar3 = Gdiplus::Image::vftable;
    puVar3[1] = local_res8[0];
    *(undefined4 *)(puVar3 + 2) = uVar1;
    return;
  }
  return;
}



/* 140007b00 FUN_140007b00 */

/* WARNING: Function: _alloca_probe replaced with injection: alloca_probe */

void FUN_140007b00(longlong param_1,longlong param_2)

{
  int *piVar1;
  HDC hdc;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  char cVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  ulonglong uVar11;
  undefined8 *puVar12;
  HDC pHVar13;
  HGDIOBJ pvVar14;
  undefined8 *puVar15;
  ulonglong uVar16;
  uint uVar17;
  undefined8 *_Memory;
  undefined1 *puVar18;
  undefined1 *puVar19;
  void *pvVar20;
  UINT cEntries;
  uint uVar21;
  undefined8 *puVar22;
  void *pvVar23;
  undefined1 auStackY_4e8 [32];
  undefined8 in_stack_fffffffffffffb38;
  undefined8 in_stack_fffffffffffffb40;
  uint local_4a8;
  uint local_4a4;
  uint local_4a0;
  int local_49c;
  undefined4 local_498;
  uint local_494;
  undefined8 local_490;
  undefined8 local_488;
  undefined8 local_480;
  undefined4 local_478;
  undefined4 local_474;
  longlong local_470;
  undefined1 local_468 [8];
  int local_460;
  void *local_458;
  RGBQUAD local_448 [256];
  ulonglong local_48;
  
  puVar18 = auStackY_4e8;
  puVar19 = auStackY_4e8;
  local_48 = DAT_140013010 ^ (ulonglong)&local_4a8;
  local_470 = param_2;
  iVar8 = GdipGetImagePixelFormat(*(undefined8 *)(param_2 + 8),&local_4a4);
  uVar17 = local_4a4;
  if (iVar8 != 0) {
    *(int *)(param_2 + 0x10) = iVar8;
  }
  local_4a8 = 0x20;
  local_4a0 = 0x22009;
  if ((local_4a4 >> 0x11 & 1) != 0) {
    local_4a0 = local_4a4;
    local_4a8 = (int)local_4a4 >> 8 & 0xff;
  }
  uVar9 = local_4a4 & 0x40000;
  if (uVar9 != 0) {
    local_4a0 = 0x26200a;
    local_4a8 = 0x20;
  }
  uVar21 = local_4a8;
  puVar22 = (undefined8 *)0x0;
  local_49c = 0;
  iVar10 = GdipGetImageHeight(*(undefined8 *)(param_2 + 8),&local_49c);
  iVar8 = local_49c;
  if (iVar10 != 0) {
    *(int *)(param_2 + 0x10) = iVar10;
  }
  local_498 = 0;
  iVar10 = GdipGetImageWidth(*(undefined8 *)(param_2 + 8),&local_498);
  if (iVar10 != 0) {
    *(int *)(param_2 + 0x10) = iVar10;
  }
  iVar8 = FUN_140007650(param_1,local_498,iVar8,uVar21,in_stack_fffffffffffffb38,
                        in_stack_fffffffffffffb40,uVar9 != 0);
  if (iVar8 == 0) goto LAB_140007ef4;
  _Memory = puVar22;
  if ((uVar17 >> 0x10 & 1) == 0) {
LAB_140007db8:
    uVar2 = *(undefined4 *)(param_1 + 0x1c);
    uVar3 = *(undefined4 *)(param_1 + 0x18);
    puVar19 = puVar18;
    if (local_4a0 == uVar17) {
      uVar5 = *(undefined8 *)(param_2 + 8);
      local_478 = uVar3;
      local_474 = uVar2;
      *(undefined1 **)(puVar18 + 0x20) = local_468;
      local_480 = 0;
      *(undefined8 *)(puVar18 + -8) = 0x140007df5;
      iVar8 = GdipBitmapLockBits(uVar5,&local_480,1,uVar17);
      if (iVar8 == 0) {
        pvVar20 = *(void **)(param_1 + 0x10);
        uVar16 = (ulonglong)(*(int *)(param_1 + 0x18) * uVar21 + 7 >> 3);
        pvVar23 = local_458;
        if (0 < *(int *)(param_1 + 0x1c)) {
          do {
            *(undefined8 *)(puVar18 + -8) = 0x140007e41;
            FUN_1400079b0(pvVar20,uVar16,pvVar23,uVar16);
            uVar17 = (int)puVar22 + 1;
            puVar22 = (undefined8 *)(ulonglong)uVar17;
            pvVar20 = (void *)((longlong)pvVar20 + (longlong)*(int *)(param_1 + 0x20));
            param_2 = local_470;
            pvVar23 = (void *)((longlong)pvVar23 + (longlong)local_460);
          } while ((int)uVar17 < *(int *)(param_1 + 0x1c));
        }
        uVar5 = *(undefined8 *)(param_2 + 8);
        *(undefined8 *)(puVar18 + -8) = 0x140007e6a;
        iVar8 = GdipBitmapUnlockBits(uVar5,local_468);
        if (iVar8 != 0) {
          *(int *)(param_2 + 0x10) = iVar8;
        }
      }
      else {
        *(int *)(param_2 + 0x10) = iVar8;
      }
    }
    else {
      uVar4 = *(undefined4 *)(param_1 + 0x20);
      *(undefined8 **)(puVar18 + 0x28) = &local_488;
      *(undefined8 *)(puVar18 + 0x20) = *(undefined8 *)(param_1 + 0x10);
      local_488 = 0;
      *(undefined8 *)(puVar18 + -8) = 0x140007e94;
      GdipCreateBitmapFromScan0(uVar3,uVar2,uVar4);
      uVar5 = local_488;
      local_490 = 0;
      *(undefined8 *)(puVar18 + -8) = 0x140007ea6;
      GdipGetImageGraphicsContext(uVar5,&local_490);
      uVar6 = local_490;
      uVar5 = *(undefined8 *)(param_2 + 8);
      *(undefined8 *)(puVar18 + -8) = 0x140007ebd;
      GdipDrawImageI(uVar6,uVar5,0,0);
      *(undefined8 *)(puVar18 + -8) = 0x140007ec6;
      GdipDeleteGraphics(uVar6);
      uVar5 = local_488;
      *(undefined8 *)(puVar18 + -8) = 0x140007ed0;
      GdipDisposeImage(uVar5);
    }
  }
  else {
    local_494 = 0;
    iVar8 = GdipGetImagePaletteSize(*(undefined8 *)(param_2 + 8),&local_494);
    uVar9 = local_494;
    if (iVar8 != 0) {
      *(int *)(param_2 + 0x10) = iVar8;
    }
    uVar16 = (ulonglong)local_494;
    if ((local_494 < 0x401) && (cVar7 = FUN_1400078b0((ulonglong)local_494), cVar7 != '\0')) {
      uVar11 = uVar16 + 0xf;
      if (uVar11 <= uVar16) {
        uVar11 = 0xffffffffffffff0;
      }
      puVar18 = auStackY_4e8 + -(uVar11 & 0xfffffffffffffff0);
      puVar15 = (undefined8 *)((longlong)&local_4a8 + -(uVar11 & 0xfffffffffffffff0));
    }
    else {
      puVar12 = (undefined8 *)malloc(uVar16 + 0x10);
      puVar18 = auStackY_4e8;
      puVar15 = puVar22;
      if (puVar12 != (undefined8 *)0x0) {
        *puVar12 = 0;
        _Memory = puVar12;
        puVar18 = auStackY_4e8;
        puVar15 = puVar12 + 2;
      }
    }
    puVar19 = puVar18;
    if (puVar15 != (undefined8 *)0x0) {
      uVar5 = *(undefined8 *)(param_2 + 8);
      *(undefined8 *)(puVar18 + -8) = 0x140007ca7;
      iVar8 = GdipGetImagePalette(uVar5,puVar15,uVar9);
      if (iVar8 != 0) {
        *(int *)(param_2 + 0x10) = iVar8;
      }
      cEntries = *(UINT *)((longlong)puVar15 + 4);
      if (cEntries - 1 < 0x100) {
        puVar12 = puVar22;
        if (cEntries != 0) {
          do {
            uVar9 = (int)puVar12 + 1;
            uVar2 = *(undefined4 *)((longlong)puVar15 + (longlong)puVar12 * 4 + 8);
            local_448[(longlong)puVar12].rgbBlue = (BYTE)uVar2;
            local_448[(longlong)puVar12].rgbRed = (BYTE)((uint)uVar2 >> 0x10);
            local_448[(longlong)puVar12].rgbGreen = (BYTE)((uint)uVar2 >> 8);
            local_448[(longlong)puVar12].rgbReserved = '\0';
            cEntries = *(uint *)((longlong)puVar15 + 4);
            puVar12 = (undefined8 *)(ulonglong)uVar9;
          } while (uVar9 < cEntries);
        }
        *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
        pHVar13 = *(HDC *)(param_1 + 0x38);
        if (pHVar13 == (HDC)0x0) {
          *(undefined8 *)(puVar18 + -8) = 0x140007d19;
          puVar12 = FUN_140007940();
          puVar15 = puVar22;
          do {
            LOCK();
            pHVar13 = (HDC)puVar12[(int)puVar15];
            puVar12[(int)puVar15] = 0;
            UNLOCK();
            if (pHVar13 != (HDC)0x0) goto LAB_140007d3e;
            uVar17 = (int)puVar15 + 1;
            puVar15 = (undefined8 *)(ulonglong)uVar17;
          } while ((int)uVar17 < 4);
          *(undefined8 *)(puVar18 + -8) = 0x140007d3e;
          pHVar13 = CreateCompatibleDC((HDC)0x0);
LAB_140007d3e:
          pvVar14 = *(HGDIOBJ *)(param_1 + 8);
          *(HDC *)(param_1 + 0x38) = pHVar13;
          *(undefined8 *)(puVar18 + -8) = 0x140007d4f;
          pvVar14 = SelectObject(pHVar13,pvVar14);
          pHVar13 = *(HDC *)(param_1 + 0x38);
          *(HGDIOBJ *)(param_1 + 0x48) = pvVar14;
          uVar17 = local_4a4;
        }
        *(undefined8 *)(puVar18 + -8) = 0x140007d6a;
        SetDIBColorTable(pHVar13,0,cEntries,local_448);
        piVar1 = (int *)(param_1 + 0x40);
        *piVar1 = *piVar1 + -1;
        uVar21 = local_4a8;
        if (*piVar1 == 0) {
          pvVar14 = *(HGDIOBJ *)(param_1 + 0x48);
          pHVar13 = *(HDC *)(param_1 + 0x38);
          *(undefined8 *)(puVar18 + -8) = 0x140007d7e;
          SelectObject(pHVar13,pvVar14);
          pHVar13 = *(HDC *)(param_1 + 0x38);
          *(undefined8 *)(puVar18 + -8) = 0x140007d87;
          puVar12 = FUN_140007940();
          puVar15 = puVar22;
          do {
            LOCK();
            hdc = (HDC)puVar12[(int)puVar15];
            puVar12[(int)puVar15] = pHVar13;
            UNLOCK();
            if (hdc == (HDC)0x0) goto LAB_140007dac;
            uVar17 = (int)puVar15 + 1;
            puVar15 = (undefined8 *)(ulonglong)uVar17;
            pHVar13 = hdc;
          } while ((int)uVar17 < 4);
          *(undefined8 *)(puVar18 + -8) = 0x140007dac;
          DeleteDC(hdc);
LAB_140007dac:
          *(undefined8 *)(param_1 + 0x38) = 0;
          uVar17 = local_4a4;
          uVar21 = local_4a8;
        }
        goto LAB_140007db8;
      }
    }
  }
  while (_Memory != (undefined8 *)0x0) {
    puVar22 = (undefined8 *)*_Memory;
    *(undefined8 *)(puVar19 + -8) = 0x140007eec;
    free(_Memory);
    _Memory = puVar22;
  }
LAB_140007ef4:
  uVar16 = local_48 ^ (ulonglong)&local_4a8;
  *(undefined8 *)(puVar19 + -8) = 0x140007f03;
  __security_check_cookie(uVar16);
  return;
}



/* 140007f20 FUN_140007f20 */

void FUN_140007f20(longlong param_1,LPCSTR param_2)

{
  bool bVar1;
  undefined8 uVar2;
  int iVar3;
  longlong *plVar4;
  undefined1 auStack_198 [32];
  undefined **ppuStack_178;
  undefined8 uStack_170;
  ulonglong uStack_168;
  undefined8 auStack_160 [3];
  undefined1 *puStack_148;
  undefined1 auStack_140 [264];
  ulonglong local_38;
  
  local_38 = DAT_140013010 ^ (ulonglong)auStack_198;
  plVar4 = FUN_140008170();
  if (*(int *)((longlong)plVar4 + 0x34) == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(plVar4 + 1));
    bVar1 = true;
    if (*plVar4 == 0) {
      ppuStack_178 = (undefined **)CONCAT44(ppuStack_178._4_4_,1);
      uStack_170 = 0;
      uStack_168 = 0;
      iVar3 = GdiplusStartup(plVar4,&ppuStack_178,auStack_160);
      bVar1 = true;
      if (iVar3 != 0) {
        bVar1 = false;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(plVar4 + 1));
    if (bVar1) {
      puStack_148 = auStack_140;
      FUN_1400074a0(&puStack_148,param_2,3);
      ppuStack_178 = Gdiplus::Bitmap::vftable;
      auStack_160[0] = 0;
      iVar3 = GdipCreateBitmapFromFile(puStack_148,auStack_160);
      uVar2 = auStack_160[0];
      uStack_170 = auStack_160[0];
      if (puStack_148 != auStack_140) {
        free(puStack_148);
      }
      uStack_168 = uStack_168 & 0xffffffff00000000;
      if (iVar3 == 0) {
        FUN_140007b00(param_1,(longlong)&ppuStack_178);
        GdipDisposeImage(uStack_170);
      }
      else {
        GdipDisposeImage(uVar2);
      }
    }
  }
  __security_check_cookie(local_38 ^ (ulonglong)auStack_198);
  return;
}



/* 140007f5d FUN_140007f5d */

void FUN_140007f5d(LPCRITICAL_SECTION param_1)

{
  bool bVar1;
  undefined8 uVar2;
  int iVar3;
  longlong *unaff_RBX;
  longlong unaff_RBP;
  LPCSTR unaff_R14;
  undefined **local_res20;
  undefined8 in_stack_00000038;
  undefined1 *in_stack_00000050;
  ulonglong in_stack_00000160;
  
  EnterCriticalSection(param_1);
  bVar1 = true;
  if (*unaff_RBX == 0) {
    local_res20 = (undefined **)CONCAT44(local_res20._4_4_,1);
    iVar3 = GdiplusStartup();
    bVar1 = true;
    if (iVar3 != 0) {
      bVar1 = false;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_RBX + 1));
  if (bVar1) {
    in_stack_00000050 = &stack0x00000058;
    FUN_1400074a0(&stack0x00000050,unaff_R14,3);
    local_res20 = Gdiplus::Bitmap::vftable;
    in_stack_00000038 = 0;
    iVar3 = GdipCreateBitmapFromFile(in_stack_00000050,&stack0x00000038);
    uVar2 = in_stack_00000038;
    if (in_stack_00000050 != &stack0x00000058) {
      free(in_stack_00000050);
    }
    if (iVar3 == 0) {
      FUN_140007b00(unaff_RBP,(longlong)&local_res20);
      GdipDisposeImage(uVar2);
    }
    else {
      GdipDisposeImage(uVar2);
    }
  }
  __security_check_cookie(in_stack_00000160 ^ (ulonglong)&stack0x00000000);
  return;
}



/* 140007fc0 FUN_140007fc0 */

void FUN_140007fc0(void)

{
  int iVar1;
  longlong unaff_RBP;
  LPCSTR unaff_R14;
  undefined8 unaff_R15;
  undefined **local_res20;
  undefined8 uStack0000000000000028;
  undefined4 uStack0000000000000030;
  undefined1 *puStack0000000000000050;
  ulonglong in_stack_00000160;
  
  puStack0000000000000050 = &stack0x00000058;
  FUN_1400074a0(&stack0x00000050,unaff_R14,3);
  local_res20 = Gdiplus::Bitmap::vftable;
  iVar1 = GdipCreateBitmapFromFile(puStack0000000000000050,&stack0x00000038);
  uStack0000000000000028 = unaff_R15;
  if (puStack0000000000000050 != &stack0x00000058) {
    free(puStack0000000000000050);
  }
  uStack0000000000000030 = (undefined4)unaff_R15;
  if (iVar1 == 0) {
    FUN_140007b00(unaff_RBP,(longlong)&local_res20);
    GdipDisposeImage(uStack0000000000000028);
  }
  else {
    GdipDisposeImage(unaff_R15);
  }
  __security_check_cookie(in_stack_00000160 ^ (ulonglong)&stack0x00000000);
  return;
}



/* 140008080 FUN_140008080 */

void FUN_140008080(undefined8 *param_1)

{
  longlong *plVar1;
  HGDIOBJ ho;
  longlong *plVar2;
  
  *param_1 = ATL::CImage::vftable;
  ho = (HGDIOBJ)param_1[1];
  if (ho != (HGDIOBJ)0x0) {
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    *(undefined8 *)((longlong)param_1 + 0x2c) = 0xffffffffffffffff;
    *(undefined2 *)(param_1 + 5) = 0;
    DeleteObject(ho);
  }
  plVar2 = FUN_140008170();
  EnterCriticalSection((LPCRITICAL_SECTION)(plVar2 + 1));
  plVar1 = plVar2 + 6;
  *(int *)plVar1 = (int)*plVar1 + -1;
  if ((int)*plVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(plVar2 + 1));
    if (*plVar2 != 0) {
      GdiplusShutdown();
    }
    *plVar2 = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)(plVar2 + 1));
  }
                    /* WARNING: Could not recover jumptable at 0x000140008119. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LeaveCriticalSection((LPCRITICAL_SECTION)(plVar2 + 1));
  return;
}



/* 140008120 FUN_140008120 */

undefined8 * FUN_140008120(undefined8 *param_1,uint param_2)

{
  FUN_140008080(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 140008170 FUN_140008170 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * FUN_140008170(void)

{
  BOOL BVar1;
  DWORD DVar2;
  
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_1400144f0) {
    _Init_thread_header(&DAT_1400144f0);
    if (DAT_1400144f0 == -1) {
      DAT_1400144f8 = 0;
      _DAT_140014528 = 0;
      BVar1 = InitializeCriticalSectionEx((LPCRITICAL_SECTION)&DAT_140014500,0,0);
      if (BVar1 == 0) {
        DVar2 = GetLastError();
        if (0 < (int)DVar2) {
          DVar2 = DVar2 & 0xffff | 0x80070000;
        }
        _DAT_140014528 = CONCAT44(DVar2,_DAT_140014528);
      }
      atexit(FUN_14000b730);
      _Init_thread_footer(&DAT_1400144f0);
    }
  }
  return &DAT_1400144f8;
}



/* 140008210 FUN_140008210 */

undefined8 * FUN_140008210(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = CSimpleException::vftable;
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    _guard_check_icall();
  }
  return param_1;
}



/* 140008250 FUN_140008250 */

CException * FUN_140008250(CException *param_1)

{
  CException::CException(param_1);
  *(undefined8 *)(param_1 + 0x14) = 0;
  *(undefined ***)param_1 = CMemoryException::vftable;
  return param_1;
}



/* 140008280 FUN_140008280 */

void FUN_140008280(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000140008289. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  KillTimer(*(HWND *)(param_1 + 0x40),1);
  return;
}



/* 140008290 FUN_140008290 */

CStatic * FUN_140008290(CStatic *param_1,uint param_2)

{
  CStatic::~CStatic(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    _guard_check_icall();
  }
  return param_1;
}



/* 1400082e0 FUN_1400082e0 */

CSliderCtrl * FUN_1400082e0(CSliderCtrl *param_1,uint param_2)

{
  CSliderCtrl::~CSliderCtrl(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    _guard_check_icall();
  }
  return param_1;
}



/* 140008330 FUN_140008330 */

CComboBox * FUN_140008330(CComboBox *param_1,uint param_2)

{
  CComboBox::~CComboBox(param_1);
  if ((param_2 & 1) != 0) {
    if ((param_2 & 4) == 0) {
      operator_delete(param_1);
      return param_1;
    }
    _guard_check_icall();
  }
  return param_1;
}



/* 140008380 FUN_140008380 */

void FUN_140008380(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000140008386. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EnableWindow(*(undefined8 *)(param_1 + 0x40),0);
  return;
}



/* 140008390 FUN_140008390 */

void FUN_140008390(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000140008399. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EnableWindow(*(undefined8 *)(param_1 + 0x40),1);
  return;
}



/* 1400083a0 FUN_1400083a0 */

void FUN_1400083a0(int param_1)

{
  code *pcVar1;
  
  if (param_1 == -0x7ff8fff2) {
    AfxThrowMemoryException();
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  AfxThrowOleException(param_1);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* 1400083c0 FUN_1400083c0 */

undefined * FUN_1400083c0(void)

{
  return &DAT_140014530;
}



/* 1400083d0 FUN_1400083d0 */

void FUN_1400083d0(longlong param_1)

{
  if (*(void **)(param_1 + 0x50) != (void *)0x0) {
    operator_delete__(*(void **)(param_1 + 0x50));
    *(undefined8 *)(param_1 + 0x50) = 0;
  }
  if (*(void **)(param_1 + 0x58) != (void *)0x0) {
    operator_delete__(*(void **)(param_1 + 0x58));
    *(undefined8 *)(param_1 + 0x58) = 0;
  }
  if (*(void **)(param_1 + 0x70) != (void *)0x0) {
    operator_delete__(*(void **)(param_1 + 0x70));
    *(undefined8 *)(param_1 + 0x70) = 0;
  }
  if (*(void **)(param_1 + 0x78) != (void *)0x0) {
    operator_delete__(*(void **)(param_1 + 0x78));
    *(undefined8 *)(param_1 + 0x78) = 0;
  }
  if (*(void **)(param_1 + 0x80) != (void *)0x0) {
    operator_delete__(*(void **)(param_1 + 0x80));
    *(undefined8 *)(param_1 + 0x80) = 0;
  }
  if (*(void **)(param_1 + 0x98) != (void *)0x0) {
    operator_delete__(*(void **)(param_1 + 0x98));
    *(undefined8 *)(param_1 + 0x98) = 0;
  }
  if (*(void **)(param_1 + 0xa0) != (void *)0x0) {
    operator_delete__(*(void **)(param_1 + 0xa0));
    *(undefined8 *)(param_1 + 0xa0) = 0;
  }
  if (*(void **)(param_1 + 0xa8) != (void *)0x0) {
    operator_delete__(*(void **)(param_1 + 0xa8));
    *(undefined8 *)(param_1 + 0xa8) = 0;
  }
  if (*(void **)(param_1 + 0x88) != (void *)0x0) {
    operator_delete__(*(void **)(param_1 + 0x88));
    *(undefined8 *)(param_1 + 0x88) = 0;
  }
  if (*(void **)(param_1 + 0x20) != (void *)0x0) {
    operator_delete__(*(void **)(param_1 + 0x20));
  }
  if (*(HGDIOBJ *)(param_1 + 0x30) != (HGDIOBJ)0x0) {
    DeleteObject(*(HGDIOBJ *)(param_1 + 0x30));
  }
  return;
}



/* 1400084e0 FUN_1400084e0 */

void FUN_1400084e0(longlong *param_1,undefined8 param_2,longlong param_3,float param_4,int param_5)

{
  float *pfVar1;
  float *pfVar2;
  double *pdVar3;
  double *pdVar4;
  int iVar5;
  float fVar6;
  double dVar7;
  int iVar8;
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  double dVar13;
  int iVar14;
  __uint64 _Var15;
  void *pvVar16;
  double *pdVar17;
  undefined8 *puVar18;
  float *pfVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  longlong lVar23;
  int iVar24;
  longlong lVar25;
  undefined8 uVar26;
  double dVar27;
  
  if ((int)param_1[2] != 8) {
                    /* WARNING: Could not recover jumptable at 0x00014000851a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    AfxMessageBox("Only for 8 bits gray image!",0,0);
    return;
  }
  iVar24 = *(int *)((longlong)param_1 + 0x3c);
  *(undefined4 *)(param_1 + 9) = 8;
  iVar21 = (int)param_1[8];
  iVar14 = (int)(iVar24 + 3 + (iVar24 + 3 >> 0x1f & 3U)) >> 2;
  *(int *)(param_1 + 0x17) = iVar24;
  *(int *)((longlong)param_1 + 0xbc) = iVar21;
  param_1[0x16] = param_1[3];
  iVar5 = iVar14 * 4;
  if (param_5 == 1) {
    if ((void *)param_1[0x14] != (void *)0x0) {
      operator_delete__((void *)param_1[0x14]);
      iVar21 = (int)param_1[8];
      iVar24 = *(int *)((longlong)param_1 + 0x3c);
      param_1[0x14] = 0;
    }
    auVar9._8_8_ = 0;
    auVar9._0_8_ = (longlong)(iVar24 * iVar21);
    _Var15 = SUB168(ZEXT816(8) * auVar9,0);
    if (SUB168(ZEXT816(8) * auVar9,8) != 0) {
      _Var15 = 0xffffffffffffffff;
    }
    pvVar16 = operator_new__(_Var15);
    param_1[0x14] = (longlong)pvVar16;
  }
  else if (param_5 == 2) {
    if ((void *)param_1[0x15] != (void *)0x0) {
      operator_delete__((void *)param_1[0x15]);
      iVar21 = (int)param_1[8];
      iVar24 = *(int *)((longlong)param_1 + 0x3c);
      param_1[0x15] = 0;
    }
    auVar10._8_8_ = 0;
    auVar10._0_8_ = (longlong)(iVar24 * iVar21);
    _Var15 = SUB168(ZEXT816(8) * auVar10,0);
    if (SUB168(ZEXT816(8) * auVar10,8) != 0) {
      _Var15 = 0xffffffffffffffff;
    }
    pvVar16 = operator_new__(_Var15);
    param_1[0x15] = (longlong)pvVar16;
  }
  else {
    if ((void *)param_1[0x13] != (void *)0x0) {
      operator_delete__((void *)param_1[0x13]);
      iVar21 = (int)param_1[8];
      iVar24 = *(int *)((longlong)param_1 + 0x3c);
      param_1[0x13] = 0;
    }
    auVar11._8_8_ = 0;
    auVar11._0_8_ = (longlong)(iVar24 * iVar21);
    _Var15 = SUB168(ZEXT816(8) * auVar11,0);
    if (SUB168(ZEXT816(8) * auVar11,8) != 0) {
      _Var15 = 0xffffffffffffffff;
    }
    pvVar16 = operator_new__(_Var15);
    param_1[0x13] = (longlong)pvVar16;
    if ((void *)param_1[10] != (void *)0x0) {
      operator_delete__((void *)param_1[10]);
      param_1[10] = 0;
    }
    pvVar16 = operator_new__((longlong)((int)param_1[8] * iVar5));
    iVar24 = 0;
    param_1[10] = (longlong)pvVar16;
    if (0 < (int)param_1[8]) {
      do {
        iVar21 = 0;
        if (0 < *(int *)((longlong)param_1 + 0x3c)) {
          lVar23 = 0;
          do {
            lVar23 = lVar23 + 1;
            iVar20 = iVar24 * *(int *)((longlong)param_1 + 0x3c) + iVar21;
            iVar21 = iVar21 + 1;
            *(double *)(param_1[0x13] + (longlong)iVar20 * 8) =
                 (double)*(byte *)(*param_1 + (longlong)(iVar14 * iVar24 * 4) + -1 + lVar23);
          } while (iVar21 < *(int *)((longlong)param_1 + 0x3c));
        }
        iVar24 = iVar24 + 1;
      } while (iVar24 < (int)param_1[8]);
    }
  }
  iVar24 = *(int *)((longlong)param_1 + 0x3c) + 2;
  auVar12._8_8_ = 0;
  auVar12._0_8_ = (longlong)(((int)param_1[8] + 2) * iVar24);
  _Var15 = SUB168(ZEXT816(8) * auVar12,0);
  if (SUB168(ZEXT816(8) * auVar12,8) != 0) {
    _Var15 = 0xffffffffffffffff;
  }
  pvVar16 = operator_new__(_Var15);
  iVar21 = (int)param_1[8];
  iVar14 = 0;
  if (0 < iVar21 + 2) {
    iVar20 = 0;
    do {
      iVar21 = *(int *)((longlong)param_1 + 0x3c);
      iVar22 = 0;
      lVar23 = 0;
      if (0 < iVar21 + 2) {
        lVar25 = -8;
        do {
          puVar18 = (undefined8 *)param_1[0x13];
          if (iVar14 < 1) {
            if (0 < lVar23) {
              if (iVar21 < iVar22) {
                uVar26 = puVar18[(longlong)iVar21 + -1];
                goto LAB_140008835;
              }
              puVar18 = (undefined8 *)((longlong)puVar18 + lVar25);
            }
            uVar26 = *puVar18;
          }
          else {
            iVar8 = (int)param_1[8];
            if (iVar8 < iVar14) {
              if (lVar23 < 1) {
                uVar26 = puVar18[(iVar8 + -1) * iVar21];
              }
              else if (iVar21 < iVar22) {
                uVar26 = puVar18[(longlong)(iVar8 * iVar21) + -1];
              }
              else {
                uVar26 = puVar18[(longlong)((iVar8 + -1) * iVar21 + iVar22) + -1];
              }
            }
            else if (lVar23 < 1) {
              uVar26 = puVar18[(iVar14 + -1) * iVar21];
            }
            else {
              if (iVar21 < iVar22) {
                iVar21 = iVar21 * iVar14;
              }
              else {
                iVar21 = (iVar14 + -1) * iVar21 + iVar22;
              }
              uVar26 = puVar18[(longlong)iVar21 + -1];
            }
          }
LAB_140008835:
          *(undefined8 *)((longlong)pvVar16 + (iVar20 + lVar23) * 8) = uVar26;
          iVar22 = iVar22 + 1;
          iVar21 = *(int *)((longlong)param_1 + 0x3c);
          lVar23 = lVar23 + 1;
          lVar25 = lVar25 + 8;
        } while (iVar22 < iVar21 + 2);
      }
      iVar21 = (int)param_1[8];
      iVar14 = iVar14 + 1;
      iVar20 = iVar20 + iVar24;
    } while (iVar14 < iVar21 + 2);
  }
  dVar13 = DAT_14000eea8;
  iVar14 = 0;
  if (0 < iVar21) {
    iVar20 = 0;
    iVar21 = 0;
    do {
      iVar22 = 0;
      if (0 < *(int *)((longlong)param_1 + 0x3c)) {
        do {
          dVar27 = 0.0;
          pfVar19 = (float *)(param_3 + 8);
          pdVar17 = (double *)((longlong)pvVar16 + ((longlong)(iVar21 + iVar22) + 2) * 8);
          lVar23 = 3;
          do {
            pfVar1 = pfVar19 + -2;
            pfVar2 = pfVar19 + -1;
            pdVar3 = pdVar17 + -2;
            pdVar4 = pdVar17 + -1;
            fVar6 = *pfVar19;
            pfVar19 = pfVar19 + 3;
            dVar7 = *pdVar17;
            pdVar17 = pdVar17 + iVar24;
            dVar27 = (double)*pfVar1 * *pdVar3 + dVar27 + (double)*pfVar2 * *pdVar4 +
                     (double)fVar6 * dVar7;
            lVar23 = lVar23 + -1;
          } while (lVar23 != 0);
          dVar27 = dVar27 / (double)param_4;
          if (param_5 == 1) {
            *(double *)
             (param_1[0x14] + (longlong)(*(int *)((longlong)param_1 + 0x3c) * iVar14 + iVar22) * 8)
                 = dVar27;
          }
          else if (param_5 == 2) {
            *(double *)
             (param_1[0x15] + (longlong)(*(int *)((longlong)param_1 + 0x3c) * iVar14 + iVar22) * 8)
                 = dVar27;
          }
          else {
            lVar23 = param_1[10];
            lVar25 = (longlong)(iVar22 + iVar20);
            if (dVar27 <= dVar13) {
              if (0.0 <= dVar27) {
                *(char *)(lVar25 + lVar23) = (char)(int)dVar27;
              }
              else {
                *(undefined1 *)(lVar25 + lVar23) = 0;
              }
            }
            else {
              *(undefined1 *)(lVar25 + lVar23) = 0xff;
            }
          }
          iVar22 = iVar22 + 1;
        } while (iVar22 < *(int *)((longlong)param_1 + 0x3c));
      }
      iVar14 = iVar14 + 1;
      iVar21 = iVar21 + iVar24;
      iVar20 = iVar20 + iVar5;
    } while (iVar14 < (int)param_1[8]);
  }
  if (pvVar16 != (void *)0x0) {
    operator_delete__(pvVar16);
  }
  return;
}



/* 140008525 FUN_140008525 */

void FUN_140008525(longlong param_1,undefined8 param_2,int param_3)

{
  float *pfVar1;
  float *pfVar2;
  double *pdVar3;
  double *pdVar4;
  float fVar5;
  double dVar6;
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  double dVar11;
  int iVar12;
  __uint64 _Var13;
  void *pvVar14;
  double *pdVar15;
  int iVar16;
  undefined8 *puVar17;
  float *pfVar18;
  longlong *unaff_RBX;
  int iVar19;
  longlong unaff_RBP;
  int iVar20;
  longlong lVar21;
  int iVar22;
  int iVar23;
  longlong lVar24;
  undefined8 uVar25;
  double dVar26;
  float unaff_XMM6_Da;
  int iStack0000000000000070;
  int iStack0000000000000078;
  longlong in_stack_00000080;
  int in_stack_00000090;
  
  *(undefined4 *)(param_1 + 0x48) = 8;
  iVar23 = *(int *)(param_1 + 0x40);
  iVar12 = (int)(param_3 + 3 + (param_3 + 3 >> 0x1f & 3U)) >> 2;
  *(int *)(param_1 + 0xb8) = param_3;
  *(int *)(param_1 + 0xbc) = iVar23;
  unaff_RBX[0x16] = *(longlong *)(param_1 + 0x18);
  iVar16 = iVar12 * 4;
  iStack0000000000000070 = iVar16;
  if (in_stack_00000090 == 1) {
    if ((void *)unaff_RBX[0x14] != (void *)0x0) {
      operator_delete__((void *)unaff_RBX[0x14]);
      iVar23 = (int)unaff_RBX[8];
      param_3 = *(int *)((longlong)unaff_RBX + 0x3c);
      unaff_RBX[0x14] = 0;
    }
    auVar7._8_8_ = 0;
    auVar7._0_8_ = (longlong)(param_3 * iVar23);
    _Var13 = SUB168(ZEXT816(8) * auVar7,0);
    if (SUB168(ZEXT816(8) * auVar7,8) != 0) {
      _Var13 = 0xffffffffffffffff;
    }
    pvVar14 = operator_new__(_Var13);
    unaff_RBX[0x14] = (longlong)pvVar14;
  }
  else if (in_stack_00000090 == 2) {
    if ((void *)unaff_RBX[0x15] != (void *)0x0) {
      operator_delete__((void *)unaff_RBX[0x15]);
      iVar23 = (int)unaff_RBX[8];
      param_3 = *(int *)((longlong)unaff_RBX + 0x3c);
      unaff_RBX[0x15] = 0;
    }
    auVar8._8_8_ = 0;
    auVar8._0_8_ = (longlong)(param_3 * iVar23);
    _Var13 = SUB168(ZEXT816(8) * auVar8,0);
    if (SUB168(ZEXT816(8) * auVar8,8) != 0) {
      _Var13 = 0xffffffffffffffff;
    }
    pvVar14 = operator_new__(_Var13);
    unaff_RBX[0x15] = (longlong)pvVar14;
  }
  else {
    if ((void *)unaff_RBX[0x13] != (void *)0x0) {
      operator_delete__((void *)unaff_RBX[0x13]);
      iVar23 = (int)unaff_RBX[8];
      param_3 = *(int *)((longlong)unaff_RBX + 0x3c);
      unaff_RBX[0x13] = 0;
    }
    auVar9._8_8_ = 0;
    auVar9._0_8_ = (longlong)(param_3 * iVar23);
    _Var13 = SUB168(ZEXT816(8) * auVar9,0);
    if (SUB168(ZEXT816(8) * auVar9,8) != 0) {
      _Var13 = 0xffffffffffffffff;
    }
    pvVar14 = operator_new__(_Var13);
    unaff_RBX[0x13] = (longlong)pvVar14;
    if ((void *)unaff_RBX[10] != (void *)0x0) {
      operator_delete__((void *)unaff_RBX[10]);
      unaff_RBX[10] = 0;
    }
    pvVar14 = operator_new__((longlong)((int)unaff_RBX[8] * iVar16));
    iVar23 = 0;
    unaff_RBX[10] = (longlong)pvVar14;
    if (0 < (int)unaff_RBX[8]) {
      do {
        iVar22 = 0;
        if (0 < *(int *)((longlong)unaff_RBX + 0x3c)) {
          lVar21 = 0;
          do {
            lVar21 = lVar21 + 1;
            iVar19 = iVar23 * *(int *)((longlong)unaff_RBX + 0x3c) + iVar22;
            iVar22 = iVar22 + 1;
            *(double *)(unaff_RBX[0x13] + (longlong)iVar19 * 8) =
                 (double)*(byte *)(*unaff_RBX + (longlong)(iVar12 * iVar23 * 4) + -1 + lVar21);
          } while (iVar22 < *(int *)((longlong)unaff_RBX + 0x3c));
        }
        iVar23 = iVar23 + 1;
      } while (iVar23 < (int)unaff_RBX[8]);
    }
  }
  iVar23 = *(int *)((longlong)unaff_RBX + 0x3c) + 2;
  auVar10._8_8_ = 0;
  auVar10._0_8_ = (longlong)(((int)unaff_RBX[8] + 2) * iVar23);
  _Var13 = SUB168(ZEXT816(8) * auVar10,0);
  if (SUB168(ZEXT816(8) * auVar10,8) != 0) {
    _Var13 = 0xffffffffffffffff;
  }
  iStack0000000000000078 = iVar23;
  pvVar14 = operator_new__(_Var13);
  iVar12 = (int)unaff_RBX[8];
  iVar22 = 0;
  if (0 < iVar12 + 2) {
    iVar19 = 0;
    do {
      iVar16 = *(int *)((longlong)unaff_RBX + 0x3c);
      iVar12 = 0;
      lVar21 = 0;
      if (0 < iVar16 + 2) {
        lVar24 = -8;
        do {
          puVar17 = (undefined8 *)unaff_RBX[0x13];
          if (iVar22 < 1) {
            if (0 < lVar21) {
              if (iVar16 < iVar12) {
                uVar25 = puVar17[(longlong)iVar16 + -1];
                goto LAB_140008835;
              }
              puVar17 = (undefined8 *)((longlong)puVar17 + lVar24);
            }
            uVar25 = *puVar17;
          }
          else {
            iVar23 = (int)unaff_RBX[8];
            if (iVar23 < iVar22) {
              if (lVar21 < 1) {
                uVar25 = puVar17[(iVar23 + -1) * iVar16];
              }
              else if (iVar16 < iVar12) {
                uVar25 = puVar17[(longlong)(iVar23 * iVar16) + -1];
              }
              else {
                uVar25 = puVar17[(longlong)((iVar23 + -1) * iVar16 + iVar12) + -1];
              }
            }
            else if (lVar21 < 1) {
              uVar25 = puVar17[(iVar22 + -1) * iVar16];
            }
            else {
              if (iVar16 < iVar12) {
                iVar16 = iVar16 * iVar22;
              }
              else {
                iVar16 = (iVar22 + -1) * iVar16 + iVar12;
              }
              uVar25 = puVar17[(longlong)iVar16 + -1];
            }
          }
LAB_140008835:
          *(undefined8 *)((longlong)pvVar14 + (iVar19 + lVar21) * 8) = uVar25;
          iVar12 = iVar12 + 1;
          iVar16 = *(int *)((longlong)unaff_RBX + 0x3c);
          lVar21 = lVar21 + 1;
          lVar24 = lVar24 + 8;
          iVar23 = iStack0000000000000078;
        } while (iVar12 < iVar16 + 2);
      }
      iVar12 = (int)unaff_RBX[8];
      iVar22 = iVar22 + 1;
      iVar19 = iVar19 + iVar23;
      unaff_RBP = in_stack_00000080;
      iVar16 = iStack0000000000000070;
    } while (iVar22 < iVar12 + 2);
  }
  dVar11 = DAT_14000eea8;
  iVar22 = 0;
  if (0 < iVar12) {
    iVar19 = 0;
    iVar12 = 0;
    do {
      iVar20 = 0;
      if (0 < *(int *)((longlong)unaff_RBX + 0x3c)) {
        do {
          dVar26 = 0.0;
          pfVar18 = (float *)(unaff_RBP + 8);
          pdVar15 = (double *)((longlong)pvVar14 + ((longlong)(iVar12 + iVar20) + 2) * 8);
          lVar21 = 3;
          do {
            pfVar1 = pfVar18 + -2;
            pfVar2 = pfVar18 + -1;
            pdVar3 = pdVar15 + -2;
            pdVar4 = pdVar15 + -1;
            fVar5 = *pfVar18;
            pfVar18 = pfVar18 + 3;
            dVar6 = *pdVar15;
            pdVar15 = pdVar15 + iVar23;
            dVar26 = (double)*pfVar1 * *pdVar3 + dVar26 + (double)*pfVar2 * *pdVar4 +
                     (double)fVar5 * dVar6;
            lVar21 = lVar21 + -1;
          } while (lVar21 != 0);
          dVar26 = dVar26 / (double)unaff_XMM6_Da;
          if (in_stack_00000090 == 1) {
            *(double *)
             (unaff_RBX[0x14] +
             (longlong)(*(int *)((longlong)unaff_RBX + 0x3c) * iVar22 + iVar20) * 8) = dVar26;
          }
          else if (in_stack_00000090 == 2) {
            *(double *)
             (unaff_RBX[0x15] +
             (longlong)(*(int *)((longlong)unaff_RBX + 0x3c) * iVar22 + iVar20) * 8) = dVar26;
          }
          else {
            lVar21 = unaff_RBX[10];
            lVar24 = (longlong)(iVar20 + iVar19);
            if (dVar26 <= dVar11) {
              if (0.0 <= dVar26) {
                *(char *)(lVar24 + lVar21) = (char)(int)dVar26;
              }
              else {
                *(undefined1 *)(lVar24 + lVar21) = 0;
              }
            }
            else {
              *(undefined1 *)(lVar24 + lVar21) = 0xff;
            }
          }
          iVar20 = iVar20 + 1;
        } while (iVar20 < *(int *)((longlong)unaff_RBX + 0x3c));
      }
      iVar22 = iVar22 + 1;
      iVar12 = iVar12 + iVar23;
      iVar19 = iVar19 + iVar16;
      unaff_RBP = in_stack_00000080;
    } while (iVar22 < (int)unaff_RBX[8]);
  }
  if (pvVar14 != (void *)0x0) {
    operator_delete__(pvVar14);
  }
  return;
}



/* 1400089d6 FUN_1400089d6 */

void FUN_1400089d6(void)

{
  void *unaff_RDI;
  
  operator_delete__(unaff_RDI);
  return;
}



/* 1400089f0 FUN_1400089f0 */

void FUN_1400089f0(longlong *param_1)

{
  double dVar1;
  undefined1 auVar2 [16];
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  int iVar8;
  void *pvVar9;
  __uint64 _Var10;
  longlong lVar11;
  int iVar12;
  longlong lVar13;
  int iVar14;
  longlong in_R8;
  uint uVar15;
  int iVar16;
  double dVar17;
  double dVar18;
  float in_XMM3_Da;
  
  if ((int)param_1[2] != 8) {
                    /* WARNING: Could not recover jumptable at 0x000140008a30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    AfxMessageBox("Only for 8 bits gray image!",0,0);
    return;
  }
  *(int *)(param_1 + 0x17) = *(int *)((longlong)param_1 + 0x3c);
  iVar12 = *(int *)((longlong)param_1 + 0x3c) + 3;
  *(undefined4 *)(param_1 + 9) = 8;
  iVar16 = (int)param_1[8];
  uVar15 = (iVar12 >> 0x1f & 3U) + iVar12 & 0xfffffffc;
  *(int *)((longlong)param_1 + 0xbc) = iVar16;
  param_1[0x16] = param_1[3];
  if ((void *)param_1[10] != (void *)0x0) {
    operator_delete__((void *)param_1[10]);
    iVar16 = (int)param_1[8];
    param_1[10] = 0;
  }
  pvVar9 = operator_new__((longlong)(int)(iVar16 * uVar15));
  param_1[10] = (longlong)pvVar9;
  if ((void *)param_1[0x13] != (void *)0x0) {
    operator_delete__((void *)param_1[0x13]);
    param_1[0x13] = 0;
  }
  auVar2._8_8_ = 0;
  auVar2._0_8_ = (longlong)((int)param_1[8] * *(int *)((longlong)param_1 + 0x3c));
  lVar11 = SUB168(ZEXT816(8) * auVar2,8);
  _Var10 = SUB168(ZEXT816(8) * auVar2,0);
  if (lVar11 != 0) {
    _Var10 = 0xffffffffffffffff;
  }
  pvVar9 = operator_new__(_Var10);
  dVar7 = DAT_14000eea8;
  dVar4 = DAT_14000ee90;
  iVar12 = 0;
  param_1[0x13] = (longlong)pvVar9;
  if (0 < (int)param_1[8]) {
    iVar16 = 0;
    do {
      iVar14 = 0;
      if (0 < *(int *)((longlong)param_1 + 0x3c)) {
        lVar13 = (longlong)iVar16;
        do {
          dVar17 = sin(((double)((uint)*(byte *)(*param_1 + lVar13) * 2) * dVar4) / dVar7);
          lVar13 = lVar13 + 1;
          iVar8 = iVar12 * *(int *)((longlong)param_1 + 0x3c) + iVar14;
          iVar14 = iVar14 + 1;
          *(double *)(param_1[0x13] + (longlong)iVar8 * 8) = dVar17;
        } while (iVar14 < *(int *)((longlong)param_1 + 0x3c));
      }
      iVar12 = iVar12 + 1;
      iVar16 = iVar16 + uVar15;
    } while (iVar12 < (int)param_1[8]);
  }
  FUN_1400084e0(param_1,lVar11,in_R8,in_XMM3_Da,1);
  iVar12 = 0;
  if (0 < (int)param_1[8]) {
    iVar16 = 0;
    do {
      iVar14 = 0;
      if (0 < *(int *)((longlong)param_1 + 0x3c)) {
        lVar13 = (longlong)iVar16;
        do {
          dVar17 = cos(((double)((uint)*(byte *)(*param_1 + lVar13) * 2) * dVar4) / dVar7);
          lVar13 = lVar13 + 1;
          iVar8 = iVar12 * *(int *)((longlong)param_1 + 0x3c) + iVar14;
          iVar14 = iVar14 + 1;
          *(double *)(param_1[0x13] + (longlong)iVar8 * 8) = dVar17;
        } while (iVar14 < *(int *)((longlong)param_1 + 0x3c));
      }
      iVar12 = iVar12 + 1;
      iVar16 = iVar16 + uVar15;
    } while (iVar12 < (int)param_1[8]);
  }
  FUN_1400084e0(param_1,lVar11,in_R8,in_XMM3_Da,2);
  dVar6 = DAT_14000eea0;
  dVar5 = DAT_14000ee98;
  dVar3 = DAT_14000ee88;
  dVar17 = DAT_14000ee80;
  iVar12 = 0;
  if (0 < (int)param_1[8]) {
    iVar16 = 0;
    do {
      iVar14 = *(int *)((longlong)param_1 + 0x3c);
      iVar8 = 0;
      if (0 < iVar14) {
        lVar11 = (longlong)iVar16;
        do {
          lVar13 = (longlong)(iVar14 * iVar12 + iVar8);
          dVar18 = *(double *)(param_1[0x15] + lVar13 * 8);
          if (0.0 <= dVar18) {
            dVar1 = *(double *)(param_1[0x14] + lVar13 * 8);
            if (dVar18 != 0.0) {
              dVar18 = atan(dVar1 / dVar18);
              goto LAB_140008cfe;
            }
            dVar18 = dVar5;
            if (0.0 < dVar1) {
              dVar18 = dVar3;
            }
          }
          else {
            dVar1 = *(double *)(param_1[0x14] + lVar13 * 8);
            dVar18 = atan(dVar1 / dVar18);
            if (dVar1 <= 0.0) {
              dVar18 = dVar18 - dVar4;
            }
            else {
              dVar18 = dVar18 + dVar4;
            }
LAB_140008cfe:
            if (dVar18 < 0.0) {
              dVar18 = dVar18 + dVar6;
            }
          }
          iVar8 = iVar8 + 1;
          *(char *)(lVar11 + param_1[10]) = (char)(int)((dVar18 * dVar7 * dVar17) / dVar4);
          lVar11 = lVar11 + 1;
          iVar14 = *(int *)((longlong)param_1 + 0x3c);
        } while (iVar8 < iVar14);
      }
      iVar12 = iVar12 + 1;
      iVar16 = iVar16 + uVar15;
    } while (iVar12 < (int)param_1[8]);
  }
  return;
}



/* 140008aed FUN_140008aed */

void FUN_140008aed(int param_1)

{
  double dVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  int iVar9;
  ulonglong in_RAX;
  __uint64 _Var10;
  void *pvVar11;
  longlong lVar12;
  longlong *unaff_RBX;
  int iVar13;
  longlong lVar14;
  int iVar15;
  int unaff_R12D;
  int iVar16;
  longlong unaff_R15;
  double dVar17;
  double dVar18;
  float unaff_XMM6_Da;
  
  auVar2._8_8_ = 0;
  auVar2._0_8_ = in_RAX;
  auVar3._8_8_ = 0;
  auVar3._0_8_ = (longlong)param_1;
  lVar12 = SUB168(auVar2 * auVar3,8);
  _Var10 = SUB168(auVar2 * auVar3,0);
  if (lVar12 != 0) {
    _Var10 = 0xffffffffffffffff;
  }
  pvVar11 = operator_new__(_Var10);
  dVar8 = DAT_14000eea8;
  dVar5 = DAT_14000ee90;
  iVar13 = 0;
  unaff_RBX[0x13] = (longlong)pvVar11;
  if (0 < (int)unaff_RBX[8]) {
    iVar16 = 0;
    do {
      iVar15 = 0;
      if (0 < *(int *)((longlong)unaff_RBX + 0x3c)) {
        lVar14 = (longlong)iVar16;
        do {
          dVar17 = sin(((double)((uint)*(byte *)(*unaff_RBX + lVar14) * 2) * dVar5) / dVar8);
          lVar14 = lVar14 + 1;
          iVar9 = iVar13 * *(int *)((longlong)unaff_RBX + 0x3c) + iVar15;
          iVar15 = iVar15 + 1;
          *(double *)(unaff_RBX[0x13] + (longlong)iVar9 * 8) = dVar17;
        } while (iVar15 < *(int *)((longlong)unaff_RBX + 0x3c));
      }
      iVar13 = iVar13 + 1;
      iVar16 = iVar16 + unaff_R12D;
    } while (iVar13 < (int)unaff_RBX[8]);
  }
  FUN_1400084e0(unaff_RBX,lVar12,unaff_R15,unaff_XMM6_Da,1);
  iVar13 = 0;
  if (0 < (int)unaff_RBX[8]) {
    iVar16 = 0;
    do {
      iVar15 = 0;
      if (0 < *(int *)((longlong)unaff_RBX + 0x3c)) {
        lVar14 = (longlong)iVar16;
        do {
          dVar17 = cos(((double)((uint)*(byte *)(*unaff_RBX + lVar14) * 2) * dVar5) / dVar8);
          lVar14 = lVar14 + 1;
          iVar9 = iVar13 * *(int *)((longlong)unaff_RBX + 0x3c) + iVar15;
          iVar15 = iVar15 + 1;
          *(double *)(unaff_RBX[0x13] + (longlong)iVar9 * 8) = dVar17;
        } while (iVar15 < *(int *)((longlong)unaff_RBX + 0x3c));
      }
      iVar13 = iVar13 + 1;
      iVar16 = iVar16 + unaff_R12D;
    } while (iVar13 < (int)unaff_RBX[8]);
  }
  FUN_1400084e0(unaff_RBX,lVar12,unaff_R15,unaff_XMM6_Da,2);
  dVar7 = DAT_14000eea0;
  dVar6 = DAT_14000ee98;
  dVar4 = DAT_14000ee88;
  dVar17 = DAT_14000ee80;
  iVar13 = 0;
  if (0 < (int)unaff_RBX[8]) {
    iVar16 = 0;
    do {
      iVar15 = *(int *)((longlong)unaff_RBX + 0x3c);
      iVar9 = 0;
      if (0 < iVar15) {
        lVar12 = (longlong)iVar16;
        do {
          lVar14 = (longlong)(iVar15 * iVar13 + iVar9);
          dVar18 = *(double *)(unaff_RBX[0x15] + lVar14 * 8);
          if (0.0 <= dVar18) {
            dVar1 = *(double *)(unaff_RBX[0x14] + lVar14 * 8);
            if (dVar18 != 0.0) {
              dVar18 = atan(dVar1 / dVar18);
              goto LAB_140008cfe;
            }
            dVar18 = dVar6;
            if (0.0 < dVar1) {
              dVar18 = dVar4;
            }
          }
          else {
            dVar1 = *(double *)(unaff_RBX[0x14] + lVar14 * 8);
            dVar18 = atan(dVar1 / dVar18);
            if (dVar1 <= 0.0) {
              dVar18 = dVar18 - dVar5;
            }
            else {
              dVar18 = dVar18 + dVar5;
            }
LAB_140008cfe:
            if (dVar18 < 0.0) {
              dVar18 = dVar18 + dVar7;
            }
          }
          iVar9 = iVar9 + 1;
          *(char *)(lVar12 + unaff_RBX[10]) = (char)(int)((dVar18 * dVar8 * dVar17) / dVar5);
          lVar12 = lVar12 + 1;
          iVar15 = *(int *)((longlong)unaff_RBX + 0x3c);
        } while (iVar9 < iVar15);
      }
      iVar13 = iVar13 + 1;
      iVar16 = iVar16 + unaff_R12D;
    } while (iVar13 < (int)unaff_RBX[8]);
  }
  return;
}



/* 140008c2d FUN_140008c2d */

void FUN_140008c2d(void)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  int iVar6;
  longlong lVar7;
  longlong unaff_RBX;
  int unaff_EBP;
  int iVar8;
  longlong lVar9;
  int unaff_R12D;
  int iVar10;
  double dVar11;
  undefined4 unaff_XMM8_Da;
  undefined4 unaff_XMM8_Db;
  undefined4 unaff_XMM9_Da;
  undefined4 unaff_XMM9_Db;
  
  dVar5 = DAT_14000eea0;
  dVar4 = DAT_14000ee98;
  dVar3 = DAT_14000ee88;
  dVar2 = DAT_14000ee80;
  iVar10 = 0;
  do {
    iVar6 = *(int *)(unaff_RBX + 0x3c);
    iVar8 = 0;
    if (0 < iVar6) {
      lVar9 = (longlong)iVar10;
      do {
        lVar7 = (longlong)(iVar6 * unaff_EBP + iVar8);
        dVar11 = *(double *)(*(longlong *)(unaff_RBX + 0xa8) + lVar7 * 8);
        if (0.0 <= dVar11) {
          dVar1 = *(double *)(*(longlong *)(unaff_RBX + 0xa0) + lVar7 * 8);
          if (dVar11 != 0.0) {
            dVar11 = atan(dVar1 / dVar11);
            goto LAB_140008cfe;
          }
          dVar11 = dVar4;
          if (0.0 < dVar1) {
            dVar11 = dVar3;
          }
        }
        else {
          dVar1 = *(double *)(*(longlong *)(unaff_RBX + 0xa0) + lVar7 * 8);
          dVar11 = atan(dVar1 / dVar11);
          if (dVar1 <= 0.0) {
            dVar11 = dVar11 - (double)CONCAT44(unaff_XMM8_Db,unaff_XMM8_Da);
          }
          else {
            dVar11 = dVar11 + (double)CONCAT44(unaff_XMM8_Db,unaff_XMM8_Da);
          }
LAB_140008cfe:
          if (dVar11 < 0.0) {
            dVar11 = dVar11 + dVar5;
          }
        }
        iVar8 = iVar8 + 1;
        *(char *)(lVar9 + *(longlong *)(unaff_RBX + 0x50)) =
             (char)(int)((dVar11 * (double)CONCAT44(unaff_XMM9_Db,unaff_XMM9_Da) * dVar2) /
                        (double)CONCAT44(unaff_XMM8_Db,unaff_XMM8_Da));
        lVar9 = lVar9 + 1;
        iVar6 = *(int *)(unaff_RBX + 0x3c);
      } while (iVar8 < iVar6);
    }
    unaff_EBP = unaff_EBP + 1;
    iVar10 = iVar10 + unaff_R12D;
    if (*(int *)(unaff_RBX + 0x40) <= unaff_EBP) {
      return;
    }
  } while( true );
}



/* 140008d61 FUN_140008d61 */

void FUN_140008d61(void)

{
  return;
}



/* 140008db0 FUN_140008db0 */

void FUN_140008db0(longlong *param_1)

{
  int iVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  double dVar5;
  int iVar6;
  int iVar7;
  void *pvVar8;
  __uint64 _Var9;
  double *pdVar10;
  int *piVar11;
  int *piVar12;
  double *pdVar13;
  uint uVar14;
  longlong lVar15;
  int iVar16;
  int iVar17;
  ulonglong uVar18;
  int iVar19;
  int iVar20;
  int *piVar21;
  longlong lVar22;
  ulonglong uVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  uint uVar28;
  
  if ((int)param_1[2] != 8) {
                    /* WARNING: Could not recover jumptable at 0x000140008dd3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    AfxMessageBox("Only for 8 bits gray image!",0,0);
    return;
  }
  iVar1 = *(int *)((longlong)param_1 + 0x3c) + 3;
  iVar16 = (int)param_1[8];
  iVar6 = (int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2;
  *(int *)(param_1 + 0x17) = *(int *)((longlong)param_1 + 0x3c);
  iVar1 = iVar6 * 4;
  *(undefined4 *)(param_1 + 9) = 8;
  *(int *)((longlong)param_1 + 0xbc) = iVar16;
  if ((void *)param_1[10] != (void *)0x0) {
    operator_delete__((void *)param_1[10]);
    iVar16 = *(int *)((longlong)param_1 + 0xbc);
    param_1[10] = 0;
  }
  pvVar8 = operator_new__((longlong)(iVar16 * iVar1));
  param_1[10] = (longlong)pvVar8;
  auVar2._8_8_ = 0;
  auVar2._0_8_ = (longlong)((int)param_1[8] * *(int *)((longlong)param_1 + 0x3c));
  _Var9 = SUB168(ZEXT816(8) * auVar2,0);
  if (SUB168(ZEXT816(8) * auVar2,8) != 0) {
    _Var9 = 0xffffffffffffffff;
  }
  pdVar10 = (double *)operator_new__(_Var9);
  dVar5 = DAT_14000eea8;
  iVar19 = 0;
  iVar16 = (int)param_1[8];
  if (0 < iVar16) {
    do {
      iVar16 = 0;
      if (0 < *(int *)((longlong)param_1 + 0x3c)) {
        lVar22 = 0;
        do {
          lVar15 = iVar6 * iVar19 * 4 + lVar22;
          lVar22 = lVar22 + 1;
          pdVar10[iVar19 * *(int *)((longlong)param_1 + 0x3c) + iVar16] =
               (double)*(byte *)(lVar15 + *param_1);
          iVar7 = iVar19 * *(int *)((longlong)param_1 + 0x3c) + iVar16;
          iVar16 = iVar16 + 1;
          pdVar10[iVar7] = (pdVar10[iVar7] * (double)param_1[3]) / dVar5;
        } while (iVar16 < *(int *)((longlong)param_1 + 0x3c));
      }
      iVar16 = (int)param_1[8];
      iVar19 = iVar19 + 1;
    } while (iVar19 < iVar16);
  }
  auVar3._8_8_ = 0;
  auVar3._0_8_ = (longlong)(iVar16 * *(int *)((longlong)param_1 + 0x3c));
  _Var9 = SUB168(ZEXT816(4) * auVar3,0);
  if (SUB168(ZEXT816(4) * auVar3,8) != 0) {
    _Var9 = 0xffffffffffffffff;
  }
  pvVar8 = operator_new__(_Var9);
  memset(pvVar8,0,(longlong)(int)param_1[8] * (longlong)*(int *)((longlong)param_1 + 0x3c) * 4);
  iVar16 = (int)param_1[8] / 2;
  iVar6 = *(int *)((longlong)param_1 + 0x3c) / 2;
  uVar18 = (ulonglong)(*(int *)((longlong)param_1 + 0x3c) * (int)param_1[8]);
  auVar4._8_8_ = 0;
  auVar4._0_8_ = uVar18;
  _Var9 = SUB168(ZEXT816(8) * auVar4,0);
  if (SUB168(ZEXT816(8) * auVar4,8) != 0) {
    _Var9 = 0xffffffffffffffff;
  }
  piVar11 = (int *)operator_new__(_Var9);
  uVar23 = 0;
  piVar21 = piVar11;
  if (piVar11 == (int *)0x0) {
    piVar11 = (int *)0x0;
  }
  else {
    for (; uVar18 != 0; uVar18 = uVar18 - 1) {
      piVar21[0] = 0;
      piVar21[1] = 0;
      piVar21 = piVar21 + 2;
    }
  }
  dVar25 = DAT_14000eec0;
  dVar27 = DAT_14000ee80;
  uVar14 = (uint)DAT_14000eed0;
  uVar28 = (uint)((ulonglong)DAT_14000eed0 >> 0x20);
  piVar11[1] = iVar6;
  *piVar11 = iVar16;
  *(undefined4 *)
   ((longlong)pvVar8 + (longlong)(iVar6 + iVar16 * *(int *)((longlong)param_1 + 0x3c)) * 4) = 1;
  iVar16 = *(int *)((longlong)param_1 + 0x3c);
  piVar21 = piVar11;
  uVar18 = uVar23;
  do {
    iVar19 = (int)uVar18;
    iVar6 = *piVar21;
    uVar18 = uVar23;
    if ((0 < iVar6) &&
       (iVar7 = iVar6 + -1,
       *(int *)((longlong)pvVar8 + (longlong)(iVar16 * iVar7 + piVar21[1]) * 4) == 0)) {
      *(int *)(uVar23 + 8 + (longlong)piVar21) = iVar7;
      uVar18 = uVar23 + 8;
      iVar16 = piVar21[1];
      iVar19 = iVar19 + 1;
      *(int *)(uVar23 + 0xc + (longlong)piVar21) = iVar16;
      *(undefined4 *)
       ((longlong)pvVar8 + (longlong)(iVar16 + iVar7 * *(int *)((longlong)param_1 + 0x3c)) * 4) = 1;
      iVar16 = *(int *)((longlong)param_1 + 0x3c);
      iVar7 = *(int *)(uVar18 + (longlong)piVar21);
      iVar17 = *(int *)(uVar23 + 0xc + (longlong)piVar21);
      iVar6 = *piVar21;
      iVar20 = piVar21[1];
      dVar26 = (double)param_1[3];
      if (dVar26 * dVar27 <
          (double)CONCAT44((uint)((ulonglong)
                                  (pdVar10[iVar7 * iVar16 + iVar17] -
                                  pdVar10[iVar6 * iVar16 + iVar20]) >> 0x20) & uVar28,
                           SUB84(pdVar10[iVar7 * iVar16 + iVar17] - pdVar10[iVar6 * iVar16 + iVar20]
                                 ,0) & uVar14)) {
        do {
          iVar17 = iVar7 * iVar16 + iVar17;
          dVar24 = pdVar10[iVar17];
          if (dVar26 * dVar25 <= dVar24 - pdVar10[iVar20 + iVar16 * iVar6]) {
            if (dVar26 * dVar27 < dVar24 - pdVar10[iVar20 + iVar16 * iVar6]) {
              pdVar10[iVar17] = dVar24 - dVar26;
            }
          }
          else {
            pdVar10[iVar17] = dVar26 + dVar24;
          }
          iVar16 = *(int *)((longlong)param_1 + 0x3c);
          iVar7 = *(int *)(uVar18 + (longlong)piVar21);
          iVar17 = *(int *)(uVar23 + 0xc + (longlong)piVar21);
          iVar6 = *piVar21;
          iVar20 = piVar21[1];
          dVar26 = (double)param_1[3];
        } while (dVar26 * dVar27 <
                 (double)CONCAT44((uint)((ulonglong)
                                         (pdVar10[iVar16 * iVar7 + iVar17] -
                                         pdVar10[iVar6 * iVar16 + iVar20]) >> 0x20) & uVar28,
                                  SUB84(pdVar10[iVar16 * iVar7 + iVar17] -
                                        pdVar10[iVar6 * iVar16 + iVar20],0) & uVar14));
      }
    }
    iVar7 = piVar21[1];
    uVar23 = uVar18;
    if ((0 < iVar7) &&
       (*(int *)((longlong)pvVar8 + (longlong)(iVar7 + iVar16 * iVar6) * 4 + -4) == 0)) {
      *(int *)(uVar18 + 8 + (longlong)piVar21) = iVar6;
      uVar23 = uVar18 + 8;
      iVar16 = piVar21[1];
      iVar19 = iVar19 + 1;
      *(int *)(uVar18 + 0xc + (longlong)piVar21) = iVar16 + -1;
      *(undefined4 *)
       ((longlong)pvVar8 + (longlong)(iVar16 + -1 + iVar6 * *(int *)((longlong)param_1 + 0x3c)) * 4)
           = 1;
      iVar16 = *(int *)((longlong)param_1 + 0x3c);
      iVar17 = *(int *)(uVar23 + (longlong)piVar21);
      iVar20 = *(int *)(uVar18 + 0xc + (longlong)piVar21);
      iVar6 = *piVar21;
      iVar7 = piVar21[1];
      dVar26 = (double)param_1[3];
      if (dVar26 * dVar27 <
          (double)CONCAT44((uint)((ulonglong)
                                  (pdVar10[iVar17 * iVar16 + iVar20] -
                                  pdVar10[iVar6 * iVar16 + iVar7]) >> 0x20) & uVar28,
                           SUB84(pdVar10[iVar17 * iVar16 + iVar20] - pdVar10[iVar6 * iVar16 + iVar7]
                                 ,0) & uVar14)) {
        do {
          iVar20 = iVar17 * iVar16 + iVar20;
          dVar24 = pdVar10[iVar20];
          if (dVar26 * dVar25 <= dVar24 - pdVar10[iVar7 + iVar16 * iVar6]) {
            if (dVar26 * dVar27 < dVar24 - pdVar10[iVar7 + iVar16 * iVar6]) {
              dVar24 = dVar24 - dVar26;
              goto LAB_140009214;
            }
          }
          else {
            dVar24 = dVar24 + dVar26;
LAB_140009214:
            pdVar10[iVar20] = dVar24;
          }
          iVar16 = *(int *)((longlong)param_1 + 0x3c);
          iVar17 = *(int *)(uVar23 + (longlong)piVar21);
          iVar20 = *(int *)(uVar18 + 0xc + (longlong)piVar21);
          iVar6 = *piVar21;
          iVar7 = piVar21[1];
          dVar26 = (double)param_1[3];
        } while (dVar26 * dVar27 <
                 (double)CONCAT44((uint)((ulonglong)
                                         (pdVar10[iVar16 * iVar17 + iVar20] -
                                         pdVar10[iVar6 * iVar16 + iVar7]) >> 0x20) & uVar28,
                                  SUB84(pdVar10[iVar16 * iVar17 + iVar20] -
                                        pdVar10[iVar6 * iVar16 + iVar7],0) & uVar14));
      }
    }
    uVar18 = uVar23;
    if ((iVar6 < (int)param_1[8] + -1) &&
       (iVar17 = iVar6 + 1,
       *(int *)((longlong)pvVar8 + (longlong)(iVar7 + iVar16 * iVar17) * 4) == 0)) {
      *(int *)(uVar23 + 8 + (longlong)piVar21) = iVar17;
      uVar18 = uVar23 + 8;
      iVar16 = piVar21[1];
      iVar19 = iVar19 + 1;
      *(int *)(uVar23 + 0xc + (longlong)piVar21) = iVar16;
      *(undefined4 *)
       ((longlong)pvVar8 + (longlong)(iVar16 + iVar17 * *(int *)((longlong)param_1 + 0x3c)) * 4) = 1
      ;
      iVar16 = *(int *)((longlong)param_1 + 0x3c);
      iVar17 = *(int *)(uVar18 + (longlong)piVar21);
      iVar20 = *(int *)(uVar23 + 0xc + (longlong)piVar21);
      iVar6 = *piVar21;
      iVar7 = piVar21[1];
      dVar26 = (double)param_1[3];
      if (dVar26 * dVar27 <
          (double)CONCAT44((uint)((ulonglong)
                                  (pdVar10[iVar17 * iVar16 + iVar20] -
                                  pdVar10[iVar16 * iVar6 + iVar7]) >> 0x20) & uVar28,
                           SUB84(pdVar10[iVar17 * iVar16 + iVar20] - pdVar10[iVar16 * iVar6 + iVar7]
                                 ,0) & uVar14)) {
        do {
          iVar20 = iVar17 * iVar16 + iVar20;
          dVar24 = pdVar10[iVar20];
          if (dVar26 * dVar25 <= dVar24 - pdVar10[iVar16 * iVar6 + iVar7]) {
            if (dVar26 * dVar27 < dVar24 - pdVar10[iVar16 * iVar6 + iVar7]) {
              dVar24 = dVar24 - dVar26;
              goto LAB_140009355;
            }
          }
          else {
            dVar24 = dVar24 + dVar26;
LAB_140009355:
            pdVar10[iVar20] = dVar24;
          }
          iVar16 = *(int *)((longlong)param_1 + 0x3c);
          iVar17 = *(int *)(uVar18 + (longlong)piVar21);
          iVar20 = *(int *)(uVar23 + 0xc + (longlong)piVar21);
          iVar6 = *piVar21;
          iVar7 = piVar21[1];
          dVar26 = (double)param_1[3];
        } while (dVar26 * dVar27 <
                 (double)CONCAT44((uint)((ulonglong)
                                         (pdVar10[iVar16 * iVar17 + iVar20] -
                                         pdVar10[iVar6 * iVar16 + iVar7]) >> 0x20) & uVar28,
                                  SUB84(pdVar10[iVar16 * iVar17 + iVar20] -
                                        pdVar10[iVar6 * iVar16 + iVar7],0) & uVar14));
      }
    }
    uVar23 = uVar18;
    if ((iVar7 < iVar16 + -1) &&
       (*(int *)((longlong)pvVar8 + (longlong)(iVar6 * iVar16 + iVar7) * 4 + 4) == 0)) {
      *(int *)(uVar18 + 8 + (longlong)piVar21) = iVar6;
      uVar23 = uVar18 + 8;
      iVar16 = piVar21[1];
      iVar19 = iVar19 + 1;
      *(int *)(uVar18 + 0xc + (longlong)piVar21) = iVar16 + 1;
      *(undefined4 *)
       ((longlong)pvVar8 + (longlong)(iVar16 + 1 + iVar6 * *(int *)((longlong)param_1 + 0x3c)) * 4)
           = 1;
      iVar16 = *(int *)((longlong)param_1 + 0x3c);
      iVar6 = *(int *)(uVar23 + (longlong)piVar21);
      iVar7 = *(int *)(uVar18 + 0xc + (longlong)piVar21);
      iVar17 = *piVar21;
      iVar20 = piVar21[1];
      dVar26 = (double)param_1[3];
      if (dVar26 * dVar27 <
          (double)CONCAT44((uint)((ulonglong)
                                  (pdVar10[iVar6 * iVar16 + iVar7] -
                                  pdVar10[iVar16 * iVar17 + iVar20]) >> 0x20) & uVar28,
                           SUB84(pdVar10[iVar6 * iVar16 + iVar7] - pdVar10[iVar16 * iVar17 + iVar20]
                                 ,0) & uVar14)) {
        do {
          iVar7 = iVar6 * iVar16 + iVar7;
          dVar24 = pdVar10[iVar7];
          if (dVar26 * dVar25 <= dVar24 - pdVar10[iVar20 + iVar16 * iVar17]) {
            if (dVar26 * dVar27 < dVar24 - pdVar10[iVar20 + iVar16 * iVar17]) {
              dVar24 = dVar24 - dVar26;
              goto LAB_140009494;
            }
          }
          else {
            dVar24 = dVar24 + dVar26;
LAB_140009494:
            pdVar10[iVar7] = dVar24;
          }
          iVar16 = *(int *)((longlong)param_1 + 0x3c);
          iVar6 = *(int *)(uVar23 + (longlong)piVar21);
          iVar7 = *(int *)(uVar18 + 0xc + (longlong)piVar21);
          iVar17 = *piVar21;
          iVar20 = piVar21[1];
          dVar26 = (double)param_1[3];
        } while (dVar26 * dVar27 <
                 (double)CONCAT44((uint)((ulonglong)
                                         (pdVar10[iVar16 * iVar6 + iVar7] -
                                         pdVar10[iVar17 * iVar16 + iVar20]) >> 0x20) & uVar28,
                                  SUB84(pdVar10[iVar16 * iVar6 + iVar7] -
                                        pdVar10[iVar17 * iVar16 + iVar20],0) & uVar14));
      }
    }
    piVar12 = piVar21 + 2;
    if (iVar19 < 1) {
      piVar12 = piVar21;
    }
    uVar18 = (ulonglong)(iVar19 - 1U);
    uVar23 = uVar23 - 8;
    piVar21 = piVar12;
    if (iVar19 - 1U == 0xffffffff) {
      uVar14 = (int)param_1[8] * *(int *)((longlong)param_1 + 0x3c);
      uVar18 = (ulonglong)uVar14;
      dVar27 = *pdVar10;
      pdVar13 = pdVar10;
      dVar25 = dVar27;
      dVar26 = dVar27;
      if (0 < (int)uVar14) {
        do {
          dVar24 = *pdVar13;
          dVar25 = dVar24;
          if (dVar24 <= dVar26) {
            dVar25 = dVar26;
          }
          if (dVar27 <= dVar24) {
            dVar24 = dVar27;
          }
          dVar27 = dVar24;
          uVar18 = uVar18 - 1;
          pdVar13 = pdVar13 + 1;
          dVar26 = dVar25;
        } while (uVar18 != 0);
      }
      iVar16 = 0;
      if (0 < *(int *)((longlong)param_1 + 0xbc)) {
        iVar6 = 0;
        do {
          iVar19 = 0;
          if (0 < (int)param_1[0x17]) {
            lVar22 = 0;
            do {
              lVar15 = param_1[10] + lVar22;
              lVar22 = lVar22 + 1;
              iVar7 = iVar16 * *(int *)((longlong)param_1 + 0x3c) + iVar19;
              iVar19 = iVar19 + 1;
              *(char *)(lVar15 + iVar6) =
                   (char)(int)(((pdVar10[iVar7] - dVar27) * dVar5) / (dVar25 - dVar27));
            } while (iVar19 < (int)param_1[0x17]);
          }
          iVar16 = iVar16 + 1;
          iVar6 = iVar6 + iVar1;
        } while (iVar16 < *(int *)((longlong)param_1 + 0xbc));
      }
      param_1[0x16] = (longlong)(dVar25 - dVar27);
      operator_delete__(pdVar10);
      operator_delete__(piVar11);
                    /* WARNING: Could not recover jumptable at 0x000140009613. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      operator_delete__(pvVar8);
      return;
    }
  } while( true );
}



/* 140008e03 FUN_140008e03 */

void FUN_140008e03(undefined4 param_1,int param_2)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  double dVar4;
  int in_EAX;
  int iVar5;
  int iVar6;
  void *pvVar7;
  __uint64 _Var8;
  double *pdVar9;
  int *piVar10;
  int *piVar11;
  double *pdVar12;
  uint uVar13;
  longlong lVar14;
  int iVar15;
  int iVar16;
  ulonglong uVar17;
  longlong *unaff_RDI;
  int iVar18;
  int iVar19;
  int *piVar20;
  longlong lVar21;
  ulonglong uVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  uint uVar27;
  int iStack0000000000000078;
  
  iVar18 = (int)unaff_RDI[8];
  iVar5 = in_EAX + param_2 >> 2;
  *(undefined4 *)(unaff_RDI + 0x17) = param_1;
  iVar15 = iVar5 * 4;
  *(undefined4 *)(unaff_RDI + 9) = 8;
  *(int *)((longlong)unaff_RDI + 0xbc) = iVar18;
  iStack0000000000000078 = iVar15;
  if ((void *)unaff_RDI[10] != (void *)0x0) {
    operator_delete__((void *)unaff_RDI[10]);
    iVar18 = *(int *)((longlong)unaff_RDI + 0xbc);
    unaff_RDI[10] = 0;
  }
  pvVar7 = operator_new__((longlong)(iVar18 * iVar15));
  unaff_RDI[10] = (longlong)pvVar7;
  auVar1._8_8_ = 0;
  auVar1._0_8_ = (longlong)((int)unaff_RDI[8] * *(int *)((longlong)unaff_RDI + 0x3c));
  _Var8 = SUB168(ZEXT816(8) * auVar1,0);
  if (SUB168(ZEXT816(8) * auVar1,8) != 0) {
    _Var8 = 0xffffffffffffffff;
  }
  pdVar9 = (double *)operator_new__(_Var8);
  dVar4 = DAT_14000eea8;
  iVar18 = 0;
  iVar15 = (int)unaff_RDI[8];
  if (0 < iVar15) {
    do {
      iVar15 = 0;
      if (0 < *(int *)((longlong)unaff_RDI + 0x3c)) {
        lVar21 = 0;
        do {
          lVar14 = iVar5 * iVar18 * 4 + lVar21;
          lVar21 = lVar21 + 1;
          pdVar9[iVar18 * *(int *)((longlong)unaff_RDI + 0x3c) + iVar15] =
               (double)*(byte *)(lVar14 + *unaff_RDI);
          iVar6 = iVar18 * *(int *)((longlong)unaff_RDI + 0x3c) + iVar15;
          iVar15 = iVar15 + 1;
          pdVar9[iVar6] = (pdVar9[iVar6] * (double)unaff_RDI[3]) / dVar4;
        } while (iVar15 < *(int *)((longlong)unaff_RDI + 0x3c));
      }
      iVar15 = (int)unaff_RDI[8];
      iVar18 = iVar18 + 1;
    } while (iVar18 < iVar15);
  }
  auVar2._8_8_ = 0;
  auVar2._0_8_ = (longlong)(iVar15 * *(int *)((longlong)unaff_RDI + 0x3c));
  _Var8 = SUB168(ZEXT816(4) * auVar2,0);
  if (SUB168(ZEXT816(4) * auVar2,8) != 0) {
    _Var8 = 0xffffffffffffffff;
  }
  pvVar7 = operator_new__(_Var8);
  memset(pvVar7,0,(longlong)(int)unaff_RDI[8] * (longlong)*(int *)((longlong)unaff_RDI + 0x3c) * 4);
  iVar15 = (int)unaff_RDI[8] / 2;
  iVar18 = *(int *)((longlong)unaff_RDI + 0x3c) / 2;
  uVar17 = (ulonglong)(*(int *)((longlong)unaff_RDI + 0x3c) * (int)unaff_RDI[8]);
  auVar3._8_8_ = 0;
  auVar3._0_8_ = uVar17;
  _Var8 = SUB168(ZEXT816(8) * auVar3,0);
  if (SUB168(ZEXT816(8) * auVar3,8) != 0) {
    _Var8 = 0xffffffffffffffff;
  }
  piVar10 = (int *)operator_new__(_Var8);
  uVar22 = 0;
  piVar20 = piVar10;
  if (piVar10 == (int *)0x0) {
    piVar10 = (int *)0x0;
  }
  else {
    for (; uVar17 != 0; uVar17 = uVar17 - 1) {
      piVar20[0] = 0;
      piVar20[1] = 0;
      piVar20 = piVar20 + 2;
    }
  }
  dVar24 = DAT_14000eec0;
  dVar26 = DAT_14000ee80;
  uVar13 = (uint)DAT_14000eed0;
  uVar27 = (uint)((ulonglong)DAT_14000eed0 >> 0x20);
  piVar10[1] = iVar18;
  *piVar10 = iVar15;
  *(undefined4 *)
   ((longlong)pvVar7 + (longlong)(iVar18 + iVar15 * *(int *)((longlong)unaff_RDI + 0x3c)) * 4) = 1;
  iVar15 = *(int *)((longlong)unaff_RDI + 0x3c);
  piVar20 = piVar10;
  uVar17 = uVar22;
  do {
    iVar5 = (int)uVar17;
    iVar18 = *piVar20;
    uVar17 = uVar22;
    if ((0 < iVar18) &&
       (iVar6 = iVar18 + -1,
       *(int *)((longlong)pvVar7 + (longlong)(iVar15 * iVar6 + piVar20[1]) * 4) == 0)) {
      *(int *)(uVar22 + 8 + (longlong)piVar20) = iVar6;
      uVar17 = uVar22 + 8;
      iVar15 = piVar20[1];
      iVar5 = iVar5 + 1;
      *(int *)(uVar22 + 0xc + (longlong)piVar20) = iVar15;
      *(undefined4 *)
       ((longlong)pvVar7 + (longlong)(iVar15 + iVar6 * *(int *)((longlong)unaff_RDI + 0x3c)) * 4) =
           1;
      iVar15 = *(int *)((longlong)unaff_RDI + 0x3c);
      iVar6 = *(int *)(uVar17 + (longlong)piVar20);
      iVar16 = *(int *)(uVar22 + 0xc + (longlong)piVar20);
      iVar18 = *piVar20;
      iVar19 = piVar20[1];
      dVar25 = (double)unaff_RDI[3];
      if (dVar25 * dVar26 <
          (double)CONCAT44((uint)((ulonglong)
                                  (pdVar9[iVar6 * iVar15 + iVar16] -
                                  pdVar9[iVar18 * iVar15 + iVar19]) >> 0x20) & uVar27,
                           SUB84(pdVar9[iVar6 * iVar15 + iVar16] - pdVar9[iVar18 * iVar15 + iVar19],
                                 0) & uVar13)) {
        do {
          iVar16 = iVar6 * iVar15 + iVar16;
          dVar23 = pdVar9[iVar16];
          if (dVar25 * dVar24 <= dVar23 - pdVar9[iVar19 + iVar15 * iVar18]) {
            if (dVar25 * dVar26 < dVar23 - pdVar9[iVar19 + iVar15 * iVar18]) {
              pdVar9[iVar16] = dVar23 - dVar25;
            }
          }
          else {
            pdVar9[iVar16] = dVar25 + dVar23;
          }
          iVar15 = *(int *)((longlong)unaff_RDI + 0x3c);
          iVar6 = *(int *)(uVar17 + (longlong)piVar20);
          iVar16 = *(int *)(uVar22 + 0xc + (longlong)piVar20);
          iVar18 = *piVar20;
          iVar19 = piVar20[1];
          dVar25 = (double)unaff_RDI[3];
        } while (dVar25 * dVar26 <
                 (double)CONCAT44((uint)((ulonglong)
                                         (pdVar9[iVar15 * iVar6 + iVar16] -
                                         pdVar9[iVar18 * iVar15 + iVar19]) >> 0x20) & uVar27,
                                  SUB84(pdVar9[iVar15 * iVar6 + iVar16] -
                                        pdVar9[iVar18 * iVar15 + iVar19],0) & uVar13));
      }
    }
    iVar6 = piVar20[1];
    uVar22 = uVar17;
    if ((0 < iVar6) &&
       (*(int *)((longlong)pvVar7 + (longlong)(iVar6 + iVar15 * iVar18) * 4 + -4) == 0)) {
      *(int *)(uVar17 + 8 + (longlong)piVar20) = iVar18;
      uVar22 = uVar17 + 8;
      iVar15 = piVar20[1];
      iVar5 = iVar5 + 1;
      *(int *)(uVar17 + 0xc + (longlong)piVar20) = iVar15 + -1;
      *(undefined4 *)
       ((longlong)pvVar7 +
       (longlong)(iVar15 + -1 + iVar18 * *(int *)((longlong)unaff_RDI + 0x3c)) * 4) = 1;
      iVar15 = *(int *)((longlong)unaff_RDI + 0x3c);
      iVar16 = *(int *)(uVar22 + (longlong)piVar20);
      iVar19 = *(int *)(uVar17 + 0xc + (longlong)piVar20);
      iVar18 = *piVar20;
      iVar6 = piVar20[1];
      dVar25 = (double)unaff_RDI[3];
      if (dVar25 * dVar26 <
          (double)CONCAT44((uint)((ulonglong)
                                  (pdVar9[iVar16 * iVar15 + iVar19] -
                                  pdVar9[iVar18 * iVar15 + iVar6]) >> 0x20) & uVar27,
                           SUB84(pdVar9[iVar16 * iVar15 + iVar19] - pdVar9[iVar18 * iVar15 + iVar6],
                                 0) & uVar13)) {
        do {
          iVar19 = iVar16 * iVar15 + iVar19;
          dVar23 = pdVar9[iVar19];
          if (dVar25 * dVar24 <= dVar23 - pdVar9[iVar6 + iVar15 * iVar18]) {
            if (dVar25 * dVar26 < dVar23 - pdVar9[iVar6 + iVar15 * iVar18]) {
              dVar23 = dVar23 - dVar25;
              goto LAB_140009214;
            }
          }
          else {
            dVar23 = dVar23 + dVar25;
LAB_140009214:
            pdVar9[iVar19] = dVar23;
          }
          iVar15 = *(int *)((longlong)unaff_RDI + 0x3c);
          iVar16 = *(int *)(uVar22 + (longlong)piVar20);
          iVar19 = *(int *)(uVar17 + 0xc + (longlong)piVar20);
          iVar18 = *piVar20;
          iVar6 = piVar20[1];
          dVar25 = (double)unaff_RDI[3];
        } while (dVar25 * dVar26 <
                 (double)CONCAT44((uint)((ulonglong)
                                         (pdVar9[iVar15 * iVar16 + iVar19] -
                                         pdVar9[iVar18 * iVar15 + iVar6]) >> 0x20) & uVar27,
                                  SUB84(pdVar9[iVar15 * iVar16 + iVar19] -
                                        pdVar9[iVar18 * iVar15 + iVar6],0) & uVar13));
      }
    }
    uVar17 = uVar22;
    if ((iVar18 < (int)unaff_RDI[8] + -1) &&
       (iVar16 = iVar18 + 1,
       *(int *)((longlong)pvVar7 + (longlong)(iVar6 + iVar15 * iVar16) * 4) == 0)) {
      *(int *)(uVar22 + 8 + (longlong)piVar20) = iVar16;
      uVar17 = uVar22 + 8;
      iVar15 = piVar20[1];
      iVar5 = iVar5 + 1;
      *(int *)(uVar22 + 0xc + (longlong)piVar20) = iVar15;
      *(undefined4 *)
       ((longlong)pvVar7 + (longlong)(iVar15 + iVar16 * *(int *)((longlong)unaff_RDI + 0x3c)) * 4) =
           1;
      iVar15 = *(int *)((longlong)unaff_RDI + 0x3c);
      iVar16 = *(int *)(uVar17 + (longlong)piVar20);
      iVar19 = *(int *)(uVar22 + 0xc + (longlong)piVar20);
      iVar18 = *piVar20;
      iVar6 = piVar20[1];
      dVar25 = (double)unaff_RDI[3];
      if (dVar25 * dVar26 <
          (double)CONCAT44((uint)((ulonglong)
                                  (pdVar9[iVar16 * iVar15 + iVar19] -
                                  pdVar9[iVar15 * iVar18 + iVar6]) >> 0x20) & uVar27,
                           SUB84(pdVar9[iVar16 * iVar15 + iVar19] - pdVar9[iVar15 * iVar18 + iVar6],
                                 0) & uVar13)) {
        do {
          iVar19 = iVar16 * iVar15 + iVar19;
          dVar23 = pdVar9[iVar19];
          if (dVar25 * dVar24 <= dVar23 - pdVar9[iVar15 * iVar18 + iVar6]) {
            if (dVar25 * dVar26 < dVar23 - pdVar9[iVar15 * iVar18 + iVar6]) {
              dVar23 = dVar23 - dVar25;
              goto LAB_140009355;
            }
          }
          else {
            dVar23 = dVar23 + dVar25;
LAB_140009355:
            pdVar9[iVar19] = dVar23;
          }
          iVar15 = *(int *)((longlong)unaff_RDI + 0x3c);
          iVar16 = *(int *)(uVar17 + (longlong)piVar20);
          iVar19 = *(int *)(uVar22 + 0xc + (longlong)piVar20);
          iVar18 = *piVar20;
          iVar6 = piVar20[1];
          dVar25 = (double)unaff_RDI[3];
        } while (dVar25 * dVar26 <
                 (double)CONCAT44((uint)((ulonglong)
                                         (pdVar9[iVar15 * iVar16 + iVar19] -
                                         pdVar9[iVar18 * iVar15 + iVar6]) >> 0x20) & uVar27,
                                  SUB84(pdVar9[iVar15 * iVar16 + iVar19] -
                                        pdVar9[iVar18 * iVar15 + iVar6],0) & uVar13));
      }
    }
    uVar22 = uVar17;
    if ((iVar6 < iVar15 + -1) &&
       (*(int *)((longlong)pvVar7 + (longlong)(iVar18 * iVar15 + iVar6) * 4 + 4) == 0)) {
      *(int *)(uVar17 + 8 + (longlong)piVar20) = iVar18;
      uVar22 = uVar17 + 8;
      iVar15 = piVar20[1];
      iVar5 = iVar5 + 1;
      *(int *)(uVar17 + 0xc + (longlong)piVar20) = iVar15 + 1;
      *(undefined4 *)
       ((longlong)pvVar7 +
       (longlong)(iVar15 + 1 + iVar18 * *(int *)((longlong)unaff_RDI + 0x3c)) * 4) = 1;
      iVar15 = *(int *)((longlong)unaff_RDI + 0x3c);
      iVar18 = *(int *)(uVar22 + (longlong)piVar20);
      iVar6 = *(int *)(uVar17 + 0xc + (longlong)piVar20);
      iVar16 = *piVar20;
      iVar19 = piVar20[1];
      dVar25 = (double)unaff_RDI[3];
      if (dVar25 * dVar26 <
          (double)CONCAT44((uint)((ulonglong)
                                  (pdVar9[iVar18 * iVar15 + iVar6] -
                                  pdVar9[iVar15 * iVar16 + iVar19]) >> 0x20) & uVar27,
                           SUB84(pdVar9[iVar18 * iVar15 + iVar6] - pdVar9[iVar15 * iVar16 + iVar19],
                                 0) & uVar13)) {
        do {
          iVar6 = iVar18 * iVar15 + iVar6;
          dVar23 = pdVar9[iVar6];
          if (dVar25 * dVar24 <= dVar23 - pdVar9[iVar19 + iVar15 * iVar16]) {
            if (dVar25 * dVar26 < dVar23 - pdVar9[iVar19 + iVar15 * iVar16]) {
              dVar23 = dVar23 - dVar25;
              goto LAB_140009494;
            }
          }
          else {
            dVar23 = dVar23 + dVar25;
LAB_140009494:
            pdVar9[iVar6] = dVar23;
          }
          iVar15 = *(int *)((longlong)unaff_RDI + 0x3c);
          iVar18 = *(int *)(uVar22 + (longlong)piVar20);
          iVar6 = *(int *)(uVar17 + 0xc + (longlong)piVar20);
          iVar16 = *piVar20;
          iVar19 = piVar20[1];
          dVar25 = (double)unaff_RDI[3];
        } while (dVar25 * dVar26 <
                 (double)CONCAT44((uint)((ulonglong)
                                         (pdVar9[iVar15 * iVar18 + iVar6] -
                                         pdVar9[iVar16 * iVar15 + iVar19]) >> 0x20) & uVar27,
                                  SUB84(pdVar9[iVar15 * iVar18 + iVar6] -
                                        pdVar9[iVar16 * iVar15 + iVar19],0) & uVar13));
      }
    }
    piVar11 = piVar20 + 2;
    if (iVar5 < 1) {
      piVar11 = piVar20;
    }
    uVar17 = (ulonglong)(iVar5 - 1U);
    uVar22 = uVar22 - 8;
    piVar20 = piVar11;
    if (iVar5 - 1U == 0xffffffff) {
      uVar13 = (int)unaff_RDI[8] * *(int *)((longlong)unaff_RDI + 0x3c);
      uVar17 = (ulonglong)uVar13;
      dVar26 = *pdVar9;
      pdVar12 = pdVar9;
      dVar24 = dVar26;
      dVar25 = dVar26;
      if (0 < (int)uVar13) {
        do {
          dVar23 = *pdVar12;
          dVar24 = dVar23;
          if (dVar23 <= dVar25) {
            dVar24 = dVar25;
          }
          if (dVar26 <= dVar23) {
            dVar23 = dVar26;
          }
          dVar26 = dVar23;
          uVar17 = uVar17 - 1;
          pdVar12 = pdVar12 + 1;
          dVar25 = dVar24;
        } while (uVar17 != 0);
      }
      iVar15 = 0;
      if (0 < *(int *)((longlong)unaff_RDI + 0xbc)) {
        iVar18 = 0;
        do {
          iVar5 = 0;
          if (0 < (int)unaff_RDI[0x17]) {
            lVar21 = 0;
            do {
              lVar14 = unaff_RDI[10] + lVar21;
              lVar21 = lVar21 + 1;
              iVar6 = iVar15 * *(int *)((longlong)unaff_RDI + 0x3c) + iVar5;
              iVar5 = iVar5 + 1;
              *(char *)(lVar14 + iVar18) =
                   (char)(int)(((pdVar9[iVar6] - dVar26) * dVar4) / (dVar24 - dVar26));
            } while (iVar5 < (int)unaff_RDI[0x17]);
          }
          iVar15 = iVar15 + 1;
          iVar18 = iVar18 + iStack0000000000000078;
        } while (iVar15 < *(int *)((longlong)unaff_RDI + 0xbc));
      }
      unaff_RDI[0x16] = (longlong)(dVar24 - dVar26);
      operator_delete__(pdVar9);
      operator_delete__(piVar10);
                    /* WARNING: Could not recover jumptable at 0x000140009613. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      operator_delete__(pvVar7);
      return;
    }
  } while( true );
}



/* 140009525 FUN_140009525 */

void FUN_140009525(longlong param_1,undefined8 param_2,double param_3,double param_4)

{
  int iVar1;
  double *pdVar2;
  longlong lVar3;
  double *unaff_RBX;
  int iVar4;
  longlong unaff_RDI;
  int iVar5;
  longlong lVar6;
  int iVar7;
  void *unaff_R12;
  void *unaff_R13;
  double dVar8;
  double dVar9;
  undefined4 unaff_XMM7_Da;
  undefined4 unaff_XMM7_Db;
  int in_stack_00000078;
  
  pdVar2 = unaff_RBX;
  do {
    dVar8 = *pdVar2;
    pdVar2 = pdVar2 + 1;
    dVar9 = dVar8;
    if (dVar8 <= param_4) {
      dVar9 = param_4;
    }
    if (param_3 <= dVar8) {
      dVar8 = param_3;
    }
    param_1 = param_1 + -1;
    param_4 = dVar9;
    param_3 = dVar8;
  } while (param_1 != 0);
  iVar7 = 0;
  if (0 < *(int *)(unaff_RDI + 0xbc)) {
    iVar4 = 0;
    do {
      iVar5 = 0;
      if (0 < *(int *)(unaff_RDI + 0xb8)) {
        lVar6 = 0;
        do {
          lVar3 = *(longlong *)(unaff_RDI + 0x50) + lVar6;
          lVar6 = lVar6 + 1;
          iVar1 = iVar7 * *(int *)(unaff_RDI + 0x3c) + iVar5;
          iVar5 = iVar5 + 1;
          *(char *)(lVar3 + iVar4) =
               (char)(int)(((unaff_RBX[iVar1] - dVar8) *
                           (double)CONCAT44(unaff_XMM7_Db,unaff_XMM7_Da)) / (dVar9 - dVar8));
        } while (iVar5 < *(int *)(unaff_RDI + 0xb8));
      }
      iVar7 = iVar7 + 1;
      iVar4 = iVar4 + in_stack_00000078;
    } while (iVar7 < *(int *)(unaff_RDI + 0xbc));
  }
  *(double *)(unaff_RDI + 0xb0) = dVar9 - dVar8;
  operator_delete__(unaff_RBX);
  operator_delete__(unaff_R13);
                    /* WARNING: Could not recover jumptable at 0x000140009613. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete__(unaff_R12);
  return;
}



/* 140009620 FUN_140009620 */

void FUN_140009620(longlong param_1)

{
  if (*(void **)(param_1 + 0x20) != (void *)0x0) {
    operator_delete__(*(void **)(param_1 + 0x20));
  }
  if (*(HGDIOBJ *)(param_1 + 0x30) != (HGDIOBJ)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000140009646. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    DeleteObject(*(HGDIOBJ *)(param_1 + 0x30));
    return;
  }
  return;
}



/* 140009660 FUN_140009660 */

void FUN_140009660(longlong *param_1,char *param_2)

{
  int iVar1;
  uint uVar2;
  __uint64 _Var3;
  void *pvVar4;
  CException *pCVar5;
  CFile *this;
  longlong lVar6;
  undefined1 auStack_98 [32];
  CException *local_78;
  CException *local_70;
  CException *local_68;
  CFile local_60 [40];
  undefined8 local_38;
  short local_28 [8];
  ulonglong local_18;
  
  local_38 = 0xfffffffffffffffe;
  local_18 = DAT_140013010 ^ (ulonglong)auStack_98;
  CFile::CFile(local_60);
  iVar1 = CFile::Open(local_60,param_2,0x20,(CFileException *)0x0);
  if (iVar1 == 0) {
    CFile::~CFile(local_60);
  }
  else {
    if ((void *)param_1[4] != (void *)0x0) {
      operator_delete__((void *)param_1[4]);
      param_1[4] = 0;
      param_1[1] = 0;
      *param_1 = 0;
      param_1[5] = 0;
    }
    pCVar5 = (CException *)0x0;
    if ((HGDIOBJ)param_1[6] != (HGDIOBJ)0x0) {
      DeleteObject((HGDIOBJ)param_1[6]);
      param_1[6] = 0;
    }
    uVar2 = CFile::Read(local_60,local_28,0xe);
    if (uVar2 != 0xe) {
      local_68 = (CException *)operator_new(0xa0);
      if (local_68 != (CException *)0x0) {
        pCVar5 = FUN_140008250(local_68);
      }
      local_78 = pCVar5;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_78,(ThrowInfo *)&DAT_1400113b8);
    }
    if (local_28[0] != 0x4d42) {
      local_68 = (CException *)operator_new(0xa0);
      if (local_68 != (CException *)0x0) {
        pCVar5 = FUN_140008250(local_68);
      }
      local_70 = pCVar5;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_70,(ThrowInfo *)&DAT_1400113b8);
    }
    if ((void *)param_1[4] != (void *)0x0) {
      operator_delete__((void *)param_1[4]);
    }
    _Var3 = CFile::GetLength(local_60);
    pvVar4 = operator_new__((ulonglong)((int)_Var3 - 0xe));
    param_1[4] = (longlong)pvVar4;
    _Var3 = CFile::GetLength(local_60);
    this = local_60;
    CFile::Read(this,(void *)param_1[4],(int)_Var3 - 0xe);
    lVar6 = param_1[4];
    param_1[5] = lVar6;
    *(undefined4 *)((longlong)param_1 + 0x3c) = *(undefined4 *)(lVar6 + 4);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(lVar6 + 8);
    *(uint *)(param_1 + 2) = (uint)*(ushort *)(lVar6 + 0xe);
    param_1[3] = 0x401921fb4d12d84a;
    iVar1 = FUN_1400099f0(this,(uint)*(ushort *)(lVar6 + 0xe));
    *(int *)(param_1 + 7) = iVar1;
    param_1[6] = 0;
    if (iVar1 != 0) {
      param_1[1] = lVar6 + 0x28;
      FUN_140009a70((longlong)param_1);
    }
    *param_1 = param_1[4] + ((longlong)(int)param_1[7] + 10) * 4;
    CFile::~CFile(local_60);
  }
  __security_check_cookie(local_18 ^ (ulonglong)auStack_98);
  return;
}



/* 140009880 FUN_140009880 */

void FUN_140009880(undefined8 *param_1,undefined8 param_2,undefined8 param_3,void *param_4,
                  void *param_5,undefined8 param_6)

{
  void *_Dst;
  int iVar1;
  undefined4 *puVar2;
  size_t _Size;
  int iStackX_14;
  
  if ((void *)param_1[4] != (void *)0x0) {
    operator_delete__((void *)param_1[4]);
    param_1[4] = 0;
    param_1[1] = 0;
    *param_1 = 0;
    param_1[5] = 0;
  }
  if ((HGDIOBJ)param_1[6] != (HGDIOBJ)0x0) {
    DeleteObject((HGDIOBJ)param_1[6]);
    param_1[6] = 0;
  }
  iStackX_14 = (int)((ulonglong)param_2 >> 0x20);
  iVar1 = (int)param_2 + 3;
  *(undefined8 *)((longlong)param_1 + 0x3c) = param_2;
  param_1[3] = param_6;
  *(undefined4 *)(param_1 + 2) = 8;
  *(undefined4 *)(param_1 + 7) = 0x100;
  _Size = (size_t)(((int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2) * iStackX_14 * 4);
  puVar2 = (undefined4 *)operator_new__(_Size + 0x428);
  param_1[5] = puVar2;
  param_1[4] = puVar2;
  *puVar2 = 0x28;
  *(undefined4 *)(param_1[5] + 4) = *(undefined4 *)((longlong)param_1 + 0x3c);
  *(undefined4 *)(param_1[5] + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined2 *)(param_1[5] + 0xc) = 1;
  *(undefined2 *)(param_1[5] + 0xe) = *(undefined2 *)(param_1 + 2);
  *(undefined4 *)(param_1[5] + 0x10) = 0;
  *(undefined4 *)(param_1[5] + 0x14) = 0;
  *(undefined4 *)(param_1[5] + 0x18) = 0;
  *(undefined4 *)(param_1[5] + 0x1c) = 0;
  *(undefined4 *)(param_1[5] + 0x20) = *(undefined4 *)(param_1 + 7);
  *(undefined4 *)(param_1[5] + 0x24) = *(undefined4 *)(param_1 + 7);
  iVar1 = *(int *)(param_1 + 7);
  param_1[6] = 0;
  if (iVar1 != 0) {
    param_1[1] = (void *)(param_1[4] + 0x28);
    memcpy((void *)(param_1[4] + 0x28),param_4,(longlong)iVar1 << 2);
    FUN_140009a70((longlong)param_1);
    iVar1 = *(int *)(param_1 + 7);
  }
  _Dst = (void *)(param_1[4] + 0x28 + (longlong)iVar1 * 4);
  *param_1 = _Dst;
  memcpy(_Dst,param_5,_Size);
  return;
}



/* 1400099f0 FUN_1400099f0 */

undefined4 FUN_1400099f0(undefined8 param_1,undefined4 param_2)

{
  undefined4 local_res10;
  
  switch(param_2) {
  case 1:
    return 2;
  default:
    return local_res10;
  case 4:
    return 0x10;
  case 8:
    return 0x100;
  case 0x10:
  case 0x18:
  case 0x20:
    return 0;
  }
}



/* 140009a70 FUN_140009a70 */

void FUN_140009a70(longlong param_1)

{
  LOGPALETTE *plpal;
  HPALETTE pHVar1;
  BYTE *pBVar2;
  BYTE *pBVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x38);
  if (iVar4 != 0) {
    if (*(HGDIOBJ *)(param_1 + 0x30) != (HGDIOBJ)0x0) {
      DeleteObject(*(HGDIOBJ *)(param_1 + 0x30));
      iVar4 = *(int *)(param_1 + 0x38);
    }
    plpal = (LOGPALETTE *)operator_new__((longlong)iVar4 * 4 + 4);
    iVar4 = 0;
    plpal->palVersion = 0x300;
    plpal->palNumEntries = *(WORD *)(param_1 + 0x38);
    if (0 < *(int *)(param_1 + 0x38)) {
      pBVar2 = &plpal->palPalEntry[0].peGreen;
      pBVar3 = *(BYTE **)(param_1 + 8);
      do {
        ((PALETTEENTRY *)(pBVar2 + -1))->peRed = pBVar3[2];
        iVar4 = iVar4 + 1;
        *pBVar2 = pBVar3[1];
        pBVar2[1] = *pBVar3;
        pBVar2[2] = '\0';
        pBVar2 = pBVar2 + 4;
        pBVar3 = pBVar3 + 4;
      } while (iVar4 < *(int *)(param_1 + 0x38));
    }
    pHVar1 = CreatePalette(plpal);
    *(HPALETTE *)(param_1 + 0x30) = pHVar1;
    operator_delete(plpal);
  }
  return;
}



/* 140009a88 FUN_140009a88 */

void FUN_140009a88(HGDIOBJ param_1)

{
  int in_EAX;
  LOGPALETTE *plpal;
  HPALETTE pHVar1;
  BYTE *pBVar2;
  longlong unaff_RBX;
  BYTE *pBVar3;
  int iVar4;
  
  if (param_1 != (HGDIOBJ)0x0) {
    DeleteObject(param_1);
    in_EAX = *(int *)(unaff_RBX + 0x38);
  }
  plpal = (LOGPALETTE *)operator_new__((longlong)in_EAX * 4 + 4);
  iVar4 = 0;
  plpal->palVersion = 0x300;
  plpal->palNumEntries = *(WORD *)(unaff_RBX + 0x38);
  if (0 < *(int *)(unaff_RBX + 0x38)) {
    pBVar2 = &plpal->palPalEntry[0].peGreen;
    pBVar3 = *(BYTE **)(unaff_RBX + 8);
    do {
      ((PALETTEENTRY *)(pBVar2 + -1))->peRed = pBVar3[2];
      iVar4 = iVar4 + 1;
      *pBVar2 = pBVar3[1];
      pBVar2[1] = *pBVar3;
      pBVar2[2] = '\0';
      pBVar2 = pBVar2 + 4;
      pBVar3 = pBVar3 + 4;
    } while (iVar4 < *(int *)(unaff_RBX + 0x38));
  }
  pHVar1 = CreatePalette(plpal);
  *(HPALETTE *)(unaff_RBX + 0x30) = pHVar1;
  operator_delete(plpal);
  return;
}



/* 140009b1c FUN_140009b1c */

void FUN_140009b1c(void)

{
  return;
}



/* 140009f20 __security_check_cookie */

/* Library Function - Single Match
    __security_check_cookie
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie == DAT_140013010) && ((short)(_StackCookie >> 0x30) == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure(_StackCookie);
}



/* 140009f44 __scrt_acquire_startup_lock */

/* Library Function - Single Match
    __scrt_acquire_startup_lock
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

ulonglong __scrt_acquire_startup_lock(void)

{
  ulonglong uVar1;
  bool bVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  
  bVar2 = __scrt_is_ucrt_dll_in_use();
  uVar3 = CONCAT71(extraout_var,bVar2);
  if ((int)uVar3 == 0) {
LAB_140009f72:
    uVar3 = uVar3 & 0xffffffffffffff00;
  }
  else {
    do {
      uVar3 = 0;
      LOCK();
      bVar2 = DAT_140013880 == 0;
      uVar1 = *(ulonglong *)((longlong)Self + 8);
      if (!bVar2) {
        uVar3 = DAT_140013880;
        uVar1 = DAT_140013880;
      }
      DAT_140013880 = uVar1;
      UNLOCK();
      if (bVar2) goto LAB_140009f72;
    } while (*(ulonglong *)((longlong)Self + 8) != uVar3);
    uVar3 = CONCAT71((int7)(uVar3 >> 8),1);
  }
  return uVar3;
}



/* 140009f80 __scrt_initialize_crt */

/* Library Function - Single Match
    __scrt_initialize_crt
   
   Library: Visual Studio 2017 Release */

longlong __scrt_initialize_crt(int param_1)

{
  char cVar1;
  uint7 extraout_var;
  uint7 uVar2;
  undefined7 extraout_var_00;
  uint7 extraout_var_01;
  
  if (param_1 == 0) {
    DAT_140013888 = 1;
  }
  __isa_available_init();
  cVar1 = FUN_14000ae3c();
  uVar2 = extraout_var;
  if (cVar1 != '\0') {
    cVar1 = FUN_14000ae3c();
    if (cVar1 != '\0') {
      return CONCAT71(extraout_var_00,1);
    }
    FUN_14000ae3c();
    uVar2 = extraout_var_01;
  }
  return (ulonglong)uVar2 << 8;
}



/* 140009fcc FUN_140009fcc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140009fcc(uint param_1)

{
  code *pcVar1;
  byte bVar2;
  bool bVar3;
  ulonglong in_RAX;
  undefined7 extraout_var;
  undefined8 uVar4;
  
  if (DAT_140013889 == '\0') {
    if (1 < param_1) {
      __scrt_fastfail(5);
      pcVar1 = (code *)swi(3);
      uVar4 = (*pcVar1)();
      return uVar4;
    }
    bVar3 = __scrt_is_ucrt_dll_in_use();
    if (((int)CONCAT71(extraout_var,bVar3) == 0) || (param_1 != 0)) {
      bVar2 = 0x40 - ((byte)DAT_140013010 & 0x3f) & 0x3f;
      in_RAX = (0xffffffffffffffffU >> bVar2 | -1L << 0x40 - bVar2) ^ DAT_140013010;
      _DAT_140013890 = in_RAX;
      uRam0000000140013898 = in_RAX;
      _DAT_1400138a0 = in_RAX;
      _DAT_1400138a8 = in_RAX;
      uRam00000001400138b0 = in_RAX;
      _DAT_1400138b8 = in_RAX;
    }
    else {
      in_RAX = _initialize_onexit_table(&DAT_140013890);
      if (((int)in_RAX != 0) ||
         (in_RAX = _initialize_onexit_table(&DAT_1400138a8), (int)in_RAX != 0)) {
        return in_RAX & 0xffffffffffffff00;
      }
    }
    DAT_140013889 = '\x01';
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



/* 14000a0a4 __scrt_is_nonwritable_in_current_image */

/* Library Function - Single Match
    __scrt_is_nonwritable_in_current_image
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release */

ulonglong __scrt_is_nonwritable_in_current_image(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint7 uVar4;
  longlong lVar5;
  
  uVar3 = 0x5a4d;
  if (((IMAGE_DOS_HEADER_140000000.e_magic == (char  [2])0x5a4d) &&
      (uVar2 = (ulonglong)(int)IMAGE_DOS_HEADER_140000000.e_lfanew, uVar3 = uVar2,
      *(int *)(IMAGE_DOS_HEADER_140000000.e_magic + uVar2) == 0x4550)) &&
     (uVar3 = 0x20b,
     *(short *)((longlong)IMAGE_DOS_HEADER_140000000.e_res_4_ + (uVar2 - 4)) == 0x20b)) {
    lVar5 = uVar2 + 0x140000018 +
            (ulonglong)*(ushort *)((longlong)IMAGE_DOS_HEADER_140000000.e_res_4_ + (uVar2 - 8));
    uVar3 = (ulonglong)*(ushort *)(IMAGE_DOS_HEADER_140000000.e_magic + uVar2 + 6);
    lVar1 = lVar5 + uVar3 * 0x28;
    for (; lVar5 != lVar1; lVar5 = lVar5 + 0x28) {
      if (((ulonglong)*(uint *)(lVar5 + 0xc) <= param_1 - 0x140000000U) &&
         (uVar3 = (ulonglong)(*(int *)(lVar5 + 8) + *(uint *)(lVar5 + 0xc)),
         param_1 - 0x140000000U < uVar3)) goto LAB_14000a11b;
    }
    lVar5 = 0;
LAB_14000a11b:
    if (lVar5 == 0) {
      uVar3 = uVar3 & 0xffffffffffffff00;
    }
    else {
      uVar4 = (uint7)(uVar3 >> 8);
      if (*(int *)(lVar5 + 0x24) < 0) {
        uVar3 = (ulonglong)uVar4 << 8;
      }
      else {
        uVar3 = CONCAT71(uVar4,1);
      }
    }
  }
  else {
    uVar3 = uVar3 & 0xffffffffffffff00;
  }
  return uVar3;
}



/* 14000a140 __scrt_release_startup_lock */

/* Library Function - Single Match
    __scrt_release_startup_lock
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __scrt_release_startup_lock(char param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if ((CONCAT31(extraout_var,bVar1) != 0) && (param_1 == '\0')) {
    LOCK();
    DAT_140013880 = 0;
    UNLOCK();
  }
  return;
}



/* 14000a164 __scrt_uninitialize_crt */

/* Library Function - Single Match
    __scrt_uninitialize_crt
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release */

undefined1 __scrt_uninitialize_crt(undefined8 param_1,char param_2)

{
  if ((DAT_140013888 == '\0') || (param_2 == '\0')) {
    FUN_14000ae3c();
    FUN_14000ae3c();
  }
  return 1;
}



/* 14000a190 _onexit */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _onexit
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release */

_onexit_t __cdecl _onexit(_onexit_t _Func)

{
  int iVar1;
  byte bVar2;
  _onexit_t p_Var3;
  
  bVar2 = (byte)DAT_140013010 & 0x3f;
  if (((DAT_140013010 ^ _DAT_140013890) >> bVar2 | (DAT_140013010 ^ _DAT_140013890) << 0x40 - bVar2)
      == 0xffffffffffffffff) {
    iVar1 = _crt_atexit();
  }
  else {
    iVar1 = _register_onexit_function(&DAT_140013890,_Func);
  }
  p_Var3 = (_onexit_t)0x0;
  if (iVar1 == 0) {
    p_Var3 = _Func;
  }
  return p_Var3;
}



/* 14000a1e0 atexit */

/* Library Function - Single Match
    atexit
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release */

int __cdecl atexit(_func_5014 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = _onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



/* 14000a1f8 FUN_14000a1f8 */

undefined8 * FUN_14000a1f8(undefined8 *param_1,ulonglong param_2)

{
  *param_1 = type_info::vftable;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 14000a22c FUN_14000a22c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_14000a22c(void)

{
  code *pcVar1;
  byte bVar2;
  HMODULE hModule;
  FARPROC pFVar3;
  FARPROC pFVar4;
  FARPROC pFVar5;
  undefined8 uVar6;
  byte bVar7;
  
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)&DAT_1400138c0,4000);
  hModule = GetModuleHandleW(L"api-ms-win-core-synch-l1-2-0.dll");
  if ((hModule == (HMODULE)0x0) &&
     (hModule = GetModuleHandleW(L"kernel32.dll"), hModule == (HMODULE)0x0)) goto LAB_14000a37e;
  pFVar3 = GetProcAddress(hModule,"InitializeConditionVariable");
  pFVar4 = GetProcAddress(hModule,"SleepConditionVariableCS");
  pFVar5 = GetProcAddress(hModule,"WakeAllConditionVariable");
  if ((pFVar3 == (FARPROC)0x0) || ((pFVar4 == (FARPROC)0x0 || (pFVar5 == (FARPROC)0x0)))) {
    DAT_1400138f0 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
    if (DAT_1400138f0 != (HANDLE)0x0) goto LAB_14000a31c;
  }
  else {
    DAT_1400138f0 = (HANDLE)0x0;
    (*(code *)PTR__guard_dispatch_icall_14000ccc8)(&DAT_1400138e8);
    bVar7 = 0x40 - ((byte)DAT_140013010 & 0x3f);
    bVar2 = bVar7 & 0x3f;
    _DAT_1400138f8 = DAT_140013010 ^ ((ulonglong)pFVar4 >> bVar2 | (longlong)pFVar4 << 0x40 - bVar2)
    ;
    bVar7 = bVar7 & 0x3f;
    _DAT_140013900 = DAT_140013010 ^ ((ulonglong)pFVar5 >> bVar7 | (longlong)pFVar5 << 0x40 - bVar7)
    ;
LAB_14000a31c:
    uVar6 = FUN_140009fcc(0);
    if ((char)uVar6 != '\0') {
      atexit(FUN_14000a38c);
      return 0;
    }
    __scrt_fastfail(7);
  }
  __scrt_fastfail(7);
LAB_14000a37e:
  __scrt_fastfail(7);
  pcVar1 = (code *)swi(3);
  uVar6 = (*pcVar1)();
  return uVar6;
}



/* 14000a38c FUN_14000a38c */

void FUN_14000a38c(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_1400138c0);
  if (DAT_1400138f0 != (HANDLE)0x0) {
    CloseHandle(DAT_1400138f0);
  }
  return;
}



/* 14000a3b4 _Init_thread_footer */

/* Library Function - Single Match
    _Init_thread_footer
   
   Library: Visual Studio 2017 Release */

void _Init_thread_footer(int *param_1)

{
  ulonglong uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1400138c0);
  uVar1 = (ulonglong)_tls_index;
  DAT_140013004 = DAT_140013004 + 1;
  *param_1 = DAT_140013004;
  *(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar1 * 8) + 4) = DAT_140013004;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1400138c0);
  _Init_thread_notify();
  return;
}



/* 14000a414 _Init_thread_header */

/* Library Function - Single Match
    _Init_thread_header
   
   Library: Visual Studio 2017 Release */

void _Init_thread_header(int *param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1400138c0);
  do {
    if (*param_1 == 0) {
      *param_1 = -1;
LAB_14000a468:
                    /* WARNING: Could not recover jumptable at 0x00014000a474. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1400138c0);
      return;
    }
    if (*param_1 != -1) {
      *(undefined4 *)
       (*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4) =
           DAT_140013004;
      goto LAB_14000a468;
    }
    _Init_thread_wait(100);
  } while( true );
}



/* 14000a47c _Init_thread_notify */

/* WARNING: Switch with 1 destination removed at 0x00014000a4ad */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _Init_thread_notify
   
   Library: Visual Studio 2017 Release */

void _Init_thread_notify(void)

{
  byte bVar1;
  
  if (DAT_1400138f0 != (HANDLE)0x0) {
    SetEvent(DAT_1400138f0);
                    /* WARNING: Could not recover jumptable at 0x00014000a4c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    ResetEvent(DAT_1400138f0);
    return;
  }
  bVar1 = (byte)DAT_140013010 & 0x3f;
                    /* WARNING: Could not recover jumptable at 0x00014000b260. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((DAT_140013010 ^ _DAT_140013900) >> bVar1 |
            (DAT_140013010 ^ _DAT_140013900) << 0x40 - bVar1))(&DAT_1400138e8);
  return;
}



/* 14000a4cc _Init_thread_wait */

/* WARNING: Switch with 1 destination removed at 0x00014000a50a */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _Init_thread_wait
   
   Library: Visual Studio 2017 Release */

void _Init_thread_wait(DWORD param_1)

{
  byte bVar1;
  
  if (DAT_1400138f0 != (HANDLE)0x0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1400138c0);
    WaitForSingleObjectEx(DAT_1400138f0,param_1,0);
                    /* WARNING: Could not recover jumptable at 0x00014000a53c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1400138c0);
    return;
  }
  bVar1 = (byte)DAT_140013010 & 0x3f;
                    /* WARNING: Could not recover jumptable at 0x00014000b260. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((DAT_140013010 ^ _DAT_1400138f8) >> bVar1 |
            (DAT_140013010 ^ _DAT_1400138f8) << 0x40 - bVar1))
            (&DAT_1400138e8,&DAT_1400138c0,param_1);
  return;
}



/* 14000a544 FUN_14000a544 */

void FUN_14000a544(void)

{
  code *pcVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  ulonglong uVar7;
  undefined7 extraout_var;
  
  _set_app_type(2);
  uVar5 = FUN_14000ae24();
  _set_fmode((int)uVar5);
  puVar6 = (undefined4 *)__p__commode();
  uVar5 = FUN_140001380();
  *puVar6 = (int)uVar5;
  uVar5 = FUN_140009fcc(1);
  if ((char)uVar5 != '\0') {
    FUN_14000ae80();
    atexit(FUN_14000aebc);
    uVar7 = FUN_14000ab30();
    iVar4 = _configure_narrow_argv(uVar7 & 0xffffffff);
    if (iVar4 == 0) {
      FUN_14000ae2c();
      bVar2 = FUN_14000ae64();
      if ((int)CONCAT71(extraout_var,bVar2) != 0) {
        __setusermatherr(FUN_140001380);
      }
      _guard_check_icall();
      _guard_check_icall();
      uVar5 = FUN_140001380();
      _configthreadlocale((int)uVar5);
      cVar3 = FUN_14000ae3c();
      if (cVar3 != '\0') {
        _initialize_narrow_environment();
      }
      FUN_140001380();
      uVar5 = thunk_FUN_140001380();
      if ((int)uVar5 == 0) {
        return;
      }
    }
  }
  __scrt_fastfail(7);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* 14000a5fc FUN_14000a5fc */

undefined8 FUN_14000a5fc(void)

{
  FUN_14000ae48();
  return 0;
}



/* 14000a60c FUN_14000a60c */

void FUN_14000a60c(void)

{
  ulonglong uVar1;
  
  FUN_14000ad30();
  uVar1 = FUN_140001380();
  _set_new_mode(uVar1 & 0xffffffff);
  return;
}



/* 14000a628 FUN_14000a628 */

int FUN_14000a628(void)

{
  bool bVar1;
  WORD WVar2;
  int iVar3;
  undefined8 uVar4;
  longlong *plVar5;
  ulonglong uVar6;
  char *pcVar7;
  IMAGE_DOS_HEADER *pIVar8;
  undefined8 unaff_RBX;
  
  iVar3 = (int)unaff_RBX;
  uVar4 = __scrt_initialize_crt(1);
  if ((char)uVar4 == '\0') {
    __scrt_fastfail(7);
  }
  else {
    bVar1 = false;
    uVar4 = __scrt_acquire_startup_lock();
    iVar3 = (int)CONCAT71((int7)((ulonglong)unaff_RBX >> 8),(char)uVar4);
    if (DAT_140013878 != 1) {
      if (DAT_140013878 == 0) {
        DAT_140013878 = 1;
        iVar3 = _initterm_e(&DAT_14000cd10,&DAT_14000cd30);
        if (iVar3 != 0) {
          return 0xff;
        }
        _initterm(&DAT_14000ccd0);
        DAT_140013878 = 2;
      }
      else {
        bVar1 = true;
      }
      __scrt_release_startup_lock((char)uVar4);
      plVar5 = (longlong *)FUN_14000ae70();
      if ((*plVar5 != 0) &&
         (uVar6 = __scrt_is_nonwritable_in_current_image((longlong)plVar5), (char)uVar6 != '\0')) {
        (*(code *)PTR__guard_dispatch_icall_14000ccc8)(0);
      }
      plVar5 = (longlong *)FUN_14000ae78();
      if ((*plVar5 != 0) &&
         (uVar6 = __scrt_is_nonwritable_in_current_image((longlong)plVar5), (char)uVar6 != '\0')) {
        _register_thread_local_exe_atexit_callback(*plVar5);
      }
      WVar2 = __scrt_get_show_window_mode();
      pcVar7 = (char *)_get_narrow_winmain_command_line();
      pIVar8 = &IMAGE_DOS_HEADER_140000000;
      iVar3 = AfxWinMain((HINSTANCE__ *)&IMAGE_DOS_HEADER_140000000,(HINSTANCE__ *)0x0,pcVar7,
                         (uint)WVar2);
      uVar6 = __scrt_is_managed_app();
      if ((char)uVar6 != '\0') {
        if (!bVar1) {
          _cexit();
        }
        __scrt_uninitialize_crt(CONCAT71((int7)((ulonglong)pIVar8 >> 8),1),'\0');
        return iVar3;
      }
      goto LAB_14000a789;
    }
  }
  __scrt_fastfail(7);
LAB_14000a789:
                    /* WARNING: Subroutine does not return */
  exit(iVar3);
}



/* 14000a79c entry */

void entry(void)

{
  __security_init_cookie();
  FUN_14000a628();
  return;
}



/* 14000a7b0 __GSHandlerCheck_SEH */

/* Library Function - Single Match
    __GSHandlerCheck_SEH
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __GSHandlerCheck_SEH
               (_EXCEPTION_RECORD *param_1,void *param_2,_CONTEXT *param_3,
               _DISPATCHER_CONTEXT *param_4)

{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = *(uint **)(param_4 + 0x38);
  uVar1 = *puVar2;
  __GSHandlerCheckCommon((ulonglong)param_2,(longlong)param_4,puVar2 + (ulonglong)uVar1 * 4 + 1);
  if ((puVar2[(ulonglong)uVar1 * 4 + 1] & ((param_1->ExceptionFlags & 0x66) != 0) + 1) != 0) {
    __C_specific_handler(param_1,param_2,param_3,param_4);
  }
  return;
}



/* 14000a838 __raise_securityfailure */

/* Library Function - Single Match
    __raise_securityfailure
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __raise_securityfailure(_EXCEPTION_POINTERS *param_1)

{
  HANDLE pvVar1;
  
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter(param_1);
  pvVar1 = GetCurrentProcess();
                    /* WARNING: Could not recover jumptable at 0x00014000a865. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TerminateProcess(pvVar1,0xc0000409);
  return;
}



/* 14000a86c __report_gsfailure */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __report_gsfailure
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  BOOL BVar2;
  undefined1 *puVar3;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [48];
  
  puVar3 = auStack_38;
  BVar2 = IsProcessorFeaturePresent(0x17);
  if (BVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(2);
    puVar3 = auStack_30;
  }
  *(undefined8 *)(puVar3 + -8) = 0x14000a896;
  capture_previous_context((PCONTEXT)&DAT_1400139b0);
  _DAT_140013920 = *(undefined8 *)(puVar3 + 0x38);
  _DAT_140013a48 = puVar3 + 0x40;
  _DAT_140013a30 = *(undefined8 *)(puVar3 + 0x40);
  _DAT_140013910 = 0xc0000409;
  _DAT_140013914 = 1;
  _DAT_140013928 = 1;
  DAT_140013930 = 2;
  *(undefined8 *)(puVar3 + 0x20) = DAT_140013010;
  *(undefined8 *)(puVar3 + 0x28) = DAT_140013008;
  *(undefined8 *)(puVar3 + -8) = 0x14000a938;
  DAT_140013aa8 = _DAT_140013920;
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_14000ce78);
  return;
}



/* 14000a940 capture_previous_context */

/* Library Function - Single Match
    capture_previous_context
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void capture_previous_context(PCONTEXT param_1)

{
  DWORD64 ControlPc;
  PRUNTIME_FUNCTION FunctionEntry;
  int iVar1;
  DWORD64 local_res8;
  ulonglong local_res10;
  PVOID local_res18 [2];
  
  RtlCaptureContext();
  ControlPc = param_1->Rip;
  iVar1 = 0;
  do {
    FunctionEntry = RtlLookupFunctionEntry(ControlPc,&local_res8,(PUNWIND_HISTORY_TABLE)0x0);
    if (FunctionEntry == (PRUNTIME_FUNCTION)0x0) {
      return;
    }
    RtlVirtualUnwind(0,local_res8,ControlPc,FunctionEntry,param_1,local_res18,&local_res10,
                     (PKNONVOLATILE_CONTEXT_POINTERS)0x0);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
  return;
}



/* 14000a9b4 __isa_available_init */

/* WARNING: Removing unreachable block (ram,0x00014000aa82) */
/* WARNING: Removing unreachable block (ram,0x00014000aa00) */
/* WARNING: Removing unreachable block (ram,0x00014000a9db) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __isa_available_init
   
   Library: Visual Studio 2017 Release */

undefined8 __isa_available_init(void)

{
  int *piVar1;
  uint *puVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  byte in_XCR0;
  
  DAT_14001301c = 2;
  _DAT_140013018 = 1;
  piVar1 = (int *)cpuid_basic_info(0);
  uVar6 = 0;
  puVar2 = (uint *)cpuid_Version_info(1);
  uVar4 = puVar2[3];
  if ((piVar1[1] == 0x756e6547 && piVar1[3] == 0x6c65746e) && piVar1[2] == 0x49656e69) {
    _DAT_140013020 = 0xffffffffffffffff;
    uVar5 = *puVar2 & 0xfff3ff0;
    if ((((uVar5 == 0x106c0) || (uVar5 == 0x20660)) || (uVar5 == 0x20670)) ||
       ((uVar5 - 0x30650 < 0x21 &&
        ((0x100010001U >> ((ulonglong)(uVar5 - 0x30650) & 0x3f) & 1) != 0)))) {
      DAT_140013e80 = DAT_140013e80 | 1;
    }
  }
  if (6 < *piVar1) {
    lVar3 = cpuid_Extended_Feature_Enumeration_info(7);
    uVar6 = *(uint *)(lVar3 + 4);
    if ((uVar6 >> 9 & 1) != 0) {
      DAT_140013e80 = DAT_140013e80 | 2;
    }
  }
  if ((uVar4 >> 0x14 & 1) != 0) {
    _DAT_140013018 = 2;
    DAT_14001301c = 6;
    if ((((uVar4 >> 0x1b & 1) != 0) && ((uVar4 >> 0x1c & 1) != 0)) && ((in_XCR0 & 6) == 6)) {
      DAT_14001301c = 0xe;
      _DAT_140013018 = 3;
      if ((uVar6 & 0x20) != 0) {
        _DAT_140013018 = 5;
        DAT_14001301c = 0x2e;
      }
    }
  }
  return 0;
}



/* 14000ab30 FUN_14000ab30 */

undefined8 FUN_14000ab30(void)

{
  return 1;
}



/* 14000ab38 __scrt_is_ucrt_dll_in_use */

/* Library Function - Single Match
    __scrt_is_ucrt_dll_in_use
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

bool __scrt_is_ucrt_dll_in_use(void)

{
  return DAT_140013030 != 0;
}



/* 14000ab44 FUN_14000ab44 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14000ab44(void)

{
  _DAT_140013e84 = 0;
  return;
}



/* 14000ab4c __scrt_fastfail */

/* Library Function - Single Match
    __scrt_fastfail
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __scrt_fastfail(undefined4 param_1)

{
  code *pcVar1;
  BOOL BVar2;
  LONG LVar3;
  PRUNTIME_FUNCTION FunctionEntry;
  undefined1 *puVar4;
  undefined8 unaff_retaddr;
  DWORD64 local_res10;
  undefined1 local_res18 [8];
  undefined1 local_res20 [8];
  undefined1 auStack_5c8 [8];
  undefined1 auStack_5c0 [232];
  undefined1 local_4d8 [152];
  undefined1 *local_440;
  DWORD64 local_3e0;
  
  puVar4 = auStack_5c8;
  BVar2 = IsProcessorFeaturePresent(0x17);
  if (BVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(param_1);
    puVar4 = auStack_5c0;
  }
  *(undefined8 *)(puVar4 + -8) = 0x14000ab7f;
  FUN_14000ab44();
  *(undefined8 *)(puVar4 + -8) = 0x14000ab90;
  memset(local_4d8,0,0x4d0);
  *(undefined8 *)(puVar4 + -8) = 0x14000ab9a;
  RtlCaptureContext(local_4d8);
  *(undefined8 *)(puVar4 + -8) = 0x14000abb4;
  FunctionEntry = RtlLookupFunctionEntry(local_3e0,&local_res10,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry != (PRUNTIME_FUNCTION)0x0) {
    *(undefined8 *)(puVar4 + 0x38) = 0;
    *(undefined1 **)(puVar4 + 0x30) = local_res18;
    *(undefined1 **)(puVar4 + 0x28) = local_res20;
    *(undefined1 **)(puVar4 + 0x20) = local_4d8;
    *(undefined8 *)(puVar4 + -8) = 0x14000abf5;
    RtlVirtualUnwind(0,local_res10,local_3e0,FunctionEntry,*(PCONTEXT *)(puVar4 + 0x20),
                     *(PVOID **)(puVar4 + 0x28),*(PDWORD64 *)(puVar4 + 0x30),
                     *(PKNONVOLATILE_CONTEXT_POINTERS *)(puVar4 + 0x38));
  }
  local_440 = &stack0x00000008;
  *(undefined8 *)(puVar4 + -8) = 0x14000ac27;
  memset(puVar4 + 0x50,0,0x98);
  *(undefined8 *)(puVar4 + 0x60) = unaff_retaddr;
  *(undefined4 *)(puVar4 + 0x50) = 0x40000015;
  *(undefined4 *)(puVar4 + 0x54) = 1;
  *(undefined8 *)(puVar4 + -8) = 0x14000ac49;
  BVar2 = IsDebuggerPresent();
  *(undefined1 **)(puVar4 + 0x40) = puVar4 + 0x50;
  *(undefined1 **)(puVar4 + 0x48) = local_4d8;
  *(undefined8 *)(puVar4 + -8) = 0x14000ac6a;
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  *(undefined8 *)(puVar4 + -8) = 0x14000ac75;
  LVar3 = UnhandledExceptionFilter((_EXCEPTION_POINTERS *)(puVar4 + 0x40));
  if ((LVar3 == 0) && (BVar2 != 1)) {
    *(undefined8 *)(puVar4 + -8) = 0x14000ac85;
    FUN_14000ab44();
  }
  return;
}



/* 14000ac98 __scrt_get_show_window_mode */

/* Library Function - Single Match
    __scrt_get_show_window_mode
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

WORD __scrt_get_show_window_mode(void)

{
  WORD WVar1;
  _STARTUPINFOW local_78;
  
  memset(&local_78,0,0x68);
  GetStartupInfoW(&local_78);
  WVar1 = 10;
  if (((byte)local_78.dwFlags & 1) != 0) {
    WVar1 = local_78.wShowWindow;
  }
  return WVar1;
}



/* 14000acdc __scrt_is_managed_app */

/* Library Function - Single Match
    __scrt_is_managed_app
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

ulonglong __scrt_is_managed_app(void)

{
  HMODULE pHVar1;
  ulonglong uVar2;
  int *piVar3;
  
  pHVar1 = GetModuleHandleW((LPCWSTR)0x0);
  if ((((pHVar1 == (HMODULE)0x0) || ((short)pHVar1->unused != 0x5a4d)) ||
      (piVar3 = (int *)((longlong)&pHVar1->unused + (longlong)pHVar1[0xf].unused), *piVar3 != 0x4550
      )) || (((pHVar1 = (HMODULE)0x20b, (short)piVar3[6] != 0x20b || ((uint)piVar3[0x21] < 0xf)) ||
             (piVar3[0x3e] == 0)))) {
    uVar2 = (ulonglong)pHVar1 & 0xffffffffffffff00;
  }
  else {
    uVar2 = 0x201;
  }
  return uVar2;
}



/* 14000ad30 FUN_14000ad30 */

void FUN_14000ad30(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000ad37. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetUnhandledExceptionFilter(FUN_14000ad40);
  return;
}



/* 14000ad40 FUN_14000ad40 */

undefined8 FUN_14000ad40(undefined8 *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if ((*piVar1 == -0x1f928c9d) && (piVar1[6] == 4)) {
    if ((piVar1[8] + 0xe66cfae0U < 3) || (piVar1[8] == 0x1994000)) {
                    /* WARNING: Subroutine does not return */
      terminate();
    }
  }
  return 0;
}



/* 14000ad78 __security_init_cookie */

/* Library Function - Single Match
    __security_init_cookie
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl __security_init_cookie(void)

{
  DWORD DVar1;
  _FILETIME local_res8;
  _FILETIME local_res10;
  LARGE_INTEGER local_res18;
  
  if (DAT_140013010 == 0x2b992ddfa232) {
    local_res10.dwLowDateTime = 0;
    local_res10.dwHighDateTime = 0;
    GetSystemTimeAsFileTime(&local_res10);
    local_res8 = local_res10;
    DVar1 = GetCurrentThreadId();
    local_res8 = (_FILETIME)((ulonglong)local_res8 ^ (ulonglong)DVar1);
    DVar1 = GetCurrentProcessId();
    local_res8 = (_FILETIME)((ulonglong)local_res8 ^ (ulonglong)DVar1);
    QueryPerformanceCounter(&local_res18);
    DAT_140013010 =
         ((ulonglong)local_res18.s.LowPart << 0x20 ^
          CONCAT44(local_res18.s.HighPart,local_res18.s.LowPart) ^ (ulonglong)local_res8 ^
         (ulonglong)&local_res8) & 0xffffffffffff;
    if (DAT_140013010 == 0x2b992ddfa232) {
      DAT_140013010 = 0x2b992ddfa233;
    }
  }
  DAT_140013008 = ~DAT_140013010;
  return;
}



/* 14000ae24 FUN_14000ae24 */

undefined8 FUN_14000ae24(void)

{
  return 0x4000;
}



/* 14000ae2c FUN_14000ae2c */

void FUN_14000ae2c(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000ae33. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InitializeSListHead(&DAT_140013e90);
  return;
}



/* 14000ae3c FUN_14000ae3c */

undefined1 FUN_14000ae3c(void)

{
  return 1;
}



/* 14000ae40 FUN_14000ae40 */

undefined * FUN_14000ae40(void)

{
  return &DAT_140013ea0;
}



/* 14000ae48 FUN_14000ae48 */

void FUN_14000ae48(void)

{
  ulonglong *puVar1;
  
  puVar1 = (ulonglong *)FUN_1400083c0();
  *puVar1 = *puVar1 | 4;
  puVar1 = (ulonglong *)FUN_14000ae40();
  *puVar1 = *puVar1 | 2;
  return;
}



/* 14000ae64 FUN_14000ae64 */

bool FUN_14000ae64(void)

{
  return DAT_140013028 == 0;
}



/* 14000ae70 FUN_14000ae70 */

undefined * FUN_14000ae70(void)

{
  return &DAT_140014548;
}



/* 14000ae78 FUN_14000ae78 */

undefined * FUN_14000ae78(void)

{
  return &DAT_140014540;
}



/* 14000ae80 FUN_14000ae80 */

void FUN_14000ae80(void)

{
  longlong *plVar1;
  
  for (plVar1 = &DAT_140010350; plVar1 < &DAT_140010350; plVar1 = plVar1 + 1) {
    if (*plVar1 != 0) {
      (*(code *)PTR__guard_dispatch_icall_14000ccc8)();
    }
  }
  return;
}



/* 14000aebc FUN_14000aebc */

void FUN_14000aebc(void)

{
  longlong *plVar1;
  
  for (plVar1 = &DAT_140010360; plVar1 < &DAT_140010360; plVar1 = plVar1 + 1) {
    if (*plVar1 != 0) {
      (*(code *)PTR__guard_dispatch_icall_14000ccc8)();
    }
  }
  return;
}



/* 14000aef8 __GSHandlerCheck */

/* Library Function - Single Match
    __GSHandlerCheck
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined8
__GSHandlerCheck(undefined8 param_1,ulonglong param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4,*(uint **)(param_4 + 0x38));
  return 1;
}



/* 14000af18 __GSHandlerCheckCommon */

/* Library Function - Single Match
    __GSHandlerCheckCommon
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __GSHandlerCheckCommon(ulonglong param_1,longlong param_2,uint *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar2 = param_1;
  if ((*param_3 & 4) != 0) {
    uVar2 = (longlong)(int)param_3[1] + param_1 & (longlong)(int)-param_3[2];
  }
  uVar1 = (ulonglong)*(uint *)(*(longlong *)(param_2 + 0x10) + 8);
  if ((*(byte *)(uVar1 + 3 + *(longlong *)(param_2 + 8)) & 0xf) != 0) {
    param_1 = param_1 + (*(byte *)(uVar1 + 3 + *(longlong *)(param_2 + 8)) & 0xfffffff0);
  }
  __security_check_cookie(param_1 ^ *(ulonglong *)((longlong)(int)(*param_3 & 0xfffffff8) + uVar2));
  return;
}



/* 14000af88 CAtlBaseModule */

/* Library Function - Single Match
    public: __cdecl ATL::CAtlBaseModule::CAtlBaseModule(void) __ptr64
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

CAtlBaseModule * __thiscall ATL::CAtlBaseModule::CAtlBaseModule(CAtlBaseModule *this)

{
  DWORD DVar1;
  BOOL BVar2;
  DWORD DVar3;
  
  memset(this + 0x28,0,0x28);
  *(undefined8 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  *(IMAGE_DOS_HEADER **)(this + 0x10) = &IMAGE_DOS_HEADER_140000000;
  *(IMAGE_DOS_HEADER **)(this + 8) = &IMAGE_DOS_HEADER_140000000;
  *(undefined **)(this + 0x20) = &DAT_14000ce88;
  *(undefined4 *)this = 0x60;
  *(undefined4 *)(this + 0x18) = 0xe00;
  BVar2 = InitializeCriticalSectionEx((LPCRITICAL_SECTION)(this + 0x28),0,0);
  if (BVar2 == 0) {
    DVar3 = GetLastError();
    DVar1 = DVar3 & 0xffff | 0x80070000;
    if ((int)DVar3 < 1) {
      DVar1 = DVar3;
    }
    if ((int)DVar1 < 0) {
      BVar2 = IsDebuggerPresent();
      if (BVar2 != 0) {
        OutputDebugStringW(L"ERROR : Unable to initialize critical section in CAtlBaseModule\n");
      }
      DAT_14001453c = 1;
    }
  }
  return this;
}



/* 14000b030 ~CAtlBaseModule */

/* Library Function - Single Match
    public: __cdecl ATL::CAtlBaseModule::~CAtlBaseModule(void) __ptr64
   
   Library: Visual Studio */

void __thiscall ATL::CAtlBaseModule::~CAtlBaseModule(CAtlBaseModule *this)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(this + 0x28));
  if (*(void **)(this + 0x50) != (void *)0x0) {
    free(*(void **)(this + 0x50));
    *(undefined8 *)(this + 0x50) = 0;
  }
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  return;
}



/* 14000b108 FUN_14000b108 */

undefined8 FUN_14000b108(int param_1,undefined4 param_2)

{
  AFX_MODULE_STATE *pAVar1;
  
  pAVar1 = AfxGetModuleState();
  pAVar1[0x28] = SUB41(param_1,0);
  *(undefined4 *)(pAVar1 + 0x78) = param_2;
  if (param_1 == 0) {
    _setmbcp(-3);
  }
  return 1;
}



/* 14000b14c FID_conflict:__GSHandlerCheck_EH */

/* Library Function - Multiple Matches With Different Base Names
    __GSHandlerCheck_EH
    __GSHandlerCheck_EH4
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void FID_conflict___GSHandlerCheck_EH
               (longlong param_1,ulonglong param_2,undefined8 param_3,longlong param_4)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_4 + 0x38);
  __GSHandlerCheckCommon(param_2,param_4,(uint *)(lVar1 + 4));
  if ((*(uint *)(lVar1 + 4) & ((*(uint *)(param_1 + 4) & 0x66) != 0) + 1) != 0) {
                    /* WARNING: Subroutine does not return */
    __CxxFrameHandler3(param_1,param_2,param_3,param_4);
  }
  return;
}



/* 14000b1e0 _alloca_probe */

/* WARNING: This is an inlined function */
/* Library Function - Single Match
    _alloca_probe
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void _alloca_probe(void)

{
  undefined1 *in_RAX;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 local_res8 [32];
  
  puVar1 = local_res8 + -(longlong)in_RAX;
  if (local_res8 < in_RAX) {
    puVar1 = (undefined1 *)0x0;
  }
  if (puVar1 < StackLimit) {
    puVar2 = (undefined1 *)StackLimit;
    do {
      puVar2 = puVar2 + -0x1000;
      *puVar2 = 0;
    } while ((undefined1 *)((ulonglong)puVar1 & 0xfffffffffffff000) != puVar2);
  }
  return;
}



/* 14000b260 _guard_dispatch_icall */

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014000b260. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



/* 14000b270 Unwind@14000b270 */

void Unwind_14000b270(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0x30));
  return;
}



/* 14000b27c Unwind@14000b27c */

void Unwind_14000b27c(undefined8 param_1,longlong param_2)

{
  FUN_140001250((CDialog *)(param_2 + 0x40));
  return;
}



/* 14000b290 Catch@14000b290 */

undefined8 Catch_14000b290(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  int iVar2;
  
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_2 + 0x30));
  plVar1 = *(longlong **)(param_2 + 0x40);
  iVar2 = (**(code **)(*plVar1 + 0x28))(plVar1,param_2 + 0x50,0x200,0);
  if (iVar2 == 0) {
    ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::Format
              ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               (param_2 + 0x30),"%Ts (%Ts:%d)","Exception thrown in destructor",
               "d:\\softsetup\\microsoft visual studio\\2017\\enterprise\\vc\\tools\\msvc\\14.16.27023\\atlmfc\\include\\afxwin1.inl"
               ,0x4d);
  }
  else {
    ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::Format
              ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               (param_2 + 0x30),"%Ts (%Ts:%d)\n%Ts","Exception thrown in destructor",
               "d:\\softsetup\\microsoft visual studio\\2017\\enterprise\\vc\\tools\\msvc\\14.16.27023\\atlmfc\\include\\afxwin1.inl"
               ,0x4d,param_2 + 0x50);
  }
  AfxMessageBox(*(char **)(param_2 + 0x30),0,0);
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_2 + 0x30));
  (**(code **)(*plVar1 + 8))(plVar1,1);
  return 0x1400014d3;
}



/* 14000b346 Unwind@14000b346 */

void Unwind_14000b346(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b34d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_2 + 0x30));
  return;
}



/* 14000b360 Unwind@14000b360 */

void Unwind_14000b360(undefined8 param_1,longlong param_2)

{
  FUN_140001d40((longlong *)(param_2 + 0x78));
  return;
}



/* 14000b370 Unwind@14000b370 */

void Unwind_14000b370(undefined8 param_1,longlong param_2)

{
  FUN_140001d40((longlong *)(param_2 + 0x40));
  return;
}



/* 14000b380 Unwind@14000b380 */

void Unwind_14000b380(undefined8 param_1,longlong param_2)

{
  FUN_140001330(*(CDialog **)(param_2 + 0x50));
  return;
}



/* 14000b38c Unwind@14000b38c */

void Unwind_14000b38c(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b39a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CComboBox::~CComboBox((CComboBox *)(*(longlong *)(param_2 + 0x50) + 0xa48));
  return;
}



/* 14000b3a1 Unwind@14000b3a1 */

void Unwind_14000b3a1(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b3af. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CSliderCtrl::~CSliderCtrl((CSliderCtrl *)(*(longlong *)(param_2 + 0x50) + 0xb30));
  return;
}



/* 14000b3b6 Unwind@14000b3b6 */

void Unwind_14000b3b6(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b3c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (*(longlong *)(param_2 + 0x50) + 0xc18));
  return;
}



/* 14000b3cb Unwind@14000b3cb */

void Unwind_14000b3cb(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b3d9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CSliderCtrl::~CSliderCtrl((CSliderCtrl *)(*(longlong *)(param_2 + 0x50) + 0xc20));
  return;
}



/* 14000b3e0 Unwind@14000b3e0 */

void Unwind_14000b3e0(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b3ee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (*(longlong *)(param_2 + 0x50) + 0xd08));
  return;
}



/* 14000b3f5 Unwind@14000b3f5 */

void Unwind_14000b3f5(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b403. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CToolTipCtrl::~CToolTipCtrl((CToolTipCtrl *)(*(longlong *)(param_2 + 0x50) + 0xd10));
  return;
}



/* 14000b40a Unwind@14000b40a */

void Unwind_14000b40a(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b418. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CStatic::~CStatic((CStatic *)(*(longlong *)(param_2 + 0x50) + 0xe38));
  return;
}



/* 14000b41f Unwind@14000b41f */

void Unwind_14000b41f(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b42d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CStatic::~CStatic((CStatic *)(*(longlong *)(param_2 + 0x50) + 0xf20));
  return;
}



/* 14000b434 Unwind@14000b434 */

void Unwind_14000b434(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b442. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CStatic::~CStatic((CStatic *)(*(longlong *)(param_2 + 0x50) + 0x1008));
  return;
}



/* 14000b449 Unwind@14000b449 */

void Unwind_14000b449(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b457. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CSliderCtrl::~CSliderCtrl((CSliderCtrl *)(*(longlong *)(param_2 + 0x50) + 0x10f0));
  return;
}



/* 14000b45e Unwind@14000b45e */

void Unwind_14000b45e(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b46c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (*(longlong *)(param_2 + 0x50) + 0x11d8));
  return;
}



/* 14000b473 Unwind@14000b473 */

void Unwind_14000b473(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b481. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (*(longlong *)(param_2 + 0x50) + 0x11e0));
  return;
}



/* 14000b490 Unwind@14000b490 */

void Unwind_14000b490(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b497. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_2 + 0x78));
  return;
}



/* 14000b4a0 Unwind@14000b4a0 */

void Unwind_14000b4a0(undefined8 param_1,longlong param_2)

{
  FUN_140001330((CDialog *)(param_2 + 0x30));
  return;
}



/* 14000b4b0 Unwind@14000b4b0 */

void Unwind_14000b4b0(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b4b7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CFileDialog::~CFileDialog((CFileDialog *)(param_2 + 0xc0));
  return;
}



/* 14000b4be Unwind@14000b4be */

void Unwind_14000b4be(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b4c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_2 + 0x50));
  return;
}



/* 14000b4cc Unwind@14000b4cc */

void Unwind_14000b4cc(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b4d3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_2 + 0x58));
  return;
}



/* 14000b4da Unwind@14000b4da */

void Unwind_14000b4da(undefined8 param_1,longlong param_2)

{
  FUN_140009620(param_2 + 0x60);
  return;
}



/* 14000b4f0 Unwind@14000b4f0 */

void Unwind_14000b4f0(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b4f7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_2 + 0x58));
  return;
}



/* 14000b4fe Unwind@14000b4fe */

void Unwind_14000b4fe(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b505. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_2 + 0x50));
  return;
}



/* 14000b50c Unwind@14000b50c */

void Unwind_14000b50c(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b513. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CFileDialog::~CFileDialog((CFileDialog *)(param_2 + 0x70));
  return;
}



/* 14000b51a Unwind@14000b51a */

void Unwind_14000b51a(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b521. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_2 + 0x60));
  return;
}



/* 14000b528 Unwind@14000b528 */

void Unwind_14000b528(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b52f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_2 + 0x50));
  return;
}



/* 14000b536 Unwind@14000b536 */

void Unwind_14000b536(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b53d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CFileDialog::~CFileDialog((CFileDialog *)(param_2 + 0x70));
  return;
}



/* 14000b544 Unwind@14000b544 */

void Unwind_14000b544(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b54b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_2 + 0x60));
  return;
}



/* 14000b552 Unwind@14000b552 */

void Unwind_14000b552(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b559. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CFileDialog::~CFileDialog((CFileDialog *)(param_2 + 0x70));
  return;
}



/* 14000b560 Unwind@14000b560 */

void Unwind_14000b560(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b567. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_2 + 0x60));
  return;
}



/* 14000b570 Unwind@14000b570 */

void Unwind_14000b570(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b577. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CFile::~CFile((CFile *)(param_2 + 0x20));
  return;
}



/* 14000b57e Catch@14000b57e */

undefined * Catch_14000b57e(undefined8 param_1,longlong param_2)

{
  CException::Delete(*(CException **)(param_2 + 0x50));
  AfxMessageBox(&DAT_14000d880,0,0);
  return &DAT_140005265;
}



/* 14000b5c0 Unwind@14000b5c0 */

void Unwind_14000b5c0(undefined8 param_1,longlong param_2)

{
  FUN_140001500((undefined8 *)(param_2 + 0x50));
  return;
}



/* 14000b5d0 Unwind@14000b5d0 */

void Unwind_14000b5d0(undefined8 param_1,longlong param_2)

{
  FUN_1400083d0(param_2 + 0x40);
  return;
}



/* 14000b5e0 Unwind@14000b5e0 */

void Unwind_14000b5e0(undefined8 param_1,longlong param_2)

{
  FUN_140008080((undefined8 *)(param_2 + 0x50));
  return;
}



/* 14000b5f0 FUN_14000b5f0 */

bool FUN_14000b5f0(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3fffff03;
}



/* 14000b620 Unwind@14000b620 */

void Unwind_14000b620(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b627. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CFile::~CFile((CFile *)(param_2 + 0x38));
  return;
}



/* 14000b62e Unwind@14000b62e */

void Unwind_14000b62e(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0x30));
  return;
}



/* 14000b63a Unwind@14000b63a */

void Unwind_14000b63a(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0x30));
  return;
}



/* 14000b646 Catch@14000b646 */

undefined8 Catch_14000b646(undefined8 param_1,longlong param_2)

{
  AfxMessageBox(&DAT_14000d898,0x30,0);
  CException::Delete(*(CException **)(param_2 + 0x68));
  return 0x1400097de;
}



/* 14000b680 FUN_14000b680 */

bool FUN_14000b680(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* 14000b698 FUN_14000b698 */

void FUN_14000b698(undefined8 *param_1)

{
  _seh_filter_exe(*(undefined4 *)*param_1,param_1);
  return;
}



/* 14000b6f0 `dynamic_atexit_destructor_for_'cache'' */

/* Library Function - Single Match
    void __cdecl `private: static class CImage::GetCDCCacheInstance::CDCCache * __ptr64 __cdecl
   ATL::CImage::GetCDCCacheInstance(void)'::`2'::`dynamic atexit destructor for 'cache''(void)
   
   Library: Visual Studio 2015 Release */

void __cdecl
`private:_static_class_CImage::GetCDCCacheInstance::CDCCache*___ptr64___cdecl_ATL::CImage::GetCDCCacheInstance(void)'
::__l2::_dynamic_atexit_destructor_for__cache__(void)

{
  undefined8 *puVar1;
  longlong lVar2;
  
  puVar1 = &DAT_1400144d0;
  lVar2 = 4;
  do {
    if ((HDC)*puVar1 != (HDC)0x0) {
      DeleteDC((HDC)*puVar1);
    }
    puVar1 = puVar1 + 1;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  return;
}



/* 14000b730 FUN_14000b730 */

void FUN_14000b730(void)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_140014500);
  if (DAT_1400144f8 != 0) {
    GdiplusShutdown();
  }
  DAT_1400144f8 = 0;
                    /* WARNING: Could not recover jumptable at 0x00014000b769. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_140014500);
  return;
}


