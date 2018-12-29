#include "TankGameMenu.h"
using namespace std;

void const drawdre(COORD x);            //���������麯��

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
		GameStart(1);
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
//��Ϸ��ʼ
void TankGameMenu::GameStart(int card)
{
	setfillcolor(BLACK);            //���ó�ʼ������ɫ
	solidrectangle(0, 0, 1200, 900);      //��������ɫ



	////////////////////////////////////////////////////���Է�Χ//////////////////////////////////////////////////
	//����������


	//����
	list<Shell*> PlayerTankShell;         //�洢���̹�˵��ӵ� 
//	list<SodWall*> MapSodWall;            //�����ͼ�ϵĿ��ƻ�ǽ
	//������
	list<Shell*>::iterator PTS;           //���̹�˵��ӵ�
//	list<SodWall*>::iterator MSW;         //��ǽ




	PlayTank player;                    //�������̹��
	COORD Judgmentxy;                   //�����ж��Ƿ����������赲�� �����¼
	Map gamemap;                         //�����ͼ
	//IMAGE bg;                            //���� 
	player.Setxy({ 14*GAMESIZE,24*GAMESIZE });              //��λ��ҳ�ʼ����




	int operation;                    //��¼������

	
	BeginBatchDraw();          //��ʼ������ͼ

	gamemap.ReadyforMap_one();            //��ͼ����ͨ�õ���


	//ѭ����Ϸ����
	while (1)
	{
		if (_kbhit())       //������������
		{
			operation= _getch();    //��ȡ��ǰ����

			if (operation == DETER && player.GetReadyForFire())          //ȷ�Ϲ������������Ѿ���ȴ����
			{
				player.Fire();             //ʹ��ҽ��뿪����ȴ
				Shell *p = new Shell(player.GetDir(),player.Getxy());   //�������ڴ�
				p->Print();                                          //��ӡ�ڵ�
				PlayerTankShell.push_back(p);                       //ѹ���ڵ�����
			}

			if (operation == UP || operation == DOWN || operation == RIGHT || operation == LEFT)    //�ƶ�����
			{
				Judgmentxy = player.Getxy();   //��¼��ǰ̹������
				player.ChangeDir((Dir)operation);           //�޸�̹�˳���
				switch (operation) { 
				case UP:
					Judgmentxy.Y-=player.GetSpeed();  
					break;
				case DOWN:
					Judgmentxy.Y += player.GetSpeed();
					break;
				case LEFT:
					Judgmentxy.X -= player.GetSpeed();
					break;
				case RIGHT:
					Judgmentxy.X += player.GetSpeed();
					break;
				}
				if (gamemap.GetTankAdmit(Judgmentxy)                                  //�ж��Ľ��Ƿ��������ײ
					&& gamemap.GetTankAdmit({ Judgmentxy.X + 59,Judgmentxy.Y + 59 })
					&& gamemap.GetTankAdmit({ Judgmentxy.X ,Judgmentxy.Y + 59 })
					&& gamemap.GetTankAdmit({ Judgmentxy.X + 59,Judgmentxy.Y })
					&& !gamemap.JudgmentBorder(Judgmentxy)                             //�ж������Ƿ񳬽�
					&&!gamemap.JudgmentBorder({ Judgmentxy.X + 59,Judgmentxy.Y + 59 }))
				player.MoveTank((Dir)operation);      //�ƶ�̹��        ���ｫint��ǿ��ת��ΪDir����������
			}
			//��Ҳ���


		}

		loadimage(NULL, _T("Floor.jpg"));          //������ͼ



		gamemap.PrintMap_2();   //����ͼMap�ࣨ����cardȷ��map  ̹���·�




		player.Print();  //��ӡ���̹��




		gamemap.PrintMap_1();  //����ͼMap�ࣨ����cardȷ��map   ̹���Ϸ�







		for (PTS = PlayerTankShell.begin(); PTS != PlayerTankShell.end();)   //�������������ڵ�����
		{

			(*PTS)->Print();       //��ӡ�ڵ�
			(*PTS)->Fly();         //�ڵ��ƶ�

			if (!gamemap.GetShellAdmit((*PTS)->GetXY()))			          //�ж��Ƿ�򵽵���
			{
				gamemap.ChangeMap((*PTS)->GetXY()); //�޸ĵ�ͼ������ǽ���;�
				PTS = PlayerTankShell.erase(PTS);	//����ɾ�����ͷ��ڴ�
			}

		//	else if()              //�ж�����̹��

			else if (gamemap.JudgmentBorder((*PTS)->GetXY()))          //�ڵ�����
			{
				PTS = PlayerTankShell.erase(PTS);	//ɾ�����ͷ��ڴ�
			}
			else             //������һ���ڵ�
				++PTS;                        






		}












		//̹���ƶ������+ai

		player.FireIntevalFigure();          //������ҿ�����ȴ����




		//����
		//�������״��������
		//ͨ���ж���������������һ��
		FlushBatchDraw();  //������ͼ
		Sleep(GameSpeed); //��Ϸ�ӳ�
		cleardevice();    //�����Ļ
	}
	EndBatchDraw();         //����������ͼ
	//��������
	//����һ��or���ؽ���


	//////////////////////////////////////////////////////////////////���Է�Χ/////////////////////////////////////////////////////////
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