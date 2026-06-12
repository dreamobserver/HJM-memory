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
   - `SZOX_Opt2Dig.cpp`、`SZOX_Opt2Dig_Hologram.cpp`、`SZOX_Opt2Dig_ReImage.cpp`  
     新SLM的相位调制能力（<1.2π）可能影响相位生成算法，需验证或调整。

4. **接口和通信程序**  
   - `SZOX.cpp`、`SZOXDig.cpp`  
     如果新SLM的数据接口（HDMI）与旧设备不同，可能需要更新通信协议或初始化代码。

5. **光学参数校准程序**  
   - `SZOX_Info_Security.cpp`、`SZOX_Info_Security_Hologram.cpp`  
     这些程序可能包含透过率（25.5%/32.4%）、填充因子（77%）等校准参数，需更新以匹配新SLM的特性。

6. **刷新频率和时序控制程序**  
   - `SZOX_Opt2Opt.cpp`、`SZOX_Opt2Opt_Hologram.cpp`  
     若新SLM的刷新频率（60Hz/75Hz/85Hz）与旧设备不同，需调整时序相关的代码。

### 建议步骤：
1. **检查硬编码参数**：在所有程序中搜索旧SLM的分辨率、像素尺寸、相位范围等参数，替换为新SLM的数值。  
2. **验证光学模型**：确保基于新SLM的光学计算（如衍射算法）仍适用。  
3. **测试接口兼容性**：确认HDMI接口的驱动和通信协议是否需要调整。  
4. **校准和测试**：更新校准参数后，需重新测试全功能（特别是成像质量和相位调制精度）。  

注意：若某些程序是通用模块（如`stdafx.cpp`），可能无需修改，但需检查其依赖项是否涉及SLM参数。

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

### **2. 光学参数更新**
#### **需修改的文件**：
- `SZQX_Dig2Dig.cpp`（当前文件）  
- `SZQX_Dig2Opt.cpp`、`SZQX_Opt2Dig.cpp`（涉及光学传递函数计算的文件）。

#### **修改内容**：
- **波长**：新SLM支持 **400nm-700nm**，但代码中硬编码为 `Lambda = 0.6328`（632.8nm，红光）。  
  若需兼容多波长，需改为可配置参数：
  ```cpp
  Lambda = 0.6328;  // 默认值，可增加UI输入或配置文件读取
  ```
- **相位调制范围**：新SLM相位调制 **<1.2π**，需检查相位生成算法是否需要限制输出范围：
  ```cpp
  // 在相位计算后添加限制（示例）
  for (auto& phase : phaseMatrix) {
      phase = fmod(phase, 1.2 * PI);  // 限制在1.2π内
  }
  ```

---

### **3. 刷新频率与时序控制**
#### **需修改的文件**：
- `SZQX_Dig2Opt.cpp`（控制程序）  
- `SZOX_Opt2Opt.cpp`（若涉及动态刷新）。

#### **修改内容**：
- 新SLM刷新频率为 **60Hz/75Hz/85Hz**，需调整控制代码中的延时或同步逻辑：
  ```cpp
  // 示例：设置刷新间隔（85Hz对应约11.76ms）
  Sleep(12);  // 粗略延时，需根据实际接口优化
  ```

---

### **4. 接口与通信协议**
#### **需修改的文件**：
- `SZQXDig.cpp`（底层通信）  
- `SZQX.cpp`（主控制逻辑）。

#### **修改内容**：
- 新SLM使用 **HDMI接口**，需验证现有代码是否兼容：
  - 若原代码使用自定义协议（如SPI），需重写为HDMI驱动。
  - 检查初始化序列和命令格式是否匹配新SLM的文档。

---

### **5. 光学校准参数**
#### **需修改的文件**：
- `SZQX_Info_Security.cpp`、`SZQX_Info_Security_Hologram.cpp`（校准相关）。

#### **修改内容**：
- 更新透过率（**25.5%/32.4%**）、填充因子（**77%**）等参数：
  ```cpp
  // 示例：校准代码中的参数
  const double transmittance = 0.324;  // 32.4%透过率
  const double fillFactor = 0.77;      // 77%填充因子
  ```

---

### **6. 其他注意事项**
1. **灰度阶数**：新SLM为 **8位（256阶）**，与代码中默认一致，无需修改。  
2. **对比度**：新SLM对比度（750:1）可能影响图像质量，需测试是否需要调整全息图生成算法。  
3. **工作电流**：硬件驱动需确保供电为 **5V/2A**，但软件层面通常无需修改。

---

### **修改步骤总结**
1. **优先级高**：  
   - 更新像素尺寸（`dxh`/`dyh`）和分辨率适配。  
   - 验证相位调制范围限制。  
2. **优先级中**：  
   - 调整接口通信（HDMI兼容性）。  
   - 更新光学参数（透过率、填充因子）。  
3. **优先级低**：  
   - 多波长支持（若需扩展）。  
   - 动态刷新率优化。

建议在修改后重新校准光学系统，并通过测试验证全息图生成和再现效果。

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
    - 若 `SZQX_Dig2Dig.cpp` 生成的相位数据直接传递给SLM，需增加限制逻辑（如 `fmod(phase, 1.2*PI)`）。

#### **结论**：  
若 `SZQX_Dig2Dig.cpp` 仅用于**数字仿真**（不涉及SLM硬件控制），光学参数可不修改；否则需与 `SZQX_Dig2Opt.cpp` 保持一致。

---

### **2. 刷新频率与时序控制**
#### **需检查的内容**：
- 当前文件中无直接控制SLM刷新频率的代码（如 `Sleep()` 或硬件同步逻辑）。  
- **是否需要修改**：  
  - 如果全息图生成是离线计算（如保存为文件后再由 `SZQX_Dig2Opt.cpp` 加载控制），则无需修改。  
  - 若涉及实时生成并推送数据到SLM（如动态全息显示），需与时序逻辑同步。

#### **结论**：  
通常无需修改，除非该文件参与实时控制流水线。

---

### **3. 光学校准参数**
#### **需检查的内容**：
- 当前文件中的 `mat2Gray()` 和 `ampOfComplex()` 函数用于图像归一化，但未使用SLM的透过率、填充因子等参数。  
- **是否需要修改**：  
  - 如果校准参数仅用于硬件控制（如 `SZQX_Dig2Opt.cpp` 中的光强补偿），则无需修改。  
  - 若仿真需精确模拟SLM光学特性（如透过率对衍射效率的影响），需引入校准参数。

#### **示例修改**（可选）：
```cpp
// 添加校准参数（若需要）
const double transmittance = 0.324; // 32.4%透过率
Matrix<double> calibratedU = U * transmittance; // 在输出前应用透过率
```

#### **结论**：  
除非仿真需要高精度模拟SLM光学效果，否则无需修改。

---

### **最终建议**
1. **无需修改的情况**：  
   - `SZQX_Dig2Dig.cpp` 仅用于**离线数字仿真**（如生成全息图文件），且硬件相关参数已由 `SZQX_Dig2Opt.cpp` 全局管理。  

2. **需要修改的情况**：  
   - 该文件直接参与SLM控制流水线（如实时生成并传输数据）。  
   - 仿真需要匹配新SLM的光学特性（如相位限制、透过率建模）。  

3. **推荐操作**：  
   - **检查函数调用链**：确认 `SZQX_Dig2Dig.cpp` 的输出是否被 `SZQX_Dig2Opt.cpp` 完全处理。  
   - **测试验证**：生成全息图后，通过新SLM显示，观察是否需调整参数（如因像素尺寸变化导致的缩放问题）。  

若仍有疑问，可提供 `SZQX_Dig2Opt.cpp` 中相关修改部分，进一步分析协同性。

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
    phase_output = fmod(phase_output, 1.2 * PI); // 限制相位范围
    ```

#### **(2) `SZQX_Dig2Dig_ReImage.cpp`**
- **作用**：数字再现算法的实现（如逆衍射计算）。  
- **修改点**：  
  - 更新衍射计算中的 **像素尺寸**（`dxh/dyh`）和 **波长**（若支持多波长）。  
  - 验证再现距离 `D1` 的单位是否与新SLM参数匹配（例如毫米→微米）。

#### **(3) `SZQX_Opt2Dig.cpp` 或 `SZQX_Opt2Dig_ReImage.cpp`**
- **作用**：光学到数字的逆向处理（如光学捕获图像的数字化再现）。  
- **修改点**：  
  - 同步修改 **分辨率** 和 **像素尺寸**，确保与数字再现模块一致。

---

### **2. 可能需要修改的文件**
#### **(1) `SZQX_Info_Security.cpp` 及相关文件**
- **作用**：校准和安全性检查（如光强均匀性校正）。  
- **修改点**：  
  - 更新透过率（**25.5%/32.4%**）、填充因子（**77%**）等参数，确保数字再现的仿真精度。

#### **(2) `SZQX_Dig2Dig_Hologram.cpp`**
- **作用**：全息图生成算法。  
- **修改点**：  
  - 若全息图生成依赖SLM参数（如相位调制曲线），需调整算法以匹配新SLM特性。

#### **(3) `SZQX.cpp`（主控制文件）**
- **作用**：协调各模块调用。  
- **修改点**：  
  - 若数字再现的流程发生变化（如新增预处理步骤），需在此文件中调整调用顺序。

---

### **3. 无需修改的文件**
- **`stdafx.cpp`**：仅包含预编译头文件，无业务逻辑。  
- **`SZOXDig.cpp`**：若仅处理底层通信（如HDMI驱动），且数字再现不涉及硬件交互。  
- **`SZQX_Dig2Opt_Hologram.cpp`**：若仅用于光学调制（如相位掩膜生成），与数字再现无关。

---

### **关键验证步骤**
1. **参数一致性检查**：  
   - 确保所有文件中 `dxh/dyh`、`Lambda`、`D/D1` 等参数单位统一（例如全用微米或全用毫米）。  
2. **数字再现流程测试**：  
   - 输入已知全息图，验证再现结果是否因像素尺寸变化导致图像缩放或畸变。  
3. **相位范围测试**：  
   - 生成极限相位（如1.2π）的全息图，检查SLM实际输出是否截断。

---

### **总结**
- **核心修改**：`SZQX_Dig2Dig.cpp`、`SZQX_Dig2Dig_ReImage.cpp`。  
- **次级检查**：`SZQX_Opt2Dig.cpp`、`SZQX_Info_Security.cpp`。  
- **依赖分析**：若数字再现是独立模块（如离线处理），可能只需调整少数文件；若与硬件控制深度耦合，需全面同步参数。  

建议结合SLM厂商的文档，重点检查衍射计算和相位映射相关的代码段。

# 用户：

SZQX_Dig2Dig_ReImage.cpp中没有像素尺寸的修改，代码如下// SZQX_Dig2Dig_ReImage.cpp : 实现文件
//

#include "stdafx.h"
#include "SZQX.h"
#include "SZQX_Dig2Dig_ReImage.h"
#include "SZQX_Dig2Dig.h"//父对话框

// SZQX_Dig2Dig_ReImage 对话框

IMPLEMENT_DYNAMIC(SZQX_Dig2Dig_ReImage, CDialog)

SZQX_Dig2Dig_ReImage::SZQX_Dig2Dig_ReImage(CWnd* pParent /*=NULL*/)
	: CDialog(SZQX_Dig2Dig_ReImage::IDD, pParent)
{
	pDib_U = NULL;
}

SZQX_Dig2Dig_ReImage::~SZQX_Dig2Dig_ReImage()
{
	if (pDib_U != NULL)
	{
		delete(pDib_U);
		pDib_U = NULL;
	}
}

void SZQX_Dig2Dig_ReImage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SZQX_Dig2Dig_ReImage, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// SZQX_Dig2Dig_ReImage 消息处理程序

void SZQX_Dig2Dig_ReImage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()
	int Nrows = pU.num_rows()/2;//行
	int Mcols = pU.num_cols()/2;//列
	if(pDib_U != NULL)
	{
		pDib_U->Draw(&dc,0,0,Mcols,Nrows);
	}
}

void SZQX_Dig2Dig_ReImage::DrawImage()
{
	if(pDib_U != NULL){
		delete(pDib_U);
		pDib_U = NULL;
	}
	pDib_U = new CDib(pU);
}

void SZQX_Dig2Dig_ReImage::GetReImage()
{
	SZQX_Dig2Dig *pDlg = (SZQX_Dig2Dig *)GetParent()->GetParent();//获得父对话框
	pU = pDlg->pU;//将父对话框的m_Image传给本窗口的m_Image

	DrawImage();
}

# DeepSeek：

**原始回答**

根据提供的 `SZQX_Dig2Dig_ReImage.cpp` 代码，该文件主要负责数字再现图像的显示（`OnPaint` 和 `DrawImage` 函数），**不涉及光学计算或像素尺寸的直接操作**。因此，在更换SLM型号后，是否需要修改此文件取决于以下情况：

---

### **1. 无需修改的情况**
- **功能定位**：  
  该文件仅作为**显示模块**，从父对话框 `SZQX_Dig2Dig` 中获取再现图像 `pU` 并渲染到界面。若父对话框（`SZQX_Dig2Dig.cpp`）已正确更新像素尺寸（`dxh/dyh = 12.5μm`）和分辨率（1024×768），且再现算法（如 `HoloReconstruction`）已适配新SLM参数，则此文件无需修改。

- **数据流分析**：  
  `pU` 数据来源于父对话框的 `pU` 成员变量，而 `pU` 是通过 `HoloReconstruction` 函数生成的。只要父对话框的计算逻辑已修正，显示模块无需调整。

---

### **2. 可能需要检查的内容**
#### **(1) 图像缩放逻辑**
- 当前代码中，`OnPaint` 函数将图像缩小为一半显示：
  ```cpp
  int Nrows = pU.num_rows()/2;  // 行数减半
  int Mcols = pU.num_cols()/2;  // 列数减半
  pDib_U->Draw(&dc, 0, 0, Mcols, Nrows);  // 绘制缩小后的图像
  ```
  - **是否需要修改**：  
    - 若新SLM分辨率（1024×768）与旧SLM不同，需确认是否仍需减半显示（可能因界面布局限制）。  
    - 若需完整分辨率显示，移除 `/2` 即可。

#### **(2) 图像格式兼容性**
- 确保 `CDib` 类（位图操作类）能正确处理新SLM生成的图像数据（如灰度范围、分辨率）。  
  - 若 `pU` 的数据范围或格式因SLM更换而变化（例如从8位灰度变为16位），需同步修改 `DrawImage` 中的 `CDib` 初始化逻辑。

---

### **3. 依赖项验证**
- **父对话框 `SZQX_Dig2Dig.cpp`**：  
  必须确保以下内容已修改：
  ```cpp
  // SZQX_Dig2Dig.cpp 中的初始化
  dxh = dyh = 12.5;  // 更新像素尺寸（新SLM为12.5μm）
  Lambda = 0.6328;   // 波长是否需调整？（新SLM支持400-700nm）
  ```
- **再现算法 `HoloReconstruction`**：  
  需验证该函数是否适配新SLM的像素尺寸和分辨率（例如衍射计算中的坐标缩放）。

---

### **结论**
- **无需修改**：若仅作为显示模块，且父对话框已正确处理新SLM参数。  
- **可选修改**：若需调整显示比例（如取消图像减半）或适配新的图像格式。  
- **依赖检查**：必须确保 `SZQX_Dig2Dig.cpp` 中的光学参数和算法已更新。

建议在完成父对话框的修改后，测试数字再现结果的显示是否正确（如图像比例、清晰度）。若显示异常，再根据具体问题调整 `SZQX_Dig2Dig_ReImage.cpp` 中的绘制逻辑。

# 用户：

SZQX_Info_Security.cpp 全部代码如下：// SZQX_Info_Security.cpp : 实现文件
//

#include "stdafx.h"
#include "SZQX.h"
#include "SZQX_Info_Security.h"
#include ".\include\fft\fft2.h"
#include ".\include\fft\GS_matlab.h"
#include ".\include\fft\cpukit.h"
#include "include\SZQX_InLine.h"

// SZQX_Info_Security 对话框

IMPLEMENT_DYNAMIC(SZQX_Info_Security, CDialog)

SZQX_Info_Security::SZQX_Info_Security(CWnd* pParent /*=NULL*/)
	: CDialog(SZQX_Info_Security::IDD, pParent)
{
	//初始化常量
	Lambda = 0.6328;
	K = 2*PI/Lambda;
	dx0 = dy0 = dxh = dyh = 5.200;
	pSLM=NULL;
}

SZQX_Info_Security::~SZQX_Info_Security()
{
	if (pSLM!=NULL)
	{
		delete(pSLM);
		pSLM=NULL;
	}
}

void SZQX_Info_Security::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_tabInfo_Security, tabInfo_Security);
}


BEGIN_MESSAGE_MAP(SZQX_Info_Security, CDialog)
	ON_NOTIFY(TCN_SELCHANGE, IDC_tabInfo_Security, &SZQX_Info_Security::OnTcnSelchangetabinfoSecurity)
	ON_BN_CLICKED(IDC_btnReadOriImage_1, &SZQX_Info_Security::OnBnClickedbtnreadoriimage1)
	ON_BN_CLICKED(IDC_btnReadOriImage_2, &SZQX_Info_Security::OnBnClickedbtnreadoriimage2)
	ON_BN_CLICKED(IDC_btnReadOriImage_3, &SZQX_Info_Security::OnBnClickedbtnreadoriimage3)
	ON_BN_CLICKED(IDC_btnGenerationHolo, &SZQX_Info_Security::OnBnClickedbtngenerationholo)
	ON_BN_CLICKED(IDC_btnSLMOut, &SZQX_Info_Security::OnBnClickedbtnslmout)
	ON_BN_CLICKED(IDC_btnReconstruction, &SZQX_Info_Security::OnBnClickedbtnreconstruction)
	ON_BN_CLICKED(IDC_btnSaveBMP, &SZQX_Info_Security::OnBnClickedbtnsavebmp)
END_MESSAGE_MAP()


// SZQX_Info_Security 消息处理程序

BOOL SZQX_Info_Security::OnInitDialog()
{
	CDialog::OnInitDialog();

	//初始化对话框各控件位置与大小
	GetDlgItem(IDC_btnReadOriImage_1)->SetWindowPos(NULL,800-240, 20, 64, 36, SWP_SHOWWINDOW); 
	GetDlgItem(IDC_btnReadOriImage_2)->SetWindowPos(NULL,800-170, 20, 64, 36, SWP_SHOWWINDOW); 
	GetDlgItem(IDC_btnReadOriImage_3)->SetWindowPos(NULL,800-240, 60, 64, 36, SWP_SHOWWINDOW); 
	GetDlgItem(IDC_btnGenerationHolo)->SetWindowPos(NULL,800-170, 60, 64, 36, SWP_SHOWWINDOW); 
	GetDlgItem(IDC_btnSLMOut)->SetWindowPos(NULL,800-240, 100, 64, 36, SWP_SHOWWINDOW); 
	GetDlgItem(IDC_btnReconstruction)->SetWindowPos(NULL,800-170, 100, 64, 36, SWP_SHOWWINDOW); 
	GetDlgItem(IDC_btnSaveBMP)->SetWindowPos(NULL, 800-200, 500, 64, 36, SWP_SHOWWINDOW);

	GetDlgItem(IDC_staD_record1)->SetWindowPos(NULL,800-250, 180, 64, 36, SWP_SHOWWINDOW); 
	GetDlgItem(IDC_editD_record1)->SetWindowPos(NULL,800-150, 180, 64, 18, SWP_SHOWWINDOW); 
	GetDlgItem(IDC_staD_record2)->SetWindowPos(NULL,800-250, 220, 64, 36, SWP_SHOWWINDOW); 
	GetDlgItem(IDC_editD_record2)->SetWindowPos(NULL,800-150, 220, 64, 18, SWP_SHOWWINDOW);
	GetDlgItem(IDC_staD_record3)->SetWindowPos(NULL,800-250, 260, 64, 36, SWP_SHOWWINDOW); 
	GetDlgItem(IDC_editD_record3)->SetWindowPos(NULL,800-150, 260, 64, 18, SWP_SHOWWINDOW);
	GetDlgItem(IDC_staSita)->SetWindowPos(NULL,800-250, 300, 64, 36, SWP_SHOWWINDOW); 
	GetDlgItem(IDC_editSita)->SetWindowPos(NULL,800-150, 300, 64, 18, SWP_SHOWWINDOW);
	GetDlgItem(IDC_staGenerationHolo)->SetWindowPos(NULL,800-260, 150, 200, 200, SWP_SHOWWINDOW);

	GetDlgItem(IDC_staD_reconstruction)->SetWindowPos(NULL,800-250, 420, 64, 36, SWP_SHOWWINDOW); 
	GetDlgItem(IDC_editD_reconstruction)->SetWindowPos(NULL,800-150, 420, 64, 18, SWP_SHOWWINDOW); 
	GetDlgItem(IDC_staReconstruction)->SetWindowPos(NULL,800-260, 380, 200, 100, SWP_SHOWWINDOW);

	GetDlgItem(IDC_staPartition)->SetWindowPos(NULL, 520, 0 , 2, 750, SWP_SHOWWINDOW);

	//添加标签控件子选项卡名称
	tabInfo_Security.InsertItem(0, "原图1");
	tabInfo_Security.InsertItem(1, "原图2");
	tabInfo_Security.InsertItem(2, "原图3");
	tabInfo_Security.InsertItem(3, "全息图");
	tabInfo_Security.InsertItem(4, "再现图");

	//关联对话框,并且将IDC_tabInfo_Security控件设为父窗口
	pageOriImage_1.Create(IDD_SZQX_Info_Security_OriImage_1_tab_dlg, GetDlgItem(IDC_tabInfo_Security));
	pageOriImage_2.Create(IDD_SZQX_Info_Security_OriImage_2_tab_dlg, GetDlgItem(IDC_tabInfo_Security));
	pageOriImage_3.Create(IDD_SZQX_Info_Security_OriImage_3_tab_dlg, GetDlgItem(IDC_tabInfo_Security));
	pageHologram.Create(IDD_SZQX_Info_Security_Hologram_tab_dlg, GetDlgItem(IDC_tabInfo_Security));
	pageReImage.Create(IDD_SZQX_Info_Security_ReImage_tab_dlg, GetDlgItem(IDC_tabInfo_Security));

	//控制IDC_tabInfo_Security客户区大小
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
	tabInfo_Security.MoveWindow(&rsTab);
	//调整Tab页面对话框的位置
	pageOriImage_1.MoveWindow(&rs);
	pageOriImage_2.MoveWindow(&rs);
	pageOriImage_3.MoveWindow(&rs);
	pageHologram.MoveWindow(&rs);
	pageReImage.MoveWindow(&rs);

	pageOriImage_1.ShowWindow(true);//显示

	//设置默认的选项卡
	tabInfo_Security.SetCurSel(0);//默认在第一个选项卡

	//初始化参数
	GetDlgItem(IDC_editD_record1)->SetWindowText("50");//衍射距离
	GetDlgItem(IDC_editD_record2)->SetWindowText("80");
	GetDlgItem(IDC_editD_record3)->SetWindowText("110");
	GetDlgItem(IDC_editSita)->SetWindowText("1.6");//参考光夹角

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void SZQX_Info_Security::PostNcDestroy()
{
	// TODO: 在此添加专用代码和/或调用基类

	delete this;
	CDialog::PostNcDestroy();
}

void SZQX_Info_Security::OnTcnSelchangetabinfoSecurity(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	int CurSel = tabInfo_Security.GetCurSel();
	switch(CurSel) 
	{ 
	case 0: 
		pageOriImage_1.ShowWindow(true);//显示
		pageOriImage_2.ShowWindow(false);
		pageOriImage_3.ShowWindow(false);
		pageHologram.ShowWindow(false);
		pageReImage.ShowWindow(false);
		break; 
	case 1: 
		pageOriImage_1.ShowWindow(false);
		pageOriImage_2.ShowWindow(true);//显示
		pageOriImage_3.ShowWindow(false);
		pageHologram.ShowWindow(false);
		pageReImage.ShowWindow(false);
		break;
	case 2:
		pageOriImage_1.ShowWindow(false);
		pageOriImage_2.ShowWindow(false);
		pageOriImage_3.ShowWindow(true);//显示
		pageHologram.ShowWindow(false);
		pageReImage.ShowWindow(false);
		break;
	case 3:
		pageOriImage_1.ShowWindow(false);
		pageOriImage_2.ShowWindow(false);
		pageOriImage_3.ShowWindow(false);
		pageHologram.ShowWindow(true);//显示
		pageReImage.ShowWindow(false);
		break;
	case 4:
		pageOriImage_1.ShowWindow(false);
		pageOriImage_2.ShowWindow(false);
		pageOriImage_3.ShowWindow(false);
		pageHologram.ShowWindow(false);
		pageReImage.ShowWindow(true);//显示
		break;
	default: 
		; 
	} 

	*pResult = 0;
}

void SZQX_Info_Security::HideAllTab()
{
	pageOriImage_1.ShowWindow(false);
	pageOriImage_2.ShowWindow(false);
	pageOriImage_3.ShowWindow(false);
	pageHologram.ShowWindow(false);
	pageReImage.ShowWindow(false);
}


void SZQX_Info_Security::OnBnClickedbtnreadoriimage1()//添加原图1按钮
{
	// TODO: 在此添加控件通知处理程序代码
	tabInfo_Security.SetCurSel(0);

	//每次读图都必须取消所有选项卡对话框
	HideAllTab();

	CString filter = "BMP (*.bmp)|*.bmp|All (*.*)|*.*||";

	CFileDialog openDlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST| OFN_HIDEREADONLY, filter);///TRUE为OPEN对话框，FALSE为SAVE AS对话框
	if(openDlg.DoModal() != IDOK){
		return;
	}
	CString filePath = openDlg.GetPathName();
	readFromBmp(pU1_ori, LPCTSTR(filePath));

	//只读入1024*768的的原图
	if (pU1_ori.num_rows()!=768 || pU1_ori.num_cols()!=1024)
	{
		AfxMessageBox("图片尺寸有误");
		pU1_ori = Matrix<double>(0,0);
		return;
	}//end if

	pageOriImage_1.GetImage();//子窗口获取原图
	pageOriImage_1.ShowWindow(true);
}

void SZQX_Info_Security::OnBnClickedbtnreadoriimage2()//添加原图2按钮
{
	// TODO: 在此添加控件通知处理程序代码
	tabInfo_Security.SetCurSel(1);

	//每次读图都必须取消所有选项卡对话框
	HideAllTab();

	CString filter = "BMP (*.bmp)|*.bmp|All (*.*)|*.*||";

	CFileDialog openDlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST| OFN_HIDEREADONLY, filter);///TRUE为OPEN对话框，FALSE为SAVE AS对话框
	if(openDlg.DoModal() != IDOK){
		return;
	}
	CString filePath = openDlg.GetPathName();
	readFromBmp(pU2_ori, LPCTSTR(filePath));

	//只读入1024*768的的原图
	if (pU2_ori.num_rows()!=768 || pU2_ori.num_cols()!=1024)
	{
		AfxMessageBox("图片尺寸有误");
		pU2_ori = Matrix<double>(0,0);
		return;
	}//end if

	pageOriImage_2.GetImage();//子窗口获取原图
	pageOriImage_2.ShowWindow(true);
}

void SZQX_Info_Security::OnBnClickedbtnreadoriimage3()//添加原图3按钮
{
	// TODO: 在此添加控件通知处理程序代码
	tabInfo_Security.SetCurSel(2);

	//每次读图都必须取消所有选项卡对话框
	HideAllTab();

	CString filter = "BMP (*.bmp)|*.bmp|All (*.*)|*.*||";

	CFileDialog openDlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST| OFN_HIDEREADONLY, filter);///TRUE为OPEN对话框，FALSE为SAVE AS对话框
	if(openDlg.DoModal() != IDOK){
		return;
	}
	CString filePath = openDlg.GetPathName();
	readFromBmp(pU3_ori, LPCTSTR(filePath));

	//只读入1024*768的的原图
	if (pU3_ori.num_rows()!=768 || pU3_ori.num_cols()!=1024)
	{
		AfxMessageBox("图片尺寸有误");
		pU3_ori = Matrix<double>(0,0);
		return;
	}//end if

	pageOriImage_3.GetImage();//子窗口获取原图
	pageOriImage_3.ShowWindow(true);
}

void SZQX_Info_Security::OnBnClickedbtngenerationholo()//生成三层全息图按钮
{
	tabInfo_Security.SetCurSel(3);

	//每次读图都必须取消所有选项卡对话框
	HideAllTab();

	//判断是否读图
	int Nrows1 = pU1_ori.num_rows();//行
	int Nrows2 = pU2_ori.num_rows();//行
	int Nrows3 = pU3_ori.num_rows();//行
	if (Nrows1 == 0 || Nrows2 == 0 || Nrows3 == 0){
		AfxMessageBox("请读入图片");
		return;
	}//end if

	UpdateData(TRUE);
	CString str_D_record1, str_D_record2, str_D_record3;
	GetDlgItem(IDC_editD_record1)->GetWindowText(str_D_record1);//获得当前衍射距离编辑框中数值
	GetDlgItem(IDC_editD_record2)->GetWindowText(str_D_record2);
	GetDlgItem(IDC_editD_record3)->GetWindowText(str_D_record3);
	D_record1 = atof(str_D_record1);
	D_record2 = atof(str_D_record2);
	D_record3 = atof(str_D_record3);

	if (D_record1 <= 0)
	{
		AfxMessageBox("请输入距离");
		return;
	}//end if

	if (D_record2 <= 0)
	{
		AfxMessageBox("请输入距离");
		return;
	}//end if

	if (D_record3 <= 0)
	{
		AfxMessageBox("请输入距离");
		return;
	}//end if

	D_record1 = D_record1*1000;//将单位转为微米
	D_record2 = D_record2*1000;
	D_record3 = D_record3*1000;

	CString str_Sita;
	GetDlgItem(IDC_editSita)->GetWindowText(str_Sita);//获得当前参考光夹角编辑框中数值
	double sita = atof(str_Sita);//参考光夹角

	if (sita <=0.000 || sita >2.500)
	{
		AfxMessageBox("夹角设置有误，请重新输入");
		return;
	}//end if

	//计算三层全息图
	ThreeD_Diffraction(pU1_ori, pU2_ori, pU3_ori, D_record1, D_record2, D_record3, sita);

	pI_Subtract = I_Subtract;
	mat2Gray(pI_Subtract, 0 ,255);//保证输出图像在灰度的值域范围

	pageHologram.GetHolo();//只显示数字相减处理后的全息图,未处理图作为SLM显示用
	pageHologram.ShowWindow(true);

}

Matrix<complex<double>>  SZQX_Info_Security::FresnelConvolutionFor3D(Matrix<double> &pU0, double D_temp)//利用卷积法衍射，针对三维物体修改部分代码
{
	//这个函数不改变输入的原图 pU0 信息，只输出全息图I_temp，
	//对于显示的全息图，根据是否使用数字相减法作决定

	//变量定义
	int Nrows = pU0.num_rows();//行
	int Mcols = pU0.num_cols();//列
	Matrix<double> Xh_cols(Nrows, Mcols);//xh：全息面上坐标x轴初始化
	Matrix<double> Yh_rows(Nrows, Mcols);//yh：。。。。。。y。。。。
	Matrix<complex<double>> hTransfer(Nrows, Mcols);//传递函数
	Matrix<double> h_theta(Nrows,Mcols);//传递函数的幅角θ矩阵
	Matrix<complex<double>> F(Nrows,Mcols);//输入图像的傅里叶变换
	Matrix<complex<double>> comU0(Nrows,Mcols);//复数形式的 U0
	Matrix<complex<double>> HImpulse(Nrows, Mcols);//传递函数hTransfer的脉冲响应
	Matrix<complex<double>> HFTemp(Nrows, Mcols);//创建H.*F的临时交换矩阵
	Matrix<complex<double>> O(Nrows, Mcols);//O为全息面上的衍射图像
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

	return O;
}

void SZQX_Info_Security::ThreeD_Diffraction(Matrix<double> &pU1_ori, Matrix<double>&pU2_ori, Matrix<double>&pU3_ori, 
											double d_record1, double d_record2, double d_record3, double sita)
{
	int Nrows = 1024;//行
	int Mcols = Nrows;//列
	int U_top = Nrows/2-pU1_ori.num_rows()/2;//行上限
	int U_bottom = U_top+pU1_ori.num_rows();//行下限
	//建立新的原图矩阵
	Matrix<double> U1(Nrows ,Mcols);
	Matrix<double> U2(Nrows, Mcols);
	Matrix<double> U3(Nrows, Mcols);
	//变量定义
	double theta = sita*PI/180.0000;//对夹角作弧度转换
	Matrix<complex<double>> O1(Nrows, Mcols);//扩充后的原图
	Matrix<complex<double>> O2(Nrows, Mcols);
	Matrix<complex<double>> O3(Nrows, Mcols);
	Matrix<complex<double>> O(Nrows, Mcols);//计算得到3层全息叠加图
	Matrix<complex<double>> R(Nrows, Mcols);//参考光
	Matrix<double> R_Theta(Nrows, Mcols);//简化程序，引入参考光幅角矩阵
	Matrix<complex<double>> ih(Nrows, Mcols);//全息图的复数形式
	Matrix<double> I_temp(Nrows, Mcols);//创建全息振幅图的临时矩阵
	Matrix<double> pU0_temp(Nrows, Mcols);//创建原图的临时矩阵
	Matrix<double> Xh_cols(Nrows, Mcols);//xh：全息面上坐标x轴初始化
	Matrix<double> Yh_rows(Nrows, Mcols);//yh：。。。。。。y。。。。
	Matrix<double> O_Amp(Nrows,Mcols);//物光的振幅
	Matrix<double> R_Amp(Nrows,Mcols);//参考光振幅
	Matrix<double>R_Square(Nrows, Mcols);//求R光强R_Amp.^2
	Matrix<double>O_Square(Nrows, Mcols);//求O光强

	//将原图扩展为1024*1024
	for(int irows = 0; irows<pU1_ori.num_rows(); irows++)
		for(int jcols = 0; jcols<pU1_ori.num_cols(); jcols++)
			U1[U_top+irows][jcols] = pU1_ori[irows][jcols];

	for(int irows = 0; irows<pU2_ori.num_rows(); irows++)
		for(int jcols = 0; jcols<pU2_ori.num_cols(); jcols++)
			U2[U_top+irows][jcols] = pU2_ori[irows][jcols];

	for(int irows = 0; irows<pU3_ori.num_rows(); irows++)
		for(int jcols = 0; jcols<pU3_ori.num_cols(); jcols++)
			U3[U_top+irows][jcols] = pU3_ori[irows][jcols];

	O1 = FresnelConvolutionFor3D(U1, d_record1);
	O2 = FresnelConvolutionFor3D(U2, d_record2);
	O3 = FresnelConvolutionFor3D(U3, d_record3);
	O = O1+O2+O3;	

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

	I_ori = I_temp;//没有使用数字相减的全息图
	R_Amp = ampOfComplex(R);
	O_Amp = ampOfComplex(O);

	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			R_Square[irows][jcols] = R_Amp[irows][jcols]*R_Amp[irows][jcols];

	for(int irows = 0; irows<Nrows; irows++)
		for(int jcols = 0; jcols<Mcols; jcols++)
			O_Square[irows][jcols] = O_Amp[irows][jcols]*O_Amp[irows][jcols];

	//数字相减不需要做 mat2Gray！！
	I_temp = I_temp-R_Square-O_Square;

	I_Subtract = I_temp;//使用数字相减的全息图
}

Matrix<double>  SZQX_Info_Security::HoloReconstruction(Matrix<double> &I, double D_temp, double D1)//再现全息图
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

Matrix<double> SZQX_Info_Security::CutMatrix(Matrix<double> &input, double NewRows, double NewCols)
{
	int Nrows = input.num_rows();
	int Mcols = input.num_cols();
	int top = Nrows/2-(int)NewRows/2;
	int left = Mcols/2-(int)NewCols/2;

	Matrix<double> temp((int)NewRows, (int)NewCols);

	for(int irows = 0; irows<NewRows; irows++)
		for(int jcols = 0; jcols<NewCols; jcols++)
			temp[irows][jcols] = input[top+irows][left+jcols];

	return temp;
}

void SZQX_Info_Security::DrawSLM()
{
	if(pSLM!=NULL){
		delete(pSLM);
		pSLM = NULL;
	}
	pSLM = new CDib(pI_ori);
}
void SZQX_Info_Security::OnBnClickedbtnslmout()//输出到SLM
{
	// TODO: 在此添加控件通知处理程序代码
	if (I_ori.num_cols() == 0)
	{AfxMessageBox(" 没有全息图");
	return;
	}
	pI_ori = CutMatrix(I_ori, 768, 1024);
	mat2Gray(pI_ori, 0, 255);//经过剪切后的全息图变换成灰度阈值。

	CMonitor monitor;
	CMonitors monitors;

	//测试SLM存在与否
	if (monitors.GetCount()<2)
	{AfxMessageBox(" 没有连接SLM");
	return;
	}

	monitor = monitors.GetMonitor( 1 );//0 第一屏 1 第二屏
	CRect rect;
	monitor.GetMonitorRect( &rect );
	CMonitorDC dc( &monitor );

	CBrush brush(RGB(0,0,0));//黑画刷
	dc.FillRect(&rect,&brush);//填充背景

	int i_MoHight,i_MoWidth;
	i_MoWidth=rect.right-rect.left;
	i_MoHight=rect.bottom-rect.top;

	DrawSLM();

	if(pSLM != NULL)//绘图到其他屏
	{
		pSLM->Draw(&dc, rect.left, rect.top, i_MoWidth, i_MoHight);
	}
}

void SZQX_Info_Security::OnBnClickedbtnreconstruction()//再现按钮
{
	// TODO: 在此添加控件通知处理程序代码
	tabInfo_Security.SetCurSel(4);

	//每次读图都必须取消所有选项卡对话框
	HideAllTab();

	if (I_Subtract.num_cols() == 0)
	{AfxMessageBox(" 没有全息图");
	return;
	}

	UpdateData(TRUE);
	CString str_D_reconstruction;
	GetDlgItem(IDC_editD_reconstruction)->GetWindowText(str_D_reconstruction);//获得当前再现距离编辑框中数值
	double D_reconstruction = atof(str_D_reconstruction);//参考光夹角

	if (D_reconstruction == 0)
	{
		AfxMessageBox("请输入距离");
		return;
	}//end if

	D_reconstruction = D_reconstruction*1000;//将单位转为微米

	pU = HoloReconstruction(I_Subtract, D_record1, D_reconstruction);
	mat2Gray(pU, 0, 255);

	pageReImage.GetReImage();
	pageReImage.ShowWindow(true);
}

void SZQX_Info_Security::OnBnClickedbtnsavebmp()//保存仿真结果图按钮
{
	// TODO: 在此添加控件通知处理程序代码
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

# DeepSeek：

**原始回答**

根据 `SZQX_Info_Security.cpp` 的完整代码和新型号SLM的参数（像素尺寸 **12.5μm**，分辨率 **1024×768**），以下是需要修改的关键部分及具体修改建议：

---

### **1. 必须修改的核心参数**
#### **(1) 像素尺寸初始化**
- **当前代码**：  
  ```cpp
  dx0 = dy0 = dxh = dyh = 5.200;  // 单位：微米（旧SLM参数）
  ```
- **修改为**：  
  ```cpp
  dx0 = dy0 = dxh = dyh = 12.5;  // 更新为新SLM的像素尺寸（12.5μm）
  ```
  **影响范围**：  
  - 所有衍射计算（如 `FresnelConvolutionFor3D`、`ThreeD_Diffraction`）中的坐标生成（`Xh_cols`/`Yh_rows`）。  
  - 再现算法（`HoloReconstruction`）中的 `dx`/`dy` 计算。

#### **(2) 分辨率适配**
- **当前代码**：  
  - 硬编码为 `1024×1024`（如 `ThreeD_Diffraction` 中的 `Nrows = 1024`），但新SLM分辨率为 **1024×768**。  
- **修改建议**：  
  - 若需严格匹配新SLM，需调整矩阵操作的分辨率（如 `U1`/`U2`/`U3` 的初始化）：  
    ```cpp
    int Nrows = 768;  // 更新为SLM实际行数
    int Mcols = 1024; // 更新为SLM实际列数
    ```
  - **注意**：需同步修改图像裁剪逻辑（如 `CutMatrix` 函数中的 `NewRows`/`NewCols`）。

---

### **2. 光学参数更新**
#### **(1) 波长（`Lambda`）**
- **当前代码**：  
  ```cpp
  Lambda = 0.6328;  // 632.8nm（固定值）
  ```
- **是否需要修改**：  
  - 新SLM支持 **400-700nm**，若需多波长支持，建议改为可配置参数：  
    ```cpp
    Lambda = 0.6328;  // 默认值，可通过UI或配置文件调整
    ```

#### **(2) 相位调制范围**
- **新SLM限制**：相位调制 **<1.2π**。  
- **修改建议**：  
  在相位生成函数（如 `FresnelConvolutionFor3D`）中添加限制逻辑：  
  ```cpp
  // 在计算相位后添加限制
  phase_output = fmod(phase_output, 1.2 * PI);  // 限制相位范围
  ```

---

### **3. 图像处理与显示适配**
#### **(1) 图像缩放与裁剪**
- **当前代码**：  
  - `CutMatrix` 函数将 `1024×1024` 图像裁剪为 `768×1024`（可能不匹配新SLM）。  
- **修改建议**：  
  - 若新SLM需要 `1024×768`，调整裁剪逻辑：  
    ```cpp
    pI_ori = CutMatrix(I_ori, 768, 1024);  // 确保输出尺寸匹配SLM
    ```

#### **(2) 显示控件适配**
- **当前代码**：  
  - `OnPaint` 和 `DrawImage` 中的显示逻辑假设固定分辨率。  
- **修改建议**：  
  - 检查显示控件的尺寸是否适配 `1024×768`，避免图像拉伸或裁剪。

---

### **4. 硬件接口与输出**
#### **(1) SLM输出（`OnBnClickedbtnslmout`）**
- **当前代码**：  
  - 检测第二屏幕并输出图像，但未验证分辨率兼容性。  
- **修改建议**：  
  - 确保 `pI_ori` 的分辨率严格匹配SLM的 `1024×768`：  
    ```cpp
    pI_ori = CutMatrix(I_ori, 768, 1024);  // 强制匹配SLM
    ```

#### **(2) 刷新频率**
- **新SLM参数**：60Hz/75Hz/85Hz。  
- **是否需要修改**：  
  - 若代码中有动态刷新控制（如 `Sleep` 延时），需根据SLM支持的频率调整：  
    ```cpp
    Sleep(12);  // 85Hz对应约11.76ms/帧
    ```

---

### **5. 其他注意事项**
1. **单位一致性**：  
   - 确保所有距离参数（如 `D_record1`）的单位统一为 **微米**（当前代码已处理）。  
2. **校准参数**：  
   - 透过率（25.5%/32.4%）和填充因子（77%）可能影响仿真精度，但当前代码未显式使用，需根据实际需求决定是否引入。  
3. **测试验证**：  
   - 修改后需验证全息图生成、SLM输出和数字再现的结果是否正常（如图像比例、相位范围）。

---

### **修改总结**
| **文件**                  | **需修改内容**                          | **修改示例**                              |
|---------------------------|---------------------------------------|------------------------------------------|
| `SZQX_Info_Security.cpp`  | 像素尺寸（`dxh/dyh`）                 | `dxh = dyh = 12.5;`                     |
|                           | 分辨率适配（`Nrows`/`Mcols`）        | `int Nrows = 768; int Mcols = 1024;`    |
|                           | 相位限制（`<1.2π`）                  | `phase_output = fmod(phase, 1.2*PI);`   |
|                           | 图像裁剪（`CutMatrix`）              | `CutMatrix(I_ori, 768, 1024);`          |

---

### **验证步骤**
1. **编译运行**：确保无编译错误。  
2. **功能测试**：  
   - 生成全息图并输出到SLM，检查图像是否完整显示。  
   - 数字再现时验证重建图像是否清晰（如无畸变）。  
3. **参数检查**：  
   - 使用调试工具确认 `dxh`、`Lambda` 等参数在计算过程中是否正确传递。  

若仍有问题，建议结合SLM厂商的API文档进一步调试硬件接口部分。