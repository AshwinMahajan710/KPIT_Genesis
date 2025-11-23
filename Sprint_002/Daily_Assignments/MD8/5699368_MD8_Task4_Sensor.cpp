#include<string>
#include<chrono>
#include"5699368_MD8_Task4_Sensor.h"
#include<random>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<thread>

// constructor
Sensor::Sensor(const std::string& name_, int minVal_, int maxVal_, int iterations_ ){
    m_iterations = iterations_;
    m_maxVal = maxVal_;
    m_minVal = minVal_;
    m_name = name_;
}

// run function
void Sensor::run() const{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    srand(time(nullptr));
    int random_no = m_minVal + (std::rand() % (m_maxVal - m_minVal + 1));
    // Generate readings
    for (int i = 1; i <= m_iterations; ++i) {
        std::cout << m_name << " Reading " << i << ": " << random_no << std::endl;
        
        // Sleep for 500 milliseconds between readings
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    // Print completion message
    std::cout << m_name << " finished simulation." << std::endl;
}