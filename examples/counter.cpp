#include "livid/livid.hpp"
#include <string>

using namespace livid;

static int COUNT = 0;

int main() {
    // This sets the document title
    Document::title("Hello");
    Console::log("%d %d", COUNT, 2);
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
    // btn1.handle(EventType::Click, [=](auto) mutable {
    //     COUNT += 1;
    //     Console::log("%d", COUNT);
    //     result.text(std::to_string(COUNT));
    // });
    // HTMLElements are automatically appended to body, here we
    // want to append to the div
    div.append(btn1);

    auto btn2 = Button();
    btn2.text("Decrement!");
    btn2.style(Style::Color, "red");
    // btn2.handle(EventType::Click, [=](auto) mutable {
    //     COUNT -= 1;
    //     Console::log("%d", COUNT);
    //     result.text(std::to_string(COUNT));
    // });
    div.append(btn2);

    // // we get all elements by tagName BUTTON
    auto elems = Document::elems_by_tag("BUTTON");
    for (auto &elem : elems) {
        // set their fontSize to 22 pixesl
        elem.style(Style::FontSize, "22px");
    }
}