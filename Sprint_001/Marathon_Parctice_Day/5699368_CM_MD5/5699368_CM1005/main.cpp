#include"Ride.h"
#include"SharedTrip.h"
#include"Trip.h"
#include"IndividualTrip.h"
#include<stdexcept>
#include<string>
#include<iostream>

int main(){

    // creating objects first
    IndividualTrip it1("101REG","Ram", 29, 3, Ride::REGULAR, 58);
    SharedTrip st1("101REG", "Raj",29, 3, Ride::REGULAR, 3);
    IndividualTrip it2("101REG","Jay", 29, 3, Ride::REGULAR, 58);
    IndividualTrip it3("101REG","Rajesh", 29, 3, Ride::REGULAR, 58);
    SharedTrip st2("101REG", "Jayesh", 29, 3, Ride::REGULAR, 3); 

    // TC1 --> testing isTripAsPerStandard for individualTrip
    if(it1.isTripAsPerStandard()){ std::cout<<"\nTrip is Valid"<<std::endl;}
    else {std::cout<<"Trip is not Valid";}
    
    // TC2 --> testing isTripAsPerStandard for SharedTrip
    if(st1.isTripAsPerStandard()) std::cout<<"\nTrip is Valid"<<std::endl;
    else {std::cout<<"Trip is not Valid";}

    // TC3 --> Calculating fare for individualTrip
    std::cout<<"\nTrip fare for individual: "<<it2.calculateFare()<<std::endl;
    
    // TC4 --> Calculating fare for individualTrip with surcharge
    std::cout<<"\nTrip fare for individual with surpluse: "<<it3.calculateFare(12.0)<<std::endl;
    
    // TC5 --> Calculating fare for sharedTrip
    std::cout<<"\nTrip fare for shared passengers: "<<st2.calculateFare()<<std::endl;

    return 0;
}