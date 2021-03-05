#define _CRT_SECURE_NO_WARNINGS
#include "Circle.h"

#include <iostream>

using namespace std;

int main()
{
    float x, y, radio;
    cout << "Introduza as coordenadas do centro (X Y): ";
    cin >> x >> y;
    cout << "Introduza o raio: ";
    cin >> radio;
    Circle c(radio, Point(x, y));

    cout << "\tPerimetro = " << c.area() << endl;

    cout << "\t'Area = " << c.perimeter() << endl;

    cout << "Introduza o deslocamento (X Y): ";
    cin >> x >> y;
    FloatXY new_position = c.move({ x, y });
    cout << "\tNova posicao = "
        << new_position.x << ", " << new_position.y << endl;

    float zoom = 1;
    cout << "Introduza a ampliacao (>1)/reducao (<1): ";
    cin >> zoom;
    float new_radio = c.resize(zoom);
    if (new_radio > 0)
        cout << "\tNovo raio = " << new_radio << endl;
    else
        cout << "\tFactor de multiplicacao resulta num raio invalido!\n";

    cout << "Introduza as coordenadas de um ponto (X Y): ";
    cin >> x >> y;
    cout << "o ponto"
        << (c.contains(Point(x, y)) ? " " : " nao ")
        << "pertence ao circulo\n";

    cout << "Introduza as coordenadas do centro (X Y): ";
    cin >> x >> y;
    cout << "Introduza o raio: ";
    cin >> radio;
    Circle c2(radio, Point(x, y));
    cout << "\tA distancia entre os Circulos e' "
        << c.perimetersDistance(c2) << endl;

    FloatXY pos2 = c2.position();
    cout << "\tPosicao do 2o circulo = " << pos2.x << ", " << pos2.y << endl;
    cout << "\tRaio do 2o circulo = " << c2.size() << endl;
    cout << "\tQuadrante do 2o circulo = " << c2.quadrantStr() << endl;

    cin.get(); cin.get();
    return 0;
}