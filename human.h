#pragma once
#include "Gracz.h"
#include <iostream>

using namespace std;

class human : public Gracz
{
public:
	void ruch(bool&, bool&);
	human();
};

