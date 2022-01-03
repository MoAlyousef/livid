/*
MIT License

Copyright (c) 2021 Mohammed Alyousef

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef __LIVID_HPP__
#define __LIVID_HPP__

#include <cstdio>
#include <emscripten.h>
#include <string>

#define WASM_EXPORT EMSCRIPTEN_KEEPALIVE extern "C"

namespace livid {

enum class WidgetType {
    Address,
    Article,
    Aside,
    Footer,
    Header,
    H1,
    H2,
    H3,
    H4,
    H5,
    H6,
    Main,
    Nav,
    Section,
    Blockquote,
    Dd,
    Div,
    Dl,
    Dt,
    Figcaption,
    Figure,
    Hr,
    Li,
    Ol,
    P,
    Pre,
    Ul,
    A,
    Abbr,
    B,
    Bdi,
    Bdo,
    Br,
    Cite,
    Code,
    Data,
    Dfn,
    Em,
    I,
    Kbd,
    Mark,
    Q,
    Rp,
    Rt,
    Ruby,
    S,
    Samp,
    Small,
    Span,
    Strong,
    Sub,
    Sup,
    Time,
    U,
    Var,
    Wbr,
    Area,
    Audio,
    Img,
    Map,
    Track,
    Video,
    Embed,
    Iframe,
    Object,
    Param,
    Picture,
    Portal,
    Source,
    Svg,
    Math,
    Canvas,
    Noscript,
    Script,
    Del,
    Ins,
    Caption,
    Col,
    Colgroup,
    Table,
    Tbody,
    Td,
    Tfoot,
    Th,
    Thead,
    Tr,
    Button,
    Datalist,
    Fieldset,
    Form,
    Input,
    Label,
    Legend,
    Meter,
    Optgroup,
    Option,
    Output,
    Progress,
    Select,
    Textarea,
    Details,
    Dialog,
    Menu,
    Summary,
    Slot,
    Template,
};

namespace detail {
constexpr const char *get_element_str(WidgetType typ) {
    switch (typ) {
    case WidgetType::Address:
        return "address";
    case WidgetType::Article:
        return "article";
    case WidgetType::Aside:
        return "aside";
    case WidgetType::Footer:
        return "footer";
    case WidgetType::Header:
        return "header";
    case WidgetType::H1:
        return "h1";
    case WidgetType::H2:
        return "h2";
    case WidgetType::H3:
        return "h3";
    case WidgetType::H4:
        return "h4";
    case WidgetType::H5:
        return "h5";
    case WidgetType::H6:
        return "h6";
    case WidgetType::Main:
        return "main";
    case WidgetType::Nav:
        return "nav";
    case WidgetType::Section:
        return "section";
    case WidgetType::Blockquote:
        return "blockquote";
    case WidgetType::Dd:
        return "dd";
    case WidgetType::Div:
        return "div";
    case WidgetType::Dl:
        return "dl";
    case WidgetType::Dt:
        return "dt";
    case WidgetType::Figcaption:
        return "figcaption";
    case WidgetType::Figure:
        return "figure";
    case WidgetType::Hr:
        return "hr";
    case WidgetType::Li:
        return "li";
    case WidgetType::Ol:
        return "ol";
    case WidgetType::P:
        return "p";
    case WidgetType::Pre:
        return "pre";
    case WidgetType::Ul:
        return "ul";
    case WidgetType::A:
        return "a";
    case WidgetType::Abbr:
        return "abbr";
    case WidgetType::B:
        return "b";
    case WidgetType::Bdi:
        return "bdi";
    case WidgetType::Bdo:
        return "bdo";
    case WidgetType::Br:
        return "br";
    case WidgetType::Cite:
        return "cite";
    case WidgetType::Code:
        return "code";
    case WidgetType::Data:
        return "data";
    case WidgetType::Dfn:
        return "dfn";
    case WidgetType::Em:
        return "em";
    case WidgetType::I:
        return "i";
    case WidgetType::Kbd:
        return "kbd";
    case WidgetType::Mark:
        return "mark";
    case WidgetType::Q:
        return "q";
    case WidgetType::Rp:
        return "rp";
    case WidgetType::Rt:
        return "rt";
    case WidgetType::Ruby:
        return "ruby";
    case WidgetType::S:
        return "s";
    case WidgetType::Samp:
        return "samp";
    case WidgetType::Small:
        return "small";
    case WidgetType::Span:
        return "span";
    case WidgetType::Strong:
        return "strong";
    case WidgetType::Sub:
        return "sub";
    case WidgetType::Sup:
        return "sup";
    case WidgetType::Time:
        return "time";
    case WidgetType::U:
        return "u";
    case WidgetType::Var:
        return "var";
    case WidgetType::Wbr:
        return "wbr";
    case WidgetType::Area:
        return "area";
    case WidgetType::Audio:
        return "audio";
    case WidgetType::Img:
        return "img";
    case WidgetType::Map:
        return "map";
    case WidgetType::Track:
        return "track";
    case WidgetType::Video:
        return "video";
    case WidgetType::Embed:
        return "embed";
    case WidgetType::Iframe:
        return "iframe";
    case WidgetType::Object:
        return "object";
    case WidgetType::Param:
        return "param";
    case WidgetType::Picture:
        return "picture";
    case WidgetType::Portal:
        return "portal";
    case WidgetType::Source:
        return "source";
    case WidgetType::Svg:
        return "svg";
    case WidgetType::Math:
        return "math";
    case WidgetType::Canvas:
        return "canvas";
    case WidgetType::Noscript:
        return "noscript";
    case WidgetType::Script:
        return "script";
    case WidgetType::Del:
        return "del";
    case WidgetType::Ins:
        return "ins";
    case WidgetType::Caption:
        return "caption";
    case WidgetType::Col:
        return "col";
    case WidgetType::Colgroup:
        return "colgroup";
    case WidgetType::Table:
        return "table";
    case WidgetType::Tbody:
        return "tbody";
    case WidgetType::Td:
        return "td";
    case WidgetType::Tfoot:
        return "tfoot";
    case WidgetType::Th:
        return "th";
    case WidgetType::Thead:
        return "thead";
    case WidgetType::Tr:
        return "tr";
    case WidgetType::Button:
        return "button";
    case WidgetType::Datalist:
        return "datalist";
    case WidgetType::Fieldset:
        return "fieldset";
    case WidgetType::Form:
        return "form";
    case WidgetType::Input:
        return "input";
    case WidgetType::Label:
        return "label";
    case WidgetType::Legend:
        return "legend";
    case WidgetType::Meter:
        return "meter";
    case WidgetType::Optgroup:
        return "optgroup";
    case WidgetType::Option:
        return "option";
    case WidgetType::Output:
        return "output";
    case WidgetType::Progress:
        return "progress";
    case WidgetType::Select:
        return "select";
    case WidgetType::Textarea:
        return "textarea";
    case WidgetType::Details:
        return "details";
    case WidgetType::Dialog:
        return "dialog";
    case WidgetType::Menu:
        return "menu";
    case WidgetType::Summary:
        return "summary";
    case WidgetType::Slot:
        return "slot";
    case WidgetType::Template:
        return "template";
    default:
        return "div";
    }
}
} // namespace detail

template <WidgetType widget_type>
class Widget {
    std::string id_ = "";
    Widget() {}

  public:
    explicit Widget(const std::string &id) : id_(id) {
        const char *element = detail::get_element_str(widget_type);
        EM_ASM_(
            {
                const widget = document.createElement(Module.UTF8ToString($0));
                widget.setAttribute('id', Module.UTF8ToString($1));
                document.body.appendChild(widget);
            },
            element, id_.c_str());
    }

    Widget(const Widget &other): id_(other.id_) {}
    Widget(Widget &&other): id_(std::move(other.id_)) {}
    Widget& operator=(const Widget &other) {
        *this = other;
        return *this;
    }

    static Widget from_id(const std::string &id) {
        Widget w;
        w.id_ = id;
        return w;
    }

    std::string id() const {
        return id_;
    }

    Widget &attr(const std::string &attr, const std::string &val) {
        EM_ASM_(
            {
                document.getElementById(Module.UTF8ToString($0))
                    .setAttribute(Module.UTF8ToString($1), Module.UTF8ToString($2));
            },
            id_.c_str(), attr.c_str(), val.c_str());
        return *this;
    }

    std::string attr(const std::string &attr) {
        char *ptr = nullptr;
        EM_ASM_(
            {
                const txt = document.getElementById(Module.UTF8ToString($0))
                                .getAttribute(Module.UTF8ToString($1));
                const cnt = (Module.lengthBytesUTF8(txt) + 1);
                $1 = Module._malloc(cnt);
                Module.stringToUTF8(txt, $2, cnt);
            },
            id_.c_str(), attr.c_str(), ptr);
        return std::string(ptr);
    }

    Widget &klass(const std::string &val) {
        EM_ASM_(
            {
                document.getElementById(Module.UTF8ToString($0))
                    .setAttribute('class', Module.UTF8ToString($1));
            },
            id_.c_str(), val.c_str());
        return *this;
    }

    std::string klass() {
        char *ptr = nullptr;
        EM_ASM_(
            {
                const txt = document.getElementById(Module.UTF8ToString($0)).getAttribute('class');
                const cnt = (Module.lengthBytesUTF8(txt) + 1);
                $1 = Module._malloc(cnt);
                Module.stringToUTF8(txt, $1, cnt);
            },
            id_.c_str(), ptr);
        return std::string(ptr);
    }

    Widget &type(const std::string &val) {
        EM_ASM_(
            {
                document.getElementById(Module.UTF8ToString($0))
                    .setAttribute('type', Module.UTF8ToString($1));
            },
            id_.c_str(), val.c_str());
        return *this;
    }

    std::string type() {
        char *ptr = nullptr;
        EM_ASM_(
            {
                const txt = document.getElementById(Module.UTF8ToString($0)).getAttribute('type');
                const cnt = (Module.lengthBytesUTF8(txt) + 1);
                $1 = Module._malloc(cnt);
                Module.stringToUTF8(txt, $1, cnt);
            },
            id_.c_str(), ptr);
        return std::string(ptr);
    }

    template <WidgetType other>
    Widget &append(const Widget<other> &w) {
        EM_ASM_(
            {
                document.getElementById(Module.UTF8ToString($0))
                    .appendChild(document.getElementById(Module.UTF8ToString($1)));
            },
            id_.c_str(), w.id().c_str());
        return *this;
    }

    template <WidgetType other>
    Widget &remove(const Widget<other> &w) {
        EM_ASM_(
            {
                document.getElementById(Module.UTF8ToString($0))
                    .removeChild(document.getElementById(Module.UTF8ToString($1)));
            },
            id_.c_str(), w.id().c_str());
        return *this;
    }

    Widget &handle(const std::string &event, const std::string &name) {
        std::string n = "_";
        n += name;
        EM_ASM_(
            {
                document.getElementById(Module.UTF8ToString($0))
                    .addEventListener(Module.UTF8ToString($1), Module[Module.UTF8ToString($2)]);
            },
            id_.c_str(), event.c_str(), n.c_str());
        return *this;
    }

    Widget &text(const std::string &html) {
        EM_ASM_(
            {
                document.getElementById(Module.UTF8ToString($0)).textContent =
                    Module.UTF8ToString($1);
            },
            id_.c_str(), html.c_str());
        return *this;
    }

    std::string text() {
        char *ptr = nullptr;
        EM_ASM_(
            {
                const txt = document.getElementById(Module.UTF8ToString($0)).textContent;
                const cnt = (Module.lengthBytesUTF8(txt) + 1);
                $1 = Module._malloc(cnt);
                Module.stringToUTF8(txt, $1, cnt);
            },
            id_.c_str(), ptr);
        return std::string(ptr);
    }

    Widget &inner_html(const std::string &html) {
        EM_ASM_(
            {
                document.getElementById(Module.UTF8ToString($0)).innerHtml =
                    Module.UTF8ToString($1);
            },
            id_.c_str(), html.c_str());
        return *this;
    }

    std::string inner_html() {
        char *ptr = nullptr;
        EM_ASM_(
            {
                const txt = document.getElementById(Module.UTF8ToString($0)).innerHtml;
                const cnt = (Module.lengthBytesUTF8(txt) + 1);
                $1 = Module._malloc(cnt);
                Module.stringToUTF8(txt, $1, cnt);
            },
            id_.c_str(), ptr);
        return std::string(ptr);
    }

    Widget &href(const std::string &html) {
        EM_ASM_(
            { document.getElementById(Module.UTF8ToString($0)).href = Module.UTF8ToString($1); },
            id_.c_str(), html.c_str());
        return *this;
    }

    std::string href() {
        char *ptr = nullptr;
        EM_ASM_(
            {
                const txt = document.getElementById(Module.UTF8ToString($0)).href;
                const cnt = (Module.lengthBytesUTF8(txt) + 1);
                $1 = Module._malloc(cnt);
                Module.stringToUTF8(txt, $1, cnt);
            },
            id_.c_str(), ptr);
        return std::string(ptr);
    }
};
} // namespace livid

#endif