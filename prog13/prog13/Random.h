#ifndef RANDOM_H
#define RANDOM_H

class Random {
public:
  void randomize(unsigned int seed);
  int uniformRandom(); // RAND_MAX 0x7fff
  int uniformRandom(int maxRange);
  int poissonRandom(double expectedValue);
};

#endif

