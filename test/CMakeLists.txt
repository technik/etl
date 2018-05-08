################################################################################
# Test project for embedded templates library
################################################################################
cmake_minimum_required (VERSION 2.6)
project(etl_tests)

enable_testing()

include_directories(../src)
add_executable(fp fixedPoint.cpp)
add_test(fixedPoint_unit_test fp)