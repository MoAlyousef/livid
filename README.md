# Livid

Livid is a single header C++ wasm frontend library leveraging Emscripten.

## Usage
The code looks something like this:
```cpp
#include <string>
#include "livid/livid.hpp"

using namespace livid;

static int COUNT = 0;

WASM_EXPORT void inc(void) {
    auto result = Widget<WidgetType::Div>::from_id("result");
    COUNT += 1;
    result.text(std::to_string(COUNT).c_str());
}

WASM_EXPORT void dec(void) {
    auto result = Widget<WidgetType::Div>::from_id("result");
    COUNT -= 1;
    result.text(std::to_string(COUNT).c_str());
}

int main() {
    Widget<WidgetType::Div> div("mydiv"); // The constructor takes an id, which needs to be unique
    Widget<WidgetType::Button> btn1("btn_inc");
    Widget<WidgetType::Button> btn2("btn_dec");
    Widget<WidgetType::Div> result("result");
    div.append_child(btn1); // widgets are automatically appended to body, here we want to append to the div
    div.append_child(btn2);
    btn1.text("Increment!"); // This sets the textContent element property
    btn1.handle("click", "inc"); // This signals that clicks call the inc function
    btn2.text("Decrement!");
    btn2.handle("click", "dec");
    result.text("0");
}
```
You'll also notice that the repo has a minimal shell which you can use, it's passed as an argument to emscripten. You can replace it with whatever shell you prefer, and include css etc. The login example uses Bulma for CSS.

## Building
Assuming you have a working installation of Emscripten:

If you clone this repo, from the root you can directly invoke em++ to build any of the examples:
```
$ em++ -std=c++17 -I. examples/counter.cpp -s EXTRA_EXPORTED_RUNTIME_METHODS=['UTF8ToString','lengthBytesUTF8','stringToUTF8'] -o index.html --shell-file my_shell.html
```

With CMake:
You need a CMakeLists.txt file with contents similar to:
```cmake
cmake_minimum_required(VERSION 3.15)
project(cmake_livid_example)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DEMSCRIPTEN -s WASM=1 -s EXTRA_EXPORTED_RUNTIME_METHODS=['UTF8ToString','lengthBytesUTF8','stringToUTF8']")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --shell-file ${CMAKE_CURRENT_LIST_DIR}/my_shell.html")

add_executable(index login.cpp)
target_compile_features(index PRIVATE cxx_std_17)
target_include_directories(index PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../..)
set_target_properties(index PROPERTIES SUFFIX .html)
```
Then configure with `emcmake cmake -Bbin`.
