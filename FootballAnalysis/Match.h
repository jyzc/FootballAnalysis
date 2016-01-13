#pragma once
#include "Datadefine.h"
#include "GamblingCompany.h"

class CMatch{
public:
	CMatch();
	virtual ~CMatch();


	long m_lMatchId;	//����ID
	Team* m_pZhuDui;		//����
	Team* m_pKeDui;	//�Ͷ�
	CTime m_ctBeginTime;	//����ʱ��
	int m_nMatchStatus;		//����״̬
	int m_nMatchResult;		//�������
	TeamData* m_pZhuData;
	TeamData* m_pKeData;

	MatchEvent* m_pMatchEvent;//����

	int m_nZhuScore;		//���ӽ���
	int m_nKeScore;		//�Ͷӽ�����
	int m_nZhuScoreHarf;		//�ϰ볡���ӽ���
	int m_nKeScoreHalf;		//�ϰ볡�Ͷӽ���

	vector<CGamblingCompany*> m_pOuPei;//ŷ��
	vector<CGamblingCompany*> m_pYaPei;//����
	vector<CGamblingCompany*> m_pDaXiaoQiu;//��С��
};

class CPlayMatch : public CMatch
{
public:
	CPlayMatch();
	virtual ~CPlayMatch();

	void Calculate();
	void Filter();

	int m_nErrorCode;//��ȡ����ʱ�Ĵ�����
	CalculateData* m_pCalData;

	vector<CMatch*> m_pZhuMatch;//�������6��
	vector<CMatch*> m_pKeMatch;//�Ͷ����6��

	vector<CMatch*> m_pZhuZhuMatch;//�������6������
	vector<CMatch*> m_pKeKeMatch;//�Ͷ����6���ͳ�

	vector<CMatch*> m_pZhuJiaoFeng;//���6����ͬ����
	vector<CMatch*> m_pJiaoFeng;//���6������
};