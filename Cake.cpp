#include "Cake.h"
#include "Player.h"

Cake::Cake(const Player& p, double* ptr, double* ptr_max, double sm, double w, std::string n,
	std::string desc, std::string d, std::string i_s, int i)
: Food{ p, ptr, ptr_max, sm, w, n, desc, d, i_s, i }
{

}

void Cake::use(Player& p)
{
	std::cout << p.name << " replenishes all of their health!" << std::endl;
	p.health = p.max_health;

	std::vector<Item*>::iterator it = p.inventory.begin() + index;
	p.inventory.erase(it);

	Item::use(p);
}