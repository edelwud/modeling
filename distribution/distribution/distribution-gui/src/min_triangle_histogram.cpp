#include <min_triangle_histogram.h>

#include <Mahi/Gui.hpp>
#include <Mahi/Util.hpp>

void MinTriangleDistributionHistogram::RenderMinTriangleHistogram() {
    if (ImGui::BeginTabItem("MinTriangle")) {
        ImGui::Text("MinTriangle distribution");
        ImGui::EndTabItem();
    }
}
