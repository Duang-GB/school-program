#include "Map.h"
using namespace std;

list<SodWall*> MapSodWall;            //�����ͼ�ϵĿ��ƻ�ǽ
list<SodWall*>::iterator MSW;         //��ǽ

Map::Map()
{
}


Map::~Map()
{
}

void Map::ReadyforAllMap()
{
	num_stee = 20;
	steewall = new SteeWall [20];
	_x = 0;
	_y = 13;
	//��ͼ�·���һ����ǽ
	for (int i = 0; i < num_stee; i++)
	{
		steewall[i].SetXY({ _x,_y });                     //���õ�������
		MT[_x][_y]=steewall[i].GetMapTerrain();           //���õ�������
		_x++;
	}
	///////////////����ǽ///////////////////////
	//testwall.SetXY({ 3,4 });
	//MT[3][4] = testwall.GetMapTerrain();
	////////////////////////////////////////
}


void Map::CloseMap()
{

}

void Map::ReadyforMap_one()
{

}

void Map::PrintMap_one()
{
	for (int i = 0; i < num_stee; i++)
	{
		steewall[i].Print();
	}
	////////////////����ǽ//////////////////
	//testwall.Print();
	//////////////////////////////////////
}
