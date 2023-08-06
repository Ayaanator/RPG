#pragma once
#include "Food.h"

class StrengthSyringe : public Food
{
public:
	StrengthSyringe(const Player& p, double* ptr, double* ptr_max, double sm = 1, double w = 45, std::string n = "Strength Syringe",
		std::string desc = "This syringe doubles your damage!", std::string d = "Attack increase : ", std::string i_s = "damage", int i = -1);
	virtual ~StrengthSyringe() = default;
};

