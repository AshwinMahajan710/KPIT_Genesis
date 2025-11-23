cmake_minimum_required(VERSION 3.16)

# // name of the project --> version --> description
project(ProjectTitle VERSION 0.0.1
    DESCRIPTION "My First Sensor"
    LANGUAGES CXX    
)

add_executable(myProj main.cpp Sensor.cpp functionalities.cpp) # while compilation it should consider this 2 files