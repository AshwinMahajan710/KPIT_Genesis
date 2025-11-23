
#include"5699368_MD8_Task1_MatrixMultiplier.h"
#include<vector>
#include<thread>
#include<iostream>

// constructor
MatrixMultiplier::MatrixMultiplier(std::vector<std::vector<int>>& mat1_, std::vector<std::vector<int>>& mat2_){
    m_mat1 = mat1_;
    m_mat2 = mat2_;
    int rows = m_mat1.size();
    int cols = m_mat2[0].size();
    m_res.resize(rows, std::vector<int>(cols,0));
}

// displaying result matrix
void MatrixMultiplier::display_res() const{
    std::cout<<"\nResult mat: "<<std::endl;
    for(auto &i: m_res){
        for(auto &j: i){
            std::cout<<" "<<j;
        }
        std::cout<<"\n";
    }
}

// mdisplaying two other matrix
void MatrixMultiplier::display_two_mats() const{
    std::cout<<"\nMatrix1: "<<std::endl;
    for(auto &i: m_mat1){
        for(auto &j: i){
            std::cout<<" "<<j;
        }
        std::cout<<"\n";
    }
    std::cout<<"\nMatrix2: "<<std::endl;
    for(auto &i: m_mat2){
        for(auto &j: i){
            std::cout<<" "<<j;
        }
        std::cout<<"\n";
    }
}

// function to multiply rows
void MatrixMultiplier::multiplyRow(int row_){
    int n = m_mat2.size();               
    int cols = m_mat2[0].size();

    for(int col = 0; col < cols; col++){
        int sum = 0;
        for(int k = 0; k < n; k++){
            sum += m_mat1[row_][k] * m_mat2[k][col];
        }
        m_res[row_][col] = sum;
    }
}

// function to multiply cols
void MatrixMultiplier::multiplyCol(){
    std::vector<std::thread> threads;
    int rows = m_mat1.size();

    threads.reserve(rows);
    for(int i = 0; i < rows; i++){
        threads.emplace_back(&MatrixMultiplier::multiplyRow, this, i);
    }

    for(auto &t : threads){
        t.join();
    }
}