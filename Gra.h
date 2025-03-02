#pragma once
#include "Ball.h"
#include "Gracz.h"
#include "human.h"
#include "Board.h"
#include "AI.h"

class Gra
{
	int players;
	void ShowCursor(bool);
	human gracz1;
	AI gracz2;
	Board table;
	Ball pila;
public:
	Gra(bool);
	int Run();
	void save_file();
	void load_file();
};

