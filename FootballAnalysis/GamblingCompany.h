#pragma once
#include "Odds.h"
#include <vector>
using namespace std;

class CGamblingCompany
{
public:
	CGamblingCompany(void);
	~CGamblingCompany(void);

	//��ҪҪ��
	long	m_lCompanyID;	
	wchar_t m_szName[40];//��˾����
	int		m_nSequence;//���
	ODDSTYPE m_nType;

	COdds* m_pChuPei;//����
	COdds* m_pZhongPei;//����
	vector<COdds*> m_pOdds;//�������ʣ����絽��
};
