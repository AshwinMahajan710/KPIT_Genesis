#ifndef GLOBAL_H
#define GLOBAL_H

#include"EngineModule.h"
#include"EngineType.h"
#include<stdexcept>
#include"SensorModule.h"

void updateAllModulesEfficiency(EngineModule* modules[], int size, float value);
void calculateTotalPowerOutput(EngineModule* modules[], int size);
void isSensorCritical(SensorModule* sensors[], int size);

#endif // GLOBAL_H
