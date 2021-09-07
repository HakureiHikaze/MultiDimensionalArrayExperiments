cmake_minimum_required(VERSION 3.20)
project(MultiDimensionalArrayExperiments)

set(CMAKE_CXX_STANDARD 11)

add_executable(MultiDimensionalArrayExperiments main.cpp Tensor.cpp Tensor.hpp Matrix.cpp Matrix.hpp)
