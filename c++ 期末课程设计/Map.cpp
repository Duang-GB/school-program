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

}

void Map::ReadyforMap_one()
{

}

void Map::CreatMap_one()
{

}