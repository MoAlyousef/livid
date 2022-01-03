#include <string>
#include "livid/livid.hpp"

using namespace livid;

class AppState {
    int counter;
    public:
     AppState(int c): counter(c) {}
    void increment() {
        counter += 1;
    }
    void decrement() {
        counter -= 1;
    }
    int value() const {
        return counter;
    }
};

static AppState state(0);

WASM_EXPORT void inc(void) {
    auto result = Widget<WidgetType::Div>::from_id("result");
    state.increment();
    result.text(std::to_string(state.value()).c_str());
}

WASM_EXPORT void dec(void) {
    auto result = Widget<WidgetType::Div>::from_id("result");
    state.decrement();
    result.text(std::to_string(state.value()).c_str());
}

int main() {
    Widget<WidgetType::Div> div("mydiv");
    Widget<WidgetType::Button> btn1("btn_inc");
    btn1.text("Increment!");
    btn1.handle("click", "inc");
    Widget<WidgetType::Button> btn2("btn_dec");
    btn2.text("Decrement!");
    btn2.handle("click", "dec");
    Widget<WidgetType::Div> result("result");

    div.append(btn1);
    div.append(btn2);

    result.text("0");
}