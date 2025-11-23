#ifndef INC_5699368_MD16_TASK1_SENSORFAULTTRACKER_H
#define INC_5699368_MD16_TASK1_SENSORFAULTTRACKER_H

#include<unordered_map>
#include<string>
#include<vector>
#include<queue>

class SensorFaultTracker{
    private:
        std::unordered_map<std::string, std::vector<int>> m_faultMap; // mapping sensorId to vector of fault codes
        std::priority_queue<std::pair<int, std::string>> m_faultQueue; // high fault code --> high priority

    public:
        SensorFaultTracker() = default;
        SensorFaultTracker(const SensorFaultTracker&) = delete;
        SensorFaultTracker(SensorFaultTracker&&) = default;

        // adding fault to map and queue
        void reportfault(const std::string& sensorId, int faultCode);

        // getting the fault codes for sensor
        std::vector<int> getFaults(const std::string& sensorId) const;

        // pops and return highest priority fault --> throw runtime error is empty
        std::pair<int , std::string > getNextCriticalFault(); 

        // returns true if queue is not emptty
        bool hasFaults() const;

        // getter for all faults
        std::unordered_map<std::string, std::vector<int>> getFaultMap() const;

};

#endif // INC_5699368_MD16_TASK1_SENSORFAULTTRACKER_H
