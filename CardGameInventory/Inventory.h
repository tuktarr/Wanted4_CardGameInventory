#pragma once

#include "Cards.h"
#include "Vector.h"
#include <string>

class Inventory
{
public:
	Inventory();
	void LoadFromCSV(const char* fileName);
	void Run();
	void Gotoxy(int x, int y);

private:
	Vector<Cards> info;
	int currentIndex;
};

