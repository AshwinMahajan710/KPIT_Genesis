#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include"Sensor.h"

int main(){
    // creating sensors
    std::vector<Sensor> m_sensors = {{"Speed",2,70.5},{"Light",2,70.5},{"Brake",2,70.5},{"Oil",2,70.5},{"Headlight",2,70.5}};

    // displaying sensors
    std::for_each(m_sensors.begin(), m_sensors.end(), [](const Sensor& sensor){sensor.display();});
    
    return 0;
}