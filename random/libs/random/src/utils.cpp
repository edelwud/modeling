#include <utils.h>

#include <cmath>
#include <numeric>

double Rand::Utils::CalculateSequenceMean(std::vector<double> &sequence) {
    double sum = std::accumulate(sequence.begin(), sequence.end(), 0.0);
    int size = sequence.size();
    return sum / size;
}

double Rand::Utils::CalculateSequenceDeviation(std::vector<double> &sequence,
                                               double mean) {
    int length = sequence.size();
    std::vector<double> diff(length);
    std::transform(sequence.begin(), sequence.end(), diff.begin(),
                   [mean](double x) { return x - mean; });
    auto diffSum =
        std::inner_product(diff.begin(), diff.end(), diff.begin(), 0.0);
    return std::sqrt(diffSum / length);
}

double Rand::Utils::CalculateSequenceVariance(std::vector<double> &sequence,
                                              double mean) {
    auto deviation = CalculateSequenceDeviation(sequence, mean);
    return deviation * deviation;
}

double
Rand::Utils::CalculateSequenceImplicitCriteria(std::vector<double> &sequence) {
    double matchCriteria = 0;
    auto length = sequence.size();
    for (auto it = sequence.begin(); it != sequence.end(); it = std::next(it)) {
        auto x = *it;
        it = std::next(it);
        auto y = *it;

        if ((x * x + y * y) < 1) {
            matchCriteria++;
        }
    }

    return matchCriteria * 2 / length;
}

int Rand::Utils::CalculateSequencePeriod(std::vector<double> &sequence) {
    auto last = sequence.back();
    for (auto it = std::next(sequence.rbegin()); it != sequence.rend(); ++it) {
        if (*it == last) {
            return (int)std::distance(sequence.rbegin(), it);
        }
    }
    return 1;
}

int Rand::Utils::CalculateSequenceAperiodicInterval(
    std::vector<double> &sequence, int period) {
    auto aperiodicInterval = 0;
    auto size = sequence.size();

    while ((sequence[aperiodicInterval] != sequence[aperiodicInterval + period])
           && aperiodicInterval + period > size)
        aperiodicInterval++;

    return aperiodicInterval + period;
}
