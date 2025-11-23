#include "5699368_MD15_Task1_SensorAggregator.h"
#include <iostream>

int main() {
    SensorAggregator agg;

    agg.addReading(100);
    agg.addReading(200);
    agg.addReading(300);
    agg.addMultipleReadings(12.5, 33.3, 55);

    std::cout << "Sum: " << agg.getSum() << std::endl;
    std::cout << "Min: " << agg.getMin() << std::endl;
    std::cout << "Max: " << agg.getMax() << std::endl;

    std::cout << "computeSum: " << computeSum(10.5, 20.5) << std::endl;
    std::cout << "computeSum(): " << computeSum() << std::endl;

    return 0;
}
