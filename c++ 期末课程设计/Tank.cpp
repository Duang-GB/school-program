#include "Tank.h"
#include"main_game.h"
using namespace std;

//list<Shell*> EnemyTankShell;          //����з�̹�˵��ӵ�

Tank::Tank()
{
	/*
	Speed = SpeedLevel_1;           //��ʼ�ٶ�
	Hp = 1;                         //��ʼ����
	Direction = UP;                 //��ʼ����
	ReadyForFire = 1;               //����װ��
	FireInterval = IntervalLevel_1; //��ʼ�������
	RectSphere = 60;                //̹�˴�С60x60����
	*/
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


void Tank::FireIntevalFigure()
{
	static int nowInterval = FireInterval;  //��ʼ����ȴʱ��
	if(!ReadyForFire)   //�����û����ȴ�ã��ſ�ʼ����ȴ
	nowInterval--;                   //��ȴing
	if (nowInterval == 0)           //��ȴ����
	{
		nowInterval = FireInterval;  //������ȴʱ��
		ReadyForFire=1;      //װ�������������һ��
	}
}

//////////////////////////////////////���tank////////////////////////////////
PlayTank::PlayTank()
{
	Speed = SpeedLevel_1;           //��ʼ�ٶ�
	Hp = 1;                         //��ʼ����
	Direction = UP;                 //��ʼ����
	ReadyForFire = 1;               //����װ��
	FireInterval = IntervalLevel_1; //��ʼ�������
	RectSphere = 60;                //̹�˴�С60x60����
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
	Hp = 1;                         //��ʼ����
	Direction = UP;                 //��ʼ����
	ReadyForFire = 1;               //����װ��
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

Dir NormalAITank::NormalMoveAI()
{

	srand((unsigned int)time(NULL));

	int n = rand() % 5;
	switch (n)
	{
	case 0:return Direction; break;   //������
	case 1:return DOWN;  break;       //�ĸ������ƶ�
	case 2:return RIGHT; break;
	case 3:return LEFT;  break;
	case 4:return RIGHT; break;
	}
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