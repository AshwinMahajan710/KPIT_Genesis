// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// Thermostat.h

#ifndef THERMOSTAT_H	//THERMOSTAT_H
#define THERMOSTAT_H

#include <string>
#include"SmartDevice.h"

class Thermostat : public SmartDevice{
  	private:
        double m_temperature{};
		bool m_ecoMode{};

  	public:
  		
  		// constructor
  		Thermostat() = default;
  		Thermostat(const std::string& name_, double temperature_);
  		
  		// activate function
  		void activate() override;
  		
		void enableEcoMode(bool mode_);
};
#endif