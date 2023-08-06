#pragma once
#include "Monster.h"

class Dragon : public Monster
{
public:
	double burn_damage{ 0 };
	double burn_division{ 20 };

	Dragon(double m, Player& p, double hm = 0.8, double dm = 0.8, std::string n = "Dragon",
		double cm = 1.33, double cr = 20, double e = 15, double a = 80,
		std::string desc = "A terrifying dragon able to set its foes on fire, and immune to burns!");
	virtual ~Dragon() = default;
	virtual void special(Player& p);
};
