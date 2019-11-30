cmake_minimum_required(VERSION 2.8)
project(main)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if(CMAKE_SYSTEM_NAME MATCHES "Widnows")
    set(SEP "\\")
else()
    set(SEP "/")
endif()

set(RESULT_LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}${SEP}libs)

include_directories(face_detector_lib)

add_executable(facedetect main.cpp)
target_link_libraries(facedetect ${RESULT_LIB_PATH}${SEP}libface_detector_lib.so)
