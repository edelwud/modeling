#include <gtest/gtest.h>

#include <random/random.h>

TEST(random, GenerateSequenceTest) {
    for (auto x : Random::GenerateSequence(12, 5, 9, 28)) {
        std::cout << std::setprecision(3) << x << "; ";
    }
}
