#pragma once
#include "Monster.h"

class SnakeSerpent : public Monster
{
public:
	double venom_damage{ 0 };
	double venom_division{ 10 };

	SnakeSerpent(double m, Player& p, double hm = 0.25, double dm = 0.25, std::string n = "Snake Serpent",
		double cm = 1.80, double cr = 33, double e = 50, double a = 95,
		std::string desc = "Altough this snake serpent is weak, it injects venom, and is quick and accurate!");
	virtual ~SnakeSerpent() = default;
	virtual void special(Player& p);
};