
/* 00401180 FUN_00401180 */

/* WARNING: Unable to track spacebase fully for stack */

undefined4 FUN_00401180(void)

{
  char cVar1;
  undefined4 uVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  char *pcVar8;
  size_t sVar9;
  void *pvVar10;
  bool bVar11;
  int iVar12;
  undefined4 extraout_EDX;
  DWORD *pDVar13;
  DWORD *pDVar14;
  DWORD *pDVar15;
  undefined4 *puVar16;
  undefined4 *puVar17;
  int unaff_FS_OFFSET;
  undefined1 auStack_8c [20];
  int local_78;
  undefined4 local_74;
  void *local_70;
  undefined4 local_60 [11];
  byte local_34;
  ushort local_30;
  
  puVar6 = local_60;
  for (iVar12 = 0x11; iVar12 != 0; iVar12 = iVar12 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  uVar5 = FUN_00405e28();
  puVar6 = (undefined4 *)((int)&local_74 + -uVar5 + 3 & 0xfffffff0);
  *puVar6 = 0xcccccccc;
  puVar6[1] = 0xcccccccc;
  puVar6[2] = 0xcccccccc;
  puVar6[3] = 0xcccccccc;
  puVar6[4] = 0xcccccccc;
  puVar6[5] = 0xcccccccc;
  puVar6[6] = 0xcccccccc;
  puVar6[7] = 0xcccccccc;
  pDVar13 = (DWORD *)((uint)(auStack_8c + -uVar5) & 0xfffffff0);
  if (DAT_0040d458 != 0) {
    *pDVar13 = extraout_EDX;
    puVar17 = pDVar13 + -1;
    pDVar13[-1] = 0x401479;
    GetStartupInfoA((LPSTARTUPINFOA)*pDVar13);
    pDVar13 = (DWORD *)((int)puVar17 + -4);
  }
  iVar12 = *(int *)(*(int *)(unaff_FS_OFFSET + 0x18) + 4);
  while( true ) {
    iVar7 = 0;
    LOCK();
    iVar4 = iVar12;
    if (DAT_0040d4ac != 0) {
      iVar7 = DAT_0040d4ac;
      iVar4 = DAT_0040d4ac;
    }
    DAT_0040d4ac = iVar4;
    UNLOCK();
    if (iVar7 == 0) {
      bVar11 = false;
      goto joined_r0x0040141e;
    }
    if (iVar7 == iVar12) break;
    *pDVar13 = 1000;
    pDVar14 = pDVar13 + -1;
    pDVar13[-1] = 0x401213;
    Sleep(*pDVar13);
    pDVar13 = (DWORD *)((int)pDVar14 + -4);
  }
  bVar11 = true;
joined_r0x0040141e:
  if (DAT_0040d4b0 == 1) {
    *pDVar13 = 0x1f;
    pDVar13[-1] = 0x401430;
    _amsg_exit(*pDVar13);
  }
  else if (DAT_0040d4b0 == 0) {
    DAT_0040d4b0 = 1;
    pDVar13[1] = (DWORD)&DAT_00412018;
    *pDVar13 = (DWORD)&DAT_0041200c;
    pDVar13[-1] = 0x40149f;
    initterm();
  }
  else {
    DAT_0040d004 = 1;
  }
  pcVar3 = (code *)PTR_tls_callback_0_00409f48;
  if (DAT_0040d4b0 == 1) {
    pDVar13[1] = (DWORD)&DAT_00412008;
    *pDVar13 = (DWORD)&DAT_00412000;
    pDVar13[-1] = 0x401452;
    initterm();
    DAT_0040d4b0 = 2;
    pcVar3 = (code *)PTR_tls_callback_0_00409f48;
  }
  if (!bVar11) {
    LOCK();
    UNLOCK();
    DAT_0040d4ac = 0;
  }
  PTR_tls_callback_0_00409f48 = pcVar3;
  if (pcVar3 != (code *)0x0) {
    pDVar13[2] = 0;
    pDVar13[1] = 2;
    *pDVar13 = 0;
    pDVar15 = pDVar13 + -1;
    pDVar13[-1] = 0x401283;
    (*pcVar3)();
    pDVar13 = (DWORD *)((int)pDVar15 + -0xc);
  }
  pDVar13[-1] = 0x40128b;
  FUN_00405060();
  *pDVar13 = 0x405320;
  puVar16 = pDVar13 + -1;
  pDVar13[-1] = 0x401298;
  DAT_0040d46c = SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)*pDVar13);
  puVar16[-1] = &LAB_00401000;
  puVar16[-2] = 0x4012ac;
  FUN_00405f70(puVar16[-1]);
  puVar16[-2] = 0x4012b1;
  FUN_00404e90();
  iVar12 = DAT_0040d01c;
  DAT_0040d49c = 0x400000;
  pcVar8 = *(char **)_acmdln_exref;
  if (pcVar8 != (char *)0x0) {
    bVar11 = false;
    do {
      cVar1 = *pcVar8;
      if (cVar1 < '!') {
        DAT_0040d498 = pcVar8;
        if (cVar1 == '\0') break;
        if (!bVar11) goto LAB_00401304;
        bVar11 = true;
      }
      else if (cVar1 == '\"') {
        bVar11 = (bool)(bVar11 ^ 1);
      }
      pcVar8 = pcVar8 + 1;
    } while( true );
  }
  goto LAB_00401314;
  while (*pcVar8 != '\0') {
LAB_00401304:
    pcVar8 = pcVar8 + 1;
    DAT_0040d498 = pcVar8;
    if (' ' < *pcVar8) break;
  }
LAB_00401314:
  if (DAT_0040d458 != 0) {
    DAT_00408000 = 10;
    if ((local_34 & 1) != 0) {
      DAT_00408000 = (uint)local_30;
    }
  }
  local_74 = DAT_0040d01c;
  local_78 = DAT_0040d01c * 4 + 4;
  puVar16[-1] = local_78;
  puVar16[-2] = 0x40134f;
  local_70 = malloc(puVar16[-1]);
  iVar7 = (int)DAT_0040d018;
  if (iVar12 < 1) {
    iVar12 = 0;
  }
  else {
    iVar12 = 0;
    do {
      puVar16[-1] = *(undefined4 *)(iVar7 + iVar12 * 4);
      puVar16[-2] = 0x40136f;
      sVar9 = strlen((char *)puVar16[-1]);
      puVar16[-1] = sVar9 + 1;
      puVar16[-2] = 0x40137a;
      pvVar10 = malloc(puVar16[-1]);
      *(void **)((int)local_70 + iVar12 * 4) = pvVar10;
      uVar2 = *(undefined4 *)(iVar7 + iVar12 * 4);
      iVar12 = iVar12 + 1;
      puVar16[1] = sVar9 + 1;
      puVar16[-1] = pvVar10;
      *puVar16 = uVar2;
      puVar16[-2] = 0x401396;
      memcpy((void *)puVar16[-1],(void *)*puVar16,puVar16[1]);
    } while (iVar12 != local_74);
    iVar12 = local_78 + -4;
  }
  *(undefined4 *)((int)local_70 + iVar12) = 0;
  DAT_0040d018 = local_70;
  puVar16[-2] = 0x4013b6;
  FUN_00404b70();
  *(undefined4 *)__initenv_exref = DAT_0040d014;
  puVar16[1] = DAT_0040d014;
  *puVar16 = DAT_0040d018;
  puVar16[-1] = DAT_0040d01c;
  puVar16[-2] = 0x4013e2;
  DAT_0040d00c = FUN_00406d30();
  if (DAT_0040d008 != 0) {
    if (DAT_0040d004 == 0) {
      puVar16[-2] = 0x401404;
      _cexit();
    }
    return DAT_0040d00c;
  }
  puVar16[-1] = DAT_0040d00c;
                    /* WARNING: Subroutine does not return */
  puVar16[-2] = &UNK_004014b3;
  exit(puVar16[-1]);
}



/* 004014c0 entry */

void entry(void)

{
  DAT_0040d458 = 1;
  FUN_00404bb0();
  FUN_00401180();
  return;
}



/* 004016c0 FUN_004016c0 */

undefined4 __cdecl FUN_004016c0(undefined4 param_1,char **param_2)

{
  QArrayData *pQVar1;
  uint uVar2;
  undefined4 uVar3;
  QApplication local_4c [8];
  QMainWindow local_44 [24];
  HWND local_2c;
  
  QApplication::QApplication(local_4c,&param_1,param_2,0x50a01);
  FUN_00405f90("pzt.qml",1,0,&DAT_00409064);
  FUN_00401a50(local_44,0);
  pQVar1 = (QArrayData *)QString::fromAscii_helper(&DAT_00409070,0x1e);
  QWidget::setWindowTitle((QString *)&stack0xffffffb0);
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_0040175d;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_0040175d;
  }
  QArrayData::deallocate(pQVar1,2,4);
LAB_0040175d:
  uVar2 = GetWindowLongW(local_2c,-0x10);
  SetWindowLongW(local_2c,-0x10,uVar2 & 0xfffeffff);
  QWidget::show();
  uVar3 = QApplication::exec();
  FUN_00402560(local_44);
  QApplication::~QApplication(local_4c);
  return uVar3;
}



/* 00401890 FUN_00401890 */

void __fastcall FUN_00401890(int param_1)

{
  QArrayData *local_30;
  QArrayData *local_2c [7];
  
  local_2c[0] = (QArrayData *)QString::fromAscii_helper(&DAT_00409090,0x15);
  local_30 = (QArrayData *)QString::fromAscii_helper(&DAT_004090a6,6);
  QMessageBox::critical(param_1,&local_30,(QVariant *)local_2c,0x400,0);
  if (*(int *)local_30 == 0) {
LAB_004019f0:
    QArrayData::deallocate(local_30,2,4);
  }
  else if (*(int *)local_30 != -1) {
    LOCK();
    *(int *)local_30 = *(int *)local_30 + -1;
    UNLOCK();
    if (*(int *)local_30 == 0) goto LAB_004019f0;
  }
  if (*(int *)local_2c[0] == 0) {
LAB_004019b0:
    QArrayData::deallocate(local_2c[0],2,4);
  }
  else if (*(int *)local_2c[0] != -1) {
    LOCK();
    *(int *)local_2c[0] = *(int *)local_2c[0] + -1;
    UNLOCK();
    if (*(int *)local_2c[0] == 0) goto LAB_004019b0;
  }
  local_2c[0] = (QArrayData *)QString::fromAscii_helper("switchObject",0xc);
  qt_qFindChild_helper
            (*(undefined4 *)(param_1 + 0x30),(QVariant *)local_2c,staticMetaObject_exref,1);
  if (*(int *)local_2c[0] != 0) {
    if (*(int *)local_2c[0] == -1) goto LAB_00401974;
    LOCK();
    *(int *)local_2c[0] = *(int *)local_2c[0] + -1;
    UNLOCK();
    if (*(int *)local_2c[0] != 0) goto LAB_00401974;
  }
  QArrayData::deallocate(local_2c[0],2,4);
LAB_00401974:
  QVariant::QVariant((QVariant *)local_2c,false);
  QObject::setProperty("checked",(QVariant *)local_2c);
  QVariant::~QVariant((QVariant *)local_2c);
  return;
}



/* 00401a50 FUN_00401a50 */

void __thiscall FUN_00401a50(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  QAction *pQVar3;
  QWidget *pQVar4;
  QGridLayout *this_00;
  QQuickWidget *this_01;
  QMenuBar *this_02;
  QMenu *this_03;
  QToolBar *this_04;
  QStatusBar *this_05;
  HWND hWnd;
  HDC pHVar5;
  undefined4 uVar6;
  void *pvStack00000058;
  char *pcStack0000005c;
  undefined4 uStack00000060;
  code *pcVar7;
  code *pcVar8;
  QString *pQVar9;
  QRect *pQVar10;
  QRect *pQVar11;
  QArrayData *in_stack_ffffffbc;
  QArrayData *pQVar12;
  QArrayData *pQVar13;
  QArrayData *pQVar14;
  QArrayData *pQVar15;
  QArrayData *pQVar16;
  
  QMainWindow::QMainWindow((QMainWindow *)this,param_1,0);
  *(undefined ***)this = &PTR_LAB_0040a288;
  *(undefined ***)((int)this + 8) = &PTR_LAB_0040a364;
  QQmlEngine::QQmlEngine((QQmlEngine *)((int)this + 0x20),(QObject *)0x0);
  puVar2 = (undefined4 *)operator_new(0x20);
  *(undefined4 **)((int)this + 0x34) = puVar2;
  QObject::objectName();
  iVar1 = *(int *)(in_stack_ffffffbc + 4);
  if (*(int *)in_stack_ffffffbc == 0) {
LAB_00402230:
    QArrayData::deallocate(in_stack_ffffffbc,2,4);
  }
  else if (*(int *)in_stack_ffffffbc != -1) {
    LOCK();
    *(int *)in_stack_ffffffbc = *(int *)in_stack_ffffffbc + -1;
    UNLOCK();
    if (*(int *)in_stack_ffffffbc == 0) goto LAB_00402230;
  }
  if (iVar1 == 0) {
    pQVar12 = (QArrayData *)&DAT_0040a660;
    QObject::setObjectName((QString *)&stack0xffffffd4);
    if (*(int *)pQVar12 == 0) {
LAB_004024a0:
      QArrayData::deallocate(pQVar12,2,4);
    }
    else if (*(int *)pQVar12 != -1) {
      LOCK();
      *(int *)pQVar12 = *(int *)pQVar12 + -1;
      UNLOCK();
      if (*(int *)pQVar12 == 0) goto LAB_004024a0;
    }
  }
  QWidget::setWindowModality(0);
  QWidget::resize((QSize *)&stack0xffffffcc);
  pQVar9 = (QString *)&stack0xffffffd4;
  pQVar12 = (QArrayData *)&DAT_0040a3f4;
  QWidget::setStyleSheet(pQVar9);
  if (*(int *)pQVar12 == 0) {
LAB_00402272:
    QArrayData::deallocate(pQVar12,2,4);
  }
  else if (*(int *)pQVar12 != -1) {
    LOCK();
    *(int *)pQVar12 = *(int *)pQVar12 + -1;
    UNLOCK();
    if (*(int *)pQVar12 == 0) goto LAB_00402272;
  }
  pQVar3 = (QAction *)operator_new(8);
  QAction::QAction(pQVar3,(QObject *)this);
  *puVar2 = pQVar3;
  pQVar12 = (QArrayData *)&DAT_0040a480;
  pcVar8 = setObjectName_exref;
  QObject::setObjectName(pQVar9);
  if (*(int *)pQVar12 == 0) {
LAB_00402251:
    QArrayData::deallocate(pQVar12,2,4);
  }
  else if (*(int *)pQVar12 != -1) {
    LOCK();
    *(int *)pQVar12 = *(int *)pQVar12 + -1;
    UNLOCK();
    if (*(int *)pQVar12 == 0) goto LAB_00402251;
  }
  pQVar4 = (QWidget *)operator_new(0x18);
  pcVar7 = (code *)0x0;
  QWidget::QWidget(pQVar4,this);
  puVar2[1] = pQVar4;
  pQVar12 = (QArrayData *)&DAT_0040a4c0;
  (*pcVar8)(pQVar9);
  if (*(int *)pQVar12 == 0) {
LAB_00402384:
    QArrayData::deallocate(pQVar12,2,4);
  }
  else if (*(int *)pQVar12 != -1) {
    LOCK();
    *(int *)pQVar12 = *(int *)pQVar12 + -1;
    UNLOCK();
    if (*(int *)pQVar12 == 0) goto LAB_00402384;
  }
  pQVar12 = (QArrayData *)&DAT_0040a500;
  (*pcVar7)(pQVar9);
  if (*(int *)pQVar12 == 0) {
LAB_004023a5:
    QArrayData::deallocate(pQVar12,2,4);
  }
  else if (*(int *)pQVar12 != -1) {
    LOCK();
    *(int *)pQVar12 = *(int *)pQVar12 + -1;
    UNLOCK();
    if (*(int *)pQVar12 == 0) goto LAB_004023a5;
  }
  this_00 = (QGridLayout *)operator_new(0x10);
  QGridLayout::QGridLayout(this_00,(QWidget *)puVar2[1]);
  puVar2[2] = this_00;
  QGridLayout::setSpacing(6);
  pQVar10 = (QRect *)0xb;
  pcVar8 = (code *)0x401cb9;
  QLayout::setContentsMargins(0xb,0xb,0xb,0xb);
  pQVar13 = (QArrayData *)&DAT_0040a520;
  pQVar12 = (QArrayData *)0x401ccf;
  (*pcVar8)();
  if (*(int *)pQVar13 == 0) {
LAB_004023f1:
    pQVar10 = (QRect *)0x2;
    QArrayData::deallocate(pQVar13,2,4);
    pQVar12 = pQVar13;
  }
  else if (*(int *)pQVar13 != -1) {
    LOCK();
    *(int *)pQVar13 = *(int *)pQVar13 + -1;
    UNLOCK();
    if (*(int *)pQVar13 == 0) goto LAB_004023f1;
  }
  this_01 = (QQuickWidget *)operator_new(0x18);
  QQuickWidget::QQuickWidget(this_01,(QWidget *)puVar2[1]);
  puVar2[3] = this_01;
  pQVar13 = (QArrayData *)&DAT_0040a560;
  (*(code *)pQVar12)();
  if (*(int *)pQVar13 == 0) {
LAB_00402293:
    QArrayData::deallocate(pQVar13,2,4);
  }
  else if (*(int *)pQVar13 != -1) {
    LOCK();
    *(int *)pQVar13 = *(int *)pQVar13 + -1;
    UNLOCK();
    if (*(int *)pQVar13 == 0) goto LAB_00402293;
  }
  QQuickWidget::setResizeMode();
  QGridLayout::addWidget();
  QMainWindow::setCentralWidget((QWidget *)puVar2[1]);
  this_02 = (QMenuBar *)operator_new(0x18);
  QMenuBar::QMenuBar(this_02,(QWidget *)this);
  puVar2[4] = this_02;
  pQVar13 = (QArrayData *)&DAT_0040a5a0;
  pQVar12 = (QArrayData *)0x401dd0;
  pQVar11 = pQVar10;
  (*(code *)pQVar10)();
  if (*(int *)pQVar13 == 0) {
LAB_004023d0:
    pQVar11 = (QRect *)0x4;
    pQVar10 = (QRect *)0x2;
    QArrayData::deallocate(pQVar13,2,4);
    pQVar12 = pQVar13;
  }
  else if (*(int *)pQVar13 != -1) {
    LOCK();
    *(int *)pQVar13 = *(int *)pQVar13 + -1;
    UNLOCK();
    if (*(int *)pQVar13 == 0) goto LAB_004023d0;
  }
  QWidget::setGeometry(pQVar11);
  pQVar13 = (QArrayData *)0x401e29;
  this_03 = (QMenu *)operator_new(0x18);
  QMenu::QMenu(this_03,(QWidget *)puVar2[4]);
  puVar2[5] = this_03;
  pQVar14 = (QArrayData *)&DAT_0040a5c0;
  (*(code *)pQVar10)();
  if (*(int *)pQVar14 == 0) {
LAB_004022b4:
    pQVar13 = (QArrayData *)0x4022cd;
    QArrayData::deallocate(pQVar14,2,4);
  }
  else if (*(int *)pQVar14 != -1) {
    LOCK();
    *(int *)pQVar14 = *(int *)pQVar14 + -1;
    UNLOCK();
    if (*(int *)pQVar14 == 0) goto LAB_004022b4;
  }
  QMainWindow::setMenuBar((QMenuBar *)puVar2[4]);
  this_04 = (QToolBar *)operator_new(0x18);
  QToolBar::QToolBar(this_04,(QWidget *)this);
  puVar2[6] = this_04;
  pQVar15 = (QArrayData *)&DAT_0040a600;
  pQVar14 = (QArrayData *)0x401eb2;
  (*(code *)pQVar10)();
  if (*(int *)pQVar15 == 0) {
LAB_00402300:
    pQVar13 = (QArrayData *)0x2;
    QArrayData::deallocate(pQVar15,2,4);
    pQVar14 = pQVar15;
  }
  else if (*(int *)pQVar15 != -1) {
    LOCK();
    *(int *)pQVar15 = *(int *)pQVar15 + -1;
    UNLOCK();
    if (*(int *)pQVar15 == 0) goto LAB_00402300;
  }
  pQVar15 = (QArrayData *)&DAT_0040a640;
  (*(code *)pQVar12)();
  if (*(int *)pQVar15 == 0) {
LAB_004022d5:
    pQVar13 = (QArrayData *)0x4022ee;
    QArrayData::deallocate(pQVar15,2,4);
  }
  else if (*(int *)pQVar15 != -1) {
    LOCK();
    *(int *)pQVar15 = *(int *)pQVar15 + -1;
    UNLOCK();
    if (*(int *)pQVar15 == 0) goto LAB_004022d5;
  }
  QMainWindow::addToolBar();
  pQVar15 = (QArrayData *)0x401f28;
  this_05 = (QStatusBar *)operator_new(0x18);
  QStatusBar::QStatusBar(this_05,(QWidget *)this);
  puVar2[7] = this_05;
  pQVar16 = (QArrayData *)&DAT_0040a420;
  (*(code *)pQVar10)();
  if (*(int *)pQVar16 == 0) {
LAB_00402363:
    pQVar15 = (QArrayData *)0x40237c;
    QArrayData::deallocate(pQVar16,2,4);
  }
  else if (*(int *)pQVar16 != -1) {
    LOCK();
    *(int *)pQVar16 = *(int *)pQVar16 + -1;
    UNLOCK();
    if (*(int *)pQVar16 == 0) goto LAB_00402363;
  }
  pQVar16 = (QArrayData *)0x401f7f;
  (*(code *)pQVar12)();
  if (*(int *)pQVar16 == 0) {
LAB_00402433:
    QArrayData::deallocate(pQVar16,2,4);
  }
  else if (*(int *)pQVar16 != -1) {
    LOCK();
    *(int *)pQVar16 = *(int *)pQVar16 + -1;
    UNLOCK();
    if (*(int *)pQVar16 == 0) goto LAB_00402433;
  }
  QMainWindow::setStatusBar((QStatusBar *)puVar2[7]);
  pQVar3 = (QAction *)QMenu::menuAction();
  QWidget::addAction(pQVar3);
  QWidget::addAction((QAction *)*puVar2);
  QCoreApplication::translate(&stack0xffffffc8,"MainWindow","MainWindow",0);
  QWidget::setWindowTitle((QString *)&stack0xffffffc8);
  if (*(int *)pQVar15 == 0) {
LAB_00402454:
    QArrayData::deallocate(pQVar15,2,4);
  }
  else if (*(int *)pQVar15 != -1) {
    LOCK();
    *(int *)pQVar15 = *(int *)pQVar15 + -1;
    UNLOCK();
    if (*(int *)pQVar15 == 0) goto LAB_00402454;
  }
  QCoreApplication::translate(&stack0xffffffc4,"MainWindow",&DAT_004090cd,0);
  QAction::setText((QString *)&stack0xffffffc4);
  if (*(int *)pQVar13 == 0) {
LAB_00402475:
    QArrayData::deallocate(pQVar13,2,4);
  }
  else if (*(int *)pQVar13 != -1) {
    LOCK();
    *(int *)pQVar13 = *(int *)pQVar13 + -1;
    UNLOCK();
    if (*(int *)pQVar13 == 0) goto LAB_00402475;
  }
  QCoreApplication::translate(&stack0xffffffc0,"MainWindow",&DAT_004090d4,0);
  QMenu::setTitle((QString *)&stack0xffffffc0);
  if (*(int *)pQVar14 == 0) {
LAB_00402412:
    QArrayData::deallocate(pQVar14,2,4);
  }
  else if (*(int *)pQVar14 != -1) {
    LOCK();
    *(int *)pQVar14 = *(int *)pQVar14 + -1;
    UNLOCK();
    if (*(int *)pQVar14 == 0) goto LAB_00402412;
  }
  QMetaObject::connectSlotsByName((QObject *)this);
  hWnd = (HWND)QWidget::winId();
  *(HWND *)((int)this + 0x18) = hWnd;
  pHVar5 = GetWindowDC(hWnd);
  *(HDC *)((int)this + 0x1c) = pHVar5;
  pQVar12 = (QArrayData *)QString::fromAscii_helper("qrc:/qml/main.qml",0x11);
  QUrl::QUrl((QUrl *)&stack0xffffffcc);
  if (*(int *)pQVar12 == 0) {
LAB_00402342:
    QArrayData::deallocate(pQVar12,2,4);
  }
  else if (*(int *)pQVar12 != -1) {
    LOCK();
    *(int *)pQVar12 = *(int *)pQVar12 + -1;
    UNLOCK();
    if (*(int *)pQVar12 == 0) goto LAB_00402342;
  }
  QQuickWidget::setSource((QUrl *)&stack0xffffffcc);
  uVar6 = QQuickWidget::rootObject();
  *(undefined4 *)((int)this + 0x30) = uVar6;
  pQVar12 = (QArrayData *)QString::fromAscii_helper("pztObject",9);
  pvStack00000058 = (void *)0x1;
  qt_qFindChild_helper();
  if (*(int *)pQVar12 != 0) {
    if (*(int *)pQVar12 == -1) goto LAB_004021ca;
    LOCK();
    *(int *)pQVar12 = *(int *)pQVar12 + -1;
    UNLOCK();
    if (*(int *)pQVar12 != 0) goto LAB_004021ca;
  }
  QArrayData::deallocate(pQVar12,2,4);
LAB_004021ca:
  uStack00000060 = 0;
  pcStack0000005c = "1HandleConnectFailed()";
  pvStack00000058 = this;
  QObject::connect();
  QMetaObject::Connection::~Connection((Connection *)&stack0xffffffb8);
  QWidget::hide();
  QWidget::hide();
  QUrl::~QUrl((QUrl *)&stack0xffffffcc);
  return;
}



/* 00402560 FUN_00402560 */

void __fastcall FUN_00402560(QMainWindow *param_1)

{
  *(undefined ***)param_1 = &PTR_LAB_0040a288;
  *(undefined ***)(param_1 + 8) = &PTR_LAB_0040a364;
  operator_delete(*(void **)(param_1 + 0x34));
  QQmlEngine::~QQmlEngine((QQmlEngine *)(param_1 + 0x20));
                    /* WARNING: Could not recover jumptable at 0x0040258d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  QMainWindow::~QMainWindow(param_1);
  return;
}



/* 00402700 FUN_00402700 */

void __fastcall FUN_00402700(QObject *param_1)

{
  QObject::QObject(param_1,(QObject *)0x0);
  *(undefined ***)param_1 = &PTR_LAB_0040a38c;
  *(undefined4 *)(param_1 + 8) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}



/* 00402750 FUN_00402750 */

void __fastcall FUN_00402750(QObject *param_1)

{
  *(undefined ***)param_1 = &PTR_LAB_0040a38c;
                    /* WARNING: Could not recover jumptable at 0x00402756. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  QObject::~QObject(param_1);
  return;
}



/* 00402780 FUN_00402780 */

void FUN_00402780(void)

{
  QTextStream QVar1;
  int iVar2;
  QTextStream *local_38;
  QArrayData *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  char *local_20;
  
  iVar2 = DisconnectPZTDriver();
  local_30 = 2;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = "default";
  if (iVar2 == 1) {
    QMessageLogger::debug();
    QString::fromUtf8_helper((char *)&local_34,0x409130);
    QTextStream::operator<<(local_38,(QString *)&local_34);
    if (*(int *)local_34 == 0) {
LAB_004028e0:
      QArrayData::deallocate(local_34,2,4);
    }
    else if (*(int *)local_34 != -1) {
      LOCK();
      *(int *)local_34 = *(int *)local_34 + -1;
      UNLOCK();
      if (*(int *)local_34 == 0) goto LAB_004028e0;
    }
    if (local_38[0x14] == (QTextStream)0x0) goto LAB_00402816;
    QTextStream::operator<<(local_38,' ');
    goto LAB_0040285f;
  }
  QMessageLogger::debug();
  QString::fromUtf8_helper((char *)&local_34,0x409142);
  QTextStream::operator<<(local_38,(QString *)&local_34);
  if (*(int *)local_34 == 0) {
LAB_00402830:
    QArrayData::deallocate(local_34,2,4);
    QVar1 = local_38[0x14];
  }
  else {
    if (*(int *)local_34 != -1) {
      LOCK();
      *(int *)local_34 = *(int *)local_34 + -1;
      UNLOCK();
      if (*(int *)local_34 == 0) goto LAB_00402830;
    }
    QVar1 = local_38[0x14];
  }
  if (QVar1 == (QTextStream)0x0) {
LAB_00402816:
    QDebug::~QDebug((QDebug *)&local_38);
    return;
  }
  QTextStream::operator<<(local_38,' ');
LAB_0040285f:
  QDebug::~QDebug((QDebug *)&local_38);
  return;
}



/* 00402920 FUN_00402920 */

void __fastcall FUN_00402920(int param_1)

{
  QTextStream QVar1;
  int iVar2;
  QTextStream *local_38;
  QArrayData *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  char *local_20;
  
  iVar2 = SetVoltage(*(int *)(param_1 + 0xc));
  local_30 = 2;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = "default";
  if (iVar2 == 1) {
    QMessageLogger::debug();
    QString::fromUtf8_helper((char *)&local_34,0x40914a);
    QTextStream::operator<<(local_38,(QString *)&local_34);
    if (*(int *)local_34 == 0) {
LAB_00402a80:
      QArrayData::deallocate(local_34,2,4);
    }
    else if (*(int *)local_34 != -1) {
      LOCK();
      *(int *)local_34 = *(int *)local_34 + -1;
      UNLOCK();
      if (*(int *)local_34 == 0) goto LAB_00402a80;
    }
    if (local_38[0x14] == (QTextStream)0x0) goto LAB_004029bc;
    QTextStream::operator<<(local_38,' ');
    goto LAB_004029ff;
  }
  QMessageLogger::debug();
  QString::fromUtf8_helper((char *)&local_34,0x409142);
  QTextStream::operator<<(local_38,(QString *)&local_34);
  if (*(int *)local_34 == 0) {
LAB_004029d0:
    QArrayData::deallocate(local_34,2,4);
    QVar1 = local_38[0x14];
  }
  else {
    if (*(int *)local_34 != -1) {
      LOCK();
      *(int *)local_34 = *(int *)local_34 + -1;
      UNLOCK();
      if (*(int *)local_34 == 0) goto LAB_004029d0;
    }
    QVar1 = local_38[0x14];
  }
  if (QVar1 == (QTextStream)0x0) {
LAB_004029bc:
    QDebug::~QDebug((QDebug *)&local_38);
    return;
  }
  QTextStream::operator<<(local_38,' ');
LAB_004029ff:
  QDebug::~QDebug((QDebug *)&local_38);
  return;
}



/* 00402ac0 FUN_00402ac0 */

void __fastcall FUN_00402ac0(int param_1)

{
  QTextStream QVar1;
  int iVar2;
  QTextStream *local_38;
  QArrayData *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  char *local_20;
  
  iVar2 = SetNoiseOutput(*(int *)(param_1 + 0xc));
  local_30 = 2;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = "default";
  if (iVar2 == 1) {
    QMessageLogger::debug();
    QString::fromUtf8_helper((char *)&local_34,0x40914a);
    QTextStream::operator<<(local_38,(QString *)&local_34);
    if (*(int *)local_34 == 0) {
LAB_00402c20:
      QArrayData::deallocate(local_34,2,4);
    }
    else if (*(int *)local_34 != -1) {
      LOCK();
      *(int *)local_34 = *(int *)local_34 + -1;
      UNLOCK();
      if (*(int *)local_34 == 0) goto LAB_00402c20;
    }
    if (local_38[0x14] == (QTextStream)0x0) goto LAB_00402b5c;
    QTextStream::operator<<(local_38,' ');
    goto LAB_00402b9f;
  }
  QMessageLogger::debug();
  QString::fromUtf8_helper((char *)&local_34,0x409142);
  QTextStream::operator<<(local_38,(QString *)&local_34);
  if (*(int *)local_34 == 0) {
LAB_00402b70:
    QArrayData::deallocate(local_34,2,4);
    QVar1 = local_38[0x14];
  }
  else {
    if (*(int *)local_34 != -1) {
      LOCK();
      *(int *)local_34 = *(int *)local_34 + -1;
      UNLOCK();
      if (*(int *)local_34 == 0) goto LAB_00402b70;
    }
    QVar1 = local_38[0x14];
  }
  if (QVar1 == (QTextStream)0x0) {
LAB_00402b5c:
    QDebug::~QDebug((QDebug *)&local_38);
    return;
  }
  QTextStream::operator<<(local_38,' ');
LAB_00402b9f:
  QDebug::~QDebug((QDebug *)&local_38);
  return;
}



/* 00402c60 FUN_00402c60 */

void __fastcall FUN_00402c60(int param_1)

{
  QTextStream QVar1;
  int iVar2;
  QTextStream *local_38;
  QArrayData *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  char *local_20;
  
  iVar2 = SetTriangularWave(*(int *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10));
  local_30 = 2;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = "default";
  if (iVar2 == 1) {
    QMessageLogger::debug();
    QString::fromUtf8_helper((char *)&local_34,0x40914a);
    QTextStream::operator<<(local_38,(QString *)&local_34);
    if (*(int *)local_34 == 0) {
LAB_00402dd0:
      QArrayData::deallocate(local_34,2,4);
    }
    else if (*(int *)local_34 != -1) {
      LOCK();
      *(int *)local_34 = *(int *)local_34 + -1;
      UNLOCK();
      if (*(int *)local_34 == 0) goto LAB_00402dd0;
    }
    if (local_38[0x14] == (QTextStream)0x0) goto LAB_00402d03;
    QTextStream::operator<<(local_38,' ');
    goto LAB_00402d4f;
  }
  QMessageLogger::debug();
  QString::fromUtf8_helper((char *)&local_34,0x409142);
  QTextStream::operator<<(local_38,(QString *)&local_34);
  if (*(int *)local_34 == 0) {
LAB_00402d20:
    QArrayData::deallocate(local_34,2,4);
    QVar1 = local_38[0x14];
  }
  else {
    if (*(int *)local_34 != -1) {
      LOCK();
      *(int *)local_34 = *(int *)local_34 + -1;
      UNLOCK();
      if (*(int *)local_34 == 0) goto LAB_00402d20;
    }
    QVar1 = local_38[0x14];
  }
  if (QVar1 == (QTextStream)0x0) {
LAB_00402d03:
    QDebug::~QDebug((QDebug *)&local_38);
    return;
  }
  QTextStream::operator<<(local_38,' ');
LAB_00402d4f:
  QDebug::~QDebug((QDebug *)&local_38);
  return;
}



/* 00402e10 FUN_00402e10 */

void __thiscall FUN_00402e10(void *this,int param_1,int param_2,int param_3)

{
  QTextStream *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  char *local_20;
  
  local_30 = 2;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = "default";
  QMessageLogger::debug();
  QTextStream::operator<<(local_34,param_1);
  if (local_34[0x14] != (QTextStream)0x0) {
    QTextStream::operator<<(local_34,' ');
  }
  QTextStream::operator<<(local_34,param_2);
  if (local_34[0x14] != (QTextStream)0x0) {
    QTextStream::operator<<(local_34,' ');
  }
  QTextStream::operator<<(local_34,param_3);
  if (local_34[0x14] == (QTextStream)0x0) {
    QDebug::~QDebug((QDebug *)&local_34);
  }
  else {
    QTextStream::operator<<(local_34,' ');
    QDebug::~QDebug((QDebug *)&local_34);
  }
  if (param_1 == 1) {
    *(int *)((int)this + 0xc) = param_2;
    FUN_00402ac0((int)this);
    return;
  }
  if (param_1 == 2) {
    *(int *)((int)this + 0x10) = param_3;
    *(int *)((int)this + 0xc) = param_2;
    FUN_00402c60((int)this);
    return;
  }
  if (param_1 == 0) {
    *(int *)((int)this + 0xc) = param_2;
    FUN_00402920((int)this);
    return;
  }
  return;
}



/* 00402f80 FUN_00402f80 */

undefined4 __fastcall FUN_00402f80(int param_1)

{
  return *(undefined4 *)(param_1 + 0xc);
}



/* 00402f90 FUN_00402f90 */

undefined4 __fastcall FUN_00402f90(int param_1)

{
  return *(undefined4 *)(param_1 + 0x10);
}



/* 00402fa0 FUN_00402fa0 */

undefined4 __fastcall FUN_00402fa0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x14);
}



/* 00402fb0 FUN_00402fb0 */

undefined4 __fastcall FUN_00402fb0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x18);
}



/* 00402fc0 FUN_00402fc0 */

void __thiscall FUN_00402fc0(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0xc) = param_1;
  return;
}



/* 00402fd0 FUN_00402fd0 */

void __thiscall FUN_00402fd0(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0x10) = param_1;
  return;
}



/* 00402fe0 FUN_00402fe0 */

void __thiscall FUN_00402fe0(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0x14) = param_1;
  return;
}



/* 00402ff0 FUN_00402ff0 */

void __thiscall FUN_00402ff0(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0x18) = param_1;
  return;
}



/* 00403000 FUN_00403000 */

void __fastcall FUN_00403000(QObject *param_1)

{
  QTextStream QVar1;
  int iVar2;
  QTextStream *local_38;
  QArrayData *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  char *local_20;
  
  iVar2 = ConnectPZTDriver((int *)(param_1 + 8));
  if (iVar2 == 1) {
    local_30 = 2;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = "default";
    QMessageLogger::debug();
    QString::fromUtf8_helper((char *)&local_34,0x409153);
    QTextStream::operator<<(local_38,(QString *)&local_34);
    if (*(int *)local_34 == 0) {
LAB_004031a0:
      QArrayData::deallocate(local_34,2,4);
    }
    else if (*(int *)local_34 != -1) {
      LOCK();
      *(int *)local_34 = *(int *)local_34 + -1;
      UNLOCK();
      if (*(int *)local_34 == 0) goto LAB_004031a0;
    }
    if (local_38[0x14] == (QTextStream)0x0) goto LAB_004030a5;
    QTextStream::operator<<(local_38,' ');
    goto LAB_004030ef;
  }
  FUN_00404490(param_1);
  local_30 = 2;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = "default";
  QMessageLogger::debug();
  QString::fromUtf8_helper((char *)&local_34,0x409142);
  QTextStream::operator<<(local_38,(QString *)&local_34);
  if (*(int *)local_34 == 0) {
LAB_004030c0:
    QArrayData::deallocate(local_34,2,4);
    QVar1 = local_38[0x14];
  }
  else {
    if (*(int *)local_34 != -1) {
      LOCK();
      *(int *)local_34 = *(int *)local_34 + -1;
      UNLOCK();
      if (*(int *)local_34 == 0) goto LAB_004030c0;
    }
    QVar1 = local_38[0x14];
  }
  if (QVar1 == (QTextStream)0x0) {
LAB_004030a5:
    QDebug::~QDebug((QDebug *)&local_38);
    return;
  }
  QTextStream::operator<<(local_38,' ');
LAB_004030ef:
  QDebug::~QDebug((QDebug *)&local_38);
  return;
}



/* 004031f0 FUN_004031f0 */

void FUN_004031f0(void)

{
  int iVar1;
  Data *in_EAX;
  Data *pDVar2;
  
  pDVar2 = in_EAX + *(int *)(in_EAX + 0xc) * 4 + 0x10;
  iVar1 = *(int *)(in_EAX + 8);
  while (pDVar2 != in_EAX + iVar1 * 4 + 0x10) {
    pDVar2 = pDVar2 + -4;
    operator_delete(*(void **)pDVar2);
  }
  QListData::dispose(in_EAX);
  return;
}



/* 00403270 FUN_00403270 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_00403270(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  QArrayData *pQVar1;
  undefined4 uVar2;
  QArrayData *in_stack_ffffffa8;
  code *pcVar3;
  int iVar4;
  QArrayData *local_24;
  char local_20 [3];
  undefined1 local_1d;
  
  local_20[0] = '\x10';
  local_20[1] = 1;
  iVar4 = (int)ROUND((double)param_2 * _DAT_00409170);
  local_1d = (undefined1)iVar4;
  local_20[2] = (char)((uint)iVar4 >> 8);
  if (param_3 == 2) {
    local_20[0] = ' ';
    local_20[1] = 2;
  }
  else if (param_3 == 3) {
    local_20[0] = '0';
    local_20[1] = 3;
    QByteArray::number((int)&local_24,param_2);
    local_20[2] = QByteArray::toInt((bool *)&stack0xffffffd7,0x10);
    if (*(int *)local_24 == 0) {
LAB_004034b0:
      QArrayData::deallocate(local_24,1,4);
    }
    else if (*(int *)local_24 != -1) {
      LOCK();
      *(int *)local_24 = *(int *)local_24 + -1;
      UNLOCK();
      if (*(int *)local_24 == 0) goto LAB_004034b0;
    }
    pcVar3 = (code *)0x4033fa;
    (*(code *)&local_24)(&local_24,param_4,0x10);
    iVar4 = 0x10;
    local_1d = (*pcVar3)(&stack0xffffffd7);
    if (*(int *)local_24 == 0) {
LAB_00403430:
      QArrayData::deallocate(in_stack_ffffffa8,1,4);
    }
    else if (*(int *)local_24 != -1) {
      LOCK();
      *(int *)local_24 = *(int *)local_24 + -1;
      UNLOCK();
      if (*(int *)local_24 == 0) goto LAB_00403430;
    }
  }
  pQVar1 = (QArrayData *)QString::fromLatin1_helper(local_20,4);
  QString::toLatin1_helper((QString *)&local_24);
  uVar2 = QIODevice::write((char *)(local_24 + *(int *)(local_24 + 0xc)),
                           CONCAT44(iVar4,*(int *)(local_24 + 4) >> 0x1f));
  (**(code **)(*param_1 + 0x60))(100);
  FUN_00405e60(5000);
  if (*(int *)local_24 == 0) {
LAB_00403480:
    uVar2 = 4;
    QArrayData::deallocate(local_24,1,4);
  }
  else if (*(int *)local_24 != -1) {
    LOCK();
    *(int *)local_24 = *(int *)local_24 + -1;
    UNLOCK();
    if (*(int *)local_24 == 0) goto LAB_00403480;
  }
  if (*(int *)pQVar1 == 0) {
LAB_00403451:
    uVar2 = 0x40346a;
    QArrayData::deallocate(pQVar1,2,4);
    return uVar2;
  }
  if (*(int *)pQVar1 != -1) {
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 == 0) goto LAB_00403451;
  }
  return uVar2;
}



/* 00403500 FUN_00403500 */

undefined4 __cdecl FUN_00403500(int *param_1,int *param_2)

{
  QArrayData *pQVar1;
  char cVar2;
  QByteArray *pQVar3;
  QArrayData *local_20 [4];
  
  cVar2 = (**(code **)(*param_1 + 0x5c))(100);
  if (cVar2 == '\0') {
LAB_00403524:
    return *(undefined4 *)(*param_2 + 4);
  }
  QIODevice::readAll();
  pQVar1 = (QArrayData *)*param_2;
  *param_2 = (int)local_20[0];
  local_20[0] = pQVar1;
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_00403561;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_00403561;
  }
  QArrayData::deallocate(pQVar1,1,4);
LAB_00403561:
  cVar2 = (**(code **)(*param_1 + 0x5c))(10);
  if (cVar2 != '\0') {
    QIODevice::readAll();
    pQVar3 = (QByteArray *)local_20;
    QByteArray::append((QByteArray *)local_20);
    if (*(int *)local_20[0] != 0) goto code_r0x00403598;
    goto LAB_004035b0;
  }
  goto LAB_00403524;
code_r0x00403598:
  if (*(int *)local_20[0] != -1) {
    LOCK();
    *(int *)local_20[0] = *(int *)local_20[0] + -1;
    UNLOCK();
    if (*(int *)local_20[0] == 0) {
LAB_004035b0:
      QArrayData::deallocate((QArrayData *)pQVar3,1,4);
    }
  }
  goto LAB_00403561;
}



/* 00403610 ConnectPZTDriver */

undefined4 __cdecl ConnectPZTDriver(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_10 [8];
  
                    /* 0x3610  1  ConnectPZTDriver */
  QMutex::lock();
  if (DAT_0040d074 == '\0') {
    if (0 < *param_1) {
      DAT_0040d064 = *param_1;
    }
    QMutex::unlock();
    iVar1 = pthread_create(local_10,0,&LAB_00403920,0);
    uVar2 = 3;
    if (iVar1 == 0) {
      FUN_00405e60(10000);
      QMutex::lock();
      if ((DAT_0040d074 == '\0') || (DAT_0040d064 == 0)) {
        *param_1 = 0;
        QMutex::unlock();
        DAT_0040d070 = 0;
        uVar2 = 2;
      }
      else {
        *param_1 = DAT_0040d064;
        QMutex::unlock();
        DAT_0040d070 = 1;
        uVar2 = 1;
      }
    }
    return uVar2;
  }
  QMutex::unlock();
  return 4;
}



/* 00403710 SetVoltage */

undefined4 __cdecl SetVoltage(int param_1)

{
  undefined4 local_10 [2];
  
                    /* 0x3710  5  SetVoltage */
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (100 < param_1) {
    param_1 = 100;
  }
  QMutex::lock();
  if (DAT_0040d074 == '\0') {
    QMutex::lock();
    return 5;
  }
  local_10[0] = 1;
  DAT_0040d068 = param_1;
  FUN_004069e0(&DAT_0040d060,local_10);
  QMutex::unlock();
  return 1;
}



/* 004037a0 DisconnectPZTDriver */

undefined4 DisconnectPZTDriver(void)

{
  undefined4 auStack_10 [4];
  
                    /* 0x37a0  2  DisconnectPZTDriver */
  QMutex::lock();
  if (DAT_0040d074 == '\0') {
    QMutex::unlock();
    return 5;
  }
  auStack_10[0] = 0;
  FUN_004069e0(&DAT_0040d060,auStack_10);
  QMutex::unlock();
  return 1;
}



/* 00403800 SetNoiseOutput */

undefined4 __cdecl SetNoiseOutput(int param_1)

{
  undefined4 local_10 [2];
  
                    /* 0x3800  3  SetNoiseOutput */
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (100 < param_1) {
    param_1 = 100;
  }
  QMutex::lock();
  if (DAT_0040d074 == '\0') {
    QMutex::lock();
    return 5;
  }
  local_10[0] = 2;
  DAT_0040d068 = param_1;
  FUN_004069e0(&DAT_0040d060,local_10);
  QMutex::unlock();
  return 1;
}



/* 00403890 SetTriangularWave */

undefined4 __cdecl SetTriangularWave(int param_1,undefined4 param_2)

{
  undefined4 local_10 [2];
  
                    /* 0x3890  4  SetTriangularWave */
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (100 < param_1) {
    param_1 = 100;
  }
  QMutex::lock();
  if (DAT_0040d074 == '\0') {
    QMutex::lock();
    return 5;
  }
  local_10[0] = 3;
  DAT_0040d06c = param_2;
  DAT_0040d068 = param_1;
  FUN_004069e0(&DAT_0040d060,local_10);
  QMutex::unlock();
  return 1;
}



/* 00404490 FUN_00404490 */

void __fastcall FUN_00404490(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&DAT_00408020,4,(void **)0x0);
  return;
}



/* 004044f0 FUN_004044f0 */

void __cdecl FUN_004044f0(QObject *param_1,int param_2,int param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  code *pcVar3;
  undefined4 uVar4;
  
  if (param_2 == 0) {
    switch(param_3) {
    case 0:
      param_3 = 0;
      break;
    case 1:
      param_3 = 1;
      break;
    case 2:
      param_3 = 2;
      break;
    case 3:
      param_3 = 3;
      break;
    case 4:
      param_3 = 4;
      break;
    case 5:
      param_3 = 5;
      break;
    case 6:
      FUN_00403000(param_1);
      return;
    case 7:
      FUN_00402780();
      return;
    case 8:
      FUN_00402920((int)param_1);
      return;
    case 9:
      FUN_00402ac0((int)param_1);
      return;
    case 10:
      FUN_00402c60((int)param_1);
      return;
    case 0xb:
      FUN_00402e10(param_1,*(int *)param_4[1],*(int *)param_4[2],*(int *)param_4[3]);
      return;
    case 0xc:
      FUN_00402fc0(param_1,*(undefined4 *)param_4[1]);
      return;
    case 0xd:
      FUN_00402fd0(param_1,*(undefined4 *)param_4[1]);
      return;
    case 0xe:
      FUN_00402fe0(param_1,*(undefined4 *)param_4[1]);
      return;
    case 0xf:
      FUN_00402ff0(param_1,*(undefined4 *)param_4[1]);
    default:
      return;
    }
                    /* WARNING: Could not recover jumptable at 0x00404615. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    QMetaObject::activate(param_1,(QMetaObject *)&DAT_00408020,param_3,(void **)0x0);
    return;
  }
  if (param_2 == 10) {
    puVar1 = (undefined4 *)param_4[1];
    puVar2 = (undefined4 *)*param_4;
    pcVar3 = (code *)*puVar1;
    if (pcVar3 == (code *)&DAT_004043d0) {
      if (puVar1[1] != 0) {
        return;
      }
      *puVar2 = 0;
      return;
    }
    if (pcVar3 == (code *)&DAT_00404400) {
      if (puVar1[1] != 0) {
        return;
      }
      *puVar2 = 1;
      return;
    }
    if (pcVar3 == (code *)&DAT_00404430) {
      if (puVar1[1] != 0) {
        return;
      }
      *puVar2 = 2;
      return;
    }
    if (pcVar3 != (code *)&DAT_00404460) {
      if (pcVar3 == FUN_00404490) {
        if (puVar1[1] != 0) {
          return;
        }
        *puVar2 = 4;
        return;
      }
      if (pcVar3 != (code *)&DAT_004044c0) {
        return;
      }
      if (puVar1[1] != 0) {
        return;
      }
      *puVar2 = 5;
      return;
    }
    if (puVar1[1] != 0) {
      return;
    }
    *puVar2 = 3;
    return;
  }
  if (param_2 != 1) {
    if (param_2 != 2) {
      return;
    }
    puVar1 = (undefined4 *)*param_4;
    if (param_3 == 1) {
      FUN_00402fd0(param_1,*puVar1);
      return;
    }
    if (param_3 < 2) {
      if (param_3 != 0) {
        return;
      }
      FUN_00402fc0(param_1,*puVar1);
      return;
    }
    if (param_3 != 2) {
      if (param_3 != 3) {
        return;
      }
      FUN_00402ff0(param_1,*puVar1);
      return;
    }
    FUN_00402fe0(param_1,*puVar1);
    return;
  }
  puVar1 = (undefined4 *)*param_4;
  if (param_3 == 1) {
    uVar4 = FUN_00402f90((int)param_1);
    *puVar1 = uVar4;
    return;
  }
  if (param_3 < 2) {
    if (param_3 != 0) {
      return;
    }
    uVar4 = FUN_00402f80((int)param_1);
    *puVar1 = uVar4;
    return;
  }
  if (param_3 == 2) {
    uVar4 = FUN_00402fa0((int)param_1);
    *puVar1 = uVar4;
    return;
  }
  if (param_3 != 3) {
    return;
  }
  uVar4 = FUN_00402fb0((int)param_1);
  *puVar1 = uVar4;
  return;
}



/* 00404a10 FUN_00404a10 */

_onexit_t __cdecl FUN_00404a10(_onexit_t param_1)

{
  _onexit_t p_Var1;
  int local_14;
  undefined4 local_10 [3];
  
  local_14 = FUN_00404ea0(DAT_0040d4a8);
  if (local_14 != -1) {
    _lock(8);
    local_14 = FUN_00404ea0(DAT_0040d4a8);
    local_10[0] = FUN_00404ea0(DAT_0040d4a4);
    p_Var1 = (_onexit_t)__dllonexit(param_1,&local_14,local_10);
    DAT_0040d4a8 = FUN_00404eb0(local_14);
    DAT_0040d4a4 = FUN_00404eb0(local_10[0]);
    _unlock(8);
    return p_Var1;
  }
  p_Var1 = _onexit(param_1);
  return p_Var1;
}



/* 00404ad0 FUN_00404ad0 */

int __cdecl FUN_00404ad0(_onexit_t param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = FUN_00404a10(param_1);
  return -(uint)(p_Var1 == (_onexit_t)0x0);
}



/* 00404b20 FUN_00404b20 */

void FUN_00404b20(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_00406d90;
  if (DAT_00406d90 == -1) {
    iVar1 = 0;
    do {
      iVar2 = iVar1;
      iVar1 = iVar2 + 1;
    } while ((&DAT_00406d90)[iVar2 + 1] != 0);
  }
  for (; iVar2 != 0; iVar2 = iVar2 + -1) {
    (*(code *)(&DAT_00406d90)[iVar2])();
  }
  FUN_00404ad0((_onexit_t)&LAB_00404af0);
  return;
}



/* 00404b70 FUN_00404b70 */

void FUN_00404b70(void)

{
  if (DAT_0040d094 != 0) {
    return;
  }
  DAT_0040d094 = 1;
  FUN_00404b20();
  return;
}



/* 00404bb0 FUN_00404bb0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00404bb0(void)

{
  DWORD DVar1;
  DWORD DVar2;
  DWORD DVar3;
  uint uVar4;
  _FILETIME local_2c;
  LARGE_INTEGER aLStack_24 [2];
  
  local_2c.dwLowDateTime = 0;
  local_2c.dwHighDateTime = 0;
  if (DAT_00408060 != 0xbb40e64e) {
    _DAT_00408064 = ~DAT_00408060;
    return;
  }
  GetSystemTimeAsFileTime(&local_2c);
  uVar4 = local_2c.dwLowDateTime ^ local_2c.dwHighDateTime;
  DVar1 = GetCurrentProcessId();
  DVar2 = GetCurrentThreadId();
  DVar3 = GetTickCount();
  QueryPerformanceCounter(aLStack_24);
  DAT_00408060 = DVar3 ^ DVar2 ^ uVar4 ^ aLStack_24[0].s.LowPart ^ aLStack_24[0].s.HighPart ^ DVar1;
  if (DAT_00408060 == 0xbb40e64e) {
    _DAT_00408064 = 0x44bf19b0;
    DAT_00408060 = 0xbb40e64f;
  }
  else {
    _DAT_00408064 = ~DAT_00408060;
  }
  return;
}



/* 00404cf0 tls_callback_1 */

undefined4 tls_callback_1(undefined4 param_1,int param_2)

{
  if ((param_2 != 0) && (param_2 != 3)) {
    return 1;
  }
  FUN_00405650(param_1,param_2);
  return 1;
}



/* 00404d40 tls_callback_0 */

/* WARNING: Removing unreachable block (ram,0x00404d80) */
/* WARNING: Removing unreachable block (ram,0x00404d86) */
/* WARNING: Removing unreachable block (ram,0x00404d88) */
/* WARNING: Removing unreachable block (ram,0x00404d93) */

undefined4 tls_callback_0(undefined4 param_1,int param_2)

{
  if (DAT_0040804c != 2) {
    DAT_0040804c = 2;
  }
  if ((param_2 != 2) && (param_2 == 1)) {
    FUN_00405650(param_1,1);
  }
  return 1;
}



/* 00404e90 FUN_00404e90 */

void FUN_00404e90(void)

{
  return;
}



/* 00404ea0 FUN_00404ea0 */

undefined4 __cdecl FUN_00404ea0(undefined4 param_1)

{
  return param_1;
}



/* 00404eb0 FUN_00404eb0 */

undefined4 __cdecl FUN_00404eb0(undefined4 param_1)

{
  return param_1;
}



/* 00404ec0 FUN_00404ec0 */

void FUN_00404ec0(char *param_1)

{
  fwrite("Mingw-w64 runtime failure:\n",1,0x1b,(FILE *)(_iob_exref + 0x40));
  vfprintf((FILE *)(_iob_exref + 0x40),param_1,&stack0x00000008);
                    /* WARNING: Subroutine does not return */
  abort();
}



/* 00404f20 FUN_00404f20 */

/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x00405223) */
/* WARNING: Type propagation algorithm not settling */

PDWORD FUN_00404f20(void)

{
  byte *pbVar1;
  int iVar2;
  PDWORD in_EAX;
  int iVar3;
  SIZE_T SVar4;
  uint uVar5;
  PDWORD pDVar6;
  code *extraout_EAX;
  code *extraout_EAX_00;
  code *pcVar7;
  code *extraout_EAX_01;
  code *extraout_EAX_02;
  uint *puVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  DWORD *pDVar12;
  int *piVar13;
  DWORD *pDVar14;
  int *piVar15;
  undefined4 *puVar16;
  undefined4 uStackY_90;
  uint auStackY_8c [6];
  int iStackY_74;
  undefined4 uStackY_70;
  undefined1 auStackY_6c [4];
  int aiStackY_68 [3];
  int iStackY_5c;
  PDWORD pDStackY_40;
  _MEMORY_BASIC_INFORMATION local_28;
  
  if ((int)DAT_0040d460 < 1) {
    iVar3 = 0;
  }
  else {
    iVar9 = 0;
    puVar8 = (uint *)(DAT_0040d464 + 4);
    do {
      if (((PDWORD)*puVar8 <= in_EAX) && (in_EAX < (PDWORD)((int)*puVar8 + *(int *)(puVar8[1] + 8)))
         ) {
        return in_EAX;
      }
      iVar9 = iVar9 + 1;
      puVar8 = puVar8 + 3;
      iVar3 = (int)DAT_0040d460;
    } while ((PDWORD)iVar9 != DAT_0040d460);
  }
  pDStackY_40 = (PDWORD)0x404f68;
  iVar9 = FUN_00405850((int)in_EAX);
  if (iVar9 != 0) {
    in_EAX = (PDWORD)(iVar3 * 0xc);
    puVar16 = (undefined4 *)(DAT_0040d464 + (int)in_EAX);
    puVar16[2] = iVar9;
    *puVar16 = 0;
    pDStackY_40 = (PDWORD)0x404f8e;
    iVar3 = FUN_00405950();
    puVar16[1] = iVar3 + *(int *)(iVar9 + 0xc);
    pDStackY_40 = (PDWORD)0x404fb6;
    SVar4 = VirtualQuery(*(LPCVOID *)(DAT_0040d464 + 4 + (int)in_EAX),&local_28,0x1c);
    if (SVar4 != 0) {
      if ((((uint)(local_28.Protect + -4) & 0xfffffffb) == 0) ||
         (local_28.Protect = (uint)(local_28.Protect + -0x40) & 0xffffffbf,
         (PDWORD)local_28.Protect == (PDWORD)0x0)) {
LAB_00404fff:
        DAT_0040d460 = (PDWORD)((int)DAT_0040d460 + 1);
        return (PDWORD)local_28.Protect;
      }
      in_EAX = (PDWORD)((int)in_EAX + DAT_0040d464);
      pDStackY_40 = (PDWORD)0x404ff8;
      local_28.Protect = VirtualProtect(local_28.BaseAddress,local_28.RegionSize,0x40,in_EAX);
      if ((PDWORD)local_28.Protect != (PDWORD)0x0) goto LAB_00404fff;
      pDStackY_40 = (PDWORD)0x40501a;
      GetLastError();
      pDStackY_40 = (PDWORD)0x40502a;
      FUN_00404ec0("  VirtualProtect failed with code 0x%x");
    }
    FUN_00404ec0("  VirtualQuery failed for %d bytes at address %p");
  }
  FUN_00404ec0("Address %p has no image-section");
  if (DAT_0040d45c != (PDWORD)0x0) {
    return DAT_0040d45c;
  }
  DAT_0040d45c = (PDWORD)0x1;
  uStackY_90 = 0x405088;
  pDStackY_40 = in_EAX;
  FUN_004058a0();
  uStackY_90 = 0x40509a;
  uVar5 = FUN_00405e28();
  DAT_0040d460 = (PDWORD)0x0;
  iVar3 = -uVar5;
  piVar15 = (int *)((int)auStackY_8c + iVar3);
  pDVar14 = (DWORD *)((int)auStackY_8c + iVar3);
  DAT_0040d464 = (uint)(auStackY_6c + iVar3 + -1) & 0xfffffff0;
  pDVar6 = DAT_0040afa0;
  if ((DAT_0040afa0 != (PDWORD)0x0) || (pDVar6 = DAT_0040afa4, DAT_0040afa4 != (PDWORD)0x0)) {
    piVar11 = (int *)&DAT_0040afa0;
LAB_0040516d:
    if (&UNK_0040afff < piVar11) {
      DAT_0040d460 = (PDWORD)0x0;
      return pDVar6;
    }
    do {
      iVar9 = piVar11[1];
      aiStackY_68[0] = *piVar11;
      piVar11 = piVar11 + 2;
      aiStackY_68[0] = aiStackY_68[0] + *(int *)(iVar9 + 0x400000);
      *(undefined4 *)((int)auStackY_8c + iVar3 + -4) = 0x405191;
      FUN_00404f20();
      *(int *)(iVar9 + 0x400000) = aiStackY_68[0];
    } while (piVar11 < &DAT_0040b000);
LAB_004051a2:
    piVar10 = (int *)0x0;
    pDVar6 = DAT_0040d460;
    if (0 < (int)DAT_0040d460) {
      do {
        pDVar6 = (PDWORD)(DAT_0040d464 + (int)piVar10 * 0xc);
        if (*pDVar6 != 0) {
          pDVar14[2] = 0x1c;
          pDVar14[1] = (DWORD)aiStackY_68;
          *pDVar14 = pDVar6[1];
          pDVar12 = pDVar14 + -1;
          pDVar14[-1] = 0x4051ed;
          SVar4 = VirtualQuery((LPCVOID)*pDVar14,(PMEMORY_BASIC_INFORMATION)pDVar14[1],pDVar14[2]);
          if (SVar4 == 0) {
            iVar3 = DAT_0040d464 + (int)piVar10 * 0xc;
            ((int *)pDVar12)[-1] = *(int *)(iVar3 + 4);
            iVar3 = *(int *)(*(int *)(iVar3 + 8) + 8);
            ((int *)pDVar12)[-3] = (int)"  VirtualQuery failed for %d bytes at address %p";
            ((int *)pDVar12)[-2] = iVar3;
            ((int *)pDVar12)[-4] = 0x405307;
            iVar9 = FUN_00404ec0((char *)((int *)pDVar12)[-3]);
            piVar15 = (int *)pDVar12 + -2;
            goto LAB_00405307;
          }
          *pDVar12 = (DWORD)auStackY_6c;
          ((int *)pDVar12)[-1] = *(int *)(DAT_0040d464 + (int)piVar10 * 0xc);
          ((int *)pDVar12)[-2] = iStackY_5c;
          ((int *)pDVar12)[-3] = aiStackY_68[0];
          piVar13 = (int *)pDVar12 + -4;
          ((int *)pDVar12)[-4] = 0x40521e;
          pDVar6 = (PDWORD)VirtualProtect((LPVOID)((int *)pDVar12)[-3],((int *)pDVar12)[-2],
                                          ((int *)pDVar12)[-1],(PDWORD)*pDVar12);
          pDVar14 = (DWORD *)((int)piVar13 + -0x10);
        }
        piVar10 = (int *)((int)piVar10 + 1);
      } while ((int)piVar10 < (int)DAT_0040d460);
    }
    return pDVar6;
  }
  piVar10 = &DAT_0040afac;
  if (DAT_0040afa8 == 0) {
    piVar11 = piVar10;
    if ((DAT_0040afac != 0) || (piVar11 = &DAT_0040afac, DAT_0040afb0 != 0)) goto LAB_0040516d;
  }
  else {
    piVar10 = (int *)&DAT_0040afa0;
  }
  iVar9 = piVar10[2];
  if (iVar9 == 1) {
    piVar10 = piVar10 + 3;
    if (&UNK_0040afff < piVar10) {
      DAT_0040d460 = (PDWORD)0x0;
      return (PDWORD)0x1;
    }
    do {
      iVar9 = *piVar10;
      iVar2 = piVar10[1];
      uStackY_70 = *(int *)(iVar9 + 0x400000);
      pbVar1 = (byte *)(iVar2 + 0x400000);
      uVar5 = (uint)*(byte *)(piVar10 + 2);
      if (uVar5 == 0x10) {
        uVar5 = (uint)*(ushort *)(iVar2 + 0x400000);
        if (*(short *)(iVar2 + 0x400000) < 0) {
          uVar5 = *(ushort *)(iVar2 + 0x400000) | 0xffff0000;
        }
        aiStackY_68[0] = uStackY_70 + ((uVar5 - 0x400000) - iVar9);
        iStackY_74 = iVar2;
        *(undefined4 *)((int)auStackY_8c + iVar3 + -4) = 0x405275;
        FUN_00404f20();
        *(undefined2 *)(iStackY_74 + 0x400000) = (undefined2)aiStackY_68[0];
      }
      else if (uVar5 == 0x20) {
        iVar9 = uStackY_70 + ((*(int *)pbVar1 + -0x400000) - *piVar10);
        aiStackY_68[0] = iVar9;
        *(undefined4 *)((int)auStackY_8c + iVar3 + -4) = 0x4052de;
        FUN_00404f20();
        *(int *)pbVar1 = iVar9;
      }
      else {
        if (uVar5 != 8) {
          *(uint *)((int)auStackY_8c + iVar3 + 4) = uVar5;
          *(char **)((int)auStackY_8c + iVar3) = "  Unknown pseudo relocation bit size %d.\n";
          *(undefined4 *)((int)auStackY_8c + iVar3 + -4) = 0x40515a;
          pDVar6 = (PDWORD)FUN_00404ec0(*(char **)((int)auStackY_8c + iVar3));
          return pDVar6;
        }
        uVar5 = (uint)*pbVar1;
        if ((char)*pbVar1 < '\0') {
          uVar5 = *pbVar1 | 0xffffff00;
        }
        aiStackY_68[0] = uStackY_70 + ((uVar5 - 0x400000) - iVar9);
        *(undefined4 *)((int)auStackY_8c + iVar3 + -4) = 0x4052be;
        FUN_00404f20();
        *pbVar1 = (byte)aiStackY_68[0];
      }
      piVar10 = piVar10 + 3;
    } while (piVar10 < &DAT_0040b000);
    goto LAB_004051a2;
  }
LAB_00405307:
  piVar15[1] = iVar9;
  *piVar15 = (int)"  Unknown pseudo relocation protocol version %d.\n";
  piVar15[-1] = 0x405317;
  FUN_00404ec0((char *)*piVar15);
  *piVar15 = (int)&stack0xffffffcc;
  piVar15[-1] = (int)piVar10;
  puVar16 = (undefined4 *)piVar15[2];
  uVar5 = *(uint *)*puVar16;
  if (uVar5 < 0xc0000092) {
    if (0xc000008c < uVar5) {
LAB_004053f0:
      piVar15[-5] = 0;
      piVar15[-6] = 8;
      piVar15[-7] = 0x405404;
      signal(piVar15[-6]);
      pcVar7 = extraout_EAX_01;
      if (extraout_EAX_01 == (code *)0x1) {
        piVar15[-5] = 1;
        piVar15[-6] = 8;
        piVar15[-7] = 0x40541d;
        signal(piVar15[-6]);
        piVar15[-7] = 0x405422;
        FUN_00404e90();
        return (PDWORD)0xffffffff;
      }
LAB_004053cd:
      if (pcVar7 != (code *)0x0) {
        piVar15[-6] = 8;
        piVar15[-7] = 0x4053da;
        (*pcVar7)();
        return (PDWORD)0xffffffff;
      }
      goto LAB_00405399;
    }
    if (uVar5 == 0xc0000005) {
      piVar15[-5] = 0;
      piVar15[-6] = 0xb;
      piVar15[-7] = 0x40535f;
      signal(piVar15[-6]);
      if (extraout_EAX == (code *)0x1) {
        piVar15[-5] = 1;
        piVar15[-6] = 0xb;
        piVar15[-7] = 0x405494;
        signal(piVar15[-6]);
        return (PDWORD)0xffffffff;
      }
      if (extraout_EAX != (code *)0x0) {
        piVar15[-6] = 0xb;
        piVar15[-7] = 0x405375;
        (*extraout_EAX)();
        return (PDWORD)0xffffffff;
      }
      goto LAB_00405399;
    }
    if (uVar5 != 0xc000001d) goto LAB_00405399;
  }
  else {
    if (uVar5 == 0xc0000094) {
      piVar15[-5] = 0;
      piVar15[-6] = 8;
      piVar15[-7] = 0x4053c4;
      signal(piVar15[-6]);
      pcVar7 = extraout_EAX_00;
      if (extraout_EAX_00 == (code *)0x1) {
        piVar15[-5] = 1;
        piVar15[-6] = 8;
        piVar15[-7] = 0x4054b4;
        signal(piVar15[-6]);
        return (PDWORD)0xffffffff;
      }
      goto LAB_004053cd;
    }
    if (uVar5 != 0xc0000096) {
      if (uVar5 != 0xc0000093) goto LAB_00405399;
      goto LAB_004053f0;
    }
  }
  piVar15[-5] = 0;
  piVar15[-6] = 4;
  piVar15[-7] = 0x405443;
  signal(piVar15[-6]);
  if (extraout_EAX_02 == (code *)0x1) {
    piVar15[-5] = 1;
    piVar15[-6] = 4;
    piVar15[-7] = 0x405474;
    signal(piVar15[-6]);
  }
  else {
    if (extraout_EAX_02 == (code *)0x0) {
LAB_00405399:
      if (DAT_0040d46c != (code *)0x0) {
        piVar15[2] = (int)puVar16;
                    /* WARNING: Could not recover jumptable at 0x004053a9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        pDVar6 = (PDWORD)(*DAT_0040d46c)();
        return pDVar6;
      }
      return (PDWORD)0x0;
    }
    piVar15[-6] = 4;
    piVar15[-7] = 0x405459;
    (*extraout_EAX_02)();
  }
  return (PDWORD)0xffffffff;
}



/* 00405060 FUN_00405060 */

/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x00405223) */
/* WARNING: Type propagation algorithm not settling */

int * FUN_00405060(void)

{
  byte *pbVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int *piVar5;
  SIZE_T SVar6;
  int iVar7;
  code *extraout_EAX;
  code *extraout_EAX_00;
  code *pcVar8;
  code *extraout_EAX_01;
  code *extraout_EAX_02;
  int iVar9;
  int *piVar10;
  int *piVar11;
  int *piVar12;
  int *piVar13;
  int *piVar14;
  int *piVar15;
  undefined4 uStack_60;
  uint auStack_5c [6];
  int local_44;
  undefined4 local_40;
  undefined1 local_3c [4];
  int local_38 [3];
  int local_2c;
  
  if (DAT_0040d45c != (int *)0x0) {
    return DAT_0040d45c;
  }
  DAT_0040d45c = (int *)0x1;
  uStack_60 = 0x405088;
  FUN_004058a0();
  uStack_60 = 0x40509a;
  uVar4 = FUN_00405e28();
  DAT_0040d460 = (int *)0x0;
  iVar9 = -uVar4;
  piVar15 = (int *)((int)auStack_5c + iVar9);
  piVar14 = (int *)((int)auStack_5c + iVar9);
  DAT_0040d464 = (uint)(local_3c + iVar9 + -1) & 0xfffffff0;
  piVar5 = DAT_0040afa0;
  if ((DAT_0040afa0 != (int *)0x0) || (piVar5 = DAT_0040afa4, DAT_0040afa4 != (int *)0x0)) {
    piVar11 = (int *)&DAT_0040afa0;
LAB_0040516d:
    if (&UNK_0040afff < piVar11) {
      DAT_0040d460 = (int *)0x0;
      return piVar5;
    }
    do {
      iVar7 = piVar11[1];
      local_38[0] = *piVar11;
      piVar11 = piVar11 + 2;
      local_38[0] = local_38[0] + *(int *)(iVar7 + 0x400000);
      *(undefined4 *)((int)auStack_5c + iVar9 + -4) = 0x405191;
      FUN_00404f20();
      *(int *)(iVar7 + 0x400000) = local_38[0];
    } while (piVar11 < &DAT_0040b000);
LAB_004051a2:
    piVar10 = (int *)0x0;
    piVar5 = DAT_0040d460;
    if (0 < (int)DAT_0040d460) {
      do {
        piVar5 = (int *)(DAT_0040d464 + (int)piVar10 * 0xc);
        if (*piVar5 != 0) {
          piVar14[2] = 0x1c;
          piVar14[1] = (int)local_38;
          *piVar14 = piVar5[1];
          piVar12 = piVar14 + -1;
          piVar14[-1] = 0x4051ed;
          SVar6 = VirtualQuery((LPCVOID)*piVar14,(PMEMORY_BASIC_INFORMATION)piVar14[1],piVar14[2]);
          if (SVar6 == 0) {
            iVar9 = DAT_0040d464 + (int)piVar10 * 0xc;
            piVar12[-1] = *(int *)(iVar9 + 4);
            iVar9 = *(int *)(*(int *)(iVar9 + 8) + 8);
            piVar12[-3] = (int)"  VirtualQuery failed for %d bytes at address %p";
            piVar12[-2] = iVar9;
            piVar12[-4] = 0x405307;
            iVar7 = FUN_00404ec0((char *)piVar12[-3]);
            piVar15 = piVar12 + -2;
            goto LAB_00405307;
          }
          *piVar12 = (int)local_3c;
          piVar12[-1] = *(int *)(DAT_0040d464 + (int)piVar10 * 0xc);
          piVar12[-2] = local_2c;
          piVar12[-3] = local_38[0];
          piVar13 = piVar12 + -4;
          piVar12[-4] = 0x40521e;
          piVar5 = (int *)VirtualProtect((LPVOID)piVar12[-3],piVar12[-2],piVar12[-1],
                                         (PDWORD)*piVar12);
          piVar14 = (int *)((int)piVar13 + -0x10);
        }
        piVar10 = (int *)((int)piVar10 + 1);
      } while ((int)piVar10 < (int)DAT_0040d460);
    }
    return piVar5;
  }
  piVar10 = &DAT_0040afac;
  if (DAT_0040afa8 == 0) {
    piVar11 = piVar10;
    if ((DAT_0040afac != 0) || (piVar11 = &DAT_0040afac, DAT_0040afb0 != 0)) goto LAB_0040516d;
  }
  else {
    piVar10 = (int *)&DAT_0040afa0;
  }
  iVar7 = piVar10[2];
  if (iVar7 == 1) {
    piVar10 = piVar10 + 3;
    if (&UNK_0040afff < piVar10) {
      DAT_0040d460 = (int *)0x0;
      return (int *)0x1;
    }
    do {
      iVar7 = *piVar10;
      iVar2 = piVar10[1];
      local_40 = *(int *)(iVar7 + 0x400000);
      pbVar1 = (byte *)(iVar2 + 0x400000);
      uVar4 = (uint)*(byte *)(piVar10 + 2);
      if (uVar4 == 0x10) {
        uVar4 = (uint)*(ushort *)(iVar2 + 0x400000);
        if (*(short *)(iVar2 + 0x400000) < 0) {
          uVar4 = *(ushort *)(iVar2 + 0x400000) | 0xffff0000;
        }
        local_38[0] = local_40 + ((uVar4 - 0x400000) - iVar7);
        local_44 = iVar2;
        *(undefined4 *)((int)auStack_5c + iVar9 + -4) = 0x405275;
        FUN_00404f20();
        *(undefined2 *)(local_44 + 0x400000) = (undefined2)local_38[0];
      }
      else if (uVar4 == 0x20) {
        iVar7 = local_40 + ((*(int *)pbVar1 + -0x400000) - *piVar10);
        local_38[0] = iVar7;
        *(undefined4 *)((int)auStack_5c + iVar9 + -4) = 0x4052de;
        FUN_00404f20();
        *(int *)pbVar1 = iVar7;
      }
      else {
        if (uVar4 != 8) {
          *(uint *)((int)auStack_5c + iVar9 + 4) = uVar4;
          *(char **)((int)auStack_5c + iVar9) = "  Unknown pseudo relocation bit size %d.\n";
          *(undefined4 *)((int)auStack_5c + iVar9 + -4) = 0x40515a;
          piVar5 = (int *)FUN_00404ec0(*(char **)((int)auStack_5c + iVar9));
          return piVar5;
        }
        uVar4 = (uint)*pbVar1;
        if ((char)*pbVar1 < '\0') {
          uVar4 = *pbVar1 | 0xffffff00;
        }
        local_38[0] = local_40 + ((uVar4 - 0x400000) - iVar7);
        *(undefined4 *)((int)auStack_5c + iVar9 + -4) = 0x4052be;
        FUN_00404f20();
        *pbVar1 = (byte)local_38[0];
      }
      piVar10 = piVar10 + 3;
    } while (piVar10 < &DAT_0040b000);
    goto LAB_004051a2;
  }
LAB_00405307:
  piVar15[1] = iVar7;
  *piVar15 = (int)"  Unknown pseudo relocation protocol version %d.\n";
  piVar15[-1] = 0x405317;
  FUN_00404ec0((char *)*piVar15);
  *piVar15 = (int)&stack0xfffffffc;
  piVar15[-1] = (int)piVar10;
  puVar3 = (undefined4 *)piVar15[2];
  uVar4 = *(uint *)*puVar3;
  if (uVar4 < 0xc0000092) {
    if (0xc000008c < uVar4) {
LAB_004053f0:
      piVar15[-5] = 0;
      piVar15[-6] = 8;
      piVar15[-7] = 0x405404;
      signal(piVar15[-6]);
      pcVar8 = extraout_EAX_01;
      if (extraout_EAX_01 == (code *)0x1) {
        piVar15[-5] = 1;
        piVar15[-6] = 8;
        piVar15[-7] = 0x40541d;
        signal(piVar15[-6]);
        piVar15[-7] = 0x405422;
        FUN_00404e90();
        return (int *)0xffffffff;
      }
LAB_004053cd:
      if (pcVar8 != (code *)0x0) {
        piVar15[-6] = 8;
        piVar15[-7] = 0x4053da;
        (*pcVar8)();
        return (int *)0xffffffff;
      }
      goto LAB_00405399;
    }
    if (uVar4 == 0xc0000005) {
      piVar15[-5] = 0;
      piVar15[-6] = 0xb;
      piVar15[-7] = 0x40535f;
      signal(piVar15[-6]);
      if (extraout_EAX == (code *)0x1) {
        piVar15[-5] = 1;
        piVar15[-6] = 0xb;
        piVar15[-7] = 0x405494;
        signal(piVar15[-6]);
        return (int *)0xffffffff;
      }
      if (extraout_EAX != (code *)0x0) {
        piVar15[-6] = 0xb;
        piVar15[-7] = 0x405375;
        (*extraout_EAX)();
        return (int *)0xffffffff;
      }
      goto LAB_00405399;
    }
    if (uVar4 != 0xc000001d) goto LAB_00405399;
  }
  else {
    if (uVar4 == 0xc0000094) {
      piVar15[-5] = 0;
      piVar15[-6] = 8;
      piVar15[-7] = 0x4053c4;
      signal(piVar15[-6]);
      pcVar8 = extraout_EAX_00;
      if (extraout_EAX_00 == (code *)0x1) {
        piVar15[-5] = 1;
        piVar15[-6] = 8;
        piVar15[-7] = 0x4054b4;
        signal(piVar15[-6]);
        return (int *)0xffffffff;
      }
      goto LAB_004053cd;
    }
    if (uVar4 != 0xc0000096) {
      if (uVar4 != 0xc0000093) goto LAB_00405399;
      goto LAB_004053f0;
    }
  }
  piVar15[-5] = 0;
  piVar15[-6] = 4;
  piVar15[-7] = 0x405443;
  signal(piVar15[-6]);
  if (extraout_EAX_02 == (code *)0x1) {
    piVar15[-5] = 1;
    piVar15[-6] = 4;
    piVar15[-7] = 0x405474;
    signal(piVar15[-6]);
  }
  else {
    if (extraout_EAX_02 == (code *)0x0) {
LAB_00405399:
      if (DAT_0040d46c != (code *)0x0) {
        piVar15[2] = (int)puVar3;
                    /* WARNING: Could not recover jumptable at 0x004053a9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        piVar5 = (int *)(*DAT_0040d46c)();
        return piVar5;
      }
      return (int *)0x0;
    }
    piVar15[-6] = 4;
    piVar15[-7] = 0x405459;
    (*extraout_EAX_02)();
  }
  return (int *)0xffffffff;
}



/* 004054c0 FUN_004054c0 */

void FUN_004054c0(void)

{
  DWORD *pDVar1;
  LPVOID pvVar2;
  DWORD DVar3;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0040d478);
  for (pDVar1 = DAT_0040d470; pDVar1 != (DWORD *)0x0; pDVar1 = (DWORD *)pDVar1[2]) {
    pvVar2 = TlsGetValue(*pDVar1);
    DVar3 = GetLastError();
    if ((DVar3 == 0) && (pvVar2 != (LPVOID)0x0)) {
      (*(code *)pDVar1[1])(pvVar2);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0040d478);
  return;
}



/* 00405650 FUN_00405650 */

undefined4 __cdecl FUN_00405650(undefined4 param_1,int param_2)

{
  void *pvVar1;
  void *_Memory;
  
  if (param_2 == 1) {
    if (DAT_0040d474 == 0) {
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_0040d478);
    }
    DAT_0040d474 = 1;
    return 1;
  }
  if (param_2 == 0) {
    if (DAT_0040d474 != 0) {
      FUN_004054c0();
    }
    if (DAT_0040d474 == 1) {
      DAT_0040d474 = 1;
      _Memory = DAT_0040d470;
      while (_Memory != (void *)0x0) {
        pvVar1 = *(void **)((int)_Memory + 8);
        free(_Memory);
        _Memory = pvVar1;
      }
      DAT_0040d470 = (void *)0x0;
      DAT_0040d474 = 0;
      DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_0040d478);
    }
  }
  else if ((param_2 == 3) && (DAT_0040d474 != 0)) {
    FUN_004054c0();
  }
  return 1;
}



/* 00405730 FUN_00405730 */

bool FUN_00405730(void)

{
  int in_EAX;
  int *piVar1;
  
  piVar1 = (int *)(in_EAX + *(int *)(in_EAX + 0x3c));
  if (*piVar1 != 0x4550) {
    return false;
  }
  return (short)piVar1[6] == 0x10b;
}



/* 00405770 FUN_00405770 */

int __cdecl FUN_00405770(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = param_1 + *(int *)(param_1 + 0x3c);
  iVar1 = iVar3 + 0x18 + (uint)*(ushort *)(iVar3 + 0x14);
  if (*(ushort *)(iVar3 + 6) != 0) {
    uVar2 = 0;
    do {
      if ((*(uint *)(iVar1 + 0xc) <= param_2) &&
         (param_2 < *(uint *)(iVar1 + 0xc) + *(int *)(iVar1 + 8))) {
        return iVar1;
      }
      uVar2 = uVar2 + 1;
      iVar1 = iVar1 + 0x28;
    } while (uVar2 != *(ushort *)(iVar3 + 6));
  }
  return 0;
}



/* 00405850 FUN_00405850 */

int __cdecl FUN_00405850(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  
  if (IMAGE_DOS_HEADER_00400000.e_magic == (char  [2])0x5a4d) {
    bVar1 = FUN_00405730();
    if (CONCAT31(extraout_var,bVar1) != 0) {
      iVar2 = FUN_00405770(0x400000,param_1 - 0x400000);
      return iVar2;
    }
  }
  return 0;
}



/* 004058a0 FUN_004058a0 */

int FUN_004058a0(void)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  
  iVar2 = 0;
  if (IMAGE_DOS_HEADER_00400000.e_magic == (char  [2])0x5a4d) {
    bVar1 = FUN_00405730();
    iVar2 = CONCAT31(extraout_var,bVar1);
    if (iVar2 != 0) {
      return (uint)*(ushort *)
                    (IMAGE_DOS_HEADER_00400000.e_magic + IMAGE_DOS_HEADER_00400000.e_lfanew + 6);
    }
  }
  return iVar2;
}



/* 00405950 FUN_00405950 */

undefined4 FUN_00405950(void)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (IMAGE_DOS_HEADER_00400000.e_magic != (char  [2])0x5a4d) {
    return 0;
  }
  bVar1 = FUN_00405730();
  if (CONCAT31(extraout_var,bVar1) != 0) {
    uVar2 = 0x400000;
  }
  return uVar2;
}



/* 00405a80 FUN_00405a80 */

undefined4 FUN_00405a80(void)

{
  LPCWSTR lpWideCharStr;
  LPWSTR lpCmdLine;
  LPWSTR *cbMultiByte;
  char **ppcVar1;
  uint uVar2;
  LPSTR lpMultiByteStr;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  HLOCAL pvStack_2c;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  
  lpCmdLine = GetCommandLineW();
  cbMultiByte = CommandLineToArgvW(lpCmdLine,&iStack_20);
  if (cbMultiByte == (LPWSTR *)0x0) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar2 = 0xffffffff;
    if (iStack_20 + 1U < 0x1fc00001) {
      uVar2 = (iStack_20 + 1U) * 4;
    }
    ppcVar1 = (char **)operator_new__(uVar2);
    if (0 < iStack_1c) {
      iVar5 = 0;
      do {
        lpWideCharStr = *(LPCWSTR *)((int)pvStack_2c + iVar5 * 4);
        uVar2 = WideCharToMultiByte(uVar2,0,(LPCWSTR)0x0,(int)lpWideCharStr,(LPSTR)0xffffffff,0,
                                    (LPCSTR)0x0,(LPBOOL)0x0);
        lpMultiByteStr = (LPSTR)operator_new__(uVar2);
        uVar2 = 0x405b76;
        WideCharToMultiByte(0,0,lpWideCharStr,-1,lpMultiByteStr,(int)cbMultiByte,(LPCSTR)0x0,
                            (LPBOOL)0x0);
        ppcVar1[iVar5] = lpMultiByteStr;
        iVar5 = iVar5 + 1;
      } while (iVar5 < iStack_1c);
    }
    ppcVar1[iStack_1c] = (char *)0x0;
    LocalFree(pvStack_2c);
    uVar3 = FUN_004016c0(iStack_1c,ppcVar1);
    if ((0 < iStack_1c) && (pcVar4 = *ppcVar1, pcVar4 != (char *)0x0)) {
      iVar5 = 0;
      do {
        iVar5 = iVar5 + 1;
        operator_delete__(pcVar4);
        if (iStack_18 <= iVar5) break;
        pcVar4 = ppcVar1[iVar5];
      } while (pcVar4 != (char *)0x0);
    }
    operator_delete__(ppcVar1);
  }
  return uVar3;
}



/* 00405e28 FUN_00405e28 */

uint FUN_00405e28(void)

{
  uint in_EAX;
  uint uVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)&stack0x00000004;
  uVar1 = in_EAX;
  if (0xfff < in_EAX) {
    do {
      puVar2 = puVar2 + -0x400;
      *puVar2 = *puVar2;
      uVar1 = uVar1 - 0x1000;
    } while (0x1000 < uVar1);
  }
  *(undefined4 *)((int)puVar2 - uVar1) = *(undefined4 *)((int)puVar2 - uVar1);
  return in_EAX;
}



/* 00405e60 FUN_00405e60 */

undefined4 __cdecl FUN_00405e60(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x16;
  if ((param_1 < 1000000) && (uVar1 = 0, param_1 != 0)) {
    Sleep(param_1 / 1000);
    return 0;
  }
  return uVar1;
}



/* 00405f70 FUN_00405f70 */

undefined4 __cdecl FUN_00405f70(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_0040d494;
  LOCK();
  DAT_0040d494 = param_1;
  UNLOCK();
  return uVar1;
}



/* 00405f90 FUN_00405f90 */

undefined4 __cdecl
FUN_00405f90(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  size_t _Size;
  char *pcVar1;
  char *_Str;
  size_t _Size_00;
  undefined4 uVar2;
  int iVar3;
  undefined1 **ppuVar4;
  char *local_110;
  QArrayData *local_104;
  QArrayData *local_100;
  size_t local_fc;
  size_t local_f8;
  char *local_f4;
  char local_ec [48];
  size_t local_bc;
  size_t local_b8;
  char *local_b4;
  char local_ac [64];
  undefined1 *local_6c [5];
  QArrayData *local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined *local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  _Str = (char *)QMetaObject::className();
  _Size_00 = strlen(_Str);
  local_fc = _Size_00 + 2;
  local_f8 = local_fc;
  if ((int)local_fc < 0x31) {
    local_f4 = local_ec;
    local_fc = 0x30;
  }
  else {
    local_f4 = (char *)malloc(local_fc);
    if (local_f4 == (char *)0x0) {
      qBadAlloc();
      local_fc = local_f8;
    }
  }
  local_110 = local_ec;
  _Size = _Size_00 + 0x13;
  memcpy(local_f4,_Str,_Size_00);
  local_f4[_Size_00] = '*';
  local_f4[_Size_00 + 1] = '\0';
  local_b8 = _Size;
  if ((int)_Size < 0x41) {
    local_b4 = local_ac;
    local_bc = 0x40;
  }
  else {
    local_b4 = (char *)malloc(_Size);
    local_bc = _Size;
    if (local_b4 == (char *)0x0) {
      qBadAlloc();
      local_bc = local_b8;
    }
  }
  pcVar1 = local_b4;
  builtin_strncpy(local_b4,"QQmlListProperty<",0x11);
  memcpy(local_b4 + 0x11,_Str,_Size_00);
  pcVar1[_Size_00 + 0x11] = '>';
  local_b4[_Size_00 + 0x12] = '\0';
  ppuVar4 = local_6c;
  for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppuVar4 = (undefined1 *)0x0;
    ppuVar4 = ppuVar4 + 1;
  }
  local_6c[3] = (undefined1 *)0x1c;
  local_6c[4] = &LAB_00406530;
  local_44 = &DAT_00408020;
  QByteArray::QByteArray((QByteArray *)&local_104,local_f4,-1);
  local_6c[1] = (undefined1 *)FUN_00406350((QByteArray *)&local_104,0,1);
  if (*(int *)local_104 == 0) {
LAB_00406221:
    QArrayData::deallocate(local_104,1,4);
  }
  else if (*(int *)local_104 != -1) {
    LOCK();
    *(int *)local_104 = *(int *)local_104 + -1;
    UNLOCK();
    if (*(int *)local_104 == 0) goto LAB_00406221;
  }
  QByteArray::QByteArray((QByteArray *)&local_100,local_b4,-1);
  local_6c[2] = (undefined1 *)
                QMetaType::registerNormalizedType
                          ((QByteArray *)&local_100,&DAT_004065a0,&LAB_004065b0,0x20,3,0);
  if (*(int *)local_100 == 0) {
LAB_00406263:
    QArrayData::deallocate(local_100,1,4);
  }
  else if (*(int *)local_100 != -1) {
    LOCK();
    *(int *)local_100 = *(int *)local_100 + -1;
    UNLOCK();
    if (*(int *)local_100 == 0) goto LAB_00406263;
  }
  local_40 = 0;
  local_3c = 0;
  local_38 = 0xffffffff;
  local_34 = 0xffffffff;
  local_30 = 0xffffffff;
  local_58 = (QArrayData *)shared_null_exref;
  local_54 = param_1;
  local_50 = param_2;
  local_4c = param_3;
  local_48 = param_4;
  uVar2 = QQmlPrivate::qmlregister(0,local_6c);
  if (*(int *)local_58 != 0) {
    if (*(int *)local_58 == -1) goto LAB_004061e9;
    LOCK();
    *(int *)local_58 = *(int *)local_58 + -1;
    UNLOCK();
    if (*(int *)local_58 != 0) goto LAB_004061e9;
  }
  QArrayData::deallocate(local_58,2,4);
LAB_004061e9:
  if (local_b4 != local_ac) {
    free(local_b4);
  }
  if (local_f4 != local_110) {
    free(local_f4);
  }
  return uVar2;
}



/* 00406350 FUN_00406350 */

void __cdecl FUN_00406350(QByteArray *param_1,int param_2,int param_3)

{
  char *_Str;
  size_t sVar1;
  int iVar2;
  uint uVar3;
  QArrayData *local_20 [4];
  
  if (param_2 != 0) goto LAB_00406363;
  iVar2 = DAT_0040805c;
  if (DAT_0040805c == 0) {
    _Str = (char *)QMetaObject::className();
    local_20[0] = (QArrayData *)shared_null_exref;
    sVar1 = strlen(_Str);
    if ((*(uint *)shared_null_exref < 2) &&
       (sVar1 + 2 <= (*(uint *)(shared_null_exref + 8) & 0x7fffffff))) {
      shared_null_exref[0xb] = (code)((byte)shared_null_exref[0xb] | 0x80);
    }
    else {
      uVar3 = sVar1 + 1;
      if (sVar1 + 1 <= *(uint *)(shared_null_exref + 4)) {
        uVar3 = *(uint *)(shared_null_exref + 4);
      }
      QByteArray::reallocData(uVar3 + 1,1);
    }
    QByteArray::append(_Str);
    QByteArray::append('*');
    iVar2 = FUN_00406350((QByteArray *)local_20,-1,1);
    DAT_0040805c = iVar2;
    if (*(int *)local_20[0] == 0) {
LAB_00406490:
      QArrayData::deallocate(local_20[0],1,4);
    }
    else if (*(int *)local_20[0] != -1) {
      LOCK();
      *(int *)local_20[0] = *(int *)local_20[0] + -1;
      UNLOCK();
      if (*(int *)local_20[0] == 0) goto LAB_00406490;
    }
  }
  if (iVar2 != -1) {
    QMetaType::registerNormalizedTypedef(param_1,iVar2);
    return;
  }
LAB_00406363:
  QMetaType::registerNormalizedType
            (param_1,&DAT_00406630,&LAB_00406640,4,(-(uint)(param_3 == 0) & 0xffffff00) + 0x10c,
             &DAT_00408020);
  return;
}



/* 00406660 FUN_00406660 */

void __fastcall FUN_00406660(undefined4 *param_1)

{
  int iVar1;
  QSerialPortInfo *this;
  Data *pDVar2;
  Data *pDVar3;
  
  pDVar3 = (Data *)*param_1;
  if (*(int *)pDVar3 == 0) {
LAB_00406684:
    pDVar2 = pDVar3 + *(int *)(pDVar3 + 0xc) * 4 + 0x10;
    iVar1 = *(int *)(pDVar3 + 8);
    while (pDVar2 != pDVar3 + iVar1 * 4 + 0x10) {
      pDVar2 = pDVar2 + -4;
      this = *(QSerialPortInfo **)pDVar2;
      if (this != (QSerialPortInfo *)0x0) {
        QSerialPortInfo::~QSerialPortInfo(this);
        operator_delete(this);
      }
    }
    QListData::dispose(pDVar3);
    return;
  }
  if (*(int *)pDVar3 != -1) {
    LOCK();
    *(int *)pDVar3 = *(int *)pDVar3 + -1;
    UNLOCK();
    if (*(int *)pDVar3 == 0) {
      pDVar3 = (Data *)*param_1;
      goto LAB_00406684;
    }
  }
  return;
}



/* 004066d0 FUN_004066d0 */

void __thiscall FUN_004066d0(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
                    /* WARNING: Load size is inaccurate */
  puVar7 = (undefined4 *)(*this + 0x10 + *(int *)(*this + 8) * 4);
  piVar4 = (int *)QListData::detach(param_1);
                    /* WARNING: Load size is inaccurate */
  iVar1 = *this;
  iVar2 = *(int *)(iVar1 + 0xc);
  for (puVar6 = (undefined4 *)(iVar1 + 0x10 + *(int *)(iVar1 + 8) * 4);
      puVar6 != (undefined4 *)(iVar1 + 0x10 + iVar2 * 4); puVar6 = puVar6 + 1) {
    puVar5 = (undefined4 *)operator_new(4);
    puVar3 = (undefined4 *)*puVar7;
    puVar7 = puVar7 + 1;
    *puVar5 = *puVar3;
    *puVar6 = puVar5;
  }
  if (*piVar4 != 0) {
    if (*piVar4 != -1) {
      LOCK();
      *piVar4 = *piVar4 + -1;
      UNLOCK();
      if (*piVar4 == 0) goto LAB_00406754;
    }
    return;
  }
LAB_00406754:
  FUN_004031f0();
  return;
}



/* 004067d0 FUN_004067d0 */

int __thiscall FUN_004067d0(void *this,int param_1,int param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  int *piVar10;
  int *piVar11;
  
                    /* WARNING: Load size is inaccurate */
  piVar11 = (int *)(*this + 0x10 + *(int *)(*this + 8) * 4);
  piVar2 = (int *)QListData::detach_grow(&param_1,param_2);
                    /* WARNING: Load size is inaccurate */
  iVar8 = *this;
  iVar5 = iVar8 + 0x10;
  iVar4 = *(int *)(iVar8 + 8) * 4;
  puVar9 = (undefined4 *)(iVar5 + iVar4);
  puVar1 = puVar9 + param_1;
  iVar6 = param_1;
  piVar10 = piVar11;
  if (puVar1 != puVar9) {
    do {
      puVar3 = (undefined4 *)operator_new(4);
      puVar7 = puVar9 + 1;
      *puVar3 = *(undefined4 *)*piVar10;
      *puVar9 = puVar3;
      puVar9 = puVar7;
      piVar10 = piVar10 + 1;
    } while (puVar1 != puVar7);
    iVar8 = *piVar11;
    iVar5 = iVar8 + 0x10;
    iVar4 = *(int *)(iVar8 + 8) << 2;
    iVar6 = param_2;
  }
  iVar8 = *(int *)(iVar8 + 0xc);
  piVar11 = piVar11 + iVar6;
  for (puVar9 = (undefined4 *)(iVar4 + (iVar6 + param_2) * 4 + iVar5);
      puVar9 != (undefined4 *)(iVar5 + iVar8 * 4); puVar9 = puVar9 + 1) {
    puVar3 = (undefined4 *)operator_new(4);
    puVar1 = (undefined4 *)*piVar11;
    piVar11 = piVar11 + 1;
    *puVar3 = *puVar1;
    *puVar9 = puVar3;
  }
  if (*piVar2 != 0) {
    if (*piVar2 == -1) goto LAB_004068bd;
    LOCK();
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (*piVar2 != 0) goto LAB_004068bd;
  }
  FUN_004031f0();
LAB_004068bd:
                    /* WARNING: Load size is inaccurate */
  return *this + 0x10 + (*(int *)(*this + 8) + param_1) * 4;
}



/* 004069e0 FUN_004069e0 */

void __thiscall FUN_004069e0(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
                    /* WARNING: Load size is inaccurate */
  if (1 < **this) {
    puVar1 = (undefined4 *)FUN_004067d0(this,0x7fffffff,1);
    puVar2 = (undefined4 *)operator_new(4);
    *puVar2 = *param_1;
    *puVar1 = puVar2;
    return;
  }
  puVar1 = (undefined4 *)QListData::append();
  puVar2 = (undefined4 *)operator_new(4);
  *puVar2 = *param_1;
  *puVar1 = puVar2;
  return;
}



/* 00406ae0 FUN_00406ae0 */

void FUN_00406ae0(void)

{
  DAT_0040d040 = 0;
  QMutex::QMutex((QMutex *)&DAT_0040d044,0);
  FUN_00404ad0((_onexit_t)&LAB_00401640);
  DAT_0040d03c = shared_null_exref;
  FUN_00404ad0((_onexit_t)&LAB_00401650);
  std::ios_base::Init::Init((Init *)&DAT_0040d038);
  FUN_00404ad0((_onexit_t)&LAB_00401630);
  return;
}



/* 00406d30 FUN_00406d30 */

void FUN_00406d30(void)

{
  FUN_00404b70();
  FUN_00405a80();
  return;
}


