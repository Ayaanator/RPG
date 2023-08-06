#pragma once
#include "Monster.h"

class Golem : public Monster
{
public:
	Golem(double m, Player& p, double hm = 1.75, double dm = 1.75, std::string n = "Golem",
		double cm = 2, double cr = 33, double e = 0, double a = 33,
		std::string desc = "A huge golem! Strong and powerful, but slow and innacurate!");
	virtual ~Golem() = default;
};

