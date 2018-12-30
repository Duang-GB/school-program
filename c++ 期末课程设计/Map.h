#pragma once
#include "Terrain.h"
#include"main_game.h"
#include"Tank.h"
//=============================��ͼ��===============================//
class Map
{
public:
	Map();
	~Map();

	const bool GetTankAdmit(COORD xy) { return MT[xy.X/60][xy.Y/60].TankT; }       //����̹��ͨ�����  �������ת��
	const bool GetShellAdmit(COORD xy) { return MT[xy.X/60][xy.Y/60].ShellT; }     //�����ڵ�ͨ�����

	const int GetNumNormalTank(){return num_normaltank;}               //��ȡ��̹ͨ������
	const int GetNumBossTank() { return num_bosstank; }             //��ȡ��Ӣ̹������
	void KillNormalTank() { --num_normaltank; }                     //����̹������
	void KillBossTank() { --num_bosstank; }

	bool JudgmentBorder(COORD xy);         //�ж�����Ƿ񳬽�
	void ChangeMap(COORD xy);              //�޸ĵ�ͼ�ϵĵ��Σ�����HP)
	const void PrintMap_1();               //��ӡ��ͼ(��̹�������
	const void PrintMap_2();               //��ӡ��ͼ����̹�������
	void CloseMap();                       //�ͷ��ڴ棬������Ϸ��׼�����ŵ�ͼ
	COORD CreatObjectXY(int h);                 //����ڵ�ͼ�ϲ���Χ���������꣬������Ұ��̹�˺�Ұ��buff�ṩ������


	void ReadyforMap_one();     //���ص�һ�ص�׼������
	void ReadyforMap_two();     //���صڶ���׼������
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

	int num_normaltank;   //��̹ͨ������
	int num_bosstank;     //��Ӣ̹������

	short _x;    //����������
	short _y;
};

