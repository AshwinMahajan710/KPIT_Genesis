// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// Thermostat.h

#ifndef THERMOSTAT_H	//THERMOSTAT_H
#define THERMOSTAT_H

#include <string>
#include"SmartDevice.h"

class Thermostat : public SmartDevice{
  	private:
        std::string m_name{};
        double m_temperature{};
  	public:
  		
  		// constructor
  		Thermostat() = default;
  		Thermostat(const std::string& name_, double temperature_);
  		
  		// activate function
  		void activate() const override;
  		
  		// getter for name
  		std::string getName() const override;
};
#endif