#pragma once
#include "Terrain.h"
#include"main_game.h"
//=============================��ͼ��===============================//
class Map
{
public:
	Map();
	~Map();

	const bool GetTankAdmit(COORD xy) { return MT[xy.X/60][xy.Y/60].TankT; }       //����̹��ͨ�����  �������ת��
	const bool GetShellAdmit(COORD xy) { return MT[xy.X/60][xy.Y/60].ShellT; }     //�����ڵ�ͨ�����

	bool JudgmentBorder(COORD xy);         //�ж�����Ƿ񳬽�
	void ChangeMap(COORD xy);              //�޸ĵ�ͼ�ϵĵ��Σ�����HP)
	const void PrintMap_1();                  //��ӡ��ͼ(��̹�������
	const void PrintMap_2();                  //��ӡ��ͼ����̹�������
	void CloseMap();                       //�ͷ��ڴ棬������Ϸ��׼�����ŵ�ͼ


	void ReadyforMap_one();     //���ص�һ�ص�׼������
	void ReadyforMap_two();
private:
	COORD Switchxy(COORD xy) { return { (xy.X / 60) ,(xy.Y / 60)  }; }   //ת�����꣨���������� ת��Ϊ ÿ60����Ϊһ��� ���Ͻ�����
	MapTerrain MT[20][14];    //ȫ��ͼ���ڵ�/̹��ͨ�����(��60x60����Ϊ��λ 

	SteeWall *steewall;      //���μ�¼ָ��
	River *river;
	Brush *brush;
	SodWall *sodwall;
	Home home;        //�Ҿ�һ��������x

	int num_stee;            //�������ε�����
	int num_river;
	int num_brush;
	int num_sodwall;

	SodWall testwall;       //����ǽ

	short _x;    //����������
	short _y;
};

