#include "AI.h"
#include "Ball.h"
#include <Windows.h>


void AI::ruch(Ball& ball, bool& end) {
	while (end)
	{
		if (ball.pos[0] > paletkaY) vecPal = 1;
		else if (ball.pos[0] < paletkaY) vecPal = -1;
		if (paletkaY + vecPal >= 2 && paletkaY + vecPal <= 27) paletkaY += vecPal;
		Sleep(200);
		vecPal = 0;
	}
}

AI::AI() : Gracz() {}
