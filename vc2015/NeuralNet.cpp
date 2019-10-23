#include "NeuralNet.h"



NeuralNet::NeuralNet(int inputSize,int outputsize, int LCount, int LSize, void(*AFunct)(float))
{
	srand(time(0));

	ActFunct = AFunct;
	InputSize = inputSize;
	OutputSize = outputsize;
	LayerCount = LCount;
	LayerSize = LSize;

	Inputs.resize(InputSize);

	nodes.resize(LayerCount);
	for (int i = 0; i < LayerCount;i++) {
		nodes[i].resize(LayerSize);
	}

	Outputs.resize(OutputSize);

	weights.resize(LayerCount + 2);

	weights[0].resize(InputSize*nodes[0].size());

	for (int i = 1; i < (LayerCount - 1); i++) {
		weights.resize(nodes[i-1].size()*nodes[i].size());
	}

	weights[weights.size()].resize(nodes[nodes.size()].size()*Outputs.size());

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
	InputSize = inputs.size();
	Inputs = inputs;
}

void NeuralNet::setLayerCount(int num)
{
	LayerCount = num;
	nodes.resize(num);
	for (int i = 0; i < LayerCount; i++) {
		nodes[i].resize(LayerSize);
	}

	//weights reset
	weights.resize(LayerCount + 2);

	weights[0].resize(InputSize*nodes[0].size());

	for (int i = 1; i < (LayerCount - 1); i++) {
		weights.resize(nodes[i - 1].size()*nodes[i].size());
	}

	weights[weights.size()].resize(nodes[nodes.size()].size()*Outputs.size());

	for (int i = 0; i < weights.size(); i++) {
		for (int j = 0; j < weights[i].size(); j++) {
			weights[i][j] = randrange(-1, 1);
		}
	}

}

void NeuralNet::setLayerSize(int num)
{
	for (int i = 0; i < LayerCount; i++) {
		nodes[i].resize(num);
	}
	//weights reset
	weights.resize(LayerCount + 2);

	weights[0].resize(InputSize*nodes[0].size());

	for (int i = 1; i < (LayerCount - 1); i++) {
		weights.resize(nodes[i - 1].size()*nodes[i].size());
	}

	weights[weights.size()].resize(nodes[nodes.size()].size()*Outputs.size());

	for (int i = 0; i < weights.size(); i++) {
		for (int j = 0; j < weights[i].size(); j++) {
			weights[i][j] = randrange(-1, 1);
		}
	}
}

void NeuralNet::setActFunct(void(*AFunct)(float))
{
	ActFunct = AFunct;
}

void NeuralNet::train(vector<vector<float>> inputs, vector<vector<float>> CorrectOutputs)
{
}

void NeuralNet::Run()
{
}

vector<float> NeuralNet::getOutputs()
{
	return Outputs;
}

float randrange(float min, float max)
{
	return min + (rand() * (float)(max - min) / RAND_MAX);
}
