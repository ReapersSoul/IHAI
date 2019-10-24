#include "Human.h"


Human::Human()
{
	srand(time(0));
	hunger = 0.0f;
	air = 0.0f;
	water = 0.0f;
	health = 0.0f;
	digestion = 0.0f;
	FertilityResetCountDown = 0.0f;
	Fertile = true;
	sex = randrange(0, 1);
}


Human::~Human()
{
}


void Human::run()
{
	// write step here.
}
