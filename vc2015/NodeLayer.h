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

	void setIndex(int i);

	void SetBias(float num);

	void setLayerRef(vector<NodeLayer>  Lyrs);

	void setActFunct(float(*AFunct)(float));

	void setNodes(vector<float> vals);

	void setWeights(vector<vector<float>> wts);

	void resizeLayer(int num);

	vector<float> getNodes();

	int getSize();

	vector<float> forwardProp(NodeLayer NL);

	vector<vector<float>> backProp(NodeLayer NL,vector<float> CorrectOutputs);

	~NodeLayer();
};
