
#todo :
# can we keep common code in this directory in a .cmake file and include 
# in CMakeLists.txt in each subdirectories

# also how to include relative path in include() (specially one step up)

cmake_minimum_required(VERSION 3.10)
project(basic_cmake VERSION 1.1)
#include .cmake file for its content
#include(calculate_exe_for_every_cpp.cmake)
# print_all_variables()

set(CMAKE_CXX_FLAGS "--std=c++17")
add_subdirectory(01_basic_concepts)
add_subdirectory(02_templates)
add_subdirectory(03_multithreading)
add_subdirectory(04_adv_concept)
add_subdirectory(04_adv_concept_2)
add_subdirectory(05_custom_smart_ptrs)
add_subdirectory(06_stl_programming)
add_subdirectory(07_cpp17_features)