#pragma once
#include <vector>
using namespace std;

class NodeLayer
{
	float(*ActFunct)(float);
	int index;
	float bias;
	NodeLayer * Layers;
	vector<vector<float>> weights;
	vector<float> nodes;
	/*
	may use error vector to allow 
	comunication of errors beyween layers
	*/

public:
	NodeLayer();

	void SetBias(float num);

	void setLayerRef(vector<NodeLayer> * Lyrs);

	void setActFunct(float(*AFunct)(float));

	void setNodes(vector<float> vals);

	void resizeLayer(int num);

	vector<float> getNodes();

	void forwardProp();

	void backProp(vector<float> CorrectOutputs);

	~NodeLayer();
};

