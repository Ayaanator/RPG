#include "Titan.h"
#include "Player.h"

Titan::Titan(double m, Player& p, double hm, double dm, std::string n, double cm, double cr, double e,
	double a, std::string desc)
: Monster{ m, p, hm, dm, n, cm, cr, e, a, desc }
{

}