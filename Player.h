/*

Default stats

Harry Dresden
100
100
10
10
15
5
5
100
Fragile Sword

*/

#pragma once
#include <memory>
#include <string>
#include <vector>
#include "I_Printable.h"
#include "Weapon.h"

class Player : public I_Printable
{
public:
	double level{ 1 };
	std::string name{ "Name" };
	double health{ 0 };
	double max_health{ 0 };
	double damage{ 0 };
	double og_damage{ 0 };
	double evasion{ 0 };
	double og_evasion{ 0 };
	double energy{ 0 };
	double max_energy{ 0 };
	std::string weapon_name{ "Weapon Name" };
	Weapon* weapon;
	double coins{ 0 };
	std::vector<Item*> inventory;
	bool dead{ false };
	bool hit_previous{ false };
	
	const int max_multiplier{ 3 };
	double max_damage{ 0 };
	double max_evasion{ 0 };

	Player();
	~Player();
	
	bool recieve_damage(double d, bool dodgeable = true);
	void display_inventory();
	void manage_inventory();
	void manage_stats();
	virtual void print(std::ostream& os);
};
