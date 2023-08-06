#include "Dragon.h"
#include "Player.h"

#include "Delay.h"
#include "RandomNumber.h"
#include "ConsoleUtils.h"

Dragon::Dragon(double m, Player& p, double hm, double dm, std::string n, double cm, double cr, double e,
	double a, std::string desc)
	: Monster{ m, p, hm, dm, n, cm, cr, e * m, a * m, desc }
{
	burn_damage = p.max_health / burn_division;

	std::ostringstream ss;

	ss << std::endl << std::setw(half_width) << std::left << "Burn damage"
		<< std::setw(half_width) << std::right << burn_damage << std::endl;

	other = ss.str();
}

void Dragon::special(Player& p)
{
	if (p.max_health > p.health)
	{
		burn_damage *= rand_dec(0.8, 1.2);
		p.recieve_damage(burn_damage, false);

		std::cout << p.name << " takes " << burn_damage << " burn damage," << " being left at "
			<< p.health << " hp!" << std::endl;

		burn_damage = p.max_health / burn_division;
	}
}