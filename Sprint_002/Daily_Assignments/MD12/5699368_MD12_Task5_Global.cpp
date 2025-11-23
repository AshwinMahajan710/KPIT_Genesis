#include"5699368_MD12_Task5_Student.h"
#include<string>
#include<stdexcept>
#include<iostream>
#include<vector>
#include<memory>
#include"5699368_MD12_Task5_Global.h"


// function to create vector of student pointers
std::vector<std::unique_ptr<Student>> createStudents(){
    std::vector<std::unique_ptr<Student>> students;
    students.emplace_back(std::make_unique<Student>(1,"Ashwin",100));
    students.emplace_back(std::make_unique<Student>(2,"Saurabh",30));
    students.emplace_back(std::make_unique<Student>(3,"Yash",10));
    students.emplace_back(std::make_unique<Student>(4,"Digvijay",70));
    students.emplace_back(std::make_unique<Student>(5,"Vishal1",80));
    students.emplace_back(std::make_unique<Student>(6,"Vishal2",20));
    students.emplace_back(std::make_unique<Student>(7,"Dipak",30));
    students.emplace_back(std::make_unique<Student>(8,"Shubham",60));
    return students;
}

// incrasing the grade
void increasingGrade(Student& stud){
    ((stud.getGrade() + 5.0 ) > 100.0) ? (stud.setGrade(100.0)) : stud.setGrade(stud.getGrade() + 5.0);
    std::cout<<"Grade Increased.."<<std::endl;
}

void decreasingGrade(Student& stud){
    ((stud.getGrade() - 5.0 ) < 0.0) ? (stud.setGrade(0.0)) : stud.setGrade(stud.getGrade() - 5.0);
    std::cout<<"Grade Decreased.."<<std::endl;
}
void recalculateGrades(std::vector<std::unique_ptr<Student>>& students, std::function<void (Student& )> func){
    
    for(const std::unique_ptr<Student>& stud: students){
        if(stud->getGrade()<50) {func = increasingGrade;}
        else {func = decreasingGrade;}
        func(*(stud));
    }
}

void findAverageGrade(const std::vector<std::unique_ptr<Student>>& students){
    double sumGrades = 0.0;
    for(const std::unique_ptr<Student>& stud: students){
        sumGrades += stud->getGrade();
    }
    std::cout<<"\nAverage Grade is: "<<(sumGrades/students.size())<<std::endl;
}
