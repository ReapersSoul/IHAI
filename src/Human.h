#pragma once
#include "Mesh.h"
#include "emotion.h"
using namespace std;

class Human
{
public:
	Human();
	~Human();
	vector<void*> LT_MEM;
	vector<void*> ST_MEM;
	float hunger;
	float air;
	float water;
	float health;
	float digestion;
	float FertilityResetCountDown;
	bool Fertile;
	string meshpath;
	Mesh mesh;

	void run();
	emotion emotions;
};

