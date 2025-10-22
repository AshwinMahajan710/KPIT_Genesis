#ifndef ENVIRONMENTDATA_H
#define ENVIRONMENTDATA_H

class EnvironmentData{
    private:
        float m_ambientTemperature;
        float m_altitude;
        float m_humidity;

    public:
        EnvironmentData(float ambientTemp_, float altitude_, float humidity_);
        void printEnvironmentData() const;
};

#endif // ENVIROMENTALDATA_H
