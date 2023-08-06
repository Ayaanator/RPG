#pragma once
#include "Monster.h"

class Titan : public Monster
{
public:
	Titan(double m, Player& p, double hm = 20, double dm = 20, std::string n = "Titan",
		double cm = 2, double cr = 33, double e = 80, double a = 100,
		std::string desc = "This is a titan... You should run...");
	virtual ~Titan() = default;
};
