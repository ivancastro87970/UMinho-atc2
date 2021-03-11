#include "ProfessionalPlayer.h"
#include "Player.h"
#include <sstream>
#include <cmath>


ProfessionalPlayer::ProfessionalPlayer(const string& name, float baseWage)
	: Player(name), baseWage(baseWage)
{
}

float ProfessionalPlayer::goalsAverage()
{
	float med=0;

	med = (Player::goals()) / Player::matches();

	return med;
}

float ProfessionalPlayer::wage()
{
	float salario = 0;

	salario = baseWage + (goalsAverage() * 20);

	return salario;
}
