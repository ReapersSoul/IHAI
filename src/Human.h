#pragma once
#include "Mesh.h"
#include "emotion.h"
#include "../vc2015/NeuralNet.h"
#include <time.h>
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
	bool sex;
	string meshpath;
	Mesh mesh;

	void run();
	emotion emotions;
};