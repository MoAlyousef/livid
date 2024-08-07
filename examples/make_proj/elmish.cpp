#include "livid/livid.hpp"
#include <string>

using namespace livid;

class AppState {
    static inline int counter = 0;

  public:
    static void increment(Event) {
        counter++;
        update();
    }

    static void decrement(Event) {
        counter--;
        update();
    }

    static void update() {
        HTMLElement::from_id("result").text(std::to_string(counter));
    }

    static void view() {
        Div()
            .append(Button().text("+").handle(EventType::Click, increment))
            .append(Button().text("-").handle(EventType::Click, decrement))
            .append(Div().id("result").text(std::to_string(counter)));
    }
};

int main() { AppState::view(); }
