#include<memory>
#include<vector>
#include"5699368_MD15_Task2_SmartSensorDiagnostics.h"
#include<limits>
#include<algorithm>

// method to add solo reading
void SmartSensorDiagnostics:: addReading(double reading_){
    m_readings->emplace_back(reading_);
}

// returning pair of min and max vals
std::pair<double,double> SmartSensorDiagnostics:: getMinMax() const{
    double MIN_VAL = std::numeric_limits<double>::max();
    double MAX_VAL = std::numeric_limits<double>::lowest();
    std::for_each(m_readings->begin(), m_readings->end(), [&](const double val_) mutable ->void {
        if(val_ < MIN_VAL) {MIN_VAL = val_;}
        if(val_ > MAX_VAL) {MAX_VAL = val_;}
    });
    return std::make_pair(MIN_VAL,MAX_VAL);
}

// returning true if all readings below the threshold
bool SmartSensorDiagnostics::isValid(double threshold) const{
    return std::all_of(m_readings->begin(), m_readings->end(),[&](const double val_){
        return (threshold > val_);
    });
}

// getting the readings count
size_t SmartSensorDiagnostics::getReadingsCount() const{
    return m_readings->size();
}