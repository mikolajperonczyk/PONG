#include "human.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

human::human() : Gracz() {}

void human::ruch(bool& ext, bool& end)
{
    char key = _getch();

    while (end) {
        if (_kbhit) key = _getch();
        switch (key) {
        case 72:
            if (paletkaY < 29)
                vecPal = 1;
            if (paletkaY + vecPal < 28 && paletkaY + vecPal > 0)
                paletkaY += vecPal;
            Sleep(100);
            vecPal = 0;
            break;
        case 80:
            if (paletkaY < 29)
                vecPal = -1;
            if (paletkaY + vecPal < 28 && paletkaY + vecPal > 0)
                paletkaY += vecPal;
            Sleep(100);
            vecPal = 0;
            break;
        case 27:
            ext = false;
            end = false;
            break;
        default:
            break;
        }
    }
}





