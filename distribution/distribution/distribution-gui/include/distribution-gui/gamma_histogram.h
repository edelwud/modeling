#pragma once

#include <vector>

class GammaDistributionHistogram {
  protected:
    void RenderGammaHistogram();

  private:
    void calculate();

  private:
    std::vector<int> positions;
    std::vector<int> values;
    std::vector<double> sequence;

  private:
    double eta = 0;
    double param = 0;
    int length = 0;

  private:
    double mean = 0;
    double variance = 0;
    double deviation = 0;
};
