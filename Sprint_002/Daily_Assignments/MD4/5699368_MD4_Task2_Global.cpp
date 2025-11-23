#include"5699368_MD4_Task2_Global.h"
#include"5699368_MD4_Task2_Sensor.h"
#include<iostream>

// by ref
void logSensorByRef(Sensor& V){
    std::cout<<"\nPrinting details via call by Ref: "<<std::endl;
    V.print();
}

// by rValue ref
void logSensorByRRef(Sensor&& V){
    std::cout<<"\nPrinting details via call by R value Ref: "<<std::endl;
    V.print();
}

// by pointer
void logSensorByPtr(Sensor* V){
    std::cout<<"\nPrinting details via call by Pointer: "<<std::endl;
    V->print();
}
