//
// Created by alex on 19.11.2019.
//

#ifndef FACE_DETECTOR_LIB_ABSTRACT_SEARCHER_H
#define FACE_DETECTOR_LIB_ABSTRACT_SEARCHER_H


#include "../common/common.h"
#include <vector>

namespace AbstractSearcherNamespace{

    class AbstractSearcher{

    private:
        bool isFile(const std::string& filePath);
        bool isDirectory(const std::string& dirPath);
        std::string getFileExtension(const std::string& filePath);
        std::string getFileName(const std::string& filePath);

    protected:
        std::vector<FileStruct> getFilesByExtention(const std::string& dirPath,
                                                    const std::string& extention);

    public:
        AbstractSearcher() {}
        virtual std::vector<FileStruct> getFiles(const std::string& root_path) = 0;
        virtual ~AbstractSearcher() = 0;
    };
}

#endif //FACE_DETECTOR_LIB_ABSTRACT_SEARCHER_H
