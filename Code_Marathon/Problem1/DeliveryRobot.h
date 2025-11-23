#ifndef DELIVERYROBOT_H
#define DELIVERYROBOT_H

#include"SensorType.h"
#include<string>

class DeliveryRobot{
    private:
        int m_robotID{};
        float m_speed {};
        bool m_obstacleAlert{};
        float m_frontSensorRange{};
        float m_rearSensorRange{};
        SensorType m_sensorType{};
        static int s_totalRobots;

    public:

        // constructors
        DeliveryRobot();
        DeliveryRobot(int id_, float speed_, bool obstacleAlert_, float frontRange_,float rearRange_, SensorType sensorType_);
        DeliveryRobot(const DeliveryRobot& other);

        // getters
        int getRobotID() const;
        float getSpeed () const;
        bool getObstacleAlert() const;
        float getFrontSensorRange() const;
        float getRearSensorRange() const;
        SensorType getSensorType() const;
        static int getTotalRobots(); // static function to get static variable count

        // setters
        void setRobotID(int id_);
        void setSpeed (float speed_);
        void setObstacleAlert(bool obstacleAlert_);
        void setFrontSensorRange(float frontRange_);
        void setRearSensorRange(float rearRange_);
        void setSensorType(SensorType sensorType_);

        // printing details
        void displayStatus() const;

        // helper:: to get sensor name
        std::string getSensorName() const;
};  

#endif // DELIVERYROBOT_H
