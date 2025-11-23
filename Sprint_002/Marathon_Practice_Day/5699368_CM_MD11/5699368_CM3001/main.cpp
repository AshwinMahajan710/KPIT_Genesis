#include<string>
#include"CAR_CATEGORY.h"
#include<iostream>
#include"Car.h"
#include<vector>
#include"Global.h"

int main(){

    // creating vector of cars and adding unique pointers
    std::vector<std::unique_ptr<Car>> cars;
    cars.emplace_back(std::make_unique<Car>("ABC123", "Toyota", "Camry", CAR_CATEGORY::SEDAN, 25000.0 , 5, 50));
    cars.emplace_back(std::make_unique<Car>("DEF456", "Honda", "Civic", CAR_CATEGORY::SEDAN, 20000.0 , 5, 40));
    cars.emplace_back(std::make_unique<Car>("GHI789", "Ford", "Mustang", CAR_CATEGORY::SPORTS_HATCHBACK, 30000.0 , 4, 60));
    cars.emplace_back(std::make_unique<Car>("JKL901", "Nissan", "Ultima", CAR_CATEGORY::SEDAN, 26000.0 , 5, 55));
    cars.emplace_back(std::make_unique<Car>("MNO234", "VW", "Golf", CAR_CATEGORY::SPORTS_HATCHBACK, 24000.0 , 4, 50));
    cars.emplace_back(std::make_unique<Car>("PQR567", "BMW", "3 Series", CAR_CATEGORY::SEDAN, 32000.0 , 5, 60));

    // Tc1 --> finding count of sedan 
    std::cout<<"\nCount of Sedan cars: "<<foundOfGivenCategory(cars, CAR_CATEGORY::SEDAN)<<std::endl;

    // Tc2 --> finding count of SUV 
    std::cout<<"\nCount of SUV cars: "<<foundOfGivenCategory(cars, CAR_CATEGORY::SUV)<<std::endl;

    return 0;
}