cmake_minimum_required(VERSION 3.15)
project(lab03)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab03 timus_2095.cpp myClass.cpp myClass.h test.cpp)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/include)
include_directories(lib/googlemock/include)

target_link_libraries(lab03 gtest)