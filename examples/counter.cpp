#include <string>
#include "livid/livid.hpp"

using namespace livid;


class AppState {
    static int counter;
    public:
    static void increment() {
        counter += 1;
        auto result = Widget<WidgetType::Div>::from_id("result");
        result.text(std::to_string(counter));
    }
    static void decrement() {
        counter -= 1;
        auto result = Widget<WidgetType::Div>::from_id("result");
        result.text(std::to_string(counter));
    }
};

int AppState::counter = 0;

WASM_EXPORT void inc(void) {
    AppState::increment();
}

WASM_EXPORT void dec(void) {
    AppState::decrement();
}
int main() {
    Document::title("Hello");

    Widget<WidgetType::Div> div; 

    Widget<WidgetType::Button> btn1;
    // This sets the textContent element property
    btn1.text("Increment!");
    btn1.style("color", "green");
    // This signals that clicks call the inc function
    btn1.handle("click", "inc");
    // widgets are automatically appended to body, here we want to append to the div
    div.append(btn1);

    Widget<WidgetType::Button> btn2;
    btn2.text("Decrement!");
    btn2.style("color", "red");
    btn2.handle("click", "dec");
    div.append(btn2);

    // The constructor can take an id, which needs to be unique and without spaces, here we need it for the callback
    Widget<WidgetType::Div> result;
    result.id("result");
    result.text("0");
    result.style("fontSize", "22px");

    auto elems = Document::elems_by_tag("BUTTON");
    for (auto &elem: elems) {
        elem.style("fontSize", "22px");
    }
}