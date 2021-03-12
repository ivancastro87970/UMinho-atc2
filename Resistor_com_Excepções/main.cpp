#include "Resistor.h"
#include <iostream>
using namespace std;

int main()
{
	float aux_in;
	cout << "Introduza o valor da resistencia:";
	cin >> aux_in;
	
	//Resistor r(aux_in);
	try 
	{
		Resistor r(aux_in);

		cout << "Introduza o valor da tensao a aplicar:";
		cin >> aux_in;
		cout <<"Corrente e': " << r.applyVoltage(aux_in)<< endl;
		
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl;
		return 1;
	}

	//cout <<  << r.getCurrent() << endl;
	return 0;
}