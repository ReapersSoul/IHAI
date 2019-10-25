#include "NodeLayer.h"



NodeLayer::NodeLayer()
{

}

void NodeLayer::setIndex(int i)
{
	index = i;
}

void NodeLayer::SetBias(float num)
{
	bias = num;
}


void NodeLayer::setLayerRef(vector<NodeLayer> Lyrs)
{
	for (int i = 0; i < Lyrs.size(); i++) {
		Layers[i] = Lyrs[i];
	}
}

void NodeLayer::setActFunct(float(*AFunct)(float))
{
}

void NodeLayer::setNodes(vector<float> vals)
{
	nodes = vals;
}

void NodeLayer::resizeLayer(int num)
{
	nodes.resize(num);
}

vector<float> NodeLayer::getNodes()
{
	return nodes;
}

int NodeLayer::getSize(){
	return nodes.size();
}

vector<float> NodeLayer::forwardProp()
{
vector<float> tmp;
	for (int i = 0; i < nodes.size(); i++) {
		float tmpval = 0;
		for (int j = 0; j < Layers[index + 1].nodes.size(); j++) {
			tmpval += (weights[i][j] * nodes[i] + bias);
		}
		tmp.push_back(tmpval);
	}
return tmp;
}

void NodeLayer::backProp(vector<float> CorrectOutputs)
{
	if (index != 0) {
		for (int i = 0; i < CorrectOutputs.size(); i++) {
			float error = nodes[i] - CorrectOutputs[i];
			for (int j = 0; j < Layers[index - 1].getSize(); j++) {
				weights[j][i] = Layers[index - 1].weights[j][i] * error;
			}
		}
	}
}

NodeLayer::~NodeLayer()
{
}
