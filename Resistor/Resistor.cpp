#include "Resistor.h"
#include <iostream>
#include <cmath>

Resistor::Resistor(float R, float Pmax) : R(R), Pmax(Pmax)
{
	voltage = 0;
	current = 0;
}

float Resistor::changeResistance(Color f1, Color f2, Multi multi)
{
	float div = (int)multi / 100.0;
	return (((int)f1 * 10 + (int)f2) * div);
}

Resistor::Resistor(Color f1, Color f2, Multi mul, float Pmax) : R(changeResistance(f1, f2, mul)), Pmax(0.25)
{
	voltage = 0;
	current = 0;
}

bool Resistor::applyVoltage(float volts)
{
	if (volts > sqrt(Pmax * R))
		return false;

	voltage = volts;
	current = volts / R;
	return true;
}

float Resistor::getVoltage() const
{
	return voltage;
}

bool Resistor::applyCurrent(float amps)
{
	if (amps > sqrt(Pmax / R))
		return false;
	current = amps;
	voltage = amps * R;
	return true;
}

float Resistor::getCurrent() const
{
	return current;
}

float Resistor::power() const
{
	return (current * voltage);
}

void Resistor::convertOhmToColor(float res)
{
	int counter = 0;
	int cont = 0;
	int r = (int)res;
	int save = r;
	int f1, f2, f3;

	while (r != 0)
	{
		r = r / 10;
		counter++;
	}

	r = save;
	f1 = r / (int)pow(10, counter - 1);
	f2 = r % (int)pow(10, counter - 1);

	r = f2;
	while (r != 0)
	{
		r = r / 10;
		cont++;
	}
	int div;
	if (cont == 0 || cont == 1)
		div = 1;
	else
		div = cont;
	f2 = f2 / (int)pow(10, div - 1);
	f3 = counter - 2;

	string array_1[] = { "Black" , "Brown", "Red" , "Orange", "Yellow",  "Green" , "Blue" , "Violet" , "Gray" , "White" };
	string array_2[] = { "Black" , "Brown", "Red" , "Orange", "Yellow",  "Green" , "Blue" , "Violet" , "Gold" , "Silver" };

	cout << "\tBand 1 = ";
	for (int i = 0; i < 10; i++)
	{
		if (f1 == i)
			cout << array_1[i] << endl;
	}

	cout << "\tBand 2 = ";
	for (int i = 0; i < 10; i++)
	{
		if (f2 == i)
			cout << array_1[i] << endl;
	}

	cout << "\tBand 3 (multiplier) = ";
	for (int i = 0; i < 10; i++)
	{
		if (f3 == i)
			cout << array_1[i] << endl << endl;
	}
}

float Resistor::convertColorToOhm(Color f1, Color f2, Multi multi)
{
	float div = (int)multi / 100.0;
	return (((int)f1 * 10 + (int)f2) * div);
}