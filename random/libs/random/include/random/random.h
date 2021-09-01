#pragma once

class Random {
public:
  static unsigned int Generate(int from, int to);
  static void SetSeed(int seed);

private:
  static inline int primeNumber = 1103515245;
  static inline int currentSeed = 1;
};