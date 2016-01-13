#pragma once

//////////////////////////////////////////////////////////////////////////
enum EventType{TYPE_COUNTRY=0, TYPE_CONTINENT, TYPE_INTERNATIONAL};
const wchar_t g_szEventType[3][20] = {L"各国赛事", L"洲际赛事", L"国际赛事"};
enum MatchArea{AREA_EUROPE=0, AREA_AMERICA, AREA_ASIA, AREA_AFRICA, AREA_OCEANIA};
const wchar_t g_szMatchArea[5][20] = {L"欧洲", L"美洲", L"亚洲", L"非洲", L"大洋洲"};
//赔率
enum ODDSTYPE{ODD_OUPEI=0, ODD_YAPEI, ODD_DAXIAOQIU};

//////////////////////////////////////////////////////////////////////////
//球队结构体
struct Team{
	long m_lTeamId;	//球队ID
	wchar_t m_szTeamName[40];	//球队名称

	Team(){
		m_lTeamId = 0;
		memset(m_szTeamName, 0, 40*sizeof(wchar_t));
	}
};

//球队数据结构体
struct TeamData{
	int		m_nJiFen;//当前积分
	int		m_nPaiHang;//当前排行
	int		m_nIndexCur;//已赛场次
	int		m_nIndexSheng;
	int		m_nIndexFu;
	int		m_nIndexPing;
	int		m_nJinQiu;
	int		m_nShiQiu;

	CTime	m_ctNow;

	TeamData()
	{
		m_nJiFen = 0;
		m_nPaiHang = 0;
		m_nIndexSheng = 0;
		m_nIndexCur = 0;
		m_nIndexFu = 0;
		m_nIndexPing= 0;
		m_nJinQiu = 0;
		m_nShiQiu = 0;
		m_ctNow = 0;
	}
};

//国家
struct Country{
	long	m_lCountryId;
	wchar_t m_szCountryName[40];	//名称

	Country()
	{
		memset(m_szCountryName,0,40*sizeof(wchar_t));
		m_lCountryId = 0;
	}
};

//赛事结构体
struct MatchEvent{
	long	m_lEventId;
	wchar_t	m_szEventName[40];	//名称
	EventType m_mtEventType; //赛事类型

	MatchArea m_maMatchArea;
	Country* m_pCountry;

	MatchEvent()
	{
		m_lEventId = 0;
		memset(m_szEventName,0,40*sizeof(wchar_t));
		m_mtEventType = TYPE_COUNTRY;

		m_pCountry = NULL;
	}
};

//////////////////////////////////////////////////////////////////////////
//计算数据
struct CalculateData{
	int m_nJBM;//jibenmian
	double m_nHDXQ;//daxiaoqiu
	double m_nDQL;//daxiaolv	
	double m_nFull;//数据完整度	
	double m_nScoreT;
	double m_nFJiaoFeng;//最近交锋
	double m_nKZhuangTai;//最近状态

	double m_nZ1;//主队
	double m_nZ2;//主队上半
	double m_nG1;//客队
	double m_nG2;//客队上半

	CalculateData()
	{
		m_nJBM = 0;
		m_nHDXQ = 0;
		m_nDQL = 0;
		m_nFull = 0;
		m_nScoreT = 0;
		m_nFJiaoFeng=0;
		m_nKZhuangTai = 0;

		m_nZ1=0;
		m_nZ2=0;
		m_nG1=0;
		m_nG2=0;
	}
};


