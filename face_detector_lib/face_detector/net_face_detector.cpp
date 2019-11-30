//
// Created by alex on 19.11.2019.
//

#include "net_face_detector.h"

#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;
using namespace cv::dnn;
using namespace FaceDetectorNamespace;

const size_t inWidth = 300;
const size_t inHeight = 300;
const double inScaleFactor = 1.0;
const Scalar meanVal(104.0, 177.0, 123.0);
const float confidenceThreshold = 0.311;


NetFaceDetector::NetFaceDetector(const std::string& modelConfig,
                                 const std::string& modelBinary) : FaceDetector(modelConfig, modelBinary){
    try {
        _net = readNetFromCaffe(modelConfig, modelBinary);
    }

    // catch open invalid files exceptions
    catch( cv::Exception& e ){
        PRINT_ERROR(e.what());
    }
    if(_net.empty()) 	PRINT_ERROR("No network layers");
}

vector<FaceRectangle> NetFaceDetector::getFacesCoordinates()
{
    Mat sourceImage = imread(samples::findFile(_source_image_file.srcFilePath),
                             IMREAD_COLOR);

    // clone and scale scr image
    _processed_image = sourceImage.clone();
    resize(sourceImage, _processed_image, Size(), 0.5, 0.5);

    // create 4-dimensional blob from image
    Mat inputBlob = blobFromImage(_processed_image, inScaleFactor,
                                  Size(inWidth, inHeight), meanVal, false, false);

    Mat detection;
    try {
        // set input blob to data
        _net.setInput(inputBlob, "data");

        // get data from "detection_out" layer
        detection = _net.forward("detection_out");
    }
    catch( cv::Exception& e ){
        PRINT_ERROR(e.what());
    }

    /*
        set detection uints
        confidence = detection.size[2],
        coordinates = detection.size[3]
    */
    Mat detectionMat(detection.size[2], detection.size[3], CV_32F, detection.ptr<float>());

    //create FaceRectangle container
    auto faceContainer = vector<FaceRectangle>();

    // run over detection rows
    for(int i = 0; i < detectionMat.rows; i++)
    {
        float confidence = detectionMat.at<float>(i, 2);
        if(confidence > confidenceThreshold)
        {
            int xLeftBottom = static_cast<int>(detectionMat.at<float>(i, 3) * _processed_image.cols);
            int yLeftBottom = static_cast<int>(detectionMat.at<float>(i, 4) * _processed_image.rows);
            int xRightTop   = static_cast<int>(detectionMat.at<float>(i, 5) * _processed_image.cols);
            int yRightTop   = static_cast<int>(detectionMat.at<float>(i, 6) * _processed_image.rows);

            Rect object((int)xLeftBottom, (int)yLeftBottom,
                        (int)(xRightTop - xLeftBottom),
                        (int)(yRightTop - yLeftBottom));

            // Blur image
            Mat blurORI = Mat(_processed_image, object);
            GaussianBlur(blurORI, blurORI, Size(53, 233), 0, 0);

            faceContainer.push_back(rectToFaceCoords(object));
        }
    }
    return faceContainer;
}

void NetFaceDetector::saveProcessedImage()
{
    if(!imwrite(_source_image_file.processedImageFilePath, _processed_image))
        PRINT_ERROR("Can't save processed image");
}
