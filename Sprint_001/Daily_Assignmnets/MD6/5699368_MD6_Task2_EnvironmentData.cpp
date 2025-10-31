#include<iostream>
#include<stdexcept>
#include"5699368_MD6_Task2_EnvironmentData.h"

// constructor
EnvironmentData::EnvironmentData(const std::string& code_,const std::string& description_,bool active_,int occurenceCount_,std::time_t lastOccurenceTime_,SeverityLevel severityLevel_,bool confirmed_,bool pending_,bool milOn_,const std::string& system_,const std::string& origin_,float ambientTemp_, float altitude_, float humidity_): DTC(code_,description_,active_,occurenceCount_,lastOccurenceTime_,severityLevel_,confirmed_,pending_,milOn_,system_,origin_){
    
    // Validating ambient_temp
    if(ambientTemp_ >= -50.0 && ambientTemp_ <= 60.0) {m_ambientTemperature = ambientTemp_;}
    else {throw std::invalid_argument("InvalidAmbientTempException: \"Ambient Temperature out of realistic range (-50 to 60) \"");}

    // validating altitude
    if(altitude_ >= -100.0 && altitude_ <= 10000.0) {m_altitude = altitude_;}
    else {throw std::invalid_argument("InvalidAltitudeTempException: \"Altitude must be between -100 to 10,000 meters\"");}

    // validating Humidity
    if(humidity_ >= 0.0 && humidity_ <= 100.0) {m_humidity = humidity_;}
    else {throw std::invalid_argument("InvalidHumidityException: \"Humidity must be between 0.0 to 100 percent\"");}
};

// printing info
void EnvironmentData::printEnvironmentData() const{
    std::cout<<"Ambient Temp: "<<m_ambientTemperature<<std::endl;
    std::cout<<"Altitude: "<<m_altitude<<std::endl;
    std::cout<<"Humidity: "<<m_humidity<<std::endl;
}
