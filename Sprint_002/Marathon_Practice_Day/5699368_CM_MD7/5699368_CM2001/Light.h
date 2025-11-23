#ifndef LIGHT_H	
#define LIGHT_H

#include <string>
#include"SmartDevice.h"
#include<stdexcept>

class Light: public SmartDevice{
  	private:
  		int m_brightness{};
        bool m_isOn{};

  	public:
  		// constructors
  		Light() = default;
  		Light(const std::string& name_, int brightness_);
  		void activate() override; // overrided activate
        void setBrightness(int brightness_);
};

#endif