#include "Tank.h"
#include"main_game.h"


Tank::Tank()
{
	Speed = SpeedLevel_1;           //��ʼ�ٶ�
	Hp = 1;                         //��ʼ����
	Direction = UP;                       //��ʼ����
	ReadyForFire = 1;               //����װ��
	FireInterval = IntervalLevel_1; //��ʼ�������
	RectSphere = 60;                //̹�˴�С60x60����
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

void Tank::ChangeDir(Dir newdir)
{
	Direction = newdir;
}

const Dir Tank::GetDir()
{
	return Direction;
}

void Tank::ChangeFireInterval(int NewInterval)
{
	FireInterval = NewInterval;
}

void Tank::Print()
{
	IMAGE img1,img2;
	loadimage(&img1, _T("PlayerTank.jpg")); //��ȡ��Ƭ ������Ϊ60x60��

     //���ݷ����λ�ô�ӡ̹��
	if (Direction == UP)
	{
		putimage(XY.X, XY.Y, &img1);       //�ڹ̶�λ�ô�ӡ̹��
	}
	else if (Direction == DOWN)
	{
		// ��תͼ�� 180 �� (PI / 6)
		rotateimage(&img2, &img1, PI);

		putimage(XY.X, XY.Y, &img2);

	}
	else if (Direction == LEFT)
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
	if(!GetReadyForFire())   //�����û����ȴ�ã��ſ�ʼ����ȴ
	nowInterval--;                   //��ȴing
	if (nowInterval == 0)           //��ȴ����
	{
		nowInterval = GetFireInterval();  //������ȴʱ��
		ChangeReadyForFire(1);      //װ�������������һ��
	}
}

const bool Tank::GetReadyForFire()
{
	return ReadyForFire;
}

void Tank::ChangeReadyForFire(int ReadyOrNot)
{
	ReadyForFire = ReadyOrNot;
}










void PlayTank::Fire()
{
	ChangeReadyForFire(0);     //���뿪����ȴ

}

void PlayTank::MoveTank(Dir NewDir)
{
		if (NewDir == UP || NewDir == DOWN || NewDir == RIGHT || NewDir == LEFT)       //�ж��Ƿ�Ϊ�������
		{
			COORD oldxy = Getxy();    //��ȡ����
			short speed = GetSpeed(); //��ȡ�ٶ�

			if(NewDir==GetDir())
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

			ChangeDir(NewDir);
		}
}
