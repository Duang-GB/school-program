#include "Tank.h"
#include"main_game.h"


Tank::Tank()
{
	Speed = SpeedLevel_1;           //��ʼ�ٶ�
	Hp = 1;                         //��ʼ����
	Dir = UP;                       //��ʼ����
	ReadyForFire = 1;               //����װ��
	FireInterval = IntervalLevel_1; //��ʼ�������
}


Tank::~Tank()
{
}


void Tank::ChangeSpeed(int newspeed)
{
	Speed = newspeed;
}

const int Tank::GetSpeed()
{
	return Speed;
}

void Tank::Setxy(COORD xy)
{
	XY = xy;
}

const COORD Tank::Getxy()
{
	return XY;
}

void Tank:: ChangeHp(int flag)
{
	if (flag == 1) //��������Ӽ�����ֵ
		Hp++;
	if (flag == 0)
		Hp--;

}

void Tank::ChangeDir(int newdir)
{
	Dir = newdir;
}

const int Tank::GetDir()
{
	return Dir;
}

void Tank::ChangeFireInterval(int NewInterval)
{
	FireInterval = NewInterval;
}

void Tank::PrintTank()
{
	IMAGE img1,img2;
	loadimage(&img1, _T("PlayerTank.jpg")); //��ȡ��Ƭ ������Ϊ60x60��

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

const int Tank::GetFireInterval()
{
	return FireInterval;
}

void Tank::FireIntevalFigure()
{
	static int nowInterval = GetFireInterval();  //��ʼ����ȴʱ��
	nowInterval--;                   //��ȴing
	if (nowInterval == 0)           //��ȴ����
	{
		nowInterval = GetFireInterval();  //������ȴʱ��
		ChangeReadyForFire(1);      //װ�������������һ��
	}
}

void Tank::ChangeReadyForFire(int ReadyOrNot)
{
	ReadyForFire = ReadyOrNot;
}

void PlayTank::Fire()
{
	ChangeReadyForFire(0);     //���뿪����ȴ
	TankShell = new Shell(GetDir(), Getxy());
}

void PlayTank::MoveTank(int NewDir)
{
		if (NewDir == UP || NewDir == DOWN || NewDir == RIGHT || NewDir == LEFT)       //�ж��Ƿ�Ϊ�������
		{
			COORD oldxy = Getxy();    //��ȡ����
			short speed = GetSpeed(); //��ȡ�ٶ�
			ChangeDir(NewDir);
			switch (NewDir) {    //�����ƶ��ٶ��ƶ�
			case UP:
				Setxy({ oldxy.X,oldxy.Y - speed });  //�޸�����
				break;
			case DOWN:
				Setxy({ oldxy.X,oldxy.Y + speed });
				break;
			case LEFT:
				Setxy({ oldxy.X - speed,oldxy.Y });
				break;
			case RIGHT:
				Setxy({ oldxy.X + speed,oldxy.Y });
				break;
			}
		}
}
