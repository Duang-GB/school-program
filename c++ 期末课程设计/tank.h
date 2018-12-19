#pragma once
#include"main_game.h"

//̹����
class Tank
{
public:
	Tank();
	~Tank();
	void MoveTank();                                  //̹���ƶ�
	void ChangeSpeed(int newspeed);                   //�޸�̹���ٶ�
	void ChangeHp(int flag);                          //�޸�̹��Ѫ��
	void ChangeFireInterval(int Newinterval);         //�޸Ĺ������
	void Setxy(COORD xy);                             //�޸�̹��λ��
	COORD Getxy();                                    //��ȡ̹��λ��
	int GetSpeed();                                   //��ȡ̹���ٶ�
	int GetDir();                                     //��ȡ̹�˷���
	void ChangeDir(int newdir);                       //�޸�̹�˷���
	void Fire();                                      //����
	void PrintTank();                                 //��ӡ̹��
	//�޸Ĺ��� 
private:
	int Speed;           //̹�˵��ƶ��ٶ�
	int Hp;              //̹��Ѫ��
	int Dir;             //̹������ķ���
	int FireInterval;    //�������
	COORD XY;            //��¼̹������
};

//�������̹����
class PlayTank :public Tank
{
public:
	void MoveTank();        //��д�ƶ�������Ҳ���
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