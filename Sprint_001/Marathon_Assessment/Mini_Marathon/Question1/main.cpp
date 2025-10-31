#include<iostream>
#include<string>
#include<stdexcept>
#include"Global.h"
#include"Vehicle.h"

int main(){

    // TC1 --> creating vehicle in stack
    Vehicle v1(101,"Toyota", "Camry", 50.0, 15000.0, true);

    // TC2 --> getting data members values using getters
    std::cout<<"\nFor Vehicle getting Info via getters: "<<std::endl;
    std::cout<<"Vehicle ID: "<<v1.getVehicleId()<<std::endl;
    std::cout<<"Vehicle Manufacturer: "<<v1.getManufacturer()<<std::endl;
    std::cout<<"Vehicle Model: "<<v1.getModel()<<std::endl;
    std::cout<<"Vehicle Fuel Level: "<<v1.getFuelLevel()<<std::endl;
    std::cout<<"Vehicle Odometer: "<<v1.getOdometer()<<std::endl;
    std::cout<<"Vehicle Availability: "<<((v1.getIsAvailable()) ? "Yes":"NO")<<std::endl;

    // TC3 --> now driving the vehicle and displaying the odometer and fuellevel
    v1.drive(150.0);
    std::cout<<"\nValues after driving vehicle: "<<std::endl;
    std::cout<<"Vehicle Fuel Level: "<<v1.getFuelLevel()<<std::endl;
    std::cout<<"Vehicle Odometer: "<<v1.getOdometer()<<std::endl;
    std::cout<<std::endl;

    // TC4 --> trying to set invalid fuel level value
    try
    {
        v1.setFuelLevel(75.0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // TC5 --> refuling the vehicle
    v1.refuel(25.0);
    std::cout<<"\nNew fuel: "<<v1.getFuelLevel()<<std::endl;

    // TC6 --> Creating array of object
    Vehicle array[2];
    array[0] = Vehicle(102,"Honda", "Civic", 45.0, 12000.0, true);
    array[1] = Vehicle(103,"Ford", "Focus", 30.0, 18000.0, false);

    // TC7 --> compare odometer
    compareOdometer(array[0], array[1]);

    return 0;

}