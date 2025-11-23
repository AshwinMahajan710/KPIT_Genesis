#include"5699368_MD5_Task1_Global.h"
#include<iostream>

// free function to log sensor event
void logEvent(int id_, double value_){
    std::cout<<"\nID: "<<id_<<" Value: "<<value_<<std::endl;
}

// class logger --> to log events
void Logger::log(int id_, double value_){
    std::cout<<"\nID: "<<id_<<" Value: "<<value_<<std::endl;
}


// dispatch function to simulate values and update them 
void dispatch(Sensor sensors[], int size){
    for(int i=0;i<size;i++){
        sensors[i].update(sensors[i].getThreshold() + 10);
    }
}