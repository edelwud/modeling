#pragma once

#include <vector>

namespace Histogram {

class Utils {
  public:
    static std::vector<int> GenerateXPositions(int length, int offset,
                                               int period);
    static int GetRandomValuesCount(std::vector<double> &sequence, double from,
                                    double to);
    static std::vector<int> GetXRandomValuesCount(std::vector<double> &sequence,
                                                  unsigned int count,
                                                  double from, double to);
};

} // namespace Histogram