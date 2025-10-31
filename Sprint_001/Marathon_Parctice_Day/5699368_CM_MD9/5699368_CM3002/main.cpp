#include"HeapSensor.h"
#include"Global.h"
#include<iostream>
#include<stdexcept>

int HeapSensor::s_totalInstances = 0;

int main(){

    // TC1 --> 
    const HeapSensor* arr1[6] = {new HeapSensor(0,3.30,30.0,true), new HeapSensor(1,2.75,28.5,true), new HeapSensor(2,4.90,29.0,false), nullptr, nullptr,nullptr};
    int n_1 = 3;
    float Min_Allowed_1 = 25.0;
    float Max_Allowed_1 = 35.0;
    std::cout<<"\nMaximum Voltage: "<<computeMaxVoltage(arr1, n_1)<<std::endl;
    std::cout<<"Average Temperature: "<<computeAverageTemperature(arr1,n_1)<<std::endl;
    std::cout<<"Instances until now : "<<HeapSensor::getTotalInstances()<<std::endl;
    for(int i=0;i<n_1;i++){
        if(arr1[i]!=nullptr){
            delete arr1[i];
            arr1[i] = nullptr;
        }
    }

    // TC2 --> 
    HeapSensor* arr2[6] = {new HeapSensor(0,6.0,-50.0,true), new HeapSensor(1,5.5,130.0,true),nullptr, nullptr, nullptr,nullptr};
    int n_2 = 3;
    float Min_Allowed_2 = -10.0;
    float Max_Allowed_2 = 120.0;
    adjustTemperaturesToRange(arr2,n_2,Min_Allowed_2,Max_Allowed_2);
    std::cout<<"\nMaximum Voltage: "<<computeMaxVoltage(const_cast<const HeapSensor**> (arr2), n_2)<<std::endl;
    std::cout<<"Average Temperature: "<<computeAverageTemperature(const_cast<const HeapSensor**> (arr2),n_2)<<std::endl;
    std::cout<<"Instances until now : "<<HeapSensor::getTotalInstances()<<std::endl;
    for(int i=0;i<n_2;i++){
        if(arr2[i]!=nullptr){
            delete arr2[i];
            arr2[i] = nullptr;
        }
    }
    
    // TC3 -->
    HeapSensor* arr3[6] = {nullptr, nullptr,nullptr, nullptr, nullptr,nullptr};
    int n_3 = 0;
    float Min_Allowed_3 = 0;
    float Max_Allowed_3 = 50.0;
    float avgTemp3 = computeAverageTemperature(const_cast<const HeapSensor**>(arr3), n_2);
    adjustTemperaturesToRange(arr3,n_3,Min_Allowed_3,Max_Allowed_3);
    std::cout<<"\nMaximum Voltage: "<<computeMaxVoltage(const_cast<const HeapSensor**> (arr3), n_3)<<std::endl;
    std::cout << "Average Temperature: " << (avgTemp3 == -1.0f ? "n/a" : std::to_string(avgTemp3)) << std::endl;
    std::cout<<"Instances until now : "<<HeapSensor::getTotalInstances()<<std::endl;
    for(int i=0;i<n_3;i++){
        if(arr3[i]!=nullptr){
            delete arr1[i];
            arr3[i] = nullptr;
        }
    }

    // TC4 --> 
    HeapSensor* arr4[6] = {new HeapSensor(5,0.50,-20.0,true), new HeapSensor(6,4.50,140.0,true),new HeapSensor(7,5.50,200.0,false), nullptr, nullptr,nullptr};
    int n_4 = 3;
    arr4[1]->calibrate(-2.0);
    arr4[0]->calibrate(0.95,1.0);
    float Min_Allowed_4 = -40.0;
    float Max_Allowed_4 = 100.0;
    adjustTemperaturesToRange(arr4,n_4,Min_Allowed_4,Max_Allowed_4);
    std::cout<<"\nMaximum Voltage: "<<computeMaxVoltage(const_cast<const HeapSensor**> (arr4), n_4)<<std::endl;
    std::cout<<"Average Temperature: "<<computeAverageTemperature(const_cast<const HeapSensor**> (arr4),n_4)<<std::endl;
    std::cout<<"Instances until now : "<<HeapSensor::getTotalInstances()<<std::endl;
    for(int i=0;i<n_4;i++){
        if(arr4[i]!=nullptr){
            delete arr4[i];
            arr4[i] = nullptr;
        }
    }

    // TC5 --> 
    HeapSensor* arr5[6] = {new HeapSensor(0,0.0,24.5,false), new HeapSensor(1,1.25,25.5,true),new HeapSensor(2,2.50,26.5,true), new HeapSensor(3,3.750,27.5,false), new HeapSensor(4,5.0,28.5,true),nullptr};
    int n_5 = 5;
    arr5[2]->calibrate(1.5);
    float Min_Allowed_5 = 26.0;
    float Max_Allowed_5 = 28.0;
    adjustTemperaturesToRange(arr5,n_5,Min_Allowed_5,Max_Allowed_5);
    std::cout<<"\nMaximum Voltage: "<<computeMaxVoltage(const_cast<const HeapSensor**> (arr5), n_5)<<std::endl;
    std::cout<<"Average Temperature: "<<computeAverageTemperature(const_cast<const HeapSensor**> (arr5),n_5)<<std::endl;
    std::cout<<"Instances until now : "<<HeapSensor::getTotalInstances()<<std::endl;
    for(int i=0;i<n_5;i++){
        if(arr5[i]!=nullptr){
            delete arr5[i];
            arr5[i] = nullptr;
        }
    }

    return 0;
}