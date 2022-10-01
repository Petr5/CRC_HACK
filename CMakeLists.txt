cmake_minimum_required(VERSION 3.23)
#project(googletest_ex C CXX)
set(This Main)
project(${This} C CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 99)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(SOURCES
        main.cpp tests/tests.cpp crc.cpp)
#set(Headers
#        )

add_library(${This} STATIC ${SOURCES} ${Headers})

add_subdirectory(tests)
add_executable(MainProgram main.cpp crc.cpp)
add_custom_target(my_parallel_build
        COMMAND ${CMAKE_COMMAND} --build . -j 2
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "My parallel build with 5 cores")


option(ENABLE_MULTHITHREADING "ENABLE_MULTHITHREADING" 1)

if(ENABLE_MULTHITHREADING)
    target_compile_definitions(MainProgram PUBLIC MULTITHREADING)
else()
    message("false")
endif(ENABLE_MULTHITHREADING)
