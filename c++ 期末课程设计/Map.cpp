#include "Map.h"
using namespace std;

list<SodWall*> MapSodWall;            //�����ͼ�ϵĿ��ƻ�ǽ
list<SodWall*>::iterator MSW;         //��ǽ
int const cor_cmp(COORD pt1, COORD pt2);

Map::Map()
{
}


Map::~Map()
{
}


bool Map::JudgmentBorder(COORD xy)
{
	if (xy.X > 1200 || xy.X < 0 || xy.Y < 0)
		return 1;                                   //����
	return 0;           //δ����
}

void Map::ChangeMap(COORD xy)
{
	int i;
	COORD _xy=Switchxy(xy);  //ת������
	MapTerrain allthrough;   //����ɴ�Խ����

	for (i = 0; i < 18; i++)
		if (cor_cmp(_xy, sodwall[i].GetXY()))   //Ѱ�ұ��ƻ���ǽ
		{
			sodwall[i].Destory();
			break;
		}

	if (sodwall[i].GetHP() == 0)     //�ñ��ƻ���ǽ���Ա���Խ
		MT[_xy.X][_xy.Y]= allthrough;

}


void Map::CloseMap()
{

}

void Map::ReadyforMap_one()
{
	num_stee = 26;
	num_river = 12;
	num_brush = 8;
	num_sodwall = 120;

	steewall = new SteeWall[num_stee];
	river = new River[num_river];
	brush = new Brush[num_brush];
	sodwall = new SodWall[num_sodwall];

	int i;

	//��ͼ�·���һ����ǽ
	_x = 0;
	_y = 13;
	for (i = 0; i < 20; i++)
	{
		steewall[i].SetXY({ _x,_y });                     //���õ�������
		MT[_x][_y] = steewall[i].GetMapTerrain();           //���õ�������
		_x++;
	}

	//��ͼ�м����ǽ
	_x = 7;
	_y = 7;
	for (i = 20; i < num_stee; i++)
	{
		steewall[i].SetXY({ _x,_y });                     //���õ�������
		MT[_x][_y] = steewall[i].GetMapTerrain();           //���õ�������
		_x++;
	}

	//�������к���
	_x = 1;
	_y = 5;
	for (i = 0; i < num_river; i++)
	{
		river[i].SetXY({ _x,_y });                     //���õ�������
		MT[_x][_y] = river[i].GetMapTerrain();           //���õ�������
		_x++;
		if (i == 4)
			_x += 8;
		if (i == 9)
		{
			_x = 9;
			_y++;
		}
	}

	//�������й�ľ
	_x = 8;
	_y = 3;
	for (i = 0; i < num_brush; i++)
	{
		brush[i].SetXY({ _x,_y });                     //���õ�������
		MT[_x][_y] = brush[i].GetMapTerrain();           //���õ�������
		_x++;
		if (i == 3)
		{
			_x = 6;
			_y = 7;
		}
		if (i == 4||i==6)
			_x = 13;
		if (i == 5)
		{
			_x = 6;
			_y = 11;
		}
	}

	//�������е���ǽ
	_x = 0;
	_y = 0;
	for (i = 0; i <18; ++i)
	{
		sodwall[i].SetXY({ _x,_y });                     //���õ�������
		MT[_x][_y] = sodwall[i].GetMapTerrain();           //���õ�������
		++_x;
		if (i == 5)
		{
			++_x;
			++_y;
		}
		if (i == 11)
		{
			++_x;
			--_y;
		}


	}



	///////////////����ǽ///////////////////////
	//testwall.SetXY({ 3,4 });
	//MT[3][4] = testwall.GetMapTerrain();
	////////////////////////////////////////
}

const void Map::PrintMap_1()
{
	int i;
	for ( i = 0; i < num_stee; i++)
		steewall[i].Print();
	for (i = 0; i < num_river; i++)
		river[i].Print();
	for (i = 0; i < num_brush; i++)
		brush[i].Print();
}

const void Map::PrintMap_2()
{
	int i;
	for (i = 0; i < 18; i++)
		sodwall[i].Print();
	home.Print();
}
