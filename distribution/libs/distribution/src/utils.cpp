#include <utils.h>

#include <cmath>
#include <numeric>

double Utils::CalculateSequenceMean(std::vector<double> &sequence) {
    double sum = std::accumulate(sequence.begin(), sequence.end(), 0.0);
    int size = sequence.size();
    return sum / size;
}

double Utils::CalculateSequenceDeviation(std::vector<double> &sequence,
                                         double mean) {
    int length = sequence.size();
    std::vector<double> diff(length);
    std::transform(sequence.begin(), sequence.end(), diff.begin(),
                   [mean](double x) { return x - mean; });
    auto diffSum =
        std::inner_product(diff.begin(), diff.end(), diff.begin(), 0.0);
    return std::sqrt(diffSum / length);
}

double Utils::CalculateSequenceVariance(std::vector<double> &sequence,
                                        double mean) {
    auto deviation = CalculateSequenceDeviation(sequence, mean);
    return deviation * deviation;
}
