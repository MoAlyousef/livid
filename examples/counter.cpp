#include "livid/livid.hpp"
#include <string>

using namespace livid;

static int COUNT = 0;

int main() {
    // This sets the document title
    Document::title("Hello");

    Widget div(WidgetType::Div);

    Widget result(WidgetType::Div);
    // We set the id to conveniently access the widget by id
    // in the callback
    result.id("result");
    result.text("0");
    result.style(Style::FontSize, "22px");

    Widget btn1(WidgetType::Button);
    // This sets the textContent element property
    btn1.text("Increment!");
    // We set the style color to green
    btn1.style(Style::Color, "green");
    // This signals that clicks call the inc function
    btn1.handle(Event::Click, [=](auto) mutable {
        COUNT += 1;
        Console::log("%d", COUNT);
        result.text(std::to_string(COUNT));
    });
    // widgets are automatically appended to body, here we
    // want to append to the div
    div.append(btn1);

    Widget btn2(WidgetType::Button);
    btn2.text("Decrement!");
    btn2.style(Style::Color, "red");
    btn2.handle(Event::Click, [=](auto) mutable {
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