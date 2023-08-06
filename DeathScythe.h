#pragma once
#include "Weapon.h"

class DeathScythe : public Weapon
{
public:
	int death_chance{ 10 };

	DeathScythe(Player& p, Rarity r = Rarity::Legendary, std::string n = "Death Scythe",
		std::string desc = "This scythe has a small chance of killing the enemy!", double dm = 1.75, double cm = 2, double a = 80,
		double cr = 15, double w = 180);
	virtual ~DeathScythe() = default;
	virtual void special(Monster & m, Player & p);
};

