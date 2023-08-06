#pragma once
#include "Weapon.h"

class Player;
class Monster;

class FireSword : public Weapon
{
public:
	double burn_damage{ 0 };
	double og_health{ 0 };
	double burn_division{ 20 };

	FireSword(Player& p, Rarity r = Rarity::Rare, std::string n = "Fire Sword",
		std::string desc = "A powerful sword that sets its targets on fire!", double dm = 1.33, double cm = 1.66, double a = 80,
		double cr = 15, double w = 80);
	virtual ~FireSword() = default;
	virtual void special(Monster& m, Player& p);
	virtual void initialize(Monster& m);
};

