
#include"5699368_MD8_Task1_MatrixMultiplier.h"
#include<vector>
#include<thread>
#include<iostream>

int main(){

    // mat1
    std::vector<std::vector<int>> mat1 = { {1, 2, 3}, {4, 5, 6}};
    std::vector<std::vector<int>> mat2 = { {1, 2},{3,4},{ 5, 6}};

    // multiply
    MatrixMultiplier multiplier(mat1, mat2);
    multiplier.multiplyCol();

    multiplier.display_two_mats();
    multiplier.display_res();

    return 0;
}