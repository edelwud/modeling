#include <simpson_histogram.h>

#include <Mahi/Gui.hpp>
#include <Mahi/Util.hpp>

void SimpsonDistributionHistogram::RenderSimpsonHistogram() {
    if (ImGui::BeginTabItem("Simpson")) {
        ImGui::Text("Simpson distribution");
        ImGui::EndTabItem();
    }
}
