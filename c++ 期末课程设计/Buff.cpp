#include "Buff.h"



Buff::Buff()
{
}


Buff::~Buff()
{
}


void HPBuff::Print()
{
	IMAGE img1;

	loadimage(&img1, _T("SteeWall.jpg")); //��ȡ��Ƭ ������Ϊ60x60��

	putimage(XY.X, XY.Y, &img1);
}