//
// Created by alex on 19.11.2019.
//

#include "jpeg_file_searcher.h"

using namespace std;
using namespace AbstractSearcherNamespace;

vector<FileStruct> JpegFileSearcher::getFiles(const string& root_path)
{
    // collect and return *.jpg files
    return AbstractSearcher::getFilesByExtention(root_path, ".jpeg");
}
