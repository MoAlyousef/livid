#include <string>
#include "livid/livid.hpp"

using namespace livid;

class AppState {
    static int counter;
    public:
    static void increment() {
        counter += 1;
        auto result = WidgetBase::from_id("result");
        result.text(std::to_string(counter));
    }
    static void decrement() {
        counter -= 1;
        auto result = WidgetBase::from_id("result");
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

    Widget<WidgetType::Div> div("mydiv"); // The constructor takes an id, which needs to be unique and without spaces

    Widget<WidgetType::Button> btn1("btn_inc");
    btn1.text("Increment!"); // This sets the textContent element property
    btn1.style("color", "green");
    btn1.handle("click", "inc"); // This signals that clicks call the inc function
    div.append(btn1); // widgets are automatically appended to body, here we want to append to the div

    Widget<WidgetType::Button> btn2("btn_dec");
    btn2.text("Decrement!");
    btn2.style("color", "red");
    btn2.handle("click", "dec");
    div.append(btn2);

    Widget<WidgetType::Div> result("result");
    result.text("0");
}