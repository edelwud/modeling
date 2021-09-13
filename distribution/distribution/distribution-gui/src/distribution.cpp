#include <distribution.h>

DistributionHistogram::DistributionHistogram()
    : Application(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE) {
    set_vsync(false);
    ImGui::DisableViewports();
};

void DistributionHistogram::update() {
    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
    ImGui::SetNextWindowSize(get_window_size(), ImGuiCond_Always);
    ImGui::Begin("Histogram");
    if (ImGui::BeginTabBar("Distribution")) {
        RenderExponentialHistogram();
        RenderGammaHistogram();
        RenderGaussHistogram();
        RenderMaxTriangleHistogram();
        RenderMinTriangleHistogram();
        RenderRandomHistogram();
        RenderSimpsonHistogram();
        RenderUniformHistogram();
        ImGui::EndTabBar();
    }
    ImGui::End();
}
