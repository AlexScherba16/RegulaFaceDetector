#include "library.h"

#include <iostream>
#include <memory>

#include "file_searcher/file_searcher.h"
#include "face_detector/net_face_detector.h"
#include "result_generator/json_result_generator.h"

static void send_to_console(const FileStruct& file,
                            const std::vector<FaceRectangle>& detected)
{
    std::cout << "processed image: " << file.processedImageFilePath << std::endl
              << "detected objects: " << detected.size() << std::endl
              << "result file: " << file.resultFilePath << std::endl << std::endl;
}

static void help()
{
    std::cout << "\n This program demonstrates function for face detection with generating result file.\n"
            "Usage:\n"
            "./facedetect [-path=<source image root path>]\n"
            "   [-model=<model_path> this is the primary trained model [/model_configuration/deploy.prototxt]]\n"
            "   [-weights[=net weights [model_weights/weights.caffemodel]]\n"
            "see facedetect.cmd for one call:\n"
            "./facedetect -path=\"/pictures \" -model=\"/model_configuration/deploy.prototxt\" -weights=model_weights/weights.caffemodel\n\n"
            "\tUsing OpenCV version " << CV_VERSION << "\n" << std::endl;
}

int run_detection(int argc, char const *argv[])
{
    if(argc < 2){
        std::cerr << "argc error" << std::endl;
        return -1;
    }
    cv::CommandLineParser parser(argc, argv,
                                 "{help h||}"
                                 "{path| |Root path to images}"
                                 "{model| |Path to trained model}"
                                 "{weights| |Path to net weights}");
    if (parser.has("help")) {
        help();
        return 0;
    }

    std::string rootPath = parser.get<std::string>("path");
    std::string modelConfig = parser.get<std::string>("model");
    std::string modelWeights = parser.get<std::string>("weights");

    if (!parser.check()){
        parser.printErrors();
        PRINT_ERROR("Invalid parameters");
    }


    std::unique_ptr<AbstractSearcherNamespace::AbstractSearcher> searcher(new FileSearcher());

    // generate files collection (in this case, collect *.jpg files)
    auto files = searcher->getFiles(rootPath);

    std::unique_ptr<FaceDetectorNamespace::FaceDetector> detector(new NetFaceDetector(modelConfig, modelWeights));
    std::unique_ptr<ResultGeneratorNamespace::ResultGenerator> generator(new JsonResultGenerator());

    int detected_images_counter = 0;

    for(auto it = files.begin(); it != files.end(); ++it){
        // set file description
        detector->setSourceImageFile((*it));

        // set detection results
        auto detected = detector->getFacesCoordinates();

        // update detected objects value
        detected_images_counter += detected.size();

        // save detected objects to result file
        generator->generateResult((*it), detected);

        // save processed image
        detector->saveProcessedImage();

        // send processed result
        send_to_console((*it), detected);
    }
    return detected_images_counter;
}