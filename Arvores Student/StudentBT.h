#pragma once
#include "StudentNode.h"

class StudentsBT 
{
    StudentNode* root;
    size_t _size;
public:
    StudentsBT();
    void add(const Student& a);
    const Student* find(size_t number);        // bool exists(const Student&);
    size_t size();
    vector<const Student*> inOrder();         // vector<Student> inOrder();
};