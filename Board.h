#pragma once

enum symbol
{
	paletka = '|',
	pilka = '@',
	srodek = 'I',
	pusto = ' ',
	pkt = '#'
};

class Board
{
	symbol plansza[29][100];
public:
	Board();
	void printK();
	void Points(int, int);
	void Paletki(int, int);
	void BallUpd(float, float);
	void cleanTab();
};