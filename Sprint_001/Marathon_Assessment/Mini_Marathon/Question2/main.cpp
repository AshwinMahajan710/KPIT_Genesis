#include"Global.h"
#include"Sensor.h"
#include<iostream>
#include<string>
#include<stdexcept>

int main(){

    // TC1 --> Creating arrays on the heap
    Sensor* arr[3];
    arr[0] = new Sensor(1,"Camera",ACTIVE,100.0,5);
    arr[1] = new Sensor(2,"Radar",INITIALIZING,150.0,5);
    arr[2] = new Sensor (3,"LiDAR",CALIBRATING,200.0,5);

    // TC2 --> recording sensor data for "Camera"
    arr[0]->recordData(85);
    arr[0]->recordData(90);
    arr[0]->recordData(88);

    // TC3 --> Printing camera sensor info
    std::cout<<"\nFollowing is the camera sensor info: ";
    arr[0]->displaySensorInfo();

    // TC4 --> Displaying the average Reading
    std::cout<<"\nAverage reading for camera sensor is: "<<arr[0]->getAverageReading()<<std::endl;

    // TC5 --> Compare the sensor ranges
    std::cout<<"\nSensor with higher detection range is: "<<compareSensorRanges(arr[0], arr[1])<<std::endl;

    // TC6 --> Checking the reliabilty of sensor at index 1
    if(isSensorReliable(*arr[1])) {std::cout<<"\nYes"<<std::endl;}
    else {std::cout<<"\nNo"<<std::endl;}

    // TC7 --> Displaying all sensor info
    displaySensorArray(arr,3);
    
    // TC8 --> deallocation
    for(int i=0;i<3;i++){
        delete arr[i];
        arr[i] = nullptr;
    }

    return 0;
}