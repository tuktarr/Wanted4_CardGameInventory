#pragma once

#include "Cards.h"
#include "Vector.h"

class Inventory
{
public:
	Inventory();

private:
	Vector<Cards> cards;
};

