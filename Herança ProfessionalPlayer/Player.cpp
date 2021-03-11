#include "Player.h"
#include <string>

Player::Player(const string& name) : name(name), _matches(0), _goals(0)
{
}

void Player::addMatch()
{
	++_matches;
}

size_t Player::addGoals(size_t goals)
{
	_goals += goals;
	return _goals;
}
size_t Player::goals()
{
	return _goals;
}

size_t Player::matches()
{
	return _matches;
}

void Player::reset()
{
	_matches = 0;
	_goals = 0;
}
