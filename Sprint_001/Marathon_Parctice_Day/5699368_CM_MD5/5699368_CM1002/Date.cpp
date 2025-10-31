#include<iostream>
#include<string>
#include<stdexcept>
#include"Date.h"

// list for validating days
constexpr int DAYS_IN_MONTH[] = {0,31,28,31,30,31,30,31,31,30,31,30,31}; // intentionally adding 0th index so that we can easily validate month by passing month value from 1 directly  
constexpr const char* MONTH_NAME[] = {"","January","February","March","April","May","June","July","August","Septeber","October","November","December"};

// default constructor
Date::Date() : m_day(0), m_month (0), m_year(0){}

// Parametrized constructor -->  for date input from user
Date::Date(unsigned int d_, unsigned int m_, unsigned int y_) : m_year(y_){

    // validating month value
    if( m_> 12 || m_ < 1 ) {throw std::invalid_argument("Exception: \"Invalid Month Val\"");}
    else {m_month = m_;}

    // validating day value
    m_day = checkDay(d_);
    std::cout<<"Valid"<<std::endl;
}

// check day function --> to validate day
unsigned int Date::checkDay(unsigned int testDay_) const{
    bool isLeapYear = (m_year%400 == 0 || (m_year%4 == 0 && m_year%100 != 0)); //checking is year leap or not
    if(!isLeapYear){
        if(testDay_ > 0 && testDay_ <= DAYS_IN_MONTH[m_month]){
            return testDay_;
        }
        else{
            throw std::invalid_argument("Exception: \"Invalid Day for " + std::string(MONTH_NAME[m_month]) + "\"");
        }
    } 
    else{
        if(m_month == 2){
            if(testDay_ > 0 && testDay_ <= DAYS_IN_MONTH[m_month] + 1){
                return testDay_;
            }
            else{
                if(testDay_ > 0 && testDay_ <= DAYS_IN_MONTH[m_month]){
                    return testDay_;
                }
                else{
                    throw std::invalid_argument("Exception: \"Invalid Day for " + std::string(MONTH_NAME[m_month]) + "\"");
                }       
            }
        }
    }
    return 0; // only necessray return for compilation
}

// function to print year
void Date::printDay() const{
    std::cout<<"Date: "<<m_day<<"-"<<m_month<<"-"<<m_year<<std::endl;
}

// setters definition
void Date::setDay(int d_){
    this->m_day = checkDay(d_);
}
void Date::setMonth(int m_){
    if(m_>0 && m_<=12 ){
        m_month = m_;
    }
    else {
        throw std::invalid_argument("Exception: \"Month has invalid value\"");
    }
}
void Date::setYear(int y_){
    this->m_year = y_;
}