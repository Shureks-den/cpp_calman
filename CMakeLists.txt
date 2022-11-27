cmake_minimum_required(VERSION 3.23)
project(calman)

set(CMAKE_CXX_STANDARD 17)

add_executable(calman main.cpp Parser/Parser.cpp Parser/Parser.h NoiseModel/NoiseModel.cpp NoiseModel/NoiseModel.h)
