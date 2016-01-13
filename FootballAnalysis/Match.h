#pragma once
#include "Datadefine.h"
#include "GamblingCompany.h"

class CMatch{
public:
	CMatch();
	virtual ~CMatch();


	long m_lMatchId;	//比赛ID
	Team* m_pZhuDui;		//主队
	Team* m_pKeDui;	//客队
	CTime m_ctBeginTime;	//比赛时间
	int m_nMatchStatus;		//比赛状态
	int m_nMatchResult;		//比赛结果
	TeamData* m_pZhuData;
	TeamData* m_pKeData;

	MatchEvent* m_pMatchEvent;//赛事

	int m_nZhuScore;		//主队进球
	int m_nKeScore;		//客队进球数
	int m_nZhuScoreHarf;		//上半场主队进球
	int m_nKeScoreHalf;		//上半场客队进球

	vector<CGamblingCompany*> m_pOuPei;//欧赔
	vector<CGamblingCompany*> m_pYaPei;//亚赔
	vector<CGamblingCompany*> m_pDaXiaoQiu;//大小球
};

class CPlayMatch : public CMatch
{
public:
	CPlayMatch();
	virtual ~CPlayMatch();

	void Calculate();
	void Filter();

	int m_nErrorCode;//获取数据时的错误码
	CalculateData* m_pCalData;

	vector<CMatch*> m_pZhuMatch;//主队最近6场
	vector<CMatch*> m_pKeMatch;//客队最近6场

	vector<CMatch*> m_pZhuZhuMatch;//主队最近6场主场
	vector<CMatch*> m_pKeKeMatch;//客队最近6场客场

	vector<CMatch*> m_pZhuJiaoFeng;//最近6场相同交锋
	vector<CMatch*> m_pJiaoFeng;//最近6场交锋
};