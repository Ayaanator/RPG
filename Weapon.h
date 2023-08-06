#pragma once
#include <string>
#include <iostream>
#include "Rarity.h"
#include "Item.h"

class Monster;
class Player;

class Weapon : public Item
{
public:
	Rarity rarity{ Rarity::None };
	double damage_multiplier{ 0 };
	double critical_multiplier{ 0 };
	double accuracy{ 0 };
	double critical_rate{ 0 };
	double damage{ 0 };
	std::string other;
	
	Weapon(const Player& p, Rarity r, std::string n, std::string desc, double dm, double cm, double a, double cr, double w);
	virtual ~Weapon() = default;
	virtual void attack(Monster& m, Player& p);
	virtual void special(Monster& m, Player& p);
	virtual void print(std::ostream& os);
	virtual void use(Player& p);
	virtual void initialize(Monster& m);
};
