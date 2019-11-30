#include <iostream>

#include "face_detector_lib/library.h"

int main(int argc, char const *argv[]) {
    if(argc < 2){
        std::cerr << "argc error" << std::endl;
        return -1;
    }
    return run_detection(argc, argv);
}