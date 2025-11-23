#include<string>
#include"5699368_MD15_Task3_SensorNode.h"
#include"5699368_MD15_Task3_PressureSensor.h"
#include"5699368_MD15_Task3_TemperatureSensor.h"
#include<array>
#include<memory>
#include"5699368_MD15_Task3_SensorGrid.h"
#include<stdexcept>
#include<algorithm>
#include<numeric>
#include"5699368_MD15_Task3_Global.h"

int main(){

    SensorGrid grid;

    grid.setSensor(0, std::make_shared<TemperatureSensor>("Engine",1234.0));
    grid.setSensor(1, std::make_shared<PressureSensor>("Brake",-700.0));
    grid.setSensor(2, std::make_shared<TemperatureSensor>("ECU",14.0));
    grid.setSensor(3, std::make_shared<PressureSensor>("Wheel",124.0));
    grid.setSensor(4, std::make_shared<TemperatureSensor>("Engine",10000.0));

    // compute average and compute sum
    
}