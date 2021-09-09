#include <graph.h>

GraphBars::GraphBars() : Application(500, 500, "Plots Benchmark") {
  set_vsync(false);
  ImGui::DisableViewports();
}

void GraphBars::update() {
  auto [w, h] = get_window_size();
  ImGui::SetNextWindowPos({0, 0}, ImGuiCond_Always);
  ImGui::SetNextWindowSize(ImVec2(w, h), ImGuiCond_Always);

  ImGui::Begin("Random GUI", nullptr, ImGuiWindowFlags_NoTitleBar);
  ImGui::Text("1000 pts ea. @ %.3f FPS", ImGui::GetIO().Framerate);

  static float xs[6] = {1, 2, 3, 4, 5, 6};
  static float bar[6] = {1, 2, 5, 3, 4, 20};

  ImPlot::SetNextPlotLimits(0, 6, 0, 10);
  if (ImPlot::BeginPlot("##ErrorBars", nullptr, nullptr, ImVec2(-1, -1),
                        ImPlotFlags_NoChild)) {
    ImPlot::PlotBars("Bar", xs, bar, 20, 0.5f);
    ImPlot::EndPlot();
  }
  ImGui::End();
}
