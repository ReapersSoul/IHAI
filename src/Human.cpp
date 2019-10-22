#include "Human.h"


Human::Human()
{
	hunger = 0.0f;
	air = 0.0f;
	water = 0.0f;
	health = 0.0f;
	digestion = 0.0f;
	FertilityResetCountDown = 0.0f;
	Fertile = true;
}


Human::~Human()
{
}


void Human::run()
{
	// write step here.
}
