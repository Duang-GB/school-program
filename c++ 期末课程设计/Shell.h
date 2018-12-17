#pragma once
#include"main_game.h"
//=============================�ڵ���===============================//
class Shell
{
public:
	void SetDirection(int dir);          //�趨�ڵ�����

	void ShellMotionUp();                //չʾ�ڵ��������ҷ��У��ֿ�д�����жϴ���
	void ShellMotionDown();
	void ShellMotionLeft();
	void ShellMotionRight();

	int Shoot();                         //�����ڵ�������ȷ�����򼰽��
	void Kill();                         //ȷ�����в�ɾ���ڵ�
	void Print();                        //��ӡ�ڵ�
private:
	int direction;          //�ڵ��н��ķ���
	int speed;              //�ڵ����ٶ�
	COORD xy;               //�ڵ��ĵ�ǰ����
	int flag;
};


////////////////////////////���ʵ��//////////////////////////////

void Shell::SetDirection(int dir)
{
	direction = dir;
	flag = 1;        //ȷ���ڵ�״̬
}

int Shell::Shoot()
{
	if (direction == UP)
		while (flag)              //�ڵ�������һֱ����
		{
			ShellMotionUp();

		}
	else if (direction == DOWN)
	{

	}
	else if (direction == LEFT)
	{

	}
	else(direction == RIGHT)
	{

	}
}

void Shell::ShellMotionUp()
{
	--xy.Y;
}
void Shell:: ShellMotionDown()
{
	++xy.Y;
}
void Shell::ShellMotionLeft()
{
	--xy.X;
}
void Shell::ShellMotionRight()
{
	++xy.X;
}

void Shell::Kill()
{
	flag = 0;
}