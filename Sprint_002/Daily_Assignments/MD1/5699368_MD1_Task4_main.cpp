
#include"5699368_MD1_Task4_ABS.h"
#include"5699368_MD1_Task4_SafetyFeature.h"
#include<iostream>
#include<string>
#include"5699368_MD1_Task4_Airbag.h"

using SafetyFeatureArray = SafetyFeature** ;

int main(){

    // Creating instance of objects and store them in SafetyFeatureArray
    SafetyFeatureArray arr = new SafetyFeature* [2];
    arr[0] = new Airbag("Front Airbag", true, 30);
    arr[1] = new ABS("Anti lock breaking", true, 98.5);

    // Calling activate and print data
    for(auto i =0;i<2;i++){
        std::cout<<"\n";
        arr[i]->activated();
        arr[i]->show();
    }

    // try to use copy constructor (should give error)
    // Airbag a1;
    // Airbag a2 = a1; // cannot be referenced it is a deleted function

    return 0;
}