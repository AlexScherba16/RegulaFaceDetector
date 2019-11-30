//
// Created by alex on 19.11.2019.
//

#ifndef FACE_DETECTOR_LIB_PNG_FILE_SEARCHER_H
#define FACE_DETECTOR_LIB_PNG_FILE_SEARCHER_H

#include "abstract_searcher.h"

class PngFileSearcher : public AbstractSearcherNamespace::AbstractSearcher{

public:
    PngFileSearcher() : AbstractSearcher() {}
    std::vector<FileStruct> getFiles(const std::string& root_path);
    ~PngFileSearcher() {};
};


#endif //FACE_DETECTOR_LIB_PNG_FILE_SEARCHER_H
