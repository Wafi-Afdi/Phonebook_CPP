# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(PhonebookCLI CXX)

# Set the C++ standard to C++17 (or C++11, C++14 depending on your preference)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF) # Ensure standard compliance

set(SOURCE_DIR src)
set(INCLUDE_DIR include)

file(GLOB_RECURSE SOURCES "${SOURCE_DIR}/*.cpp")

# Add an executable target
add_executable(${PROJECT_NAME} ${SOURCES})

# Specify include directories so header files can be found
target_include_directories(${PROJECT_NAME} PUBLIC ${SOURCE_DIR})
