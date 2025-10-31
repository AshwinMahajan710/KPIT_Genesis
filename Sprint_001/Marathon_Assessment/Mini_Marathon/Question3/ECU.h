#ifndef ECU_H
#define ECU_H

#include"EngineState.h"

class ECU{
    private:
        int m_ecuId;
        EngineState m_engineState;
        int m_rpm;
        double m_coolantTemp; // temp in celcius
        double m_throttlePosition; // Throttle percentage (0–100)
        int* m_faultCodes;
        int m_faultCount;
        int m_totalFaultCodes; // helper --> Total capacity to store fault codes

    public:
        //constructor
        ECU();
        ECU(int ecuId_, EngineState state_, int rpm_, double coolantTemp_, int faultCount_);
        ECU(const ECU& other);
    // Destructor
    ~ECU();

    // copy assignment
    ECU& operator=(const ECU& other);

        // Getters
        int getECUId() const;
        EngineState getEngineState() const;
        int getRPM() const;
        double getCoolantTemp() const;
        double getThrottlePsition() const;
        int* getFaultCodes() const;
        int getFaultCount() const;
        int getTotalFaultCount() const;

        // Setters
        void setECUId(int ecuId_);
        void setEngineState(EngineState state_);
        void setRPM(int rpm_);
        void setCoolantTemp(double coolantTemp_);

        // startEngine() --> Transitions state from OFF → CRANKING → IDLE 
        void startEngine();

        // accelerate(double throttle) --> Updates throttle and RPM (RPM = throttle × 60)
        void accelerate(double throttle_);

        // addFaultCode(int code) --> Adds fault code dynamically
        void addFaultCode(int code_);

        // checkOverheating(): Sets state to OVERHEATING if coolantTemp > 105
        void checkOverheating();

};

#endif // ECU_H
