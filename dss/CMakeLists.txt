project(libdss VERSION 0.1 LANGUAGES CXX)
set(target dss)

add_library(${target} INTERFACE)
target_include_directories(${target}
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${dss_include_install_prefix}/include>
)

if (DSS_BUILD_TESTS)
set(test_srcs
    test/ForwardLinkedListTest.cpp
)
foreach (src ${test_srcs})
    get_filename_component(filename ${src} NAME_WE)
    set(testname ${target}_${filename})
    add_executable(${testname} ${src})
    target_link_libraries(${testname}
        dss
        catch
    )
    add_test(
        NAME ${testname}
        WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}
        COMMAND ${testname}
    )
endforeach()
endif()
