#include <simpson_histogram.h>
#include <utils.h>

#include <Mahi/Gui.hpp>
#include <Mahi/Util.hpp>

#include <distribution/distribution.h>
#include <distribution/utils.h>

void SimpsonDistributionHistogram::RenderSimpsonHistogram() {
    if (ImGui::BeginTabItem("Simpson")) {
        ImGui::InputDouble("a", &a);
        ImGui::InputDouble("b", &b);
        ImGui::InputInt("length", &length);
        if (ImGui::Button("Apply"))
            calculate();

        ImGui::Text("Mean: %lf\nVariance: %lf\nDeviation: %lf", mean, variance,
                    deviation);

        ImPlot::FitNextPlotAxes(true, true, true, true);
        if (ImPlot::BeginPlot("##SimpsonHistogram", nullptr, nullptr,
                              ImVec2(-1, -1), ImPlotFlags_NoChild)) {
            ImPlot::PlotBars("Simpson Levels", positions.data(), values.data(),
                             positions.size(), 0.9f);
            ImPlot::EndPlot();
        }
        ImGui::EndTabItem();
    }
}

void SimpsonDistributionHistogram::calculate() {
    sequence = Distribution::GenerateSimpsonDistribution(a, b, length);
    mean = Utils::CalculateSequenceMean(sequence);
    variance = Utils::CalculateSequenceVariance(sequence, mean);
    deviation = Utils::CalculateSequenceDeviation(sequence, mean);

    positions = HistogramUtils::GenerateXPositions(100, 0, 1);
    values = HistogramUtils::GetXRandomValuesCount(sequence, 100, 0, 1);
}
