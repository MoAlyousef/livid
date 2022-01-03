cmake_minimum_required(VERSION 3.15)
project(cmake_livid_example)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DEMSCRIPTEN -s WASM=1 -s EXTRA_EXPORTED_RUNTIME_METHODS=['UTF8ToString','lengthBytesUTF8','stringToUTF8']")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --shell-file ${CMAKE_CURRENT_LIST_DIR}/my_shell.html")

add_executable(index login.cpp)
target_compile_features(index PRIVATE cxx_std_17)
target_include_directories(index PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../..)
set_target_properties(index PROPERTIES SUFFIX .html)