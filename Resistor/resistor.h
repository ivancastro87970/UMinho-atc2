#pragma once
#include <iostream>
#include <random>

using namespace std;

enum class Color
{
	black = 0, brown = 1, red = 2, orange = 3, yellow = 4, green = 5, blue = 6, violet = 7, gray = 8, white = 9
};

enum class Multi			//multiplicar tudo por 100 uma vez que 'enum' só permite 'int' -> no final do processamento, dividir por 100
{
	black = 100, brown = 1000, red = 10000, orange = 100000, yellow = 1000000, green = 10000000, blue = 100000000, violet = 1000000000, gold = 1, silver = 10
};

class Resistor {
	float voltage;
	float current;
public:
	const float R;
	const float Pmax;
	Resistor(float R, float Pmax = 0.25);
	Resistor(Color, Color, Multi, float Pmax = 0.25);
	bool applyVoltage(float volts);
	float getCurrent() const;
	bool applyCurrent(float amps);
	float getVoltage() const;
	float power() const;
	static void convertOhmToColor(float r);
	static float convertColorToOhm(Color, Color, Multi);
	float changeResistance(Color, Color, Multi);
};
