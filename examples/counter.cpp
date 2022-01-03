#include <emscripten.h>
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
    Widget<WidgetType::Div> div("mydiv");
    Widget<WidgetType::Button> btn1("btn_inc");
    btn1.text("Increment!");
    btn1.handle("click", "inc");
    Widget<WidgetType::Button> btn2("btn_dec");
    btn2.text("Decrement!");
    btn2.handle("click", "dec");
    Widget<WidgetType::Div> result("result");

    div.append_child(btn1);
    div.append_child(btn2);

    result.text("0");
}