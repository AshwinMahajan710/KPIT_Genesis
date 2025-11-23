#ifndef INC_5699368_MD14_TASK3_SPEEDSENSOR_H
#define INC_5699368_MD14_TASK3_SPEEDSENSOR_H

#include<vector>
#include<string>
#include"5699368_MD14_Task3_Sensor.h"

class SpeedSensor: public Sensor{
    public:
        std::variant<int, double, std::string> readData() const override;
        std::string getType() const override;
};


#endif // INC_5699368_MD14_TASK3_SPEEDSENSOR_H
