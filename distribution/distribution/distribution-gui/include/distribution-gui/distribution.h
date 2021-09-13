#pragma once

#include <Mahi/Gui.hpp>
#include <Mahi/Util.hpp>

#include <random_histogram.h>
#include <uniform_histogram.h>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define WINDOW_TITLE "Visual interface for distribution view"

using namespace mahi::gui;
using namespace mahi::util;

class DistributionHistogram : public RandomDistributionHistogram,
                              public UniformDistributionHistogram,
                              public Application {
  public:
    DistributionHistogram();

  public:
    void update() override;
};