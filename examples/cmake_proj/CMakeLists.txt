cmake_minimum_required(VERSION 3.15)
project(cmake_livid_example)

include(FetchContent)

FetchContent_Declare(
    LIVID
    GIT_REPOSITORY https://github.com/MoAlyousef/livid
    GIT_TAG main
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(LIVID)

add_executable(index src/login.cpp)
target_link_options(index PRIVATE --shell-file ${CMAKE_CURRENT_LIST_DIR}/my_shell.html)
set_target_properties(index PROPERTIES SUFFIX .html)
target_link_libraries(index PRIVATE livid::livid)