#include "Ball.h"
#include <Windows.h>
#include <iostream>

Ball::Ball()
{
	pos[0] = 14.0;
	pos[1] = 49.0;
	vecBall[0] = 0.2;
	vecBall[1] = -1;
}

void Ball::move(Gracz& a, Gracz& b, bool& win1, bool& win2, bool& end)
{
	int i;
	while(end){
		if(pos[1]+vecBall[1] < 97 && pos[1]+vecBall[1] > 0 && pos[0] + vecBall[0] < 29 && pos[0] + vecBall[0] > 0){
			for (i = 0; i < 2; i++)
			{
				pos[i] += vecBall[i];
			}
		}
		else if(pos[0] + vecBall[0] >= 29 || pos[0] + vecBall[0] <= 0) {
			vecBall[0] = -vecBall[0];
			for (i = 0; i < 2; i++)
			{
				pos[i] += vecBall[i];
			}
		}
		else if (pos[1] + vecBall[1] <= 0) {
			
			if (!a.CheckHit(pos[0])) {
				vecBall[1] = -vecBall[1];
				this->randomize(a);
			}
			else {
				b.punkty += 1;
				if (b.CzyWygral()) {
					win2 = false;
					end = true;
				}
				this->reset(0);
			}
		}
		else if (pos[1] + vecBall[1] >= 97) {
			if (!b.CheckHit(pos[0])) {
				vecBall[1] = -vecBall[1];
				this->randomize(b);
			}
			else {
				a.punkty += 1;
				if (a.CzyWygral()) {
					win1 = false;
					end = true;
				}
				this->reset(1);
			}
		}
		Sleep(60);
	}
}

void Ball::randomize(Gracz& obj)
{
	float vect = obj.vecPal;
	float x = (rand() % 40)/100.0;
	if (vect < 0) x = -x;
	if(vect == 0) x = x - 0.2;
	if (abs(vecBall[0] + x) <= 0.5) vecBall[0] += x;
	else if(vecBall[0] > 0) vecBall[0] = 0.5;
	else vecBall[0] = -0.5;
}

void Ball::reset(int who)
{
	pos[0] = 14.0;
	pos[1] = 49.0;
	vecBall[0] = 0;
	if (who == 1)
		vecBall[1] = -1;
	else vecBall[1] = 1;
}

