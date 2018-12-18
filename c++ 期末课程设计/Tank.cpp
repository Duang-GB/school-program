#include "Tank.h"
#include"main_game.h"


Tank::Tank()
{
	Speed = 6;
	Hp = 1;
	Dir = UP;
}


Tank::~Tank()
{
}

void Tank::MoveTank()
{
	if (_kbhit())       //���������
		Dir = _getch();

	switch (Dir) {    //�����ƶ��ٶ��ƶ�
	case UP:
		XY.Y-=Speed;
		break;
	case DOWN:
		XY.Y+= Speed;
		break;
	case LEFT:
		XY.X-= Speed;
		break;
	case RIGHT:
		XY.X+= Speed;
		break;
	}
}

void Tank::ChangSpeed(int newspeed)
{
	Speed = newspeed;
}

void Tank::Setxy(COORD xy)
{
	XY = xy;
}

void Tank:: ChangHp(int flag)
{
	if (flag == 1) //��������Ӽ�����ֵ
		Hp++;
	if (flag == 0)
		Hp--;

}

void Tank::ChangeFireInterval(int NewInterval)
{
	FireInterval = NewInterval;
}