#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath> //<math.h>

using namespace std; 
#include "Counter.h"

Counter::Counter(size_t start) : start(start), count(start)
{
	/*this->start = start;*/
}

void Counter::incr()
{
	count++;
}

void Counter::dec()
{
	count--;
}

void Counter::reset()
{
	count = start; // ou count = 0?
}

size_t Counter::value()
{
	return count;
}