#pragma once
#include <memory>
#include "Weapon.h"
#include "Fists.h"
#include "FragileSword.h"
#include "Monster.h"

class Player
{
private:
	std::string name{ "Name" };
	double health{ 0 };
	double max_health{ 0 };
	double damage{ 0 };
	double evasion{ 0 };
	int energy{ 0 };
	int max_energy{ 0 };
	std::string weapon_name{ "Weapon Name" };
	std::unique_ptr<Weapon> weapon;

public:
	Player();
	~Player();

	void recieve_damage(double d);
};

