#include "Bone.h"


Bone::Bone()
{
	xRot = 0.0f;
	yRot = 0.0f;
	zRot = 0.0f;
	posX = 0;
	posY = 0;
	posZ = 0;
	HasParent = false;
	parent = -99;
}


Bone::~Bone()
{
}
