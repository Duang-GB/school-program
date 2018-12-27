#pragma once

#include"Object.h"

//=======================================̹����====================================//
class Tank :public Object
{
public:
	Tank();
	~Tank();
	virtual void MoveTank(Dir NewDir)=0;           //̹���ƶ�
	virtual void Fire()=0;                         //����
	void ChangeSpeed(int newspeed);                   //�޸�̹���ٶ�
	void ChangeHp(int flag);                          //�޸�̹��Ѫ��
	void ChangeFireInterval(int Newinterval);         //�޸Ĺ������
	void Setxy(COORD xy);                             //�޸�̹��λ��
	void ChangeDir(Dir NewDir);                       //�޸�̹�˷���
	void ChangeReadyForFire(int Ready);               //�޸��ܷ��ڵ�״̬
	const COORD Getxy();                                  //��ȡ̹��λ��
	const int GetSpeed();                                 //��ȡ̹���ٶ�
	const Dir GetDir();                                   //��ȡ̹�˷���
	const int GetFireInterval();                          //��ȡ�������
	const bool GetReadyForFire();                         //��ȡ̹���ܷ��ڵ�״̬
	void Print();                                         //��ӡ̹��
	void FireIntevalFigure();                                 //���㿪����ȴ�Ƿ����

private:
	int Speed;           //̹�˵��ƶ��ٶ�
	int Hp;              //̹��Ѫ��
	int FireInterval;    //�������
	bool ReadyForFire;   //��ʾ�Ƿ�������  1Ϊ����

};

//�������̹����
class PlayTank :public Tank
{
public:
	void MoveTank(Dir newdir);        //��д�ƶ�������Ҳ���
	void Fire();            //��д����ҿ��ƿ���
};

//��ͨai̹����(�ٶȣ����٣�Ѫ���仯
class NormalAITank :public Tank
{
	void NormalAI();          //��̹ͨ���ж�ai
};

//��Ӣai̹����
class BossAITank :public Tank
{
	void BossAI();           //boss̹��ai
};