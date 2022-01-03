#include <string>
#include "livid/livid.hpp"

using namespace livid;

int main() {
    Widget<WidgetType::Form> box("box");
    box.attr("class", "box");

    Widget<WidgetType::Div> field1("field1");
    field1.attr("class", "field");
    box.append_child(field1);

    Widget<WidgetType::Label> email("email");
    email.attr("class", "label");
    email.text("Email");
    field1.append_child(email);

    Widget<WidgetType::Div> control1("control1");
    control1.attr("class", "control");
    field1.append_child(control1);

    Widget<WidgetType::Input> input1("input1");
    input1.attr("class", "input");
    input1.attr("type", "email");
    input1.attr("placeholder", "m@gmail.com");
    control1.append_child(input1);

    Widget<WidgetType::Div> field2("field2");
    field2.attr("class", "field");
    box.append_child(field2);

    Widget<WidgetType::Label> pass("pass");
    pass.attr("class", "label");
    pass.text("Password");
    field2.append_child(pass);

    Widget<WidgetType::Div> control2("control2");
    control2.attr("class", "control");
    field2.append_child(control2);
    
    Widget<WidgetType::Input> input2("input2");
    input2.attr("class", "input");
    input2.attr("type", "password");
    input2.attr("placeholder", "*******");
    control2.append_child(input2);

    Widget<WidgetType::Button> button("button");
    button.attr("class", "button is-primary");
    button.text("Sign in");
    box.append_child(button);
}