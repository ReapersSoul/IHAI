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

void setWeights(vector<vector<float>> wts){
	for(int i=0; i<weights.size();i++){
		for (int j = 0; j < weights[i]; j++) {
			weights[i][j]=wts[i][j];
		}
	}
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

vector<float> NodeLayer::forwardProp(NodeLayer NL)
{
vector<float> tmp;
	for (int i = 0; i < nodes.size(); i++) {
		float tmpval = 0;
		for (int j = 0; j < NL.nodes.size(); j++) {
			tmpval += (weights[i][j] * nodes[i] + bias);
		}
		tmp.push_back(tmpval);
	}
return tmp;
}

vector<vector<float>> NodeLayer::backProp(NodeLayer NL,vector<float> CorrectOutputs)
{
	vector<vector<float>> RTRNWeights;
		for (int i = 0; i < CorrectOutputs.size(); i++) {
			float error = nodes[i] - CorrectOutputs[i];
			for (int j = 0; j < NL.getSize(); j++) {
				RTRNWeights[j][i] = NL.weights[j][i] * error;
			}
		}
		return RTRNWeights;
}

NodeLayer::~NodeLayer()
{
}
