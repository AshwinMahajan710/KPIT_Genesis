#include<vector>
#include<string>
#include<mutex>
#include"5699368_MD8_Task2_ImageProcessor.h"
#include<iostream>
#include<thread>

// constructor
ImageProcessor::ImageProcessor(std::vector<int> image_){
    m_img = image_;
}

// displaying the values
void ImageProcessor::display() const{
    for(auto i=0; i< 10; i++){
        std::cout<<" "<<m_img[i]<<std::endl;
    }
}

void ImageProcessor::applyFilterToRegion(int start, int end, const std::string& filterName){
    // lets say operation is to add 5 in each pixel
    for(int i=start; i<end;i++){
        m_img[i] += 5;
    }
}

// function to excute threads
void ImageProcessor::runInParallel() {
    int numFilter = 4;
    std::vector<std::thread> threads;
    threads.emplace_back(&ImageProcessor::applyFilterToRegion, this, 0, 250, "GrayScale");
    threads.emplace_back(&ImageProcessor::applyFilterToRegion, this, 250, 500, "GrayScale");
    threads.emplace_back(&ImageProcessor::applyFilterToRegion, this, 500, 750, "GrayScale");
    threads.emplace_back(&ImageProcessor::applyFilterToRegion, this, 750, 1000, "GrayScale");

    for(auto &thread: threads){
        if(thread.joinable()){
            thread.join();
        }
    }
}