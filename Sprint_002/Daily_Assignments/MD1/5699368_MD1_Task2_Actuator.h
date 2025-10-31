#ifndef INC_5699368_MD1_TASK2_ACTUATOR_H
#define INC_5699368_MD1_TASK2_ACTUATOR_H

#include"5699368_MD1_Task2_ActuatorType.h"
#include<string>

class Actuator{
    private:
        ActuatorType m_actuatorType;
    
    public:
        Actuator() = default;
        Actuator(ActuatorType type_);

        // show sensor function to check which sensor it is
        void showActuator() const;
};

#endif // INC_5699368_MD1_TASK2_ACTUATOR_H
