#pragma once
#include "Odds.h"
#include <vector>
using namespace std;

class CGamblingCompany
{
public:
	CGamblingCompany(void);
	~CGamblingCompany(void);

	//必要要素
	long	m_lCompanyID;	
	wchar_t m_szName[40];//公司名称
	int		m_nSequence;//序号
	ODDSTYPE m_nType;

	COdds* m_pChuPei;//初赔
	COdds* m_pZhongPei;//终赔
	vector<COdds*> m_pOdds;//所有赔率，从早到晚
};
