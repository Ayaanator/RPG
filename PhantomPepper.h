#pragma once
#include "Food.h"

class PhantomPepper : public Food
{
public:
	PhantomPepper(const Player& p, double* ptr, double* ptr_max, double sm = 0.33, double w = 15, std::string n = "Phantom Pepper",
		std::string desc = "This is so spicy, it increase your attack!", std::string d = "Attack increase : ", std::string i_s = "damage", int i = -1);
	virtual ~PhantomPepper() = default;
};


