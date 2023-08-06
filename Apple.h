#pragma once
#include "Food.h"
class Apple : public Food
{
public:
	Apple(const Player& p, double* ptr, double* ptr_max, double sm = 0.33, double w = 5, std::string n = "Apple",
		std::string desc = "Heals player", std::string d = "Heals : ", std::string i_s = "hp", int i = -1);
	virtual ~Apple() = default;
};

