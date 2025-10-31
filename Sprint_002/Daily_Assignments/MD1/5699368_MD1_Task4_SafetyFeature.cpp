#include<string>
#include<iostream>
#include"5699368_MD1_Task4_SafetyFeature.h"

SafetyFeature::SafetyFeature(const std::string& featureName_, bool isEnabled_){
    m_featureName = featureName_;
    m_isEnabled = isEnabled_;
}

// virtual function activated
void SafetyFeature::activated(){
    std::cout<<"Activating generic safety feature..."<<std::endl;
}

// virtual function show
void SafetyFeature::show(){
    std::cout<<"\nFeature Name: "<<m_featureName<<std::endl;
    std::cout<<"\nIs Enabled: "<<m_isEnabled<<std::endl;
}