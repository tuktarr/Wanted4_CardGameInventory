#include "Cards.h"
#include <iostream>

Cards::Cards()
	: id(0), cost(0), rarity(0)
{

}

Cards::~Cards()
{
}


void Cards::SetData(int _id, const std::string& _name, const std::string& _type, int _cost, int _rarity)
{
	id = _id;
	name = _name;
	type = _type;
	cost = _cost;
	rarity = _rarity;

}

void Cards::ShowInfo()
{
	std::cout << "ID: " << id << " | Name: " << name << " | Type: " << type << " | Cost: " << cost << " | Rarity: " << rarity << " \033[K\n";
}
