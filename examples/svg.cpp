#include "livid/livid.hpp"
#include <string>

using namespace livid;

int main() {
    Widget<WidgetType::Svg> svg; // or NSWidget svg("http://www.w3.org/2000/svg", "svg");
    svg.attr("viewBox", "0 0 300 300");
    svg.attr("width", "300");
    svg.attr("height", "300");
    svg.style(Style::Display, "block");

    // NSWidget is a namespaced widget
    NSWidget circle("http://www.w3.org/2000/svg", "circle");
    circle.attr("cx", "50");
    circle.attr("cy", "50");
    circle.attr("r", "40");
    circle.attr("stroke", "black");
    circle.attr("stroke-width", "3");
    circle.attr("fill", "red");
    svg.append(circle);
}