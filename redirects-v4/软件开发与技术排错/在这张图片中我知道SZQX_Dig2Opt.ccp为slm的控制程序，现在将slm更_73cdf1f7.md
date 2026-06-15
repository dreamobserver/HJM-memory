---
title: "在这张图片中我知道SZQX_Dig2Opt.ccp为slm的控制程序，现在将slm更"
source_platform: "DeepSeek"
source_file: "SLM更换后程序修改建议.md"
turn_start: 1
turn_end: 4
primary_category: "软件开发与技术排错"
tags:
  - "状态栏"
  - "软件开发"
project_id: "bce3f1b967-software-01"
stage: "阶段1/2"
previous_slice: null
next_slice: "脉冲测距故障排查_a4819898.md"
has_attachment: false
attachment_context_confidence: not_applicable
classification_confidence: 0.97
---

# 在这张图片中我知道SZQX_Dig2Opt.ccp为slm的控制程序，现在将slm更

## 问题摘要

本切片围绕“在这张图片中我知道SZQX_Dig2Opt.ccp为slm的控制程序，现在将slm更”展开。起始诉求是：在这张图片中我知道SZQX_Dig2Opt.ccp为slm的控制程序，现在将slm更换为图二型号，除了控制程序还有哪些程序需要修改 后续进展或反馈是：与数字再现相关的修改要修改SZQX_Dig2Opt.cpp文件还要修改什么文件内容覆盖原始对话 T1-T4。

## 原始对话

# 用户：

在这张图片中我知道SZQX_Dig2Opt.ccp为slm的控制程序，现在将slm更换为图二型号，除了控制程序还有哪些程序需要修改

# DeepSeek：

**原始回答**

根据提供的信息，将SLM（空间光调制器）更换为图二型号（透射式液晶，0.63英寸靶面，1024x768分辨率等）后，除了控制程序 `SZOX_Dig2Opt.cpp` 外，以下程序可能需要修改：

1. **分辨率相关的程序**  
   - `SZOX_Dig2Dig.cpp`、`SZOX_Dig2Dig_Hologram.cpp`、`SZOX_Dig2Dig_ReImage.cpp`  
     这些程序可能包含硬编码的分辨率（1024x768），需要更新以匹配新SLM的参数。

2. **像素尺寸和光学计算相关的程序**  
   - `SZOX_Dig2Opt.cpp`、`SZOX_Dig2Opt_Hologram.cpp`、`SZOX_Dig2Opt_Orilmage.cpp`  
     这些程序可能涉及像素尺寸（12.5μm）和光学传递函数的计算，需根据新SLM的像素尺寸调整。

3. **相位调制相关的程序**  
   - `SZOX_Opt2Dig.cpp`、`SZOX_Opt2Dig_Hologram.cpp`、

项是否涉及SLM参数。

# 用户：

SZOX_Dig2Dig.cpp代码如下// SZQX_Dig2Dig.cpp : 实现文件
//

#include "stdafx.h"
#include "SZQX.h"
#include "SZQX_Dig2Dig.h"
#include ".\include\fft\fft2.h"
#include ".\include\fft\GS_matlab.h"
#include ".\include\fft\cpukit.h"
#include ".\include\SZQX_InLine.h"//为SZQX编写的公用函数

// SZQX_Dig2Dig 对话框

IMPLEMENT_DYNAMIC(SZQX_Dig2Dig, CDialog)

SZQX_Dig2Dig::SZQX_Dig2Dig(CWnd* pParent /*=NULL*/)
	: CDialog(SZQX_Dig2Dig::IDD, pParent)
{
	//初始化常量
	Lambda = 0.6328;
	K = 2*PI/Lambda;
	dx0 = dy0 = dxh = dyh = 5.200;
}

SZQX_Dig2Dig::~SZQX_Dig2Dig()
{
}

void SZQX_Dig2Dig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_tabDig2Dig, tabDig2Dig);
}


BEGIN_MESSAGE_MAP(SZQX_Dig2Dig, CDialog)
	ON_NOTIFY(TCN_SELCHANGE, IDC_tabDig2Dig, &SZQX_Dig2Dig::OnTcnSelchangetabdig2dig)
	ON_BN_CLICKED(IDC_btnReadOriImage, &SZQX_Dig2Dig::OnBnClickedbtnreadoriimage)
	ON_BN_CLICKED(IDC_btnGenerationHolo, &SZQX_Dig2Dig::OnBnClickedbtngenerationholo)
	ON_BN_CLICKED(IDC_btnReconstruction, &SZQX_Dig2Dig::OnBnClickedbtnreconstruction)
	ON_BN_CLICKED(IDC_btnSaveBMP, &SZQX_Dig2Dig::OnBnClickedbtnsavebmp)
END_MESSAGE_MAP()


// SZQX_Dig2Dig 消息处理程序

BOOL SZQX_Dig2Dig::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//初始化对话框各控件位置与大小
	GetDlgItem(IDC_btnReadOriImage)->SetWindowPos(NULL,800-200, 20-5, 64, 36, SWP_SHOWWINDOW); 

	GetDlgItem(IDC_staChoiceFun)->SetWindowPos(NULL,800-260, 70-5, 200, 80, SWP_SHOWWINDOW);
	GetDlgItem(IDC_rbFresnelConvolution)->SetWindowPos(NULL,800-200, 80-5, 90, 36, SWP_NOZORDER);
	GetDlgItem(IDC_rbFresnelWithDigiSubtract)->SetWindowPos(NULL,800-200, 110-5, 90, 36, SWP_NOZORDER);

	GetDlgItem(IDC_btnGenerationHolo)->SetWindowPos(NULL,800-200, 160-5, 64, 36, SWP_SHOWWINDOW); 
	GetDlgItem(IDC_btnReconstruction)->SetWindowPos(NULL,800-200, 200-5, 64, 36, SWP_SHOWWINDOW); 

	GetDlgItem(IDC_staD)->SetWindowPos(NULL,800-250, 270-5, 64, 36, SWP_SHOWWINDOW); 
	GetDlgItem(IDC_editD)->SetWindowPos(NULL,800-150, 270-5, 64, 18, SWP_SHOWWINDOW); 
	GetDlgItem(IDC_staSita)->SetWindowPos(NULL,800-250, 310-5, 64, 36, SWP_SHOWWINDOW); 
	GetDlgItem(IDC_editSita)->SetWindowPos(NULL,800-150, 310-5, 64, 18, SWP_SHOWWINDOW);
	GetDlgItem(IDC_staGenerationHolo)->SetWindowPos(NULL,800-260, 250-5, 200, 100, SWP_SHOWWINDOW);

	GetDlgItem(IDC_staD1)->SetWindowPos(NULL,800-250, 400-5, 64, 36, SWP_SHOWWINDOW); 
	GetDlgItem(IDC_editD1)->SetWindowPos(NULL,800-150, 400-5, 64, 18, SWP_SHOWWINDOW); 
	GetDlgItem(IDC_staReconstruction)->SetWindowPos(NULL,800-260, 370-5, 200, 80, SWP_SHOWWINDOW);

	GetDlgItem(IDC_btnSaveBMP)->SetWindowPos(NULL, 800-200, 470, 64, 36, SWP_SHOWWINDOW);

	GetDlgItem(IDC_staPartition)->SetWindowPos(NULL, 520, 0 , 2, 750, SWP_SHOWWINDOW);

	//添加标签控件子选项卡名称
	tabDig2Dig.InsertItem(0, "原图");
	tabDig2Dig.InsertItem(1, "全息图");
	tabDig2Dig.InsertItem(2, "再现图");

	//关联对话框,并且将IDC_tabDig2Dig控件设为父窗口
	pageOriImage.Create(IDD_SZQX_Dig2Dig_OriImage_tab_dlg, GetDlgItem(IDC_tabDig2Dig));
	pageHologram.Create(IDD_SZQX_Dig2Dig_Hologram_tab_dlg, GetDlgItem(IDC_tabDig2Dig));
	pageReImage.Create(IDD_SZQX_Dig2Dig_ReImage_tab_dlg, GetDlgItem(IDC_tabDig2Dig));

	//控制IDC_tabDig2Dig客户区大小与位置
	CRect rs;
	CRect rsTab;
	rsTab.top = 0;
	rsTab.bottom = 520+20;
	rsTab.left = 0;
	rsTab.right = 520;

	rs.top = rsTab.top+20;
	rs.bottom = rsTab.bottom;
	rs.left = rsTab.left;
	rs.right = rsTab.right;

	//tab控件位置大小
	tabDig2Dig.MoveWindow(&rsTab);
	//调整Tab页面对话框的位置
	pageOriImage.MoveWindow(&rs);
	pageHologram.MoveWindow(&rs);
	pageReImage.MoveWindow(&rs);
	HideAllTab();

	pageOriImage.ShowWindow(true);//显示

	//设置默认的选项卡
	tabDig2Dig.SetCurSel(0);//默认在第一个选项卡

	//设置单选按钮
	((CButton *)GetDlgItem(IDC_rbFresnelConvolution))->SetCheck(TRUE);//选上
	((CButton *)GetDlgItem(IDC_rbFresnelWithDigiSubtract))->SetCheck(FALSE);//不选上

	//初始化参数
	GetDlgItem(IDC_editD)->SetWindowText("90");//衍射距离
	GetDlgItem(IDC_editSita)->SetWindowText("1.6");//参考光夹角
	GetDlgItem(IDC_editD1)->SetWindowText("90");//再现距离

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void SZQX_Dig2Dig::OnTcnSelchangetabdig2dig(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	int CurSel = tabDig2Dig.GetCurSel();
	switch(CurSel) 
	{ 
	case 0: 
		pageOriImage.ShowWindow(true); //显示
		pageHologram.ShowWindow(false); 
		pageReImage.ShowWindow(false);
		break; 
	case 1: 
		pageOriImage.ShowWindow(false); 
		pageHologram.ShowWindow(true);  //显示
		pageReImage.ShowWindow(false);
		break;
	case 2:
		pageOriImage.ShowWindow(false); 
		pageHologram.ShowWindow(false); 
		pageReImage.ShowWindow(true);//显示
		break; 
	default: 
		; 
	} 

	*pResult = 0;
}

void SZQX_Dig2Dig::PostNcDestroy()
{
	// TODO: 在此添加专用代码和/或调用基类

	delete this;
	CDialog::PostNcDestroy();
}

Matrix<double> SZQX_Dig2Dig::FresnelConvolution(Matrix<double> &pU0, double D_temp, double sita)//利用卷积法衍射，不作数字相减
{
	//这个函数不改变输入的原图 pU0 信息，只输出全息图I_temp，
	//对于显示的全息图，根据是否使用数字相减法作决定

	//变量定义
	int Nrows = pU0.num_rows();//行
	int Mcols = pU0.num_cols();//列
	double theta = sita*PI/180.0000;//对夹角作弧度转换
	Matrix<double> Xh_cols(Nrows, Mcols);//xh：全息面上坐标x轴初始化
	Matrix<double> Yh_rows(Nrows, Mcols);//yh：。。。。。。y。。。。
	Matrix<complex<double>> hTransfer(Nrows, Mcols);//传递函数
	Matrix<double> h_theta(Nrows,Mcols);//传递函数的幅角θ矩阵
	Matrix<complex<double>> F(Nrows,Mcols);//输入图像的傅里叶变换
	Matrix<complex<double>> comU0(Nrows,Mcols);//复数形式的 U0
	Matrix<complex<double>> HImpulse(Nrows, Mcols);//传递函数hTransfer的脉冲响应
	Matrix<complex<double>> HFTemp(Nrows, Mcols);//创建H.*F的临时交换矩阵
	Matrix<complex<double>> O(Nrows, Mcols);//O为全息面上的衍射图像
	Matrix<complex<double>> R(Nrows, Mcols);//参考光
	Matrix<double> R_Theta(Nrows, Mcols);//简化程序，引入参考光幅角矩阵
	Matrix<complex<double>> ih(Nrows, Mcols);//全息图的复数形式
	Matrix<double> I_temp(Nrows, Mcols);//创建全息振幅图的临时矩阵
	Matrix<double> pU0_temp(Nrows, Mcols);//创建原图的临时矩阵
    pU0_temp = pU0;//将原图数据传到内部变量pU0_temp
	//常数项因子
	//C0 = exp(j*k*d)/(j*lambda*d)  
	//   = [cos(k*d)+jsin(k*d)]/j*lambda*d
	//   = [sin(k*d)/(lambda*d)]-j*[cos(k*d)/(lambda*d)]
	std::complex<double> C0 = complex<double> ( sin(K*D_temp)/(Lambda*D_temp), -cos(K*D_temp)/(Lambda*D_temp) );

	//建立X方向坐标，原程序如下：
	////x = -M/2:1:(M/2-1); 
	////y = N/2:-1:(-N/2+1); 
	////[X,Y] = meshgrid(x,y);%建立坐标系
	////xh = dxh.*X;yh = dyh.*Y;

	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			Xh_cols[irows][jcols] = dxh*(jcols-Mcols/2);

	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			Yh_rows[irows][jcols] = dyh*(Nrows/2-irows);

	////h = exp((j*k)/(2*d)*(xh.^2+yh.^2)); %利用卷积法衍射

	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			h_theta[irows][jcols] = K/(2*D_temp)*( Xh_cols[irows][jcols]*Xh_cols[irows][jcols]+Yh_rows[irows][jcols]*Yh_rows[irows][jcols] );

	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			hTransfer[irows][jcols] = complex<double>( cos(h_theta[irows][jcols]), sin(h_theta[irows][jcols]) );

	////F = fftshift(fft2(fftshift(U0)));
	////H = fftshift(fft2(fftshift(h)));
	////mat2gray(U0)
	mat2Gray(pU0_temp, 0.0, 1.0);

	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			comU0[irows][jcols] = complex<double>( pU0_temp[irows][jcols], 0.000 );

	F = fftshift(fft2(fftshift(comU0)));
	HImpulse = fftshift(fft2(fftshift(hTransfer)));

	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			HFTemp[irows][jcols] = HImpulse[irows][jcols]*F[irows][jcols];

	////O = C0.*fftshift(ifft2(fftshift(H.*F))); %衍射图
	O = fftshift(ifft2(fftshift(HFTemp)));

	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			O[irows][jcols] = O[irows][jcols]*C0;

	////R = exp( j*k*(xh*sind(sita) + yh*sind(sita) ));%参考光
	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			R_Theta[irows][jcols] = K*(Xh_cols[irows][jcols]*sin(theta)+Yh_rows[irows][jcols]*sin(theta));

	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			R[irows][jcols] = complex<double> ( cos(R_Theta[irows][jcols]), sin(R_Theta[irows][jcols]) );

	////ih = O+R;
	ih = O+R;

	////I = abs(ih);
	////I = I.^2;
	I_temp = ampOfComplex(ih);

	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			I_temp[irows][jcols] = I_temp[irows][jcols]*I_temp[irows][jcols];

	//不作任何处理必须做 mat2Gray！！
	mat2Gray(I_temp, 0.00, 1.00);

	return I_temp;
}

Matrix<double> SZQX_Dig2Dig::FresnelWithDigiSubtract(Matrix<double> &pU0, double D_temp, double sita)//加入数字相减的衍射
{
	//这个函数不改变输入的原图 pU0 信息，只输出全息图I_temp，
	//对于显示的全息图，根据是否使用数字相减法作决定

	//变量定义
	int Nrows = pU0.num_rows();//行
	int Mcols = pU0.num_cols();//列
	double theta = sita*PI/180.0000;//对夹角作弧度转换
	double R_AverageAmp = 0.000;//参考光平均振幅
	Matrix<double> Xh_cols(Nrows, Mcols);//xh：全息面上坐标x轴初始化
	Matrix<double> Yh_rows(Nrows, Mcols);//yh：。。。。。。y。。。。
	Matrix<complex<double>> hTransfer(Nrows, Mcols);//传递函数
	Matrix<double> h_theta(Nrows,Mcols);//传递函数的幅角θ矩阵
	Matrix<complex<double>> F(Nrows,Mcols);//输入图像的傅里叶变换
	Matrix<complex<double>> comU0(Nrows,Mcols);//复数形式的U0
	Matrix<complex<double>> HImpulse(Nrows, Mcols);//传递函数hTransfer的脉冲响应
	Matrix<complex<double>> HFTemp(Nrows, Mcols);//创建H.*F的临时交换矩阵
	Matrix<complex<double>> O(Nrows, Mcols);//O为全息面上的衍射图像
	Matrix<complex<double>> R(Nrows, Mcols);//参考光
	Matrix<double> R_Theta(Nrows, Mcols);//简化程序，引入参考光幅角
	Matrix<double> O_Amp(Nrows,Mcols);//物光的振幅
	Matrix<double> R_Amp(Nrows,Mcols);//参考光振幅
	Matrix<double>R_Square(Nrows, Mcols);//求R光强R_Amp.^2
	Matrix<double>O_Square(Nrows, Mcols);//求O光强
	Matrix<complex<double>> ih(Nrows, Mcols);//全息图的复数形式
	Matrix<double> I_temp(Nrows, Mcols);//创建全息振幅图的临时矩阵
	Matrix<double> pU0_temp(Nrows, Mcols);//创建原图的临时矩阵
	pU0_temp = pU0;//将原图数据传到内部变量pU0_temp
	//常数项因子
	//C0 = exp(j*k*d)/(j*lambda*d)  
	//   = [cos(k*d)+jsin(k*d)]/j*lambda*d
	//   = [sin(k*d)/(lambda*d)]-j*[cos(k*d)/(lambda*d)]
	std::complex<double> C0 = complex<double> ( sin(K*D_temp)/(Lambda*D_temp), -cos(K*D_temp)/(Lambda*D_temp) );

	//建立X方向坐标，原程序如下：
	////x = -M/2:1:(M/2-1); 
	////y = N/2:-1:(-N/2+1); 
	////[X,Y] = meshgrid(x,y);%建立坐标系
	////xh = dxh.*X;yh = dyh.*Y;

	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			Xh_cols[irows][jcols] = dxh*(jcols-Mcols/2);

	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			Yh_rows[irows][jcols] = dyh*(Nrows/2-irows);

	////h = exp((j*k)/(2*d)*(xh.^2+yh.^2)); %利用卷积法衍射

	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			h_theta[irows][jcols] = K/(2*D_temp)*( Xh_cols[irows][jcols]*Xh_cols[irows][jcols]+Yh_rows[irows][jcols]*Yh_rows[irows][jcols] );

	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			hTransfer[irows][jcols] = complex<double>( cos(h_theta[irows][jcols]), sin(h_theta[irows][jcols]) );

	////F = fftshift(fft2(fftshift(U0)));
	////H = fftshift(fft2(fftshift(h)));
	////mat2gray(U0)
	mat2Gray(pU0_temp, 0.0, 1.0);

	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			comU0[irows][jcols] = complex<double>( pU0_temp[irows][jcols], 0.000 );

	F = fftshift(fft2(fftshift(comU0)));
	HImpulse = fftshift(fft2(fftshift(hTransfer)));

	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			HFTemp[irows][jcols] = HImpulse[irows][jcols]*F[irows][jcols];

	////O = C0.*fftshift(ifft2(fftshift(H.*F))); %衍射图
	O = fftshift(ifft2(fftshift(HFTemp)));

	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			O[irows][jcols] = O[irows][jcols]*C0;

	////R =sum(sum(abs(O)))/(N*M)* exp((j)*k*(xh*sind(sita) + yh*sind(sita) ));%参考光
	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			R_Theta[irows][jcols] = K*(Xh_cols[irows][jcols]*sin(theta)+Yh_rows[irows][jcols]*sin(theta));

	O_Amp = ampOfComplex(O);

	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			R_AverageAmp = R_AverageAmp+O_Amp[irows][jcols];

	R_AverageAmp = R_AverageAmp/(Nrows*Mcols);

	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			R[irows][jcols] = complex<double> ( R_AverageAmp*cos(R_Theta[irows][jcols]), R_AverageAmp*sin(R_Theta[irows][jcols]) );

	R_Amp = ampOfComplex(R);

	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			R_Square[irows][jcols] = R_Amp[irows][jcols]*R_Amp[irows][jcols];

	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			O_Square[irows][jcols] = O_Amp[irows][jcols]*O_Amp[irows][jcols];

	////ih = O+R;
	ih = O+R;
	////I = abs(ih);
	////I = I.^2;
	I_temp = ampOfComplex(ih);

	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			I_temp[irows][jcols] = I_temp[irows][jcols]*I_temp[irows][jcols];

	//数字相减不需要做 mat2Gray！！
	I_temp = I_temp-R_Square-O_Square;

	return I_temp;
}

Matrix<double>  SZQX_Dig2Dig::HoloReconstruction(Matrix<double> &I, double D_temp, double D1)//再现全息图
{
	//这个函数不改变输入的全息图 I信息，只输出再现图U，
	//此函数对于经过各种全息处理方法得到的全息图都可再现。

	//变量定义
    int Nrows = I.num_rows();//行
	int Mcols = I.num_cols();//列
	double dx, dy;//再现平面坐标比例
	Matrix<double> X_cols(Nrows, Mcols);//再现平面坐标x轴初始化
	Matrix<double> Y_rows(Nrows, Mcols);//。。。。。。y。。。。
	Matrix<double> Xh_cols(Nrows, Mcols);//xh：全息面上坐标x轴初始化
	Matrix<double> Yh_rows(Nrows, Mcols);//yh：。。。。。。y。。。。
	Matrix<double> C_Theta(Nrows, Mcols);//C的幅角
	Matrix<complex<double>> C(Nrows, Mcols);
	Matrix<double> C1_Theta(Nrows, Mcols);//C1的幅角
	Matrix<complex<double>> C1(Nrows, Mcols);
	Matrix<complex<double>> Uh2(Nrows, Mcols);//全息图与平面波相乘
	Matrix<complex<double>> Uh2_fft(Nrows, Mcols);
	Matrix<complex<double>> U_complex(Nrows, Mcols);//复数形式的U
	Matrix<double> U(Nrows, Mcols);//再现像
	//常数项因子
	//C0 = exp(j*k*d)/(j*lambda*d)  
	//   = [cos(k*d)+jsin(k*d)]/j*lambda*d
	//   = [sin(k*d)/(lambda*d)]-j*[cos(k*d)/(lambda*d)]
	std::complex<double> C0 = complex<double> ( sin(K*D_temp)/(Lambda*D_temp), -cos(K*D_temp)/(Lambda*D_temp) );

	////d1=d;%再现的距离,即可改变大小，也可改变正负
	////dx=(lambda*d1)/(M*dxh);dy=(lambda*d1)/(N*dyh);%再现像平面的坐标和全息平面坐标的关系
	////x = dx.*X;y = dy.*Y;
	//D1 = D_temp;
	dx = (Lambda*D1)/(Mcols*dxh);
	dy = (Lambda*D1)/(Nrows*dyh);

	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			X_cols[irows][jcols] = dx*(jcols-Mcols/2);

	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			Y_rows[irows][jcols] = dy*(Nrows/2-irows);

	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			Xh_cols[irows][jcols] = dxh*(jcols-Mcols/2);

	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			Yh_rows[irows][jcols] = dyh*(Nrows/2-irows);

	////C = exp((j*k)/(2*d1)*(x.^2+y.^2));
	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			C_Theta[irows][jcols] = K/(2*D1)*( X_cols[irows][jcols]*X_cols[irows][jcols]+Y_rows[irows][jcols]*Y_rows[irows][jcols] );

	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			C[irows][jcols] = complex<double>( cos(C_Theta[irows][jcols]), sin(C_Theta[irows][jcols]) );

	////C1 = exp((j*k)/(2*d1)*(xh.^2+yh.^2));
	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			C1_Theta[irows][jcols] = K/(2*D1)*( Xh_cols[irows][jcols]*Xh_cols[irows][jcols]+Yh_rows[irows][jcols]*Yh_rows[irows][jcols] );

	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			C1[irows][jcols] = complex<double>( cos(C1_Theta[irows][jcols]), sin(C1_Theta[irows][jcols]) );

	//由于采用带夹角的参考光导致傅里叶频移，所以使用平面波去重建，即R=1
	////% R_conj=conj(R);
	////% Uh1=R_conj.*I;
	////Uh1 = I;
	////Uh2=C1.*Uh1;
	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			Uh2[irows][jcols] = C1[irows][jcols]*I[irows][jcols];

	////Uh2_fft=fftshift(fft2(fftshift(Uh2)));
	Uh2_fft = fftshift(fft2(fftshift(Uh2)));

	////U=C0.*C.*(Uh2_fft);%利用傅里叶变换法实现再现
	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			U_complex[irows][jcols] = C0*C[irows][jcols]*Uh2_fft[irows][jcols];

	////U = abs(U);
	U = ampOfComplex(U_complex);

	//不使用数字相减得到的U，取光强无法看到信息，所以只取振幅
	/*for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			U[irows][jcols] = U[irows][jcols]*U[irows][jcols];*/

	return U;
}

void SZQX_Dig2Dig::HideAllTab()
{
	pageOriImage.ShowWindow(false);
	pageHologram.ShowWindow(false);
	pageReImage.ShowWindow(false);
}

void SZQX_Dig2Dig::OnBnClickedbtnreadoriimage()//读图按钮
{
	// TODO: 在此添加控件通知处理程序代码
	tabDig2Dig.SetCurSel(0);

	//每次读图都必须取消所有选项卡对话框
	HideAllTab();

	CString filter = "BMP (*.bmp)|*.bmp|All (*.*)|*.*||";

	CFileDialog openDlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST| OFN_HIDEREADONLY, filter);///TRUE为OPEN对话框，FALSE为SAVE AS对话框
	if(openDlg.DoModal() != IDOK){
		return;
	}
	CString filePath = openDlg.GetPathName();
	readFromBmp(pU0, LPCTSTR(filePath));

	//读图限制
	int sign = ReadBMPLimit(pU0);

	if (sign == 1)
	{
		AfxMessageBox("图片尺寸过大，建议压缩");
		pU0 = Matrix<double>(0,0);
		return;
	}//end if

	if (sign == 2)
	{
		AfxMessageBox("图片尺寸不标准，进行扩充");
	}//end if

	pageOriImage.GetImage();//子窗口获取原图
	pageOriImage.ShowWindow(true);
	Invalidate();
}

void SZQX_Dig2Dig::OnBnClickedbtngenerationholo()//生成计算全息图按钮
{
	// TODO: 在此添加控件通知处理程序代码
	tabDig2Dig.SetCurSel(1);

	int Nrows = pU0.num_rows();//行
	if (Nrows == 0){
		AfxMessageBox("读图有误");
		return;
	}//end if

	HideAllTab();

	UpdateData(TRUE);
	int Radio1_FC, Radio2_FDS;//创建单选按钮变量
	Radio1_FC = ((CButton *)GetDlgItem(IDC_rbFresnelConvolution))->GetCheck();
	Radio2_FDS = ((CButton *)GetDlgItem(IDC_rbFresnelWithDigiSubtract))->GetCheck();

	CString str_D;
	GetDlgItem(IDC_editD)->GetWindowText(str_D);//获得当前衍射距离编辑框中数值
	D = atof(str_D);

	if (D <= 0)
	{
		AfxMessageBox("请输入距离");
		return;
	}//end if

	D = D*1000;//将单位转为微米

	CString str_Sita;
	GetDlgItem(IDC_editSita)->GetWindowText(str_Sita);//获得当前参考光夹角编辑框中数值
	double sita = atof(str_Sita);//参考光夹角

	if (sita <=0.000 || sita >2.500)
	{
		AfxMessageBox("夹角设置有误，请重新输入");
		return;
	}//end if

	if (Radio1_FC == 1)
	{
		I = FresnelConvolution(pU0, D, sita);
	}//end if

	if (Radio2_FDS == 1)
	{
		I = FresnelWithDigiSubtract(pU0, D, sita);
	}//end if

	p_I = I;
	mat2Gray(p_I, 0, 255);//保证输出图像在灰度的值域范围

	pageHologram.GetHolo();
	pageHologram.ShowWindow(true);
}

void SZQX_Dig2Dig::OnBnClickedbtnreconstruction()//仿真再现按钮
{
	// TODO: 在此添加控件通知处理程序代码
	tabDig2Dig.SetCurSel(2);

	int Nrows = I.num_rows();//行
	if (Nrows == 0){
		AfxMessageBox("没有全息图");
		return;
	}

	HideAllTab();

	UpdateData(TRUE);
	CString str_D1;
	GetDlgItem(IDC_editD1)->GetWindowText(str_D1);//获得当前再现距离编辑框中数值
	double D1 = atof(str_D1);//参考光夹角
	D1 = D1*1000;//将单位转为微米

	pU = HoloReconstruction(I, D, D1);
	mat2Gray(pU, 0, 255);

	pageReImage.GetReImage();
	pageReImage.ShowWindow(true);
}

void SZQX_Dig2Dig::OnBnClickedbtnsavebmp()//保存仿真结果按钮
{
	// TODO: 在此添加控件通知处理程序代码
	//检测是否计算仿真结果
	if (pU.num_cols() == 0){
		AfxMessageBox("没有仿真结果");
		return;
	}

	CString filter = "BMP (*.bmp)|*.bmp|All (*.*)|*.*||";
	CFileDialog openDlg(FALSE, NULL, NULL, OFN_FILEMUSTEXIST| OFN_HIDEREADONLY, filter);///TRUE为OPEN对话框，FALSE为SAVE AS对话框
	if(openDlg.DoModal() != IDOK){
		return;
	}

	CString fileName;
	fileName = openDlg.GetFileName();
	fileName += ".bmp";
	imWrite(pU,(LPCTSTR)fileName);
}
要作何修改

# DeepSeek：

**原始回答**

根据新SLM的规格（图二）和 `SZQX_Dig2Dig.cpp` 的代码，以下是需要修改的关键部分及具体修改建议：

---

### **1. 像素尺寸与分辨率调整**
#### **需修改的文件**：
- `SZQX_Dig2Dig.cpp`（当前文件）
- 其他涉及硬编码分辨率或像素尺寸的文件（如 `SZQX_Dig2Opt.cpp`、`SZQX_Dig2Dig_Hologram.cpp` 等）。

#### **修改内容**：
- **旧参数**：`dx0 = dy0 = dxh = dyh = 5.200;`（单位：微米）  
- **新SLM参数**：像素尺寸为 **12.5μm**，分辨率为 **1024×768**。  
  ```cpp
  // 修改初始化代码中的像素尺寸
  dx0 = dy0 = dxh = dyh = 12.5;  // 更新为12.5微米
  ```
- **验证分辨率**：确保代码中的矩阵操作（如FFT）适配新分辨率（1024×768），避免越界或填充错误。

---

### **2. 光

全息图生成和再现效果。

# 用户：

光学参数更新， 刷新频率与时序控制，光学校准参数已经在SZQX_Dig2Opt.ccp有了修改在SZOX_Dig2Dig.cpp还要修改吗

# DeepSeek：

**原始回答**

在 `SZQX_Dig2Dig.cpp` 中是否需要修改，取决于该文件是否直接依赖新SLM的光学参数、刷新频率或校准参数。以下是具体分析：

---

### **1. 光学参数更新**
#### **需检查的内容**：
- **波长（`Lambda`）**：  
  - 当前代码中硬编码为 `Lambda = 0.6328`（632.8nm）。  
  - **是否需要修改**：  
    - 如果 `SZQX_Dig2Opt.cpp` 已全局覆盖波长参数，且 `SZQX_Dig2Dig.cpp` 仅用于仿真（不直接控制SLM），则无需修改。  
    - 若涉及多波长仿真或与SLM实际波长联动，需同步更新为可配置参数。  

- **相位调制范围（`<1.2π`）**：  
  - 当前代码中未显式限制相位输出范围（例如 `FresnelConvolution()` 中的相位计算）。  
  - **是否需要修改**：  
    - 如果全息图生成后由 `SZQX_Dig2Opt.cpp` 统一处理相位限制，则无需修改。  
 

分，进一步分析协同性。

# 用户：

与数字再现相关的修改要修改SZQX_Dig2Opt.cpp文件还要修改什么文件

# DeepSeek：

**原始回答**

在将SLM更换为新型号（图二参数）并修改 `SZQX_Dig2Opt.cpp`（控制程序）后，若涉及**数字再现（Digital Reconstruction）**相关的功能，还需检查以下文件是否需要同步修改：

---

### **1. 必须修改的文件**
#### **(1) `SZQX_Dig2Dig.cpp`（当前文件）**
- **修改点**：  
  - **像素尺寸**：更新 `dxh/dyh` 为 **12.5μm**（新SLM参数）。  
    ```cpp
    dx0 = dy0 = dxh = dyh = 12.5; // 原为5.2μm
    ```
  - **分辨率适配**：确保矩阵运算（如FFT）兼容 **1024×768**，避免越界。  
  - **相位限制**：若新SLM相位调制范围 **<1.2π**，需在相位生成函数中增加限制：  
    ```cpp
    // 在FresnelConvolution()或FresnelWithDigiSubtract()中
    phase_o

## 关键结论

原对话最后阶段给出的主要判断或处理方向：原始回答** 在将SLM更换为新型号（图二参数）并修改 `SZQX_Dig2Opt.cpp`（控制程序）后，若涉及**数字再现（Digital Reconstruction）**相关的功能，还需检查以下文件是否需要同步修改： **1. 必须修改的文件** **(1) `SZQX_Dig2Dig.cpp`（当前文件）** **修改点**： **像素尺寸**：更新 `dxh/dyh` 为 **12.5μm**（新SLM参数）。

## 上下文关系

- 所属项目：bce3f1b967-software-01
- 当前阶段：阶段1/2
- 前置切片：无
- 后续切片：脉冲测距故障排查_a4819898.md
- 附件说明：无
