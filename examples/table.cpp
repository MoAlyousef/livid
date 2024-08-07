#include "livid/livid.hpp"
#include <string>
#include <vector>

using namespace livid;

HTMLElement create_table(const std::vector<std::vector<int>> &data) {
    auto t = Table();
    t.attr("border", "1");
    auto tb = Tbody();
    t.append(tb);
    for (const auto &i : data) {
        auto tr = Tr();
        tb.append(tr);

        for (int j = 0; j < data[i].size(); j++) {
            auto td = Td();
            td.attr("width", "100");
            td.text(std::to_string(data[i][j]));
            tr.append(td);
        }
    }
    return t;
}

int main() {
    std::vector<std::vector<int>> data = {
        {1, 2, 3, 4, 5, 6, 7}, {10, 11, 12, 13, 14, 15, 16}
    };
    Document::title("Table");
    auto table = create_table(data);
}