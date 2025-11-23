#ifndef INC_5699368_MD16_TASK4_SENSOREVENTAGGREGATOR_H
#define INC_5699368_MD16_TASK4_SENSOREVENTAGGREGATOR_H

#include<unordered_map>
#include<queue>
#include<stack>
#include<array>
#include<string>
#include<vector>
#include<tuple>

class SensorEventAggregator{
    private:
        std::unordered_map<int, std::string> m_sensorIdToType; // maps each sensorId to its type
        std::priority_queue<std::tuple<int, int , std::string>, std::vector<std::tuple<int, int , std::string>>, std::greater<std::tuple<int, int , std::string>>> m_eventQueue; // lower priority val means high importnace
        std::stack<int> m_sensorHistory; // tracks history of processed sensor ids
        std::array<std::string, 5 > m_configData = {"CPU Added", "ECU Working", "Brakes system passed", "Oil Good", "Engine Temp okay"}; // stores fixed size configuration string for file system

    public:
        SensorEventAggregator() = default;
        SensorEventAggregator(const SensorEventAggregator&) = delete;
        SensorEventAggregator(SensorEventAggregator&&) = default;
        ~SensorEventAggregator() = default;

        // adding new sensorId and its type to map --> if already exist ignore it
        void addSensor(int sensorId, const std::string& type);

        // adding new event in priorityqueue
        void pushEvent(int priority, int sensorId, const std::string& description);

        // getting the highest priority Tuple
        std::tuple<int, int, std::string> popHighestPrioriy();

        // pops and returns most recent sensor id from stack
        int popSensorFromHistory() ;
        
        // retrieves configuration string at given index --> throws std::out_of_range if index invalid
        std::string getConfigData(size_t index) const;

        // getting sensortype by sensorId --> throws error if not found
        std::string getSensorType(int sensorId);
};

#endif // INC_5699368_MD16_TASK4_SENSOREVENTAGGREGATOR_H
