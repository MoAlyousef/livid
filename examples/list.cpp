#include "livid/livid.hpp"

using namespace livid;

template <class... Ts>
void create_unordered_list(Ts... args) {
    auto ul = Ul();
    for (const auto &arg : {args...}) {
        ul.append(Li().text(arg));
    }
}

int main() {
    Document::add_css_link(
        "https://classless.de/classless.css"
    );
    create_unordered_list("Item1", "Item2", "Item3");
}