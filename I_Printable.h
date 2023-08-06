#pragma once
#include <iostream>

class I_Printable
{
	friend std::ostream& operator<<(std::ostream& os, I_Printable& p);
public:
	I_Printable() = default;
	virtual ~I_Printable() = default;
	virtual void print(std::ostream& os) = 0;
};