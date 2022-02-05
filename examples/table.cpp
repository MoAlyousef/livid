#include "livid/livid.hpp"
#include <vector>
#include <string>

using namespace livid;

using Table = Widget<WidgetType::Table>;
using Tbody = Widget<WidgetType::Tbody>;
using Tr = Widget<WidgetType::Tr>; // table row
using Td = Widget<WidgetType::Td>; // table cell

Table create_table(const std::vector<std::vector<int>> &data) {
    Table t;
    t.attr("border", "1");
    Tbody tb;
    t.append(tb);
    for (int i = 0; i < data.size(); i++) {
        Tr tr;
        tb.append(tr);

        for (int j = 0; j < data[i].size(); j++) {
            Td td;
            td.attr("width", "100");
            td.text(std::to_string(data[i][j]));
            tr.append(td);
        }
    }
    return t;
}

int main() { 
    std::vector<std::vector<int>> data = {
        {1, 2, 3, 4, 5, 6, 7},
        {10, 11, 12, 13, 14, 15, 16}
    };
    Document::title("Table");
    auto table = create_table(data);
}