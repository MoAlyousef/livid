#include "livid/livid.hpp"

using namespace livid;

using Table = Widget<WidgetType::Table>;
using Tbody = Widget<WidgetType::Tbody>;
using Tr = Widget<WidgetType::Tr>;
using Td = Widget<WidgetType::Td>;

void create_table() {
    Table t;
    Tbody tb;
    t.append(tb);
    for (int i = 0; i < 3; i++) {
        Tr tr;
        tb.append(tr);

        for (int j = 0; j < 4; j++) {
            Td td;
            td.text("Hello");
            tr.append(td);
        }
    }
}

int main() { create_table(); }