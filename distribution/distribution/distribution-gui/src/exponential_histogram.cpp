#include <exponential_histogram.h>
#include <utils.h>

#include <Mahi/Gui.hpp>
#include <Mahi/Util.hpp>

#include <distribution/distribution.h>
#include <distribution/utils.h>

void ExponentialDistributionHistogram::RenderExponentialHistogram() {
    if (ImGui::BeginTabItem("Exponential")) {
        ImGui::InputDouble("param", &param);
        ImGui::InputInt("length", &length);
        if (ImGui::Button("Apply"))
            calculate();

        ImGui::Text("Mean: %lf\nVariance: %lf\nDeviation: %lf", mean, variance,
                    deviation);

        ImPlot::FitNextPlotAxes(true, true, true, true);
        if (ImPlot::BeginPlot("##ExponentialHistogram", nullptr, nullptr,
                              ImVec2(-1, -1), ImPlotFlags_NoChild)) {
            ImPlot::PlotBars("Exponential Levels", positions.data(),
                             values.data(), positions.size(), 0.5f);
            ImPlot::EndPlot();
        }
        ImGui::EndTabItem();
    }
}

void ExponentialDistributionHistogram::calculate() {
    sequence = Distribution::GenerateExponentialDistribution(param, length);
    mean = Utils::CalculateSequenceMean(sequence);
    variance = Utils::CalculateSequenceVariance(sequence, mean);
    deviation = Utils::CalculateSequenceDeviation(sequence, mean);

    positions = HistogramUtils::GenerateXPositions(20, 0, 1);
    values = HistogramUtils::GetXRandomValuesCount(sequence, 20, 0, 1);
}