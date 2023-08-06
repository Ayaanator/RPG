#pragma once
#include "Weapon.h"

class NatureAxe : public Weapon
{
public:
	double heals{ 0 };
	double heal_multiplier{ 0.05 };

	NatureAxe(Player& p, Rarity r = Rarity::Epic, std::string n = "Nature Axe",
		std::string desc = "This axe heals you!", double dm = 1.75, double cm = 2, double a = 66,
		double cr = 25, double w = 120);
	virtual ~NatureAxe() = default;
	virtual void special(Monster& m, Player& p);
};