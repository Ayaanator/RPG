#include <string>
#include <array>

#include "Make.h"
#include "Player.h"

#include "RandomNumber.h"

#include "Item.h"

#include "Weapon.h"
#include "FragileSword.h"
#include "StoneHammer.h"
#include "FireSword.h"
#include "PoisonDaggers.h"
#include "NatureAxe.h"
#include "DeathScythe.h"
#include "Dice.h"
#include "GodGreatsword.h"

#include "Food.h"
#include "Apple.h"
#include "Pie.h"
#include "Cake.h"
#include "EnergyDrink.h"
#include "EnergyPotion.h"
#include "PhantomPepper.h"
#include "StrengthSyringe.h"
#include "ReflexJuice.h"
#include "SpeedSteak.h"
#include "GodFruit.h"

#include "Monster.h"
#include "Goblin.h"
#include "Golem.h"
#include "GrimReaper.h"
#include "Dragon.h"
#include "SnakeSerpent.h"
#include "ArmoredGuardian.h"
#include "Titan.h"

Item* make_item(Player& p, std::string n, bool rand)
{
	Item* temp = new FragileSword(p);

	if (!rand)
	{
		if(n == "Fragile Sword" || n == "Stone Hammer" || n == "Fire Sword" || n == "Poison Daggers" || 
			n == "Nature Axe" || n == "Death Scythe" || n == "Dice")
		{ 
			temp = make_weapon(p, n);
		}
		else
		{
			temp = make_food(p, n);
		}
	}
	else
	{
		int n{ rand_num(1, 3) };

		if (n == 1)
		{
			temp = make_weapon(p, "None", true);
		}
		else
		{
			temp = make_food(p, "None", true);
		}
	}
	
	return temp;
}

Weapon* make_weapon(Player& p, std::string n, bool rand)
{
	Weapon* temp = new FragileSword(p);

	if (!rand)
	{
		if (n == "Fragile Sword")
		{
			temp = new FragileSword(p);
		}
		else if (n == "Stone Hammer")
		{
			temp = new StoneHammer(p);
		}
		else if (n == "Fire Sword")
		{
			temp = new FireSword(p);
		}
		else if (n == "Poison Daggers")
		{
			temp = new PoisonDaggers(p);
		}
		else if (n == "Nature Axe")
		{
			temp = new NatureAxe(p);
		}
		else if (n == "Death Scythe")
		{
			temp = new DeathScythe(p);
		}
		else if (n == "Dice")
		{
			temp = new Dice(p);
		}
		else if (n == "God Greatsword")
		{
			temp = new GodGreatsword(p);
		}
	}
	else
	{
		int n{ rand_num(1, 8) };

		if (n == 1)
		{
			temp = new FragileSword(p);
		}
		else if (n == 2)
		{
			temp = new StoneHammer(p);
		}
		else if (n == 3)
		{
			temp = new FireSword(p);
		}
		else if (n == 4)
		{
			temp = new PoisonDaggers(p);
		}
		else if (n == 5)
		{
			temp = new NatureAxe(p);
		}
		else if (n == 6)
		{
			temp = new DeathScythe(p);
		}
		else if (n == 7)
		{
			temp = new Dice(p);
		}
		else if (n == 8)
		{
			temp = new GodGreatsword(p);
		}
	}
	
	return temp;
}

Food* make_food(Player& p, std::string n, bool rand)
{
	Food* temp = new Food(p, &(p.health), &(p.max_health));

	if (!rand)
	{
		if (n == "Apple")
		{
			temp = new Apple(p, &(p.health), &(p.max_health));
		}
		else if (n == "Pie")
		{
			temp = new Pie(p, &(p.health), &(p.max_health));
		}
		else if (n == "Cake")
		{
			temp = new Cake(p, &(p.health), &(p.max_health));
		}
		else if (n == "Energy Drink")
		{
			temp = new EnergyDrink(p, &(p.energy), &(p.max_energy));
		}
		else if (n == "Energy Potion")
		{
			temp = new EnergyPotion(p, &(p.energy), &(p.max_energy));
		}
		else if (n == "Phantom Pepper")
		{
			temp = new PhantomPepper(p, &(p.damage), &(p.max_damage));
		}
		else if (n == "Strength Syringe")
		{
			temp = new StrengthSyringe(p, &(p.damage), &(p.max_damage));
		}
		else if (n == "Reflex Juice")
		{
			temp = new ReflexJuice(p, &(p.evasion), &(p.max_evasion));
		}
		else if (n == "Speed Steak")
		{
			temp = new SpeedSteak(p, &(p.evasion), &(p.max_evasion));
		}
		else if (n == "God Fruit")
		{
			double d{ 1 };
			temp = new GodFruit(p, &(p.damage), &(d));
		}
	}
	else
	{
		int n{ rand_num(1, 10) };

		if (n == 1)
		{
			temp = new Apple(p, &(p.health), &(p.max_health));
		}
		else if (n == 2)
		{
			temp = new Pie(p, &(p.health), &(p.max_health));
		}
		else if (n == 3)
		{
			temp = new Cake(p, &(p.health), &(p.max_health));
		}
		else if (n == 4)
		{
			temp = new EnergyDrink(p, &(p.energy), &(p.max_energy));
		}
		else if (n == 5)
		{
			temp = new EnergyPotion(p, &(p.energy), &(p.max_energy));
		}
		else if (n == 6)
		{
			temp = new PhantomPepper(p, &(p.damage), &(p.max_damage));
		}
		else if (n == 7)
		{
			temp = new StrengthSyringe(p, &(p.damage), &(p.max_damage));
		}
		else if (n == 8)
		{
			temp = new ReflexJuice(p, &(p.evasion), &(p.max_evasion));
		}
		else if (n == 9)
		{
			temp = new SpeedSteak(p, &(p.evasion), &(p.max_evasion));
		}
		else if (n == 10)
		{
			temp = new GodFruit(p, &(p.damage), &(p.max_damage));
		}
	}
	
	return temp;
}

Monster* make_monster(double m, Player& p, std::string n, bool rand)
{
	Monster* temp = new Monster(m, p);

	if (!rand)
	{
		if (n == "Goblin")
		{
			temp = new Goblin(m, p);
		}
		else if (n == "Goblin")
		{
			temp = new Golem(m, p);
		}
		else if (n == "Grim Reaper")
		{
			temp = new GrimReaper(m, p);
		}
		else if (n == "Dragon")
		{
			temp = new Dragon(m, p);
		}
		else if (n == "Snake Serpent")
		{
			temp = new SnakeSerpent(m, p);
		}
		else if (n == "Armored Guardian")
		{
			temp = new ArmoredGuardian(m, p);
		}
		else if (n == "Titan")
		{
			temp = new Titan(m, p);
		}
	}
	else
	{
		int n{ rand_num(1, 7) };

		if (n == 1)
		{
			temp = new Goblin(m, p);
		}
		else if (n == 2)
		{
			temp = new Golem(m, p);
		}
		else if (n == 3)
		{
			temp = new GrimReaper(m, p);
		}
		else if (n == 4)
		{
			temp = new Dragon(m, p);
		}
		else if (n == 5)
		{
			temp = new SnakeSerpent(m, p);
		}
		else if (n == 6)
		{
			temp = new ArmoredGuardian(m, p);
		}
		else if (n == 7)
		{
			temp = new Titan(m, p);
		}
	}

	return temp;
}