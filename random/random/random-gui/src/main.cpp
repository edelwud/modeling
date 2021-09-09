#define MAHI_GUI_NO_CONSOLE
#define MAHI_GUI_USE_DISCRETE_GPU

#include <histogram.h>

int main() {
  RandomHistogram histogram;
  histogram.SetRandomParameters(126398, 911201, 1, 1000000, 20, 0, 1);
  histogram.run();
  return 0;
}