#pragma once
#include <string>
#include <vector>
using namespace std;

struct Student 
{
    size_t number;
    string name;
};

class StudentNode 
{
    StudentNode* left, * right;
    Student a;
public:
    StudentNode(const Student& a);
    void add(StudentNode* n);
    const Student* find(size_t number);        // bool exists(const Student&);
    void inOrder(vector<const Student*>& elements);
};