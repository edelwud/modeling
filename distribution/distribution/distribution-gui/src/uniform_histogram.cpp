#include <uniform_histogram.h>

#include <Mahi/Gui.hpp>
#include <Mahi/Util.hpp>

void UniformDistributionHistogram::RenderUniformHistogram() {
    if (ImGui::BeginTabItem("Uniform")) {
        ImGui::Text("Uniform distribution");
        ImGui::EndTabItem();
    }
}
