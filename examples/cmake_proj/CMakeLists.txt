cmake_minimum_required(VERSION 3.15)
project(cmake_livid_example)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-s WASM=1 -s EXTRA_EXPORTED_RUNTIME_METHODS=['UTF8ToString','lengthBytesUTF8','stringToUTF8','ccall']")

add_executable(index src/login.cpp)
target_include_directories(index PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../../include)
target_link_options(index PRIVATE --shell-file ${CMAKE_CURRENT_LIST_DIR}/my_shell.html)
set_target_properties(index PROPERTIES SUFFIX .html)