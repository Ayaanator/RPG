#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>

const char line_char{ '=' };
const int width{ 85 };
const int half_width{ width / 2 };

inline void print_line(char c, int w)
{
	for (int i = 0; i < w; i++)
	{
		std::cout << c;
	}

	std::cout << std::endl;
}

inline void print_left_right(std::string s1, std::string s2, int w, std::ostream &os)
{
	os << std::setw(half_width) << std::left << s1
		<< std::setw(half_width) << std::right << s2 << std::endl;
}

inline void print_left_right(std::string s1, std::string s2)
{
	std::cout << std::setw(half_width) << std::left << s1
		<< std::setw(half_width) << std::right << s2 << std::endl;
}

inline int print_center(std::string s, int w)
{
	return (width / 2) + (s.size() / 2);
}

inline void clear_input()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}