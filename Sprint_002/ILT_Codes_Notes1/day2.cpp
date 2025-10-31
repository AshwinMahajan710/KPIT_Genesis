#include<iostream>

// int main(){

//     // lvalue is any modifiable variable or value and rvalue is non modifiable value --> below are the examples
//     int a = 2; // --> lvalue : a, rvalue : 2
//     int y = a; // --> lvalue : y, lvalue = a;
//     int* ptr = &a; // --> lvalue : ptr, lvalue = a;

//     // another def --> value which do not have dedicated memory locatiion is rvalue
//     // int a = func() // lvalue : a, rvalue = func();
//     int z = y + 1; // lval --> z, lval --> y, rval --> y+1
//     return 0;
// }

#include <iostream>
#include <string>

// int main() {
//     std::string s1 = "First";
//     std::string s2 = "Last";

//     std::string c1 = s1 + s2;     // normal concatenation
//     std::cout << c1 << std::endl; // FirstLast

//     std::string c2 = c1;          // lvalue reference (copy)
//     c2 = "KPIT";

//     std::cout << c1 << std::endl; // FirstLast
//     std::cout << c2 << std::endl; // KPIT

//     // std::string& c3 = s1 + s2; // ❌ invalid: s1+s2 is rvalue (temporary)

//     std::string&& c4 = s1 + s2;   // ✅ rvalue reference
//     std::cout << c4 << std::endl; // FirstLast

//     return 0;
// }



// understand - find concerns and explanation about output
 
void updateRecords(std::string&& record){
    record += " - Updated Record";
}
void transferOwnership(std::string&& owner){
    std::string newRecord = std::move(owner);
    std::cout << newRecord << std::endl;
}

int main() {
    std::string vehicleRecord = "Car ID 1234";
    std::cout << vehicleRecord << std::endl;
    updateRecords(std::move(vehicleRecord));
    std::cout << vehicleRecord << std::endl;
    transferOwnership(std::move(vehicleRecord));
    std::cout << vehicleRecord << std::endl;
    return 0;
}

// int main (){
//     int a = 12;
//     int && b = std::move(a);

//     std::cout<<a<<" "<<b<<std::endl;
    
//     // Changing actual a
//     a = 13;
//     std::cout<<a<<" "<<b<<std::endl;

//     // Changing b
//     b = 19;
//     std::cout<<a<<" "<<b<<std::endl;

//     // in both cases both values are going to be chnage the same
//     // o/p --> 12 12
//     //         13 13
//     //         19 19

//     // try to store int the lvalue using move but new obj
//     int c = b;
//     std::cout<<b<<" "<<c<<std::endl; 
//     return 0;
// }