#pragma once
#include "Food.h"

class Cake : public Food
{
public:
	Cake(const Player& p, double* ptr, double* ptr_max, double sm = 1, double w = 30, std::string n = "Pie",
		std::string desc = "Replenishes health!", std::string d = "Heals : ", std::string i_s = "hp", int i = -1);
	virtual ~Cake() = default;
	virtual void use(Player& p);
};

