#include<string>
#include"SensorType.h"
#include"Sensor.h"
#include"ADASModule.h"
#include<memory>
#include<vector>
#include<iostream>
#include"Vehicle.h"

// constructor delegated
Vehicle::Vehicle() : Vehicle("","",0){}

// constructor --> parameterized
Vehicle::Vehicle(const std::string& make_, const std::string& model_, int year_): m_make(make_), m_model(model_), m_year(year_){}

// method to add ADAS modules
void Vehicle::addModules(std::shared_ptr<ADASModule>& module){
    m_modules.emplace_back(module);
    std::cout<<"\nmodule added successfully..."<<std::endl;
}

// overloaded operator << for printing 
std::ostream& operator<< (std::ostream& out, const Vehicle& other){
    out<<"\nMake: "<<other.m_make<<std::endl;
    out<<"Model: "<<other.m_model<<std::endl;
    out<<"Year: "<<other.m_year<<std::endl;
    for(auto &module: other.m_modules){
        out<<"\nModule Name: "<<module->m_moduleName<<std::endl;
        out<<"Version Name: "<<module->m_version<<std::endl;
        out<<"Sensor Name: "<<(module->m_sensor).m_range<<std::endl;
        out<<"Sensor Resolution: "<<(module->m_sensor).m_resolution<<std::endl;
        out<<"Sensor Type: "<<(module->m_sensor).getSensorName()<<std::endl;
    }
    return out;
}