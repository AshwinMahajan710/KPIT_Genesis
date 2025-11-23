#ifndef ADASMODULE_H
#define ADASMODULE_H

#include<string>
#include"SensorType.h"
#include"Sensor.h"

class ADASModule{
    public:
        std::string m_moduleName{};
        std::string m_version;
        Sensor m_sensor;

        // constructors
        ADASModule();
        ADASModule(const std::string& moduleName_, const std::string& version_, Sensor sensor_);
};

#endif // ADASMODULE_H
