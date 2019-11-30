// tests.cpp
#include "../library.h"

#include <iostream>
#include <gtest/gtest.h>

std::string APP_NAME;
std::string PATH;
std::string MODEL;
std::string WEIGHTS;

TEST(FaceDetectorLibTest, NoParamsLaunch){
	int result = run_detection(1, NULL);
	EXPECT_EQ(result, -1);
}

TEST(FaceDetectorLibTest, FailPath){
    const char* argv[] = {APP_NAME.c_str(),
                          ""};
	ASSERT_THROW(run_detection(2, argv), std::runtime_error);
}

TEST(FaceDetectorLibTest, NoModel){
    const char* argv[] = {APP_NAME.c_str(),
                          PATH.c_str(),
                          ""};
	ASSERT_THROW(run_detection(3, argv), std::runtime_error);
}

TEST(FaceDetectorLibTest, NoModelWeights){
    const char* argv[] = {APP_NAME.c_str(),
                          PATH.c_str(),
                          MODEL.c_str(),
                          ""};
	ASSERT_THROW(run_detection(4, argv), std::runtime_error);
}

TEST(FaceDetectorLibTest, Positiveresult){
    const char* argv[] = {APP_NAME.c_str(),
                          PATH.c_str(),
                          MODEL.c_str(),
                          WEIGHTS.c_str()};
    int result = 0;
    try {
        result = run_detection(4, argv);
    }
    catch (std::runtime_error& ex){
        std::cout << "Catch exception inside Positiveresult test:\n" << ex.what() <<std::endl;
        return;
    }
    ASSERT_GE(result, 0);
}

int main(int argc, char **argv) {
    if (argc < 4){
        std::cout << "Invalid argc parameters: enter [-path, -model, -weights]\n";
        return -1;
    }
    APP_NAME = argv[0];
    PATH = argv[1];
    MODEL = argv[2];
    WEIGHTS = argv[3];

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}