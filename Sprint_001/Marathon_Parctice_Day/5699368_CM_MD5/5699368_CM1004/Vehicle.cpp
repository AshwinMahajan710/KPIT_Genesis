#include<iostream>
#include<stdexcept>
#include<string>
#include<cstring>
#include"Vehicle.h"
#include"VehicleType.h"

constexpr int DEFAULT_TEST_RUNS = 2;
constexpr int VEHICLE_ID_SIZE = 11;

// constructor
Vehicle::Vehicle(){
    this->m_numberOfTestRuns = DEFAULT_TEST_RUNS;
    this->m_testScores = new int [m_numberOfTestRuns];
    for(int i=0;i<m_numberOfTestRuns;i++){
        m_testScores[i] = 0;
    }
    this->m_type = VehicleType::COMMERCIAL;
    this->m_vehicleID = new char[VEHICLE_ID_SIZE];
}

// Parametrized constructor 
Vehicle::Vehicle(unsigned int n_){
    if(n_>=0 && n_<=5) {this->m_numberOfTestRuns = n_;}
    else{throw std::out_of_range("Test runs out of bounds");}

    this->m_testScores = new int [m_numberOfTestRuns];
    for(int i=0;i<m_numberOfTestRuns;i++){
        m_testScores[i] = 0;
    }

    this->m_type = VehicleType::COMMERCIAL;
    this->m_vehicleID = new char[VEHICLE_ID_SIZE];
}

// Copy constructor
Vehicle::Vehicle(const Vehicle& other_){
        this->m_numberOfTestRuns = other_.m_numberOfTestRuns;
        this->m_testScores = new int[m_numberOfTestRuns];
        for(int i=0;i<m_numberOfTestRuns;i++){
            this->m_testScores[i] = other_.m_testScores[i];
        }
        this->m_type = other_.m_type;
        this->m_vehicleID = new char[VEHICLE_ID_SIZE];
        strcpy(m_vehicleID, other_.m_vehicleID);
}

// destructor
Vehicle::~Vehicle(){
    delete[] m_testScores;
    delete[] m_vehicleID;
}

// Overloading == Operator --> will return true if both have same avg scores
bool Vehicle::operator==(const Vehicle& other_) const{
    float thisTotalScore = 0.0;
    float otherTotalScore = 0.0;
    for(int i=0;i<this->m_numberOfTestRuns;i++){
        thisTotalScore += this->m_testScores[i]; 
    }
    for(int i=0;i<other_.m_numberOfTestRuns;i++){
        otherTotalScore += other_.m_testScores[i]; 
    }
    return ((thisTotalScore / this->m_numberOfTestRuns ) == (otherTotalScore / other_.m_numberOfTestRuns ));
}

// Overloading = Operator --> returning this object after assigning all values
Vehicle& Vehicle:: operator=(const Vehicle& other_){
    if(this != &other_){
        delete[] this->m_testScores;
        delete[] this->m_vehicleID;
        this->m_numberOfTestRuns = other_.m_numberOfTestRuns;
        this->m_testScores = new int[m_numberOfTestRuns];
        for(int i=0;i<m_numberOfTestRuns;i++){
            this->m_testScores[i] = other_.m_testScores[i];
        }
        this->m_type = other_.m_type;
        this->m_vehicleID = new char [VEHICLE_ID_SIZE];
        strcpy(this->m_vehicleID,other_.m_vehicleID);
    }
    return *(this);
}

// Overloading [] Operator --> returning testScore at given index --> return exception in case of invalid values
int Vehicle::operator[](int index_) const{
    if(index_ < 0 || index_ >= m_numberOfTestRuns){
        throw std::invalid_argument("Index given out of bounds");
    }
    else{
        return m_testScores[index_];
    }
}

// Overloading << operator --> printing information
std::ostream& operator<<(std::ostream& out, const Vehicle& other_){
    out<<"\nTotal Test Runs: "<<other_.m_numberOfTestRuns<<std::endl;
    out<<"Test Scores: ";
    for(int i=0;i<other_.m_numberOfTestRuns;i++){
        out<<other_.m_testScores[i]<<" ";
    }
    out<<"\nType: "<<other_.getVehicleTypeString()<<std::endl;
    out<<"Vehicle ID: "<<other_.m_vehicleID<<std::endl;
    return out;
}

// Overloading >> operator --> taking input from user
std::istream& operator>>(std::istream& in, Vehicle& other_){

    // Validating values and the assigning one by one
    delete[] other_.m_testScores; // first delete previous things
    delete[] other_.m_vehicleID;

    // validation for numOfTestRuns
    int tempTestRuns = 0;
    std::cout<<"Enter number of test runs(should be less than 5 but no -ve): ";
    in>>tempTestRuns;
    if(tempTestRuns < 0 || tempTestRuns > 5) {throw std::invalid_argument("Exception: \"Value given out our range\"");}
    else {other_.m_numberOfTestRuns = tempTestRuns;}
    
    // validation for individual scores
    other_.m_testScores = new int[other_.m_numberOfTestRuns];
    int score = 0;
    std::cout<<"Enter each test score one by one: ";
    for(int i=0;i<other_.m_numberOfTestRuns;i++){
        std::cout<<i+1<<" ?: ";
        in>>score;
        if(score<0) {throw std::invalid_argument("Exception: \"Value given is negative.. score can never be -ve\"");}
        else{other_.m_testScores[i] = score;}
    }

    // Validation for vehicleType
    int typeVal = 0;
    std::cout<<"Enter Vehicle type (Passenger : 1, Commercial: 0): ";
    in>>typeVal;
    if(typeVal != 0 && typeVal != 1) {throw std::invalid_argument("Exception: \"Invalid Value for Vehicle Type\"");}
    else {other_.m_type = static_cast<VehicleType>(typeVal);}

    // directly assign id after clearing buffer
    char* str;
    other_.m_vehicleID = new char[VEHICLE_ID_SIZE];
    std::cout<<"Enter vehicle ID: ";
    in>>other_.m_vehicleID;
    // other_.m_vehicleID = str;
    return in;
}

// getter for no of test runs
unsigned int Vehicle::getNumberOfTestRuns() const{
    return m_numberOfTestRuns;
}

// getter for test score
const int* Vehicle::getTestScores() const {
    return m_testScores;
}

// getter for vehicle type
VehicleType Vehicle::getVehicleType() const{
    return m_type;
}

// HELPER FUNCTION:- help to get string val of enum type
std::string Vehicle::getVehicleTypeString() const{
    switch (m_type)
    {
        case VehicleType::COMMERCIAL:{
            return "Commercial";
            break;
        }
        case VehicleType::PASSENGER:{
            return "Passesnger";
            break;
        }
        default:{
            return "Other";
        }
    }
}