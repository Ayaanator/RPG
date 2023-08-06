#pragma once
#include "Weapon.h"

class StoneHammer : public Weapon
{
public:
	StoneHammer(Player& p, Rarity r = Rarity::Uncommon, std::string n = "Stone Hammer",
		std::string desc = "A mean hammer, inaccurate but deadly!", double dm = 2, double cm = 2.4, double a = 50,
		double cr = 50, double w = 50);
	virtual ~StoneHammer() = default;
};

