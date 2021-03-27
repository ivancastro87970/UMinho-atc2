#pragma once
#include <string>
#include "IntegerNode.h"

using namespace std;

class IntegersBT 
{
	size_t _size;
	size_t _height;
	IntegerNode* root;
public:
	IntegersBT();
	void add(int i);
	bool contains(int i);
	size_t size();
	vector<int>inOrder();
	size_t height();
};