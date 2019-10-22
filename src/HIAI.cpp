// HIAI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include "Mesh.h"

wchar_t *CharToLPCWSTR(const char* charArray)
{
	wchar_t* wString = new wchar_t[4096];
	MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
	return wString;
}

Mesh ml;

int main()
{
	//MessageBox(NULL, CharToLPCWSTR("Hello World!"), CharToLPCWSTR("My first windows app"), NULL);

	ml.LoadMesh("C:/Users/Trevor/Desktop/testfile.ALobj");
	for (int i = 0; i < ml.bones.size(); i++) {
		cout << "bone #" << i << ": "<<endl;
		cout << ml.bones[i].posX << endl;
		cout << ml.bones[i].posY << endl;
		cout << ml.bones[i].posZ << endl;
		cout << ml.bones[i].xRot << endl;
		cout << ml.bones[i].yRot<< endl;
		cout << ml.bones[i].zRot << endl;
		cout << ml.bones[i].HasParent << endl;
		cout << ml.bones[i].parent << endl;
	}
	for (int i = 0; i < ml.points.size(); i++) {
		cout << "living point #" << i << ": " << endl;
		cout << ml.points[i].posX << endl;
		cout << ml.points[i].posY << endl;
		cout << ml.points[i].posZ << endl;
		cout << ml.points[i].pain << endl;
		cout << ml.points[i].pleasure << endl;
		cout << ml.points[i].presure << endl;
		cout << ml.points[i].Parent_Bone << endl;
		cout << ml.points[i].weight << endl;
	}
	for (int i = 0; i < ml.faces.size(); i++) {
		cout << "face #" << i << ": ";
		for (int j = 0; j < ml.faces[i].size(); j++) {
			cout << ml.faces[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
}
