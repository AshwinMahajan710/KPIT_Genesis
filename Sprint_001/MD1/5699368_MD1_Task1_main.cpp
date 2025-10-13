#include"5699368_MD1_Task1_global.h"
#include"5699368_MD1_Task1_FleetVehicle.h"
#include<iostream>
#include<string>
#include<limits>

int main(){
    
    // Creating the array of 3 objects of FleetVehicle
    FleetVehicle* vehicles = new FleetVehicle[3];
    int vehicle_count = 0; // index to track no of vehicles in array

    // Start the loop
    std::cout<<" ---------------Welcome to Fleet Management System --------------- "<<std::endl;
    while (true)
    {
        std::cout<<"\n 1. Add vehicle details using parameterized constructor."<<std::endl;
        std::cout<<"2. Assign a driver."<<std::endl;
        std::cout<<"3. Refuel a vehicle."<<std::endl;
        std::cout<<"4. Update status."<<std::endl;
        std::cout<<"5. Display vehicle info."<<std::endl;
        std::cout<<"6. Exit"<<std::endl;

        int choice;
        std::cout<<"Enter Your choice: "<<std::endl;
        std::cin>>choice;

        switch (choice)
        {

        // case to add vehicle in array
        case 1: {
            
            // terminate if array is full
            if(vehicle_count >=3) {
                std::cout<<"No more vehicles can be added as memory is full..."<<std::endl;
            }
            
            // else add vehicle in array
            else{
                int vehicleID_;
                float fuelLevel_;
                double distanceTravelled_;
                char status_;
                bool availability_;
                std::string driverName_;

                std::cout<<"Enter all the details (Id, Fuel Level, Distance Travel, Status(A / I), Availability(1 / 0), Driver Name): ";
                std::cin>>vehicleID_>>fuelLevel_>>distanceTravelled_>>status_>>availability_;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                getline(std::cin,driverName_);
                vehicles[vehicle_count++] = FleetVehicle(vehicleID_,fuelLevel_,distanceTravelled_,status_, availability_, driverName_); // increment count after adding vehicle
                std::cout<<"Operation completed successfully..."<<std::endl;
            }
            break;
        }

        // case to chenge driver name
        case 2:{
            // first check the vehicle availability with respective id. Then change driver name only if vehicle found
            std::string new_driver_name;
            int id;
            bool found = false;
            std::cout<<"Enter the id of the vehicle to change or assign driver: "<<std::endl;
            std::cin>>id;
            std::cout<<"Enter the new name of driver: "<<std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(std::cin,new_driver_name);
            for(size_t i=0;i<vehicle_count;i++){
                if (vehicles[i].getVehicleID()==id)
                {
                    assignDriver(vehicles[i],new_driver_name);
                    std::cout<<"Driver changed successfully..."<<std::endl;
                    found = true;
                }
            }
            if(!found){
                std::cout<<"Respective vehicle with given id not available..."<<std::endl;
            }
            break;
        }

        // case to refuel vehicle
        case 3:{
            // first check the vehicle availability with respective id. Then check for valid refule value and only then refule vehicle wlse throw error 
            try{
                float refuel_val;
                int id;
                bool found = false;
                std::cout<<"Enter the id of the vehicle to refuel: "<<std::endl;
                std::cin>>id;
                std::cout<<"Enter the refule value: "<<std::endl;
                std::cin>>refuel_val;

                for(size_t i=0;i<vehicle_count;i++){
                    if (vehicles[i].getVehicleID()==id)
                    { 
                        refuelVehicle(vehicles[i],refuel_val);
                        std::cout<<"Fuel Capacity changed successfully..."<<std::endl;
                        found = true;
                        break;
                    }
                }
                if(!found){
                    std::cout<<"Respective vehicle with given id not available..."<<std::endl;
                    break;
                }
            } catch(const std::exception& e){
                std::cout<<e.what()<<std::endl;
            }
            break;
        }

        // case to update status of each vehicle
        case 4:{
            for (size_t i=0;i<vehicle_count;i++)
            {
                vehicles[i].updateStatus();
            }
            std::cout<<"Status of entire vehicles updated successfully..."<<std::endl;
            break;
        }

        // case to display vehicle information
        case 5:{
            std::cout<<"\nFollowing is the entire Information: "<<std::endl;
            for (size_t i=0;i<vehicle_count;i++)
            {   
                std::cout<<std::endl;
                vehicles[i].displayInfo();
            }
            break;
        }

        // Case to exit application
        case 6: {
            delete [] vehicles; // clearing dynamically allocated memory
            std::cout << "Thank you for using application..." << std::endl;
            return 0;
        }

        // default case in case of invalid input
        default:
            std::cout<<"Wrong choice ... enter again..."<<std::endl;
            break;
        }
    }

    return 0;
}
 