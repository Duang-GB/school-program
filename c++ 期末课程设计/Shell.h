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
