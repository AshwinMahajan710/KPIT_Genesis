#include<vector>
#include"5699368_MD15_Task1_SensorAggregator.h"
#include<algorithm>
#include<limits>
#include<iostream>

template <typename... Args>
double computeSum(Args... values){
    return (values + ... + 0);
}

int main(){

    SensorAggregator aggregator;

    // TO ADD SINGLE RADING
    aggregator.addReadings(1234.90);

    // to add multiple readings
    aggregator.addMultipleReadings(1234,6789,345.6,2345.8);

    std::cout<<"Sum is: "<<aggregator.getSum()<<std::endl;
    std::cout<<"MIN is: "<<aggregator.getMin()<<std::endl;
    std::cout<<"MAX is: "<<aggregator.getMax()<<std::endl;

    std::cout<<"Individual sum is: "<<computeSum(1234,55,233,44,5)<<std::endl;

    return 0;
}