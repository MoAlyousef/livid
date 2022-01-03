#include "livid/livid.hpp"
#include <string>

using namespace livid;

using Div = Widget<WidgetType::Div>;
using Form = Widget<WidgetType::Form>;
using Label = Widget<WidgetType::Label>;
using Input = Widget<WidgetType::Input>;
using Button = Widget<WidgetType::Button>;

int main() {
    Form("box").klass("box").append(
        Div("field1")
            .klass("field")
            .append(Label("email").klass("label").text("Email"))
            .append(
                Div("control1").klass("control").append(
                    Input("input1")
                        .klass("input")
                        .type("email")
                        .attr("placeholder", "m@gmail.com")
                )
            )
            .append(
                Div("field2")
                    .klass("field")
                    .append(Label("pass").klass("label").text("Password"))
                    .append(
                        Div("control2").klass("control").append(
                            Input("input2")
                                .klass("input")
                                .type("password")
                                .attr("placeholder", "*******")
                        )
                    )
            )
            .append(Button("button").klass("button is-primary").text("Sign in"))
    );
}