#include "stdafx.h"
#include "Match.h"


CMatch::CMatch()
{
	m_lMatchId = 0;
	m_ctBeginTime = 0;
	m_nZhuScore = 0;
	m_nKeScore = 0;
	m_nZhuScoreHarf = 0;
	m_nKeScoreHalf = 0;
	m_nMatchResult = 0;
	m_nMatchStatus = 0;

	m_pZhuDui = NULL;
	m_pKeDui = NULL;
	m_pZhuData = NULL;
	m_pKeData = NULL;

	m_pMatchEvent = NULL;

	m_pOuPei.clear();
	m_pYaPei.clear();
	m_pDaXiaoQiu.clear();
}
CMatch::~CMatch()
{
	if (m_pOuPei.size()>0)
	{
		for (int i=0; i<(int)m_pOuPei.size(); i++)
		{
			delete m_pOuPei.at(i);
		}
		m_pOuPei.clear();
	}

	if (m_pYaPei.size()>0)
	{
		for (int i=0; i<(int)m_pYaPei.size(); i++)
		{
			delete m_pYaPei.at(i);
		}
		m_pYaPei.clear();
	}

	if (m_pDaXiaoQiu.size()>0)
	{
		for (int i=0; i<(int)m_pDaXiaoQiu.size(); i++)
		{
			delete m_pDaXiaoQiu.at(i);
		}
		m_pDaXiaoQiu.clear();
	}

	if (m_pZhuDui)
	{
		delete m_pZhuDui;
		m_pZhuDui = NULL;
	}
	if (m_pKeDui)
	{
		delete m_pKeDui;
		m_pKeDui = NULL;
	}
	if (m_pZhuData)
	{
		delete m_pZhuData;
		m_pZhuData = NULL;
	}
	if (m_pKeData)
	{
		delete m_pKeData;
		m_pKeData = NULL;
	}
}

//////////////////////////////////////////////////////////////////////////
CPlayMatch::CPlayMatch()
{
	CMatch::CMatch();

	m_nErrorCode = 0;
	m_pCalData = NULL;

	m_pZhuMatch.clear();
	m_pKeMatch.clear();
	m_pZhuZhuMatch.clear();
	m_pKeKeMatch.clear();
	m_pZhuJiaoFeng.clear();
	m_pJiaoFeng.clear();
}

CPlayMatch::~CPlayMatch()
{
	CMatch::~CMatch();

	if (m_pZhuMatch.size()>0)
	{
		for (int i=0; i<(int)m_pZhuMatch.size(); i++)
		{
			delete m_pZhuMatch.at(i);
		}
		m_pZhuMatch.clear();
	}

	if (m_pKeMatch.size()>0)
	{
		for (int i=0; i<(int)m_pKeMatch.size(); i++)
		{
			delete m_pKeMatch.at(i);
		}
		m_pKeMatch.clear();
	}

	if (m_pZhuZhuMatch.size()>0)
	{
		for (int i=0; i<(int)m_pZhuZhuMatch.size(); i++)
		{
			delete m_pZhuZhuMatch.at(i);
		}
		m_pZhuZhuMatch.clear();
	}

	if (m_pKeKeMatch.size()>0)
	{
		for (int i=0; i<(int)m_pKeKeMatch.size(); i++)
		{
			delete m_pKeKeMatch.at(i);
		}
		m_pKeKeMatch.clear();
	}

	if (m_pZhuJiaoFeng.size()>0)
	{
		for (int i=0; i<(int)m_pZhuJiaoFeng.size(); i++)
		{
			delete m_pZhuJiaoFeng.at(i);
		}
		m_pZhuJiaoFeng.clear();
	}

	if (m_pJiaoFeng.size()>0)
	{
		for (int i=0; i<(int)m_pJiaoFeng.size(); i++)
		{
			delete m_pJiaoFeng.at(i);
		}
		m_pJiaoFeng.clear();
	}
}

//////////////////////////////////////////////////////////////////////////
void CPlayMatch::Calculate()
{

}

void CPlayMatch::Filter()
{

}