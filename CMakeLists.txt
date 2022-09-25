cmake_minimum_required(VERSION 3.23)
project(crc)

set(CMAKE_CXX_STANDARD 17)
#CXXFLAGS("-g -O0 -Wall -W -Wshadow -Wunused-variable \
#-Wunused-parameter -Wunused-function -Wunused -Wno-system-headers \
#-Wno-deprecated -Woverloaded-virtual -Wwrite-strings -fprofile-arcs -ftest-coverage")
#CFLAGS("-g -O0 -Wall -W -fprofile-arcs -ftest-coverage")
#LDFLAGS("-fprofile-arcs -ftest-coverage")

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(crc_run main.cpp crc.cpp crc.h )
target_link_libraries(crc_run gtest gtest_main)

#find_package(GTest CONFIG REQUIRED)
#target_link_libraries()