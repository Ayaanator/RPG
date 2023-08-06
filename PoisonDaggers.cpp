#include <sstream>
#include "PoisonDaggers.h"

#include "Player.h"
#include "Monster.h"

#include "RandomNumber.h"
#include "ConsoleUtils.h"

PoisonDaggers::PoisonDaggers(Player& p, Rarity r, std::string n,
	std::string desc, double dm, double cm, double a,
	double cr, double w)
: Weapon{ p, r, n, desc, dm, cm, a, cr, w }
{
	std::ostringstream ss;

	ss << std::endl << std::setw(half_width) << std::left << "Poison damage"
		<< std::setw(half_width) << std::right << "Monster health / " + std::to_string(poison_division) << std::endl;

	other = ss.str();
}

void PoisonDaggers::special(Monster& m, Player& p)
{
	if (og_health > m.health && m.name.find("Snake Serpent") == std::string::npos)
	{
		poison_damage *= rand_dec(0.8, 1.2);
		m.recieve_damage(poison_damage, false);

		std::cout << "The " << m.name << " takes " << poison_damage << " burn damage," << " being left at "
			<< m.health << " hp!" << std::endl;

		poison_damage = og_health / poison_division;
	}
}

void PoisonDaggers::initialize(Monster& m)
{
	poison_damage = m.damage / poison_division;
	og_health = m.health;
}