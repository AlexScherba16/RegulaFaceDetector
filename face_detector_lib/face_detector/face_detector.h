//
// Created by alex on 19.11.2019.
//

#ifndef FACE_DETECTOR_LIB_FACE_DETECTOR_H
#define FACE_DETECTOR_LIB_FACE_DETECTOR_H


#include "../common/common.h"
#include <opencv2/core.hpp>

namespace FaceDetectorNamespace
{
    class FaceDetector
    {
    protected:
        FileStruct _source_image_file;
        FaceRectangle rectToFaceCoords(const cv::Rect& rectangle);

    public:
        FaceDetector() = delete;
        FaceDetector(const std::string& modelConfig,
                     const std::string& modelBinary){}
        virtual void setSourceImageFile(const FileStruct& src){_source_image_file = src;}
        virtual std::vector<FaceRectangle> getFacesCoordinates() = 0;
        virtual void saveProcessedImage() = 0;
        virtual ~FaceDetector() = 0;
    };
}


#endif //FACE_DETECTOR_LIB_FACE_DETECTOR_H
