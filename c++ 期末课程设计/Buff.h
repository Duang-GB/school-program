#pragma once
#include"main_game.h"
//=============================������===============================//
class Buff
{
public:
	Buff();
	~Buff();
	void CreatBuff();                      //����buff
	void GetBuff();                        //���buff
	virtual void BuffEffect()=0;           //buffЧ��
	virtual const void PrintBuff() = 0;    //��ӡbuf
};

class MoveSpeedBuff:public Buff
{
public:
	void BuffEffect();
};

class FireIntervalBuff :public Buff
{
public:
	void BuffEffect();
};

class HPBuff :public Buff
{
public:
	void BuffEffect();
};