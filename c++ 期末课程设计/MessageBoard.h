#pragma once
#include"main_game.h"
#include"Tank.h"
//=============================��Ϣ����===============================//
class MessageBoard
{
public:
	MessageBoard();
	~MessageBoard();
	const void Print();                            //��ӡ��Ϣ����
	void ChangeTankMessage(PlayTank tank);         //�޸���Ϣ����Ϣ
	void ChangeCard(int car) { card = car; }       //�޸Ĺؿ�
private:
	int Speed;           //̹�˵��ƶ��ٶ�
	int Hp;              //̹��Ѫ��
	int FireInterval;    //�������
	int card;            //�ڼ���
	COORD XY;            //��Ϣ���λ��
};

