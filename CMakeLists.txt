cmake_minimum_required(VERSION 3.0)
set(LIVID_PROJECT_VERSION 0.1.1)
project(livid VERSION ${LIVID_PROJECT_VERSION})

add_library(livid INTERFACE)
target_include_directories(livid INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)
target_compile_features(livid INTERFACE cxx_std_17)
target_compile_definitions(livid INTERFACE -DEMSCRIPTEN)
add_library(livid::livid ALIAS livid)