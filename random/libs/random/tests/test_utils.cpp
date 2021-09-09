#include <gtest/gtest.h>

#include <cmath>

#include <random/random.h>
#include <random/utils.h>

TEST(utils, CalculatingMeanTest) {
    auto sequence = Random::GenerateSequence(12, 5, 9, 28);
    std::cout << std::setprecision(3) << Utils::CalculateSequenceMean(sequence);
}

TEST(utils, CalculatingDevianceTest) {
    auto sequence = Random::GenerateSequence(12, 5, 9, 28);
    auto mean = Utils::CalculateSequenceMean(sequence);
    std::cout << std::setprecision(3) << Utils::CalculateSequenceDeviation(sequence, mean);
}

TEST(utils, CalculatingVarianceTest) {
    auto sequence = Random::GenerateSequence(12, 5, 9, 28);
    auto mean = Utils::CalculateSequenceMean(sequence);
    std::cout << std::setprecision(3) << Utils::CalculateSequenceVariance(sequence, mean);
}

TEST(utils, CalculatingImplicitCriteriaTest) {
    auto sequence = Random::GenerateSequence(12, 5, 9, 28);
    std::cout
        << "Actual: " << std::setprecision(10) << Utils::CalculateSequenceImplicitCriteria(sequence)
        << std::endl
        << "Expected: " << std::setprecision(10) << M_PI_4;
}

TEST(utils, CalculatingPeriodTest) {
    auto sequence = Random::GenerateSequence(12, 5, 9, 28);
    std::cout << Utils::CalculateSequencePeriod(sequence);
}

TEST(utils, CalculatingAperiodicIntervalTest) {
    auto sequence = Random::GenerateSequence(12, 5, 9, 28);
    auto period = Utils::CalculateSequencePeriod(sequence);
    std::cout << Utils::CalculateSequenceAperiodicInterval(sequence, period);
}