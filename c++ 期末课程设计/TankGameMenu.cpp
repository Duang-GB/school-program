#include "TankGameMenu.h"
using namespace std;

void const drawdre(COORD x);              //�����麯��
bool const cor_cmp(COORD pt1, COORD pt2);  //����ȽϺ���
bool const JudgmentKill(COORD shellxy, COORD tankxy); //���к���


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

	srand((unsigned int)time(NULL));


	////////////////////////////////////////////////////���Է�Χ//////////////////////////////////////////////////
	//����������


	//����
	list<Shell*> PlayerTankShell;         //�洢���̹�˵��ӵ� 
	list<Shell*> EnemyTankShell;          //����з�̹�˵��ӵ�
	list<NormalAITank*> NormalTank;       //����з�̹��


	//������
	list<Shell*>::iterator PTS;           //���̹�˵��ӵ�
	list<Shell*>::iterator ETS;           //�з�̹�˵��ӵ�
	list<NormalAITank*>::iterator NT;     //�з�̹��




	PlayTank player;                    //�������̹��
	COORD Judgmentxy;                   //�����ж��Ƿ����������赲�� �����¼
	Map gamemap;                        //�����ͼ

	player.Setxy({ 14*GAMESIZE,24*GAMESIZE });              //��λ��ҳ�ʼ����



	int operation;                    //��¼������
	int random;                       //һ�������
	
	BeginBatchDraw();          //��ʼ������ͼ

	gamemap.ReadyforMap_one();            //��ͼ����ͨ�õ���



	//ѭ����Ϸ����
	while (1)
	{
		//��Ұ���������Ӧ
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

			else if (operation == UP || operation == DOWN || operation == RIGHT || operation == LEFT)    //�ƶ�����
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


		//���ɵз�̹��	
		if (gamemap.GetNumNormalTank() > 0 && NormalTank.size()< 3)   //��������4���з�̹����̹�˻���ʣ��
		{
			NormalAITank *p=new NormalAITank();        //����tank�ڴ�
			gamemap.KillNormalTank();                  //����ʣ��з�̹������
			random = rand();     //�����
			p->Setxy(gamemap.CreatObjectXY(random));         //�������λ��
			NormalTank.push_back(p);          //ѹ��
		}
		
		///////////////////////////////////��ӡ����//////////////////////////////////////
		loadimage(NULL, _T("Floor.jpg"));          //������ͼ
		gamemap.PrintMap_2();   //����ͼMap�ࣨ����cardȷ��map  ̹���·�
		player.Print();  //��ӡ���̹��

		 //��������ͨ�з�̹�˲����������ƶ�����ӡ
		for (NT = NormalTank.begin(); NT != NormalTank.end();)  
		{
			if ((*NT)->GetHP() == 0)        //�ж��Ƿ�����
			{
				NT = NormalTank.erase(NT);       //�ͷŵз�̹���ڴ�
			}
			else
			{
				random = rand();  //�����
				Dir movedir = (*NT)->NormalMoveAI(random);    //������̹ͨ���ƶ�ai
				Judgmentxy = (*NT)->Getxy();        //��¼��ǰ̹������


				//�����жϣ����˾ʹ�
				if ((*NT)->GetReadyForFire())        
				{
					(*NT)->ChangeReadyForFire(0);     //��ȴ
					Shell *p = new Shell(movedir, Judgmentxy);   //�������ڴ�
					p->Print();
					EnemyTankShell.push_back(p);                       //ѹ���ڵ�����
				}



				//�޸�̹�˳���
				(*NT)->ChangeDir(movedir);          
				switch (movedir) {
				case UP:
					Judgmentxy.Y -= SpeedLevel_1;
					break;
				case DOWN:
					Judgmentxy.Y += SpeedLevel_1;
					break;
				case LEFT:
					Judgmentxy.X -= SpeedLevel_1;
					break;
				case RIGHT:
					Judgmentxy.X += SpeedLevel_1;
					break;
				}

				if (gamemap.GetTankAdmit(Judgmentxy)                                  //�ж��Ľ��Ƿ��������ײ
					&& gamemap.GetTankAdmit({ Judgmentxy.X + 59,Judgmentxy.Y + 59 })
					&& gamemap.GetTankAdmit({ Judgmentxy.X ,Judgmentxy.Y + 59 })
					&& gamemap.GetTankAdmit({ Judgmentxy.X + 59,Judgmentxy.Y })
					&& !gamemap.JudgmentBorder(Judgmentxy)                             //�ж������Ƿ񳬽�
					&& !gamemap.JudgmentBorder({ Judgmentxy.X + 59,Judgmentxy.Y + 59 }))
					(*NT)->MoveTank(movedir);      //�ƶ��з���̹ͨ��        

				(*NT)->Print();         //��ӡ̹��


				++NT;           //����һ��̹�˲���
			}
		}
		gamemap.PrintMap_1();  //����ͼMap�ࣨ����cardȷ��map   ̹���Ϸ�


		//����������������ڵ�����
		for (PTS = PlayerTankShell.begin(); PTS != PlayerTankShell.end();)   
		{

			(*PTS)->Print();       //��ӡ�ڵ�
			(*PTS)->Fly();         //�ڵ��ƶ�
			COORD Shellxy = (*PTS)->GetXY();  //��¼�ڵ�����
			bool flag = 0;        //�Ƿ����ез�̹�˵ı�־

			for (NT = NormalTank.begin(); NT != NormalTank.end(); NT++)      //����̹����ȷ����û������
			{
				if (JudgmentKill(Shellxy, (*NT)->Getxy()))  //����
				{
					(*NT)->ChangeHp(0);              //����HP
					flag = 1;
					break;
				}
			}

			if (!gamemap.GetShellAdmit((*PTS)->GetXY()))			          //�ж��Ƿ�򵽵���
			{
				gamemap.ChangeMap((*PTS)->GetXY()); //�޸ĵ�ͼ������ǽ���;�
				PTS = PlayerTankShell.erase(PTS);	//����ɾ�����ͷ��ڴ�
			}
			else if (gamemap.JudgmentBorder((*PTS)->GetXY())||flag)          //�ڵ�������ɱ
			{
				PTS = PlayerTankShell.erase(PTS);	//ɾ�����ͷ��ڴ�
			}
			else             //������һ���ڵ�
			{
				++PTS;
			}
		}

		//�����������Եз��ڵ�����
		for (ETS = EnemyTankShell.begin(); ETS != EnemyTankShell.end();)  
		{

			(*ETS)->Print();       //��ӡ�ڵ�
			(*ETS)->Fly();         //�ڵ��ƶ�

			if (!gamemap.GetShellAdmit((*ETS)->GetXY()))			          //�ж��Ƿ�򵽵���
			{
				gamemap.ChangeMap((*ETS)->GetXY()); //�޸ĵ�ͼ������ǽ���;�
				ETS = EnemyTankShell.erase(ETS);	//����ɾ�����ͷ��ڴ�
			}

			//	else if()              //�ж�����̹��

			else if (gamemap.JudgmentBorder((*ETS)->GetXY()))          //�ڵ�����
			{
				ETS = EnemyTankShell.erase(ETS);	//ɾ�����ͷ��ڴ�
			}
			else             //������һ���ڵ�
				++ETS;
		}

		player.FireIntevalFigure();          //������ҿ�����ȴ����
		for (NT = NormalTank.begin(); NT != NormalTank.end(); NT++)
			(*NT)->FireIntevalFigure();      //����з��ڵ���ȴ

		//����
		//�������״��������
		//ͨ���ж���������������һ��
		FlushBatchDraw();  //������ͼ
		Sleep(GameSpeed); //��Ϸ�ӳ�
		cleardevice();    //�����Ļ
	}
	EndBatchDraw();         //����������ͼ
	gamemap.CloseMap();     //�ͷŵ�ͼ�ڴ�
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