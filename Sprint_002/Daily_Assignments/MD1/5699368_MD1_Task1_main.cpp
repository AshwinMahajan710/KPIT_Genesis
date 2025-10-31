#include<iostream>
#include<string>
#include"5699368_MD1_Task1_Vehicle.h"
#include"5699368_MD1_Task1_Car.h"
#include"5699368_MD1_Task1_ElectricCar.h"
#include"5699368_MD1_Task1_Truck.h"

int main(){

    //creating aobjects of each
    Car c1("Car1234",2004,4);
    Truck t1("Car1234",2004,12345.00);
    ElectricCar e1("Car1234",2004,100);

    // Creating vehicle array
    Vehicle* arr[3];
    arr[0] = &c1;
    arr[1] = &t1;
    arr[2] = &e1;

    // printing
    for(int i=0;i<3;i++){
        std::cout<<"\nVehicle "<<i+1<<std::endl;
        arr[i]->displayInfo();
        arr[i]->runDiagnostics();
    }

    return 0;
}
