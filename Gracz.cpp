#include "Gracz.h"

bool Gracz::CzyWygral()
{
	if (punkty == 10)
		return true;
	return false;
}


int Gracz::CheckHit(float pila)
{
	if (paletkaY + 2 >= (int)pila && paletkaY - 2 <= (int)pila) return 0;
	return 1;
}

Gracz::Gracz()
{
	punkty = 0;
	paletkaY = 14;
	vecPal = 0;
}
