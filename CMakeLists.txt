cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

add_compile_options("-Wall" "-Wextra" "-Wpedantic")

project(DesignPatterns)

add_subdirectory(src)

enable_testing() #This needs adding in every subdirectory that includes tests
add_subdirectory(test)




