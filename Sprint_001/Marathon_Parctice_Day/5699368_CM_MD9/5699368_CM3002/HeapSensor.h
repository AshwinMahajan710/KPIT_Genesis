#ifndef HEAPSENSOR_H
#define HEAPSENSOR_H

// constants
static float MIN_VOLTAGE = 0.0f;
static float MAX_VOLTAGE = 5.0f;
static float MIN_TEMPERATURE = -40.0f;
static float MAX_TEMPERATURE = 125.0f;

// class heapsensor
class HeapSensor{
    private:
        int m_id;
        float m_voltageV;
        float m_temperatureC;
        bool m_active;
        static int s_totalInstances;
    
    public:
        //constructors
        HeapSensor();
        HeapSensor(int id_, float voltageV_, float temperatureC_, bool active_);

        // getters
        int getId() const;
        float getVoltageV() const;
        float getTemperatureC() const;
        bool getActive() const;
        static int getTotalInstances();

        // setters
        void setId(int id_);
        void setVoltageV(float voltageV_);
        void setTemperatureC(float temperatureC_);
        void setActive(bool active_);

        // overloaded function
        void calibrate(float tempOffset_);
        void calibrate(float tempScale_, float tempOffset_);

        // destructor
        ~HeapSensor();

};


#endif // HEAPSENSOR_H
