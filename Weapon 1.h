#pragma once
#include <string>
#include <iostream>
#include "Rarity.h"
#include "Monster.h"

class Weapon
{
private:
	Rarity rarity{ Rarity::None };
	std::string name{ "Weapon" };
	std::string description{ "Description" };
	double damage_multiplier{ 0 };
	double critical_multiplier{ 0 };
	double accuracy{ 0 };

public:
	Weapon(Rarity r, std::string n, std::string d, double dm, double cm, double a);
	virtual ~Weapon() = default;
	virtual void attack(Monster &m);
	virtual void special(Monster &m);
};

