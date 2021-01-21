cmake_minimum_required(VERSION 3.8)
project(kolokwium)

add_executable(kolokwium src/tests_main.cpp
        src/zad1.cpp
        # src/zad2.cpp
        # src/zad3.cpp
        # src/zad4.cpp
        # src/zad5.cpp
        )

set_target_properties(kolokwium PROPERTIES CXX_STANDARD 17)
target_include_directories(kolokwium PUBLIC include)
