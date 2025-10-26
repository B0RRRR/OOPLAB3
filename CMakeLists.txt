cmake_minimum_required(VERSION 3.16)
project(RotationFigures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

file(GLOB TEST_FILES ${CMAKE_SOURCE_DIR}/tests/*.cpp)
add_executable(Tests ${SRC_FILES} ${TEST_FILES})

find_package(GTest REQUIRED)
if(GTest_FOUND)
    include_directories(${GTEST_INCLUDE_DIRS})
    target_link_libraries(Tests ${GTEST_BOTH_LIBRARIES} pthread)
endif()

enable_testing()
include(GoogleTest)
gtest_discover_tests(Tests)
