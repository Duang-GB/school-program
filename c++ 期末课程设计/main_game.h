#pragma once

#include<iostream>
#include<stdlib.h>
#include<graphics.h>     //easyXͼ�ο�
#include<conio.h>
#include<time.h>
#include<windows.h>

//��������
constexpr auto GAMESIZE = 30;       //��ͼʹ�õı�׼������һ��Ϊ30����
const int TANK = 1;        //̹��
const int HOME = 2;        //��
const int SHELL = 3;       //�ڵ�
const int SODWALL = 5;     //��ǽ ���ƻ���ǽ
const int STEEWALL = 6;    //��ǽ �����ƻ���ǽ
const int BRUSH = 7;       //��ľ ̹�˿��Դ�Խ �ڵ��޷�����
const int RIVER = 8;       //���� ̹�˲��ܴ�Խ �ڵ����Դ�Խ


//��������
constexpr auto UP = 119;       //w ��
constexpr auto DOWN = 115;     //s ��
constexpr auto LEFT = 97;      //a ��
constexpr auto RIGHT = 100;    //d ��
constexpr auto DETER = 106;    //j ����/ȷ��
constexpr auto ACT = 107;    //k ����/�˳�/����

constexpr auto PI = 3.1415926535;         //������תͼƬ