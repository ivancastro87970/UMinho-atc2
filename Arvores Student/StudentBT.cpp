#include "StudentBT.h"


StudentsBT::StudentsBT() {
    root = nullptr;
    _size = 0;
}


void StudentsBT::add(const Student& a) {
    StudentNode* n = new StudentNode(a);
    _size++;
    if (!root)
        root = n;
    else
        root->add(n);
}


const Student* StudentsBT::find(size_t number) {        // bool exists(const Student&);
    if (!root)
        return nullptr;
    return root->find(number);
}


size_t StudentsBT::size() {
    return _size;
}


vector<const Student*> StudentsBT::inOrder() {            // vector<Student> inOrder();
    vector<const Student*> elements;
    if (root)
        root->inOrder(elements);
    return elements;
}