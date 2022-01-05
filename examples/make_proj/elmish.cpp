#include "livid/livid.hpp"
#include <string>

using namespace livid;

using Div = Widget<WidgetType::Div>;
using Button = Widget<WidgetType::Button>;

class AppState {
    static inline int counter = 0;

  public:
    static void Increment() { counter++; update(); }
    
    static void Decrement() { counter--; update(); }
    
    static void update() { Div::from_id("result").text(std::to_string(counter)); }
    
    void view() {
        Div()
            .append(Button().text("+").handle(Event::Click, Increment))
            .append(Button().text("-").handle(Event::Click, Decrement))
            .append(Div().id("result").text(std::to_string(counter)));
    }
};

int main() {
    AppState a;
    a.view();
}