#pragma once
#include <vector>
#include <time.h>

float randrange(float min, float max);

using namespace std;
class NeuralNet
{
public:
	int LayerCount = 0;
	int LayerSize = 0;
	int InputSize = 0;
	int OutputSize = 0;

	void(*ActFunct)(float);
	vector<vector<float>> weights;
	vector<float>inputs;
	vector<vector<float>> nodes;
	vector<float>outputs;
	void setinputs(vector<float> inputs);
	void setLayerCount(int num);
	void setLayerSize(int num);
	void setActFunct(void(*AFunct)(float));
	void train(vector<vector<float>> inputs,vector<vector<float>> CorrectOutputs);
	void Run();
	vector<float> getOutputs();

	NeuralNet(int inputSize, int outputsize, int LCount, int LSize, void(*AFunct)(float));
	NeuralNet();
	~NeuralNet();
};

