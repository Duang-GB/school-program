#pragma once
#include"main_game.h"
class Tank
{
public:
	Tank();
	~Tank();
	void MoveTank();                   //̹���ƶ�
	void ChangSpeed(int newspeed);     //�޸�̹���ٶ�
	void ChangHp(int flag);
	void Fire();                //����
	void Setxy(COORD xy);              //����̹�˳�ʼλ��
	void ChangeFireInterval(int Newinterval);         //�޸Ĺ������
	void PrintTank();
	//�޸Ĺ���
private:
	int Speed;           //̹�˵��ƶ��ٶ�
	int Hp;              //̹��Ѫ��
	int Dir;             //̹������ķ���
	int FireInterval;    //�������
	COORD XY;            //��¼̹������
};

