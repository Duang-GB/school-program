#pragma once
#include"main_game.h"
//=============================������===============================//
class Terrain
{
public:
	Terrain();
	~Terrain();
	const void PrintTerrain();       //��ӡ����
private:
	bool TankThrough;             //Tank�ܷ�Խ
	bool ShellThrough;            //�ڵ��ܷ�Խ
};
