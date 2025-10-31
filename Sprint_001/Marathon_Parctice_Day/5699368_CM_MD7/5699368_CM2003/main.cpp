#include"Battery.h"
#include<string>
#include<iostream>
#include<stdexcept>
#include"Global.h"

int constexpr ARRAY_SIZE = 3;

int main(){

    // TC1 --> creating array of 3 batteries
    Battery* batteries = new Battery[ARRAY_SIZE] {Battery(1,"Type1","Manufacturer 1",1000.0,12.0),Battery(2,"Type2","Manufacturer 2",2000.0,24.0),Battery(3,"Type3","Manufacturer 1",3000.0,36.0)};

    // TC2 --> Displaying all the available batteries in the system
    std::cout<<"\nFollowing are the all batteries in the system: "<<std::endl;
    showAllBatteries(batteries,ARRAY_SIZE);

    // TC3 --> Searching batteries manufactured by manufacturer 1
    std::cout<<"\nFollowing are the details of batteries manufactured by manufacturer 1: "<<std::endl;
    searchBattriesByManufacturer(batteries,ARRAY_SIZE,"Manufacturer 1");

    // TC4 --> Searching batteries manufactured by manufacturer 9 --> will throw exception as no batteries were manufactured by manufacturer 9
    try
    {
        std::cout<<"\nFollowing are the details of batteries manufactured by manufacturer 9: "<<std::endl;
        searchBattriesByManufacturer(batteries,ARRAY_SIZE,"Manufacturer 9");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}