#include"SensorType.h"
#include"DeliveryRobot.h"
#include<string>
#include<iostream>

// constructor --> default
DeliveryRobot::DeliveryRobot(): DeliveryRobot(0,0.0f,false,0.0,0.0,SensorType::CAMERA){
    s_totalRobots++;
}

// constructors --> parameterized
DeliveryRobot::DeliveryRobot(int id_, float speed_, bool obstacleAlert_, float frontRange_,float rearRange_, SensorType sensorType_): m_robotID(id_), m_speed(speed_), m_obstacleAlert(obstacleAlert_), m_frontSensorRange(frontRange_), m_rearSensorRange(rearRange_), m_sensorType(sensorType_){
    s_totalRobots++;
}

// constructor --> copy
DeliveryRobot::DeliveryRobot(const DeliveryRobot& other): m_robotID(other.m_robotID), m_speed(other.m_speed), m_obstacleAlert(other.m_obstacleAlert), m_frontSensorRange(other.m_frontSensorRange), m_rearSensorRange(other.m_rearSensorRange), m_sensorType(other.m_sensorType){
    s_totalRobots++;
}

// getters
int DeliveryRobot::getRobotID() const{
    return m_robotID;
}
float DeliveryRobot::getSpeed () const{
    return m_speed;
}
bool DeliveryRobot::getObstacleAlert() const{
    return m_obstacleAlert;
}
float DeliveryRobot::getFrontSensorRange() const{
    return m_frontSensorRange;
}
float DeliveryRobot::getRearSensorRange() const{
    return m_rearSensorRange;
}
SensorType DeliveryRobot::getSensorType() const{
    return m_sensorType;
}

// setters
void DeliveryRobot::setRobotID(int id_){
    m_robotID = id_;
}
void DeliveryRobot::setSpeed (float speed_){
    m_speed = speed_;
}
void DeliveryRobot::setObstacleAlert(bool obstacleAlert_){
    m_obstacleAlert = obstacleAlert_;
}
void DeliveryRobot::setFrontSensorRange(float frontRange_){
    m_frontSensorRange = frontRange_;
}
void DeliveryRobot::setRearSensorRange(float rearRange_){
    m_rearSensorRange = rearRange_;
}
void DeliveryRobot::setSensorType(SensorType sensorType_){
    m_sensorType = sensorType_;
}
int DeliveryRobot::getTotalRobots(){
    return s_totalRobots;
}

// to display info
void DeliveryRobot::displayStatus() const{
    std::cout<<"\nPrinting attribute for robot: "<<std::endl;
    std::cout<<"Robot ID: "<<getRobotID()<<std::endl;
    std::cout<<"Robot Speed: "<<getSpeed()<<std::endl;
    std::cout<<"Robot Obstacle Alert: "<<(getObstacleAlert() ? "Active":"Not Active") <<std::endl;
    std::cout<<"Front Sensor Range: "<<getFrontSensorRange()<<std::endl;
    std::cout<<"Rear Sensor Range: "<<getRearSensorRange()<<std::endl;
    std::cout<<"Robot Sensor Type: "<<getSensorName()<<std::endl;
}

// // helper:: to get sensor name
std::string DeliveryRobot:: getSensorName() const{
    switch (m_sensorType)
    {
        case SensorType::CAMERA:{
            return "Camera";
            break;
        }
        case SensorType::LIDAR:{
            return "Lidar";
            break;
        }
        case SensorType::ULTRASONIC:{
            return "Ultrasonic";
        }
        default:
            return "Unkonwn";
        }
}