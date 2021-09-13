#include <distribution.h>

DistributionHistogram::DistributionHistogram()
    : Application(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE) {
    set_vsync(false);
    ImGui::DisableViewports();
};

void DistributionHistogram::update() {
    RenderExponentialHistogram();
    RenderGammaHistogram();
    RenderGaussHistogram();
    RenderMaxTriangleHistogram();
    RenderMinTriangleHistogram();
    RenderRandomHistogram();
    RenderSimpsonHistogram();
    RenderUniformHistogram();
}
