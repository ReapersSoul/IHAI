#pragma once
class Bone
{
public:
	Bone();
	~Bone();
	int parent;
	float xRot;
	float yRot;
	float zRot;
	int posX;
	int posY;
	int posZ;
	bool HasParent;
};

