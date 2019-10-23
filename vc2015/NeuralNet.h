#pragma once
#include <vector>
#include <time.h>

float randrange(float min, float max);

using namespace std;
class NeuralNet
{
private:
	int LayerCount = 0;
	int LayerSize = 0;
	int InputSize = 0;
	int OutputSize = 0;

	float (*ActFunct)(float);
	vector<vector<vector<float>>> weights;
	float bias;
	vector<float>Inputs;
	vector<vector<float>> nodes;
	vector<float>Outputs;
public:
	void setinputs(vector<float> inputs);

	void setOutputSize(int num);

	//this function will reset the weights of the neural network to random you will have to retrain your network
	void setLayerCount(int num);
	//this function will reset the weights of the neural network to random you will have to retrain your network
	void setLayerSize(int num);
	//this function will not reset your weights
	void setActFunct(float(*AFunct)(float));
	//this function will change your weights to more accurate values
	void train(vector<vector<float>> inputs,vector<vector<float>> CorrectOutputs,int itterations);
	void Run();
	vector<float> getOutputs();

	NeuralNet(int inputSize, int outputsize, int LCount, int LSize, float(*AFunct)(float));
	NeuralNet();
	~NeuralNet();
};

