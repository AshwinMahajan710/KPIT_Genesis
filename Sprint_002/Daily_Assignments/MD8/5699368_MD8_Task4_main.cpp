#include<string>
#include<chrono>
#include"5699368_MD8_Task4_Sensor.h"
#include<random>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<thread>

int main(){

    // creating vector of sensor and adding sensors to it
    std::vector<Sensor> sensors;
    sensors.emplace_back(Sensor{"Speed",0,200});
    sensors.emplace_back(Sensor{"temperature",-20,50});
    sensors.emplace_back(Sensor{"Fuel",0,100});
    sensors.emplace_back(Sensor{"GPS",0,100});

    // creating vector of thread
    std::vector<std::thread> threads;
    threads.emplace_back(&Sensor::run, sensors[0]);
    threads.emplace_back(&Sensor::run, sensors[1]);
    threads.emplace_back(&Sensor::run, sensors[2]);
    threads.emplace_back(&Sensor::run, sensors[3]);

    for(auto &i : threads){
        i.join();
    }
    
    return 0;
}