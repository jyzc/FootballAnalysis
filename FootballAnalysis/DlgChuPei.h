#pragma once


// CDlgChuPei �Ի���

class CDlgChuPei : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgChuPei)

public:
	CDlgChuPei(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgChuPei();

// �Ի�������
	enum { IDD = IDD_DIALOG_CHUPEI };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
