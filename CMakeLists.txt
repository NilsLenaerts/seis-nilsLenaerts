cmake_minimum_required(VERSION 3.23)

#set the project name
project(seis-nilslenaerts VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(src)

add_executable(seis-nilslenaerts
            src/bytestream.cpp
            src/bytestream.h
)