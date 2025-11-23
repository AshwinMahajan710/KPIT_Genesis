#include<string>
#include"5699368_MD15_Task3_SensorNode.h"
#include"5699368_MD15_Task3_PressureSensor.h"
#include"5699368_MD15_Task3_TemperatureSensor.h"
#include<array>
#include<memory>
#include"5699368_MD15_Task3_SensorGrid.h"
#include<stdexcept>
#include<algorithm>
#include<numeric>
#include"5699368_MD15_Task3_Global.h"

double computeSum(const std::array<std::shared_ptr<SensorNode>, 5>& sensors){
    return std::apply([](const auto&... nodes){
        return ((nodes? nodes->getVal() : 0.0) + ...);
    }, sensors);
}

double computeAverage(const std::array<std::shared_ptr<SensorNode>, 5>& sensors){
    return std::apply([](const auto&... nodes){
        double sum = ((nodes ? nodes->getVal(): 0.0) + ...); 
        return sum / sizeof...(nodes);
    }, sensors);
}

bool validateAllBelow(const std::array<std::shared_ptr<SensorNode>, 5>& sensors,
                      double threshold)
{
    return std::apply(
        [threshold](const auto&... nodes) {
            // initializer in if
            if (double maxVal = std::max({ (nodes ? nodes->getVal() : 0.0)... });
                maxVal < threshold)
            {
                return true;
            }
            return false;
        },
        sensors
    );
}

// // uses structure binding
// std::pair<std::string, double> findHighestSensor(const std::array<std::shared_ptr<SensorNode>, 5>& sensors){
//     return std::apply([](const auto&... nodes){
//         double sum = ((nodes ? nodes->getVal(): 0.0) + ...); 
//         return sum / sizeof...(nodes);
//     }, sensors);
// }

// void printSensorReport(const SensorNode & node);