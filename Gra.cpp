#include "Gra.h"
#include "human.h"
#include "AI.h"
#include "Board.h"
#include <iostream>
#include <thread>
#include <Windows.h>
#include "Ball.h"
#include <fstream>
#include <string>


void Gra::ShowCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}

Gra::Gra(bool loadf)
{
    if (loadf) load_file();
}

int Gra::Run()
{
    bool ext = true;
    bool win1 = true;
    bool win2 = true;
    bool end = true;
    char ret;
    char sav;

    char save;
    int x = 0;

    ShowCursor(false);

    thread t(&Ball::move, &pila, ref(gracz1), ref(gracz2), ref(win1), ref(win2), ref(end));
    thread move1(&human::ruch, &gracz1, ref(ext), ref(end));
    thread move2(&AI::ruch, &gracz2, ref(pila), ref(end));



    do
    {
        table.cleanTab();
        table.Paletki(gracz1.paletkaY, gracz2.paletkaY);
        table.Points(gracz1.punkty, gracz2.punkty);
        table.BallUpd(pila.pos[1], pila.pos[0]);
        table.printK();
        Sleep(30);
        system("cls");
    } while (win1 == true && win2 == true && ext == true);

    end = false;
    t.join();
    move1.join();
    move2.join();

    ShowCursor(true);

    if (!ext) {
        do {
            cout << "Czy chcesz zapisac rozgrywke? (y/n)" << endl;
            cin >> sav;
            cin.clear();
        } while (sav != 'y' && sav != 'n');
        if (sav == 'y') {
            save_file();
            cout << "Pomyslnie zapisano rozgrywke" << endl;
        }

    }


    if (!win1)
        cout << "Gratulacje! Wygrales" << endl;
    if (!win2)
        cout << "Przegrales" << endl;
    do {
        cout << "Czy chcesz zagrac jeszcze raz? (y/n)" << endl;
        cin >> ret;
        cin.clear();
        if (ret == 'y') {
            system("cls");
            return 1;
        }
        else cout << "Dziekuje za zagranie w PONG" << endl;
    } while (ret != 'y' && ret != 'n');

    system("pause");

    return 0;
}


void Gra::save_file()
{
    ofstream SaveFile("Save.txt");

    SaveFile << pila.pos[0] << endl;
    SaveFile << pila.pos[1] << endl;
    SaveFile << pila.vecBall[0] << endl;
    SaveFile << pila.vecBall[1] << endl;
    SaveFile << gracz1.paletkaY << endl;
    SaveFile << gracz1.punkty << endl;
    SaveFile << gracz2.paletkaY << endl;
    SaveFile << gracz2.punkty << endl;

    SaveFile.close();
}

void Gra::load_file()
{
    int i = 0;
    string inputvar;
    ifstream SaveFile("Save.txt");

    while (getline(SaveFile, inputvar, '\n')) {
        if (i == 0) pila.pos[0] = stof(inputvar);
        if (i == 1) pila.pos[1] = stof(inputvar);
        if (i == 2) pila.vecBall[0] = stof(inputvar);
        if (i == 3) pila.vecBall[1] = stof(inputvar);
        if (i == 4) gracz1.paletkaY = stof(inputvar);
        if (i == 5) gracz1.punkty = stof(inputvar);
        if (i == 6) gracz2.paletkaY = stof(inputvar);
        if (i == 7) gracz2.punkty = stof(inputvar);
        i += 1;
    }
    SaveFile.close();
}




