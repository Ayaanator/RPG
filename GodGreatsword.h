#pragma once
#include "Weapon.h"

class GodGreatsword : public Weapon
{
public:
	bool first{ false };

	GodGreatsword(Player& p, Rarity r = Rarity::Mythic, std::string n = "God Greatsword",
		std::string desc = "This sword, said to be evolved from a fragile sword, is extremely powerful!", double dm = 10, double cm = 2.5, double a = 100,
		double cr = 33, double w = 240);
	virtual ~GodGreatsword() = default;
};
