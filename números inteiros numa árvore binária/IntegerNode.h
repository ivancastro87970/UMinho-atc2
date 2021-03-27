#pragma once
#include<vector>

using namespace std;


class IntegerNode
{
	int i; // key
	IntegerNode* left;
	IntegerNode* right;
public:
	IntegerNode(int i);
	size_t add(IntegerNode* n);
	bool contains(int i);
	void inOrder(vector<int>& elements);
};