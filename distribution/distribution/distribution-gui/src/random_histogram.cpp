#include <random_histogram.h>

#include <Mahi/Gui.hpp>
#include <Mahi/Util.hpp>

void RandomDistributionHistogram::RenderRandomHistogram() {
    if (ImGui::BeginTabItem("Random")) {
        ImGui::Text("Random distribution");
        ImGui::EndTabItem();
    }
}
