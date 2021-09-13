#define MAHI_GUI_NO_CONSOLE
#define MAHI_GUI_USE_DISCRETE_GPU

#include <distribution.h>

int main() {
    DistributionHistogram histogram;
    histogram.run();
    return 0;
}