#include "Human.h"


Human::Human()
{
	srand(time(0));
	hunger = 0.0f;
	air = 100.0f;
	water = 100.0f;
	health = 100.0f;
	digestion = 0.0f;
	FertilityResetCountDown = 0.0f;
	Fertile = true;
	sex = randrange(0, 1);
}


Human::~Human()
{
}

float ActFunct(float val)
{
	return 0.0f;
}


void Human::run()
{
	// write step here.
	vector<float> input;
	input.push_back(hunger);
	input.push_back(air);
	input.push_back(water);
	input.push_back(health);
	input.push_back(digestion);
	input.push_back(FertilityResetCountDown);
	input.push_back(Fertile);
	input.push_back(sex);
	input.push_back(emotions.acceptance);
	input.push_back(emotions.admiration);
	input.push_back(emotions.amazement);
	input.push_back(emotions.anger);
	input.push_back(emotions.annoyance);
	input.push_back(emotions.anticipation);
	input.push_back(emotions.apprehension);
	input.push_back(emotions.boredom);
	input.push_back(emotions.disgust);
	input.push_back(emotions.distraction);
	input.push_back(emotions.ecstasy);
	input.push_back(emotions.fear);
	input.push_back(emotions.greif);
	input.push_back(emotions.intrest);
	input.push_back(emotions.joy);
	input.push_back(emotions.loathing);
	input.push_back(emotions.pensiveness);
	input.push_back(emotions.rage);
	input.push_back(emotions.sadness);
	input.push_back(emotions.serenity);
	input.push_back(emotions.surprise);
	input.push_back(emotions.terror);
	input.push_back(emotions.trust);
	input.push_back(emotions.vigilance);
	for (int i = 0; i < mesh.points.size(); i++) {
		input.push_back(mesh.points[i].pain);
		input.push_back(mesh.points[i].presure);
		input.push_back(mesh.points[i].pleasure);
		input.push_back(mesh.points[i].Parent_Bone);
	}
	for (int i = 0; i < mesh.bones.size(); i++) {
		input.push_back(mesh.bones[i].HasParent);
		input.push_back(mesh.bones[i].parent);
		input.push_back(mesh.bones[i].posX);
		input.push_back(mesh.bones[i].posY);
		input.push_back(mesh.bones[i].posZ);
		input.push_back(mesh.bones[i].xRot);
		input.push_back(mesh.bones[i].yRot);
		input.push_back(mesh.bones[i].zRot);
	}

	brain.setinputs(input);
	brain.setOutputSize(input.size());
	brain.setActFunct(ActFunct);
	brain.setLayerCount(3);
	brain.setLayerSize(15);

	brain.Run();

	vector<float> outs;

	outs = brain.getOutputs();

	for (int i = 0; i < outs.size(); i++) {
		CI_LOG_D(outs[i]);
	}
}
