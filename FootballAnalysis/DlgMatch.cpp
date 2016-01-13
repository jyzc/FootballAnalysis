// DlgMatch.cpp : 实现文件
//

#include "stdafx.h"
#include "FootballAnalysis.h"
#include "DlgMatch.h"
#include "afxdialogex.h"


// CDlgMatch 对话框

IMPLEMENT_DYNAMIC(CDlgMatch, CDialogEx)

CDlgMatch::CDlgMatch(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgMatch::IDD, pParent)
{

}

CDlgMatch::~CDlgMatch()
{
}

void CDlgMatch::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(CDlgMatch, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgMatch 消息处理程序


void CDlgMatch::MoveControl(void)
{
	CRect mrect,mrect1,mrect2;
	GetClientRect(&mrect);

	mrect1.left=mrect.left+10;
	mrect1.right=mrect1.left+80;
	mrect1.top=mrect.top+5;
	mrect1.bottom=mrect1.top+25;
	GetDlgItem(IDC_BUTTON1)->MoveWindow(mrect1);

	mrect1.left = mrect1.right+5;
	mrect1.right = mrect1.left+80;
	GetDlgItem(IDC_BUTTON2)->MoveWindow(mrect1);

	mrect1.left = mrect1.right+5;
	mrect1.right = mrect1.left+80;
	GetDlgItem(IDC_EDIT1)->MoveWindow(mrect1);

	//list
	mrect1.left=mrect.left+10;
	mrect1.right=mrect.right-10;
	mrect1.top=mrect1.bottom+5;
	mrect1.bottom=mrect.bottom-10;
	GetDlgItem(IDC_LIST1)->MoveWindow(mrect1);
}


void CDlgMatch::InitControl(void)
{
	SetWindowLong(m_list.m_hWnd ,GWL_EXSTYLE,WS_EX_CLIENTEDGE);
	::SendMessage(m_list.m_hWnd, LVM_SETEXTENDEDLISTVIEWSTYLE,LVS_EX_FULLROWSELECT, LVS_EX_FULLROWSELECT);

	wchar_t szTitle[14][20] = {L"编号",L"赛事",L"时间",L"状态",L"主队",L"比分",L"上半",L"客队",L"数据完整度",L"分析数据" ,L"上半杀大",L"乖离率",L"大小球",L"赛前过滤"};
	for (int i=0; i<14; i++)
	{
		m_list.InsertColumn( i, szTitle[i], LVCFMT_LEFT, 80 );
	}
}


BOOL CDlgMatch::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitControl();
// 	MoveControl();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


HBRUSH CDlgMatch::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


void CDlgMatch::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	CRect   rect;
	GetClientRect(rect);
	dc.FillSolidRect(rect,RGB(255,255,255));   //设置为白色背景
}


BOOL CDlgMatch::PreTranslateMessage(MSG* pMsg)
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
