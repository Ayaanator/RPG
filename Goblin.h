#pragma once
#include "Monster.h"

class Goblin : public Monster
{
public:
	Goblin(double m, Player& p, double hm = 0.75, double dm = 0.75, std::string n = "Goblin",
		double cm = 1.2, double cr = 10, double e = 15, double a = 75, 
		std::string desc = "A green goblin, stats are well rounded");
	virtual ~Goblin() = default;
};

