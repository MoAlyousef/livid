#include "livid/livid.hpp"

using namespace livid;

template<class ...Ts>
void create_unordered_list(Ts... args) {
    auto ul = Ul();
    for (const auto &arg : {args...}) {
        ul.append(Li().text(arg));
    }
}

int main() { 
    Document::add_css_link("https://cdn.jsdelivr.net/npm/bulma@0.9.3/css/bulma.min.css");
    create_unordered_list("Item1", "Item2", "Item3"); 
}