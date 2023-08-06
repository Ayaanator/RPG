#include <sstream>
#include "FireSword.h"

#include "Player.h"
#include "Monster.h"

#include "RandomNumber.h"
#include "ConsoleUtils.h"

FireSword::FireSword(Player& p, Rarity r, std::string n,
	std::string desc, double dm, double cm, double a,
	double cr, double w)
: Weapon{ p, r, n, desc, dm, cm, a, cr, w }
{
	std::ostringstream ss;

	ss << std::endl << std::setw(half_width) << std::left << "Burn damage"
		<< std::setw(half_width) << std::right << "Monster health / " + std::to_string(burn_division) << std::endl;

	other = ss.str();
}

void FireSword::special(Monster& m, Player& p)
{
	if (og_health > m.health && m.name.find("Dragon") == std::string::npos)
	{
		burn_damage *= rand_dec(0.8, 1.2);
		m.recieve_damage(burn_damage, false);
		
		std::cout << "The " << m.name << " takes " << burn_damage << " burn damage," << " being left at "
			<< m.health << " hp!" << std::endl;

		burn_damage = og_health / burn_division;
	}
}

void FireSword::initialize(Monster& m)
{
	burn_damage = m.health / burn_division;
	og_health = m.health;
}