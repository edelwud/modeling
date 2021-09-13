#pragma once

#include <Mahi/Gui.hpp>
#include <Mahi/Util.hpp>

#include <exponential_histogram.h>
#include <gamma_histogram.h>
#include <gauss_histogram.h>
#include <max_triangle_histogram.h>
#include <min_triangle_histogram.h>
#include <random_histogram.h>
#include <simpson_histogram.h>
#include <uniform_histogram.h>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define WINDOW_TITLE "Visual interface for distribution view"

using namespace mahi::gui;
using namespace mahi::util;

class DistributionHistogram : public Application,
                              public ExponentialDistributionHistogram,
                              public GammaDistributionHistogram,
                              public GaussDistributionHistogram,
                              public MaxTriangleDistributionHistogram,
                              public MinTriangleDistributionHistogram,
                              public RandomDistributionHistogram,
                              public SimpsonDistributionHistogram,
                              public UniformDistributionHistogram {
  public:
    DistributionHistogram();

  public:
    void update() override;
};