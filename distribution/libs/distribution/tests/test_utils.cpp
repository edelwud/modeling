#include <gtest/gtest.h>

#include <distribution/distribution.h>
#include <distribution/utils.h>

#define SEQUENCE_LENGTH 1000

TEST(utils, CalculatingMeanTest) {
    auto sequence = Distribution::GenerateRandomDistribution(SEQUENCE_LENGTH);
    std::cout << std::setprecision(3) << Utils::CalculateSequenceMean(sequence);
}

TEST(utils, CalculatingDevianceTest) {
    auto sequence = Distribution::GenerateRandomDistribution(SEQUENCE_LENGTH);
    auto mean = Utils::CalculateSequenceMean(sequence);
    std::cout << std::setprecision(3)
              << Utils::CalculateSequenceDeviation(sequence, mean);
}

TEST(utils, CalculatingVarianceTest) {
    auto sequence = Distribution::GenerateRandomDistribution(SEQUENCE_LENGTH);
    auto mean = Utils::CalculateSequenceMean(sequence);
    std::cout << std::setprecision(3)
              << Utils::CalculateSequenceVariance(sequence, mean);
}
