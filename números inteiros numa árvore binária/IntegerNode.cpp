#include "IntegerNode.h"
#include "IntegersBT.h"
#include<iostream>

using namespace std;

IntegerNode::IntegerNode(int i)
    :i(i), left(nullptr), right(nullptr)
{
}

size_t IntegerNode::add(IntegerNode* n)
{
    if (n->i <= i)
    {
        if (!left)
            left = n;
        else
            left->add(n);
    }
    else 
        if (!right)
            right = n;
        else
            right->add(n);
}

bool IntegerNode::contains(int i)
{
    if (i < this->i) {
        if (left)
            return left->contains(i);
    }
    else if (i > this->i) {
        if (right)
            return right->contains(i);
    }
    else
        return true;
    return false;
}

void IntegerNode::inOrder(vector<int>& elements)
{
    if (left)
        left->inOrder(elements);
    elements.push_back(i);
    if (right)
        right->inOrder(elements);
}
