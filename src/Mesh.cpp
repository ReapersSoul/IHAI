#include "Mesh.h"

Mesh::Mesh()
{
}


Mesh::~Mesh()
{
}

void Mesh::LoadMesh(string FileName)
{
	ifstream InStream(FileName);
	string in;

	while (!InStream.eof()) {
		InStream >> in;
		if (in == "//") {
			do {
				InStream >> in;
			} while (in != "//");
		}
		else if (in == "BS") {
			Bone tmpbone;
			while (true) {
				InStream >> in;

				if (in == "//") {
					do {
						InStream >> in;
					} while (in != "//");
				}
				else if (in == "BE") {
					break;
				}
				else if (in == "HasParent") {
					InStream >> tmpbone.HasParent;
				}
				else if (in == "Parent") {
					InStream >> tmpbone.parent;
				}
				else if (in == "x") {
					InStream >> tmpbone.posX;
				}
				else if (in == "y") {
					InStream >> tmpbone.posY;
				}
				else if (in == "z") {
					InStream >> tmpbone.posZ;
				}
				else if (in == "xRot") {
					InStream >> tmpbone.xRot;
				}
				else if (in == "yRot") {
					InStream >> tmpbone.yRot;
				}
				else if (in == "zRot") {
					InStream >> tmpbone.zRot;
				}
				else {
					cerr << "unrecognized identifier in bone" << endl;
				}
			}
			bones.push_back(tmpbone);
		}
		else if (in == "VS") {
			Mesh_Point tempVert;
			while (true) {
				InStream >> in;

				if (in == "VE") {
					break;
				}
				else if (in == "//") {
					do {
						InStream >> in;
					} while (in != "//");
				}
				else if (in == "x") {
					InStream >> tempVert.posX;
				}
				else if (in == "y") {
					InStream >> tempVert.posY;
				}
				else if (in == "z") {
					InStream >> tempVert.posZ;
				}
				else if (in == "pain") {
					InStream >> tempVert.pain;
				}
				else if (in == "pleasure") {
					InStream >> tempVert.pleasure;
				}
				else if (in == "presure") {
					InStream >> tempVert.presure;
				}
				else if (in == "Parent_Bone") {
					InStream >> tempVert.Parent_Bone;
				}
				else if (in == "weight") {
					InStream >> tempVert.weight;
				}
				else {
					cerr << "unrecognized identifier in vertex" << endl;
				}
			}
			points.push_back(tempVert);
		}
		else if (in == "FS") {
			vector<int> tempFace;
			while (true) {
				InStream >> in;

				if (in == "FE") {
					break;
				}
				else if (in == "//") {
					do {
						InStream >> in;
					} while (in != "//");
				}
				else if (in == "Pindex") {
					int tmpint = 0;
					InStream >> tmpint;
					tempFace.push_back(tmpint);
				}
				else {
					cerr << "unrecognized identifier in face" << endl;
				}

			}
			faces.push_back(tempFace);
		}
		else {
		cerr << "unrecognized identifier in file" << endl;
		}
	}
	return;
}

bool Mesh::SaveMesh(string FileName)
{
	ofstream ofs(FileName + ".aobj");
	for (int i = 0; i < points.size(); i++) {
		ofs <<"mp " << points[i].posX << " " << points[i].posY << " " << points[i].posZ << " " << points[i].pain << " " << points[i].pleasure << " " << points[i].presure << " " << points[i].weight << " " << points[i].Parent_Bone << endl;
	}
	for (int i = 0; i < faces.size(); i++) {
		ofs << "f ";
		for (int j = 0; j < faces[i].size(); j++) {
			ofs << faces[i][j] << " ";
		}
		ofs << endl;
	}
	for (int i = 0; i < bones.size(); i++) {
		ofs << "B " << bones[i].xRot << " " << bones[i].yRot << " " << bones[i].zRot << " " << bones[i].posX << " " << bones[i].posY << " " << bones[i].posZ << " " << bones[i].HasParent << " " << bones[i].parent << endl;
	}
	return true;
}

void Mesh::CreateBone()
{
	//create bone
}

void Mesh::DrawBone()
{
	//drawbone
}

void Mesh::DrawMesh()
{
	//draw mesh
}

float distFunct(int x, int y, int z, int x2, int y2, int z2)
{
	return pow((pow((x2 - x), 2) + pow((y2 - y), 2) + pow((z2 - z), 2)), .5);
}
