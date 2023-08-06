#include "Item.h"
#include "Player.h"

void Item::use(Player& p)
{
	p.manage_inventory();
}