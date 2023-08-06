#include "PhantomPepper.h"

PhantomPepper::PhantomPepper(const Player& p, double* ptr, double* ptr_max, double sm, double w, std::string n,
	std::string desc, std::string d, std::string i_s, int i)
: Food{ p, ptr, ptr_max, sm, w, n, desc, d, i_s, i }
{

}