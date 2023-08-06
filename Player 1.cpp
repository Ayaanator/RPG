#include <fstream>
#include <vector>
#include "Player.h"

Player::Player()
{
	std::ifstream i_file{ "player.txt" };
	std::string line;

	std::getline(i_file, line);
	name = line;
	
	i_file >> health >> max_health >> damage >> evasion >> energy >> max_energy;
	
	std::getline(i_file, line);
	std::getline(i_file, line);
	weapon_name = line;

	if (weapon_name == "Fragile Sword")
	{
		weapon = std::make_unique<FragileSword>();
	}
	else if (weapon_name == "Fists")
	{
		weapon = std::make_unique<Fists>();
	}

	i_file.close();
}

Player::~Player()
{
	std::ofstream o_file{ "player.txt", std::ios::trunc };

	o_file << name << std::endl;
	o_file << health << std::endl;
	o_file << max_health << std::endl;
	o_file << damage << std::endl;
	o_file << evasion << std::endl;
	o_file << energy << std::endl;
	o_file << max_energy << std::endl;
	o_file << weapon_name << std::endl;
}

void Player::recieve_damage(double d)
{
	if (health < d)
	{
		health = 0;
	}
	else
	{
		health -= d;
	}
}