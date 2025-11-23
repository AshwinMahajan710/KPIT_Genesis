// #include<iostream>
// #include<variant> 
// #include<string>

// struct visitor
// {
//     void operator()(int var){std::cout<<"accessing integer vale: "<<var<<std::endl;}
//     void operator()(double var){std::cout<<"accessing double vale: "<<var<<std::endl;}
//     void operator()(const std::string& var){std::cout<<"accessing string vale: "<<var<<std::endl;}
// };

// std::variant<int, std::string> myFunction(int arg) {
//     if (arg < 0) {
//         return 10;                      // int
//     } else {
//         return std::string("Argument"); // string
//     }
// }

// int main(){

//     std::variant<int, char , double> myVariant;

//     myVariant = 10;
//     std::cout<<std::get<int>(myVariant) <<std::endl;
    
//     myVariant = 'A';
//     std::cout<<std::get<char>(myVariant) <<std::endl;

//     myVariant = 3.14;
    
//     std::cout<<std::get<double>(myVariant) <<std::endl;
    
//     // when try to invoke invalid datatype invokes exception of bad_variant access
//     try
//     {
//         std::cout<<std::get<char>(myVariant) <<std::endl;
//     }
//     catch(const std::bad_variant_access& e)
//     {
//         std::cerr << "Invalid type accessing"<<std::endl;
//     }

//     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
//     std::visit(visitor{}, myVariant);
    
//     myVariant = 'k';
//     std::visit(visitor{}, myVariant);

//     // - - - -- - - - - - - - - - - - - - - -- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - - - - -- - - - - - - -  - - - - -
//     // using lambda function for the same
//     std::visit([](auto &&var ) {std::cout<<"accessing value: "<< var<<std::endl;}, myVariant);
    
    
//     /// 
//     auto var = myFunction(10);
//     // std::cout << std::get<int>(var) << std::endl;  // willl throw exception if type not matched so use lambad
//     std::visit([](auto &&var ) {std::cout<<"accessing value: "<< var<<std::endl;}, var);

//     return 0; 
// }

#include<iostream>
#include<variant>

class Car{
    public:
        void display(){std::cout<<"It is Car"<<std::endl;}
};
class Bike{
    public:
        void display(){std::cout<<"It is bike"<<std::endl;}
};
class Truck{
    public:
        void display(){std::cout<<"It is truck"<<std::endl;}
};

void operation(std::variant<Car, Truck, Bike>& vehicle){
    std::visit([](auto &&var) {var.display();}, vehicle);
}

int main(){

    std::variant<Car, Truck, Bike> car = Car{}; 
    std::variant<Car, Truck, Bike> bike = Bike{}; 
    std::variant<Car, Truck, Bike> truck = Truck{}; 

    operation(car);
    operation(bike);
    operation(truck);
    
    return 0;
}