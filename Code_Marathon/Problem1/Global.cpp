#include"SensorType.h"
#include"DeliveryRobot.h"
#include<string>
#include<iostream>

// function to analyze sensor performance
void analyzeSensorPerformance(const DeliveryRobot robots[], int count){
    for(auto i=0;i<count;i++){
        switch (robots[i].getSensorType())
        {
            case SensorType::LIDAR:{
                if(robots[i].getFrontSensorRange() > 100.0){
                    std::cout<<"\nLIDAR performing optimally"<<std::endl;
                }
                else{
                    std::cout<<"\nLIDAR range below threshold"<<std::endl;
                }
                break;
            }
            case SensorType::CAMERA:{
                if(robots[i].getRearSensorRange() < 30.0){
                    std::cout<<"\nCamera may need calibration"<<std::endl;
                }
                else{
                    std::cout<<"\nCamera functioning well"<<std::endl;
                }
                break;
            }
            case SensorType::ULTRASONIC:{
                if(robots[i].getObstacleAlert()){
                    std::cout<<"\nObstacle detected!"<<std::endl;
                }
                else{
                    std::cout<<"\nPath clear"<<std::endl;
                }
                break;
            }
        }
    }
}

// printing full details of robot object
void printRobotSummary(const DeliveryRobot* robot){
    std::cout<<"\nRobot Summary: ";
    std::cout<<"Robot "<<robot->getRobotID()<<" | Speed: "<<robot->getSpeed() <<" Km/Hr | Sensor: "<<robot->getSensorName()<<std::endl;
}

// Returns a deep copy of the vehicle using the copy constructor
DeliveryRobot* cloneRobot(const DeliveryRobot* original){
    DeliveryRobot* newRobot = new DeliveryRobot(*original);
    return newRobot;
}

// function to evaluate efficiency
void evaluateFleetEfficiency(DeliveryRobot* fleet[], int size){
    int countRobots = 0;
    for (auto i = 0; i < size; i++)
    {
        if(fleet[i]->getSpeed() > 60.0){
            printRobotSummary(fleet[i]);
            ++countRobots;
        }
    }
    if(countRobots>=size){
        std::cout<<"Fleet is operating at high efficiency"<<std::endl;
    }else{
        std::cout<<"Fleet performance below optimal threshold"<<std::endl;
    }
}