#pragma once
#include "Player.h"
#include <string>

using namespace std;

class ProfessionalPlayer : public Player
{
	float baseWage;

public:
	ProfessionalPlayer(const string& name, float baseWage);
	float goalsAverage();
	float wage();
};