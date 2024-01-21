cmake_minimum_required(VERSION 3.4.1)
project(RnFridaDetection)

set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_CXX_STANDARD 11)

add_library(rn-frida-detection            SHARED
            ../cpp/rn-frida-detection.cpp
            cpp-adapter.cpp
)

# Specifies a path to native header files.
include_directories(
            ../cpp
)
