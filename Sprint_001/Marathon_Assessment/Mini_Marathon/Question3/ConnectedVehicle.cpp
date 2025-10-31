#include"ECU.h"
#include"GPSModule.h"
#include"EngineState.h"
#include"DriveMode.h"
#include"ConnectedVehicle.h"
#include<string>
#include<iostream>
#include<stdexcept>

// constructor --> default
ConnectedVehicle::ConnectedVehicle() : ConnectedVehicle(0,"",ECU(0,EngineState::OFF,0,0.0,0),GPSModule(0.0,0.0,0.0,0.0), DriveMode::NORMAL){};

// constructor --> parameterized
ConnectedVehicle::ConnectedVehicle(int vehicleId_, const std::string& vin_, const ECU& ecu_, const GPSModule& gps_, DriveMode currentMode_)
: m_vehicleId(vehicleId_), m_vin(vin_), m_ecu(ecu_), m_gps(gps_), m_currentMode(currentMode_)
{
}

// switchDriveMode(DriveMode mode) --> to change the drive mode
void ConnectedVehicle::switchDriveMode(DriveMode mode_){
    m_currentMode = mode_;
}

// performDiagnostics(): Returns fault code summary
void ConnectedVehicle::performDiagnostics() const{
    int* codes = m_ecu.getFaultCodes();
    int count = m_ecu.getFaultCount();
    std::cout<<"Following are the fault values: "<<std::endl;
    for(int i=0;i<count;i++){
        std::cout<<" "<<codes[i];
    }
    std::cout<<std::endl;
}

// getTelemetrySnapshot() -> Returns formatted string with ECU and GPS data
void ConnectedVehicle::getTelemetrySnapshot() const{
    int m_ecuId;
        EngineState m_engineState;
        int m_rpm;
        double m_coolantTemp; // temp in celcius
        double m_throttlePosition; // Throttle percentage (0–100)
        int* m_faultCodes;
        int m_faultCount;
        int m_totalFaultCodes;
    std::cout<<"\nECU Details: "<<std::endl;
    std::cout<<"ECU Id: "<<m_ecu.getECUId()<<std::endl;
    std::cout<<"RPM: "<<m_ecu.getRPM()<<std::endl;
    std::cout<<"Coolant Temp: "<<m_ecu.getCoolantTemp()<<std::endl;
    std::cout<<"Throttle: "<<m_ecu.getThrottlePsition()<<std::endl;
    std::cout<<"Fault Count: "<<m_ecu.getFaultCount()<<std::endl;
    std::cout<<"Fault Codes: ";
    for(int i=0;i<m_ecu.getFaultCount();i++){
        std::cout<<" "<<m_ecu.getFaultCodes()[i];
    }

    std::cout<<"\nGPS Details: "<<std::endl;
    std::cout<<"Longitude: "<<m_gps.getLongitude()<<std::endl;
    std::cout<<"Lattitude: "<<m_gps.getLatitude()<<std::endl;
    std::cout<<"Speed: "<<m_gps.getSpeed()<<std::endl;
    std::cout<<"Heading: "<<m_gps.getHeading()<<std::endl;
}

ECU ConnectedVehicle::getECU() const{
    return m_ecu;
}
GPSModule ConnectedVehicle::getGPS() const{
    return m_gps;
}