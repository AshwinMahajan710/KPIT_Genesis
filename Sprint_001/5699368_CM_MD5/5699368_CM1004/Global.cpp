#include"Vehicle.h"
#include"Global.h"
#include<limits>
#include<cfloat>

// function to print vehicle details with min avg score
void findMinAvgScoore(Vehicle vArr_[], int size_){
    Vehicle* ptr = nullptr; // will point to the vehicle with minAvgScore
    float minAvgScore = FLT_MAX; // explicit conversion to double
    for(int i=0;i<size_;i++){
        float curr_total_score = 0.0;
        const int* curr_test_scores = vArr_[i].getTestScores();
        for(int j=0;j<vArr_[i].getNumberOfTestRuns();j++){
            curr_total_score += curr_test_scores[i];
        }
        if(minAvgScore > (curr_total_score / vArr_[i].getNumberOfTestRuns())) {ptr = &vArr_[i];}
    }
    std::cout<<"\nFollowing are the details for Vehicle with min Avg Score: ";
    std::cout<<*(ptr); 
}

// function to print vehicles of given vehicle type
void showVehicles(Vehicle vArr_[], int size_, VehicleType type_){
    bool found = false;
    for(int i=0;i<size_;i++){
        if(vArr_[i].getVehicleType() == type_){
            std::cout<<"\nVehicle Found: ";
            std::cout<<vArr_[i];
            found = true;
        }
    }
    if(!found){
        throw std::out_of_range("EXception: \"Vehicle Object Not found.\"");
    }
}