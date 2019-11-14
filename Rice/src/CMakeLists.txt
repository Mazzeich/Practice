cmake_minimum_required(VERSION 3.13)
project(Rice)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(OpenCV_DIR /home/oem/OpenCV4/installation/OpenCV-master/lib/cmake/opencv4)

find_package(OpenCV REQUIRED)

add_executable(Rice main.cpp test.cpp computerVision.cpp computerVision.h)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/include)
include_directories(lib/googlemock/include)

target_link_libraries(Rice ${OpenCV_LIBS} gtest)