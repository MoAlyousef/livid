#include "livid/livid.hpp"
#include <string>

using namespace livid;

using Div = Widget<WidgetType::Div>;
using Form = Widget<WidgetType::Form>;
using Label = Widget<WidgetType::Label>;
using Input = Widget<WidgetType::Input>;
using Button = Widget<WidgetType::Button>;

int main() {
    Form().klass("box").append(
        Div()
            .klass("field") // the class attribute is used by many css libs for styling elements of the same class
            .append(Label().klass("label").text("Email"))
            .append(Div().klass("control").append(
                Input().klass("input").attr("type", "email").attr("placeholder", "m@gmail.com")))
            .append(
                Div()
                    .klass("field")
                    .append(Label().klass("label").text("Password"))
                    .append(Div().klass("control").append(
                        Input().klass("input").attr("type", "password").attr("placeholder", "*******"))))
            .append(Button().klass("button is-primary").text("Sign in")));
}