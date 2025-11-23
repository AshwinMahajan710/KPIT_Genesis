// < = = = = = = = = = =  main.cpp  = = = = = = = = = = >
#include<memory>
#include<vector>
#include"Device.h"
#include"Status.h"
#include"Global.h"
#include<iostream>
#include<string>
#include<functional>

using DeviceVector = std::vector<std::unique_ptr<Device>>;
int main(){
  
  // get the vector of devices
  DeviceVector devices = createDevices();
  
  // Displaying all the devices
  std::cout<<"\nFollowing are all the devices: "<<std::endl;
  for(auto &device : devices){
    device->display();
  }
  
  // getting name to search device --> and the search device
  std::string name{};
  std::cout<<"\nEnter device name: "<<std::endl;
  std::cin>>name;
	
  Device* searchedDevice = searchDevice(devices, name);
  if(searchedDevice == nullptr){std::cout<<"\nDevice with respective name not found: "<<std::endl;}
  else{
    std::cout<<"\nDevice founded...Following are the details: ";
    searchedDevice -> display();
  }
  
  // using lambda to count active things
  int count = 0;
  auto lambda = [](DeviceVector& devices, int &count) mutable -> void {
    for(auto& device: devices){
      if(device->getStatus() == Status::ACTIVE) {count++;}
    }
  } ;
  
  lambda(devices, count);
  std::cout<<"\nThe total active devices are: "<<count<<std::endl;
  
  // using std::function to apply an operation to change status to active
  std::function<void(DeviceVector& devices, Status status)> func;
  func = [](DeviceVector& devices, Status status)  mutable -> void{
    for(auto& device: devices){
      device->setStatus(Status::ACTIVE);
    }
  };
  
  func(devices, Status::ACTIVE);
  
  return 0;
}




