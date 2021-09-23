#include <gauss_histogram.h>
#include <utils.h>

#include <Mahi/Gui.hpp>
#include <Mahi/Util.hpp>

#include <distribution/distribution.h>
#include <distribution/utils.h>

void GaussDistributionHistogram::RenderGaussHistogram() {
    if (ImGui::BeginTabItem("Gauss")) {
        ImGui::InputDouble("mean", &seqMean);
        ImGui::InputDouble("std", &std);
        ImGui::InputInt("n", &n);
        ImGui::InputInt("length", &length);
        if (ImGui::Button("Apply"))
            calculate();

        ImGui::Text("Mean: %lf\nVariance: %lf\nDeviation: %lf", mean, variance,
                    deviation);

        ImPlot::FitNextPlotAxes(true, true, true, true);
        if (ImPlot::BeginPlot("##GaussHistogram", nullptr, nullptr,
                              ImVec2(-1, -1), ImPlotFlags_NoChild)) {
            ImPlot::PlotBars("Gauss Levels", positions.data(), values.data(),
                             positions.size(), 0.9f);
            ImPlot::EndPlot();
        }

        ImGui::EndTabItem();
    }
}

void GaussDistributionHistogram::calculate() {
    sequence = Distribution::GenerateGaussDistribution(seqMean, std, n, length);

    auto max = *std::max_element(sequence.begin(), sequence.end());
    auto min = *std::min_element(sequence.begin(), sequence.end());

    mean = Utils::CalculateSequenceMean(sequence);
    variance = Utils::CalculateSequenceVariance(sequence, mean);
    deviation = Utils::CalculateSequenceDeviation(sequence, mean);

    positions = HistogramUtils::GenerateXPositions(100, 0, 1);
    values = HistogramUtils::GetXRandomValuesCount(sequence, 100, min, max);
}
