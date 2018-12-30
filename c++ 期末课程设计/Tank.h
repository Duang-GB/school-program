#pragma once

#include"Object.h"
#include"Shell.h"

//=======================================̹����====================================//
class Tank :public Object
{
public:
	Tank();
	~Tank();
	virtual void MoveTank(Dir NewDir)=0;           //̹���ƶ�
	virtual void Fire()=0;                         //����

	void ChangeSpeed(int newspeed) { Speed = newspeed; }                                //�޸�̹���ٶ�
	void ChangeFireInterval(int Newinterval) { FireInterval = Newinterval; }            //�޸Ĺ������
	void Setxy(COORD xy) { XY = xy; }                                                   //�޸�̹��λ��
	void ChangeDir(Dir NewDir) { Direction = NewDir; }                                  //�޸�̹�˷���
	void ChangeReadyForFire(int ReadyOrNot) { ReadyForFire = ReadyOrNot; }              //�޸��ܷ��ڵ�״̬
	const COORD Getxy() {return XY; }                                        //��ȡ̹��λ��
	const int GetSpeed() { return Speed; }                                   //��ȡ̹���ٶ�
	const Dir GetDir() { return Direction; }                                 //��ȡ̹�˷���
//	const int GetFireInterval() {return  FireInterval;}                      //��ȡ�������
	bool GetReadyForFire() { return ReadyForFire; }                    //��ȡ̹���ܷ��ڵ�״̬
	const int GetHP() { return Hp; }                                         //��ȡ̹��Ѫ��

	void ChangeHp(int flag);                          //�޸�̹��Ѫ��
	//void Print();                                     //��ӡ̹��
	void FireIntevalFigure();                         //���㿪����ȴ�Ƿ����

protected:
	int Speed;           //̹�˵��ƶ��ٶ�
	int Hp;              //̹��Ѫ��
	int FireInterval;    //�������
	bool ReadyForFire;   //��ʾ�Ƿ�������  1Ϊ����
	int nowInterval;     //��ǰ�Ĺ�����ȴ����

};

//�������̹����
class PlayTank :public Tank
{
public:
	PlayTank();
	void Print();
	void MoveTank(Dir newdir);  //�ƶ�����Ҳ���
	void Fire();                //����ҿ��ƿ���
};

//��ͨai̹����(�ٶȣ����٣�Ѫ���仯
class NormalAITank :public Tank
{
public:
	NormalAITank();
	Dir NormalMoveAI(int h);          //��̹ͨ���ƶ�ai
	void Print();
	void MoveTank(Dir NewDir);
	void Fire() {};

};

//��Ӣai̹����
class BossAITank :public Tank
{
public:
	BossAITank();
	void Print();
	void BossAI();           //boss̹��ai
	void MoveTank(Dir NewDir) {};
	void Fire() {};
};