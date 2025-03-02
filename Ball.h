#pragma once
#include "Gracz.h"

class Gracz;

using namespace std;

class Ball
{
public:
	float vecBall[2];
	Ball();
	float pos[2];
	void move(Gracz&, Gracz&, bool&, bool&, bool&);
	void reset(int);
	void randomize(Gracz&);
};

