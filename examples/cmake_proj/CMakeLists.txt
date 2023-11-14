cmake_minimum_required(VERSION 3.15)
project(cmake_livid_example)

add_executable(index src/login.cpp)
target_compile_features(index PRIVATE cxx_std_17)
target_include_directories(index PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../../include)
set_target_properties(index PROPERTIES SUFFIX .html LINK_FLAGS "-s WASM=1 -s EVAL_CTORS=2 --bind --shell-file ${CMAKE_CURRENT_LIST_DIR}/my_shell.html")