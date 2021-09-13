#pragma once

#include <vector>

class GaussDistributionHistogram {
  protected:
    void RenderGaussHistogram();

  private:
    void calculate();

  private:
    std::vector<int> positions;
    std::vector<int> values;
    std::vector<double> sequence;

  private:
    double seqMean = 0;
    double std = 0;
    int length = 0;
    int n = 0;

  private:
    double mean = 0;
    double variance = 0;
    double deviation = 0;
};
