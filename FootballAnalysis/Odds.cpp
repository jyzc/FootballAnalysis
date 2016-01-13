#include "StdAfx.h"
#include "Odds.h"


COdds::COdds(void)
{
	m_ctTime = 0;
}


COdds::~COdds(void)
{
}

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
COuzhiOdds::COuzhiOdds()
{
	m_nType = ODD_OUPEI;
	dWinOdds = 0;
	dWinRate = 0;
	dDrowOdds = 0;
	dDrowRate = 0;
	dLoseOdds = 0;
	dLoseRate = 0;
	dReturnRate = 0;
}
COuzhiOdds::~COuzhiOdds()
{

}

//////////////////////////////////////////////////////////////////////////
CYazhiOdds::CYazhiOdds()
{
	m_nType = ODD_YAPEI;
	dTape = 0;
	dHostOdds = 0;
	dAwayOdds = 0;
}

CYazhiOdds::~CYazhiOdds()
{

}

//////////////////////////////////////////////////////////////////////////
CDxzhiOdds::CDxzhiOdds()
{
	m_nType = ODD_DAXIAOQIU;
	dTape = 0;
	dHostOdds = 0;
	dAwayOdds = 0;
}
CDxzhiOdds::~CDxzhiOdds()
{

}