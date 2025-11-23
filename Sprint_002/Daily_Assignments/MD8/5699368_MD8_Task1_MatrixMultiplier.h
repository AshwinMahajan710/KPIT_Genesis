#ifndef INC_5699368_MD8_TASK1_MATRIXMULTIPLIER_H
#define INC_5699368_MD8_TASK1_MATRIXMULTIPLIER_H

#include<vector>
#include<thread>

// MatrixMultiplier class
class MatrixMultiplier{
    private:
        std::vector<std::vector<int>> m_mat1;        
        std::vector<std::vector<int>> m_mat2;
        std::vector<std::vector<int>> m_res;

    public:
        MatrixMultiplier() = default;
        MatrixMultiplier(std::vector<std::vector<int>>& mat1_, std::vector<std::vector<int>>& mat2_);
        void display_res() const;
        void display_two_mats() const;
        void multiplyRow(int row_);
        void multiplyCol();
};

#endif // INC_5699368_MD8_TASK1_MATRIXMULTIPLIER_H
