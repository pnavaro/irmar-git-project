project(cpp_project CXX)
cmake_minimum_required(VERSION 3.0)

file(GLOB hpp_files ${PROJECT_SOURCE_DIR} "*.h")
file(GLOB cpp_files ${PROJECT_SOURCE_DIR} "*.cpp")
include_directories(${PROJECT_SOURCE_DIR})
foreach(cpp_file ${cpp_files})
   if (NOT ${cpp_file} MATCHES "main.c")
      list(APPEND  lib_sources ${cpp_file})
   endif (NOT ${cpp_file} MATCHES "main.c")
endforeach(cpp_file)
add_library(classes STATIC ${lib_sources})
add_executable( project.exe main.cpp)
target_link_libraries( project.exe classes)
