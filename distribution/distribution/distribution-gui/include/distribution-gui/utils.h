#pragma once

#include <vector>

class HistogramUtils {
  public:
    static std::vector<int> GenerateXPositions(int length, int offset,
                                               int period);
    static int GetRandomValuesCount(std::vector<double> &sequence, double from,
                                    double to);
    static std::vector<int> GetXRandomValuesCount(std::vector<double> &sequence,
                                                  unsigned int count,
                                                  double from, double to);
};