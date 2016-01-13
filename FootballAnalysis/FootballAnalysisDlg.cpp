
// FootballAnalysisDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "FootballAnalysis.h"
#include "FootballAnalysisDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFootballAnalysisDlg 对话框




CFootballAnalysisDlg::CFootballAnalysisDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFootballAnalysisDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bIsMax = FALSE;
}

void CFootballAnalysisDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON6, m_btnMin);
	DDX_Control(pDX, IDC_BUTTON5, m_btnMax);
	DDX_Control(pDX, IDC_BUTTON4, m_btnNormal);
	DDX_Control(pDX, IDC_BUTTON1, m_btnClose);
	DDX_Control(pDX, IDC_BUTTON2, m_btnMatch);
	DDX_Control(pDX, IDC_BUTTON3, m_btnChuPei);
	DDX_Control(pDX, IDC_BUTTON7, m_btnGaoFeng);
	DDX_Control(pDX, IDC_BUTTON8, m_btnLiShi);
}

BEGIN_MESSAGE_MAP(CFootballAnalysisDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CFootballAnalysisDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CFootballAnalysisDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CFootballAnalysisDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON6, &CFootballAnalysisDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON5, &CFootballAnalysisDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON4, &CFootballAnalysisDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON7, &CFootballAnalysisDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CFootballAnalysisDlg::OnBnClickedButton8)
	ON_WM_LBUTTONDOWN()
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CFootballAnalysisDlg 消息处理程序

BOOL CFootballAnalysisDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	InitControl();
	MoveControl();
	SetMenuIndex(0);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CFootballAnalysisDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CFootballAnalysisDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CFootballAnalysisDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFootballAnalysisDlg::OnBnClickedButton1()
{
	CDialogEx::OnCancel();
}


void CFootballAnalysisDlg::OnBnClickedButton2()
{
	//第一个按钮
	SetMenuIndex(0);
}


void CFootballAnalysisDlg::OnBnClickedButton3()
{
	//第二个按钮
	SetMenuIndex(1);
}


void CFootballAnalysisDlg::SetMenuIndex(int nIndex)
{
	if (m_nSelectedIndex==nIndex)
		return;

	switch (nIndex)
	{
	case 0:
		m_pDlgMatch.ShowWindow(SW_SHOW);
		m_pDlgChuPei.ShowWindow(SW_HIDE);

		m_btnMatch.SetCheckType(TRUE);
		break;
	case 1:
		m_pDlgMatch.ShowWindow(SW_HIDE);
		m_pDlgChuPei.ShowWindow(SW_SHOW);

		m_btnChuPei.SetCheckType(TRUE);
		break;
	case 2:


		m_btnGaoFeng.SetCheckType(TRUE);
		break;
	case 3:

		m_btnLiShi.SetCheckType(TRUE);
		break;
	default:
		break;
	}

	switch (m_nSelectedIndex)
	{
	case 0:
		m_btnMatch.SetCheckType(FALSE);
		m_btnMatch.Invalidate();
		break;
	case 1:
		m_btnChuPei.SetCheckType(FALSE);
		m_btnChuPei.Invalidate();
		break;
	case 2:
		m_btnGaoFeng.SetCheckType(FALSE);
		m_btnGaoFeng.Invalidate();
		break;
	case 3:
		m_btnLiShi.SetCheckType(FALSE);
		m_btnLiShi.Invalidate();
		break;
	}
	m_nSelectedIndex = nIndex;

}


void CFootballAnalysisDlg::InitControl(void)
{
	SetWindowText(_T("足彩分析工具 V1.0"));
	ModifyStyle(0,WS_SYSMENU);

	m_pDlgMatch.Create(IDD_DIALOG_MATCH, this);
	m_pDlgChuPei.Create(IDD_DIALOG_CHUPEI, this);

	m_btnClose.LoadBitmap(IDB_BITMAP_CLOSE);
	m_btnMin.LoadBitmap(IDB_BITMAP_MIN);

	m_btnMatch.LoadBitmap(IDB_BITMAP_FENXI);
	m_btnChuPei.LoadBitmap(IDB_BITMAP_YAPEI);
	m_btnGaoFeng.LoadBitmap(IDB_BITMAP_OUPEI);
	m_btnLiShi.LoadBitmap(IDB_BITMAP_DAXIAOQIU);


	CRect dlgrect;
	GetClientRect(&dlgrect);
	ClientToScreen(&dlgrect);
	dlgrect.right=dlgrect.left+768;
	dlgrect.bottom=dlgrect.top+576;
	MoveWindow(&dlgrect);
}


void CFootballAnalysisDlg::MoveControl(void)
{
	CRect mrect,mrect1,mrect2;
	GetClientRect(&mrect);

	//Close
	mrect1.right=mrect.right-3;
	mrect1.left=mrect1.right-47;
	mrect1.top=mrect.top;
	mrect1.bottom=mrect1.top+19;
	m_btnClose.MoveWindow(&mrect1);

	mrect1.right=mrect1.left;
	mrect1.left=mrect1.right-33;
	mrect1.top=mrect.top;
	mrect1.bottom=mrect1.top+19;
	m_btnNormal.MoveWindow(&mrect1);
	m_btnMax.MoveWindow(&mrect1);

	mrect1.right=mrect1.left;
	mrect1.left=mrect1.right-33;
	mrect1.top=mrect.top;
	mrect1.bottom=mrect1.top+19;
	m_btnMin.MoveWindow(&mrect1);

	//query
	mrect1.top=mrect.top+23;
	mrect1.bottom=mrect1.top+88;
	mrect1.right=mrect.right-50;	
	mrect1.left=mrect1.right-76;	
	m_btnLiShi.MoveWindow(&mrect1);

	mrect1.right=mrect1.left-4;	
	mrect1.left=mrect1.right-76;	
	m_btnGaoFeng.MoveWindow(&mrect1);

	mrect1.right=mrect1.left-4;	
	mrect1.left=mrect1.right-76;	
	m_btnChuPei.MoveWindow(&mrect1);

	mrect1.right=mrect1.left-4;	
	mrect1.left=mrect1.right-76;	
	m_btnMatch.MoveWindow(&mrect1);


	//home dialog
	mrect2.left = mrect.left+2;
	mrect2.right = mrect.right-2;
	mrect2.top = mrect1.bottom;
	mrect2.bottom = mrect.bottom-27;
	m_pDlgMatch.MoveWindow(&mrect2);
	m_pDlgChuPei.MoveWindow(&mrect2);

	m_pDlgMatch.MoveControl();

	mrect1.top = mrect.bottom-22;
	mrect1.bottom = mrect.bottom-2;
	mrect1.left = mrect.left+5;
	mrect1.right = mrect1.left+420;
	GetDlgItem(IDC_STATIC_MSG)->MoveWindow(&mrect1);

	if (m_bIsMax)
	{
		m_btnMax.ShowWindow(SW_HIDE);
		m_btnNormal.ShowWindow(SW_SHOW);
	}
	else
	{
		m_btnMax.ShowWindow(SW_SHOW);
		m_btnNormal.ShowWindow(SW_HIDE);
	}
}


void CFootballAnalysisDlg::OnBnClickedButton6()
{
	// min
	WINDOWPLACEMENT lwndpl;
	WINDOWPLACEMENT * lpwndpl;
	lpwndpl=&lwndpl;
	GetWindowPlacement(lpwndpl);
	lpwndpl->showCmd=SW_SHOWMINIMIZED;
	SetWindowPlacement(lpwndpl);
}


void CFootballAnalysisDlg::OnBnClickedButton5()
{
	// max
	GetClientRect(&m_normalrect);
	ClientToScreen(&m_normalrect);
	int cx=::GetSystemMetrics(SM_CXFULLSCREEN);
	int cy=::GetSystemMetrics(SM_CYFULLSCREEN);
	CRect rect;
	SystemParametersInfo(SPI_GETWORKAREA,0,&rect,0);
	cy = rect.bottom;
	MoveWindow(0, 0, cx, cy);


	m_bIsMax=TRUE;
	MoveControl();
	Invalidate();
}


void CFootballAnalysisDlg::OnBnClickedButton4()
{
	//normal
	MoveWindow(&m_normalrect);
	m_bIsMax=FALSE;
	MoveControl();
	Invalidate();
}


void CFootballAnalysisDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	SetMenuIndex(2);
}


void CFootballAnalysisDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	SetMenuIndex(3);
}


void CFootballAnalysisDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (!m_bIsMax)
	{
		CPoint   pos;   
		GetCursorPos(&pos);
		CRect mrect;
		GetClientRect(&mrect);
		ClientToScreen(&mrect);
		if(mrect.PtInRect(pos))
			PostMessage(WM_NCLBUTTONDOWN,HTCAPTION,MAKELPARAM(point.x,point.y));
	}

	CDialogEx::OnLButtonDown(nFlags, point);
}


BOOL CFootballAnalysisDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CBitmap bitmap;
	CDC dcCompatible;
	bitmap.LoadBitmap(IDB_BITMAP_TOP_LEFT);         //"IDB_BITMAP1"为自定义图片ID	
	dcCompatible.CreateCompatibleDC(pDC);
	CBitmap * pOldBitmap;
	pOldBitmap = dcCompatible.SelectObject(&bitmap);

	CRect rect,rect1;

	GetClientRect(&rect);
	rect1.left=rect.left;
	rect1.top=rect.top;
	rect1.right=rect.left+222;
	rect1.bottom=rect1.top+111;
	pDC->BitBlt(rect1.left,rect1.top,rect1.Width(),rect1.Height(),&dcCompatible,0,0,SRCCOPY);
	DeleteObject(&dcCompatible);
	dcCompatible.SelectObject(pOldBitmap);
	bitmap.DeleteObject();

	//top middle
	CDC dcCompatible1;
	dcCompatible1.CreateCompatibleDC(pDC);
	bitmap.LoadBitmap(IDB_BITMAP_TOP_MIDDLE);
	pOldBitmap=dcCompatible1.SelectObject(&bitmap);
	BITMAP bmp;
	bitmap.GetBitmap(&bmp);
	rect1.left=rect1.right;
	rect1.right=rect.right-3;
	pDC->StretchBlt(rect1.left,rect1.top,rect1.Width(),rect1.Height(),&dcCompatible1,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY);
	DeleteObject(&dcCompatible1);
	dcCompatible1.SelectObject(pOldBitmap);
	bitmap.DeleteObject();

	//top right
	CDC dcCompatible4;
	dcCompatible4.CreateCompatibleDC(pDC);
	bitmap.LoadBitmap(IDB_BITMAP_TOP_RIGHT);
	pOldBitmap=dcCompatible4.SelectObject(&bitmap);
	bitmap.GetBitmap(&bmp);
	rect1.left=rect1.right;
	rect1.right=rect.right;	
	pDC->StretchBlt(rect1.left,rect1.top,rect1.Width(),rect1.Height(),&dcCompatible4,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY);
	DeleteObject(&dcCompatible4);
	dcCompatible4.SelectObject(pOldBitmap);
	bitmap.DeleteObject();

	//center middle
	CDC dcCompatible2;
	dcCompatible2.CreateCompatibleDC(pDC);
	bitmap.LoadBitmap(IDB_BITMAP_CENTER_MIDDLE);
	pOldBitmap=dcCompatible2.SelectObject(&bitmap);
	bitmap.GetBitmap(&bmp);
	rect1.top=rect1.bottom;
	rect1.bottom=rect.bottom-27;
	rect1.left = rect.left;
	rect1.right = rect.right;
	pDC->StretchBlt(rect1.left,rect1.top,rect1.Width(),rect1.Height(),&dcCompatible2,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY);
	DeleteObject(&dcCompatible2);
	dcCompatible2.SelectObject(pOldBitmap);
	bitmap.DeleteObject();

	//bottom left
	CDC dcCompatible5;
	dcCompatible5.CreateCompatibleDC(pDC);
	bitmap.LoadBitmap(IDB_BITMAP_BUTTOM_LEFT);
	pOldBitmap=dcCompatible5.SelectObject(&bitmap);
	bitmap.GetBitmap(&bmp);
	rect1.bottom=rect.bottom;
	rect1.top=rect1.bottom-27;
	rect1.left = rect.left;
	rect1.right = rect.left+3;
	pDC->StretchBlt(rect1.left,rect1.top,rect1.Width(),rect1.Height(),&dcCompatible5,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY);
	DeleteObject(&dcCompatible5);
	dcCompatible5.SelectObject(pOldBitmap);
	bitmap.DeleteObject();

	//bottom middle
	CDC dcCompatible3;
	dcCompatible3.CreateCompatibleDC(pDC);
	bitmap.LoadBitmap(IDB_BITMAP_BUTTOM_MIDDLE);
	pOldBitmap=dcCompatible3.SelectObject(&bitmap);
	bitmap.GetBitmap(&bmp);
	rect1.left = rect1.right;
	rect1.right = rect.right-3;
	pDC->StretchBlt(rect1.left,rect1.top,rect1.Width(),rect1.Height(),&dcCompatible3,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY);
	DeleteObject(&dcCompatible3);
	dcCompatible3.SelectObject(pOldBitmap);
	bitmap.DeleteObject();

	//bottom right
	CDC dcCompatible6;
	dcCompatible6.CreateCompatibleDC(pDC);
	bitmap.LoadBitmap(IDB_BITMAP_BUTTOM_RIGHT);
	pOldBitmap=dcCompatible6.SelectObject(&bitmap);
	bitmap.GetBitmap(&bmp);
	rect1.left = rect1.right;
	rect1.right = rect.right;
	pDC->StretchBlt(rect1.left,rect1.top,rect1.Width(),rect1.Height(),&dcCompatible6,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY);
	DeleteObject(&dcCompatible6);
	dcCompatible6.SelectObject(pOldBitmap);
	bitmap.DeleteObject();

// 	return CDialogEx::OnEraseBkgnd(pDC);
	return TRUE;
}


HBRUSH CFootballAnalysisDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (nCtlColor==CTLCOLOR_STATIC)
	{
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)::GetStockObject(NULL_BRUSH);
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


BOOL CFootballAnalysisDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message==WM_KEYDOWN)   
	{   
		switch(pMsg->wParam)   
		{   
		case   VK_RETURN: 
		case   VK_ESCAPE: 
			{
				return   TRUE;   
			}
		default:break;
		}   
	} 

	return CDialogEx::PreTranslateMessage(pMsg);
}
