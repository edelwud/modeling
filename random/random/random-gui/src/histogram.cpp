#include <histogram.h>
#include <utils.h>
#include <random/random.h>

#include <vector>

RandomHistogram::RandomHistogram() : Application(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE) {
  set_vsync(false);
  ImGui::DisableViewports();
}

void RandomHistogram::update() {
  auto [w, h] = get_window_size();
  ImGui::SetNextWindowPos({0, 0}, ImGuiCond_Always);
  ImGui::SetNextWindowSize(ImVec2(w, h), ImGuiCond_Always);

  ImGui::Begin("Random GUI", nullptr, ImGuiWindowFlags_NoTitleBar);
  ImGui::Text("1000 pts ea. @ %.3f FPS", ImGui::GetIO().Framerate);

  ImPlot::SetNextPlotLimits(-1, length, 0, maxY);
  if (ImPlot::BeginPlot("##ErrorBars", nullptr, nullptr, ImVec2(-1, -1),
                        ImPlotFlags_NoChild)) {
    ImPlot::PlotBars("Bar", positions.data(), values.data(), length, 0.5f);
    ImPlot::EndPlot();
  }
  ImGui::End();
}

void RandomHistogram::SetRandomParameters(int a, int m, int r0, int sequenceLength, int positionLength, int from, int to) {
    length = positionLength;
    positions = Histogram::Utils::GenerateXPositions(length, 0, 1);
    sequence = Random::GenerateSequence(a, m, r0, sequenceLength);
    values = Histogram::Utils::GetXRandomValuesCount(sequence, length, from, to);
    maxY = *std::max_element(values.begin(), values.end());
}
