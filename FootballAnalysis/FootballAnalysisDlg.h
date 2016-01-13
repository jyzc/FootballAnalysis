
// FootballAnalysisDlg.h : 头文件
//

#pragma once
#include "DlgMatch.h"
#include "DlgChuPei.h"
#include "HoverButton.h"

// CFootballAnalysisDlg 对话框
class CFootballAnalysisDlg : public CDialogEx
{
// 构造
public:
	CFootballAnalysisDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_FOOTBALLANALYSIS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	void SetMenuIndex(int nIndex);
	void InitControl(void);
	void MoveControl(void);
	BOOL m_bIsMax;
	CRect m_normalrect;
	CHoverButton m_btnMin;
	CButton m_btnMax;
	CButton m_btnNormal;
	CHoverButton m_btnClose;
	CHoverButton m_btnMatch;
	CHoverButton m_btnChuPei;
	CHoverButton m_btnGaoFeng;
	CHoverButton m_btnLiShi;
	CDlgChuPei m_pDlgChuPei;
	CDlgMatch m_pDlgMatch;
	int m_nSelectedIndex;

	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
