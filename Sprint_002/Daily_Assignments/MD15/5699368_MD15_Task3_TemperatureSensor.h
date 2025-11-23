#ifndef INC_5699368_MD15_TASK3_TEMPERATURESENSOR_H
#define INC_5699368_MD15_TASK3_TEMPERATURESENSOR_H

#include<string>
#include"5699368_MD15_Task3_SensorNode.h"

class TemperatureSensor: public SensorNode{
    public:
        // parametrized constructor
        TemperatureSensor(const std::string& id_, double value_);
       void updateVal(double newVal_) override;
};


#endif // INC_5699368_MD15_TASK3_TEMPERATURESENSOR_H
