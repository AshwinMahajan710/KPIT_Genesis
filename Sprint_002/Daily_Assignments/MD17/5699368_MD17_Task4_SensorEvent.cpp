#include<string>
#include<variant>
#include"5699368_MD17_Task4_SensorEvent.h"
#include<stdexcept>

// constructor --> parametrized
SensorEvent::SensorEvent(const std::string& sourceModule_, std::variant<int,double,std::string> payload_, bool isUrgent_):m_isUrgent(isUrgent_){

    // validation
    if(sourceModule_.length() == 0 || (std::holds_alternative<std::string>(payload_) && std::get<std::string>(payload_).length() == 0)){
        throw std::runtime_error("InvalidArguments for either name or payload");
    }
    m_payload = payload_;
    m_sourceModule = sourceModule_;
}

// getters
std::string SensorEvent:: getSourceModule() const{
    return m_sourceModule;
}
const std::variant<int, double, std::string>& SensorEvent::getPayload() const{
    return m_payload;
}
bool SensorEvent::isUrgentEvent() const{
    return m_isUrgent;
}