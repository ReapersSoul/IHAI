#pragma once
#include <vector>
using namespace std;

class NodeLayer
{
	float(*ActFunct)(float);
	int index;
	float bias;
	vector<NodeLayer> & Layers;
	vector<vector<float>> weights;
	vector<float> nodes;
public:
	NodeLayer();

	void SetBias(float num);

	void setLayerRef(vector<NodeLayer> * Lyrs);

	void setActFunct(float(*AFunct)(float));

	void setNodes(vector<float> vals);

	void forwardProp();

	~NodeLayer();
};

