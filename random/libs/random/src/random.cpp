#include <random.h>

std::vector<double> Random::GenerateSequence(int a, int m, int r0, int length) {
    std::vector<double> sequence(length);
    long long rn = r0;
    std::generate(sequence.begin(), sequence.end(), [a, m, &rn]() {
        rn = rn * a % m;
        return (double)rn / (double)m;
    });
    return sequence;
}
