#pragma once

#include <Mahi/Gui.hpp>
#include <Mahi/Util.hpp>

using namespace mahi::gui;
using namespace mahi::util;

class GraphBars : public Application {
public:
  GraphBars();
  void update() override;
};
