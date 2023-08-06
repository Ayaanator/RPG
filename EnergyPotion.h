#pragma once
#include "Food.h"

class EnergyPotion : public Food
{
public:
	EnergyPotion(const Player& p, double* ptr, double* ptr_max, double sm = 1, double w = 24, std::string n = "Energy Potion",
		std::string desc = "Replenishes energy", std::string d = "Energy restoration : ", std::string i_s = "energy", int i = -1);
	virtual ~EnergyPotion() = default;
	virtual void use(Player& p);
};
