#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <vector>

#include "ftxui/dom/node.hpp"
#include "ftxui/screen/box.hpp"
#include "ftxui/screen/color.hpp"

#include <random/random.h>

int main() {
  using namespace ftxui;
  Element document = graph([](int x, int y) {
                       std::vector<int> result(x, 0);
                       for (int i = 1; i < x; ++i) {
                         result[i] = Random::Generate(i, x) / y;
                       }
                       return result;
                     }) |
                     color(Color::Red) | border | color(Color::White) |
                     bgcolor(Color::Black);

  auto screen = Screen::Create(Dimension::Fixed(80), Dimension::Fixed(10));
  Render(screen, document);
  screen.Print();

  return EXIT_SUCCESS;
}