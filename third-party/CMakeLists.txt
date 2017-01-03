project(dss_third_party VERSION 0.1 LANGUAGES CXX)

# Catch C++ testing library
set(target "catch")
add_library(${target} INTERFACE)
target_include_directories(${target}
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${dss_include_install_prefix}/include>
)
