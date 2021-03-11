#pragma once
#include <string>

using namespace std;

class Player
{
	string name;
	size_t _matches;
	size_t _goals;

public:
	Player(const string& name);
	void addMatch();
	size_t addGoals(size_t goals);
	size_t goals();
	size_t matches();
	void reset();
};