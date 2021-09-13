#include <exponential_histogram.h>

#include <Mahi/Gui.hpp>
#include <Mahi/Util.hpp>

void ExponentialDistributionHistogram::RenderExponentialHistogram() {
    if (ImGui::BeginTabItem("Exponential")) {
        ImGui::Text("Exponential distribution");
        ImGui::EndTabItem();
    }
}
