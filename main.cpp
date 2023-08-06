#include <iomanip>
#include <random>
#include <sstream>

#include "Player.h"
#include "Monster.h"

#include "Make.h"
#include "Delay.h"
#include "ConsoleUtils.h"
#include "RandomNumber.h"

#include "Treasure.h"

const double level_increase{ 0.010 };
std::ostream& operator<<(std::ostream& os, const I_Printable& p);
void battle(Player& p, Monster& m);
void explore(Player& p);
void gamble(Player& p);
void shop(Player& p);
void print_menu();

int main()
{

	std::cout << std::fixed << std::setprecision(2);
	bool quit{ false };

	Player player;

	std::cout << std::setw(print_center("Epic RPG Game", width)) << std::right << "Epic RPG Game" << std::endl << std::endl;
	
	print_line('=', width);
	print_line('-', width);
	print_line('~', width);
	print_line('-', width);
	print_line('=', width);
	std::cout << std::endl;
	
	while (!quit)
	{
		print_menu();
		bool valid_main_input{ false };
		player.manage_inventory();

		while (!valid_main_input)
		{
			std::cout << "Enter choice : ";
			char c;
			std::cin >> c;
			c = std::toupper(c);
			clear_input();
			valid_main_input = true;
			std::cout << std::endl;

			if (c == 'E')
			{
				explore(player);
			}
			else if (c == 'S')
			{
				shop(player);
			}
			else if (c == 'I')
			{
				std::cout << player << std::endl;
				player.display_inventory();

				if (player.inventory.size() > 0)
				{
					std::cout << "Enter item number: ";

					int i;
					std::cin >> i;
					i--;
					clear_input();

					if (i < player.inventory.size())
					{
						std::cout << std::endl;
						std::cout << *(player.inventory[i]) << std::endl;

						std::cout << "Use? (Y - N) : ";

						char c;
						std::cin >> c;
						clear_input();
						c = std::toupper(c);

						if (c == 'Y')
						{
							player.inventory[i]->use(player);
						}
						else
						{
							std::cout << "Use cancelled" << std::endl;
						}
						
					}
					else
					{
						std::cout << "Invalid number" << std::endl;
					}

					std::cout << std::endl;
				}
			}
			else if (c == 'C')
			{
				gamble(player);
			}
			else if (c == 'R')
			{
				const int delay_seconds{ 3 };

				std::cout << "Walking home..." << std::endl;

				delay(delay_seconds);

				std::cout << "Going to bed..." << std::endl;

				delay(delay_seconds);

				std::cout << "Sleeping..." << std::endl;

				delay(delay_seconds);

				const int energy_increase{ rand_num(1, 2) };
				const double health_increase{ rand_dec(player.max_health / 20, player.max_health / 5) };
				const double coin_increase{ rand_dec(1, 10) };

				if (player.energy + energy_increase < player.max_energy)
				{
					player.energy += energy_increase;
				}
				else
				{
					player.energy = player.max_energy;
				}

				if (player.health + health_increase < player.max_health)
				{
					player.health += health_increase;
				}
				else
				{
					player.health = player.max_health;
				}

				player.coins += coin_increase;

				std::cout << std::endl;

				std::cout << player.name << " gains " << energy_increase << " energy, " 
					<< health_increase << " health, and " << coin_increase << " coins, being left with "
					<< player.energy << " energy, " << player.health << " health, and " << player.coins << " coins!";

				std::cout << std::endl << std::endl;
				player.level += level_increase / 20;
			}
			else if(c == 'Q')
			{
				std::cout << "Quitting game..." << std::endl;
				delay(1);
				quit = true;
			}
			else
			{
				std::cout << "Invalid input" << std::endl;
				valid_main_input = false;
			}
		}
	}

	return 0;

}

std::ostream& operator<<(std::ostream& os, I_Printable& p)
{
	p.print(os);
	return os;
}

void battle(Player& p, Monster& m)
{
	std::string title{ p.name + " vs " + m.name };
	print_line('=', width);
	std::cout << std::endl;
	std::cout << std::setw(print_center(title, width)) << std::right << title << std::endl;
	std::cout << std::endl;

	print_line('-', width);
	std::cout << std::endl;

	bool first_time{ true };
	bool ran{ false };
	int attacks{ 0 };

	while (p.dead == false && m.dead == false && ran == false)
	{
		bool valid_battle_input{ false };
		p.manage_inventory();

		if (first_time)
		{
			while (!valid_battle_input)
			{
				valid_battle_input = true;
				std::cout << "Choose (A - attack, I - items, S - stats, R - run) : ";
				
				char c;
				std::cin >> c;
				clear_input();
			
				c = std::toupper(c);
				first_time = false;

				std::cout << std::endl;

				if (c == 'A')
				{
					std::cout << std::endl;
					p.weapon->attack(m, p);

					attacks++;
				}
				else if (c == 'I')
				{
					p.display_inventory();

					if (p.inventory.size() < 1)
					{
						valid_battle_input = false;
						break;
					}

					std::cout << "Enter item number: ";

					int i;
					std::cin >> i;
					i--;
					clear_input();

					if (i < p.inventory.size())
					{
						std::cout << std::endl;
						std::cout << *(p.inventory[i]) << std::endl;

						std::cout << "Use? (Y - N) : ";

						char c;
						std::cin >> c;
						clear_input();
						c = std::toupper(c);

						if (c == 'Y')
						{
							p.inventory[i]->use(p);
							valid_battle_input = false;
						}
						else
						{
							std::cout << "Use cancelled" << std::endl;
							valid_battle_input = false;
						}
					}
					else
					{
						std::cout << "Invalid number" << std::endl;
						valid_battle_input = false;
					}

					std::cout << std::endl;
				}
				else if (c == 'S')
				{
					std::cout << std::endl << p << m << std::endl;
					valid_battle_input = false;
				}
				else if (c == 'R')
				{
					std::cout << std::endl << p.name << " runs away!" << std::endl;
					ran = true;
					break;
				}
				else
				{
					std::cout << "Invalid input" << std::endl << std::endl;
					valid_battle_input = false;
				}
			}
		}
		else
		{
			while (!valid_battle_input)
			{
				valid_battle_input = true;
				std::cout << "Choose (A - attack, I - items, S - stats) : ";

				char c;
				std::cin >> c;
				clear_input();
				c = std::toupper(c);

				if (c == 'A')
				{
					std::cout << std::endl;
					p.weapon->attack(m, p);

					attacks++;
				}
				else if (c == 'I')
				{
					p.display_inventory();

					if (p.inventory.size() < 1)
					{
						valid_battle_input = false;
						break;
					}

					std::cout << "Enter item number: ";

					int i;
					std::cin >> i;
					i--;
					clear_input();

					if (i < p.inventory.size())
					{
						std::cout << std::endl;
						std::cout << *(p.inventory[i]) << std::endl;

						std::cout << "Use? (Y - N) : ";

						char c;
						std::cin >> c;
						clear_input();
						c = std::toupper(c);

						if (c == 'Y')
						{
							p.inventory[i]->use(p);
						}
						else
						{
							std::cout << "Use cancelled" << std::endl;
							valid_battle_input = false;
						}
					}
					else
					{
						std::cout << "Invalid number" << std::endl;
					}

					std::cout << std::endl;
				}
				else if (c == 'S')
				{
					std::cout << std::endl << p << m << std::endl;
					valid_battle_input = false;
				}
				else
				{
					std::cout << "Invalid input" << std::endl << std::endl;
					valid_battle_input = false;
				}
			}
		}
		
		if (p.weapon->name == "God Greatsword" && attacks == 1)
		{
			p.health *= 5;
			std::cout << "The " << p.weapon->name << " ramps up " << p.name << "'s health to " << p.health << "!" << std::endl;
		}

		if (!m.dead && !ran)
		{
			m.attack(p);

			if (!p.dead)
			{
				p.weapon->special(m, p);
			}

			if (!m.dead)
			{
				m.special(p);
			}
		}

		std::cout << std::endl;
	}

	delay(1);

	if (m.dead)
	{
		std::cout << p.name << " wins the battle with " << p.health << " hp remaining!" << std::endl;

		delay(1);

		m.reward(p);
		p.level += level_increase;
		p.health += (p.max_health - p.health) / 2;

		if (p.level + level_increase < 2)
		{
			p.level += level_increase;
		}
	}
	else
	{
		const int steal_min{ 1 };
		int steal_max{ 8 };

		if (ran)
		{
			steal_max = 2;
		}

		int steal{ rand_num(steal_min, steal_max) };
		double stolen_coins{ p.coins * static_cast<double>(steal) / 100 };

		p.coins -= stolen_coins;
		std::cout << m.name << " wins the battle and steals " << stolen_coins << " coins!" << std::endl;
		std::cout << p.name << " is left with " << p.coins << " coins!" << std::endl;

		std::cout << std::endl;

		p.level += level_increase / 2;
		p.health = p.max_health / 2;
		p.dead = false;

		if (p.level + (level_increase / 2) < 2)
		{
			p.level += level_increase / 2;
		}

		delay(3);
	}

	print_line('=', width);
	std::cout << std::endl;

	p.manage_stats();
	p.manage_inventory();
}

void explore(Player& p)
{
	if (p.energy > 0)
	{
		int k{ rand_num(1, 60) };
		double d{ 0 };
		int n{ rand_num(1, 675) };

		if (n < 15)
		{
			d = rand_dec(0.01, 0.19);
		}
		else if (n < 45)
		{
			d = rand_dec(0.19, 0.49);
		}
		else if (n < 75)
		{
			d = rand_dec(0.49, 0.99);
		}
		else if (n < 540)
		{
			d = rand_dec(0.99, 1.24);
		}
		else if (n < 615)
		{
			d = rand_dec(1.24, 1.99);
		}
		else if (n < 660)
		{
			d = rand_dec(1.99, 3.99);
		}
		else
		{
			d = rand_dec(3.99, 10);
		}

		if (k < 50)
		{
			Monster* m = make_monster(d, p, "None", true);
			
			p.weapon->initialize(*m);

			std::cout << "A " << m->name << " approaches " << p.name << "..." << std::endl << std::endl;
			delay(2);
			battle(p, *m);
			p.energy--;
		}
		else
		{
			p.energy--;
			Treasure treasure{ d };
			treasure.claim_reward(p);

			if (p.level + (level_increase / 2) < 2)
			{
				p.level += level_increase / 2;
			}
		}
		
		std::cout << "Energy left : " << p.energy << "/" << p.max_energy << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "You don't have enough energy to explore..." << std::endl << std::endl;
	}

	p.manage_inventory();
}

void gamble(Player& p)
{
	bool valid_coins{ false };
	
	while (!valid_coins)
	{
		std::cout << "Enter coins (5 or over) : ";

		int c{ 0 };
		std::cin >> c;
		clear_input();
		
		if (c <= p.coins && c >= 5)
		{
			valid_coins = true;
			bool valid_risk{ false };

			while(!valid_risk)
			{
				std::cout << "Enter risk (over 1) : ";

				int r{ 0 };
				std::cin >> r;
				clear_input();

				if (r > 1)
				{
					valid_risk = true;

					int n{ rand_num(1, r) };
					int result{ 0 };

					std::cout << "..." << std::endl;
					delay(3);

					if (n == 1)
					{
						result = c * r;
						p.coins += result;
						std::cout << p.name << " won " << result << " coins!" << std::endl;
					}
					else
					{
						result = c;
						p.coins -= result;
						std::cout << p.name << " lost " << result << " coins..." << std::endl;
					}

					std::cout << std::endl;
				}
				else
				{
					std::cout << "Invalid risk" << std::endl;
				}
			}
		}
		else
		{
			std::cout << "You don't have enough coins" << std::endl;
		}
	}
}

void shop(Player& p)
{
	const int setw_name{ 25 };
	const int setw_price{ 0 };

	print_line('=', width);
	std::cout << std::endl;
	std::cout << std::setw(print_center("Shop", width)) << std::right << "Shop" << std::endl << std::endl;

	
	int item_size{ rand_num(15, 20) };
	std::vector<Item*> items{ static_cast<unsigned>(item_size) };

	print_line('-', width);

	std::cout << std::endl;
	std::cout << "Items" << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < items.size(); i++)
	{
		items[i] = make_item(p, "None", true);
		items[i]->index = i;

		std::string n{ std::to_string(i + 1) };
		std::string s{ n + ". " + items[i]->name };

		std::cout << std::setw(setw_name) << std::left 
			<< s << std::setw(setw_price) << std::left << "|  " << items[i]->worth << "$" << std::endl;
	}

	std::cout << std::endl;
	print_line('-', width);

	std::cout << std::endl << "Buffs" << std::endl << std::endl;

	const double max_energy_price{ 15.00 };
	const double max_health_price{ 2.50 };
	const double damage_price{ 20.00 };
	const double evasion_price{ 10.00 };

	std::cout << std::setw(setw_name) << std::left << "M - Increase max energy"
		<< std::setw(setw_price) << std::right << "|  " << max_energy_price << "$" << std::endl;

	std::cout << std::setw(setw_name) << std::left << "H - Increase max health"
		<< std::setw(setw_price) << std::right << "|  " << max_health_price << "$" << std::endl;

	std::cout << std::setw(setw_name) << std::left << "D - Increase damage"
		<< std::setw(setw_price) << std::right << "|  " << damage_price << "$" << std::endl;

	std::cout << std::setw(setw_name) << std::left << "E - Increase evasion"
		<< std::setw(setw_price) << std::right << "|  " << evasion_price << "$" << std::endl;

	std::cout << std::endl;
	print_line('-', width);

	std::cout << std::endl;
	print_line('=', width);

	bool valid_shop_input{ false };

	while (!valid_shop_input)
	{
		
		for (int i = 0; i < items.size(); i++)
		{
			items[i] = make_item(p, items[i]->name);
			items[i]->index = i;
		}

		std::cout << std::endl; 
		std::cout << "You have " << p.coins << " coins" << std::endl << std::endl;
		std::cout << "Enter buying choice (Q - exit, S - sell) : ";

		char c;
		std::string s;
		std::cin >> s;
		c = std::toupper(s[0]);
		clear_input();
		bool print_options{ true };

		if (c != 'Q')
		{
			if (isdigit(c))
			{
				int n{ std::stoi(s) };
				n--;

				if (n < items.size())
				{
					if (items[n]->worth <= p.coins)
					{
						std::cout << std::endl << *items[n] << std::endl;

						std::cout << "Confirm purchase? (Y - N) : ";
						std::cin >> c;
						clear_input();
						c = std::toupper(c);

						if (c == 'Y')
						{
							std::cout << p.name << " buys " << items[n]->name << " for " << items[n]->worth << " coins" 
								<< std::endl;

							p.level += level_increase / 10;

							delay(1);

							p.inventory.push_back(make_item(p, items[n]->name));
							p.coins -= items[n]->worth;

							auto it = items.begin() + n;
							items.erase(it);

							std::cout << std::endl;

							print_line('-', width);

							std::cout << std::endl;
							std::cout << "Items" << std::endl;
							std::cout << std::endl;

							for (int i = 0; i < items.size(); i++)
							{
								items[i]->index = i;
								std::string n{ std::to_string(i + 1) };
								std::string s{ n + ". " + items[i]->name };

								std::cout << std::setw(setw_name) << std::left
									<< s << std::setw(setw_price) << std::left << "|  " << items[i]->worth << "$" << std::endl;
							}

							std::cout << std::endl;
							print_line('-', width);

							std::cout << std::endl << "Buffs" << std::endl << std::endl;

							std::cout << std::setw(setw_name) << std::left << "M - Increase max energy"
								<< std::setw(setw_price) << std::right << "|  " << max_energy_price << "$" << std::endl;

							std::cout << std::setw(setw_name) << std::left << "H - Increase max health"
								<< std::setw(setw_price) << std::right << "|  " << max_health_price << "$" << std::endl;

							std::cout << std::setw(setw_name) << std::left << "D - Increase damage"
								<< std::setw(setw_price) << std::right << "|  " << damage_price << "$" << std::endl;

							std::cout << std::setw(setw_name) << std::left << "E - Increase evasion"
								<< std::setw(setw_price) << std::right << "|  " << evasion_price << "$" << std::endl;

							std::cout << std::endl;
							print_line('-', width);
						}
						else
						{
							std::cout << "Purchase cancelled" << std::endl;
						}
					}
					else
					{
						std::cout << "Not enough coins" << std::endl;
						std::cout << std::endl;
					}
				}
				else
				{
					std::cout << "Index out of range" << std::endl;
				}
			}
			else
			{

				if (c == 'M')
				{
					std::cout << "Enter how many times you want to buy : ";

					int n{ 0 };
					std::cin >> n;
					clear_input();

					if (n > 0)
					{
						double cost{ n * max_energy_price };

						if (cost <= p.coins)
						{
							std::cout << p.name << " buys " << n << " max energy for " << cost << " coins" << std::endl;
							p.max_energy += n;
							p.coins -= cost;

							p.level += level_increase;
						}
						else
						{
							std::cout << "Not enough coins" << std::endl;
							std::cout << std::endl;
						}
					}
					else
					{
						std::cout << "Invalid number" << std::endl;
					}
				}
				else if (c == 'H')
				{
					std::cout << "Enter how many times you want to buy : ";

					double n{ 0 };
					std::cin >> n;
					clear_input();
					
					if (n > 0)
					{
						double cost{ n * max_health_price };

						if (cost <= p.coins)
						{
							std::cout << p.name << " buys " << n << " max health for " << cost << " coins" << std::endl;
							p.max_health += n;
							p.coins -= cost;

							p.level += level_increase;
						}
						else
						{
							std::cout << "Not enough coins" << std::endl;
							std::cout << std::endl;
						}
					}
					else
					{
						std::cout << "Invalid number" << std::endl;
					}
				}
				else if (c == 'D')
				{
					std::cout << "Enter how many times you want to buy : ";

					int n{ 0 };
					std::cin >> n;
					clear_input();

					if (n > 0)
					{
						double cost{ n * damage_price };

						if (cost <= p.coins)
						{
							std::cout << p.name << " buys " << n << " damage for " << cost << " coins" << std::endl;
							p.damage += n;
							p.og_damage += n;
							p.coins -= cost;

							p.level += level_increase;
						}
						else
						{
							std::cout << "Not enough coins" << std::endl;
							std::cout << std::endl;
						}
					}
					else
					{
						std::cout << "Invalid number" << std::endl;
					}
				}
				else if (c == 'E')
				{
					std::cout << "Enter how many times you want to buy : ";

					int n{ 0 };
					std::cin >> n;
					clear_input();

					if (n > 0)
					{
						double cost{ n * evasion_price };

						if (cost <= p.coins)
						{
							std::cout << p.name << " buys " << n << " evasion for " << cost << " coins" << std::endl;
							p.evasion += n;
							p.og_evasion += n;
							p.coins -= cost;

							p.level += level_increase;
						}
						else
						{
							std::cout << "Not enough coins" << std::endl;
							std::cout << std::endl;
						}
					}
					else
					{
						std::cout << "Invalid number" << std::endl;
					}
				}
				else if (c == 'S')
				{
					std::cout << std::endl;

					if (p.inventory.size() > 0)
					{
						print_line('=', width);

						std::cout << std::endl;
						std::cout << std::setw(print_center("Inventory", width)) << std::right << "Inventory";
						std::cout << std::endl << std::endl;

						for (int i = 0; i < p.inventory.size(); i++)
						{
							std::string n{ std::to_string(i + 1) };
							std::string s{ n + ". " + p.inventory[i]->name };
							p.inventory[i]->index = i;

							std::cout << std::setw(setw_name) << std::left
								<< s << std::setw(setw_price) << std::left << "|  " 
								<< p.inventory[i]->selling_value << "$" << std::endl;
						}

						std::cout << std::endl;
						print_line('=', width);
						std::cout << std::endl;

						std::cout << "Choose item to sell : ";
						int i;
						std::cin >> i;
						clear_input();
						i--;

						if (i < p.inventory.size())
						{
							std::cout << std::endl;
							std::cout << *(p.inventory[i]) << std::endl;

							std::cout << "Confirm sell? (Y - N) : ";

							char c;
							std::cin >> c;
							clear_input();
							c = std::toupper(c);

							if (c == 'Y')
							{
								std::cout << p.name << " sells " << p.inventory[i]->name << " for "
									<< p.inventory[i]->selling_value << " coins" << std::endl;

								p.level += level_increase / 15;

								p.coins += p.inventory[i]->selling_value;

								auto it = p.inventory.begin() + i;
								p.inventory.erase(it);
							}
							else
							{
								std::cout << "Sell cancelled" << std::endl;
							}
						}
						else
						{
							std::cout << "Index out of range" << std::endl;
						}
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
				else
				{
					std::cout << "Invalid input" << std::endl << std::endl;
					print_options = false;
				}		

				delay(1);

				if (print_options)
				{
					std::cout << std::endl;
					print_line('-', width);

					std::cout << std::endl;
					std::cout << "Items" << std::endl;
					std::cout << std::endl;

					for (int i = 0; i < items.size(); i++)
					{
						items[i]->index = i;
						std::string n{ std::to_string(i + 1) };
						std::string s{ n + ". " + items[i]->name };

						std::cout << std::setw(setw_name) << std::left
							<< s << std::setw(setw_price) << std::left << "|  " << items[i]->worth << "$" << std::endl;
					}
				
					std::cout << std::endl;
					print_line('-', width);

					std::cout << std::endl << "Buffs" << std::endl << std::endl;

					std::cout << std::setw(setw_name) << std::left << "M - Increase max energy"
						<< std::setw(setw_price) << std::right << "|  " << max_energy_price << "$" << std::endl;

					std::cout << std::setw(setw_name) << std::left << "H - Increase max health"
						<< std::setw(setw_price) << std::right << "|  " << max_health_price << "$" << std::endl;

					std::cout << std::setw(setw_name) << std::left << "D - Increase damage"
						<< std::setw(setw_price) << std::right << "|  " << damage_price << "$" << std::endl;

					std::cout << std::setw(setw_name) << std::left << "E - Increase evasion"
						<< std::setw(setw_price) << std::right << "|  " << evasion_price << "$" << std::endl;

					std::cout << std::endl;
					print_line('-', width);
				}
			}
		}
		else
		{
			std::cout << std::endl;
			valid_shop_input = true;
		}

	}

	p.manage_inventory();
}

void print_menu()
{
	std::cout << "E - Explore" << std::endl;
	std::cout << "S - Shop" << std::endl;
	std::cout << "I - Items" << std::endl;
	std::cout << "C - Casino" << std::endl;
	std::cout << "R - Rest" << std::endl;
	std::cout << "Q - Quit" << std::endl << std::endl;
}