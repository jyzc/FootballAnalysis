
// FootballAnalysis.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CFootballAnalysisApp:
// �йش����ʵ�֣������ FootballAnalysis.cpp
//

class CFootballAnalysisApp : public CWinApp
{
public:
	CFootballAnalysisApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CFootballAnalysisApp theApp;