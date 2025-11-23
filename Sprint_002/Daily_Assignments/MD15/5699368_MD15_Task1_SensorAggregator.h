#ifndef INC_5699368_MD15_TASK1_SENSORAGGREGATOR_H
#define INC_5699368_MD15_TASK1_SENSORAGGREGATOR_H

#include<vector>

class SensorAggregator{
    private:
        std::vector<double> m_readings;
    public:
        SensorAggregator() = default;
        
        void addReadings(double reading_) ;
        template <typename... Args>
        void addMultipleReadings(Args... readings){
            (addReadings(readings), ...);
        }

        double getSum() const;
        double getMin() const;
        double getMax() const;
};

#endif // INC_5699368_MD15_TASK1_SENSORAGGREGATOR_H
