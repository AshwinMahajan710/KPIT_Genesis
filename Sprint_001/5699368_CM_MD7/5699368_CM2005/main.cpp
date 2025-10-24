#include"Ride.h"
#include"Trip.h"
#include"SharedTrip.h"
#include<stdexcept>
#include<string>
#include<iostream>
#include"IndividualTrip.h"

int main(){

    // Creting the object of both sharedTrip class and IndividualTrip class
    IndividualTrip it("101REG",29,3,0,58);
    SharedTrip st("101REG",29,3,0,3);

    // TC1 --> validate is trip as per standard --> individual Trip
    if(it.isTripAsPerStandard()) {std::cout<<"\nYes"<<std::endl;}
    else {std::cout<<"\nNo"<<std::endl;}
    
    // TC2 --> validate is trip as per standard --> shared Trip
    if(st.isTripAsPerStandard()) {std::cout<<"\nYes"<<std::endl;}
    else {std::cout<<"\nNo"<<std::endl;}

    // TC3 --> calculate fare --> individual trip
    std::cout<<"\nFare for individual trip: "<<it.calculateFare()<<std::endl;

    // TC4 --> calculate fare --> shared trip
    std::cout<<"\nFare for shared trip: "<<st.calculateFare()<<std::endl;
    
    return 0;
}