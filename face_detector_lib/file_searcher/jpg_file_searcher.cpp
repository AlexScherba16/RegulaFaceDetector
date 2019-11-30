//
// Created by alex on 19.11.2019.
//

#include "jpg_file_searcher.h"

using namespace std;
using namespace AbstractSearcherNamespace;

vector<FileStruct> JpgFileSearcher::getFiles(const string& root_path)
{
    // collect and return *.jpg files
    return AbstractSearcher::getFilesByExtention(root_path, ".jpg");
}
