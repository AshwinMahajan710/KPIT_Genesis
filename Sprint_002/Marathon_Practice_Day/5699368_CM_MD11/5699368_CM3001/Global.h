#ifndef GLOBAL_H
#define GLOBAL_H

#include<string>
#include"CAR_CATEGORY.h"
#include<iostream>
#include"Car.h"
#include<vector>
#include<memory>

int foundOfGivenCategory(std::vector<std::unique_ptr<Car>>& cars, CAR_CATEGORY category_);

#endif // GLOBAL_H
