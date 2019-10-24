#include "NodeLayer.h"



NodeLayer::NodeLayer()
{

}

void NodeLayer::SetBias(float num)
{
	bias = num;
}


void NodeLayer::setLayerRef(vector<NodeLayer>* Lyrs)
{
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

vector<float> NodeLayer::forwardProp()
{
vector<float> tmp;
	for (int i = 0; i < nodes.size(); i++) {
		float tmpval = 0;
		for (int j = 0; j < Layers[index + 1].nodes.size(); j++) {
			tmpval += (weights[i][j] * nodes[i] + bias);
		}
		tmp.pushback(tmpval);
	}
return tmp;
}

void NodeLayer::backProp(vector<float> CorrectOutputs)
{
	for(int i=0; i<CorrectOutputs.size();i++){
		
	}
}

NodeLayer::~NodeLayer()
{
}
