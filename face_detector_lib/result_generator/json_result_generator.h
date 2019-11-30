//
// Created by alex on 19.11.2019.
//

#ifndef FACE_DETECTOR_LIB_JSON_RESULT_GENERATOR_H
#define FACE_DETECTOR_LIB_JSON_RESULT_GENERATOR_H

#include "result_generator.h"

class JsonResultGenerator : public ResultGeneratorNamespace::ResultGenerator
{
public:
    JsonResultGenerator() : ResultGenerator() {};
    void generateResult(const FileStruct& file,
                        const std::vector<FaceRectangle>& coordinates);
    ~JsonResultGenerator() {};
};

#endif //FACE_DETECTOR_LIB_JSON_RESULT_GENERATOR_H
