#pragma once
#include <vector>
class Cards
{
public:
	Cards();
	~Cards();

public:
	void SetData(int _id, const char* _name, const char* _type, int _cost, int _rarity);
	void ShowInfo();

private:
	int id;
	char name[60];
	char type[30];
	int cost;
	int rarity;
};