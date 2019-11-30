//
// Created by alex on 19.11.2019.
//

#include "file_searcher.h"
#include "jpg_file_searcher.h"
#include "png_file_searcher.h"
#include "jpeg_file_searcher.h"

using namespace std;

std::vector<FileStruct> FileSearcher::getFiles(const std::string& root_path)
{
    vector<FileStruct> result;
    auto jpg = JpgFileSearcher().getFiles(root_path);
    auto jpeg = JpegFileSearcher().getFiles(root_path);
    auto png = PngFileSearcher().getFiles(root_path);

    cout << "jpg: " << jpg.size() << endl
         << "jpeg: " << jpeg.size() << endl
         << "png: " << png.size() << endl;

    result.insert(result.end(), jpg.begin(), jpg.end());
    result.insert(result.end(), jpeg.begin(), jpeg.end());
    result.insert(result.end(), png.begin(), png.end());

    return result;
}
