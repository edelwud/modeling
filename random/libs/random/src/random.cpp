#include <random.h>

unsigned int Random::Generate(int from, int to) {
  currentSeed = currentSeed * primeNumber + 12345;
  return static_cast<unsigned int>(currentSeed * 65536) % (to - from) + from;
}

void Random::SetSeed(int seed) { currentSeed = seed; }
