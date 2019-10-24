#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <math.h>

#include "Mesh_Point.h"
using namespace std;

float distFunct(int x, int y, int z, int x2, int y2, int z2);

class Mesh
{
public:
	Mesh();
	~Mesh();
	vector<Mesh_Point> points;
	vector<vector<int>> faces;
	vector<Bone> bones;
	void LoadMesh(string FileName);
	bool SaveMesh(string FileName);
	void CreateBone();
	void DrawBone();
	void DrawMesh();
};

