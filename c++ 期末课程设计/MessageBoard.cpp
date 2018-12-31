#include "MessageBoard.h"



MessageBoard::MessageBoard()
{
	Speed = SpeedLevel_1;           //��ʼ�ٶ�
	Hp = 2;                         //��ʼ����
	FireInterval = IntervalLevel_1; //��ʼ�������
	card = 1;                       //��һ��
	XY = { 0,810 };
}


MessageBoard::~MessageBoard()
{
}

const void MessageBoard::Print()
{
	IMAGE img1;
	loadimage(&img1, _T("MessageBoard.jpg")); //��ȡ��Ƭ ������Ϊ60x60��
	putimage(XY.X, XY.Y, &img1);

	//��ӡѪ��
	setbkcolor(BLACK);              //�������屳����ɫ
	settextstyle(30, 0, _T("����"));   //�������ָ�ʽ��������
	settextcolor(RED);          //������ɫ
	if(Hp==1)
		outtextxy(150,840, _T("1"));
	else if(Hp==2)
		outtextxy(150, 840, _T("2"));
	else if(Hp==3)
		outtextxy(150, 840, _T("3"));
	else
		outtextxy(150, 840, _T("0"));

	settextcolor(GREEN);          //������ɫ
	//��ӡ�ؿ�
	if (card == 1)
		outtextxy(900, 840, _T("�� һ ��"));
	else if (card==2)
		outtextxy(900, 840, _T("�� �� ��"));

	settextstyle(20, 0, _T("����"));   //�������ָ�ʽ��������
	//��ӡ�ٶ�
	if (Speed == SpeedLevel_1)
		outtextxy(300, 825, _T("Level 1"));
	else if (Speed == SpeedLevel_2)
		outtextxy(300, 825, _T("Level 2"));
	else if (Speed == SpeedLevel_3)
		outtextxy(300, 825, _T("Level 3"));
	else;

	//��ӡ����
	if (FireInterval == IntervalLevel_1)
		outtextxy(300, 855, _T("Level 1"));
	else if (FireInterval == IntervalLevel_1)
		outtextxy(300, 855, _T("Level 2"));
	else if (FireInterval == IntervalLevel_1)
		outtextxy(300, 855, _T("Level 3"));
	else;



}

void MessageBoard::ChangeTankMessage(PlayTank tank)
{
	Speed = tank.GetSpeed();
	Hp = tank.GetHP();
	FireInterval = tank.GetFireInterval();
}
