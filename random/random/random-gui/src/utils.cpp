#include <utils.h>

#include <numeric>

std::vector<int> Histogram::Utils::GenerateXPositions(int length, int offset, int period) {
    int currentPosition = offset;
    std::vector<int> positions(length);
    std::generate(positions.begin(), positions.end(), [&currentPosition, period]() {
        currentPosition += period;
        return currentPosition - period;
    });
    return positions;
}

int Histogram::Utils::GetRandomValuesCount(std::vector<double>& sequence, double from, double to) {
    int result = 0;
    for (auto x : sequence)
        if (x >= from && x < to)
            result++;
    return result;
}

std::vector<int>
Histogram::Utils::GetXRandomValuesCount(std::vector<double> &sequence, double count, double from, double to) {
    std::vector<int> result(count);
    auto delta = to - from;
    auto groupSize = delta / count;
    auto currentPosition = from;

    std::for_each(result.begin(), result.end(), [&currentPosition, groupSize, &sequence](auto& x) {
        x = GetRandomValuesCount(sequence, currentPosition, currentPosition + groupSize);
        currentPosition += groupSize;
    });

    return result;
}
