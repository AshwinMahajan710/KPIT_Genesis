#include<string>
#include"SensorType.h"
#include"Sensor.h"
#include"ADASModule.h"

// delegated constructor
ADASModule::ADASModule(): ADASModule("", "0.0", Sensor()){};

// constructor --> parameterized
ADASModule::ADASModule(const std::string& moduleName_, const std::string& version_, Sensor sensor_): m_moduleName(moduleName_), m_version(version_), m_sensor(sensor_){}