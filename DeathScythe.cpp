#include <sstream>
#include "DeathScythe.h"

#include "Player.h"
#include "Monster.h"

#include "RandomNumber.h"
#include "ConsoleUtils.h"
#include "Delay.h"

DeathScythe::DeathScythe(Player& p, Rarity r, std::string n,
	std::string desc, double dm, double cm, double a,
	double cr, double w)
: Weapon{ p, r, n, desc, dm, cm, a, cr, w }
{
	std::ostringstream ss;

	ss << std::endl << std::setw(half_width) << std::left << "Death chance"
		<< std::setw(half_width) << std::right << std::to_string(death_chance) + "%" << std::endl;

	other = ss.str();
}

void DeathScythe::special(Monster& m, Player& p)
{
	if (p.hit_previous)
	{
		if (rand_num(1, 100) <= death_chance)
		{
			delay(1);

			std::cout << "The " << m.name << " feels Death creep up behind it..." << std::endl;
			m.health = 0;
			m.dead = true;

			delay(2);

			std::cout << "The " << m.name << " falls to the ground!" << std::endl;

			delay(1);
		}
	}
}