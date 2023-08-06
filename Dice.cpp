#include <sstream>
#include "Dice.h"

#include "Player.h"
#include "Monster.h"

#include "RandomNumber.h"
#include "ConsoleUtils.h"
#include "Delay.h"

Dice::Dice(Player& p, Rarity r, std::string n,
	std::string desc, double dm, double cm, double a,
	double cr, double w)
	: Weapon{ p, r, n, desc, dm, cm, a, cr, w }
{
	std::ostringstream ss;

	ss << std::endl << std::setw(half_width) << std::left << "You dying : 50%"
		<< std::setw(half_width) << std::right << "Enemy dying : 50%";

	other = ss.str();
}

void Dice::attack(Monster& m, Player& p)
{
	std::cout << "You roll the die... If you get an even number you win..." << std::endl;

	delay(2);
	int n{ rand_num(1, 6) };

	if (n % 2 == 0)
	{
		m.health = 0;
		m.dead = true;

		std::cout << "The " << m.name << " watches in horror as you roll a " << n << "..." << std::endl;

		delay(2);

		std::cout << "The " << m.name << " falls to the ground!" << std::endl;

		delay(1);
	}
	else
	{
		p.health = 0;
		p.dead = true;

		std::cout << p.name << " watches in horror as they roll " << n << "..." << std::endl;

		delay(2);

		std::cout << p.name << " falls to the ground..." << std::endl;

		delay(1);
	}
}