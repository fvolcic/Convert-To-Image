
#include <string>
#include <fstream>
#include <cmath>
#include <stdio.h> 
#include <iostream>
#include "specialvector.h"
#include "bitmap.hpp"
#include "parse_to_image.h"

void parseToImage(std::string filename, std::string outfile){

    VectorWrapper<unsigned char> image_data; 

    // print the original filename into the file
    for(unsigned char character : filename)
        image_data.push_back(character);
    image_data.push_back('#');

    // print the needed bytes to store the number of pixels into the file
    for(int i = 0; i < 10; ++i)
        image_data.push_back('0');
    image_data.push_back('#'); 

    // read the entire file into the vector
    // this is to be saved into the new file
    std::fstream file(filename); 
    unsigned int file_size = 0; 

    for(std::string line; std::getline(file, line);){
        for(char character : line){
            image_data.push_back(character);
            ++file_size; 
        }
        image_data.push_back('\n');
        ++file_size; 
    }

    // the actual saving of the image
    unsigned int image_size = ceil(sqrt(image_data.size() / 3 )); 
    bitmap_image image(image_size, image_size); 

    // the final step is to save the size of the data in the image. 
    char buffer[10]; 
    snprintf(buffer, 10, "%d", file_size); 
    unsigned int offset = 10 - ceil(log10(file_size)); 
    int start_index = filename.size() + 1 + offset; 

    for(int i = start_index; i < start_index + 10 - offset; ++i){
        image_data[i] = buffer[i - start_index]; 
    }

    for(int i = 0; i < image_size; ++i){
        for(int j = 0; j < image_size; ++j){
            auto rgb = image_data.get_triplet(i * image_size + j, 0); 
            image.set_pixel(j, i, rgb_t{rgb.e0, rgb.e1, rgb.e2});
        }
    }

    std::cout << "Successfully Converted " << filename << " to an Image!" << std::endl;
    std::cout << "Image saved as " << outfile << std::endl; 
    image.save_image(outfile); 

}