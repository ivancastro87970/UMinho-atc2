#define _CRT_SECURE_NO_WARNINGS
#include "Resistor.h"
#include <iostream>

using namespace std;

void clear_stdin()
{
    char ch;
    do
    {
        ch = getchar();
    } while (ch != '\n');
}

int printMenu()
{
    int op = 10;
    cout << "\t 1-\t\t\t\t\tApply Voltage" << endl;
    cout << "\t 2-\t\t\t\t\tApply Current" << endl;
    cout << "\t 3-\t\t\t\t\tGet Voltage" << endl;
    cout << "\t 4-\t\t\t\t\tGet Current" << endl;
    cout << "\t 5-\t\t\t\t\tGet Power" << endl;
    cout << "\t 6-\t\t\t\t\tConvert Colors to Ohms" << endl;
    cout << "\t 7-\t\t\t\t\tConvert Ohms to Colors" << endl;
    cout << "\t 8-\t\t\t\t\tInitializate a Resistor with Colors Code" << endl;
    cout << "\t 9-\t\t\t\t\tExit" << endl << endl;
    cout << "\t\t\t\t\t\tYour Option: ";
    cin >> op;
    clear_stdin();
    return op;
}

Color printColorsCode()
{
    int op = 1;
    cout << "\t 0-\t\t\t\t\tBlack  (0)" << endl;
    cout << "\t 1-\t\t\t\t\tBrown  (1)" << endl;
    cout << "\t 2-\t\t\t\t\tRed    (2)" << endl;
    cout << "\t 3-\t\t\t\t\tOrange (3)" << endl;
    cout << "\t 4-\t\t\t\t\tYellow (4)" << endl;
    cout << "\t 5-\t\t\t\t\tGreen  (5)" << endl;
    cout << "\t 6-\t\t\t\t\tBlue   (6)" << endl;
    cout << "\t 7-\t\t\t\t\tViolet (7)" << endl;
    cout << "\t 8-\t\t\t\t\tGray   (8)" << endl;
    cout << "\t 9-\t\t\t\t\tWhite  (9)" << endl;
    cout << "\t\t\t\t\t\t? ";
    cin >> op;
    clear_stdin();
    switch (op)
    {
    case 0: return Color::black;
    case 1: return Color::brown;
    case 2: return Color::red;
    case 3: return Color::orange;
    case 4: return Color::yellow;
    case 5: return Color::green;
    case 6: return Color::blue;
    case 7: return Color::violet;
    case 8: return Color::gray;
    case 9: return Color::white;
    default: return Color::black;
    }
}

Multi printColorsCodeMul()
{
    int op = 1;
    cout << "\t 1-\t\t\t\t\tBlack  (x1)" << endl;
    cout << "\t 2-\t\t\t\t\tBrown  (x10)" << endl;
    cout << "\t 3-\t\t\t\t\tRed    (x100)" << endl;
    cout << "\t 4-\t\t\t\t\tOrange (x1k)" << endl;
    cout << "\t 5-\t\t\t\t\tYellow (x10k)" << endl;
    cout << "\t 6-\t\t\t\t\tGreen  (x100k)" << endl;
    cout << "\t 7-\t\t\t\t\tBlue   (x1M)" << endl;
    cout << "\t 8-\t\t\t\t\tViolet (x10M)" << endl;
    cout << "\t 9-\t\t\t\t\tGold   (x0.1)" << endl;
    cout << "\t10-\t\t\t\t\tSilver (x0.01)" << endl;
    cout << "\t\t\t\t\t\t? ";
    cin >> op;
    clear_stdin();
    switch (op)
    {
    case 1: return Multi::black;
    case 2: return Multi::brown;
    case 3: return Multi::red;
    case 4: return Multi::orange;
    case 5: return Multi::yellow;
    case 6: return Multi::green;
    case 7: return Multi::blue;
    case 8: return Multi::violet;
    case 9: return Multi::gold;
    case 10: return Multi::silver;
    default: return Multi::black;
    }
}

int main()
{
    int op = 1;
    float res, volt, curr, pmax;
    cout << "\t\t\t\tInsira o valor da Resistencia: ";
    cin >> res;
    clear_stdin();
    if (res <= 0)
    {
        cout << "\t\t\terror: Nao existe valores de resistencias negativas!" << endl;
        return 0;
    }
    cout << "\t\t\tInsira o valor da Potencia Maxima da Resistencia ( <= 0.25 ): ";
    cin >> pmax;
    clear_stdin();
    if (pmax > 0.25)
    {
        cout << "\t\t\terror: Potencia maxima ultrapassada!" << endl;
        return 0;
    }

    Resistor r(res, pmax);

    while (op > 0 && op < 9)
    {
        op = printMenu();
        switch (op)
        {
        case 1:
        {
            cout << "\t\t\t\t\t\t? ";
            cin >> volt;
            clear_stdin();
            if (!r.applyVoltage(volt))
                cout << "\t\t\t\terror: to much volts!" << endl << endl;
            break;
        }
        case 2:
        {
            cout << "\t\t\t\t\t\t? ";
            cin >> curr;
            clear_stdin();
            if (!r.applyCurrent(curr))
                cout << "\t\t\t\terror: to much current!" << endl << endl;
            break;
        }
        case 3:
        {
            cout << "\t\t\t\tVoltage: " << r.getVoltage() << " V" << endl << endl;
            break;
        }
        case 4:
        {
            cout << "\t\t\t\tCurrent: " << r.getCurrent() << " A" << endl << endl;
            break;
        }
        case 5:
        {
            cout << "\t\t\t\tPower: " << r.power() << " W" << endl << endl;
            break;
        }
        case 6:
        {
            Color b1, b2;
            Multi mul;
            cout << "\t\t\tChoose Your First Band\n";
            b1 = printColorsCode();
            cout << "\t\t\tChoose Your Second Band\n";
            b2 = printColorsCode();
            cout << "\t\t\tChoose Your Third Band (and your multiplier)\n";
            mul = printColorsCodeMul();
            float res = r.convertColorToOhm(b1, b2, mul);
            cout << "\t\t\tR = " << res << " Ohms" << endl << endl;
            break;
        }
        case 7:
        {
            float rp;
            cout << "\t\t\tChoose Your Resistence ( >= 10 ) : ";
            cin >> rp;
            if (rp < 10)
                cout << "\t\t\t\t\t\terror: invalid input!" << endl;
            else
                r.convertOhmToColor(rp);
            break;
        }
        case 8:
        {
            Color b1, b2;
            Multi mul;
            cout << "\t\t\tChoose Your First Band\n";
            b1 = printColorsCode();
            cout << "\t\t\tChoose Your Second Band\n";
            b2 = printColorsCode();
            cout << "\t\t\tChoose Your Third Band (and your multiplier)\n";
            mul = printColorsCodeMul();
            Resistor r(b1, b2, mul);
            cout << endl;
            break;
        }
        default:
            op = 10;
            break;
        }

    }

    return 0;
}