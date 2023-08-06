#pragma once
#include "Item.h"

class Player;

class Food : public Item
{
public:
	double* stat_to_increase{ nullptr };
	double* max_stat{ nullptr };
	const double stat_multiplier{ 0 };
	const double stat_increase{ 0 };
	std::string does;
	std::string increased_stat;
	Food(const Player& p, double* ptr, double* ptr_max, double sm = 0, double w = 0, std::string n = "Food",
		std::string desc = "Increases stat", std::string d = "Stats : ", std::string i_s = "stat", int i = -1);

	virtual ~Food() = default;

	virtual void use(Player& p);
	virtual void print(std::ostream& os);
};

