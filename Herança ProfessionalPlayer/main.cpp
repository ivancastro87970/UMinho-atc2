#include "Player.h"
#include "ProfessionalPlayer.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ProfessionalPlayer p1("ivan", 2000);
    p1.addGoals(3);
    p1.goals();
    p1.goalsAverage();
    p1.wage();
    p1.reset();

}