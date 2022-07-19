#include "livid/livid.hpp"
#include <string>

using namespace livid;

int main() {
    int count = 0;

    // This sets the document title
    Document::title("Hello");

    Widget div(WidgetType::Div);

    Widget result(WidgetType::Div);
    // We set the id to conveniently access the widget by id in the callback
    result.id("result");
    result.text("0");
    result.style(Style::FontSize, "22px");

    Widget btn1(WidgetType::Button);
    // This sets the textContent element property
    btn1.text("Increment!");
    // We set the style color to green
    btn1.style(Style::Color, "green");
    // This signals that clicks call the inc function
    btn1.handle(Event::Click, [&](auto) {
        count += 1;
        Console::log("%d", count);
        auto result = Widget::from_id("result");
        result.text(std::to_string(count));
    });
    // widgets are automatically appended to body, here we want to append to the div
    div.append(btn1);

    Widget btn2(WidgetType::Button);
    btn2.text("Decrement!");
    btn2.style(Style::Color, "red");
    btn2.handle(Event::Click, [&, result](auto) mutable {
        count -= 1;
        Console::log("%d", count);
        result.text(std::to_string(count));
    });
    div.append(btn2);

    // we get all elements by tagName BUTTON
    auto elems = Document::elems_by_tag("BUTTON");
    for (auto &elem : elems) {
        // set their fontSize to 22 pixesl
        elem.style(Style::FontSize, "22px");
    }
}