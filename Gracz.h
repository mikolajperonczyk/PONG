#pragma once

using namespace std;

class Gracz
{
public:
	bool CzyWygral();
	Gracz();
	int vecPal;
	int punkty;
	int paletkaY;
	int CheckHit(float);
};

