#include "Cards.h"

Cards::Cards()
	: id(0), cost(0), rarity(0)
{
	name[0] = '\0';
	type[0] = '\0';
}

Cards::~Cards()
{
}


void Cards::SetData(int _id, const char* _name, const char* _type, int _cost, int _rarity)
{
}

void Cards::ShowInfo()
{
}
