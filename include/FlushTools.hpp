#ifndef FLUSH_TOOLS_HPP_
#define FLUSH_TOOLS_HPP_

#include <iostream>
#include <random>
#include <chrono>
#include <climits>


class FlushTools {
public:
    int randomGen(unsigned long long min_val = 0, 
                    unsigned long long max_val = ULLONG_MAX);
};

#endif // FLUSH_TOOLS_HPP