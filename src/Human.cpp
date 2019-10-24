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


void Human::run()
{
	// write step here.
}
