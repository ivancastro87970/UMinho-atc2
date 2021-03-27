#include "IntegersBT.h"
#include "IntegerNode.h"

IntegersBT::IntegersBT()
{
	root = nullptr;
	_size = 0;
}

void IntegersBT::add(int i)
{
	IntegerNode* b = new IntegerNode(i);
	_size++;
	if (!root)
		root = b;
	else
		root->add(b);
}

bool IntegersBT::contains(int i)
{
	if (!root)
		return false;
	return root->contains(i);
}

size_t IntegersBT::size()
{
	return _size;
}

vector<int> IntegersBT::inOrder()
{
	vector<int> vetore;
	if (root)
		root->inOrder(vetore);
	return vetore;
}

size_t IntegersBT::height()
{
}
