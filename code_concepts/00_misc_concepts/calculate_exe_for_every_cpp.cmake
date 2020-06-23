cmake_minimum_required(VERSION 3.10)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId})
message(STATUS "project name : ${ProjectId}")

# this cmake script iterate through source files and create exes for sources.
# exe's names are name of the .cpp file minus .cpp extension
file( GLOB ALL_SOURCE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp )

foreach( src_file ${ALL_SOURCE_FILES} )
    #create exename by replacing .cpp with .out
    string( REPLACE ".cpp" ".out" exe_name ${src_file} )
    add_executable( ${exe_name} ${src_file} )

    set_target_properties(${exe_name} PROPERTIES LINKER_LANGUAGE CXX)
    
endforeach()