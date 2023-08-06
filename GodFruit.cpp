#include "GodFruit.h"
#include "Player.h"

#include "Delay.h"

GodFruit::GodFruit(const Player& p, double* ptr, double* ptr_max, double sm, double w, std::string n,
	std::string desc, std::string d, std::string i_s, int i)
: Food{ p, ptr, ptr_max, sm, w, n, desc, d, i_s, i }
{

}

void GodFruit::use(Player& p)
{
	p.health *= multiplier;
	p.damage *= multiplier;
	p.evasion *= multiplier;

	std::cout << p.name << " eats the fruit..." << std::endl;

	delay(2);

	std::cout << p.name << "'s stats get multiplied by " << multiplier << "!!!" << std::endl;

	delay(2);

	std::cout << std::endl;

	if (p.evasion > 80)
	{
		p.evasion = 80;
	}

	std::cout << "Health : " << p.health << std::endl;
	std::cout << "Damage : " << p.damage << std::endl;
	std::cout << "Evasion : " << p.evasion << std::endl;
}