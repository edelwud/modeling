#pragma once

#include <vector>

class Utils {
public:
    static double CalculateSequenceMean(std::vector<double>& sequence);
    static double CalculateSequenceVariance(std::vector<double>& sequence, double mean);
    static double CalculateSequenceDeviation(std::vector<double>& sequence, double mean);
    static double CalculateSequenceImplicitCriteria(std::vector<double>& sequence);
    static int CalculateSequencePeriod(std::vector<double>& sequence);
    static int CalculateSequenceAperiodicInterval(std::vector<double>& sequence, int period);
};
