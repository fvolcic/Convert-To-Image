#include "specialvector.h"
#include "options.h"
#include "parse_to_image.h"
#include "parse_from_image.h"
#include <iostream> 

using namespace std; 

int main(int argc, char ** argv){
    Options options(argc, argv);

    if(options.toImage){
        std::string outfile = options.hasOutFile ? options.outfile : "out.bmp";
        parseToImage(options.filename, outfile);
    }

    if(options.fromImage){
        parseFromImage(options.filename);
    }

}
