#include"5699368_MD12_Task5_Student.h"
#include<string>
#include<stdexcept>
#include<iostream>

// constructor --> parameterized
Student::Student(int id_, const std::string& name_, double greade_): m_id(id_), m_name(name_){
    if(greade_<0.0 || greade_>100.0) {throw std::invalid_argument("Invalid Grade values...");}
    else {m_grade = greade_;}
}

// getters
int Student::getId () const{
    return m_id;
}
std::string Student::getName () const{
    return m_name;
}
double Student::getGrade () const{
    return m_grade;
}

void Student::setId (int id_){
    m_id = id_;
}
void Student::setName (const std::string& name_){
    m_name = name_;
}
void Student::setGrade (double grade_) {
    if(grade_<0.0 || grade_>100.0) {throw std::invalid_argument("Invalid Grade values...");}
    else {m_grade = grade_;}
}
        

// display function
void Student::display() const{
    std::cout<<"\nStudent ID: "<<m_id<<std::endl;
    std::cout<<"Student Name: "<<m_name<<std::endl;
    std::cout<<"Student Grade: "<<m_grade<<std::endl;
}