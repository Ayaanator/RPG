#include "GrimReaper.h"
#include "Player.h"

#include "Delay.h"
#include "RandomNumber.h"
#include "ConsoleUtils.h"

GrimReaper::GrimReaper(double m, Player& p, double hm, double dm, std::string n, double cm, double cr, double e,
	double a, std::string desc)
: Monster{ m, p, hm, dm, n, cm, cr, e * m, a * m, desc }
{
	std::ostringstream ss;

	ss << std::endl << std::setw(half_width) << std::left << "Effect of being hit"
		<< std::setw(half_width) << std::right << "Death" << std::endl;

	other = ss.str();
}

void GrimReaper::attack(Player& p)
{
	if (rand_num(1, 100) <= accuracy)
	{
		std::cout << "The " << name << " slashes " << p.name << "..." << std::endl;

		delay(2);

		std::cout << p.name << " falls to the ground..." << std::endl;

		delay(2);

		p.health = 0;
		p.dead = true;
	}
	else
	{
		std::cout << "The " << name << " misses, phew!" << std::endl;
	}
}