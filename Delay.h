#pragma once
#include <chrono>
#include <thread>
#include <iostream>

inline void delay(int d)
{
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds

    sleep_for(nanoseconds(d));
    sleep_until(system_clock::now() + seconds(d));
}