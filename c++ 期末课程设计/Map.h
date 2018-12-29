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

	void ChangeMap(COORD xy);              //�޸ĵ�ͼ�ϵĵ��Σ�����HP)
	void CloseMap();                       //�ͷ��ڴ棬������Ϸ��׼�����ŵ�ͼ

	void ReadyforAllMap();        //�������е�ͼ��ͬ����

	void ReadyforMap_one();     //���ص�һ�ص�׼������
	void PrintMap_one();        //��ӡ��һ��

	void ReadyforMap_two();
	void PrintMap_two();
private:
	MapTerrain MT[20][14];    //ȫ��ͼ���ڵ�/̹��ͨ�����(��60x60����Ϊ��λ 
	SteeWall *steewall;      //���μ�¼ָ��
	River *river;
	Brush *brush;
	int num_stee;            //�������ε�����
	int num_river;
	int num_brush;

	//SteeWall testwall;       //����ǽ

	short _x;    //����������
	short _y;
};

