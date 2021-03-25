#include "StudentNode.h"

#include <stdexcept>
using namespace std;

StudentNode::StudentNode(const Student& a)
    : left(nullptr), right(nullptr), a(a)
{ }


void StudentNode::add(StudentNode* n) {                        // void add(const Student& a);
    if (n->a.number < a.number) {
        if (!left)
            left = n;
        else
            left->add(n);
    }
    else if (n->a.number > a.number)
        if (!right)
            right = n;
        else
            right->add(n);
    else
        throw invalid_argument("A student with number " +
            to_string(a.number) + " already exists!");
}


const Student* StudentNode::find(size_t number) {        // bool exists(const Student&);
    if (number < a.number) {
        if (left)
            return left->find(number);
    }
    else if (number > a.number) {
        if (right)
            return right->find(number);
    }
    else
        return &a;
    return nullptr;
}


void StudentNode::inOrder(vector<const Student*>& elements) {
    if (left)
        left->inOrder(elements);
    elements.push_back(&a);
    if (right)
        right->inOrder(elements);
}