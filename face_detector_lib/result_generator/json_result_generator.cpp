//
// Created by alex on 19.11.2019.
//

#include "json_result_generator.h"

#include <boost/filesystem.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using namespace std;
using namespace ResultGeneratorNamespace;

namespace filesys = boost::filesystem;
namespace pt = boost::property_tree;


void JsonResultGenerator::generateResult(const FileStruct& file,
                                         const vector<FaceRectangle>& coordinates)
{
    filesys::path pathObj(file.resultFilePath);

    if(!pathObj.has_extension())
        PRINT_ERROR("Result file path has no extention");

    string resultPath = filesys::change_extension(file.resultFilePath, ".json").string();

    pt::ptree root;
    root.put("source_file", file.srcFileName);
    root.put("detected_faces", coordinates.size());

    int index = 0;
    for (auto &item : coordinates)
    {
        pt::ptree coordinates_node;
        coordinates_node.put("top_left_x", item.top_left_x);
        coordinates_node.put("top_left_y", item.top_left_y);

        coordinates_node.put("top_right_x", item.top_right_x);
        coordinates_node.put("top_right_y", item.top_right_y);

        coordinates_node.put("bottom_right_x", item.bottom_right_x);
        coordinates_node.put("bottom_right_y", item.bottom_right_y);

        coordinates_node.put("bottom_left_x", item.bottom_left_x);
        coordinates_node.put("bottom_left_y", item.bottom_left_y);
        root.add_child("faces.coordinates_" + to_string(index), coordinates_node);

        ++index;
    };
    pt::write_json(resultPath, root);
}