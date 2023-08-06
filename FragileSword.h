#pragma once
#include "Weapon.h"

class FragileSword : public Weapon
{
public:
	FragileSword(Player& p, Rarity r = Rarity::Common, std::string n = "Fragile Sword",
		std::string desc = "A trusty ol' sword with well rounded stats", double dm = 1.2, double cm = 1.4, double a = 75,
		double cr = 15, double w = 33);
	virtual ~FragileSword() = default;
};
