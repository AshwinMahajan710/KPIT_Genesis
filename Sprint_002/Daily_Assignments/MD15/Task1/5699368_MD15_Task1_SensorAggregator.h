#ifndef INC_5699368_MD15_TASK1_SENSORAGGREGATOR_H
#define INC_5699368_MD15_TASK1_SENSORAGGREGATOR_H

#include <vector>
#include <numeric>
#include <algorithm>
#include <stdexcept>

class SensorAggregator {
private:
    std::vector<double> m_readings;

public:
    SensorAggregator() = default;
    SensorAggregator(const SensorAggregator&) = delete;
    SensorAggregator(SensorAggregator&&) = default;

    void addReading(double reading_);

    template <typename... Args>
    void addMultipleReadings(Args... readings_) {
        (addReading(readings_), ...);
    }

    double getSum() const {
        return std::accumulate(m_readings.begin(), m_readings.end(), 0.0);
    }

    double getMin() const {
        if (m_readings.empty()) throw std::runtime_error("NoElementsException");
        return *std::min_element(m_readings.begin(), m_readings.end());
    }

    double getMax() const {
        if (m_readings.empty()) throw std::runtime_error("NoElementsException");
        return *std::max_element(m_readings.begin(), m_readings.end());
    }
};

// global template function must be fully in header
template <typename... Args>
double computeSum(Args... values) {
    return (values + ... + 0.0);
}

#endif
