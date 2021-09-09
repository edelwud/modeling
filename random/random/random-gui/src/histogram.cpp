#include <histogram.h>
#include <random/random.h>
#include <utils.h>

#include <vector>

RandomHistogram::RandomHistogram()
    : Application(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE) {
    set_vsync(false);
    ImGui::DisableViewports();
}

void RandomHistogram::update() {
    ImGui::BeginFixed("Random parameters", {0, 0},
                      {WINDOW_WIDTH / 4, WINDOW_HEIGHT});
    ImGui::Text("1000 pts ea. @ %.3f FPS", ImGui::GetIO().Framerate);
    ImGui::InputInt("A", &a);
    ImGui::InputInt("M", &m);
    ImGui::InputInt("r0", &r0);
    ImGui::InputInt("length", &sequenceLength);
    if (ImGui::Button("Apply"))
        SetRandomParameters(a, m, r0, sequenceLength, 20, 0, 1);
    ImGui::End();

    ImGui::BeginFixed(WINDOW_TITLE, {WINDOW_WIDTH / 4, 0},
                      {WINDOW_WIDTH * 3 / 4, WINDOW_HEIGHT - 100});

    ImPlot::SetNextPlotLimits(-1, length, 0, maxY);
    if (ImPlot::BeginPlot("##Histogram", nullptr, nullptr, ImVec2(-1, -1),
                          ImPlotFlags_NoChild)) {
        ImPlot::PlotBars("Level", positions.data(), values.data(), length,
                         0.5f);
        ImPlot::EndPlot();
    }
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
}
