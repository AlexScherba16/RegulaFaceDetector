//
// Created by alex on 19.11.2019.
//

#ifndef FACE_DETECTOR_LIB_JPEG_FILE_SEARCHER_H
#define FACE_DETECTOR_LIB_JPEG_FILE_SEARCHER_H


#include "abstract_searcher.h"

class JpegFileSearcher : public AbstractSearcherNamespace::AbstractSearcher{

public:
    JpegFileSearcher() : AbstractSearcher() {}
    std::vector<FileStruct> getFiles(const std::string& root_path);
    ~JpegFileSearcher() {};
};


#endif //FACE_DETECTOR_LIB_JPEG_FILE_SEARCHER_H
