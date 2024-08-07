# Livid

Livid is a single header C++ wasm frontend library leveraging Emscripten.

## Usage

The code looks something like this:
```cpp
#include "livid/livid.hpp"
#include <string>

using namespace livid;

static int COUNT = 0;

int main() {
    // This sets the document title
    Document::title("Hello");

    auto div = Div();

    auto result = Div();
    // We set the id to conveniently access the HTMLElement by id
    // in the callback
    result.id("result");
    result.text("0");
    result.style(Style::FontSize, "22px");

    auto btn1 = Button();
    // This sets the textContent element property
    btn1.text("Increment!");
    // We set the style color to green
    btn1.style(Style::Color, "green");
    // This signals that clicks call the inc function
    btn1.handle(EventType::Click, [=](auto) mutable {
        COUNT += 1;
        Console::log("%d", COUNT);
        result.text(std::to_string(COUNT));
    });
    // HTMLElements are automatically appended to body, here we
    // want to append to the div
    div.append(btn1);

    auto btn2 = Button();
    btn2.text("Decrement!");
    btn2.style(Style::Color, "red");
    btn2.handle(EventType::Click, [=](auto) mutable {
        COUNT -= 1;
        Console::log("%d", COUNT);
        result.text(std::to_string(COUNT));
    });
    div.append(btn2);

    // we get all elements by tagName BUTTON
    auto elems = Document::elems_by_tag("BUTTON");
    for (auto &elem : elems) {
        // set their fontSize to 22 pixesl
        elem.style(Style::FontSize, "22px");
    }
}
```
You can also use a builder pattern:
```cpp
#include "livid/livid.hpp"
#include <string>

using namespace livid;

int main() {
    Form().klass("box").append(
        Div()
            .klass("field")
            .append(Label().klass("label").text("Email"))
            .append(Div().klass("control").append(
                Input()
                    .klass("input")
                    .attr("type", "email")
                    .attr("placeholder", "m@gmail.com")
            ))
            .append(
                Div()
                    .klass("field")
                    .append(Label().klass("label").text(
                        "Password"
                    ))
                    .append(Div().klass("control").append(
                        Input()
                            .klass("input")
                            .attr("type", "password")
                            .attr("placeholder", "*******")
                    ))
            )
            .append(Button()
                        .klass("button is-primary")
                        .text("Sign in"))
    );
}
```
This uses Bulma for css styling.
![image](https://user-images.githubusercontent.com/37966791/147970535-12542b64-94e2-4660-86d1-43846d9ce92f.png)

You can also use an elmish architecture for your application:
```cpp
#include "livid/livid.hpp"
#include <string>

using namespace livid;

class AppState {
    static inline int counter = 0;

  public:
    static void increment(Event) {
        counter++;
        update();
    }

    static void decrement(Event) {
        counter--;
        update();
    }

    static void update() {
        HTMLElement::from_id("result").text(std::to_string(counter));
    }

    static void view() {
        Div()
            .append(Button().text("+").handle(EventType::Click, increment))
            .append(Button().text("-").handle(EventType::Click, decrement))
            .append(Div().id("result").text(std::to_string(counter)));
    }
};

int main() {
    AppState::view();
}
```

## Building

Assuming you have a working installation of Emscripten:

If you clone this repo, from the root you can directly invoke em++ to build any of the examples:
```
$ em++ -s WASM=1 --bind -std=c++20 -O3 -Iinclude examples/counter.cpp -o index.html --shell-file my_shell.html
```

With CMake:
You need a CMakeLists.txt file with contents similar to:
```cmake
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

add_executable(index main.cpp)
target_compile_features(index PRIVATE cxx_std_20)
set_target_properties(index PROPERTIES SUFFIX .html LINK_FLAGS "-s WASM=1 --bind --shell-file ${CMAKE_CURRENT_LIST_DIR}/my_shell.html")
target_link_libraries(index PRIVATE livid::livid)
```

Then configure with `emcmake cmake -Bbin -DCMAKE_BUILD_TYPE=Release`, and build with `cmake --build bin`.

There's also a Makefile in the examples directory (under make_proj) if you prefer to use make.

The build usually outputs 3 files, an html, wasm and js files, you need all 3 to run your program.
Building in release mode (`-O3` or `-DCMAKE_BUILD_TYPE=Release`), the total size of a simple project is around 30kb.

## Running

Opening the html file directly in the browser won't work.
To run, you need a server to serve the generated html file:
```
$ python3 -m http.server --directory .
```
Or you can use `emrun` which is provided by emscripten.

emrun opens a browser automatically, if you use another server program, you need to open your wasm-capable browser to the provided url, which is usually something like 127.0.0.1:8000

## Html shell

You'll notice that the repo has a minimal shell which you can use, it's passed as an argument to emscripten. You can replace it with whatever shell you prefer, and include css etc:
```html
<!doctype html>
<html lang="en-us">
  <head>
    <meta charset="utf-8">
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>My app</title>
  </head>
  <body>
  {{{ SCRIPT }}}
  </body>
</html>
```

## Documentation

Still a work in progress, you can generate it using `doxygen livid.dox`.
