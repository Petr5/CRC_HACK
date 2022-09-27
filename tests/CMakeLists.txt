cmake_minimum_required(VERSION 3.23)

set(This ExampleTest)

set(Sources
        tests.cpp
#        crc.h
        )

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
        gtest_main
        Main
        )

add_test(
        NAME${This}
        COMMAND${This}

)