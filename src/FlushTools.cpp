#include "FlushTools.hpp"

int FlushTools::randomGen(unsigned long long min_val, unsigned long long max_val) {
  std::random_device rd;
  unsigned long long entropy = rd();
  auto seed =
      entropy ^ std::chrono::high_resolution_clock::now().time_since_epoch().count();
  std::mt19937 gen(seed);

  std::uniform_int_distribution<unsigned long long> dist(min_val, max_val);
  unsigned long long psudo_rand = dist(gen);

  return min_val + (psudo_rand % (max_val - min_val + 1));
}
