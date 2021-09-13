#include <gauss_histogram.h>

#include <Mahi/Gui.hpp>
#include <Mahi/Util.hpp>

void GaussDistributionHistogram::RenderGaussHistogram() {
    if (ImGui::BeginTabItem("Gauss")) {
        ImGui::Text("Gauss distribution");
        ImGui::EndTabItem();
    }
}
