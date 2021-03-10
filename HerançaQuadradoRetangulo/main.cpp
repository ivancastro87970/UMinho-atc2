#include <iostream>
#include "Rectangle.h"
#include "Square.h"

using namespace std;

int main()
{
	Rectangle r(2, 4);
	cout << "r: " << r.toString() << endl;
	cout << "r area: " << r.area() << endl;
	cout << "r perimeter: " << r.perimeter() << endl;

	Square s(3);
	cout << "s: " << s.toString() << endl;
	cout << "s area: " << s.area() << endl;
	cout << "s perimeter: " << s.perimeter() << endl;


	return 0;
}