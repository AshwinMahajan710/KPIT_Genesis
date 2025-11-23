#ifndef INC_5699368_MD15_TASK2_SMARTSENSORDIAGNOSTICS_H
#define INC_5699368_MD15_TASK2_SMARTSENSORDIAGNOSTICS_H

#include<memory>
#include<vector>

class SmartSensorDiagnostics{
    private:
        std::unique_ptr<std::vector<double>> m_readings;
    public:
        SmartSensorDiagnostics()
            : m_readings(std::make_unique<std::vector<double>>()) {}
        ~SmartSensorDiagnostics() = default;
        
        // method to add solo reading
        void addReading(double reading_);

        // method to add multiple readings at a time
        template <typename... Args>
        void addMultipleReadings(Args... args){
            (addReading(args), ...);
        }

        // returning pair of min and max vals
        std::pair<double,double> getMinMax() const;
        
        // returning true if all readings below the threshold
        bool isValid(double threshold) const;
        
        // getting the readings count
        size_t getReadingsCount() const;

};

#endif // INC_5699368_MD15_TASK2_SMARTSENSORDIAGNOSTICS_H
