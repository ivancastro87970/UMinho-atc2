#pragma once
#include "Counter.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath> //<math.h>

using namespace std;

class AutoCounter
{
	Counter counter;
	size_t limit;
	bool up; 
	bool autoreload;

public:
	AutoCounter(size_t limit, bool up, bool autoreload);
	bool count();
	size_t value(); 
	void reset();
};