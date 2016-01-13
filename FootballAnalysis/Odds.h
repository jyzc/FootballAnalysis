#pragma once
#include "Datadefine.h"

class COdds
{
public:
	COdds(void);
	~COdds(void);

	CTime m_ctTime;
	ODDSTYPE	m_nType;
};

class COuzhiOdds : public COdds
{
public:
	COuzhiOdds();
	virtual ~COuzhiOdds();

	double dWinOdds;
	double dWinRate;
	double dDrowOdds;//ping
	double dDrowRate;
	double dLoseOdds;
	double dLoseRate;

	double dReturnRate;
};

class CYazhiOdds : public COdds
{
public:
	CYazhiOdds();
	virtual ~CYazhiOdds();

	double dTape;
	double dHostOdds;
	double dAwayOdds;
};

class CDxzhiOdds : public COdds
{
public:
	CDxzhiOdds();
	virtual ~CDxzhiOdds();

	double dTape;
	double dHostOdds;
	double dAwayOdds;

};
