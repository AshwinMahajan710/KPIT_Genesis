#include<iostream>
#include<string>

// class vehicle
class Vehicle{
    private:
        std::string m_make;
        std::string m_model;
        int m_yearOfManufacturing;
        double m_exShowroomPrice;

    public:

        // Default Value
        Vehicle(){
            this->m_make = "Unknown";
            this->m_model = "Unknown";
            m_yearOfManufacturing = 0;
            this->m_exShowroomPrice = 0;
        }        

        // parameterized constructor
        Vehicle(std::string make_, std::string model_, int yearsOfManufacturing_, double exShowroomPrice_){
            this->m_make = make_;
            this->m_model = model_;
            m_yearOfManufacturing = yearsOfManufacturing_;
            this->m_exShowroomPrice = exShowroomPrice_;
        }

        // Getters for all 4 data values
        std::string getMake() const{
            return this->m_make;
        }
        std::string getModel() const{
            return this->m_model;
        }
        int getyearsOfManufacturing() const{
            return this->m_yearOfManufacturing;
        }
        double getexShowroomPrice() const{
            return this->m_exShowroomPrice;
        }

        // Setters for all 4 data values;
        void setMake(const std::string make_){
            this->m_make = make_;
        }
        void setModel(const std::string model_){
            this->m_model = model_;
        }
        void setYearOfManufacturing(const int yearsOfManufacture_){
            this->m_yearOfManufacturing = yearsOfManufacture_;
        }
        void setexShowroomPrice(const int exShowroomPrice_){
            this->m_exShowroomPrice = exShowroomPrice_;
        }

        // display function
        void display(){
            std::cout<<"Make: "<<this->m_make<<std::endl;
            std::cout<<"Model: "<<this->m_model<<std::endl;
            std::cout<<"Year of Manufacturing: "<<this->m_yearOfManufacturing<<std::endl;
            std::cout<<"Ex Showroom Price: "<<this->m_exShowroomPrice<<std::endl;
        }
};

// main function
int main(){

    // Creating first object --> parameterized constructor
    Vehicle vehicle1 ("Tata","Nexon",2024,12.6);

    // creating second object --> default constructor
    Vehicle vehicle2;

    // creating third object --> parameterized constructor
    Vehicle vehicle3("Mahindra","Thar",2025, 25.2);

    // displaying both objects
    std::cout<<"\nVehicle 1 details: "<<std::endl;
    vehicle1.display();
    std::cout<<"\nVehicle 2 details: "<<std::endl;
    vehicle2.display();

    // Now creating array of 3 objects
    Vehicle vehicles [3];
    vehicles[0] = vehicle1;
    vehicles[1] = vehicle2;
    vehicles[2] = vehicle3;

    // Displaying values by traversing array
    for(int i=0;i<3;i++){
        std::cout<<"\nVehicle "<<i+1<<" details: "<<std::endl;
        vehicles[i].display();
    }

    // try to use one getter and setter
    vehicle2.setMake("Toyota");
    std::cout<<"\nVehicle 2 new make value: "<<vehicle2.getMake()<<std::endl;
    

    return 0;
}
