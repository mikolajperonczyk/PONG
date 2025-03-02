#pragma once
#include "Gracz.h"
#include "Ball.h"


class AI : public Gracz
{
public:
	AI();
	void ruch(Ball&, bool&);
};

