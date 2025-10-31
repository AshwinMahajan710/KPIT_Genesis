#include"ECU.h"
#include"GPSModule.h"
#include"EngineState.h"
#include"DriveMode.h"
#include"ConnectedVehicle.h"
#include<string>
#include<iostream>
#include<stdexcept>

int main(){

    // TC1 --> Creating ECU
    ECU ecu(1,EngineState::OFF,0.0, 20.0, 5);

    // TC2 --> Calling start Engine
    ecu.startEngine();  

    // TC3 --> Accelerating vehicle
    ecu.accelerate(50.0);
    std::cout<<"\nAfter accelerating Throttle: "<<ecu.getThrottlePsition()<<std::endl;
    std::cout<<"After accelerating RPM: "<<ecu.getRPM()<<std::endl;

    // TC4 --> Adding fault code dynamically
    ecu.addFaultCode(420);
    std::cout<<"\nAfter adding fault code fault count: "<<ecu.getFaultCount()<<std::endl;
    std::cout<<"\nFault code Added: "<<ecu.getFaultCodes()[0]<<std::endl;

    // TC5 --> Overheating check after seting coolant temp 110
    ecu.setCoolantTemp(110.0);
    ecu.checkOverheating();

    // TC6 --> Updating GPS Positions
    GPSModule gps; // default constructor
    gps.updatePosition(18.52, 73.85);

    // TC7 --> creating connected vehicle object
    ConnectedVehicle vehicle(1001, "1HGBH", ecu, gps, DriveMode::NORMAL);

    // TC8 --> accessing RPM using composed object
    std::cout<<"\nRPM of the vehicle is: "<<vehicle.getECU().getRPM()<<std::endl;

    // TC9 --> switching the drivemode
    vehicle.switchDriveMode(DriveMode::AUTONOMOUS);

    // TC 10 --> Perform Diagnostics
    vehicle.performDiagnostics();

    // TC 11 --> getting telemetry snapshot
    vehicle.getTelemetrySnapshot();

    return 0;
}