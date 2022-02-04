#include "livid/livid.hpp"

using namespace livid;

using Ul = Widget<WidgetType::Ul>;
using Li = Widget<WidgetType::Li>;

template<class ...Ts>
void create_unordered_list(Ts... args) {
    Ul ul;
    for (const auto &arg : {args...}) {
        ul.append(Li().text(arg));
    }
}

int main() { 
    create_unordered_list("Item1", "Item2", "Item3"); 
}