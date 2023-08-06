#include "SnakeSerpent.h"
#include "Player.h"

#include "Delay.h"
#include "RandomNumber.h"
#include "ConsoleUtils.h"

SnakeSerpent::SnakeSerpent(double m, Player& p, double hm, double dm, std::string n, double cm, double cr, double e,
	double a, std::string desc)
	: Monster{ m, p, hm, dm, n, cm, cr, e * m, a * m, desc }
{
	venom_damage = p.max_health / venom_division;

	std::ostringstream ss;

	ss << std::endl << std::setw(half_width) << std::left << "Venom damage"
		<< std::setw(half_width) << std::right << venom_damage << std::endl;

	other = ss.str();
}

void SnakeSerpent::special(Player& p)
{
	if (p.max_health > p.health)
	{
		venom_damage *= rand_dec(0.8, 1.2);
		p.recieve_damage(venom_damage, false);

		std::cout << p.name << " takes " << venom_damage << " venom damage," << " being left at "
			<< p.health << " hp!" << std::endl;

		venom_damage = p.max_health / venom_division;
	}
}