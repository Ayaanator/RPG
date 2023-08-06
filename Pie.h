#pragma once
#include "Food.h"

class Pie : public Food
{
public:
	Pie(const Player& p, double* ptr, double* ptr_max, double sm = 0.66, double w = 10, std::string n = "Pie",
		std::string desc = "Heals player", std::string d = "Heals : ", std::string i_s = "hp", int i = -1);
	virtual ~Pie() = default;
};

