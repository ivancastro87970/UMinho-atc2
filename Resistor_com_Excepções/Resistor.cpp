#include "Resistor.h"
#include<stdexcept>
#include <cmath>

using namespace std;

Resistor::Resistor(float R, float Pmax) : R(R), Pmax(Pmax) 
{
	if (R < 0)
		throw invalid_argument("Resistencia n�o pode ser negativa! ");
	voltage = current = 0;
}

float Resistor::applyVoltage(float volts) 
{
	if (volts > sqrt(Pmax * R))
		// return false;	 // usar o debaixo � igual, mas com excep��es
		throw invalid_argument("Volatge Exceeds max power! "); // excep��o
	voltage = volts;
	current = voltage / R;
	// return true;
	return current;
}

float Resistor::getCurrent() const 
{
	return current;
}

bool Resistor::applyCurrent(float amps) // tratamento de erros
{
	if (amps * R > sqrt(Pmax * R))
		return false;
	current = amps;
	voltage = R * current;
	return true;
}

float Resistor::getVoltage() const 
{
	return voltage;
}

inline float Resistor::power() const 
{
	return voltage * current;
}