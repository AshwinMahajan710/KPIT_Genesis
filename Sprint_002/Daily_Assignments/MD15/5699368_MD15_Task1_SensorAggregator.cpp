#include<vector>
#include"5699368_MD15_Task1_SensorAggregator.h"
#include<algorithm>
#include<limits>

// function to add readings
void SensorAggregator:: addReadings(double reading_) {
    m_readings.emplace_back(reading_);
}


// getting sum
double SensorAggregator::getSum() const{
    double sum = 0;
    for(auto& reading: m_readings){
        sum += reading;
    }
    return sum;
}

// getting min
double SensorAggregator::getMin() const{
    double MIN_VAL = std::numeric_limits<int>::max();
    for(auto &reading: m_readings){
        if(reading < MIN_VAL){
            MIN_VAL = reading;
        }
    }
    return MIN_VAL;
}

// getting max
double SensorAggregator::getMax() const{
    double MAX_VAL = std::numeric_limits<int>::min();
    for(auto &reading: m_readings){
        if(reading > MAX_VAL){
            MAX_VAL = reading;
        }
    }
    return MAX_VAL;
}