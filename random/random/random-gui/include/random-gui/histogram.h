#pragma once

#include <Mahi/Gui.hpp>
#include <Mahi/Util.hpp>

#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 400
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
};
