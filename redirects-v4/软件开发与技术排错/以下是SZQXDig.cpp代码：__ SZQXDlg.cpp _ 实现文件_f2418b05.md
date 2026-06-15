---
title: "以下是SZQXDig.cpp代码：// SZQXDlg.cpp : 实现文件"
source_platform: "DeepSeek"
source_file: "SLM全息再现异常问题分析与解决.md"
turn_start: 17
turn_end: 17
primary_category: "软件开发与技术排错"
tags:
  - "大恒相机"
  - "脉冲测距"
  - "状态栏"
project_id: "d22b651400-software-03"
stage: "独立主题"
previous_slice: null
next_slice: null
has_attachment: false
attachment_context_confidence: not_applicable
classification_confidence: 0.97
---

# 以下是SZQXDig.cpp代码：// SZQXDlg.cpp : 实现文件

## 问题摘要

本切片围绕“以下是SZQXDig.cpp代码：// SZQXDlg.cpp : 实现文件”展开。起始诉求是：以下是SZQXDig.cpp代码：// SZQXDlg.cpp : 实现文件 //***************************************************************** //关于目前4个子功能模块与相机采集程序的逻辑关系。有必要作以下的…内容覆盖原始对话 T17-T17。

## 原始对话

pp`或父对话框类中。

# 用户：

以下是SZQXDig.cpp代码：// SZQXDlg.cpp : 实现文件
//*****************************************************************
//关于目前4个子功能模块与相机采集程序的逻辑关系。有必要作以下的说明
//目前由于两个功能模块需要相机采集（Opt2Dig,Opt2Opt）而且这两个相机
//采集的分辨率不一样，所以分别在两个模块中加入独立的相机采集程序。
//
//每次运行，程序的工作流程如下：
//点击模块-》判断是否有相机：（有）启动界面上的相机相关按钮。
//（无）禁用相机相关按钮。
//
//点击（Opt2Dig,Opt2Opt）这两个模块时，判断是否之前启用相机，（是）关闭相机
//（否）继续启动功能模块。并根据所在模块重置相机分辨率
//（Opt2Dig,Opt2Opt）这两个模块启动前，会检测相机是否连上。
//
//若以后需要3个或以上的功能模块需要相机，则这个程序需要重新改动。
//建议：直接将相机采集程序抽出来独立成一模块。
//*********************************************************************************


#include "stdafx.h"
#include "SZQX.h"
#include "SZQXDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSZQXDlg 对话框

CSZQXDlg::CSZQXDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSZQXDlg::IDD, pParent)
	, nEditGain(0)
	, nEditExposure(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//初始化5个子对话框
	pDig2Dig = NULL;
	pDig2Opt = NULL;
	pOpt2Dig = NULL;
	pOpt2Opt = NULL;
	pInfo_Security = NULL;

	m_bSnapping = false;

	m_bStartSign = false;

	m_nChoicCCDModel = 1;//默认选择光学再现
}

void CSZQXDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_sbGain, sbGain);
	DDX_Control(pDX, IDC_sbExposure, sbShutter);
	DDX_Text(pDX, IDC_editGain, nEditGain);
	DDV_MinMaxInt(pDX, nEditGain, 0, 60);
	DDX_Text(pDX, IDC_editExposure, nEditExposure);
	DDV_MinMaxInt(pDX, nEditExposure, 0, 999);
	DDX_Control(pDX, IDC_cbbADC, cbbADC);
}

BEGIN_MESSAGE_MAP(CSZQXDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_btnReset, &CSZQXDlg::OnBnClickedbtnreset)
	ON_BN_CLICKED(IDC_rbDig2Dig, &CSZQXDlg::OnBnClickedrbdig2dig)
	ON_BN_CLICKED(IDC_rbOpt2Dig, &CSZQXDlg::OnBnClickedrbopt2dig)
	ON_BN_CLICKED(IDC_rbDig2Opt, &CSZQXDlg::OnBnClickedrbdig2opt)
	ON_BN_CLICKED(IDC_btnSnap, &CSZQXDlg::OnBnClickedbtnsnap)
	ON_BN_CLICKED(IDC_btnSaveBMP, &CSZQXDlg::OnBnClickedbtnsavebmp)
	ON_WM_HSCROLL()
	ON_EN_CHANGE(IDC_editGain, &CSZQXDlg::OnEnChangeeditgain)
	ON_EN_CHANGE(IDC_editExposure, &CSZQXDlg::OnEnChangeeditexposure)
	ON_CBN_SELCHANGE(IDC_cbbADC, &CSZQXDlg::OnCbnSelchangecbbadc)
	ON_BN_CLICKED(IDCANCEL, &CSZQXDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_rbOpt2Opt, &CSZQXDlg::OnBnClickedrbopt2opt)
	ON_BN_CLICKED(IDC_rbInfo_Security, &CSZQXDlg::OnBnClickedrbinfoSecurity)
	ON_BN_CLICKED(IDC_btnCamera, &CSZQXDlg::OnBnClickedbtncamera)
	ON_STN_CLICKED(IDC_staSZQX, &CSZQXDlg::OnStnClickedstaszqx)
END_MESSAGE_MAP()


// CSZQXDlg 消息处理程序

BOOL CSZQXDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	//添加摄像机采集参数
	sbGain.SetScrollRange(1, 60, TRUE);
	sbShutter.SetScrollRange(1, 999, TRUE);

	int MoHight, MoWidth;//定义对话框尺寸
	MoHight = 670;
	MoWidth = 960;

	//初始化对话框位置与大小
	::MoveWindow(this->m_hWnd, 1440/2-MoWidth/2, 900/2-MoHight/2, MoWidth, MoHight,TRUE);
	GetDlgItem(IDC_staSZQX)->SetWindowPos(NULL,MoWidth/2-250, 20, 500, 40, SWP_SHOWWINDOW); 
	//分割线
	GetDlgItem(IDC_staTop)->SetWindowPos(NULL, 0,100-20, MoWidth, 2, SWP_SHOWWINDOW);
	GetDlgItem(IDC_staBottom)->SetWindowPos(NULL, 0, 250, 200, 5, SWP_SHOWWINDOW);
	GetDlgItem(IDC_staLeft)->SetWindowPos(NULL, 200, 100-20, 2, MoHight, SWP_SHOWWINDOW);
	//设置主按键位置 起始位置在x0，y100
	GetDlgItem(IDC_rbDig2Dig)->SetWindowPos(NULL,40,100,150,18,SWP_SHOWWINDOW); 
	GetDlgItem(IDC_rbOpt2Dig)->SetWindowPos(NULL,40,130,150,18,SWP_SHOWWINDOW); 
	GetDlgItem(IDC_rbDig2Opt)->SetWindowPos(NULL,40,160,150,18,SWP_SHOWWINDOW); 
	GetDlgItem(IDC_rbOpt2Opt)->SetWindowPos(NULL,40,190,150,18,SWP_SHOWWINDOW); 
	GetDlgItem(IDC_rbInfo_Security)->SetWindowPos(NULL,40,220,150,18,SWP_SHOWWINDOW);
	GetDlgItem(IDCANCEL)->SetWindowPos(NULL, 70, MoHight-70, 64,36, SWP_SHOWWINDOW);
	GetDlgItem(IDC_cbbParameterReset)->SetWindowPos(NULL, 100, 270, 90, 64, SWP_SHOWWINDOW);
	GetDlgItem(IDC_btnReset)->SetWindowPos(NULL, 20, 265, 64, 36, SWP_SHOWWINDOW); 

	//GetDlgItem(IDC_STATIC)->SetWindowPos(NULL, 10, 10, 60, 40, SWP_SHOWWINDOW);

	GetDlgItem(IDC_btnCamera)->SetWindowPos(NULL,40,350,100,36,SWP_SHOWWINDOW);
	//************************************************************************************//
	//不使用大恒相机，注释相机相关控件
	//***********************************************************************************//
	//图像采集区域设置
//     GetDlgItem(IDC_staCCDSnap)->SetWindowPos(NULL, 10, 315, 180, 270, SWP_SHOWWINDOW);
// 	GetDlgItem(IDC_btnSnap)->SetWindowPos(NULL, 23, 340, 64, 36, SWP_SHOWWINDOW);
// 	GetDlgItem(IDC_btnSaveBMP)->SetWindowPos(NULL, 113, 340, 64, 36, SWP_SHOWWINDOW);
// 	//增益
// 	GetDlgItem(IDC_staGain)->SetWindowPos(NULL, 23, 390, 60, 18, SWP_SHOWWINDOW);
// 	GetDlgItem(IDC_editGain)->SetWindowPos(NULL, 83, 390, 30, 18, SWP_SHOWWINDOW);
//     GetDlgItem(IDC_sbGain)->SetWindowPos(NULL, 23, 420, 150, 18, SWP_SHOWWINDOW);
// 	GetDlgItem(IDC_staGainRange)->SetWindowPos(NULL, 120, 390, 24, 18, SWP_SHOWWINDOW);
// 	//曝光
// 	GetDlgItem(IDC_staExposure)->SetWindowPos(NULL, 23, 470, 60, 18, SWP_SHOWWINDOW);
// 	GetDlgItem(IDC_editExposure)->SetWindowPos(NULL, 83, 470, 30, 18, SWP_SHOWWINDOW);
// 	GetDlgItem(IDC_sbExposure)->SetWindowPos(NULL, 23, 500, 150, 18, SWP_SHOWWINDOW);
// 	GetDlgItem(IDC_staExposureTime)->SetWindowPos(NULL, 120, 470, 64, 18, SWP_SHOWWINDOW);
// 	//AD转换
// 	GetDlgItem(IDC_staADC)->SetWindowPos(NULL, 23, 550, 64, 18, SWP_SHOWWINDOW);
// 	GetDlgItem(IDC_cbbADC)->SetWindowPos(NULL, 95, 550, 90, 64, SWP_SHOWWINDOW);
	//加入子对话框类
	//数字记录数字再现
	if(pDig2Dig != NULL){
		delete(pDig2Dig);
		pDig2Dig = NULL;
	}
	pDig2Dig = new SZQX_Dig2Dig;
	pDig2Dig->Create(IDD_SZQX_Dig2Dig_child_dlg, this);

	//数字记录光学再现
	if(pDig2Opt != NULL){
		delete(pDig2Opt);
		pDig2Opt = NULL;
	}
	pDig2Opt = new SZQX_Dig2Opt;
	pDig2Opt->Create(IDD_SZQX_Dig2Opt_child_dlg, this);

	//光学记录数字再现
	if(pOpt2Dig != NULL){
		delete(pOpt2Dig);
		pOpt2Dig = NULL;
	}
	pOpt2Dig = new SZQX_Opt2Dig;
	pOpt2Dig->Create(IDD_SZQX_Opt2Dig_child_dlg, this);

	//光学记录光学再现
	if(pOpt2Dig != NULL){
		delete(pOpt2Opt);
		pOpt2Opt = NULL;
	}
	pOpt2Opt = new SZQX_Opt2Opt;
	pOpt2Opt->Create(IDD_SZQX_Opt2Opt_child_dlg, this);
	//信息安全
	if(pInfo_Security != NULL){
		delete(pInfo_Security);
		pInfo_Security = NULL;
	}
	pInfo_Security = new SZQX_Info_Security;
	pInfo_Security->Create(IDD_SZQX_Info_Security_child_dlg, this);

	//定义子对话框大小及位置,子对话框大小为 800*750
	CRect rs;
	rs.top = 100-10;
	rs.bottom = MoHight;
	rs.left = 200+10;
	rs.right = MoWidth;

	pDig2Dig->MoveWindow(&rs);
	pDig2Opt->MoveWindow(&rs);
	pOpt2Dig->MoveWindow(&rs);
	pOpt2Opt->MoveWindow(&rs);
	pInfo_Security->MoveWindow(&rs);

	//对下拉列表IDC_cbbParameterReset 设置
	//定义光学再现使用的像面比例因子参数
	CString strTemp;
	((CComboBox*)GetDlgItem(IDC_cbbParameterReset))->ResetContent();//消除现有所有内容
	for(int i=1;i<=100;i++)
	{
		strTemp.Format("%d",i);
		((CComboBox*)GetDlgItem(IDC_cbbParameterReset))->AddString(strTemp);
	}

	int iCount=((CComboBox*)GetDlgItem(IDC_cbbParameterReset))->GetCount();//取得目前已经有的行数??? if(iCount<1)//防止重复多次添加
	{
		((CComboBox*)GetDlgItem(IDC_cbbParameterReset))->ResetContent();
		for(int i=1;i<=100;i++)
		{
			strTemp.Format("%d",i);
			((CComboBox*)GetDlgItem(IDC_cbbParameterReset))->AddString(strTemp);
		}
	}

	CString SLMdxyh, CCDdxyh;
	SLMdxyh = "9";
	CCDdxyh = "5.2";
	((CComboBox*)GetDlgItem(IDC_cbbParameterReset))->ResetContent();//消除现有所有内容
	((CComboBox*)GetDlgItem(IDC_cbbParameterReset))->AddString("SLM像素比例");
	((CComboBox*)GetDlgItem(IDC_cbbParameterReset))->AddString("CCD像素比例");
	GetDlgItem(IDC_cbbParameterReset)->SetWindowText("CCD像素比例");

	cbbADC.ResetContent();
	cbbADC.AddString("Level 0");
	cbbADC.AddString("Level 1");
	cbbADC.AddString("Level 2");
	cbbADC.AddString("Level 3");

	EnableCCD();//禁用所有ccd采集按钮

	GetDlgItem(IDC_editGain)->SetWindowText("10");
	GetDlgItem(IDC_editExposure)->SetWindowText("60");
	sbGain.SetScrollPos(10);
	sbShutter.SetScrollPos(60);
	cbbADC.SetWindowText("Level 2");

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSZQXDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}

	//改变字体大小
	CWnd *pWnd = GetDlgItem(IDC_staSZQX);
	CDC *pDC = pWnd->GetDC();
	CFont font;
	CFont *pFont;
	font.CreateFont(36,0,0,0,FW_BOLD,FALSE,FALSE,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS, 
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,DEFAULT_PITCH | FF_SWISS, _T("宋体"));
	pFont=pDC->SelectObject(&font);
	GetDlgItem(IDC_staSZQX)->SetFont(&font);
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSZQXDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CSZQXDlg::OnBnClickedbtnreset()
{
	// TODO: 在此添加控件通知处理程序代码
	//获取下拉列表的参数
	UpdateData(TRUE);
	CString str_dxyh;
	double dxyh;
	((CComboBox*)GetDlgItem(IDC_cbbParameterReset))->GetWindowText(str_dxyh);

	if (str_dxyh == "")
	{
		return;
	}//end if

	if ( str_dxyh == "SLM像素比例" )
	{
		dxyh = 9;
	}//end if

	if ( str_dxyh == "CCD像素比例" )
	{
		dxyh = 5.2;
	}//end if

	//与光学再现，有关的模块为数字记录光学再现
	pDig2Opt->dxh = dxyh;
	pDig2Opt->dyh = dxyh;
	Invalidate();
}

void CSZQXDlg::OnBnClickedrbdig2dig()//数字记录数字再现按钮
{
	// TODO: 在此添加控件通知处理程序代码
	pDig2Dig->ShowWindow(SW_SHOW);//显示
	pDig2Opt->ShowWindow(SW_HIDE);
	pOpt2Dig->ShowWindow(SW_HIDE);
	pOpt2Opt->ShowWindow(SW_HIDE);
	pInfo_Security->ShowWindow(SW_HIDE);

	//判断相机采集参数启用与否
	m_bStartSign = false;

// 	if ( pOpt2Dig->pageCCD.GetCameraStatus() || pOpt2Opt->pageCCD.GetCameraStatus() )//先判断相机是否存在
// 	{
// 		EnableCCD();
// 	}
}

void CSZQXDlg::OnBnClickedrbopt2dig()//光学记录数字再现按钮
{
	// TODO: 在此添加控件通知处理程序代码
	pDig2Dig->ShowWindow(SW_HIDE);
	pDig2Opt->ShowWindow(SW_HIDE);
	pOpt2Dig->ShowWindow(SW_SHOW);//显示
	pOpt2Opt->ShowWindow(SW_HIDE);
	pInfo_Security->ShowWindow(SW_HIDE);

	//判断相机采集参数启用与否
	m_bStartSign = TRUE;
	
	//如果在点击“数字再现”之前就启动“光学再现”的CCD采集，则先关闭相机然后才再次启动
// 	if ( m_nChoicCCDModel != Opt2Dig )//这个值不同意味着是从另一个相机采集模块跳转过来
// 	{
// 		//需要关闭另一个相机
// 		pOpt2Opt->pageCCD.CloseSnap();
// 		GetDlgItem(IDC_btnSnap)->SetWindowText("采集图像");
// 		m_nChoicCCDModel = Opt2Dig;
// 	}//end if

// 	if ( pOpt2Dig->pageCCD.GetCameraStatus() || pOpt2Opt->pageCCD.GetCameraStatus() )//先判断相机是否存在
// 	{
// 		EnableCCD();
// 	}
}

void CSZQXDlg::OnBnClickedrbdig2opt()//数字记录光学再现按钮
{
	// TODO: 在此添加控件通知处理程序代码
	pDig2Dig->ShowWindow(SW_HIDE);
	pDig2Opt->ShowWindow(SW_SHOW);//显示
	pOpt2Dig->ShowWindow(SW_HIDE);
	pOpt2Opt->ShowWindow(SW_HIDE);
	pInfo_Security->ShowWindow(SW_HIDE);

	//判断相机采集参数启用与否
	m_bStartSign = false;

// 	if ( pOpt2Dig->pageCCD.GetCameraStatus() || pOpt2Opt->pageCCD.GetCameraStatus() )//先判断相机是否存在
// 	{
// 		EnableCCD();
// 	}
}

void CSZQXDlg::OnBnClickedrbopt2opt()//光学记录光学再现按钮
{
	// TODO: 在此添加控件通知处理程序代码
	pDig2Dig->ShowWindow(SW_HIDE);
	pDig2Opt->ShowWindow(SW_HIDE);
	pOpt2Dig->ShowWindow(SW_HIDE);
	pOpt2Opt->ShowWindow(SW_SHOW);//显示
	pInfo_Security->ShowWindow(SW_HIDE);

	//判断相机采集参数启用与否
	m_bStartSign = TRUE;

// 	if ( m_nChoicCCDModel != Opt2Opt )//这个值不同意味着是从另一个相机采集模块跳转过来
// 	{
// 		//需要关闭另一个相机
// 		pOpt2Dig->pageCCD.CloseSnap();
// 		GetDlgItem(IDC_btnSnap)->SetWindowText("采集图像");
// 		m_nChoicCCDModel = Opt2Opt;
// 	}//end if

// 	if ( pOpt2Dig->pageCCD.GetCameraStatus() || pOpt2Opt->pageCCD.GetCameraStatus() )//先判断相机是否存在
// 	{
// 		EnableCCD();
// 	}
}

void CSZQXDlg::OnBnClickedrbinfoSecurity()//信息安全按钮
{
	// TODO: 在此添加控件通知处理程序代码
	pDig2Dig->ShowWindow(SW_HIDE);
	pDig2Opt->ShowWindow(SW_HIDE);
	pOpt2Dig->ShowWindow(SW_HIDE);
	pOpt2Opt->ShowWindow(SW_HIDE);
	pInfo_Security->ShowWindow(SW_SHOW);//显示

	//判断相机采集参数启用与否
	m_bStartSign = false;

// 	if ( pOpt2Dig->pageCCD.GetCameraStatus() || pOpt2Opt->pageCCD.GetCameraStatus() )//先判断相机是否存在
// 	{
// 		EnableCCD();
// 	}
}

void CSZQXDlg::OnBnClickedbtnsnap()//相机采集按钮
{
	// TODO: 在此添加控件通知处理程序代码

	if ( m_nChoicCCDModel == Opt2Dig )//启动数字再现的相机程序
	{
//		m_bSnapping = pOpt2Dig->pageCCD.m_bSnapping;

		CWnd *pWnd = NULL;
		pWnd = this->GetDlgItem(IDC_btnSnap);

		if (m_bSnapping)
		{//停止采集
			pWnd->SetWindowText("采集图像");
			//pOpt2Dig->pageCCD.ClickSnap();
			GetDlgItem(IDC_btnSaveBMP)->EnableWindow(TRUE);//启用保存图像按钮
		}//end if
		else
		{//开始采集
			pWnd->SetWindowText("停止采集");
			//pOpt2Dig->pageCCD.ResetResolution();//重置相机分辨率
			//pOpt2Dig->pageCCD.ClickSnap();
			GetDlgItem(IDC_btnSaveBMP)->EnableWindow(FALSE);//禁用保存图像按钮
		}//end else
	}//end if

	if ( m_nChoicCCDModel == Opt2Opt )//启动光学再现的相机程序
	{
		//m_bSnapping = pOpt2Opt->pageCCD.m_bSnapping;

		CWnd *pWnd = NULL;
		pWnd = this->GetDlgItem(IDC_btnSnap);

		if (m_bSnapping)
		{//停止采集
			pWnd->SetWindowText("采集图像");
			//pOpt2Opt->pageCCD.ClickSnap();
			GetDlgItem(IDC_btnSaveBMP)->EnableWindow(TRUE);//启用保存图像按钮
		}//end if
		else
		{//开始采集
			pWnd->SetWindowText("停止采集");
			//pOpt2Opt->pageCCD.ResetResolution();//重置相机分辨率
			//pOpt2Opt->pageCCD.ClickSnap();
			GetDlgItem(IDC_btnSaveBMP)->EnableWindow(FALSE);//禁用保存图像按钮
		}//end else
	}//end if
}

void CSZQXDlg::OnBnClickedbtnsavebmp()//相机采集单帧按钮
{
	// TODO: 在此添加控件通知处理程序代码
// 	if ( m_nChoicCCDModel == Opt2Dig )//启动数字再现的相机程序
// 	{
// 		pOpt2Dig->pageCCD.BeginCCD();
// 		pOpt2Dig->pageCCD.ResetResolution();//重置相机分辨率
// 		pOpt2Dig->pageCCD.SaveBMP();
// 	}//end if

// 	if ( m_nChoicCCDModel == Opt2Opt )//启动光学再现的相机程序
// 	{
// 		pOpt2Opt->pageCCD.BeginCCD();
// 		pOpt2Opt->pageCCD.ResetResolution();//重置相机分辨率
// 		pOpt2Opt->pageCCD.SaveBMP();
// 	}//end if
	
}

void CSZQXDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int nCurPos = 0;
	int i = 0;

	nCurPos = pScrollBar->GetScrollPos();
	switch( nSBCode ){
	case SB_THUMBPOSITION:
		pScrollBar->SetScrollPos( nPos );
		break;
	case SB_LINERIGHT:
		nCurPos = pScrollBar->GetScrollPos();
		nCurPos++;
		pScrollBar->SetScrollPos( nCurPos );
		break;
	case SB_LINELEFT:
		nCurPos = pScrollBar->GetScrollPos();
		nCurPos--;
		pScrollBar->SetScrollPos( nCurPos );
		break;
	case SB_PAGERIGHT:
		nCurPos = pScrollBar->GetScrollPos();
		nCurPos += 10;
		pScrollBar->SetScrollPos( nCurPos );
		break;
	case SB_PAGELEFT:
		nCurPos = pScrollBar->GetScrollPos();
		nCurPos -= 10;
		pScrollBar->SetScrollPos( nCurPos );
		break;
	case SB_THUMBTRACK:
		pScrollBar->SetScrollPos( nPos );
		break;
	default:
		break;
	}

	if (pScrollBar == &sbGain) 
	{//设置增益滑条
		nEditGain = nCurPos;

// 		if ( m_nChoicCCDModel == Opt2Dig ) //数字再现
// 		{
// 			for (int i = 0; i < 4; i++)//分别调整各通道增益
// 				pOpt2Dig->pageCCD.SetGain(i, nCurPos);//end for
// 		}//end if

// 		if ( m_nChoicCCDModel == Opt2Opt ) //光学再现
// 		{
// 			for (int i = 0; i < 4; i++)//分别调整各通道增益
// 				pOpt2Opt->pageCCD.SetGain(i, nCurPos);//end for
// 		}//end if
	}

	if (pScrollBar == &sbShutter) 
	{//设置曝光时间滑条
		nEditExposure = nCurPos;

// 		if ( m_nChoicCCDModel == Opt2Dig )//数字再现
// 		{
// 			pOpt2Dig->pageCCD.SetShutter(nEditExposure);
// 		}//end if

// 		if ( m_nChoicCCDModel == Opt2Opt )//光学再现
// 		{
// 			pOpt2Opt->pageCCD.SetShutter(nEditExposure);
// 		}//end if		
	}

	UpdateData(FALSE);

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CSZQXDlg::OnEnChangeeditgain()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	sbGain.SetScrollPos(nEditGain);

// 	if ( m_nChoicCCDModel == Opt2Dig )//数字再现
// 	{
// 		for (int i = 0; i < 4; i++)//分别调整各通道增益
// 			pOpt2Dig->pageCCD.SetGain(i, nEditGain);//end for
// 	}//end if
	
// 	if ( m_nChoicCCDModel == Opt2Opt )//光学再现
// 	{
// 		for (int i = 0; i < 4; i++)//分别调整各通道增益
// 			pOpt2Opt->pageCCD.SetGain(i, nEditGain);//end for
// 	}//end if
}

void CSZQXDlg::OnEnChangeeditexposure()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	sbShutter.SetScrollPos(nEditExposure);

// 	if ( m_nChoicCCDModel == Opt2Dig )//数字再现
// 	{
// 		pOpt2Dig->pageCCD.SetShutter(nEditExposure);
// 	}//end if
	
// 	if ( m_nChoicCCDModel == Opt2Opt )//光学再现
// 	{
// 		pOpt2Opt->pageCCD.SetShutter(nEditExposure);
// 	}//end if
}

void CSZQXDlg::OnCbnSelchangecbbadc()
{
	// TODO: 在此添加控件通知处理程序代码
	int m_lADCLevel = 0;
	m_lADCLevel = cbbADC.GetCurSel();

// 	if ( m_nChoicCCDModel == Opt2Dig )//数字再现
// 	{
// 		pOpt2Dig->pageCCD.SetADC(m_lADCLevel);
// 	}//end if
	
// 	if ( m_nChoicCCDModel == Opt2Opt )//光学再现
// 	{
// 		pOpt2Opt->pageCCD.SetADC(m_lADCLevel);
// 	}//end if
}

void CSZQXDlg::EnableCCD()
{
	if (m_bStartSign)
	{//若可以采集，启用所有按钮
		GetDlgItem(IDC_staCCDSnap)->EnableWindow(TRUE);
		GetDlgItem(IDC_btnSnap)->EnableWindow(TRUE);
		GetDlgItem(IDC_btnSaveBMP)->EnableWindow(TRUE);
		//增益
		GetDlgItem(IDC_staGain)->EnableWindow(TRUE);
		GetDlgItem(IDC_editGain)->EnableWindow(TRUE);
		GetDlgItem(IDC_sbGain)->EnableWindow(TRUE);
		GetDlgItem(IDC_staGainRange)->EnableWindow(TRUE);
		//曝光
		GetDlgItem(IDC_staExposure)->EnableWindow(TRUE);
		GetDlgItem(IDC_editExposure)->EnableWindow(TRUE);
		GetDlgItem(IDC_sbExposure)->EnableWindow(TRUE);
		GetDlgItem(IDC_staExposureTime)->EnableWindow(TRUE);
		//AD转换
		GetDlgItem(IDC_staADC)->EnableWindow(TRUE);
		GetDlgItem(IDC_cbbADC)->EnableWindow(TRUE);
	} 
	else
	{//离开采集页面或其他模块，禁用所有按钮，并停止图像采集
		GetDlgItem(IDC_staCCDSnap)->EnableWindow(FALSE);
		GetDlgItem(IDC_btnSnap)->EnableWindow(FALSE);
		GetDlgItem(IDC_btnSaveBMP)->EnableWindow(FALSE);
		//增益
		GetDlgItem(IDC_staGain)->EnableWindow(FALSE);
		GetDlgItem(IDC_editGain)->EnableWindow(FALSE);
		GetDlgItem(IDC_sbGain)->EnableWindow(FALSE);
		GetDlgItem(IDC_staGainRange)->EnableWindow(FALSE);
		//曝光
		GetDlgItem(IDC_staExposure)->EnableWindow(FALSE);
		GetDlgItem(IDC_editExposure)->EnableWindow(FALSE);
		GetDlgItem(IDC_sbExposure)->EnableWindow(FALSE);
		GetDlgItem(IDC_staExposureTime)->EnableWindow(FALSE);
		//AD转换
		GetDlgItem(IDC_staADC)->EnableWindow(FALSE);
		GetDlgItem(IDC_cbbADC)->EnableWindow(FALSE);
		//关闭相机
// 		if ( m_nChoicCCDModel == Opt2Dig )
// 			pOpt2Dig->pageCCD.CloseSnap();//end if

// 		if ( m_nChoicCCDModel == Opt2Opt )
// 			pOpt2Opt->pageCCD.CloseSnap();//end if
		
		GetDlgItem(IDC_btnSnap)->SetWindowText("采集图像");
	}
}

void CSZQXDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	OnCancel();
}




void CSZQXDlg::OnBnClickedbtncamera()
{
	CString ExePath;
	TCHAR Temp[MAX_PATH];
	GetModuleFileName(NULL, Temp, MAX_PATH);
	ExePath.Format(_T("%s"),Temp);
	int nPos = ExePath.ReverseFind('\\');
	ExePath = ExePath.Left(nPos);//去除文件名，得到文件夹路径名！
	ExePath += "\\相机采集程序.exe";

	CFileStatus   status; 
	if   (!CFile::GetStatus( ExePath, status )) 
	{ 
		AfxMessageBox("相机采集程序不存在，请拷贝程序至主程序文件夹");
		return;
	} 

	ShellExecute(NULL, "open", (LPCTSTR)ExePath, NULL,NULL,SW_SHOWNORMAL);
}


void CSZQXDlg::OnStnClickedstaszqx()
{
	// TODO: Add your control notification handler code here
}

# DeepSeek：

**原始回答**

根据提供的 `SZQXDig.cpp` 代码分析，该文件是主对话框控制模块，**不直接包含SLM相位控制逻辑**。以下是关键结论和解决方案：

---

### **核心发现**
1. **功能定位**：
   - 主控界面管理（模块切换、相机控制等）
   - 不涉及SLM底层通信或相位调制
   - 相机采集功能被注释（未实际使用）

2. **SLM控制缺失**：
   - 无SLM初始化、相位映射、图像加载等关键函数
   - 未发现与`SZQX_Dig2Opt_Hologram`的SLM交互代码

---

### **SLM控制代码的可能位置**
#### 1. **子对话框 `SZQX_Dig2Opt`**
- 负责"数字到光学"转换的模块
- 应包含发送全息图到SLM的按钮事件
- 预期代码结构：
  ```cpp
  void SZQX_Dig2Opt::OnBnClickedSendToSLM() {
      Matrix phaseMap = GeneratePhaseMap();  // 从全息图生成相位数据

## 关键结论

原对话最后阶段给出的主要判断或处理方向：以下是关键结论和解决方案： **核心发现** 1. **功能定位**： 主控界面管理（模块切换、相机控制等） 不涉及SLM底层通信或相位调制 相机采集功能被注释（未实际使用） 2. **SLM控制缺失**： 无SLM初始化、相位映射、图像加载等关键函数 未发现与`SZQX_Dig2Opt_Hologram`的SLM交互代码 **SLM控制代码的可能位置** 1. **子对话框 `SZQX_Dig2Opt`** 负责"数字到光学"转换的模块 应包含发送全息图到SLM的按钮事件 预期代码结构： ```cpp void SZQX_Dig2Opt::OnBnClickedSendToSLM() { Matrix phaseMap = GeneratePhaseMap(); // 从全息图生成相位数据

## 上下文关系

- 所属项目：d22b651400-software-03
- 当前阶段：独立主题
- 前置切片：无
- 后续切片：无
- 附件说明：无
