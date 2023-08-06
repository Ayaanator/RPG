#pragma once

class Player;
class Item;
class Weapon;
class Food;
class Monster;

Weapon* make_weapon(Player& p, std::string n, bool rand = false);
Item* make_item(Player& p, std::string n, bool rand = false);
Food* make_food(Player& p, std::string n, bool rand = false);
Monster* make_monster(double m, Player& p, std::string n = "None", bool rand = false);