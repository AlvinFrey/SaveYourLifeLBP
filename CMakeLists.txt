cmake_minimum_required(VERSION 3.17)
project(SaveYourLifeLBP)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(SaveYourLifeLBP main.cpp MaskLabel.h training.cpp training.h distance.cpp model/imageModel.cpp model/imageModel.h utils.cpp utils.h predict.cpp predict.h distance.h)

target_link_libraries(SaveYourLifeLBP ${OpenCV_LIBS})