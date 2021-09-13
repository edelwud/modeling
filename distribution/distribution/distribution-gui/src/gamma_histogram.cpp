#include <gamma_histogram.h>

#include <Mahi/Gui.hpp>
#include <Mahi/Util.hpp>

void GammaDistributionHistogram::RenderGammaHistogram() {
    if (ImGui::BeginTabItem("Gamma")) {
        ImGui::Text("Gamma distribution");
        ImGui::EndTabItem();
    }
}
