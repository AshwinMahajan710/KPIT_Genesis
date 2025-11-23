// < = = = = = = = = = =  Device.h  = = = = = = = = = = >
#ifndef DEVICE_H
#define DEVICE_H

#include<string>
#include"Status.h"

class Device{
  	private:
  		int m_id{};
  		std::string m_name{};
  		Status m_status{};
  
  	public:
  		
  		// default and parameterized constructor
  		Device() = default;
  		Device(int id_, const std::string& name_, Status status_);
  
  		// copy and copy assignment deleted
  		Device(const Device& ) = delete;
 		Device& operator =(const Device& ) = delete; 
  		
  		// move constructor and move assignment implementation
        Device(Device&& );
 		Device& operator =(Device&& ); 
  		
  		// display method to display details
  		void display() const;
  
  		// Helper --> statusString() to display status string
  		std::string statusString() const;
  
  		// getter for string to search with name
  		std::string getName() const;
  
  		// getter to get status for checking the active staus
  		Status getStatus() const;
  
  		// setter for status
  		void setStatus(Status status);
  
};
#endif