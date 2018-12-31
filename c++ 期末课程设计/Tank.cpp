#include "Tank.h"
#include"main_game.h"
using namespace std;

//list<Shell*> EnemyTankShell;          //����з�̹�˵��ӵ�

Tank::Tank()
{

}


Tank::~Tank()
{
}


void Tank:: ChangeHp(int flag)
{
	if (flag == 1) //��������Ӽ�����ֵ
		Hp++;
	if (flag == 0)
		Hp--;
}

const void Tank::TankBoom()
{
	IMAGE img;
	loadimage(&img, _T("Boom.jpg"));
	putimage(XY.X , XY.Y , &img);
}

void Tank::FireIntevalFigure()
{
	if(!ReadyForFire)   //�����û����ȴ�ã��ſ�ʼ����ȴ
	nowInterval--;                   //��ȴing
	if (nowInterval <= 0)           //��ȴ����
	{
		nowInterval = FireInterval;  //������ȴʱ��
		ReadyForFire=1;      //װ�������������һ��
	}
}

//////////////////////////////////////���tank////////////////////////////////
PlayTank::PlayTank()
{
	Speed = SpeedLevel_1;           //��ʼ�ٶ�
	Hp = 2;                         //��ʼ����
	Direction = UP;                 //��ʼ����
	ReadyForFire = 1;               //����װ��
	FireInterval = IntervalLevel_1; //��ʼ�������
	RectSphere = 60;                //̹�˴�С60x60����
	nowInterval = FireInterval;  //��ʼ����ȴʱ��
}

void PlayTank::Fire()
{
	ReadyForFire=0;     //���뿪����ȴ
}

void PlayTank::MoveTank(Dir NewDir)
{
			switch (NewDir) {    //�����ƶ��ٶ��ƶ�
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
				XY.X+= Speed;
				break;
			}
}

void PlayTank::Print()
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

/////////////////////////////////////��ͨ�з�̹��//////////////////////////
NormalAITank::NormalAITank()
{
	Speed = SpeedLevel_1;           //��ʼ�ٶ�
	Hp = 2;                         //��ʼ����
	Direction = DOWN;                 //��ʼ����
	ReadyForFire = 0;               //����װ��
	FireInterval = IntervalLevel_1; //��ʼ�������
	RectSphere = 60;                //̹�˴�С60x60����
}

void NormalAITank::Print()
{
	IMAGE img1, img2;
	loadimage(&img1, _T("NormalTank.jpg")); //��ȡ��Ƭ ������Ϊ60x60��

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
		rotateimage(&img2, &img1, (3 * PI) / 2);

		putimage(XY.X, XY.Y, &img2);

	}
}

Dir NormalAITank::NormalMoveAI(int h)
{

	int n = h % 15;
	if (n < 11)
		return Direction;  //�������±���ԭ���򲻱�
	else if (n < 12)
		return UP;
	else if (n < 13)
		return DOWN;
	else if (n < 14)
		return LEFT;
	else
		return RIGHT;
}

void NormalAITank::MoveTank(Dir NewDir)
{
		switch (NewDir) {    //�����ƶ��ٶ��ƶ�
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
		}
}

/*
void NormalAITank::Fire()
{
	ReadyForFire = 0;
	Shell *p = new Shell(Direction,XY);   //�������ڴ�
	p->Print();
	EnemyTankShell.push_back(p);                       //ѹ���ڵ�����
}
*/

////////////////////////////////////��Ӣ�з�̹��//////////////////////////
BossAITank::BossAITank()
{
	Speed = SpeedLevel_3;           //��ʼ�ٶ�
	Hp = 3;                         //��ʼ����
	Direction = UP;                 //��ʼ����
	ReadyForFire = 1;               //����װ��
	FireInterval = IntervalLevel_3; //��ʼ�������
	RectSphere = 60;                //̹�˴�С60x60����
}

void BossAITank::Print()
{
	IMAGE img1, img2;
	loadimage(&img1, _T("BossTank.jpg")); //��ȡ��Ƭ ������Ϊ60x60��

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
		rotateimage(&img2, &img1, (3 * PI) / 2);

		putimage(XY.X, XY.Y, &img2);

	}
}

Dir BossAITank::BossMoveAI(int h)
{
	int n = h % 15;
	if (XY.Y < 400)       //�ڵ�ͼ�ϰ벿��
	{
		if (n < 8)
			return Direction;  //�������±���ԭ���򲻱�
		else if (n < 12)
			return DOWN;        //������������
		else if (n < 13)
			return LEFT;
		else
			return RIGHT;
	}
	else
	{
		if (n < 11)
			return Direction;  //�������±���ԭ���򲻱�
		else if (n < 12)
			return UP;         //���ⷽ����
		else if (n < 13)
			return DOWN;
		else if (n < 14)
			return LEFT;
		else
			return RIGHT;
	}
}

void BossAITank::MoveTank(Dir NewDir)
{
	switch (NewDir) {    //�����ƶ��ٶ��ƶ�
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
	}
}