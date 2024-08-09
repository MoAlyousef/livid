#include "livid/livid.hpp"
#include <emscripten/html5.h>
#include <string>

using namespace livid;

static int COUNT = 0;

int main() {
    // This sets the document title
    Document::title("Hello");

    auto div = Div();

    auto result = Div().id("result");
    // We set the id to conveniently access the HTMLElement by id
    // in the callback
    result.id("result");
    result.text("0");
    result.style(Style::FontSize, "22px");

    auto btn1 = Button().id("btn1");
    // This sets the textContent element property
    btn1.text("Increment!");
    // We set the style color to green
    btn1.style(Style::Color, "green");
    // This signals that clicks call the inc function
    emscripten_set_click_callback(
        // id
        "#btn1",
        // user_data: void *
        nullptr,
        // use captures: EM_BOOL
        0,
        // callback: (int eventtype, const EmscriptenMouseEvent *me, void *user_data) -> EM_BOOL
        [](int, const auto *mouseevent, void *) -> auto { 
            COUNT += 1;
            Console::log("%d", COUNT);
            auto result = HTMLElement::from_id("result");
            result.text(std::to_string(COUNT));
            return 1;
        }
    );
    // HTMLElements are automatically appended to body, here we
    // want to append to the div
    div.append(btn1);

    auto btn2 = Button().id("btn2");
    btn2.text("Decrement!");
    btn2.style(Style::Color, "red");
    emscripten_set_click_callback(
        "#btn2",
        nullptr,
        0,
        [](int, const auto *mouseevent, void *) -> auto {
            COUNT -= 1;
            Console::log("%d", COUNT);
            auto result = HTMLElement::from_id("result");
            result.text(std::to_string(COUNT));
            return 1;
        }
    );
    div.append(btn2);

    // we get all elements by tagName BUTTON
    auto elems = Document::elems_by_tag("BUTTON");
    for (auto &elem : elems) {
        // set their fontSize to 22 pixesl
        elem.style(Style::FontSize, "22px");
    }
}