#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

#include "Random.h"

// pseudo random number seed
void Random::randomize(unsigned int seed) {
  srand(seed);
}

// Poisson random number of given expected value
int Random::poissonRandom(double expectedValue) {
  int n = 0;
  double limit; // exp(-v) where v is the expected value
  double x;     // pseudorandom number
  limit = exp(-expectedValue);
  x = rand() / (double) RAND_MAX;
  while (x > limit) {
    n++;
    x *= rand() / (double) RAND_MAX;
  }
  return n;
}

// random number 0 ~ RAND_MAX
int Random::uniformRandom() {
  return rand();
}

// random number 0 ~ maxRange-1
int Random::uniformRandom(int maxRange) {
  return rand() % maxRange;
}

