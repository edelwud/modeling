#include <gtest/gtest.h>

#include <random/random.h>

TEST(random, generatingDouble) {
    for (int i = 10; i < 1000; i += 10) {
        std::cout << Random::Generate(0, i) << ": " << i << std::endl;
    }
}