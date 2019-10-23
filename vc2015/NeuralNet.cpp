#include "NeuralNet.h"



NeuralNet::NeuralNet(int inputSize,int outputsize, int LCount, int LSize, void(*AFunct)(float))
{
	srand(time(0));

	ActFunct = AFunct;
	InputSize = inputSize;
	OutputSize = outputsize;
	LayerCount = LCount;
	LayerSize = LSize;

	inputs.resize(InputSize);

	nodes.resize(LayerCount);
	for (int i = 0; i < LayerCount;i++) {
		nodes[i].resize(LayerSize);
	}

	outputs.resize(OutputSize);

	weights.resize(LCount + 2);

	weights[0].resize(InputSize*nodes[0].size());

	for (int i = 1; i < (LCount - 1); i++) {
		weights.resize(nodes[i-1].size()*nodes[i].size());
	}

	weights[weights.size()].resize(nodes[nodes.size()].size()*outputs.size());

	for (int i = 0; i < weights.size(); i++) {
		for (int j = 0; j < weights[i].size(); j++) {
			weights[i][j]= randrange(-1,1);
		}
	}

}

NeuralNet::NeuralNet()
{
}


NeuralNet::~NeuralNet()
{
}

void NeuralNet::setinputs(vector<float> inputs)
{
}

void NeuralNet::setLayerCount(int num)
{
}

void NeuralNet::setLayerSize(int num)
{
}

void NeuralNet::setActFunct(void(*AFunct)(float))
{
}

void NeuralNet::train(vector<vector<float>> inputs, vector<vector<float>> CorrectOutputs)
{
}

void NeuralNet::Run()
{
}

vector<float> NeuralNet::getOutputs()
{
	return vector<float>();
}

float randrange(float min, float max)
{
	return min + (rand() * (float)(max - min) / RAND_MAX);
}
