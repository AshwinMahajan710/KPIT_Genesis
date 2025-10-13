#include "5699368_MD1_Task1_global.h"
#include "5699368_MD1_Task1_FleetVehicle.h"
#include <iostream>
#include <string>
#include <limits>

int main()
{
    constexpr int MAX_VEHICLES = 3;
    FleetVehicle vehicles[MAX_VEHICLES]; // Prefer stack allocation for safety
    int vehicle_count = 0;

    std::cout << "--------------- Welcome to Fleet Management System ---------------\n";

    bool is_running = true;
    while (is_running)
    {
        std::cout << "\n1. Add vehicle details using parameterized constructor.\n"
                  << "2. Assign a driver.\n"
                  << "3. Refuel a vehicle.\n"
                  << "4. Update status.\n"
                  << "5. Display vehicle info.\n"
                  << "6. Exit\n";

        int choice = 0;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice)
        {
            case 1:
            {
                if (vehicle_count >= MAX_VEHICLES)
                {
                    std::cout << "No more vehicles can be added as memory is full...\n";
                }
                else
                {
                    int vehicleID_ = 0;
                    float fuelLevel_ = 0.0F;
                    double distanceTravelled_ = 0.0;
                    char status_ = 'I';
                    bool availability_ = false;
                    std::string driverName_;

                    std::cout << "Enter details (ID, Fuel Level, Distance, Status (A/I), Availability (1/0), Driver Name): ";
                    std::cin >> vehicleID_ >> fuelLevel_ >> distanceTravelled_ >> status_ >> availability_;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, driverName_);

                    vehicles[vehicle_count] = FleetVehicle(vehicleID_, fuelLevel_, distanceTravelled_,
                                                           status_, availability_, driverName_);
                    ++vehicle_count;

                    std::cout << "Vehicle added successfully.\n";
                }
                break;
            }

            case 2:
            {
                int id = 0;
                std::string new_driver_name;
                bool found = false;

                std::cout << "Enter vehicle ID: ";
                std::cin >> id;

                std::cout << "Enter new driver name: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, new_driver_name);

                for (int i = 0; i < vehicle_count; ++i)
                {
                    if (vehicles[i].getVehicleID() == id)
                    {
                        assignDriver(vehicles[i], new_driver_name);
                        std::cout << "Driver changed successfully.\n";
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    std::cout << "Vehicle ID not found.\n";
                }

                break;
            }

            case 3:
            {
                try
                {
                    int id = 0;
                    float refuel_val = 0.0F;
                    bool found = false;

                    std::cout << "Enter vehicle ID to refuel: ";
                    std::cin >> id;
                    std::cout << "Enter refuel value: ";
                    std::cin >> refuel_val;

                    for (int i = 0; i < vehicle_count; ++i)
                    {
                        if (vehicles[i].getVehicleID() == id)
                        {
                            refuelVehicle(vehicles[i], refuel_val);
                            std::cout << "Fuel updated successfully.\n";
                            found = true;
                            break;
                        }
                    }

                    if (!found)
                    {
                        std::cout << "Vehicle ID not found.\n";
                    }
                }
                catch (const std::invalid_argument &e)
                {
                    std::cout << e.what() << '\n';
                }

                break;
            }

            case 4:
            {
                for (int i = 0; i < vehicle_count; ++i)
                {
                    vehicles[i].updateStatus();
                }
                std::cout << "All vehicle statuses updated successfully.\n";
                break;
            }

            case 5:
            {
                std::cout << "\nFleet Information:\n";
                for (int i = 0; i < vehicle_count; ++i)
                {
                    vehicles[i].displayInfo();
                    std::cout << '\n';
                }
                break;
            }

            case 6:
            {
                std::cout << "Exiting system. Thank you!\n";
                is_running = false;
                break;
            }

            default:
            {
                std::cout << "Invalid choice! Try again.\n";
                break;
            }
        }
    }

    return 0;
}
