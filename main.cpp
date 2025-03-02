#include <iostream>
#include "Gra.h"

using namespace std;


void Instruction()
{
    cout << "Gra PONG polega na zdobyciu 10 punktow obijajac pilke paletka tak by przeciwnik nie zdolal jej ponownie odbic" << endl;
    cout << "Poruszanie paletka odbywa sie za pomoca klawiszy (strzlka w gore) i (strzalka w dol) kolejno w gore i w dol" << endl;
    cout << "Po nacisnieciu klawisza ESC nastepuje wyjscie z gry" << endl;
    system("pause");
    system("cls");
}

int Menu()
{
    int choice = 2;
    char t;
    do {
        cout << "MENU" << endl;
        cout << "1.Rozpocznij rozgrywke" << endl;
        cout << "2.Wyswietl instrukcje" << endl;
        cout << "3.Wczytaj rozgruwke" << endl;
        cout << "4.Wyjdz z gry" << endl;
        do {
            cin >> t;
            cin.clear();
        } while (t != '1' && t != '2' && t != '3' && t != '4');
        if (t == '2')
            Instruction();
        if (t == '3') {
            choice = 1;
            cout << "Pomyslnie wczytano rozgrywke" << endl;
            system("cls");
        }
        if (t == '4')
            choice = 0;
    } while (t != '1' && t != '4');
    return choice;
}



int main()
{
    bool loadf = false;
    int k = Menu();

    if (k == 1) loadf = true;
    if (k == 0) return 0;
    Gra g(loadf);
    while (g.Run());

    return 0;
}
