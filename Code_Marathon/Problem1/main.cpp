#include"SensorType.h"
#include"DeliveryRobot.h"
#include<string>
#include<iostream>
#include"Global.h"

// initializing static variable
int DeliveryRobot::s_totalRobots = 0;

int main(){

    // TC1 --> creating robot1 ob heap
    DeliveryRobot robot1(101,80.5, true, 120.0,60.0, SensorType::LIDAR);
    
    // TC2 --> cloning robot1 into robot2
    DeliveryRobot* robot2 = cloneRobot(&robot1);

    // TC3 -->  calling display status for both robots
    std::cout<<"\nPrinting attribute for robot1: "<<std::endl;
    robot1.displayStatus();
    std::cout<<"\nPrinting attribute for robot2: "<<std::endl;
    robot2->displayStatus();

    // TC4 --> printing both robot summary
    printRobotSummary(&robot1);
    printRobotSummary(robot2);

    // TC5 --> Calling getTotalRobots
    std::cout<<"\nTotal Robots Count: "<<DeliveryRobot::getTotalRobots()<<std::endl;

    // TC6 --> Creating array of two obj and analyze fleet efficiency
    DeliveryRobot* fleet[2] = {&robot1, robot2};
    evaluateFleetEfficiency(fleet, 2);

    // deleting heap objects
    delete robot2;
    robot2 = nullptr;

    fleet[0] = nullptr;
    
    return 0;
}