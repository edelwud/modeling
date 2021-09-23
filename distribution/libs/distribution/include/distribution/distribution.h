#pragma once

#include <vector>

class Distribution {
  public:
    static std::vector<double> GenerateRandomDistribution(int length);
    static std::vector<double> GenerateUniformDistribution(double a, double b,
                                                           int length);
    static std::vector<double>
    GenerateGaussDistribution(double mean, double std, int n, int length);
    static std::vector<double> GenerateExponentialDistribution(double param,
                                                               int length);
    static std::vector<double> GenerateGammaDistribution(int eta, double param,
                                                         int length);
    static std::vector<double> GenerateMinTriangleDistribution(double a, double b,
                                                               int length);
    static std::vector<double> GenerateMaxTriangleDistribution(double a, double b,
                                                               int length);
    static std::vector<double> GenerateSimpsonDistribution(double a, double b,
                                                           int length);
};