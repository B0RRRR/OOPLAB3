cmake_minimum_required(VERSION 3.16)
project(RotationFigures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_executable(RotationFigures ${SRC_FILES})

list(REMOVE_ITEM SRC_FILES ${CMAKE_SOURCE_DIR}/src/main.cpp)

file(GLOB TEST_FILES ${CMAKE_SOURCE_DIR}/tests/*.cpp)
add_executable(UnitTests ${SRC_FILES} ${TEST_FILES})

find_package(GTest REQUIRED)
if(GTest_FOUND)
    include_directories(${GTEST_INCLUDE_DIRS})
    target_link_libraries(UnitTests ${GTEST_BOTH_LIBRARIES} pthread)
endif()

enable_testing()
include(GoogleTest)
gtest_discover_tests(UnitTests)
