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
	{
		Dir = _getch();  //��ȡ����
		switch (Dir) {    //�����ƶ��ٶ��ƶ�
		case UP:
			XY.Y -= Speed;  //�޸�����
			break;
		case DOWN:
			XY.Y += Speed;
			break;
		case LEFT:
			XY.X -= Speed;
			break;
		case RIGHT:
			XY.X += Speed;
			break;
		case 0:
			break;
		}
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

void Tank::PrintTank()
{
	IMAGE img1,img2;
	loadimage(&img1, _T("PlayerTank.jpg")); //��ȡ��Ƭ

     //���ݷ����λ�ô�ӡ̹��
	if (Dir == UP)
	{
		putimage(XY.X, XY.Y, &img1);       //�ڹ̶�λ�ô�ӡ̹��
	}
	else if (Dir == DOWN)
	{
		// ��תͼ�� 180 �� (PI / 6)
		rotateimage(&img2, &img1, PI);

		putimage(XY.X, XY.Y, &img2);

	}
	else if (Dir == LEFT)
	{
		// ��תͼ�� 270 �� (PI / 6)
		rotateimage(&img2, &img1, PI / 2);

		putimage(XY.X, XY.Y, &img2);

	}
	else
	{
		// ��תͼ�� 30 �� (PI / 6)
		rotateimage(&img2, &img1, (3*PI) / 2);

		putimage(XY.X, XY.Y, &img2);

	}
}

/*
void PlayTank::Fire()
{
	if (_kbhit())       //���������
	{

	}
	//���ǹ������
}

void PlayTank::MoveTank()
{
	if (_kbhit())       //���������
	{
		Dir = _getch();  //��ȡ����
		switch (Dir) {    //�����ƶ��ٶ��ƶ�
		case UP:
			XY.Y -= Speed;  //�޸�����
			break;
		case DOWN:
			XY.Y += Speed;
			break;
		case LEFT:
			XY.X -= Speed;
			break;
		case RIGHT:
			XY.X += Speed;
			break;
		case 0:
			break;
		}
	}
}
*/