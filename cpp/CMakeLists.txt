cmake_minimum_required(VERSION 3.10)
project(NavigationRoutingSystem)

# Find pybind11
find_package(pybind11 REQUIRED)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

# Add the source files
add_library(graph_module MODULE
    graph.cpp
    graph_pybind.cpp
)

# Link pybind11 to the module
target_link_libraries(graph_module PRIVATE pybind11::module)
