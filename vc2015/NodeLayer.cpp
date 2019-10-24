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

void NodeLayer::forwardProp()
{
	for (int i = 0; i < nodes.size;i++) {
		float tmpval=0;
		for (int j = 0; j < Layers[index - 1].nodes.size(); j++) {
			tmpval += (weights[i][j] * Layers[index - 1].nodes[j]+bias);
		}
		nodes[i] = tmpval;
	}
}

NodeLayer::~NodeLayer()
{
}
