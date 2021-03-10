#include "Arc.h"

#include <iostream>

using namespace std;

int main()
{
    float x, y, radio;
    cout << "Introduza as coordenadas do centro (X Y): ";
    cin >> x >> y;
    cout << "Introduza o raio: ";
    cin >> radio;
    Arc a(radio, Point(x, y));

    cout << "\tPerimetro = " << a.perimeter() << endl;

    cout << "\t'Area = " << a.area() << endl;

    float rot;
    cout << "Introduza um angulo para rodar (graus): ";
    cin >> rot;
    float new_orientation = a.rotateThrough(rot);
    cout << "\tNova orientacao = " << new_orientation << endl;

    float dd;
    cout << "Introduza uma variacao do angulo (<0 reduzir / >0 aumentar): ";
    cin >> dd;
    float new_angle = a.changeAngle(dd);
    cout << "\tNovo angulo = " << new_angle << endl;

    cout << "Introduza o deslocamento (X Y): ";
    cin >> x >> y;
    FloatXY new_position = a.move({ x, y });
    cout << "\tNova posicao = "
        << new_position.x << ", " << new_position.y << endl;

    float zoom = 1;
    cout << "Introduza a ampliacao (>1)/reducao (<1): ";
    cin >> zoom;
    float new_radio = a.resize(zoom);
    if (new_radio > 0)
        cout << "\tNovo raio = " << new_radio << endl;
    else
        cout << "\tFactor de multiplicacao resulta num raio invalido!\n";

    cin.get(); cin.get();
    return 0;
}