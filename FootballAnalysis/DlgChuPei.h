#pragma once


// CDlgChuPei 对话框

class CDlgChuPei : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgChuPei)

public:
	CDlgChuPei(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgChuPei();

// 对话框数据
	enum { IDD = IDD_DIALOG_CHUPEI };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
