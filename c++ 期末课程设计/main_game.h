#pragma once

#include<iostream>
#include<stdlib.h>
#include<graphics.h>     //easyXͼ�ο�
#include<conio.h>
#include<time.h>
#include<windows.h>
#include <list>          

//��������
constexpr auto GAMESIZE = 30;       //��ͼʹ�õı�׼������һ��Ϊ30����
const int TANK = 1;        //̹��
const int HOME = 2;        //��
const int SHELL = 3;       //�ڵ�
const int SODWALL = 5;     //��ǽ ���ƻ���ǽ
const int STEEWALL = 6;    //��ǽ �����ƻ���ǽ
const int BRUSH = 7;       //��ľ ̹�˿��Դ�Խ �ڵ��޷�����
const int RIVER = 8;       //���� ̹�˲��ܴ�Խ �ڵ����Դ�Խ


struct MapTerrain
{
	bool TankT = 1, ShellT = 1; 
};    //����������ͼ�ĵ������� �����̹���ܷ�Խ��




//��������
const enum Dir { UP=119, DOWN=115, LEFT=97, RIGHT=100 };   //w�� a�� s�� d��
constexpr auto DETER = 106;    //j ����/ȷ��
constexpr auto ACT = 107;    //k ����/�˳�/����

constexpr auto PI = 3.1415926535;         //������תͼƬ


//��Ϸƽ������
const int SpeedLevel_1 = 10;   //�ƶ��ٶ�
const int SpeedLevel_2 = 15;
const int SpeedLevel_3 = 20;

const int IntervalLevel_1 = 15;  //������ȴʱ��
const int IntervalLevel_2 = 10;
const int IntervalLevel_3 = 7;

const int ShellFlySpeed = 20;   //�ڵ������ٶ�
const int GameSpeed = 10;       //��Ϸ�ӳ�30msһ֡