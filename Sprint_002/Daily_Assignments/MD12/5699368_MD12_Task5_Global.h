#ifndef INC_5699368_MD12_TASK5_GLOBAL_H
#define INC_5699368_MD12_TASK5_GLOBAL_H

#include"5699368_MD12_Task5_Student.h"
#include<string>
#include<stdexcept>
#include<iostream>
#include<vector>
#include<memory>
#include<functional>

// function to create vector of student pointers
std::vector<std::unique_ptr<Student>> createStudents();

// increasing the grade of the student
void increasingGrade(Student&);
void decreasingGrade(Student&);
void recalculateGrades(std::vector<std::unique_ptr<Student>>& students, std::function<void (Student& )> func);
void findAverageGrade(const std::vector<std::unique_ptr<Student>>& students);



#endif // INC_5699368_MD12_TASK5_GLOBAL_H
