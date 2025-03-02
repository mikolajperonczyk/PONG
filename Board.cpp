#include "Board.h"
#include <iostream>


using namespace std;



Board::Board()
{

	for (int i = 0; i < 29; i++)
		for (int j = 0; j < 100; j++)
			plansza[i][j] = pusto;

	for (int i = 0; i < 29; i += 2) {
		plansza[i][49] = srodek;
	}

}

void Board::printK()
{

	for (int i = 28; i >= 0; i--) {
		cout << endl;
		for (int j = 0; j < 100; j++) {
			cout << (char)plansza[i][j];
		}
	}

}

void Board::Paletki(int PalG1, int PalG2)
{
	for (int i = 0; i < 3; i++) {
		plansza[i + PalG1 - 1][0] = paletka;
		plansza[i + PalG2 - 1][97] = paletka;
	}
}


void Board::BallUpd(float x, float y)
{
	if (x > 97) x = 97.0;
	if (y > 29) y = 29.0;
	if (x < 0) x = 0;
	if (y < 0) y = 0;
	plansza[(int)y][(int)x] = pilka;
}


void Board::cleanTab()
{
	for (int i = 0; i < 29; i++)
		for (int j = 0; j < 100; j++)
			plansza[i][j] = pusto;

	for (int i = 0; i < 30; i += 2) {
		plansza[i][49] = srodek;
	}
}


void Board::Points(int punktG1, int punktG2)
{
	int moveG1x = 30;
	int moveG1y = 20;
	int moveG2x = moveG1x + 48;
	int moveG2y = moveG1y;
	int size = 7;

	for (int i = 0; i < 2; i++) {
		if (i == 1) {
			punktG1 = punktG2;
			moveG1x = moveG2x;
			moveG1y = moveG2y;
		}
		switch (punktG1)
		{
		case 0:
			for (int i = 1; i < size - 1; i++) {
				plansza[moveG1y][i + moveG1x] = pkt;
				plansza[size + moveG1y - 1][i + moveG1x] = pkt;
				plansza[i + moveG1y][moveG1x] = pkt;
				plansza[i + moveG1y][moveG1x + size - 1] = pkt;
			}
			break;
		case 1:
			for (int i = 0; i < size; ++i)
				plansza[i + moveG1y][size / 2 + moveG1x] = pkt;
			break;
		case 2:
			for (int j = 1; j < size - 1; ++j) {
				plansza[size + moveG1y - 1][j + moveG1x] = pkt;
				plansza[moveG1y][j + moveG1x] = pkt;
				plansza[moveG1y + 3][j + moveG1x] = pkt;
			}
			for (int i = 1; i < size / 2; i++) {
				plansza[moveG1y + i][moveG1x] = pkt;
			}
			for (int i = size - 2; i < size; i++) {
				plansza[moveG1y + i - 1][moveG1x + size - 1] = pkt;
			}
			break;
		case 3:
			for (int i = 1; i < size; i++) {
				plansza[moveG1y + size - 1][moveG1x + i] = pkt;
				plansza[moveG1y + (size - 1) / 2][moveG1x + i] = pkt;
				plansza[moveG1y][moveG1x + i] = pkt;
			}

			plansza[moveG1y + size - 2][moveG1x] = pkt;
			plansza[moveG1y + 1][moveG1x] = pkt;

			for (int i = 1; i < size - 1; i++) {
				if (i == 3) continue;
				plansza[moveG1y + i][moveG1x + size] = pkt;
			}
			break;
		case 4:
			for (int i = 3; i < size; i++)
				plansza[moveG1y + i][moveG1x] = pkt;
			for (int i = 1; i < size; i++)
				plansza[moveG1y + 3][moveG1x + i] = pkt;
			for (int i = 0; i < size; i++)
				plansza[moveG1y + i][moveG1x + size] = pkt;
			break;
		case 5:
			for (int j = 1; j < size - 1; ++j) {
				plansza[size + moveG1y - 1][j + moveG1x] = pkt;
				plansza[moveG1y][j + moveG1x] = pkt;
				plansza[moveG1y + 3][j + moveG1x] = pkt;
			}
			for (int i = size - 2; i < size; i++) {
				plansza[moveG1y + i - 1][moveG1x] = pkt;
			}
			for (int i = 1; i < size / 2; i++) {
				plansza[moveG1y + i][moveG1x + size - 1] = pkt;
			}
			break;
		case 6:
			for (int j = 1; j < size - 1; ++j) {
				plansza[size + moveG1y - 1][j + moveG1x] = pkt;
				plansza[moveG1y][j + moveG1x] = pkt;
				plansza[moveG1y + 3][j + moveG1x] = pkt;
			}
			for (int i = 2; i < size; i++) {
				if (i == 4) continue;
				plansza[moveG1y + i - 1][moveG1x] = pkt;
			}
			for (int i = 1; i < size / 2; i++) {
				plansza[moveG1y + i][moveG1x + size - 1] = pkt;
			}
			break;
		case 7:
			for (int i = 1; i < size; i++) {
				plansza[moveG1y + size - 1][moveG1x + i] = pkt;
			}
			for (int i = 0; i < size; i++) {
				plansza[moveG1y + i][moveG1x + size] = pkt;
			}
			break;
		case 8:
			for (int j = 1; j < size - 1; ++j) {
				plansza[size + moveG1y - 1][j + moveG1x] = pkt;
				plansza[moveG1y][j + moveG1x] = pkt;
				plansza[moveG1y + 3][j + moveG1x] = pkt;
			}
			for (int i = 2; i < size; i++) {
				if (i == 4) continue;
				plansza[moveG1y + i - 1][moveG1x] = pkt;
				plansza[moveG1y + i - 1][moveG1x + size - 1] = pkt;
			}
			break;
		case 9:
			for (int j = 1; j < size - 1; ++j) {
				plansza[size + moveG1y - 1][j + moveG1x] = pkt;
				plansza[moveG1y][j + moveG1x] = pkt;
				plansza[moveG1y + 3][j + moveG1x] = pkt;
			}
			for (int i = 2; i < size; i++) {
				if (i == 4) continue;
				plansza[moveG1y + i - 1][moveG1x + size - 1] = pkt;
			}
			for (int i = size / 2 + 1; i < size - 1; i++) {
				plansza[moveG1y + i][moveG1x] = pkt;
			}
			break;
		default:
			break;
		}
	}
}