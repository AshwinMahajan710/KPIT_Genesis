#ifndef INC_5699368_MD2_TASK1_VEHICLE_H
#define INC_5699368_MD2_TASK1_VEHICLE_H

#include<string>
#include"5699368_MD4_Task1_Status.h"

class Vehicle{
    public:
        int m_id =  -1;
        std::string m_model = "";
        double m_temperature = 0.0;
        double m_voltage = 0.0;
        Status m_status = Status::FAIL;

        // constructor
        Vehicle() = default; // uses in class initialization
        Vehicle(int id_,const std::string& model_, double temperature_, double voltage_, Status status_);

        void updateTemperature(double temp_);
        void updateVoltage(double voltage_);
        void setStatus(Status&& status_); // for rvalue
        void print() const;

        void setStatus(const Status& ) = delete;   // for lvalue --> but deleted

        // Helper:- printing the status 
        std::string getStatusString() const;
};

#endif // INC_5699368_MD2_TASK1_VEHICLE_H
