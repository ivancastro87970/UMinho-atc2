#include "StudentBT.h"

#include <iostream>
using namespace std;


int main()
{
    StudentsBT bt;
    bt.add({ 1, "Maria" });
    bt.add({ 2, "Jose" });
    //bt.remove(1);

    const Student* s = bt.find(2);
    vector<const Student*> elements = bt.inOrder();
    for (const Student* s : elements) {
        cout << s->number << ", " << s->name << endl;
    }
}