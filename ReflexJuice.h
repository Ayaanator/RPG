#pragma once
#include "Food.h"

class ReflexJuice : public Food
{
public:
	ReflexJuice(const Player& p, double* ptr, double* ptr_max, double sm = 0.5, double w = 15, std::string n = "Reflex Juice",
		std::string desc = "This juice increases your evasion!", std::string d = "Evasion increase : ", std::string i_s = "evasion points", int i = -1);
	virtual ~ReflexJuice() = default;
};
