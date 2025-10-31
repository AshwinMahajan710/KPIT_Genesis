#include"Engine.h"
#include<iostream>

// constructor --> default (delegated)
Engine::Engine() : Engine(0){}

// constructor --> parameterized
Engine::Engine(int horsePower_){
    m_horsePower = horsePower_;
}

// getter
int Engine::getHP() const noexcept{
    return m_horsePower;
}