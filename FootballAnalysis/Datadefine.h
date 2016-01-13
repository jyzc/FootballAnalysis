#pragma once

//////////////////////////////////////////////////////////////////////////
enum EventType{TYPE_COUNTRY=0, TYPE_CONTINENT, TYPE_INTERNATIONAL};
const wchar_t g_szEventType[3][20] = {L"��������", L"�޼�����", L"��������"};
enum MatchArea{AREA_EUROPE=0, AREA_AMERICA, AREA_ASIA, AREA_AFRICA, AREA_OCEANIA};
const wchar_t g_szMatchArea[5][20] = {L"ŷ��", L"����", L"����", L"����", L"������"};
//����
enum ODDSTYPE{ODD_OUPEI=0, ODD_YAPEI, ODD_DAXIAOQIU};

//////////////////////////////////////////////////////////////////////////
//��ӽṹ��
struct Team{
	long m_lTeamId;	//���ID
	wchar_t m_szTeamName[40];	//�������

	Team(){
		m_lTeamId = 0;
		memset(m_szTeamName, 0, 40*sizeof(wchar_t));
	}
};

//������ݽṹ��
struct TeamData{
	int		m_nJiFen;//��ǰ����
	int		m_nPaiHang;//��ǰ����
	int		m_nIndexCur;//��������
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

//����
struct Country{
	long	m_lCountryId;
	wchar_t m_szCountryName[40];	//����

	Country()
	{
		memset(m_szCountryName,0,40*sizeof(wchar_t));
		m_lCountryId = 0;
	}
};

//���½ṹ��
struct MatchEvent{
	long	m_lEventId;
	wchar_t	m_szEventName[40];	//����
	EventType m_mtEventType; //��������

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
//��������
struct CalculateData{
	int m_nJBM;//jibenmian
	double m_nHDXQ;//daxiaoqiu
	double m_nDQL;//daxiaolv	
	double m_nFull;//����������	
	double m_nScoreT;
	double m_nFJiaoFeng;//�������
	double m_nKZhuangTai;//���״̬

	double m_nZ1;//����
	double m_nZ2;//�����ϰ�
	double m_nG1;//�Ͷ�
	double m_nG2;//�Ͷ��ϰ�

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


