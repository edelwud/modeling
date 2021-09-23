#include <distribution.h>

#include <cmath>
#include <numeric>
#include <random>

std::vector<double> Distribution::GenerateRandomDistribution(int length) {
    std::vector<double> sequence(length);

    std::random_device rd;
    std::mt19937 gen(rd());

    std::generate(sequence.begin(), sequence.end(), [&gen]() {
        return std::generate_canonical<double, 10>(gen);
    });

    return sequence;
}

std::vector<double> Distribution::GenerateUniformDistribution(double a, double b,
                                                              int length) {
    auto sequence = GenerateRandomDistribution(length);
    std::vector<double> uniformSequence(length);

    std::transform(sequence.begin(), sequence.end(), uniformSequence.begin(),
                   [a, b](auto x) { return x * (b - a) + a; });

    return uniformSequence;
}

std::vector<double> Distribution::GenerateGaussDistribution(double mean,
                                                            double std, int n,
                                                            int length) {
    std::vector<double> gaussSequence(length);

    std::generate(gaussSequence.begin(), gaussSequence.end(), [mean, std, n]() {
        auto sequence = GenerateRandomDistribution(n);
        auto sum = std::accumulate(sequence.begin(), sequence.end(), 0.0);
        return mean + std * std::sqrt(12 / n) * (sum - (double)(n) / 2);
    });

    return gaussSequence;
}

std::vector<double> Distribution::GenerateExponentialDistribution(double param,
                                                                  int length) {
    auto sequence = GenerateRandomDistribution(length);
    std::vector<double> exponentialSequence(length);

    std::transform(sequence.begin(), sequence.end(),
                   exponentialSequence.begin(),
                   [param](auto x) { return -1 / param * std::log(x); });

    return exponentialSequence;
}

std::vector<double>
Distribution::GenerateGammaDistribution(int eta, double param, int length) {
    std::vector<double> gammaSequence(length);

    std::generate(gammaSequence.begin(), gammaSequence.end(), [eta, param]() {
        auto sequence = GenerateRandomDistribution(eta);
        auto total = std::accumulate(sequence.begin(), sequence.end(), 1.0,
                                     std::multiplies<double>());
        return -1 / param * std::log(total);
    });

    return gammaSequence;
}

std::vector<double> Distribution::GenerateMinTriangleDistribution(double a, double b,
                                                                  int length) {
    std::vector<double> minTriangleSequence(length);

    std::generate(minTriangleSequence.begin(), minTriangleSequence.end(),
                  [a, b]() {
                      auto sequence = GenerateRandomDistribution(2);
                      auto min = std::min(sequence.begin(), sequence.end());
                      return a + (b - a) * *min;
                  });

    return minTriangleSequence;
}

std::vector<double> Distribution::GenerateMaxTriangleDistribution(double a, double b,
                                                                  int length) {
    std::vector<double> maxTriangleSequence(length);

    std::generate(maxTriangleSequence.begin(), maxTriangleSequence.end(),
                  [a, b]() {
                      auto sequence = GenerateRandomDistribution(2);
                      auto max = std::max(sequence.begin(), sequence.end());
                      return a + (b - a) * *max;
                  });

    return maxTriangleSequence;
}

std::vector<double> Distribution::GenerateSimpsonDistribution(double a, double b,
                                                              int length) {
    auto uniOne = GenerateUniformDistribution(a / 2, b / 2, length);
    auto uniTwo = GenerateUniformDistribution(a / 2, b / 2, length);

    std::transform(uniOne.begin(), uniOne.end(), uniTwo.begin(), uniOne.begin(),
                   std::plus<double>());

    return uniOne;
}
