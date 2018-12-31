#pragma once
#include"main_game.h"
#include"Object.h"
#include"Tank.h"
//=============================������===============================//
class Buff:public Object
{
public:
	Buff();
	~Buff();
	virtual void BuffEffect(PlayTank &tank)=0;           //buffЧ��
	void Setxy(COORD xy) { XY = xy; }      //�趨����
	COORD Getxy() { return XY; };          //��������
protected:
	int Dynamic;      //��̬Ч��ʵ��
};

class MoveSpeedBuff:public Buff
{
public:
	void BuffEffect(PlayTank &tank);
	void Print();
};

class FireIntervalBuff :public Buff
{
public:
	void BuffEffect(PlayTank &tank);
	void Print();
};

class HPBuff :public Buff
{
public:
	void BuffEffect(PlayTank &tank);
	void Print();
};
