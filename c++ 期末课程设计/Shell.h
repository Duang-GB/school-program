#pragma once

#include"main_game.h"
//=============================�ڵ���===============================//
class Shell
{
public:
	Shell(int dir, COORD xy);
	~Shell();
	void Print();                        //��ӡ�ڵ�
	void Fly();                          //�ڵ������жϺ���
	const COORD GetShellxy();            //��ȡ�ڵ����꣨�����ж��Ƿ�����

private:
	int Direction;          //�ڵ��н��ķ���
	COORD XY;               //�ڵ��ĵ�ǰ����
	int Flag;
};


////////////////////////////���ʵ��//////////////////////////////
