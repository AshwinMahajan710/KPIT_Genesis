#include<memory>
#include<vector>
#include"5699368_MD15_Task2_SmartSensorDiagnostics.h"
#include<limits>
#include<algorithm>
#include"5699368_MD15_Task2_Global.h"
#include<iostream>

int main(){

    // creating entries and adding things
    SmartSensorDiagnostics diagnostic;
     
    diagnostic.addReading(12.5);
    diagnostic.addReading(18.0);

    diagnostic.addMultipleReadings(5.0,7.5,10.0);

    std::cout<<"\nAre all readings Valid: "<<(diagnostic.isValid(20.0) ? "Yes": "No")<<std::endl;

    std::cout<<"\nComputing sum: "<<computeSum(1.0,2.0,3.0)<<std::endl;
    std::cout<<"\nComputing Average: "<<computeAverage(1.0,2.0,3.0)<<std::endl;

    // unpacking pair
    auto [min, max] = diagnostic.getMinMax();
    std::cout<<"Min element is: "<<min<<std::endl;
    std::cout<<"max element is: "<<max<<std::endl;

    return 0;
}