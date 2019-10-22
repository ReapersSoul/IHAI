#pragma once
#include <vector>
#include "Bone.h"
using namespace std;
class Mesh_Point
{
public:
	Mesh_Point();
	~Mesh_Point();
	float posX;
	float posY;
	float posZ;

	float pain;
	float pleasure;
	float presure;
	float weight;
	int Parent_Bone;
};

