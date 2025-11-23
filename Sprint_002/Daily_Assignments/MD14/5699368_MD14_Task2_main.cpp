#include<string>
#include<variant>
#include"5699368_MD14_Task2_Global.h"
#include"5699368_MD14_Task2_SensorReading.h"
#include<iostream>

int main(){

    // creating 3 objects
    SensorReading r1("Temp", std::variant<int , float, std::string> (122.0f));
    SensorReading r2("Status", std::variant<int , float, std::string> ("Active"));
    SensorReading r3("Speed", std::variant<int , float, std::string> (200));

    // printng sensor info
    printSensorReading(r1);
    printSensorReading(r2);
    printSensorReading(r3);

    // chekcing the types
    r1.processReading();
    r2.processReading();
    r3.processReading();
    
    return 0;
}