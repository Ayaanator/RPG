#pragma once
#include "I_Printable.h"

class Player;

class Item : public I_Printable
{
public:
	const double worth_multiplier{ 0.75 };
	double worth{ 0 };
	double selling_value{ 0 };
	int index{ -1 };
	std::string description{ "Description" };
	std::string name{ "Item" };
	
	Item(double w = 0, std::string n = "Item", std::string desc = "Description", int i = -1)
	: worth{ w }, name{ n }, description{ desc }, index{ i }, selling_value{ worth * worth_multiplier }
	{

	}

	virtual ~Item() = default;

	virtual void use(Player& p);

};

