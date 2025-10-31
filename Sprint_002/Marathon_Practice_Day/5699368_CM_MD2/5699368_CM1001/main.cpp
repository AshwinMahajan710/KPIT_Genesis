#include<string>
#include"VehicleType.h"
#include"Vehicle.h"
#include"Car.h"
#include"Truck.h"
#include<vector>
#include"Global.h"

int main(){

    // creating a vector of vehicle pointers
    std::vector<Vehicle*> vehicles;
    vehicles.push_back(new Car("1HGCM263144",5));
    vehicles.push_back(new Truck("3H7CN789GGU",12.5));
    vehicles.push_back(nullptr);

    // printing info using global variable also delete obj memory at pointers after using them 
    for(auto i: vehicles){
        printVehicleInfo(i);        
        delete i;
        i = nullptr;
    }

    return 0;
}