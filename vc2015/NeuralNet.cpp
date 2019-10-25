#include "NeuralNet.h"



NeuralNet::NeuralNet(int inputSize,int outputsize, int LCount, int LSize, float(*AFunct)(float))
{
	srand(time(0));

	ActFunct = AFunct;
	LayerSize = LSize;

	Inputs.resizeLayer(inputSize);

	Layers.resize(LCount);
	for (int i = 0; i < LCount;i++) {
		Layers[i].resizeLayer(LayerSize);
	}

	Outputs.resizeLayer(outputsize);

	for (int i = 0; i < Layers.size(); i++) {
		Layers[i].setIndex(i);
	}

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
	Layers.resize(num);
	for (int i = 0; i < Layers.size(); i++) {
		Layers[i].resizeLayer(LayerSize);
	}

	//weights reset

}

void NeuralNet::setLayerSize(int num)
{
	LayerSize = num;
	for (int i = 0; i < Layers.size(); i++) {
		Layers[i].resizeLayer(num);
	}
	//weights reset

}

void NeuralNet::setActFunct(float(*AFunct)(float))
{
	ActFunct = AFunct;
}

void NeuralNet::train(vector<vector<float>> inputs, vector<vector<float>> CorrectOutputs, int itterations)
{
	for (int i = 0; i < itterations; i++) {
		//setup
		Inputs.setNodes(inputs[i]);
		Outputs.resizeLayer(CorrectOutputs[i].size());
		//forward propigation
		Layers[0].setNodes(Inputs.forwardProp(Layers[0]));
		for (int j = 1; j < Layers.size(); j++) {
			Layers[j].setNodes(Layers[j - 1].forwardProp(Layers[j]));
		}
		Outputs.setNodes(Layers[Layers.size()].forwardProp(Outputs));
		//back propigation

		vector<vector<float>> tempWeights;

		Outputs.backProp(Layers[Layers.size()], CorrectOutputs[i]);


		for (int j = Layers.size(); j > -1; j--) {
			vector<float> temp;
			temp = Layers[j].getNodes();
			Layers[j].setWeights(tempWeights);
			Layers[j].forwardProp(Layers[j + 1]);
			if (j != 0) {
				tempWeights = Layers[j].backProp(Layers[j - 1], temp);
			}
			else if (j = 0) {
				Inputs.setWeights(Layers[j].backProp(Inputs, temp));
			}

		}
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
