#pragma once

#include <Mahi/Gui.hpp>
#include <Mahi/Util.hpp>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define WINDOW_TITLE "Visual interface for Random library"

using namespace mahi::gui;
using namespace mahi::util;

class RandomHistogram : public Application {
  public:
    RandomHistogram();

  public:
    void update() override;
    void SetRandomParameters(int a, int m, int r0, int sequenceLength,
                             int positionLength, int from, int to);

  private:
    std::vector<int> positions;
    std::vector<int> values;
    std::vector<double> sequence;

    int maxY;
    int length;

    int period = 0,
        aperiodicInterval = 0;

    double mean = 0;

  private:
    int a = 126398,
        m = 911201,
        r0 = 1,
        sequenceLength = 1000000;
};
