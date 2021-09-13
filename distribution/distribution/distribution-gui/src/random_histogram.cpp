#include <random_histogram.h>
#include <utils.h>

#include <Mahi/Gui.hpp>
#include <Mahi/Util.hpp>

#include <distribution/distribution.h>
#include <distribution/utils.h>

void RandomDistributionHistogram::RenderRandomHistogram() {
    if (ImGui::BeginTabItem("Random")) {
        ImGui::InputInt("length", &length);
        if (ImGui::Button("Apply"))
            calculate();

        ImGui::Text("Mean: %lf\nVariance: %lf\nDeviation: %lf", mean, variance,
                    deviation);

        ImPlot::FitNextPlotAxes(true, true, true, true);
        if (ImPlot::BeginPlot("##RandomHistogram", nullptr, nullptr,
                              ImVec2(-1, -1), ImPlotFlags_NoChild)) {
            ImPlot::PlotBars("Random Levels", positions.data(), values.data(),
                             positions.size(), 0.5f);
            ImPlot::EndPlot();
        }

        ImGui::EndTabItem();
    }
}

void RandomDistributionHistogram::calculate() {
    sequence = Distribution::GenerateRandomDistribution(length);
    mean = Utils::CalculateSequenceMean(sequence);
    variance = Utils::CalculateSequenceVariance(sequence, mean);
    deviation = Utils::CalculateSequenceDeviation(sequence, mean);

    positions = HistogramUtils::GenerateXPositions(20, 0, 1);
    values = HistogramUtils::GetXRandomValuesCount(sequence, 20, 0, 1);
}
