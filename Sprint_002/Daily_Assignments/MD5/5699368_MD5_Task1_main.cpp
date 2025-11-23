#include"5699368_MD5_Task1_Global.h"
#include<iostream>
#include<functional>
#include<string>

int main(){

    // creating raw sensor array
    Sensor sensors[] = {{101,"TEMP",75.0,70.0}, {102,"PRESSURE",95.0,90.0},{103,"HUMIDITY",45.0,50.0}};

    // one lambda handler capturing threshold by value 
    sensors[0].setHandler([&](int id_, double value_) {
    if (sensors[0].getThreshold() > value_) {
        std::cout << "\nID: " << id_ << " Value: " << value_ << std::endl;
    }
});

    // one with bound member function std::bind
    Logger logger;
    sensors[1].setHandler(std::bind(&Logger::log, &logger, std::placeholders::_1, std::placeholders::_2));

    // one to bound with reference wrappers
    sensors[2].setHandler(std::reference_wrapper(logEvent));

    // replacing one handler to see how many time it triggerd
    int count = 0;
    sensors[1].setHandler([= ,&count](int id_, double value_) mutable -> void {count++; if(value_ > sensors[0].getThreshold()){ std::cout<<"\nID: "<<id_<<" Value: "<<value_<<std::endl;}});
    
    // Triggering the handlers by updating values
    dispatch(sensors, 3);
    
    std::cout<<"\nsensor 1 handler function used : "<<count <<" many times.."<<std::endl;

    return 0;
}