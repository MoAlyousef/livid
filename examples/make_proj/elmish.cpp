#include "livid/livid.hpp"
#include <string>

using namespace livid;

class AppState {
    static inline int counter = 0;

  public:
    static void increment(emscripten::val) {
        counter++;
        update();
    }

    static void decrement(emscripten::val) {
        counter--;
        update();
    }

    static void update() {
        Widget::from_id("result").text(
            std::to_string(counter)
        );
    }

    static void view() {
        Div()
            .append(Button().text("+").handle(
                Event::Click, increment
            ))
            .append(Button().text("-").handle(
                Event::Click, decrement
            ))
            .append(Div().id("result").text(
                std::to_string(counter)
            ));
    }
};

int main() {
    AppState::view();
}
