#include <gtest/gtest.h>

#include <distribution/distribution.h>
#include <distribution/utils.h>

#define SEQUENCE_LENGTH 1000

void metrics(std::vector<double> &sequence) {
    auto mean = Utils::CalculateSequenceMean(sequence);
    std::cout << std::endl
              << "Mean: " << std::setprecision(3) << mean << std::endl;
    std::cout << "Variance: " << std::setprecision(3)
              << Utils::CalculateSequenceVariance(sequence, mean) << std::endl;
    std::cout << "Deviation: " << std::setprecision(3)
              << Utils::CalculateSequenceDeviation(sequence, mean) << std::endl;
}

TEST(random, GenerateRandomSequenceTest) {
    auto sequence = Distribution::GenerateRandomDistribution(SEQUENCE_LENGTH);
    for (auto x : sequence) {
        std::cout << std::setprecision(3) << x << "; ";
    }
    metrics(sequence);
}

TEST(random, GenerateUniformSequenceTest) {
    int a = 0;
    int b = 1;
    auto sequence =
        Distribution::GenerateUniformDistribution(a, b, SEQUENCE_LENGTH);
    for (auto x : sequence) {
        std::cout << std::setprecision(3) << x << "; ";
    }
    metrics(sequence);
}

TEST(random, GenerateGaussSequenceTest) {
    double mean = 0.5;
    double std = 0.75;
    int n = 6;
    auto sequence =
        Distribution::GenerateGaussDistribution(mean, std, n, SEQUENCE_LENGTH);
    for (auto x : sequence) {
        std::cout << std::setprecision(3) << x << "; ";
    }
    metrics(sequence);
}

TEST(random, GenerateExponentialSequenceTest) {
    int param = 13;
    auto sequence =
        Distribution::GenerateExponentialDistribution(param, SEQUENCE_LENGTH);
    for (auto x : sequence) {
        std::cout << std::setprecision(3) << x << "; ";
    }
    metrics(sequence);
}

TEST(random, GenerateGammaSequenceTest) {
    int eta = 13;
    int param = 13;
    auto sequence =
        Distribution::GenerateGammaDistribution(eta, param, SEQUENCE_LENGTH);
    for (auto x : sequence) {
        std::cout << std::setprecision(3) << x << "; ";
    }
    metrics(sequence);
}

TEST(random, GenerateMinTriangleSequenceTest) {
    int a = 1;
    int b = 0;
    auto sequence =
        Distribution::GenerateMinTriangleDistribution(a, b, SEQUENCE_LENGTH);
    for (auto x : sequence) {
        std::cout << std::setprecision(3) << x << "; ";
    }
    metrics(sequence);
}

TEST(random, GenerateMaxTriangleSequenceTest) {
    int a = 1;
    int b = 0;
    auto sequence =
        Distribution::GenerateMaxTriangleDistribution(a, b, SEQUENCE_LENGTH);
    for (auto x : sequence) {
        std::cout << std::setprecision(3) << x << "; ";
    }
    metrics(sequence);
}

TEST(random, GenerateSimpsonSequenceTest) {
    int a = 1;
    int b = 2;
    auto sequence =
        Distribution::GenerateSimpsonDistribution(a, b, SEQUENCE_LENGTH);
    for (auto x : sequence) {
        std::cout << std::setprecision(3) << x << "; ";
    }
    metrics(sequence);
}
