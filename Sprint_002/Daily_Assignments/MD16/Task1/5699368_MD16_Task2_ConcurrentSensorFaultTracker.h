#ifndef INC_5699368_MD16_TASK2_CONCURRENTSENSORFAULTTRACKER_H
#define INC_5699368_MD16_TASK2_CONCURRENTSENSORFAULTTRACKER_H

#include<unordered_map>
#include<queue>
#include<vector>
#include<string>
#include<mutex>

class ConcurrentSensorFaultTracker{
    private:
        std::unordered_map<std::string, std::vector<int>> m_faultMap; // mapping sensorId to vector of fault codes
        std::priority_queue<std::pair<int, std::string>> m_faultQueue; // high fault code --> high priority
        mutable std::mutex m_faultMutex; // protecting acceess to both faultMap and faultQueue

    public:
        ConcurrentSensorFaultTracker() = default;
        ConcurrentSensorFaultTracker(const ConcurrentSensorFaultTracker&) = delete;
        ConcurrentSensorFaultTracker(ConcurrentSensorFaultTracker&&) = default;

        // adding fault to map and queue --> thread safe addition of fault to map and queue
        void reportfault(const std::string& sensorId, int faultCode);

        // getting the fault codes for sensor --> thread safe retrieval of fault codes
        std::vector<int> getFaults(const std::string& sensorId) const;

        // pops and return highest priority fault --> throw runtime error is empty --> thread safe pop of highest priority fault
        std::pair<int , std::string > getNextCriticalFault(); 

        // returns true if queue is not emptty --> thread safe check for fault emptyness
        bool hasFaults() const;

        // getter for all faults
        std::unordered_map<std::string, std::vector<int>> getFaultMap() const;

};

#endif // INC_5699368_MD16_TASK2_CONCURRENTSENSORFAULTTRACKER_H
