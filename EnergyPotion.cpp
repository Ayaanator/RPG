#include "EnergyPotion.h"
#include "Player.h"

EnergyPotion::EnergyPotion(const Player& p, double* ptr, double* ptr_max, double sm, double w, std::string n,
	std::string desc, std::string d, std::string i_s, int i)
: Food{ p, ptr, ptr_max, sm, w, n, desc, d, i_s, i }
{

}

void EnergyPotion::use(Player& p)
{
	std::cout << p.name << " replenishes all of their energy!" << std::endl;
	p.energy = p.max_energy;

	std::vector<Item*>::iterator it = p.inventory.begin() + index;
	p.inventory.erase(it);

	Item::use(p);
}