#ifndef GLOBAL_H
#define GLOBAL_H

#include"Battery.h"
#include<string>
#include<iostream>
#include<stdexcept>

// function to search battery via manufacturer
void searchBattriesByManufacturer(Battery* batteries_, int count_, const std::string& manufacturer_);

// function to show all batteries details
void showAllBatteries(Battery* batteries_, int count_); 


#endif // GLOBAL_H
