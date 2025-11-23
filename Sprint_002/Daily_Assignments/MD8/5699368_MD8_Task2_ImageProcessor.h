#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include<vector>
#include<string>
#include<mutex>

class ImageProcessor{
    private:
        std::vector<int> m_img;
    public:
        ImageProcessor(std::vector<int> image_);
        void display() const;
        void applyFilterToRegion(int start, int end, const std::string& filterName);
        void runInParallel() ;
};

#endif // IMAGEPROCESSOR_H