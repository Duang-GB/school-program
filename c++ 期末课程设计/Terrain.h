#pragma once
#include"main_game.h"
//=============================�����ࣨ�������εĻ��ࣩ===============================//
class Terrain
{
public:
	Terrain();
	~Terrain();
	void SetXY(COORD xy) { XY.X = xy.X * 60; XY.Y = xy.Y * 60; }   //�趨����
	const COORD GetXY() { return { XY.X / 60,XY.Y/60 }; }          //��ȡ����
	virtual void Print() = 0;       //��ӡ����
	const int GetHP() { return HP; }       //�����жϵ����Ƿ񻹴���
	const MapTerrain GetMapTerrain(){return mapterrain;}    //��ȡ��ͼ��Խ��Ϣ
	void Destory() { HP--; }              //����ǽ��HP
protected:
	MapTerrain mapterrain;      //tank/�ڵ��ܷ�Խ����Ϣ
	COORD XY;
	int HP;
};

//const int SODWALL = 5;     //��ǽ ���ƻ���ǽ
//const int STEEWALL = 6;    //��ǽ �����ƻ���ǽ
//const int BRUSH = 7;       //��ľ ̹�˿��Դ�Խ �ڵ��޷�����
//const int RIVER = 8;       //���� ̹�˲��ܴ�Խ �ڵ����Դ�Խ



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
private:
	int Dynamic;      //������̬Ч��ʵ��
};

//��԰��
class Home :public Terrain
{
public:
	Home();
	void Print();
};