cmake_minimum_required(VERSION 3.10)
project(LedDriverProject C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

# Include headers
include_directories(${CMAKE_SOURCE_DIR}/Inc)

# Tạo thư viện driver
add_library(led_driver Src/Led_Driver.c)

# Thêm thư mục test
add_subdirectory(Tests)
