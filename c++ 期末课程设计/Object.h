#pragma once

#include"main_game.h"
//=========================����� ������̹�ˡ��ڵ���buff���ĸ��ࣩ====================//
class Object
{
public:
	virtual void Print()=0; //��Ҫ��ӡ
protected:
	Dir Direction;  //����
	COORD XY;       //���Ͻ�����
	int RectSphere; //���ش�С
};
