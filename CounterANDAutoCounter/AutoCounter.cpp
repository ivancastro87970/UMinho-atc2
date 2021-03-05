#include "AutoCounter.h"
#include "Counter.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath> //<math.h>

using namespace std;

AutoCounter::AutoCounter(size_t limit, bool up, bool autoreload) : up(up), autoreload(autoreload), limit(up?limit:0), counter(up?0:limit)
{
	/*this->limit = limit;
	this->up = up;
	this->autoreload = autoreload;*/
}

bool AutoCounter::count()
{
	if (!autoreload && limit == counter.value()) // se não houver auto reload e se o valor do counter for igual ao limit
	{
		return false;
	}

	if (autoreload && limit == counter.value()) // se houver auto reload e se o valor do counter for igual ao limit
	{
		reset();
	}

	if (up)
		counter.incr();
	else 
		counter.dec();

	return true;
}

size_t AutoCounter::value()
{
	return counter.value();
}

void AutoCounter::reset()
{
	counter.reset();
}
