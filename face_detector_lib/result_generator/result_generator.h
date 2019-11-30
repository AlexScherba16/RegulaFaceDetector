//
// Created by alex on 19.11.2019.
//

#ifndef FACE_DETECTOR_LIB_RESULT_GENERATOR_H
#define FACE_DETECTOR_LIB_RESULT_GENERATOR_H


#include "../common/common.h"
#include <vector>
#include <string>

namespace ResultGeneratorNamespace
{
    class ResultGenerator
    {
    public:
        ResultGenerator() {}
        virtual void generateResult(const FileStruct& file,
                                    const std::vector<FaceRectangle>& coordinates) = 0;
        virtual ~ResultGenerator() = 0;
    };
}

#endif //FACE_DETECTOR_LIB_RESULT_GENERATOR_H
