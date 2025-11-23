#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include"Sensor.h"
#include"../Day12/include/functionalities.h"

bool compareByPriority(const Sensor& sensor1, const Sensor& sensor2){
    return sensor1.getPriority() > sensor2.getPriority();
}