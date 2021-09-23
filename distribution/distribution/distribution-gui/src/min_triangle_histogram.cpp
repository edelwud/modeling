#include <min_triangle_histogram.h>
#include <utils.h>

#include <Mahi/Gui.hpp>
#include <Mahi/Util.hpp>

#include <distribution/distribution.h>
#include <distribution/utils.h>

void MinTriangleDistributionHistogram::RenderMinTriangleHistogram() {
    if (ImGui::BeginTabItem("MinTriangle")) {
        ImGui::InputDouble("a", &a);
        ImGui::InputDouble("b", &b);
        ImGui::InputInt("length", &length);
        if (ImGui::Button("Apply"))
            calculate();

        ImGui::Text("Mean: %lf\nVariance: %lf\nDeviation: %lf", mean, variance,
                    deviation);

        ImPlot::FitNextPlotAxes(true, true, true, true);
        if (ImPlot::BeginPlot("##MinTriangleHistogram", nullptr, nullptr,
                              ImVec2(-1, -1), ImPlotFlags_NoChild)) {
            ImPlot::PlotBars("MinTriangle Levels", positions.data(),
                             values.data(), positions.size(), 0.9f);
            ImPlot::EndPlot();
        }
        ImGui::EndTabItem();
    }
}

void MinTriangleDistributionHistogram::calculate() {
    sequence = Distribution::GenerateMinTriangleDistribution(a, b, length);

    auto max = *std::max_element(sequence.begin(), sequence.end()) + 1;
    auto min = *std::min_element(sequence.begin(), sequence.end()) - 1;

    mean = Utils::CalculateSequenceMean(sequence);
    variance = Utils::CalculateSequenceVariance(sequence, mean);
    deviation = Utils::CalculateSequenceDeviation(sequence, mean);

    positions = HistogramUtils::GenerateXPositions(100, 0, 1);
    values = HistogramUtils::GetXRandomValuesCount(sequence, 100, min, max);
}
