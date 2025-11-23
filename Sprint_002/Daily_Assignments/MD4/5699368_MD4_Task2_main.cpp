#include<string>
#include"5699368_MD4_Task2_State.h"
#include"5699368_MD4_Task2_Sensor.h"
#include"5699368_MD4_Task2_Global.h"
#include<iostream>

int main(){
    
    // initializing objects via uniform initialziation
    Sensor s1{201,"Temperature", 1.05, 0.2,State::CALIBRATED};
    Sensor s2{202,"Pressure", 0.98, -0.1,State::UNCALIBRATED};
    Sensor s3{203,"Humidity", 1.00, 0.0,State::ERROR};

    // applying calibtration to s2
    s2.applyCallibration(1.10,-0.5);

    // setting state of s2
    s2.setState(State::ERROR);

    // logging sensor s2 --> by ref, rvalueref, by ptr
    logSensorByRef(s2);
    logSensorByRRef(std::move(s2));
    logSensorByPtr(&s2);

    // lamda function to check critical sensors
    auto checkCriticalSensors = [](Sensor& s){return(s.getGain()>1.0 || s.getState()==State::ERROR);};

    // storing critical sensors
        // storing the results in array and storing them
    Sensor* arr[3] = {&s1,&s2,&s3};
    for(auto &i: arr){
        if(!checkCriticalSensors(*i)){
            i = nullptr;
        }
    }

    std::cout<<"\nFollowing are the details of filtered Critical Sensors: "<<std::endl;
    // printing 
    for(auto &i: arr){
        if(i!=nullptr){
            std::cout<<std::endl;
            i->print();

        }
    }

    return 0;
}