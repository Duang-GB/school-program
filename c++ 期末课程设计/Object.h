#pragma once

#include"main_game.h"
//=========================����� ������̹�ˡ��ڵ���buff�����εĸ��ࣩ====================//
class Object
{
public:
	virtual void Print()=0; //��Ҫ��ӡ
	                        //����ײЧ��
protected:
	Dir Direction;  //����
	COORD XY;       //���Ͻ�����
	int RectSphere; //���ش�С
};