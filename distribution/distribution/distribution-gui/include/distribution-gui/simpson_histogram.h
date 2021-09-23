#pragma once

#include <vector>

class SimpsonDistributionHistogram {
  protected:
    void RenderSimpsonHistogram();

  private:
    void calculate();

  private:
    std::vector<int> positions;
    std::vector<int> values;
    std::vector<double> sequence;

  private:
    double a = 0;
    double b = 0;
    int length = 0;

  private:
    double mean = 0;
    double variance = 0;
    double deviation = 0;
};
