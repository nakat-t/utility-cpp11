cmake_minimum_required(VERSION 3.12)

project(utility_cpp11 VERSION 0.1.0 LANGUAGES CXX)

include(CTest)

if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Release")
    set(CMAKE_BUILD_TYPE "Release")
endif()

if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 11)
endif()
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(include_dirs "${PROJECT_SOURCE_DIR}/include")

file(GLOB_RECURSE sources_for_catch2_test CONFIGURE_DEPENDS "test/*.t.cpp")

set(catch2_test_app_name catch2_test_${PROJECT_NAME})

set(include_dirs_for_catch2_test
    ${PROJECT_SOURCE_DIR}/test
    ${PROJECT_SOURCE_DIR}/external/catchorg/Catch2/single_include
)

add_executable(${catch2_test_app_name} ${sources_for_catch2_test})

target_include_directories(
    ${catch2_test_app_name}
    PUBLIC
    ${include_dirs}
    ${include_dirs_for_catch2_test}
    ${PROJECT_BINARY_DIR}
)

if(BUILD_TESTING)
    add_test(NAME catch2 COMMAND ${catch2_test_app_name})
endif()

set(include_dirs_for_compile_fail_test
    ${include_dirs}
    ${PROJECT_SOURCE_DIR}/test
)

file(GLOB_RECURSE sources_for_compile_fail_test CONFIGURE_DEPENDS "test/*.compile.fail.cpp")

foreach(srcfile ${sources_for_compile_fail_test})
    string(REGEX REPLACE "${PROJECT_SOURCE_DIR}/test/(([^/]+/)*([^./]+))\\.compile\\.fail\\.cpp" [[\1]] compile_fail_basename "${srcfile}")
    string(REPLACE "/" "." compile_fail_basename "${compile_fail_basename}")
    set(test_target ${compile_fail_basename}.compile.fail)
    add_executable(${test_target} ${srcfile})
    target_include_directories(
        ${test_target}
        PUBLIC
        ${include_dirs_for_compile_fail_test}
    )
    set_target_properties(
        ${test_target}
        PROPERTIES
        EXCLUDE_FROM_ALL True
        EXCLUDE_FROM_DEFAULT_BUILD True
    )
    if(BUILD_TESTING)
        add_test(
            NAME ${test_target}
            COMMAND ${CMAKE_COMMAND} --build . --target ${test_target} --config $<CONFIGURATION>
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        )
        set_tests_properties(${test_target} PROPERTIES WILL_FAIL True)
    endif()
endforeach()
