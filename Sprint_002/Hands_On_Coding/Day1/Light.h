// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// Light.h

#ifndef LIGHT_H	
#define LIGHT_H

#include <string>
#include"SmartDevice.h"
#include<stdexcept>

class Light: public SmartDevice{
  	private:
  		std::string m_name{};
  		int m_brightness{};
  	public:
  		
  		// constructors
  		Light() = default;
  		Light(const std::string& name_, int brightness_);
  		void activate() const override; // overrided activate
  		std::string getName() const override; // overrided getName
};

#endif