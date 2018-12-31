#include "TankGameMenu.h"
using namespace std;

void const drawdre(COORD x);              //�����麯��

TankGameMenu::TankGameMenu()
{
}


TankGameMenu::~TankGameMenu()
{
}
//���˵�
void TankGameMenu::printTankGameMenu()
{
	initgraph(1200, 900);              //��ʼ��ͼ�ν���
	setbkcolor(BLACK);              //�������屳����ɫ
	setfillcolor(BLACK);            //���ó�ʼ������ɫ
	solidrectangle(0,0,1200,900);      //��������ɫ
	settextstyle(40, 0, _T("����"));   //�������ָ�ʽ��������

	int const ox = 500;          //��עλ�õĳ���

	settextcolor(RED);          //��ѡ���������ɫ
	outtextxy(ox, ox-100, _T("�� Ϸ �� ʼ"));//�˵������������
	settextcolor(GREEN);        //δѡ���������ɫ
	outtextxy(ox, ox+50, _T("�� Ϸ ˵ ��"));
	outtextxy(ox, ox+200, _T("�� �� �� Ϸ"));

	int dir;                        //�˵�ѡ�����Ϻ���
	int flag = 1;                   //ȷ��ѡ��
	while (1)
	{
		if (_kbhit())
		{//����flagֵ�����ƶ�

			dir = _getch();    //��ȡ�����ֵ
			if (dir == UP && flag != 1)  //���ݼ�ֵ�任ѡ��
				flag--;
			if (dir == DOWN && flag != 3)
				flag++;
			if (dir == DETER)
				break;
			settextcolor(GREEN);
			outtextxy(ox, ox-100, _T("�� Ϸ �� ʼ"));//�˵�����������ɫ����
			outtextxy(ox, ox+50, _T("�� Ϸ ˵ ��"));
			outtextxy(ox, ox+200, _T("�� �� �� Ϸ"));

			switch (flag)                //����ѡ��任��ɫ
			{
			case 1: settextcolor(RED);
				outtextxy(ox, ox - 100, _T("�� Ϸ �� ʼ"));
				break;
			case 2: settextcolor(RED);
				outtextxy(ox, ox + 50, _T("�� Ϸ ˵ ��"));
				break;
			case 3:settextcolor(RED);
				outtextxy(ox, ox + 200, _T("�� �� �� Ϸ"));
				break;
			default: break;
			}
		}
	}
	if (flag == 1)//��Ϸ��ʼ
	{
		return;
	}
	if (flag == 2)//��Ϸ˵��
	{
		Commeting();
	}
	if (flag == 3)//�˳���Ϸ
	{
		Inaugurated();  //��������
		exit(-1);
	}

}
//ˢ��
void TankGameMenu::Inaugurated()
{
	setfillcolor(GREEN);            //������ɫ
	COORD point = { 0,0 };          //���ñʼ�λ�ã�������ĳ�ʼλ��
	while (point.Y<=2)
	{
		while (point.X <= 60)
		{
			drawdre(point);
			drawdre({ point.X-7,point.Y + 1 });
			drawdre({ point.X-15,point.Y + 2 });
			drawdre({ point.X-2,point.Y + 4 });
			drawdre({ point.X-1,point.Y + 5 });
			drawdre({ point.X-4,point.Y + 6 });
			drawdre({ point.X - 15,point.Y + 8 });
			drawdre({ point.X-1,point.Y + 9 });
			drawdre({ point.X-2,point.Y + 11 });
			drawdre({ point.X - 3,point.Y + 13 });
			drawdre({ point.X - 15,point.Y + 15 });
			drawdre({ point.X - 6,point.Y + 16 });
			drawdre({ point.X - 7,point.Y + 18 });
			drawdre({ point.X - 18,point.Y + 20 });
			drawdre({ point.X - 1,point.Y + 21 });
			drawdre({ point.X - 18,point.Y + 23 });
			drawdre({ point.X - 15,point.Y + 24 });
			drawdre({ point.X - 1,point.Y + 26 });
			drawdre({ point.X - 4,point.Y + 28 });
			drawdre({ point.X - 1,point.Y + 30 });
			drawdre({ point.X - 20,point.Y + 32 });
			drawdre({ point.X - 15,point.Y + 33 });
			drawdre({ point.X - 4,point.Y + 35 });
			drawdre({ point.X - 1,point.Y + 37 });
			drawdre({ point.X - 20,point.Y + 39 });
			drawdre({ point.X - 4,point.Y + 40 });
			point.X += 1;
			Sleep(8);
		}
		point.X = 0;
		point.Y += 1;
	}
	printf("%d,%d\n", point.X, point.Y);
}

//��Ϸ˵��
void TankGameMenu::Commeting()
{
	//��ӡһ��ͼƬ
	loadimage(NULL, _T("˵��ͼƬ"));
	//��k����
	int flag;     //�ж�����
	if (_kbhit())
		flag=_getch();
	if (flag == ACT)
		printTankGameMenu(); //����ѡ��˵�
}

void TankGameMenu::GameOver()
{
	IMAGE img1;

	loadimage(&img1, _T("GameOver.jpg")); //��ȡ��Ƭ ������Ϊ60x60��

	putimage(0, 300, &img1);

	setbkcolor(BLACK);              //�������屳����ɫ
	settextstyle(40, 0, _T("����"));   //�������ָ�ʽ��������
	int const ox = 300;          //��עλ�õĳ���

	settextcolor(RED);          //��ѡ���������ɫ
	outtextxy(ox, ox+250, _T("�� �� �� ʼ"));//�˵������������
	settextcolor(GREEN);        //δѡ���������ɫ
	outtextxy(ox+400, ox + 250, _T("�� �� �� Ϸ"));

	Sleep(1000);
	int dir;                        //�˵�ѡ���������
	int flag = 1;                   //ȷ��ѡ��
	while (1)
	{
		if (_kbhit())
		{//����flagֵ�����ƶ�

			dir = _getch();    //��ȡ�����ֵ
			if (dir == LEFT && flag != 1)  //���ݼ�ֵ�任ѡ��
				flag--;
			if (dir == RIGHT && flag != 2)
				flag++;
			if (dir == DETER)
				break;
			settextcolor(GREEN);
			outtextxy(ox, ox + 250, _T("�� �� �� ʼ"));//�˵�����������ɫ����
			outtextxy(ox + 400, ox + 250, _T("�� �� �� Ϸ"));

			switch (flag)                //����ѡ��任��ɫ
			{
			case 1: settextcolor(RED);
				outtextxy(ox, ox + 250, _T("�� �� �� ʼ"));
				break;
			case 2:settextcolor(RED);
				outtextxy(ox + 400, ox + 250, _T("�� �� �� Ϸ"));
				break;
			default: break;
			}
		}
	}
	if (flag == 1)
		return;  //���¿�ʼ
	else
		Inaugurated();
		exit(1); //�˳���Ϸ
}