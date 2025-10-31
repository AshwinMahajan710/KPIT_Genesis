
#include"5699368_MD1_Task4_Airbag.h"
#include"5699368_MD1_Task4_SafetyFeature.h"
#include<iostream>
#include<string>

// constructor
Airbag::Airbag(const std::string& featureName_, bool isEnabled_, int deplymentThreshold_): SafetyFeature(featureName_, isEnabled_) ,m_deploymentThreshold(deplymentThreshold_){};

void Airbag::activated(){
    std::cout<<"\nActivating Airbag"<<std::endl;
}

void Airbag::show(){
    SafetyFeature::show();
    std::cout<<"\nDeployment Threshold: "<<m_deploymentThreshold<<std::endl;
}