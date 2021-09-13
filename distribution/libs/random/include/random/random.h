#pragma once

#include <vector>

class Random {
  public:
    static std::vector<double> GenerateSequence(int a, int m, int r0,
                                                int length);
};