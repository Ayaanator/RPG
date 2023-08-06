#pragma once
#include "Food.h"

class EnergyDrink : public Food
{
public:
	EnergyDrink(const Player& p, double* ptr, double* ptr_max, double sm = 0.20, double w = 8, std::string n = "Energy Drink",
		std::string desc = "Restores energy", std::string d = "Energy restoration : ", std::string i_s = "energy", int i = -1);
	virtual ~EnergyDrink() = default;
};

