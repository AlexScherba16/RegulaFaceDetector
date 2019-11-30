//
// Created by alex on 19.11.2019.
//

#ifndef FACE_DETECTOR_LIB_FILE_SEARCHER_H
#define FACE_DETECTOR_LIB_FILE_SEARCHER_H

#include "../common/common.h"
#include "abstract_searcher.h"


//REQUIRED_EXT = ('.png', '.jpg', '.jpeg')
class FileSearcher : public AbstractSearcherNamespace::AbstractSearcher{

public:
    FileSearcher() : AbstractSearcher() {}
    std::vector<FileStruct> getFiles(const std::string& root_path);
    ~FileSearcher(){}
};


#endif //FACE_DETECTOR_LIB_FILE_SEARCHER_H
