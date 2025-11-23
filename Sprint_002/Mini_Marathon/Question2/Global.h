#ifndef GLOBAL_H
#define GLOBAL_H

#include<string>
#include"Status.h"
#include"SmartAppliance.h"
#include<stdexcept>
#include<iostream>
#include<vector>
#include<memory>
#include<functional>

// function which will create vector of unique_ptr of SmartAppliance and then return it after adding some objects
std::vector<std::unique_ptr<SmartAppliance>> createAppliances();

// Function to search appliance using its name
SmartAppliance* searchAppliance(const std::vector<std::unique_ptr<SmartAppliance>>& appliances, const std::string& name);

// counts and prints appliances with status ON
void countOnAppliances(const std::vector<std::unique_ptr<SmartAppliance>>& appliances);

// Filters and displays appliances with discount above a given threshold
void filterByDiscount(const std::vector<std::unique_ptr<SmartAppliance>>& appliances, double threshold);

// Searches and displays an appliance by name
void searchByName(const   std::vector<std::unique_ptr<SmartAppliance>>& appliances, const std::string& target);

// Increase the discount of application by 5%
void increaseDiscount(SmartAppliance& appliance);

// decrease discount by 10 cap at 0%
void decreaseDiscount(SmartAppliance& appliance);

// Applies conditional discount logic to each appliance using a function passed as a parameter
void recalculateDiscount(std::vector<std::unique_ptr<SmartAppliance>>& appliances, std::function<void(SmartAppliance&)>);

// Calculates and prints the average discount across all appliances
void findAverageDiscount(const std::vector<std::unique_ptr<SmartAppliance>>& appliances);

#endif // GLOBAL_H
