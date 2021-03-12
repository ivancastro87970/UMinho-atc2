#pragma once
#include <random>
#include <iostream>

class Resistor 
{
	float voltage;
	float current;
public:
	const float R;
	const float Pmax;
	Resistor(float R, float Pmax = 0.25);
	float applyVoltage(float volts);
	float getCurrent() const;
	bool applyCurrent(float amps);
	float getVoltage() const;
	float power() const;
};
