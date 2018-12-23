#include "Shell.h"
#include"main_game.h"

Shell::Shell(int dir, COORD xy)
{
	Direction = dir;       //��ȡ����

	if (Direction == UP)   //�ڵ��ĳ�ʼλ��Ӧ����̹�˵�����ǰ��
	{
		XY.X = xy.X+25 ;
		XY.Y = xy.Y - 10;
	}
	else if (Direction == DOWN)
	{
		XY.X = xy.X + 25;
		XY.Y = xy.Y + 60;
	}
	else if (Direction == LEFT)
	{
		XY.X = xy.X - 10;
		XY.Y = xy.Y + 25;
	}
	else  //RIGHT
	{
		XY.X = xy.X + 60;
		XY.Y = xy.Y +25;
	}
}

Shell::~Shell()
{

}

void Shell::Print()
{
	IMAGE img1;
	loadimage(&img1, _T("Shell.jpg")); //��ȡ��Ƭ (����Ϊ10x10��
	putimage(XY.X, XY.Y, &img1);       //�ڹ̶�λ�ô�ӡ�ڵ�
}

void Shell::Fly()
{
	if (Direction == UP)                           //�ж��ڵ����з��򲢸ı�����
		XY.Y -= ShellFlySpeed;
	else if (Direction == DOWN)
		XY.Y += ShellFlySpeed;
	else if (Direction == LEFT)
		XY.X -= ShellFlySpeed;
	else  //RIGHT
		XY.X += ShellFlySpeed;
}

const COORD Shell::GetShellxy()
{
	return XY;
}