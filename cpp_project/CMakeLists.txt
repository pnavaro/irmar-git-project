project(cpp_project CXX)
cmake_minimum_required(VERSION 3.0)

file(GLOB cpp_files ${PROJECT_SOURCE_DIR} "*.cpp")
include_directories(${PROJECT_SOURCE_DIR})
add_library(classes STATIC ${cpp_files})
add_executable( project.exe main.cpp)
target_link_libraries( project.exe classes)
