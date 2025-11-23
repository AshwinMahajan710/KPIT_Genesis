#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include<string>

class SmartDevice{
    private:
        std::string m_name{};
    protected:
        SmartDevice() = default;
        SmartDevice(const std::string& name_);
    public:
        virtual void activate() = 0;
        virtual std::string getName() const;
        virtual ~SmartDevice();
    
};

#endif // SMARTDEVICE_H
