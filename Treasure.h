#pragma once
#include <string>

class Player;

class Treasure
{
public:
    std::string name;
    double multiplier{ 0 };
    
    Treasure(double m);
    ~Treasure() = default;

    void claim_reward(Player& p);
};