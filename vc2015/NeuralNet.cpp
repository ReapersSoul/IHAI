#include "NeuralNet.h"



NeuralNet::NeuralNet(int inputSize,int outputsize, int LCount, int LSize, float(*AFunct)(float))
{
	srand(time(0));

	ActFunct = AFunct;
	LayerSize = LSize;

	Inputs.resizeLayer(inputSize);

	nodes.resize(LCount);
	for (int i = 0; i < LCount;i++) {
		nodes[i].resizeLayer(LayerSize);
	}

	Outputs.resizeLayer(outputsize);

	//weights setup

}

NeuralNet::NeuralNet()
{
}


NeuralNet::~NeuralNet()
{
}

void NeuralNet::setinputs(vector<float> inputs)
{
	Inputs.setNodes(inputs);
}

void NeuralNet::setOutputSize(int num)
{
	Outputs.resizeLayer(num);
}

void NeuralNet::setLayerCount(int num)
{
	nodes.resize(num);
	for (int i = 0; i < nodes.size(); i++) {
		nodes[i].resizeLayer(LayerSize);
	}

	//weights reset

}

void NeuralNet::setLayerSize(int num)
{
	LayerSize = num;
	for (int i = 0; i < nodes.size(); i++) {
		nodes[i].resizeLayer(num);
	}
	//weights reset
	
}

void NeuralNet::setActFunct(float(*AFunct)(float))
{
	ActFunct = AFunct;
}

void NeuralNet::train(vector<vector<float>> inputs, vector<vector<float>> CorrectOutputs,int itterations)
{
	for (int i = 0; i < itterations; i++) {
		//setup
		Inputs.setNodes(inputs[i]);
		Outputs.resizeLayer(CorrectOutputs[i].size());
		//forward propigation
		nodes[0].setNodes(Inputs.forwardProp());
		for (int j = 1; j < nodes.size(); j++) {
			nodes[j].setNodes(nodes[j - 1].forwardProp());
		}
		Outputs.setNodes(nodes[nodes.size()].forwardProp());
		//back propigation

	}
}

void NeuralNet::Run()
{
}

vector<float> NeuralNet::getOutputs()
{
	return Outputs.getNodes();
}

float randrange(float min, float max)
{
	return min + (rand() * (float)(max - min) / RAND_MAX);
}

double randrange(double min, double max)
{
	return min + (rand() * (double)(max - min) / RAND_MAX);
}

int randrange(int min, int max)
{
	return min + (rand() * (int)(max - min) / RAND_MAX);
}