#include<string>
#include<variant>
#include"5699368_MD14_Task1_SensorReading.h"

// constructor --> parameterized
SensorReading::SensorReading(const std::string& name_, const std::variant<int , float, std::string >& val_) : m_sensorName(name_), m_value(val_){}

// getting the name of the sensor
std::string SensorReading:: getName() const{
    return m_sensorName;
}

// getting variant value as string
std::string SensorReading::getValueAsString() const{
    return std::visit([](auto&& val_) {
        using T = std::decay_t<decltype(val_)>;
        if constexpr (std::is_same_v<T, std::string>)
            return val_;
        else
            return std::to_string(val_);
    }, m_value);
}

// updating the value
void SensorReading:: updateValue(std::variant<int , float, std::string >& val_){
    m_value = val_;
}

// get value
std::variant<int , float, std::string> SensorReading::getValue() const{
    return m_value;
}