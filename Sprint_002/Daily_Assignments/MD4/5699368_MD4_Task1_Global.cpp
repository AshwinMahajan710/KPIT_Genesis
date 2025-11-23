#include"5699368_MD4_Task1_Vehicle.h"
#include"5699368_MD4_Task1_Global.h"
#include<iostream>

// by value
void logVehicleByValue(Vehicle V){
    std::cout<<"\nPrinting details via call by value: "<<std::endl;
    V.print();
}

// by ref
void logVehicleByRef(Vehicle& V){
    std::cout<<"\nPrinting details via call by Ref: "<<std::endl;
    V.print();
}

// by rValue ref
void logVehicleByRRef(Vehicle&& V){
    std::cout<<"\nPrinting details via call by R value Ref: "<<std::endl;
    V.print();
}

// by pointer
void logVehicleByPtr(Vehicle* V){
    std::cout<<"\nPrinting details via call by Pointer: "<<std::endl;
    V->print();
}
