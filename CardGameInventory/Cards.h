#pragma once
#include <string>

class Cards
{
public:
	Cards();
	~Cards();

public:
	void SetData(int _id, const std::string& _name, const std::string& _type, int _cost, int _rarity);
	void ShowInfo();

private:
	int id;
	std::string name;
	std::string type;
	int cost;
	int rarity;
};