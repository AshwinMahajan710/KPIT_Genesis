#ifndef ENGINEMODULE_H
#define ENGINEMODULE_H

#include"EngineType.h"
#include<string>

class EngineModule{
    private:
        int m_id{};
        float m_rpm{};
        float m_temperature{};
        float m_efficiency{}; // 0-100
        EngineType m_type;
    public:
        // Constructors 
        EngineModule() = default;
        EngineModule(int id_, float rpm_, float temperature_, float efficiency_, EngineType type_);
    
        // Destructor
        ~EngineModule();

        // getters
        int getId() const;
        float getRpm() const;
        float getTemperature() const;
        float getEfficiency() const;
        EngineType getType() const;

        // setters
        void setId(int id_);
        void setRpm(float rpm_);
        void setTemperature(float temperature_);
        void setEfficiency(float efficiency_);
        void setType(EngineType type_);

        // display details
        virtual void displayDetails() const;

        // to update efficiency --> Throw std::range_error if value is outside [0, 100] --> For PETROL and DIESEL, cap efficiency at 80% and throw if exceeded
        void updateEfficiency(float value);

        // to calculate power
        virtual float calculatePowerOutput() const; // Return: rpm × efficiency × 0.01

        // helper --> to get EngineType name
        std::string getEngineTypeName() const;
};


#endif // ENGINEMODULE_H
