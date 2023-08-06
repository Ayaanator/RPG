#pragma once
#include "Food.h"

class GodFruit : public Food
{
public:
	int multiplier{ 10 };

	GodFruit(const Player& p, double* ptr, double* ptr_max, double sm = 10, double w = 100, std::string n = "God Fruit",
		std::string desc = "This fruit was made to fight the titans, it greatly multiplies stats!", std::string d = "Stat multiplication : ", std::string i_s = "stats", int i = -1);
	virtual ~GodFruit() = default;
	virtual void use(Player& p);
};

