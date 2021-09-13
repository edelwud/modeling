#include <simpson_histogram.h>

#include <Mahi/Gui.hpp>
#include <Mahi/Util.hpp>

void SimpsonDistributionHistogram::RenderSimpsonHistogram() {
    ImGui::Begin("Simpson");
    ImGui::Text("Simpson distribution");
    ImGui::End();
}
