#include <histogram.h>
#include <utils.h>
#include <random/random.h>
#include <random/utils.h>

#include <vector>

RandomHistogram::RandomHistogram()
    : Application(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE) {
    set_vsync(false);
    ImGui::DisableViewports();
}

void RandomHistogram::update() {
    ImGui::SetNextWindowPos(ImVec2(0,0), ImGuiCond_Always);
    ImGui::SetNextWindowSize(get_window_size(), ImGuiCond_Always);

    ImGui::Begin("Histogram", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);
    ImGui::BeginChild("Random parameters", ImVec2(ImGui::GetWindowContentRegionWidth() * 0.5f, -1));
    ImGui::Text("1000 pts ea. @ %.3f FPS", ImGui::GetIO().Framerate);
    ImGui::InputInt("A", &a);
    ImGui::InputInt("M", &m);
    ImGui::InputInt("r0", &r0);
    ImGui::InputInt("length", &sequenceLength);
    if (ImGui::Button("Apply"))
        SetRandomParameters(a, m, r0, sequenceLength, 20, 0, 1);
    ImGui::Text("Period: %d;\nAperiodic interval: %d;\nExpected value: %lf;", period, aperiodicInterval, mean);
    ImGui::EndChild();

    ImGui::SameLine();

    ImGui::BeginChild("Values", ImVec2(0, -1));

    if (ImGui::BeginTabBar("Plots")) {
        if (ImGui::BeginTabItem("Histogram")) {
            ImPlot::SetNextPlotLimits(-1, length, 0, maxY);
            if (ImPlot::BeginPlot("##Histogram", nullptr, nullptr, ImVec2(-1, -1),
                                  ImPlotFlags_NoChild)) {
                ImPlot::PlotBars("Level", positions.data(), values.data(), length,
                                 0.5f);
                ImPlot::EndPlot();
            }
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Magnitude")) {
            ImGui::Text("Second tab");
            ImGui::EndTabItem();
        }
        ImGui::EndTabBar();
    }

    ImGui::EndChild();

    ImGui::End();
}

void RandomHistogram::SetRandomParameters(int _a, int _m, int _r0,
                                          int _sequenceLength,
                                          int positionLength, int from,
                                          int to) {
    length = positionLength;
    positions = Histogram::Utils::GenerateXPositions(length, 0, 1);
    sequence = Random::GenerateSequence(_a, _m, _r0, _sequenceLength);
    values =
        Histogram::Utils::GetXRandomValuesCount(sequence, length, from, to);
    maxY = *std::max_element(values.begin(), values.end());

    mean = Rand::Utils::CalculateSequenceMean(sequence);
    period = Rand::Utils::CalculateSequencePeriod(sequence);
    aperiodicInterval = Rand::Utils::CalculateSequenceAperiodicInterval(sequence, period);
}
