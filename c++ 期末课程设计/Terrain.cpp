#include "Terrain.h"



Terrain::Terrain()
{
}


Terrain::~Terrain()
{
}




Floor::Floor()
{
	TankThrough = 1;
	ShellThrough = 1;
	HP = 1;         //���治���Ѫ
}

SteeWall::SteeWall()
{
	TankThrough = 0;
	ShellThrough = 0;
	HP = 1000;         //���������޷��ƻ�
}

SodWall::SodWall()
{

	TankThrough = 0;
	ShellThrough = 0;
	HP = 2;         
}

Brush::Brush()
{
	TankThrough = 1;
	ShellThrough = 0;
	HP = 1000;         
}

River::River()
{
	TankThrough = 0;
	ShellThrough = 1;
	HP = 1000;        
}

Home::Home()
{
	TankThrough = 0;
	ShellThrough = 0;
	HP = 1;
	XY = { 20 * GAMESIZE,26 * GAMESIZE };  //��ʼ����
}


void Floor::Print()
{
	IMAGE img1;
	loadimage(&img1, _T("Floor.jpg")); //��ȡ��Ƭ ������Ϊ60x60��
	putimage(XY.X, XY.Y, &img1);
}

void SteeWall::Print()
{
	IMAGE img1;

	loadimage(&img1, _T("SteeWall.jpg")); //��ȡ��Ƭ ������Ϊ60x60��

	putimage(XY.X, XY.Y, &img1);
}

void SodWall::Print()
{
	IMAGE img1;

	if (HP == 2)
		loadimage(&img1, _T("SodWall_intact.jpg")); //��ȡ���ǽ����Ƭ ������Ϊ60x60��
	if (HP == 1)
		loadimage(&img1, _T("SodWall_damage.jpg")); //��ȡ���ǽ����Ƭ ������Ϊ60x60��

	putimage(XY.X, XY.Y, &img1);
}

void Brush::Print()
{
	IMAGE img1;
	loadimage(&img1, _T("Brush.jpg")); //��ȡ��Ƭ ������Ϊ60x60��
	putimage(XY.X, XY.Y, &img1);
}

void River::Print()
{
	IMAGE img1;
	loadimage(&img1, _T("River.jpg")); //��ȡ��Ƭ ������Ϊ60x60��
	putimage(XY.X, XY.Y, &img1);
}

void Home::Print()
{
	IMAGE img1;
	loadimage(&img1, _T("Home.jpg")); //��ȡ��Ƭ ������Ϊ60x60��
	putimage(XY.X, XY.Y, &img1);
}