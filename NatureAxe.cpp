#include <sstream>
#include "NatureAxe.h"

#include "Player.h"
#include "Monster.h"

#include "RandomNumber.h"
#include "ConsoleUtils.h"

NatureAxe::NatureAxe(Player& p, Rarity r, std::string n,
	std::string desc, double dm, double cm, double a,
	double cr, double w)
: Weapon{ p, r, n, desc, dm, cm, a, cr, w }
{
	heals = p.max_health * heal_multiplier;

	std::ostringstream ss;

	ss << std::endl << std::setw(half_width) << std::left << "Heals"
		<< std::setw(half_width) << std::right << heals << std::endl;

	other = ss.str();
}

void NatureAxe::special(Monster& m, Player& p)
{
	if (p.hit_previous)
	{
		heals *= rand_dec(0.8, 1.2);
		
		if (p.health + heals > p.max_health)
		{
			p.health = p.max_health;
		}
		else
		{
			p.health += heals;
		}

		std::cout << p.name << " gains back " << heals << " hp, being left at " << p.health << " hp!" << std::endl;
		heals = p.max_health * heal_multiplier;
	}
}