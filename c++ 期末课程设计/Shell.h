#pragma once

#include "Object.h"
//=============================�ڵ���===============================//
class Shell :public Object
{
public:
	Shell(Dir facedir, COORD xy);
	~Shell();
	COORD GetXY();     //��ȡ�ڵ�����
	void Fly();
	void Print();
private:
	int Flag;
};


////////////////////////////���ʵ��//////////////////////////////
