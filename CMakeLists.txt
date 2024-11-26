# Minimum CMake version required
cmake_minimum_required(VERSION 3.20)

# Project name
project(KBELEngine)

# Set the C++ standard version that will be used
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(test)
