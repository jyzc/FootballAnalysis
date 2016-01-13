#include "StdAfx.h"
#include "GamblingCompany.h"


CGamblingCompany::CGamblingCompany(void)
{
	m_pChuPei = NULL;
	m_pZhongPei = NULL;
	
}


CGamblingCompany::~CGamblingCompany(void)
{
	if (m_pOdds.size()>0)
	{
		for (int i=0; i<(int)m_pOdds.size(); i++)
		{
			delete m_pOdds.at(i);
		}
		m_pOdds.clear();
	}
}
