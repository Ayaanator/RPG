#include "Monster.h"
#include "Player.h"
#include "Treasure.h"

#include "ConsoleUtils.h"
#include "RandomNumber.h"

Monster::Monster(double m, Player& p, double hm, double dm, std::string n, double cm, double cr, double e, 
	double a, std::string desc)
: multiplier{ make_multiplier(m, p) }, health_multiplier{ hm * multiplier }, damage_multiplier{ dm * multiplier }, name{ n }, health{ p.max_health * health_multiplier },
	damage{ p.og_damage * p.weapon->damage_multiplier * damage_multiplier }, critical_multiplier{ cm }, 
	critical_rate{ cr }, evasion{ e }, accuracy{ a }, description{ desc }
{

	if (m < 0.19)
	{
		power = "Harmless";
	}
	else if (m < 0.49)
	{
		power = "Very weak";
	}
	else if (m < 0.99)
	{
		power = "Weak";
	}
	else if (m < 1.24)
	{
		power = "Normal";
	}
	else if (m < 1.99)
	{
		power = "Strong";
	}
	else if (m < 3.99)
	{
		power = "Very strong";
	}
	else
	{
		power = "Dangerous";
	}
	
	name = power + " " + name;
}

bool Monster::recieve_damage(double d, bool dodgeable)
{
	if (rand_num(0, 100) <= evasion && dodgeable == true)
	{
		std::cout << "The " << name << " dodges the attack!" << std::endl;
		return false;
	}
	else
	{
		if (health < d)
		{
			health = 0;
			dead = true;
		}
		else
		{
			health -= d;
		}

		return true;
	}
}

double Monster::make_multiplier(double m, const Player& p)
{
	return m - ((p.level - 1) * m);
}

void Monster::attack(Player& p)
{
	double dam{ damage };
	hit_previous = false;
	
	if (rand_num(0, 100) <= accuracy)
	{
		if (rand_num(0, 100) <= critical_rate)
		{
			dam *= critical_multiplier * rand_dec(0.95, 1.05);

			if (p.recieve_damage(dam))
			{
				std::cout << "The " << name << " deals " << dam << " CRITICAL damage to " << p.name << ", leaving them at "
					<< p.health << " hp!" << std::endl;

				hit_previous = true;
			}

		}
		else
		{
			dam *= rand_dec(0.95, 1.05);

			if (p.recieve_damage(dam))
			{
				std::cout << "The " << name << " deals " << dam << " damage to " << p.name << ", leaving them at "
					<< p.health << " hp!" << std::endl;

				hit_previous = true;
			}

		}
	}
	else
	{
		std::cout << "The " << name << " misses the attack!" << std::endl;
	}
}

void Monster::special(Player& p)
{

}

void Monster::reward(Player& p)
{
	Treasure treasure{ multiplier };
	treasure.claim_reward(p);
}

void Monster::print(std::ostream& os)
{
	print_line('=', width);

	os << std::endl << std::setw(print_center(name, width)) << std::right << name << std::endl << std::endl;
	
	print_left_right("Damage", std::to_string(damage), width, os);
	print_left_right("Health", std::to_string(health), width, os);
	print_left_right("Critical multiplier", std::to_string(critical_multiplier), width, os);
	print_left_right("Critical rate", std::to_string(critical_rate), width, os);
	print_left_right("Accuracy", std::to_string(accuracy), width, os);
	print_left_right("Evasion", std::to_string(evasion), width, os);

	std::cout << other;

	os << std::endl << std::setw(print_center(description, width)) << std::right << description << std::endl << std::endl;
	print_line('=', width);
}