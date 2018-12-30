#include "Shell.h"
#include"main_game.h"

Shell::Shell(Dir facedir, COORD xy)
{
	Direction = facedir;       //��ȡ����

	if (Direction == UP)   //�ڵ��ĳ�ʼλ��Ӧ����̹�˵�����ǰ��
	{
		XY.X = xy.X+25 ;
		XY.Y = xy.Y - 10;
	}
	else if (Direction == DOWN)
	{
		XY.X = xy.X + 25;
		XY.Y = xy.Y + 60;
	}
	else if (Direction == LEFT)
	{
		XY.X = xy.X - 10;
		XY.Y = xy.Y + 25;
	}
	else  //RIGHT
	{
		XY.X = xy.X + 60;
		XY.Y = xy.Y +25;
	}

	RectSphere = 10;        //�ڵ�����10x10
}

Shell::~Shell()
{

}

void Shell::Print()
{
	IMAGE img1, img2;
	loadimage(&img1, _T("Shell.jpg")); //��ȡ��Ƭ ������Ϊ10x10��

	 //���ݷ����λ�ô�ӡ̹��
	if (Direction == UP)
	{
		putimage(XY.X, XY.Y, &img1);       //�ڹ̶�λ�ô�ӡ�ڵ�
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

void Shell::Fly()
{
	if (Direction == UP)                           //�ж��ڵ����з��򲢸ı�����
		XY.Y -= ShellFlySpeed;
	else if (Direction == DOWN)
		XY.Y += ShellFlySpeed;
	else if (Direction == LEFT)
		XY.X -= ShellFlySpeed;
	else  //RIGHT
		XY.X += ShellFlySpeed;
}

COORD Shell::GetXY()
{
	return XY;
}

void Shell::PrintShellBoom()
{
	IMAGE img;
	loadimage(&img, _T("Boom.jpg"));
	putimage(XY.X-10, XY.Y-10, &img);
}