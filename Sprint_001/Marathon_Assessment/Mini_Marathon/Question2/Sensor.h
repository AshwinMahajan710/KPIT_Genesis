#ifndef SENSOR_H
#define SENSOR_H

#include<string>

enum SensorStatus{
    INACTIVE, 
    INITIALIZING, 
    ACTIVE, 
    FAULT,
    CALIBRATING
};

class Sensor{
    private:
        int m_sensorId;
        std::string m_sensorType;
        SensorStatus m_status;
        double m_detectionRange;
        int* m_dataPoints; // to store sensor readings
        int m_dataCount; // no of readings currently stored
        int m_capacity; // max no of readings can be stored
    
    public:
        // constructors
        Sensor();
        Sensor(int sensorId_, const std::string& sensorType_, SensorStatus status_, double detectionRange_, int capacity_);
        Sensor(const Sensor& other);

        // getters
        int getSensorId() const;
        std::string getSensorType() const;
        SensorStatus getStatus() const;
        double getDetectionRange() const;
        int* getDataPoints() const;
        int getDataCount() const;
        int getCapacity() const;

        // Setters
        void setSensorId(int sensorId_);
        void setSensorType(const std::string& sensorType_);
        void setStatus(SensorStatus status_);
        void setDetectionRange(double detectionRange_);

        // updateStatus(SensorStatus)  --> to update sensors operational status
        void updateStatus(SensorStatus status_);

        // recordData(int) --> adding new reading data
        void recordData(int data_);

        // getAverageReading() --> get average reading value
        double getAverageReading() const;

        // getStatusAsString() --> getting string value of status
        std::string getStatusAsString() const;

        // displaySensorInfo() --> to display all sensor info
        void displaySensorInfo() const;

        // destructor
        ~Sensor();
};

#endif // SENSOR_H
