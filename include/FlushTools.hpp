#ifndef FlushTools_hpp
#define FlushTools_hpp

#include <iostream>
#include <random>
#include <chrono>
#include <climits>


class FlushTools {
public:
    int randomGen(unsigned long long min_val = 0, unsigned long long max_val = ULLONG_MAX);
};

#endif