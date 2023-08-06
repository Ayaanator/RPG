#include "Weapon.h"

Weapon::Weapon(Rarity r, std::string n, std::string d, double dm, double cm, double a)
: rarity{ r }, name{ n }, description{ d },
	damage_multiplier{ dm }, critical_multiplier{ cm }, accuracy{ a }
{

}

void Weapon::attack(Monster &m)
{
	m.recieve_damage(damage_multiplier);
	special(m);
}

void Weapon::special(Monster &m)
{

}