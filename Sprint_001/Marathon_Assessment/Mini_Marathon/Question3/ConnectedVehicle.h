#ifndef CONNECTEDVEHICLE_H
#define CONNECTEDVEHICLE_H

#include"ECU.h"
#include"GPSModule.h"
#include"EngineState.h"
#include"DriveMode.h"
#include<string>

class ConnectedVehicle{
    private:
        int m_vehicleId;
        std::string m_vin;
        ECU m_ecu;
        GPSModule m_gps;
        DriveMode m_currentMode;

    public:
        // constructor
    ConnectedVehicle();
    ConnectedVehicle(int vehicleId_, const std::string& vin_, const ECU& ecu_, const GPSModule& gps_, DriveMode currentMode_);

        // getter
        ECU getECU() const;
        GPSModule getGPS() const;
        // switchDriveMode(DriveMode mode) --> to change the drive mode
        void switchDriveMode(DriveMode mode_);

        // performDiagnostics(): Returns fault code summary
        void performDiagnostics() const;

        // getTelemetrySnapshot() -> Returns formatted string with ECU and GPS data
        void getTelemetrySnapshot() const;


};

#endif // CONNECTEDVEHICLE_H
