#pragma once
#include <string>
#include "I_Printable.h"
#include <map>

class Player;

class Monster : public I_Printable
{
public:
	
	double multiplier{ 0 };
	double health_multiplier{ 0 };
	double damage_multiplier{ 0 };

	std::string name;
	std::string power;
	double health{ 0 };
	double damage{ 0 };
	double critical_multiplier{ 0 };
	double critical_rate{ 0 };
	double evasion{ 0 };
	double accuracy{ 0 };
	std::string other;
	std::string description;
	bool dead{ false };
	bool hit_previous{ false };

	Monster(double m, Player& p, double hm = 0, double dm = 0, std::string n = "Monster",
		double cm = 0, double cr = 0, double e = 0, double a = 0, std::string desc = "Description");
	virtual ~Monster() = default;


	virtual bool recieve_damage(double d, bool dodgeable = true);
	virtual void attack(Player& p);
	virtual void special(Player& p);
	virtual void reward(Player& p);
	double make_multiplier(double m, const Player& p);
	void print(std::ostream& os);
};