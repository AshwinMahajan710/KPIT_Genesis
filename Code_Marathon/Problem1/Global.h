#ifndef GLOBAL_H
#define GLOBAL_H

#include"SensorType.h"
#include"DeliveryRobot.h"
#include<string>

void analyzeSensorPerformance(const DeliveryRobot robots[], int count);
void printRobotSummary(const DeliveryRobot* robot);
DeliveryRobot* cloneRobot(const DeliveryRobot* original); // Returns a deep copy of the vehicle using the copy constructor
void evaluateFleetEfficiency(DeliveryRobot* fleet[], int size);

#endif // GLOBAL_H
