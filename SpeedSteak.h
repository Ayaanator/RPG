#pragma once
#include "Food.h"

class SpeedSteak : public Food
{
public:
	SpeedSteak(const Player& p, double* ptr, double* ptr_max, double sm = 1, double w = 27.5, std::string n = "Speed Steak",
		std::string desc = "A steak that makes you dodge better than Spider-Man!", std::string d = "Evasion increase : ", std::string i_s = "evasion points", int i = -1);
	virtual ~SpeedSteak() = default;
};
