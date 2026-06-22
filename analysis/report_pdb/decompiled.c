
/* 140001000 `dynamic_initializer_for_'theApp'' */

void __cdecl _dynamic_initializer_for__theApp__(void)

{
  CWinApp::CWinApp((CWinApp *)&theApp,(char *)0x0);
  theApp._332_4_ = 1;
  theApp._0_8_ = CDSPIApp::vftable;
  atexit(_dynamic_atexit_destructor_for__theApp__);
  return;
}



/* 140001040 `dynamic_initializer_for_'desripHolo'' */

void __cdecl _dynamic_initializer_for__desripHolo__(void)

{
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             &desripHolo,s__________________________);
  atexit(_dynamic_atexit_destructor_for__desripHolo__);
  return;
}



/* 140001070 `dynamic_initializer_for_'desripShearo'' */

void __cdecl _dynamic_initializer_for__desripShearo__(void)

{
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             &desripShearo,s____________________________);
  atexit(_dynamic_atexit_destructor_for__desripShearo__);
  return;
}



/* 140001098 `dynamic_initializer_for_'_AtlBaseModule'' */

void __cdecl ATL::_dynamic_initializer_for___AtlBaseModule__(void)

{
  CAtlBaseModule::CAtlBaseModule(&_AtlBaseModule);
  atexit(_dynamic_atexit_destructor_for___AtlBaseModule__);
  return;
}



/* 1400010b8 `dynamic_initializer_for_'_afxInitAppState'' */

void __cdecl _dynamic_initializer_for___afxInitAppState__(void)

{
  int iVar1;
  
  iVar1 = AfxInitialize(0,0xe00);
  _afxInitAppState = (char)iVar1;
  return;
}



/* 1400010e0 __empty_global_delete */

void __cdecl __empty_global_delete(void *param_1,ulong64 param_2)

{
  return;
}



/* 1400010f0 GetMessageMap */

AFX_MSGMAP * __thiscall CDSPIApp::GetMessageMap(CDSPIApp *this)

{
  return (AFX_MSGMAP *)&PTR_GetThisMessageMap_14000d298;
}



/* 140001100 `scalar_deleting_destructor' */

void * __thiscall CDSPIApp::_scalar_deleting_destructor_(CDSPIApp *this,uint param_1)

{
  CWinApp::~CWinApp((CWinApp *)this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      operator_delete(this);
      return this;
    }
    __empty_global_delete(this,0x178);
  }
  return this;
}



/* 140001150 InitInstance */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

int __thiscall CDSPIApp::InitInstance(CDSPIApp *this)

{
  int extraout_EAX;
  longlong *plVar1;
  char *pcVar2;
  undefined1 auStack_1248 [32];
  INITCOMMONCONTROLSEX local_1228;
  undefined8 local_1220;
  CShellManager *local_1218;
  CDSPIDlg local_1208;
  ulonglong local_18;
  undefined8 uStack_10;
  
  uStack_10 = 0x14000115c;
  local_1220 = 0xfffffffffffffffe;
  local_18 = __security_cookie ^ (ulonglong)auStack_1248;
  local_1228.dwSize = 8;
  local_1228.dwICC = 0xff;
  InitCommonControlsEx(&local_1228);
  CWinApp::InitInstance((CWinApp *)this);
  AfxEnableControlContainer((COccManager *)0x0);
  local_1218 = (CShellManager *)operator_new(0x18);
  if (local_1218 == (CShellManager *)0x0) {
    plVar1 = (longlong *)0x0;
  }
  else {
    plVar1 = (longlong *)CShellManager::CShellManager(local_1218);
  }
  pcVar2 = s_______________________;
  CWinApp::SetRegistryKey((CWinApp *)this,s_______________________);
  CDSPIDlg::CDSPIDlg(&local_1208,(CWnd *)pcVar2);
  *(CDSPIDlg **)&this->field_0x40 = &local_1208;
  CDialog::DoModal((CDialog *)&local_1208);
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 8))(plVar1,1);
  }
  CDSPIDlg::~CDSPIDlg(&local_1208);
  __security_check_cookie(local_18 ^ (ulonglong)auStack_1248);
  return extraout_EAX;
}



/* 140001250 ~CDSPIDlg */

void __thiscall CDSPIDlg::~CDSPIDlg(CDSPIDlg *this)

{
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             &this[1]._padding_);
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)(this + 1)
            );
  CSliderCtrl::~CSliderCtrl((CSliderCtrl *)&(this->m_CConstrastSlider).field_0x8);
  CStatic::~CStatic((CStatic *)&(this->m_StaticPicture).field_0x8);
  CStatic::~CStatic((CStatic *)&(this->m_StaticDescription).field_0x8);
  CStatic::~CStatic((CStatic *)&(this->m_StaticFigure).field_0x8);
  CToolTipCtrl::~CToolTipCtrl((CToolTipCtrl *)&(this->m_Mytip)._padding_);
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             &this->m_Mytip);
  CSliderCtrl::~CSliderCtrl((CSliderCtrl *)&(this->m_CGainControlSlider).field_0x8);
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             &this->m_CGainControlSlider);
  CSliderCtrl::~CSliderCtrl((CSliderCtrl *)&(this->m_CExposureTimeSlider).field_0x8);
  CComboBox::~CComboBox((CComboBox *)&(this->cbbADC).field_0x8);
  CDialogImpl::~CDialogImpl((CDialogImpl *)&this->_padding_);
  this->_padding_ = (longlong)CBrush::vftable;
  CGdiObject::~CGdiObject((CGdiObject *)&this->_padding_);
                    /* WARNING: Could not recover jumptable at 0x000140001320. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CDialog::~CDialog((CDialog *)this);
  return;
}



/* 140001330 ~CDialogEx */

void __thiscall CDialogEx::~CDialogEx(CDialogEx *this)

{
  CDialogImpl::~CDialogImpl(&this->m_Impl);
  *(undefined ***)&(this->m_brBkgr).field_0x0 = CBrush::vftable;
  CGdiObject::~CGdiObject((CGdiObject *)&this->m_brBkgr);
                    /* WARNING: Could not recover jumptable at 0x000140001364. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CDialog::~CDialog((CDialog *)this);
  return;
}



/* 140001370 GetApplicationRecoveryPingInterval */

ulong __thiscall CWinApp::GetApplicationRecoveryPingInterval(CWinApp *this)

{
  return 5000;
}



/* 140001380 GetApplicationRecoveryParameter */

int __cdecl CWinApp::GetApplicationRecoveryParameter(_exception *_Except)

{
  return 0;
}



/* 140001390 RestoreAutosavedFilesAtRestart */

int __thiscall CWinApp::RestoreAutosavedFilesAtRestart(CWinApp *this)

{
  return this->m_dwRestartManagerSupportFlags & 0x20;
}



/* 1400013a0 ReopenPreviousFilesAtRestart */

int __thiscall CWinApp::ReopenPreviousFilesAtRestart(CWinApp *this)

{
  return this->m_dwRestartManagerSupportFlags & 0x10;
}



/* 1400013b0 SupportsAutosaveAtInterval */

int __thiscall CWinApp::SupportsAutosaveAtInterval(CWinApp *this)

{
  return this->m_dwRestartManagerSupportFlags & 8;
}



/* 1400013c0 SupportsAutosaveAtRestart */

int __thiscall CWinApp::SupportsAutosaveAtRestart(CWinApp *this)

{
  return this->m_dwRestartManagerSupportFlags & 4;
}



/* 1400013d0 SupportsApplicationRecovery */

int __thiscall CWinApp::SupportsApplicationRecovery(CWinApp *this)

{
  return this->m_dwRestartManagerSupportFlags & 2;
}



/* 1400013e0 SupportsRestartManager */

int __thiscall CWinApp::SupportsRestartManager(CWinApp *this)

{
  return this->m_dwRestartManagerSupportFlags & 1;
}



/* 1400013f0 `scalar_deleting_destructor' */

void * __thiscall CBrush::_scalar_deleting_destructor_(CBrush *this,uint param_1)

{
  *(undefined ***)this = vftable;
  CGdiObject::~CGdiObject((CGdiObject *)this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      operator_delete(this);
      return this;
    }
    __empty_global_delete(this,0x10);
  }
  return this;
}



/* 140001450 `scalar_deleting_destructor' */

void * __thiscall CGdiObject::_scalar_deleting_destructor_(CGdiObject *this,uint param_1)

{
  ~CGdiObject(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      operator_delete(this);
      return this;
    }
    __empty_global_delete(this,0x10);
  }
  return this;
}



/* 1400014a0 ~CGdiObject */

void __thiscall CGdiObject::~CGdiObject(CGdiObject *this)

{
  undefined1 auStack_268 [56];
  undefined8 local_230;
  ulonglong local_18;
  
  local_230 = 0xfffffffffffffffe;
  local_18 = __security_cookie ^ (ulonglong)auStack_268;
  this->_padding_ = (longlong)vftable;
  CGdiObject::DeleteObject(this);
  __security_check_cookie(local_18 ^ (ulonglong)auStack_268);
  return;
}



/* 140001500 ~CnComm */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140001600 ReadPort */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140001710 WritePort */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

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



/* 1400017f0 Write */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140001970 BeginThread */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 1400019a6 FUN_1400019a6 */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140001a5c FUN_140001a5c */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140001b00 EndThread */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140001ca0 Close */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140001cf0 GetQueueCount */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140001d40 ~InnerLock */

void __thiscall CnComm::BlockBuffer::InnerLock::~InnerLock(InnerLock *this)

{
  if (this->ptr != (BlockBuffer *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000140001d4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    LeaveCriticalSection((LPCRITICAL_SECTION)&this->ptr->C_);
    return;
  }
  return;
}



/* 140001d60 ~BlockBuffer */

void __thiscall CnComm::BlockBuffer::~BlockBuffer(BlockBuffer *this)

{
  uint uVar1;
  Block *pBVar2;
  Block *pBVar3;
  
  pBVar2 = this->F_;
  this->_padding_ = (longlong)vftable;
  if (pBVar2 != (Block *)0x0) {
    if ((pBVar2 == this->L_) && (uVar1 = pBVar2->S_, this->M_ << 2 < uVar1)) {
      pBVar2->B_ = 0;
      pBVar2->E_ = 0;
      *(undefined8 *)&pBVar2->S_ = 0;
      pBVar2->N_ = (Block *)0x0;
      pBVar2->P_[0] = '\0';
      pBVar2->P_[1] = '\0';
      pBVar2->P_[2] = '\0';
      pBVar2->P_[3] = '\0';
      *(undefined4 *)&pBVar2->field_0x1c = 0;
      this->F_->S_ = uVar1;
      goto LAB_140001de7;
    }
    while (pBVar2 != (Block *)0x0) {
      this->F_ = pBVar2;
      pBVar3 = pBVar2->N_;
      operator_delete(pBVar2,0x20);
      pBVar2 = pBVar3;
    }
  }
  this->L_ = (Block *)0x0;
  this->F_ = (Block *)0x0;
  this->S_ = 0;
LAB_140001de7:
                    /* WARNING: Could not recover jumptable at 0x000140001df5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DeleteCriticalSection((LPCRITICAL_SECTION)&this->C_);
  return;
}



/* 140001e00 SafeSize */

ulong __thiscall CnComm::BlockBuffer::SafeSize(BlockBuffer *this)

{
  ulong uVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  if (this == (BlockBuffer *)0x0) {
    lpCriticalSection = (LPCRITICAL_SECTION)0x20;
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)&this->C_;
    EnterCriticalSection(lpCriticalSection);
  }
  uVar1 = this->S_;
  LeaveCriticalSection(lpCriticalSection);
  return uVar1;
}



/* 140001e40 Read */

ulong __thiscall CnComm::BlockBuffer::Read(BlockBuffer *this,void *param_1,ulong param_2)

{
  Block *pBVar1;
  uint uVar2;
  ulong uVar3;
  uint uVar4;
  Block *pBVar5;
  ulonglong uVar6;
  ulong uVar7;
  uint uVar8;
  
  pBVar5 = this->F_;
  uVar6 = 0;
  if (param_2 == 0) {
    return 0;
  }
  do {
    uVar7 = (ulong)uVar6;
    if (pBVar5 == (Block *)0x0) {
      return uVar7;
    }
    uVar3 = pBVar5->E_;
    uVar4 = pBVar5->B_;
    uVar2 = uVar3 - uVar4;
    if (param_2 - uVar7 <= uVar3 - uVar4) {
      uVar2 = param_2 - uVar7;
    }
    if (param_1 != (void *)0x0) {
      memcpy((void *)(uVar6 + (longlong)param_1),pBVar5->P_ + uVar4,(ulonglong)uVar2);
      uVar3 = pBVar5->E_;
      uVar4 = pBVar5->B_;
    }
    pBVar1 = pBVar5->N_;
    uVar8 = uVar7 + uVar2;
    uVar6 = (ulonglong)uVar8;
    if (uVar2 == uVar3 - uVar4) {
      if ((pBVar1 == (Block *)0x0) && (pBVar5->S_ <= this->M_ << 2)) {
        pBVar5->B_ = 0;
        pBVar5->E_ = 0;
      }
      else {
        operator_delete__(pBVar5);
        this->F_ = pBVar1;
        if (pBVar1 == (Block *)0x0) {
          this->L_ = (Block *)0x0;
        }
      }
    }
    else {
      pBVar5->B_ = uVar2 + uVar4;
    }
    this->S_ = this->S_ - uVar2;
    pBVar5 = pBVar1;
  } while (uVar8 < param_2);
  return uVar8;
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



/* 140001f40 NewBlock */

Block * __thiscall CnComm::BlockBuffer::NewBlock(BlockBuffer *this,ulong param_1)

{
  Block *pBVar1;
  
  if (param_1 < this->M_) {
    param_1 = this->M_;
  }
  pBVar1 = (Block *)operator_new__((ulonglong)param_1 + 0x1c);
  if (pBVar1 != (Block *)0x0) {
    pBVar1->B_ = 0;
    pBVar1->E_ = 0;
    *(undefined8 *)&pBVar1->S_ = 0;
    pBVar1->N_ = (Block *)0x0;
    pBVar1->P_[0] = '\0';
    pBVar1->P_[1] = '\0';
    pBVar1->P_[2] = '\0';
    pBVar1->P_[3] = '\0';
    *(undefined4 *)&pBVar1->field_0x1c = 0;
    pBVar1->S_ = param_1;
    if (this->L_ != (Block *)0x0) {
      this->L_->N_ = pBVar1;
      this->L_ = pBVar1;
      return pBVar1;
    }
    this->F_ = pBVar1;
    this->L_ = pBVar1;
  }
  return pBVar1;
}



/* 140001fb0 Init */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140002110 Destroy */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 1400021b0 OpenPort */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140002220 SetupPort */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140002300 PortToBuffer */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 1400023c0 BufferToPort */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 1400024f3 FUN_1400024f3 */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 1400025d0 FUN_1400025d0 */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140002620 Notify */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 1400026b0 OnReceive */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 1400026d0 OnDSR */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140002730 OnCTS */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140002790 OnBreak */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 1400027c0 OnTxEmpty */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 1400027e0 OnError */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140002830 OnRing */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140002890 OnRLSD */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 1400028f0 OnRxFlag */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140002910 OnPower */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140002930 OnRx80Full */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140002950 OnEvent1 */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140002970 OnEvent2 */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140002990 OnPrintErr */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 1400029b0 HandleEvent */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 1400029c5 FUN_1400029c5 */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140002a4c FUN_140002a4c */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140002a90 FUN_140002a90 */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140002b05 FUN_140002b05 */

void FUN_140002b05(void)

{
  longlong *unaff_RDI;
  ulonglong in_stack_00000038;
  
  (**(code **)(*unaff_RDI + 0x60))();
  __security_check_cookie(in_stack_00000038 ^ (ulonglong)&stack0x00000000);
  return;
}



/* 140002b30 OverlappedModel */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140002b6a FUN_140002b6a */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140002b82 FUN_140002b82 */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

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



/* 140002ca0 NonoverlappedModel */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140002cc8 FUN_140002cc8 */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140002de1 FUN_140002de1 */

undefined8 FUN_140002de1(void)

{
  return 0;
}



/* 140002df0 ReadModel */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140002ea0 WriteModel */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140002eb6 FUN_140002eb6 */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140002f5e FUN_140002f5e */

undefined8 FUN_140002f5e(void)

{
  return 0;
}



/* 140002f70 WatchThreadProc */

uint __cdecl CnComm::WatchThreadProc(void *param_1)

{
  uint uVar1;
  
                    /* WARNING: Load size is inaccurate */
  if ((*(uint *)((longlong)param_1 + 8) >> 1 & 1) != 0) {
    uVar1 = (**(code **)(*param_1 + 0xb0))();
    _endthreadex(uVar1);
    return uVar1;
  }
  uVar1 = (**(code **)(*param_1 + 0xb8))();
  _endthreadex(uVar1);
  return uVar1;
}



/* 140002fc0 ReadThreadProc */

uint __cdecl CnComm::ReadThreadProc(void *param_1)

{
  uint _Retval;
  
                    /* WARNING: Load size is inaccurate */
  _Retval = (**(code **)(*param_1 + 0xc0))();
  _endthreadex(_Retval);
  return _Retval;
}



/* 140002ff0 WriteThreadProc */

uint __cdecl CnComm::WriteThreadProc(void *param_1)

{
  uint _Retval;
  
                    /* WARNING: Load size is inaccurate */
  _Retval = (**(code **)(*param_1 + 200))();
  _endthreadex(_Retval);
  return _Retval;
}



/* 140003020 `scalar_deleting_destructor' */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 140003060 `scalar_deleting_destructor' */

void * __thiscall CnComm::BlockBuffer::_scalar_deleting_destructor_(BlockBuffer *this,uint param_1)

{
  ~BlockBuffer(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this,0x48);
  }
  return this;
}



/* 1400030a0 `scalar_deleting_destructor' */

void * __thiscall CAboutDlg::_scalar_deleting_destructor_(CAboutDlg *this,uint param_1)

{
  CDialogImpl::~CDialogImpl((CDialogImpl *)&this->field_0x158);
  *(undefined ***)&this->field_0x140 = CBrush::vftable;
  CGdiObject::~CGdiObject((CGdiObject *)&this->field_0x140);
  CDialog::~CDialog((CDialog *)this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      operator_delete(this);
      return this;
    }
    __empty_global_delete(this,0x170);
  }
  return this;
}



/* 140003120 GetMessageMap */

AFX_MSGMAP * __thiscall CAboutDlg::GetMessageMap(CAboutDlg *this)

{
  return (AFX_MSGMAP *)&PTR_GetThisMessageMap_14000e9f8;
}



/* 140003130 CDSPIDlg */

CDSPIDlg * __thiscall CDSPIDlg::CDSPIDlg(CDSPIDlg *this,CWnd *param_1)

{
  undefined1 *puVar1;
  HINSTANCE__ *hInstance;
  HICON pHVar2;
  uchar *puVar3;
  uchar uVar4;
  int iVar5;
  
  CDialogEx::CDialogEx((CDialogEx *)this,0x66,(CWnd *)0x0);
  this->_padding_ = (longlong)vftable;
  iVar5 = 0;
  *(undefined8 *)&this->RectPreviw = 0;
  *(undefined8 *)&(this->RectPreviw).field_0x8 = 0;
  this->unwrapsize = (CSize)0x0;
  puVar1 = &(this->cbbADC).field_0x8;
  CWnd::CWnd((CWnd *)puVar1);
  *(undefined ***)puVar1 = CComboBox::vftable;
  puVar1 = &(this->m_CExposureTimeSlider).field_0x8;
  CWnd::CWnd((CWnd *)puVar1);
  *(undefined ***)puVar1 = CSliderCtrl::vftable;
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             &this->m_CGainControlSlider,"");
  puVar1 = &(this->m_CGainControlSlider).field_0x8;
  CWnd::CWnd((CWnd *)puVar1);
  *(undefined ***)puVar1 = CSliderCtrl::vftable;
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             &this->m_Mytip,"10");
  CToolTipCtrl::CToolTipCtrl((CToolTipCtrl *)&(this->m_Mytip)._padding_);
  puVar1 = &(this->m_StaticFigure).field_0x8;
  CWnd::CWnd((CWnd *)puVar1);
  *(undefined ***)puVar1 = CStatic::vftable;
  puVar1 = &(this->m_StaticDescription).field_0x8;
  CWnd::CWnd((CWnd *)puVar1);
  *(undefined ***)puVar1 = CStatic::vftable;
  puVar1 = &(this->m_StaticPicture).field_0x8;
  CWnd::CWnd((CWnd *)puVar1);
  *(undefined ***)puVar1 = CStatic::vftable;
  puVar1 = &(this->m_CConstrastSlider).field_0x8;
  CWnd::CWnd((CWnd *)puVar1);
  *(undefined ***)puVar1 = CSliderCtrl::vftable;
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)(this + 1)
            );
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             &this[1]._padding_,"");
  AfxGetModuleState();
  hInstance = AfxFindResourceHandle((char *)0x81,&DAT_0000000e);
  pHVar2 = LoadIconW(hInstance,(LPCWSTR)0x81);
  this->m_hIcon = (HICON__ *)pHVar2;
  this->nDeviceCount = 0;
  this->m_nHeight = 0;
  this->m_nWidth = 0;
  this->m_constrast = 10;
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)(this + 1)
             ,"10");
  *(undefined4 *)&this->cbbADC = 0;
  this->m_pRawBuffer = (uchar *)0x0;
  this->m_pRawBufferRef = (uchar *)0x0;
  this->m_pImageBuffer = (uchar *)0x0;
  this->m_pImageBufferClr = (uchar *)0x0;
  this->m_CameraPhase = (uchar *)0x0;
  this->m_CameraPhaseRef = (uchar *)0x0;
  this->m_CameraDataBuf[0] = (uchar *)0x0;
  this->m_CameraDataBuf[1] = (uchar *)0x0;
  this->m_CameraDataBuf[2] = (uchar *)0x0;
  this->m_CameraDataBuf[3] = (uchar *)0x0;
  this->m_CameraFilter = (uchar *)0x0;
  this->m_CameraUnwrap = (uchar *)0x0;
  puVar3 = &ColorTable[0].rgbGreen;
  do {
    uVar4 = (uchar)iVar5;
    puVar3[1] = uVar4;
    *puVar3 = uVar4;
    ((tagRGBQUAD *)(puVar3 + -1))->rgbBlue = uVar4;
    puVar3[2] = '\0';
    iVar5 = iVar5 + 1;
    puVar3 = puVar3 + 4;
  } while (iVar5 < 0x100);
  return this;
}



/* 140003390 `scalar_deleting_destructor' */

void * __thiscall CDSPIDlg::_scalar_deleting_destructor_(CDSPIDlg *this,uint param_1)

{
  ~CDSPIDlg(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      operator_delete(this);
      return this;
    }
    __empty_global_delete(this,0x11e8);
  }
  return this;
}



/* 1400033e0 DoDataExchange */

void __thiscall CDSPIDlg::DoDataExchange(CDSPIDlg *this,CDataExchange *param_1)

{
  DDX_Control(param_1,1000,(CWnd *)&(this->m_CExposureTimeSlider).field_0x8);
  DDX_Text(param_1,0x3ea,
           (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
           &this->m_CGainControlSlider);
  DDX_Text(param_1,0x3eb,
           (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
           &this->m_Mytip);
  DDX_Control(param_1,0x3e9,(CWnd *)&(this->m_CGainControlSlider).field_0x8);
  DDX_Control(param_1,0x3fd,(CWnd *)&(this->m_StaticDescription).field_0x8);
  DDX_Control(param_1,0x3ec,(CWnd *)&(this->m_StaticPicture).field_0x8);
  DDX_Control(param_1,0x400,(CWnd *)&(this->m_CConstrastSlider).field_0x8);
  DDX_Text(param_1,0x401,
           (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)(this + 1));
  DDV_MaxChars(param_1,(CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                       (this + 1),100);
                    /* WARNING: Could not recover jumptable at 0x0001400034d1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DDX_Text(param_1,0x402,
           (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
           &this[1]._padding_);
  return;
}



/* 1400034e0 GetMessageMap */

AFX_MSGMAP * __thiscall CDSPIDlg::GetMessageMap(CDSPIDlg *this)

{
  return (AFX_MSGMAP *)&PTR_GetThisMessageMap_14000dad0;
}



/* 1400034f0 OnInitDialog */

int __thiscall CDSPIDlg::OnInitDialog(CDSPIDlg *this)

{
  int *piVar1;
  int iVar2;
  HMENU pHVar3;
  CMenu *pCVar4;
  CWnd *pCVar5;
  HDC pHVar6;
  CDC *pCVar7;
  LPCSTR local_res10;
  ulonglong uVar8;
  ulonglong uVar9;
  
  CDialog::OnInitDialog((CDialog *)this);
  pHVar3 = GetSystemMenu((HWND)this->_padding_,0);
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
      AppendMenuA((HMENU)pCVar4->m_hMenu,0x800,0,(LPCSTR)0x0);
      AppendMenuA((HMENU)pCVar4->m_hMenu,0,0x10,local_res10);
    }
    ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               &local_res10);
  }
  SendMessageA((HWND)this->_padding_,0x80,1,(LPARAM)this->m_hIcon);
  SendMessageA((HWND)this->_padding_,0x80,0,(LPARAM)this->m_hIcon);
  Ordinal_13(0xc,vendorCode);
  pCVar5 = CWnd::GetDlgItem((CWnd *)this,0x3ec);
  pHVar6 = GetDC((HWND)pCVar5->m_hWnd);
  pCVar7 = CDC::FromHandle(pHVar6);
  this->pDCShow = pCVar7;
  pCVar5 = CWnd::GetDlgItem((CWnd *)this,0x3f8);
  CWnd::EnableWindow(pCVar5,0);
  pCVar5 = CWnd::GetDlgItem((CWnd *)this,0x3f4);
  CWnd::EnableWindow(pCVar5,0);
  pCVar5 = CWnd::GetDlgItem((CWnd *)this,0x3f5);
  CWnd::EnableWindow(pCVar5,0);
  pCVar5 = CWnd::GetDlgItem((CWnd *)this,0x3f6);
  CWnd::EnableWindow(pCVar5,0);
  pCVar5 = CWnd::GetDlgItem((CWnd *)this,0x3f7);
  CWnd::EnableWindow(pCVar5,0);
  this->m_bOpen = 0;
  this->m_bStart = 0;
  this->m_bStatus = 0;
  this->Show3D = 0;
  KSJ_UnInit();
  KSJ_Init();
  iVar2 = KSJ_DeviceGetCount();
  this->nDeviceCount = iVar2;
  if (iVar2 == 0) {
    CWnd::MessageBoxA((CWnd *)this,s__________,(char *)0x0,0);
    pCVar5 = CWnd::GetDlgItem((CWnd *)this,0x3ed);
    CWnd::EnableWindow(pCVar5,0);
    return 0;
  }
  piVar1 = &this->m_nHeight;
  uVar9 = 0;
  uVar8 = 0;
  KSJ_PreviewGetDefaultFieldOfView(iVar2 + -1,0,0,&this->m_nWidth,piVar1,0,0);
  uVar9 = uVar9 & 0xffffffff00000000;
  uVar8 = uVar8 & 0xffffffff00000000;
  KSJ_PreviewSetFieldOfView(0,0,0,this->m_nWidth,*piVar1,uVar8,uVar9);
  KSJ_CaptureSetFieldOfView
            (0,0,0,this->m_nWidth,*piVar1,uVar8 & 0xffffffff00000000,uVar9 & 0xffffffff00000000);
  KSJ_CaptureGetSize(0,&this->m_nWidth,piVar1);
  KSJ_StreamStart(0);
  KSJ_CaptureSetRecover(0,0);
  this->m_bOpen = 1;
  PrepareForShowImg(this);
  CSliderCtrl::SetRange((CSliderCtrl *)&(this->m_CGainControlSlider).field_0x8,1,200,0);
  SendMessageA(*(HWND *)&(this->m_CGainControlSlider).field_0x48,0x405,1,10);
  pCVar5 = CWnd::GetDlgItem((CWnd *)this,0x3e9);
  CWnd::EnableWindow(pCVar5,0);
  pCVar5 = CWnd::GetDlgItem((CWnd *)this,0x3eb);
  CWnd::EnableWindow(pCVar5,0);
  pCVar5 = CWnd::GetDlgItem((CWnd *)this,0x3ff);
  CWnd::EnableWindow(pCVar5,0);
  CSliderCtrl::SetRange((CSliderCtrl *)&(this->m_CExposureTimeSlider).field_0x8,10,500,0);
  SendMessageA(*(HWND *)&(this->m_CExposureTimeSlider).field_0x48,0x405,1,100);
  CSliderCtrl::SetRange((CSliderCtrl *)&(this->m_CConstrastSlider).field_0x8,1,100,0);
  SendMessageA(*(HWND *)&(this->m_CConstrastSlider).field_0x48,0x405,1,(longlong)this->m_constrast);
  OnBnClickedBtnDspi(this);
  (**(code **)((this->m_Mytip)._padding_ + 0x2d8))(&(this->m_Mytip)._padding_,this,0);
  pCVar5 = CWnd::GetDlgItem((CWnd *)this,0x3f6);
  CToolTipCtrl::AddTool
            ((CToolTipCtrl *)&(this->m_Mytip)._padding_,pCVar5,s_________________________,
             (tagRECT *)0x0,0);
  pCVar5 = CWnd::GetDlgItem((CWnd *)this,0x3f7);
  CToolTipCtrl::AddTool
            ((CToolTipCtrl *)&(this->m_Mytip)._padding_,pCVar5,s_________________3D______,
             (tagRECT *)0x0,0);
  pCVar5 = CWnd::GetDlgItem((CWnd *)this,0x3f5);
  CToolTipCtrl::AddTool
            ((CToolTipCtrl *)&(this->m_Mytip)._padding_,pCVar5,s___________________,(tagRECT *)0x0,0
            );
  SendMessageA((HWND)(this->m_Mytip)._padding_,0x403,0,200);
  SendMessageA((HWND)(this->m_Mytip)._padding_,0x414,0xff0000,0);
  SendMessageA((HWND)(this->m_Mytip)._padding_,0x413,0xffffff,0);
  SendMessageA((HWND)(this->m_Mytip)._padding_,0x401,1,0);
  return 1;
}



/* 1400039d0 OnSysCommand */

void __thiscall CDSPIDlg::OnSysCommand(CDSPIDlg *this,uint param_1,long64 param_2)

{
  undefined1 local_178 [320];
  CGdiObject local_38;
  CDialogImpl local_20 [2];
  
  if ((param_1 & 0xfff0) == 0x10) {
    CDialogEx::CDialogEx((CDialogEx *)local_178,100,(CWnd *)0x0);
    local_178._0_8_ = CAboutDlg::vftable;
    CDialog::DoModal((CDialog *)local_178);
    CDialogImpl::~CDialogImpl(local_20);
    local_38._padding_ = (longlong)CBrush::vftable;
    CGdiObject::~CGdiObject(&local_38);
    CDialog::~CDialog((CDialog *)local_178);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000140003a59. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CWnd::Default((CWnd *)this);
  return;
}



/* 140003a60 OnPaint */

void __thiscall CDSPIDlg::OnPaint(CDSPIDlg *this)

{
  BOOL BVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_b8 [32];
  tagRECT tStack_98;
  CPaintDC CStack_88;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_b8;
  BVar1 = IsIconic((HWND)this->_padding_);
  if (BVar1 == 0) {
    CDialog::OnPaint((CDialog *)this);
  }
  else {
    CPaintDC::CPaintDC(&CStack_88,(CWnd *)this);
    SendMessageA((HWND)this->_padding_,0x27,CStack_88._padding_,0);
    iVar2 = GetSystemMetrics(0xb);
    iVar3 = GetSystemMetrics(0xc);
    tStack_98.left = 0;
    tStack_98.top = 0;
    tStack_98.right = 0;
    tStack_98.bottom = 0;
    GetClientRect((HWND)this->_padding_,&tStack_98);
    DrawIcon((HDC)CStack_88._padding_,(((tStack_98.right - tStack_98.left) - iVar2) + 1) / 2,
             (((tStack_98.bottom - tStack_98.top) - iVar3) + 1) / 2,(HICON)this->m_hIcon);
    CPaintDC::~CPaintDC(&CStack_88);
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
  SendMessageA((HWND)unaff_RSI->m_hWnd,0x27,(WPARAM)in_stack_00000038,0);
  iVar1 = GetSystemMetrics(0xb);
  iVar2 = GetSystemMetrics(0xc);
  local_res20._0_4_ = 0;
  local_res20._4_4_ = 0;
  LStack0000000000000028 = 0;
  LStack000000000000002c = 0;
  GetClientRect((HWND)unaff_RSI->m_hWnd,(LPRECT)&local_res20);
  DrawIcon(in_stack_00000038,(((LStack0000000000000028 - (LONG)local_res20) - iVar1) + 1) / 2,
           (((LStack000000000000002c - local_res20._4_4_) - iVar2) + 1) / 2,
           *(HICON *)&unaff_RSI[1].m_bGestureInited);
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



/* 140003b70 OnQueryDragIcon */

HICON__ * __thiscall CDSPIDlg::OnQueryDragIcon(CDSPIDlg *this)

{
  return this->m_hIcon;
}



/* 140003b80 Gray2RGB */

void __thiscall
CDSPIDlg::Gray2RGB(CDSPIDlg *this,uchar *param_1,uchar *param_2,int param_3,int param_4)

{
  uchar uVar1;
  uchar *puVar2;
  uchar *puVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uchar *puVar6;
  
  if (0 < param_3) {
    puVar6 = param_2 + 2;
    uVar4 = (ulonglong)(uint)param_3;
    do {
      if (0 < param_4) {
        puVar2 = puVar6;
        puVar3 = param_1;
        uVar5 = (ulonglong)(uint)param_4;
        do {
          puVar2[-2] = *puVar3;
          puVar2[-1] = *puVar3;
          uVar1 = *puVar3;
          puVar3 = puVar3 + param_3;
          *puVar2 = uVar1;
          puVar2 = puVar2 + param_3 * 3;
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
      }
      param_1 = param_1 + 1;
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



/* 140003c00 PrepareForShowImg */

void __thiscall CDSPIDlg::PrepareForShowImg(CDSPIDlg *this)

{
  int iVar1;
  tagBITMAPINFO *ptVar2;
  uchar *puVar3;
  uchar **ppuVar4;
  longlong lVar5;
  
  (this->m_endPoint).x = this->m_nWidth;
  iVar1 = this->m_nHeight;
  (this->m_startPoint).x = 0;
  (this->m_startPoint).y = 0;
  (this->m_endPoint).y = iVar1;
  ptVar2 = (tagBITMAPINFO *)operator_new__(0x2c);
  this->m_pBmpInfo = ptVar2;
  (ptVar2->bmiHeader).biSize = 0x28;
  (this->m_pBmpInfo->bmiHeader).biPlanes = 1;
  (this->m_pBmpInfo->bmiHeader).biBitCount = 0x18;
  (this->m_pBmpInfo->bmiHeader).biCompression = 0;
  (this->m_pBmpInfo->bmiHeader).biSizeImage = this->m_nHeight * this->m_nWidth * 3;
  (this->m_pBmpInfo->bmiHeader).biXPelsPerMeter = 0;
  (this->m_pBmpInfo->bmiHeader).biYPelsPerMeter = 0;
  (this->m_pBmpInfo->bmiHeader).biClrUsed = 0;
  (this->m_pBmpInfo->bmiHeader).biClrImportant = 0;
  (this->m_pBmpInfo->bmiHeader).biWidth = this->m_nWidth;
  (this->m_pBmpInfo->bmiHeader).biHeight = -this->m_nHeight;
  puVar3 = (uchar *)operator_new__((longlong)(this->m_nHeight * this->m_nWidth));
  this->m_pRawBuffer = puVar3;
  puVar3 = (uchar *)operator_new__((longlong)(this->m_nHeight * this->m_nWidth));
  this->m_pRawBufferRef = puVar3;
  this->m_pImageBuffer = (uchar *)0x0;
  puVar3 = (uchar *)operator_new__((longlong)(this->m_nHeight * this->m_nWidth));
  this->m_pImageBuffer = puVar3;
  puVar3 = (uchar *)operator_new__((longlong)(this->m_nHeight * this->m_nWidth * 3));
  this->m_pImageBufferClr = puVar3;
  puVar3 = (uchar *)operator_new__((longlong)(this->m_nHeight * this->m_nWidth));
  this->m_CameraPhase = puVar3;
  puVar3 = (uchar *)operator_new__((longlong)(this->m_nHeight * this->m_nWidth));
  this->m_CameraPhaseRef = puVar3;
  puVar3 = (uchar *)operator_new__((longlong)(this->m_nHeight * this->m_nWidth));
  this->m_CameraFilter = puVar3;
  puVar3 = (uchar *)operator_new__((longlong)(this->m_nHeight * this->m_nWidth));
  this->m_CameraUnwrap = puVar3;
  ppuVar4 = this->m_CameraDataBuf;
  lVar5 = 4;
  do {
    puVar3 = (uchar *)operator_new__((longlong)(this->m_nHeight * this->m_nWidth));
    *ppuVar4 = puVar3;
    ppuVar4 = ppuVar4 + 1;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  return;
}



/* 140003e30 DrawImage */

long64 __thiscall CDSPIDlg::DrawImage(CDSPIDlg *this,ulong64 param_1,long64 param_2)

{
  CWnd *pCVar1;
  HDC pHVar2;
  CDC *pCVar3;
  long64 extraout_RAX;
  HDC__ *pHVar4;
  undefined1 auStackY_a8 [32];
  tagRECT local_38;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_a8;
  pCVar1 = CWnd::GetDlgItem((CWnd *)this,0x3ec);
  pHVar2 = GetDC((HWND)pCVar1->m_hWnd);
  pCVar3 = CDC::FromHandle(pHVar2);
  GetClientRect((HWND)pCVar1->m_hWnd,&local_38);
  if (pCVar3 == (CDC *)0x0) {
    pHVar4 = (HDC__ *)0x0;
  }
  else {
    pHVar4 = pCVar3->m_hDC;
  }
  SetStretchBltMode((HDC)pHVar4,3);
  if (pCVar3 == (CDC *)0x0) {
    pHVar4 = (HDC__ *)0x0;
  }
  else {
    pHVar4 = pCVar3->m_hDC;
  }
  StretchDIBits((HDC)pHVar4,0,0,local_38.right - local_38.left,local_38.bottom - local_38.top,0,0,
                this->m_nWidth,this->m_nHeight,this->m_pRawBuffer,(BITMAPINFO *)this->m_pBmpInfo,0,
                0xcc0020);
  ReleaseDC((HWND)pCVar1->m_hWnd,(HDC)pCVar3->m_hDC);
  __security_check_cookie(local_28 ^ (ulonglong)auStackY_a8);
  return extraout_RAX;
}



/* 140003f60 DrawImage2 */

void __thiscall CDSPIDlg::DrawImage2(CDSPIDlg *this)

{
  CWnd *pCVar1;
  HDC__ *hdc;
  HDC__ *hdc_00;
  int SrcWidth;
  int iVar2;
  undefined1 auStackY_98 [32];
  uchar *lpBits;
  tagBITMAPINFO *lpbmi;
  tagRECT local_28;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  pCVar1 = CWnd::GetDlgItem((CWnd *)this,0x3ec);
  GetClientRect((HWND)pCVar1->m_hWnd,&local_28);
  hdc_00 = (HDC__ *)0x0;
  hdc = hdc_00;
  if (this->pDCShow != (CDC *)0x0) {
    hdc = this->pDCShow->m_hDC;
  }
  SetStretchBltMode((HDC)hdc,3);
  iVar2 = this->m_bStatus;
  (this->m_pBmpInfo->bmiHeader).biBitCount = 0x18;
  if (iVar2 != 6) {
    if (iVar2 == 8) {
      (this->m_pBmpInfo->bmiHeader).biWidth = *(long *)&this->unwrapsize;
      (this->m_pBmpInfo->bmiHeader).biHeight = -*(int *)&(this->unwrapsize).field_0x4;
      if (this->pDCShow != (CDC *)0x0) {
        hdc_00 = this->pDCShow->m_hDC;
      }
      lpbmi = this->m_pBmpInfo;
      lpBits = this->m_CameraUnwrapJet;
      iVar2 = *(int *)&(this->unwrapsize).field_0x4;
      SrcWidth = *(int *)&this->unwrapsize;
      goto LAB_140004170;
    }
    if (iVar2 == 5) {
      (this->m_pBmpInfo->bmiHeader).biWidth = (this->m_endPoint).x - (this->m_startPoint).x;
      (this->m_pBmpInfo->bmiHeader).biHeight = (this->m_startPoint).y - (this->m_endPoint).y;
      if (this->pDCShow != (CDC *)0x0) {
        hdc_00 = this->pDCShow->m_hDC;
      }
      lpbmi = this->m_pBmpInfo;
      iVar2 = (this->m_endPoint).y - (this->m_startPoint).y;
      SrcWidth = (this->m_endPoint).x - (this->m_startPoint).x;
      lpBits = this->m_CameraUnwrapJet;
      goto LAB_140004170;
    }
  }
  (this->m_pBmpInfo->bmiHeader).biWidth = this->m_nWidth;
  (this->m_pBmpInfo->bmiHeader).biHeight = -this->m_nHeight;
  if (this->pDCShow != (CDC *)0x0) {
    hdc_00 = this->pDCShow->m_hDC;
  }
  lpbmi = this->m_pBmpInfo;
  lpBits = this->m_pImageBufferClr;
  iVar2 = this->m_nHeight;
  SrcWidth = this->m_nWidth;
LAB_140004170:
  StretchDIBits((HDC)hdc_00,0,0,local_28.right - local_28.left,local_28.bottom - local_28.top,0,0,
                SrcWidth,iVar2,lpBits,(BITMAPINFO *)lpbmi,0,0xcc0020);
  __security_check_cookie(local_18 ^ (ulonglong)auStackY_98);
  return;
}



/* 1400041c0 OnTimer */

void __thiscall CDSPIDlg::OnTimer(CDSPIDlg *this,ulong64 param_1)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  uchar *puVar4;
  bool bVar5;
  uchar uVar6;
  uint uVar7;
  char cVar8;
  CDSPIDlg *pCVar9;
  longlong lVar10;
  int iVar11;
  longlong lVar12;
  longlong lVar13;
  uchar *puVar14;
  byte *pbVar15;
  ulonglong uVar16;
  uchar *puVar17;
  
  if (param_1 == 1) {
    iVar11 = this->m_bStatus;
    if (iVar11 == 1) {
      KSJ_CaptureRawData(this->nDeviceCount + -1,this->m_pRawBuffer);
      pCVar9 = (CDSPIDlg *)this->m_pImageBuffer;
      memcpy(pCVar9,this->m_pRawBuffer,(longlong)(this->m_nHeight * this->m_nWidth));
      Gray2RGB(pCVar9,this->m_pImageBuffer,this->m_pImageBufferClr,this->m_nWidth,this->m_nHeight);
      DrawImage2(this);
                    /* WARNING: Could not recover jumptable at 0x000140004249. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      CWnd::Default((CWnd *)this);
      return;
    }
    if (iVar11 == 2) {
      KSJ_CaptureRawData(this->nDeviceCount + -1,this->m_pRawBuffer);
      uVar7 = this->m_nHeight;
      iVar11 = this->m_nWidth;
      puVar4 = this->m_pRawBufferRef;
      puVar17 = this->m_pRawBuffer;
      puVar14 = this->m_pImageBuffer;
      if (0 < (int)(uVar7 * iVar11)) {
        lVar12 = 0;
        do {
          bVar2 = puVar4[lVar12];
          bVar3 = puVar17[lVar12];
          if (bVar2 < bVar3) {
            cVar8 = bVar3 - bVar2;
          }
          else {
            cVar8 = bVar2 - bVar3;
          }
          puVar14[lVar12] = (char)this->m_constrast * cVar8;
          lVar12 = lVar12 + 1;
        } while (lVar12 < (int)(uVar7 * iVar11));
        uVar7 = this->m_nHeight;
        iVar11 = this->m_nWidth;
        puVar14 = this->m_pImageBuffer;
      }
      Gray2RGB((CDSPIDlg *)(ulonglong)uVar7,puVar14,this->m_pImageBufferClr,iVar11,uVar7);
    }
    else {
      if (iVar11 == 3) {
        bVar5 = PhaseByFourStepCapture(this);
        if (bVar5) {
          PhaseByCalculate(this);
          uVar7 = this->m_nHeight;
          iVar11 = this->m_nWidth;
          lVar12 = (longlong)iVar11;
          puVar4 = this->m_CameraPhaseRef;
          puVar17 = this->m_CameraPhase;
          if (0 < (int)uVar7) {
            lVar13 = 0;
            uVar16 = (ulonglong)uVar7;
            do {
              if (0 < lVar12) {
                pbVar15 = puVar4 + lVar13;
                lVar10 = lVar12;
                puVar14 = puVar17 + lVar13;
                do {
                  pbVar1 = pbVar15 + ((longlong)puVar17 - (longlong)puVar4);
                  uVar6 = *pbVar1 - *pbVar15;
                  bVar2 = *pbVar15;
                  pbVar15 = pbVar15 + 1;
                  if (*pbVar1 < bVar2) {
                    uVar6 = uVar6 + 0xff;
                  }
                  *puVar14 = uVar6;
                  lVar10 = lVar10 + -1;
                  puVar14 = puVar14 + 1;
                } while (lVar10 != 0);
              }
              lVar13 = lVar13 + lVar12;
              uVar16 = uVar16 - 1;
            } while (uVar16 != 0);
            iVar11 = this->m_nWidth;
            uVar7 = this->m_nHeight;
            puVar17 = this->m_CameraPhase;
          }
          pCVar9 = (CDSPIDlg *)this->m_pImageBuffer;
          memcpy(pCVar9,puVar17,(longlong)(int)(uVar7 * iVar11));
          Gray2RGB(pCVar9,this->m_pImageBuffer,this->m_pImageBufferClr,this->m_nWidth,
                   this->m_nHeight);
          DrawImage2(this);
        }
        else {
          this->m_bStatus = 1;
        }
        goto FUN_1400044d8;
      }
      if (iVar11 == 4) {
        pCVar9 = (CDSPIDlg *)this->m_pImageBuffer;
        memcpy(pCVar9,this->m_CameraFilter,(longlong)(this->m_nHeight * this->m_nWidth));
        Gray2RGB(pCVar9,this->m_pImageBuffer,this->m_pImageBufferClr,this->m_nWidth,this->m_nHeight)
        ;
      }
      else if (iVar11 == 5) {
        Gray2RGB(this,this->m_CameraUnwrap,this->m_CameraUnwrapJet,*(int *)&this->unwrapsize,
                 *(int *)&(this->unwrapsize).field_0x4);
      }
      else if (2 < iVar11 - 6U) goto FUN_1400044d8;
    }
    DrawImage2(this);
  }
FUN_1400044d8:
                    /* WARNING: Could not recover jumptable at 0x0001400044e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CWnd::Default((CWnd *)this);
  return;
}



/* 140004250 FUN_140004250 */

void FUN_140004250(CDSPIDlg *param_1)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  uchar *puVar4;
  bool bVar5;
  uchar uVar6;
  int in_EAX;
  uint uVar7;
  char cVar8;
  CDSPIDlg *pCVar9;
  CDSPIDlg *unaff_RBX;
  longlong lVar10;
  int iVar11;
  longlong lVar12;
  longlong lVar13;
  uchar *puVar14;
  byte *pbVar15;
  ulonglong uVar16;
  uchar *puVar17;
  
  if (in_EAX == 2) {
    KSJ_CaptureRawData(param_1->nDeviceCount + -1,unaff_RBX->m_pRawBuffer);
    uVar7 = unaff_RBX->m_nHeight;
    iVar11 = unaff_RBX->m_nWidth;
    puVar4 = unaff_RBX->m_pRawBufferRef;
    puVar17 = unaff_RBX->m_pRawBuffer;
    puVar14 = unaff_RBX->m_pImageBuffer;
    if (0 < (int)(uVar7 * iVar11)) {
      lVar12 = 0;
      do {
        bVar2 = puVar4[lVar12];
        bVar3 = puVar17[lVar12];
        if (bVar2 < bVar3) {
          cVar8 = bVar3 - bVar2;
        }
        else {
          cVar8 = bVar2 - bVar3;
        }
        puVar14[lVar12] = (char)unaff_RBX->m_constrast * cVar8;
        lVar12 = lVar12 + 1;
      } while (lVar12 < (int)(uVar7 * iVar11));
      uVar7 = unaff_RBX->m_nHeight;
      iVar11 = unaff_RBX->m_nWidth;
      puVar14 = unaff_RBX->m_pImageBuffer;
    }
    CDSPIDlg::Gray2RGB((CDSPIDlg *)(ulonglong)uVar7,puVar14,unaff_RBX->m_pImageBufferClr,iVar11,
                       uVar7);
    param_1 = unaff_RBX;
  }
  else {
    if (in_EAX == 3) {
      bVar5 = CDSPIDlg::PhaseByFourStepCapture(param_1);
      if (bVar5) {
        CDSPIDlg::PhaseByCalculate(unaff_RBX);
        uVar7 = unaff_RBX->m_nHeight;
        iVar11 = unaff_RBX->m_nWidth;
        lVar12 = (longlong)iVar11;
        puVar4 = unaff_RBX->m_CameraPhaseRef;
        puVar17 = unaff_RBX->m_CameraPhase;
        if (0 < (int)uVar7) {
          lVar13 = 0;
          uVar16 = (ulonglong)uVar7;
          do {
            if (0 < lVar12) {
              pbVar15 = puVar4 + lVar13;
              lVar10 = lVar12;
              puVar14 = puVar17 + lVar13;
              do {
                pbVar1 = pbVar15 + ((longlong)puVar17 - (longlong)puVar4);
                uVar6 = *pbVar1 - *pbVar15;
                bVar2 = *pbVar15;
                pbVar15 = pbVar15 + 1;
                if (*pbVar1 < bVar2) {
                  uVar6 = uVar6 + 0xff;
                }
                *puVar14 = uVar6;
                lVar10 = lVar10 + -1;
                puVar14 = puVar14 + 1;
              } while (lVar10 != 0);
            }
            lVar13 = lVar13 + lVar12;
            uVar16 = uVar16 - 1;
          } while (uVar16 != 0);
          iVar11 = unaff_RBX->m_nWidth;
          uVar7 = unaff_RBX->m_nHeight;
          puVar17 = unaff_RBX->m_CameraPhase;
        }
        pCVar9 = (CDSPIDlg *)unaff_RBX->m_pImageBuffer;
        memcpy(pCVar9,puVar17,(longlong)(int)(uVar7 * iVar11));
        CDSPIDlg::Gray2RGB(pCVar9,unaff_RBX->m_pImageBuffer,unaff_RBX->m_pImageBufferClr,
                           unaff_RBX->m_nWidth,unaff_RBX->m_nHeight);
        CDSPIDlg::DrawImage2(unaff_RBX);
      }
      else {
        unaff_RBX->m_bStatus = 1;
      }
      goto LAB_1400044d3;
    }
    if (in_EAX == 4) {
      pCVar9 = (CDSPIDlg *)param_1->m_pImageBuffer;
      memcpy(pCVar9,param_1->m_CameraFilter,(longlong)(param_1->m_nHeight * param_1->m_nWidth));
      CDSPIDlg::Gray2RGB(pCVar9,unaff_RBX->m_pImageBuffer,unaff_RBX->m_pImageBufferClr,
                         unaff_RBX->m_nWidth,unaff_RBX->m_nHeight);
      param_1 = unaff_RBX;
    }
    else if (in_EAX == 5) {
      CDSPIDlg::Gray2RGB(param_1,param_1->m_CameraUnwrap,param_1->m_CameraUnwrapJet,
                         *(int *)&param_1->unwrapsize,*(int *)&(param_1->unwrapsize).field_0x4);
      param_1 = unaff_RBX;
    }
    else if (2 < in_EAX - 6U) goto LAB_1400044d3;
  }
  CDSPIDlg::DrawImage2(param_1);
LAB_1400044d3:
                    /* WARNING: Could not recover jumptable at 0x0001400044e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CWnd::Default((CWnd *)unaff_RBX);
  return;
}



/* 140004329 FUN_140004329 */

void FUN_140004329(void)

{
  byte *pbVar1;
  byte bVar2;
  uchar *puVar3;
  uchar uVar4;
  uint uVar5;
  int iVar6;
  longlong lVar7;
  CDSPIDlg *this;
  CDSPIDlg *unaff_RBX;
  longlong lVar8;
  longlong lVar9;
  byte *pbVar10;
  uchar *puVar11;
  ulonglong uVar12;
  uchar *_Src;
  
  CDSPIDlg::PhaseByCalculate(unaff_RBX);
  uVar5 = unaff_RBX->m_nHeight;
  iVar6 = unaff_RBX->m_nWidth;
  lVar7 = (longlong)iVar6;
  puVar3 = unaff_RBX->m_CameraPhaseRef;
  _Src = unaff_RBX->m_CameraPhase;
  if (0 < (int)uVar5) {
    lVar9 = 0;
    uVar12 = (ulonglong)uVar5;
    do {
      if (0 < lVar7) {
        pbVar10 = puVar3 + lVar9;
        lVar8 = lVar7;
        puVar11 = _Src + lVar9;
        do {
          pbVar1 = pbVar10 + ((longlong)_Src - (longlong)puVar3);
          uVar4 = *pbVar1 - *pbVar10;
          bVar2 = *pbVar10;
          pbVar10 = pbVar10 + 1;
          if (*pbVar1 < bVar2) {
            uVar4 = uVar4 + 0xff;
          }
          *puVar11 = uVar4;
          lVar8 = lVar8 + -1;
          puVar11 = puVar11 + 1;
        } while (lVar8 != 0);
      }
      lVar9 = lVar9 + lVar7;
      uVar12 = uVar12 - 1;
    } while (uVar12 != 0);
    iVar6 = unaff_RBX->m_nWidth;
    uVar5 = unaff_RBX->m_nHeight;
    _Src = unaff_RBX->m_CameraPhase;
  }
  this = (CDSPIDlg *)unaff_RBX->m_pImageBuffer;
  memcpy(this,_Src,(longlong)(int)(uVar5 * iVar6));
  CDSPIDlg::Gray2RGB(this,unaff_RBX->m_pImageBuffer,unaff_RBX->m_pImageBufferClr,unaff_RBX->m_nWidth
                     ,unaff_RBX->m_nHeight);
  CDSPIDlg::DrawImage2(unaff_RBX);
                    /* WARNING: Could not recover jumptable at 0x0001400044e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CWnd::Default((CWnd *)unaff_RBX);
  return;
}



/* 14000435e FUN_14000435e */

void FUN_14000435e(longlong param_1)

{
  byte *pbVar1;
  byte bVar2;
  char cVar3;
  uint in_EAX;
  CDSPIDlg *this;
  CDSPIDlg *unaff_RBX;
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
  this = (CDSPIDlg *)unaff_RBX->m_pImageBuffer;
  memcpy(this,unaff_RBX->m_CameraPhase,(longlong)(unaff_RBX->m_nHeight * unaff_RBX->m_nWidth));
  CDSPIDlg::Gray2RGB(this,unaff_RBX->m_pImageBuffer,unaff_RBX->m_pImageBufferClr,unaff_RBX->m_nWidth
                     ,unaff_RBX->m_nHeight);
  CDSPIDlg::DrawImage2(unaff_RBX);
                    /* WARNING: Could not recover jumptable at 0x0001400044e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CWnd::Default((CWnd *)unaff_RBX);
  return;
}



/* 1400043e8 FUN_1400043e8 */

void FUN_1400043e8(int param_1)

{
  int in_EAX;
  CDSPIDlg *this;
  CDSPIDlg *unaff_RBX;
  void *unaff_R15;
  
  this = (CDSPIDlg *)unaff_RBX->m_pImageBuffer;
  memcpy(this,unaff_R15,(longlong)(in_EAX * param_1));
  CDSPIDlg::Gray2RGB(this,unaff_RBX->m_pImageBuffer,unaff_RBX->m_pImageBufferClr,unaff_RBX->m_nWidth
                     ,unaff_RBX->m_nHeight);
  CDSPIDlg::DrawImage2(unaff_RBX);
                    /* WARNING: Could not recover jumptable at 0x0001400044e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CWnd::Default((CWnd *)unaff_RBX);
  return;
}



/* 140004438 FUN_140004438 */

void FUN_140004438(void)

{
  CWnd *unaff_RBX;
  
  *(undefined4 *)&unaff_RBX[1].m_pDynamicLayout = 1;
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



/* 1400044f0 OnBnClickedBtnCapContinue */

void __thiscall CDSPIDlg::OnBnClickedBtnCapContinue(CDSPIDlg *this)

{
  CWnd *pCVar1;
  
  pCVar1 = CWnd::GetDlgItem((CWnd *)this,0x3f8);
  CWnd::EnableWindow(pCVar1,1);
  pCVar1 = CWnd::GetDlgItem((CWnd *)this,0x3f4);
  CWnd::EnableWindow(pCVar1,1);
  pCVar1 = CWnd::GetDlgItem((CWnd *)this,0x3f5);
  CWnd::EnableWindow(pCVar1,1);
  pCVar1 = CWnd::GetDlgItem((CWnd *)this,0x3f6);
  CWnd::EnableWindow(pCVar1,1);
  pCVar1 = CWnd::GetDlgItem((CWnd *)this,0x3f7);
  CWnd::EnableWindow(pCVar1,1);
  pCVar1 = CWnd::GetDlgItem((CWnd *)this,0x3f1);
  CWnd::EnableWindow(pCVar1,1);
  KSJ_SetParam(this->nDeviceCount + -1,0xb);
  this->m_bStatus = 1;
                    /* WARNING: Could not recover jumptable at 0x0001400045d1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetTimer((HWND)this->_padding_,1,100,(TIMERPROC)0x0);
  return;
}



/* 1400045e0 OnClose */

void __thiscall CDSPIDlg::OnClose(CDSPIDlg *this)

{
  UINT_PTR in_RDX;
  
  KSJ_UnInit();
  CWnd::KillTimer((HWND)this,in_RDX);
                    /* WARNING: Subroutine does not return */
  exit(0);
}



/* 140004600 OnNMCustomdrawSliderExposuretime */

void __thiscall
CDSPIDlg::OnNMCustomdrawSliderExposuretime(CDSPIDlg *this,tagNMHDR *param_1,long64 *param_2)

{
  ulonglong uVar1;
  undefined1 auStack_48 [32];
  char local_28 [16];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  uVar1 = SendMessageA(*(HWND *)&(this->m_CExposureTimeSlider).field_0x48,0x400,0,0);
  KSJ_SetParam(this->nDeviceCount + -1,0,uVar1 & 0xffffffff);
  sprintf_s<10>((char (*) [10])local_28,"%d");
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             &this->m_CGainControlSlider,local_28);
  CWnd::UpdateData((CWnd *)this,0);
  *param_2 = 0;
  __security_check_cookie(local_18 ^ (ulonglong)auStack_48);
  return;
}



/* 1400046b0 OnNMCustomdrawSliderGain */

void __thiscall CDSPIDlg::OnNMCustomdrawSliderGain(CDSPIDlg *this,tagNMHDR *param_1,long64 *param_2)

{
  ulonglong uVar1;
  undefined1 auStack_48 [32];
  char local_28 [16];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  uVar1 = SendMessageA(*(HWND *)&(this->m_CGainControlSlider).field_0x48,0x400,0,0);
  KSJ_SetParam(this->nDeviceCount + -1,0x10,uVar1 & 0xff);
  sprintf_s<10>((char (*) [10])local_28,"%d");
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             &this->m_Mytip,local_28);
  CWnd::UpdateData((CWnd *)this,0);
  *param_2 = 0;
  __security_check_cookie(local_18 ^ (ulonglong)auStack_48);
  return;
}



/* 140004760 OnNMCustomdrawSliderConstrast */

void __thiscall
CDSPIDlg::OnNMCustomdrawSliderConstrast(CDSPIDlg *this,tagNMHDR *param_1,long64 *param_2)

{
  LRESULT LVar1;
  undefined1 auStack_48 [32];
  char local_28 [16];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  LVar1 = SendMessageA(*(HWND *)&(this->m_CConstrastSlider).field_0x48,0x400,0,0);
  this->m_constrast = (uint)LVar1 & 0xff;
  sprintf_s<10>((char (*) [10])local_28,"%d");
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)(this + 1)
             ,local_28);
  CWnd::UpdateData((CWnd *)this,0);
  *param_2 = 0;
  __security_check_cookie(local_18 ^ (ulonglong)auStack_48);
  return;
}



/* 1400047f0 OnBnClickedBtnOpen */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CDSPIDlg::OnBnClickedBtnOpen(CDSPIDlg *this)

{
  uchar *puVar1;
  int iVar2;
  __int64 _Var3;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar4;
  CWnd *pCVar5;
  ulonglong uVar6;
  uchar *puVar7;
  uint uVar8;
  uint uVar9;
  uchar *puVar10;
  int iVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  undefined1 auStackY_4b8 [32];
  char *local_468;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> local_460 [8];
  ImgDIB local_458;
  undefined8 local_408;
  CFileDialog local_3f8;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined2 local_40;
  ulonglong local_38;
  
  local_408 = 0xfffffffffffffffe;
  local_38 = __security_cookie ^ (ulonglong)auStackY_4b8;
  KillTimer((HWND)this->_padding_,1);
  local_68 = _s__________bmp____bmp_________;
  uStack_60 = _UNK_14000d768;
  local_58 = _DAT_14000d770;
  uStack_50 = _UNK_14000d778;
  local_48 = DAT_14000d780;
  local_40 = DAT_14000d788;
  uVar14 = 0;
  CFileDialog::CFileDialog(&local_3f8,1,"bmp",(char *)0x0,0,(char *)&local_68,(CWnd *)this,0,1);
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)&local_468
             ,"This is the string A,This is the string B.");
  _Var3 = CFileDialog::DoModal(&local_3f8);
  if (_Var3 == 1) {
    pCVar4 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             CFileDialog::GetPathName(&local_3f8);
    ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::operator=
              ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               &local_468,pCVar4);
    ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>(local_460);
  }
  local_458.m_lpDib = (uchar *)0x0;
  local_458.m_lpColorTable = (tagRGBQUAD *)0x0;
  local_458.m_pImgData = (uchar *)0x0;
  local_458.m_lpBmpInfoHead = (tagBITMAPINFOHEADER *)0x0;
  local_458.m_hPalette = (HPALETTE__ *)0x0;
  ImgDIB::Read(&local_458,local_468);
  puVar10 = local_458.m_lpDib;
  if (local_458.m_nBitCount == 8) {
    uVar8 = 0;
    if (this->m_bOpen == 0) {
      uVar9 = local_458.m_imgWidth;
      if (local_458.m_lpDib == (uchar *)0x0) {
        uVar9 = uVar8;
      }
      this->m_nWidth = uVar9;
      uVar9 = uVar8;
      if ((local_458.m_lpDib != (uchar *)0x0) &&
         (uVar9 = local_458.m_imgHeight, local_458.m_imgHeight < 0)) {
        uVar9 = -local_458.m_imgHeight;
      }
      this->m_nHeight = uVar9;
      PrepareForShowImg(this);
    }
    uVar13 = (ulonglong)(uint)local_458.m_imgWidth;
    if (puVar10 == (uchar *)0x0) {
      uVar13 = uVar14;
    }
    iVar2 = (int)uVar13;
    this->m_nWidth = iVar2;
    if ((puVar10 == (uchar *)0x0) || (uVar8 = local_458.m_imgHeight, -1 < local_458.m_imgHeight)) {
      this->m_nHeight = uVar8;
      uVar6 = uVar14;
      if (0 < iVar2) {
        do {
          iVar11 = (int)uVar6;
          uVar6 = uVar14;
          if (0 < (int)uVar8) {
            do {
              iVar2 = (int)uVar6;
              this->m_pRawBuffer[this->m_nWidth * iVar2 + iVar11] =
                   local_458.m_pImgData[(this->m_nHeight - iVar2) * this->m_nWidth + iVar11];
              uVar6 = (ulonglong)(iVar2 + 1U);
              uVar8 = this->m_nHeight;
            } while ((int)(iVar2 + 1U) < (int)uVar8);
            uVar13 = (ulonglong)(uint)this->m_nWidth;
          }
          iVar2 = (int)uVar13;
          uVar6 = (ulonglong)(iVar11 + 1U);
        } while ((int)(iVar11 + 1U) < iVar2);
      }
    }
    else {
      uVar8 = -local_458.m_imgHeight;
      this->m_nHeight = uVar8;
      uVar6 = uVar14;
      if (0 < iVar2) {
        do {
          uVar12 = uVar14;
          if (0 < (int)uVar8) {
            do {
              iVar2 = this->m_nWidth * (int)uVar12 + (int)uVar6;
              this->m_pRawBuffer[iVar2] = local_458.m_pImgData[iVar2];
              uVar9 = (int)uVar12 + 1;
              uVar8 = this->m_nHeight;
              uVar12 = (ulonglong)uVar9;
            } while ((int)uVar9 < (int)uVar8);
            uVar13 = (ulonglong)(uint)this->m_nWidth;
          }
          uVar9 = (int)uVar6 + 1;
          iVar2 = (int)uVar13;
          uVar6 = (ulonglong)uVar9;
        } while ((int)uVar9 < iVar2);
      }
    }
    memcpy(this->m_CameraPhase,this->m_pRawBuffer,(longlong)(int)(uVar8 * iVar2));
    memcpy(this->m_CameraFilter,this->m_pRawBuffer,(longlong)(this->m_nWidth * this->m_nHeight));
    memcpy(this->m_CameraUnwrap,this->m_pRawBuffer,(longlong)(this->m_nWidth * this->m_nHeight));
    (this->m_startPoint).x = 0;
    (this->m_startPoint).y = 0;
    (this->m_endPoint).x = this->m_nWidth;
    (this->m_endPoint).y = this->m_nHeight;
    pCVar5 = CWnd::GetDlgItem((CWnd *)this,0x3f5);
    CWnd::EnableWindow(pCVar5,1);
    pCVar5 = CWnd::GetDlgItem((CWnd *)this,0x3f6);
    CWnd::EnableWindow(pCVar5,1);
    pCVar5 = CWnd::GetDlgItem((CWnd *)this,0x3f7);
    CWnd::EnableWindow(pCVar5,1);
    memcpy(this->m_pImageBuffer,this->m_pRawBuffer,(longlong)(this->m_nWidth * this->m_nHeight));
    uVar8 = this->m_nHeight;
    uVar9 = this->m_nWidth;
    puVar1 = this->m_pImageBufferClr;
    puVar7 = this->m_pImageBuffer;
    if (0 < (int)uVar9) {
      uVar13 = (ulonglong)uVar9;
      do {
        if (0 < (int)uVar8) {
          uVar6 = uVar14;
          puVar10 = puVar7;
          uVar12 = (ulonglong)uVar8;
          do {
            puVar1[uVar6] = *puVar10;
            puVar1[uVar6 + 1] = *puVar10;
            puVar1[uVar6 + 2] = *puVar10;
            uVar6 = uVar6 + (longlong)(int)(uVar9 * 3);
            puVar10 = puVar10 + (int)uVar9;
            uVar12 = uVar12 - 1;
          } while (uVar12 != 0);
        }
        uVar14 = uVar14 + 3;
        puVar7 = puVar7 + 1;
        uVar13 = uVar13 - 1;
        puVar10 = local_458.m_lpDib;
      } while (uVar13 != 0);
    }
    this->m_bStatus = 7;
    SetTimer((HWND)this->_padding_,1,100,(TIMERPROC)0x0);
  }
  else {
    CWnd::MessageBoxA((CWnd *)this,s________8_BMP_________,(char *)0x0,0);
  }
  if (puVar10 != (uchar *)0x0) {
    operator_delete__(puVar10);
  }
  if (local_458.m_hPalette != (HPALETTE__ *)0x0) {
    DeleteObject(local_458.m_hPalette);
  }
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)&local_468
            );
  CFileDialog::~CFileDialog(&local_3f8);
  __security_check_cookie(local_38 ^ (ulonglong)auStackY_4b8);
  return;
}



/* 140004c90 OnBnClickedBtnSave */

void __thiscall CDSPIDlg::OnBnClickedBtnSave(CDSPIDlg *this)

{
  tagOFNA *ptVar1;
  __int64 _Var2;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *pCVar3;
  uchar *puVar4;
  undefined1 auStackY_418 [32];
  int iVar5;
  int iVar6;
  CSimpleStringT<char,1> local_3c8;
  char *local_3c0;
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> local_3b8 [8];
  undefined8 local_3b0;
  CFileDialog local_3a8;
  ulonglong local_18;
  
  local_3b0 = 0xfffffffffffffffe;
  local_18 = __security_cookie ^ (ulonglong)auStackY_418;
  KillTimer((HWND)this->_padding_,1);
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)&local_3c0
             ,"This is the string A,This is the string B.");
  if (this->m_bStatus == 5) {
    ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               &local_3c8);
    ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::Format
              ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               &local_3c8,"Unwrap_%.3f",(double)*(float *)&this->cbbADC);
    ATL::CSimpleStringT<char,1>::SetAt(&local_3c8,*(int *)(local_3c8.m_pszData + -0x10) + -4,'_');
    CFileDialog::CFileDialog(&local_3a8,0,"bmp",local_3c8.m_pszData,6,(char *)0x0,(CWnd *)0x0,0,1);
    ptVar1 = CFileDialog::GetOFN(&local_3a8);
    ptVar1->lpstrFilter = s__________bmp_;
    _Var2 = CFileDialog::DoModal(&local_3a8);
    if (_Var2 == 1) {
      pCVar3 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               CFileDialog::GetPathName(&local_3a8);
      ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 &local_3c0,pCVar3);
      ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>(local_3b8);
      SaveDataToBMPFile(this,local_3c0,this->m_CameraUnwrap,
                        (this->m_endPoint).x - (this->m_startPoint).x,
                        (this->m_endPoint).y - (this->m_startPoint).y,8);
    }
    CFileDialog::~CFileDialog(&local_3a8);
    ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               &local_3c8);
  }
  else if (this->m_bStatus == 8) {
    ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
    CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               &local_3c8);
    ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::Format
              ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               &local_3c8,"UnwrapJet_%.3f",(double)*(float *)&this->cbbADC);
    ATL::CSimpleStringT<char,1>::SetAt(&local_3c8,*(int *)(local_3c8.m_pszData + -0x10) + -4,'_');
    CFileDialog::CFileDialog(&local_3a8,0,"bmp",local_3c8.m_pszData,6,(char *)0x0,(CWnd *)0x0,0,1);
    ptVar1 = CFileDialog::GetOFN(&local_3a8);
    ptVar1->lpstrFilter = s__________bmp_;
    _Var2 = CFileDialog::DoModal(&local_3a8);
    if (_Var2 == 1) {
      pCVar3 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               CFileDialog::GetPathName(&local_3a8);
      ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 &local_3c0,pCVar3);
      ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>(local_3b8);
      SaveDataToBMPFile(this,local_3c0,this->m_CameraUnwrapJet,
                        (this->m_endPoint).x - (this->m_startPoint).x,
                        (this->m_endPoint).y - (this->m_startPoint).y,0x18);
    }
    CFileDialog::~CFileDialog(&local_3a8);
    ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
    ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
              ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               &local_3c8);
  }
  else {
    CFileDialog::CFileDialog(&local_3a8,0,"bmp",(char *)0x0,6,(char *)0x0,(CWnd *)0x0,0,1);
    ptVar1 = CFileDialog::GetOFN(&local_3a8);
    ptVar1->lpstrFilter = s__________bmp_;
    _Var2 = CFileDialog::DoModal(&local_3a8);
    if (_Var2 == 1) {
      pCVar3 = (CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
               CFileDialog::GetPathName(&local_3a8);
      ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::operator=
                ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
                 &local_3c0,pCVar3);
      ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
      ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>(local_3b8);
      if (((this->m_bStatus == 6) ||
          ((this->m_endPoint).x - (this->m_startPoint).x != this->m_nWidth)) ||
         (iVar5 = this->m_nHeight, (this->m_endPoint).y - (this->m_startPoint).y != iVar5)) {
        iVar6 = 0x18;
        iVar5 = this->m_nHeight;
        puVar4 = this->m_pImageBufferClr;
      }
      else {
        iVar6 = 8;
        puVar4 = this->m_pImageBuffer;
      }
      SaveDataToBMPFile(this,local_3c0,puVar4,this->m_nWidth,iVar5,iVar6);
    }
    CFileDialog::~CFileDialog(&local_3a8);
  }
  SetTimer((HWND)this->_padding_,1,100,(TIMERPROC)0x0);
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)&local_3c0
            );
  __security_check_cookie(local_18 ^ (ulonglong)auStackY_418);
  return;
}



/* 1400050b0 SaveDataToBMPFile */

bool __thiscall
CDSPIDlg::SaveDataToBMPFile
          (CDSPIDlg *this,char *param_1,uchar *param_2,int param_3,int param_4,int param_5)

{
  undefined1 extraout_AL;
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined1 auStack_c8 [32];
  CFile local_a8;
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
  local_38 = __security_cookie ^ (ulonglong)auStack_c8;
  if ((param_3 < 0) || (param_4 < 0)) {
    pcVar3 = s_________0__;
  }
  else if (param_2 == (uchar *)0x0) {
    pcVar3 = s______________;
  }
  else {
    if ((param_5 - 8U & 0xffffffef) == 0) {
      iVar1 = (int)(param_3 * param_5 + (param_3 * param_5 >> 0x1f & 7U)) >> 3;
      local_6e = iVar1 * param_4 + 0x436;
      local_70 = 0x4d42;
      local_6a = 0;
      local_66 = 0x436;
      local_60 = 0x28;
      local_58 = -param_4;
      local_54 = 1;
      local_52 = (undefined2)param_5;
      local_50 = 0;
      local_48 = 0;
      local_40 = 0;
      local_5c = param_3;
      CFile::CFile(&local_a8);
      iVar2 = CFile::Open(&local_a8,param_1,0x1012,(CFileException *)0x0);
      if (iVar2 == 0) {
        CWnd::MessageBoxA((CWnd *)this,s_______________,(char *)0x0,0);
        CFile::~CFile(&local_a8);
      }
      else {
        CFile::Write(&local_a8,&local_70,0xe);
        CFile::Write(&local_a8,&local_60,0x28);
        CFile::Write(&local_a8,ColorTable,0x400);
        iVar1 = iVar1 + 3;
        CFile::Write(&local_a8,param_2,((int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2) * param_4 * 4);
        CFile::~CFile(&local_a8);
      }
      goto LAB_140005287;
    }
    pcVar3 = s_______8__________24____;
  }
  CWnd::MessageBoxA((CWnd *)this,pcVar3,(char *)0x0,0);
LAB_140005287:
  __security_check_cookie(local_38 ^ (ulonglong)auStack_c8);
  return (bool)extraout_AL;
}



/* 1400052b0 PhaseByFourStepCapture */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 1400059a0 PhaseByCalculate */

void __thiscall CDSPIDlg::PhaseByCalculate(CDSPIDlg *this)

{
  uchar *puVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  uchar uVar5;
  int iVar6;
  int iVar7;
  ulonglong uVar8;
  uint uVar9;
  ulonglong uVar10;
  double dVar11;
  
  dVar4 = __real_406fe00000000000;
  dVar3 = __real_400921fb4d12d84a;
  dVar2 = __real_3fe0000000000000;
  uVar8 = 0;
  iVar6 = this->m_nWidth;
  iVar7 = this->m_nHeight;
  uVar10 = uVar8;
  if (0 < iVar7 * iVar6) {
    do {
      puVar1 = this->m_CameraDataBuf[0];
      iVar6 = (uint)puVar1[uVar8] - (uint)this->m_CameraDataBuf[2][uVar8];
      iVar7 = (uint)this->m_CameraDataBuf[3][uVar8] - (uint)this->m_CameraDataBuf[1][uVar8];
      if (iVar6 == 0) {
        uVar5 = '?';
        if (iVar7 < 1) {
          uVar5 = 0xbf;
        }
      }
      else {
        dVar11 = atan((double)iVar7 / (double)iVar6);
        uVar5 = (uchar)(int)((dVar11 * dVar4 * dVar2) / dVar3);
        if (iVar6 < 1) {
          uVar5 = uVar5 + '\x7f';
        }
        else if (iVar7 < 1) {
          uVar5 = uVar5 + 0xff;
        }
      }
      puVar1[uVar8] = uVar5;
      uVar9 = (int)uVar10 + 1;
      iVar7 = this->m_nHeight;
      uVar8 = uVar8 + 1;
      iVar6 = this->m_nWidth;
      uVar10 = (ulonglong)uVar9;
    } while ((int)uVar9 < iVar7 * iVar6);
  }
  memcpy(this->m_CameraPhase,this->m_CameraDataBuf[0],(longlong)(iVar7 * iVar6));
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
  dVar4 = __real_406fe00000000000;
  dVar2 = __real_3fe0000000000000;
  uVar8 = (ulonglong)unaff_R15D;
  *(undefined4 *)(in_R11 + -0x48) = unaff_XMM8_Da;
  *(undefined4 *)(in_R11 + -0x44) = unaff_XMM8_Db;
  *(undefined4 *)(in_R11 + -0x40) = unaff_XMM8_Dc;
  *(undefined4 *)(in_R11 + -0x3c) = unaff_XMM8_Dd;
  dVar3 = __real_400921fb4d12d84a;
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



/* 140005b00 OnBnClickedBtnPhasedif */

void __thiscall CDSPIDlg::OnBnClickedBtnPhasedif(CDSPIDlg *this)

{
  bool bVar1;
  
  KSJ_CaptureRawData(this->nDeviceCount + -1,this->m_pRawBuffer);
  memcpy(this->m_pRawBufferRef,this->m_pRawBuffer,(longlong)(this->m_nWidth * this->m_nHeight));
  bVar1 = PhaseByFourStepCapture(this);
  if (bVar1) {
    PhaseByCalculate(this);
    memcpy(this->m_CameraPhaseRef,this->m_CameraPhase,(longlong)(this->m_nWidth * this->m_nHeight));
    this->m_bStatus = 3;
                    /* WARNING: Could not recover jumptable at 0x000140005b98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    SetTimer((HWND)this->_padding_,1,200,(TIMERPROC)0x0);
    return;
  }
  return;
}



/* 140005bb0 OnBnClickedBtnImgdif */

void __thiscall CDSPIDlg::OnBnClickedBtnImgdif(CDSPIDlg *this)

{
  KSJ_CaptureRawData(this->nDeviceCount + -1,this->m_pRawBuffer);
  memcpy(this->m_pRawBufferRef,this->m_pRawBuffer,(longlong)(this->m_nWidth * this->m_nHeight));
  this->m_bStatus = 2;
                    /* WARNING: Could not recover jumptable at 0x000140005c0f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetTimer((HWND)this->_padding_,1,100,(TIMERPROC)0x0);
  return;
}



/* 140005c20 OnBnClickedBtnFilter */

void __thiscall CDSPIDlg::OnBnClickedBtnFilter(CDSPIDlg *this)

{
  float *pfVar1;
  CSize CVar2;
  double dVar3;
  float fVar4;
  int iVar5;
  uchar *_Dst;
  float *pfVar6;
  longlong lVar7;
  CSize CVar8;
  char *pcVar9;
  undefined1 auStackY_298 [32];
  FunDIB local_258;
  float local_198 [84];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_298;
  _Dst = (uchar *)operator_new__((longlong)(this->m_nHeight * this->m_nWidth));
  memcpy(_Dst,this->m_CameraPhase,(longlong)(this->m_nHeight * this->m_nWidth));
  memcpy(this->m_CameraFilter,this->m_CameraPhase,(longlong)(this->m_nHeight * this->m_nWidth));
  this->m_bStatus = 4;
  pcVar9 = (char *)0x64;
  SetTimer((HWND)this->_padding_,1,100,(TIMERPROC)0x0);
  fVar4 = __real_41100000;
  dVar3 = __real_401921fb4d12d84a;
  lVar7 = 5;
  pfVar6 = local_198;
  do {
    pfVar6[0] = 1.0;
    pfVar6[1] = 1.0;
    pfVar6[2] = 1.0;
    pfVar6[3] = 1.0;
    pfVar6[4] = 1.0;
    pfVar6[5] = 1.0;
    pfVar1 = pfVar6 + 0x10;
    pfVar6[6] = 1.0;
    pfVar6[7] = 1.0;
    pfVar6[8] = 1.0;
    pfVar6[9] = 1.0;
    pfVar6[10] = 1.0;
    pfVar6[0xb] = 1.0;
    pfVar6[0xc] = 1.0;
    pfVar6[0xd] = 1.0;
    pfVar6[0xe] = 1.0;
    pfVar6[0xf] = 1.0;
    lVar7 = lVar7 + -1;
    pfVar6 = pfVar1;
  } while (lVar7 != 0);
  *pfVar1 = 1.0;
  local_258._padding_ = 0;
  local_258._padding_ = 0;
  local_258._padding_ = 0;
  local_258._padding_ = 0;
  local_258._padding_ = 0;
  local_258.m_rcZoom._0_8_ = 0;
  local_258.m_rcZoom._8_8_ = 0;
  local_258.m_pImgDataOut = (uchar *)0x0;
  local_258.m_pImgMask = (uchar *)0x0;
  local_258.m_pImgDataBuf1 = (uchar *)0x0;
  local_258.m_pImgDataBuf2 = (uchar *)0x0;
  local_258.m_pImgDataBuf3 = (uchar *)0x0;
  local_258.m_lpColorTableOut = (tagRGBQUAD *)0x0;
  local_258.m_pImgBufInput = (double *)0x0;
  local_258.m_pImgBufOut1 = (double *)0x0;
  local_258.m_pImgBufOut2 = (double *)0x0;
  local_258.m_nColorTableLengthOut = 0;
  local_258.m_nBitCountOut = 0;
  local_258.m_imgWidthOut = 0;
  local_258.m_imgHeightOut = 0;
  local_258.m_dPhaseDifOut = 0.0;
  CVar2._4_4_ = this->m_nHeight;
  CVar2._0_4_ = this->m_nWidth;
  do {
    lVar7 = 3;
    do {
      CVar8 = CVar2;
      ImgDIB::ReplaceDib((ImgDIB *)&local_258,CVar2,(int)pcVar9,this->m_pBmpInfo->bmiColors,_Dst,
                         dVar3);
      pcVar9 = (char *)local_198;
      FunDIB::SpecialFilterEx(&local_258,CVar8._0_4_,local_198,fVar4);
      lVar7 = lVar7 + -1;
    } while (lVar7 != 0);
    memcpy(this->m_CameraFilter,local_258.m_pImgDataOut,(longlong)(this->m_nHeight * this->m_nWidth)
          );
    memcpy(_Dst,this->m_CameraFilter,(longlong)(this->m_nHeight * this->m_nWidth));
    pcVar9 = "Phase Smoothing";
    iVar5 = CWnd::MessageBoxA((CWnd *)this,s________,"Phase Smoothing",4);
  } while (iVar5 != 6);
  operator_delete__(_Dst);
  FunDIB::~FunDIB(&local_258);
  __security_check_cookie(local_48 ^ (ulonglong)auStackY_298);
  return;
}



/* 140005e90 OnBnClickedBtnUnwrap */

void __thiscall CDSPIDlg::OnBnClickedBtnUnwrap(CDSPIDlg *this)

{
  int iVar1;
  uchar *puVar2;
  int iVar3;
  CSize CVar4;
  int iVar5;
  uchar *in_R8;
  int iVar6;
  int iVar7;
  undefined1 auStackY_128 [32];
  FunDIB local_e8;
  char local_28 [16];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_128;
  iVar1 = (this->m_endPoint).x - (this->m_startPoint).x;
  *(int *)&this->unwrapsize = iVar1;
  iVar3 = (this->m_endPoint).y - (this->m_startPoint).y;
  *(int *)&(this->unwrapsize).field_0x4 = iVar3;
  if ((this->m_nWidth != iVar1) || (this->m_nHeight != iVar3)) {
    operator_delete__(this->m_CameraUnwrap);
    puVar2 = (uchar *)operator_new__((longlong)
                                     (*(int *)&this->unwrapsize *
                                     *(int *)&(this->unwrapsize).field_0x4));
    this->m_CameraUnwrap = puVar2;
    iVar1 = *(int *)&this->unwrapsize;
    iVar3 = *(int *)&(this->unwrapsize).field_0x4;
  }
  iVar5 = (int)in_R8;
  iVar6 = iVar3;
  iVar7 = 0;
  if (0 < iVar1) {
    do {
      iVar3 = iVar6;
      iVar6 = 0;
      if (iVar3 < 1) {
        iVar6 = *(int *)&(this->unwrapsize).field_0x4;
      }
      else {
        do {
          in_R8 = this->m_CameraFilter;
          this->m_CameraUnwrap[*(int *)&this->unwrapsize * iVar6 + iVar7] =
               in_R8[((this->m_startPoint).y + iVar6) * this->m_nWidth + (this->m_startPoint).x +
                     iVar7];
          iVar6 = iVar6 + 1;
          iVar3 = *(int *)&(this->unwrapsize).field_0x4;
        } while (iVar6 < iVar3);
        iVar1 = *(int *)&this->unwrapsize;
        iVar6 = iVar3;
      }
      iVar5 = (int)in_R8;
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar1);
  }
  this->m_CameraUnwrapJet = (uchar *)0x0;
  puVar2 = (uchar *)operator_new__((longlong)(*(int *)&this->unwrapsize * iVar3 * 3));
  this->m_CameraUnwrapJet = puVar2;
  local_e8._padding_ = 0;
  local_e8._padding_ = 0;
  local_e8._padding_ = 0;
  local_e8._padding_ = 0;
  local_e8._padding_ = 0;
  local_e8.m_rcZoom._0_8_ = 0;
  local_e8.m_rcZoom._8_8_ = 0;
  local_e8.m_pImgDataOut = (uchar *)0x0;
  local_e8.m_pImgMask = (uchar *)0x0;
  local_e8.m_pImgDataBuf1 = (uchar *)0x0;
  local_e8.m_pImgDataBuf2 = (uchar *)0x0;
  local_e8.m_pImgDataBuf3 = (uchar *)0x0;
  local_e8.m_lpColorTableOut = (tagRGBQUAD *)0x0;
  local_e8.m_pImgBufInput = (double *)0x0;
  local_e8.m_pImgBufOut1 = (double *)0x0;
  local_e8.m_pImgBufOut2 = (double *)0x0;
  local_e8.m_nColorTableLengthOut = 0;
  local_e8.m_nBitCountOut = 0;
  local_e8.m_imgWidthOut = 0;
  local_e8.m_imgHeightOut = 0;
  local_e8.m_dPhaseDifOut = 0.0;
  CVar4 = this->unwrapsize;
  ImgDIB::ReplaceDib((ImgDIB *)&local_e8,CVar4,iVar5,this->m_pBmpInfo->bmiColors,
                     this->m_CameraUnwrap,__real_401921fb4d12d84a);
  FunDIB::PhaseUnwrap(&local_e8,CVar4._0_4_);
  memcpy(this->m_CameraUnwrap,local_e8.m_pImgDataOut,
         (longlong)(*(int *)&this->unwrapsize * *(int *)&(this->unwrapsize).field_0x4));
  *(float *)&this->cbbADC =
       (float)((local_e8.m_dPhaseDifOut * __real_3fe0000000000000) / __real_400921fb4d12d84a);
  sprintf_s<10>((char (*) [10])local_28,"%.3f");
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::operator=
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             &this[1]._padding_,local_28);
  CWnd::UpdateData((CWnd *)this,0);
  this->m_bStatus = 5;
  SetTimer((HWND)this->_padding_,1,100,(TIMERPROC)0x0);
  FunDIB::~FunDIB(&local_e8);
  __security_check_cookie(local_18 ^ (ulonglong)auStackY_128);
  return;
}



/* 140006150 grayToJet */

void __cdecl grayToJet(uchar *param_1,uchar *param_2,int param_3,int param_4)

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
  uchar *puVar10;
  uchar *puVar11;
  longlong lVar12;
  ulonglong uVar13;
  uchar *puVar14;
  longlong lVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  
  fVar9 = __real_437f0000;
  fVar8 = __real_40800000;
  dVar7 = __real_406fe00000000000;
  fVar6 = __real_3f800000;
  fVar5 = __real_3f600000;
  fVar4 = __real_3f200000;
  fVar3 = __real_3f000000;
  fVar2 = __real_3ec00000;
  fVar1 = __real_3e000000;
  if (0 < param_4) {
    puVar14 = param_1 + 2;
    puVar11 = param_2 + 2;
    lVar15 = (longlong)param_3;
    uVar13 = (ulonglong)(uint)param_4;
    do {
      lVar12 = 0;
      if (3 < lVar15) {
        puVar10 = puVar11;
        do {
          fVar18 = (float)puVar14[lVar12 + -2] / fVar9;
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
          puVar10[-2] = (uchar)(int)((double)fVar16 * dVar7);
          puVar10[-1] = (uchar)(int)((double)fVar17 * dVar7);
          *puVar10 = (uchar)(int)((double)fVar18 * dVar7);
          fVar18 = (float)puVar14[lVar12 + -1] / fVar9;
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
          puVar10[1] = (uchar)(int)((double)fVar16 * dVar7);
          puVar10[2] = (uchar)(int)((double)fVar17 * dVar7);
          puVar10[3] = (uchar)(int)((double)fVar18 * dVar7);
          fVar18 = (float)puVar14[lVar12] / fVar9;
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
          puVar10[4] = (uchar)(int)((double)fVar16 * dVar7);
          puVar10[5] = (uchar)(int)((double)fVar17 * dVar7);
          puVar10[6] = (uchar)(int)((double)fVar18 * dVar7);
          fVar18 = (float)puVar14[lVar12 + 1] / fVar9;
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
          puVar10[7] = (uchar)(int)((double)fVar16 * dVar7);
          puVar10[8] = (uchar)(int)((double)fVar17 * dVar7);
          puVar10[9] = (uchar)(int)((double)fVar18 * dVar7);
          puVar10 = puVar10 + 0xc;
        } while (lVar12 < lVar15 + -3);
      }
      if (lVar12 < lVar15) {
        puVar10 = param_2 + (longlong)(puVar14 + lVar12 + (-2 - (longlong)param_1)) * 3 + 2;
        do {
          fVar18 = (float)puVar14[lVar12 + -2] / fVar9;
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
          puVar10[-2] = (uchar)(int)((double)fVar16 * dVar7);
          puVar10[-1] = (uchar)(int)((double)fVar17 * dVar7);
          *puVar10 = (uchar)(int)((double)fVar18 * dVar7);
          puVar10 = puVar10 + 3;
        } while (lVar12 < lVar15);
      }
      puVar11 = puVar11 + lVar15 * 3;
      puVar14 = puVar14 + lVar15;
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
  fVar4 = __real_3f600000;
  *(undefined4 *)(in_RAX + -0x28) = unaff_XMM7_Da;
  *(undefined4 *)(in_RAX + -0x24) = unaff_XMM7_Db;
  *(undefined4 *)(in_RAX + -0x20) = unaff_XMM7_Dc;
  *(undefined4 *)(in_RAX + -0x1c) = unaff_XMM7_Dd;
  fVar2 = __real_3ec00000;
  *(undefined4 *)(in_RAX + -0x38) = unaff_XMM8_Da;
  *(undefined4 *)(in_RAX + -0x34) = unaff_XMM8_Db;
  *(undefined4 *)(in_RAX + -0x30) = unaff_XMM8_Dc;
  *(undefined4 *)(in_RAX + -0x2c) = unaff_XMM8_Dd;
  fVar1 = __real_3e000000;
  *(undefined4 *)(in_RAX + -0x48) = unaff_XMM9_Da;
  *(undefined4 *)(in_RAX + -0x44) = unaff_XMM9_Db;
  *(undefined4 *)(in_RAX + -0x40) = unaff_XMM9_Dc;
  *(undefined4 *)(in_RAX + -0x3c) = unaff_XMM9_Dd;
  dVar5 = __real_406fe00000000000;
  *(undefined4 *)(in_RAX + -0x58) = unaff_XMM10_Da;
  *(undefined4 *)(in_RAX + -0x54) = unaff_XMM10_Db;
  *(undefined4 *)(in_RAX + -0x50) = unaff_XMM10_Dc;
  *(undefined4 *)(in_RAX + -0x4c) = unaff_XMM10_Dd;
  fVar6 = __real_437f0000;
  fVar3 = __real_3f000000;
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



/* 140006650 OnBnClickedBtn3d */

void __thiscall CDSPIDlg::OnBnClickedBtn3d(CDSPIDlg *this)

{
  grayToJet(this->m_CameraUnwrap,this->m_CameraUnwrapJet,*(int *)&this->unwrapsize,
            *(int *)&(this->unwrapsize).field_0x4);
  this->m_bStatus = 8;
                    /* WARNING: Could not recover jumptable at 0x000140006698. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetTimer((HWND)this->_padding_,1,100,(TIMERPROC)0x0);
  return;
}



/* 1400066a0 OnBnClickedBtnDspi */

void __thiscall CDSPIDlg::OnBnClickedBtnDspi(CDSPIDlg *this)

{
  long *plVar1;
  HBITMAP__ *ho;
  CWnd *pCVar2;
  HDC pHVar3;
  CDC *pCVar4;
  CInitGDIPlus *pCVar5;
  HDC__ *pHVar6;
  int in_R9D;
  undefined1 auStackY_e8 [32];
  int in_stack_ffffffffffffff48;
  int in_stack_ffffffffffffff50;
  CImage local_98;
  undefined8 local_48;
  tagRECT local_40;
  ulonglong local_30;
  
  local_48 = 0xfffffffffffffffe;
  local_30 = __security_cookie ^ (ulonglong)auStackY_e8;
  pCVar2 = CWnd::GetDlgItem((CWnd *)this,0x3fe);
  pHVar3 = GetDC((HWND)pCVar2->m_hWnd);
  pCVar4 = CDC::FromHandle(pHVar3);
  pHVar6 = (HDC__ *)0x0;
  if (pCVar4 != (CDC *)0x0) {
    pHVar6 = pCVar4->m_hDC;
  }
  local_40.left = 0;
  local_40.top = 0;
  local_40.right = 0;
  local_40.bottom = 0;
  GetClientRect((HWND)pCVar2->m_hWnd,&local_40);
  local_98._padding_ = (longlong)ATL::CImage::vftable;
  local_98.m_hBitmap = (HBITMAP__ *)0x0;
  local_98.m_pBits = (void *)0x0;
  local_98.m_nWidth = 0;
  local_98.m_nHeight = 0;
  local_98.m_nPitch = 0;
  local_98.m_nBPP = 0;
  local_98.m_bIsDIBSection = false;
  local_98.m_bHasAlphaChannel = false;
  local_98.m_iTransparentColor = -1;
  local_98.m_clrTransparentColor = 0xffffffff;
  local_98.m_hDC = (HDC__ *)0x0;
  local_98.m_nDCRefCount = 0;
  local_98.m_hOldBitmap = (HBITMAP__ *)0x0;
  pCVar5 = ATL::CImage::GetInitGDIPlusInstance();
  EnterCriticalSection((LPCRITICAL_SECTION)&pCVar5->m_sect);
  pCVar5->m_nCImageObjects = pCVar5->m_nCImageObjects + 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)&pCVar5->m_sect);
  ATL::CImage::Load(&local_98,"res\\Holography.png");
  ATL::CImage::Draw(&local_98,pHVar6,local_40.bottom - local_40.top,in_R9D,
                    local_40.right - local_40.left,local_40.bottom - local_40.top,
                    in_stack_ffffffffffffff48,in_stack_ffffffffffffff50,local_98.m_nWidth,
                    local_98.m_nHeight);
  CWnd::SetWindowTextA((CWnd *)&(this->m_StaticDescription).field_0x8,(char *)desripHolo);
  ho = local_98.m_hBitmap;
  local_98._padding_ = (longlong)ATL::CImage::vftable;
  if (local_98.m_hBitmap != (HBITMAP__ *)0x0) {
    local_98.m_hBitmap = (HBITMAP__ *)0x0;
    local_98.m_pBits = (void *)0x0;
    local_98.m_nWidth = 0;
    local_98.m_nHeight = 0;
    local_98.m_nPitch = 0;
    local_98.m_nBPP = 0;
    local_98.m_iTransparentColor = -1;
    local_98.m_clrTransparentColor = 0xffffffff;
    local_98.m_bIsDIBSection = false;
    local_98.m_bHasAlphaChannel = false;
    DeleteObject(ho);
  }
  pCVar5 = ATL::CImage::GetInitGDIPlusInstance();
  EnterCriticalSection((LPCRITICAL_SECTION)&pCVar5->m_sect);
  plVar1 = &pCVar5->m_nCImageObjects;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&pCVar5->m_sect);
    if (pCVar5->m_dwToken != 0) {
      GdiplusShutdown();
    }
    pCVar5->m_dwToken = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&pCVar5->m_sect);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&pCVar5->m_sect);
  __security_check_cookie(local_30 ^ (ulonglong)auStackY_e8);
  return;
}



/* 140006870 OnBnClickedBtnSheardspi */

void __thiscall CDSPIDlg::OnBnClickedBtnSheardspi(CDSPIDlg *this)

{
  long *plVar1;
  HBITMAP__ *ho;
  CWnd *pCVar2;
  HDC pHVar3;
  CDC *pCVar4;
  CInitGDIPlus *pCVar5;
  HDC__ *pHVar6;
  int in_R9D;
  undefined1 auStackY_e8 [32];
  int in_stack_ffffffffffffff48;
  int in_stack_ffffffffffffff50;
  CImage local_98;
  undefined8 local_48;
  tagRECT local_40;
  ulonglong local_30;
  
  local_48 = 0xfffffffffffffffe;
  local_30 = __security_cookie ^ (ulonglong)auStackY_e8;
  pCVar2 = CWnd::GetDlgItem((CWnd *)this,0x3fe);
  pHVar3 = GetDC((HWND)pCVar2->m_hWnd);
  pCVar4 = CDC::FromHandle(pHVar3);
  pHVar6 = (HDC__ *)0x0;
  if (pCVar4 != (CDC *)0x0) {
    pHVar6 = pCVar4->m_hDC;
  }
  local_40.left = 0;
  local_40.top = 0;
  local_40.right = 0;
  local_40.bottom = 0;
  GetClientRect((HWND)pCVar2->m_hWnd,&local_40);
  local_98._padding_ = (longlong)ATL::CImage::vftable;
  local_98.m_hBitmap = (HBITMAP__ *)0x0;
  local_98.m_pBits = (void *)0x0;
  local_98.m_nWidth = 0;
  local_98.m_nHeight = 0;
  local_98.m_nPitch = 0;
  local_98.m_nBPP = 0;
  local_98.m_bIsDIBSection = false;
  local_98.m_bHasAlphaChannel = false;
  local_98.m_iTransparentColor = -1;
  local_98.m_clrTransparentColor = 0xffffffff;
  local_98.m_hDC = (HDC__ *)0x0;
  local_98.m_nDCRefCount = 0;
  local_98.m_hOldBitmap = (HBITMAP__ *)0x0;
  pCVar5 = ATL::CImage::GetInitGDIPlusInstance();
  EnterCriticalSection((LPCRITICAL_SECTION)&pCVar5->m_sect);
  pCVar5->m_nCImageObjects = pCVar5->m_nCImageObjects + 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)&pCVar5->m_sect);
  ATL::CImage::Load(&local_98,"res\\Shearography.png");
  ATL::CImage::Draw(&local_98,pHVar6,local_40.bottom - local_40.top,in_R9D,
                    local_40.right - local_40.left,local_40.bottom - local_40.top,
                    in_stack_ffffffffffffff48,in_stack_ffffffffffffff50,local_98.m_nWidth,
                    local_98.m_nHeight);
  CWnd::SetWindowTextA((CWnd *)&(this->m_StaticDescription).field_0x8,(char *)desripShearo);
  ho = local_98.m_hBitmap;
  local_98._padding_ = (longlong)ATL::CImage::vftable;
  if (local_98.m_hBitmap != (HBITMAP__ *)0x0) {
    local_98.m_hBitmap = (HBITMAP__ *)0x0;
    local_98.m_pBits = (void *)0x0;
    local_98.m_nWidth = 0;
    local_98.m_nHeight = 0;
    local_98.m_nPitch = 0;
    local_98.m_nBPP = 0;
    local_98.m_iTransparentColor = -1;
    local_98.m_clrTransparentColor = 0xffffffff;
    local_98.m_bIsDIBSection = false;
    local_98.m_bHasAlphaChannel = false;
    DeleteObject(ho);
  }
  pCVar5 = ATL::CImage::GetInitGDIPlusInstance();
  EnterCriticalSection((LPCRITICAL_SECTION)&pCVar5->m_sect);
  plVar1 = &pCVar5->m_nCImageObjects;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&pCVar5->m_sect);
    if (pCVar5->m_dwToken != 0) {
      GdiplusShutdown();
    }
    pCVar5->m_dwToken = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&pCVar5->m_sect);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&pCVar5->m_sect);
  __security_check_cookie(local_30 ^ (ulonglong)auStackY_e8);
  return;
}



/* 140006a40 OnRButtonDown */

void __thiscall CDSPIDlg::OnRButtonDown(CDSPIDlg *this,uint param_1,CPoint param_2)

{
  POINT pt;
  BOOL BVar1;
  CWnd *pCVar2;
  float fVar3;
  undefined1 auStack_48 [32];
  tagRECT local_28;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28.left = 0;
  local_28.top = 0;
  local_28.right = 0;
  local_28.bottom = 0;
  GetCursorPos((LPPOINT)&sel_pos);
  pCVar2 = CWnd::GetDlgItem((CWnd *)this,0x3ec);
  GetWindowRect((HWND)pCVar2->m_hWnd,&local_28);
  pt.y = sel_pos.y;
  pt.x = sel_pos.x;
  BVar1 = PtInRect(&local_28,pt);
  if (BVar1 != 0) {
    ClipCursor(&local_28);
    xscale = (float)this->m_nWidth / (float)(local_28.right - local_28.left);
    fVar3 = (float)this->m_nHeight / (float)(local_28.bottom - local_28.top);
    yscale = fVar3;
    (this->m_startPoint).x = (int)((float)(sel_pos.x - local_28.left) * xscale);
    (this->m_startPoint).y = (int)((float)(sel_pos.y - local_28.top) * fVar3);
  }
  move_flag = true;
  CWnd::Default((CWnd *)this);
  __security_check_cookie(local_18 ^ (ulonglong)auStack_48);
  return;
}



/* 140006b60 OnMouseMove */

void __thiscall CDSPIDlg::OnMouseMove(CDSPIDlg *this,uint param_1,CPoint param_2)

{
  POINT pt;
  BOOL BVar1;
  CWnd *pCVar2;
  undefined1 auStack_48 [32];
  tagRECT local_28;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28.left = 0;
  local_28.top = 0;
  local_28.right = 0;
  local_28.bottom = 0;
  if (move_flag) {
    GetCursorPos((LPPOINT)&sel_pos);
    pCVar2 = CWnd::GetDlgItem((CWnd *)this,0x3ec);
    GetWindowRect((HWND)pCVar2->m_hWnd,&local_28);
    pt.y = sel_pos.y;
    pt.x = sel_pos.x;
    BVar1 = PtInRect(&local_28,pt);
    if (BVar1 != 0) {
      (this->m_endPoint).x = (int)((float)(sel_pos.x - local_28.left) * xscale);
      (this->m_endPoint).y = (int)((float)(sel_pos.y - local_28.top) * yscale);
    }
    move_flag = false;
  }
  up_flag = true;
  CWnd::Default((CWnd *)this);
  __security_check_cookie(local_18 ^ (ulonglong)auStack_48);
  return;
}



/* 140006c40 OnRButtonUp */

void __thiscall CDSPIDlg::OnRButtonUp(CDSPIDlg *this,uint param_1,CPoint param_2)

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
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28.left = 0;
  local_28.top = 0;
  local_28.right = 0;
  local_28.bottom = 0;
  if (up_flag) {
    GetCursorPos((LPPOINT)&sel_pos);
    pCVar3 = CWnd::GetDlgItem((CWnd *)this,0x3ec);
    GetWindowRect((HWND)pCVar3->m_hWnd,&local_28);
    pt.y = sel_pos.y;
    pt.x = sel_pos.x;
    BVar1 = PtInRect(&local_28,pt);
    if (BVar1 != 0) {
      ClipCursor((RECT *)0x0);
      (this->m_endPoint).x = (int)((float)(sel_pos.x - local_28.left) * xscale);
      (this->m_endPoint).y = (int)((float)(sel_pos.y - local_28.top) * yscale);
    }
  }
  iVar6 = 0;
  iVar5 = (this->m_startPoint).x;
  iVar2 = (this->m_endPoint).x - iVar5;
  up_flag = false;
  (this->m_endPoint).x = iVar5 + ((int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2) * 4;
  iVar5 = (this->m_startPoint).y;
  iVar2 = (this->m_endPoint).y - iVar5;
  (this->m_endPoint).y = iVar5 + ((int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2) * 4;
  if (0 < this->m_nWidth) {
    do {
      iVar5 = 0;
      if (0 < this->m_nHeight) {
        do {
          iVar2 = (this->m_startPoint).x;
          if ((((iVar6 == iVar2) || (iVar6 == (this->m_endPoint).x)) &&
              ((this->m_startPoint).y <= iVar5)) && (iVar5 <= (this->m_endPoint).y)) {
            this->m_pImageBufferClr[(this->m_nWidth * iVar5 + iVar6) * 3] = '\0';
            this->m_pImageBufferClr[(longlong)((this->m_nWidth * iVar5 + iVar6) * 3) + 1] = '\0';
            this->m_pImageBufferClr[(longlong)((this->m_nWidth * iVar5 + iVar6) * 3) + 2] = 0xff;
            this->m_pImageBufferClr[(longlong)((this->m_nWidth * iVar5 + iVar6) * 3) + -3] = '\0';
            this->m_pImageBufferClr[(longlong)((this->m_nWidth * iVar5 + iVar6) * 3) + -2] = '\0';
            this->m_pImageBufferClr[(longlong)((this->m_nWidth * iVar5 + iVar6) * 3) + -1] = 0xff;
            this->m_pImageBufferClr[(longlong)((this->m_nWidth * iVar5 + iVar6) * 3) + 3] = '\0';
            this->m_pImageBufferClr[(longlong)((this->m_nWidth * iVar5 + iVar6) * 3) + 4] = '\0';
            this->m_pImageBufferClr[(longlong)((this->m_nWidth * iVar5 + iVar6) * 3) + 5] = 0xff;
          }
          else if (((iVar6 < iVar2) || ((this->m_endPoint).x < iVar6)) ||
                  ((iVar5 != (this->m_startPoint).y && (iVar5 != (this->m_endPoint).y)))) {
            iVar2 = this->m_nWidth * iVar5 + iVar6;
            this->m_pImageBufferClr[iVar2 * 3] = this->m_pImageBuffer[iVar2];
            iVar2 = this->m_nWidth * iVar5 + iVar6;
            this->m_pImageBufferClr[(longlong)(iVar2 * 3) + 1] = this->m_pImageBuffer[iVar2];
            iVar2 = this->m_nWidth * iVar5 + iVar6;
            this->m_pImageBufferClr[(longlong)(iVar2 * 3) + 2] = this->m_pImageBuffer[iVar2];
          }
          else {
            iVar2 = iVar5 + 1;
            iVar4 = iVar5 + -1;
            this->m_pImageBufferClr[(this->m_nWidth * iVar5 + iVar6) * 3] = '\0';
            this->m_pImageBufferClr[(longlong)((this->m_nWidth * iVar5 + iVar6) * 3) + 1] = '\0';
            this->m_pImageBufferClr[(longlong)((this->m_nWidth * iVar5 + iVar6) * 3) + 2] = 0xff;
            this->m_pImageBufferClr[(iVar4 * this->m_nWidth + iVar6) * 3] = '\0';
            this->m_pImageBufferClr[(longlong)((iVar4 * this->m_nWidth + iVar6) * 3) + 1] = '\0';
            this->m_pImageBufferClr[(longlong)((iVar4 * this->m_nWidth + iVar6) * 3) + 2] = 0xff;
            this->m_pImageBufferClr[(iVar2 * this->m_nWidth + iVar6) * 3] = '\0';
            this->m_pImageBufferClr[(longlong)((iVar2 * this->m_nWidth + iVar6) * 3) + 1] = '\0';
            this->m_pImageBufferClr[(longlong)((iVar2 * this->m_nWidth + iVar6) * 3) + 2] = 0xff;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < this->m_nHeight);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < this->m_nWidth);
  }
  this->m_bStatus = 6;
  SetTimer((HWND)this->_padding_,1,100,(TIMERPROC)0x0);
  CWnd::Default((CWnd *)this);
  __security_check_cookie(local_18 ^ (ulonglong)auStack_48);
  return;
}



/* 1400070f0 PreTranslateMessage */

int __thiscall CDSPIDlg::PreTranslateMessage(CDSPIDlg *this,tagMSG *param_1)

{
  int iVar1;
  
  if (param_1->message == 0x200) {
    SendMessageA((HWND)(this->m_Mytip)._padding_,0x407,0,(LPARAM)param_1);
  }
                    /* WARNING: Could not recover jumptable at 0x000140007131. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = CDialogEx::PreTranslateMessage((CDialogEx *)this,param_1);
  return iVar1;
}



/* 140007140 sprintf_s<10> */

int __cdecl sprintf_s<10>(char (*param_1) [10],char *param_2)

{
  int iVar1;
  ulong64 *puVar2;
  undefined1 local_res18 [16];
  
  puVar2 = __local_stdio_printf_options();
  iVar1 = __stdio_common_vsprintf_s(*puVar2,param_1,10,param_2,0,local_res18);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  return iVar1;
}



/* 1400071a0 Create */

int __thiscall CDialog::Create(CDialog *this,uint param_1,CWnd *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400071a3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = CDialog::Create(this,(char *)(ulonglong)(ushort)param_1,param_2);
  return iVar1;
}



/* 1400071b0 Draw */

int __thiscall
ATL::CImage::Draw(CImage *this,HDC__ *param_1,int param_2,int param_3,int param_4,int param_5,
                 int param_6,int param_7,int param_8,int param_9)

{
  int *piVar1;
  HDC hdc;
  BOOL BVar2;
  CDCCache *pCVar3;
  HDC__ *hdc_00;
  HBITMAP__ *pHVar4;
  UINT crTransparent;
  int iVar5;
  int iVar6;
  HDC pHVar7;
  RGBQUAD local_res18 [2];
  int local_res20;
  
  if (param_1 == (HDC__ *)0x0) {
    return 0;
  }
  this->m_nDCRefCount = this->m_nDCRefCount + 1;
  iVar5 = 0;
  local_res18[0] = (RGBQUAD)param_2;
  local_res20 = param_3;
  if (this->m_hDC == (HDC__ *)0x0) {
    pCVar3 = GetCDCCacheInstance();
    iVar6 = iVar5;
    do {
      LOCK();
      hdc_00 = pCVar3->m_ahDCs[iVar6];
      pCVar3->m_ahDCs[iVar6] = (HDC__ *)0x0;
      UNLOCK();
      if (hdc_00 != (HDC__ *)0x0) goto LAB_14000721e;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 4);
    hdc_00 = (HDC__ *)CreateCompatibleDC((HDC)0x0);
LAB_14000721e:
    this->m_hDC = hdc_00;
    pHVar4 = (HBITMAP__ *)SelectObject((HDC)hdc_00,this->m_hBitmap);
    this->m_hOldBitmap = pHVar4;
  }
  if (this->m_iTransparentColor == 0xffffffff) {
    crTransparent = this->m_clrTransparentColor;
    if (crTransparent == 0xffffffff) {
      if (this->m_bHasAlphaChannel == false) {
        BVar2 = StretchBlt((HDC)param_1,0,0,param_4,param_5,(HDC)this->m_hDC,0,0,param_8,param_9,
                           0xcc0020);
      }
      else {
        local_res20 = 0x1ff0000;
        BVar2 = AlphaBlend((HDC)param_1,0,0,param_4,param_5,(HDC)this->m_hDC,0,0,param_8,param_9,
                           (BLENDFUNCTION)0x1ff0000);
      }
      goto LAB_14000737e;
    }
  }
  else {
    GetDIBColorTable((HDC)this->m_hDC,this->m_iTransparentColor,1,local_res18);
    crTransparent =
         ((uint)local_res18[0] >> 8 & 0xff) << 8 | ((uint)local_res18[0] & 0xff) << 0x10 |
         (uint)local_res18[0] >> 0x10 & 0xff;
  }
  BVar2 = TransparentBlt((HDC)param_1,0,0,param_4,param_5,(HDC)this->m_hDC,0,0,param_8,param_9,
                         crTransparent);
LAB_14000737e:
  piVar1 = &this->m_nDCRefCount;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    SelectObject((HDC)this->m_hDC,this->m_hOldBitmap);
    pHVar7 = (HDC)this->m_hDC;
    pCVar3 = GetCDCCacheInstance();
    do {
      LOCK();
      hdc = (HDC)pCVar3->m_ahDCs[iVar5];
      pCVar3->m_ahDCs[iVar5] = (HDC__ *)pHVar7;
      UNLOCK();
      if (hdc == (HDC)0x0) goto LAB_1400073bc;
      iVar5 = iVar5 + 1;
      pHVar7 = hdc;
    } while (iVar5 < 4);
    DeleteDC(hdc);
LAB_1400073bc:
    this->m_hDC = (HDC__ *)0x0;
  }
  return BVar2;
}



/* 1400073e0 AtlConvAllocMemory<wchar_t> */

void __cdecl
ATL::AtlConvAllocMemory<wchar_t>(wchar_t **param_1,int param_2,wchar_t *param_3,int param_4)

{
  wchar_t *_Memory;
  
  if (((param_1 == (wchar_t **)0x0) || (param_2 < 0)) || (param_3 == (wchar_t *)0x0)) {
                    /* WARNING: Subroutine does not return */
    AtlThrowImpl(0x80070057);
  }
  _Memory = *param_1;
  if (_Memory == param_3) {
    if (param_2 < 0x81) goto LAB_140007425;
    param_3 = (wchar_t *)calloc((longlong)param_2,2);
    *param_1 = param_3;
  }
  else {
    if (param_2 < 0x81) {
      free(_Memory);
    }
    else {
      param_3 = (wchar_t *)_recalloc(_Memory,(longlong)param_2,2);
      if (param_3 == (wchar_t *)0x0) goto LAB_140007460;
    }
LAB_140007425:
    *param_1 = param_3;
  }
  if (param_3 != (wchar_t *)0x0) {
    return;
  }
LAB_140007460:
                    /* WARNING: Subroutine does not return */
  AtlThrowImpl(0x8007000e);
}



/* 140007480 AtlThrowLastWin32 */

void __cdecl ATL::AtlThrowLastWin32(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
                    /* WARNING: Subroutine does not return */
  AtlThrowImpl(DVar1);
}



/* 1400074a0 Init */

void __thiscall ATL::CA2WEX<128>::Init(CA2WEX<128> *this,char *param_1,uint param_2)

{
  wchar_t *pwVar1;
  wchar_t *_Memory;
  int iVar2;
  DWORD DVar3;
  int iVar4;
  wchar_t *pwVar5;
  int iVar6;
  longlong lVar7;
  char *pcVar8;
  bool bVar9;
  
  if (param_1 == (char *)0x0) {
    this->m_psz = (wchar_t *)0x0;
    return;
  }
  lVar7 = -1;
  do {
    lVar7 = lVar7 + 1;
  } while (param_1[lVar7] != '\0');
  iVar6 = (int)lVar7 + 1;
  pwVar1 = this->m_szBuffer;
  if (((this == (CA2WEX<128> *)0x0) || (iVar6 < 0)) || (pwVar1 == (wchar_t *)0x0)) {
                    /* WARNING: Subroutine does not return */
    AtlThrowImpl(0x80070057);
  }
  _Memory = this->m_psz;
  pwVar5 = pwVar1;
  if (_Memory == pwVar1) {
    if (iVar6 < 0x81) {
      this->m_psz = pwVar1;
    }
    else {
      pwVar5 = (wchar_t *)calloc((longlong)iVar6,2);
      this->m_psz = pwVar5;
    }
  }
  else if (iVar6 < 0x81) {
    free(_Memory);
    this->m_psz = pwVar1;
  }
  else {
    pwVar5 = (wchar_t *)_recalloc(_Memory,(longlong)iVar6,2);
    if (pwVar5 == (wchar_t *)0x0) goto FUN_14000760d;
    this->m_psz = pwVar5;
  }
  if (pwVar5 != (wchar_t *)0x0) {
    pcVar8 = param_1;
    iVar2 = MultiByteToWideChar(param_2,0,param_1,iVar6,pwVar5,iVar6);
    iVar4 = (int)pcVar8;
    bVar9 = iVar2 == 0;
    if (iVar2 == 0) {
      DVar3 = GetLastError();
      if (DVar3 == 0x7a) {
        iVar2 = iVar6;
        iVar4 = MultiByteToWideChar(param_2,0,param_1,iVar6,(LPWSTR)0x0,0);
        AtlConvAllocMemory<wchar_t>(&this->m_psz,iVar4,pwVar1,iVar2);
        iVar6 = MultiByteToWideChar(param_2,0,param_1,iVar6,this->m_psz,iVar4);
        iVar4 = (int)param_1;
        bVar9 = iVar6 == 0;
      }
    }
    if (!bVar9) {
      return;
    }
    AtlConvFreeMemory<wchar_t>(this->m_psz,pwVar1,iVar4);
                    /* WARNING: Subroutine does not return */
    AtlThrowLastWin32();
  }
FUN_14000760d:
                    /* WARNING: Subroutine does not return */
  AtlThrowImpl(0x8007000e);
}



/* 1400074c5 FUN_1400074c5 */

void FUN_1400074c5(undefined8 *param_1,longlong param_2)

{
  wchar_t *pwVar1;
  wchar_t *_Memory;
  int iVar2;
  DWORD DVar3;
  int iVar4;
  LPWSTR pWVar5;
  int iVar6;
  longlong lVar7;
  wchar_t **unaff_RSI;
  LPCSTR pCVar8;
  UINT unaff_R12D;
  LPCSTR unaff_R14;
  bool bVar9;
  
  lVar7 = -1;
  do {
    lVar7 = lVar7 + 1;
  } while (*(char *)(param_2 + lVar7) != '\0');
  iVar6 = (int)lVar7 + 1;
  pwVar1 = (wchar_t *)(param_1 + 1);
  if (((unaff_RSI == (wchar_t **)0x0) || (iVar6 < 0)) || (pwVar1 == (wchar_t *)0x0)) {
                    /* WARNING: Subroutine does not return */
    ATL::AtlThrowImpl(0x80070057);
  }
  _Memory = (wchar_t *)*param_1;
  pWVar5 = pwVar1;
  if (_Memory == pwVar1) {
    if (iVar6 < 0x81) {
      *unaff_RSI = pwVar1;
    }
    else {
      pWVar5 = (LPWSTR)calloc((longlong)iVar6,2);
      *unaff_RSI = pWVar5;
    }
  }
  else if (iVar6 < 0x81) {
    free(_Memory);
    *unaff_RSI = pwVar1;
  }
  else {
    pWVar5 = (LPWSTR)_recalloc(_Memory,(longlong)iVar6,2);
    if (pWVar5 == (LPWSTR)0x0) goto FUN_14000760d;
    *unaff_RSI = pWVar5;
  }
  if (pWVar5 != (LPWSTR)0x0) {
    pCVar8 = unaff_R14;
    iVar2 = MultiByteToWideChar(unaff_R12D,0,unaff_R14,iVar6,pWVar5,iVar6);
    iVar4 = (int)pCVar8;
    bVar9 = iVar2 == 0;
    if (iVar2 == 0) {
      DVar3 = GetLastError();
      if (DVar3 == 0x7a) {
        iVar2 = iVar6;
        iVar4 = MultiByteToWideChar(unaff_R12D,0,unaff_R14,iVar6,(LPWSTR)0x0,0);
        ATL::AtlConvAllocMemory<wchar_t>(unaff_RSI,iVar4,pwVar1,iVar2);
        iVar6 = MultiByteToWideChar(unaff_R12D,0,unaff_R14,iVar6,*unaff_RSI,iVar4);
        iVar4 = (int)unaff_R14;
        bVar9 = iVar6 == 0;
      }
    }
    if (!bVar9) {
      return;
    }
    ATL::AtlConvFreeMemory<wchar_t>(*unaff_RSI,pwVar1,iVar4);
                    /* WARNING: Subroutine does not return */
    ATL::AtlThrowLastWin32();
  }
FUN_14000760d:
                    /* WARNING: Subroutine does not return */
  ATL::AtlThrowImpl(0x8007000e);
}



/* 140007575 FUN_140007575 */

void FUN_140007575(undefined8 param_1,DWORD param_2,LPCSTR param_3,int param_4,int param_5)

{
  int iVar1;
  DWORD DVar2;
  int iVar3;
  int unaff_EBX;
  wchar_t *unaff_RBP;
  wchar_t **unaff_RSI;
  UINT unaff_R12D;
  LPCSTR unaff_R14;
  bool bVar4;
  LPWSTR in_stack_00000020;
  
  iVar1 = MultiByteToWideChar(unaff_R12D,param_2,param_3,param_4,in_stack_00000020,param_5);
  iVar3 = (int)param_3;
  bVar4 = iVar1 == 0;
  if (iVar1 == 0) {
    DVar2 = GetLastError();
    if (DVar2 == 0x7a) {
      iVar1 = unaff_EBX;
      iVar3 = MultiByteToWideChar(unaff_R12D,0,unaff_R14,unaff_EBX,(LPWSTR)0x0,0);
      ATL::AtlConvAllocMemory<wchar_t>(unaff_RSI,iVar3,unaff_RBP,iVar1);
      iVar1 = MultiByteToWideChar(unaff_R12D,0,unaff_R14,unaff_EBX,*unaff_RSI,iVar3);
      iVar3 = (int)unaff_R14;
      bVar4 = iVar1 == 0;
    }
  }
  if (!bVar4) {
    return;
  }
  ATL::AtlConvFreeMemory<wchar_t>(*unaff_RSI,unaff_RBP,iVar3);
                    /* WARNING: Subroutine does not return */
  ATL::AtlThrowLastWin32();
}



/* 1400075f9 FUN_1400075f9 */

void FUN_1400075f9(void)

{
  return;
}



/* 14000760d FUN_14000760d */

void FUN_14000760d(void)

{
                    /* WARNING: Subroutine does not return */
  ATL::AtlThrowImpl(0x8007000e);
}



/* 140007640 AtlConvFreeMemory<wchar_t> */

void __cdecl ATL::AtlConvFreeMemory<wchar_t>(wchar_t *param_1,wchar_t *param_2,int param_3)

{
  if (param_1 != param_2) {
                    /* WARNING: Could not recover jumptable at 0x000140007645. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    free(param_1);
    return;
  }
  return;
}



/* 140007650 CreateEx */

int __thiscall
ATL::CImage::CreateEx
          (CImage *this,int param_1,int param_2,int param_3,ulong param_4,ulong *param_5,
          ulong param_6)

{
  int iVar1;
  int extraout_EAX;
  undefined8 *_Memory;
  HBITMAP h;
  undefined8 *_Dst;
  int iVar2;
  undefined8 *puVar3;
  int iVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined4 *puVar7;
  int *piVar8;
  int *piVar9;
  undefined2 *puVar10;
  undefined8 *puVar11;
  undefined2 *puVar12;
  BITMAPINFO *lpbmi;
  undefined1 auStackY_e8 [32];
  undefined1 auStack_a8 [4];
  int iStack_a4;
  int iStack_a0;
  ushort uStack_96;
  void *pvStack_90;
  int iStack_84;
  uint uStack_80;
  ushort uStack_7a;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_e8;
  _Memory = (undefined8 *)malloc(0x438);
  if (_Memory == (undefined8 *)0x0) {
    lpbmi = (BITMAPINFO *)0x0;
    puVar3 = (undefined8 *)&DAT_00000014;
    _Dst = (undefined8 *)0x28;
    puVar6 = (undefined8 *)&DAT_0000001c;
    puVar7 = (undefined4 *)&DAT_00000024;
    piVar8 = (int *)&DAT_00000004;
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
    piVar8 = (int *)((longlong)_Memory + 0x14);
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
    *puVar10 = (short)param_3;
    *piVar8 = param_1;
    (lpbmi->bmiHeader).biSize = 0x28;
    *piVar9 = param_2;
    *puVar12 = 1;
    *(undefined4 *)puVar11 = 0;
    if (param_3 < 9) {
      memset(_Dst,0,0x400);
    }
    h = CreateDIBSection((HDC)0x0,lpbmi,0,&this->m_pBits,(HANDLE)0x0,0);
    if (h != (HBITMAP)0x0) {
      this->m_hBitmap = (HBITMAP__ *)h;
      iVar4 = (param_2 >> 0x1f) + 2;
      iVar1 = GetObjectA(h,0x68,auStack_a8);
      if (iVar1 == 0x68) {
        this->m_nWidth = iStack_84;
        this->m_nBPP = (uint)uStack_7a;
        this->m_bIsDIBSection = true;
        iVar5 = (uStack_80 ^ (int)uStack_80 >> 0x1f) - ((int)uStack_80 >> 0x1f);
        this->m_nHeight = iVar5;
        this->m_pBits = pvStack_90;
        iVar1 = this->m_nWidth * (uint)uStack_7a + 0x1f;
        iVar1 = (int)((iVar1 >> 0x1f & 0x1fU) + iVar1) >> 5;
        iVar2 = iVar1 * 4;
        this->m_nPitch = iVar2;
        if (iVar4 == 0) {
          iVar4 = (0 < (int)uStack_80) + 1;
        }
        if (iVar4 == 2) {
          this->m_pBits = (void *)((longlong)this->m_pBits + (longlong)((iVar5 + -1) * iVar2));
          this->m_nPitch = iVar1 * -4;
        }
      }
      else {
        this->m_nWidth = iStack_a4;
        this->m_nHeight = iStack_a0;
        this->m_nBPP = (uint)uStack_96;
        this->m_bIsDIBSection = false;
        this->m_nPitch = 0;
        this->m_pBits = (void *)0x0;
      }
      this->m_bHasAlphaChannel = false;
      this->m_bHasAlphaChannel = (param_6 & 1) != 0;
      this->m_iTransparentColor = -1;
    }
  }
  while (_Memory != (undefined8 *)0x0) {
    puVar3 = (undefined8 *)*_Memory;
    free(_Memory);
    _Memory = puVar3;
  }
  __security_check_cookie(local_38 ^ (ulonglong)auStackY_e8);
  return extraout_EAX;
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



/* 1400078b0 _AtlVerifyStackAvailable */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

bool __cdecl ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(ulong64 param_1)

{
  undefined1 extraout_AL;
  ulonglong uVar1;
  undefined1 *puVar2;
  undefined1 auStack_38 [32];
  undefined1 local_18 [8];
  ulonglong local_10;
  
  puVar2 = auStack_38;
  local_10 = __security_cookie ^ (ulonglong)local_18;
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
  __security_check_cookie(__security_cookie);
  return (bool)extraout_AL;
}



/* 140007940 GetCDCCacheInstance */

CDCCache * __cdecl ATL::CImage::GetCDCCacheInstance(void)

{
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) <
      `private:_static_class_ATL::CImage::CDCCache*___ptr64___cdecl_ATL::CImage::GetCDCCacheInstance(void)'
      ::__l2::_thread_safe_static_guard_0__) {
    _Init_thread_header(&`private:_static_class_ATL::CImage::CDCCache*___ptr64___cdecl_ATL::CImage::GetCDCCacheInstance(void)'
                         ::__l2::_thread_safe_static_guard_0__);
    if (`private:_static_class_ATL::CImage::CDCCache*___ptr64___cdecl_ATL::CImage::GetCDCCacheInstance(void)'
        ::__l2::_thread_safe_static_guard_0__ == -1) {
      `private:_static_class_ATL::CImage::CDCCache*___ptr64___cdecl_ATL::CImage::GetCDCCacheInstance(void)'
      ::__l2::cache.m_ahDCs[0] = (HDC__ *)0x0;
      `private:_static_class_ATL::CImage::CDCCache*___ptr64___cdecl_ATL::CImage::GetCDCCacheInstance(void)'
      ::__l2::cache.m_ahDCs[1] = (HDC__ *)0x0;
      `private:_static_class_ATL::CImage::CDCCache*___ptr64___cdecl_ATL::CImage::GetCDCCacheInstance(void)'
      ::__l2::cache.m_ahDCs[2] = (HDC__ *)0x0;
      `private:_static_class_ATL::CImage::CDCCache*___ptr64___cdecl_ATL::CImage::GetCDCCacheInstance(void)'
      ::__l2::cache.m_ahDCs[3] = (HDC__ *)0x0;
      atexit(`ATL::CImage::GetCDCCacheInstance'::__l2::_dynamic_atexit_destructor_for__cache__);
      _Init_thread_footer(&`private:_static_class_ATL::CImage::CDCCache*___ptr64___cdecl_ATL::CImage::GetCDCCacheInstance(void)'
                           ::__l2::_thread_safe_static_guard_0__);
    }
  }
  return &`private:_static_class_ATL::CImage::CDCCache*___ptr64___cdecl_ATL::CImage::GetCDCCacheInstance(void)'
          ::__l2::cache;
}



/* 1400079b0 memcpy_s */

errno_t __cdecl ATL::Checked::memcpy_s(void *_Dst,rsize_t _DstSize,void *_Src,rsize_t _MaxCount)

{
  code *pcVar1;
  errno_t in_EAX;
  errno_t eVar2;
  int *piVar3;
  void *pvVar4;
  
  if (_MaxCount == 0) {
    return in_EAX;
  }
  if (_Dst == (void *)0x0) {
    piVar3 = _errno();
    *piVar3 = 0x16;
  }
  else {
    if ((_Src != (void *)0x0) && (_MaxCount <= _DstSize)) {
      pvVar4 = memcpy(_Dst,_Src,_MaxCount);
      return (errno_t)pvVar4;
    }
    memset(_Dst,0,_DstSize);
    if (_Src == (void *)0x0) {
      piVar3 = _errno();
      *piVar3 = 0x16;
    }
    else {
      if (_MaxCount <= _DstSize) goto LAB_140007a39;
      piVar3 = _errno();
      *piVar3 = 0x22;
    }
  }
  _invalid_parameter_noinfo();
LAB_140007a39:
  AfxThrowInvalidArgException();
  pcVar1 = (code *)swi(3);
  eVar2 = (*pcVar1)();
  return eVar2;
}



/* 140007a40 `scalar_deleting_destructor' */

void * __thiscall Gdiplus::Bitmap::_scalar_deleting_destructor_(Bitmap *this,uint param_1)

{
  *(undefined ***)this = Image::vftable;
  GdipDisposeImage(*(undefined8 *)&this->field_0x8);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      GdipFree();
      return this;
    }
    __empty_global_delete(this,0x18);
  }
  return this;
}



/* 140007aa0 Clone */

Image * __thiscall Gdiplus::Image::Clone(Image *this)

{
  Status SVar1;
  Image *pIVar2;
  GpImage *local_res8 [4];
  
  local_res8[0] = (GpImage *)0x0;
  SVar1 = GdipCloneImage(this->nativeImage,local_res8);
  if (SVar1 != Ok) {
    this->lastResult = SVar1;
  }
  pIVar2 = (Image *)GdipAlloc(0x18);
  if (pIVar2 != (Image *)0x0) {
    SVar1 = this->lastResult;
    pIVar2->_padding_ = (longlong)vftable;
    pIVar2->nativeImage = local_res8[0];
    pIVar2->lastResult = SVar1;
    return pIVar2;
  }
  return (Image *)0x0;
}



/* 140007b00 CreateFromGdiplusBitmap */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined4 __thiscall ATL::CImage::CreateFromGdiplusBitmap(CImage *this,Bitmap *param_1)

{
  int *piVar1;
  HDC hdc;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  bool bVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined4 extraout_EAX;
  ulonglong uVar10;
  undefined8 *puVar11;
  CDCCache *pCVar12;
  HDC__ *pHVar13;
  HBITMAP__ *pHVar14;
  undefined8 *puVar15;
  ulonglong uVar16;
  uint uVar17;
  undefined8 *_Memory;
  undefined1 *puVar18;
  undefined1 *puVar19;
  HDC pHVar20;
  void *_Dst;
  UINT cEntries;
  uint uVar21;
  undefined8 *puVar22;
  void *_Src;
  undefined1 auStackY_4e8 [32];
  ulong in_stack_fffffffffffffb38;
  ulong *in_stack_fffffffffffffb40;
  uint local_4a8;
  uint local_4a4;
  uint local_4a0;
  int local_49c;
  int local_498;
  uint local_494;
  undefined8 local_490;
  undefined8 local_488;
  undefined8 local_480;
  int local_478;
  int local_474;
  Bitmap *local_470;
  undefined1 local_468 [8];
  int local_460;
  void *local_458;
  RGBQUAD local_448 [256];
  ulonglong local_48;
  
  puVar18 = auStackY_4e8;
  puVar19 = auStackY_4e8;
  local_48 = __security_cookie ^ (ulonglong)&local_4a8;
  local_470 = param_1;
  iVar7 = GdipGetImagePixelFormat(*(undefined8 *)&param_1->field_0x8,&local_4a4);
  uVar17 = local_4a4;
  if (iVar7 != 0) {
    *(int *)&param_1->field_0x10 = iVar7;
  }
  local_4a8 = 0x20;
  local_4a0 = 0x22009;
  if ((local_4a4 >> 0x11 & 1) != 0) {
    local_4a0 = local_4a4;
    local_4a8 = (int)local_4a4 >> 8 & 0xff;
  }
  uVar8 = local_4a4 & 0x40000;
  if (uVar8 != 0) {
    local_4a0 = 0x26200a;
    local_4a8 = 0x20;
  }
  uVar21 = local_4a8;
  puVar22 = (undefined8 *)0x0;
  local_49c = 0;
  iVar9 = GdipGetImageHeight(*(undefined8 *)&param_1->field_0x8,&local_49c);
  iVar7 = local_49c;
  if (iVar9 != 0) {
    *(int *)&param_1->field_0x10 = iVar9;
  }
  local_498 = 0;
  iVar9 = GdipGetImageWidth(*(undefined8 *)&param_1->field_0x8,&local_498);
  if (iVar9 != 0) {
    *(int *)&param_1->field_0x10 = iVar9;
  }
  iVar7 = CreateEx(this,local_498,iVar7,uVar21,in_stack_fffffffffffffb38,in_stack_fffffffffffffb40,
                   (uint)(uVar8 != 0));
  if (iVar7 == 0) goto LAB_140007ef4;
  _Memory = puVar22;
  if ((uVar17 >> 0x10 & 1) == 0) {
LAB_140007db8:
    iVar7 = this->m_nHeight;
    iVar9 = this->m_nWidth;
    puVar19 = puVar18;
    if (local_4a0 == uVar17) {
      uVar4 = *(undefined8 *)&param_1->field_0x8;
      local_478 = iVar9;
      local_474 = iVar7;
      *(undefined1 **)(puVar18 + 0x20) = local_468;
      local_480 = 0;
      *(undefined8 *)(puVar18 + -8) = 0x140007df5;
      iVar7 = GdipBitmapLockBits(uVar4,&local_480,1,uVar17);
      if (iVar7 == 0) {
        _Dst = this->m_pBits;
        uVar16 = (ulonglong)(this->m_nWidth * uVar21 + 7 >> 3);
        _Src = local_458;
        if (0 < this->m_nHeight) {
          do {
            *(undefined8 *)(puVar18 + -8) = 0x140007e41;
            Checked::memcpy_s(_Dst,uVar16,_Src,uVar16);
            uVar17 = (int)puVar22 + 1;
            puVar22 = (undefined8 *)(ulonglong)uVar17;
            _Dst = (void *)((longlong)_Dst + (longlong)this->m_nPitch);
            param_1 = local_470;
            _Src = (void *)((longlong)_Src + (longlong)local_460);
          } while ((int)uVar17 < this->m_nHeight);
        }
        uVar4 = *(undefined8 *)&param_1->field_0x8;
        *(undefined8 *)(puVar18 + -8) = 0x140007e6a;
        iVar7 = GdipBitmapUnlockBits(uVar4,local_468);
        if (iVar7 != 0) {
          *(int *)&param_1->field_0x10 = iVar7;
        }
      }
      else {
        *(int *)&param_1->field_0x10 = iVar7;
      }
    }
    else {
      iVar3 = this->m_nPitch;
      *(undefined8 **)(puVar18 + 0x28) = &local_488;
      *(void **)(puVar18 + 0x20) = this->m_pBits;
      local_488 = 0;
      *(undefined8 *)(puVar18 + -8) = 0x140007e94;
      GdipCreateBitmapFromScan0(iVar9,iVar7,iVar3);
      uVar4 = local_488;
      local_490 = 0;
      *(undefined8 *)(puVar18 + -8) = 0x140007ea6;
      GdipGetImageGraphicsContext(uVar4,&local_490);
      uVar5 = local_490;
      uVar4 = *(undefined8 *)&param_1->field_0x8;
      *(undefined8 *)(puVar18 + -8) = 0x140007ebd;
      GdipDrawImageI(uVar5,uVar4,0,0);
      *(undefined8 *)(puVar18 + -8) = 0x140007ec6;
      GdipDeleteGraphics(uVar5);
      uVar4 = local_488;
      *(undefined8 *)(puVar18 + -8) = 0x140007ed0;
      GdipDisposeImage(uVar4);
    }
  }
  else {
    local_494 = 0;
    iVar7 = GdipGetImagePaletteSize(*(undefined8 *)&param_1->field_0x8,&local_494);
    uVar8 = local_494;
    if (iVar7 != 0) {
      *(int *)&param_1->field_0x10 = iVar7;
    }
    uVar16 = (ulonglong)local_494;
    if ((local_494 < 0x401) &&
       (bVar6 = _ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable((ulonglong)local_494), bVar6)) {
      uVar10 = uVar16 + 0xf;
      if (uVar10 <= uVar16) {
        uVar10 = 0xffffffffffffff0;
      }
      puVar18 = auStackY_4e8 + -(uVar10 & 0xfffffffffffffff0);
      puVar15 = (undefined8 *)((longlong)&local_4a8 + -(uVar10 & 0xfffffffffffffff0));
    }
    else {
      puVar11 = (undefined8 *)malloc(uVar16 + 0x10);
      puVar18 = auStackY_4e8;
      puVar15 = puVar22;
      if (puVar11 != (undefined8 *)0x0) {
        *puVar11 = 0;
        _Memory = puVar11;
        puVar18 = auStackY_4e8;
        puVar15 = puVar11 + 2;
      }
    }
    puVar19 = puVar18;
    if (puVar15 != (undefined8 *)0x0) {
      uVar4 = *(undefined8 *)&param_1->field_0x8;
      *(undefined8 *)(puVar18 + -8) = 0x140007ca7;
      iVar7 = GdipGetImagePalette(uVar4,puVar15,uVar8);
      if (iVar7 != 0) {
        *(int *)&param_1->field_0x10 = iVar7;
      }
      cEntries = *(UINT *)((longlong)puVar15 + 4);
      if (cEntries - 1 < 0x100) {
        puVar11 = puVar22;
        if (cEntries != 0) {
          do {
            uVar8 = (int)puVar11 + 1;
            uVar2 = *(undefined4 *)((longlong)puVar15 + (longlong)puVar11 * 4 + 8);
            local_448[(longlong)puVar11].rgbBlue = (BYTE)uVar2;
            local_448[(longlong)puVar11].rgbRed = (BYTE)((uint)uVar2 >> 0x10);
            local_448[(longlong)puVar11].rgbGreen = (BYTE)((uint)uVar2 >> 8);
            local_448[(longlong)puVar11].rgbReserved = '\0';
            cEntries = *(uint *)((longlong)puVar15 + 4);
            puVar11 = (undefined8 *)(ulonglong)uVar8;
          } while (uVar8 < cEntries);
        }
        this->m_nDCRefCount = this->m_nDCRefCount + 1;
        pHVar13 = this->m_hDC;
        if (pHVar13 == (HDC__ *)0x0) {
          *(undefined8 *)(puVar18 + -8) = 0x140007d19;
          pCVar12 = GetCDCCacheInstance();
          puVar15 = puVar22;
          do {
            LOCK();
            pHVar13 = pCVar12->m_ahDCs[(int)puVar15];
            pCVar12->m_ahDCs[(int)puVar15] = (HDC__ *)0x0;
            UNLOCK();
            if (pHVar13 != (HDC__ *)0x0) goto LAB_140007d3e;
            uVar17 = (int)puVar15 + 1;
            puVar15 = (undefined8 *)(ulonglong)uVar17;
          } while ((int)uVar17 < 4);
          *(undefined8 *)(puVar18 + -8) = 0x140007d3e;
          pHVar13 = (HDC__ *)CreateCompatibleDC((HDC)0x0);
LAB_140007d3e:
          pHVar14 = this->m_hBitmap;
          this->m_hDC = pHVar13;
          *(undefined8 *)(puVar18 + -8) = 0x140007d4f;
          pHVar14 = (HBITMAP__ *)SelectObject((HDC)pHVar13,pHVar14);
          pHVar13 = this->m_hDC;
          this->m_hOldBitmap = pHVar14;
          uVar17 = local_4a4;
        }
        *(undefined8 *)(puVar18 + -8) = 0x140007d6a;
        SetDIBColorTable((HDC)pHVar13,0,cEntries,local_448);
        piVar1 = &this->m_nDCRefCount;
        *piVar1 = *piVar1 + -1;
        uVar21 = local_4a8;
        if (*piVar1 == 0) {
          pHVar14 = this->m_hOldBitmap;
          pHVar20 = (HDC)this->m_hDC;
          *(undefined8 *)(puVar18 + -8) = 0x140007d7e;
          SelectObject(pHVar20,pHVar14);
          pHVar20 = (HDC)this->m_hDC;
          *(undefined8 *)(puVar18 + -8) = 0x140007d87;
          pCVar12 = GetCDCCacheInstance();
          puVar15 = puVar22;
          do {
            LOCK();
            hdc = (HDC)pCVar12->m_ahDCs[(int)puVar15];
            pCVar12->m_ahDCs[(int)puVar15] = (HDC__ *)pHVar20;
            UNLOCK();
            if (hdc == (HDC)0x0) goto LAB_140007dac;
            uVar17 = (int)puVar15 + 1;
            puVar15 = (undefined8 *)(ulonglong)uVar17;
            pHVar20 = hdc;
          } while ((int)uVar17 < 4);
          *(undefined8 *)(puVar18 + -8) = 0x140007dac;
          DeleteDC(hdc);
LAB_140007dac:
          this->m_hDC = (HDC__ *)0x0;
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
  return extraout_EAX;
}



/* 140007f20 Load */

undefined4 __thiscall ATL::CImage::Load(CImage *this,char *param_1)

{
  bool bVar1;
  undefined8 uVar2;
  int iVar3;
  undefined4 extraout_EAX;
  CInitGDIPlus *pCVar4;
  undefined1 auStack_198 [32];
  undefined **ppuStack_178;
  undefined8 uStack_170;
  ulonglong uStack_168;
  undefined8 auStack_160 [3];
  CA2WEX<128> CStack_148;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_198;
  pCVar4 = GetInitGDIPlusInstance();
  if (pCVar4->m_dwLastError == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&pCVar4->m_sect);
    bVar1 = true;
    if (pCVar4->m_dwToken == 0) {
      ppuStack_178 = (undefined **)CONCAT44(ppuStack_178._4_4_,1);
      uStack_170 = 0;
      uStack_168 = 0;
      iVar3 = GdiplusStartup(pCVar4,&ppuStack_178,auStack_160);
      bVar1 = true;
      if (iVar3 != 0) {
        bVar1 = false;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&pCVar4->m_sect);
    if (bVar1) {
      CStack_148.m_psz = CStack_148.m_szBuffer;
      CA2WEX<128>::Init(&CStack_148,param_1,3);
      ppuStack_178 = Gdiplus::Bitmap::vftable;
      auStack_160[0] = 0;
      iVar3 = GdipCreateBitmapFromFile(CStack_148.m_psz,auStack_160);
      uVar2 = auStack_160[0];
      uStack_170 = auStack_160[0];
      if (CStack_148.m_psz != CStack_148.m_szBuffer) {
        free(CStack_148.m_psz);
      }
      uStack_168 = uStack_168 & 0xffffffff00000000;
      if (iVar3 == 0) {
        CreateFromGdiplusBitmap(this,(Bitmap *)&ppuStack_178);
        GdipDisposeImage(uStack_170);
      }
      else {
        GdipDisposeImage(uVar2);
      }
    }
  }
  __security_check_cookie(local_38 ^ (ulonglong)auStack_198);
  return extraout_EAX;
}



/* 140007f5d FUN_140007f5d */

void FUN_140007f5d(LPCRITICAL_SECTION param_1)

{
  bool bVar1;
  undefined8 uVar2;
  int iVar3;
  longlong *unaff_RBX;
  CImage *unaff_RBP;
  char *unaff_R14;
  undefined **local_res20;
  undefined8 in_stack_00000038;
  wchar_t *in_stack_00000050;
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
    in_stack_00000050 = (wchar_t *)&stack0x00000058;
    ATL::CA2WEX<128>::Init((CA2WEX<128> *)&stack0x00000050,unaff_R14,3);
    local_res20 = Gdiplus::Bitmap::vftable;
    in_stack_00000038 = 0;
    iVar3 = GdipCreateBitmapFromFile(in_stack_00000050,&stack0x00000038);
    uVar2 = in_stack_00000038;
    if (in_stack_00000050 != (wchar_t *)&stack0x00000058) {
      free(in_stack_00000050);
    }
    if (iVar3 == 0) {
      ATL::CImage::CreateFromGdiplusBitmap(unaff_RBP,(Bitmap *)&local_res20);
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
  CImage *unaff_RBP;
  char *unaff_R14;
  undefined8 unaff_R15;
  undefined **local_res20;
  undefined8 uStack0000000000000028;
  undefined4 uStack0000000000000030;
  wchar_t *pwStack0000000000000050;
  ulonglong in_stack_00000160;
  
  pwStack0000000000000050 = (wchar_t *)&stack0x00000058;
  ATL::CA2WEX<128>::Init((CA2WEX<128> *)&stack0x00000050,unaff_R14,3);
  local_res20 = Gdiplus::Bitmap::vftable;
  iVar1 = GdipCreateBitmapFromFile(pwStack0000000000000050,&stack0x00000038);
  uStack0000000000000028 = unaff_R15;
  if (pwStack0000000000000050 != (wchar_t *)&stack0x00000058) {
    free(pwStack0000000000000050);
  }
  uStack0000000000000030 = (undefined4)unaff_R15;
  if (iVar1 == 0) {
    ATL::CImage::CreateFromGdiplusBitmap(unaff_RBP,(Bitmap *)&local_res20);
    GdipDisposeImage(uStack0000000000000028);
  }
  else {
    GdipDisposeImage(unaff_R15);
  }
  __security_check_cookie(in_stack_00000160 ^ (ulonglong)&stack0x00000000);
  return;
}



/* 140008080 ~CImage */

void __thiscall ATL::CImage::~CImage(CImage *this)

{
  long *plVar1;
  HBITMAP__ *ho;
  CInitGDIPlus *pCVar2;
  
  this->_padding_ = (longlong)vftable;
  ho = this->m_hBitmap;
  if (ho != (HBITMAP__ *)0x0) {
    this->m_hBitmap = (HBITMAP__ *)0x0;
    this->m_pBits = (void *)0x0;
    this->m_nWidth = 0;
    this->m_nHeight = 0;
    this->m_nPitch = 0;
    this->m_nBPP = 0;
    this->m_iTransparentColor = -1;
    this->m_clrTransparentColor = 0xffffffff;
    this->m_bIsDIBSection = false;
    this->m_bHasAlphaChannel = false;
    DeleteObject(ho);
  }
  pCVar2 = GetInitGDIPlusInstance();
  EnterCriticalSection((LPCRITICAL_SECTION)&pCVar2->m_sect);
  plVar1 = &pCVar2->m_nCImageObjects;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&pCVar2->m_sect);
    if (pCVar2->m_dwToken != 0) {
      GdiplusShutdown();
    }
    pCVar2->m_dwToken = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&pCVar2->m_sect);
  }
                    /* WARNING: Could not recover jumptable at 0x000140008119. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LeaveCriticalSection((LPCRITICAL_SECTION)&pCVar2->m_sect);
  return;
}



/* 140008120 `scalar_deleting_destructor' */

void * __thiscall ATL::CImage::_scalar_deleting_destructor_(CImage *this,uint param_1)

{
  ~CImage(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this,0x50);
  }
  return this;
}



/* 140008170 GetInitGDIPlusInstance */

CInitGDIPlus * __cdecl ATL::CImage::GetInitGDIPlusInstance(void)

{
  BOOL BVar1;
  ulong uVar2;
  
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) <
      `private:_static_class_ATL::CImage::CInitGDIPlus*___ptr64___cdecl_ATL::CImage::GetInitGDIPlusInstance(void)'
      ::__l2::_thread_safe_static_guard_0__) {
    _Init_thread_header(&`private:_static_class_ATL::CImage::CInitGDIPlus*___ptr64___cdecl_ATL::CImage::GetInitGDIPlusInstance(void)'
                         ::__l2::_thread_safe_static_guard_0__);
    if (`private:_static_class_ATL::CImage::CInitGDIPlus*___ptr64___cdecl_ATL::CImage::GetInitGDIPlusInstance(void)'
        ::__l2::_thread_safe_static_guard_0__ == -1) {
      `private:_static_class_ATL::CImage::CInitGDIPlus*___ptr64___cdecl_ATL::CImage::GetInitGDIPlusInstance(void)'
      ::__l2::gdiPlus.m_dwToken = 0;
      `private:_static_class_ATL::CImage::CInitGDIPlus*___ptr64___cdecl_ATL::CImage::GetInitGDIPlusInstance(void)'
      ::__l2::gdiPlus.m_nCImageObjects = 0;
      `private:_static_class_ATL::CImage::CInitGDIPlus*___ptr64___cdecl_ATL::CImage::GetInitGDIPlusInstance(void)'
      ::__l2::gdiPlus.m_dwLastError = 0;
      BVar1 = InitializeCriticalSectionEx
                        ((LPCRITICAL_SECTION)
                         &`private:_static_class_ATL::CImage::CInitGDIPlus*___ptr64___cdecl_ATL::CImage::GetInitGDIPlusInstance(void)'
                          ::__l2::gdiPlus.m_sect,0,0);
      if (BVar1 == 0) {
        uVar2 = GetLastError();
        if (0 < (int)uVar2) {
          uVar2 = uVar2 & 0xffff | 0x80070000;
        }
        `private:_static_class_ATL::CImage::CInitGDIPlus*___ptr64___cdecl_ATL::CImage::GetInitGDIPlusInstance(void)'
        ::__l2::gdiPlus.m_dwLastError = uVar2;
      }
      atexit(`ATL::CImage::GetInitGDIPlusInstance'::__l2::_dynamic_atexit_destructor_for__gdiPlus__)
      ;
      _Init_thread_footer(&`private:_static_class_ATL::CImage::CInitGDIPlus*___ptr64___cdecl_ATL::CImage::GetInitGDIPlusInstance(void)'
                           ::__l2::_thread_safe_static_guard_0__);
    }
  }
  return &`private:_static_class_ATL::CImage::CInitGDIPlus*___ptr64___cdecl_ATL::CImage::GetInitGDIPlusInstance(void)'
          ::__l2::gdiPlus;
}



/* 140008210 `scalar_deleting_destructor' */

void * __thiscall
CMemoryException::_scalar_deleting_destructor_(CMemoryException *this,uint param_1)

{
  *(undefined ***)this = CSimpleException::vftable;
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      operator_delete(this);
      return this;
    }
    __empty_global_delete(this,0xa0);
  }
  return this;
}



/* 140008250 CMemoryException */

CMemoryException * __thiscall CMemoryException::CMemoryException(CMemoryException *this)

{
  CException::CException((CException *)this);
  *(undefined8 *)&this->field_0x14 = 0;
  *(undefined ***)this = vftable;
  return this;
}



/* 140008280 KillTimer */

BOOL __stdcall CWnd::KillTimer(HWND hWnd,UINT_PTR uIDEvent)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140008289. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = ::KillTimer(*(HWND *)(hWnd + 0x10),1);
  return BVar1;
}



/* 140008290 `scalar_deleting_destructor' */

void * __thiscall CStatic::_scalar_deleting_destructor_(CStatic *this,uint param_1)

{
  CStatic::~CStatic(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      operator_delete(this);
      return this;
    }
    __empty_global_delete(this,0xe8);
  }
  return this;
}



/* 1400082e0 `scalar_deleting_destructor' */

void * __thiscall CSliderCtrl::_scalar_deleting_destructor_(CSliderCtrl *this,uint param_1)

{
  CSliderCtrl::~CSliderCtrl(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      operator_delete(this);
      return this;
    }
    __empty_global_delete(this,0xe8);
  }
  return this;
}



/* 140008330 `scalar_deleting_destructor' */

void * __thiscall CComboBox::_scalar_deleting_destructor_(CComboBox *this,uint param_1)

{
  CComboBox::~CComboBox(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      operator_delete(this);
      return this;
    }
    __empty_global_delete(this,0xe8);
  }
  return this;
}



/* 140008380 BeginModalState */

void __thiscall CWnd::BeginModalState(CWnd *this)

{
                    /* WARNING: Could not recover jumptable at 0x000140008386. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EnableWindow(this->m_hWnd,0);
  return;
}



/* 140008390 EndModalState */

void __thiscall CWnd::EndModalState(CWnd *this)

{
                    /* WARNING: Could not recover jumptable at 0x000140008399. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EnableWindow(this->m_hWnd,1);
  return;
}



/* 1400083a0 AtlThrowImpl */

void __cdecl ATL::AtlThrowImpl(int param_1)

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



/* 1400083c0 __local_stdio_printf_options */

ulong64 * __cdecl __local_stdio_printf_options(void)

{
  return &`__local_stdio_printf_options'::__l2::_OptionsStorage;
}



/* 1400083d0 ~FunDIB */

void __thiscall FunDIB::~FunDIB(FunDIB *this)

{
  if (this->m_pImgDataOut != (uchar *)0x0) {
    operator_delete__(this->m_pImgDataOut);
    this->m_pImgDataOut = (uchar *)0x0;
  }
  if (this->m_pImgMask != (uchar *)0x0) {
    operator_delete__(this->m_pImgMask);
    this->m_pImgMask = (uchar *)0x0;
  }
  if (this->m_pImgDataBuf1 != (uchar *)0x0) {
    operator_delete__(this->m_pImgDataBuf1);
    this->m_pImgDataBuf1 = (uchar *)0x0;
  }
  if (this->m_pImgDataBuf2 != (uchar *)0x0) {
    operator_delete__(this->m_pImgDataBuf2);
    this->m_pImgDataBuf2 = (uchar *)0x0;
  }
  if (this->m_pImgDataBuf3 != (uchar *)0x0) {
    operator_delete__(this->m_pImgDataBuf3);
    this->m_pImgDataBuf3 = (uchar *)0x0;
  }
  if (this->m_pImgBufInput != (double *)0x0) {
    operator_delete__(this->m_pImgBufInput);
    this->m_pImgBufInput = (double *)0x0;
  }
  if (this->m_pImgBufOut1 != (double *)0x0) {
    operator_delete__(this->m_pImgBufOut1);
    this->m_pImgBufOut1 = (double *)0x0;
  }
  if (this->m_pImgBufOut2 != (double *)0x0) {
    operator_delete__(this->m_pImgBufOut2);
    this->m_pImgBufOut2 = (double *)0x0;
  }
  if (this->m_lpColorTableOut != (tagRGBQUAD *)0x0) {
    operator_delete__(this->m_lpColorTableOut);
    this->m_lpColorTableOut = (tagRGBQUAD *)0x0;
  }
  if ((void *)this->_padding_ != (void *)0x0) {
    operator_delete__((void *)this->_padding_);
  }
  if ((HGDIOBJ)this->_padding_ != (HGDIOBJ)0x0) {
    DeleteObject((HGDIOBJ)this->_padding_);
  }
  return;
}



/* 1400084e0 SpecialFilter */

void __thiscall
FunDIB::SpecialFilter(FunDIB *this,int param_1,float *param_2,float param_3,int param_4)

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
  int iVar13;
  __uint64 _Var14;
  double *pdVar15;
  uchar *puVar16;
  void *pvVar17;
  float *pfVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  longlong lVar22;
  int iVar23;
  longlong lVar24;
  double dVar25;
  double dVar26;
  
  if ((int)this->_padding_ != 8) {
                    /* WARNING: Could not recover jumptable at 0x00014000851a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    AfxMessageBox("Only for 8 bits gray image!",0,0);
    return;
  }
  iVar23 = *(int *)((longlong)&this->_padding_ + 4);
  this->m_nBitCountOut = 8;
  iVar20 = (int)this->_padding_;
  iVar13 = (int)(iVar23 + 3 + (iVar23 + 3 >> 0x1f & 3U)) >> 2;
  this->m_imgWidthOut = iVar23;
  this->m_imgHeightOut = iVar20;
  this->m_dPhaseDifOut = (double)this->_padding_;
  iVar5 = iVar13 * 4;
  if (param_4 == 1) {
    if (this->m_pImgBufOut1 != (double *)0x0) {
      operator_delete__(this->m_pImgBufOut1);
      iVar20 = (int)this->_padding_;
      iVar23 = *(int *)((longlong)&this->_padding_ + 4);
      this->m_pImgBufOut1 = (double *)0x0;
    }
    auVar9._8_8_ = 0;
    auVar9._0_8_ = (longlong)(iVar23 * iVar20);
    _Var14 = SUB168(ZEXT816(8) * auVar9,0);
    if (SUB168(ZEXT816(8) * auVar9,8) != 0) {
      _Var14 = 0xffffffffffffffff;
    }
    pdVar15 = (double *)operator_new__(_Var14);
    this->m_pImgBufOut1 = pdVar15;
  }
  else if (param_4 == 2) {
    if (this->m_pImgBufOut2 != (double *)0x0) {
      operator_delete__(this->m_pImgBufOut2);
      iVar20 = (int)this->_padding_;
      iVar23 = *(int *)((longlong)&this->_padding_ + 4);
      this->m_pImgBufOut2 = (double *)0x0;
    }
    auVar10._8_8_ = 0;
    auVar10._0_8_ = (longlong)(iVar23 * iVar20);
    _Var14 = SUB168(ZEXT816(8) * auVar10,0);
    if (SUB168(ZEXT816(8) * auVar10,8) != 0) {
      _Var14 = 0xffffffffffffffff;
    }
    pdVar15 = (double *)operator_new__(_Var14);
    this->m_pImgBufOut2 = pdVar15;
  }
  else {
    if (this->m_pImgBufInput != (double *)0x0) {
      operator_delete__(this->m_pImgBufInput);
      iVar20 = (int)this->_padding_;
      iVar23 = *(int *)((longlong)&this->_padding_ + 4);
      this->m_pImgBufInput = (double *)0x0;
    }
    auVar11._8_8_ = 0;
    auVar11._0_8_ = (longlong)(iVar23 * iVar20);
    _Var14 = SUB168(ZEXT816(8) * auVar11,0);
    if (SUB168(ZEXT816(8) * auVar11,8) != 0) {
      _Var14 = 0xffffffffffffffff;
    }
    pdVar15 = (double *)operator_new__(_Var14);
    this->m_pImgBufInput = pdVar15;
    if (this->m_pImgDataOut != (uchar *)0x0) {
      operator_delete__(this->m_pImgDataOut);
      this->m_pImgDataOut = (uchar *)0x0;
    }
    puVar16 = (uchar *)operator_new__((longlong)((int)this->_padding_ * iVar5));
    iVar23 = 0;
    this->m_pImgDataOut = puVar16;
    if (0 < (int)this->_padding_) {
      do {
        iVar20 = 0;
        if (0 < *(int *)((longlong)&this->_padding_ + 4)) {
          lVar22 = 0;
          do {
            lVar22 = lVar22 + 1;
            iVar19 = iVar23 * *(int *)((longlong)&this->_padding_ + 4) + iVar20;
            iVar20 = iVar20 + 1;
            this->m_pImgBufInput[iVar19] =
                 (double)*(byte *)(this->_padding_ + (longlong)(iVar13 * iVar23 * 4) + -1 + lVar22);
          } while (iVar20 < *(int *)((longlong)&this->_padding_ + 4));
        }
        iVar23 = iVar23 + 1;
      } while (iVar23 < (int)this->_padding_);
    }
  }
  iVar23 = *(int *)((longlong)&this->_padding_ + 4) + 2;
  auVar12._8_8_ = 0;
  auVar12._0_8_ = (longlong)(((int)this->_padding_ + 2) * iVar23);
  _Var14 = SUB168(ZEXT816(8) * auVar12,0);
  if (SUB168(ZEXT816(8) * auVar12,8) != 0) {
    _Var14 = 0xffffffffffffffff;
  }
  pvVar17 = operator_new__(_Var14);
  iVar20 = (int)this->_padding_;
  iVar13 = 0;
  if (0 < iVar20 + 2) {
    iVar19 = 0;
    do {
      iVar20 = *(int *)((longlong)&this->_padding_ + 4);
      iVar21 = 0;
      lVar22 = 0;
      if (0 < iVar20 + 2) {
        lVar24 = -8;
        do {
          pdVar15 = this->m_pImgBufInput;
          if (iVar13 < 1) {
            if (0 < lVar22) {
              if (iVar20 < iVar21) {
                dVar25 = pdVar15[(longlong)iVar20 + -1];
                goto LAB_140008835;
              }
              pdVar15 = (double *)((longlong)pdVar15 + lVar24);
            }
            dVar25 = *pdVar15;
          }
          else {
            iVar8 = (int)this->_padding_;
            if (iVar8 < iVar13) {
              if (lVar22 < 1) {
                dVar25 = pdVar15[(iVar8 + -1) * iVar20];
              }
              else if (iVar20 < iVar21) {
                dVar25 = pdVar15[(longlong)(iVar8 * iVar20) + -1];
              }
              else {
                dVar25 = pdVar15[(longlong)((iVar8 + -1) * iVar20 + iVar21) + -1];
              }
            }
            else if (lVar22 < 1) {
              dVar25 = pdVar15[(iVar13 + -1) * iVar20];
            }
            else {
              if (iVar20 < iVar21) {
                iVar20 = iVar20 * iVar13;
              }
              else {
                iVar20 = (iVar13 + -1) * iVar20 + iVar21;
              }
              dVar25 = pdVar15[(longlong)iVar20 + -1];
            }
          }
LAB_140008835:
          *(double *)((longlong)pvVar17 + (iVar19 + lVar22) * 8) = dVar25;
          iVar21 = iVar21 + 1;
          iVar20 = *(int *)((longlong)&this->_padding_ + 4);
          lVar22 = lVar22 + 1;
          lVar24 = lVar24 + 8;
        } while (iVar21 < iVar20 + 2);
      }
      iVar20 = (int)this->_padding_;
      iVar13 = iVar13 + 1;
      iVar19 = iVar19 + iVar23;
    } while (iVar13 < iVar20 + 2);
  }
  dVar25 = __real_406fe00000000000;
  iVar13 = 0;
  if (0 < iVar20) {
    iVar19 = 0;
    iVar20 = 0;
    do {
      iVar21 = 0;
      if (0 < *(int *)((longlong)&this->_padding_ + 4)) {
        do {
          dVar26 = 0.0;
          pfVar18 = param_2 + 2;
          pdVar15 = (double *)((longlong)pvVar17 + ((longlong)(iVar20 + iVar21) + 2) * 8);
          lVar22 = 3;
          do {
            pfVar1 = pfVar18 + -2;
            pfVar2 = pfVar18 + -1;
            pdVar3 = pdVar15 + -2;
            pdVar4 = pdVar15 + -1;
            fVar6 = *pfVar18;
            pfVar18 = pfVar18 + 3;
            dVar7 = *pdVar15;
            pdVar15 = pdVar15 + iVar23;
            dVar26 = (double)*pfVar1 * *pdVar3 + dVar26 + (double)*pfVar2 * *pdVar4 +
                     (double)fVar6 * dVar7;
            lVar22 = lVar22 + -1;
          } while (lVar22 != 0);
          iVar8 = *(int *)((longlong)&this->_padding_ + 4);
          dVar26 = dVar26 / (double)param_3;
          if (param_4 == 1) {
            this->m_pImgBufOut1[iVar8 * iVar13 + iVar21] = dVar26;
          }
          else if (param_4 == 2) {
            this->m_pImgBufOut2[iVar8 * iVar13 + iVar21] = dVar26;
          }
          else {
            puVar16 = this->m_pImgDataOut;
            iVar8 = iVar21 + iVar19;
            if (dVar26 <= dVar25) {
              if (0.0 <= dVar26) {
                puVar16[iVar8] = (uchar)(int)dVar26;
              }
              else {
                puVar16[iVar8] = '\0';
              }
            }
            else {
              puVar16[iVar8] = 0xff;
            }
          }
          iVar21 = iVar21 + 1;
        } while (iVar21 < *(int *)((longlong)&this->_padding_ + 4));
      }
      iVar13 = iVar13 + 1;
      iVar20 = iVar20 + iVar23;
      iVar19 = iVar19 + iVar5;
    } while (iVar13 < (int)this->_padding_);
  }
  if (pvVar17 != (void *)0x0) {
    operator_delete__(pvVar17);
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
  dVar11 = __real_406fe00000000000;
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



/* 1400089f0 SpecialFilterEx */

void __thiscall FunDIB::SpecialFilterEx(FunDIB *this,int param_1,float *param_2,float param_3)

{
  double dVar1;
  undefined1 auVar2 [16];
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  int iVar8;
  uchar *puVar9;
  __uint64 _Var10;
  double *pdVar11;
  longlong lVar12;
  int iVar13;
  longlong lVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  double dVar18;
  double dVar19;
  
  if ((int)this->_padding_ != 8) {
                    /* WARNING: Could not recover jumptable at 0x000140008a30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    AfxMessageBox("Only for 8 bits gray image!",0,0);
    return;
  }
  iVar13 = *(int *)((longlong)&this->_padding_ + 4);
  this->m_imgWidthOut = iVar13;
  iVar13 = iVar13 + 3;
  this->m_nBitCountOut = 8;
  iVar17 = (int)this->_padding_;
  uVar16 = (iVar13 >> 0x1f & 3U) + iVar13 & 0xfffffffc;
  this->m_imgHeightOut = iVar17;
  this->m_dPhaseDifOut = (double)this->_padding_;
  if (this->m_pImgDataOut != (uchar *)0x0) {
    operator_delete__(this->m_pImgDataOut);
    iVar17 = (int)this->_padding_;
    this->m_pImgDataOut = (uchar *)0x0;
  }
  puVar9 = (uchar *)operator_new__((longlong)(int)(iVar17 * uVar16));
  this->m_pImgDataOut = puVar9;
  if (this->m_pImgBufInput != (double *)0x0) {
    operator_delete__(this->m_pImgBufInput);
    this->m_pImgBufInput = (double *)0x0;
  }
  auVar2._8_8_ = 0;
  auVar2._0_8_ = (longlong)((int)this->_padding_ * *(int *)((longlong)&this->_padding_ + 4));
  lVar12 = SUB168(ZEXT816(8) * auVar2,8);
  _Var10 = SUB168(ZEXT816(8) * auVar2,0);
  if (lVar12 != 0) {
    _Var10 = 0xffffffffffffffff;
  }
  pdVar11 = (double *)operator_new__(_Var10);
  dVar7 = __real_406fe00000000000;
  dVar4 = __real_400921fb4d12d84a;
  iVar13 = 0;
  this->m_pImgBufInput = pdVar11;
  if (0 < (int)this->_padding_) {
    iVar17 = 0;
    do {
      iVar15 = 0;
      if (0 < *(int *)((longlong)&this->_padding_ + 4)) {
        lVar14 = (longlong)iVar17;
        do {
          dVar18 = sin(((double)((uint)*(byte *)(this->_padding_ + lVar14) * 2) * dVar4) / dVar7);
          lVar14 = lVar14 + 1;
          iVar8 = iVar13 * *(int *)((longlong)&this->_padding_ + 4) + iVar15;
          iVar15 = iVar15 + 1;
          this->m_pImgBufInput[iVar8] = dVar18;
        } while (iVar15 < *(int *)((longlong)&this->_padding_ + 4));
      }
      iVar13 = iVar13 + 1;
      iVar17 = iVar17 + uVar16;
    } while (iVar13 < (int)this->_padding_);
  }
  SpecialFilter(this,(int)lVar12,param_2,param_3,1);
  iVar13 = (int)lVar12;
  iVar17 = 0;
  if (0 < (int)this->_padding_) {
    iVar15 = 0;
    do {
      iVar13 = 0;
      if (0 < *(int *)((longlong)&this->_padding_ + 4)) {
        lVar14 = (longlong)iVar15;
        do {
          dVar18 = cos(((double)((uint)*(byte *)(this->_padding_ + lVar14) * 2) * dVar4) / dVar7);
          lVar14 = lVar14 + 1;
          iVar8 = iVar17 * *(int *)((longlong)&this->_padding_ + 4) + iVar13;
          iVar13 = iVar13 + 1;
          this->m_pImgBufInput[iVar8] = dVar18;
        } while (iVar13 < *(int *)((longlong)&this->_padding_ + 4));
      }
      iVar13 = (int)lVar12;
      iVar17 = iVar17 + 1;
      iVar15 = iVar15 + uVar16;
    } while (iVar17 < (int)this->_padding_);
  }
  SpecialFilter(this,iVar13,param_2,param_3,2);
  dVar6 = __real_401921fb4d12d84a;
  dVar5 = __real_4012d97c79ce2238;
  dVar3 = __real_3ff921fb4d12d84a;
  dVar18 = __real_3fe0000000000000;
  iVar13 = 0;
  if (0 < (int)this->_padding_) {
    iVar17 = 0;
    do {
      iVar15 = *(int *)((longlong)&this->_padding_ + 4);
      iVar8 = 0;
      if (0 < iVar15) {
        lVar12 = (longlong)iVar17;
        do {
          iVar15 = iVar15 * iVar13 + iVar8;
          dVar19 = this->m_pImgBufOut2[iVar15];
          if (0.0 <= dVar19) {
            dVar1 = this->m_pImgBufOut1[iVar15];
            if (dVar19 != 0.0) {
              dVar19 = atan(dVar1 / dVar19);
              goto LAB_140008cfe;
            }
            dVar19 = dVar5;
            if (0.0 < dVar1) {
              dVar19 = dVar3;
            }
          }
          else {
            dVar1 = this->m_pImgBufOut1[iVar15];
            dVar19 = atan(dVar1 / dVar19);
            if (dVar1 <= 0.0) {
              dVar19 = dVar19 - dVar4;
            }
            else {
              dVar19 = dVar19 + dVar4;
            }
LAB_140008cfe:
            if (dVar19 < 0.0) {
              dVar19 = dVar19 + dVar6;
            }
          }
          iVar8 = iVar8 + 1;
          this->m_pImgDataOut[lVar12] = (uchar)(int)((dVar19 * dVar7 * dVar18) / dVar4);
          lVar12 = lVar12 + 1;
          iVar15 = *(int *)((longlong)&this->_padding_ + 4);
        } while (iVar8 < iVar15);
      }
      iVar13 = iVar13 + 1;
      iVar17 = iVar17 + uVar16;
    } while (iVar13 < (int)this->_padding_);
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
  double *pdVar11;
  longlong lVar12;
  FunDIB *unaff_RBX;
  int iVar13;
  longlong lVar14;
  int iVar15;
  int unaff_R12D;
  int iVar16;
  float *unaff_R15;
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
  pdVar11 = (double *)operator_new__(_Var10);
  dVar8 = __real_406fe00000000000;
  dVar5 = __real_400921fb4d12d84a;
  iVar13 = 0;
  unaff_RBX->m_pImgBufInput = pdVar11;
  if (0 < (int)unaff_RBX->_padding_) {
    iVar16 = 0;
    do {
      iVar15 = 0;
      if (0 < *(int *)((longlong)&unaff_RBX->_padding_ + 4)) {
        lVar14 = (longlong)iVar16;
        do {
          dVar17 = sin(((double)((uint)*(byte *)(unaff_RBX->_padding_ + lVar14) * 2) * dVar5) /
                       dVar8);
          lVar14 = lVar14 + 1;
          iVar9 = iVar13 * *(int *)((longlong)&unaff_RBX->_padding_ + 4) + iVar15;
          iVar15 = iVar15 + 1;
          unaff_RBX->m_pImgBufInput[iVar9] = dVar17;
        } while (iVar15 < *(int *)((longlong)&unaff_RBX->_padding_ + 4));
      }
      iVar13 = iVar13 + 1;
      iVar16 = iVar16 + unaff_R12D;
    } while (iVar13 < (int)unaff_RBX->_padding_);
  }
  FunDIB::SpecialFilter(unaff_RBX,(int)lVar12,unaff_R15,unaff_XMM6_Da,1);
  iVar13 = (int)lVar12;
  iVar16 = 0;
  if (0 < (int)unaff_RBX->_padding_) {
    iVar15 = 0;
    do {
      iVar13 = 0;
      if (0 < *(int *)((longlong)&unaff_RBX->_padding_ + 4)) {
        lVar14 = (longlong)iVar15;
        do {
          dVar17 = cos(((double)((uint)*(byte *)(unaff_RBX->_padding_ + lVar14) * 2) * dVar5) /
                       dVar8);
          lVar14 = lVar14 + 1;
          iVar9 = iVar16 * *(int *)((longlong)&unaff_RBX->_padding_ + 4) + iVar13;
          iVar13 = iVar13 + 1;
          unaff_RBX->m_pImgBufInput[iVar9] = dVar17;
        } while (iVar13 < *(int *)((longlong)&unaff_RBX->_padding_ + 4));
      }
      iVar13 = (int)lVar12;
      iVar16 = iVar16 + 1;
      iVar15 = iVar15 + unaff_R12D;
    } while (iVar16 < (int)unaff_RBX->_padding_);
  }
  FunDIB::SpecialFilter(unaff_RBX,iVar13,unaff_R15,unaff_XMM6_Da,2);
  dVar7 = __real_401921fb4d12d84a;
  dVar6 = __real_4012d97c79ce2238;
  dVar4 = __real_3ff921fb4d12d84a;
  dVar17 = __real_3fe0000000000000;
  iVar13 = 0;
  if (0 < (int)unaff_RBX->_padding_) {
    iVar16 = 0;
    do {
      iVar15 = *(int *)((longlong)&unaff_RBX->_padding_ + 4);
      iVar9 = 0;
      if (0 < iVar15) {
        lVar12 = (longlong)iVar16;
        do {
          iVar15 = iVar15 * iVar13 + iVar9;
          dVar18 = unaff_RBX->m_pImgBufOut2[iVar15];
          if (0.0 <= dVar18) {
            dVar1 = unaff_RBX->m_pImgBufOut1[iVar15];
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
            dVar1 = unaff_RBX->m_pImgBufOut1[iVar15];
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
          unaff_RBX->m_pImgDataOut[lVar12] = (uchar)(int)((dVar18 * dVar8 * dVar17) / dVar5);
          lVar12 = lVar12 + 1;
          iVar15 = *(int *)((longlong)&unaff_RBX->_padding_ + 4);
        } while (iVar9 < iVar15);
      }
      iVar13 = iVar13 + 1;
      iVar16 = iVar16 + unaff_R12D;
    } while (iVar13 < (int)unaff_RBX->_padding_);
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
  
  dVar5 = __real_401921fb4d12d84a;
  dVar4 = __real_4012d97c79ce2238;
  dVar3 = __real_3ff921fb4d12d84a;
  dVar2 = __real_3fe0000000000000;
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



/* 140008db0 PhaseUnwrap */

void __thiscall FunDIB::PhaseUnwrap(FunDIB *this,int param_1)

{
  int iVar1;
  longlong lVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  double dVar6;
  int iVar7;
  int iVar8;
  uchar *puVar9;
  __uint64 _Var10;
  double *pdVar11;
  void *_Dst;
  int *piVar12;
  int *piVar13;
  double *pdVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  ulonglong uVar18;
  int iVar19;
  int iVar20;
  longlong lVar21;
  int *piVar22;
  ulonglong uVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  uint uVar28;
  
  if ((int)this->_padding_ != 8) {
                    /* WARNING: Could not recover jumptable at 0x000140008dd3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    AfxMessageBox("Only for 8 bits gray image!",0,0);
    return;
  }
  iVar16 = *(int *)((longlong)&this->_padding_ + 4);
  iVar1 = iVar16 + 3;
  iVar19 = (int)this->_padding_;
  iVar7 = (int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2;
  this->m_imgWidthOut = iVar16;
  iVar1 = iVar7 * 4;
  this->m_nBitCountOut = 8;
  this->m_imgHeightOut = iVar19;
  if (this->m_pImgDataOut != (uchar *)0x0) {
    operator_delete__(this->m_pImgDataOut);
    iVar19 = this->m_imgHeightOut;
    this->m_pImgDataOut = (uchar *)0x0;
  }
  puVar9 = (uchar *)operator_new__((longlong)(iVar19 * iVar1));
  this->m_pImgDataOut = puVar9;
  auVar3._8_8_ = 0;
  auVar3._0_8_ = (longlong)((int)this->_padding_ * *(int *)((longlong)&this->_padding_ + 4));
  _Var10 = SUB168(ZEXT816(8) * auVar3,0);
  if (SUB168(ZEXT816(8) * auVar3,8) != 0) {
    _Var10 = 0xffffffffffffffff;
  }
  pdVar11 = (double *)operator_new__(_Var10);
  dVar6 = __real_406fe00000000000;
  iVar19 = 0;
  iVar16 = (int)this->_padding_;
  if (0 < iVar16) {
    do {
      iVar16 = 0;
      if (0 < *(int *)((longlong)&this->_padding_ + 4)) {
        lVar21 = 0;
        do {
          lVar2 = iVar7 * iVar19 * 4 + lVar21;
          lVar21 = lVar21 + 1;
          pdVar11[iVar19 * *(int *)((longlong)&this->_padding_ + 4) + iVar16] =
               (double)*(byte *)(lVar2 + this->_padding_);
          iVar8 = iVar19 * *(int *)((longlong)&this->_padding_ + 4) + iVar16;
          iVar16 = iVar16 + 1;
          pdVar11[iVar8] = (pdVar11[iVar8] * (double)this->_padding_) / dVar6;
        } while (iVar16 < *(int *)((longlong)&this->_padding_ + 4));
      }
      iVar16 = (int)this->_padding_;
      iVar19 = iVar19 + 1;
    } while (iVar19 < iVar16);
  }
  auVar4._8_8_ = 0;
  auVar4._0_8_ = (longlong)(iVar16 * *(int *)((longlong)&this->_padding_ + 4));
  _Var10 = SUB168(ZEXT816(4) * auVar4,0);
  if (SUB168(ZEXT816(4) * auVar4,8) != 0) {
    _Var10 = 0xffffffffffffffff;
  }
  _Dst = operator_new__(_Var10);
  memset(_Dst,0,(longlong)(int)this->_padding_ * (longlong)*(int *)((longlong)&this->_padding_ + 4)
                * 4);
  iVar16 = *(int *)((longlong)&this->_padding_ + 4);
  iVar19 = (int)this->_padding_ / 2;
  iVar7 = iVar16 / 2;
  uVar18 = (ulonglong)(iVar16 * (int)this->_padding_);
  auVar5._8_8_ = 0;
  auVar5._0_8_ = uVar18;
  _Var10 = SUB168(ZEXT816(8) * auVar5,0);
  if (SUB168(ZEXT816(8) * auVar5,8) != 0) {
    _Var10 = 0xffffffffffffffff;
  }
  piVar12 = (int *)operator_new__(_Var10);
  uVar23 = 0;
  piVar22 = piVar12;
  if (piVar12 == (int *)0x0) {
    piVar12 = (int *)0x0;
  }
  else {
    for (; uVar18 != 0; uVar18 = uVar18 - 1) {
      piVar22[0] = 0;
      piVar22[1] = 0;
      piVar22 = piVar22 + 2;
    }
  }
  dVar25 = __real_bfe0000000000000;
  dVar27 = __real_3fe0000000000000;
  uVar15 = (uint)__xmm_7fffffffffffffff7fffffffffffffff;
  uVar28 = (uint)((ulonglong)__xmm_7fffffffffffffff7fffffffffffffff >> 0x20);
  piVar12[1] = iVar7;
  *piVar12 = iVar19;
  *(undefined4 *)
   ((longlong)_Dst + (longlong)(iVar7 + iVar19 * *(int *)((longlong)&this->_padding_ + 4)) * 4) = 1;
  iVar16 = *(int *)((longlong)&this->_padding_ + 4);
  piVar22 = piVar12;
  uVar18 = uVar23;
  do {
    iVar7 = (int)uVar18;
    iVar19 = *piVar22;
    uVar18 = uVar23;
    if ((0 < iVar19) &&
       (iVar8 = iVar19 + -1,
       *(int *)((longlong)_Dst + (longlong)(iVar16 * iVar8 + piVar22[1]) * 4) == 0)) {
      *(int *)(uVar23 + 8 + (longlong)piVar22) = iVar8;
      uVar18 = uVar23 + 8;
      iVar16 = piVar22[1];
      iVar7 = iVar7 + 1;
      *(int *)(uVar23 + 0xc + (longlong)piVar22) = iVar16;
      *(undefined4 *)
       ((longlong)_Dst + (longlong)(iVar16 + iVar8 * *(int *)((longlong)&this->_padding_ + 4)) * 4)
           = 1;
      iVar16 = *(int *)((longlong)&this->_padding_ + 4);
      iVar8 = *(int *)(uVar18 + (longlong)piVar22);
      iVar17 = *(int *)(uVar23 + 0xc + (longlong)piVar22);
      iVar19 = *piVar22;
      iVar20 = piVar22[1];
      dVar26 = (double)this->_padding_;
      if (dVar26 * dVar27 <
          (double)CONCAT44((uint)((ulonglong)
                                  (pdVar11[iVar8 * iVar16 + iVar17] -
                                  pdVar11[iVar19 * iVar16 + iVar20]) >> 0x20) & uVar28,
                           SUB84(pdVar11[iVar8 * iVar16 + iVar17] -
                                 pdVar11[iVar19 * iVar16 + iVar20],0) & uVar15)) {
        do {
          iVar17 = iVar8 * iVar16 + iVar17;
          dVar24 = pdVar11[iVar17];
          if (dVar26 * dVar25 <= dVar24 - pdVar11[iVar20 + iVar16 * iVar19]) {
            if (dVar26 * dVar27 < dVar24 - pdVar11[iVar20 + iVar16 * iVar19]) {
              pdVar11[iVar17] = dVar24 - dVar26;
            }
          }
          else {
            pdVar11[iVar17] = dVar26 + dVar24;
          }
          iVar16 = *(int *)((longlong)&this->_padding_ + 4);
          iVar8 = *(int *)(uVar18 + (longlong)piVar22);
          iVar17 = *(int *)(uVar23 + 0xc + (longlong)piVar22);
          iVar19 = *piVar22;
          iVar20 = piVar22[1];
          dVar26 = (double)this->_padding_;
        } while (dVar26 * dVar27 <
                 (double)CONCAT44((uint)((ulonglong)
                                         (pdVar11[iVar16 * iVar8 + iVar17] -
                                         pdVar11[iVar19 * iVar16 + iVar20]) >> 0x20) & uVar28,
                                  SUB84(pdVar11[iVar16 * iVar8 + iVar17] -
                                        pdVar11[iVar19 * iVar16 + iVar20],0) & uVar15));
      }
    }
    iVar8 = piVar22[1];
    uVar23 = uVar18;
    if ((0 < iVar8) &&
       (*(int *)((longlong)_Dst + (longlong)(iVar8 + iVar16 * iVar19) * 4 + -4) == 0)) {
      *(int *)(uVar18 + 8 + (longlong)piVar22) = iVar19;
      uVar23 = uVar18 + 8;
      iVar16 = piVar22[1];
      iVar7 = iVar7 + 1;
      *(int *)(uVar18 + 0xc + (longlong)piVar22) = iVar16 + -1;
      *(undefined4 *)
       ((longlong)_Dst +
       (longlong)(iVar16 + -1 + iVar19 * *(int *)((longlong)&this->_padding_ + 4)) * 4) = 1;
      iVar16 = *(int *)((longlong)&this->_padding_ + 4);
      iVar17 = *(int *)(uVar23 + (longlong)piVar22);
      iVar20 = *(int *)(uVar18 + 0xc + (longlong)piVar22);
      iVar19 = *piVar22;
      iVar8 = piVar22[1];
      dVar26 = (double)this->_padding_;
      if (dVar26 * dVar27 <
          (double)CONCAT44((uint)((ulonglong)
                                  (pdVar11[iVar17 * iVar16 + iVar20] -
                                  pdVar11[iVar19 * iVar16 + iVar8]) >> 0x20) & uVar28,
                           SUB84(pdVar11[iVar17 * iVar16 + iVar20] -
                                 pdVar11[iVar19 * iVar16 + iVar8],0) & uVar15)) {
        do {
          iVar20 = iVar17 * iVar16 + iVar20;
          dVar24 = pdVar11[iVar20];
          if (dVar26 * dVar25 <= dVar24 - pdVar11[iVar8 + iVar16 * iVar19]) {
            if (dVar26 * dVar27 < dVar24 - pdVar11[iVar8 + iVar16 * iVar19]) {
              dVar24 = dVar24 - dVar26;
              goto LAB_140009214;
            }
          }
          else {
            dVar24 = dVar24 + dVar26;
LAB_140009214:
            pdVar11[iVar20] = dVar24;
          }
          iVar16 = *(int *)((longlong)&this->_padding_ + 4);
          iVar17 = *(int *)(uVar23 + (longlong)piVar22);
          iVar20 = *(int *)(uVar18 + 0xc + (longlong)piVar22);
          iVar19 = *piVar22;
          iVar8 = piVar22[1];
          dVar26 = (double)this->_padding_;
        } while (dVar26 * dVar27 <
                 (double)CONCAT44((uint)((ulonglong)
                                         (pdVar11[iVar16 * iVar17 + iVar20] -
                                         pdVar11[iVar19 * iVar16 + iVar8]) >> 0x20) & uVar28,
                                  SUB84(pdVar11[iVar16 * iVar17 + iVar20] -
                                        pdVar11[iVar19 * iVar16 + iVar8],0) & uVar15));
      }
    }
    uVar18 = uVar23;
    if ((iVar19 < (int)this->_padding_ + -1) &&
       (iVar17 = iVar19 + 1, *(int *)((longlong)_Dst + (longlong)(iVar8 + iVar16 * iVar17) * 4) == 0
       )) {
      *(int *)(uVar23 + 8 + (longlong)piVar22) = iVar17;
      uVar18 = uVar23 + 8;
      iVar16 = piVar22[1];
      iVar7 = iVar7 + 1;
      *(int *)(uVar23 + 0xc + (longlong)piVar22) = iVar16;
      *(undefined4 *)
       ((longlong)_Dst + (longlong)(iVar16 + iVar17 * *(int *)((longlong)&this->_padding_ + 4)) * 4)
           = 1;
      iVar16 = *(int *)((longlong)&this->_padding_ + 4);
      iVar17 = *(int *)(uVar18 + (longlong)piVar22);
      iVar20 = *(int *)(uVar23 + 0xc + (longlong)piVar22);
      iVar19 = *piVar22;
      iVar8 = piVar22[1];
      dVar26 = (double)this->_padding_;
      if (dVar26 * dVar27 <
          (double)CONCAT44((uint)((ulonglong)
                                  (pdVar11[iVar17 * iVar16 + iVar20] -
                                  pdVar11[iVar16 * iVar19 + iVar8]) >> 0x20) & uVar28,
                           SUB84(pdVar11[iVar17 * iVar16 + iVar20] -
                                 pdVar11[iVar16 * iVar19 + iVar8],0) & uVar15)) {
        do {
          iVar20 = iVar17 * iVar16 + iVar20;
          dVar24 = pdVar11[iVar20];
          if (dVar26 * dVar25 <= dVar24 - pdVar11[iVar16 * iVar19 + iVar8]) {
            if (dVar26 * dVar27 < dVar24 - pdVar11[iVar16 * iVar19 + iVar8]) {
              dVar24 = dVar24 - dVar26;
              goto LAB_140009355;
            }
          }
          else {
            dVar24 = dVar24 + dVar26;
LAB_140009355:
            pdVar11[iVar20] = dVar24;
          }
          iVar16 = *(int *)((longlong)&this->_padding_ + 4);
          iVar17 = *(int *)(uVar18 + (longlong)piVar22);
          iVar20 = *(int *)(uVar23 + 0xc + (longlong)piVar22);
          iVar19 = *piVar22;
          iVar8 = piVar22[1];
          dVar26 = (double)this->_padding_;
        } while (dVar26 * dVar27 <
                 (double)CONCAT44((uint)((ulonglong)
                                         (pdVar11[iVar16 * iVar17 + iVar20] -
                                         pdVar11[iVar19 * iVar16 + iVar8]) >> 0x20) & uVar28,
                                  SUB84(pdVar11[iVar16 * iVar17 + iVar20] -
                                        pdVar11[iVar19 * iVar16 + iVar8],0) & uVar15));
      }
    }
    uVar23 = uVar18;
    if ((iVar8 < iVar16 + -1) &&
       (*(int *)((longlong)_Dst + (longlong)(iVar19 * iVar16 + iVar8) * 4 + 4) == 0)) {
      *(int *)(uVar18 + 8 + (longlong)piVar22) = iVar19;
      uVar23 = uVar18 + 8;
      iVar16 = piVar22[1];
      iVar7 = iVar7 + 1;
      *(int *)(uVar18 + 0xc + (longlong)piVar22) = iVar16 + 1;
      *(undefined4 *)
       ((longlong)_Dst +
       (longlong)(iVar16 + 1 + iVar19 * *(int *)((longlong)&this->_padding_ + 4)) * 4) = 1;
      iVar16 = *(int *)((longlong)&this->_padding_ + 4);
      iVar19 = *(int *)(uVar23 + (longlong)piVar22);
      iVar8 = *(int *)(uVar18 + 0xc + (longlong)piVar22);
      iVar17 = *piVar22;
      iVar20 = piVar22[1];
      dVar26 = (double)this->_padding_;
      if (dVar26 * dVar27 <
          (double)CONCAT44((uint)((ulonglong)
                                  (pdVar11[iVar19 * iVar16 + iVar8] -
                                  pdVar11[iVar16 * iVar17 + iVar20]) >> 0x20) & uVar28,
                           SUB84(pdVar11[iVar19 * iVar16 + iVar8] -
                                 pdVar11[iVar16 * iVar17 + iVar20],0) & uVar15)) {
        do {
          iVar8 = iVar19 * iVar16 + iVar8;
          dVar24 = pdVar11[iVar8];
          if (dVar26 * dVar25 <= dVar24 - pdVar11[iVar20 + iVar16 * iVar17]) {
            if (dVar26 * dVar27 < dVar24 - pdVar11[iVar20 + iVar16 * iVar17]) {
              dVar24 = dVar24 - dVar26;
              goto LAB_140009494;
            }
          }
          else {
            dVar24 = dVar24 + dVar26;
LAB_140009494:
            pdVar11[iVar8] = dVar24;
          }
          iVar16 = *(int *)((longlong)&this->_padding_ + 4);
          iVar19 = *(int *)(uVar23 + (longlong)piVar22);
          iVar8 = *(int *)(uVar18 + 0xc + (longlong)piVar22);
          iVar17 = *piVar22;
          iVar20 = piVar22[1];
          dVar26 = (double)this->_padding_;
        } while (dVar26 * dVar27 <
                 (double)CONCAT44((uint)((ulonglong)
                                         (pdVar11[iVar16 * iVar19 + iVar8] -
                                         pdVar11[iVar17 * iVar16 + iVar20]) >> 0x20) & uVar28,
                                  SUB84(pdVar11[iVar16 * iVar19 + iVar8] -
                                        pdVar11[iVar17 * iVar16 + iVar20],0) & uVar15));
      }
    }
    piVar13 = piVar22 + 2;
    if (iVar7 < 1) {
      piVar13 = piVar22;
    }
    uVar18 = (ulonglong)(iVar7 - 1U);
    uVar23 = uVar23 - 8;
    piVar22 = piVar13;
    if (iVar7 - 1U == 0xffffffff) {
      uVar15 = (int)this->_padding_ * *(int *)((longlong)&this->_padding_ + 4);
      uVar18 = (ulonglong)uVar15;
      dVar27 = *pdVar11;
      pdVar14 = pdVar11;
      dVar25 = dVar27;
      dVar26 = dVar27;
      if (0 < (int)uVar15) {
        do {
          dVar24 = *pdVar14;
          dVar25 = dVar24;
          if (dVar24 <= dVar26) {
            dVar25 = dVar26;
          }
          if (dVar27 <= dVar24) {
            dVar24 = dVar27;
          }
          dVar27 = dVar24;
          uVar18 = uVar18 - 1;
          pdVar14 = pdVar14 + 1;
          dVar26 = dVar25;
        } while (uVar18 != 0);
      }
      iVar16 = 0;
      if (0 < this->m_imgHeightOut) {
        iVar19 = 0;
        do {
          iVar7 = 0;
          if (0 < this->m_imgWidthOut) {
            lVar21 = 0;
            do {
              iVar8 = iVar16 * *(int *)((longlong)&this->_padding_ + 4) + iVar7;
              iVar7 = iVar7 + 1;
              this->m_pImgDataOut[iVar19 + lVar21] =
                   (uchar)(int)(((pdVar11[iVar8] - dVar27) * dVar6) / (dVar25 - dVar27));
              lVar21 = lVar21 + 1;
            } while (iVar7 < this->m_imgWidthOut);
          }
          iVar16 = iVar16 + 1;
          iVar19 = iVar19 + iVar1;
        } while (iVar16 < this->m_imgHeightOut);
      }
      this->m_dPhaseDifOut = dVar25 - dVar27;
      operator_delete__(pdVar11);
      operator_delete__(piVar12);
                    /* WARNING: Could not recover jumptable at 0x000140009613. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      operator_delete__(_Dst);
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
  dVar4 = __real_406fe00000000000;
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
  dVar24 = __real_bfe0000000000000;
  dVar26 = __real_3fe0000000000000;
  uVar13 = (uint)__xmm_7fffffffffffffff7fffffffffffffff;
  uVar27 = (uint)((ulonglong)__xmm_7fffffffffffffff7fffffffffffffff >> 0x20);
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



/* 140009620 ~ImgDIB */

void __thiscall ImgDIB::~ImgDIB(ImgDIB *this)

{
  if (this->m_lpDib != (uchar *)0x0) {
    operator_delete__(this->m_lpDib);
  }
  if (this->m_hPalette != (HPALETTE__ *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000140009646. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    DeleteObject(this->m_hPalette);
    return;
  }
  return;
}



/* 140009660 Read */

int __thiscall ImgDIB::Read(ImgDIB *this,char *param_1)

{
  int iVar1;
  uint uVar2;
  int extraout_EAX;
  __uint64 _Var3;
  uchar *puVar4;
  CMemoryException *pCVar5;
  ImgDIB *this_00;
  tagBITMAPINFOHEADER *ptVar6;
  undefined1 auStack_98 [32];
  CMemoryException *local_78;
  CMemoryException *local_70;
  CMemoryException *local_68;
  ImgDIB local_60;
  ulonglong local_18;
  
  local_60.m_lpBmpInfoHead = (tagBITMAPINFOHEADER *)0xfffffffffffffffe;
  local_18 = __security_cookie ^ (ulonglong)auStack_98;
  CFile::CFile((CFile *)&local_60);
  iVar1 = CFile::Open((CFile *)&local_60,param_1,0x20,(CFileException *)0x0);
  if (iVar1 == 0) {
    CFile::~CFile((CFile *)&local_60);
  }
  else {
    if (this->m_lpDib != (uchar *)0x0) {
      operator_delete__(this->m_lpDib);
      this->m_lpDib = (uchar *)0x0;
      this->m_lpColorTable = (tagRGBQUAD *)0x0;
      this->m_pImgData = (uchar *)0x0;
      this->m_lpBmpInfoHead = (tagBITMAPINFOHEADER *)0x0;
    }
    pCVar5 = (CMemoryException *)0x0;
    if (this->m_hPalette != (HPALETTE__ *)0x0) {
      DeleteObject(this->m_hPalette);
      this->m_hPalette = (HPALETTE__ *)0x0;
    }
    uVar2 = CFile::Read((CFile *)&local_60,&local_60.m_nColorTableLength,0xe);
    if (uVar2 != 0xe) {
      local_68 = (CMemoryException *)operator_new(0xa0);
      if (local_68 != (CMemoryException *)0x0) {
        pCVar5 = CMemoryException::CMemoryException(local_68);
      }
      local_78 = pCVar5;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_78,(ThrowInfo *)&_TI5PEAVCMemoryException__);
    }
    if ((short)local_60.m_nColorTableLength != 0x4d42) {
      local_68 = (CMemoryException *)operator_new(0xa0);
      if (local_68 != (CMemoryException *)0x0) {
        pCVar5 = CMemoryException::CMemoryException(local_68);
      }
      local_70 = pCVar5;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_70,(ThrowInfo *)&_TI5PEAVCMemoryException__);
    }
    if (this->m_lpDib != (uchar *)0x0) {
      operator_delete__(this->m_lpDib);
    }
    _Var3 = CFile::GetLength((CFile *)&local_60);
    puVar4 = (uchar *)operator_new__((ulonglong)((int)_Var3 - 0xe));
    this->m_lpDib = puVar4;
    _Var3 = CFile::GetLength((CFile *)&local_60);
    this_00 = &local_60;
    CFile::Read((CFile *)this_00,this->m_lpDib,(int)_Var3 - 0xe);
    ptVar6 = (tagBITMAPINFOHEADER *)this->m_lpDib;
    this->m_lpBmpInfoHead = ptVar6;
    this->m_imgWidth = ptVar6->biWidth;
    this->m_imgHeight = ptVar6->biHeight;
    this->m_nBitCount = (uint)ptVar6->biBitCount;
    this->m_dPhaseDif = 6.2831852;
    iVar1 = ComputeColorTabalLength(this_00,(uint)ptVar6->biBitCount);
    this->m_nColorTableLength = iVar1;
    this->m_hPalette = (HPALETTE__ *)0x0;
    if (iVar1 != 0) {
      this->m_lpColorTable = (tagRGBQUAD *)(ptVar6 + 1);
      MakePalette(this);
    }
    this->m_pImgData = this->m_lpDib + ((longlong)this->m_nColorTableLength + 10) * 4;
    CFile::~CFile((CFile *)&local_60);
  }
  __security_check_cookie(local_18 ^ (ulonglong)auStack_98);
  return extraout_EAX;
}



/* 140009880 ReplaceDib */

void __thiscall
ImgDIB::ReplaceDib(ImgDIB *this,CSize param_1,int param_2,tagRGBQUAD *param_3,uchar *param_4,
                  double param_5)

{
  int iVar1;
  tagBITMAPINFOHEADER *ptVar2;
  size_t _Size;
  int iStackX_14;
  
  if (this->m_lpDib != (uchar *)0x0) {
    operator_delete__(this->m_lpDib);
    this->m_lpDib = (uchar *)0x0;
    this->m_lpColorTable = (tagRGBQUAD *)0x0;
    this->m_pImgData = (uchar *)0x0;
    this->m_lpBmpInfoHead = (tagBITMAPINFOHEADER *)0x0;
  }
  if (this->m_hPalette != (HPALETTE__ *)0x0) {
    DeleteObject(this->m_hPalette);
    this->m_hPalette = (HPALETTE__ *)0x0;
  }
  iStackX_14 = param_1._4_4_;
  iVar1 = param_1._0_4_ + 3;
  this->m_imgWidth = param_1._0_4_;
  this->m_imgHeight = iStackX_14;
  this->m_dPhaseDif = param_5;
  this->m_nBitCount = 8;
  this->m_nColorTableLength = 0x100;
  _Size = (size_t)(((int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2) * iStackX_14 * 4);
  ptVar2 = (tagBITMAPINFOHEADER *)operator_new__(_Size + 0x428);
  this->m_lpBmpInfoHead = ptVar2;
  this->m_lpDib = (uchar *)ptVar2;
  ptVar2->biSize = 0x28;
  this->m_lpBmpInfoHead->biWidth = this->m_imgWidth;
  this->m_lpBmpInfoHead->biHeight = this->m_imgHeight;
  this->m_lpBmpInfoHead->biPlanes = 1;
  this->m_lpBmpInfoHead->biBitCount = (ushort)this->m_nBitCount;
  this->m_lpBmpInfoHead->biCompression = 0;
  this->m_lpBmpInfoHead->biSizeImage = 0;
  this->m_lpBmpInfoHead->biXPelsPerMeter = 0;
  this->m_lpBmpInfoHead->biYPelsPerMeter = 0;
  this->m_lpBmpInfoHead->biClrUsed = this->m_nColorTableLength;
  this->m_lpBmpInfoHead->biClrImportant = this->m_nColorTableLength;
  iVar1 = this->m_nColorTableLength;
  this->m_hPalette = (HPALETTE__ *)0x0;
  if (iVar1 != 0) {
    this->m_lpColorTable = (tagRGBQUAD *)(this->m_lpDib + 0x28);
    memcpy((tagRGBQUAD *)(this->m_lpDib + 0x28),param_3,(longlong)iVar1 << 2);
    MakePalette(this);
    iVar1 = this->m_nColorTableLength;
  }
  this->m_pImgData = this->m_lpDib + (longlong)iVar1 * 4 + 0x28;
  memcpy(this->m_lpDib + (longlong)iVar1 * 4 + 0x28,param_4,_Size);
  return;
}



/* 1400099f0 ComputeColorTabalLength */

int __thiscall ImgDIB::ComputeColorTabalLength(ImgDIB *this,int param_1)

{
  int local_res10;
  
  switch(param_1) {
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



/* 140009a70 MakePalette */

void __thiscall ImgDIB::MakePalette(ImgDIB *this)

{
  LOGPALETTE *plpal;
  HPALETTE pHVar1;
  BYTE *pBVar2;
  tagRGBQUAD *ptVar3;
  int iVar4;
  
  iVar4 = this->m_nColorTableLength;
  if (iVar4 != 0) {
    if (this->m_hPalette != (HPALETTE__ *)0x0) {
      DeleteObject(this->m_hPalette);
      iVar4 = this->m_nColorTableLength;
    }
    plpal = (LOGPALETTE *)operator_new__((longlong)iVar4 * 4 + 4);
    iVar4 = 0;
    plpal->palVersion = 0x300;
    plpal->palNumEntries = (WORD)this->m_nColorTableLength;
    if (0 < this->m_nColorTableLength) {
      pBVar2 = &plpal->palPalEntry[0].peGreen;
      ptVar3 = this->m_lpColorTable;
      do {
        ((PALETTEENTRY *)(pBVar2 + -1))->peRed = ptVar3->rgbRed;
        iVar4 = iVar4 + 1;
        *pBVar2 = ptVar3->rgbGreen;
        pBVar2[1] = ptVar3->rgbBlue;
        pBVar2[2] = '\0';
        pBVar2 = pBVar2 + 4;
        ptVar3 = ptVar3 + 1;
      } while (iVar4 < this->m_nColorTableLength);
    }
    pHVar1 = CreatePalette(plpal);
    this->m_hPalette = (HPALETTE__ *)pHVar1;
    operator_delete(plpal,8);
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
  operator_delete(plpal,8);
  return;
}



/* 140009b1c FUN_140009b1c */

void FUN_140009b1c(void)

{
  return;
}



/* 140009b22 operator_delete */

/* void __cdecl operator delete(void * __ptr64) */

void __cdecl operator_delete(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000140009b22. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete(param_1);
  return;
}



/* 140009e8e AfxGetModuleState */

/* class AFX_MODULE_STATE * __ptr64 __cdecl AfxGetModuleState(void) */

AFX_MODULE_STATE * __cdecl AfxGetModuleState(void)

{
  AFX_MODULE_STATE *pAVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140009e8e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar1 = AfxGetModuleState();
  return pAVar1;
}



/* 140009f20 __security_check_cookie */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie == __security_cookie) && ((short)(_StackCookie >> 0x30) == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure(_StackCookie);
}



/* 140009f44 __scrt_acquire_startup_lock */

bool __cdecl __scrt_acquire_startup_lock(void)

{
  void *pvVar1;
  int iVar2;
  void *pvVar3;
  bool bVar4;
  
  iVar2 = __scrt_is_ucrt_dll_in_use();
  if (iVar2 == 0) {
LAB_140009f72:
    bVar4 = false;
  }
  else {
    do {
      pvVar3 = (void *)0x0;
      LOCK();
      bVar4 = __scrt_native_startup_lock == (void *)0x0;
      pvVar1 = *(void **)((longlong)Self + 8);
      if (!bVar4) {
        pvVar3 = __scrt_native_startup_lock;
        pvVar1 = __scrt_native_startup_lock;
      }
      __scrt_native_startup_lock = pvVar1;
      UNLOCK();
      if (bVar4) goto LAB_140009f72;
    } while (*(void **)((longlong)Self + 8) != pvVar3);
    bVar4 = true;
  }
  return bVar4;
}



/* 140009f80 __scrt_initialize_crt */

bool __cdecl __scrt_initialize_crt(__scrt_module_type param_1)

{
  bool bVar1;
  
  if (param_1 == dll) {
    is_initialized_as_dll = true;
  }
  __isa_available_init();
  bVar1 = _should_initialize_environment();
  if (bVar1) {
    bVar1 = _should_initialize_environment();
    if (bVar1) {
      return true;
    }
    _should_initialize_environment();
  }
  return false;
}



/* 140009fcc __scrt_initialize_onexit_tables */

bool __cdecl __scrt_initialize_onexit_tables(__scrt_module_type param_1)

{
  byte bVar1;
  int iVar2;
  
  if (!module_local_atexit_table_initialized) {
    if (exe < param_1) {
                    /* WARNING: Subroutine does not return */
      __scrt_fastfail(5);
    }
    iVar2 = __scrt_is_ucrt_dll_in_use();
    if ((iVar2 == 0) || (param_1 != dll)) {
      bVar1 = 0x40 - ((byte)__security_cookie & 0x3f) & 0x3f;
      module_local_atexit_table._first =
           (_func___cdecl_void **)
           ((0xffffffffffffffffU >> bVar1 | -1L << 0x40 - bVar1) ^ __security_cookie);
      module_local_atexit_table._last = module_local_atexit_table._first;
      module_local_atexit_table._end = module_local_atexit_table._first;
      module_local_at_quick_exit_table._first = module_local_atexit_table._first;
      module_local_at_quick_exit_table._last = module_local_atexit_table._first;
      module_local_at_quick_exit_table._end = module_local_atexit_table._first;
    }
    else {
      iVar2 = _initialize_onexit_table(&module_local_atexit_table);
      if ((iVar2 != 0) ||
         (iVar2 = _initialize_onexit_table(&module_local_at_quick_exit_table), iVar2 != 0)) {
        return false;
      }
    }
    module_local_atexit_table_initialized = true;
  }
  return true;
}



/* 14000a0a4 __scrt_is_nonwritable_in_current_image */

bool __cdecl __scrt_is_nonwritable_in_current_image(void *param_1)

{
  bool bVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (((IMAGE_DOS_HEADER_140000000.e_magic == (char  [2])0x5a4d) &&
      (lVar2 = (longlong)(int)IMAGE_DOS_HEADER_140000000.e_lfanew,
      *(int *)(IMAGE_DOS_HEADER_140000000.e_magic + lVar2) == 0x4550)) &&
     (*(short *)((longlong)IMAGE_DOS_HEADER_140000000.e_res_4_ + lVar2 + -4) == 0x20b)) {
    lVar3 = lVar2 + 0x140000018 +
            (ulonglong)*(ushort *)((longlong)IMAGE_DOS_HEADER_140000000.e_res_4_ + lVar2 + -8);
    lVar2 = lVar3 + (ulonglong)*(ushort *)(IMAGE_DOS_HEADER_140000000.e_magic + lVar2 + 6) * 0x28;
    for (; lVar3 != lVar2; lVar3 = lVar3 + 0x28) {
      if (((ulonglong)*(uint *)(lVar3 + 0xc) <= (longlong)param_1 - 0x140000000U) &&
         ((longlong)param_1 - 0x140000000U <
          (ulonglong)(*(int *)(lVar3 + 8) + *(uint *)(lVar3 + 0xc)))) goto LAB_14000a11b;
    }
    lVar3 = 0;
LAB_14000a11b:
    if (lVar3 == 0) {
      bVar1 = false;
    }
    else if (*(int *)(lVar3 + 0x24) < 0) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}



/* 14000a140 __scrt_release_startup_lock */

void __cdecl __scrt_release_startup_lock(bool param_1)

{
  int iVar1;
  
  iVar1 = __scrt_is_ucrt_dll_in_use();
  if ((iVar1 != 0) && (!param_1)) {
    LOCK();
    __scrt_native_startup_lock = (void *)0x0;
    UNLOCK();
  }
  return;
}



/* 14000a164 __scrt_uninitialize_crt */

bool __cdecl __scrt_uninitialize_crt(bool param_1,bool param_2)

{
  if ((!is_initialized_as_dll) || (!param_2)) {
    _should_initialize_environment();
    _should_initialize_environment();
  }
  return true;
}



/* 14000a190 _onexit */

_onexit_t __cdecl _onexit(_onexit_t _Func)

{
  int iVar1;
  byte bVar2;
  _onexit_t p_Var3;
  
  bVar2 = (byte)__security_cookie & 0x3f;
  if (((__security_cookie ^ (ulonglong)module_local_atexit_table._first) >> bVar2 |
      (__security_cookie ^ (ulonglong)module_local_atexit_table._first) << 0x40 - bVar2) ==
      0xffffffffffffffff) {
    iVar1 = _crt_atexit();
  }
  else {
    iVar1 = _register_onexit_function(&module_local_atexit_table,_Func);
  }
  p_Var3 = (_onexit_t)0x0;
  if (iVar1 == 0) {
    p_Var3 = _Func;
  }
  return p_Var3;
}



/* 14000a1e0 atexit */

int __cdecl atexit(_func_5014 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = _onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



/* 14000a1f8 `scalar_deleting_destructor' */

void * __thiscall type_info::_scalar_deleting_destructor_(type_info *this,uint param_1)

{
  this->_padding_ = (longlong)vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(this,0x18);
  }
  return this;
}



/* 14000a224 operator_delete */

void __cdecl operator_delete(void *param_1,ulong64 param_2)

{
                    /* WARNING: Could not recover jumptable at 0x000140009b22. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete(param_1);
  return;
}



/* 14000a22c __scrt_initialize_thread_safe_statics */

int __cdecl __scrt_initialize_thread_safe_statics(void)

{
  byte bVar1;
  bool bVar2;
  HMODULE hModule;
  FARPROC pFVar3;
  FARPROC pFVar4;
  FARPROC pFVar5;
  byte bVar6;
  
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)&_Tss_mutex,4000);
  hModule = GetModuleHandleW(L"api-ms-win-core-synch-l1-2-0.dll");
  if ((hModule == (HMODULE)0x0) &&
     (hModule = GetModuleHandleW(L"kernel32.dll"), hModule == (HMODULE)0x0)) {
                    /* WARNING: Subroutine does not return */
    __scrt_fastfail(7);
  }
  pFVar3 = GetProcAddress(hModule,"InitializeConditionVariable");
  pFVar4 = GetProcAddress(hModule,"SleepConditionVariableCS");
  pFVar5 = GetProcAddress(hModule,"WakeAllConditionVariable");
  if (((pFVar3 == (FARPROC)0x0) || (pFVar4 == (FARPROC)0x0)) || (pFVar5 == (FARPROC)0x0)) {
    _Tss_event = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
    if (_Tss_event == (HANDLE)0x0) {
                    /* WARNING: Subroutine does not return */
      __scrt_fastfail(7);
    }
  }
  else {
    _Tss_event = (void *)0x0;
    (*(code *)__guard_dispatch_icall_fptr)(&_Tss_cv);
    bVar6 = 0x40 - ((byte)__security_cookie & 0x3f);
    bVar1 = bVar6 & 0x3f;
    encoded_sleep_condition_variable_cs =
         (_func___cdecl_int__RTL_CONDITION_VARIABLE_ptr__RTL_CRITICAL_SECTION_ptr_ulong *)
         (__security_cookie ^ ((ulonglong)pFVar4 >> bVar1 | (longlong)pFVar4 << 0x40 - bVar1));
    bVar6 = bVar6 & 0x3f;
    encoded_wake_all_condition_variable =
         (_func___cdecl_void__RTL_CONDITION_VARIABLE_ptr *)
         (__security_cookie ^ ((ulonglong)pFVar5 >> bVar6 | (longlong)pFVar5 << 0x40 - bVar6));
  }
  bVar2 = __scrt_initialize_onexit_tables(dll);
  if (!bVar2) {
                    /* WARNING: Subroutine does not return */
    __scrt_fastfail(7);
  }
  atexit(__scrt_uninitialize_thread_safe_statics);
  return 0;
}



/* 14000a38c __scrt_uninitialize_thread_safe_statics */

void __cdecl __scrt_uninitialize_thread_safe_statics(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&_Tss_mutex);
  if (_Tss_event != (void *)0x0) {
    CloseHandle(_Tss_event);
  }
  return;
}



/* 14000a3b4 _Init_thread_footer */

void __cdecl _Init_thread_footer(int *param_1)

{
  ulonglong uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&_Tss_mutex);
  uVar1 = (ulonglong)_tls_index;
  _Init_global_epoch = _Init_global_epoch + 1;
  *param_1 = _Init_global_epoch;
  *(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar1 * 8) + 4) = _Init_global_epoch;
  LeaveCriticalSection((LPCRITICAL_SECTION)&_Tss_mutex);
  _Init_thread_notify();
  return;
}



/* 14000a414 _Init_thread_header */

void __cdecl _Init_thread_header(int *param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&_Tss_mutex);
  do {
    if (*param_1 == 0) {
      *param_1 = -1;
LAB_14000a468:
                    /* WARNING: Could not recover jumptable at 0x00014000a474. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      LeaveCriticalSection((LPCRITICAL_SECTION)&_Tss_mutex);
      return;
    }
    if (*param_1 != -1) {
      *(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4) =
           _Init_global_epoch;
      goto LAB_14000a468;
    }
    _Init_thread_wait(100);
  } while( true );
}



/* 14000a47c _Init_thread_notify */

/* WARNING: Switch with 1 destination removed at 0x00014000a4ad */

void __cdecl _Init_thread_notify(void)

{
  byte bVar1;
  
  if (_Tss_event != (void *)0x0) {
    SetEvent(_Tss_event);
                    /* WARNING: Could not recover jumptable at 0x00014000a4c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    ResetEvent(_Tss_event);
    return;
  }
  bVar1 = (byte)__security_cookie & 0x3f;
                    /* WARNING: Could not recover jumptable at 0x00014000b260. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((__security_cookie ^ (ulonglong)encoded_wake_all_condition_variable) >> bVar1 |
            (__security_cookie ^ (ulonglong)encoded_wake_all_condition_variable) << 0x40 - bVar1))
            (&_Tss_cv);
  return;
}



/* 14000a4cc _Init_thread_wait */

/* WARNING: Switch with 1 destination removed at 0x00014000a50a */

void __cdecl _Init_thread_wait(ulong param_1)

{
  byte bVar1;
  
  if (_Tss_event != (void *)0x0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&_Tss_mutex);
    WaitForSingleObjectEx(_Tss_event,param_1,0);
                    /* WARNING: Could not recover jumptable at 0x00014000a53c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    EnterCriticalSection((LPCRITICAL_SECTION)&_Tss_mutex);
    return;
  }
  bVar1 = (byte)__security_cookie & 0x3f;
                    /* WARNING: Could not recover jumptable at 0x00014000b260. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((__security_cookie ^ (ulonglong)encoded_sleep_condition_variable_cs) >> bVar1 |
            (__security_cookie ^ (ulonglong)encoded_sleep_condition_variable_cs) << 0x40 - bVar1))
            (&_Tss_cv,&_Tss_mutex,param_1);
  return;
}



/* 14000a544 pre_c_initialization */

int __cdecl pre_c_initialization(void)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  _crt_argv_mode _Var5;
  _exception *p_Var6;
  code *_Except;
  ulong64 in_RDX;
  
  _set_app_type(2);
  uVar3 = _get_startup_file_mode();
  p_Var6 = (_exception *)(ulonglong)uVar3;
  _set_fmode(uVar3);
  piVar1 = (int *)__p__commode();
  iVar4 = CWinApp::GetApplicationRecoveryParameter(p_Var6);
  *piVar1 = iVar4;
  bVar2 = __scrt_initialize_onexit_tables(exe);
  if (bVar2) {
    _RTC_Initialize();
    atexit(_RTC_Terminate);
    _Var5 = _get_startup_argv_mode();
    _Except = (code *)(ulonglong)_Var5;
    iVar4 = _configure_narrow_argv();
    if (iVar4 == 0) {
      __scrt_initialize_type_info();
      iVar4 = __scrt_is_user_matherr_present();
      if (iVar4 != 0) {
        _Except = CWinApp::GetApplicationRecoveryParameter;
        __setusermatherr();
      }
      __empty_global_delete(_Except,in_RDX);
      __empty_global_delete(_Except,in_RDX);
      uVar3 = CWinApp::GetApplicationRecoveryParameter((_exception *)_Except);
      p_Var6 = (_exception *)(ulonglong)uVar3;
      _configthreadlocale(uVar3);
      bVar2 = _should_initialize_environment();
      if (bVar2) {
        _initialize_narrow_environment();
      }
      CWinApp::GetApplicationRecoveryParameter(p_Var6);
      iVar4 = __scrt_initialize_mta();
      if (iVar4 == 0) {
        return 0;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  __scrt_fastfail(7);
}



/* 14000a5fc post_pgo_initialization */

int __cdecl post_pgo_initialization(void)

{
  __scrt_initialize_default_local_stdio_options();
  return 0;
}



/* 14000a60c pre_cpp_initialization */

void __cdecl pre_cpp_initialization(void)

{
  int iVar1;
  _exception *in_RCX;
  
  __scrt_set_unhandled_exception_filter();
  iVar1 = CWinApp::GetApplicationRecoveryParameter(in_RCX);
  _set_new_mode(iVar1);
  return;
}



/* 14000a628 __scrt_common_main_seh */

int __cdecl __scrt_common_main_seh(void)

{
  bool bVar1;
  bool bVar2;
  ushort uVar3;
  int iVar4;
  _func___cdecl_void_void_ptr_ulong_void_ptr **pp_Var5;
  LPSTR lpCmdLine;
  
  bVar1 = __scrt_initialize_crt(exe);
  if (!bVar1) {
                    /* WARNING: Subroutine does not return */
    __scrt_fastfail(7);
  }
  bVar1 = false;
  bVar2 = __scrt_acquire_startup_lock();
  if (__scrt_current_native_startup_state == initializing) {
                    /* WARNING: Subroutine does not return */
    __scrt_fastfail(7);
  }
  if (__scrt_current_native_startup_state == uninitialized) {
    __scrt_current_native_startup_state = initializing;
    iVar4 = _initterm_e(&__xi_a,&__xi_z);
    if (iVar4 != 0) {
      return 0xff;
    }
    _initterm(&__xc_a);
    __scrt_current_native_startup_state = initialized;
  }
  else {
    bVar1 = true;
  }
  __scrt_release_startup_lock(bVar2);
  pp_Var5 = __scrt_get_dyn_tls_init_callback();
  if ((*pp_Var5 != (_func___cdecl_void_void_ptr_ulong_void_ptr *)0x0) &&
     (bVar2 = __scrt_is_nonwritable_in_current_image(pp_Var5), bVar2)) {
    (*(code *)__guard_dispatch_icall_fptr)(0);
  }
  pp_Var5 = __scrt_get_dyn_tls_dtor_callback();
  if ((*pp_Var5 != (_func___cdecl_void_void_ptr_ulong_void_ptr *)0x0) &&
     (bVar2 = __scrt_is_nonwritable_in_current_image(pp_Var5), bVar2)) {
    _register_thread_local_exe_atexit_callback(*pp_Var5);
  }
  uVar3 = __scrt_get_show_window_mode();
  lpCmdLine = (LPSTR)_get_narrow_winmain_command_line();
  iVar4 = WinMain((HINSTANCE)&IMAGE_DOS_HEADER_140000000,(HINSTANCE)0x0,lpCmdLine,(uint)uVar3);
  bVar2 = __scrt_is_managed_app();
  if (bVar2) {
    if (!bVar1) {
      _cexit();
    }
    __scrt_uninitialize_crt(true,false);
    return iVar4;
  }
                    /* WARNING: Subroutine does not return */
  exit(iVar4);
}



/* 14000a79c WinMainCRTStartup */

int __cdecl WinMainCRTStartup(void)

{
  int iVar1;
  
  __security_init_cookie();
  iVar1 = __scrt_common_main_seh();
  return iVar1;
}



/* 14000a7b0 __GSHandlerCheck_SEH */

_EXCEPTION_DISPOSITION __cdecl
__GSHandlerCheck_SEH
          (_EXCEPTION_RECORD *param_1,void *param_2,_CONTEXT *param_3,_DISPATCHER_CONTEXT *param_4)

{
  uint uVar1;
  uint *puVar2;
  EXCEPTION_DISPOSITION EVar3;
  
  puVar2 = (uint *)param_4->HandlerData;
  uVar1 = *puVar2;
  __GSHandlerCheckCommon(param_2,param_4,(_GS_HANDLER_DATA *)(puVar2 + (ulonglong)uVar1 * 4 + 1));
  EVar3 = ExceptionContinueSearch;
  if ((puVar2[(ulonglong)uVar1 * 4 + 1] & ((param_1->ExceptionFlags & 0x66) != 0) + 1) != 0) {
    EVar3 = __C_specific_handler
                      ((_EXCEPTION_RECORD *)param_1,param_2,(_CONTEXT *)param_3,
                       (_DISPATCHER_CONTEXT *)param_4);
  }
  return EVar3;
}



/* 14000a838 __raise_securityfailure */

void __cdecl __raise_securityfailure(_EXCEPTION_POINTERS *param_1)

{
  HANDLE pvVar1;
  
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)param_1);
  pvVar1 = GetCurrentProcess();
                    /* WARNING: Could not recover jumptable at 0x00014000a865. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TerminateProcess(pvVar1,0xc0000409);
  return;
}



/* 14000a86c __report_gsfailure */

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
  capture_previous_context(&GS_ContextRecord);
  GS_ExceptionRecord.ExceptionAddress = *(void **)(puVar3 + 0x38);
  GS_ContextRecord.Rsp = (ulong64)(puVar3 + 0x40);
  GS_ContextRecord.Rcx = *(ulong64 *)(puVar3 + 0x40);
  GS_ExceptionRecord.ExceptionCode = 0xc0000409;
  GS_ExceptionRecord.ExceptionFlags = 1;
  GS_ExceptionRecord.NumberParameters = 1;
  GS_ExceptionRecord.ExceptionInformation[0] = 2;
  *(ulong64 *)(puVar3 + 0x20) = __security_cookie;
  *(ulong64 *)(puVar3 + 0x28) = __security_cookie_complement;
                    /* WARNING: Subroutine does not return */
  *(undefined **)(puVar3 + -8) = &UNK_14000a938;
  GS_ContextRecord.Rip = (ulong64)GS_ExceptionRecord.ExceptionAddress;
  __raise_securityfailure(&GS_ExceptionPointers);
}



/* 14000a940 capture_previous_context */

void __cdecl capture_previous_context(_CONTEXT *param_1)

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
    RtlVirtualUnwind(0,local_res8,ControlPc,FunctionEntry,(PCONTEXT)param_1,local_res18,&local_res10
                     ,(PKNONVOLATILE_CONTEXT_POINTERS)0x0);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
  return;
}



/* 14000a9b4 __isa_available_init */

/* WARNING: Removing unreachable block (ram,0x00014000aa82) */
/* WARNING: Removing unreachable block (ram,0x00014000aa00) */
/* WARNING: Removing unreachable block (ram,0x00014000a9db) */

int __cdecl __isa_available_init(void)

{
  int *piVar1;
  uint *puVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  byte in_XCR0;
  
  __isa_enabled = 2;
  __isa_available = 1;
  piVar1 = (int *)cpuid_basic_info(0);
  uVar6 = 0;
  puVar2 = (uint *)cpuid_Version_info(1);
  uVar4 = puVar2[3];
  if ((piVar1[1] == 0x756e6547 && piVar1[3] == 0x6c65746e) && piVar1[2] == 0x49656e69) {
    __memcpy_nt_iters = -1;
    uVar5 = *puVar2 & 0xfff3ff0;
    if ((((uVar5 == 0x106c0) || (uVar5 == 0x20660)) || (uVar5 == 0x20670)) ||
       ((uVar5 - 0x30650 < 0x21 &&
        ((0x100010001U >> ((ulonglong)(uVar5 - 0x30650) & 0x3f) & 1) != 0)))) {
      __favor = __favor | 1;
    }
  }
  if (6 < *piVar1) {
    lVar3 = cpuid_Extended_Feature_Enumeration_info(7);
    uVar6 = *(uint *)(lVar3 + 4);
    if ((uVar6 >> 9 & 1) != 0) {
      __favor = __favor | 2;
    }
  }
  if ((uVar4 >> 0x14 & 1) != 0) {
    __isa_available = 2;
    __isa_enabled = 6;
    if ((((uVar4 >> 0x1b & 1) != 0) && ((uVar4 >> 0x1c & 1) != 0)) && ((in_XCR0 & 6) == 6)) {
      __isa_enabled = 0xe;
      __isa_available = 3;
      if ((uVar6 & 0x20) != 0) {
        __isa_available = 5;
        __isa_enabled = 0x2e;
      }
    }
  }
  return 0;
}



/* 14000ab30 _get_startup_argv_mode */

_crt_argv_mode __cdecl _get_startup_argv_mode(void)

{
  return _crt_argv_unexpanded_arguments;
}



/* 14000ab38 __scrt_is_ucrt_dll_in_use */

int __cdecl __scrt_is_ucrt_dll_in_use(void)

{
  return (int)(__scrt_ucrt_dll_is_in_use != 0);
}



/* 14000ab44 __crt_debugger_hook */

void __cdecl __crt_debugger_hook(int param_1)

{
  __scrt_debugger_hook_flag = 0;
  return;
}



/* 14000ab4c __scrt_fastfail */

void __cdecl __scrt_fastfail(uint param_1)

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
  __crt_debugger_hook(3);
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
    __crt_debugger_hook(3);
  }
  return;
}



/* 14000ac98 __scrt_get_show_window_mode */

ushort __cdecl __scrt_get_show_window_mode(void)

{
  ushort uVar1;
  _STARTUPINFOW local_78;
  
  memset(&local_78,0,0x68);
  GetStartupInfoW(&local_78);
  uVar1 = 10;
  if (((byte)local_78.dwFlags & 1) != 0) {
    uVar1 = local_78.wShowWindow;
  }
  return uVar1;
}



/* 14000acd4 __scrt_initialize_mta */

int __cdecl __scrt_initialize_mta(void)

{
  return 0;
}



/* 14000acdc __scrt_is_managed_app */

bool __cdecl __scrt_is_managed_app(void)

{
  bool bVar1;
  HMODULE pHVar2;
  int *piVar3;
  
  pHVar2 = GetModuleHandleW((LPCWSTR)0x0);
  if ((((pHVar2 == (HMODULE)0x0) || ((short)pHVar2->unused != 0x5a4d)) ||
      (piVar3 = (int *)((longlong)&pHVar2->unused + (longlong)pHVar2[0xf].unused), *piVar3 != 0x4550
      )) || ((((short)piVar3[6] != 0x20b || ((uint)piVar3[0x21] < 0xf)) || (piVar3[0x3e] == 0)))) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}



/* 14000ad30 __scrt_set_unhandled_exception_filter */

void __cdecl __scrt_set_unhandled_exception_filter(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000ad37. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetUnhandledExceptionFilter(__scrt_unhandled_exception_filter);
  return;
}



/* 14000ad40 __scrt_unhandled_exception_filter */

long __cdecl __scrt_unhandled_exception_filter(_EXCEPTION_POINTERS *param_1)

{
  int iVar1;
  _EXCEPTION_RECORD *p_Var2;
  
  p_Var2 = param_1->ExceptionRecord;
  if ((p_Var2->ExceptionCode == 0xe06d7363) && (p_Var2->NumberParameters == 4)) {
    iVar1 = (int)p_Var2->ExceptionInformation[0];
    if ((iVar1 + 0xe66cfae0U < 3) || (iVar1 == 0x1994000)) {
                    /* WARNING: Subroutine does not return */
      terminate();
    }
  }
  return 0;
}



/* 14000ad78 __security_init_cookie */

void __cdecl __security_init_cookie(void)

{
  DWORD DVar1;
  _FILETIME local_res8;
  _FILETIME local_res10;
  LARGE_INTEGER local_res18;
  
  if (__security_cookie == 0x2b992ddfa232) {
    local_res10.dwLowDateTime = 0;
    local_res10.dwHighDateTime = 0;
    GetSystemTimeAsFileTime(&local_res10);
    local_res8 = local_res10;
    DVar1 = GetCurrentThreadId();
    local_res8 = (_FILETIME)((ulonglong)local_res8 ^ (ulonglong)DVar1);
    DVar1 = GetCurrentProcessId();
    local_res8 = (_FILETIME)((ulonglong)local_res8 ^ (ulonglong)DVar1);
    QueryPerformanceCounter(&local_res18);
    __security_cookie =
         ((ulonglong)local_res18.s.LowPart << 0x20 ^
          CONCAT44(local_res18.s.HighPart,local_res18.s.LowPart) ^ (ulonglong)local_res8 ^
         (ulonglong)&local_res8) & 0xffffffffffff;
    if (__security_cookie == 0x2b992ddfa232) {
      __security_cookie = 0x2b992ddfa233;
    }
  }
  __security_cookie_complement = ~__security_cookie;
  return;
}



/* 14000ae24 _get_startup_file_mode */

int __cdecl _get_startup_file_mode(void)

{
  return 0x4000;
}



/* 14000ae2c __scrt_initialize_type_info */

void __cdecl __scrt_initialize_type_info(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000ae33. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InitializeSListHead(&__type_info_root_node);
  return;
}



/* 14000ae3c _should_initialize_environment */

bool __cdecl _should_initialize_environment(void)

{
  return true;
}



/* 14000ae40 __local_stdio_scanf_options */

ulong64 * __cdecl __local_stdio_scanf_options(void)

{
  return &`__local_stdio_scanf_options'::__l2::_OptionsStorage;
}



/* 14000ae48 __scrt_initialize_default_local_stdio_options */

void __cdecl __scrt_initialize_default_local_stdio_options(void)

{
  ulong64 *puVar1;
  
  puVar1 = __local_stdio_printf_options();
  *puVar1 = *puVar1 | 4;
  puVar1 = __local_stdio_scanf_options();
  *puVar1 = *puVar1 | 2;
  return;
}



/* 14000ae64 __scrt_is_user_matherr_present */

int __cdecl __scrt_is_user_matherr_present(void)

{
  return (int)(__scrt_default_matherr == 0);
}



/* 14000ae70 __scrt_get_dyn_tls_init_callback */

_func___cdecl_void_void_ptr_ulong_void_ptr ** __cdecl __scrt_get_dyn_tls_init_callback(void)

{
  return &__dyn_tls_init_callback;
}



/* 14000ae78 __scrt_get_dyn_tls_dtor_callback */

_func___cdecl_void_void_ptr_ulong_void_ptr ** __cdecl __scrt_get_dyn_tls_dtor_callback(void)

{
  return &__dyn_tls_dtor_callback;
}



/* 14000ae80 _RTC_Initialize */

void __cdecl _RTC_Initialize(void)

{
  _func___cdecl_void **pp_Var1;
  
  for (pp_Var1 = __rtc_izz; pp_Var1 < __rtc_izz; pp_Var1 = pp_Var1 + 1) {
    if (*pp_Var1 != (_func___cdecl_void *)0x0) {
      (*(code *)__guard_dispatch_icall_fptr)();
    }
  }
  return;
}



/* 14000aebc _RTC_Terminate */

void __cdecl _RTC_Terminate(void)

{
  _func___cdecl_void **pp_Var1;
  
  for (pp_Var1 = __rtc_tzz; pp_Var1 < __rtc_tzz; pp_Var1 = pp_Var1 + 1) {
    if (*pp_Var1 != (_func___cdecl_void *)0x0) {
      (*(code *)__guard_dispatch_icall_fptr)();
    }
  }
  return;
}



/* 14000aef8 __GSHandlerCheck */

_EXCEPTION_DISPOSITION __cdecl
__GSHandlerCheck(_EXCEPTION_RECORD *param_1,void *param_2,_CONTEXT *param_3,
                _DISPATCHER_CONTEXT *param_4)

{
  __GSHandlerCheckCommon(param_2,param_4,(_GS_HANDLER_DATA *)param_4->HandlerData);
  return ExceptionContinueSearch;
}



/* 14000af18 __GSHandlerCheckCommon */

void __cdecl
__GSHandlerCheckCommon(void *param_1,_DISPATCHER_CONTEXT *param_2,_GS_HANDLER_DATA *param_3)

{
  ulonglong uVar1;
  void *pvVar2;
  
  pvVar2 = param_1;
  if (((byte)param_3->u & 4) != 0) {
    pvVar2 = (void *)((longlong)param_3->AlignedBaseOffset + (longlong)param_1 &
                     (longlong)-param_3->Alignment);
  }
  uVar1 = (ulonglong)param_2->FunctionEntry->UnwindData;
  if ((*(byte *)(uVar1 + 3 + param_2->ImageBase) & 0xf) != 0) {
    param_1 = (void *)((longlong)param_1 +
                      (ulonglong)(*(byte *)(uVar1 + 3 + param_2->ImageBase) & 0xfffffff0));
  }
  __security_check_cookie
            ((ulonglong)param_1 ^
             *(ulonglong *)((longlong)(int)(*(uint *)param_3 & 0xfffffff8) + (longlong)pvVar2));
  return;
}



/* 14000af88 CAtlBaseModule */

CAtlBaseModule * __thiscall ATL::CAtlBaseModule::CAtlBaseModule(CAtlBaseModule *this)

{
  DWORD DVar1;
  BOOL BVar2;
  DWORD DVar3;
  
  memset(&this->field_0x28,0,0x28);
  *(undefined8 *)&this->field_0x50 = 0;
  *(undefined4 *)&this->field_0x58 = 0;
  *(undefined4 *)&this->field_0x5c = 0;
  *(IMAGE_DOS_HEADER **)&this->field_0x10 = &IMAGE_DOS_HEADER_140000000;
  *(IMAGE_DOS_HEADER **)&this->field_0x8 = &IMAGE_DOS_HEADER_140000000;
  *(_GUID **)&this->field_0x20 = &GUID_ATLVer110;
  *(undefined4 *)this = 0x60;
  *(undefined4 *)&this->field_0x18 = 0xe00;
  BVar2 = _AtlInitializeCriticalSectionEx((LPCRITICAL_SECTION)&this->field_0x28,0,0);
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
      m_bInitFailed = true;
    }
  }
  return this;
}



/* 14000b030 ~CAtlBaseModule */

void __thiscall ATL::CAtlBaseModule::~CAtlBaseModule(CAtlBaseModule *this)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&this->field_0x28);
  if (*(void **)&this->field_0x50 != (void *)0x0) {
    free(*(void **)&this->field_0x50);
    *(undefined8 *)&this->field_0x50 = 0;
  }
  *(undefined4 *)&this->field_0x58 = 0;
  *(undefined4 *)&this->field_0x5c = 0;
  return;
}



/* 14000b108 AfxInitialize */

int __cdecl AfxInitialize(int param_1,ulong param_2)

{
  AFX_MODULE_STATE *pAVar1;
  
  pAVar1 = AfxGetModuleState();
  pAVar1->m_bDLL = (uchar)param_1;
  pAVar1->m_dwVersion = param_2;
  if (param_1 == 0) {
    _setmbcp(-3);
  }
  return 1;
}



/* 14000b140 WinMain */

int __stdcall WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000b145. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = AfxWinMain(hInstance,hPrevInstance,lpCmdLine,nShowCmd);
  return iVar1;
}



/* 14000b145 AfxWinMain */

/* int __cdecl AfxWinMain(struct HINSTANCE__ * __ptr64,struct HINSTANCE__ * __ptr64,char *
   __ptr64,int) */

int __cdecl AfxWinMain(HINSTANCE__ *param_1,HINSTANCE__ *param_2,char *param_3,int param_4)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000b145. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = AfxWinMain(param_1,param_2,param_3,param_4);
  return iVar1;
}



/* 14000b14c __GSHandlerCheck_EH */

_EXCEPTION_DISPOSITION __cdecl
__GSHandlerCheck_EH(_EXCEPTION_RECORD *param_1,void *param_2,_CONTEXT *param_3,
                   _DISPATCHER_CONTEXT *param_4)

{
  void *pvVar1;
  
  pvVar1 = param_4->HandlerData;
  __GSHandlerCheckCommon(param_2,param_4,(_GS_HANDLER_DATA *)((longlong)pvVar1 + 4));
  if ((*(uint *)((longlong)pvVar1 + 4) & ((param_1->ExceptionFlags & 0x66) != 0) + 1) != 0) {
                    /* WARNING: Subroutine does not return */
    __CxxFrameHandler3(param_1,param_2,param_3,param_4);
  }
  return ExceptionContinueSearch;
}



/* 14000b1e0 __chkstk */

/* WARNING: This is an inlined function */

void __cdecl __chkstk(void)

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



/* 14000b260 _guard_dispatch_icall_nop */

void __cdecl _guard_dispatch_icall_nop(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014000b260. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



/* 14000b270 dtor$0 */

void `CDSPIApp::InitInstance'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  CObject::operator_delete(*(void **)(param_2 + 0x30));
  return;
}



/* 14000b27c dtor$1 */

void `CDSPIApp::InitInstance'::__l1::dtor_1(undefined8 param_1,longlong param_2)

{
  CDSPIDlg::~CDSPIDlg((CDSPIDlg *)(param_2 + 0x40));
  return;
}



/* 14000b290 catch$1 */

undefined8 `CGdiObject::~CGdiObject'::__l1::catch_1(undefined8 param_1,longlong param_2)

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



/* 14000b346 dtor$0 */

void `CGdiObject::~CGdiObject'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b34d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_2 + 0x30));
  return;
}



/* 14000b360 dtor$0 */

void `CnComm::Write'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  CnComm::BlockBuffer::InnerLock::~InnerLock((InnerLock *)(param_2 + 0x78));
  return;
}



/* 14000b370 dtor$0 */

void `CnComm::PortToBuffer'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  CnComm::BlockBuffer::InnerLock::~InnerLock((InnerLock *)(param_2 + 0x40));
  return;
}



/* 14000b380 dtor$0 */

void `CDSPIDlg::CDSPIDlg'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  CDialogEx::~CDialogEx(*(CDialogEx **)(param_2 + 0x50));
  return;
}



/* 14000b38c dtor$1 */

void `CDSPIDlg::CDSPIDlg'::__l1::dtor_1(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b39a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CComboBox::~CComboBox((CComboBox *)(*(longlong *)(param_2 + 0x50) + 0xa48));
  return;
}



/* 14000b3a1 dtor$2 */

void `CDSPIDlg::CDSPIDlg'::__l1::dtor_2(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b3af. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CSliderCtrl::~CSliderCtrl((CSliderCtrl *)(*(longlong *)(param_2 + 0x50) + 0xb30));
  return;
}



/* 14000b3b6 dtor$3 */

void `CDSPIDlg::CDSPIDlg'::__l1::dtor_3(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b3c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (*(longlong *)(param_2 + 0x50) + 0xc18));
  return;
}



/* 14000b3cb dtor$4 */

void `CDSPIDlg::CDSPIDlg'::__l1::dtor_4(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b3d9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CSliderCtrl::~CSliderCtrl((CSliderCtrl *)(*(longlong *)(param_2 + 0x50) + 0xc20));
  return;
}



/* 14000b3e0 dtor$5 */

void `CDSPIDlg::CDSPIDlg'::__l1::dtor_5(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b3ee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (*(longlong *)(param_2 + 0x50) + 0xd08));
  return;
}



/* 14000b3f5 dtor$6 */

void `CDSPIDlg::CDSPIDlg'::__l1::dtor_6(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b403. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CToolTipCtrl::~CToolTipCtrl((CToolTipCtrl *)(*(longlong *)(param_2 + 0x50) + 0xd10));
  return;
}



/* 14000b40a dtor$7 */

void `CDSPIDlg::CDSPIDlg'::__l1::dtor_7(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b418. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CStatic::~CStatic((CStatic *)(*(longlong *)(param_2 + 0x50) + 0xe38));
  return;
}



/* 14000b41f dtor$8 */

void `CDSPIDlg::CDSPIDlg'::__l1::dtor_8(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b42d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CStatic::~CStatic((CStatic *)(*(longlong *)(param_2 + 0x50) + 0xf20));
  return;
}



/* 14000b434 dtor$9 */

void `CDSPIDlg::CDSPIDlg'::__l1::dtor_9(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b442. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CStatic::~CStatic((CStatic *)(*(longlong *)(param_2 + 0x50) + 0x1008));
  return;
}



/* 14000b449 dtor$10 */

void `CDSPIDlg::CDSPIDlg'::__l1::dtor_10(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b457. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CSliderCtrl::~CSliderCtrl((CSliderCtrl *)(*(longlong *)(param_2 + 0x50) + 0x10f0));
  return;
}



/* 14000b45e dtor$11 */

void `CDSPIDlg::CDSPIDlg'::__l1::dtor_11(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b46c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (*(longlong *)(param_2 + 0x50) + 0x11d8));
  return;
}



/* 14000b473 dtor$12 */

void `CDSPIDlg::CDSPIDlg'::__l1::dtor_12(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b481. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (*(longlong *)(param_2 + 0x50) + 0x11e0));
  return;
}



/* 14000b490 dtor$0 */

void `CDSPIDlg::OnInitDialog'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b497. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_2 + 0x78));
  return;
}



/* 14000b4a0 dtor$0 */

void `CDSPIDlg::OnSysCommand'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  CDialogEx::~CDialogEx((CDialogEx *)(param_2 + 0x30));
  return;
}



/* 14000b4b0 dtor$0 */

void `CDSPIDlg::OnBnClickedBtnOpen'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b4b7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CFileDialog::~CFileDialog((CFileDialog *)(param_2 + 0xc0));
  return;
}



/* 14000b4be dtor$1 */

void `CDSPIDlg::OnBnClickedBtnOpen'::__l1::dtor_1(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b4c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_2 + 0x50));
  return;
}



/* 14000b4cc dtor$2 */

void `CDSPIDlg::OnBnClickedBtnOpen'::__l1::dtor_2(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b4d3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_2 + 0x58));
  return;
}



/* 14000b4da dtor$3 */

void `CDSPIDlg::OnBnClickedBtnOpen'::__l1::dtor_3(undefined8 param_1,longlong param_2)

{
  ImgDIB::~ImgDIB((ImgDIB *)(param_2 + 0x60));
  return;
}



/* 14000b4f0 dtor$0 */

void `CDSPIDlg::OnBnClickedBtnSave'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b4f7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_2 + 0x58));
  return;
}



/* 14000b4fe dtor$1 */

void `CDSPIDlg::OnBnClickedBtnSave'::__l1::dtor_1(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b505. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_2 + 0x50));
  return;
}



/* 14000b50c dtor$2 */

void `CDSPIDlg::OnBnClickedBtnSave'::__l1::dtor_2(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b513. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CFileDialog::~CFileDialog((CFileDialog *)(param_2 + 0x70));
  return;
}



/* 14000b51a dtor$3 */

void `CDSPIDlg::OnBnClickedBtnSave'::__l1::dtor_3(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b521. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_2 + 0x60));
  return;
}



/* 14000b528 dtor$4 */

void `CDSPIDlg::OnBnClickedBtnSave'::__l1::dtor_4(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b52f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_2 + 0x50));
  return;
}



/* 14000b536 dtor$5 */

void `CDSPIDlg::OnBnClickedBtnSave'::__l1::dtor_5(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b53d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CFileDialog::~CFileDialog((CFileDialog *)(param_2 + 0x70));
  return;
}



/* 14000b544 dtor$6 */

void `CDSPIDlg::OnBnClickedBtnSave'::__l1::dtor_6(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b54b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_2 + 0x60));
  return;
}



/* 14000b552 dtor$7 */

void `CDSPIDlg::OnBnClickedBtnSave'::__l1::dtor_7(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b559. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CFileDialog::~CFileDialog((CFileDialog *)(param_2 + 0x70));
  return;
}



/* 14000b560 dtor$8 */

void `CDSPIDlg::OnBnClickedBtnSave'::__l1::dtor_8(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b567. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             (param_2 + 0x60));
  return;
}



/* 14000b570 dtor$0 */

void `CDSPIDlg::SaveDataToBMPFile'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b577. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CFile::~CFile((CFile *)(param_2 + 0x20));
  return;
}



/* 14000b57e catch$1 */

undefined * `CDSPIDlg::SaveDataToBMPFile'::__l1::catch_1(undefined8 param_1,longlong param_2)

{
  CException::Delete(*(CException **)(param_2 + 0x50));
  AfxMessageBox(s_______________,0,0);
  return &DAT_140005265;
}



/* 14000b5c0 dtor$0 */
/* decompilation failed: 
Low-level Error: Field field0_0x0 does not fit in structure _OVERLAPPED */

/* 14000b5d0 dtor$0 */

void `CDSPIDlg::OnBnClickedBtnFilter'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  FunDIB::~FunDIB((FunDIB *)(param_2 + 0x40));
  return;
}



/* 14000b5e0 dtor$0 */

void `CDSPIDlg::OnBnClickedBtnDspi'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  ATL::CImage::~CImage((CImage *)(param_2 + 0x50));
  return;
}



/* 14000b5f0 filt$0 */

bool `ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable'::__l1::filt_0(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3fffff03;
}



/* 14000b620 dtor$0 */

void `ImgDIB::Read'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b627. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CFile::~CFile((CFile *)(param_2 + 0x38));
  return;
}



/* 14000b62e dtor$1 */

void `ImgDIB::Read'::__l1::dtor_1(undefined8 param_1,longlong param_2)

{
  CObject::operator_delete(*(void **)(param_2 + 0x30));
  return;
}



/* 14000b63a dtor$2 */

void `ImgDIB::Read'::__l1::dtor_2(undefined8 param_1,longlong param_2)

{
  CObject::operator_delete(*(void **)(param_2 + 0x30));
  return;
}



/* 14000b646 catch$3 */

undefined8 `ImgDIB::Read'::__l1::catch_3(undefined8 param_1,longlong param_2)

{
  AfxMessageBox(s_Read_error_Only_for_BMP_file__,0x30,0);
  CException::Delete(*(CException **)(param_2 + 0x68));
  return 0x1400097de;
}



/* 14000b680 __scrt_is_nonwritable_in_current_image$filt$0 */

bool __scrt_is_nonwritable_in_current_image_filt_0(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* 14000b698 filt$0 */

void `__scrt_common_main_seh'::__l1::filt_0(undefined8 *param_1)

{
  _seh_filter_exe(*(undefined4 *)*param_1,param_1);
  return;
}



/* 14000b6c0 `dynamic_atexit_destructor_for_'theApp'' */

void __cdecl _dynamic_atexit_destructor_for__theApp__(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b6c7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CWinApp::~CWinApp((CWinApp *)&theApp);
  return;
}



/* 14000b6d0 `dynamic_atexit_destructor_for_'desripHolo'' */

void __cdecl _dynamic_atexit_destructor_for__desripHolo__(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b6d7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             &desripHolo);
  return;
}



/* 14000b6e0 `dynamic_atexit_destructor_for_'desripShearo'' */

void __cdecl _dynamic_atexit_destructor_for__desripShearo__(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b6e7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>::
  ~CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_>
            ((CStringT<char,class_StrTraitMFC_DLL<char,class_ATL::ChTraitsCRT<char>_>_> *)
             &desripShearo);
  return;
}



/* 14000b6f0 `dynamic_atexit_destructor_for_'cache'' */

void __cdecl `ATL::CImage::GetCDCCacheInstance'::__l2::_dynamic_atexit_destructor_for__cache__(void)

{
  CDCCache *pCVar1;
  longlong lVar2;
  
  pCVar1 = &`private:_static_class_ATL::CImage::CDCCache*___ptr64___cdecl_ATL::CImage::GetCDCCacheInstance(void)'
            ::__l2::cache;
  lVar2 = 4;
  do {
    if (*(HDC *)pCVar1 != (HDC)0x0) {
      DeleteDC(*(HDC *)pCVar1);
    }
    pCVar1 = (CDCCache *)((longlong)pCVar1 + 8);
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  return;
}



/* 14000b730 `dynamic_atexit_destructor_for_'gdiPlus'' */

void __cdecl
`ATL::CImage::GetInitGDIPlusInstance'::__l2::_dynamic_atexit_destructor_for__gdiPlus__(void)

{
  EnterCriticalSection
            ((LPCRITICAL_SECTION)
             &`private:_static_class_ATL::CImage::CInitGDIPlus*___ptr64___cdecl_ATL::CImage::GetInitGDIPlusInstance(void)'
              ::__l2::gdiPlus.m_sect);
  if (`private:_static_class_ATL::CImage::CInitGDIPlus*___ptr64___cdecl_ATL::CImage::GetInitGDIPlusInstance(void)'
      ::__l2::gdiPlus.m_dwToken != 0) {
    GdiplusShutdown();
  }
  `private:_static_class_ATL::CImage::CInitGDIPlus*___ptr64___cdecl_ATL::CImage::GetInitGDIPlusInstance(void)'
  ::__l2::gdiPlus.m_dwToken = 0;
                    /* WARNING: Could not recover jumptable at 0x00014000b769. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LeaveCriticalSection
            ((LPCRITICAL_SECTION)
             &`private:_static_class_ATL::CImage::CInitGDIPlus*___ptr64___cdecl_ATL::CImage::GetInitGDIPlusInstance(void)'
              ::__l2::gdiPlus.m_sect);
  return;
}



/* 14000b770 `dynamic_atexit_destructor_for_'_AtlBaseModule'' */

void __cdecl ATL::_dynamic_atexit_destructor_for___AtlBaseModule__(void)

{
  CAtlBaseModule::~CAtlBaseModule(&_AtlBaseModule);
  return;
}


