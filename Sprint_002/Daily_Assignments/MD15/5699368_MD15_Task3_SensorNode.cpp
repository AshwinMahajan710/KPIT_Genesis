#include<string>
#include"5699368_MD15_Task3_SensorNode.h"

// constructor --> parameterized
SensorNode::SensorNode(const std::string& id_, double value_): m_id(id_), m_value(value_){}

void SensorNode::updateVal(double newVal_){
    m_value = newVal_;
}

double SensorNode::getVal() const{
    return m_value;
}

std::string SensorNode::getId() const{
    return m_id;
}