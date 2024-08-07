#include "livid/livid.hpp"
#include <string>

using namespace livid;

static int COUNT = 0;

int main() {
    // This sets the document title
    Document::title("Hello");
    auto canvas       = Canvas(600, 400);
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