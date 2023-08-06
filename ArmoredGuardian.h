#pragma once
#include "Monster.h"

class ArmoredGuardian : public Monster
{
public:
	ArmoredGuardian(double m, Player& p, double hm = 2.5, double dm = 0.33, std::string n = "Armored Guardian",
		double cm = 1.2, double cr = 10, double e = 0, double a = 66,
		std::string desc = "His defence is godlike and immune to all effects! But, his attacks are weak!");
	virtual ~ArmoredGuardian() = default;
};

