#include "IntegersBT.h"
#include "IntegerNode.h"

IntegersBT::IntegersBT() : root(nullptr), _size(0), _height(0)
{
}

void IntegersBT::add(int i)
{
	IntegerNode* b = new IntegerNode(i);
	_size++;
	if (!root)
		root = b;
	else
	{
		size_t altura = root->add(b);
		if (altura > _height)
			_height++;
	}
		
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
	return _height;
}