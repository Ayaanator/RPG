#include "Food.h"
#include "Player.h"

#include "ConsoleUtils.h"

Food::Food(const Player& p, double* ptr, double* ptr_max, double sm, double w, std::string n,
	std::string desc, std::string d, std::string i_s, int i)
: stat_multiplier{ sm }, stat_to_increase{ ptr }, max_stat{ ptr_max }, 
	stat_increase{ *max_stat * stat_multiplier }, does{ d }, increased_stat{ i_s }, Item{ w, n, desc }
{

}

void Food::use(Player& p)
{

	if (*stat_to_increase + stat_increase < *max_stat)
	{
		*stat_to_increase += stat_increase;
	}
	else
	{
		*stat_to_increase = *max_stat;
	}
	
	std::cout << p.name << " gains " << stat_increase << " " << increased_stat << ", being left with " 
		<< *stat_to_increase << " " << increased_stat << std::endl;

	std::vector<Item*>::iterator it = p.inventory.begin() + index;
	p.inventory.erase(it);
	
	Item::use(p);
}

void Food::print(std::ostream& os)
{
	print_line('-', width);

	os << std::endl << std::setw(print_center(name, width)) << std::right << name << std::endl << std::endl;

	std::cout << does << stat_increase << " " << increased_stat << std::endl;

	os << std::endl << std::setw(print_center(description, width)) << std::right << description << std::endl << std::endl;
	print_line('-', width);
}