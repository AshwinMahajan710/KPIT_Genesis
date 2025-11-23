#ifndef SMARTHOMECONTROLLER_H
#define SMARTHOMECONTROLLER_H

#include<vector>
#include"SmartDevice.h"
#include"Light.h"
#include"Thermostat.h"
#include<string>
#include<memory>
#include<unordered_map>
#include<functional>

class SmartHomeController{
    private:
        std::vector<std::unique_ptr<SmartDevice>> m_devices;
        std::unordered_map<std::string, std::function<void()>> m_callbacks;
    public:
        SmartHomeController() = default;
        void registerDevice(std::unique_ptr<SmartDevice> device, std::function<void()> onActivate);
        void activateDevice(const std::string& name);
        // activate all devices and its callbacks
        void activateAll(); 

        // special member functions --> COPY AND COPY ASSIGNMENT DELETED
        SmartHomeController(const SmartHomeController& other) = delete;
        SmartHomeController& operator=(const SmartHomeController& other) = delete;

        // special member functions --> MOVE AND MOVE ASSIGNMENT DELETED
        SmartHomeController(SmartHomeController&& other) = delete;
        SmartHomeController& operator=(SmartHomeController&& other) = delete;
};

#endif // SMARTHOMECONTROLLER_H
