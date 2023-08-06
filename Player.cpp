#include <fstream>
#include <vector>
#include <typeinfo>

#include "Player.h"

#include "Make.h"
#include "ConsoleUtils.h"
#include "RandomNumber.h"

#include "FragileSword.h"
#include "StoneHammer.h"

#include "Apple.h"

Player::Player()
{
	std::string line;

	//Stats and weapon
	std::ifstream i_player_file{ "player.txt" };

	std::getline(i_player_file, line);
	name = line;

	i_player_file >> health >> max_health >> damage >> evasion >> energy >> max_energy
		>> coins >> level;

	og_damage = damage;
	og_evasion = evasion;

	max_damage = og_damage * max_multiplier;
	max_evasion = og_evasion * max_multiplier;

	std::getline(i_player_file, line);
	std::getline(i_player_file, line);
	weapon_name = line;

	weapon = make_weapon(*this, line);

	i_player_file.close();

	//Inventory
	std::ifstream i_inventory_file{ "inventory.txt" };

	while (std::getline(i_inventory_file, line))
	{
		Item* temp = make_item(*this, line);
		inventory.push_back(temp);
	}

	manage_inventory();

	i_inventory_file.close();
}

Player::~Player()
{
	std::ofstream o_player_file{ "player.txt", std::ios::trunc };

	o_player_file << name << std::endl;
	o_player_file << health << std::endl;
	o_player_file << max_health << std::endl;
	o_player_file << damage << std::endl;
	o_player_file << evasion << std::endl;
	o_player_file << energy << std::endl;
	o_player_file << max_energy << std::endl;
	o_player_file << coins << std::endl;
	o_player_file << level << std::endl;
	o_player_file << weapon_name << std::endl;

	o_player_file.close();

	std::ofstream o_inventory_file{ "inventory.txt", std::ios::trunc };

	for (int i = 0; i < static_cast<int>(inventory.size()); i++)
	{
		o_inventory_file << inventory[i]->name << std::endl;
	}

	o_inventory_file.close();
	delete weapon;
	
}

bool Player::recieve_damage(double d, bool dodgeable)
{
	if (rand_num(0, 100) <= evasion && dodgeable == true)
	{
		std::cout << name << " dodges the attack!" << std::endl;
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

void Player::display_inventory()
{
	if (inventory.size() > 0)
	{
		print_line('=', width);

		std::cout << std::endl;
		std::cout << std::setw(print_center("Inventory", width)) << std::right << "Inventory";
		std::cout << std::endl << std::endl;

		for (int i = 1; static_cast<unsigned>(i) <= inventory.size(); i++)
		{
			std::cout << i << ". " << inventory[i - 1]->name << std::endl;
		}

		std::cout << std::endl;
		print_line('=', width);
		std::cout << std::endl;
	}
	else
	{
		print_line('=', width);

		std::cout << std::endl;
		std::cout << std::setw(print_center("Inventory is empty...", width)) << std::right << "Inventory is empty...";
		std::cout << std::endl << std::endl;

		print_line('=', width);
		std::cout << std::endl;
	}
}

void Player::manage_inventory()
{
	weapon = make_weapon(*this, weapon_name);

	for (int i = 0; i < inventory.size(); i++)
	{
		inventory[i] = make_item(*this, inventory[i]->name);
		inventory[i]->index = i;
	}
}

void Player::manage_stats()
{
	damage = og_damage;
	evasion = og_evasion;

	max_damage = og_damage * max_multiplier;
	max_evasion = og_evasion * max_multiplier;

	if (health > max_health)
	{
		health = max_health;
	}

	if (level > 1.95)
	{
		level = 1.95;
	}
}

void Player::print(std::ostream& os)
{
	print_line('=', width);

	os << std::endl << std::setw(print_center(name, width)) << std::right << name << std::endl << std::endl;

	print_left_right("Damage", std::to_string(damage), width, os);
	print_left_right("Health", std::to_string(health), width, os);
	print_left_right("Max health", std::to_string(max_health), width, os);
	print_left_right("Evasion", std::to_string(evasion), width, os);
	print_left_right("Energy", std::to_string(energy), width, os);
	print_left_right("Max energy", std::to_string(max_energy), width, os);
	print_left_right("Coins", std::to_string(coins), width, os);

	std::cout << std::endl << *weapon << std::endl;

	print_line('=', width);

}
