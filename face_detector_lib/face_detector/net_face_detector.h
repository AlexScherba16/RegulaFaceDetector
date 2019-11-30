//
// Created by alex on 19.11.2019.
//

#ifndef FACE_DETECTOR_LIB_NET_FACE_DETECTOR_H
#define FACE_DETECTOR_LIB_NET_FACE_DETECTOR_H

#include "face_detector.h"
#include <opencv2/dnn.hpp>

class NetFaceDetector : public FaceDetectorNamespace::FaceDetector
{
    private:
        cv::Mat _processed_image;
        cv::dnn::Net _net;

    public:
        NetFaceDetector(const std::string& modelConfig,
                        const std::string& modelBinary);
        std::vector<FaceRectangle> getFacesCoordinates();
        void saveProcessedImage();
        ~NetFaceDetector() {};
};


#endif //FACE_DETECTOR_LIB_NET_FACE_DETECTOR_H
