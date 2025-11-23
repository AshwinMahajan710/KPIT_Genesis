#ifndef INC_5699368_MD14_TASK3_SENSOR_H
#define INC_5699368_MD14_TASK3_SENSOR_H

#include<variant>
#include<string>

class Sensor{
    public:
        virtual ~Sensor() =default;
        virtual std::variant<int, double, std::string> readData() const = 0;
        virtual std::string getType() const = 0;
};

#endif // INC_5699368_MD14_TASK3_SENSOR_H
