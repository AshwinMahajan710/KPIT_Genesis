#include"TotalCostOfOwnership.h"
#include<vector>
#include<memory>
#include"Vehicle.h"
#include"Registration.h"
#include"Maintainance.h"
#include"Insuarance.h"
#include"Global.h"
#include<cfloat>
#include<functional>
#include<iostream>

int main(){

    // cretaing individual objects

    // vehicle objects
    Vehicle v1("Toyota","Camry", 2022, VEHICLE_TYPE::SEDAN, FUEL_TYPE::GASOLINE, TRANSMISSION_TYPE::AUTOMATIC, 25000.0);
    Vehicle v2("Honda","Civic", 2021, VEHICLE_TYPE::SEDAN, FUEL_TYPE::GASOLINE, TRANSMISSION_TYPE::MANUAL, 20000.0);
    Vehicle v3("Ford","F-150", 2020, VEHICLE_TYPE::TRUCK, FUEL_TYPE::DIESEL, TRANSMISSION_TYPE::AUTOMATIC, 30000.0);

    // maintainace obj
    Maintainance m1(500.0, 200.0, 1000.0);
    Maintainance m2(400.0, 150.0, 800.0);
    Maintainance m3(600.0, 250.0, 1200.0);

    // Insuarance obj
    Insuarance I1(500.0 , 1000.0, 2000.0);
    Insuarance I2(400.0 , 800.0, 1500.0);
    Insuarance I3(600.0 , 1200.0, 2500.0);

    // Registration obj
    Registration R1(100.0,200.0);
    Registration R2(80.0,150.0);
    Registration R3(120.0,250.0);


    // cretaing obj of total cost
    std::vector<std::unique_ptr<TotalCostOfOwnership>> vehicles;
    vehicles.emplace_back(std::make_unique<TotalCostOfOwnership>(v1,R1,m1,I1));
    vehicles.emplace_back(std::make_unique<TotalCostOfOwnership>(v2,R2,m2,I2));
    vehicles.emplace_back(std::make_unique<TotalCostOfOwnership>(v3,R3,m3,I3));

    // check the lowest cost vehicle
    const Vehicle* minCostVehicle = findLowestTotalCostVehicle(vehicles);
    if(minCostVehicle == nullptr){
        std::cout<<"No vehicle found...."<<std::endl;
    }else{
        std::cout<<"Vehicle Found...Below are the details"<<std::endl;
        minCostVehicle->display();
    }

    return 0;
}