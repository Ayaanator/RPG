#include "Treasure.h"
#include "Player.h"

#include "ConsoleUtils.h"
#include "RandomNumber.h"
#include "Delay.h"
#include "Make.h"

#include "Weapon.h"
#include "FragileSword.h"
#include "StoneHammer.h"

#include "Food.h"
#include "Apple.h"

Treasure::Treasure(double m)
: multiplier{ m }
{
    if (m < 0.19)
	{
		name = "Worthless treasure";
	}
	else if (m < 0.49)
	{
		name = "Crappy treasure";
	}
	else if (m < 0.99)
	{
		name = "Dislikeable treasure";
	}
	else if (m < 1.24)
	{
		name = "Normal treasure";
	}
	else if (m < 1.99)
	{
		name = "Good treasure";
	}
	else if (m < 3.99)
	{
		name = "Amazing treasure";
	}
	else
	{
		name = "Supercalifragilisticexpialidocious treasure";
	}
}

void Treasure::claim_reward(Player& p)
{
	std::cout << p.name << " found " << name << " chest!" << std::endl << std::endl;

	delay(2);

    double coin_reward{ multiplier * p.level * 15 };

	int n{ rand_num(1, 80) };
	int n2{ rand_num(1, 80) };

	print_line('=', width);
	std::cout << std::endl;

	std::cout << std::setw(print_center("Rewards", width)) << std::right << "Rewards" << std::endl;
	std::cout << std::endl;

	std::cout << "Coins : " << coin_reward << std::endl << std::endl;
	p.coins += coin_reward;

	int e{ rand_num(std::floor(std::ceil(multiplier) * std::ceil(multiplier) * -1), 100) };

	if (e < 1)
	{
		e = std::round(5.00 * p.max_energy / 5.00);
		std::cout << "Energy : " << e << std::endl << std::endl;
		p.energy += e;
	}
	else if (e < 2)
	{
		e = std::round(4.00 * p.max_energy / 5.00);
		std::cout << "Energy : " << e << std::endl << std::endl;
		p.energy += e;
	}
	else if (e < 5)
	{
		e = std::round(3.00 * p.max_energy / 5.00);
		std::cout << "Energy : " << e << std::endl << std::endl;
		p.energy += e;
	}
	else if (e < 12)
	{
		e = std::round(2.00 * p.max_energy / 5.00);
		std::cout << "Energy : " << e << std::endl << std::endl;
		p.energy += e;
	}
	else if (e < 31)
	{
		
		e = std::round(1 * p.max_energy / 5);
		std::cout << "Energy : " << e << std::endl << std::endl;
		p.energy += e;
	}

	if (p.energy > p.max_energy)
	{
		p.energy = p.max_energy;
	}

	for (int i = 0; i < std::round(multiplier); i++)
	{
		if (n <= 50)
		{
			Weapon* weapon_reward = make_weapon(p, "None", true);
			std::cout << *weapon_reward << std::endl;
			p.inventory.push_back(weapon_reward);
		}

		if (n2 <= 50)
		{
			Food* food_reward = make_food(p, "None", true);
			std::cout << *food_reward;
			p.inventory.push_back(food_reward);
		}
	}

	std::cout << std::endl;
	print_line('=', width);
	std::cout << std::endl;

	p.manage_inventory();
}