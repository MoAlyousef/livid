#include "livid/livid.hpp"

using namespace livid;

__attribute__((used))
extern "C" void set_title() {
    // This sets the document title
    Document::title("Hello");
}

__attribute__((used))
extern "C" void draw_on_canvas() {
    auto canvas       = Canvas(HTMLElement::from_id("mycanvas"));
    auto ctx          = canvas.get_context("2d");
    const auto width  = canvas.width();
    const auto height = canvas.height();

    ctx.call<void>("clearRect", 0, 0, width, height);

    // rect
    ctx.set("fillStyle", "green");
    ctx.call<void>("fillRect", 0, 0, width, height);

    // line
    ctx.set("strokeStyle", "black");
    ctx.call<void>("moveTo", 0, 0);
    ctx.call<void>("lineTo", width, height);
    ctx.call<void>("stroke");

    // text
    ctx.set("fillStyle", "black");
    ctx.set("font", "bold 48px serif");
    ctx.call<void, std::string>(
        "fillText", "Hello World!", width / 2, height / 2
    );
}