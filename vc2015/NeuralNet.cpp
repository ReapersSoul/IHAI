#include "NeuralNet.h"



NeuralNet::NeuralNet(int inputSize,int outputsize, int LCount, int LSize, float(*AFunct)(float))
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

	//weights setup

	weights.resize(LayerCount + 2);

	weights[0].resize(InputSize);

	for (int j = 0; j < weights[0].size(); j++) {
		weights[0][j].resize(nodes[0].size());
	}

	for (int i = 1; i < weights.size(); i++) {
		weights[i].resize(nodes[i-1].size());
		for (int j = 0; j < weights[i].size(); j++) {
			weights[i][j].resize(nodes[i].size());
		}
	}

	weights[weights.size()].resize(nodes[nodes.size()].size());

	for (int j = 0; j < weights[weights.size()].size(); j++) {
		weights[weights.size()][j].resize(OutputSize);
	}

	for (int i = 0; i < weights.size(); i++) {
		for (int j = 0; j < weights[i].size(); j++) {
			for (int l = 0; l < weights[i][j].size(); l++) {
				weights[i][j][l] = randrange(-1, 1);
			}
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

void NeuralNet::setOutputSize(int num)
{
	OutputSize = num;
	Outputs.resize(OutputSize);
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

	weights[0].resize(InputSize);

	for (int j = 0; j < weights[0].size(); j++) {
		weights[0][j].resize(nodes[0].size());
	}

	for (int i = 1; i < weights.size(); i++) {
		weights[i].resize(nodes[i - 1].size());
		for (int j = 0; j < weights[i].size(); j++) {
			weights[i][j].resize(nodes[i].size());
		}
	}

	weights[weights.size()].resize(nodes[nodes.size()].size());

	for (int j = 0; j < weights[weights.size()].size(); j++) {
		weights[weights.size()][j].resize(OutputSize);
	}

	for (int i = 0; i < weights.size(); i++) {
		for (int j = 0; j < weights[i].size(); j++) {
			for (int l = 0; l < weights[i][j].size(); l++) {
				weights[i][j][l] = randrange(-1, 1);
			}
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

	weights[0].resize(InputSize);

	for (int j = 0; j < weights[0].size(); j++) {
		weights[0][j].resize(nodes[0].size());
	}

	for (int i = 1; i < weights.size(); i++) {
		weights[i].resize(nodes[i - 1].size());
		for (int j = 0; j < weights[i].size(); j++) {
			weights[i][j].resize(nodes[i].size());
		}
	}

	weights[weights.size()].resize(nodes[nodes.size()].size());

	for (int j = 0; j < weights[weights.size()].size(); j++) {
		weights[weights.size()][j].resize(OutputSize);
	}

	for (int i = 0; i < weights.size(); i++) {
		for (int j = 0; j < weights[i].size(); j++) {
			for (int l = 0; l < weights[i][j].size(); l++) {
				weights[i][j][l] = randrange(-1, 1);
			}
		}
	}
}

void NeuralNet::setActFunct(float(*AFunct)(float))
{
	ActFunct = AFunct;
}

void NeuralNet::train(vector<vector<float>> inputs, vector<vector<float>> CorrectOutputs,int itterations)
{
	for (int i = 0; i < itterations; i++) {
		for (int j = 0; j < inputs.size(); j++) {

			InputSize = inputs[j].size();
			Inputs = inputs[j];
			
			//inputs
			for (int x = 0; x < InputSize; x++) {
				for (int y = 0; y < nodes[0].size(); y++) {
					nodes[0][y]= ActFunct(weights[0][x][y]*Inputs[x] + bias);
				}
			}
			//nodes
			for (int x = 1; x < nodes.size() - 1; x++) {
				
				for (int y = 0; y < nodes[x+1].size(); y++) {
					float tmpval = 0;
					for (int z = 0; z < nodes[x].size(); z++) {
						tmpval += (nodes[x][z] * weights[x][y][z] + bias);
					}

				}
			}
			//outputs
			for (int x = 0; x < nodes[nodes.size()].size(); x++) {
				for (int y = 0; y < OutputSize; y++) {
					Outputs[y] = ActFunct(weights[weights.size()][x][y] * nodes[nodes.size()][x] + bias);
				}
			}

		}
	}
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
