#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath> //<math.h>

using namespace std;


class Counter
{
	size_t count;
	size_t start;

public:
	Counter(); // construtor default
	Counter(size_t start);
	void incr();
	void dec();
	void reset();
	size_t value(); //	readOnly
};