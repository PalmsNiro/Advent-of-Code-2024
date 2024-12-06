cmake_minimum_required(VERSION 3.14)
project(Advent_of_Code2024 VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Options
option(BUILD_TESTS "Build tests" ON)

# Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add GoogleTest
add_subdirectory(submodules/googletest)

# Add executable
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/Day1.cpp
    src/Day2.cpp
    src/Day3.cpp
    src/Day4.cpp
    src/Day5.cpp
    src/Day6.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include  # Public headers
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src      # Private headers
)

# Tests
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()