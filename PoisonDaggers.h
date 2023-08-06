#pragma once
#include "Weapon.h"

class PoisonDaggers : public Weapon
{
public:
	double poison_damage{ 0 };
	double og_health{ 0 };
	double poison_division{ 20 };

	PoisonDaggers(Player& p, Rarity r = Rarity::Rare, std::string n = "Poison Daggers",
		std::string desc = "A dangerous dagger that poisons living things!", double dm = 1.5, double cm = 2, double a = 66,
		double cr = 25, double w = 80);
	virtual ~PoisonDaggers() = default;
	virtual void special(Monster& m, Player& p);
	virtual void initialize(Monster& m);
};

