#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "bitmap.hpp"
#include "parse_from_image.h"

#ifndef PARSEFROM
#define PARSEFROM

void parseFromImage(std::string filename){
    
    bitmap_image image(filename); 

    std::vector<unsigned char> data; 

    for(int i = 0; i < image.width(); ++i){
        for(int j = 0; j < image.height(); ++j){
            rgb_t rgb = image.get_pixel(j, i);
            data.push_back(rgb.red); 
            data.push_back(rgb.green); 
            data.push_back(rgb.blue); 
        }
    }

    std::string outfile = "";
    
    auto data_iter = data.begin(); 
    
    while(*data_iter != '#'){
        outfile += *data_iter;
        ++data_iter;
    }
    ++data_iter;

    char numbuf[10];
    for(int i = 0; i < 10; ++i){
    numbuf[i] = *data_iter; 
    ++data_iter; 
    }

    ++data_iter; 
    
    unsigned int data_size = atoi(numbuf); 

    std::ofstream file(outfile); 

    for(int i = 0; i < data_size; ++i){
        file << *data_iter;
        ++data_iter; 
    }

    std::cout << "Successfully converted " << filename << " to the data saved at " << outfile << "!" << std::endl; 

    file.close();
    image.save_image(filename); 

}

#endif