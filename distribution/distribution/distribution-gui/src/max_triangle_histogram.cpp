#include <max_triangle_histogram.h>

#include <Mahi/Gui.hpp>
#include <Mahi/Util.hpp>

void MaxTriangleDistributionHistogram::RenderMaxTriangleHistogram() {
    ImGui::Begin("MaxTriangle");
    ImGui::Text("MaxTriangle distribution");
    ImGui::End();
}
