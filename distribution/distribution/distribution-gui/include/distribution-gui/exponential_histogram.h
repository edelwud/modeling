#pragma once

#include <vector>

class ExponentialDistributionHistogram {
  protected:
    void RenderExponentialHistogram();

  private:
    void calculate();

  private:
    std::vector<int> positions;
    std::vector<int> values;
    std::vector<double> sequence;

  private:
    int length = 0;
    double param = 0;

  private:
    double mean = 0;
    double variance = 0;
    double deviation = 0;
};
