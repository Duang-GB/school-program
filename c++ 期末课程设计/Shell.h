#pragma once

#include "Object.h"
//=============================�ڵ���===============================//
class Shell :public Object
{
public:
	Shell(Dir facedir, COORD xy);
	~Shell();
	COORD GetXY();     //��ȡ�ڵ�����
	Dir GetDir() { return Direction; }   //��ȡ�ڵ�����
	void Fly();
	void Print();
	void PrintShellBoom();
private:
	int Flag;
};

