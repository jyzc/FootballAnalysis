// DlgMatch.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "FootballAnalysis.h"
#include "DlgMatch.h"
#include "afxdialogex.h"


// CDlgMatch �Ի���

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


// CDlgMatch ��Ϣ�������


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

	wchar_t szTitle[14][20] = {L"���",L"����",L"ʱ��",L"״̬",L"����",L"�ȷ�",L"�ϰ�",L"�Ͷ�",L"����������",L"��������" ,L"�ϰ�ɱ��",L"������",L"��С��",L"��ǰ����"};
	for (int i=0; i<14; i++)
	{
		m_list.InsertColumn( i, szTitle[i], LVCFMT_LEFT, 80 );
	}
}


BOOL CDlgMatch::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	InitControl();
// 	MoveControl();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


HBRUSH CDlgMatch::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	if (nCtlColor==CTLCOLOR_STATIC)
	{
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)::GetStockObject(NULL_BRUSH);
	}
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}


void CDlgMatch::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CRect   rect;
	GetClientRect(rect);
	dc.FillSolidRect(rect,RGB(255,255,255));   //����Ϊ��ɫ����
}


BOOL CDlgMatch::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
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
