#pragma once


// CDlgMatch �Ի���

class CDlgMatch : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgMatch)

public:
	CDlgMatch(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgMatch();

// �Ի�������
	enum { IDD = IDD_DIALOG_MATCH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	void MoveControl(void);
	void InitControl(void);
	virtual BOOL OnInitDialog();
	CListCtrl m_list;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
