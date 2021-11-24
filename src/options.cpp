#include "options.h"
#include <getopt.h>
#include <iostream>

using namespace std;

#ifndef H_OPTIONS
#define H_OPTIONS


Options::Options(int argc, char ** argv){
    int c;
    
    while((c = getopt(argc, argv, "f:o:idh")) != -1){
        switch (c)
        {
        case 'f':
            filename = std::string(optarg);
            hasfilename = true;
            break;
        case 'i':
            fromImage = true;
            break;
        case 'o':
            outfile = std::string(optarg); 
            hasOutFile = true; 
            break; 
        case 'd':
            toImage = true;
            break;
        case 'h':
            printhelp();
            exit(0); 
            break;

        default:
            break;
        }
    }

    checkoptions(); 
    
}

bool Options::checkoptions(){
    bool err = false; 
    if(!hasfilename){
        cerr << "Missing ARGUMENT filename" << endl;
        err = true; 
    }

    if(! toImage ^ fromImage){
        cerr << "Must specify exactly one of -i and -d" << endl;
        err = true; 
    }

    if(err){
        cout << endl;
        cout << "Exiting 1 with error" << endl;
        exit(1); 
    }
    return true; 
}

void Options::printhelp(){
    cout << "Data Image Parser Help\n" << endl;
    cout << "-f [FILENAME] | Specify the input file for the program" << endl;
    cout << "-o [FILENAME] | Specify the output filename for parsing data to an image" << endl;
    cout << "-d | Specify that you are inputting data that you would like to produce an image from" << endl;
    cout << "-i | Specify that you are inputting an image that you would like to get the original data from" << endl;
    cout << endl; 
}

#endif