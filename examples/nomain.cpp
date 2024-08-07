#include "livid/livid.hpp"

using namespace livid;

__attribute__((used))
extern "C" void set_title() {
    // This sets the document title
    Document::title("Hello");
}