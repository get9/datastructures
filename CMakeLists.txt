cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(DSS VERSION 0.1 LANGUAGES CXX)

# Set some default directories
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")
set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/lib")
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

# Use modern C++
set(CMAKE_CXX_STANDARD 14)
set(CXX_STANDARD_REQUIRED on)

# If using Ninja, make sure output is colorized
if (CMAKE_GENERATOR MATCHES "Ninja")
    add_compile_options("-fdiagnostics-color=always")
endif()

# Include helpful cmake files
include(DSSConstants)

# Options
option(DSS_BUILD_TESTS "Build tests" on)

# Enable testing
if (DSS_BUILD_TESTS)
    enable_testing()
endif()

# Add subdirs
add_subdirectory(third-party)
add_subdirectory(dss)

# To be added later
#add_subdirectory(examples)
