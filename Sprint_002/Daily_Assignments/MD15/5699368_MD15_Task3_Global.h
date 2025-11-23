#ifndef INC_5699368_MD15_TASK3_GLOBAL_H
#define INC_5699368_MD15_TASK3_GLOBAL_H

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

double computeSum(const std::array<std::shared_ptr<SensorNode>, 5>& sensors);

double computeAverage(const std::array<std::shared_ptr<SensorNode>, 5>& sensors);

bool validateAllBelow(const std::array<std::shared_ptr<SensorNode>, 5>& sensors, double threshold);

// uses structure binding
std::pair<std::string, double> findHighestSensor(const std::array<std::shared_ptr<SensorNode>, 5>& sensors); 

// void printSensorReport(const SensorNode & node);

#endif // INC_5699368_MD15_TASK3_GLOBAL_H
