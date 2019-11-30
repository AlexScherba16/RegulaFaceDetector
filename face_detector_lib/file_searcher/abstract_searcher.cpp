//
// Created by alex on 19.11.2019.
//

#include <iostream>
#include <boost/filesystem.hpp>

#include "abstract_searcher.h"

using namespace std;
using namespace AbstractSearcherNamespace;
namespace filesys = boost::filesystem;

bool AbstractSearcher::isFile(const std::string& filePath){
    try{
        // Create a Path object from given path string
        filesys::path pathObj(filePath);
        // Check if path exists and is of a regular file
        if (filesys::exists(pathObj) && filesys::is_regular_file(pathObj))
            return true;
    }
    catch (filesys::filesystem_error & e){
        cerr << e.what() << endl;
    }
    return false;
}

bool AbstractSearcher::isDirectory(const std::string& dirPath){
    try {
        // Create a Path object from given path string
        filesys::path pathObj(dirPath);
        // Check if path exists and is of a directory file
        if (filesys::exists(pathObj) && filesys::is_directory(pathObj))
            return true;
    }
    catch (filesys::filesystem_error & e){
        cerr << e.what() << endl;
    }
    return false;
}

string AbstractSearcher::getFileExtension(const string& filePath){
    // Create a Path object from given string
    filesys::path pathObj(filePath);

    // Check if file name in the path object has extension
    if (pathObj.has_extension()) {
        // Fetch the extension from path object and return
        return pathObj.extension().string();
    }

    // In case of no extension return empty string
    return "";
}

string AbstractSearcher::getFileName(const std::string& filePath){
    // Create a Path object from given string
    filesys::path pathObj(filePath);

    // Return file name with extention
    return pathObj.filename().string();
}

vector<FileStruct> AbstractSearcher::getFilesByExtention(const string& dirPath,
                                                     const string& extention)
{
    // Validate income parameters
    if(dirPath.empty()) 		PRINT_ERROR("Empty directory path");
    if(extention.empty()) 		PRINT_ERROR("Empty file extention");
    if(!isDirectory(dirPath))	PRINT_ERROR("Invalid directory path");

    // Create a Path object from given string
    filesys::path apk_path(dirPath);

    // Create directory iterator
    filesys::recursive_directory_iterator end;

    // Image file descriptor strings
    string filePath;
    string fileName;
    string processedImageFilePath;
    string resultFilePath;

    // Files collection
    vector<FileStruct> files;

    for (filesys::recursive_directory_iterator i(apk_path); i != end; ++i)
    {
        filePath = filesys::path((*i)).string();

        // check file validation
        if(isFile(filePath) && getFileExtension(filePath) == extention)
        {

            filesys::path parent_path(filePath);
            fileName = getFileName(filePath);

            // skip already existing files
            if(fileName.find(PROCESSED_IMAGE_PREFIX) != string::npos)
                continue;

            processedImageFilePath = parent_path.parent_path().string() +
                                     boost::filesystem::path::preferred_separator;

            resultFilePath = processedImageFilePath;

            processedImageFilePath += PROCESSED_IMAGE_PREFIX + fileName;
            resultFilePath += RESULT_FILE_PREFIX + fileName;

            files.push_back(
                    FileStruct(filePath,
                               fileName,
                               processedImageFilePath,
                               resultFilePath));
        }
    }

    return files;
}

AbstractSearcher::~AbstractSearcher() {}
