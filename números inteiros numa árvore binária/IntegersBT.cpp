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
	/*
	/*else
	{
		size_t vai_left, vai_right;
		vai_left = height(root.left);
		vai_right = height(root.right);
		if (vai_left > vai_right)
			return vai_left + 1;
		else
			return vai_right + 1;
	}*/
	/*vector<IntegersBT*> queue1;

	queue1.push_back(root);
	size_t height = 0;

	while (1)
	{
		int node_count = queue1.size();
		if (node_count == 0)
			return height;

		height++;
		while (node_count > 0)
		{
			IntegersBT* node = queue1.front();
			queue1.pop_back();
			if (node->left != NULL)
				queue1.push_back(node->left);
			if (node->right != NULL)
				queue1.push_back(node->right);
			node_count --;
		}
	}*/
}
