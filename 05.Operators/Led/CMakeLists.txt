cmake_minimum_required(VERSION 3.10)
project(LedDriverProject C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/Inc)

add_library(led_driver Src/Led_Driver.c)

add_subdirectory(Tests)
