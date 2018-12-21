#pragma once
#include"main_game.h"
#include"Shell.h"

//̹����
class Tank
{
public:
	Tank();
	~Tank();
	virtual void MoveTank(int NewDir)=0;           //̹���ƶ�
	virtual void Fire()=0;                         //����
	void ChangeSpeed(int newspeed);                   //�޸�̹���ٶ�
	void ChangeHp(int flag);                          //�޸�̹��Ѫ��
	void ChangeFireInterval(int Newinterval);         //�޸Ĺ������
	void Setxy(COORD xy);                             //�޸�̹��λ��
	void ChangeDir(int NewDir);                       //�޸�̹�˷���
	void ChangeReadyForFire(int Ready);               //�޸��ܷ��ڵ�״̬
	const COORD Getxy();                                  //��ȡ̹��λ��
	const int GetSpeed();                                 //��ȡ̹���ٶ�
	const int GetDir();                                   //��ȡ̹�˷���
	const int GetFireInterval();                          //��ȡ�������
	void PrintTank();                                         //��ӡ̹��
	void FireIntevalFigure();                                 //���㿪����ȴ�Ƿ����
	Shell *TankShell;    //̹�˵��ڵ�ָ��


private:
	int Speed;           //̹�˵��ƶ��ٶ�
	int Hp;              //̹��Ѫ��
	int Dir;             //̹������ķ���
	int FireInterval;    //�������
	COORD XY;            //��¼̹������
	bool ReadyForFire;   //��ʾ�Ƿ�������  1Ϊ����
};

//�������̹����
class PlayTank :public Tank
{
public:
	void MoveTank(int newdir);        //��д�ƶ�������Ҳ���
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