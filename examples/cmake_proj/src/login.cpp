#include "livid/livid.hpp"
#include <string>

using namespace livid;

int main() {
    Form().klass("box").append(
        Div() // the class attribute is used by many css
              // libs for styling elements of the same class
            .klass("field")
            .append(Label().klass("label").text("Email"))
            .append(Div().klass("control").append(
                Input()
                    .klass("input")
                    .attr("type", "email")
                    .attr("placeholder", "m@gmail.com")
            ))
            .append(Div()
                        .klass("field")
                        .append(Label().klass("label").text("Password"))
                        .append(Div().klass("control").append(
                            Input()
                                .klass("input")
                                .attr("type", "password")
                                .attr("placeholder", "*******")
                        )))
            .append(Button().klass("button is-primary").text("Sign in"))
    );
}
