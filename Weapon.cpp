#include <random>
#include <iomanip>

#include "Player.h"
#include "Monster.h"

#include "Make.h"
#include "ConsoleUtils.h"
#include "RandomNumber.h"

#include "Weapon.h"
#include "FragileSword.h"
#include "StoneHammer.h"

Weapon::Weapon(const Player& p, Rarity r, std::string n, std::string desc, double dm, double cm, double a, double cr, double w)
: rarity{ r }, damage_multiplier{ dm }, critical_multiplier{ cm },
	accuracy{ a }, critical_rate{ cr }, damage{ p.damage * damage_multiplier }, Item{ w, n, desc }
{
	
}

void Weapon::attack(Monster& m, Player& p)
{
	double dam{ damage };
	p.hit_previous = false;

	if (rand_num(0, 100) <= accuracy)
	{
		if (rand_num(0, 100) <= critical_rate)
		{
			dam *= critical_multiplier * rand_dec(0.95, 1.05);

			if (m.recieve_damage(dam))
			{
				std::cout << p.name << " deals " << dam << " CRITICAL damage to the " << m.name << ", leaving them at "
					<< m.health << " hp!" << std::endl;

				p.hit_previous = true;
			}
		}
		else
		{
			dam *= rand_dec(0.95, 1.05);

			if (m.recieve_damage(dam))
			{
				std::cout << p.name << " deals " << dam << " damage to the " << m.name << ", leaving them at "
					<< m.health << " hp!" << std::endl;

				p.hit_previous = true;
			}
		}
	}
	else
	{
		std::cout << p.name << " misses the attack!" << std::endl;
	}
}

void Weapon::special(Monster& m, Player& p)
{

}

void Weapon::print(std::ostream& os)
{

	print_line('-', width);
	
	os << std::endl << std::setw(print_center(name, width)) << std::right << name << std::endl << std::endl;
	
	print_left_right("Damage", std::to_string(damage), width, os);
	print_left_right("Damage multiplier", std::to_string(damage_multiplier), width, os);
	print_left_right("Critical multiplier", std::to_string(critical_multiplier), width, os);
	print_left_right("Critical rate", std::to_string(critical_rate), width, os);
	print_left_right("Accuracy", std::to_string(accuracy), width, os);
	
	os << other;

	os << std::endl << std::setw(print_center(description, width)) << std::right << description << std::endl << std::endl;
	print_line('-', width);

}

void Weapon::use(Player& p)
{
	std::cout << p.name << " switches weapons" << std::endl;

	p.inventory[index] = p.weapon;
	p.weapon = make_weapon(p, name);
	p.weapon_name = name;

	Item::use(p);
}

void Weapon::initialize(Monster& m)
{

}