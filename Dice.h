#pragma once
#include "Weapon.h"

class Dice : public Weapon
{
public:
	int win_chance{ 50 };

	Dice(Player& p, Rarity r = Rarity::Mythic, std::string n = "Dice",
		std::string desc = "You or the enemy will die, take your chances at your own risk!", double dm = 0, double cm = 0, double a = 100,
		double cr = 0, double w = 260);
	virtual ~Dice() = default;
	virtual void attack(Monster& m, Player& p);
};

