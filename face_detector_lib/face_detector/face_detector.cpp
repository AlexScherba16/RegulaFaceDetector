//
// Created by alex on 19.11.2019.
//

#include "face_detector.h"

using namespace FaceDetectorNamespace;
using namespace cv;

FaceRectangle FaceDetector::rectToFaceCoords(const Rect& rectangle)
{
    FaceRectangle coords;

    coords.top_left_x = rectangle.x;
    coords.top_left_y = rectangle.y;

    coords.top_right_x = rectangle.br().x;
    coords.top_right_y = rectangle.y;

    coords.bottom_right_x = rectangle.br().x;
    coords.bottom_right_y = rectangle.br().y;

    coords.bottom_left_x = rectangle.x;
    coords.bottom_left_y = rectangle.br().y;

    return coords;
}

FaceDetector::~FaceDetector() {}
