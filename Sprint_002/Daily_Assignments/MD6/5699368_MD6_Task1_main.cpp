
#include<iostream>
#include<functional>
#include<string>
#include<array>

double Analyzer(std::function<double(std::array<int, 5> arr)> func, std::array<int, 5> arr ){
    return func(arr);
}

double fuelConsumptionEstimator(std::array<int, 5> arr){
    double totalRPM = 0.0;
    for (int i = 0; i < 5; i++){
        totalRPM += arr[i];
    } 
    return (totalRPM / 100.0);
}

double engineStressIndex(std::array<int, 5> arr){
    int totalRPM = 0.0;
    for (int i = 0; i < 5; i++){
        totalRPM += arr[i];
    } 
    return (totalRPM % 1200);
}

double ecoScore(std::array<int, 5> arr){
    double totalRPM = 0.0;
    for (int i = 0; i < 5; i++){
        totalRPM += arr[i];
    } 
    return (5000 - totalRPM);
}

int main(){

    // array
    std::array<int, 5> arr = {1000,1500,2000,2500,3000};

    // choice
    int ch;
    std::cout<<"Enter your choice: "<<std::endl;
    std::cin >> ch;

    switch (ch)
    {
        case 1:{
            // std::function<double(std::array<int, 5> arr)>  fuelEstimator = fuelConsumptionEstimator;
            std::cout<<"\nFuel consumption is: "<<Analyzer(fuelConsumptionEstimator, arr)<<std::endl;
            break;
        }
        
        case 2:{
            // std::function<double(std::array<int, 5> arr)>  fuelEstimator = fuelConsumptionEstimator;
            std::cout<<"\nEngine stress index is: "<<Analyzer(engineStressIndex, arr)<<std::endl;
            break;
        }

        case 3:{
            // std::function<double(std::array<int, 5> arr)>  fuelEstimator = fuelConsumptionEstimator;
            std::cout<<"\nEco score is: "<<Analyzer(ecoScore, arr)<<std::endl;
            break;
        }
    
        default:
            std::cout<<"\nInvalid choice"<<std::endl;
            break;
    }

    return 0;
}