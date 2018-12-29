#pragma once
#include"main_game.h"
//=============================�����ࣨ�������εĻ��ࣩ===============================//
class Terrain
{
public:
	Terrain();
	~Terrain();
	void SetXY(COORD xy) { XY.X = xy.X * 60; XY.Y = xy.Y * 60; }   //�趨����
	virtual void Print() = 0;       //��ӡ����
	const int GetHP() { return HP; }       //�����жϵ����Ƿ񻹴���
	const MapTerrain GetMapTerrain(){return mapterrain;}    //��ȡ��ͼ��Խ��Ϣ

protected:
	MapTerrain mapterrain;      //tank/�ڵ��ܷ�Խ����Ϣ
	COORD XY;
	int HP;
};

//const int SODWALL = 5;     //��ǽ ���ƻ���ǽ
//const int STEEWALL = 6;    //��ǽ �����ƻ���ǽ
//const int BRUSH = 7;       //��ľ ̹�˿��Դ�Խ �ڵ��޷�����
//const int RIVER = 8;       //���� ̹�˲��ܴ�Խ �ڵ����Դ�Խ

//�ذ���
class Floor :public Terrain
{
public:
	Floor();
	void Print();
};

//��ǽ��
class SteeWall :public Terrain
{
public:
	SteeWall();
	void Print();
};

//��ǽ��
class SodWall :public Terrain
{
public:
	SodWall();
	void Print();
};

//��ľ��
class Brush :public Terrain
{
public:
	Brush();
	void Print();
};

//������
class River :public Terrain
{
public:
	River();
	void Print();
};

//��԰��
class Home :public Terrain
{
	Home();
	void Print();
};