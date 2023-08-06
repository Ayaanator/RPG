#pragma once
#include "Monster.h"

class GrimReaper : public Monster
{
public:
	GrimReaper(double m, Player& p, double hm = 0.66, double dm = 0.00, std::string n = "Grim Reaper",
		double cm = 0, double cr = 0, double e = 10, double a = 10,
		std::string desc = "An agile grim reaper, inaccurate, but instakills!");
	virtual ~GrimReaper() = default;
	virtual void attack(Player& p);
};
