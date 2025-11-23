#include<string>
#include"CAR_CATEGORY.h"
#include<iostream>
#include"Car.h"
#include<vector>
#include"Global.h"

// function to count objects of given category
int foundOfGivenCategory(std::vector<std::unique_ptr<Car>>& cars, CAR_CATEGORY category_){
    int count = 0;
    for (auto &car: cars)
    {
        if(car->getCarCategory() == category_){
            count++;
        }
    }
    return count;
}