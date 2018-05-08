################################################################################
# Test project for embedded templates library
################################################################################
cmake_minimum_required (VERSION 2.6)
project(etl_tests)

if(MSVC)
	add_definitions(-DNOMINMAX /std:c++17)
endif(MSVC)
if(CMAKE_COMPILER_IS_GNUCXX)
	add_definitions(-std=c++17)
endif()

enable_testing()

include_directories(../src)
add_executable(fp fixedPoint.cpp)
add_test(fixedPoint_unit_test fp)