// < = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = START = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = >
// SmartDevice.h

#ifndef SMARTDEVICE_H // SMARTDEVICE_H
#define SMARTDEVICE_H

#include <string>
// class SmartDevice
class SmartDevice{
  public:
      virtual void activate() const = 0; // pure virtual activate
      virtual std::string getName() const = 0; // pure virtual getName
      virtual ~SmartDevice(){}; // virtual destructor
  };

#endif