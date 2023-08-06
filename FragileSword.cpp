#include "FragileSword.h"
#include "Player.h"

FragileSword::FragileSword(Player& p, Rarity r, std::string n, std::string desc, double dm, double cm, double a, double cr, double w)
: Weapon{ p, r, n, desc, dm, cm, a, cr, w }
{

}