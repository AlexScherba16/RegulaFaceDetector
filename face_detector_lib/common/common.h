//
// Created by alex on 19.11.2019.
//

#ifndef FACE_DETECTOR_LIB_COMMON_H
#define FACE_DETECTOR_LIB_COMMON_H

#include <string>
#include <iostream>

// processed image file prefix
#define PROCESSED_IMAGE_PREFIX 	"processed_"

// detection result file prefix
#define RESULT_FILE_PREFIX 	"result_"

struct FileStruct{
    std::string srcFilePath;
    std::string srcFileName;
    std::string processedImageFilePath;
    std::string resultFilePath;

    FileStruct(){}
    FileStruct(const std::string& srcFilePath,
               const std::string& srcFileName,
               const std::string& processedImageFilePath,
               const std::string& resultFilePath) :
            srcFilePath(srcFilePath),
            srcFileName(srcFileName),
            processedImageFilePath(processedImageFilePath),
            resultFilePath(resultFilePath){}
};

struct FaceRectangle{
    int top_left_x;
    int top_left_y;

    int top_right_x;
    int top_right_y;

    int bottom_right_x;
    int bottom_right_y;

    int bottom_left_x;
    int bottom_left_y;
};


static void PRINT_ERROR(const std::string& error){
    throw std::runtime_error(error);
}

#endif //FACE_DETECTOR_LIB_COMMON_H
