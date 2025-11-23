#ifndef SENSOR_H
#define SENSOR_H

#include<string>
#include<vector>
#include<functional>

class Sensor{
    private:
        std::string m_id{};
        std::vector<std::function<void(const std::string& )>> m_listeners;
    
    public:
        // constructors
        Sensor() = default;
        Sensor(const std::string& id_);
        void addListeners(std::function<void(const std::string& )> listen_);
        void triggerMessage(const std::string& message_); // triggering all callbacks with given message
        std::string getId() const;
};

#endif // SENSOR_H
