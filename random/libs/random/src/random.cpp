#include <random.h>

std::vector<double> Random::GenerateSequence(int a, int m, int r0, int length) {
  std::vector<double> sequence(length);
  std::generate(sequence.begin(), sequence.end(), [a, m, r0]() {
    static int rn = r0;
    rn = rn * a % m;
    return (double)rn / (double)m;
  });
  return sequence;
}
